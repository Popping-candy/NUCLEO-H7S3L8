#include "Delay.h"
#include "Delay_Drv.h"

bool Delay_Init(void)
{
    return Delay_DrvInit();
}

bool Delay_Us(uint32 microseconds)
{
    return Delay_DrvWait(microseconds, 1000000U);
}

bool Delay_Ms(uint32 milliseconds)
{
    return Delay_DrvWait(milliseconds, 1000U);
}

bool Delay_GetCycleCount(uint32 *cycles)
{
    return Delay_DrvGetCycleCount(cycles);
}
