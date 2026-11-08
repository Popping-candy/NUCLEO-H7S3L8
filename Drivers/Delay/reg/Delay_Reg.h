#ifndef DELAY_REG_H
#define DELAY_REG_H

#include <stdbool.h>
#include "Std_Types.h"

/* Cortex-M7 CoreSight DWT。CYCCNT 每个核心时钟周期递增。 */
#define DELAY_REG32(address) (*(volatile uint32 *)(uintptr_t)(address))
#define DELAY_DEMCR      DELAY_REG32(0xE000EDFCU)
#define DELAY_DWT_CTRL   DELAY_REG32(0xE0001000U)
#define DELAY_DWT_CYCCNT DELAY_REG32(0xE0001004U)
#define DELAY_DWT_LAR    DELAY_REG32(0xE0001FB0U)
#define DELAY_DWT_LSR    DELAY_REG32(0xE0001FB4U)
#define DELAY_TRCENA     (1U << 24U)
#define DELAY_NOCYCCNT   (1U << 25U)
#define DELAY_CYCCNTENA  (1U << 0U)
#define DELAY_LOCK_PRESENT_AND_LOCKED 3U
#define DELAY_UNLOCK_KEY 0xC5ACCE55U

static inline bool Delay_RegCounterEnabled(void)
{
    return (DELAY_DEMCR & DELAY_TRCENA) != 0U &&
           (DELAY_DWT_CTRL & (DELAY_NOCYCCNT | DELAY_CYCCNTENA)) == DELAY_CYCCNTENA;
}

static inline uint32 Delay_RegReadCounter(void)
{
    return DELAY_DWT_CYCCNT;
}

static inline bool Delay_RegEnableCounter(void)
{
    DELAY_DEMCR |= DELAY_TRCENA;
    if ((DELAY_DWT_CTRL & DELAY_NOCYCCNT) != 0U) {
        return false;
    }
    if ((DELAY_DWT_LSR & DELAY_LOCK_PRESENT_AND_LOCKED) == DELAY_LOCK_PRESENT_AND_LOCKED) {
        DELAY_DWT_LAR = DELAY_UNLOCK_KEY;
    }
    /* 保留已有计数值及其他 DWT 配置。 */
    DELAY_DWT_CTRL |= DELAY_CYCCNTENA;
    const uint32 start = Delay_RegReadCounter();
    return Delay_RegCounterEnabled() && Delay_RegReadCounter() != start;
}

#endif
