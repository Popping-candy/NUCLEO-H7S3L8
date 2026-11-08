#ifndef GPIO_PINS_H
#define GPIO_PINS_H

#include <stdbool.h>
#include "Std_Types.h"

/* STM32H7S3L8H6，TFBGA225 OCTO SMPS。端口号沿用 RCC 位号。 */
enum {
    GPIO_PORT_A = 0,
    GPIO_PORT_B = 1,
    GPIO_PORT_C = 2,
    GPIO_PORT_D = 3,
    GPIO_PORT_E = 4,
    GPIO_PORT_F = 5,
    GPIO_PORT_G = 6,
    GPIO_PORT_H = 7,
    GPIO_PORT_M = 12,
    GPIO_PORT_N = 13,
    GPIO_PORT_O = 14,
    GPIO_PORT_P = 15,
    GPIO_PORT_SLOTS = 16
};

/* 引脚编号 = 端口号 × 16 + 端口内位号。右侧注释为封装球位。 */
enum {

    GPIO_PIN_PA0 = 16U * GPIO_PORT_A + 0U,  /* M1 */
    GPIO_PIN_PA1 = 16U * GPIO_PORT_A + 1U,  /* M2 */
    GPIO_PIN_PA2 = 16U * GPIO_PORT_A + 2U,  /* L4 */
    GPIO_PIN_PA3 = 16U * GPIO_PORT_A + 3U,  /* N1 */
    GPIO_PIN_PA4 = 16U * GPIO_PORT_A + 4U,  /* M3 */
    GPIO_PIN_PA5 = 16U * GPIO_PORT_A + 5U,  /* N2 */
    GPIO_PIN_PA6 = 16U * GPIO_PORT_A + 6U,  /* P1 */
    GPIO_PIN_PA7 = 16U * GPIO_PORT_A + 7U,  /* M4 */
    GPIO_PIN_PA8 = 16U * GPIO_PORT_A + 8U,  /* F12 */
    GPIO_PIN_PA9 = 16U * GPIO_PORT_A + 9U,  /* D14 */
    GPIO_PIN_PA10 = 16U * GPIO_PORT_A + 10U,  /* E13 */
    GPIO_PIN_PA11 = 16U * GPIO_PORT_A + 11U,  /* C15 */
    GPIO_PIN_PA12 = 16U * GPIO_PORT_A + 12U,  /* C14 */
    GPIO_PIN_PA13 = 16U * GPIO_PORT_A + 13U,  /* E12 */
    GPIO_PIN_PA14 = 16U * GPIO_PORT_A + 14U,  /* D13 */
    GPIO_PIN_PA15 = 16U * GPIO_PORT_A + 15U,  /* G11 */

    GPIO_PIN_PB0 = 16U * GPIO_PORT_B + 0U,  /* P2 */
    GPIO_PIN_PB1 = 16U * GPIO_PORT_B + 1U,  /* R2 */
    GPIO_PIN_PB2 = 16U * GPIO_PORT_B + 2U,  /* N4 */
    GPIO_PIN_PB3 = 16U * GPIO_PORT_B + 3U,  /* C4 */
    GPIO_PIN_PB4 = 16U * GPIO_PORT_B + 4U,  /* D5 */
    GPIO_PIN_PB5 = 16U * GPIO_PORT_B + 5U,  /* B3 */
    GPIO_PIN_PB6 = 16U * GPIO_PORT_B + 6U,  /* E5 */
    GPIO_PIN_PB7 = 16U * GPIO_PORT_B + 7U,  /* D4 */
    GPIO_PIN_PB8 = 16U * GPIO_PORT_B + 8U,  /* B1 */
    GPIO_PIN_PB9 = 16U * GPIO_PORT_B + 9U,  /* C2 */
    GPIO_PIN_PB10 = 16U * GPIO_PORT_B + 10U,  /* P15 */
    GPIO_PIN_PB11 = 16U * GPIO_PORT_B + 11U,  /* N14 */
    GPIO_PIN_PB12 = 16U * GPIO_PORT_B + 12U,  /* L12 */
    GPIO_PIN_PB13 = 16U * GPIO_PORT_B + 13U,  /* N15 */
    GPIO_PIN_PB14 = 16U * GPIO_PORT_B + 14U,  /* M13 */
    GPIO_PIN_PB15 = 16U * GPIO_PORT_B + 15U,  /* M14 */

