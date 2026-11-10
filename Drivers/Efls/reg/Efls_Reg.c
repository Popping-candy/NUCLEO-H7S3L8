#include <stddef.h>
#include "Efls_Reg.h"
#include "Delay.h"
#include "Delay_Reg.h"
#include "Mcu.h"

/* 按 STM32H7S3xx CMSIS 定义。SSN 是三位，足以选择 0～7 号扇区。 */
#define EFLS_REG32(address) (*(volatile uint32 *)(uintptr_t)(address))
#define EFLS_FLASH_KEYR EFLS_REG32(0x52002004U)
#define EFLS_FLASH_CR   EFLS_REG32(0x52002010U)
#define EFLS_FLASH_SR   EFLS_REG32(0x52002014U)
#define EFLS_FLASH_ISR  EFLS_REG32(0x52002024U)
#define EFLS_FLASH_ICR  EFLS_REG32(0x52002028U)
#define EFLS_SCB_CCR    EFLS_REG32(0xE000ED14U)

#define EFLS_KEY1       0x45670123U
#define EFLS_KEY2       0xCDEF89ABU
#define EFLS_LOCK       (1U << 0U)
#define EFLS_PG         (1U << 1U)
#define EFLS_SER        (1U << 2U)
#define EFLS_START      (1U << 5U)
#define EFLS_SSN_SHIFT  6U
#define EFLS_SSN_MASK   (7U << EFLS_SSN_SHIFT)
#define EFLS_OTHER_OP   ((1U << 3U) | (1U << 4U) | (1U << 16U) | (1U << 24U))
#define EFLS_OP_MASK    (EFLS_PG | EFLS_SER | EFLS_START | EFLS_SSN_MASK)
#define EFLS_BUSY_MASK  ((1U << 0U) | (1U << 2U)) /* BUSY 与 QW */
#define EFLS_ERROR_MASK ((1U << 17U) | (1U << 18U) | (1U << 19U) | (1U << 21U))
#define EFLS_EOP        (1U << 16U)
#define EFLS_TIMEOUT_SECONDS 3U

static bool pendingCleanup;

bool Efls_RegReady(void)
{
    if ((EFLS_FLASH_SR & EFLS_BUSY_MASK) != 0U) {
        return false;
    }
    if (pendingCleanup) {
        /* 上次超时时保持控制位，等硬件空闲后才能清理并重新上锁。 */
        EFLS_FLASH_CR = (EFLS_FLASH_CR & ~EFLS_OP_MASK) | EFLS_LOCK;
        pendingCleanup = false;
    }
    return true;
}

bool Efls_RegDataCacheEnabled(void)
{
    return (EFLS_SCB_CCR & (1U << 16U)) != 0U;
}

/* 由启动代码复制到 AXI SRAM。发起擦写后避免同 Bank 取指。
 * 调用方屏蔽可屏蔽中断，words 指向 RAM 中已准备好的 16 字节。
 */
__attribute__((section(".RamFunc"), noinline))
static Efls_ResultType Efls_RegRun(uint32 command, uintptr_t address,
                                  const uint16 *words, uint32 *flags)
{
    /* 遇到其他擦写模式时拒绝启动，防止继承全 Bank 或 OTP 操作位。 */
    if ((EFLS_FLASH_CR & (EFLS_PG | EFLS_SER | EFLS_START | EFLS_OTHER_OP)) != 0U) {
        return EFLS_BUSY;
    }
    const uint32 hz = SystemCoreClock;
    if (hz == 0U || hz > UINT32_MAX / 2U / EFLS_TIMEOUT_SECONDS || !Delay_Init()) {
        return EFLS_TIMEBASE_UNAVAILABLE;
    }
    const uint32 timeoutCycles = hz * EFLS_TIMEOUT_SECONDS;

    if ((EFLS_FLASH_CR & EFLS_LOCK) != 0U) {
        EFLS_FLASH_KEYR = EFLS_KEY1;
        EFLS_FLASH_KEYR = EFLS_KEY2;
        if ((EFLS_FLASH_CR & EFLS_LOCK) != 0U) {
            return EFLS_LOCK_FAILED;
        }
    }

    EFLS_FLASH_ICR = EFLS_EOP | EFLS_ERROR_MASK;
    const uint32 start = DELAY_DWT_CYCCNT;
    EFLS_FLASH_CR = (EFLS_FLASH_CR & ~EFLS_OP_MASK) | command;
    if (words != NULL) {
        /* ST H7RS 的完整 Flash word 使用八次连续半字写。 */
        volatile uint16 *destination = (volatile uint16 *)address;
        for (uint32 i = 0U; i < EFLS_WRITE_SIZE / sizeof(uint16); ++i) {
            destination[i] = words[i];
        }
    }
    __asm volatile ("dsb\n\tisb" ::: "memory");

    /* 直接读 DWT，Flash 忙时不调用可能位于同 Bank 的函数。 */
    while ((EFLS_FLASH_SR & EFLS_BUSY_MASK) != 0U) {
        if ((uint32)(DELAY_DWT_CYCCNT - start) >= timeoutCycles) {
            *flags = EFLS_FLASH_ISR;
            pendingCleanup = true;
            return EFLS_TIMEOUT;
        }
    }

    *flags = EFLS_FLASH_ISR;
    EFLS_FLASH_ICR = *flags & (EFLS_EOP | EFLS_ERROR_MASK);
    EFLS_FLASH_CR = (EFLS_FLASH_CR & ~EFLS_OP_MASK) | EFLS_LOCK;
    return (*flags & EFLS_ERROR_MASK) != 0U ? EFLS_CONTROLLER_ERROR : EFLS_OK;
}

Efls_ResultType Efls_RegErase(uint32 sector, uint32 *flags)
{
    return Efls_RegRun(EFLS_SER | EFLS_START | (sector << EFLS_SSN_SHIFT), 0U, NULL, flags);
}

Efls_ResultType Efls_RegProgram(uintptr_t address, const uint16 *words, uint32 *flags)
{
    return Efls_RegRun(EFLS_PG, address, words, flags);
}
