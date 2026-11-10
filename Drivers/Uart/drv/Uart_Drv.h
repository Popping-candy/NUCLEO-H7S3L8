#ifndef UART_DRV_H
#define UART_DRV_H

#include "Uart.h"

Uart_ResultType Uart_DrvInit(uint32 baudRate);
Uart_ResultType Uart_DrvWriteByte(uint8 data, uint32 timeoutMs);
Uart_ResultType Uart_DrvReadByte(uint8 *data, uint32 timeoutMs);

#endif
