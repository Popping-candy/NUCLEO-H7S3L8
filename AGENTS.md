# NUCLEO-H7S3L8 项目指引

- 项目面向 NUCLEO-H7S3L8（MB1737），目标 MCU 为 STM32H7S3L8H6。先查 [开发笔记索引](docs/README.md)，以当前源码、链接脚本及匹配的 ELF/MAP 核对项目状态。
- 板级连接和电气限制优先查 [板卡硬件](docs/board/hardware.md) 及其对应 ST 原文。涉及接线、跳线、引脚、时钟、烧录流程或存储布局的变更，在同一次修改更新对应笔记。新增实板结果时记录板卡与硅版本、工具版本、操作、预期和实测；未验证的内容标明是手册依据、原理图推导或待验证项。
- 通过 ST-LINK/GDB 操作实板、核对连接或采集运行现场时，使用 [`stm32h7s3l8-debug` 项目 Skill](.agents/skills/stm32h7s3l8-debug/SKILL.md)。
