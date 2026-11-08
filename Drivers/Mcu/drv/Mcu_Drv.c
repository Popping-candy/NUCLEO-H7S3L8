#include "Mcu_Drv.h"
#include "Mcu_Reg.h"

#define MCU_HSI_HZ 64000000U
#define MCU_CSI_HZ 4000000U
#define MCU_HSE_HZ 24000000U

/* 24 MHz / 4 × 128 / 4 = 192 MHz。M 直接编码，N 和 P 写入分频值减一。 */
#define MCU_PLL_M 4U
#define MCU_PLL_N 128U
#define MCU_PLL_P 4U
#define MCU_PLL_AHB_DIV2 8U
#define MCU_PLL_APB_DIV2 0x4444U
#define MCU_FLASH_HSI_TIMING 1U
/* AN6062 表 6，Flash AXI 96 MHz、VOS0：LATENCY=2，WRHIGHFREQ=01。 */
#define MCU_FLASH_PLL_TIMING (2U | (1U << MCU_FLASH_WRHIGHFREQ_SHIFT))

uint32 SystemCoreClock = MCU_HSI_HZ;
static bool initialized;
static bool pllOwned;
static bool pllPrepared;
static uint32 resetRawValue;
static Mcu_ClockResultType lastError;
static Mcu_ClockResultType fallbackResult;

static uint32 Mcu_HsiHz(void)
{
    return MCU_HSI_HZ >> ((MCU_RCC_CR & MCU_HSIDIV_MASK) >> MCU_HSIDIV_SHIFT);
}

static uint32 Mcu_Pll1Hz(void)
{
    const uint32 source = MCU_RCC_PLLCKSELR;
    const uint32 m = (source & MCU_DIVM1_MASK) >> MCU_DIVM1_SHIFT;
    const uint32 dividers = MCU_RCC_PLL1DIVR1;
    const uint32 n = (dividers & MCU_PLL1_DIVN_MASK) + 1U;
    const uint32 p = ((dividers & MCU_PLL1_DIVP_MASK) >> MCU_PLL1_DIVP_SHIFT) + 1U;
    uint32 inputHz;

    switch (source & MCU_PLLSRC_MASK) {
    case MCU_SW_HSI: inputHz = Mcu_HsiHz(); break;
    case MCU_SW_CSI: inputHz = MCU_CSI_HZ; break;
    case MCU_SW_HSE: inputHz = MCU_HSE_HZ; break;
    default: return 0U;
    }
    if (m == 0U) {
        return 0U;
    }

    /* FRACN 以 1/8192 为单位。64 位中间值保留精度并防止乘法溢出。 */
    const uint32 frac = (MCU_RCC_PLLCFGR & MCU_PLL1_FRACEN) != 0U
                        ? (MCU_RCC_PLL1FRACR & MCU_FRACN_MASK) >> MCU_FRACN_SHIFT : 0U;
    return (uint32)(((uint64_t)inputHz * (8192U * n + frac)) / (8192U * m * p));
}

static uint32 Mcu_DivideCoreOrAhb(uint32 hz, uint32 encoding)
{
    static const uint8 shifts[] = {1U, 2U, 3U, 4U, 6U, 7U, 8U, 9U};
    return encoding < 8U ? hz : hz >> shifts[encoding - 8U];
}

static uint32 Mcu_DivideApb(uint32 hz, uint32 encoding)
{
    return encoding < 4U ? hz : hz >> (encoding - 3U);
}

Mcu_ClockInfoType Mcu_DrvReadClocks(void)
{
    Mcu_ClockInfoType clocks = {0};
    switch ((MCU_RCC_CFGR & MCU_SWS_MASK) >> MCU_SWS_SHIFT) {
    case MCU_SW_HSI:
        clocks.source = MCU_SOURCE_HSI;
        clocks.sysHz = Mcu_HsiHz();
        break;
    case MCU_SW_CSI:
        clocks.source = MCU_SOURCE_CSI;
        clocks.sysHz = MCU_CSI_HZ;
        break;
    case MCU_SW_HSE:
        clocks.source = MCU_SOURCE_HSE;
        clocks.sysHz = MCU_HSE_HZ;
        break;
    case MCU_SW_PLL1:
        clocks.source = MCU_SOURCE_PLL1;
        clocks.sysHz = Mcu_Pll1Hz();
        break;
    default:
        clocks.source = MCU_SOURCE_UNKNOWN;
        break;
    }

    const uint32 apb = MCU_RCC_APBCFGR;
    clocks.coreHz = Mcu_DivideCoreOrAhb(clocks.sysHz, MCU_RCC_CDCFGR & MCU_PRESCALE_MASK);
    clocks.ahbHz = Mcu_DivideCoreOrAhb(clocks.coreHz, MCU_RCC_BMCFGR & MCU_PRESCALE_MASK);
    clocks.apb1Hz = Mcu_DivideApb(clocks.ahbHz, apb & 7U);
    clocks.apb2Hz = Mcu_DivideApb(clocks.ahbHz, (apb >> 4U) & 7U);
    clocks.apb4Hz = Mcu_DivideApb(clocks.ahbHz, (apb >> 8U) & 7U);
    clocks.apb5Hz = Mcu_DivideApb(clocks.ahbHz, (apb >> 12U) & 7U);
    return clocks;
}

