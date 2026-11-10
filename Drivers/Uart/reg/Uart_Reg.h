#ifndef UART_REG_H
#define UART_REG_H

#include "Std_Types.h"

#define UART_REG32(offset) (*(volatile uint32 *)(uintptr_t)(0x40004800U + (offset)))
#define UART_CR1   UART_REG32(0x00U)
#define UART_CR2   UART_REG32(0x04U)
#define UART_CR3   UART_REG32(0x08U)
#define UART_BRR   UART_REG32(0x0CU)
#define UART_RQR   UART_REG32(0x18U)
#define UART_ISR   UART_REG32(0x1CU)
#define UART_ICR   UART_REG32(0x20U)
#define UART_RDR   UART_REG32(0x24U)
#define UART_TDR   UART_REG32(0x28U)
#define UART_PRESC UART_REG32(0x2CU)

#define UART_UE      (1U << 0U)
#define UART_RE      (1U << 2U)
#define UART_TE      (1U << 3U)
#define UART_RXNE    (1U << 5U)
#define UART_TXE     (1U << 7U)
#define UART_TEACK   (1U << 21U)
#define UART_REACK   (1U << 22U)
/* ISR 与 ICR 的 PE、FE、NE、ORE 位号一致。 */
#define UART_RX_ERRORS 0xFU
#define UART_RX_FLUSH (1U << 3U)

#endif
