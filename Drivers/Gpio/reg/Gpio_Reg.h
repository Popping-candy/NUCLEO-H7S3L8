#ifndef GPIO_REG_H
#define GPIO_REG_H

#include <stdbool.h>
#include <stddef.h>
#include "Gpio_Pins.h"

/* RM0477: GPIOx 寄存器按 4 字节排列。volatile 保证每次访问都到达外设。 */
typedef struct {
    volatile uint32 moder;
    volatile uint32 otyper;
    volatile uint32 ospeedr;
    volatile uint32 pupdr;
    volatile const uint32 idr;
    volatile uint32 odr;
    volatile uint32 bsrr;
} Gpio_RegBlock;

_Static_assert(offsetof(Gpio_RegBlock, idr) == 0x10U, "GPIO IDR offset");
_Static_assert(offsetof(Gpio_RegBlock, bsrr) == 0x18U, "GPIO BSRR offset");

#define GPIO_REG_RCC_AHB4ENR (*(volatile uint32 *)(uintptr_t)0x58024540UL)

/* 端口编号与 AHB4ENR 的位号一致。I～L 的编号是空洞，驱动层先校验。 */
static inline Gpio_RegBlock *Gpio_RegBlockAt(uint8 port)
{
    return (Gpio_RegBlock *)(uintptr_t)(0x58020000UL + 0x400UL * port);
}

/* 单核 Cortex-M7 临界区。保存并恢复原 PRIMASK，允许在已有临界区中调用。 */
static inline uint32 Gpio_RegLock(void)
{
    uint32 primask;
    __asm volatile ("mrs %0, primask\n\tcpsid i" : "=r"(primask) : : "memory");
    return primask;
}

static inline void Gpio_RegUnlock(uint32 primask)
{
    __asm volatile ("msr primask, %0" : : "r"(primask) : "memory");
}

static inline bool Gpio_RegClockEnabled(uint8 port)
{
    return (GPIO_REG_RCC_AHB4ENR & (1UL << port)) != 0U;
}

static inline void Gpio_RegEnableClock(uint8 port)
{
    GPIO_REG_RCC_AHB4ENR |= 1UL << port;
    /* 回读 RCC，给时钟门控生效留出时间，再访问 GPIO。 */
    (void)GPIO_REG_RCC_AHB4ENR;
}

static inline uint16 Gpio_RegReadInputs(uint8 port)
{
    return (uint16)Gpio_RegBlockAt(port)->idr;
}

static inline void Gpio_RegWriteOutputs(uint8 port, uint16 mask, uint16 level)
{
    /* BSRR 低半字置位，高半字清零。只写一次，无需读改写 ODR。 */
    const uint32 set = (uint32)(mask & level);
    const uint32 clear = (uint32)(mask & (uint16)~level);
    Gpio_RegBlockAt(port)->bsrr = set | (clear << 16U);
}

static inline void Gpio_RegSetDirection(uint8 port, uint8 pin, bool output)
{
    Gpio_RegBlock *gpio = Gpio_RegBlockAt(port);
    const uint32 shift = 2U * pin;
    /* MODER 每个引脚占两位，00 输入，01 输出，保留同端口其他引脚。 */
    gpio->moder = (gpio->moder & ~(3UL << shift)) | ((uint32)output << shift);
}

static inline void Gpio_RegConfigure(uint8 port, uint8 pin, bool output, uint8 pull, bool high)
{
    Gpio_RegBlock *gpio = Gpio_RegBlockAt(port);
    const uint16 bit = (uint16)(1UL << pin);
    const uint32 shift = 2U * pin;

    gpio->otyper &= ~(uint32)bit;       /* OTYPER = 0，推挽。 */
    gpio->ospeedr &= ~(3UL << shift);   /* OSPEEDR = 00，低速。 */
    gpio->pupdr = (gpio->pupdr & ~(3UL << shift)) | ((uint32)pull << shift);
    if (output) {
        /* 先预装输出锁存位，再切输出模式，避免由旧锁存值产生毛刺。 */
        Gpio_RegWriteOutputs(port, bit, high ? bit : 0U);
    }
    Gpio_RegSetDirection(port, pin, output);
}

#endif
