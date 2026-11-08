#include "Gpio_Pins.h"

/* 1 = 此封装有对应的 GPIO 球位。按 ST STM32H7S3L8Hx.xml 的 GPIO 信号生成。 */
static const uint16 packagePins[GPIO_PORT_SLOTS] = {
    [GPIO_PORT_A] = 0xFFFFU,
    [GPIO_PORT_B] = 0xFFFFU,
    [GPIO_PORT_C] = 0xFFFFU,
    [GPIO_PORT_D] = 0xFFFFU,
    [GPIO_PORT_E] = 0xFFFFU,
    [GPIO_PORT_F] = 0xFFFFU,
    [GPIO_PORT_G] = 0xFFFFU,
    [GPIO_PORT_H] = 0x0003U,
    [GPIO_PORT_M] = 0x7B6FU,
    [GPIO_PORT_N] = 0x1FFFU,
    [GPIO_PORT_O] = 0x0037U,
    [GPIO_PORT_P] = 0x00FFU,
};

uint16 Gpio_PackageMask(uint8 port)
{
    return port < GPIO_PORT_SLOTS ? packagePins[port] : 0U;
}

bool Gpio_PinExists(uint16 pin)
{
    /* 先检查完整 ID，避免大编号截断成有效端口号。 */
    return pin < 16U * GPIO_PORT_SLOTS &&
           (Gpio_PackageMask(Gpio_PinPort(pin)) & Gpio_PinBit(pin)) != 0U;
}
