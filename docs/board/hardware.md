# NUCLEO-H7S3L8 原理图与接线

[开发笔记](../README.md) · [上电与调试](../firmware/bringup-debug.md) · [外设实验](peripherals-io.md) · [官方资料对照](../reference/references.md)

本文以 **MB1737-H7S3L8-B02** 为基线，跳线和焊桥按出厂配置描述。接线前对照板背版本贴纸和实物。**灯数和连线来自 ST 手册与原理图**。本项目已实测 Rev B 的 ST-LINK 烧录、指令步进和三灯 GPIO 切换。串口输出及断电冷启动仍待验证。 [UM3276](https://www.st.com/resource/en/user_manual/um3276-stm32h7rx7sx-nucleo144-board-mb1737-stmicroelectronics.pdf) · [B02 原理图](https://www.st.com/resource/en/schematic_pack/mb1737-h7s3l8-b02-schematic.pdf) · [命令行调试实测](../toolchain/stlink-gdb-cli.md)

## 先辨认板子与接口

| 板上标号 | 对应电路 | 日常用途 |
| --- | --- | --- |
| U12 | 目标 STM32H7S3L8H6 | 运行项目固件 |
| U14、CN5 | 板载 STLINK-V3EC 和它的 USB-C | 默认供电、SWD 烧录与调试、VCP 串口 |
| CN1 | MIPI20 | 外接 SWD/JTAG 探针或 Trace |
| CN2 | 目标 MCU 的 USB-C | USB 2.0 HS 数据及 Type-C 供受电 |
| CN4 | RJ45，连接 LAN8742A PHY | 10/100 Mbit/s 以太网，插座有两个灯 |
| CN7–CN10 | ST Zio | Arduino Uno V3 兼容位置及附加引脚 |
| CN11/CN12 | ST morpho | 更多 MCU 引脚、电源和复位信号 |

原理图第 2 页是总图，第 3–4 页是 MCU 引脚和电源，第 5 页是 NOR，第 6 页是排针和用户灯相关接线，第 7–10 页依次是以太网、用户 USB、供电和 ST-LINK。跨页追线时按**网络名**查找。查排针时同时核对 **连接器编号、物理脚号、Arduino 标号、MCU 引脚**，例如 `CN7.10 → D13 → PA5`。 `SB` 是焊桥，`JP` 是跳线，`DNF` 表示默认不装。 [B02 原理图目录](https://www.st.com/resource/en/schematic_pack/mb1737-h7s3l8-b02-schematic.pdf#page=1) · [UM3276 §7–8](https://www.st.com/resource/en/user_manual/um3276-stm32h7rx7sx-nucleo144-board-mb1737-stmicroelectronics.pdf#page=10)

## 供电、跳线和指示灯

### 电源路径和跳线

默认只接一根支持数据的线到 **CN5**。ST-LINK 枚举成功后，经 `T_PWR_EN` 使能 U10 的电子保险丝，`5V_STLK` 经过 JP3 进入板上 5 V。LD5 监视这条 5 V 电源轨。板上稳压电路提供 3.3 V 和 1.8 V，JP5 选择 MCU VDD，经过 JP2 后进入 `VDD_MCU`。

| 跳线 | 默认 | 切换或测量时怎么用 |
| --- | --- | --- |
| JP1 | 开路 | 板载 ST-LINK。闭合时选择外接探针，按 CN1 接线 |
| JP2 | 短接 | 给 MCU 供电。测 MCU 电流时用电流表替换短接帽，串联测量 |
| JP3 | 1–2 | 选择板上 5 V 的来源，见下表 |
| JP5 | 1–2 | 选择 3.3 V VDD；2–3 选 1.8 V，切换前核对扩展电路电平 |

| JP3 位置 | 来源 | 接线 |
| --- | --- | --- |
| 1–2 | ST-LINK USB | CN5 |
| 3–4 | VIN，7–12 V | CN8.15 或 CN11.24，经板上稳压转成 5 V |
| 5–6 | 外部稳压 5 V | CN11.6（`5V_EXT`） |
| 7–8 | 用户 USB 供电 | CN2 作为受电端 |

外部电源要共地。用外部电源调试时先选 JP3、接线并给目标板上电，再接 CN5。默认供电时，CN8.9／CN11.18 是板上 5 V 电源轨，CN8.7／CN11.16 是 3.3 V 电源轨。**CN11.6 和 CN11.18 用途不同。** LD5 亮而 SWD 连不上时，检查 JP2、JP5、目标 `VDD_MCU` 和 NRST。 [B02 原理图第 9–10 页](https://www.st.com/resource/en/schematic_pack/mb1737-h7s3l8-b02-schematic.pdf#page=9) · [UM3276 表 5、表 8 与 §7.4](https://www.st.com/resource/en/user_manual/um3276-stm32h7rx7sx-nucleo144-board-mb1737-stmicroelectronics.pdf#page=15)

### 共有多少指示灯

**PCB 上有 7 个独立指示灯，CN4 网口集成 2 个，合计 9 个可见灯位。** 能用目标 MCU GPIO 控制的是 LD1、LD2、LD3。独立灯编号跳过 LD6、LD7，多色灯按物理灯位计数。

| 灯位 | 颜色 | 电路与判读 |
| --- | --- | --- |
| **LD1** | 绿 | 默认 PD10，经 SB50 控制。断开 SB50 并接通 SB49 可改为 PA5/D13 |
| **LD2** | 黄 | PD13 控制 |
| **LD3** | 红 | PB7 控制 |
| **LD4** | 绿 | CN2 的 VBUS 指示，板子从该口受电或对外供电时可亮。USB 数据枚举要另查 |
| **LD5** | 绿 | 板上 5 V 电源轨有电。目标 VDD 仍需独立核对 |
| **LD8** | 红／绿／橙 | ST-LINK 通信状态。电脑侧初始化完成可为红色，建立目标通信后可为绿色，通信时可红绿快闪，橙色表示通信故障 |
| **LD9** | 红／绿／橙 | ST-LINK 目标供电状态。绿为供电能力满足请求，橙为不足，红色常亮为过流切断。熄灭时目标可能由其他路径供电 |
| **CN4 内置两灯** | 绿、黄 | 由以太网 PHY 的 LED 信号驱动，具体显示随 PHY 配置 |

LD1～LD3 都是**高电平亮、低电平灭**。以 LD1 为例，PD10 高电平让三极管导通，电流由 3V3 经限流电阻和 LED 流向地。固件配置 PD10 为推挽输出后即可用板载绿灯验证 GPIO。 [UM3276 §7.5](https://www.st.com/resource/en/user_manual/um3276-stm32h7rx7sx-nucleo144-board-mb1737-stmicroelectronics.pdf#page=21) · [B02 原理图第 6–10 页](https://www.st.com/resource/en/schematic_pack/mb1737-h7s3l8-b02-schematic.pdf#page=6)

### 断电重启

仅由 CN5 供电且 JP3 在 1–2 时，拔 CN5 或关闭能**实际切断 VBUS** 的 USB 端口可让板子断电。Windows 禁用设备或选择性挂起不能保证切断 5 V。要从电脑控制，取决于 USB Hub 能否实际逐口切断 VBUS 及其 Windows 控制工具。

操作前退出调试并等写入结束。LD5 熄灭是初步判断，确认冷启动可测目标 `VDD_MCU` 降至接近 0 V。若 CN2、外部电源或有源扩展模块仍连接，逐一核对其他供电或反向供电路径。B1 复位只拉低 NRST，冷启动验证需走实际断电再上电。 [UM3276 §7.4–7.5](https://www.st.com/resource/en/user_manual/um3276-stm32h7rx7sx-nucleo144-board-mb1737-stmicroelectronics.pdf#page=15) · [Microsoft USB 选择性挂起](https://learn.microsoft.com/en-us/windows-hardware/drivers/usbcon/usb-selective-suspend)

## 板载信号速查

| 功能 | 引脚或连接 | 验证与限制 |
| --- | --- | --- |
| SWD | PA13（SWDIO）、PA14（SWCLK）、NRST | 板载 ST-LINK 走 CN5。外接 CN1 时，1 为目标 VDD 参考，2 为 SWDIO，4 为 SWCLK，10 为 NRST，并接地 |
| SWO | PB3 | 与 Zio D23 的 SPI3/I²S 时钟共享 |
| VCP | USART3，PD8 TX、PD9 RX | 经板载 ST-LINK 从 CN5 枚举为 COM 口。固件与电脑终端可从 115200、8N1、无流控开始 |
| B1 RESET | NRST | 按下拉低。板载探针、CN8.5、CN11.14 也接到复位网络 |
| B2 USER | PC13 | 按下为低，EXTI 实验可用下降沿并处理消抖 |
| HSE | X1，24 MHz | 默认晶体路径。8 MHz ST-LINK MCO 是另一条焊桥路径 |
| LSE | X2，32.768 kHz | RTC 等低速计时用途 |
| BOOT0 | CN11.7，默认下拉 | CN11.5 为 VDD。引脚能否改变启动入口取决于选项字节和产品状态 |

[UM3276 表 7、§7.6–7.10](https://www.st.com/resource/en/user_manual/um3276-stm32h7rx7sx-nucleo144-board-mb1737-stmicroelectronics.pdf#page=14) · [B02 原理图第 3、10 页](https://www.st.com/resource/en/schematic_pack/mb1737-h7s3l8-b02-schematic.pdf#page=3)

## 用户 USB、以太网与外部 Flash

| 模块 | 板内连接和排查入口 |
| --- | --- |
| **CN2 用户 USB-C** | PM5/PM6 是 D−/D+，经保护和滤波接目标 MCU 的 USB HS PHY。PM0/PM1 是 CC1/CC2。TCPP03-M20 管理 Type-C 的供受电路径，先确认 VBUS 和电源角色，再查 USB 枚举 |
| **CN4 以太网** | STM32 MAC 通过 RMII 连到 U15 LAN8742A，经过隔离变压器到 RJ45。PB6 为参考时钟，PG6/PA2 为 MDC/MDIO，PA7 为接收有效，PG4/PG5 为接收数据，PG11/PG13/PG12 为发送使能和数据。排查时先查 PHY 电源、时钟和管理接口，再查 MAC 和网络栈 |
| **U18 外部 NOR** | MX25UW25645G，256 Mbit（32 MiB），板上 1.8 V。CLK 和 NCS 分别提供时钟与片选，IO0–IO7 传数据，DQS 用于数据采样。当前片内工程无需依赖这颗 NOR；XIP 需要先由 Boot 初始化并映射外存 |

[B02 原理图第 5、7、8 页](https://www.st.com/resource/en/schematic_pack/mb1737-h7s3l8-b02-schematic.pdf#page=5) · [UM3276 表 9–10](https://www.st.com/resource/en/user_manual/um3276-stm32h7rx7sx-nucleo144-board-mb1737-stmicroelectronics.pdf#page=24) · [内存与存储](../firmware/memory-storage.md)

## 用排针前查冲突

| 要接什么 | 板端接线 | 核对项 |
| --- | --- | --- |
| 3.3 V I²C 传感器 | CN7.2／D15／PB8 → SCL；CN7.4／D14／PB9 → SDA；CN7.8 → GND；可从 CN8.7 取 3.3 V | 开漏上拉接到与总线电平匹配的电源，先查模块是否已有上拉 |
| SPI1 模块 | CN7.10／D13／PA5 → SCK；CN7.12／D12／PA6 → MISO；CN7.14／D11／PB5 → MOSI；CN7.16／D10／PD14 → CS；再接电源和地 | 若 LD1 改接 PA5，SPI 时钟也会驱动它。PD14 的片选与 TIM4_CH3 需要择一 |
| ADC | CN9.1／A0／PA3 → 模拟输入，CN9.12 → GND。PA3 对应 ADC 通道 15 | 输入限制按实际 VREFP、供电和 DS14359 核对 |
| PWM | CN7.18／D9／PD15（TIM4_CH4）接探头，CN7.8 接探头地 | 先核对定时器内核时钟，再量周期和占空比 |
| SDMMC1 | 从 CN8 引出数据、CK 和 CMD | PC12、PD2 与 Trace 共用，查 [SD 卡接线](../firmware/memory-storage.md#持久数据与-sd-卡) |

排针供电脚有 5 V 并不说明信号脚支持 5 V。接线前检查共地、供电、电平及复用，并查看已连上的板载电路。重用 RMII、USB 电源检测、振荡器或调试脚时，查 UM3276 对应焊桥及连接器脚注。实际接线按「连接器脚号 → MCU 引脚/AF → 模块端 → 工作电平 → 焊桥」记录。 [UM3276 §8](https://www.st.com/resource/en/user_manual/um3276-stm32h7rx7sx-nucleo144-board-mb1737-stmicroelectronics.pdf#page=26) · [DS14359](https://www.st.com/resource/en/datasheet/stm32h7s3l8.pdf)
