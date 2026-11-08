#include "Mcu_Reg.h"

extern const uint32 g_pfnVectors[];

void SystemInit(void)
{
    /* 在 .data/.bss 初始化前执行，只访问链接符号和 CPU 寄存器。 */
    MCU_SCB_VTOR = (uint32)(uintptr_t)g_pfnVectors;
    /* 工程按硬浮点 ABI 编译，给 FPU 的 CP10、CP11 完全访问权限。 */
    MCU_SCB_CPACR |= 0xFU << 20U;
    __asm volatile ("dsb\n\tisb" ::: "memory");
}
