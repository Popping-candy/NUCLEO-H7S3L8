# 内存与存储

[返回首页](../../README.md) · [启动与调试](bringup-debug.md) · [外设与 I/O](../board/peripherals-io.md)

## 地址、容量和用途

| 区域 | 地址或容量 | 适用场景 |
| --- | --- | --- |
| 片内用户 Flash | `0x08000000`，64 KiB | 前 56 KiB 链接当前固件，末尾 8 KiB 留给 [Efls](efls.md) |
| 片内系统 Flash | 128 KiB | ST 出厂引导和安全相关系统代码 |
| ITCM | 从 `0x00000000` 起 | 低延迟执行。核对当前分配及复位时地址映射 |
| DTCM | 从 `0x20000000` 起 | 低延迟数据和栈。先核对指定 DMA 的可达性 |
| AXI SRAM | 窗口从 `0x24000000` 起 | 通用 RAM、缓冲区或 LRUN 的执行区 |
| AHB SRAM | 从 `0x30000000` 起，共 32 KiB | 按总线可达性放置数据或缓冲区 |
| Backup SRAM | `0x38800000`，4 KiB | 有备份域供电时保存少量状态 |
| XSPI1 / XSPI2 | 映射窗口基址分别为 `0x90000000` / `0x70000000` | 地址窗口与实际存储器容量分别核算。本板默认 NOR loader 实测读取 0x70000000，改用其他窗口时核对 loader 与板级连接 |
| 板载 NOR | 256 Mbit = 32 MiB | 外部固件、资源和数据，按实际分区擦写 |

**620 KiB 是芯片的 RAM 总量规格。** ITCM/DTCM 与 AXI 有可重分配区域，部分 AXI SRAM 与 ECC 配置有关。不可把表中的地址窗口直接当成一段连续 RAM，也不可把同一共享 RAM 同时计入两边。建立链接脚本时逐一核对实际选项字节、ECC、可用物理边界和 DMA 可达性。 [DS14359](https://www.st.com/resource/en/datasheet/stm32h7s3l8.pdf) · [RM0477 内存映射与 RAM 配置](https://www.st.com/resource/en/reference_manual/rm0477-stm32h7rx7sx-armbased-32bit-mcus-stmicroelectronics.pdf)

## 片内、XIP 和 LRUN

| 路线 | 复位后的执行链 | 构建和烧录 |
| --- | --- | --- |
| 片内 | 片内应用直接启动 | 一个 ELF，链接到片内 Flash。适合早期点灯和串口 |
| XIP | 片内 Boot 初始化 XSPI，CPU 从映射后的 NOR 取指 | Boot 和 App 分别构建，内部和外部 Flash 分别烧写 |
| LRUN | 片内 Boot 初始化存储，把 App 镜像装入 RAM 再执行 | 区分镜像存放地址和 RAM 执行地址，按官方模板的镜像格式生成 |

先读同一固件版本的模板说明及链接文件，再改分区。检查 Boot 与 App 的向量表、`.text`、`.data` 装载和运行地址，确认应用偏移与 Boot 约定一致。交接还涉及 MSP、VTOR、中断、MPU/Cache 等状态，优先复用 ST 模板的交接代码。 [官方模板目录](https://github.com/STMicroelectronics/STM32CubeH7RS/tree/main/Projects/NUCLEO-H7S3L8/Templates) · [AN6101](https://www.st.com/resource/en/application_note/an6101-introduction-to-external-memory-manager-and-external-memory-loader-middleware-for-boot-flash-mcu-stmicroelectronics.pdf)

## 外部 loader 与板上 NOR

- **运行时初始化**由固件的 Boot 或驱动负责，例如配置引脚、XSPI、NOR 指令和 memory-mapped 模式。
- **烧录时初始化**由工具调用板卡专用外部 loader（`.stldr`）完成。可用 ST 的板卡示例中 `MX25UW25645G_NUCLEO-H7S3L8.stldr` 作为识别线索，按已安装的工具版本及使用的连接模式选择相应变体。
- **验证顺序**建议为读器件 ID 或 SFDP、在预留扇区做擦写并读回、进入映射模式对比内容、分别校验 Boot 和 App、断电冷启动。调试时检查 Boot 的初始化状态，再下外部应用断点。

读 ID 成功只能说明当前命令和时序基本可用。切换到 Octal/DTR 后，还要核对 DQS、dummy cycles、时钟、采样设置与 ES0596。避免在代码、中断或常量仍从同一 NOR 取用时直接擦写；若需要并行读写，按器件银行限制和 ST 已验证的 RWW 方案实施。 [ST 外存管理指南](https://wiki.st.com/stm32mcu/wiki/Getting_started_with_External_memory_Manager_and_External_memory_loader) · [板卡 loader 用例](https://github.com/STMicroelectronics/x-cube-azrtos-h7rs/blob/main/Projects/NUCLEO-H7S3L8/Applications/USBX/Ux_Device_HID/README.md) · [AN6228](https://www.st.com/content/st_com/en/technical-documents/an6228-how-to-implement-xspi-readwhilewrite-feature-on-stm32-mcus-stmicroelectronics.html)

## DMA、MPU 与 D-Cache

1. 确认外设所用 DMA 能访问缓冲区，按链接 MAP 检查实际地址。DMA 描述符同样需要核对。
2. 使用缓存区时，缓冲区按 **32 字节 Cache line** 对齐并独占边界行。CPU 写、DMA 读（例如 TX）时，在 DMA 读取前 clean。DMA 写、CPU 读（例如 RX）时，交给 DMA 前确保相关行没有会回写覆盖数据的脏内容，DMA 完成后在 CPU 读取前 invalidate。
3. DMA 持有缓冲区期间，CPU 避免访问同一缓冲区。另一种布局是通过链接脚本和 MPU 设置专用非缓存区，再验证 DMA 可达性。
4. 缓存异常常表现为 DMA 完成但读到旧值、数据偶尔损坏、关闭 D-Cache 后现象消失。记录缓冲地址、长度、对齐和每次所有权切换。 [AN4839](https://www.st.com/resource/en/application_note/an4839-level-1-cache-on-stm32f7-series-and-stm32h7-series-stmicroelectronics.pdf) · [RM0477](https://www.st.com/resource/en/reference_manual/rm0477-stm32h7rx7sx-armbased-32bit-mcus-stmicroelectronics.pdf)

## 持久数据与 SD 卡

- **NOR 分区**以擦除边界划分 Boot/App 镜像、只读资源、配置与日志。记录偏移、长度、用途、擦除粒度和谁能更新。常见 NOR 写入将位从 1 编程为 0，恢复为 1 需要擦除。按器件手册处理页边界、写使能、忙状态和超时。
- **配置与日志**可使用带版本、长度、序号和 CRC 的记录。关键配置用双副本或追加提交，更新时先校验新记录再切换，验证断电后能选回完整副本。
- **SDMMC1** 通过 CN8 接外部卡座。D0–D3 为 PC8–PC11（CN8.2/.4/.6/.8），CK 为 PC12（CN8.10），CMD 为 PD2（CN8.12）。核对 Trace 冲突、卡座供电、上拉和电平，先用低速 1-bit 初始化，再做块读写校验，最后接 FatFs、切换总线宽度并测试掉电和拔卡。 [UM3276 表 12](https://www.st.com/resource/en/user_manual/um3276-stm32h7rx7sx-nucleo144-board-mb1737-stmicroelectronics.pdf)
