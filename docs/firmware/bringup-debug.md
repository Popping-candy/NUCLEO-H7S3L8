# 上电、启动与调试

[返回首页](../../README.md) · [板卡硬件](../board/hardware.md) · [VS Code 指南](../toolchain/stm32cubeide-vscode-zh.md)

## 第一次上板

当前工程已验证命令行烧录、调试、PLL1 和三灯流水。[USART3 VCP](uart.md) 已通过启动输出和回显验证。脱离调试器的断电冷启动待验证。先看[工程文件与构建方式](project-layout.md)。

| 步骤 | 操作 | 通过条件 |
| --- | --- | --- |
| 1. 检查与上电 | 核对 JP1/JP2/JP3/JP5，暂时拔掉扩展模块，用数据线接 CN5 | 供电指示正常，电脑枚举 ST-LINK 和 VCP |
| 2. 确认 SWD | 用 STM32CubeProgrammer 选择 ST-LINK/SWD 并连接 | 可读目标信息和内部 Flash。记下器件、硅修订号及选项字节 |
| 3. 构建片内镜像 | 板级功能验证构建 Release，源码级调试可选 Debug。烧录前核对 ELF 的装载地址和覆盖扇区 | 应用向量表在 `0x08000000`，装载段位于固件区，待保留的数据已有备份 |
| 4. 烧录与调试 | 在 VS Code 加载片内 ELF，或用 CubeProgrammer 下载并校验，再复位 | 能停在 `main()`；排查启动时再在 `Reset_Handler` 设断点 |
| 5. 验证板载 I/O | 运行当前默认应用，观察三灯逐个亮灭，通过 CN5 打开 VCP | 三灯按 LD1、LD2、LD3 顺序切换，每步约 1 秒。串口可收启动行并回显 |
| 6. 独立运行 | 退出调试会话，保留 CN5 供电，按 B1，再断电重上 | 两次都重新进入流水灯，打开 VCP 时同时检查启动日志 |

采用 STM32Cube HAL 的例程时，先初始化该库和时基，再用 `HAL_Delay` 闪灯。本工程的 HAL 目录是自有驱动的对外接口层。在断点处，CPU 停机时 LED 也可能停在当前状态。现有示例的板载 LED、按键或串口也可用于验证，现象以该例程的 README 为准。 [官方片内模板](https://github.com/STMicroelectronics/STM32CubeH7RS/tree/main/Projects/NUCLEO-H7S3L8/Templates/Template) · [STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html)

## 从复位到 main

普通片内启动时，处理器按有效启动地址读取向量表的初始 MSP 和复位入口。启动汇编执行运行时初始化，通常包括 `.data` 初始化、`.bss` 清零、调用系统初始化和 C/C++ 运行时，随后进入 `main`。本工程的 SystemInit 先设置向量表和 FPU，随后启动汇编初始化 .data 和 .bss。进入 main 后，MCU 驱动配置时钟，Port 再初始化引脚。 [MCU 启动与时钟](mcu-clock.md)

有外部应用时，片内 Boot/FSBL 先配置 NOR、XSPI 和必要的 MPU/Cache，再启动外部应用。XIP 让应用从映射后的 NOR 执行。LRUN 由 Boot 将镜像装入 RAM 后从 RAM 执行。直接用调试器把 PC 设到外部应用入口，可能跳过这些初始化，也可能掩盖冷启动时的错误。 [RM0477](https://www.st.com/resource/en/reference_manual/rm0477-stm32h7rx7sx-armbased-32bit-mcus-stmicroelectronics.pdf) · [AN6101](https://www.st.com/resource/en/application_note/an6101-introduction-to-external-memory-manager-and-external-memory-loader-middleware-for-boot-flash-mcu-stmicroelectronics.pdf)

片内用户 Flash、ST 系统存储区的出厂引导器、工程自己的 Boot 是三类入口。系统引导器可用接口和进入条件以 AN2606 对 STM32H7R/S 的章节及 RM0477 为准。BOOT0 默认低，调高前先核对选项字节和产品状态。首次实验先记录出厂配置，避免改保护设置造成擦除或失去调试访问。 [AN2606](https://www.st.com/resource/en/application_note/an2606-stm32-microcontroller-system-memory-boot-mode-stmicroelectronics.pdf) · [ST 安全启动概览](https://wiki.st.com/stm32mcu/wiki/Security%3ASecure_Boot_STM32H7RS_How_to_Introduction)

命令行附加、寄存器读取和单指令步进见 [ST-LINK/GDB 实测流程](../toolchain/stlink-gdb-cli.md)。

## 调试顺序

1. **连接层。** 看 ST-LINK 日志和目标电压。拔掉可能驱动 SWD/NRST 的扩展线，确认 CubeProgrammer 和 IDE 没有同时占用探针。连接不稳时降低 SWD 时钟。怀疑现有应用改了调试引脚或进入低功耗时，尝试 Connect under reset。
2. **镜像层。** 检查当前构建预设和 ELF 时间戳。用 MAP 或 `arm-none-eabi-objdump -h <固件.elf>` 检查向量表、`.text`、`.data` 的运行及装载地址。烧录裸 `.bin` 时需显式给出对应的装载地址。
3. **启动层。** 依次断在复位入口、时钟配置、Boot 外存初始化、应用复位入口和 `main`。外部 Flash 执行优先用硬件断点。调试 Boot 和 App 时分别确认加载地址和符号来源。
4. **故障层。** 进入 `HardFault_Handler` 时，先保存堆栈中的 PC/LR、MSP/PSP、CFSR、HFSR，以及有效时的 BFAR/MMFAR。用同一次构建的 ELF 将 PC 反查源码，并结合反汇编区分取指故障、数据访问故障和非法指令。

| 现象 | 优先检查 |
| --- | --- |
| 有 COM 口，连接不到 MCU | JP2、目标供电、NRST、SWD、探针占用 |
| 停在时钟初始化 | 24 MHz 晶体与 HSE bypass 选择，PLL、VOS、Flash latency |
| LED 正常，串口乱码或无输出 | 选中的 COM 口、USART3/AF、时钟树、波特率和流控 |
| 片内可跑，外部烧录失败 | 板卡专用外部 loader、外部地址、擦写校验日志 |
| 外部烧录校验通过，复位后无输出 | Boot 是否烧入、应用向量地址、XSPI 映射、VTOR、App ELF 链接地址 |
| 单步正常，全速失败 | 初始化时序、缺少超时或同步、Cache/DMA 一致性、优化影响 |

每次先做一项改动，记录复位方式、断点地址和日志。连接恢复优先验证供电和调试路径，擦除和改选项字节前先确认镜像与数据分区范围。
