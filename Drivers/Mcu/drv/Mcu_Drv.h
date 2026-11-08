#ifndef MCU_DRV_H
#define MCU_DRV_H

#include "Mcu.h"

void Mcu_DrvInit(void);
Mcu_ClockResultType Mcu_DrvInitClock(Mcu_ClockType profile);
Mcu_PllStatusType Mcu_DrvPllStatus(void);
Mcu_ClockResultType Mcu_DrvDistributePllClock(void);
Mcu_ClockInfoType Mcu_DrvReadClocks(void);
uint32 Mcu_DrvResetRawValue(void);
Mcu_ClockResultType Mcu_DrvLastClockError(void);
Mcu_ClockResultType Mcu_DrvFallbackResult(void);

#endif