static bool Mcu_SelectClock(uint32 source)
{
    Mcu_RegUpdate(&MCU_RCC_CFGR, MCU_SW_MASK, source);
    /* SW 是软件请求，只有 SWS 回读一致才算切换完成。 */
    return Mcu_RegWait(&MCU_RCC_CFGR, MCU_SWS_MASK, source << MCU_SWS_SHIFT);
}

static bool Mcu_SetFlashTiming(uint32 timing)
{
    Mcu_RegUpdate(&MCU_FLASH_ACR, MCU_FLASH_TIMING_MASK, timing);
    return Mcu_RegWait(&MCU_FLASH_ACR, MCU_FLASH_TIMING_MASK, timing);
}

static void Mcu_SetBusDividers(uint32 ahb, uint32 apb)
{
    Mcu_RegUpdate(&MCU_RCC_CDCFGR, MCU_PRESCALE_MASK, 0U);
    Mcu_RegUpdate(&MCU_RCC_BMCFGR, MCU_PRESCALE_MASK, ahb);
    Mcu_RegUpdate(&MCU_RCC_APBCFGR, MCU_APBPRES_MASK, apb);
    (void)MCU_RCC_APBCFGR;
}

static Mcu_ClockResultType Mcu_EnterHsi(void)
{
    pllPrepared = false;
    MCU_RCC_CR |= MCU_HSION;
    if (!Mcu_RegWait(&MCU_RCC_CR, MCU_HSIRDY, MCU_HSIRDY)) {
        return MCU_CLOCK_HSI_TIMEOUT;
    }
    if (!Mcu_SelectClock(MCU_SW_HSI)) {
        return MCU_CLOCK_HSI_SWITCH_TIMEOUT;
    }

    /* 已确认 HSI 接管，才允许停掉本模块开启的 PLL1。 */
    if (pllOwned) {
        MCU_RCC_CR &= ~MCU_PLL1ON;
        if (!Mcu_RegWait(&MCU_RCC_CR, MCU_PLL1RDY, 0U)) {
            return MCU_CLOCK_PLL_STOP_TIMEOUT;
        }
        pllOwned = false;
    }
    if (!Mcu_SetFlashTiming(MCU_FLASH_HSI_TIMING)) {
        return MCU_CLOCK_FLASH_TIMING_FAILED;
    }
    Mcu_SetBusDividers(0U, 0U);
    return MCU_CLOCK_OK;
}

static Mcu_ClockResultType Mcu_ClockFailure(Mcu_ClockResultType error)
{
    lastError = error;
    fallbackResult = Mcu_EnterHsi();
    SystemCoreClock = Mcu_DrvReadClocks().coreHz;
    return error;
}

void Mcu_DrvInit(void)
{
    if (!initialized) {
        /* 复位标志可同时存在，保留完整快照，供调试时解析。 */
        resetRawValue = MCU_RCC_RSR;
        initialized = true;
    }
    SystemCoreClock = Mcu_DrvReadClocks().coreHz;
}

