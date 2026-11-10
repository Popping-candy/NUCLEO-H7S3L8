# USART3 调试串口

[开发笔记](../README.md) · [Port / Dio](autosar-gpio.md) · [MCU 时钟](mcu-clock.md) · [命令行烧录](../toolchain/stlink-gdb-cli.md)

## 使用板载虚拟串口

将电脑接到板卡的 CN5（ST-LINK USB-C），使用 **115200、8 数据位、无校验、1 停止位、无流控** 打开板卡对应的 COM 口。可以用 STM32CubeProgrammer 的 `-l` 按板名找到端口，本机是 COM7。关闭终端的本地回显，复位后会收到 `NUCLEO-H7S3L8 USART3 ready`。终端发出的每个字节由固件原样返回，同时三灯继续按原顺序亮灭。

| MCU 引脚 | 复用 | 连线 |
| --- | --- | --- |
| PD8 | AF7 USART3_TX | MCU 发给 ST-LINK |
| PD9 | AF7 USART3_RX | MCU 接收 ST-LINK 数据 |

默认焊桥已连接这两条线，用 CN5 即可验证。 [UM3276 板卡手册](https://www.st.com/resource/en/user_manual/um3276-stm32h7rx7sx-nucleo144-board-mb1737-stmicroelectronics.pdf) · [DS14359 引脚复用表](https://www.st.com/resource/en/datasheet/stm32h7s3l8.pdf)

## 从配置到收发

1. [main.c](../../Src/main.c) 选定 MCU 时钟档并调用 `Delay_Init()` 启用 DWT 周期计数器。
2. [Port](../../Drivers/Port/drv/Port_Drv.c) 先整表校验，再启用 GPIOD 时钟，设置推挽、低速、上拉，写入 `AFRH` 中 PD8 和 PD9 的 AF7，最后将两脚的 `MODER` 设为 `10b`。上拉在 USART 启用前给线路提供空闲高电平。
3. [Mcu](../../Drivers/Mcu/drv/Mcu_Drv.c) 用 `RCC_CCIPR2.UART234578SEL=0` 选择 PCLK1，并置位 `RCC_APB1ENR1.USART3EN`。该内核时钟选择器由六个实例共用，其他实例启用且来源不同的时候会拒绝切换。
4. [Uart](../../Drivers/Uart/drv/Uart_Drv.c) 在 `CR1.UE=0` 时设帧格式和分频。优先使用能让 `BRR` 落入 16～65535 的最小 `PRESC` 分频，`BRR=round(PCLK1 / PRESC 分频值 / 波特率)`。使能收发后等待 `TEACK` 和 `REACK`，清理启动阶段的 RX 数据和错误。
5. 发字节时轮询 `ISR.TXE` 后写 `TDR`。收字节时检查 `ISR.RXNE` 与错误位，正常读取 `RDR`，异常时丢弃错误数据并写 `ICR` 清除相应标志。 [ST CMSIS 器件头文件](https://github.com/STMicroelectronics/cmsis-device-h7rs/blob/main/Include/stm32h7s3xx.h)

| 时钟档 | PCLK1 标称值 | 115200 对应 BRR |
| --- | ---: | ---: |
| PLL1，CPU 600 MHz，默认 | 150 MHz | 1302（`0x516`） |
| PLL1，CPU 192 MHz | 48 MHz | 417（`0x1A1`） |
| HSI，CPU 64 MHz | 64 MHz | 556（`0x22C`） |

## 接口与边界

[Uart.h](../../Drivers/Uart/hal/Uart.h) 提供 `Uart_Init(baudRate)`、`Uart_WriteByte(data, timeoutMs)`、`Uart_ReadByte(&data, timeoutMs)`。超时为 0 时只检查一次。大于 0 时用 DWT 计时，逐次采样并累计经过周期，支持超过一次计数回绕的等待。调用期间保持时钟与 DWT 配置稳定。发送成功表示字节已交给外设，最后一位是否发完可查看 `ISR.TC`。切换系统时钟后，需要在下一次通信前重新初始化串口。

本版由主循环独占 USART3，用轮询收发。应用在每段 LED 等待中查询 RX，收到后回显。当前启动日志直接调用 Uart，`printf()` 重定向、软件缓冲区、中断和 DMA 留待需要时加入。持续输入的处理能力取决于主循环多久轮询一次，收得太快时可能出现硬件溢出。

默认 600 MHz 档已验证 115200、1200 波特和 3.6 秒接收超时。 [600 MHz 验证报告](clock-600mhz-report.md)

## 2026-11-09 原 192 MHz 与 HSI 实板验证

- NUCLEO-H7S3L8（MB1737），硅版本 Rev B，器件 ID `0x485`。使用 Arm GCC 14.3.1、CubeProgrammer 2.23.0、ST-LINK GDB Server 7.14.0、Arm GDB 14.3.1。SWD 1 MHz、AP 1，VCP 使用 COM7。
- 两档各用 Release 优化级别构建，经 CubeProgrammer 擦写第 0 扇区并校验。每档分别做三次独立软件复位，启动行均正确，无尾随字节。每档在约两秒内分四批发送共 32 个字节，全部逐字节回显，包含 `00 0D 0A 55 7F 80 A5 FF`。
- GDB 读回两个引脚的 `MODER=10b`、`AFRH[7:0]=0x77`，`UART234578SEL=0`、`USART3EN=1`、`CR1=0xD`。HSI 档的 `SWS=0`、`BRR=0x22C`，PLL1 档的 `SWS=3`、`BRR=0x1A1`，与预期一致。
- 默认 PLL1 档在 Dio_WriteChannel 的硬件断点记录 7 次调用。灯序与原应用一致，相邻间隔为 192000761～192000862 个 DWT 周期，约 1 秒。片内 Efls 第 7 扇区的 8 KiB 读回与既有备份逐字节一致。
- 默认 PLL1 Release 镜像最终留在板上，GDB 已分离，固件继续运行。Debug 构建跨过首个扇区，本次用 Release 镜像烧录。