    GPIO_PIN_PC0 = 16U * GPIO_PORT_C + 0U,  /* K3 */
    GPIO_PIN_PC1 = 16U * GPIO_PORT_C + 1U,  /* L1 */
    GPIO_PIN_PC2 = 16U * GPIO_PORT_C + 2U,  /* L2 */
    GPIO_PIN_PC3 = 16U * GPIO_PORT_C + 3U,  /* L3 */
    GPIO_PIN_PC4 = 16U * GPIO_PORT_C + 4U,  /* L5 */
    GPIO_PIN_PC5 = 16U * GPIO_PORT_C + 5U,  /* N3 */
    GPIO_PIN_PC6 = 16U * GPIO_PORT_C + 6U,  /* E15 */
    GPIO_PIN_PC7 = 16U * GPIO_PORT_C + 7U,  /* F13 */
    GPIO_PIN_PC8 = 16U * GPIO_PORT_C + 8U,  /* D15 */
    GPIO_PIN_PC9 = 16U * GPIO_PORT_C + 9U,  /* E14 */
    GPIO_PIN_PC10 = 16U * GPIO_PORT_C + 10U,  /* B14 */
    GPIO_PIN_PC11 = 16U * GPIO_PORT_C + 11U,  /* B15 */
    GPIO_PIN_PC12 = 16U * GPIO_PORT_C + 12U,  /* D12 */
    GPIO_PIN_PC13 = 16U * GPIO_PORT_C + 13U,  /* E4 */
    GPIO_PIN_PC14 = 16U * GPIO_PORT_C + 14U,  /* D2 */
    GPIO_PIN_PC15 = 16U * GPIO_PORT_C + 15U,  /* D1 */

    GPIO_PIN_PD0 = 16U * GPIO_PORT_D + 0U,  /* C13 */
    GPIO_PIN_PD1 = 16U * GPIO_PORT_D + 1U,  /* B13 */
    GPIO_PIN_PD2 = 16U * GPIO_PORT_D + 2U,  /* A14 */
    GPIO_PIN_PD3 = 16U * GPIO_PORT_D + 3U,  /* A12 */
    GPIO_PIN_PD4 = 16U * GPIO_PORT_D + 4U,  /* C11 */
    GPIO_PIN_PD5 = 16U * GPIO_PORT_D + 5U,  /* D7 */
    GPIO_PIN_PD6 = 16U * GPIO_PORT_D + 6U,  /* E7 */
    GPIO_PIN_PD7 = 16U * GPIO_PORT_D + 7U,  /* B6 */
    GPIO_PIN_PD8 = 16U * GPIO_PORT_D + 8U,  /* M11 */
    GPIO_PIN_PD9 = 16U * GPIO_PORT_D + 9U,  /* P13 */
    GPIO_PIN_PD10 = 16U * GPIO_PORT_D + 10U,  /* R14 */
    GPIO_PIN_PD11 = 16U * GPIO_PORT_D + 11U,  /* M12 */
    GPIO_PIN_PD12 = 16U * GPIO_PORT_D + 12U,  /* N13 */
    GPIO_PIN_PD13 = 16U * GPIO_PORT_D + 13U,  /* P14 */
    GPIO_PIN_PD14 = 16U * GPIO_PORT_D + 14U,  /* L14 */
    GPIO_PIN_PD15 = 16U * GPIO_PORT_D + 15U,  /* L13 */

    GPIO_PIN_PE0 = 16U * GPIO_PORT_E + 0U,  /* A2 */
    GPIO_PIN_PE1 = 16U * GPIO_PORT_E + 1U,  /* C3 */
    GPIO_PIN_PE2 = 16U * GPIO_PORT_E + 2U,  /* B2 */
    GPIO_PIN_PE3 = 16U * GPIO_PORT_E + 3U,  /* F5 */
    GPIO_PIN_PE4 = 16U * GPIO_PORT_E + 4U,  /* E2 */
    GPIO_PIN_PE5 = 16U * GPIO_PORT_E + 5U,  /* F4 */
    GPIO_PIN_PE6 = 16U * GPIO_PORT_E + 6U,  /* E1 */
    GPIO_PIN_PE7 = 16U * GPIO_PORT_E + 7U,  /* M6 */
    GPIO_PIN_PE8 = 16U * GPIO_PORT_E + 8U,  /* R4 */
    GPIO_PIN_PE9 = 16U * GPIO_PORT_E + 9U,  /* P5 */
    GPIO_PIN_PE10 = 16U * GPIO_PORT_E + 10U,  /* R5 */
    GPIO_PIN_PE11 = 16U * GPIO_PORT_E + 11U,  /* C12 */
    GPIO_PIN_PE12 = 16U * GPIO_PORT_E + 12U,  /* E11 */
    GPIO_PIN_PE13 = 16U * GPIO_PORT_E + 13U,  /* B12 */
    GPIO_PIN_PE14 = 16U * GPIO_PORT_E + 14U,  /* A13 */
    GPIO_PIN_PE15 = 16U * GPIO_PORT_E + 15U,  /* D11 */

