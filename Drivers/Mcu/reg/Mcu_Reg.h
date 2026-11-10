#ifndef MCU_REG_H
#define MCU_REG_H

#include <stdbool.h>
#include "Std_Types.h"

/* 地址和位编码对照 RM0477 与 ST 的 stm32h7s3xx.h。 */
#define MCU_REG32(address) (*(volatile uint32 *)(uintptr_t)(address))

#define MCU_RCC_CR         MCU_REG32(0x58024400U)
#define MCU_RCC_CFGR       MCU_REG32(0x58024410U)
#define MCU_RCC_CDCFGR     MCU_REG32(0x58024418U)
#define MCU_RCC_BMCFGR     MCU_REG32(0x5802441CU)
#define MCU_RCC_APBCFGR    MCU_REG32(0x58024420U)
#define MCU_RCC_PLLCKSELR  MCU_REG32(0x58024428U)
#define MCU_RCC_PLLCFGR    MCU_REG32(0x5802442CU)
#define MCU_RCC_PLL1DIVR1  MCU_REG32(0x58024430U)
#define MCU_RCC_PLL1FRACR  MCU_REG32(0x58024434U)
#define MCU_RCC_CCIPR2     MCU_REG32(0x58024450U)
#define MCU_RCC_APB1ENR1   MCU_REG32(0x58024548U)
#define MCU_RCC_RSR        MCU_REG32(0x58024530U)
#define MCU_PWR_SR1        MCU_REG32(0x58024804U)
#define MCU_PWR_CSR2       MCU_REG32(0x5802480CU)
#define MCU_PWR_CSR4       MCU_REG32(0x58024814U)
#define MCU_FLASH_ACR      MCU_REG32(0x52002000U)
#define MCU_FLASH_OBW2SR   MCU_REG32(0x52002268U)
#define MCU_SCB_VTOR       MCU_REG32(0xE000ED08U)
#define MCU_SCB_CPACR      MCU_REG32(0xE000ED88U)

#define MCU_HSION          (1U << 0)
#define MCU_HSIRDY         (1U << 2)
#define MCU_HSIDIV_SHIFT   3U
#define MCU_HSIDIV_MASK    (3U << MCU_HSIDIV_SHIFT)
#define MCU_HSEON          (1U << 16)
#define MCU_HSERDY         (1U << 17)
#define MCU_HSEBYP         (1U << 18)
#define MCU_HSEEXT         (1U << 19)
#define MCU_PLL1ON         (1U << 24)
#define MCU_PLL1RDY        (1U << 25)
#define MCU_OTHER_PLLS     (0xFU << 26)

#define MCU_SW_MASK        7U
#define MCU_SWS_SHIFT      3U
#define MCU_SWS_MASK       (MCU_SW_MASK << MCU_SWS_SHIFT)
#define MCU_SW_HSI         0U
#define MCU_SW_CSI         1U
#define MCU_SW_HSE         2U
#define MCU_SW_PLL1        3U
#define MCU_PRESCALE_MASK  0xFU
#define MCU_APBPRES_MASK   0x7777U

/* USART2/3、UART4/5/7/8 共用 UART234578SEL。编码 0 选择 PCLK1。 */
#define MCU_UART_GROUP_SEL_MASK 7U
#define MCU_UART_GROUP_PCLK1    0U
#define MCU_USART3_GATE         (1U << 18U)
#define MCU_UART_GROUP_GATES    ((0xFU << 17U) | (3U << 30U))

#define MCU_PLLSRC_MASK    3U
#define MCU_DIVM1_SHIFT    4U
#define MCU_DIVM1_MASK     (0x3FU << MCU_DIVM1_SHIFT)
#define MCU_PLL1_FRACEN    (1U << 0)
#define MCU_PLL1_RGE_4_8   (2U << 3)
#define MCU_PLL1_RGE_8_16  (3U << 3)
#define MCU_PLL1_PEN       (1U << 5)
#define MCU_PLL1_CFG_MASK  0x1FFU
#define MCU_PLL1_DIVN_MASK 0x1FFU
#define MCU_PLL1_DIVP_SHIFT 9U
#define MCU_PLL1_DIVP_MASK (0x7FU << MCU_PLL1_DIVP_SHIFT)
#define MCU_FRACN_SHIFT    3U
#define MCU_FRACN_MASK     (0x1FFFU << MCU_FRACN_SHIFT)

#define MCU_PWR_SUPPLY_MASK 0x3FU
#define MCU_PWR_LDO_SUPPLY (1U << 1)
#define MCU_PWR_STARTUP_SUPPLY (3U << 1)
#define MCU_PWR_ACTVOS     (1U << 0)
#define MCU_PWR_ACTVOSRDY  (1U << 1)
#define MCU_PWR_VOS        (1U << 0)
#define MCU_PWR_VOSRDY     (1U << 1)
#define MCU_FLASH_SRAM_ECC (1U << 8U)
#define MCU_FLASH_TIMING_MASK 0x3FU
#define MCU_FLASH_WRHIGHFREQ_SHIFT 4U

static inline void Mcu_RegUpdate(volatile uint32 *reg, uint32 mask, uint32 value)
{
    *reg = (*reg & ~mask) | value;
}

static inline bool Mcu_RegWait(const volatile uint32 *reg, uint32 mask, uint32 expected)
{
    /* 启动阶段尚无系统节拍，限制轮询次数。此上限不是毫秒计时。 */
    for (uint32 polls = 0U; polls < 4000000U; ++polls) {
        if ((*reg & mask) == expected) {
            return true;
        }
    }
    return false;
}

#endif
