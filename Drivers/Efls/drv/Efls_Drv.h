#ifndef EFLS_DRV_H
#define EFLS_DRV_H

#include "Efls.h"

Efls_ResultType Efls_DrvRead(uint32 offset, void *destination, uint32 length);
Efls_ResultType Efls_DrvBlankCheck(uint32 offset, uint32 length);
Efls_ResultType Efls_DrvErase(uint32 offset, uint32 length);
Efls_ResultType Efls_DrvWrite(uint32 offset, const void *source, uint32 length);
uint32 Efls_DrvLastFlags(void);

#endif
