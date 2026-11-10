#ifndef UART_H
#define UART_H

#include "Std_Types.h"

typedef enum {
    UART_OK,
    UART_INVALID_ARGUMENT,
    UART_CLOCK_UNAVAILABLE,
    UART_TIMEBASE_UNAVAILABLE,
    UART_NOT_INITIALIZED,
    UART_TIMEOUT,
    UART_RX_ERROR
} Uart_ResultType;

/* USART3，8N1、16 倍过采样、无流控。先配置 MCU 时钟、Delay 和 Port 复用。 */
Uart_ResultType Uart_Init(uint32 baudRate);
/* timeoutMs=0 只检查一次。写成功表示字节已交给发送寄存器。 */
Uart_ResultType Uart_WriteByte(uint8 data, uint32 timeoutMs);
/* timeoutMs=0 只检查一次。仅 UART_OK 时写入 data，接收错误时丢弃错误数据。 */
Uart_ResultType Uart_ReadByte(uint8 *data, uint32 timeoutMs);

#endif
