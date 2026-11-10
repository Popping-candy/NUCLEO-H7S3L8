#include <stddef.h>
#include "Delay_Drv.h"
#include "Delay_Reg.h"
#include "Mcu.h"

bool Delay_DrvInit(void)
{
    return Delay_RegEnableCounter();
}

bool Delay_DrvWait(uint32 duration, uint32 unitsPerSecond)
{
    if (duration == 0U) {
        return true;
    }

    const uint32 clockHz = SystemCoreClock;
    if (clockHz == 0U || !Delay_RegCounterEnabled()) {
        return false;
    }

    /* 向上取整到完整周期。毫秒直接换算，避免先乘 1000 造成 32 位溢出。 */
    uint64_t remaining = ((uint64_t)clockHz * duration + unitsPerSecond - 1U) / unitsPerSecond;
    const uint32 maxChunk = UINT32_MAX / 2U;
    while (remaining != 0U) {
        const uint32 chunk = remaining > maxChunk ? maxChunk : (uint32)remaining;
        const uint32 start = Delay_RegReadCounter();

        /* 无符号减法按 2^32 取模，能跨越一次计数器回绕。 */
        while ((uint32)(Delay_RegReadCounter() - start) < chunk) {
        }
        remaining -= chunk;
    }

    return true;
}

bool Delay_DrvGetCycleCount(uint32 *cycles)
{
    if (cycles == NULL || !Delay_RegCounterEnabled()) {
        return false;
    }
    *cycles = Delay_RegReadCounter();
    return true;
}
