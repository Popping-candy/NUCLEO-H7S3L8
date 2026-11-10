#include "Mcu_Drv.h"

void Mcu_Init(void)
{
    Mcu_DrvInit();
}

Mcu_ClockResultType Mcu_InitClock(Mcu_ClockType profile)
{
    return Mcu_DrvInitClock(profile);
}

Mcu_PllStatusType Mcu_GetPllStatus(void)
{
    return Mcu_DrvPllStatus();
}

Mcu_ClockResultType Mcu_DistributePllClock(void)
{
    return Mcu_DrvDistributePllClock();
}

Mcu_ClockInfoType Mcu_GetClockInfo(void)
{
    return Mcu_DrvReadClocks();
}

uint32 Mcu_GetResetRawValue(void)
{
    return Mcu_DrvResetRawValue();
}

Mcu_ClockResultType Mcu_GetLastClockError(void)
{
    return Mcu_DrvLastClockError();
}

Mcu_ClockResultType Mcu_GetFallbackResult(void)
{
    return Mcu_DrvFallbackResult();
}

bool Mcu_EnableUsart3Clock(void)
{
    return Mcu_DrvEnableUsart3Clock();
}

uint32 Mcu_GetUsart3ClockHz(void)
{
    return Mcu_DrvGetUsart3ClockHz();
}
