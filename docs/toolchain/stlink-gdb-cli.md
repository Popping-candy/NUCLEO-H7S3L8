# 用 ST-LINK 和 GDB 从命令行调试

[返回项目首页](../../README.md) · [上电、启动与调试](../firmware/bringup-debug.md) · [VS Code 中文指南](stm32cubeide-vscode-zh.md)

这套流程在 **NUCLEO-H7S3L8、硅版本 Rev B** 的实板上验证过。以 SWD 附加正在运行的片内固件，读寄存器并单步一条指令。板上固件与本地 ELF 应来自同一次构建，地址和源码才能对应。

## 1. 准备

- 板卡通过 **CN5** 接电脑，退出占用探针的 VS Code 调试会话或 CubeProgrammer。
- 从固件项目根目录运行，准备 STM32Cube 工具包和与板上固件匹配的 ELF。下文示例使用 `build/Release/NUCLEO-H7S3L8.elf`。
- 本机实测的包为 GDB Server `7.14.0+st.2`、GNU GDB `14.3.1+st.2`、CubeProgrammer `2.23.0`。安装版本变化后，在 `$env:LOCALAPPDATA\stm32cube\bundles` 下核对路径。

## 烧录、校验与复位

先核对目标板及 ELF 的装载范围。对每个带数据的 `LOAD` 段，用 `PhysAddr` 和 `FileSiz` 确认实际占用的扇区。当前链接脚本的固件区是 `0x08000000–0x0800DFFF`，第 7 扇区留给 Efls。已验证的 600 MHz Release 镜像只覆盖第 0 扇区，Debug 镜像还覆盖第 1 扇区。需要保留后续扇区的数据时，先按实际镜像核对覆盖范围并备份。 [600 MHz 实板记录](../firmware/clock-600mhz-report.md)

用探针列表确认板名，多个探针时在连接参数加 `sn=` 对应序列号。

```powershell
$stm32Bundles = Join-Path $env:LOCALAPPDATA 'stm32cube\bundles'
$cube = Join-Path $stm32Bundles 'programmer\2.23.0\bin\STM32_Programmer_CLI.exe'
$elf = '.\build\Release\NUCLEO-H7S3L8.elf'
arm-none-eabi-readelf -lW $elf
& $cube -l stlink
& $cube -c port=SWD ap=1 freq=1000 mode=UR -d $elf -v -rst
```

成功日志应有 Download verified successfully 和 MCU Reset。工具会擦除镜像覆盖的扇区。随后用同一 ELF 附加调试。

本机 GDB Server 7.14.0 的 compare-sections 曾在 CubeProgrammer 校验成功后仍报告不匹配。遇到这种情况，用 GDB 的 dump binary memory 读回对应段，用 arm-none-eabi-objcopy -O binary --only-section 提取 ELF 对应段，再比对字节或哈希。

## 2. 启动 GDB Server

在第一个 PowerShell 窗口执行：

```powershell
$stm32Bundles = Join-Path $env:LOCALAPPDATA 'stm32cube\bundles'
$stlinkServer = Join-Path $stm32Bundles 'stlink-gdbserver\7.14.0+st.2\bin\ST-LINK_gdbserver.exe'
$cubeProgrammerBin = Join-Path $stm32Bundles 'programmer\2.23.0\bin'
& $stlinkServer -cp $cubeProgrammerBin -d -m 1 -g -p 61234 --frequency 1000
```

看到 `Waiting for debugger connection...` 后再启动客户端。`-d` 选择 SWD，**`-m 1` 选择调试访问端口 AP 1**，`-g` 附加运行中的目标。本次测试用 1 MHz SWD。保持服务在本机使用。

## 3. 连接、读寄存器和单步

在第二个 PowerShell 窗口进入固件项目根目录并执行：

```powershell
$stm32Bundles = Join-Path $env:LOCALAPPDATA 'stm32cube\bundles'
$armGdb = Join-Path $stm32Bundles 'gnu-gdb-for-stm32\14.3.1+st.2\bin\arm-none-eabi-gdb.exe'
& $armGdb -nx .\build\Release\NUCLEO-H7S3L8.elf
```

在 GDB 提示符中依次输入：

```gdb
target remote 127.0.0.1:61234
info registers pc sp lr xpsr
x/2i $pc
stepi
info registers pc
x/i $pc
detach
quit
```

实测空工程停在 `main.c:24` 的 `for(;;);`。单指令步进后，PC 从 `0x08000414`（`nop`）变为 `0x08000416`（跳回指令），源码行号仍为 24。其他构建的地址以当前 ELF 为准。结束后，在第一个窗口用 Ctrl+C 关闭仍在运行的服务。

## 排查

| 现象 | 先检查 |
| --- | --- |
| `Target unknown error 32` | 核对 `-m 1`、探针占用和目标供电。本机省略 `-m 1` 时复现过该错误 |
| 找不到 CubeProgrammer | `-cp` 指向包含 `STM32_Programmer_CLI.exe` 的目录 |
| 源码级单步一直在运行 | 当前示例是单行死循环，改用 `stepi` 检查每条指令 |

[ST 对本板 AP 1 的说明](https://community.st.com/stm32cubeprogrammer-mcus-30/stlink-gdb-server-and-nucleo-h73sl8-132248)
