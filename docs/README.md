# 开发笔记

[返回项目首页](../README.md)

## 当前进度

| 项目 | 当前情况 |
| --- | --- |
| 启动与时钟 | 片内启动，配置 VTOR、FPU 和 PLL1。实板读回 PLL 已锁定，寄存器推算 CPU 192 MHz、AHB 96 MHz、APB 48 MHz。 [MCU 实测](firmware/mcu-clock.md) |
| GPIO 与延时 | Port / Dio 提供封装引脚编号和数字 I/O，默认初始化三灯和 B2。流水灯的 GPIO 状态与约 1 秒的相邻步进间隔已在板上核对。 [GPIO](firmware/autosar-gpio.md) · [延时](firmware/project-layout.md#阻塞延时) |
| 片内存储 | Efls 数据区在第 7 扇区。临时固件已通过擦除、首尾编程、读回和非法操作拒绝验证。测试后恢复原流水灯及扇区数据。 [Efls 实测](firmware/efls.md) |
| 烧录与调试 | SWD AP 1 命令行烧录、校验、复位、硬件断点、单步和回读均有实测。 [操作流程](toolchain/stlink-gdb-cli.md) |
| 计划与待验证 | USART3 VCP 尚未接入应用。外置 NOR 已通过 ST loader 完整读取，项目内的 Fls、XSPI/复用配置与 XIP/LRUN 仍是后续工作。独立断电冷启动与 MCO 实测待记录。 |

第一次接触这个工程时，依次看[工程文件](firmware/project-layout.md)、[板卡供电与引脚](board/hardware.md)和[上板验证顺序](firmware/bringup-debug.md)。

## 按问题查找

| 分类 | 笔记 |
| --- | --- |
| 板卡 | [原理图与接线](board/hardware.md) · [指示灯数量与含义](board/hardware.md#共有多少指示灯) · [GPIO 入门与 LD1 点灯](board/peripherals-io.md#gpio-入门与-ld1-点灯) · [外设接线与验证](board/peripherals-io.md) |
| 固件 | [源码、构建和产物](firmware/project-layout.md) · [启动与调试排查](firmware/bringup-debug.md) · [内存与存储](firmware/memory-storage.md) · [Efls 片内 Flash](firmware/efls.md) · [MCU 启动与时钟](firmware/mcu-clock.md) · [AUTOSAR GPIO](firmware/autosar-gpio.md) |
| 工具链 | [STM32CubeIDE for VS Code 中文指南](toolchain/stm32cubeide-vscode-zh.md) · [ST-LINK/GDB 命令行实测](toolchain/stlink-gdb-cli.md) |
| 参考 | [全片外设寄存器表](reference/registers/README.md) · [ST 原文与中文对照](reference/references.md) · [实验记录模板](reference/references.md#实验记录模板) |
