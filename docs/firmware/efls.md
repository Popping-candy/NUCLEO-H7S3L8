# Efls 片内 Flash 驱动

[开发笔记](../README.md) · [内存与存储](memory-storage.md) · [Flash 寄存器](../reference/registers/memory-dma.md#flash)

Efls 是 STM32H7S3L8H6 的片内用户 Flash 驱动。Fls 留给板载外置 NOR。链接脚本将前 56 KiB 留给固件，将第 7 扇区（0x0800E000–0x0800FFFF，8 KiB）留给 Efls。所有参数使用相对于该区起点的字节偏移。

| 接口 | 用法 |
| --- | --- |
| Efls_Read | 读任意区内字节，调用者提供可写缓冲区。 |
| Efls_BlankCheck | 检查区间的可见字节是否全为 0xFF。 |
| Efls_Erase | 以 8 KiB 扇区为单位。当前调用参数为偏移 0、长度 EFLS_SECTOR_SIZE。擦除后检查全扇区。 |
| Efls_Write | 偏移和长度均按 16 字节对齐。要求目标区为擦除态，逐 Flash word 编程并读回。全 FF 块保持擦除态。 |
| Efls_GetLastFlashFlags | 读取最近一次实际擦写操作捕获的 FLASH_ISR。 |

[HAL](../../Drivers/Efls/hal/Efls.h) 定义接口与返回值。[DRV](../../Drivers/Efls/drv/Efls_Drv.c) 做边界、对齐和读回检查。[寄存器层](../../Drivers/Efls/reg/Efls_Reg.c) 解锁控制器、发起操作、轮询 BUSY/QW、检查错误并上锁。启动代码把擦写例程复制到 AXI SRAM。它沿用链接脚本现有的 .RamFunc 机制，链接了该例程的镜像会产生一个同时包含可写数据与可执行代码的 RAM 段，GNU ld 会提示 RWX。

接口用于启动后从线程上下文同步调用。擦写期间屏蔽可屏蔽中断。当前擦写要求 D-Cache 关闭。多块写入可能在部分完成后返回错误。轮询上限到达且控制器仍忙时保留操作位，等后续调用确认空闲再清理。读取接口按普通内存映射读取，Flash ECC 的异常处理仍遵循芯片机制。 [DS14359](https://www.st.com/resource/en/datasheet/stm32h7s3l8.pdf) · [RM0477](https://www.st.com/resource/en/reference_manual/rm0477-stm32h7rx7sx-armbased-32bit-mcus-stmicroelectronics.pdf) · [ST 器件头文件](https://github.com/STMicroelectronics/cmsis-device-h7rs/blob/main/Include/stm32h7s3xx.h)

## 2026-11-09 实板验证

- NUCLEO-H7S3L8 Rev B，CubeProgrammer 2.23.0、ST-LINK GDB Server 7.14.0、Arm GDB 14.3.1。SWD AP 1，片内调试 1 MHz，外置 NOR 只读转储 8 MHz。
- 实验前读回片内 64 KiB 与外置 NOR 32 MiB。片内前 7344 字节与流水灯 ELF 一致，其余扇区可见 OSPI、VCP、认证模式和时钟测试字符串，推测是较早的板级测试镜像残片。外置 0x70000000 有 Cortex-M 向量表特征，初始 SP 0x20010000，复位向量 0x70001119，含 h7l8_tcp_app 与 LwIP 字符串，推测是一个旧的网络应用。
- 临时测试固件只烧入扇区 0。预期在扇区 7 完成擦除、判空、首尾各写 16 字节、读回、拒绝重写与非法边界、再次擦除。GDB 的 eflsTest.stage = 100，各用例通过，FLASH_CR = 1、FLASH_SR = 0，控制器已上锁。RAM 擦写例程地址为 0x24000008。
- 实验后恢复原流水灯固件和扇区 7 内容。读回全部片内 65536 字节，与实验前 SHA-256 一致。外置 NOR 仅做读取。调试器已分离，流水灯继续运行。
