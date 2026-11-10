# NUCLEO-H7S3L8 裸机固件

目标为 MB1737 上的 STM32H7S3L8H6。当前应用从片内 Flash 启动，依次点亮、熄灭 LD1、LD2、LD3。稳态每步间隔约 1 秒。通过 CN5 的板载 VCP 输出启动信息并进行字节回显。

| 模块 | 当前能力 |
| --- | --- |
| [Mcu](docs/firmware/mcu-clock.md) | 配置 HSE 与 PLL1，默认 CPU 600 MHz，记录时钟与复位诊断，失败时尝试回退 HSI。提供 USART3 时钟使能与频率查询。 |
| [Port / Dio](docs/firmware/autosar-gpio.md) | 数字输入和推挽输出，支持通道、端口、通道组与掩码访问。封装引脚表覆盖 152 个 GPIO 球位，支持指定 AF 和电气属性。 |
| [Uart](docs/firmware/uart.md) | 板载 USART3 VCP，115200 8N1，轮询收发、超时和错误处理。 |
| [Delay](docs/firmware/project-layout.md#阻塞延时) | 基于 DWT 的微秒和毫秒阻塞延时。 |
| [Efls](docs/firmware/efls.md) | 片内读取、判空、扇区擦除和 16 字节编程。前 56 KiB 用于固件，末尾 8 KiB 用于数据。 |

## 构建与调试

在提供 CMake、Ninja 和 STM32 ARM GCC 的终端中，从项目根目录执行以下命令。构建产物位于 `build/Debug/`，发布构建使用 `Release` 预设。

```powershell
cmake --preset Debug
cmake --build --preset Debug
```

- [开发笔记与当前进度](docs/README.md) · [600 MHz 实板验证报告](docs/firmware/clock-600mhz-report.md) · [后续模块路线图](docs/firmware/roadmap.md)
- [工程布局与工具链配置](docs/firmware/project-layout.md)
- [ST-LINK 命令行烧录与调试](docs/toolchain/stlink-gdb-cli.md)
- [板卡硬件](docs/board/hardware.md) · [寄存器表](docs/reference/registers/README.md) · [ST 原文与中文资料](docs/reference/references.md)
