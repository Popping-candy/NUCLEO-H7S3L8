#include "Efls_Drv.h"

Efls_ResultType Efls_Read(uint32 offset, void *destination, uint32 length)
{
    return Efls_DrvRead(offset, destination, length);
}

Efls_ResultType Efls_BlankCheck(uint32 offset, uint32 length)
{
    return Efls_DrvBlankCheck(offset, length);
}

Efls_ResultType Efls_Erase(uint32 offset, uint32 length)
{
    return Efls_DrvErase(offset, length);
}

Efls_ResultType Efls_Write(uint32 offset, const void *source, uint32 length)
{
    return Efls_DrvWrite(offset, source, length);
}

uint32 Efls_GetLastFlashFlags(void)
{
    return Efls_DrvLastFlags();
}
