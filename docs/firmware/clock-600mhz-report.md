# 600 MHz 时钟升级与实板验证报告

[开发笔记](../README.md) · [MCU 时钟](mcu-clock.md) · [USART3](uart.md) · [Efls](efls.md)

2026-11-10 在 NUCLEO-H7S3L8（MB1737、STM32H7S3L8H6 Rev B、器件 ID `0x485`）验证。最终板上运行默认 600 MHz Release 固件，串口仍使用 CN5 的 COM7、115200、8N1、无流控。

## 时钟配置

| 项目 | 原默认档 | 新默认档 | 600 MHz 实板读回 |
| --- | --- | --- | --- |
| HSE、PLL1M/N/P | 24 MHz，4/128/4 | 24 MHz，2/50/1 | `PLLCKSELR` 来源与 M1 字段为 `0x22`，`PLL1DIVR1[15:0]=0x31` |
| SYSCLK、CPU | 192 MHz | 600 MHz | `PLL1RDY=1`、`SWS=3`、`CDCFGR[3:0]=0`、`SystemCoreClock=600000000` |
| AXI/AHB | 96 MHz | 300 MHz | `BMCFGR[3:0]=8`，CPU 时钟 /2 |
| APB1/2/4/5 | 48 MHz | 150 MHz | `APBCFGR & 0x7777=0x4444`，总线时钟再 /2 |
| Flash 等待周期、编程延迟档 | 2、01 | 7、11 | `FLASH_ACR & 0x3F=0x37` |
| 供电与 SRAM ECC | LDO、VOS high | LDO、VOS high，600 MHz 要求 SRAM ECC 关闭 | `PWR_CSR2=0x2`、`PWR_SR1=0x3`、`PWR_CSR4=0x3`，以上为各寄存器的供电和电压状态字段，均已就绪。 `FLASH_OBW2SR=0x00000200`，ECC 位为 0。 |

600 MHz 使用 DS14359 的 VOS high 条件，AXI/AHB 和 APB 分别在 300 MHz 和 150 MHz 的额定上限。VOS high 的结温上限为 105 °C。ST 确认 SRAM ECC 启用时，VOS high 下 CPU 上限为 400 MHz。Flash 时序按 300 MHz AXI 时钟设置。 [DS14359 表 26、27](https://www.st.com/resource/en/datasheet/stm32h7s3v8.pdf) · [ST 对 ECC 上限的说明](https://community.st.com/stm32-mcus-products-25/stm32h7s3l8h6-max-fcpu-with-axi-sram-ecc-enabled-ds14359-rev-6-table-26-footnote-8-168033) · [AN6062 表 6](https://www.st.com/resource/en/application_note/an6062-introduction-to-stm32h7rx7sx-system-architecture-and-performance-stmicroelectronics.pdf)

## 模块适配与实测

| 模块 | 适配 | 实板结果 |
| --- | --- | --- |
| Mcu | 新增 600 MHz 预设，启动时确认 LDO 与 VOS 就绪，先设置 Flash 时序和总线分频，再切换到 PLL1。保留 192 MHz 兼容档和 HSI 64 MHz 回退。 | 最终镜像连续三次独立软件复位均收到启动行。192 MHz 兼容档实测 `FLASH_ACR=0x12`。临时固件模拟 SRAM ECC 启用，启动报告记录 `MCU_CLOCK_SRAM_ECC_ENABLED`，实测留在 HSI 64 MHz。模拟通过软件注入状态，未编程选项字节。 |
| Uart | USART3 仍取 PCLK1。自动选择合适的 `PRESC` 和 `BRR`，低速波特率仍可使用。超时按采样间隔累计 DWT 周期。 | 115200 时 `PRESC=/1`、`BRR=0x516`，一次发送全部 256 个字节值，逐字节回显一致。1200 时实测 `PRESC=/2`、`BRR=0xF424`，启动行与 5 字节回显通过。3600 ms 空收返回 `UART_TIMEOUT`，经过 2,160,001,122 周期。192 MHz 档和 HSI 回退均通过 115200 启动与回显。 |
| Delay | `Delay_Us` 和 `Delay_Ms` 已按 `SystemCoreClock` 计算周期。长延时按块等待，应用的 1 秒步进也取当前核心频率。 | 请求 123 µs 实测 75,006 周期，约 125.01 µs，包含调用和测量开销。请求 12 ms 实测 7,201,016 周期，约 12.002 ms。 |
| Port / Dio | GPIO 的门控、引脚模式与电气配置沿用原接口。外设总线提频，LED 的节拍由 DWT 控制。 | PD8/PD9 的 AF7 和复用模式读回正确，PC13 的输入及上拉配置读回正确。连续 7 次 LED 操作的灯序正确，6 个相邻间隔为 600,001,285～600,001,494 周期，约 1 秒，记录中跨过一次计数回绕。 |
| Efls | 片内擦写沿用 AXI SRAM 执行路径。擦除和每个 16 字节编程的轮询预算用 DWT 计为 3 秒。Flash 忙时直接读 DWT 寄存器。 | 第 7 扇区擦除、判空、首尾编程、读回、拒绝二次编程和非法擦除范围均通过。首次擦除含判空约 3.33 ms。恢复后 `FLASH_CR=1`、`FLASH_SR=0`。第 1～7 扇区的 56 KiB 与实验前备份逐字节一致。 |

Fls/XSPI、定时器和其他计划中的通信驱动尚未接入应用。后续驱动需从 Mcu 查询实际总线或内核时钟，再计算外设分频和超时。

## 验证环境与范围

- Arm GCC 14.3.1 的 Debug 和 Release 构建均通过，默认镜像占用片内 Flash 分别为 9,680 B 和 6,064 B。板上测试使用 Release 和临时 Release 变体，装载数据均落在第 0 扇区。Efls 临时镜像使用现有 `.RamFunc` 链接布局，GNU ld 报告包含擦写代码的 RAM 段为 RWX。
- 使用 CubeProgrammer 2.23.0 下载与校验，使用 ST-LINK GDB Server 7.14.0 和 Arm GDB 14.3.1 读回。SWD 1 MHz、AP 1，探针报告目标电压 3.27 V。最终恢复正式镜像，已分离 GDB。
- 频率由板载 24 MHz HSE 标称值和寄存器配置推算。实板覆盖软件复位、串口收发和关键时序回归。绝对频率的仪器测量、断电冷启动及温升和长时稳定性待实测。
