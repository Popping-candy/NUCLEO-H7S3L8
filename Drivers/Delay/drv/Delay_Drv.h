#ifndef DELAY_DRV_H
#define DELAY_DRV_H

#include <stdbool.h>
#include "Std_Types.h"

bool Delay_DrvInit(void);
bool Delay_DrvWait(uint32 duration, uint32 unitsPerSecond);

#endif
