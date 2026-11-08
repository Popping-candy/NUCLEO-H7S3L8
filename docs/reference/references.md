# 官方资料与实验记录

[返回首页](../../README.md)

## ST 原文与中文对照

**ST 官方中文入口**是 ST 中国站的产品或工具页面。**本项目中文**是面向 NUCLEO-H7S3L8 的章节导读、数据速查和实验步骤。UM3276、DS14359、RM0477 等技术资料链接指向 ST 英文原文，目前未核实到这些手册的官方中文全文。VS Code 文档门户的语言菜单目前列出 English，本项目提供首页中文译述和章节导读。

| ST 原始资料 | 本项目对应中文 | 原文定位与中文要点 |
| --- | --- | --- |
| [NUCLEO-H7S3L8 开发板产品页](https://www.st.com/en/evaluation-tools/nucleo-h7s3l8.html) | [板卡硬件与引脚](../board/hardware.md) · [ST 中国站板卡页](https://www.st.com.cn/zh/evaluation-tools/nucleo-h7s3l8.html) | 从产品页确认订货号和设计资源，实物板版本看贴纸 |
| [UM3276 板卡用户手册](https://www.st.com/resource/en/user_manual/um3276-stm32h7rx7sx-nucleo144-board-mb1737-stmicroelectronics.pdf) | [供电与跳线](../board/hardware.md#供电跳线和指示灯) · [上电检查](../firmware/bringup-debug.md#第一次上板) · [排针复用](../board/hardware.md#用排针前查冲突) | §6 快速上手与默认配置，§7 板级电路和外设，§8 扩展接口，§9 板卡与硅版本 |
| [MB1737 B02 原理图](https://www.st.com/resource/en/schematic_pack/mb1737-h7s3l8-b02-schematic.pdf) | [板载信号速查](../board/hardware.md#板载信号速查) · [外设与 I/O](../board/peripherals-io.md) | 看 Power、Connectors、ST-LinkV3EC SWD、OctoSPI Flash、USB、Ethernet 图页。按网络名追踪连接和焊桥 |
| [DS14359 芯片数据手册](https://www.st.com/resource/en/datasheet/stm32h7s3l8.pdf) | [外设与 I/O](../board/peripherals-io.md) · [地址、容量和用途](../firmware/memory-storage.md#地址容量和用途) · [ST 中国站芯片页](https://www.st.com.cn/zh/microcontrollers-microprocessors/stm32h7s3l8.html) | 看器件功能、引脚定义、复用功能和电气特性。按 STM32H7S3L8H6 的封装列定位，按工作条件选限值 |
| [RM0477 芯片参考手册](https://www.st.com/resource/en/reference_manual/rm0477-stm32h7rx7sx-armbased-32bit-mcus-stmicroelectronics.pdf) | [复位到 main](../firmware/bringup-debug.md#从复位到-main) · [内存映射](../firmware/memory-storage.md#地址容量和用途) · [外设与 I/O](../board/peripherals-io.md) | 看内存映射、RCC、GPIO、FLASH、XSPI 和相应外设。用寄存器名定位位定义、复位值与配置顺序 |
| [ES0596 芯片勘误](https://www.st.com/resource/en/errata_sheet/es0596-stm32h7rxx7sxx-device-errata-stmicroelectronics.pdf) | [硅版本与勘误读法](#芯片资料怎么对读) · [实验记录模板](#实验记录模板) | 用 `DBGMCU_IDCODE.REV_ID` 查硅版本，再查适用性、触发条件和规避措施 |
| [AN2606 系统存储区启动](https://www.st.com/resource/en/application_note/an2606-stm32-microcontroller-system-memory-boot-mode-stmicroelectronics.pdf) | [启动入口与调试恢复](../firmware/bringup-debug.md#从复位到-main) | 在 H7R/S 章节查出厂引导器的进入条件、接口和引脚 |
| [AN6101 Boot Flash 与外存管理](https://www.st.com/resource/en/application_note/an6101-introduction-to-external-memory-manager-and-external-memory-loader-middleware-for-boot-flash-mcu-stmicroelectronics.pdf) · [AN6228 XSPI 并行读写](https://www.st.com/content/st_com/en/technical-documents/an6228-how-to-implement-xspi-readwhilewrite-feature-on-stm32-mcus-stmicroelectronics.html) | [片内、XIP 和 LRUN](../firmware/memory-storage.md#片内xip-和-lrun) · [外部 loader 与板上 NOR](../firmware/memory-storage.md#外部-loader-与板上-nor) | 区分外存初始化、应用执行和工具烧录。边读边写要核对器件银行和执行位置 |
| [AN4839 一级缓存](https://www.st.com/resource/en/application_note/an4839-level-1-cache-on-stm32f7-series-and-stm32h7-series-stmicroelectronics.pdf) · [AN5593 GPDMA](https://www.st.com/content/st_com/en/technical-documents/an5593-how-to-use-the-gpdma-for-stm32-mcus-stmicroelectronics.html) | [DMA、MPU 与 D-Cache](../firmware/memory-storage.md#dmampu-与-d-cache) · [外设验证](../board/peripherals-io.md) | 用 AN4839 查缓冲区一致性，用 AN5593 查传输和链表，再回 RM0477 查具体 DMA 的内存可达性 |
| [STM32CubeIDE for VS Code 在线指南](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/index.html) · [UM3512 安装手册](https://www.st.com.cn/resource/en/user_manual/um3512-stm32cube-for-visual-studio-code-installation-guide-stmicroelectronics.pdf) | [本项目中文指南](../toolchain/stm32cubeide-vscode-zh.md) · [ST 中国站工具介绍](https://www.st.com.cn/content/st_com/zh/stm32cubeide.html) | 在线指南按安装、建工程、构建、调试查找。中文指南保留菜单和配置字段的英文名称 |
| [STM32CubeH7RS 官方固件与例程](https://github.com/STMicroelectronics/STM32CubeH7RS/tree/main/Projects/NUCLEO-H7S3L8) | [软件包、示例与工具](#软件包示例与工具) · [固件代码怎么读](../firmware/project-layout.md) | 示例的 README、`.ioc`、启动文件和链接脚本应来自同一发布版本 |

### 板卡资料怎么对读

- **先接电源。** UM3276 §6.2 表 4 对应[供电、跳线和指示灯](../board/hardware.md#供电跳线和指示灯)。首次上电检查 JP1 开路、JP2 短接、JP3 和 JP5 均在 1–2，再接 CN5。对外供电或改 1.8 V 时回查 §7.4。
- **再确认接口。** §7.3、§7.5–§7.9 对应[板载信号速查](../board/hardware.md#板载信号速查)。CN5 连板载调试器和 VCP，CN2 连目标 USB。PD10 驱动默认绿灯，PD8/PD9 对应 VCP。引脚连接和跳线变更时，用 B02 原理图沿网络追踪。
- **扩展模块接入前。** 用 §8 的连接器表按排针编号查 MCU 引脚，再用 DS14359 核对 AF、电平和模拟输入限制。遇到 PHY、SWO、Trace 或片选共用时，继续看连接器表脚注和原理图焊桥。

### 芯片资料怎么对读

1. **DS14359 定边界。** 先看型号、封装和外设实例，再查引脚、供电和频率约束。比如接 I²C 传感器，按数据手册核对引脚及电气约束，再按板卡图确认它确实引到对应排针。
2. **RM0477 定操作。** 沿时钟使能 → GPIO 复用 → 外设配置 → 中断/DMA 的顺序查对应章节。做外存启动时，先核对 XSPI 地址窗口、链接脚本、实际 NOR 容量和 Boot 交接。
3. **ES0596 定例外。** UM3276 列出的板卡批次使用过 Y 与 B 两种硅版本。以实物 `REV_ID` 为准，匹配勘误的适用性表。遇到高速 XSPI、DMA 或其他边界问题，记录勘误编号、触发配置、规避措施和复测结果。新硬件批次到手时到 [ST H7R3/H7S3 文档中心](https://www.st.com/en/microcontrollers-microprocessors/stm32h7r3-7s3/documentation.html) 核对修订。

## 软件包、示例与工具

- [STM32CubeH7RS 仓库](https://github.com/STMicroelectronics/STM32CubeH7RS)包含设备支持、驱动及板卡工程。使用发布版本时记下标签。用 Git 获取时按官方说明同步子模块，使驱动与示例版本一致。
- [NUCLEO-H7S3L8 示例入口](https://github.com/STMicroelectronics/STM32CubeH7RS/tree/main/Projects/NUCLEO-H7S3L8)下有 HAL、LL、混合示例、应用和模板。读每个示例的运行位置、供电、接线和调试要求。部分外设示例自身依赖 Boot 镜像。
- [片内模板](https://github.com/STMicroelectronics/STM32CubeH7RS/tree/main/Projects/NUCLEO-H7S3L8/Templates/Template)、[XIP 模板](https://github.com/STMicroelectronics/STM32CubeH7RS/tree/main/Projects/NUCLEO-H7S3L8/Templates/Template_XIP)和 [LRUN 模板](https://github.com/STMicroelectronics/STM32CubeH7RS/tree/main/Projects/NUCLEO-H7S3L8/Templates/Template_LRUN)用于比对启动文件、链接脚本和镜像流程。
- [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html)管理引脚、时钟和代码生成配置。[STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html)用于独立连接、烧录、读回和校验。[STM32CubeIDE for VS Code 中文指南](../toolchain/stm32cubeide-vscode-zh.md)串起编辑、构建与调试。

## 实验记录模板

| 字段 | 填写内容 |
| --- | --- |
| 日期与版本 | 日期、Git 提交、板号、硅修订号 |
| 工具链 | 扩展、CubeMX、H7RS 包、编译器、Programmer、探针固件版本 |
| 环境 | 供电、跳线、焊桥、扩展件和接线 |
| 镜像 | 片内/XIP/LRUN、构建预设、ELF 与 loader、写入地址 |
| 复现 | 从上电起的操作顺序、复位方式、数据输入 |
| 预期与实测 | LED、串口、寄存器、波形或读回数据 |
| 处置 | 单项改动、验证结果、相关勘误和修复提交 |

建议首轮记录依次验证 SWD 连接、LD1、VCP、脱离调试器冷启动。之后每加入一种外设或一种存储模式，就用相同字段留下可以复现的记录。