Mcu_ClockResultType Mcu_DrvInitClock(Mcu_ClockType profile)
{
    if (!initialized) {
        return MCU_CLOCK_NOT_INITIALIZED;
    }
    if (profile != MCU_CLOCK_HSI && profile != MCU_CLOCK_PLL1_192MHZ) {
        return MCU_CLOCK_INVALID_PROFILE;
    }

    lastError = Mcu_EnterHsi();
    fallbackResult = lastError;
    SystemCoreClock = Mcu_DrvReadClocks().coreHz;
    if (lastError != MCU_CLOCK_OK || profile == MCU_CLOCK_HSI) {
        return lastError;
    }

    /* MB1737 使用 LDO 为 Vcore 供电。只从复位态选择 LDO，保留已配置的其他位。 */
    if ((MCU_PWR_CSR2 & MCU_PWR_SUPPLY_MASK) == MCU_PWR_STARTUP_SUPPLY) {
        Mcu_RegUpdate(&MCU_PWR_CSR2, MCU_PWR_SUPPLY_MASK, MCU_PWR_LDO_SUPPLY);
    }
    if ((MCU_PWR_CSR2 & MCU_PWR_SUPPLY_MASK) != MCU_PWR_LDO_SUPPLY ||
        !Mcu_RegWait(&MCU_PWR_SR1, MCU_PWR_ACTVOSRDY, MCU_PWR_ACTVOSRDY)) {
        return Mcu_ClockFailure(MCU_CLOCK_SUPPLY_NOT_READY);
    }
    MCU_PWR_CSR4 |= MCU_PWR_VOS;
    if (!Mcu_RegWait(&MCU_PWR_CSR4, MCU_PWR_VOSRDY, MCU_PWR_VOSRDY) ||
        !Mcu_RegWait(&MCU_PWR_SR1, MCU_PWR_ACTVOS | MCU_PWR_ACTVOSRDY,
                     MCU_PWR_ACTVOS | MCU_PWR_ACTVOSRDY)) {
        return Mcu_ClockFailure(MCU_CLOCK_VOS_TIMEOUT);
    }

    /* PLL1/2/3 共用输入源。检测到 PLL2/3 工作时不改它们的输入。 */
    if ((MCU_RCC_CR & MCU_OTHER_PLLS) != 0U) {
        return Mcu_ClockFailure(MCU_CLOCK_PLL_SOURCE_IN_USE);
    }
    MCU_RCC_CR &= ~MCU_PLL1ON;
    if (!Mcu_RegWait(&MCU_RCC_CR, MCU_PLL1RDY, 0U)) {
        return Mcu_ClockFailure(MCU_CLOCK_PLL_STOP_TIMEOUT);
    }

    /* 只有从旁路切回晶体时才需要先停 HSE。 */
    if ((MCU_RCC_CR & (MCU_HSEBYP | MCU_HSEEXT)) != 0U) {
        MCU_RCC_CR &= ~MCU_HSEON;
        if (!Mcu_RegWait(&MCU_RCC_CR, MCU_HSERDY, 0U)) {
            return Mcu_ClockFailure(MCU_CLOCK_HSE_STOP_TIMEOUT);
        }
        MCU_RCC_CR &= ~(MCU_HSEBYP | MCU_HSEEXT);
    }
    MCU_RCC_CR |= MCU_HSEON;
    if (!Mcu_RegWait(&MCU_RCC_CR, MCU_HSERDY, MCU_HSERDY)) {
        return Mcu_ClockFailure(MCU_CLOCK_HSE_TIMEOUT);
    }

    Mcu_RegUpdate(&MCU_RCC_PLLCKSELR, MCU_PLLSRC_MASK | MCU_DIVM1_MASK,
                  MCU_SW_HSE | (MCU_PLL_M << MCU_DIVM1_SHIFT));
    Mcu_RegUpdate(&MCU_RCC_PLLCFGR, MCU_PLL1_CFG_MASK,
                  MCU_PLL1_RGE_4_8 | MCU_PLL1_PEN);
    Mcu_RegUpdate(&MCU_RCC_PLL1DIVR1, MCU_PLL1_DIVN_MASK | MCU_PLL1_DIVP_MASK,
                  (MCU_PLL_N - 1U) | ((MCU_PLL_P - 1U) << MCU_PLL1_DIVP_SHIFT));
    pllOwned = true;
    MCU_RCC_CR |= MCU_PLL1ON;
    if (!Mcu_RegWait(&MCU_RCC_CR, MCU_PLL1RDY, MCU_PLL1RDY)) {
        return Mcu_ClockFailure(MCU_CLOCK_PLL_LOCK_TIMEOUT);
    }

    /* 到这里 PLL 已锁定，但 CPU 仍取 HSI。分配接口负责最后的切换。 */
    pllPrepared = true;
    return MCU_CLOCK_OK;
}

Mcu_PllStatusType Mcu_DrvPllStatus(void)
{
    return (MCU_RCC_CR & MCU_PLL1RDY) != 0U ? MCU_PLL_LOCKED : MCU_PLL_UNLOCKED;
}

Mcu_ClockResultType Mcu_DrvDistributePllClock(void)
{
    if (!initialized) {
        return MCU_CLOCK_NOT_INITIALIZED;
    }
    if (!pllPrepared) {
        return MCU_CLOCK_PLL_NOT_PREPARED;
    }
    if (Mcu_DrvPllStatus() != MCU_PLL_LOCKED) {
        return Mcu_ClockFailure(MCU_CLOCK_PLL_LOCK_TIMEOUT);
    }

    /* 先调整 Flash 等待周期及总线分频，再让 CPU 使用较高频率。 */
    if (!Mcu_SetFlashTiming(MCU_FLASH_PLL_TIMING)) {
        return Mcu_ClockFailure(MCU_CLOCK_FLASH_TIMING_FAILED);
    }
    Mcu_SetBusDividers(MCU_PLL_AHB_DIV2, MCU_PLL_APB_DIV2);
    if (!Mcu_SelectClock(MCU_SW_PLL1)) {
        return Mcu_ClockFailure(MCU_CLOCK_PLL_SWITCH_TIMEOUT);
    }

    SystemCoreClock = Mcu_DrvReadClocks().coreHz;
    return MCU_CLOCK_OK;
}

uint32 Mcu_DrvResetRawValue(void)
{
    return resetRawValue;
}

Mcu_ClockResultType Mcu_DrvLastClockError(void)
{
    return lastError;
}

Mcu_ClockResultType Mcu_DrvFallbackResult(void)
{
    return fallbackResult;
}
