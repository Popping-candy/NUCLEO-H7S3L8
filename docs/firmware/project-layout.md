# 当前固件工程怎么读

[开发笔记](../README.md) · [上电、启动与调试](bringup-debug.md)

这个工程从 STM32CubeIDE for VS Code 空工程起步，当前以裸机方式运行，包含 [Mcu](mcu-clock.md)、[Port / Dio](autosar-gpio.md)、[Delay](#阻塞延时)、[Efls](efls.md) 和 [Uart](uart.md)。官方 STM32CubeH7RS 示例可用来对照后续外设配置。 [官方模板与例程](../reference/references.md#软件包示例与工具)

## 源码、配置和产物

| 位置 | 用途 |
| --- | --- |
| [Src/main.c](../../Src/main.c) | 初始化 MCU 时钟、Port、Delay 和 Uart。三灯步进期间轮询 VCP 回显 |
| [Drivers](../../Drivers) | 各模块按 HAL 对外接口、DRV 逻辑与 REG 寄存器访问组织。Port 和 Dio 共用 GPIO 寄存器层和封装表 |
| [Src/startup_stm32h7sxx.S](../../Src/startup_stm32h7sxx.S) | 定义向量表、`Reset_Handler` 和缺省中断处理，初始化 C 运行时并进入 `main()` |
| [Src/syscall.c](../../Src/syscall.c) · [Src/sysmem.c](../../Src/sysmem.c) | 标准库底层接口与堆。要从 VCP 看 `printf()`，需要接上标准库输出钩子 |
| [stm32h7sxx8_flash.ld](../../stm32h7sxx8_flash.ld) | 放置代码、变量、堆和栈。片内用户 Flash 为 `0x08000000` 起的 64 KiB。前 56 KiB 链接固件，末尾 8 KiB 留给 [Efls](efls.md) |
| [CMakeLists.txt](../../CMakeLists.txt) · [CMakePresets.json](../../CMakePresets.json) · `cmake/` | 定义构建目标、Debug/Release 预设、交叉编译器、源文件和链接选项 |
| `.settings/` · `.vscode/` · `.clangd` | 可共享的 STM32Cube Bundle、编辑器和索引配置。构建以 CMake 为准，生成的 project-description.json 含本机临时路径，保留在本地 |
| `build/Debug/`、`build/Release/` | 构建目录。ELF 带装载地址和调试符号，MAP 说明实际链接布局，`compile_commands.json` 用于索引 |

现有 Debug MAP 显示向量表在 `0x08000000`，`.data` 的运行地址从 `0x24000000` 开始。检查运行地址时以同一次构建的 ELF/MAP 为准。

## 从项目根目录构建

在 CMake、Ninja 和 STM32 ARM GCC 已可用的终端中执行：

```powershell
cmake --preset Debug
cmake --build --preset Debug
```

VS Code 中可以选择同名 Debug 预设构建。若终端缺少工具，可先通过 STM32 扩展配置 Bundle，再按[工具链指南](../toolchain/stm32cubeide-vscode-zh.md#3-构建与定位产物)核对环境和输出目录。

## 裸机与驱动

**裸机**描述固件怎么运行。CPU 复位后由启动代码进入 `main()`，应用可以在主循环里工作，也可以由中断响应事件，运行时没有操作系统调度任务。

**驱动**描述代码负责什么。GPIO 驱动负责启用端口时钟、配置引脚和读写电平。应用代码决定何时点灯、闪多久，以及用灯表示什么状态。

以 LD1 为例，`main()` 里直接写 `RCC_AHB4ENR`、`MODER` 和 `BSRR`，就是在裸机应用里直接完成驱动操作。也可以把这些操作封装到 `led_init()`、`led_on()`、`led_off()`，由主循环调用。若采用 ST 的 HAL/LL，GPIO 驱动由库提供，板级代码负责把 LD1 对应到 PD10。两种组织方式都能在裸机上运行，也都能与 RTOS 配合。

本工程采用裸机方式，应用通过 [Port / Dio](autosar-gpio.md) 操作板载 GPIO。[寄存器级点灯示例](../board/peripherals-io.md#寄存器级实验让-pd10-输出高电平)解释了底层机制。

## 扩展代码时怎么查

先从 `main.c` 和当前 CMake 源文件列表找应用入口。修改时钟或中断时结合启动文件、外设配置与 STM32 参考手册。引入 HAL/LL、BSP 或中间件后，再分别记录固件包版本、生成配置和板级依赖。

| 软件层 | 后续加入时主要核对 |
| --- | --- |
| CMSIS 与器件支持 | 芯片宏、寄存器定义和 IRQ 枚举 |
| HAL / LL | 时钟、引脚 AF、DMA/NVIC 和传输超时 |
| BSP | 板卡版本与 LED、按键等板级连线 |
| 中间件 | 外存管理、USB、网络或文件系统使用的内存、缓冲区和错误处理 |

## 阻塞延时

先完成 [MCU 时钟配置](mcu-clock.md)，再调用 `Delay_Init()`。应用通过 [Delay.h](../../Drivers/Delay/hal/Delay.h) 调用 `Delay_Us()` 或 `Delay_Ms()`。三个接口均返回 `bool`，用于判断周期计数器是否可用或等待是否完成。

底层读取 Cortex-M7 的 DWT CYCCNT，按 `SystemCoreClock` 换算周期。等待会占用 CPU，中断仍可运行，调用期间需保持核心时钟和 DWT 配置稳定。该模块不占用 SysTick 或通用定时器。需要在等待期间处理其他事务时，可用 `Delay_GetCycleCount()` 自行计算经过周期。Uart 超时和流水灯等待均使用这个接口。

2026-11-09 在 NUCLEO-H7S3L8 Rev B 上验证。CubeProgrammer 2.23.0 烧录校验并复位，ST-LINK GDB Server 7.14.0 和 Arm GDB 14.3.1 通过 SWD 1 MHz、AP 1 读取灯状态。预期每次切换相隔 1 秒。实测三个相邻切换分别相差 192002180、192002196、192002190 个 DWT 周期，按当时的核心频率 192 MHz 约为 1 秒。GPIO 锁存位依次显示 LD1 亮、LD1/LD2 亮、三灯亮、LD2/LD3 亮。结束后 detach，固件继续运行。

默认 600 MHz 档的步进与 Delay 接口测试见 [600 MHz 验证报告](clock-600mhz-report.md)。

首个入库版本的回归使用同一套板卡和工具。Debug ELF 烧录校验后，硬件断点连续记录 7 个灯状态，确认稳态依次熄灭 LD1、LD2、LD3，再依次点亮。6 个相邻间隔为 192002188～192002352 个 DWT 周期，按 192 MHz 换算约 1 秒。MCU 报告无时钟错误，第 7 扇区读回与实验前备份一致。会话结束后已 detach。
