#include "Uart_Drv.h"

Uart_ResultType Uart_Init(uint32 baudRate)
{
    return Uart_DrvInit(baudRate);
}

Uart_ResultType Uart_WriteByte(uint8 data, uint32 timeoutMs)
{
    return Uart_DrvWriteByte(data, timeoutMs);
}

Uart_ResultType Uart_ReadByte(uint8 *data, uint32 timeoutMs)
{
    return Uart_DrvReadByte(data, timeoutMs);
}
