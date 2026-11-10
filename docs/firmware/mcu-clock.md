# MCU 启动与时钟

[开发笔记](../README.md) · [RCC 寄存器](../reference/registers/system.md#rcc)

当前固件从片内 Flash 启动。启动汇编先调用 [SystemInit](../../Drivers/Mcu/drv/Mcu_System.c) 设置 VTOR 和 FPU，再初始化 C 运行时。[main.c](../../Src/main.c) 在 Port 初始化之前配置 MCU 时钟。

| 层 | 文件 | 职责 |
| --- | --- | --- |
| HAL | [Mcu.h](../../Drivers/Mcu/hal/Mcu.h) | 初始化、选择时钟档、查询 PLL 锁定与分配 PLL 时钟，以及读取诊断数据。 |
| DRV | [Mcu_Drv.c](../../Drivers/Mcu/drv/Mcu_Drv.c) | 按硬件顺序切换时钟，等待硬件状态，计算频率和处理失败。 |
| REG | [Mcu_Reg.h](../../Drivers/Mcu/reg/Mcu_Reg.h) | RCC、PWR、FLASH_ACR 和 Cortex-M7 系统控制寄存器定义。 |

## 预设频率

| 方案 | SYSCLK 与 CPU | AHB | APB1 / APB2 / APB4 / APB5 |
| --- | ---: | ---: | ---: |
| MCU_CLOCK_HSI，复位默认 HSI /1 | 64 MHz | 64 MHz | 64 MHz |
| MCU_CLOCK_PLL1_192MHZ，兼容档 | 192 MHz | 96 MHz | 48 MHz |
| MCU_CLOCK_PLL1_600MHZ，默认档 | 600 MHz | 300 MHz | 150 MHz |

默认档使用板载 24 MHz HSE，PLL1P 为 24 MHz ÷ 2 × 50 ÷ 1，PLL 参考输入为 12 MHz。CPU /1、AXI/AHB /2、APB 再 /2。600 MHz 要求 VOS high 且 SRAM ECC 关闭。驱动只读 `FLASH_OBW2SR.ECC_ON_SRAM`，检测到 ECC 启用时记录 `MCU_CLOCK_SRAM_ECC_ENABLED` 并保持 HSI。 [DS14359 表 26 与 PLL 特性](https://www.st.com/resource/en/datasheet/stm32h7s3v8.pdf) · [ST 对 ECC 上限的说明](https://community.st.com/stm32-mcus-products-25/stm32h7s3l8h6-max-fcpu-with-axi-sram-ecc-enabled-ds14359-rev-6-table-26-footnote-8-168033)

启动先使用 HSI，选择 MB1737 的 Vcore LDO 并确认就绪，再请求 VOS high，等待 HSE 和 PLL1 就绪。切到 PLL1 前先设 Flash 等待周期和总线分频，确认 `RCC_CFGR.SWS` 后再更新 `SystemCoreClock`。默认档 Flash AXI 为 300 MHz，`LATENCY=7`、`WRHIGHFREQ=0b11`。192 MHz 兼容档使用 24 MHz ÷ 4 × 128 ÷ 4，Flash AXI 为 96 MHz，`LATENCY=2`、`WRHIGHFREQ=0b01`。 [AN6062 表 6](https://www.st.com/resource/en/application_note/an6062-introduction-to-stm32h7rx7sx-system-architecture-and-performance-stmicroelectronics.pdf) · [UM3276 §7.7](https://www.st.com/resource/en/user_manual/dm01032590.pdf) · [600 MHz 验证报告](clock-600mhz-report.md)

## USART3 外设时钟

启动阶段调用 `Mcu_EnableUsart3Clock()` 选择 PCLK1 并打开 USART3 门控。时钟选择器由 USART2/3 和 UART4/5/7/8 共用，驱动在已有同组外设使用其他来源时返回失败。`Mcu_GetUsart3ClockHz()` 从当前 RCC 分频推算频率，门控未开或来源不支持时返回 0。两种时钟档的分频值均已通过串口回显和 BRR 读回核对。 [USART3 实测](uart.md)

## 调试与回退

- 默认入口调用 Mcu_Init、Mcu_InitClock，再调用 Mcu_DistributePllClock。初始化返回后可用 Mcu_GetPllStatus 检查 PLL1RDY。选择 HSI 档时只调用前两个接口。
- PLL 启动或切换失败时，保留首个硬件失败阶段，尝试切回 HSI 并确认 SWS，然后恢复 HSI 的总线分频与 Flash 时序。回退结果独立保存。等待使用有上限的寄存器轮询次数。
- 在 [main.c](../../Src/main.c) 的 Port_Init 调用处停住后，可在 GDB 执行 `p mcuBootReport` 和 `p SystemCoreClock`。PLL 档预期 source 为 MCU_SOURCE_PLL1、error 为 MCU_CLOCK_OK。复位标志是 RCC_RSR 的原始快照，可同时出现 PORRSTF、PINRSTF、BORRSTF 等标志，驱动保留它们供排查。
- 可通过 `x/wx 0x58024400` 查看 PLL1RDY，`x/wx 0x58024410` 查看 SWS，`x/wx 0x52002000` 查看 Flash 时序。PLL 档预期 SWS 掩码结果为 0x18。默认 600 MHz 档的 FLASH_ACR 低六位为 0x37，192 MHz 兼容档为 0x12。 [600 MHz 寄存器读回](clock-600mhz-report.md)

## 2026-11-09 只读附加记录

- NUCLEO-H7S3L8，DBGMCU_IDCODE 为 0x20006485（器件 ID 0x485，硅版本 Rev B）。工具为 ST-LINK GDB Server 7.14.0 和 Arm GDB 14.3.1，SWD 1 MHz、AP 1。
- GDB 比对发现板上 .isr_vector 与 .text 均不同于当前 Debug ELF。旧镜像的寄存器实测为 RCC_CR = 0x25、RCC_CFGR = 0、PWR_CSR2 = 0x6、PWR_SR1 = 0。系统使用 HSI，ACTVOSRDY 未置位。
- 据此在源码补上从复位供电态选择 LDO 的步骤，后续烧录结果见下。只读会话以 detach 结束。

## 2026-11-09 原 192 MHz 档烧录后实测

- CubeProgrammer 2.23.0 通过 SWD 1 MHz、AP 1 擦写片内扇区 0，校验通过并复位。GDB 读回的 .isr_vector 和 .text 与本地 Debug ELF 字节一致。此次 compare-sections 的报告以读回比对为准。
- PWR_CSR2 = 0x2、PWR_SR1 = 0x3、PWR_CSR4 = 0x3，LDO 和高档 VOS 已就绪。RCC_CR = 0x03030025，PLL1RDY 置位。RCC_CFGR = 0x1B，SWS 确认当前时钟来自 PLL1。
- FLASH_ACR = 0x12。启动报告和寄存器分频配置一致，标称 CPU 192 MHz、AHB 96 MHz、APB1/2/4/5 各 48 MHz，error 为 MCU_CLOCK_OK。频率为寄存器推算值，待 MCO 实测。
- GPIOD_ODR = 0x0400，PD10 输出锁存位置位。单步 PC 从 0x080011F8 进入 0x08001254，随后 detach，固件继续运行。

