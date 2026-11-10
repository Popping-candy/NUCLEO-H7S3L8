#include <stddef.h>
#include "Uart_Drv.h"
#include "Uart_Reg.h"
#include "Delay.h"
#include "Mcu.h"

static bool initialized;

static Uart_ResultType Uart_Wait(uint32 readyMask, uint32 timeoutMs)
{
    if (timeoutMs == 0U) {
        return (UART_ISR & readyMask) != 0U ? UART_OK : UART_TIMEOUT;
    }
    const uint32 hz = SystemCoreClock;
    uint32 previous;
    if (hz == 0U || !Delay_GetCycleCount(&previous)) {
        return UART_TIMEBASE_UNAVAILABLE;
    }

    uint64_t remaining = ((uint64_t)hz * timeoutMs + 999U) / 1000U;
    while ((UART_ISR & readyMask) == 0U) {
        uint32 now;
        if (!Delay_GetCycleCount(&now)) {
            return UART_TIMEBASE_UNAVAILABLE;
        }
        /* 按两次采样之差扣除周期，长超时可跨过多次 CYCCNT 回绕。 */
        const uint32 elapsed = now - previous;
        if (elapsed >= remaining) {
            return UART_TIMEOUT;
        }
        remaining -= elapsed;
        previous = now;
    }
    return UART_OK;
}

Uart_ResultType Uart_DrvInit(uint32 baudRate)
{
    if (baudRate == 0U) {
        return UART_INVALID_ARGUMENT;
    }
    uint32 cycles;
    if (!Delay_GetCycleCount(&cycles)) {
        return UART_TIMEBASE_UNAVAILABLE;
    }
    if (!Mcu_EnableUsart3Clock()) {
        return UART_CLOCK_UNAVAILABLE;
    }
    const uint32 clockHz = Mcu_GetUsart3ClockHz();
    if (clockHz == 0U) {
        return UART_CLOCK_UNAVAILABLE;
    }
    /* 下标对应 PRESC 编码。优先选最小分频以保留 BRR 精度。 */
    static const uint16 divisors[] = {1U, 2U, 4U, 6U, 8U, 10U, 12U, 16U, 32U, 64U, 128U, 256U};
    uint32 presc;
    uint64_t divider = 0U;
    for (presc = 0U; presc < sizeof divisors / sizeof divisors[0]; ++presc) {
        const uint64_t scaledBaud = (uint64_t)divisors[presc] * baudRate;
        divider = ((uint64_t)clockHz + scaledBaud / 2U) / scaledBaud;
        if (divider <= UINT16_MAX) {
            break;
        }
    }
    if (divider < 16U || divider > UINT16_MAX) {
        return UART_INVALID_ARGUMENT;
    }

    initialized = false;
    UART_CR1 = 0U; /* UE=0 时再改帧格式和分频。 */
    UART_CR2 = 0U;
    UART_CR3 = 0U;
    UART_PRESC = presc;
    UART_BRR = (uint32)divider;
    UART_CR1 = UART_UE | UART_TE | UART_RE;

    Uart_ResultType result = Uart_Wait(UART_TEACK, 10U);
    if (result == UART_OK) {
        result = Uart_Wait(UART_REACK, 10U);
    }
    if (result == UART_OK) {
        UART_RQR = UART_RX_FLUSH;
        UART_ICR = UART_RX_ERRORS;
        initialized = true;
    } else {
        UART_CR1 = 0U;
    }
    return result;
}

Uart_ResultType Uart_DrvWriteByte(uint8 data, uint32 timeoutMs)
{
    if (!initialized) {
        return UART_NOT_INITIALIZED;
    }
    const Uart_ResultType result = Uart_Wait(UART_TXE, timeoutMs);
    if (result == UART_OK) {
        UART_TDR = data;
    }
    return result;
}

Uart_ResultType Uart_DrvReadByte(uint8 *data, uint32 timeoutMs)
{
    if (data == NULL) {
        return UART_INVALID_ARGUMENT;
    }
    if (!initialized) {
        return UART_NOT_INITIALIZED;
    }
    const Uart_ResultType result = Uart_Wait(UART_RXNE | UART_RX_ERRORS, timeoutMs);
    if (result != UART_OK) {
        return result;
    }
    const uint32 status = UART_ISR;
    const uint32 errors = status & UART_RX_ERRORS;
    if (errors != 0U) {
        /* 丢弃带错误的数据，写 1 清除状态后可继续接收。 */
        if ((status & UART_RXNE) != 0U) {
            (void)UART_RDR;
        }
        UART_ICR = errors;
        return UART_RX_ERROR;
    }
    *data = (uint8)UART_RDR;
    return UART_OK;
}