    GPIO_PIN_PF0 = 16U * GPIO_PORT_F + 0U,  /* B5 */
    GPIO_PIN_PF1 = 16U * GPIO_PORT_F + 1U,  /* C5 */
    GPIO_PIN_PF2 = 16U * GPIO_PORT_F + 2U,  /* A4 */
    GPIO_PIN_PF3 = 16U * GPIO_PORT_F + 3U,  /* A3 */
    GPIO_PIN_PF4 = 16U * GPIO_PORT_F + 4U,  /* B4 */
    GPIO_PIN_PF5 = 16U * GPIO_PORT_F + 5U,  /* G3 */
    GPIO_PIN_PF6 = 16U * GPIO_PORT_F + 6U,  /* H5 */
    GPIO_PIN_PF7 = 16U * GPIO_PORT_F + 7U,  /* H4 */
    GPIO_PIN_PF8 = 16U * GPIO_PORT_F + 8U,  /* H3 */
    GPIO_PIN_PF9 = 16U * GPIO_PORT_F + 9U,  /* J2 */
    GPIO_PIN_PF10 = 16U * GPIO_PORT_F + 10U,  /* J3 */
    GPIO_PIN_PF11 = 16U * GPIO_PORT_F + 11U,  /* M5 */
    GPIO_PIN_PF12 = 16U * GPIO_PORT_F + 12U,  /* R3 */
    GPIO_PIN_PF13 = 16U * GPIO_PORT_F + 13U,  /* P3 */
    GPIO_PIN_PF14 = 16U * GPIO_PORT_F + 14U,  /* P4 */
    GPIO_PIN_PF15 = 16U * GPIO_PORT_F + 15U,  /* N5 */

    GPIO_PIN_PG0 = 16U * GPIO_PORT_G + 0U,  /* B11 */
    GPIO_PIN_PG1 = 16U * GPIO_PORT_G + 1U,  /* E10 */
    GPIO_PIN_PG2 = 16U * GPIO_PORT_G + 2U,  /* C6 */
    GPIO_PIN_PG3 = 16U * GPIO_PORT_G + 3U,  /* A5 */
    GPIO_PIN_PG4 = 16U * GPIO_PORT_G + 4U,  /* N6 */
    GPIO_PIN_PG5 = 16U * GPIO_PORT_G + 5U,  /* P6 */
    GPIO_PIN_PG6 = 16U * GPIO_PORT_G + 6U,  /* M7 */
    GPIO_PIN_PG7 = 16U * GPIO_PORT_G + 7U,  /* N7 */
    GPIO_PIN_PG8 = 16U * GPIO_PORT_G + 8U,  /* P7 */
    GPIO_PIN_PG9 = 16U * GPIO_PORT_G + 9U,  /* R7 */
    GPIO_PIN_PG10 = 16U * GPIO_PORT_G + 10U,  /* R13 */
    GPIO_PIN_PG11 = 16U * GPIO_PORT_G + 11U,  /* F3 */
    GPIO_PIN_PG12 = 16U * GPIO_PORT_G + 12U,  /* F2 */
    GPIO_PIN_PG13 = 16U * GPIO_PORT_G + 13U,  /* G5 */
    GPIO_PIN_PG14 = 16U * GPIO_PORT_G + 14U,  /* F1 */
    GPIO_PIN_PG15 = 16U * GPIO_PORT_G + 15U,  /* G4 */

    GPIO_PIN_PH0 = 16U * GPIO_PORT_H + 0U,  /* K1 */
    GPIO_PIN_PH1 = 16U * GPIO_PORT_H + 1U,  /* K2 */

