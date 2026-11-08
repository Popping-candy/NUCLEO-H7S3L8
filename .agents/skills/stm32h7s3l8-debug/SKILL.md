---
name: stm32h7s3l8-debug
description: Build, program, verify, reset, and debug the project's NUCLEO-H7S3L8 on Windows through STM32CubeProgrammer and ST-LINK GDB.
---

# NUCLEO-H7S3L8 实板调试

用户已授权 Agent 在本项目的实板调试任务中直接执行构建、下载当前固件、按镜像范围擦除、校验、复位、运行，以及 GDB 附加、断点、步进和诊断读数。固件与 ELF 不一致时，若任务需要验证当前代码，直接构建和烧录后继续。用户明确要求只读时按只读执行。全片擦除、选项字节、OTP 和探针固件属于独立操作，按任务明确范围处理。

[命令行烧录与调试](../../../docs/toolchain/stlink-gdb-cli.md) 保存实测命令和工具包位置。工程根目录包含 CMakeLists.txt、Src/ 和 stm32h7sxx8_flash.ld。

1. 核对目标板是 NUCLEO-H7S3L8（STM32H7S3L8H6）。用 CubeProgrammer 的探针列表确定板名和探针，多个探针时绑定序列号。确认没有其他进程占用探针。
2. 验证新代码时先构建对应预设，核对镜像装载地址。片内工程用 CubeProgrammer CLI、SWD、AP 1 和 1 MHz 烧录，校验成功后复位。需要保留现场时先附加读取。调试时用同一次构建的 ELF，通过校验结果或 GDB 比对确认它与板上固件匹配。
3. 附加时启动 ST-LINK GDB Server，使用 SWD（-d）、AP 1（-m 1）和附加模式（-g）。用 127.0.0.1 和空闲端口。自动运行时隐藏 Server 窗口，记录本次 PID，等端口就绪，再用 arm-none-eabi-gdb -nx -batch，设置连接与远程超时。源码级单步停在循环时用 stepi 验证 PC。
4. 结束时 detach，并关闭本次启动的 Server。记录目标最终状态、操作、关键寄存器和实测结果。

## 常见阻塞

- Target unknown error 32 时核对 AP 1、探针占用和目标供电。仍无法正常连接时，可用 CubeProgrammer 区分探针、复位时序和 GDB 参数。
- 沙箱内出现 Windows DLL 重定位错误时，按宿主审批机制运行已安装的同一个工具。项目授权适用于板卡操作，宿主审批由环境单独处理。
- 擦写或校验失败时保留首个有意义的错误。先核对探针、目标、镜像与地址，再决定是否重试。