    GPIO_PIN_PM0 = 16U * GPIO_PORT_M + 0U,  /* D10 */
    GPIO_PIN_PM1 = 16U * GPIO_PORT_M + 1U,  /* C10 */
    GPIO_PIN_PM2 = 16U * GPIO_PORT_M + 2U,  /* B10 */
    GPIO_PIN_PM3 = 16U * GPIO_PORT_M + 3U,  /* A10 */
    GPIO_PIN_PM5 = 16U * GPIO_PORT_M + 5U,  /* B9 */
    GPIO_PIN_PM6 = 16U * GPIO_PORT_M + 6U,  /* A9 */
    GPIO_PIN_PM8 = 16U * GPIO_PORT_M + 8U,  /* C9 */
    GPIO_PIN_PM9 = 16U * GPIO_PORT_M + 9U,  /* B8 */
    GPIO_PIN_PM11 = 16U * GPIO_PORT_M + 11U,  /* B7 */
    GPIO_PIN_PM12 = 16U * GPIO_PORT_M + 12U,  /* A7 */
    GPIO_PIN_PM13 = 16U * GPIO_PORT_M + 13U,  /* C7 */
    GPIO_PIN_PM14 = 16U * GPIO_PORT_M + 14U,  /* C8 */

    GPIO_PIN_PN0 = 16U * GPIO_PORT_N + 0U,  /* G14 */
    GPIO_PIN_PN1 = 16U * GPIO_PORT_N + 1U,  /* F14 */
    GPIO_PIN_PN2 = 16U * GPIO_PORT_N + 2U,  /* H15 */
    GPIO_PIN_PN3 = 16U * GPIO_PORT_N + 3U,  /* G13 */
    GPIO_PIN_PN4 = 16U * GPIO_PORT_N + 4U,  /* K14 */
    GPIO_PIN_PN5 = 16U * GPIO_PORT_N + 5U,  /* K15 */
    GPIO_PIN_PN6 = 16U * GPIO_PORT_N + 6U,  /* J14 */
    GPIO_PIN_PN7 = 16U * GPIO_PORT_N + 7U,  /* J13 */
    GPIO_PIN_PN8 = 16U * GPIO_PORT_N + 8U,  /* K13 */
    GPIO_PIN_PN9 = 16U * GPIO_PORT_N + 9U,  /* H14 */
    GPIO_PIN_PN10 = 16U * GPIO_PORT_N + 10U,  /* H13 */
    GPIO_PIN_PN11 = 16U * GPIO_PORT_N + 11U,  /* G15 */
    GPIO_PIN_PN12 = 16U * GPIO_PORT_N + 12U,  /* L15 */

    GPIO_PIN_PO0 = 16U * GPIO_PORT_O + 0U,  /* N12 */
    GPIO_PIN_PO1 = 16U * GPIO_PORT_O + 1U,  /* P8 */
    GPIO_PIN_PO2 = 16U * GPIO_PORT_O + 2U,  /* P11 */
    GPIO_PIN_PO4 = 16U * GPIO_PORT_O + 4U,  /* R10 */
    GPIO_PIN_PO5 = 16U * GPIO_PORT_O + 5U,  /* R9 */

    GPIO_PIN_PP0 = 16U * GPIO_PORT_P + 0U,  /* N10 */
    GPIO_PIN_PP1 = 16U * GPIO_PORT_P + 1U,  /* P12 */
    GPIO_PIN_PP2 = 16U * GPIO_PORT_P + 2U,  /* N8 */
    GPIO_PIN_PP3 = 16U * GPIO_PORT_P + 3U,  /* N9 */
    GPIO_PIN_PP4 = 16U * GPIO_PORT_P + 4U,  /* R8 */
    GPIO_PIN_PP5 = 16U * GPIO_PORT_P + 5U,  /* P10 */
    GPIO_PIN_PP6 = 16U * GPIO_PORT_P + 6U,  /* R11 */
    GPIO_PIN_PP7 = 16U * GPIO_PORT_P + 7U,  /* N11 */
};

enum { GPIO_PIN_COUNT = 152 };

uint16 Gpio_PackageMask(uint8 port);
bool Gpio_PinExists(uint16 pin);

static inline uint8 Gpio_PinPort(uint16 pin)
{
    return (uint8)(pin / 16U);
}

static inline uint8 Gpio_PinIndex(uint16 pin)
{
    return (uint8)(pin % 16U);
}

static inline uint16 Gpio_PinBit(uint16 pin)
{
    return (uint16)(1UL << Gpio_PinIndex(pin));
}

#endif
