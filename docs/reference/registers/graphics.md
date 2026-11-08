# 图像、显示与并行接口寄存器

[寄存器总索引](README.md)

## 表格字段怎么读

| 字段 | 中文注释 |
| --- | --- |
| 实例 / 基地址 / 来源 | 实例是同类外设中的独立硬件单元或模式视图。基地址是寄存器块的起点。来源区分 SVD、继承视图和芯片头文件补表。 |
| 寄存器 / 中文用途 | 英文原名可用于搜索手册和源码。中文用途说明该寄存器主要控制、读取或保存的内容。 |
| 偏移 / 绝对地址 | 单位是字节。绝对地址等于实例基地址加偏移，是调试器访问该寄存器的地址。 |
| 位宽 / 访问 | 位宽以 bit 为单位。RO 为只读，WO 为只写，RW 为读写，RW1 和 WO1 表示只可写入一次。 |
| 复位值 / 掩码 | 复位值是资料定义的初值。掩码为 1 的位才用所列复位值解释，当前运行值需要实读。 |
| 位域 | FIELD[高位:低位] 指定寄存器内部的位范围，FIELD[位号] 表示单个位。花括号内的 mask 表示不连续位，中文括号是简释。 |
| 备注 / — | 备注保留别名、读动作和地址来源差异。— 表示源数据未提供相应信息。 |

## 实例索引

| 实例 | 基地址 | 寄存器条目 | 来源 |
| --- | --- | ---: | --- |
| [DCMIPP](#dcmipp) | `0x50002000` | 37 | SVD |
| [DMA2D](#dma2d) | `0x52001000` | 535 | SVD |
| [GFXMMU](#gfxmmu) | `0x52010000` | 2057 | SVD |
| [GFXTIM](#gfxtim) | `0x50004000` | 26 | SVD |
| [GFXTIM_CMSIS](#gfxtim_cmsis) | `0x50004000` | 4 | CMSIS 补表 |
| [JPEG](#jpeg) | `0x52003000` | 504 | SVD |
| [JPEG_CMSIS](#jpeg_cmsis) | `0x52003000` | 41 | CMSIS 补表 |
| [LTDC](#ltdc) | `0x50001000` | 37 | SVD |
| [PSSI](#pssi) | `0x48000400` | 7 | SVD |

## DCMIPP

**模块用途**　数字摄像头接口和像素流水线，用于采集图像数据并写入内存。具体流水线能力按本芯片型号确认。

基地址 `0x50002000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `DCMIPP_IPGR1` | IP-Plug 全局配置或标识 | `0x000` | `0x50002000` | 32 | — | 0x00000002 / 0xFFFFFFFF | QOS_MODE[24] (RW)（待核）、MEMORYPAGE[2:0] (RW)（待核） | — |
| `DCMIPP_IPGR2` | IP-Plug 全局配置或标识 | `0x004` | `0x50002004` | 32 | — | 0x00000000 / 0xFFFFFFFF | PSTART[0] (RW)（待核） | — |
| `DCMIPP_IPGR3` | IP-Plug 全局配置或标识 | `0x008` | `0x50002008` | 32 | — | 0x00000001 / 0xFFFFFFFF | IDLE[0] (RO)（待核） | — |
| `DCMIPP_IPGR8` | IP-Plug 全局配置或标识 | `0x01C` | `0x5000201C` | 32 | — | 0xAA040314 / 0xFFFFFFFF | IPPID[31:24] (RO)（IP 标识符 (0xAA)）、ARCHIID[20:16] (RO)（待核）、REVID[12:8] (RO)（修订号标识符 (0x03)）、DID[5:0] (RO)（分频标识符 (0x14)） | — |
| `DCMIPP_IPC1R1` | IP-Plug 客户端配置 | `0x020` | `0x50002020` | 32 | — | 0x00000003 / 0xFFFFFFFF | OTR[9:8] (RW)（待核）、TRAFFIC[2:0] (RW)（待核） | — |
| `DCMIPP_IPC1R2` | IP-Plug 客户端配置 | `0x024` | `0x50002024` | 32 | — | 0x00010000 / 0xFFFFFFFF | WLRU[19:16] (RW)（待核）、SVCMAPPING[11:8] (RW)（待核） | — |
| `DCMIPP_IPC1R3` | IP-Plug 客户端配置 | `0x028` | `0x50002028` | 32 | — | 0x001F0000 / 0xFFFFFFFF | DPREGEND[20:16] (RW)（待核）、DPREGSTART[4:0] (RW)（待核） | — |
| `DCMIPP_PRCR` | DCMIPP 并行接口控制寄存器 | `0x104` | `0x50002104` | 32 | — | 0x00000000 / 0xFFFFFFFF | SWAPBITS[26] (RW)（待核）、SWAPCYCLES[25] (RW)（待核）、FORMAT[23:16] (RW)（待核）、ENABLE[14] (RW)（并行接口使能）、EDM[12:10] (RW)（扩展数据模式）、VSPOL[7] (RW)（垂直同步极性）、HSPOL[6] (RW)（水平同步极性）、PCKPOL[5] (RW)（像素时钟极性）、ESS[4] (RW)（嵌入式同步选择） | — |
| `DCMIPP_PRESCR` | DCMIPP 并行接口嵌入式同步编码寄存器 | `0x108` | `0x50002108` | 32 | — | 0x00000000 / 0xFFFFFFFF | FEC[31:24] (RW)（待核）、LEC[23:16] (RW)（待核）、LSC[15:8] (RW)（待核）、FSC[7:0] (RW)（待核） | — |
| `DCMIPP_PRESUR` | DCMIPP 并行接口嵌入式同步取消屏蔽寄存器 | `0x10C` | `0x5000210C` | 32 | — | 0x00000000 / 0xFFFFFFFF | FEU[31:24] (RW)（待核）、LEU[23:16] (RW)（待核）、LSU[15:8] (RW)（待核）、FSU[7:0] (RW)（待核） | — |
| `DCMIPP_PRIER` | DCMIPP 并行接口中断使能寄存器 | `0x1F4` | `0x500021F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | ERRIE[6] (RW)（同步错误中断使能） | — |
| `DCMIPP_PRSR` | DCMIPP 并行接口状态寄存器 | `0x1F8` | `0x500021F8` | 32 | — | 0x00030000 / 0xFFFFFFFF | VSYNC[17] (RO)（待核）、HSYNC[16] (RO)（待核）、ERRF[6] (RO)（同步错误原始中断状态） | — |
| `DCMIPP_PRFCR` | DCMIPP 并行接口中断清除寄存器 | `0x1FC` | `0x500021FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | CERRF[6] (WO)（同步错误中断状态清除） | — |
| `DCMIPP_CMCR` | DCMIPP 公共配置寄存器 | `0x204` | `0x50002204` | 32 | — | 0x00000000 / 0xFFFFFFFF | CFC[4] (WO)（清除帧计数器） | — |
| `DCMIPP_CMFRCR` | DCMIPP 公共帧计数器寄存器 | `0x208` | `0x50002208` | 32 | — | 0x00000000 / 0xFFFFFFFF | FRMCNT[31:0] (RO)（待核） | — |
| `DCMIPP_CMIER` | DCMIPP 公共中断使能寄存器 | `0x3F0` | `0x500023F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | P0OVRIE[15] (RW)（溢出中断使能的 Pipe0）、P0LIMITIE[14] (RW)（限制中断使能的 Pipe0）、P0VSYNCIE[10] (RW)（垂直同步中断使能的 Pipe0）、P0FRAMEIE[9] (RW)（帧捕获完成中断使能的 Pipe0）、P0LINEIE[8] (RW)（待核）、PRERRIE[6] (RW)（限制中断使能的并行接口）、ATXERRIE[5] (RW)（待核） | — |
| `DCMIPP_CMSR1` | DCMIPP 公共状态寄存器 1 | `0x3F4` | `0x500023F4` | 32 | — | 0x00000003 / 0xFFFFFFFF | P0CPTACT[15] (RO)（活动帧捕获 (活动来自启动-的-帧至帧完成) 的 Pipe0）、PRVSYNC[1] (RO)（待核）、PRHSYNC[0] (RO)（待核） | — |
| `DCMIPP_CMSR2` | DCMIPP 公共状态寄存器 2 | `0x3F8` | `0x500023F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | P0OVRF[15] (RO)（溢出原始中断状态的 Pipe0）、P0LIMITF[14] (RO)（限制原始中断状态的 Pipe0）、P0VSYNCF[10] (RO)（VSYNC 原始中断状态的 Pipe0）、P0FRAMEF[9] (RO)（帧捕获完成原始中断状态的 Pipe0）、P0LINEF[8] (RO)（待核）、PRERRF[6] (RO)（同步错误原始中断状态的并行接口）、ATXERRF[5] (RO)（待核） | — |
| `DCMIPP_CMFCR` | DCMIPP 公共中断清除寄存器 | `0x3FC` | `0x500023FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | CP0OVRF[15] (WO)（溢出中断状态清除）、CP0LIMITF[14] (WO)（限制中断状态清除）、CP0VSYNCF[10] (WO)（垂直同步中断状态清除）、CP0FRAMEF[9] (WO)（帧捕获完成中断状态清除）、CP0LINEF[8] (WO)（待核）、CPRERRF[6] (WO)（同步错误中断状态清除）、CATXERRF[5] (WO)（AXI 传输错误中断状态清除） | — |
| `DCMIPP_P0FSCR` | DCMIPP Pipe0 流选择配置寄存器 | `0x404` | `0x50002404` | 32 | — | 0x00000000 / 0xFFFFFFFF | PIPEN[31] (RW)（待核） | — |
| `DCMIPP_P0FCTCR` | DCMIPP Pipe0 流控制配置寄存器 | `0x500` | `0x50002500` | 32 | — | 0x00000000 / 0xFFFFFFFF | CPTREQ[3] (RW)（待核）、CPTMODE[2] (RW)（捕获模式）、FRATE[1:0] (RW)（待核） | — |
| `DCMIPP_P0SCSTR` | DCMIPP Pipe0 统计/裁剪启动寄存器 | `0x504` | `0x50002504` | 32 | — | 0x00000000 / 0xFFFFFFFF | VSTART[27:16] (RW)（垂直启动, 来自 0 至 4094 像素高位）、HSTART[11:0] (RW)（待核） | — |
| `DCMIPP_P0SCSZR` | DCMIPP Pipe0 统计/裁剪大小寄存器 | `0x508` | `0x50002508` | 32 | — | 0x00000000 / 0xFFFFFFFF | ENABLE[31] (RW)（待核）、POSNEG[30] (RW)（待核）、VSIZE[27:16] (RW)（垂直大小, 来自 0 至 4094 像素高位）、HSIZE[11:0] (RW)（待核） | — |
| `DCMIPP_P0DCCNTR` | DCMIPP Pipe0 转储计数器寄存器 | `0x5B0` | `0x500025B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | CNT[25:0] (RO)（待核） | — |
| `DCMIPP_P0DCLMTR` | DCMIPP Pipe0 转储限制寄存器 | `0x5B4` | `0x500025B4` | 32 | — | 0x00FFFFFF / 0xFFFFFFFF | ENABLE[31] (RW)（待核）、LIMIT[23:0] (RW)（待核） | — |
| `DCMIPP_P0PPCR` | DCMIPP Pipe0 像素打包器配置寄存器 | `0x5C0` | `0x500025C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DBM[16] (RW)（待核）、LINEMULT[15:13] (RW)（待核）、OELS[11] (RW)（奇数/偶数行选择 (行选择启动)）、LSM[10] (RW)（行选择模式）、OEBS[9] (RW)（奇数/偶数字节选择 (字节选择启动)）、BSM[8:7] (RW)（字节选择模式）、PAD[5] (RW)（待核） | — |
| `DCMIPP_P0PPM0AR1` | DCMIPP Pipe0 像素打包器 Memory0 地址寄存器 1 | `0x5C4` | `0x500025C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | M0A[31:0] (RW)（Memory0 地址） | — |
| `DCMIPP_P0PPM0AR2` | DCMIPP Pipe0 像素打包器 Memory0 地址寄存器 2 | `0x5C8` | `0x500025C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | M0A[31:0] (RW)（Memory0 地址） | — |
| `DCMIPP_P0IER` | DCMIPP Pipe0 中断使能寄存器 | `0x5F4` | `0x500025F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | OVRIE[7] (RW)（溢出中断使能）、LIMITIE[6] (RW)（限制中断使能）、VSYNCIE[2] (RW)（VSYNC 中断使能）、FRAMEIE[1] (RW)（帧捕获完成中断使能）、LINEIE[0] (RW)（待核） | — |
| `DCMIPP_P0SR` | DCMIPP Pipe0 状态寄存器 | `0x5F8` | `0x500025F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | CPTACT[23] (RO)（待核）、OVRF[7] (RO)（溢出原始中断状态）、LIMITF[6] (RO)（限制原始中断状态）、VSYNCF[2] (RO)（VSYNC 原始中断状态）、FRAMEF[1] (RO)（帧捕获完成原始中断状态）、LINEF[0] (RO)（待核） | — |
| `DCMIPP_P0FCR` | DCMIPP Pipe0 中断清除寄存器 | `0x5FC` | `0x500025FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | COVRF[7] (WO)（溢出中断状态清除）、CLIMITF[6] (WO)（限制中断状态清除）、CVSYNCF[2] (WO)（垂直同步中断状态清除）、CFRAMEF[1] (WO)（帧捕获完成中断状态清除）、CLINEF[0] (WO)（待核） | — |
| `DCMIPP_P0CFCTCR` | DCMIPP Pipe0 当前流控制配置寄存器 | `0x700` | `0x50002700` | 32 | — | 0x00000000 / 0xFFFFFFFF | CPTREQ[3] (RO)（待核）、CPTMODE[2] (RO)（捕获模式）、FRATE[1:0] (RO)（待核） | — |
| `DCMIPP_P0CSCSTR` | DCMIPP Pipe0 当前统计/裁剪启动寄存器 | `0x704` | `0x50002704` | 32 | — | 0x00000000 / 0xFFFFFFFF | VSTART[27:16] (RO)（当前垂直启动, 来自 0 至 4094 像素高位）、HSTART[11:0] (RO)（待核） | — |
| `DCMIPP_P0CSCSZR` | DCMIPP Pipe0 当前统计/裁剪大小寄存器 | `0x708` | `0x50002708` | 32 | — | 0x00000000 / 0xFFFFFFFF | ENABLE[31] (RO)（当前值的使能位）、POSNEG[30] (RO)（当前值的  POSNEG 位）、VSIZE[27:16] (RO)（当前垂直大小, 来自 0 至 4094 像素高位）、HSIZE[11:0] (RO)（待核） | — |
| `DCMIPP_P0CPPCR` | DCMIPP Pipe0 当前像素打包器配置寄存器 | `0x7C0` | `0x500027C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DBM[16] (RO)（待核）、LINEMULT[15:13] (RO)（待核）、OELS[11] (RO)（待核）、LSM[10] (RO)（当前行选择模式）、OEBS[9] (RO)（当前奇数/偶数字节选择 (字节选择启动)）、BSM[8:7] (RO)（当前字节选择模式）、PAD[5] (RO)（待核） | — |
| `DCMIPP_P0CPPM0AR1` | DCMIPP Pipe0 当前像素打包器 Memory0 地址寄存器 1 | `0x7C4` | `0x500027C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | M0A[31:0] (RO)（Memory0 地址） | — |
| `DCMIPP_P0CPPM0AR2` | DCMIPP Pipe0 当前像素打包器 Memory0 地址寄存器 2 | `0x7C8` | `0x500027C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | M0A[31:0] (RO)（Memory0 地址） | — |

## DMA2D

**模块用途**　二维图像搬运与转换引擎，支持填充、像素格式转换和图层混合，可减少 CPU 的逐像素处理。

基地址 `0x52001000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `DMA2D_CR` | DMA2D 控制寄存器 | `0x000` | `0x52001000` | 32 | — | 0x00000000 / 0xFFFFFFFF | MODE[18:16] (RW)（DMA2D 模式）、CEIE[13] (RW)（配置错误 (CE) 中断使能）、CTCIE[12] (RW)（颜色查找表传输完成 (CTC) 中断使能）、CAEIE[11] (RW)（颜色查找表访问错误 (CAE) 中断使能）、TWIE[10] (RW)（传输水位 (TW) 中断使能）、TCIE[9] (RW)（传输完成 (TC) 中断使能）、TEIE[8] (RW)（传输错误 (TE) 中断使能）、LOM[6] (RW)（行偏移模式）、ABORT[2] (RW)（中止当前传输）、SUSP[1] (RW)（挂起）、START[0] (RW)（启动） | — |
| `DMA2D_ISR` | DMA2D 中断状态寄存器 | `0x004` | `0x52001004` | 32 | — | 0x00000000 / 0xFFFFFFFF | CEIF[5] (RO)（配置错误中断标志）、CTCIF[4] (RO)（颜色查找表传输完成中断标志）、CAEIF[3] (RO)（颜色查找表访问错误中断标志）、TWIF[2] (RO)（传输水位中断标志）、TCIF[1] (RO)（传输完成中断标志）、TEIF[0] (RO)（传输错误中断标志） | — |
| `DMA2D_IFCR` | DMA2D 中断标志清除寄存器 | `0x008` | `0x52001008` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCEIF[5] (RW)（清除配置错误中断标志）、CCTCIF[4] (RW)（清除颜色查找表传输完成中断标志）、CAECIF[3] (RW)（清除颜色查找表访问错误中断标志）、CTWIF[2] (RW)（清除传输水位中断标志）、CTCIF[1] (RW)（清除传输完成中断标志）、CTEIF[0] (RW)（清除传输错误中断标志） | — |
| `DMA2D_FGMAR` | DMA2D 前景存储器地址寄存器 | `0x00C` | `0x5200100C` | 32 | — | 0x00000000 / 0xFFFFFFFF | MA[31:0] (RW)（待核） | — |
| `DMA2D_FGOR` | DMA2D 前景偏移寄存器 | `0x010` | `0x52001010` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[15:0] (RW)（行偏移） | — |
| `DMA2D_BGMAR` | DMA2D 背景存储器地址寄存器 | `0x014` | `0x52001014` | 32 | — | 0x00000000 / 0xFFFFFFFF | MA[31:0] (RW)（待核） | — |
| `DMA2D_BGOR` | DMA2D 背景偏移寄存器 | `0x018` | `0x52001018` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[15:0] (RW)（行偏移） | — |
| `DMA2D_FGPFCCR` | DMA2D 前景 PFC 控制寄存器 | `0x01C` | `0x5200101C` | 32 | — | 0x00000000 / 0xFFFFFFFF | ALPHA[31:24] (RW)（Alpha 分量）、RBS[21] (RW)（红色/蓝色交换）、AI[20] (RW)（反转 Alpha 值）、CSS[19:18] (RW)（色度子采样方式）、AM[17:16] (RW)（透明度模式）、CS[15:8] (RW)（颜色查找表大小）、START[5] (RW)（启动）、CCM[4] (RW)（颜色查找表颜色模式）、CM[3:0] (RW)（颜色模式） | — |
| `DMA2D_FGCOLR` | DMA2D 前景颜色寄存器 | `0x020` | `0x52001020` | 32 | — | 0x00000000 / 0xFFFFFFFF | RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGPFCCR` | DMA2D 背景 PFC 控制寄存器 | `0x024` | `0x52001024` | 32 | — | 0x00000000 / 0xFFFFFFFF | ALPHA[31:24] (RW)（Alpha 分量）、RBS[21] (RW)（红色/蓝色交换）、AI[20] (RW)（反转 Alpha 值）、AM[17:16] (RW)（透明度模式）、CS[15:8] (RW)（颜色查找表大小）、START[5] (RW)（启动）、CCM[4] (RW)（颜色查找表颜色模式）、CM[3:0] (RW)（颜色模式） | — |
| `DMA2D_BGCOLR` | DMA2D 背景颜色寄存器 | `0x028` | `0x52001028` | 32 | — | 0x00000000 / 0xFFFFFFFF | RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCMAR` | DMA2D 前景颜色查找表存储器地址寄存器 | `0x02C` | `0x5200102C` | 32 | — | 0x00000000 / 0xFFFFFFFF | MA[31:0] (RW)（存储器地址） | — |
| `DMA2D_BGCMAR` | DMA2D 背景颜色查找表存储器地址寄存器 | `0x030` | `0x52001030` | 32 | — | 0x00000000 / 0xFFFFFFFF | MA[31:0] (RW)（存储器地址） | — |
| `DMA2D_OPFCCR` | DMA2D 输出 PFC 控制寄存器 | `0x034` | `0x52001034` | 32 | — | 0x00000000 / 0xFFFFFFFF | RBS[21] (RW)（红色/蓝色交换）、AI[20] (RW)（反转 Alpha 值）、SB[8] (RW)（交换字节）、CM[2:0] (RW)（颜色模式） | — |
| `DMA2D_OCOLR_ARGB8888` | DMA2D 输出颜色寄存器 | `0x038` | `0x52001038` | 32 | — | 0x00000000 / 0xFFFFFFFF | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_OCOLR_RGB565` | DMA2D 输出颜色寄存器 | `0x038` | `0x52001038` | 32 | — | 0x00000000 / 0xFFFFFFFF | RED[15:11] (RW)（红色分量）、GREEN[10:5] (RW)（绿色分量）、BLUE[4:0] (RW)（蓝色分量） | 别名 DMA2D_OCOLR_ARGB8888 |
| `DMA2D_OCOLR_ARGB1555` | DMA2D 输出颜色寄存器 | `0x038` | `0x52001038` | 32 | — | 0x00000000 / 0xFFFFFFFF | A[15] (RW)（透明度通道值的输出颜色内 ARGB1555 模式）、RED[14:10] (RW)（红色分量）、GREEN[9:5] (RW)（绿色分量）、BLUE[4:0] (RW)（蓝色分量） | 别名 DMA2D_OCOLR_ARGB8888 |
| `DMA2D_OCOLR_ARGB4444` | DMA2D 输出颜色寄存器 | `0x038` | `0x52001038` | 32 | — | 0x00000000 / 0xFFFFFFFF | ALPHA[15:12] (RW)（Alpha 分量）、RED[11:8] (RW)（红色分量）、GREEN[7:4] (RW)（绿色分量）、BLUE[3:0] (RW)（蓝色分量） | 别名 DMA2D_OCOLR_ARGB8888 |
| `DMA2D_OMAR` | DMA2D 输出存储器地址寄存器 | `0x03C` | `0x5200103C` | 32 | — | 0x00000000 / 0xFFFFFFFF | MA[31:0] (RW)（存储器地址） | — |
| `DMA2D_OOR` | DMA2D 输出偏移寄存器 | `0x040` | `0x52001040` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[15:0] (RW)（行偏移） | — |
| `DMA2D_NLR` | DMA2D 数量行寄存器 | `0x044` | `0x52001044` | 32 | — | 0x00000000 / 0xFFFFFFFF | PL[29:16] (RW)（待核）、NL[15:0] (RW)（待核） | — |
| `DMA2D_LWR` | DMA2D 行水位寄存器 | `0x048` | `0x52001048` | 32 | — | 0x00000000 / 0xFFFFFFFF | LW[15:0] (RW)（行水位的中断生成） | — |
| `DMA2D_AMTCR` | DMA2D AXI 主设备定时器配置寄存器 | `0x04C` | `0x5200104C` | 32 | — | 0x00000000 / 0xFFFFFFFF | DT[15:8] (RW)（待核）、EN[0] (RW)（待核） | — |
| `DMA2D_FGCLUT0` | DMA2D 前景颜色查找表 | `0x400` | `0x52001400` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT1` | DMA2D 前景颜色查找表 | `0x404` | `0x52001404` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT2` | DMA2D 前景颜色查找表 | `0x408` | `0x52001408` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT3` | DMA2D 前景颜色查找表 | `0x40C` | `0x5200140C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT4` | DMA2D 前景颜色查找表 | `0x410` | `0x52001410` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT5` | DMA2D 前景颜色查找表 | `0x414` | `0x52001414` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT6` | DMA2D 前景颜色查找表 | `0x418` | `0x52001418` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT7` | DMA2D 前景颜色查找表 | `0x41C` | `0x5200141C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT8` | DMA2D 前景颜色查找表 | `0x420` | `0x52001420` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT9` | DMA2D 前景颜色查找表 | `0x424` | `0x52001424` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT10` | DMA2D 前景颜色查找表 | `0x428` | `0x52001428` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT11` | DMA2D 前景颜色查找表 | `0x42C` | `0x5200142C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT12` | DMA2D 前景颜色查找表 | `0x430` | `0x52001430` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT13` | DMA2D 前景颜色查找表 | `0x434` | `0x52001434` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT14` | DMA2D 前景颜色查找表 | `0x438` | `0x52001438` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT15` | DMA2D 前景颜色查找表 | `0x43C` | `0x5200143C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT16` | DMA2D 前景颜色查找表 | `0x440` | `0x52001440` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT17` | DMA2D 前景颜色查找表 | `0x444` | `0x52001444` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT18` | DMA2D 前景颜色查找表 | `0x448` | `0x52001448` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT19` | DMA2D 前景颜色查找表 | `0x44C` | `0x5200144C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT20` | DMA2D 前景颜色查找表 | `0x450` | `0x52001450` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT21` | DMA2D 前景颜色查找表 | `0x454` | `0x52001454` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT22` | DMA2D 前景颜色查找表 | `0x458` | `0x52001458` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT23` | DMA2D 前景颜色查找表 | `0x45C` | `0x5200145C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT24` | DMA2D 前景颜色查找表 | `0x460` | `0x52001460` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT25` | DMA2D 前景颜色查找表 | `0x464` | `0x52001464` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT26` | DMA2D 前景颜色查找表 | `0x468` | `0x52001468` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT27` | DMA2D 前景颜色查找表 | `0x46C` | `0x5200146C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT28` | DMA2D 前景颜色查找表 | `0x470` | `0x52001470` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT29` | DMA2D 前景颜色查找表 | `0x474` | `0x52001474` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT30` | DMA2D 前景颜色查找表 | `0x478` | `0x52001478` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT31` | DMA2D 前景颜色查找表 | `0x47C` | `0x5200147C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT32` | DMA2D 前景颜色查找表 | `0x480` | `0x52001480` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT33` | DMA2D 前景颜色查找表 | `0x484` | `0x52001484` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT34` | DMA2D 前景颜色查找表 | `0x488` | `0x52001488` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT35` | DMA2D 前景颜色查找表 | `0x48C` | `0x5200148C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT36` | DMA2D 前景颜色查找表 | `0x490` | `0x52001490` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT37` | DMA2D 前景颜色查找表 | `0x494` | `0x52001494` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT38` | DMA2D 前景颜色查找表 | `0x498` | `0x52001498` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT39` | DMA2D 前景颜色查找表 | `0x49C` | `0x5200149C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT40` | DMA2D 前景颜色查找表 | `0x4A0` | `0x520014A0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT41` | DMA2D 前景颜色查找表 | `0x4A4` | `0x520014A4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT42` | DMA2D 前景颜色查找表 | `0x4A8` | `0x520014A8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT43` | DMA2D 前景颜色查找表 | `0x4AC` | `0x520014AC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT44` | DMA2D 前景颜色查找表 | `0x4B0` | `0x520014B0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT45` | DMA2D 前景颜色查找表 | `0x4B4` | `0x520014B4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT46` | DMA2D 前景颜色查找表 | `0x4B8` | `0x520014B8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT47` | DMA2D 前景颜色查找表 | `0x4BC` | `0x520014BC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT48` | DMA2D 前景颜色查找表 | `0x4C0` | `0x520014C0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT49` | DMA2D 前景颜色查找表 | `0x4C4` | `0x520014C4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT50` | DMA2D 前景颜色查找表 | `0x4C8` | `0x520014C8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT51` | DMA2D 前景颜色查找表 | `0x4CC` | `0x520014CC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT52` | DMA2D 前景颜色查找表 | `0x4D0` | `0x520014D0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT53` | DMA2D 前景颜色查找表 | `0x4D4` | `0x520014D4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT54` | DMA2D 前景颜色查找表 | `0x4D8` | `0x520014D8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT55` | DMA2D 前景颜色查找表 | `0x4DC` | `0x520014DC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT56` | DMA2D 前景颜色查找表 | `0x4E0` | `0x520014E0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT57` | DMA2D 前景颜色查找表 | `0x4E4` | `0x520014E4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT58` | DMA2D 前景颜色查找表 | `0x4E8` | `0x520014E8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT59` | DMA2D 前景颜色查找表 | `0x4EC` | `0x520014EC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT60` | DMA2D 前景颜色查找表 | `0x4F0` | `0x520014F0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT61` | DMA2D 前景颜色查找表 | `0x4F4` | `0x520014F4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT62` | DMA2D 前景颜色查找表 | `0x4F8` | `0x520014F8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT63` | DMA2D 前景颜色查找表 | `0x4FC` | `0x520014FC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT64` | DMA2D 前景颜色查找表 | `0x500` | `0x52001500` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT65` | DMA2D 前景颜色查找表 | `0x504` | `0x52001504` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT66` | DMA2D 前景颜色查找表 | `0x508` | `0x52001508` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT67` | DMA2D 前景颜色查找表 | `0x50C` | `0x5200150C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT68` | DMA2D 前景颜色查找表 | `0x510` | `0x52001510` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT69` | DMA2D 前景颜色查找表 | `0x514` | `0x52001514` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT70` | DMA2D 前景颜色查找表 | `0x518` | `0x52001518` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT71` | DMA2D 前景颜色查找表 | `0x51C` | `0x5200151C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT72` | DMA2D 前景颜色查找表 | `0x520` | `0x52001520` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT73` | DMA2D 前景颜色查找表 | `0x524` | `0x52001524` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT74` | DMA2D 前景颜色查找表 | `0x528` | `0x52001528` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT75` | DMA2D 前景颜色查找表 | `0x52C` | `0x5200152C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT76` | DMA2D 前景颜色查找表 | `0x530` | `0x52001530` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT77` | DMA2D 前景颜色查找表 | `0x534` | `0x52001534` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT78` | DMA2D 前景颜色查找表 | `0x538` | `0x52001538` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT79` | DMA2D 前景颜色查找表 | `0x53C` | `0x5200153C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT80` | DMA2D 前景颜色查找表 | `0x540` | `0x52001540` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT81` | DMA2D 前景颜色查找表 | `0x544` | `0x52001544` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT82` | DMA2D 前景颜色查找表 | `0x548` | `0x52001548` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT83` | DMA2D 前景颜色查找表 | `0x54C` | `0x5200154C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT84` | DMA2D 前景颜色查找表 | `0x550` | `0x52001550` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT85` | DMA2D 前景颜色查找表 | `0x554` | `0x52001554` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT86` | DMA2D 前景颜色查找表 | `0x558` | `0x52001558` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT87` | DMA2D 前景颜色查找表 | `0x55C` | `0x5200155C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT88` | DMA2D 前景颜色查找表 | `0x560` | `0x52001560` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT89` | DMA2D 前景颜色查找表 | `0x564` | `0x52001564` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT90` | DMA2D 前景颜色查找表 | `0x568` | `0x52001568` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT91` | DMA2D 前景颜色查找表 | `0x56C` | `0x5200156C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT92` | DMA2D 前景颜色查找表 | `0x570` | `0x52001570` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT93` | DMA2D 前景颜色查找表 | `0x574` | `0x52001574` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT94` | DMA2D 前景颜色查找表 | `0x578` | `0x52001578` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT95` | DMA2D 前景颜色查找表 | `0x57C` | `0x5200157C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT96` | DMA2D 前景颜色查找表 | `0x580` | `0x52001580` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT97` | DMA2D 前景颜色查找表 | `0x584` | `0x52001584` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT98` | DMA2D 前景颜色查找表 | `0x588` | `0x52001588` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT99` | DMA2D 前景颜色查找表 | `0x58C` | `0x5200158C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT100` | DMA2D 前景颜色查找表 | `0x590` | `0x52001590` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT101` | DMA2D 前景颜色查找表 | `0x594` | `0x52001594` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT102` | DMA2D 前景颜色查找表 | `0x598` | `0x52001598` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT103` | DMA2D 前景颜色查找表 | `0x59C` | `0x5200159C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT104` | DMA2D 前景颜色查找表 | `0x5A0` | `0x520015A0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT105` | DMA2D 前景颜色查找表 | `0x5A4` | `0x520015A4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT106` | DMA2D 前景颜色查找表 | `0x5A8` | `0x520015A8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT107` | DMA2D 前景颜色查找表 | `0x5AC` | `0x520015AC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT108` | DMA2D 前景颜色查找表 | `0x5B0` | `0x520015B0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT109` | DMA2D 前景颜色查找表 | `0x5B4` | `0x520015B4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT110` | DMA2D 前景颜色查找表 | `0x5B8` | `0x520015B8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT111` | DMA2D 前景颜色查找表 | `0x5BC` | `0x520015BC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT112` | DMA2D 前景颜色查找表 | `0x5C0` | `0x520015C0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT113` | DMA2D 前景颜色查找表 | `0x5C4` | `0x520015C4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT114` | DMA2D 前景颜色查找表 | `0x5C8` | `0x520015C8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT115` | DMA2D 前景颜色查找表 | `0x5CC` | `0x520015CC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT116` | DMA2D 前景颜色查找表 | `0x5D0` | `0x520015D0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT117` | DMA2D 前景颜色查找表 | `0x5D4` | `0x520015D4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT118` | DMA2D 前景颜色查找表 | `0x5D8` | `0x520015D8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT119` | DMA2D 前景颜色查找表 | `0x5DC` | `0x520015DC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT120` | DMA2D 前景颜色查找表 | `0x5E0` | `0x520015E0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT121` | DMA2D 前景颜色查找表 | `0x5E4` | `0x520015E4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT122` | DMA2D 前景颜色查找表 | `0x5E8` | `0x520015E8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT123` | DMA2D 前景颜色查找表 | `0x5EC` | `0x520015EC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT124` | DMA2D 前景颜色查找表 | `0x5F0` | `0x520015F0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT125` | DMA2D 前景颜色查找表 | `0x5F4` | `0x520015F4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT126` | DMA2D 前景颜色查找表 | `0x5F8` | `0x520015F8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT127` | DMA2D 前景颜色查找表 | `0x5FC` | `0x520015FC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT128` | DMA2D 前景颜色查找表 | `0x600` | `0x52001600` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT129` | DMA2D 前景颜色查找表 | `0x604` | `0x52001604` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT130` | DMA2D 前景颜色查找表 | `0x608` | `0x52001608` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT131` | DMA2D 前景颜色查找表 | `0x60C` | `0x5200160C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT132` | DMA2D 前景颜色查找表 | `0x610` | `0x52001610` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT133` | DMA2D 前景颜色查找表 | `0x614` | `0x52001614` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT134` | DMA2D 前景颜色查找表 | `0x618` | `0x52001618` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT135` | DMA2D 前景颜色查找表 | `0x61C` | `0x5200161C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT136` | DMA2D 前景颜色查找表 | `0x620` | `0x52001620` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT137` | DMA2D 前景颜色查找表 | `0x624` | `0x52001624` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT138` | DMA2D 前景颜色查找表 | `0x628` | `0x52001628` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT139` | DMA2D 前景颜色查找表 | `0x62C` | `0x5200162C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT140` | DMA2D 前景颜色查找表 | `0x630` | `0x52001630` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT141` | DMA2D 前景颜色查找表 | `0x634` | `0x52001634` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT142` | DMA2D 前景颜色查找表 | `0x638` | `0x52001638` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT143` | DMA2D 前景颜色查找表 | `0x63C` | `0x5200163C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT144` | DMA2D 前景颜色查找表 | `0x640` | `0x52001640` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT145` | DMA2D 前景颜色查找表 | `0x644` | `0x52001644` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT146` | DMA2D 前景颜色查找表 | `0x648` | `0x52001648` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT147` | DMA2D 前景颜色查找表 | `0x64C` | `0x5200164C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT148` | DMA2D 前景颜色查找表 | `0x650` | `0x52001650` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT149` | DMA2D 前景颜色查找表 | `0x654` | `0x52001654` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT150` | DMA2D 前景颜色查找表 | `0x658` | `0x52001658` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT151` | DMA2D 前景颜色查找表 | `0x65C` | `0x5200165C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT152` | DMA2D 前景颜色查找表 | `0x660` | `0x52001660` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT153` | DMA2D 前景颜色查找表 | `0x664` | `0x52001664` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT154` | DMA2D 前景颜色查找表 | `0x668` | `0x52001668` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT155` | DMA2D 前景颜色查找表 | `0x66C` | `0x5200166C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT156` | DMA2D 前景颜色查找表 | `0x670` | `0x52001670` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT157` | DMA2D 前景颜色查找表 | `0x674` | `0x52001674` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT158` | DMA2D 前景颜色查找表 | `0x678` | `0x52001678` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT159` | DMA2D 前景颜色查找表 | `0x67C` | `0x5200167C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT160` | DMA2D 前景颜色查找表 | `0x680` | `0x52001680` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT161` | DMA2D 前景颜色查找表 | `0x684` | `0x52001684` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT162` | DMA2D 前景颜色查找表 | `0x688` | `0x52001688` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT163` | DMA2D 前景颜色查找表 | `0x68C` | `0x5200168C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT164` | DMA2D 前景颜色查找表 | `0x690` | `0x52001690` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT165` | DMA2D 前景颜色查找表 | `0x694` | `0x52001694` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT166` | DMA2D 前景颜色查找表 | `0x698` | `0x52001698` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT167` | DMA2D 前景颜色查找表 | `0x69C` | `0x5200169C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT168` | DMA2D 前景颜色查找表 | `0x6A0` | `0x520016A0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT169` | DMA2D 前景颜色查找表 | `0x6A4` | `0x520016A4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT170` | DMA2D 前景颜色查找表 | `0x6A8` | `0x520016A8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT171` | DMA2D 前景颜色查找表 | `0x6AC` | `0x520016AC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT172` | DMA2D 前景颜色查找表 | `0x6B0` | `0x520016B0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT173` | DMA2D 前景颜色查找表 | `0x6B4` | `0x520016B4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT174` | DMA2D 前景颜色查找表 | `0x6B8` | `0x520016B8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT175` | DMA2D 前景颜色查找表 | `0x6BC` | `0x520016BC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT176` | DMA2D 前景颜色查找表 | `0x6C0` | `0x520016C0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT177` | DMA2D 前景颜色查找表 | `0x6C4` | `0x520016C4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT178` | DMA2D 前景颜色查找表 | `0x6C8` | `0x520016C8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT179` | DMA2D 前景颜色查找表 | `0x6CC` | `0x520016CC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT180` | DMA2D 前景颜色查找表 | `0x6D0` | `0x520016D0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT181` | DMA2D 前景颜色查找表 | `0x6D4` | `0x520016D4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT182` | DMA2D 前景颜色查找表 | `0x6D8` | `0x520016D8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT183` | DMA2D 前景颜色查找表 | `0x6DC` | `0x520016DC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT184` | DMA2D 前景颜色查找表 | `0x6E0` | `0x520016E0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT185` | DMA2D 前景颜色查找表 | `0x6E4` | `0x520016E4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT186` | DMA2D 前景颜色查找表 | `0x6E8` | `0x520016E8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT187` | DMA2D 前景颜色查找表 | `0x6EC` | `0x520016EC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT188` | DMA2D 前景颜色查找表 | `0x6F0` | `0x520016F0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT189` | DMA2D 前景颜色查找表 | `0x6F4` | `0x520016F4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT190` | DMA2D 前景颜色查找表 | `0x6F8` | `0x520016F8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT191` | DMA2D 前景颜色查找表 | `0x6FC` | `0x520016FC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT192` | DMA2D 前景颜色查找表 | `0x700` | `0x52001700` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT193` | DMA2D 前景颜色查找表 | `0x704` | `0x52001704` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT194` | DMA2D 前景颜色查找表 | `0x708` | `0x52001708` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT195` | DMA2D 前景颜色查找表 | `0x70C` | `0x5200170C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT196` | DMA2D 前景颜色查找表 | `0x710` | `0x52001710` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT197` | DMA2D 前景颜色查找表 | `0x714` | `0x52001714` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT198` | DMA2D 前景颜色查找表 | `0x718` | `0x52001718` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT199` | DMA2D 前景颜色查找表 | `0x71C` | `0x5200171C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT200` | DMA2D 前景颜色查找表 | `0x720` | `0x52001720` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT201` | DMA2D 前景颜色查找表 | `0x724` | `0x52001724` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT202` | DMA2D 前景颜色查找表 | `0x728` | `0x52001728` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT203` | DMA2D 前景颜色查找表 | `0x72C` | `0x5200172C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT204` | DMA2D 前景颜色查找表 | `0x730` | `0x52001730` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT205` | DMA2D 前景颜色查找表 | `0x734` | `0x52001734` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT206` | DMA2D 前景颜色查找表 | `0x738` | `0x52001738` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT207` | DMA2D 前景颜色查找表 | `0x73C` | `0x5200173C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT208` | DMA2D 前景颜色查找表 | `0x740` | `0x52001740` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT209` | DMA2D 前景颜色查找表 | `0x744` | `0x52001744` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT210` | DMA2D 前景颜色查找表 | `0x748` | `0x52001748` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT211` | DMA2D 前景颜色查找表 | `0x74C` | `0x5200174C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT212` | DMA2D 前景颜色查找表 | `0x750` | `0x52001750` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT213` | DMA2D 前景颜色查找表 | `0x754` | `0x52001754` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT214` | DMA2D 前景颜色查找表 | `0x758` | `0x52001758` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT215` | DMA2D 前景颜色查找表 | `0x75C` | `0x5200175C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT216` | DMA2D 前景颜色查找表 | `0x760` | `0x52001760` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT217` | DMA2D 前景颜色查找表 | `0x764` | `0x52001764` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT218` | DMA2D 前景颜色查找表 | `0x768` | `0x52001768` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT219` | DMA2D 前景颜色查找表 | `0x76C` | `0x5200176C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT220` | DMA2D 前景颜色查找表 | `0x770` | `0x52001770` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT221` | DMA2D 前景颜色查找表 | `0x774` | `0x52001774` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT222` | DMA2D 前景颜色查找表 | `0x778` | `0x52001778` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT223` | DMA2D 前景颜色查找表 | `0x77C` | `0x5200177C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT224` | DMA2D 前景颜色查找表 | `0x780` | `0x52001780` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT225` | DMA2D 前景颜色查找表 | `0x784` | `0x52001784` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT226` | DMA2D 前景颜色查找表 | `0x788` | `0x52001788` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT227` | DMA2D 前景颜色查找表 | `0x78C` | `0x5200178C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT228` | DMA2D 前景颜色查找表 | `0x790` | `0x52001790` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT229` | DMA2D 前景颜色查找表 | `0x794` | `0x52001794` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT230` | DMA2D 前景颜色查找表 | `0x798` | `0x52001798` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT231` | DMA2D 前景颜色查找表 | `0x79C` | `0x5200179C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT232` | DMA2D 前景颜色查找表 | `0x7A0` | `0x520017A0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT233` | DMA2D 前景颜色查找表 | `0x7A4` | `0x520017A4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT234` | DMA2D 前景颜色查找表 | `0x7A8` | `0x520017A8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT235` | DMA2D 前景颜色查找表 | `0x7AC` | `0x520017AC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT236` | DMA2D 前景颜色查找表 | `0x7B0` | `0x520017B0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT237` | DMA2D 前景颜色查找表 | `0x7B4` | `0x520017B4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT238` | DMA2D 前景颜色查找表 | `0x7B8` | `0x520017B8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT239` | DMA2D 前景颜色查找表 | `0x7BC` | `0x520017BC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT240` | DMA2D 前景颜色查找表 | `0x7C0` | `0x520017C0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT241` | DMA2D 前景颜色查找表 | `0x7C4` | `0x520017C4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT242` | DMA2D 前景颜色查找表 | `0x7C8` | `0x520017C8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT243` | DMA2D 前景颜色查找表 | `0x7CC` | `0x520017CC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT244` | DMA2D 前景颜色查找表 | `0x7D0` | `0x520017D0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT245` | DMA2D 前景颜色查找表 | `0x7D4` | `0x520017D4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT246` | DMA2D 前景颜色查找表 | `0x7D8` | `0x520017D8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT247` | DMA2D 前景颜色查找表 | `0x7DC` | `0x520017DC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT248` | DMA2D 前景颜色查找表 | `0x7E0` | `0x520017E0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT249` | DMA2D 前景颜色查找表 | `0x7E4` | `0x520017E4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT250` | DMA2D 前景颜色查找表 | `0x7E8` | `0x520017E8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT251` | DMA2D 前景颜色查找表 | `0x7EC` | `0x520017EC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT252` | DMA2D 前景颜色查找表 | `0x7F0` | `0x520017F0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT253` | DMA2D 前景颜色查找表 | `0x7F4` | `0x520017F4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT254` | DMA2D 前景颜色查找表 | `0x7F8` | `0x520017F8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_FGCLUT255` | DMA2D 前景颜色查找表 | `0x7FC` | `0x520017FC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT0` | DMA2D 背景颜色查找表 | `0x800` | `0x52001800` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT1` | DMA2D 背景颜色查找表 | `0x804` | `0x52001804` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT2` | DMA2D 背景颜色查找表 | `0x808` | `0x52001808` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT3` | DMA2D 背景颜色查找表 | `0x80C` | `0x5200180C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT4` | DMA2D 背景颜色查找表 | `0x810` | `0x52001810` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT5` | DMA2D 背景颜色查找表 | `0x814` | `0x52001814` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT6` | DMA2D 背景颜色查找表 | `0x818` | `0x52001818` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT7` | DMA2D 背景颜色查找表 | `0x81C` | `0x5200181C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT8` | DMA2D 背景颜色查找表 | `0x820` | `0x52001820` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT9` | DMA2D 背景颜色查找表 | `0x824` | `0x52001824` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT10` | DMA2D 背景颜色查找表 | `0x828` | `0x52001828` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT11` | DMA2D 背景颜色查找表 | `0x82C` | `0x5200182C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT12` | DMA2D 背景颜色查找表 | `0x830` | `0x52001830` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT13` | DMA2D 背景颜色查找表 | `0x834` | `0x52001834` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT14` | DMA2D 背景颜色查找表 | `0x838` | `0x52001838` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT15` | DMA2D 背景颜色查找表 | `0x83C` | `0x5200183C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT16` | DMA2D 背景颜色查找表 | `0x840` | `0x52001840` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT17` | DMA2D 背景颜色查找表 | `0x844` | `0x52001844` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT18` | DMA2D 背景颜色查找表 | `0x848` | `0x52001848` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT19` | DMA2D 背景颜色查找表 | `0x84C` | `0x5200184C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT20` | DMA2D 背景颜色查找表 | `0x850` | `0x52001850` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT21` | DMA2D 背景颜色查找表 | `0x854` | `0x52001854` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT22` | DMA2D 背景颜色查找表 | `0x858` | `0x52001858` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT23` | DMA2D 背景颜色查找表 | `0x85C` | `0x5200185C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT24` | DMA2D 背景颜色查找表 | `0x860` | `0x52001860` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT25` | DMA2D 背景颜色查找表 | `0x864` | `0x52001864` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT26` | DMA2D 背景颜色查找表 | `0x868` | `0x52001868` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT27` | DMA2D 背景颜色查找表 | `0x86C` | `0x5200186C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT28` | DMA2D 背景颜色查找表 | `0x870` | `0x52001870` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT29` | DMA2D 背景颜色查找表 | `0x874` | `0x52001874` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT30` | DMA2D 背景颜色查找表 | `0x878` | `0x52001878` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT31` | DMA2D 背景颜色查找表 | `0x87C` | `0x5200187C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT32` | DMA2D 背景颜色查找表 | `0x880` | `0x52001880` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT33` | DMA2D 背景颜色查找表 | `0x884` | `0x52001884` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT34` | DMA2D 背景颜色查找表 | `0x888` | `0x52001888` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT35` | DMA2D 背景颜色查找表 | `0x88C` | `0x5200188C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT36` | DMA2D 背景颜色查找表 | `0x890` | `0x52001890` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT37` | DMA2D 背景颜色查找表 | `0x894` | `0x52001894` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT38` | DMA2D 背景颜色查找表 | `0x898` | `0x52001898` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT39` | DMA2D 背景颜色查找表 | `0x89C` | `0x5200189C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT40` | DMA2D 背景颜色查找表 | `0x8A0` | `0x520018A0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT41` | DMA2D 背景颜色查找表 | `0x8A4` | `0x520018A4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT42` | DMA2D 背景颜色查找表 | `0x8A8` | `0x520018A8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT43` | DMA2D 背景颜色查找表 | `0x8AC` | `0x520018AC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT44` | DMA2D 背景颜色查找表 | `0x8B0` | `0x520018B0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT45` | DMA2D 背景颜色查找表 | `0x8B4` | `0x520018B4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT46` | DMA2D 背景颜色查找表 | `0x8B8` | `0x520018B8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT47` | DMA2D 背景颜色查找表 | `0x8BC` | `0x520018BC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT48` | DMA2D 背景颜色查找表 | `0x8C0` | `0x520018C0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT49` | DMA2D 背景颜色查找表 | `0x8C4` | `0x520018C4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT50` | DMA2D 背景颜色查找表 | `0x8C8` | `0x520018C8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT51` | DMA2D 背景颜色查找表 | `0x8CC` | `0x520018CC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT52` | DMA2D 背景颜色查找表 | `0x8D0` | `0x520018D0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT53` | DMA2D 背景颜色查找表 | `0x8D4` | `0x520018D4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT54` | DMA2D 背景颜色查找表 | `0x8D8` | `0x520018D8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT55` | DMA2D 背景颜色查找表 | `0x8DC` | `0x520018DC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT56` | DMA2D 背景颜色查找表 | `0x8E0` | `0x520018E0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT57` | DMA2D 背景颜色查找表 | `0x8E4` | `0x520018E4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT58` | DMA2D 背景颜色查找表 | `0x8E8` | `0x520018E8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT59` | DMA2D 背景颜色查找表 | `0x8EC` | `0x520018EC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT60` | DMA2D 背景颜色查找表 | `0x8F0` | `0x520018F0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT61` | DMA2D 背景颜色查找表 | `0x8F4` | `0x520018F4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT62` | DMA2D 背景颜色查找表 | `0x8F8` | `0x520018F8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT63` | DMA2D 背景颜色查找表 | `0x8FC` | `0x520018FC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT64` | DMA2D 背景颜色查找表 | `0x900` | `0x52001900` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT65` | DMA2D 背景颜色查找表 | `0x904` | `0x52001904` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT66` | DMA2D 背景颜色查找表 | `0x908` | `0x52001908` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT67` | DMA2D 背景颜色查找表 | `0x90C` | `0x5200190C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT68` | DMA2D 背景颜色查找表 | `0x910` | `0x52001910` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT69` | DMA2D 背景颜色查找表 | `0x914` | `0x52001914` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT70` | DMA2D 背景颜色查找表 | `0x918` | `0x52001918` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT71` | DMA2D 背景颜色查找表 | `0x91C` | `0x5200191C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT72` | DMA2D 背景颜色查找表 | `0x920` | `0x52001920` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT73` | DMA2D 背景颜色查找表 | `0x924` | `0x52001924` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT74` | DMA2D 背景颜色查找表 | `0x928` | `0x52001928` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT75` | DMA2D 背景颜色查找表 | `0x92C` | `0x5200192C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT76` | DMA2D 背景颜色查找表 | `0x930` | `0x52001930` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT77` | DMA2D 背景颜色查找表 | `0x934` | `0x52001934` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT78` | DMA2D 背景颜色查找表 | `0x938` | `0x52001938` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT79` | DMA2D 背景颜色查找表 | `0x93C` | `0x5200193C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT80` | DMA2D 背景颜色查找表 | `0x940` | `0x52001940` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT81` | DMA2D 背景颜色查找表 | `0x944` | `0x52001944` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT82` | DMA2D 背景颜色查找表 | `0x948` | `0x52001948` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT83` | DMA2D 背景颜色查找表 | `0x94C` | `0x5200194C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT84` | DMA2D 背景颜色查找表 | `0x950` | `0x52001950` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT85` | DMA2D 背景颜色查找表 | `0x954` | `0x52001954` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT86` | DMA2D 背景颜色查找表 | `0x958` | `0x52001958` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT87` | DMA2D 背景颜色查找表 | `0x95C` | `0x5200195C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT88` | DMA2D 背景颜色查找表 | `0x960` | `0x52001960` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT89` | DMA2D 背景颜色查找表 | `0x964` | `0x52001964` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT90` | DMA2D 背景颜色查找表 | `0x968` | `0x52001968` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT91` | DMA2D 背景颜色查找表 | `0x96C` | `0x5200196C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT92` | DMA2D 背景颜色查找表 | `0x970` | `0x52001970` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT93` | DMA2D 背景颜色查找表 | `0x974` | `0x52001974` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT94` | DMA2D 背景颜色查找表 | `0x978` | `0x52001978` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT95` | DMA2D 背景颜色查找表 | `0x97C` | `0x5200197C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT96` | DMA2D 背景颜色查找表 | `0x980` | `0x52001980` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT97` | DMA2D 背景颜色查找表 | `0x984` | `0x52001984` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT98` | DMA2D 背景颜色查找表 | `0x988` | `0x52001988` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT99` | DMA2D 背景颜色查找表 | `0x98C` | `0x5200198C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT100` | DMA2D 背景颜色查找表 | `0x990` | `0x52001990` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT101` | DMA2D 背景颜色查找表 | `0x994` | `0x52001994` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT102` | DMA2D 背景颜色查找表 | `0x998` | `0x52001998` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT103` | DMA2D 背景颜色查找表 | `0x99C` | `0x5200199C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT104` | DMA2D 背景颜色查找表 | `0x9A0` | `0x520019A0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT105` | DMA2D 背景颜色查找表 | `0x9A4` | `0x520019A4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT106` | DMA2D 背景颜色查找表 | `0x9A8` | `0x520019A8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT107` | DMA2D 背景颜色查找表 | `0x9AC` | `0x520019AC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT108` | DMA2D 背景颜色查找表 | `0x9B0` | `0x520019B0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT109` | DMA2D 背景颜色查找表 | `0x9B4` | `0x520019B4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT110` | DMA2D 背景颜色查找表 | `0x9B8` | `0x520019B8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT111` | DMA2D 背景颜色查找表 | `0x9BC` | `0x520019BC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT112` | DMA2D 背景颜色查找表 | `0x9C0` | `0x520019C0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT113` | DMA2D 背景颜色查找表 | `0x9C4` | `0x520019C4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT114` | DMA2D 背景颜色查找表 | `0x9C8` | `0x520019C8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT115` | DMA2D 背景颜色查找表 | `0x9CC` | `0x520019CC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT116` | DMA2D 背景颜色查找表 | `0x9D0` | `0x520019D0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT117` | DMA2D 背景颜色查找表 | `0x9D4` | `0x520019D4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT118` | DMA2D 背景颜色查找表 | `0x9D8` | `0x520019D8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT119` | DMA2D 背景颜色查找表 | `0x9DC` | `0x520019DC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT120` | DMA2D 背景颜色查找表 | `0x9E0` | `0x520019E0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT121` | DMA2D 背景颜色查找表 | `0x9E4` | `0x520019E4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT122` | DMA2D 背景颜色查找表 | `0x9E8` | `0x520019E8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT123` | DMA2D 背景颜色查找表 | `0x9EC` | `0x520019EC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT124` | DMA2D 背景颜色查找表 | `0x9F0` | `0x520019F0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT125` | DMA2D 背景颜色查找表 | `0x9F4` | `0x520019F4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT126` | DMA2D 背景颜色查找表 | `0x9F8` | `0x520019F8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT127` | DMA2D 背景颜色查找表 | `0x9FC` | `0x520019FC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT128` | DMA2D 背景颜色查找表 | `0xA00` | `0x52001A00` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT129` | DMA2D 背景颜色查找表 | `0xA04` | `0x52001A04` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT130` | DMA2D 背景颜色查找表 | `0xA08` | `0x52001A08` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT131` | DMA2D 背景颜色查找表 | `0xA0C` | `0x52001A0C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT132` | DMA2D 背景颜色查找表 | `0xA10` | `0x52001A10` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT133` | DMA2D 背景颜色查找表 | `0xA14` | `0x52001A14` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT134` | DMA2D 背景颜色查找表 | `0xA18` | `0x52001A18` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT135` | DMA2D 背景颜色查找表 | `0xA1C` | `0x52001A1C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT136` | DMA2D 背景颜色查找表 | `0xA20` | `0x52001A20` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT137` | DMA2D 背景颜色查找表 | `0xA24` | `0x52001A24` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT138` | DMA2D 背景颜色查找表 | `0xA28` | `0x52001A28` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT139` | DMA2D 背景颜色查找表 | `0xA2C` | `0x52001A2C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT140` | DMA2D 背景颜色查找表 | `0xA30` | `0x52001A30` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT141` | DMA2D 背景颜色查找表 | `0xA34` | `0x52001A34` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT142` | DMA2D 背景颜色查找表 | `0xA38` | `0x52001A38` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT143` | DMA2D 背景颜色查找表 | `0xA3C` | `0x52001A3C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT144` | DMA2D 背景颜色查找表 | `0xA40` | `0x52001A40` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT145` | DMA2D 背景颜色查找表 | `0xA44` | `0x52001A44` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT146` | DMA2D 背景颜色查找表 | `0xA48` | `0x52001A48` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT147` | DMA2D 背景颜色查找表 | `0xA4C` | `0x52001A4C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT148` | DMA2D 背景颜色查找表 | `0xA50` | `0x52001A50` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT149` | DMA2D 背景颜色查找表 | `0xA54` | `0x52001A54` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT150` | DMA2D 背景颜色查找表 | `0xA58` | `0x52001A58` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT151` | DMA2D 背景颜色查找表 | `0xA5C` | `0x52001A5C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT152` | DMA2D 背景颜色查找表 | `0xA60` | `0x52001A60` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT153` | DMA2D 背景颜色查找表 | `0xA64` | `0x52001A64` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT154` | DMA2D 背景颜色查找表 | `0xA68` | `0x52001A68` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT155` | DMA2D 背景颜色查找表 | `0xA6C` | `0x52001A6C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT156` | DMA2D 背景颜色查找表 | `0xA70` | `0x52001A70` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT157` | DMA2D 背景颜色查找表 | `0xA74` | `0x52001A74` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT158` | DMA2D 背景颜色查找表 | `0xA78` | `0x52001A78` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT159` | DMA2D 背景颜色查找表 | `0xA7C` | `0x52001A7C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT160` | DMA2D 背景颜色查找表 | `0xA80` | `0x52001A80` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT161` | DMA2D 背景颜色查找表 | `0xA84` | `0x52001A84` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT162` | DMA2D 背景颜色查找表 | `0xA88` | `0x52001A88` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT163` | DMA2D 背景颜色查找表 | `0xA8C` | `0x52001A8C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT164` | DMA2D 背景颜色查找表 | `0xA90` | `0x52001A90` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT165` | DMA2D 背景颜色查找表 | `0xA94` | `0x52001A94` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT166` | DMA2D 背景颜色查找表 | `0xA98` | `0x52001A98` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT167` | DMA2D 背景颜色查找表 | `0xA9C` | `0x52001A9C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT168` | DMA2D 背景颜色查找表 | `0xAA0` | `0x52001AA0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT169` | DMA2D 背景颜色查找表 | `0xAA4` | `0x52001AA4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT170` | DMA2D 背景颜色查找表 | `0xAA8` | `0x52001AA8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT171` | DMA2D 背景颜色查找表 | `0xAAC` | `0x52001AAC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT172` | DMA2D 背景颜色查找表 | `0xAB0` | `0x52001AB0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT173` | DMA2D 背景颜色查找表 | `0xAB4` | `0x52001AB4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT174` | DMA2D 背景颜色查找表 | `0xAB8` | `0x52001AB8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT175` | DMA2D 背景颜色查找表 | `0xABC` | `0x52001ABC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT176` | DMA2D 背景颜色查找表 | `0xAC0` | `0x52001AC0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT177` | DMA2D 背景颜色查找表 | `0xAC4` | `0x52001AC4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT178` | DMA2D 背景颜色查找表 | `0xAC8` | `0x52001AC8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT179` | DMA2D 背景颜色查找表 | `0xACC` | `0x52001ACC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT180` | DMA2D 背景颜色查找表 | `0xAD0` | `0x52001AD0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT181` | DMA2D 背景颜色查找表 | `0xAD4` | `0x52001AD4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT182` | DMA2D 背景颜色查找表 | `0xAD8` | `0x52001AD8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT183` | DMA2D 背景颜色查找表 | `0xADC` | `0x52001ADC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT184` | DMA2D 背景颜色查找表 | `0xAE0` | `0x52001AE0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT185` | DMA2D 背景颜色查找表 | `0xAE4` | `0x52001AE4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT186` | DMA2D 背景颜色查找表 | `0xAE8` | `0x52001AE8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT187` | DMA2D 背景颜色查找表 | `0xAEC` | `0x52001AEC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT188` | DMA2D 背景颜色查找表 | `0xAF0` | `0x52001AF0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT189` | DMA2D 背景颜色查找表 | `0xAF4` | `0x52001AF4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT190` | DMA2D 背景颜色查找表 | `0xAF8` | `0x52001AF8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT191` | DMA2D 背景颜色查找表 | `0xAFC` | `0x52001AFC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT192` | DMA2D 背景颜色查找表 | `0xB00` | `0x52001B00` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT193` | DMA2D 背景颜色查找表 | `0xB04` | `0x52001B04` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT194` | DMA2D 背景颜色查找表 | `0xB08` | `0x52001B08` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT195` | DMA2D 背景颜色查找表 | `0xB0C` | `0x52001B0C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT196` | DMA2D 背景颜色查找表 | `0xB10` | `0x52001B10` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT197` | DMA2D 背景颜色查找表 | `0xB14` | `0x52001B14` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT198` | DMA2D 背景颜色查找表 | `0xB18` | `0x52001B18` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT199` | DMA2D 背景颜色查找表 | `0xB1C` | `0x52001B1C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT200` | DMA2D 背景颜色查找表 | `0xB20` | `0x52001B20` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT201` | DMA2D 背景颜色查找表 | `0xB24` | `0x52001B24` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT202` | DMA2D 背景颜色查找表 | `0xB28` | `0x52001B28` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT203` | DMA2D 背景颜色查找表 | `0xB2C` | `0x52001B2C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT204` | DMA2D 背景颜色查找表 | `0xB30` | `0x52001B30` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT205` | DMA2D 背景颜色查找表 | `0xB34` | `0x52001B34` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT206` | DMA2D 背景颜色查找表 | `0xB38` | `0x52001B38` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT207` | DMA2D 背景颜色查找表 | `0xB3C` | `0x52001B3C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT208` | DMA2D 背景颜色查找表 | `0xB40` | `0x52001B40` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT209` | DMA2D 背景颜色查找表 | `0xB44` | `0x52001B44` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT210` | DMA2D 背景颜色查找表 | `0xB48` | `0x52001B48` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT211` | DMA2D 背景颜色查找表 | `0xB4C` | `0x52001B4C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT212` | DMA2D 背景颜色查找表 | `0xB50` | `0x52001B50` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT213` | DMA2D 背景颜色查找表 | `0xB54` | `0x52001B54` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT214` | DMA2D 背景颜色查找表 | `0xB58` | `0x52001B58` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT215` | DMA2D 背景颜色查找表 | `0xB5C` | `0x52001B5C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT216` | DMA2D 背景颜色查找表 | `0xB60` | `0x52001B60` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT217` | DMA2D 背景颜色查找表 | `0xB64` | `0x52001B64` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT218` | DMA2D 背景颜色查找表 | `0xB68` | `0x52001B68` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT219` | DMA2D 背景颜色查找表 | `0xB6C` | `0x52001B6C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT220` | DMA2D 背景颜色查找表 | `0xB70` | `0x52001B70` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT221` | DMA2D 背景颜色查找表 | `0xB74` | `0x52001B74` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT222` | DMA2D 背景颜色查找表 | `0xB78` | `0x52001B78` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT223` | DMA2D 背景颜色查找表 | `0xB7C` | `0x52001B7C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT224` | DMA2D 背景颜色查找表 | `0xB80` | `0x52001B80` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT225` | DMA2D 背景颜色查找表 | `0xB84` | `0x52001B84` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT226` | DMA2D 背景颜色查找表 | `0xB88` | `0x52001B88` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT227` | DMA2D 背景颜色查找表 | `0xB8C` | `0x52001B8C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT228` | DMA2D 背景颜色查找表 | `0xB90` | `0x52001B90` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT229` | DMA2D 背景颜色查找表 | `0xB94` | `0x52001B94` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT230` | DMA2D 背景颜色查找表 | `0xB98` | `0x52001B98` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT231` | DMA2D 背景颜色查找表 | `0xB9C` | `0x52001B9C` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT232` | DMA2D 背景颜色查找表 | `0xBA0` | `0x52001BA0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT233` | DMA2D 背景颜色查找表 | `0xBA4` | `0x52001BA4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT234` | DMA2D 背景颜色查找表 | `0xBA8` | `0x52001BA8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT235` | DMA2D 背景颜色查找表 | `0xBAC` | `0x52001BAC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT236` | DMA2D 背景颜色查找表 | `0xBB0` | `0x52001BB0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT237` | DMA2D 背景颜色查找表 | `0xBB4` | `0x52001BB4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT238` | DMA2D 背景颜色查找表 | `0xBB8` | `0x52001BB8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT239` | DMA2D 背景颜色查找表 | `0xBBC` | `0x52001BBC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT240` | DMA2D 背景颜色查找表 | `0xBC0` | `0x52001BC0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT241` | DMA2D 背景颜色查找表 | `0xBC4` | `0x52001BC4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT242` | DMA2D 背景颜色查找表 | `0xBC8` | `0x52001BC8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT243` | DMA2D 背景颜色查找表 | `0xBCC` | `0x52001BCC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT244` | DMA2D 背景颜色查找表 | `0xBD0` | `0x52001BD0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT245` | DMA2D 背景颜色查找表 | `0xBD4` | `0x52001BD4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT246` | DMA2D 背景颜色查找表 | `0xBD8` | `0x52001BD8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT247` | DMA2D 背景颜色查找表 | `0xBDC` | `0x52001BDC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT248` | DMA2D 背景颜色查找表 | `0xBE0` | `0x52001BE0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT249` | DMA2D 背景颜色查找表 | `0xBE4` | `0x52001BE4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT250` | DMA2D 背景颜色查找表 | `0xBE8` | `0x52001BE8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT251` | DMA2D 背景颜色查找表 | `0xBEC` | `0x52001BEC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT252` | DMA2D 背景颜色查找表 | `0xBF0` | `0x52001BF0` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT253` | DMA2D 背景颜色查找表 | `0xBF4` | `0x52001BF4` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT254` | DMA2D 背景颜色查找表 | `0xBF8` | `0x52001BF8` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |
| `DMA2D_BGCLUT255` | DMA2D 背景颜色查找表 | `0xBFC` | `0x52001BFC` | 32 | — | 0x00000000 / 0x00000000 | ALPHA[31:24] (RW)（Alpha 分量）、RED[23:16] (RW)（红色分量）、GREEN[15:8] (RW)（绿色分量）、BLUE[7:0] (RW)（蓝色分量） | — |

## GFXMMU

**模块用途**　图形存储映射单元，通过查找表把虚拟帧缓冲行映射到物理存储块。

基地址 `0x52010000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `GFXMMU_CR` | GFXMMU 配置寄存器 | `0x000` | `0x52010000` | 32 | — | 0x00000000 / 0xFFFFFFFF | B3PM[31] (RW)（缓冲区 3 打包模式）、B3PE[30] (RW)（缓冲区 3 打包使能）、B2PM[29] (RW)（缓冲区 2 打包模式）、B2PE[28] (RW)（缓冲区 2 打包使能）、B1PM[27] (RW)（缓冲区 1 打包模式）、B1PE[26] (RW)（缓冲区 1 打包使能）、B0PM[25] (RW)（缓冲区 0 打包模式）、B0PE[24] (RW)（缓冲区 0 打包使能）、ATE[15] (RW)（待核）、BS[6] (RW)（块大小）、AMEIE[4] (RW)（AXI 主设备错误中断使能）、B3OIE[3] (RW)（缓冲区 3 溢出中断使能）、B2OIE[2] (RW)（缓冲区 2 溢出中断使能）、B1OIE[1] (RW)（缓冲区 1 溢出中断使能）、B0OIE[0] (RW)（缓冲区 0 溢出中断使能） | — |
| `GFXMMU_SR` | GFXMMU 状态寄存器 | `0x004` | `0x52010004` | 32 | — | 0x00000000 / 0xFFFFFFFF | AMEF[4] (RO)（AXI 主设备错误标志）、B3OF[3] (RO)（缓冲区 3 溢出标志）、B2OF[2] (RO)（缓冲区 2 溢出标志）、B1OF[1] (RO)（缓冲区 1 溢出标志）、B0OF[0] (RO)（缓冲区 0 溢出标志） | — |
| `GFXMMU_FCR` | GFXMMU 清除标志寄存器 | `0x008` | `0x52010008` | 32 | — | 0x00000000 / 0xFFFFFFFF | CAMEF[4] (RW)（清除 AXI 主设备错误标志）、CB3OF[3] (RW)（清除缓冲区 3 溢出标志）、CB2OF[2] (RW)（清除缓冲区 2 溢出标志）、CB1OF[1] (RW)（清除缓冲区 1 溢出标志）、CB0OF[0] (RW)（清除缓冲区 0 溢出标志） | — |
| `GFXMMU_DVR` | 默认像素数据配置 | `0x010` | `0x52010010` | 32 | — | 0x00000000 / 0xFFFFFFFF | DV[31:0] (RW)（默认值） | — |
| `GFXMMU_DAR` | 默认 Alpha 值配置 | `0x014` | `0x52010014` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[7:0] (RW)（默认透明度） | — |
| `GFXMMU_B0CR` | GFXMMU 缓冲区 0 配置寄存器 | `0x020` | `0x52010020` | 32 | — | 0x00000000 / 0xFFFFFFFF | PBBA[31:23] (RW)（物理缓冲区基地址）、PBO[22:4] (RW)（物理缓冲区偏移） | — |
| `GFXMMU_B1CR` | GFXMMU 缓冲区 1 配置寄存器 | `0x024` | `0x52010024` | 32 | — | 0x00000000 / 0xFFFFFFFF | PBBA[31:23] (RW)（物理缓冲区基地址）、PBO[22:4] (RW)（物理缓冲区偏移） | — |
| `GFXMMU_B2CR` | GFXMMU 缓冲区 2 配置寄存器 | `0x028` | `0x52010028` | 32 | — | 0x00000000 / 0xFFFFFFFF | PBBA[31:23] (RW)（物理缓冲区基地址）、PBO[22:4] (RW)（物理缓冲区偏移） | — |
| `GFXMMU_B3CR` | GFXMMU 缓冲区 3 配置寄存器 | `0x02C` | `0x5201002C` | 32 | — | 0x00000000 / 0xFFFFFFFF | PBBA[31:23] (RW)（物理缓冲区基地址）、PBO[22:4] (RW)（物理缓冲区偏移） | — |
| `GFXMMU_LUT0L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1000` | `0x52011000` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT0H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1004` | `0x52011004` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1008` | `0x52011008` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x100C` | `0x5201100C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT2L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1010` | `0x52011010` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT2H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1014` | `0x52011014` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT3L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1018` | `0x52011018` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT3H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x101C` | `0x5201101C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT4L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1020` | `0x52011020` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT4H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1024` | `0x52011024` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT5L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1028` | `0x52011028` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT5H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x102C` | `0x5201102C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT6L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1030` | `0x52011030` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT6H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1034` | `0x52011034` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT7L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1038` | `0x52011038` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT7H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x103C` | `0x5201103C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT8L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1040` | `0x52011040` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT8H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1044` | `0x52011044` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT9L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1048` | `0x52011048` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT9H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x104C` | `0x5201104C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT10L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1050` | `0x52011050` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT10H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1054` | `0x52011054` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT11L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1058` | `0x52011058` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT11H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x105C` | `0x5201105C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT12L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1060` | `0x52011060` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT12H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1064` | `0x52011064` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT13L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1068` | `0x52011068` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT13H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x106C` | `0x5201106C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT14L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1070` | `0x52011070` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT14H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1074` | `0x52011074` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT15L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1078` | `0x52011078` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT15H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x107C` | `0x5201107C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT16L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1080` | `0x52011080` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT16H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1084` | `0x52011084` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT17L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1088` | `0x52011088` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT17H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x108C` | `0x5201108C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT18L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1090` | `0x52011090` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT18H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1094` | `0x52011094` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT19L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1098` | `0x52011098` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT19H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x109C` | `0x5201109C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT20L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x10A0` | `0x520110A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT20H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x10A4` | `0x520110A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT21L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x10A8` | `0x520110A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT21H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x10AC` | `0x520110AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT22L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x10B0` | `0x520110B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT22H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x10B4` | `0x520110B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT23L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x10B8` | `0x520110B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT23H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x10BC` | `0x520110BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT24L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x10C0` | `0x520110C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT24H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x10C4` | `0x520110C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT25L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x10C8` | `0x520110C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT25H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x10CC` | `0x520110CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT26L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x10D0` | `0x520110D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT26H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x10D4` | `0x520110D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT27L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x10D8` | `0x520110D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT27H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x10DC` | `0x520110DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT28L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x10E0` | `0x520110E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT28H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x10E4` | `0x520110E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT29L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x10E8` | `0x520110E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT29H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x10EC` | `0x520110EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT30L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x10F0` | `0x520110F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT30H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x10F4` | `0x520110F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT31L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x10F8` | `0x520110F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT31H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x10FC` | `0x520110FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT32L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1100` | `0x52011100` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT32H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1104` | `0x52011104` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT33L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1108` | `0x52011108` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT33H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x110C` | `0x5201110C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT34L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1110` | `0x52011110` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT34H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1114` | `0x52011114` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT35L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1118` | `0x52011118` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT35H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x111C` | `0x5201111C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT36L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1120` | `0x52011120` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT36H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1124` | `0x52011124` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT37L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1128` | `0x52011128` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT37H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x112C` | `0x5201112C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT38L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1130` | `0x52011130` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT38H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1134` | `0x52011134` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT39L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1138` | `0x52011138` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT39H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x113C` | `0x5201113C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT40L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1140` | `0x52011140` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT40H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1144` | `0x52011144` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT41L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1148` | `0x52011148` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT41H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x114C` | `0x5201114C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT42L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1150` | `0x52011150` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT42H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1154` | `0x52011154` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT43L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1158` | `0x52011158` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT43H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x115C` | `0x5201115C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT44L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1160` | `0x52011160` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT44H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1164` | `0x52011164` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT45L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1168` | `0x52011168` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT45H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x116C` | `0x5201116C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT46L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1170` | `0x52011170` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT46H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1174` | `0x52011174` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT47L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1178` | `0x52011178` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT47H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x117C` | `0x5201117C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT48L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1180` | `0x52011180` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT48H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1184` | `0x52011184` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT49L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1188` | `0x52011188` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT49H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x118C` | `0x5201118C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT50L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1190` | `0x52011190` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT50H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1194` | `0x52011194` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT51L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1198` | `0x52011198` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT51H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x119C` | `0x5201119C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT52L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x11A0` | `0x520111A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT52H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x11A4` | `0x520111A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT53L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x11A8` | `0x520111A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT53H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x11AC` | `0x520111AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT54L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x11B0` | `0x520111B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT54H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x11B4` | `0x520111B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT55L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x11B8` | `0x520111B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT55H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x11BC` | `0x520111BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT56L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x11C0` | `0x520111C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT56H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x11C4` | `0x520111C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT57L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x11C8` | `0x520111C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT57H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x11CC` | `0x520111CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT58L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x11D0` | `0x520111D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT58H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x11D4` | `0x520111D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT59L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x11D8` | `0x520111D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT59H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x11DC` | `0x520111DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT60L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x11E0` | `0x520111E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT60H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x11E4` | `0x520111E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT61L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x11E8` | `0x520111E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT61H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x11EC` | `0x520111EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT62L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x11F0` | `0x520111F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT62H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x11F4` | `0x520111F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT63L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x11F8` | `0x520111F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT63H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x11FC` | `0x520111FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT64L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1200` | `0x52011200` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT64H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1204` | `0x52011204` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT65L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1208` | `0x52011208` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT65H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x120C` | `0x5201120C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT66L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1210` | `0x52011210` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT66H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1214` | `0x52011214` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT67L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1218` | `0x52011218` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT67H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x121C` | `0x5201121C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT68L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1220` | `0x52011220` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT68H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1224` | `0x52011224` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT69L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1228` | `0x52011228` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT69H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x122C` | `0x5201122C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT70L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1230` | `0x52011230` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT70H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1234` | `0x52011234` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT71L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1238` | `0x52011238` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT71H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x123C` | `0x5201123C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT72L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1240` | `0x52011240` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT72H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1244` | `0x52011244` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT73L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1248` | `0x52011248` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT73H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x124C` | `0x5201124C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT74L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1250` | `0x52011250` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT74H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1254` | `0x52011254` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（待核） | — |
| `GFXMMU_LUT75L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1258` | `0x52011258` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT75H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x125C` | `0x5201125C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT76L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1260` | `0x52011260` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT76H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1264` | `0x52011264` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT77L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1268` | `0x52011268` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT77H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x126C` | `0x5201126C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT78L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1270` | `0x52011270` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT78H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1274` | `0x52011274` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT79L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1278` | `0x52011278` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT79H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x127C` | `0x5201127C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT80L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1280` | `0x52011280` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT80H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1284` | `0x52011284` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT81L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1288` | `0x52011288` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT81H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x128C` | `0x5201128C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT82L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1290` | `0x52011290` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT82H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1294` | `0x52011294` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT83L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1298` | `0x52011298` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT83H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x129C` | `0x5201129C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT84L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x12A0` | `0x520112A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT84H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x12A4` | `0x520112A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT85L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x12A8` | `0x520112A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT85H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x12AC` | `0x520112AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT86L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x12B0` | `0x520112B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT86H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x12B4` | `0x520112B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT87L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x12B8` | `0x520112B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT87H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x12BC` | `0x520112BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT88L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x12C0` | `0x520112C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT88H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x12C4` | `0x520112C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT89L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x12C8` | `0x520112C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT89H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x12CC` | `0x520112CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT90L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x12D0` | `0x520112D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT90H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x12D4` | `0x520112D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT91L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x12D8` | `0x520112D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT91H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x12DC` | `0x520112DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT92L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x12E0` | `0x520112E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT92H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x12E4` | `0x520112E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT93L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x12E8` | `0x520112E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT93H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x12EC` | `0x520112EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT94L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x12F0` | `0x520112F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT94H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x12F4` | `0x520112F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT95L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x12F8` | `0x520112F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT95H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x12FC` | `0x520112FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT96L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1300` | `0x52011300` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT96H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1304` | `0x52011304` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT97L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1308` | `0x52011308` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT97H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x130C` | `0x5201130C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT98L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1310` | `0x52011310` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT98H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1314` | `0x52011314` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT99L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1318` | `0x52011318` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT99H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x131C` | `0x5201131C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT100L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1320` | `0x52011320` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT100H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1324` | `0x52011324` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT101L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1328` | `0x52011328` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT101H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x132C` | `0x5201132C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT102L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1330` | `0x52011330` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT102H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1334` | `0x52011334` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT103L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1338` | `0x52011338` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT103H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x133C` | `0x5201133C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT104L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1340` | `0x52011340` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT104H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1344` | `0x52011344` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT105L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1348` | `0x52011348` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT105H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x134C` | `0x5201134C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT106L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1350` | `0x52011350` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT106H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1354` | `0x52011354` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT107L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1358` | `0x52011358` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT107H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x135C` | `0x5201135C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT108L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1360` | `0x52011360` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT108H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1364` | `0x52011364` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT109L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1368` | `0x52011368` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT109H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x136C` | `0x5201136C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT110L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1370` | `0x52011370` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT110H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1374` | `0x52011374` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT111L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1378` | `0x52011378` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT111H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x137C` | `0x5201137C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT112L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1380` | `0x52011380` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT112H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1384` | `0x52011384` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT113L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1388` | `0x52011388` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT113H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x138C` | `0x5201138C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT114L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1390` | `0x52011390` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT114H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1394` | `0x52011394` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT115L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1398` | `0x52011398` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT115H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x139C` | `0x5201139C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT116L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x13A0` | `0x520113A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT116H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x13A4` | `0x520113A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT117L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x13A8` | `0x520113A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT117H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x13AC` | `0x520113AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT118L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x13B0` | `0x520113B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT118H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x13B4` | `0x520113B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT119L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x13B8` | `0x520113B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT119H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x13BC` | `0x520113BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT120L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x13C0` | `0x520113C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT120H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x13C4` | `0x520113C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT121L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x13C8` | `0x520113C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT121H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x13CC` | `0x520113CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT122L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x13D0` | `0x520113D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT122H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x13D4` | `0x520113D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT123L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x13D8` | `0x520113D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT123H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x13DC` | `0x520113DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT124L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x13E0` | `0x520113E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT124H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x13E4` | `0x520113E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT125L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x13E8` | `0x520113E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT125H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x13EC` | `0x520113EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT126L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x13F0` | `0x520113F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT126H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x13F4` | `0x520113F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT127L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x13F8` | `0x520113F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT127H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x13FC` | `0x520113FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT128L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1400` | `0x52011400` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT128H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1404` | `0x52011404` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT129L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1408` | `0x52011408` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT129H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x140C` | `0x5201140C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT130L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1410` | `0x52011410` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT130H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1414` | `0x52011414` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT131L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1418` | `0x52011418` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT131H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x141C` | `0x5201141C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT132L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1420` | `0x52011420` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT132H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1424` | `0x52011424` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT133L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1428` | `0x52011428` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT133H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x142C` | `0x5201142C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT134L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1430` | `0x52011430` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT134H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1434` | `0x52011434` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT135L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1438` | `0x52011438` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT135H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x143C` | `0x5201143C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT136L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1440` | `0x52011440` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT136H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1444` | `0x52011444` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT137L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1448` | `0x52011448` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT137H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x144C` | `0x5201144C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT138L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1450` | `0x52011450` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT138H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1454` | `0x52011454` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT139L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1458` | `0x52011458` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT139H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x145C` | `0x5201145C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT140L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1460` | `0x52011460` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT140H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1464` | `0x52011464` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT141L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1468` | `0x52011468` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT141H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x146C` | `0x5201146C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT142L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1470` | `0x52011470` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT142H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1474` | `0x52011474` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT143L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1478` | `0x52011478` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT143H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x147C` | `0x5201147C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT144L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1480` | `0x52011480` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT144H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1484` | `0x52011484` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT145L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1488` | `0x52011488` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT145H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x148C` | `0x5201148C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT146L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1490` | `0x52011490` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT146H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1494` | `0x52011494` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT147L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1498` | `0x52011498` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT147H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x149C` | `0x5201149C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT148L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x14A0` | `0x520114A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT148H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x14A4` | `0x520114A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT149L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x14A8` | `0x520114A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT149H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x14AC` | `0x520114AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT150L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x14B0` | `0x520114B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT150H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x14B4` | `0x520114B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT151L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x14B8` | `0x520114B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT151H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x14BC` | `0x520114BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT152L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x14C0` | `0x520114C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT152H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x14C4` | `0x520114C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT153L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x14C8` | `0x520114C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT153H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x14CC` | `0x520114CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT154L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x14D0` | `0x520114D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT154H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x14D4` | `0x520114D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT155L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x14D8` | `0x520114D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT155H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x14DC` | `0x520114DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT156L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x14E0` | `0x520114E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT156H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x14E4` | `0x520114E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT157L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x14E8` | `0x520114E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT157H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x14EC` | `0x520114EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT158L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x14F0` | `0x520114F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT158H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x14F4` | `0x520114F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT159L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x14F8` | `0x520114F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT159H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x14FC` | `0x520114FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT160L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1500` | `0x52011500` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT160H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1504` | `0x52011504` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT161L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1508` | `0x52011508` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT161H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x150C` | `0x5201150C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT162L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1510` | `0x52011510` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT162H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1514` | `0x52011514` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT163L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1518` | `0x52011518` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT163H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x151C` | `0x5201151C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT164L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1520` | `0x52011520` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT164H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1524` | `0x52011524` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT165L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1528` | `0x52011528` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT165H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x152C` | `0x5201152C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT166L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1530` | `0x52011530` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT166H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1534` | `0x52011534` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT167L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1538` | `0x52011538` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT167H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x153C` | `0x5201153C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT168L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1540` | `0x52011540` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT168H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1544` | `0x52011544` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT169L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1548` | `0x52011548` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT169H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x154C` | `0x5201154C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT170L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1550` | `0x52011550` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT170H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1554` | `0x52011554` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT171L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1558` | `0x52011558` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT171H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x155C` | `0x5201155C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT172L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1560` | `0x52011560` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT172H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1564` | `0x52011564` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT173L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1568` | `0x52011568` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT173H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x156C` | `0x5201156C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT174L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1570` | `0x52011570` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT174H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1574` | `0x52011574` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT175L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1578` | `0x52011578` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT175H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x157C` | `0x5201157C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT176L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1580` | `0x52011580` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT176H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1584` | `0x52011584` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT177L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1588` | `0x52011588` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT177H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x158C` | `0x5201158C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT178L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1590` | `0x52011590` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT178H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1594` | `0x52011594` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT179L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1598` | `0x52011598` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT179H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x159C` | `0x5201159C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT180L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x15A0` | `0x520115A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT180H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x15A4` | `0x520115A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT181L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x15A8` | `0x520115A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT181H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x15AC` | `0x520115AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT182L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x15B0` | `0x520115B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT182H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x15B4` | `0x520115B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT183L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x15B8` | `0x520115B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT183H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x15BC` | `0x520115BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT184L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x15C0` | `0x520115C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT184H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x15C4` | `0x520115C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT185L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x15C8` | `0x520115C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT185H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x15CC` | `0x520115CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT186L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x15D0` | `0x520115D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT186H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x15D4` | `0x520115D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT187L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x15D8` | `0x520115D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT187H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x15DC` | `0x520115DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT188L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x15E0` | `0x520115E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT188H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x15E4` | `0x520115E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT189L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x15E8` | `0x520115E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT189H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x15EC` | `0x520115EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT190L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x15F0` | `0x520115F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT190H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x15F4` | `0x520115F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT191L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x15F8` | `0x520115F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT191H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x15FC` | `0x520115FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT192L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1600` | `0x52011600` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT192H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1604` | `0x52011604` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT193L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1608` | `0x52011608` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT193H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x160C` | `0x5201160C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT194L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1610` | `0x52011610` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT194H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1614` | `0x52011614` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT195L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1618` | `0x52011618` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT195H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x161C` | `0x5201161C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT196L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1620` | `0x52011620` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT196H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1624` | `0x52011624` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT197L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1628` | `0x52011628` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT197H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x162C` | `0x5201162C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT198L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1630` | `0x52011630` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT198H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1634` | `0x52011634` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT199L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1638` | `0x52011638` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT199H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x163C` | `0x5201163C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT200L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1640` | `0x52011640` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT200H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1644` | `0x52011644` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT201L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1648` | `0x52011648` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT201H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x164C` | `0x5201164C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT202L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1650` | `0x52011650` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT202H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1654` | `0x52011654` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT203L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1658` | `0x52011658` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT203H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x165C` | `0x5201165C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT204L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1660` | `0x52011660` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT204H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1664` | `0x52011664` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT205L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1668` | `0x52011668` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT205H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x166C` | `0x5201166C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT206L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1670` | `0x52011670` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT206H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1674` | `0x52011674` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT207L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1678` | `0x52011678` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT207H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x167C` | `0x5201167C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT208L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1680` | `0x52011680` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT208H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1684` | `0x52011684` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT209L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1688` | `0x52011688` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT209H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x168C` | `0x5201168C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT210L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1690` | `0x52011690` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT210H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1694` | `0x52011694` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT211L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1698` | `0x52011698` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT211H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x169C` | `0x5201169C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT212L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x16A0` | `0x520116A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT212H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x16A4` | `0x520116A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT213L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x16A8` | `0x520116A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT213H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x16AC` | `0x520116AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT214L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x16B0` | `0x520116B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT214H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x16B4` | `0x520116B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT215L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x16B8` | `0x520116B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT215H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x16BC` | `0x520116BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT216L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x16C0` | `0x520116C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT216H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x16C4` | `0x520116C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT217L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x16C8` | `0x520116C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT217H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x16CC` | `0x520116CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT218L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x16D0` | `0x520116D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT218H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x16D4` | `0x520116D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT219L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x16D8` | `0x520116D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT219H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x16DC` | `0x520116DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT220L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x16E0` | `0x520116E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT220H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x16E4` | `0x520116E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT221L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x16E8` | `0x520116E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT221H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x16EC` | `0x520116EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT222L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x16F0` | `0x520116F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT222H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x16F4` | `0x520116F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT223L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x16F8` | `0x520116F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT223H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x16FC` | `0x520116FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT224L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1700` | `0x52011700` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT224H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1704` | `0x52011704` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT225L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1708` | `0x52011708` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT225H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x170C` | `0x5201170C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT226L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1710` | `0x52011710` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT226H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1714` | `0x52011714` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT227L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1718` | `0x52011718` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT227H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x171C` | `0x5201171C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT228L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1720` | `0x52011720` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT228H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1724` | `0x52011724` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT229L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1728` | `0x52011728` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT229H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x172C` | `0x5201172C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT230L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1730` | `0x52011730` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT230H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1734` | `0x52011734` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT231L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1738` | `0x52011738` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT231H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x173C` | `0x5201173C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT232L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1740` | `0x52011740` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT232H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1744` | `0x52011744` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT233L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1748` | `0x52011748` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT233H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x174C` | `0x5201174C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT234L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1750` | `0x52011750` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT234H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1754` | `0x52011754` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT235L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1758` | `0x52011758` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT235H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x175C` | `0x5201175C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT236L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1760` | `0x52011760` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT236H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1764` | `0x52011764` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT237L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1768` | `0x52011768` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT237H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x176C` | `0x5201176C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT238L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1770` | `0x52011770` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT238H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1774` | `0x52011774` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT239L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1778` | `0x52011778` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT239H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x177C` | `0x5201177C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT240L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1780` | `0x52011780` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT240H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1784` | `0x52011784` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT241L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1788` | `0x52011788` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT241H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x178C` | `0x5201178C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT242L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1790` | `0x52011790` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT242H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1794` | `0x52011794` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT243L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1798` | `0x52011798` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT243H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x179C` | `0x5201179C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT244L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x17A0` | `0x520117A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT244H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x17A4` | `0x520117A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT245L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x17A8` | `0x520117A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT245H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x17AC` | `0x520117AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT246L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x17B0` | `0x520117B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT246H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x17B4` | `0x520117B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT247L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x17B8` | `0x520117B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT247H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x17BC` | `0x520117BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT248L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x17C0` | `0x520117C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT248H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x17C4` | `0x520117C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT249L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x17C8` | `0x520117C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT249H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x17CC` | `0x520117CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT250L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x17D0` | `0x520117D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT250H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x17D4` | `0x520117D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT251L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x17D8` | `0x520117D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT251H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x17DC` | `0x520117DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT252L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x17E0` | `0x520117E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT252H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x17E4` | `0x520117E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT253L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x17E8` | `0x520117E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT253H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x17EC` | `0x520117EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT254L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x17F0` | `0x520117F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT254H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x17F4` | `0x520117F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT255L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x17F8` | `0x520117F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT255H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x17FC` | `0x520117FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT256L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1800` | `0x52011800` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT256H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1804` | `0x52011804` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT257L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1808` | `0x52011808` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT257H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x180C` | `0x5201180C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT258L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1810` | `0x52011810` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT258H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1814` | `0x52011814` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT259L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1818` | `0x52011818` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT259H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x181C` | `0x5201181C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT260L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1820` | `0x52011820` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT260H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1824` | `0x52011824` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT261L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1828` | `0x52011828` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT261H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x182C` | `0x5201182C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT262L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1830` | `0x52011830` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT262H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1834` | `0x52011834` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT263L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1838` | `0x52011838` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT263H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x183C` | `0x5201183C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT264L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1840` | `0x52011840` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT264H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1844` | `0x52011844` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT265L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1848` | `0x52011848` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT265H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x184C` | `0x5201184C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT266L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1850` | `0x52011850` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT266H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1854` | `0x52011854` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT267L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1858` | `0x52011858` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT267H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x185C` | `0x5201185C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT268L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1860` | `0x52011860` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT268H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1864` | `0x52011864` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT269L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1868` | `0x52011868` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT269H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x186C` | `0x5201186C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT270L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1870` | `0x52011870` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT270H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1874` | `0x52011874` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT271L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1878` | `0x52011878` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT271H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x187C` | `0x5201187C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT272L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1880` | `0x52011880` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT272H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1884` | `0x52011884` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT273L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1888` | `0x52011888` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT273H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x188C` | `0x5201188C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT274L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1890` | `0x52011890` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT274H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1894` | `0x52011894` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT275L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1898` | `0x52011898` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT275H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x189C` | `0x5201189C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT276L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x18A0` | `0x520118A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT276H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x18A4` | `0x520118A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT277L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x18A8` | `0x520118A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT277H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x18AC` | `0x520118AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT278L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x18B0` | `0x520118B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT278H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x18B4` | `0x520118B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT279L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x18B8` | `0x520118B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT279H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x18BC` | `0x520118BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT280L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x18C0` | `0x520118C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT280H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x18C4` | `0x520118C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT281L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x18C8` | `0x520118C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT281H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x18CC` | `0x520118CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT282L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x18D0` | `0x520118D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT282H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x18D4` | `0x520118D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT283L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x18D8` | `0x520118D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT283H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x18DC` | `0x520118DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT284L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x18E0` | `0x520118E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT284H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x18E4` | `0x520118E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT285L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x18E8` | `0x520118E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT285H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x18EC` | `0x520118EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT286L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x18F0` | `0x520118F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT286H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x18F4` | `0x520118F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT287L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x18F8` | `0x520118F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT287H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x18FC` | `0x520118FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT288L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1900` | `0x52011900` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT288H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1904` | `0x52011904` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT289L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1908` | `0x52011908` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT289H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x190C` | `0x5201190C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT290L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1910` | `0x52011910` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT290H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1914` | `0x52011914` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT291L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1918` | `0x52011918` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT291H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x191C` | `0x5201191C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT292L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1920` | `0x52011920` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT292H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1924` | `0x52011924` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT293L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1928` | `0x52011928` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT293H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x192C` | `0x5201192C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT294L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1930` | `0x52011930` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT294H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1934` | `0x52011934` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT295L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1938` | `0x52011938` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT295H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x193C` | `0x5201193C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT296L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1940` | `0x52011940` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT296H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1944` | `0x52011944` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT297L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1948` | `0x52011948` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT297H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x194C` | `0x5201194C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT298L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1950` | `0x52011950` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT298H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1954` | `0x52011954` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT299L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1958` | `0x52011958` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT299H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x195C` | `0x5201195C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT300L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1960` | `0x52011960` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT300H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1964` | `0x52011964` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT301L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1968` | `0x52011968` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT301H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x196C` | `0x5201196C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT302L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1970` | `0x52011970` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT302H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1974` | `0x52011974` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT303L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1978` | `0x52011978` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT303H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x197C` | `0x5201197C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT304L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1980` | `0x52011980` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT304H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1984` | `0x52011984` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT305L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1988` | `0x52011988` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT305H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x198C` | `0x5201198C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT306L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1990` | `0x52011990` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT306H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1994` | `0x52011994` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT307L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1998` | `0x52011998` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT307H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x199C` | `0x5201199C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT308L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x19A0` | `0x520119A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT308H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x19A4` | `0x520119A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT309L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x19A8` | `0x520119A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT309H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x19AC` | `0x520119AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT310L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x19B0` | `0x520119B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT310H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x19B4` | `0x520119B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT311L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x19B8` | `0x520119B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT311H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x19BC` | `0x520119BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT312L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x19C0` | `0x520119C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT312H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x19C4` | `0x520119C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT313L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x19C8` | `0x520119C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT313H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x19CC` | `0x520119CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT314L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x19D0` | `0x520119D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT314H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x19D4` | `0x520119D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT315L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x19D8` | `0x520119D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT315H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x19DC` | `0x520119DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT316L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x19E0` | `0x520119E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT316H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x19E4` | `0x520119E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT317L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x19E8` | `0x520119E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT317H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x19EC` | `0x520119EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT318L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x19F0` | `0x520119F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT318H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x19F4` | `0x520119F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT319L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x19F8` | `0x520119F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT319H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x19FC` | `0x520119FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT320L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A00` | `0x52011A00` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT320H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A04` | `0x52011A04` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT321L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A08` | `0x52011A08` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT321H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A0C` | `0x52011A0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT322L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A10` | `0x52011A10` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT322H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A14` | `0x52011A14` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT323L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A18` | `0x52011A18` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT323H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A1C` | `0x52011A1C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT324L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A20` | `0x52011A20` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT324H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A24` | `0x52011A24` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT325L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A28` | `0x52011A28` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT325H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A2C` | `0x52011A2C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT326L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A30` | `0x52011A30` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT326H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A34` | `0x52011A34` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT327L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A38` | `0x52011A38` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT327H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A3C` | `0x52011A3C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT328L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A40` | `0x52011A40` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT328H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A44` | `0x52011A44` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT329L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A48` | `0x52011A48` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT329H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A4C` | `0x52011A4C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT330L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A50` | `0x52011A50` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT330H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A54` | `0x52011A54` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT331L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A58` | `0x52011A58` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT331H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A5C` | `0x52011A5C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT332L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A60` | `0x52011A60` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT332H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A64` | `0x52011A64` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT333L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A68` | `0x52011A68` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT333H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A6C` | `0x52011A6C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT334L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A70` | `0x52011A70` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT334H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A74` | `0x52011A74` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT335L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A78` | `0x52011A78` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT335H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A7C` | `0x52011A7C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT336L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A80` | `0x52011A80` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT336H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A84` | `0x52011A84` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT337L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A88` | `0x52011A88` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT337H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A8C` | `0x52011A8C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT338L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A90` | `0x52011A90` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT338H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A94` | `0x52011A94` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT339L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1A98` | `0x52011A98` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT339H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1A9C` | `0x52011A9C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT340L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1AA0` | `0x52011AA0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT340H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1AA4` | `0x52011AA4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT341L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1AA8` | `0x52011AA8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT341H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1AAC` | `0x52011AAC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT342L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1AB0` | `0x52011AB0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT342H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1AB4` | `0x52011AB4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT343L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1AB8` | `0x52011AB8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT343H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1ABC` | `0x52011ABC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT344L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1AC0` | `0x52011AC0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT344H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1AC4` | `0x52011AC4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT345L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1AC8` | `0x52011AC8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT345H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1ACC` | `0x52011ACC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT346L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1AD0` | `0x52011AD0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT346H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1AD4` | `0x52011AD4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT347L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1AD8` | `0x52011AD8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT347H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1ADC` | `0x52011ADC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT348L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1AE0` | `0x52011AE0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT348H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1AE4` | `0x52011AE4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT349L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1AE8` | `0x52011AE8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT349H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1AEC` | `0x52011AEC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT350L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1AF0` | `0x52011AF0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT350H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1AF4` | `0x52011AF4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT351L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1AF8` | `0x52011AF8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT351H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1AFC` | `0x52011AFC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT352L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B00` | `0x52011B00` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT352H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B04` | `0x52011B04` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT353L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B08` | `0x52011B08` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT353H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B0C` | `0x52011B0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT354L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B10` | `0x52011B10` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT354H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B14` | `0x52011B14` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT355L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B18` | `0x52011B18` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT355H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B1C` | `0x52011B1C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT356L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B20` | `0x52011B20` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT356H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B24` | `0x52011B24` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT357L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B28` | `0x52011B28` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT357H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B2C` | `0x52011B2C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT358L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B30` | `0x52011B30` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT358H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B34` | `0x52011B34` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT359L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B38` | `0x52011B38` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT359H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B3C` | `0x52011B3C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT360L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B40` | `0x52011B40` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT360H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B44` | `0x52011B44` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT361L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B48` | `0x52011B48` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT361H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B4C` | `0x52011B4C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT362L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B50` | `0x52011B50` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT362H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B54` | `0x52011B54` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT363L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B58` | `0x52011B58` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT363H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B5C` | `0x52011B5C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT364L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B60` | `0x52011B60` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT364H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B64` | `0x52011B64` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT365L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B68` | `0x52011B68` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT365H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B6C` | `0x52011B6C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT366L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B70` | `0x52011B70` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT366H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B74` | `0x52011B74` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT367L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B78` | `0x52011B78` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT367H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B7C` | `0x52011B7C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT368L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B80` | `0x52011B80` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT368H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B84` | `0x52011B84` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT369L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B88` | `0x52011B88` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT369H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B8C` | `0x52011B8C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT370L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B90` | `0x52011B90` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT370H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B94` | `0x52011B94` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT371L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1B98` | `0x52011B98` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT371H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1B9C` | `0x52011B9C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT372L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1BA0` | `0x52011BA0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT372H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1BA4` | `0x52011BA4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT373L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1BA8` | `0x52011BA8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT373H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1BAC` | `0x52011BAC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT374L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1BB0` | `0x52011BB0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT374H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1BB4` | `0x52011BB4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT375L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1BB8` | `0x52011BB8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT375H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1BBC` | `0x52011BBC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT376L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1BC0` | `0x52011BC0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT376H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1BC4` | `0x52011BC4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT377L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1BC8` | `0x52011BC8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT377H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1BCC` | `0x52011BCC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT378L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1BD0` | `0x52011BD0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT378H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1BD4` | `0x52011BD4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT379L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1BD8` | `0x52011BD8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT379H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1BDC` | `0x52011BDC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT380L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1BE0` | `0x52011BE0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT380H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1BE4` | `0x52011BE4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT381L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1BE8` | `0x52011BE8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT381H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1BEC` | `0x52011BEC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT382L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1BF0` | `0x52011BF0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT382H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1BF4` | `0x52011BF4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT383L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1BF8` | `0x52011BF8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT383H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1BFC` | `0x52011BFC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT384L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C00` | `0x52011C00` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT384H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C04` | `0x52011C04` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT385L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C08` | `0x52011C08` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT385H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C0C` | `0x52011C0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT386L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C10` | `0x52011C10` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT386H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C14` | `0x52011C14` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT387L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C18` | `0x52011C18` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT387H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C1C` | `0x52011C1C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT388L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C20` | `0x52011C20` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT388H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C24` | `0x52011C24` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT389L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C28` | `0x52011C28` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT389H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C2C` | `0x52011C2C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT390L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C30` | `0x52011C30` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT390H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C34` | `0x52011C34` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT391L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C38` | `0x52011C38` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT391H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C3C` | `0x52011C3C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT392L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C40` | `0x52011C40` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT392H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C44` | `0x52011C44` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT393L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C48` | `0x52011C48` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT393H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C4C` | `0x52011C4C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT394L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C50` | `0x52011C50` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT394H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C54` | `0x52011C54` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT395L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C58` | `0x52011C58` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT395H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C5C` | `0x52011C5C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT396L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C60` | `0x52011C60` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT396H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C64` | `0x52011C64` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT397L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C68` | `0x52011C68` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT397H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C6C` | `0x52011C6C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT398L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C70` | `0x52011C70` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT398H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C74` | `0x52011C74` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT399L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C78` | `0x52011C78` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT399H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C7C` | `0x52011C7C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT400L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C80` | `0x52011C80` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT400H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C84` | `0x52011C84` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT401L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C88` | `0x52011C88` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT401H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C8C` | `0x52011C8C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT402L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C90` | `0x52011C90` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT402H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C94` | `0x52011C94` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT403L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1C98` | `0x52011C98` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT403H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1C9C` | `0x52011C9C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT404L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1CA0` | `0x52011CA0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT404H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1CA4` | `0x52011CA4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT405L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1CA8` | `0x52011CA8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT405H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1CAC` | `0x52011CAC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT406L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1CB0` | `0x52011CB0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT406H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1CB4` | `0x52011CB4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT407L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1CB8` | `0x52011CB8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT407H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1CBC` | `0x52011CBC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT408L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1CC0` | `0x52011CC0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT408H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1CC4` | `0x52011CC4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT409L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1CC8` | `0x52011CC8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT409H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1CCC` | `0x52011CCC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT410L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1CD0` | `0x52011CD0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT410H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1CD4` | `0x52011CD4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT411L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1CD8` | `0x52011CD8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT411H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1CDC` | `0x52011CDC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT412L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1CE0` | `0x52011CE0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT412H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1CE4` | `0x52011CE4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT413L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1CE8` | `0x52011CE8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT413H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1CEC` | `0x52011CEC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT414L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1CF0` | `0x52011CF0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT414H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1CF4` | `0x52011CF4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT415L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1CF8` | `0x52011CF8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT415H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1CFC` | `0x52011CFC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT416L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D00` | `0x52011D00` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT416H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D04` | `0x52011D04` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT417L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D08` | `0x52011D08` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT417H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D0C` | `0x52011D0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT418L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D10` | `0x52011D10` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT418H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D14` | `0x52011D14` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT419L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D18` | `0x52011D18` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT419H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D1C` | `0x52011D1C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT420L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D20` | `0x52011D20` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT420H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D24` | `0x52011D24` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT421L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D28` | `0x52011D28` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT421H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D2C` | `0x52011D2C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT422L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D30` | `0x52011D30` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT422H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D34` | `0x52011D34` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT423L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D38` | `0x52011D38` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT423H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D3C` | `0x52011D3C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT424L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D40` | `0x52011D40` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT424H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D44` | `0x52011D44` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT425L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D48` | `0x52011D48` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT425H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D4C` | `0x52011D4C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT426L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D50` | `0x52011D50` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT426H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D54` | `0x52011D54` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT427L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D58` | `0x52011D58` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT427H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D5C` | `0x52011D5C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT428L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D60` | `0x52011D60` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT428H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D64` | `0x52011D64` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT429L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D68` | `0x52011D68` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT429H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D6C` | `0x52011D6C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT430L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D70` | `0x52011D70` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT430H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D74` | `0x52011D74` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT431L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D78` | `0x52011D78` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT431H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D7C` | `0x52011D7C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT432L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D80` | `0x52011D80` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT432H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D84` | `0x52011D84` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT433L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D88` | `0x52011D88` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT433H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D8C` | `0x52011D8C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT434L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D90` | `0x52011D90` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT434H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D94` | `0x52011D94` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT435L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1D98` | `0x52011D98` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT435H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1D9C` | `0x52011D9C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT436L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1DA0` | `0x52011DA0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT436H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1DA4` | `0x52011DA4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT437L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1DA8` | `0x52011DA8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT437H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1DAC` | `0x52011DAC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT438L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1DB0` | `0x52011DB0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT438H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1DB4` | `0x52011DB4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT439L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1DB8` | `0x52011DB8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT439H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1DBC` | `0x52011DBC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT440L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1DC0` | `0x52011DC0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT440H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1DC4` | `0x52011DC4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT441L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1DC8` | `0x52011DC8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT441H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1DCC` | `0x52011DCC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT442L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1DD0` | `0x52011DD0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT442H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1DD4` | `0x52011DD4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT443L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1DD8` | `0x52011DD8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT443H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1DDC` | `0x52011DDC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT444L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1DE0` | `0x52011DE0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT444H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1DE4` | `0x52011DE4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT445L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1DE8` | `0x52011DE8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT445H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1DEC` | `0x52011DEC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT446L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1DF0` | `0x52011DF0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT446H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1DF4` | `0x52011DF4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT447L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1DF8` | `0x52011DF8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT447H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1DFC` | `0x52011DFC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT448L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E00` | `0x52011E00` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT448H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E04` | `0x52011E04` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT449L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E08` | `0x52011E08` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT449H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E0C` | `0x52011E0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT450L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E10` | `0x52011E10` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT450H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E14` | `0x52011E14` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT451L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E18` | `0x52011E18` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT451H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E1C` | `0x52011E1C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT452L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E20` | `0x52011E20` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT452H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E24` | `0x52011E24` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT453L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E28` | `0x52011E28` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT453H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E2C` | `0x52011E2C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT454L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E30` | `0x52011E30` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT454H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E34` | `0x52011E34` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT455L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E38` | `0x52011E38` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT455H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E3C` | `0x52011E3C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT456L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E40` | `0x52011E40` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT456H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E44` | `0x52011E44` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT457L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E48` | `0x52011E48` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT457H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E4C` | `0x52011E4C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT458L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E50` | `0x52011E50` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT458H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E54` | `0x52011E54` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT459L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E58` | `0x52011E58` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT459H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E5C` | `0x52011E5C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT460L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E60` | `0x52011E60` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT460H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E64` | `0x52011E64` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT461L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E68` | `0x52011E68` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT461H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E6C` | `0x52011E6C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT462L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E70` | `0x52011E70` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT462H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E74` | `0x52011E74` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT463L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E78` | `0x52011E78` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT463H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E7C` | `0x52011E7C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT464L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E80` | `0x52011E80` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT464H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E84` | `0x52011E84` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT465L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E88` | `0x52011E88` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT465H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E8C` | `0x52011E8C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT466L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E90` | `0x52011E90` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT466H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E94` | `0x52011E94` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT467L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1E98` | `0x52011E98` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT467H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1E9C` | `0x52011E9C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT468L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1EA0` | `0x52011EA0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT468H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1EA4` | `0x52011EA4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT469L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1EA8` | `0x52011EA8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT469H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1EAC` | `0x52011EAC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT470L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1EB0` | `0x52011EB0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT470H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1EB4` | `0x52011EB4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT471L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1EB8` | `0x52011EB8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT471H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1EBC` | `0x52011EBC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT472L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1EC0` | `0x52011EC0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT472H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1EC4` | `0x52011EC4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT473L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1EC8` | `0x52011EC8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT473H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1ECC` | `0x52011ECC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT474L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1ED0` | `0x52011ED0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT474H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1ED4` | `0x52011ED4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT475L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1ED8` | `0x52011ED8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT475H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1EDC` | `0x52011EDC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT476L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1EE0` | `0x52011EE0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT476H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1EE4` | `0x52011EE4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT477L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1EE8` | `0x52011EE8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT477H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1EEC` | `0x52011EEC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT478L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1EF0` | `0x52011EF0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT478H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1EF4` | `0x52011EF4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT479L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1EF8` | `0x52011EF8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT479H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1EFC` | `0x52011EFC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT480L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F00` | `0x52011F00` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT480H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F04` | `0x52011F04` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT481L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F08` | `0x52011F08` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT481H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F0C` | `0x52011F0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT482L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F10` | `0x52011F10` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT482H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F14` | `0x52011F14` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT483L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F18` | `0x52011F18` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT483H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F1C` | `0x52011F1C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT484L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F20` | `0x52011F20` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT484H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F24` | `0x52011F24` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT485L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F28` | `0x52011F28` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT485H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F2C` | `0x52011F2C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT486L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F30` | `0x52011F30` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT486H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F34` | `0x52011F34` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT487L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F38` | `0x52011F38` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT487H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F3C` | `0x52011F3C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT488L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F40` | `0x52011F40` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT488H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F44` | `0x52011F44` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT489L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F48` | `0x52011F48` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT489H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F4C` | `0x52011F4C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT490L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F50` | `0x52011F50` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT490H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F54` | `0x52011F54` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT491L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F58` | `0x52011F58` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT491H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F5C` | `0x52011F5C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT492L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F60` | `0x52011F60` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT492H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F64` | `0x52011F64` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT493L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F68` | `0x52011F68` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT493H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F6C` | `0x52011F6C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT494L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F70` | `0x52011F70` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT494H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F74` | `0x52011F74` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT495L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F78` | `0x52011F78` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT495H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F7C` | `0x52011F7C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT496L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F80` | `0x52011F80` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT496H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F84` | `0x52011F84` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT497L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F88` | `0x52011F88` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT497H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F8C` | `0x52011F8C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT498L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F90` | `0x52011F90` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT498H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F94` | `0x52011F94` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT499L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1F98` | `0x52011F98` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT499H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1F9C` | `0x52011F9C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT500L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1FA0` | `0x52011FA0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT500H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1FA4` | `0x52011FA4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT501L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1FA8` | `0x52011FA8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT501H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1FAC` | `0x52011FAC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT502L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1FB0` | `0x52011FB0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT502H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1FB4` | `0x52011FB4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT503L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1FB8` | `0x52011FB8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT503H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1FBC` | `0x52011FBC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT504L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1FC0` | `0x52011FC0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT504H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1FC4` | `0x52011FC4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT505L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1FC8` | `0x52011FC8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT505H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1FCC` | `0x52011FCC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT506L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1FD0` | `0x52011FD0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT506H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1FD4` | `0x52011FD4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT507L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1FD8` | `0x52011FD8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT507H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1FDC` | `0x52011FDC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT508L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1FE0` | `0x52011FE0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT508H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1FE4` | `0x52011FE4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT509L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1FE8` | `0x52011FE8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT509H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1FEC` | `0x52011FEC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT510L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1FF0` | `0x52011FF0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT510H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1FF4` | `0x52011FF4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT511L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x1FF8` | `0x52011FF8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT511H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x1FFC` | `0x52011FFC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT512L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2000` | `0x52012000` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT512H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2004` | `0x52012004` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT513L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2008` | `0x52012008` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT513H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x200C` | `0x5201200C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT514L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2010` | `0x52012010` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT514H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2014` | `0x52012014` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT515L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2018` | `0x52012018` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT515H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x201C` | `0x5201201C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT516L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2020` | `0x52012020` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT516H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2024` | `0x52012024` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT517L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2028` | `0x52012028` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT517H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x202C` | `0x5201202C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT518L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2030` | `0x52012030` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT518H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2034` | `0x52012034` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT519L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2038` | `0x52012038` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT519H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x203C` | `0x5201203C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT520L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2040` | `0x52012040` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT520H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2044` | `0x52012044` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT521L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2048` | `0x52012048` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT521H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x204C` | `0x5201204C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT522L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2050` | `0x52012050` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT522H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2054` | `0x52012054` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT523L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2058` | `0x52012058` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT523H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x205C` | `0x5201205C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT524L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2060` | `0x52012060` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT524H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2064` | `0x52012064` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT525L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2068` | `0x52012068` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT525H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x206C` | `0x5201206C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT526L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2070` | `0x52012070` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT526H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2074` | `0x52012074` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT527L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2078` | `0x52012078` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT527H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x207C` | `0x5201207C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT528L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2080` | `0x52012080` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT528H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2084` | `0x52012084` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT529L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2088` | `0x52012088` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT529H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x208C` | `0x5201208C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT530L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2090` | `0x52012090` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT530H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2094` | `0x52012094` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT531L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2098` | `0x52012098` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT531H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x209C` | `0x5201209C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT532L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x20A0` | `0x520120A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT532H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x20A4` | `0x520120A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT533L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x20A8` | `0x520120A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT533H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x20AC` | `0x520120AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT534L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x20B0` | `0x520120B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT534H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x20B4` | `0x520120B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT535L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x20B8` | `0x520120B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT535H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x20BC` | `0x520120BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT536L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x20C0` | `0x520120C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT536H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x20C4` | `0x520120C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT537L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x20C8` | `0x520120C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT537H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x20CC` | `0x520120CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT538L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x20D0` | `0x520120D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT538H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x20D4` | `0x520120D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT539L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x20D8` | `0x520120D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT539H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x20DC` | `0x520120DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT540L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x20E0` | `0x520120E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT540H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x20E4` | `0x520120E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT541L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x20E8` | `0x520120E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT541H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x20EC` | `0x520120EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT542L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x20F0` | `0x520120F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT542H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x20F4` | `0x520120F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT543L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x20F8` | `0x520120F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT543H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x20FC` | `0x520120FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT544L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2100` | `0x52012100` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT544H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2104` | `0x52012104` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT545L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2108` | `0x52012108` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT545H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x210C` | `0x5201210C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT546L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2110` | `0x52012110` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT546H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2114` | `0x52012114` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT547L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2118` | `0x52012118` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT547H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x211C` | `0x5201211C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT548L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2120` | `0x52012120` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT548H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2124` | `0x52012124` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT549L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2128` | `0x52012128` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT549H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x212C` | `0x5201212C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT550L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2130` | `0x52012130` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT550H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2134` | `0x52012134` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT551L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2138` | `0x52012138` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT551H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x213C` | `0x5201213C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT552L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2140` | `0x52012140` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT552H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2144` | `0x52012144` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT553L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2148` | `0x52012148` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT553H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x214C` | `0x5201214C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT554L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2150` | `0x52012150` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT554H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2154` | `0x52012154` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT555L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2158` | `0x52012158` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT555H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x215C` | `0x5201215C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT556L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2160` | `0x52012160` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT556H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2164` | `0x52012164` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT557L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2168` | `0x52012168` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT557H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x216C` | `0x5201216C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT558L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2170` | `0x52012170` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT558H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2174` | `0x52012174` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT559L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2178` | `0x52012178` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT559H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x217C` | `0x5201217C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT560L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2180` | `0x52012180` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT560H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2184` | `0x52012184` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT561L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2188` | `0x52012188` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT561H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x218C` | `0x5201218C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT562L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2190` | `0x52012190` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT562H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2194` | `0x52012194` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT563L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2198` | `0x52012198` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT563H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x219C` | `0x5201219C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT564L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x21A0` | `0x520121A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT564H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x21A4` | `0x520121A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT565L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x21A8` | `0x520121A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT565H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x21AC` | `0x520121AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT566L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x21B0` | `0x520121B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT566H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x21B4` | `0x520121B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT567L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x21B8` | `0x520121B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT567H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x21BC` | `0x520121BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT568L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x21C0` | `0x520121C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT568H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x21C4` | `0x520121C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT569L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x21C8` | `0x520121C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT569H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x21CC` | `0x520121CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT570L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x21D0` | `0x520121D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT570H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x21D4` | `0x520121D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT571L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x21D8` | `0x520121D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT571H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x21DC` | `0x520121DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT572L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x21E0` | `0x520121E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT572H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x21E4` | `0x520121E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT573L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x21E8` | `0x520121E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT573H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x21EC` | `0x520121EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT574L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x21F0` | `0x520121F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT574H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x21F4` | `0x520121F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT575L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x21F8` | `0x520121F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT575H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x21FC` | `0x520121FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT576L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2200` | `0x52012200` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT576H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2204` | `0x52012204` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT577L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2208` | `0x52012208` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT577H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x220C` | `0x5201220C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT578L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2210` | `0x52012210` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT578H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2214` | `0x52012214` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT579L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2218` | `0x52012218` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT579H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x221C` | `0x5201221C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT580L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2220` | `0x52012220` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT580H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2224` | `0x52012224` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT581L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2228` | `0x52012228` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT581H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x222C` | `0x5201222C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT582L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2230` | `0x52012230` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT582H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2234` | `0x52012234` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT583L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2238` | `0x52012238` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT583H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x223C` | `0x5201223C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT584L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2240` | `0x52012240` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT584H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2244` | `0x52012244` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT585L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2248` | `0x52012248` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT585H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x224C` | `0x5201224C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT586L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2250` | `0x52012250` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT586H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2254` | `0x52012254` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT587L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2258` | `0x52012258` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT587H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x225C` | `0x5201225C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT588L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2260` | `0x52012260` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT588H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2264` | `0x52012264` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT589L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2268` | `0x52012268` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT589H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x226C` | `0x5201226C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT590L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2270` | `0x52012270` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT590H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2274` | `0x52012274` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT591L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2278` | `0x52012278` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT591H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x227C` | `0x5201227C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT592L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2280` | `0x52012280` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT592H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2284` | `0x52012284` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT593L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2288` | `0x52012288` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT593H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x228C` | `0x5201228C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT594L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2290` | `0x52012290` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT594H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2294` | `0x52012294` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT595L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2298` | `0x52012298` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT595H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x229C` | `0x5201229C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT596L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x22A0` | `0x520122A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT596H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x22A4` | `0x520122A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT597L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x22A8` | `0x520122A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT597H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x22AC` | `0x520122AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT598L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x22B0` | `0x520122B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT598H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x22B4` | `0x520122B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT599L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x22B8` | `0x520122B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT599H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x22BC` | `0x520122BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT600L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x22C0` | `0x520122C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT600H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x22C4` | `0x520122C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT601L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x22C8` | `0x520122C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT601H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x22CC` | `0x520122CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT602L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x22D0` | `0x520122D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT602H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x22D4` | `0x520122D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT603L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x22D8` | `0x520122D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT603H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x22DC` | `0x520122DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT604L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x22E0` | `0x520122E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT604H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x22E4` | `0x520122E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT605L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x22E8` | `0x520122E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT605H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x22EC` | `0x520122EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT606L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x22F0` | `0x520122F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT606H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x22F4` | `0x520122F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT607L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x22F8` | `0x520122F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT607H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x22FC` | `0x520122FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT608L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2300` | `0x52012300` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT608H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2304` | `0x52012304` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT609L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2308` | `0x52012308` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT609H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x230C` | `0x5201230C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT610L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2310` | `0x52012310` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT610H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2314` | `0x52012314` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT611L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2318` | `0x52012318` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT611H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x231C` | `0x5201231C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT612L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2320` | `0x52012320` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT612H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2324` | `0x52012324` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT613L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2328` | `0x52012328` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT613H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x232C` | `0x5201232C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT614L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2330` | `0x52012330` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT614H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2334` | `0x52012334` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT615L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2338` | `0x52012338` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT615H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x233C` | `0x5201233C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT616L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2340` | `0x52012340` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT616H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2344` | `0x52012344` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT617L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2348` | `0x52012348` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT617H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x234C` | `0x5201234C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT618L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2350` | `0x52012350` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT618H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2354` | `0x52012354` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT619L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2358` | `0x52012358` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT619H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x235C` | `0x5201235C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT620L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2360` | `0x52012360` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT620H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2364` | `0x52012364` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT621L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2368` | `0x52012368` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT621H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x236C` | `0x5201236C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT622L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2370` | `0x52012370` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT622H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2374` | `0x52012374` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT623L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2378` | `0x52012378` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT623H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x237C` | `0x5201237C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT624L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2380` | `0x52012380` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT624H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2384` | `0x52012384` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT625L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2388` | `0x52012388` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT625H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x238C` | `0x5201238C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT626L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2390` | `0x52012390` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT626H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2394` | `0x52012394` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT627L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2398` | `0x52012398` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT627H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x239C` | `0x5201239C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT628L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x23A0` | `0x520123A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT628H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x23A4` | `0x520123A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT629L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x23A8` | `0x520123A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT629H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x23AC` | `0x520123AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT630L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x23B0` | `0x520123B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT630H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x23B4` | `0x520123B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT631L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x23B8` | `0x520123B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT631H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x23BC` | `0x520123BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT632L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x23C0` | `0x520123C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT632H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x23C4` | `0x520123C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT633L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x23C8` | `0x520123C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT633H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x23CC` | `0x520123CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT634L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x23D0` | `0x520123D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT634H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x23D4` | `0x520123D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT635L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x23D8` | `0x520123D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT635H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x23DC` | `0x520123DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT636L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x23E0` | `0x520123E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT636H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x23E4` | `0x520123E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT637L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x23E8` | `0x520123E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT637H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x23EC` | `0x520123EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT638L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x23F0` | `0x520123F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT638H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x23F4` | `0x520123F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT639L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x23F8` | `0x520123F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT639H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x23FC` | `0x520123FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT640L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2400` | `0x52012400` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT640H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2404` | `0x52012404` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT641L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2408` | `0x52012408` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT641H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x240C` | `0x5201240C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT642L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2410` | `0x52012410` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT642H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2414` | `0x52012414` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT643L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2418` | `0x52012418` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT643H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x241C` | `0x5201241C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT644L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2420` | `0x52012420` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT644H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2424` | `0x52012424` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT645L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2428` | `0x52012428` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT645H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x242C` | `0x5201242C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT646L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2430` | `0x52012430` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT646H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2434` | `0x52012434` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT647L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2438` | `0x52012438` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT647H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x243C` | `0x5201243C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT648L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2440` | `0x52012440` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT648H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2444` | `0x52012444` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT649L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2448` | `0x52012448` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT649H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x244C` | `0x5201244C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT650L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2450` | `0x52012450` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT650H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2454` | `0x52012454` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT651L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2458` | `0x52012458` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT651H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x245C` | `0x5201245C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT652L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2460` | `0x52012460` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT652H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2464` | `0x52012464` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT653L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2468` | `0x52012468` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT653H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x246C` | `0x5201246C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT654L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2470` | `0x52012470` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT654H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2474` | `0x52012474` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT655L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2478` | `0x52012478` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT655H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x247C` | `0x5201247C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT656L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2480` | `0x52012480` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT656H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2484` | `0x52012484` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT657L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2488` | `0x52012488` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT657H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x248C` | `0x5201248C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT658L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2490` | `0x52012490` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT658H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2494` | `0x52012494` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT659L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2498` | `0x52012498` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT659H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x249C` | `0x5201249C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT660L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x24A0` | `0x520124A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT660H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x24A4` | `0x520124A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT661L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x24A8` | `0x520124A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT661H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x24AC` | `0x520124AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT662L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x24B0` | `0x520124B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT662H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x24B4` | `0x520124B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT663L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x24B8` | `0x520124B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT663H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x24BC` | `0x520124BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT664L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x24C0` | `0x520124C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT664H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x24C4` | `0x520124C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT665L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x24C8` | `0x520124C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT665H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x24CC` | `0x520124CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT666L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x24D0` | `0x520124D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT666H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x24D4` | `0x520124D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT667L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x24D8` | `0x520124D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT667H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x24DC` | `0x520124DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT668L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x24E0` | `0x520124E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT668H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x24E4` | `0x520124E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT669L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x24E8` | `0x520124E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT669H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x24EC` | `0x520124EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT670L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x24F0` | `0x520124F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT670H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x24F4` | `0x520124F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT671L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x24F8` | `0x520124F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT671H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x24FC` | `0x520124FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT672L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2500` | `0x52012500` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT672H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2504` | `0x52012504` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT673L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2508` | `0x52012508` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT673H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x250C` | `0x5201250C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT674L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2510` | `0x52012510` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT674H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2514` | `0x52012514` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT675L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2518` | `0x52012518` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT675H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x251C` | `0x5201251C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT676L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2520` | `0x52012520` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT676H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2524` | `0x52012524` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT677L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2528` | `0x52012528` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT677H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x252C` | `0x5201252C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT678L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2530` | `0x52012530` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT678H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2534` | `0x52012534` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT679L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2538` | `0x52012538` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT679H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x253C` | `0x5201253C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT680L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2540` | `0x52012540` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT680H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2544` | `0x52012544` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT681L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2548` | `0x52012548` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT681H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x254C` | `0x5201254C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT682L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2550` | `0x52012550` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT682H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2554` | `0x52012554` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT683L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2558` | `0x52012558` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT683H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x255C` | `0x5201255C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT684L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2560` | `0x52012560` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT684H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2564` | `0x52012564` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT685L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2568` | `0x52012568` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT685H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x256C` | `0x5201256C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT686L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2570` | `0x52012570` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT686H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2574` | `0x52012574` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT687L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2578` | `0x52012578` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT687H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x257C` | `0x5201257C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT688L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2580` | `0x52012580` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT688H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2584` | `0x52012584` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT689L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2588` | `0x52012588` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT689H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x258C` | `0x5201258C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT690L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2590` | `0x52012590` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT690H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2594` | `0x52012594` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT691L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2598` | `0x52012598` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT691H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x259C` | `0x5201259C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT692L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x25A0` | `0x520125A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT692H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x25A4` | `0x520125A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT693L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x25A8` | `0x520125A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT693H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x25AC` | `0x520125AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT694L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x25B0` | `0x520125B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT694H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x25B4` | `0x520125B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT695L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x25B8` | `0x520125B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT695H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x25BC` | `0x520125BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT696L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x25C0` | `0x520125C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT696H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x25C4` | `0x520125C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT697L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x25C8` | `0x520125C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT697H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x25CC` | `0x520125CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT698L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x25D0` | `0x520125D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT698H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x25D4` | `0x520125D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT699L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x25D8` | `0x520125D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT699H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x25DC` | `0x520125DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT700L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x25E0` | `0x520125E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT700H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x25E4` | `0x520125E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT701L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x25E8` | `0x520125E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT701H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x25EC` | `0x520125EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT702L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x25F0` | `0x520125F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT702H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x25F4` | `0x520125F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT703L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x25F8` | `0x520125F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT703H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x25FC` | `0x520125FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT704L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2600` | `0x52012600` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT704H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2604` | `0x52012604` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT705L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2608` | `0x52012608` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT705H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x260C` | `0x5201260C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT706L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2610` | `0x52012610` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT706H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2614` | `0x52012614` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT707L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2618` | `0x52012618` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT707H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x261C` | `0x5201261C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT708L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2620` | `0x52012620` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT708H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2624` | `0x52012624` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT709L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2628` | `0x52012628` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT709H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x262C` | `0x5201262C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT710L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2630` | `0x52012630` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT710H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2634` | `0x52012634` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT711L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2638` | `0x52012638` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT711H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x263C` | `0x5201263C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT712L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2640` | `0x52012640` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT712H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2644` | `0x52012644` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT713L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2648` | `0x52012648` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT713H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x264C` | `0x5201264C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT714L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2650` | `0x52012650` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT714H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2654` | `0x52012654` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT715L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2658` | `0x52012658` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT715H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x265C` | `0x5201265C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT716L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2660` | `0x52012660` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT716H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2664` | `0x52012664` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT717L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2668` | `0x52012668` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT717H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x266C` | `0x5201266C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT718L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2670` | `0x52012670` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT718H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2674` | `0x52012674` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT719L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2678` | `0x52012678` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT719H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x267C` | `0x5201267C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT720L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2680` | `0x52012680` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT720H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2684` | `0x52012684` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT721L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2688` | `0x52012688` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT721H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x268C` | `0x5201268C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT722L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2690` | `0x52012690` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT722H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2694` | `0x52012694` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT723L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2698` | `0x52012698` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT723H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x269C` | `0x5201269C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT724L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x26A0` | `0x520126A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT724H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x26A4` | `0x520126A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT725L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x26A8` | `0x520126A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT725H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x26AC` | `0x520126AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT726L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x26B0` | `0x520126B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT726H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x26B4` | `0x520126B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT727L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x26B8` | `0x520126B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT727H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x26BC` | `0x520126BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT728L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x26C0` | `0x520126C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT728H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x26C4` | `0x520126C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT729L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x26C8` | `0x520126C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT729H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x26CC` | `0x520126CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT730L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x26D0` | `0x520126D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT730H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x26D4` | `0x520126D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT731L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x26D8` | `0x520126D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT731H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x26DC` | `0x520126DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT732L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x26E0` | `0x520126E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT732H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x26E4` | `0x520126E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT733L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x26E8` | `0x520126E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT733H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x26EC` | `0x520126EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT734L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x26F0` | `0x520126F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT734H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x26F4` | `0x520126F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT735L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x26F8` | `0x520126F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT735H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x26FC` | `0x520126FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT736L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2700` | `0x52012700` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT736H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2704` | `0x52012704` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT737L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2708` | `0x52012708` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT737H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x270C` | `0x5201270C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT738L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2710` | `0x52012710` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT738H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2714` | `0x52012714` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT739L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2718` | `0x52012718` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT739H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x271C` | `0x5201271C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT740L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2720` | `0x52012720` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT740H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2724` | `0x52012724` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT741L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2728` | `0x52012728` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT741H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x272C` | `0x5201272C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT742L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2730` | `0x52012730` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT742H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2734` | `0x52012734` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT743L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2738` | `0x52012738` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT743H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x273C` | `0x5201273C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT744L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2740` | `0x52012740` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT744H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2744` | `0x52012744` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT745L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2748` | `0x52012748` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT745H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x274C` | `0x5201274C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT746L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2750` | `0x52012750` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT746H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2754` | `0x52012754` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT747L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2758` | `0x52012758` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT747H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x275C` | `0x5201275C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT748L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2760` | `0x52012760` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT748H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2764` | `0x52012764` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT749L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2768` | `0x52012768` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT749H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x276C` | `0x5201276C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT750L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2770` | `0x52012770` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT750H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2774` | `0x52012774` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT751L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2778` | `0x52012778` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT751H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x277C` | `0x5201277C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT752L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2780` | `0x52012780` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT752H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2784` | `0x52012784` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT753L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2788` | `0x52012788` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT753H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x278C` | `0x5201278C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT754L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2790` | `0x52012790` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT754H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2794` | `0x52012794` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT755L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2798` | `0x52012798` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT755H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x279C` | `0x5201279C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT756L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x27A0` | `0x520127A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT756H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x27A4` | `0x520127A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT757L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x27A8` | `0x520127A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT757H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x27AC` | `0x520127AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT758L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x27B0` | `0x520127B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT758H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x27B4` | `0x520127B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT759L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x27B8` | `0x520127B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT759H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x27BC` | `0x520127BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT760L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x27C0` | `0x520127C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT760H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x27C4` | `0x520127C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT761L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x27C8` | `0x520127C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT761H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x27CC` | `0x520127CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT762L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x27D0` | `0x520127D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT762H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x27D4` | `0x520127D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT763L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x27D8` | `0x520127D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT763H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x27DC` | `0x520127DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT764L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x27E0` | `0x520127E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT764H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x27E4` | `0x520127E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT765L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x27E8` | `0x520127E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT765H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x27EC` | `0x520127EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT766L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x27F0` | `0x520127F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT766H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x27F4` | `0x520127F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT767L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x27F8` | `0x520127F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT767H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x27FC` | `0x520127FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT768L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2800` | `0x52012800` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT768H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2804` | `0x52012804` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT769L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2808` | `0x52012808` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT769H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x280C` | `0x5201280C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT770L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2810` | `0x52012810` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT770H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2814` | `0x52012814` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT771L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2818` | `0x52012818` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT771H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x281C` | `0x5201281C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT772L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2820` | `0x52012820` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT772H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2824` | `0x52012824` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT773L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2828` | `0x52012828` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT773H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x282C` | `0x5201282C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT774L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2830` | `0x52012830` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT774H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2834` | `0x52012834` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT775L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2838` | `0x52012838` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT775H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x283C` | `0x5201283C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT776L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2840` | `0x52012840` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT776H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2844` | `0x52012844` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT777L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2848` | `0x52012848` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT777H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x284C` | `0x5201284C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT778L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2850` | `0x52012850` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT778H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2854` | `0x52012854` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT779L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2858` | `0x52012858` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT779H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x285C` | `0x5201285C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT780L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2860` | `0x52012860` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT780H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2864` | `0x52012864` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT781L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2868` | `0x52012868` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT781H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x286C` | `0x5201286C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT782L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2870` | `0x52012870` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT782H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2874` | `0x52012874` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT783L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2878` | `0x52012878` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT783H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x287C` | `0x5201287C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT784L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2880` | `0x52012880` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT784H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2884` | `0x52012884` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT785L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2888` | `0x52012888` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT785H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x288C` | `0x5201288C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT786L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2890` | `0x52012890` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT786H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2894` | `0x52012894` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT787L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2898` | `0x52012898` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT787H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x289C` | `0x5201289C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT788L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x28A0` | `0x520128A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT788H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x28A4` | `0x520128A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT789L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x28A8` | `0x520128A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT789H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x28AC` | `0x520128AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT790L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x28B0` | `0x520128B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT790H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x28B4` | `0x520128B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT791L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x28B8` | `0x520128B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT791H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x28BC` | `0x520128BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT792L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x28C0` | `0x520128C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT792H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x28C4` | `0x520128C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT793L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x28C8` | `0x520128C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT793H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x28CC` | `0x520128CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT794L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x28D0` | `0x520128D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT794H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x28D4` | `0x520128D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT795L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x28D8` | `0x520128D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT795H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x28DC` | `0x520128DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT796L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x28E0` | `0x520128E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT796H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x28E4` | `0x520128E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT797L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x28E8` | `0x520128E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT797H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x28EC` | `0x520128EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT798L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x28F0` | `0x520128F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT798H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x28F4` | `0x520128F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT799L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x28F8` | `0x520128F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT799H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x28FC` | `0x520128FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT800L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2900` | `0x52012900` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT800H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2904` | `0x52012904` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT801L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2908` | `0x52012908` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT801H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x290C` | `0x5201290C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT802L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2910` | `0x52012910` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT802H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2914` | `0x52012914` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT803L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2918` | `0x52012918` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT803H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x291C` | `0x5201291C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT804L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2920` | `0x52012920` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT804H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2924` | `0x52012924` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT805L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2928` | `0x52012928` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT805H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x292C` | `0x5201292C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT806L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2930` | `0x52012930` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT806H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2934` | `0x52012934` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT807L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2938` | `0x52012938` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT807H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x293C` | `0x5201293C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT808L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2940` | `0x52012940` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT808H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2944` | `0x52012944` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT809L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2948` | `0x52012948` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT809H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x294C` | `0x5201294C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT810L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2950` | `0x52012950` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT810H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2954` | `0x52012954` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT811L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2958` | `0x52012958` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT811H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x295C` | `0x5201295C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT812L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2960` | `0x52012960` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT812H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2964` | `0x52012964` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT813L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2968` | `0x52012968` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT813H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x296C` | `0x5201296C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT814L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2970` | `0x52012970` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT814H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2974` | `0x52012974` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT815L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2978` | `0x52012978` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT815H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x297C` | `0x5201297C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT816L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2980` | `0x52012980` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT816H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2984` | `0x52012984` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT817L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2988` | `0x52012988` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT817H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x298C` | `0x5201298C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT818L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2990` | `0x52012990` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT818H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2994` | `0x52012994` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT819L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2998` | `0x52012998` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT819H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x299C` | `0x5201299C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT820L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x29A0` | `0x520129A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT820H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x29A4` | `0x520129A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT821L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x29A8` | `0x520129A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT821H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x29AC` | `0x520129AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT822L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x29B0` | `0x520129B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT822H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x29B4` | `0x520129B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT823L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x29B8` | `0x520129B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT823H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x29BC` | `0x520129BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT824L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x29C0` | `0x520129C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT824H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x29C4` | `0x520129C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT825L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x29C8` | `0x520129C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT825H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x29CC` | `0x520129CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT826L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x29D0` | `0x520129D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT826H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x29D4` | `0x520129D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT827L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x29D8` | `0x520129D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT827H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x29DC` | `0x520129DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT828L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x29E0` | `0x520129E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT828H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x29E4` | `0x520129E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT829L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x29E8` | `0x520129E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT829H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x29EC` | `0x520129EC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT830L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x29F0` | `0x520129F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT830H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x29F4` | `0x520129F4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT831L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x29F8` | `0x520129F8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT831H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x29FC` | `0x520129FC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT832L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A00` | `0x52012A00` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT832H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A04` | `0x52012A04` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT833L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A08` | `0x52012A08` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT833H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A0C` | `0x52012A0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT834L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A10` | `0x52012A10` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT834H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A14` | `0x52012A14` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT835L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A18` | `0x52012A18` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT835H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A1C` | `0x52012A1C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT836L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A20` | `0x52012A20` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT836H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A24` | `0x52012A24` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT837L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A28` | `0x52012A28` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT837H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A2C` | `0x52012A2C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT838L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A30` | `0x52012A30` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT838H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A34` | `0x52012A34` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT839L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A38` | `0x52012A38` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT839H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A3C` | `0x52012A3C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT840L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A40` | `0x52012A40` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT840H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A44` | `0x52012A44` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT841L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A48` | `0x52012A48` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT841H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A4C` | `0x52012A4C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT842L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A50` | `0x52012A50` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT842H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A54` | `0x52012A54` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT843L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A58` | `0x52012A58` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT843H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A5C` | `0x52012A5C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT844L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A60` | `0x52012A60` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT844H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A64` | `0x52012A64` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT845L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A68` | `0x52012A68` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT845H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A6C` | `0x52012A6C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT846L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A70` | `0x52012A70` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT846H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A74` | `0x52012A74` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT847L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A78` | `0x52012A78` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT847H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A7C` | `0x52012A7C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT848L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A80` | `0x52012A80` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT848H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A84` | `0x52012A84` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT849L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A88` | `0x52012A88` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT849H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A8C` | `0x52012A8C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT850L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A90` | `0x52012A90` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT850H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A94` | `0x52012A94` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT851L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2A98` | `0x52012A98` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT851H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2A9C` | `0x52012A9C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT852L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2AA0` | `0x52012AA0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT852H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2AA4` | `0x52012AA4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT853L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2AA8` | `0x52012AA8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT853H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2AAC` | `0x52012AAC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT854L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2AB0` | `0x52012AB0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT854H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2AB4` | `0x52012AB4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT855L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2AB8` | `0x52012AB8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT855H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2ABC` | `0x52012ABC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT856L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2AC0` | `0x52012AC0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT856H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2AC4` | `0x52012AC4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT857L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2AC8` | `0x52012AC8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT857H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2ACC` | `0x52012ACC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT858L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2AD0` | `0x52012AD0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT858H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2AD4` | `0x52012AD4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT859L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2AD8` | `0x52012AD8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT859H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2ADC` | `0x52012ADC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT860L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2AE0` | `0x52012AE0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT860H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2AE4` | `0x52012AE4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT861L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2AE8` | `0x52012AE8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT861H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2AEC` | `0x52012AEC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT862L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2AF0` | `0x52012AF0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT862H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2AF4` | `0x52012AF4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT863L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2AF8` | `0x52012AF8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT863H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2AFC` | `0x52012AFC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT864L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B00` | `0x52012B00` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT864H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B04` | `0x52012B04` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT865L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B08` | `0x52012B08` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT865H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B0C` | `0x52012B0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT866L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B10` | `0x52012B10` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT866H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B14` | `0x52012B14` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT867L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B18` | `0x52012B18` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT867H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B1C` | `0x52012B1C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT868L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B20` | `0x52012B20` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT868H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B24` | `0x52012B24` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT869L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B28` | `0x52012B28` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT869H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B2C` | `0x52012B2C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT870L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B30` | `0x52012B30` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT870H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B34` | `0x52012B34` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT871L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B38` | `0x52012B38` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT871H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B3C` | `0x52012B3C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT872L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B40` | `0x52012B40` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT872H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B44` | `0x52012B44` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT873L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B48` | `0x52012B48` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT873H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B4C` | `0x52012B4C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT874L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B50` | `0x52012B50` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT874H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B54` | `0x52012B54` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT875L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B58` | `0x52012B58` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT875H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B5C` | `0x52012B5C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT876L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B60` | `0x52012B60` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT876H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B64` | `0x52012B64` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT877L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B68` | `0x52012B68` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT877H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B6C` | `0x52012B6C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT878L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B70` | `0x52012B70` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT878H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B74` | `0x52012B74` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT879L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B78` | `0x52012B78` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT879H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B7C` | `0x52012B7C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT880L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B80` | `0x52012B80` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT880H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B84` | `0x52012B84` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT881L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B88` | `0x52012B88` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT881H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B8C` | `0x52012B8C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT882L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B90` | `0x52012B90` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT882H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B94` | `0x52012B94` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT883L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2B98` | `0x52012B98` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT883H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2B9C` | `0x52012B9C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT884L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2BA0` | `0x52012BA0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT884H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2BA4` | `0x52012BA4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT885L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2BA8` | `0x52012BA8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT885H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2BAC` | `0x52012BAC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT886L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2BB0` | `0x52012BB0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT886H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2BB4` | `0x52012BB4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT887L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2BB8` | `0x52012BB8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT887H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2BBC` | `0x52012BBC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT888L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2BC0` | `0x52012BC0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT888H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2BC4` | `0x52012BC4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT889L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2BC8` | `0x52012BC8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT889H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2BCC` | `0x52012BCC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT890L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2BD0` | `0x52012BD0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT890H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2BD4` | `0x52012BD4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT891L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2BD8` | `0x52012BD8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT891H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2BDC` | `0x52012BDC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT892L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2BE0` | `0x52012BE0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT892H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2BE4` | `0x52012BE4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT893L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2BE8` | `0x52012BE8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT893H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2BEC` | `0x52012BEC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT894L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2BF0` | `0x52012BF0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT894H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2BF4` | `0x52012BF4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT895L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2BF8` | `0x52012BF8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT895H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2BFC` | `0x52012BFC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT896L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C00` | `0x52012C00` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT896H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C04` | `0x52012C04` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT897L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C08` | `0x52012C08` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT897H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C0C` | `0x52012C0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT898L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C10` | `0x52012C10` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT898H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C14` | `0x52012C14` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT899L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C18` | `0x52012C18` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT899H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C1C` | `0x52012C1C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT900L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C20` | `0x52012C20` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT900H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C24` | `0x52012C24` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT901L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C28` | `0x52012C28` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT901H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C2C` | `0x52012C2C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT902L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C30` | `0x52012C30` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT902H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C34` | `0x52012C34` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT903L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C38` | `0x52012C38` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT903H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C3C` | `0x52012C3C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT904L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C40` | `0x52012C40` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT904H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C44` | `0x52012C44` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT905L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C48` | `0x52012C48` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT905H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C4C` | `0x52012C4C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT906L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C50` | `0x52012C50` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT906H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C54` | `0x52012C54` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT907L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C58` | `0x52012C58` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT907H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C5C` | `0x52012C5C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT908L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C60` | `0x52012C60` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT908H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C64` | `0x52012C64` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT909L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C68` | `0x52012C68` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT909H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C6C` | `0x52012C6C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT910L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C70` | `0x52012C70` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT910H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C74` | `0x52012C74` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT911L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C78` | `0x52012C78` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT911H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C7C` | `0x52012C7C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT912L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C80` | `0x52012C80` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT912H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C84` | `0x52012C84` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT913L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C88` | `0x52012C88` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT913H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C8C` | `0x52012C8C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT914L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C90` | `0x52012C90` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT914H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C94` | `0x52012C94` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT915L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2C98` | `0x52012C98` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT915H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2C9C` | `0x52012C9C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT916L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2CA0` | `0x52012CA0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT916H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2CA4` | `0x52012CA4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT917L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2CA8` | `0x52012CA8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT917H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2CAC` | `0x52012CAC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT918L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2CB0` | `0x52012CB0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT918H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2CB4` | `0x52012CB4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT919L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2CB8` | `0x52012CB8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT919H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2CBC` | `0x52012CBC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT920L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2CC0` | `0x52012CC0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT920H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2CC4` | `0x52012CC4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT921L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2CC8` | `0x52012CC8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT921H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2CCC` | `0x52012CCC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT922L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2CD0` | `0x52012CD0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT922H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2CD4` | `0x52012CD4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT923L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2CD8` | `0x52012CD8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT923H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2CDC` | `0x52012CDC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT924L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2CE0` | `0x52012CE0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT924H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2CE4` | `0x52012CE4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT925L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2CE8` | `0x52012CE8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT925H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2CEC` | `0x52012CEC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT926L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2CF0` | `0x52012CF0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT926H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2CF4` | `0x52012CF4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT927L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2CF8` | `0x52012CF8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT927H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2CFC` | `0x52012CFC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT928L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D00` | `0x52012D00` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT928H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D04` | `0x52012D04` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT929L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D08` | `0x52012D08` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT929H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D0C` | `0x52012D0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT930L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D10` | `0x52012D10` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT930H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D14` | `0x52012D14` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT931L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D18` | `0x52012D18` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT931H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D1C` | `0x52012D1C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT932L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D20` | `0x52012D20` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT932H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D24` | `0x52012D24` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT933L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D28` | `0x52012D28` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT933H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D2C` | `0x52012D2C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT934L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D30` | `0x52012D30` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT934H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D34` | `0x52012D34` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT935L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D38` | `0x52012D38` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT935H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D3C` | `0x52012D3C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT936L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D40` | `0x52012D40` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT936H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D44` | `0x52012D44` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT937L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D48` | `0x52012D48` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT937H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D4C` | `0x52012D4C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT938L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D50` | `0x52012D50` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT938H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D54` | `0x52012D54` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT939L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D58` | `0x52012D58` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT939H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D5C` | `0x52012D5C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT940L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D60` | `0x52012D60` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT940H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D64` | `0x52012D64` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT941L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D68` | `0x52012D68` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT941H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D6C` | `0x52012D6C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT942L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D70` | `0x52012D70` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT942H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D74` | `0x52012D74` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT943L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D78` | `0x52012D78` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT943H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D7C` | `0x52012D7C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT944L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D80` | `0x52012D80` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT944H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D84` | `0x52012D84` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT945L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D88` | `0x52012D88` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT945H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D8C` | `0x52012D8C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT946L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D90` | `0x52012D90` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT946H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D94` | `0x52012D94` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT947L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2D98` | `0x52012D98` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT947H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2D9C` | `0x52012D9C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT948L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2DA0` | `0x52012DA0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT948H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2DA4` | `0x52012DA4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT949L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2DA8` | `0x52012DA8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT949H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2DAC` | `0x52012DAC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT950L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2DB0` | `0x52012DB0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT950H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2DB4` | `0x52012DB4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT951L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2DB8` | `0x52012DB8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT951H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2DBC` | `0x52012DBC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT952L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2DC0` | `0x52012DC0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT952H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2DC4` | `0x52012DC4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT953L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2DC8` | `0x52012DC8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT953H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2DCC` | `0x52012DCC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT954L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2DD0` | `0x52012DD0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT954H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2DD4` | `0x52012DD4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT955L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2DD8` | `0x52012DD8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT955H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2DDC` | `0x52012DDC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT956L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2DE0` | `0x52012DE0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT956H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2DE4` | `0x52012DE4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT957L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2DE8` | `0x52012DE8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT957H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2DEC` | `0x52012DEC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT958L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2DF0` | `0x52012DF0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT958H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2DF4` | `0x52012DF4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT959L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2DF8` | `0x52012DF8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT959H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2DFC` | `0x52012DFC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT960L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E00` | `0x52012E00` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT960H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E04` | `0x52012E04` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT961L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E08` | `0x52012E08` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT961H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E0C` | `0x52012E0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT962L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E10` | `0x52012E10` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT962H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E14` | `0x52012E14` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT963L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E18` | `0x52012E18` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT963H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E1C` | `0x52012E1C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT964L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E20` | `0x52012E20` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT964H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E24` | `0x52012E24` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT965L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E28` | `0x52012E28` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT965H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E2C` | `0x52012E2C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT966L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E30` | `0x52012E30` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT966H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E34` | `0x52012E34` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT967L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E38` | `0x52012E38` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT967H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E3C` | `0x52012E3C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT968L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E40` | `0x52012E40` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT968H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E44` | `0x52012E44` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT969L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E48` | `0x52012E48` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT969H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E4C` | `0x52012E4C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT970L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E50` | `0x52012E50` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT970H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E54` | `0x52012E54` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT971L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E58` | `0x52012E58` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT971H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E5C` | `0x52012E5C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT972L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E60` | `0x52012E60` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT972H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E64` | `0x52012E64` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT973L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E68` | `0x52012E68` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT973H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E6C` | `0x52012E6C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT974L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E70` | `0x52012E70` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT974H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E74` | `0x52012E74` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT975L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E78` | `0x52012E78` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT975H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E7C` | `0x52012E7C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT976L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E80` | `0x52012E80` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT976H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E84` | `0x52012E84` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT977L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E88` | `0x52012E88` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT977H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E8C` | `0x52012E8C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT978L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E90` | `0x52012E90` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT978H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E94` | `0x52012E94` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT979L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2E98` | `0x52012E98` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT979H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2E9C` | `0x52012E9C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT980L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2EA0` | `0x52012EA0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT980H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2EA4` | `0x52012EA4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT981L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2EA8` | `0x52012EA8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT981H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2EAC` | `0x52012EAC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT982L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2EB0` | `0x52012EB0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT982H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2EB4` | `0x52012EB4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT983L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2EB8` | `0x52012EB8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT983H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2EBC` | `0x52012EBC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT984L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2EC0` | `0x52012EC0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT984H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2EC4` | `0x52012EC4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT985L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2EC8` | `0x52012EC8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT985H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2ECC` | `0x52012ECC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT986L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2ED0` | `0x52012ED0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT986H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2ED4` | `0x52012ED4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT987L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2ED8` | `0x52012ED8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT987H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2EDC` | `0x52012EDC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT988L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2EE0` | `0x52012EE0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT988H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2EE4` | `0x52012EE4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT989L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2EE8` | `0x52012EE8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT989H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2EEC` | `0x52012EEC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT990L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2EF0` | `0x52012EF0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT990H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2EF4` | `0x52012EF4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT991L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2EF8` | `0x52012EF8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT991H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2EFC` | `0x52012EFC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT992L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F00` | `0x52012F00` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT992H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F04` | `0x52012F04` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT993L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F08` | `0x52012F08` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT993H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F0C` | `0x52012F0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT994L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F10` | `0x52012F10` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT994H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F14` | `0x52012F14` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT995L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F18` | `0x52012F18` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT995H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F1C` | `0x52012F1C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT996L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F20` | `0x52012F20` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT996H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F24` | `0x52012F24` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT997L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F28` | `0x52012F28` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT997H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F2C` | `0x52012F2C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT998L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F30` | `0x52012F30` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT998H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F34` | `0x52012F34` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT999L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F38` | `0x52012F38` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT999H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F3C` | `0x52012F3C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1000L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F40` | `0x52012F40` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1000H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F44` | `0x52012F44` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1001L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F48` | `0x52012F48` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1001H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F4C` | `0x52012F4C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1002L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F50` | `0x52012F50` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1002H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F54` | `0x52012F54` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1003L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F58` | `0x52012F58` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1003H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F5C` | `0x52012F5C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1004L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F60` | `0x52012F60` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1004H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F64` | `0x52012F64` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1005L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F68` | `0x52012F68` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1005H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F6C` | `0x52012F6C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1006L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F70` | `0x52012F70` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1006H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F74` | `0x52012F74` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1007L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F78` | `0x52012F78` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1007H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F7C` | `0x52012F7C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1008L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F80` | `0x52012F80` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1008H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F84` | `0x52012F84` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1009L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F88` | `0x52012F88` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1009H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F8C` | `0x52012F8C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1010L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F90` | `0x52012F90` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1010H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F94` | `0x52012F94` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1011L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2F98` | `0x52012F98` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1011H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2F9C` | `0x52012F9C` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1012L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2FA0` | `0x52012FA0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1012H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2FA4` | `0x52012FA4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1013L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2FA8` | `0x52012FA8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1013H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2FAC` | `0x52012FAC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1014L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2FB0` | `0x52012FB0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1014H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2FB4` | `0x52012FB4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1015L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2FB8` | `0x52012FB8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1015H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2FBC` | `0x52012FBC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1016L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2FC0` | `0x52012FC0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1016H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2FC4` | `0x52012FC4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1017L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2FC8` | `0x52012FC8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1017H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2FCC` | `0x52012FCC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1018L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2FD0` | `0x52012FD0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1018H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2FD4` | `0x52012FD4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1019L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2FD8` | `0x52012FD8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1019H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2FDC` | `0x52012FDC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1020L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2FE0` | `0x52012FE0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1020H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2FE4` | `0x52012FE4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1021L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2FE8` | `0x52012FE8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1021H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2FEC` | `0x52012FEC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1022L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2FF0` | `0x52012FF0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1022H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2FF4` | `0x52012FF4` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |
| `GFXMMU_LUT1023L` | 虚拟行映射表条目的低字，配置行使能和有效块范围 | `0x2FF8` | `0x52012FF8` | 32 | — | 0x00000000 / 0xFFFFFFFF | LVB[23:16] (RW)（该行末尾有效块编号）、FVB[15:8] (RW)（该行首个有效块编号）、EN[0] (RW)（启用该虚拟行的映射） | — |
| `GFXMMU_LUT1023H` | 虚拟行映射表条目的高字，配置该行的块地址偏移 | `0x2FFC` | `0x52012FFC` | 32 | — | 0x00000000 / 0xFFFFFFFF | LO[17:0] (RW)（行偏移） | — |

## GFXTIM

**模块用途**　图形定时器，用于生成和协调图形子系统的定时事件。

基地址 `0x50004000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `GFXTIM_CR` | GFXTIM 配置寄存器 | `0x000` | `0x50004000` | 32 | — | 0x00000000 / 0xFFFFFFFF | LCCOE[17] (RW)（行-时钟校准输出使能）、FCCOE[16] (RW)（帧-时钟校准输出使能）、SYNCS[9:8] (RW)（同步源）、TEPOL[4] (RW)（待核）、TES[1:0] (RW)（待核） | — |
| `GFXTIM_CGCR` | GFXTIM 时钟发生器配置寄存器 | `0x004` | `0x50004004` | 32 | — | 0x00000000 / 0xFFFFFFFF | FCCHRS[30:28] (RW)（帧- -时钟计数器硬件重装源）、FCCFR[24] (WO)（待核）、FCCCS[22:20] (RW)（帧时钟计数器时钟源）、FCS[18:16] (RW)（帧时钟源）、LCCHRS[14:12] (RW)（行时钟计数器硬件重装源）、LCCFR[8] (WO)（待核）、LCCCS[4] (RW)（行时钟计数器时钟源）、LCS[2:0] (RW)（行时钟源） | — |
| `GFXTIM_TCR` | GFXTIM 定时器配置寄存器 | `0x008` | `0x50004008` | 32 | — | 0x00000000 / 0xFFFFFFFF | FRFC2R[22] (WO)（待核）、RFC2CM[21] (RW)（相对帧计数器 2 连续模式）、RFC2EN[20] (WO)（相对帧计数器 2 使能）、FRFC1R[18] (WO)（待核）、RFC1CM[17] (RW)（相对帧计数器 1 连续模式）、RFC1EN[16] (WO)（相对帧计数器 1 使能）、FALCR[5] (WO)（待核）、ALCEN[4] (WO)（绝对行计数器使能）、FAFCR[1] (WO)（待核）、AFCEN[0] (WO)（绝对帧计数器使能） | — |
| `GFXTIM_TDR` | GFXTIM 定时器禁用寄存器 | `0x00C` | `0x5000400C` | 32 | — | 0x00000000 / 0xFFFFFFFF | RFC2DIS[20] (WO)（相对帧计数器 2 禁用）、RFC1DIS[16] (WO)（相对帧计数器 1 禁用）、ALCDIS[4] (WO)（绝对行计数器禁用）、AFCDIS[0] (WO)（绝对帧计数器禁用） | — |
| `GFXTIM_EVCR` | GFXTIM 事件控制寄存器 | `0x010` | `0x50004010` | 32 | — | 0x00000000 / 0xFFFFFFFF | EV4EN[3] (RW)（事件 4 使能）、EV3EN[2] (RW)（事件 3 使能）、EV2EN[1] (RW)（事件 2 使能）、EV1EN[0] (RW)（事件 1 使能） | — |
| `GFXTIM_EVSR` | GFXTIM 事件选择寄存器 | `0x014` | `0x50004014` | 32 | — | 0x00000000 / 0xFFFFFFFF | FES4[30:28] (RW)（帧-事件选择 4）、LES4[26:24] (RW)（行-事件选择 4）、FES3[22:20] (RW)（帧-事件选择 3）、LES3[18:16] (RW)（行-事件选择 3）、FES2[14:12] (RW)（帧-事件选择 2）、LES2[10:8] (RW)（行-事件选择 2）、FES1[6:4] (RW)（帧-事件选择 1）、LES1[2:0] (RW)（行-事件选择 1） | — |
| `GFXTIM_WDGTCR` | GFXTIM 看门狗定时器配置寄存器 | `0x020` | `0x50004020` | 32 | — | 0x00000000 / 0xFFFFFFFF | FWDGR[16] (WO)（待核）、WDGCS[11:8] (RW)（看门狗时钟源）、WDGHRC[5:4] (RW)（看门狗硬件重装配置）、WDGS[2] (RO)（看门狗状态）、WDGDIS[1] (WO)（看门狗禁用）、WDGEN[0] (WO)（看门狗使能） | — |
| `GFXTIM_ISR` | GFXTIM 中断状态寄存器 | `0x030` | `0x50004030` | 32 | — | 0x00000000 / 0xFFFFFFFF | WDGPF[25] (RO)（看门狗预警标志）、WDGAF[24] (RO)（看门狗闹钟标志）、EV4F[19] (RO)（事件 4 标志）、EV3F[18] (RO)（事件 3 标志）、EV2F[17] (RO)（事件 2 标志）、EV1F[16] (RO)（事件 1 标志）、RFC2RF[13] (RO)（相对帧计数器 2 重装标志）、RFC1RF[12] (RO)（相对帧计数器 1 重装标志）、ALCC2F[9] (RO)（绝对行计数器比较 2 标志）、ALCC1F[8] (RO)（绝对行计数器比较 1 标志）、AFCC1F[4] (RO)（绝对帧计数器比较 1 标志）、TEF[2] (RO)（待核）、ALCOF[1] (RO)（绝对行计数器溢出标志）、AFCOF[0] (RO)（绝对帧计数器溢出标志） | — |
| `GFXTIM_ICR` | GFXTIM 中断清除寄存器 | `0x034` | `0x50004034` | 32 | — | 0x00000000 / 0xFFFFFFFF | CWDGPF[25] (WO)（清除看门狗预警标志）、CWDGAF[24] (WO)（清除看门狗闹钟标志）、CEV4F[19] (WO)（清除事件 4 标志）、CEV3F[18] (WO)（清除事件 3 标志）、CEV2F[17] (WO)（清除事件 2 标志）、CEV1F[16] (WO)（清除事件 1 标志）、CRFC2RF[13] (WO)（清除相对帧计数器 2 重装标志）、CRFC1RF[12] (WO)（清除相对帧计数器 1 重装标志）、CALCC2F[9] (WO)（清除绝对行计数器比较 2 标志）、CALCC1F[8] (WO)（清除绝对行计数器比较 1 标志）、CAFCC1F[4] (WO)（清除绝对帧计数器比较 1 标志）、CTEF[2] (WO)（待核）、CALCOF[1] (WO)（清除绝对行计数器溢出标志）、CAFCOF[0] (WO)（清除绝对帧计数器溢出标志） | — |
| `GFXTIM_IER` | GFXTIM 中断使能寄存器 | `0x038` | `0x50004038` | 32 | — | 0x00000000 / 0xFFFFFFFF | WDGPIE[25] (RW)（看门狗预警中断使能）、WDGAIE[24] (RW)（看门狗闹钟中断使能）、EV4IE[19] (RW)（事件 4 中断使能）、EV3IE[18] (RW)（事件 3 中断使能）、EV2IE[17] (RW)（事件 2 中断使能）、EV1IE[16] (RW)（事件 1 中断使能）、RFC2RIE[13] (RW)（相对帧计数器 2 重装中断使能）、RFC1RIE[12] (RW)（相对帧计数器 1 重装中断使能）、ALCC2IE[9] (RW)（绝对行计数器比较 2 中断使能）、ALCC1IE[8] (RW)（绝对行计数器比较 1 中断使能）、AFCC1IE[4] (RW)（绝对帧计数器比较 1 中断使能）、TEIE[2] (RW)（待核）、ALCOIE[1] (RW)（绝对行计数器溢出中断使能）、AFCOIE[0] (RW)（绝对帧计数器溢出中断使能） | — |
| `GFXTIM_TSR` | GFXTIM 定时器状态寄存器 | `0x03C` | `0x5000403C` | 32 | — | 0x00000000 / 0xFFFFFFFF | RFC2S[20] (RO)（相对帧计数器 2 状态）、RFC1S[16] (RO)（相对帧计数器 1 状态）、ALCS[4] (RO)（绝对行计数器状态）、AFCS[0] (RO)（绝对帧计数器状态） | — |
| `GFXTIM_LCCRR` | GFXTIM 行时钟计数器重装寄存器 | `0x040` | `0x50004040` | 32 | — | 0x00000000 / 0xFFFFFFFF | RELOAD[21:0] (RW)（重装值） | — |
| `GFXTIM_FCCRR` | GFXTIM 帧时钟计数器重装寄存器 | `0x044` | `0x50004044` | 32 | — | 0x00000000 / 0xFFFFFFFF | RELOAD[11:0] (RW)（重装值） | — |
| `GFXTIM_ATR` | GFXTIM 绝对时间寄存器 | `0x050` | `0x50004050` | 32 | — | 0x00000000 / 0xFFFFFFFF | FRAME[31:12] (RO)（待核）、LINE[11:0] (RO)（行编号） | — |
| `GFXTIM_AFCR` | GFXTIM 绝对帧计数器寄存器 | `0x054` | `0x50004054` | 32 | — | 0x00000000 / 0xFFFFFFFF | FRAME[19:0] (RW)（帧编号） | — |
| `GFXTIM_ALCR` | GFXTIM 绝对行计数器寄存器 | `0x058` | `0x50004058` | 32 | — | 0x00000000 / 0xFFFFFFFF | LINE[11:0] (RW)（行编号） | — |
| `GFXTIM_AFCC1R` | GFXTIM 绝对帧计数器比较 1 寄存器 | `0x060` | `0x50004060` | 32 | — | 0x00000000 / 0xFFFFFFFF | FRAME[19:0] (RW)（帧编号） | — |
| `GFXTIM_ALCC1R` | GFXTIM 绝对行计数器比较 1 寄存器 | `0x070` | `0x50004070` | 32 | — | 0x00000000 / 0xFFFFFFFF | LINE[11:0] (RW)（行编号） | — |
| `GFXTIM_ALCC2R` | GFXTIM 绝对行计数器比较 2 寄存器 | `0x074` | `0x50004074` | 32 | — | 0x00000000 / 0xFFFFFFFF | LINE[11:0] (RW)（行编号） | — |
| `GFXTIM_RFC1R` | GFXTIM 相对帧计数器 1 寄存器 | `0x080` | `0x50004080` | 32 | — | 0x00000000 / 0xFFFFFFFF | FRAME[11:0] (RO)（帧编号） | — |
| `GFXTIM_RFC1RR` | GFXTIM 相对帧计数器 1 重装寄存器 | `0x084` | `0x50004084` | 32 | — | 0x00000000 / 0xFFFFFFFF | FRAME[11:0] (RW)（帧重装值） | — |
| `GFXTIM_RFC2R` | GFXTIM 相对帧计数器 2 寄存器 | `0x088` | `0x50004088` | 32 | — | 0x00000000 / 0xFFFFFFFF | FRAME[11:0] (RO)（帧编号） | — |
| `GFXTIM_RFC2RR` | GFXTIM 相对帧计数器 2 重装寄存器 | `0x08C` | `0x5000408C` | 32 | — | 0x00000000 / 0xFFFFFFFF | FRAME[11:0] (RW)（帧重装值） | — |
| `GFXTIM_WDGCR` | GFXTIM 看门狗计数器寄存器 | `0x0A0` | `0x500040A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | VALUE[15:0] (RO)（值） | — |
| `GFXTIM_WDGRR` | GFXTIM 看门狗重装寄存器 | `0x0A4` | `0x500040A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | RELOAD[15:0] (RW)（重装值） | — |
| `GFXTIM_WDGPAR` | GFXTIM 看门狗预警寄存器 | `0x0A8` | `0x500040A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | PREALARM[15:0] (RW)（预警值） | — |

## GFXTIM_CMSIS

**模块用途**　图形定时器的芯片头文件补充视图，和 GFXTIM 主表对照使用。

基地址 `0x50004000` · CMSIS 补表

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `HWCFGR` | 硬件配置标识寄存器 | `0x3F0` | `0x500043F0` | 32 | — | — / — | — | — |
| `VERR` | 版本标识寄存器 | `0x3F4` | `0x500043F4` | 32 | — | — / — | MAJREV[7:4]（待核）、MINREV[3:0]（待核） | — |
| `IPIDR` | 外设标识寄存器 | `0x3F8` | `0x500043F8` | 32 | — | — / — | ID[31:0]（待核） | — |
| `SIDR` | 大小标识寄存器 | `0x3FC` | `0x500043FC` | 32 | — | — / — | SID[31:0]（待核） | — |

## JPEG

**模块用途**　JPEG 编解码器，使用配置、状态和 FIFO 寄存器控制数据流，查找表保存量化和 Huffman 编码相关数据。

基地址 `0x52003000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `JPEG_CONFR0` | JPEG 编解码器控制寄存器 | `0x000` | `0x52003000` | 32 | — | 0x00000000 / 0xFFFFFFFF | START[0] (WO)（启动） | — |
| `JPEG_CONFR1` | JPEG 编解码器配置寄存器 1 | `0x004` | `0x52003004` | 32 | — | 0x00000000 / 0xFFFFFFFF | YSIZE[31:16] (RW)（Y 大小）、HDR[8] (RW)（待核）、NS[7:6] (RW)（待核）、COLSPACE[5:4] (RW)（颜色空间）、DE[3] (RW)（待核）、NF[1:0] (RW)（待核） | — |
| `JPEG_CONFR2` | JPEG 编解码器配置寄存器 2 | `0x008` | `0x52003008` | 32 | — | 0x00000000 / 0xFFFFFFFF | NMCU[25:0] (RW)（待核） | — |
| `JPEG_CONFR3` | JPEG 编解码器配置寄存器 3 | `0x00C` | `0x5200300C` | 32 | — | 0x00000000 / 0xFFFFFFFF | XSIZE[31:16] (RW)（X 大小） | — |
| `JPEG_CONFR4` | JPEG 编解码器配置寄存器 4 | `0x010` | `0x52003010` | 32 | — | 0x00000000 / 0xFFFFFFFF | HSF[15:12] (RW)（水平采样系数）、VSF[11:8] (RW)（垂直采样系数）、NB[7:4] (RW)（数量块）、QT[3:2] (RW)（量化表）、HA[1] (RW)（待核）、HD[0] (RW)（待核） | — |
| `JPEG_CONFR5` | JPEG 编解码器配置寄存器 5 | `0x014` | `0x52003014` | 32 | — | 0x00000000 / 0xFFFFFFFF | HSF[15:12] (RW)（水平采样系数）、VSF[11:8] (RW)（垂直采样系数）、NB[7:4] (RW)（数量块）、QT[3:2] (RW)（量化表）、HA[1] (RW)（待核）、HD[0] (RW)（待核） | — |
| `JPEG_CONFR6` | JPEG 编解码器配置寄存器 6 | `0x018` | `0x52003018` | 32 | — | 0x00000000 / 0xFFFFFFFF | HSF[15:12] (RW)（水平采样系数）、VSF[11:8] (RW)（垂直采样系数）、NB[7:4] (RW)（数量块）、QT[3:2] (RW)（量化表）、HA[1] (RW)（待核）、HD[0] (RW)（待核） | — |
| `JPEG_CONFR7` | JPEG 编解码器配置寄存器 7 | `0x01C` | `0x5200301C` | 32 | — | 0x00000000 / 0xFFFFFFFF | HSF[15:12] (RW)（水平采样系数）、VSF[11:8] (RW)（垂直采样系数）、NB[7:4] (RW)（数量块）、QT[3:2] (RW)（量化表）、HA[1] (RW)（待核）、HD[0] (RW)（待核） | — |
| `JPEG_CR` | JPEG 控制寄存器 | `0x030` | `0x52003030` | 32 | — | 0x00000000 / 0xFFFFFFFF | OFF[14] (WO)（输出 FIFO 清空）、IFF[13] (WO)（输入 FIFO 清空）、ODMAEN[12] (RW)（输出 DMA 使能）、IDMAEN[11] (RW)（输入 DMA 使能）、HPDIE[6] (RW)（待核）、EOCIE[5] (RW)（结束的转换中断使能）、OFNEIE[4] (RW)（待核）、OFTIE[3] (RW)（输出 FIFO 阈值中断使能）、IFNFIE[2] (RW)（待核）、IFTIE[1] (RW)（输入 FIFO 阈值中断使能）、JCEN[0] (RW)（JPEG 核心使能） | — |
| `JPEG_SR` | JPEG 状态寄存器 | `0x034` | `0x52003034` | 32 | — | 0x00000006 / 0xFFFFFFFF | COF[7] (RO)（编解码器操作标志）、HPDF[6] (RO)（待核）、EOCF[5] (RO)（结束的转换标志）、OFNEF[4] (RO)（待核）、OFTF[3] (RO)（输出 FIFO 阈值标志）、IFNFF[2] (RO)（待核）、IFTF[1] (RO)（输入 FIFO 阈值标志） | — |
| `JPEG_CFR` | JPEG 清除标志寄存器 | `0x038` | `0x52003038` | 32 | — | 0x00000000 / 0xFFFFFFFF | CHPDF[6] (RW)（待核）、CEOCF[5] (RW)（清除结束的转换标志） | — |
| `JPEG_DIR` | JPEG 数据输入寄存器 | `0x040` | `0x52003040` | 32 | — | 0x00000000 / 0xFFFFFFFF | DATAIN[31:0] (WO)（数据输入 FIFO） | — |
| `JPEG_DOR` | JPEG 数据输出寄存器 | `0x044` | `0x52003044` | 32 | — | 0x00000000 / 0xFFFFFFFF | DATAOUT[31:0] (RO)（数据输出 FIFO） | — |
| `JPEG_QMEM0_0` | JPEG 量化存储器 0 | `0x050` | `0x52003050` | 32 | — | 0x00000000 / 0x00000000 | QCOEF3[31:24] (RW)（量化系数 3）、QCOEF2[23:16] (RW)（量化系数 2）、QCOEF1[15:8] (RW)（量化系数 1）、QCOEF0[7:0] (RW)（量化系数 0） | — |
| `JPEG_QMEM0_1` | JPEG 量化存储器 0 | `0x054` | `0x52003054` | 32 | — | 0x00000000 / 0x00000000 | QCOEF7[31:24] (RW)（量化系数 7）、QCOEF6[23:16] (RW)（量化系数 6）、QCOEF5[15:8] (RW)（量化系数 5）、QCOEF4[7:0] (RW)（量化系数 4） | — |
| `JPEG_QMEM0_2` | JPEG 量化存储器 0 | `0x058` | `0x52003058` | 32 | — | 0x00000000 / 0x00000000 | QCOEF11[31:24] (RW)（量化系数 11）、QCOEF10[23:16] (RW)（量化系数 10）、QCOEF9[15:8] (RW)（量化系数 9）、QCOEF8[7:0] (RW)（量化系数 8） | — |
| `JPEG_QMEM0_3` | JPEG 量化存储器 0 | `0x05C` | `0x5200305C` | 32 | — | 0x00000000 / 0x00000000 | QCOEF15[31:24] (RW)（量化系数 15）、QCOEF14[23:16] (RW)（量化系数 14）、QCOEF13[15:8] (RW)（量化系数 13）、QCOEF12[7:0] (RW)（量化系数 12） | — |
| `JPEG_QMEM0_4` | JPEG 量化存储器 0 | `0x060` | `0x52003060` | 32 | — | 0x00000000 / 0x00000000 | QCOEF19[31:24] (RW)（量化系数 19）、QCOEF18[23:16] (RW)（量化系数 18）、QCOEF17[15:8] (RW)（量化系数 17）、QCOEF16[7:0] (RW)（量化系数 16） | — |
| `JPEG_QMEM0_5` | JPEG 量化存储器 0 | `0x064` | `0x52003064` | 32 | — | 0x00000000 / 0x00000000 | QCOEF23[31:24] (RW)（量化系数 23）、QCOEF22[23:16] (RW)（量化系数 22）、QCOEF21[15:8] (RW)（量化系数 21）、QCOEF20[7:0] (RW)（量化系数 20） | — |
| `JPEG_QMEM0_6` | JPEG 量化存储器 0 | `0x068` | `0x52003068` | 32 | — | 0x00000000 / 0x00000000 | QCOEF27[31:24] (RW)（量化系数 27）、QCOEF26[23:16] (RW)（量化系数 26）、QCOEF25[15:8] (RW)（量化系数 25）、QCOEF24[7:0] (RW)（量化系数 24） | — |
| `JPEG_QMEM0_7` | JPEG 量化存储器 0 | `0x06C` | `0x5200306C` | 32 | — | 0x00000000 / 0x00000000 | QCOEF31[31:24] (RW)（量化系数 31）、QCOEF30[23:16] (RW)（量化系数 30）、QCOEF29[15:8] (RW)（量化系数 29）、QCOEF28[7:0] (RW)（量化系数 28） | — |
| `JPEG_QMEM0_8` | JPEG 量化存储器 0 | `0x070` | `0x52003070` | 32 | — | 0x00000000 / 0x00000000 | QCOEF35[31:24] (RW)（量化系数 35）、QCOEF34[23:16] (RW)（量化系数 34）、QCOEF33[15:8] (RW)（量化系数 33）、QCOEF32[7:0] (RW)（量化系数 32） | — |
| `JPEG_QMEM0_9` | JPEG 量化存储器 0 | `0x074` | `0x52003074` | 32 | — | 0x00000000 / 0x00000000 | QCOEF39[31:24] (RW)（量化系数 39）、QCOEF38[23:16] (RW)（量化系数 38）、QCOEF37[15:8] (RW)（量化系数 37）、QCOEF36[7:0] (RW)（量化系数 36） | — |
| `JPEG_QMEM0_10` | JPEG 量化存储器 0 | `0x078` | `0x52003078` | 32 | — | 0x00000000 / 0x00000000 | QCOEF43[31:24] (RW)（量化系数 43）、QCOEF42[23:16] (RW)（量化系数 42）、QCOEF41[15:8] (RW)（量化系数 41）、QCOEF40[7:0] (RW)（量化系数 40） | — |
| `JPEG_QMEM0_11` | JPEG 量化存储器 0 | `0x07C` | `0x5200307C` | 32 | — | 0x00000000 / 0x00000000 | QCOEF47[31:24] (RW)（量化系数 47）、QCOEF46[23:16] (RW)（量化系数 46）、QCOEF45[15:8] (RW)（量化系数 45）、QCOEF44[7:0] (RW)（量化系数 44） | — |
| `JPEG_QMEM0_12` | JPEG 量化存储器 0 | `0x080` | `0x52003080` | 32 | — | 0x00000000 / 0x00000000 | QCOEF51[31:24] (RW)（量化系数 51）、QCOEF50[23:16] (RW)（量化系数 50）、QCOEF49[15:8] (RW)（量化系数 49）、QCOEF48[7:0] (RW)（量化系数 48） | — |
| `JPEG_QMEM0_13` | JPEG 量化存储器 0 | `0x084` | `0x52003084` | 32 | — | 0x00000000 / 0x00000000 | QCOEF55[31:24] (RW)（量化系数 55）、QCOEF54[23:16] (RW)（量化系数 54）、QCOEF53[15:8] (RW)（量化系数 53）、QCOEF52[7:0] (RW)（量化系数 52） | — |
| `JPEG_QMEM0_14` | JPEG 量化存储器 0 | `0x088` | `0x52003088` | 32 | — | 0x00000000 / 0x00000000 | QCOEF59[31:24] (RW)（量化系数 59）、QCOEF58[23:16] (RW)（量化系数 58）、QCOEF57[15:8] (RW)（量化系数 57）、QCOEF56[7:0] (RW)（量化系数 56） | — |
| `JPEG_QMEM0_15` | JPEG 量化存储器 0 | `0x08C` | `0x5200308C` | 32 | — | 0x00000000 / 0x00000000 | QCOEF63[31:24] (RW)（量化系数 63）、QCOEF62[23:16] (RW)（量化系数 62）、QCOEF61[15:8] (RW)（量化系数 61）、QCOEF60[7:0] (RW)（量化系数 60） | — |
| `JPEG_QMEM1_0` | JPEG 量化存储器 1 | `0x090` | `0x52003090` | 32 | — | 0x00000000 / 0x00000000 | QCOEF3[31:24] (RW)（量化系数 3）、QCOEF2[23:16] (RW)（量化系数 2）、QCOEF1[15:8] (RW)（量化系数 1）、QCOEF0[7:0] (RW)（量化系数 0） | — |
| `JPEG_QMEM1_1` | JPEG 量化存储器 1 | `0x094` | `0x52003094` | 32 | — | 0x00000000 / 0x00000000 | QCOEF7[31:24] (RW)（量化系数 7）、QCOEF6[23:16] (RW)（量化系数 6）、QCOEF5[15:8] (RW)（量化系数 5）、QCOEF4[7:0] (RW)（量化系数 4） | — |
| `JPEG_QMEM1_2` | JPEG 量化存储器 1 | `0x098` | `0x52003098` | 32 | — | 0x00000000 / 0x00000000 | QCOEF11[31:24] (RW)（量化系数 11）、QCOEF10[23:16] (RW)（量化系数 10）、QCOEF9[15:8] (RW)（量化系数 9）、QCOEF8[7:0] (RW)（量化系数 8） | — |
| `JPEG_QMEM1_3` | JPEG 量化存储器 1 | `0x09C` | `0x5200309C` | 32 | — | 0x00000000 / 0x00000000 | QCOEF15[31:24] (RW)（量化系数 15）、QCOEF14[23:16] (RW)（量化系数 14）、QCOEF13[15:8] (RW)（量化系数 13）、QCOEF12[7:0] (RW)（量化系数 12） | — |
| `JPEG_QMEM1_4` | JPEG 量化存储器 1 | `0x0A0` | `0x520030A0` | 32 | — | 0x00000000 / 0x00000000 | QCOEF19[31:24] (RW)（量化系数 19）、QCOEF18[23:16] (RW)（量化系数 18）、QCOEF17[15:8] (RW)（量化系数 17）、QCOEF16[7:0] (RW)（量化系数 16） | — |
| `JPEG_QMEM1_5` | JPEG 量化存储器 1 | `0x0A4` | `0x520030A4` | 32 | — | 0x00000000 / 0x00000000 | QCOEF23[31:24] (RW)（量化系数 23）、QCOEF22[23:16] (RW)（量化系数 22）、QCOEF21[15:8] (RW)（量化系数 21）、QCOEF20[7:0] (RW)（量化系数 20） | — |
| `JPEG_QMEM1_6` | JPEG 量化存储器 1 | `0x0A8` | `0x520030A8` | 32 | — | 0x00000000 / 0x00000000 | QCOEF27[31:24] (RW)（量化系数 27）、QCOEF26[23:16] (RW)（量化系数 26）、QCOEF25[15:8] (RW)（量化系数 25）、QCOEF24[7:0] (RW)（量化系数 24） | — |
| `JPEG_QMEM1_7` | JPEG 量化存储器 1 | `0x0AC` | `0x520030AC` | 32 | — | 0x00000000 / 0x00000000 | QCOEF31[31:24] (RW)（量化系数 31）、QCOEF30[23:16] (RW)（量化系数 30）、QCOEF29[15:8] (RW)（量化系数 29）、QCOEF28[7:0] (RW)（量化系数 28） | — |
| `JPEG_QMEM1_8` | JPEG 量化存储器 1 | `0x0B0` | `0x520030B0` | 32 | — | 0x00000000 / 0x00000000 | QCOEF35[31:24] (RW)（量化系数 35）、QCOEF34[23:16] (RW)（量化系数 34）、QCOEF33[15:8] (RW)（量化系数 33）、QCOEF32[7:0] (RW)（量化系数 32） | — |
| `JPEG_QMEM1_9` | JPEG 量化存储器 1 | `0x0B4` | `0x520030B4` | 32 | — | 0x00000000 / 0x00000000 | QCOEF39[31:24] (RW)（量化系数 39）、QCOEF38[23:16] (RW)（量化系数 38）、QCOEF37[15:8] (RW)（量化系数 37）、QCOEF36[7:0] (RW)（量化系数 36） | — |
| `JPEG_QMEM1_10` | JPEG 量化存储器 1 | `0x0B8` | `0x520030B8` | 32 | — | 0x00000000 / 0x00000000 | QCOEF43[31:24] (RW)（量化系数 43）、QCOEF42[23:16] (RW)（量化系数 42）、QCOEF41[15:8] (RW)（量化系数 41）、QCOEF40[7:0] (RW)（量化系数 40） | — |
| `JPEG_QMEM1_11` | JPEG 量化存储器 1 | `0x0BC` | `0x520030BC` | 32 | — | 0x00000000 / 0x00000000 | QCOEF47[31:24] (RW)（量化系数 47）、QCOEF46[23:16] (RW)（量化系数 46）、QCOEF45[15:8] (RW)（量化系数 45）、QCOEF44[7:0] (RW)（量化系数 44） | — |
| `JPEG_QMEM1_12` | JPEG 量化存储器 1 | `0x0C0` | `0x520030C0` | 32 | — | 0x00000000 / 0x00000000 | QCOEF51[31:24] (RW)（量化系数 51）、QCOEF50[23:16] (RW)（量化系数 50）、QCOEF49[15:8] (RW)（量化系数 49）、QCOEF48[7:0] (RW)（量化系数 48） | — |
| `JPEG_QMEM1_13` | JPEG 量化存储器 1 | `0x0C4` | `0x520030C4` | 32 | — | 0x00000000 / 0x00000000 | QCOEF55[31:24] (RW)（量化系数 55）、QCOEF54[23:16] (RW)（量化系数 54）、QCOEF53[15:8] (RW)（量化系数 53）、QCOEF52[7:0] (RW)（量化系数 52） | — |
| `JPEG_QMEM1_14` | JPEG 量化存储器 1 | `0x0C8` | `0x520030C8` | 32 | — | 0x00000000 / 0x00000000 | QCOEF59[31:24] (RW)（量化系数 59）、QCOEF58[23:16] (RW)（量化系数 58）、QCOEF57[15:8] (RW)（量化系数 57）、QCOEF56[7:0] (RW)（量化系数 56） | — |
| `JPEG_QMEM1_15` | JPEG 量化存储器 1 | `0x0CC` | `0x520030CC` | 32 | — | 0x00000000 / 0x00000000 | QCOEF63[31:24] (RW)（量化系数 63）、QCOEF62[23:16] (RW)（量化系数 62）、QCOEF61[15:8] (RW)（量化系数 61）、QCOEF60[7:0] (RW)（量化系数 60） | — |
| `JPEG_QMEM2_0` | JPEG 量化存储器 2 | `0x0D0` | `0x520030D0` | 32 | — | 0x00000000 / 0x00000000 | QCOEF3[31:24] (RW)（量化系数 3）、QCOEF2[23:16] (RW)（量化系数 2）、QCOEF1[15:8] (RW)（量化系数 1）、QCOEF0[7:0] (RW)（量化系数 0） | — |
| `JPEG_QMEM2_1` | JPEG 量化存储器 2 | `0x0D4` | `0x520030D4` | 32 | — | 0x00000000 / 0x00000000 | QCOEF7[31:24] (RW)（量化系数 7）、QCOEF6[23:16] (RW)（量化系数 6）、QCOEF5[15:8] (RW)（量化系数 5）、QCOEF4[7:0] (RW)（量化系数 4） | — |
| `JPEG_QMEM2_2` | JPEG 量化存储器 2 | `0x0D8` | `0x520030D8` | 32 | — | 0x00000000 / 0x00000000 | QCOEF11[31:24] (RW)（量化系数 11）、QCOEF10[23:16] (RW)（量化系数 10）、QCOEF9[15:8] (RW)（量化系数 9）、QCOEF8[7:0] (RW)（量化系数 8） | — |
| `JPEG_QMEM2_3` | JPEG 量化存储器 2 | `0x0DC` | `0x520030DC` | 32 | — | 0x00000000 / 0x00000000 | QCOEF15[31:24] (RW)（量化系数 15）、QCOEF14[23:16] (RW)（量化系数 14）、QCOEF13[15:8] (RW)（量化系数 13）、QCOEF12[7:0] (RW)（量化系数 12） | — |
| `JPEG_QMEM2_4` | JPEG 量化存储器 2 | `0x0E0` | `0x520030E0` | 32 | — | 0x00000000 / 0x00000000 | QCOEF19[31:24] (RW)（量化系数 19）、QCOEF18[23:16] (RW)（量化系数 18）、QCOEF17[15:8] (RW)（量化系数 17）、QCOEF16[7:0] (RW)（量化系数 16） | — |
| `JPEG_QMEM2_5` | JPEG 量化存储器 2 | `0x0E4` | `0x520030E4` | 32 | — | 0x00000000 / 0x00000000 | QCOEF23[31:24] (RW)（量化系数 23）、QCOEF22[23:16] (RW)（量化系数 22）、QCOEF21[15:8] (RW)（量化系数 21）、QCOEF20[7:0] (RW)（量化系数 20） | — |
| `JPEG_QMEM2_6` | JPEG 量化存储器 2 | `0x0E8` | `0x520030E8` | 32 | — | 0x00000000 / 0x00000000 | QCOEF27[31:24] (RW)（量化系数 27）、QCOEF26[23:16] (RW)（量化系数 26）、QCOEF25[15:8] (RW)（量化系数 25）、QCOEF24[7:0] (RW)（量化系数 24） | — |
| `JPEG_QMEM2_7` | JPEG 量化存储器 2 | `0x0EC` | `0x520030EC` | 32 | — | 0x00000000 / 0x00000000 | QCOEF31[31:24] (RW)（量化系数 31）、QCOEF30[23:16] (RW)（量化系数 30）、QCOEF29[15:8] (RW)（量化系数 29）、QCOEF28[7:0] (RW)（量化系数 28） | — |
| `JPEG_QMEM2_8` | JPEG 量化存储器 2 | `0x0F0` | `0x520030F0` | 32 | — | 0x00000000 / 0x00000000 | QCOEF35[31:24] (RW)（量化系数 35）、QCOEF34[23:16] (RW)（量化系数 34）、QCOEF33[15:8] (RW)（量化系数 33）、QCOEF32[7:0] (RW)（量化系数 32） | — |
| `JPEG_QMEM2_9` | JPEG 量化存储器 2 | `0x0F4` | `0x520030F4` | 32 | — | 0x00000000 / 0x00000000 | QCOEF39[31:24] (RW)（量化系数 39）、QCOEF38[23:16] (RW)（量化系数 38）、QCOEF37[15:8] (RW)（量化系数 37）、QCOEF36[7:0] (RW)（量化系数 36） | — |
| `JPEG_QMEM2_10` | JPEG 量化存储器 2 | `0x0F8` | `0x520030F8` | 32 | — | 0x00000000 / 0x00000000 | QCOEF43[31:24] (RW)（量化系数 43）、QCOEF42[23:16] (RW)（量化系数 42）、QCOEF41[15:8] (RW)（量化系数 41）、QCOEF40[7:0] (RW)（量化系数 40） | — |
| `JPEG_QMEM2_11` | JPEG 量化存储器 2 | `0x0FC` | `0x520030FC` | 32 | — | 0x00000000 / 0x00000000 | QCOEF47[31:24] (RW)（量化系数 47）、QCOEF46[23:16] (RW)（量化系数 46）、QCOEF45[15:8] (RW)（量化系数 45）、QCOEF44[7:0] (RW)（量化系数 44） | — |
| `JPEG_QMEM2_12` | JPEG 量化存储器 2 | `0x100` | `0x52003100` | 32 | — | 0x00000000 / 0x00000000 | QCOEF51[31:24] (RW)（量化系数 51）、QCOEF50[23:16] (RW)（量化系数 50）、QCOEF49[15:8] (RW)（量化系数 49）、QCOEF48[7:0] (RW)（量化系数 48） | — |
| `JPEG_QMEM2_13` | JPEG 量化存储器 2 | `0x104` | `0x52003104` | 32 | — | 0x00000000 / 0x00000000 | QCOEF55[31:24] (RW)（量化系数 55）、QCOEF54[23:16] (RW)（量化系数 54）、QCOEF53[15:8] (RW)（量化系数 53）、QCOEF52[7:0] (RW)（量化系数 52） | — |
| `JPEG_QMEM2_14` | JPEG 量化存储器 2 | `0x108` | `0x52003108` | 32 | — | 0x00000000 / 0x00000000 | QCOEF59[31:24] (RW)（量化系数 59）、QCOEF58[23:16] (RW)（量化系数 58）、QCOEF57[15:8] (RW)（量化系数 57）、QCOEF56[7:0] (RW)（量化系数 56） | — |
| `JPEG_QMEM2_15` | JPEG 量化存储器 2 | `0x10C` | `0x5200310C` | 32 | — | 0x00000000 / 0x00000000 | QCOEF63[31:24] (RW)（量化系数 63）、QCOEF62[23:16] (RW)（量化系数 62）、QCOEF61[15:8] (RW)（量化系数 61）、QCOEF60[7:0] (RW)（量化系数 60） | — |
| `JPEG_QMEM3_0` | JPEG 量化存储器 3 | `0x110` | `0x52003110` | 32 | — | 0x00000000 / 0x00000000 | QCOEF3[31:24] (RW)（量化系数 3）、QCOEF2[23:16] (RW)（量化系数 2）、QCOEF1[15:8] (RW)（量化系数 1）、QCOEF0[7:0] (RW)（量化系数 0） | — |
| `JPEG_QMEM3_1` | JPEG 量化存储器 3 | `0x114` | `0x52003114` | 32 | — | 0x00000000 / 0x00000000 | QCOEF7[31:24] (RW)（量化系数 7）、QCOEF6[23:16] (RW)（量化系数 6）、QCOEF5[15:8] (RW)（量化系数 5）、QCOEF4[7:0] (RW)（量化系数 4） | — |
| `JPEG_QMEM3_2` | JPEG 量化存储器 3 | `0x118` | `0x52003118` | 32 | — | 0x00000000 / 0x00000000 | QCOEF11[31:24] (RW)（量化系数 11）、QCOEF10[23:16] (RW)（量化系数 10）、QCOEF9[15:8] (RW)（量化系数 9）、QCOEF8[7:0] (RW)（量化系数 8） | — |
| `JPEG_QMEM3_3` | JPEG 量化存储器 3 | `0x11C` | `0x5200311C` | 32 | — | 0x00000000 / 0x00000000 | QCOEF15[31:24] (RW)（量化系数 15）、QCOEF14[23:16] (RW)（量化系数 14）、QCOEF13[15:8] (RW)（量化系数 13）、QCOEF12[7:0] (RW)（量化系数 12） | — |
| `JPEG_QMEM3_4` | JPEG 量化存储器 3 | `0x120` | `0x52003120` | 32 | — | 0x00000000 / 0x00000000 | QCOEF19[31:24] (RW)（量化系数 19）、QCOEF18[23:16] (RW)（量化系数 18）、QCOEF17[15:8] (RW)（量化系数 17）、QCOEF16[7:0] (RW)（量化系数 16） | — |
| `JPEG_QMEM3_5` | JPEG 量化存储器 3 | `0x124` | `0x52003124` | 32 | — | 0x00000000 / 0x00000000 | QCOEF23[31:24] (RW)（量化系数 23）、QCOEF22[23:16] (RW)（量化系数 22）、QCOEF21[15:8] (RW)（量化系数 21）、QCOEF20[7:0] (RW)（量化系数 20） | — |
| `JPEG_QMEM3_6` | JPEG 量化存储器 3 | `0x128` | `0x52003128` | 32 | — | 0x00000000 / 0x00000000 | QCOEF27[31:24] (RW)（量化系数 27）、QCOEF26[23:16] (RW)（量化系数 26）、QCOEF25[15:8] (RW)（量化系数 25）、QCOEF24[7:0] (RW)（量化系数 24） | — |
| `JPEG_QMEM3_7` | JPEG 量化存储器 3 | `0x12C` | `0x5200312C` | 32 | — | 0x00000000 / 0x00000000 | QCOEF31[31:24] (RW)（量化系数 31）、QCOEF30[23:16] (RW)（量化系数 30）、QCOEF29[15:8] (RW)（量化系数 29）、QCOEF28[7:0] (RW)（量化系数 28） | — |
| `JPEG_QMEM3_8` | JPEG 量化存储器 3 | `0x130` | `0x52003130` | 32 | — | 0x00000000 / 0x00000000 | QCOEF35[31:24] (RW)（量化系数 35）、QCOEF34[23:16] (RW)（量化系数 34）、QCOEF33[15:8] (RW)（量化系数 33）、QCOEF32[7:0] (RW)（量化系数 32） | — |
| `JPEG_QMEM3_9` | JPEG 量化存储器 3 | `0x134` | `0x52003134` | 32 | — | 0x00000000 / 0x00000000 | QCOEF39[31:24] (RW)（量化系数 39）、QCOEF38[23:16] (RW)（量化系数 38）、QCOEF37[15:8] (RW)（量化系数 37）、QCOEF36[7:0] (RW)（量化系数 36） | — |
| `JPEG_QMEM3_10` | JPEG 量化存储器 3 | `0x138` | `0x52003138` | 32 | — | 0x00000000 / 0x00000000 | QCOEF43[31:24] (RW)（量化系数 43）、QCOEF42[23:16] (RW)（量化系数 42）、QCOEF41[15:8] (RW)（量化系数 41）、QCOEF40[7:0] (RW)（量化系数 40） | — |
| `JPEG_QMEM3_11` | JPEG 量化存储器 3 | `0x13C` | `0x5200313C` | 32 | — | 0x00000000 / 0x00000000 | QCOEF47[31:24] (RW)（量化系数 47）、QCOEF46[23:16] (RW)（量化系数 46）、QCOEF45[15:8] (RW)（量化系数 45）、QCOEF44[7:0] (RW)（量化系数 44） | — |
| `JPEG_QMEM3_12` | JPEG 量化存储器 3 | `0x140` | `0x52003140` | 32 | — | 0x00000000 / 0x00000000 | QCOEF51[31:24] (RW)（量化系数 51）、QCOEF50[23:16] (RW)（量化系数 50）、QCOEF49[15:8] (RW)（量化系数 49）、QCOEF48[7:0] (RW)（量化系数 48） | — |
| `JPEG_QMEM3_13` | JPEG 量化存储器 3 | `0x144` | `0x52003144` | 32 | — | 0x00000000 / 0x00000000 | QCOEF55[31:24] (RW)（量化系数 55）、QCOEF54[23:16] (RW)（量化系数 54）、QCOEF53[15:8] (RW)（量化系数 53）、QCOEF52[7:0] (RW)（量化系数 52） | — |
| `JPEG_QMEM3_14` | JPEG 量化存储器 3 | `0x148` | `0x52003148` | 32 | — | 0x00000000 / 0x00000000 | QCOEF59[31:24] (RW)（量化系数 59）、QCOEF58[23:16] (RW)（量化系数 58）、QCOEF57[15:8] (RW)（量化系数 57）、QCOEF56[7:0] (RW)（量化系数 56） | — |
| `JPEG_QMEM3_15` | JPEG 量化存储器 3 | `0x14C` | `0x5200314C` | 32 | — | 0x00000000 / 0x00000000 | QCOEF63[31:24] (RW)（量化系数 63）、QCOEF62[23:16] (RW)（量化系数 62）、QCOEF61[15:8] (RW)（量化系数 61）、QCOEF60[7:0] (RW)（量化系数 60） | — |
| `JPEG_HUFFMIN0_0` | JPEG Huffman 最小值 | `0x150` | `0x52003150` | 32 | — | 0x00000000 / 0x00000000 | DATA0[31:0] (RW)（最小 Huffman 值） | — |
| `JPEG_HUFFMIN0_1` | JPEG Huffman 最小值 | `0x154` | `0x52003154` | 32 | — | 0x00000000 / 0x00000000 | DATA0[31:0] (RW)（最小 Huffman 值） | — |
| `JPEG_HUFFMIN0_2` | JPEG Huffman 最小值 | `0x158` | `0x52003158` | 32 | — | 0x00000000 / 0x00000000 | DATA0[31:0] (RW)（最小 Huffman 值） | — |
| `JPEG_HUFFMIN0_3` | JPEG Huffman 最小值 0 [备选] | `0x15C` | `0x5200315C` | 32 | — | 0x00000000 / 0x00000000 | DATA0[3:0] (RW)（最小 Huffman 值） | — |
| `JPEG_HUFFMIN1_0` | JPEG Huffman 最小值 | `0x160` | `0x52003160` | 32 | — | 0x00000000 / 0x00000000 | DATA1[31:0] (RW)（最小 Huffman 值） | — |
| `JPEG_HUFFMIN1_1` | JPEG Huffman 最小值 | `0x164` | `0x52003164` | 32 | — | 0x00000000 / 0x00000000 | DATA1[31:0] (RW)（最小 Huffman 值） | — |
| `JPEG_HUFFMIN1_2` | JPEG Huffman 最小值 | `0x168` | `0x52003168` | 32 | — | 0x00000000 / 0x00000000 | DATA1[31:0] (RW)（最小 Huffman 值） | — |
| `JPEG_HUFFMIN1_3` | JPEG Huffman 最小值 1 [备选] | `0x16C` | `0x5200316C` | 32 | — | 0x00000000 / 0x00000000 | DATA1[3:0] (RW)（最小 Huffman 值） | — |
| `JPEG_HUFFMIN2_0` | JPEG Huffman 最小值 | `0x170` | `0x52003170` | 32 | — | 0x00000000 / 0x00000000 | DATA2[31:0] (RW)（最小 Huffman 值） | — |
| `JPEG_HUFFMIN2_1` | JPEG Huffman 最小值 | `0x174` | `0x52003174` | 32 | — | 0x00000000 / 0x00000000 | DATA2[31:0] (RW)（最小 Huffman 值） | — |
| `JPEG_HUFFMIN2_2` | JPEG Huffman 最小值 | `0x178` | `0x52003178` | 32 | — | 0x00000000 / 0x00000000 | DATA2[31:0] (RW)（最小 Huffman 值） | — |
| `JPEG_HUFFMIN2_3` | JPEG Huffman 最小值 2 [备选] | `0x17C` | `0x5200317C` | 32 | — | 0x00000000 / 0x00000000 | DATA2[3:0] (RW)（最小 Huffman 值） | — |
| `JPEG_HUFFMIN3_0` | JPEG Huffman 最小值 | `0x180` | `0x52003180` | 32 | — | 0x00000000 / 0x00000000 | DATA3[31:0] (RW)（最小 Huffman 值） | — |
| `JPEG_HUFFMIN3_1` | JPEG Huffman 最小值 | `0x184` | `0x52003184` | 32 | — | 0x00000000 / 0x00000000 | DATA3[31:0] (RW)（最小 Huffman 值） | — |
| `JPEG_HUFFMIN3_2` | JPEG Huffman 最小值 | `0x188` | `0x52003188` | 32 | — | 0x00000000 / 0x00000000 | DATA3[31:0] (RW)（最小 Huffman 值） | — |
| `JPEG_HUFFMIN3_3` | JPEG Huffman 最小值 3 [备选] | `0x18C` | `0x5200318C` | 32 | — | 0x00000000 / 0x00000000 | DATA3[3:0] (RW)（最小 Huffman 值） | — |
| `JPEG_HUFFBASE0` | JPEG Huffman 基址 | `0x190` | `0x52003190` | 32 | — | 0x00000000 / 0x00000000 | DATA1[24:16] (RW)（数据 1）、DATA0[8:0] (RW)（数据 0） | — |
| `JPEG_HUFFBASE1` | JPEG Huffman 基址 | `0x194` | `0x52003194` | 32 | — | 0x00000000 / 0x00000000 | DATA3[24:16] (RW)（数据 3）、DATA2[8:0] (RW)（数据 2） | — |
| `JPEG_HUFFBASE2` | JPEG Huffman 基址 | `0x198` | `0x52003198` | 32 | — | 0x00000000 / 0x00000000 | DATA5[24:16] (RW)（数据 5）、DATA4[8:0] (RW)（数据 4） | — |
| `JPEG_HUFFBASE3` | JPEG Huffman 基址 | `0x19C` | `0x5200319C` | 32 | — | 0x00000000 / 0x00000000 | DATA7[24:16] (RW)（数据 7）、DATA6[8:0] (RW)（数据 6） | — |
| `JPEG_HUFFBASE4` | JPEG Huffman 基址 | `0x1A0` | `0x520031A0` | 32 | — | 0x00000000 / 0x00000000 | DATA9[24:16] (RW)（数据 9）、DATA8[8:0] (RW)（数据 8） | — |
| `JPEG_HUFFBASE5` | JPEG Huffman 基址 | `0x1A4` | `0x520031A4` | 32 | — | 0x00000000 / 0x00000000 | DATA11[24:16] (RW)（数据 11）、DATA10[8:0] (RW)（数据 10） | — |
| `JPEG_HUFFBASE6` | JPEG Huffman 基址 | `0x1A8` | `0x520031A8` | 32 | — | 0x00000000 / 0x00000000 | DATA13[24:16] (RW)（数据 13）、DATA12[8:0] (RW)（数据 12） | — |
| `JPEG_HUFFBASE7` | JPEG Huffman 基址 | `0x1AC` | `0x520031AC` | 32 | — | 0x00000000 / 0x00000000 | DATA15[24:16] (RW)（数据 15）、DATA14[8:0] (RW)（数据 14） | — |
| `JPEG_HUFFBASE8` | JPEG Huffman 基址 | `0x1B0` | `0x520031B0` | 32 | — | 0x00000000 / 0x00000000 | DATA17[24:16] (RW)（数据 17）、DATA16[8:0] (RW)（数据 16） | — |
| `JPEG_HUFFBASE9` | JPEG Huffman 基址 | `0x1B4` | `0x520031B4` | 32 | — | 0x00000000 / 0x00000000 | DATA19[24:16] (RW)（数据 19）、DATA18[8:0] (RW)（数据 18） | — |
| `JPEG_HUFFBASE10` | JPEG Huffman 基址 | `0x1B8` | `0x520031B8` | 32 | — | 0x00000000 / 0x00000000 | DATA21[24:16] (RW)（数据 21）、DATA20[8:0] (RW)（数据 20） | — |
| `JPEG_HUFFBASE11` | JPEG Huffman 基址 | `0x1BC` | `0x520031BC` | 32 | — | 0x00000000 / 0x00000000 | DATA23[24:16] (RW)（数据 23）、DATA22[8:0] (RW)（数据 22） | — |
| `JPEG_HUFFBASE12` | JPEG Huffman 基址 | `0x1C0` | `0x520031C0` | 32 | — | 0x00000000 / 0x00000000 | DATA25[24:16] (RW)（数据 25）、DATA24[8:0] (RW)（数据 24） | — |
| `JPEG_HUFFBASE13` | JPEG Huffman 基址 | `0x1C4` | `0x520031C4` | 32 | — | 0x00000000 / 0x00000000 | DATA27[24:16] (RW)（数据 27）、DATA26[8:0] (RW)（数据 26） | — |
| `JPEG_HUFFBASE14` | JPEG Huffman 基址 | `0x1C8` | `0x520031C8` | 32 | — | 0x00000000 / 0x00000000 | DATA29[24:16] (RW)（数据 29）、DATA28[8:0] (RW)（数据 28） | — |
| `JPEG_HUFFBASE15` | JPEG Huffman 基址 | `0x1CC` | `0x520031CC` | 32 | — | 0x00000000 / 0x00000000 | DATA31[24:16] (RW)（数据 31）、DATA30[8:0] (RW)（数据 30） | — |
| `JPEG_HUFFBASE16` | JPEG Huffman 基址 | `0x1D0` | `0x520031D0` | 32 | — | 0x00000000 / 0x00000000 | DATA33[24:16] (RW)（数据 33）、DATA32[8:0] (RW)（数据 32） | — |
| `JPEG_HUFFBASE17` | JPEG Huffman 基址 | `0x1D4` | `0x520031D4` | 32 | — | 0x00000000 / 0x00000000 | DATA35[24:16] (RW)（数据 35）、DATA34[8:0] (RW)（数据 34） | — |
| `JPEG_HUFFBASE18` | JPEG Huffman 基址 | `0x1D8` | `0x520031D8` | 32 | — | 0x00000000 / 0x00000000 | DATA37[24:16] (RW)（数据 37）、DATA36[8:0] (RW)（数据 36） | — |
| `JPEG_HUFFBASE19` | JPEG Huffman 基址 | `0x1DC` | `0x520031DC` | 32 | — | 0x00000000 / 0x00000000 | DATA39[24:16] (RW)（数据 39）、DATA38[8:0] (RW)（数据 38） | — |
| `JPEG_HUFFBASE20` | JPEG Huffman 基址 | `0x1E0` | `0x520031E0` | 32 | — | 0x00000000 / 0x00000000 | DATA41[24:16] (RW)（数据 41）、DATA40[8:0] (RW)（数据 40） | — |
| `JPEG_HUFFBASE21` | JPEG Huffman 基址 | `0x1E4` | `0x520031E4` | 32 | — | 0x00000000 / 0x00000000 | DATA43[24:16] (RW)（数据 43）、DATA42[8:0] (RW)（数据 42） | — |
| `JPEG_HUFFBASE22` | JPEG Huffman 基址 | `0x1E8` | `0x520031E8` | 32 | — | 0x00000000 / 0x00000000 | DATA45[24:16] (RW)（数据 45）、DATA44[8:0] (RW)（数据 44） | — |
| `JPEG_HUFFBASE23` | JPEG Huffman 基址 | `0x1EC` | `0x520031EC` | 32 | — | 0x00000000 / 0x00000000 | DATA47[24:16] (RW)（数据 47）、DATA46[8:0] (RW)（数据 46） | — |
| `JPEG_HUFFBASE24` | JPEG Huffman 基址 | `0x1F0` | `0x520031F0` | 32 | — | 0x00000000 / 0x00000000 | DATA49[24:16] (RW)（数据 49）、DATA48[8:0] (RW)（数据 48） | — |
| `JPEG_HUFFBASE25` | JPEG Huffman 基址 | `0x1F4` | `0x520031F4` | 32 | — | 0x00000000 / 0x00000000 | DATA51[24:16] (RW)（数据 51）、DATA50[8:0] (RW)（数据 50） | — |
| `JPEG_HUFFBASE26` | JPEG Huffman 基址 | `0x1F8` | `0x520031F8` | 32 | — | 0x00000000 / 0x00000000 | DATA53[24:16] (RW)（数据 53）、DATA52[8:0] (RW)（数据 52） | — |
| `JPEG_HUFFBASE27` | JPEG Huffman 基址 | `0x1FC` | `0x520031FC` | 32 | — | 0x00000000 / 0x00000000 | DATA55[24:16] (RW)（数据 55）、DATA54[8:0] (RW)（数据 54） | — |
| `JPEG_HUFFBASE28` | JPEG Huffman 基址 | `0x200` | `0x52003200` | 32 | — | 0x00000000 / 0x00000000 | DATA57[24:16] (RW)（数据 57）、DATA56[8:0] (RW)（数据 56） | — |
| `JPEG_HUFFBASE29` | JPEG Huffman 基址 | `0x204` | `0x52003204` | 32 | — | 0x00000000 / 0x00000000 | DATA59[24:16] (RW)（数据 59）、DATA58[8:0] (RW)（数据 58） | — |
| `JPEG_HUFFBASE30` | JPEG Huffman 基址 | `0x208` | `0x52003208` | 32 | — | 0x00000000 / 0x00000000 | DATA61[24:16] (RW)（数据 61）、DATA60[8:0] (RW)（数据 60） | — |
| `JPEG_HUFFBASE31` | JPEG Huffman 基址 | `0x20C` | `0x5200320C` | 32 | — | 0x00000000 / 0x00000000 | DATA63[24:16] (RW)（数据 63）、DATA62[8:0] (RW)（数据 62） | — |
| `JPEG_HUFFSYMB0` | JPEG Huffman 符号 | `0x210` | `0x52003210` | 32 | — | 0x00000000 / 0x00000000 | DATA3[31:24] (RW)（数据 3）、DATA2[23:16] (RW)（数据 2）、DATA1[15:8] (RW)（数据 1）、DATA0[7:0] (RW)（数据 0） | — |
| `JPEG_HUFFSYMB1` | JPEG Huffman 符号 | `0x214` | `0x52003214` | 32 | — | 0x00000000 / 0x00000000 | DATA7[31:24] (RW)（数据 7）、DATA6[23:16] (RW)（数据 6）、DATA5[15:8] (RW)（数据 5）、DATA4[7:0] (RW)（数据 4） | — |
| `JPEG_HUFFSYMB2` | JPEG Huffman 符号 | `0x218` | `0x52003218` | 32 | — | 0x00000000 / 0x00000000 | DATA11[31:24] (RW)（数据 11）、DATA10[23:16] (RW)（数据 10）、DATA9[15:8] (RW)（数据 9）、DATA8[7:0] (RW)（数据 8） | — |
| `JPEG_HUFFSYMB3` | JPEG Huffman 符号 | `0x21C` | `0x5200321C` | 32 | — | 0x00000000 / 0x00000000 | DATA15[31:24] (RW)（数据 15）、DATA14[23:16] (RW)（数据 14）、DATA13[15:8] (RW)（数据 13）、DATA12[7:0] (RW)（数据 12） | — |
| `JPEG_HUFFSYMB4` | JPEG Huffman 符号 | `0x220` | `0x52003220` | 32 | — | 0x00000000 / 0x00000000 | DATA19[31:24] (RW)（数据 19）、DATA18[23:16] (RW)（数据 18）、DATA17[15:8] (RW)（数据 17）、DATA16[7:0] (RW)（数据 16） | — |
| `JPEG_HUFFSYMB5` | JPEG Huffman 符号 | `0x224` | `0x52003224` | 32 | — | 0x00000000 / 0x00000000 | DATA23[31:24] (RW)（数据 23）、DATA22[23:16] (RW)（数据 22）、DATA21[15:8] (RW)（数据 21）、DATA20[7:0] (RW)（数据 20） | — |
| `JPEG_HUFFSYMB6` | JPEG Huffman 符号 | `0x228` | `0x52003228` | 32 | — | 0x00000000 / 0x00000000 | DATA27[31:24] (RW)（数据 27）、DATA26[23:16] (RW)（数据 26）、DATA25[15:8] (RW)（数据 25）、DATA24[7:0] (RW)（数据 24） | — |
| `JPEG_HUFFSYMB7` | JPEG Huffman 符号 | `0x22C` | `0x5200322C` | 32 | — | 0x00000000 / 0x00000000 | DATA31[31:24] (RW)（数据 31）、DATA30[23:16] (RW)（数据 30）、DATA29[15:8] (RW)（数据 29）、DATA28[7:0] (RW)（数据 28） | — |
| `JPEG_HUFFSYMB8` | JPEG Huffman 符号 | `0x230` | `0x52003230` | 32 | — | 0x00000000 / 0x00000000 | DATA35[31:24] (RW)（数据 35）、DATA34[23:16] (RW)（数据 34）、DATA33[15:8] (RW)（数据 33）、DATA32[7:0] (RW)（数据 32） | — |
| `JPEG_HUFFSYMB9` | JPEG Huffman 符号 | `0x234` | `0x52003234` | 32 | — | 0x00000000 / 0x00000000 | DATA39[31:24] (RW)（数据 39）、DATA38[23:16] (RW)（数据 38）、DATA37[15:8] (RW)（数据 37）、DATA36[7:0] (RW)（数据 36） | — |
| `JPEG_HUFFSYMB10` | JPEG Huffman 符号 | `0x238` | `0x52003238` | 32 | — | 0x00000000 / 0x00000000 | DATA43[31:24] (RW)（数据 43）、DATA42[23:16] (RW)（数据 42）、DATA41[15:8] (RW)（数据 41）、DATA40[7:0] (RW)（数据 40） | — |
| `JPEG_HUFFSYMB11` | JPEG Huffman 符号 | `0x23C` | `0x5200323C` | 32 | — | 0x00000000 / 0x00000000 | DATA47[31:24] (RW)（数据 47）、DATA46[23:16] (RW)（数据 46）、DATA45[15:8] (RW)（数据 45）、DATA44[7:0] (RW)（数据 44） | — |
| `JPEG_HUFFSYMB12` | JPEG Huffman 符号 | `0x240` | `0x52003240` | 32 | — | 0x00000000 / 0x00000000 | DATA51[31:24] (RW)（数据 51）、DATA50[23:16] (RW)（数据 50）、DATA49[15:8] (RW)（数据 49）、DATA48[7:0] (RW)（数据 48） | — |
| `JPEG_HUFFSYMB13` | JPEG Huffman 符号 | `0x244` | `0x52003244` | 32 | — | 0x00000000 / 0x00000000 | DATA55[31:24] (RW)（数据 55）、DATA54[23:16] (RW)（数据 54）、DATA53[15:8] (RW)（数据 53）、DATA52[7:0] (RW)（数据 52） | — |
| `JPEG_HUFFSYMB14` | JPEG Huffman 符号 | `0x248` | `0x52003248` | 32 | — | 0x00000000 / 0x00000000 | DATA59[31:24] (RW)（数据 59）、DATA58[23:16] (RW)（数据 58）、DATA57[15:8] (RW)（数据 57）、DATA56[7:0] (RW)（数据 56） | — |
| `JPEG_HUFFSYMB15` | JPEG Huffman 符号 | `0x24C` | `0x5200324C` | 32 | — | 0x00000000 / 0x00000000 | DATA63[31:24] (RW)（数据 63）、DATA62[23:16] (RW)（数据 62）、DATA61[15:8] (RW)（数据 61）、DATA60[7:0] (RW)（数据 60） | — |
| `JPEG_HUFFSYMB16` | JPEG Huffman 符号 | `0x250` | `0x52003250` | 32 | — | 0x00000000 / 0x00000000 | DATA67[31:24] (RW)（数据 67）、DATA66[23:16] (RW)（数据 66）、DATA65[15:8] (RW)（数据 65）、DATA64[7:0] (RW)（数据 64） | — |
| `JPEG_HUFFSYMB17` | JPEG Huffman 符号 | `0x254` | `0x52003254` | 32 | — | 0x00000000 / 0x00000000 | DATA71[31:24] (RW)（数据 71）、DATA70[23:16] (RW)（数据 70）、DATA69[15:8] (RW)（数据 69）、DATA68[7:0] (RW)（数据 68） | — |
| `JPEG_HUFFSYMB18` | JPEG Huffman 符号 | `0x258` | `0x52003258` | 32 | — | 0x00000000 / 0x00000000 | DATA75[31:24] (RW)（数据 75）、DATA74[23:16] (RW)（数据 74）、DATA73[15:8] (RW)（数据 73）、DATA72[7:0] (RW)（数据 72） | — |
| `JPEG_HUFFSYMB19` | JPEG Huffman 符号 | `0x25C` | `0x5200325C` | 32 | — | 0x00000000 / 0x00000000 | DATA79[31:24] (RW)（数据 79）、DATA78[23:16] (RW)（数据 78）、DATA77[15:8] (RW)（数据 77）、DATA76[7:0] (RW)（数据 76） | — |
| `JPEG_HUFFSYMB20` | JPEG Huffman 符号 | `0x260` | `0x52003260` | 32 | — | 0x00000000 / 0x00000000 | DATA83[31:24] (RW)（数据 83）、DATA82[23:16] (RW)（数据 82）、DATA81[15:8] (RW)（数据 81）、DATA80[7:0] (RW)（数据 80） | — |
| `JPEG_HUFFSYMB21` | JPEG Huffman 符号 | `0x264` | `0x52003264` | 32 | — | 0x00000000 / 0x00000000 | DATA87[31:24] (RW)（数据 87）、DATA86[23:16] (RW)（数据 86）、DATA85[15:8] (RW)（数据 85）、DATA84[7:0] (RW)（数据 84） | — |
| `JPEG_HUFFSYMB22` | JPEG Huffman 符号 | `0x268` | `0x52003268` | 32 | — | 0x00000000 / 0x00000000 | DATA91[31:24] (RW)（数据 91）、DATA90[23:16] (RW)（数据 90）、DATA89[15:8] (RW)（数据 89）、DATA88[7:0] (RW)（数据 88） | — |
| `JPEG_HUFFSYMB23` | JPEG Huffman 符号 | `0x26C` | `0x5200326C` | 32 | — | 0x00000000 / 0x00000000 | DATA95[31:24] (RW)（数据 95）、DATA94[23:16] (RW)（数据 94）、DATA93[15:8] (RW)（数据 93）、DATA92[7:0] (RW)（数据 92） | — |
| `JPEG_HUFFSYMB24` | JPEG Huffman 符号 | `0x270` | `0x52003270` | 32 | — | 0x00000000 / 0x00000000 | DATA99[31:24] (RW)（数据 99）、DATA98[23:16] (RW)（数据 98）、DATA97[15:8] (RW)（数据 97）、DATA96[7:0] (RW)（数据 96） | — |
| `JPEG_HUFFSYMB25` | JPEG Huffman 符号 | `0x274` | `0x52003274` | 32 | — | 0x00000000 / 0x00000000 | DATA103[31:24] (RW)（数据 103）、DATA102[23:16] (RW)（数据 102）、DATA101[15:8] (RW)（数据 101）、DATA100[7:0] (RW)（数据 100） | — |
| `JPEG_HUFFSYMB26` | JPEG Huffman 符号 | `0x278` | `0x52003278` | 32 | — | 0x00000000 / 0x00000000 | DATA107[31:24] (RW)（数据 107）、DATA106[23:16] (RW)（数据 106）、DATA105[15:8] (RW)（数据 105）、DATA104[7:0] (RW)（数据 104） | — |
| `JPEG_HUFFSYMB27` | JPEG Huffman 符号 | `0x27C` | `0x5200327C` | 32 | — | 0x00000000 / 0x00000000 | DATA111[31:24] (RW)（数据 111）、DATA110[23:16] (RW)（数据 110）、DATA109[15:8] (RW)（数据 109）、DATA108[7:0] (RW)（数据 108） | — |
| `JPEG_HUFFSYMB28` | JPEG Huffman 符号 | `0x280` | `0x52003280` | 32 | — | 0x00000000 / 0x00000000 | DATA115[31:24] (RW)（数据 115）、DATA114[23:16] (RW)（数据 114）、DATA113[15:8] (RW)（数据 113）、DATA112[7:0] (RW)（数据 112） | — |
| `JPEG_HUFFSYMB29` | JPEG Huffman 符号 | `0x284` | `0x52003284` | 32 | — | 0x00000000 / 0x00000000 | DATA119[31:24] (RW)（数据 119）、DATA118[23:16] (RW)（数据 118）、DATA117[15:8] (RW)（数据 117）、DATA116[7:0] (RW)（数据 116） | — |
| `JPEG_HUFFSYMB30` | JPEG Huffman 符号 | `0x288` | `0x52003288` | 32 | — | 0x00000000 / 0x00000000 | DATA123[31:24] (RW)（数据 123）、DATA122[23:16] (RW)（数据 122）、DATA121[15:8] (RW)（数据 121）、DATA120[7:0] (RW)（数据 120） | — |
| `JPEG_HUFFSYMB31` | JPEG Huffman 符号 | `0x28C` | `0x5200328C` | 32 | — | 0x00000000 / 0x00000000 | DATA127[31:24] (RW)（数据 127）、DATA126[23:16] (RW)（数据 126）、DATA125[15:8] (RW)（数据 125）、DATA124[7:0] (RW)（数据 124） | — |
| `JPEG_HUFFSYMB32` | JPEG Huffman 符号 | `0x290` | `0x52003290` | 32 | — | 0x00000000 / 0x00000000 | DATA131[31:24] (RW)（数据 131）、DATA130[23:16] (RW)（数据 130）、DATA129[15:8] (RW)（数据 129）、DATA128[7:0] (RW)（数据 128） | — |
| `JPEG_HUFFSYMB33` | JPEG Huffman 符号 | `0x294` | `0x52003294` | 32 | — | 0x00000000 / 0x00000000 | DATA135[31:24] (RW)（数据 135）、DATA134[23:16] (RW)（数据 134）、DATA133[15:8] (RW)（数据 133）、DATA132[7:0] (RW)（数据 132） | — |
| `JPEG_HUFFSYMB34` | JPEG Huffman 符号 | `0x298` | `0x52003298` | 32 | — | 0x00000000 / 0x00000000 | DATA139[31:24] (RW)（数据 139）、DATA138[23:16] (RW)（数据 138）、DATA137[15:8] (RW)（数据 137）、DATA136[7:0] (RW)（数据 136） | — |
| `JPEG_HUFFSYMB35` | JPEG Huffman 符号 | `0x29C` | `0x5200329C` | 32 | — | 0x00000000 / 0x00000000 | DATA143[31:24] (RW)（数据 143）、DATA142[23:16] (RW)（数据 142）、DATA141[15:8] (RW)（数据 141）、DATA140[7:0] (RW)（数据 140） | — |
| `JPEG_HUFFSYMB36` | JPEG Huffman 符号 | `0x2A0` | `0x520032A0` | 32 | — | 0x00000000 / 0x00000000 | DATA147[31:24] (RW)（数据 147）、DATA146[23:16] (RW)（数据 146）、DATA145[15:8] (RW)（数据 145）、DATA144[7:0] (RW)（数据 144） | — |
| `JPEG_HUFFSYMB37` | JPEG Huffman 符号 | `0x2A4` | `0x520032A4` | 32 | — | 0x00000000 / 0x00000000 | DATA151[31:24] (RW)（数据 151）、DATA150[23:16] (RW)（数据 150）、DATA149[15:8] (RW)（数据 149）、DATA148[7:0] (RW)（数据 148） | — |
| `JPEG_HUFFSYMB38` | JPEG Huffman 符号 | `0x2A8` | `0x520032A8` | 32 | — | 0x00000000 / 0x00000000 | DATA155[31:24] (RW)（数据 155）、DATA154[23:16] (RW)（数据 154）、DATA153[15:8] (RW)（数据 153）、DATA152[7:0] (RW)（数据 152） | — |
| `JPEG_HUFFSYMB39` | JPEG Huffman 符号 | `0x2AC` | `0x520032AC` | 32 | — | 0x00000000 / 0x00000000 | DATA159[31:24] (RW)（数据 159）、DATA158[23:16] (RW)（数据 158）、DATA157[15:8] (RW)（数据 157）、DATA156[7:0] (RW)（数据 156） | — |
| `JPEG_HUFFSYMB40` | JPEG Huffman 符号 | `0x2B0` | `0x520032B0` | 32 | — | 0x00000000 / 0x00000000 | DATA163[31:24] (RW)（数据 163）、DATA162[23:16] (RW)（数据 162）、DATA161[15:8] (RW)（数据 161）、DATA160[7:0] (RW)（数据 160） | — |
| `JPEG_HUFFSYMB41` | JPEG Huffman 符号 | `0x2B4` | `0x520032B4` | 32 | — | 0x00000000 / 0x00000000 | DATA167[31:24] (RW)（数据 167）、DATA166[23:16] (RW)（数据 166）、DATA165[15:8] (RW)（数据 165）、DATA164[7:0] (RW)（数据 164） | — |
| `JPEG_HUFFSYMB42` | JPEG Huffman 符号 | `0x2B8` | `0x520032B8` | 32 | — | 0x00000000 / 0x00000000 | DATA171[31:24] (RW)（数据 171）、DATA170[23:16] (RW)（数据 170）、DATA169[15:8] (RW)（数据 169）、DATA168[7:0] (RW)（数据 168） | — |
| `JPEG_HUFFSYMB43` | JPEG Huffman 符号 | `0x2BC` | `0x520032BC` | 32 | — | 0x00000000 / 0x00000000 | DATA175[31:24] (RW)（数据 175）、DATA174[23:16] (RW)（数据 174）、DATA173[15:8] (RW)（数据 173）、DATA172[7:0] (RW)（数据 172） | — |
| `JPEG_HUFFSYMB44` | JPEG Huffman 符号 | `0x2C0` | `0x520032C0` | 32 | — | 0x00000000 / 0x00000000 | DATA179[31:24] (RW)（数据 179）、DATA178[23:16] (RW)（数据 178）、DATA177[15:8] (RW)（数据 177）、DATA176[7:0] (RW)（数据 176） | — |
| `JPEG_HUFFSYMB45` | JPEG Huffman 符号 | `0x2C4` | `0x520032C4` | 32 | — | 0x00000000 / 0x00000000 | DATA183[31:24] (RW)（数据 183）、DATA182[23:16] (RW)（数据 182）、DATA181[15:8] (RW)（数据 181）、DATA180[7:0] (RW)（数据 180） | — |
| `JPEG_HUFFSYMB46` | JPEG Huffman 符号 | `0x2C8` | `0x520032C8` | 32 | — | 0x00000000 / 0x00000000 | DATA187[31:24] (RW)（数据 187）、DATA186[23:16] (RW)（数据 186）、DATA185[15:8] (RW)（数据 185）、DATA184[7:0] (RW)（数据 184） | — |
| `JPEG_HUFFSYMB47` | JPEG Huffman 符号 | `0x2CC` | `0x520032CC` | 32 | — | 0x00000000 / 0x00000000 | DATA191[31:24] (RW)（数据 191）、DATA190[23:16] (RW)（数据 190）、DATA189[15:8] (RW)（数据 189）、DATA188[7:0] (RW)（数据 188） | — |
| `JPEG_HUFFSYMB48` | JPEG Huffman 符号 | `0x2D0` | `0x520032D0` | 32 | — | 0x00000000 / 0x00000000 | DATA195[31:24] (RW)（数据 195）、DATA194[23:16] (RW)（数据 194）、DATA193[15:8] (RW)（数据 193）、DATA192[7:0] (RW)（数据 192） | — |
| `JPEG_HUFFSYMB49` | JPEG Huffman 符号 | `0x2D4` | `0x520032D4` | 32 | — | 0x00000000 / 0x00000000 | DATA199[31:24] (RW)（数据 199）、DATA198[23:16] (RW)（数据 198）、DATA197[15:8] (RW)（数据 197）、DATA196[7:0] (RW)（数据 196） | — |
| `JPEG_HUFFSYMB50` | JPEG Huffman 符号 | `0x2D8` | `0x520032D8` | 32 | — | 0x00000000 / 0x00000000 | DATA203[31:24] (RW)（数据 203）、DATA202[23:16] (RW)（数据 202）、DATA201[15:8] (RW)（数据 201）、DATA200[7:0] (RW)（数据 200） | — |
| `JPEG_HUFFSYMB51` | JPEG Huffman 符号 | `0x2DC` | `0x520032DC` | 32 | — | 0x00000000 / 0x00000000 | DATA207[31:24] (RW)（数据 207）、DATA206[23:16] (RW)（数据 206）、DATA205[15:8] (RW)（数据 205）、DATA204[7:0] (RW)（数据 204） | — |
| `JPEG_HUFFSYMB52` | JPEG Huffman 符号 | `0x2E0` | `0x520032E0` | 32 | — | 0x00000000 / 0x00000000 | DATA211[31:24] (RW)（数据 211）、DATA210[23:16] (RW)（数据 210）、DATA209[15:8] (RW)（数据 209）、DATA208[7:0] (RW)（数据 208） | — |
| `JPEG_HUFFSYMB53` | JPEG Huffman 符号 | `0x2E4` | `0x520032E4` | 32 | — | 0x00000000 / 0x00000000 | DATA215[31:24] (RW)（数据 215）、DATA214[23:16] (RW)（数据 214）、DATA213[15:8] (RW)（数据 213）、DATA212[7:0] (RW)（数据 212） | — |
| `JPEG_HUFFSYMB54` | JPEG Huffman 符号 | `0x2E8` | `0x520032E8` | 32 | — | 0x00000000 / 0x00000000 | DATA219[31:24] (RW)（数据 219）、DATA218[23:16] (RW)（数据 218）、DATA217[15:8] (RW)（数据 217）、DATA216[7:0] (RW)（数据 216） | — |
| `JPEG_HUFFSYMB55` | JPEG Huffman 符号 | `0x2EC` | `0x520032EC` | 32 | — | 0x00000000 / 0x00000000 | DATA223[31:24] (RW)（数据 223）、DATA222[23:16] (RW)（数据 222）、DATA221[15:8] (RW)（数据 221）、DATA220[7:0] (RW)（数据 220） | — |
| `JPEG_HUFFSYMB56` | JPEG Huffman 符号 | `0x2F0` | `0x520032F0` | 32 | — | 0x00000000 / 0x00000000 | DATA227[31:24] (RW)（数据 227）、DATA226[23:16] (RW)（数据 226）、DATA225[15:8] (RW)（数据 225）、DATA224[7:0] (RW)（数据 224） | — |
| `JPEG_HUFFSYMB57` | JPEG Huffman 符号 | `0x2F4` | `0x520032F4` | 32 | — | 0x00000000 / 0x00000000 | DATA231[31:24] (RW)（数据 231）、DATA230[23:16] (RW)（数据 230）、DATA229[15:8] (RW)（数据 229）、DATA228[7:0] (RW)（数据 228） | — |
| `JPEG_HUFFSYMB58` | JPEG Huffman 符号 | `0x2F8` | `0x520032F8` | 32 | — | 0x00000000 / 0x00000000 | DATA235[31:24] (RW)（数据 235）、DATA234[23:16] (RW)（数据 234）、DATA233[15:8] (RW)（数据 233）、DATA232[7:0] (RW)（数据 232） | — |
| `JPEG_HUFFSYMB59` | JPEG Huffman 符号 | `0x2FC` | `0x520032FC` | 32 | — | 0x00000000 / 0x00000000 | DATA239[31:24] (RW)（数据 239）、DATA238[23:16] (RW)（数据 238）、DATA237[15:8] (RW)（数据 237）、DATA236[7:0] (RW)（数据 236） | — |
| `JPEG_HUFFSYMB60` | JPEG Huffman 符号 | `0x300` | `0x52003300` | 32 | — | 0x00000000 / 0x00000000 | DATA243[31:24] (RW)（数据 243）、DATA242[23:16] (RW)（数据 242）、DATA241[15:8] (RW)（数据 241）、DATA240[7:0] (RW)（数据 240） | — |
| `JPEG_HUFFSYMB61` | JPEG Huffman 符号 | `0x304` | `0x52003304` | 32 | — | 0x00000000 / 0x00000000 | DATA247[31:24] (RW)（数据 247）、DATA246[23:16] (RW)（数据 246）、DATA245[15:8] (RW)（数据 245）、DATA244[7:0] (RW)（数据 244） | — |
| `JPEG_HUFFSYMB62` | JPEG Huffman 符号 | `0x308` | `0x52003308` | 32 | — | 0x00000000 / 0x00000000 | DATA251[31:24] (RW)（数据 251）、DATA250[23:16] (RW)（数据 250）、DATA249[15:8] (RW)（数据 249）、DATA248[7:0] (RW)（数据 248） | — |
| `JPEG_HUFFSYMB63` | JPEG Huffman 符号 | `0x30C` | `0x5200330C` | 32 | — | 0x00000000 / 0x00000000 | DATA255[31:24] (RW)（数据 255）、DATA254[23:16] (RW)（数据 254）、DATA253[15:8] (RW)（数据 253）、DATA252[7:0] (RW)（数据 252） | — |
| `JPEG_HUFFSYMB64` | JPEG Huffman 符号 | `0x310` | `0x52003310` | 32 | — | 0x00000000 / 0x00000000 | DATA259[31:24] (RW)（数据 259）、DATA258[23:16] (RW)（数据 258）、DATA257[15:8] (RW)（数据 257）、DATA256[7:0] (RW)（数据 256） | — |
| `JPEG_HUFFSYMB65` | JPEG Huffman 符号 | `0x314` | `0x52003314` | 32 | — | 0x00000000 / 0x00000000 | DATA263[31:24] (RW)（数据 263）、DATA262[23:16] (RW)（数据 262）、DATA261[15:8] (RW)（数据 261）、DATA260[7:0] (RW)（数据 260） | — |
| `JPEG_HUFFSYMB66` | JPEG Huffman 符号 | `0x318` | `0x52003318` | 32 | — | 0x00000000 / 0x00000000 | DATA267[31:24] (RW)（数据 267）、DATA266[23:16] (RW)（数据 266）、DATA265[15:8] (RW)（数据 265）、DATA264[7:0] (RW)（数据 264） | — |
| `JPEG_HUFFSYMB67` | JPEG Huffman 符号 | `0x31C` | `0x5200331C` | 32 | — | 0x00000000 / 0x00000000 | DATA271[31:24] (RW)（数据 271）、DATA270[23:16] (RW)（数据 270）、DATA269[15:8] (RW)（数据 269）、DATA268[7:0] (RW)（数据 268） | — |
| `JPEG_HUFFSYMB68` | JPEG Huffman 符号 | `0x320` | `0x52003320` | 32 | — | 0x00000000 / 0x00000000 | DATA275[31:24] (RW)（数据 275）、DATA274[23:16] (RW)（数据 274）、DATA273[15:8] (RW)（数据 273）、DATA272[7:0] (RW)（数据 272） | — |
| `JPEG_HUFFSYMB69` | JPEG Huffman 符号 | `0x324` | `0x52003324` | 32 | — | 0x00000000 / 0x00000000 | DATA279[31:24] (RW)（数据 279）、DATA278[23:16] (RW)（数据 278）、DATA277[15:8] (RW)（数据 277）、DATA276[7:0] (RW)（数据 276） | — |
| `JPEG_HUFFSYMB70` | JPEG Huffman 符号 | `0x328` | `0x52003328` | 32 | — | 0x00000000 / 0x00000000 | DATA283[31:24] (RW)（数据 283）、DATA282[23:16] (RW)（数据 282）、DATA281[15:8] (RW)（数据 281）、DATA280[7:0] (RW)（数据 280） | — |
| `JPEG_HUFFSYMB71` | JPEG Huffman 符号 | `0x32C` | `0x5200332C` | 32 | — | 0x00000000 / 0x00000000 | DATA287[31:24] (RW)（数据 287）、DATA286[23:16] (RW)（数据 286）、DATA285[15:8] (RW)（数据 285）、DATA284[7:0] (RW)（数据 284） | — |
| `JPEG_HUFFSYMB72` | JPEG Huffman 符号 | `0x330` | `0x52003330` | 32 | — | 0x00000000 / 0x00000000 | DATA291[31:24] (RW)（数据 291）、DATA290[23:16] (RW)（数据 290）、DATA289[15:8] (RW)（数据 289）、DATA288[7:0] (RW)（数据 288） | — |
| `JPEG_HUFFSYMB73` | JPEG Huffman 符号 | `0x334` | `0x52003334` | 32 | — | 0x00000000 / 0x00000000 | DATA295[31:24] (RW)（数据 295）、DATA294[23:16] (RW)（数据 294）、DATA293[15:8] (RW)（数据 293）、DATA292[7:0] (RW)（数据 292） | — |
| `JPEG_HUFFSYMB74` | JPEG Huffman 符号 | `0x338` | `0x52003338` | 32 | — | 0x00000000 / 0x00000000 | DATA299[31:24] (RW)（数据 299）、DATA298[23:16] (RW)（数据 298）、DATA297[15:8] (RW)（数据 297）、DATA296[7:0] (RW)（数据 296） | — |
| `JPEG_HUFFSYMB75` | JPEG Huffman 符号 | `0x33C` | `0x5200333C` | 32 | — | 0x00000000 / 0x00000000 | DATA303[31:24] (RW)（数据 303）、DATA302[23:16] (RW)（数据 302）、DATA301[15:8] (RW)（数据 301）、DATA300[7:0] (RW)（数据 300） | — |
| `JPEG_HUFFSYMB76` | JPEG Huffman 符号 | `0x340` | `0x52003340` | 32 | — | 0x00000000 / 0x00000000 | DATA307[31:24] (RW)（数据 307）、DATA306[23:16] (RW)（数据 306）、DATA305[15:8] (RW)（数据 305）、DATA304[7:0] (RW)（数据 304） | — |
| `JPEG_HUFFSYMB77` | JPEG Huffman 符号 | `0x344` | `0x52003344` | 32 | — | 0x00000000 / 0x00000000 | DATA311[31:24] (RW)（数据 311）、DATA310[23:16] (RW)（数据 310）、DATA309[15:8] (RW)（数据 309）、DATA308[7:0] (RW)（数据 308） | — |
| `JPEG_HUFFSYMB78` | JPEG Huffman 符号 | `0x348` | `0x52003348` | 32 | — | 0x00000000 / 0x00000000 | DATA315[31:24] (RW)（数据 315）、DATA314[23:16] (RW)（数据 314）、DATA313[15:8] (RW)（数据 313）、DATA312[7:0] (RW)（数据 312） | — |
| `JPEG_HUFFSYMB79` | JPEG Huffman 符号 | `0x34C` | `0x5200334C` | 32 | — | 0x00000000 / 0x00000000 | DATA319[31:24] (RW)（数据 319）、DATA318[23:16] (RW)（数据 318）、DATA317[15:8] (RW)（数据 317）、DATA316[7:0] (RW)（数据 316） | — |
| `JPEG_HUFFSYMB80` | JPEG Huffman 符号 | `0x350` | `0x52003350` | 32 | — | 0x00000000 / 0x00000000 | DATA323[31:24] (RW)（数据 323）、DATA322[23:16] (RW)（数据 322）、DATA321[15:8] (RW)（数据 321）、DATA320[7:0] (RW)（数据 320） | — |
| `JPEG_HUFFSYMB81` | JPEG Huffman 符号 | `0x354` | `0x52003354` | 32 | — | 0x00000000 / 0x00000000 | DATA327[31:24] (RW)（数据 327）、DATA326[23:16] (RW)（数据 326）、DATA325[15:8] (RW)（数据 325）、DATA324[7:0] (RW)（数据 324） | — |
| `JPEG_HUFFSYMB82` | JPEG Huffman 符号 | `0x358` | `0x52003358` | 32 | — | 0x00000000 / 0x00000000 | DATA331[31:24] (RW)（数据 331）、DATA330[23:16] (RW)（数据 330）、DATA329[15:8] (RW)（数据 329）、DATA328[7:0] (RW)（数据 328） | — |
| `JPEG_HUFFSYMB83` | JPEG Huffman 符号 | `0x35C` | `0x5200335C` | 32 | — | 0x00000000 / 0x00000000 | DATA335[31:24] (RW)（数据 335）、DATA334[23:16] (RW)（数据 334）、DATA333[15:8] (RW)（数据 333）、DATA332[7:0] (RW)（数据 332） | — |
| `JPEG_DHTMEM0` | JPEG DHT 存储器 | `0x360` | `0x52003360` | 32 | — | 0x00000000 / 0x00000000 | DATA3[31:24] (RW)（Huffman 表数据 3）、DATA2[23:16] (RW)（Huffman 表数据 2）、DATA1[15:8] (RW)（Huffman 表数据 1）、DATA0[7:0] (RW)（Huffman 表数据 0） | — |
| `JPEG_DHTMEM1` | JPEG DHT 存储器 | `0x364` | `0x52003364` | 32 | — | 0x00000000 / 0x00000000 | DATA7[31:24] (RW)（Huffman 表数据 7）、DATA6[23:16] (RW)（Huffman 表数据 6）、DATA5[15:8] (RW)（Huffman 表数据 5）、DATA4[7:0] (RW)（Huffman 表数据 4） | — |
| `JPEG_DHTMEM2` | JPEG DHT 存储器 | `0x368` | `0x52003368` | 32 | — | 0x00000000 / 0x00000000 | DATA11[31:24] (RW)（Huffman 表数据 11）、DATA10[23:16] (RW)（Huffman 表数据 10）、DATA9[15:8] (RW)（Huffman 表数据 9）、DATA8[7:0] (RW)（Huffman 表数据 8） | — |
| `JPEG_DHTMEM3` | JPEG DHT 存储器 | `0x36C` | `0x5200336C` | 32 | — | 0x00000000 / 0x00000000 | DATA15[31:24] (RW)（Huffman 表数据 15）、DATA14[23:16] (RW)（Huffman 表数据 14）、DATA13[15:8] (RW)（Huffman 表数据 13）、DATA12[7:0] (RW)（Huffman 表数据 12） | — |
| `JPEG_DHTMEM4` | JPEG DHT 存储器 | `0x370` | `0x52003370` | 32 | — | 0x00000000 / 0x00000000 | DATA19[31:24] (RW)（Huffman 表数据 19）、DATA18[23:16] (RW)（Huffman 表数据 18）、DATA17[15:8] (RW)（Huffman 表数据 17）、DATA16[7:0] (RW)（Huffman 表数据 16） | — |
| `JPEG_DHTMEM5` | JPEG DHT 存储器 | `0x374` | `0x52003374` | 32 | — | 0x00000000 / 0x00000000 | DATA23[31:24] (RW)（Huffman 表数据 23）、DATA22[23:16] (RW)（Huffman 表数据 22）、DATA21[15:8] (RW)（Huffman 表数据 21）、DATA20[7:0] (RW)（Huffman 表数据 20） | — |
| `JPEG_DHTMEM6` | JPEG DHT 存储器 | `0x378` | `0x52003378` | 32 | — | 0x00000000 / 0x00000000 | DATA27[31:24] (RW)（Huffman 表数据 27）、DATA26[23:16] (RW)（Huffman 表数据 26）、DATA25[15:8] (RW)（Huffman 表数据 25）、DATA24[7:0] (RW)（Huffman 表数据 24） | — |
| `JPEG_DHTMEM7` | JPEG DHT 存储器 | `0x37C` | `0x5200337C` | 32 | — | 0x00000000 / 0x00000000 | DATA31[31:24] (RW)（Huffman 表数据 31）、DATA30[23:16] (RW)（Huffman 表数据 30）、DATA29[15:8] (RW)（Huffman 表数据 29）、DATA28[7:0] (RW)（Huffman 表数据 28） | — |
| `JPEG_DHTMEM8` | JPEG DHT 存储器 | `0x380` | `0x52003380` | 32 | — | 0x00000000 / 0x00000000 | DATA35[31:24] (RW)（Huffman 表数据 35）、DATA34[23:16] (RW)（Huffman 表数据 34）、DATA33[15:8] (RW)（Huffman 表数据 33）、DATA32[7:0] (RW)（Huffman 表数据 32） | — |
| `JPEG_DHTMEM9` | JPEG DHT 存储器 | `0x384` | `0x52003384` | 32 | — | 0x00000000 / 0x00000000 | DATA39[31:24] (RW)（Huffman 表数据 39）、DATA38[23:16] (RW)（Huffman 表数据 38）、DATA37[15:8] (RW)（Huffman 表数据 37）、DATA36[7:0] (RW)（Huffman 表数据 36） | — |
| `JPEG_DHTMEM10` | JPEG DHT 存储器 | `0x388` | `0x52003388` | 32 | — | 0x00000000 / 0x00000000 | DATA43[31:24] (RW)（Huffman 表数据 43）、DATA42[23:16] (RW)（Huffman 表数据 42）、DATA41[15:8] (RW)（Huffman 表数据 41）、DATA40[7:0] (RW)（Huffman 表数据 40） | — |
| `JPEG_DHTMEM11` | JPEG DHT 存储器 | `0x38C` | `0x5200338C` | 32 | — | 0x00000000 / 0x00000000 | DATA47[31:24] (RW)（Huffman 表数据 47）、DATA46[23:16] (RW)（Huffman 表数据 46）、DATA45[15:8] (RW)（Huffman 表数据 45）、DATA44[7:0] (RW)（Huffman 表数据 44） | — |
| `JPEG_DHTMEM12` | JPEG DHT 存储器 | `0x390` | `0x52003390` | 32 | — | 0x00000000 / 0x00000000 | DATA51[31:24] (RW)（Huffman 表数据 51）、DATA50[23:16] (RW)（Huffman 表数据 50）、DATA49[15:8] (RW)（Huffman 表数据 49）、DATA48[7:0] (RW)（Huffman 表数据 48） | — |
| `JPEG_DHTMEM13` | JPEG DHT 存储器 | `0x394` | `0x52003394` | 32 | — | 0x00000000 / 0x00000000 | DATA55[31:24] (RW)（Huffman 表数据 55）、DATA54[23:16] (RW)（Huffman 表数据 54）、DATA53[15:8] (RW)（Huffman 表数据 53）、DATA52[7:0] (RW)（Huffman 表数据 52） | — |
| `JPEG_DHTMEM14` | JPEG DHT 存储器 | `0x398` | `0x52003398` | 32 | — | 0x00000000 / 0x00000000 | DATA59[31:24] (RW)（Huffman 表数据 59）、DATA58[23:16] (RW)（Huffman 表数据 58）、DATA57[15:8] (RW)（Huffman 表数据 57）、DATA56[7:0] (RW)（Huffman 表数据 56） | — |
| `JPEG_DHTMEM15` | JPEG DHT 存储器 | `0x39C` | `0x5200339C` | 32 | — | 0x00000000 / 0x00000000 | DATA63[31:24] (RW)（Huffman 表数据 63）、DATA62[23:16] (RW)（Huffman 表数据 62）、DATA61[15:8] (RW)（Huffman 表数据 61）、DATA60[7:0] (RW)（Huffman 表数据 60） | — |
| `JPEG_DHTMEM16` | JPEG DHT 存储器 | `0x3A0` | `0x520033A0` | 32 | — | 0x00000000 / 0x00000000 | DATA67[31:24] (RW)（Huffman 表数据 67）、DATA66[23:16] (RW)（Huffman 表数据 66）、DATA65[15:8] (RW)（Huffman 表数据 65）、DATA64[7:0] (RW)（Huffman 表数据 64） | — |
| `JPEG_DHTMEM17` | JPEG DHT 存储器 | `0x3A4` | `0x520033A4` | 32 | — | 0x00000000 / 0x00000000 | DATA71[31:24] (RW)（Huffman 表数据 71）、DATA70[23:16] (RW)（Huffman 表数据 70）、DATA69[15:8] (RW)（Huffman 表数据 69）、DATA68[7:0] (RW)（Huffman 表数据 68） | — |
| `JPEG_DHTMEM18` | JPEG DHT 存储器 | `0x3A8` | `0x520033A8` | 32 | — | 0x00000000 / 0x00000000 | DATA75[31:24] (RW)（Huffman 表数据 75）、DATA74[23:16] (RW)（Huffman 表数据 74）、DATA73[15:8] (RW)（Huffman 表数据 73）、DATA72[7:0] (RW)（Huffman 表数据 72） | — |
| `JPEG_DHTMEM19` | JPEG DHT 存储器 | `0x3AC` | `0x520033AC` | 32 | — | 0x00000000 / 0x00000000 | DATA79[31:24] (RW)（Huffman 表数据 79）、DATA78[23:16] (RW)（Huffman 表数据 78）、DATA77[15:8] (RW)（Huffman 表数据 77）、DATA76[7:0] (RW)（Huffman 表数据 76） | — |
| `JPEG_DHTMEM20` | JPEG DHT 存储器 | `0x3B0` | `0x520033B0` | 32 | — | 0x00000000 / 0x00000000 | DATA83[31:24] (RW)（Huffman 表数据 83）、DATA82[23:16] (RW)（Huffman 表数据 82）、DATA81[15:8] (RW)（Huffman 表数据 81）、DATA80[7:0] (RW)（Huffman 表数据 80） | — |
| `JPEG_DHTMEM21` | JPEG DHT 存储器 | `0x3B4` | `0x520033B4` | 32 | — | 0x00000000 / 0x00000000 | DATA87[31:24] (RW)（Huffman 表数据 87）、DATA86[23:16] (RW)（Huffman 表数据 86）、DATA85[15:8] (RW)（Huffman 表数据 85）、DATA84[7:0] (RW)（Huffman 表数据 84） | — |
| `JPEG_DHTMEM22` | JPEG DHT 存储器 | `0x3B8` | `0x520033B8` | 32 | — | 0x00000000 / 0x00000000 | DATA91[31:24] (RW)（Huffman 表数据 91）、DATA90[23:16] (RW)（Huffman 表数据 90）、DATA89[15:8] (RW)（Huffman 表数据 89）、DATA88[7:0] (RW)（Huffman 表数据 88） | — |
| `JPEG_DHTMEM23` | JPEG DHT 存储器 | `0x3BC` | `0x520033BC` | 32 | — | 0x00000000 / 0x00000000 | DATA95[31:24] (RW)（Huffman 表数据 95）、DATA94[23:16] (RW)（Huffman 表数据 94）、DATA93[15:8] (RW)（Huffman 表数据 93）、DATA92[7:0] (RW)（Huffman 表数据 92） | — |
| `JPEG_DHTMEM24` | JPEG DHT 存储器 | `0x3C0` | `0x520033C0` | 32 | — | 0x00000000 / 0x00000000 | DATA99[31:24] (RW)（Huffman 表数据 99）、DATA98[23:16] (RW)（Huffman 表数据 98）、DATA97[15:8] (RW)（Huffman 表数据 97）、DATA96[7:0] (RW)（Huffman 表数据 96） | — |
| `JPEG_DHTMEM25` | JPEG DHT 存储器 | `0x3C4` | `0x520033C4` | 32 | — | 0x00000000 / 0x00000000 | DATA103[31:24] (RW)（Huffman 表数据 103）、DATA102[23:16] (RW)（Huffman 表数据 102）、DATA101[15:8] (RW)（Huffman 表数据 101）、DATA100[7:0] (RW)（Huffman 表数据 100） | — |
| `JPEG_DHTMEM26` | JPEG DHT 存储器 | `0x3C8` | `0x520033C8` | 32 | — | 0x00000000 / 0x00000000 | DATA107[31:24] (RW)（Huffman 表数据 107）、DATA106[23:16] (RW)（Huffman 表数据 106）、DATA105[15:8] (RW)（Huffman 表数据 105）、DATA104[7:0] (RW)（Huffman 表数据 104） | — |
| `JPEG_DHTMEM27` | JPEG DHT 存储器 | `0x3CC` | `0x520033CC` | 32 | — | 0x00000000 / 0x00000000 | DATA111[31:24] (RW)（Huffman 表数据 111）、DATA110[23:16] (RW)（Huffman 表数据 110）、DATA109[15:8] (RW)（Huffman 表数据 109）、DATA108[7:0] (RW)（Huffman 表数据 108） | — |
| `JPEG_DHTMEM28` | JPEG DHT 存储器 | `0x3D0` | `0x520033D0` | 32 | — | 0x00000000 / 0x00000000 | DATA115[31:24] (RW)（Huffman 表数据 115）、DATA114[23:16] (RW)（Huffman 表数据 114）、DATA113[15:8] (RW)（Huffman 表数据 113）、DATA112[7:0] (RW)（Huffman 表数据 112） | — |
| `JPEG_DHTMEM29` | JPEG DHT 存储器 | `0x3D4` | `0x520033D4` | 32 | — | 0x00000000 / 0x00000000 | DATA119[31:24] (RW)（Huffman 表数据 119）、DATA118[23:16] (RW)（Huffman 表数据 118）、DATA117[15:8] (RW)（Huffman 表数据 117）、DATA116[7:0] (RW)（Huffman 表数据 116） | — |
| `JPEG_DHTMEM30` | JPEG DHT 存储器 | `0x3D8` | `0x520033D8` | 32 | — | 0x00000000 / 0x00000000 | DATA123[31:24] (RW)（Huffman 表数据 123）、DATA122[23:16] (RW)（Huffman 表数据 122）、DATA121[15:8] (RW)（Huffman 表数据 121）、DATA120[7:0] (RW)（Huffman 表数据 120） | — |
| `JPEG_DHTMEM31` | JPEG DHT 存储器 | `0x3DC` | `0x520033DC` | 32 | — | 0x00000000 / 0x00000000 | DATA127[31:24] (RW)（Huffman 表数据 127）、DATA126[23:16] (RW)（Huffman 表数据 126）、DATA125[15:8] (RW)（Huffman 表数据 125）、DATA124[7:0] (RW)（Huffman 表数据 124） | — |
| `JPEG_DHTMEM32` | JPEG DHT 存储器 | `0x3E0` | `0x520033E0` | 32 | — | 0x00000000 / 0x00000000 | DATA131[31:24] (RW)（Huffman 表数据 131）、DATA130[23:16] (RW)（Huffman 表数据 130）、DATA129[15:8] (RW)（Huffman 表数据 129）、DATA128[7:0] (RW)（Huffman 表数据 128） | — |
| `JPEG_DHTMEM33` | JPEG DHT 存储器 | `0x3E4` | `0x520033E4` | 32 | — | 0x00000000 / 0x00000000 | DATA135[31:24] (RW)（Huffman 表数据 135）、DATA134[23:16] (RW)（Huffman 表数据 134）、DATA133[15:8] (RW)（Huffman 表数据 133）、DATA132[7:0] (RW)（Huffman 表数据 132） | — |
| `JPEG_DHTMEM34` | JPEG DHT 存储器 | `0x3E8` | `0x520033E8` | 32 | — | 0x00000000 / 0x00000000 | DATA139[31:24] (RW)（Huffman 表数据 139）、DATA138[23:16] (RW)（Huffman 表数据 138）、DATA137[15:8] (RW)（Huffman 表数据 137）、DATA136[7:0] (RW)（Huffman 表数据 136） | — |
| `JPEG_DHTMEM35` | JPEG DHT 存储器 | `0x3EC` | `0x520033EC` | 32 | — | 0x00000000 / 0x00000000 | DATA143[31:24] (RW)（Huffman 表数据 143）、DATA142[23:16] (RW)（Huffman 表数据 142）、DATA141[15:8] (RW)（Huffman 表数据 141）、DATA140[7:0] (RW)（Huffman 表数据 140） | — |
| `JPEG_DHTMEM36` | JPEG DHT 存储器 | `0x3F0` | `0x520033F0` | 32 | — | 0x00000000 / 0x00000000 | DATA147[31:24] (RW)（Huffman 表数据 147）、DATA146[23:16] (RW)（Huffman 表数据 146）、DATA145[15:8] (RW)（Huffman 表数据 145）、DATA144[7:0] (RW)（Huffman 表数据 144） | — |
| `JPEG_DHTMEM37` | JPEG DHT 存储器 | `0x3F4` | `0x520033F4` | 32 | — | 0x00000000 / 0x00000000 | DATA151[31:24] (RW)（Huffman 表数据 151）、DATA150[23:16] (RW)（Huffman 表数据 150）、DATA149[15:8] (RW)（Huffman 表数据 149）、DATA148[7:0] (RW)（Huffman 表数据 148） | — |
| `JPEG_DHTMEM38` | JPEG DHT 存储器 | `0x3F8` | `0x520033F8` | 32 | — | 0x00000000 / 0x00000000 | DATA155[31:24] (RW)（Huffman 表数据 155）、DATA154[23:16] (RW)（Huffman 表数据 154）、DATA153[15:8] (RW)（Huffman 表数据 153）、DATA152[7:0] (RW)（Huffman 表数据 152） | — |
| `JPEG_DHTMEM39` | JPEG DHT 存储器 | `0x3FC` | `0x520033FC` | 32 | — | 0x00000000 / 0x00000000 | DATA159[31:24] (RW)（Huffman 表数据 159）、DATA158[23:16] (RW)（Huffman 表数据 158）、DATA157[15:8] (RW)（Huffman 表数据 157）、DATA156[7:0] (RW)（Huffman 表数据 156） | — |
| `JPEG_DHTMEM40` | JPEG DHT 存储器 | `0x400` | `0x52003400` | 32 | — | 0x00000000 / 0x00000000 | DATA163[31:24] (RW)（Huffman 表数据 163）、DATA162[23:16] (RW)（Huffman 表数据 162）、DATA161[15:8] (RW)（Huffman 表数据 161）、DATA160[7:0] (RW)（Huffman 表数据 160） | — |
| `JPEG_DHTMEM41` | JPEG DHT 存储器 | `0x404` | `0x52003404` | 32 | — | 0x00000000 / 0x00000000 | DATA167[31:24] (RW)（Huffman 表数据 167）、DATA166[23:16] (RW)（Huffman 表数据 166）、DATA165[15:8] (RW)（Huffman 表数据 165）、DATA164[7:0] (RW)（Huffman 表数据 164） | — |
| `JPEG_DHTMEM42` | JPEG DHT 存储器 | `0x408` | `0x52003408` | 32 | — | 0x00000000 / 0x00000000 | DATA171[31:24] (RW)（Huffman 表数据 171）、DATA170[23:16] (RW)（Huffman 表数据 170）、DATA169[15:8] (RW)（Huffman 表数据 169）、DATA168[7:0] (RW)（Huffman 表数据 168） | — |
| `JPEG_DHTMEM43` | JPEG DHT 存储器 | `0x40C` | `0x5200340C` | 32 | — | 0x00000000 / 0x00000000 | DATA175[31:24] (RW)（Huffman 表数据 175）、DATA174[23:16] (RW)（Huffman 表数据 174）、DATA173[15:8] (RW)（Huffman 表数据 173）、DATA172[7:0] (RW)（Huffman 表数据 172） | — |
| `JPEG_DHTMEM44` | JPEG DHT 存储器 | `0x410` | `0x52003410` | 32 | — | 0x00000000 / 0x00000000 | DATA179[31:24] (RW)（Huffman 表数据 179）、DATA178[23:16] (RW)（Huffman 表数据 178）、DATA177[15:8] (RW)（Huffman 表数据 177）、DATA176[7:0] (RW)（Huffman 表数据 176） | — |
| `JPEG_DHTMEM45` | JPEG DHT 存储器 | `0x414` | `0x52003414` | 32 | — | 0x00000000 / 0x00000000 | DATA183[31:24] (RW)（Huffman 表数据 183）、DATA182[23:16] (RW)（Huffman 表数据 182）、DATA181[15:8] (RW)（Huffman 表数据 181）、DATA180[7:0] (RW)（Huffman 表数据 180） | — |
| `JPEG_DHTMEM46` | JPEG DHT 存储器 | `0x418` | `0x52003418` | 32 | — | 0x00000000 / 0x00000000 | DATA187[31:24] (RW)（Huffman 表数据 187）、DATA186[23:16] (RW)（Huffman 表数据 186）、DATA185[15:8] (RW)（Huffman 表数据 185）、DATA184[7:0] (RW)（Huffman 表数据 184） | — |
| `JPEG_DHTMEM47` | JPEG DHT 存储器 | `0x41C` | `0x5200341C` | 32 | — | 0x00000000 / 0x00000000 | DATA191[31:24] (RW)（Huffman 表数据 191）、DATA190[23:16] (RW)（Huffman 表数据 190）、DATA189[15:8] (RW)（Huffman 表数据 189）、DATA188[7:0] (RW)（Huffman 表数据 188） | — |
| `JPEG_DHTMEM48` | JPEG DHT 存储器 | `0x420` | `0x52003420` | 32 | — | 0x00000000 / 0x00000000 | DATA195[31:24] (RW)（Huffman 表数据 195）、DATA194[23:16] (RW)（Huffman 表数据 194）、DATA193[15:8] (RW)（Huffman 表数据 193）、DATA192[7:0] (RW)（Huffman 表数据 192） | — |
| `JPEG_DHTMEM49` | JPEG DHT 存储器 | `0x424` | `0x52003424` | 32 | — | 0x00000000 / 0x00000000 | DATA199[31:24] (RW)（Huffman 表数据 199）、DATA198[23:16] (RW)（Huffman 表数据 198）、DATA197[15:8] (RW)（Huffman 表数据 197）、DATA196[7:0] (RW)（Huffman 表数据 196） | — |
| `JPEG_DHTMEM50` | JPEG DHT 存储器 | `0x428` | `0x52003428` | 32 | — | 0x00000000 / 0x00000000 | DATA203[31:24] (RW)（Huffman 表数据 203）、DATA202[23:16] (RW)（Huffman 表数据 202）、DATA201[15:8] (RW)（Huffman 表数据 201）、DATA200[7:0] (RW)（Huffman 表数据 200） | — |
| `JPEG_DHTMEM51` | JPEG DHT 存储器 | `0x42C` | `0x5200342C` | 32 | — | 0x00000000 / 0x00000000 | DATA207[31:24] (RW)（Huffman 表数据 207）、DATA206[23:16] (RW)（Huffman 表数据 206）、DATA205[15:8] (RW)（Huffman 表数据 205）、DATA204[7:0] (RW)（Huffman 表数据 204） | — |
| `JPEG_DHTMEM52` | JPEG DHT 存储器 | `0x430` | `0x52003430` | 32 | — | 0x00000000 / 0x00000000 | DATA211[31:24] (RW)（Huffman 表数据 211）、DATA210[23:16] (RW)（Huffman 表数据 210）、DATA209[15:8] (RW)（Huffman 表数据 209）、DATA208[7:0] (RW)（Huffman 表数据 208） | — |
| `JPEG_DHTMEM53` | JPEG DHT 存储器 | `0x434` | `0x52003434` | 32 | — | 0x00000000 / 0x00000000 | DATA215[31:24] (RW)（Huffman 表数据 215）、DATA214[23:16] (RW)（Huffman 表数据 214）、DATA213[15:8] (RW)（Huffman 表数据 213）、DATA212[7:0] (RW)（Huffman 表数据 212） | — |
| `JPEG_DHTMEM54` | JPEG DHT 存储器 | `0x438` | `0x52003438` | 32 | — | 0x00000000 / 0x00000000 | DATA219[31:24] (RW)（Huffman 表数据 219）、DATA218[23:16] (RW)（Huffman 表数据 218）、DATA217[15:8] (RW)（Huffman 表数据 217）、DATA216[7:0] (RW)（Huffman 表数据 216） | — |
| `JPEG_DHTMEM55` | JPEG DHT 存储器 | `0x43C` | `0x5200343C` | 32 | — | 0x00000000 / 0x00000000 | DATA223[31:24] (RW)（Huffman 表数据 223）、DATA222[23:16] (RW)（Huffman 表数据 222）、DATA221[15:8] (RW)（Huffman 表数据 221）、DATA220[7:0] (RW)（Huffman 表数据 220） | — |
| `JPEG_DHTMEM56` | JPEG DHT 存储器 | `0x440` | `0x52003440` | 32 | — | 0x00000000 / 0x00000000 | DATA227[31:24] (RW)（Huffman 表数据 227）、DATA226[23:16] (RW)（Huffman 表数据 226）、DATA225[15:8] (RW)（Huffman 表数据 225）、DATA224[7:0] (RW)（Huffman 表数据 224） | — |
| `JPEG_DHTMEM57` | JPEG DHT 存储器 | `0x444` | `0x52003444` | 32 | — | 0x00000000 / 0x00000000 | DATA231[31:24] (RW)（Huffman 表数据 231）、DATA230[23:16] (RW)（Huffman 表数据 230）、DATA229[15:8] (RW)（Huffman 表数据 229）、DATA228[7:0] (RW)（Huffman 表数据 228） | — |
| `JPEG_DHTMEM58` | JPEG DHT 存储器 | `0x448` | `0x52003448` | 32 | — | 0x00000000 / 0x00000000 | DATA235[31:24] (RW)（Huffman 表数据 235）、DATA234[23:16] (RW)（Huffman 表数据 234）、DATA233[15:8] (RW)（Huffman 表数据 233）、DATA232[7:0] (RW)（Huffman 表数据 232） | — |
| `JPEG_DHTMEM59` | JPEG DHT 存储器 | `0x44C` | `0x5200344C` | 32 | — | 0x00000000 / 0x00000000 | DATA239[31:24] (RW)（Huffman 表数据 239）、DATA238[23:16] (RW)（Huffman 表数据 238）、DATA237[15:8] (RW)（Huffman 表数据 237）、DATA236[7:0] (RW)（Huffman 表数据 236） | — |
| `JPEG_DHTMEM60` | JPEG DHT 存储器 | `0x450` | `0x52003450` | 32 | — | 0x00000000 / 0x00000000 | DATA243[31:24] (RW)（Huffman 表数据 243）、DATA242[23:16] (RW)（Huffman 表数据 242）、DATA241[15:8] (RW)（Huffman 表数据 241）、DATA240[7:0] (RW)（Huffman 表数据 240） | — |
| `JPEG_DHTMEM61` | JPEG DHT 存储器 | `0x454` | `0x52003454` | 32 | — | 0x00000000 / 0x00000000 | DATA247[31:24] (RW)（Huffman 表数据 247）、DATA246[23:16] (RW)（Huffman 表数据 246）、DATA245[15:8] (RW)（Huffman 表数据 245）、DATA244[7:0] (RW)（Huffman 表数据 244） | — |
| `JPEG_DHTMEM62` | JPEG DHT 存储器 | `0x458` | `0x52003458` | 32 | — | 0x00000000 / 0x00000000 | DATA251[31:24] (RW)（Huffman 表数据 251）、DATA250[23:16] (RW)（Huffman 表数据 250）、DATA249[15:8] (RW)（Huffman 表数据 249）、DATA248[7:0] (RW)（Huffman 表数据 248） | — |
| `JPEG_DHTMEM63` | JPEG DHT 存储器 | `0x45C` | `0x5200345C` | 32 | — | 0x00000000 / 0x00000000 | DATA255[31:24] (RW)（Huffman 表数据 255）、DATA254[23:16] (RW)（Huffman 表数据 254）、DATA253[15:8] (RW)（Huffman 表数据 253）、DATA252[7:0] (RW)（Huffman 表数据 252） | — |
| `JPEG_DHTMEM64` | JPEG DHT 存储器 | `0x460` | `0x52003460` | 32 | — | 0x00000000 / 0x00000000 | DATA259[31:24] (RW)（Huffman 表数据 259）、DATA258[23:16] (RW)（Huffman 表数据 258）、DATA257[15:8] (RW)（Huffman 表数据 257）、DATA256[7:0] (RW)（Huffman 表数据 256） | — |
| `JPEG_DHTMEM65` | JPEG DHT 存储器 | `0x464` | `0x52003464` | 32 | — | 0x00000000 / 0x00000000 | DATA263[31:24] (RW)（Huffman 表数据 263）、DATA262[23:16] (RW)（Huffman 表数据 262）、DATA261[15:8] (RW)（Huffman 表数据 261）、DATA260[7:0] (RW)（Huffman 表数据 260） | — |
| `JPEG_DHTMEM66` | JPEG DHT 存储器 | `0x468` | `0x52003468` | 32 | — | 0x00000000 / 0x00000000 | DATA267[31:24] (RW)（Huffman 表数据 267）、DATA266[23:16] (RW)（Huffman 表数据 266）、DATA265[15:8] (RW)（Huffman 表数据 265）、DATA264[7:0] (RW)（Huffman 表数据 264） | — |
| `JPEG_DHTMEM67` | JPEG DHT 存储器 | `0x46C` | `0x5200346C` | 32 | — | 0x00000000 / 0x00000000 | DATA271[31:24] (RW)（Huffman 表数据 271）、DATA270[23:16] (RW)（Huffman 表数据 270）、DATA269[15:8] (RW)（Huffman 表数据 269）、DATA268[7:0] (RW)（Huffman 表数据 268） | — |
| `JPEG_DHTMEM68` | JPEG DHT 存储器 | `0x470` | `0x52003470` | 32 | — | 0x00000000 / 0x00000000 | DATA275[31:24] (RW)（Huffman 表数据 275）、DATA274[23:16] (RW)（Huffman 表数据 274）、DATA273[15:8] (RW)（Huffman 表数据 273）、DATA272[7:0] (RW)（Huffman 表数据 272） | — |
| `JPEG_DHTMEM69` | JPEG DHT 存储器 | `0x474` | `0x52003474` | 32 | — | 0x00000000 / 0x00000000 | DATA279[31:24] (RW)（Huffman 表数据 279）、DATA278[23:16] (RW)（Huffman 表数据 278）、DATA277[15:8] (RW)（Huffman 表数据 277）、DATA276[7:0] (RW)（Huffman 表数据 276） | — |
| `JPEG_DHTMEM70` | JPEG DHT 存储器 | `0x478` | `0x52003478` | 32 | — | 0x00000000 / 0x00000000 | DATA283[31:24] (RW)（Huffman 表数据 283）、DATA282[23:16] (RW)（Huffman 表数据 282）、DATA281[15:8] (RW)（Huffman 表数据 281）、DATA280[7:0] (RW)（Huffman 表数据 280） | — |
| `JPEG_DHTMEM71` | JPEG DHT 存储器 | `0x47C` | `0x5200347C` | 32 | — | 0x00000000 / 0x00000000 | DATA287[31:24] (RW)（Huffman 表数据 287）、DATA286[23:16] (RW)（Huffman 表数据 286）、DATA285[15:8] (RW)（Huffman 表数据 285）、DATA284[7:0] (RW)（Huffman 表数据 284） | — |
| `JPEG_DHTMEM72` | JPEG DHT 存储器 | `0x480` | `0x52003480` | 32 | — | 0x00000000 / 0x00000000 | DATA291[31:24] (RW)（Huffman 表数据 291）、DATA290[23:16] (RW)（Huffman 表数据 290）、DATA289[15:8] (RW)（Huffman 表数据 289）、DATA288[7:0] (RW)（Huffman 表数据 288） | — |
| `JPEG_DHTMEM73` | JPEG DHT 存储器 | `0x484` | `0x52003484` | 32 | — | 0x00000000 / 0x00000000 | DATA295[31:24] (RW)（Huffman 表数据 295）、DATA294[23:16] (RW)（Huffman 表数据 294）、DATA293[15:8] (RW)（Huffman 表数据 293）、DATA292[7:0] (RW)（Huffman 表数据 292） | — |
| `JPEG_DHTMEM74` | JPEG DHT 存储器 | `0x488` | `0x52003488` | 32 | — | 0x00000000 / 0x00000000 | DATA299[31:24] (RW)（Huffman 表数据 299）、DATA298[23:16] (RW)（Huffman 表数据 298）、DATA297[15:8] (RW)（Huffman 表数据 297）、DATA296[7:0] (RW)（Huffman 表数据 296） | — |
| `JPEG_DHTMEM75` | JPEG DHT 存储器 | `0x48C` | `0x5200348C` | 32 | — | 0x00000000 / 0x00000000 | DATA303[31:24] (RW)（Huffman 表数据 303）、DATA302[23:16] (RW)（Huffman 表数据 302）、DATA301[15:8] (RW)（Huffman 表数据 301）、DATA300[7:0] (RW)（Huffman 表数据 300） | — |
| `JPEG_DHTMEM76` | JPEG DHT 存储器 | `0x490` | `0x52003490` | 32 | — | 0x00000000 / 0x00000000 | DATA307[31:24] (RW)（Huffman 表数据 307）、DATA306[23:16] (RW)（Huffman 表数据 306）、DATA305[15:8] (RW)（Huffman 表数据 305）、DATA304[7:0] (RW)（Huffman 表数据 304） | — |
| `JPEG_DHTMEM77` | JPEG DHT 存储器 | `0x494` | `0x52003494` | 32 | — | 0x00000000 / 0x00000000 | DATA311[31:24] (RW)（Huffman 表数据 311）、DATA310[23:16] (RW)（Huffman 表数据 310）、DATA309[15:8] (RW)（Huffman 表数据 309）、DATA308[7:0] (RW)（Huffman 表数据 308） | — |
| `JPEG_DHTMEM78` | JPEG DHT 存储器 | `0x498` | `0x52003498` | 32 | — | 0x00000000 / 0x00000000 | DATA315[31:24] (RW)（Huffman 表数据 315）、DATA314[23:16] (RW)（Huffman 表数据 314）、DATA313[15:8] (RW)（Huffman 表数据 313）、DATA312[7:0] (RW)（Huffman 表数据 312） | — |
| `JPEG_DHTMEM79` | JPEG DHT 存储器 | `0x49C` | `0x5200349C` | 32 | — | 0x00000000 / 0x00000000 | DATA319[31:24] (RW)（Huffman 表数据 319）、DATA318[23:16] (RW)（Huffman 表数据 318）、DATA317[15:8] (RW)（Huffman 表数据 317）、DATA316[7:0] (RW)（Huffman 表数据 316） | — |
| `JPEG_DHTMEM80` | JPEG DHT 存储器 | `0x4A0` | `0x520034A0` | 32 | — | 0x00000000 / 0x00000000 | DATA323[31:24] (RW)（Huffman 表数据 323）、DATA322[23:16] (RW)（Huffman 表数据 322）、DATA321[15:8] (RW)（Huffman 表数据 321）、DATA320[7:0] (RW)（Huffman 表数据 320） | — |
| `JPEG_DHTMEM81` | JPEG DHT 存储器 | `0x4A4` | `0x520034A4` | 32 | — | 0x00000000 / 0x00000000 | DATA327[31:24] (RW)（Huffman 表数据 327）、DATA326[23:16] (RW)（Huffman 表数据 326）、DATA325[15:8] (RW)（Huffman 表数据 325）、DATA324[7:0] (RW)（Huffman 表数据 324） | — |
| `JPEG_DHTMEM82` | JPEG DHT 存储器 | `0x4A8` | `0x520034A8` | 32 | — | 0x00000000 / 0x00000000 | DATA331[31:24] (RW)（Huffman 表数据 331）、DATA330[23:16] (RW)（Huffman 表数据 330）、DATA329[15:8] (RW)（Huffman 表数据 329）、DATA328[7:0] (RW)（Huffman 表数据 328） | — |
| `JPEG_DHTMEM83` | JPEG DHT 存储器 | `0x4AC` | `0x520034AC` | 32 | — | 0x00000000 / 0x00000000 | DATA335[31:24] (RW)（Huffman 表数据 335）、DATA334[23:16] (RW)（Huffman 表数据 334）、DATA333[15:8] (RW)（Huffman 表数据 333）、DATA332[7:0] (RW)（Huffman 表数据 332） | — |
| `JPEG_DHTMEM84` | JPEG DHT 存储器 | `0x4B0` | `0x520034B0` | 32 | — | 0x00000000 / 0x00000000 | DATA339[31:24] (RW)（Huffman 表数据 339）、DATA338[23:16] (RW)（Huffman 表数据 338）、DATA337[15:8] (RW)（Huffman 表数据 337）、DATA336[7:0] (RW)（Huffman 表数据 336） | — |
| `JPEG_DHTMEM85` | JPEG DHT 存储器 | `0x4B4` | `0x520034B4` | 32 | — | 0x00000000 / 0x00000000 | DATA343[31:24] (RW)（Huffman 表数据 343）、DATA342[23:16] (RW)（Huffman 表数据 342）、DATA341[15:8] (RW)（Huffman 表数据 341）、DATA340[7:0] (RW)（Huffman 表数据 340） | — |
| `JPEG_DHTMEM86` | JPEG DHT 存储器 | `0x4B8` | `0x520034B8` | 32 | — | 0x00000000 / 0x00000000 | DATA347[31:24] (RW)（Huffman 表数据 347）、DATA346[23:16] (RW)（Huffman 表数据 346）、DATA345[15:8] (RW)（Huffman 表数据 345）、DATA344[7:0] (RW)（Huffman 表数据 344） | — |
| `JPEG_DHTMEM87` | JPEG DHT 存储器 | `0x4BC` | `0x520034BC` | 32 | — | 0x00000000 / 0x00000000 | DATA351[31:24] (RW)（Huffman 表数据 351）、DATA350[23:16] (RW)（Huffman 表数据 350）、DATA349[15:8] (RW)（Huffman 表数据 349）、DATA348[7:0] (RW)（Huffman 表数据 348） | — |
| `JPEG_DHTMEM88` | JPEG DHT 存储器 | `0x4C0` | `0x520034C0` | 32 | — | 0x00000000 / 0x00000000 | DATA355[31:24] (RW)（Huffman 表数据 355）、DATA354[23:16] (RW)（Huffman 表数据 354）、DATA353[15:8] (RW)（Huffman 表数据 353）、DATA352[7:0] (RW)（Huffman 表数据 352） | — |
| `JPEG_DHTMEM89` | JPEG DHT 存储器 | `0x4C4` | `0x520034C4` | 32 | — | 0x00000000 / 0x00000000 | DATA359[31:24] (RW)（Huffman 表数据 359）、DATA358[23:16] (RW)（Huffman 表数据 358）、DATA357[15:8] (RW)（Huffman 表数据 357）、DATA356[7:0] (RW)（Huffman 表数据 356） | — |
| `JPEG_DHTMEM90` | JPEG DHT 存储器 | `0x4C8` | `0x520034C8` | 32 | — | 0x00000000 / 0x00000000 | DATA363[31:24] (RW)（Huffman 表数据 363）、DATA362[23:16] (RW)（Huffman 表数据 362）、DATA361[15:8] (RW)（Huffman 表数据 361）、DATA360[7:0] (RW)（Huffman 表数据 360） | — |
| `JPEG_DHTMEM91` | JPEG DHT 存储器 | `0x4CC` | `0x520034CC` | 32 | — | 0x00000000 / 0x00000000 | DATA367[31:24] (RW)（Huffman 表数据 367）、DATA366[23:16] (RW)（Huffman 表数据 366）、DATA365[15:8] (RW)（Huffman 表数据 365）、DATA364[7:0] (RW)（Huffman 表数据 364） | — |
| `JPEG_DHTMEM92` | JPEG DHT 存储器 | `0x4D0` | `0x520034D0` | 32 | — | 0x00000000 / 0x00000000 | DATA371[31:24] (RW)（Huffman 表数据 371）、DATA370[23:16] (RW)（Huffman 表数据 370）、DATA369[15:8] (RW)（Huffman 表数据 369）、DATA368[7:0] (RW)（Huffman 表数据 368） | — |
| `JPEG_DHTMEM93` | JPEG DHT 存储器 | `0x4D4` | `0x520034D4` | 32 | — | 0x00000000 / 0x00000000 | DATA375[31:24] (RW)（Huffman 表数据 375）、DATA374[23:16] (RW)（Huffman 表数据 374）、DATA373[15:8] (RW)（Huffman 表数据 373）、DATA372[7:0] (RW)（Huffman 表数据 372） | — |
| `JPEG_DHTMEM94` | JPEG DHT 存储器 | `0x4D8` | `0x520034D8` | 32 | — | 0x00000000 / 0x00000000 | DATA379[31:24] (RW)（Huffman 表数据 379）、DATA378[23:16] (RW)（Huffman 表数据 378）、DATA377[15:8] (RW)（Huffman 表数据 377）、DATA376[7:0] (RW)（Huffman 表数据 376） | — |
| `JPEG_DHTMEM95` | JPEG DHT 存储器 | `0x4DC` | `0x520034DC` | 32 | — | 0x00000000 / 0x00000000 | DATA383[31:24] (RW)（Huffman 表数据 383）、DATA382[23:16] (RW)（Huffman 表数据 382）、DATA381[15:8] (RW)（Huffman 表数据 381）、DATA380[7:0] (RW)（Huffman 表数据 380） | — |
| `JPEG_DHTMEM96` | JPEG DHT 存储器 | `0x4E0` | `0x520034E0` | 32 | — | 0x00000000 / 0x00000000 | DATA387[31:24] (RW)（Huffman 表数据 387）、DATA386[23:16] (RW)（Huffman 表数据 386）、DATA385[15:8] (RW)（Huffman 表数据 385）、DATA384[7:0] (RW)（Huffman 表数据 384） | — |
| `JPEG_DHTMEM97` | JPEG DHT 存储器 | `0x4E4` | `0x520034E4` | 32 | — | 0x00000000 / 0x00000000 | DATA391[31:24] (RW)（Huffman 表数据 391）、DATA390[23:16] (RW)（Huffman 表数据 390）、DATA389[15:8] (RW)（Huffman 表数据 389）、DATA388[7:0] (RW)（Huffman 表数据 388） | — |
| `JPEG_DHTMEM98` | JPEG DHT 存储器 | `0x4E8` | `0x520034E8` | 32 | — | 0x00000000 / 0x00000000 | DATA395[31:24] (RW)（Huffman 表数据 395）、DATA394[23:16] (RW)（Huffman 表数据 394）、DATA393[15:8] (RW)（Huffman 表数据 393）、DATA392[7:0] (RW)（Huffman 表数据 392） | — |
| `JPEG_DHTMEM99` | JPEG DHT 存储器 | `0x4EC` | `0x520034EC` | 32 | — | 0x00000000 / 0x00000000 | DATA399[31:24] (RW)（Huffman 表数据 399）、DATA398[23:16] (RW)（Huffman 表数据 398）、DATA397[15:8] (RW)（Huffman 表数据 397）、DATA396[7:0] (RW)（Huffman 表数据 396） | — |
| `JPEG_DHTMEM100` | JPEG DHT 存储器 | `0x4F0` | `0x520034F0` | 32 | — | 0x00000000 / 0x00000000 | DATA403[31:24] (RW)（Huffman 表数据 403）、DATA402[23:16] (RW)（Huffman 表数据 402）、DATA401[15:8] (RW)（Huffman 表数据 401）、DATA400[7:0] (RW)（Huffman 表数据 400） | — |
| `JPEG_DHTMEM101` | JPEG DHT 存储器 | `0x4F4` | `0x520034F4` | 32 | — | 0x00000000 / 0x00000000 | DATA407[31:24] (RW)（Huffman 表数据 407）、DATA406[23:16] (RW)（Huffman 表数据 406）、DATA405[15:8] (RW)（Huffman 表数据 405）、DATA404[7:0] (RW)（Huffman 表数据 404） | — |
| `JPEG_DHTMEM102` | JPEG DHT 存储器 | `0x4F8` | `0x520034F8` | 32 | — | 0x00000000 / 0x00000000 | DATA411[31:24] (RW)（Huffman 表数据 411）、DATA410[23:16] (RW)（Huffman 表数据 410）、DATA409[15:8] (RW)（Huffman 表数据 409）、DATA408[7:0] (RW)（Huffman 表数据 408） | — |
| `JPEG_HUFFENC_AC0_0` | JPEG Huffman 编码器 AC0 | `0x500` | `0x52003500` | 32 | — | 0x00000000 / 0x00000000 | HLEN1[27:24] (RW)（Huffman 长度 1）、HCODE1[23:16] (RW)（Huffman 编码 1）、HLEN0[11:8] (RW)（Huffman 长度 0）、HCODE0[7:0] (RW)（Huffman 编码 0） | — |
| `JPEG_HUFFENC_AC0_1` | JPEG Huffman 编码器 AC0 | `0x504` | `0x52003504` | 32 | — | 0x00000000 / 0x00000000 | HLEN3[27:24] (RW)（Huffman 长度 3）、HCODE3[23:16] (RW)（Huffman 编码 3）、HLEN2[11:8] (RW)（Huffman 长度 2）、HCODE2[7:0] (RW)（Huffman 编码 2） | — |
| `JPEG_HUFFENC_AC0_2` | JPEG Huffman 编码器 AC0 | `0x508` | `0x52003508` | 32 | — | 0x00000000 / 0x00000000 | HLEN5[27:24] (RW)（Huffman 长度 5）、HCODE5[23:16] (RW)（Huffman 编码 5）、HLEN4[11:8] (RW)（Huffman 长度 4）、HCODE4[7:0] (RW)（Huffman 编码 4） | — |
| `JPEG_HUFFENC_AC0_3` | JPEG Huffman 编码器 AC0 | `0x50C` | `0x5200350C` | 32 | — | 0x00000000 / 0x00000000 | HLEN7[27:24] (RW)（Huffman 长度 7）、HCODE7[23:16] (RW)（Huffman 编码 7）、HLEN6[11:8] (RW)（Huffman 长度 6）、HCODE6[7:0] (RW)（Huffman 编码 6） | — |
| `JPEG_HUFFENC_AC0_4` | JPEG Huffman 编码器 AC0 | `0x510` | `0x52003510` | 32 | — | 0x00000000 / 0x00000000 | HLEN9[27:24] (RW)（Huffman 长度 9）、HCODE9[23:16] (RW)（Huffman 编码 9）、HLEN8[11:8] (RW)（Huffman 长度 8）、HCODE8[7:0] (RW)（Huffman 编码 8） | — |
| `JPEG_HUFFENC_AC0_5` | JPEG Huffman 编码器 AC0 | `0x514` | `0x52003514` | 32 | — | 0x00000000 / 0x00000000 | HLEN11[27:24] (RW)（Huffman 长度 11）、HCODE11[23:16] (RW)（Huffman 编码 11）、HLEN10[11:8] (RW)（Huffman 长度 10）、HCODE10[7:0] (RW)（Huffman 编码 10） | — |
| `JPEG_HUFFENC_AC0_6` | JPEG Huffman 编码器 AC0 | `0x518` | `0x52003518` | 32 | — | 0x00000000 / 0x00000000 | HLEN13[27:24] (RW)（Huffman 长度 13）、HCODE13[23:16] (RW)（Huffman 编码 13）、HLEN12[11:8] (RW)（Huffman 长度 12）、HCODE12[7:0] (RW)（Huffman 编码 12） | — |
| `JPEG_HUFFENC_AC0_7` | JPEG Huffman 编码器 AC0 | `0x51C` | `0x5200351C` | 32 | — | 0x00000000 / 0x00000000 | HLEN15[27:24] (RW)（Huffman 长度 15）、HCODE15[23:16] (RW)（Huffman 编码 15）、HLEN14[11:8] (RW)（Huffman 长度 14）、HCODE14[7:0] (RW)（Huffman 编码 14） | — |
| `JPEG_HUFFENC_AC0_8` | JPEG Huffman 编码器 AC0 | `0x520` | `0x52003520` | 32 | — | 0x00000000 / 0x00000000 | HLEN17[27:24] (RW)（Huffman 长度 17）、HCODE17[23:16] (RW)（Huffman 编码 17）、HLEN16[11:8] (RW)（Huffman 长度 16）、HCODE16[7:0] (RW)（Huffman 编码 16） | — |
| `JPEG_HUFFENC_AC0_9` | JPEG Huffman 编码器 AC0 | `0x524` | `0x52003524` | 32 | — | 0x00000000 / 0x00000000 | HLEN19[27:24] (RW)（Huffman 长度 19）、HCODE19[23:16] (RW)（Huffman 编码 19）、HLEN18[11:8] (RW)（Huffman 长度 18）、HCODE18[7:0] (RW)（Huffman 编码 18） | — |
| `JPEG_HUFFENC_AC0_10` | JPEG Huffman 编码器 AC0 | `0x528` | `0x52003528` | 32 | — | 0x00000000 / 0x00000000 | HLEN21[27:24] (RW)（Huffman 长度 21）、HCODE21[23:16] (RW)（Huffman 编码 21）、HLEN20[11:8] (RW)（Huffman 长度 20）、HCODE20[7:0] (RW)（Huffman 编码 20） | — |
| `JPEG_HUFFENC_AC0_11` | JPEG Huffman 编码器 AC0 | `0x52C` | `0x5200352C` | 32 | — | 0x00000000 / 0x00000000 | HLEN23[27:24] (RW)（Huffman 长度 23）、HCODE23[23:16] (RW)（Huffman 编码 23）、HLEN22[11:8] (RW)（Huffman 长度 22）、HCODE22[7:0] (RW)（Huffman 编码 22） | — |
| `JPEG_HUFFENC_AC0_12` | JPEG Huffman 编码器 AC0 | `0x530` | `0x52003530` | 32 | — | 0x00000000 / 0x00000000 | HLEN25[27:24] (RW)（Huffman 长度 25）、HCODE25[23:16] (RW)（Huffman 编码 25）、HLEN24[11:8] (RW)（Huffman 长度 24）、HCODE24[7:0] (RW)（Huffman 编码 24） | — |
| `JPEG_HUFFENC_AC0_13` | JPEG Huffman 编码器 AC0 | `0x534` | `0x52003534` | 32 | — | 0x00000000 / 0x00000000 | HLEN27[27:24] (RW)（Huffman 长度 27）、HCODE27[23:16] (RW)（Huffman 编码 27）、HLEN26[11:8] (RW)（Huffman 长度 26）、HCODE26[7:0] (RW)（Huffman 编码 26） | — |
| `JPEG_HUFFENC_AC0_14` | JPEG Huffman 编码器 AC0 | `0x538` | `0x52003538` | 32 | — | 0x00000000 / 0x00000000 | HLEN29[27:24] (RW)（Huffman 长度 29）、HCODE29[23:16] (RW)（Huffman 编码 29）、HLEN28[11:8] (RW)（Huffman 长度 28）、HCODE28[7:0] (RW)（Huffman 编码 28） | — |
| `JPEG_HUFFENC_AC0_15` | JPEG Huffman 编码器 AC0 | `0x53C` | `0x5200353C` | 32 | — | 0x00000000 / 0x00000000 | HLEN31[27:24] (RW)（Huffman 长度 31）、HCODE31[23:16] (RW)（Huffman 编码 31）、HLEN30[11:8] (RW)（Huffman 长度 30）、HCODE30[7:0] (RW)（Huffman 编码 30） | — |
| `JPEG_HUFFENC_AC0_16` | JPEG Huffman 编码器 AC0 | `0x540` | `0x52003540` | 32 | — | 0x00000000 / 0x00000000 | HLEN33[27:24] (RW)（Huffman 长度 33）、HCODE33[23:16] (RW)（Huffman 编码 33）、HLEN32[11:8] (RW)（Huffman 长度 32）、HCODE32[7:0] (RW)（Huffman 编码 32） | — |
| `JPEG_HUFFENC_AC0_17` | JPEG Huffman 编码器 AC0 | `0x544` | `0x52003544` | 32 | — | 0x00000000 / 0x00000000 | HLEN35[27:24] (RW)（Huffman 长度 35）、HCODE35[23:16] (RW)（Huffman 编码 35）、HLEN34[11:8] (RW)（Huffman 长度 34）、HCODE34[7:0] (RW)（Huffman 编码 34） | — |
| `JPEG_HUFFENC_AC0_18` | JPEG Huffman 编码器 AC0 | `0x548` | `0x52003548` | 32 | — | 0x00000000 / 0x00000000 | HLEN37[27:24] (RW)（Huffman 长度 37）、HCODE37[23:16] (RW)（Huffman 编码 37）、HLEN36[11:8] (RW)（Huffman 长度 36）、HCODE36[7:0] (RW)（Huffman 编码 36） | — |
| `JPEG_HUFFENC_AC0_19` | JPEG Huffman 编码器 AC0 | `0x54C` | `0x5200354C` | 32 | — | 0x00000000 / 0x00000000 | HLEN39[27:24] (RW)（Huffman 长度 39）、HCODE39[23:16] (RW)（Huffman 编码 39）、HLEN38[11:8] (RW)（Huffman 长度 38）、HCODE38[7:0] (RW)（Huffman 编码 38） | — |
| `JPEG_HUFFENC_AC0_20` | JPEG Huffman 编码器 AC0 | `0x550` | `0x52003550` | 32 | — | 0x00000000 / 0x00000000 | HLEN41[27:24] (RW)（Huffman 长度 41）、HCODE41[23:16] (RW)（Huffman 编码 41）、HLEN40[11:8] (RW)（Huffman 长度 40）、HCODE40[7:0] (RW)（Huffman 编码 40） | — |
| `JPEG_HUFFENC_AC0_21` | JPEG Huffman 编码器 AC0 | `0x554` | `0x52003554` | 32 | — | 0x00000000 / 0x00000000 | HLEN43[27:24] (RW)（Huffman 长度 43）、HCODE43[23:16] (RW)（Huffman 编码 43）、HLEN42[11:8] (RW)（Huffman 长度 42）、HCODE42[7:0] (RW)（Huffman 编码 42） | — |
| `JPEG_HUFFENC_AC0_22` | JPEG Huffman 编码器 AC0 | `0x558` | `0x52003558` | 32 | — | 0x00000000 / 0x00000000 | HLEN45[27:24] (RW)（Huffman 长度 45）、HCODE45[23:16] (RW)（Huffman 编码 45）、HLEN44[11:8] (RW)（Huffman 长度 44）、HCODE44[7:0] (RW)（Huffman 编码 44） | — |
| `JPEG_HUFFENC_AC0_23` | JPEG Huffman 编码器 AC0 | `0x55C` | `0x5200355C` | 32 | — | 0x00000000 / 0x00000000 | HLEN47[27:24] (RW)（Huffman 长度 47）、HCODE47[23:16] (RW)（Huffman 编码 47）、HLEN46[11:8] (RW)（Huffman 长度 46）、HCODE46[7:0] (RW)（Huffman 编码 46） | — |
| `JPEG_HUFFENC_AC0_24` | JPEG Huffman 编码器 AC0 | `0x560` | `0x52003560` | 32 | — | 0x00000000 / 0x00000000 | HLEN49[27:24] (RW)（Huffman 长度 49）、HCODE49[23:16] (RW)（Huffman 编码 49）、HLEN48[11:8] (RW)（Huffman 长度 48）、HCODE48[7:0] (RW)（Huffman 编码 48） | — |
| `JPEG_HUFFENC_AC0_25` | JPEG Huffman 编码器 AC0 | `0x564` | `0x52003564` | 32 | — | 0x00000000 / 0x00000000 | HLEN51[27:24] (RW)（Huffman 长度 51）、HCODE51[23:16] (RW)（Huffman 编码 51）、HLEN50[11:8] (RW)（Huffman 长度 50）、HCODE50[7:0] (RW)（Huffman 编码 50） | — |
| `JPEG_HUFFENC_AC0_26` | JPEG Huffman 编码器 AC0 | `0x568` | `0x52003568` | 32 | — | 0x00000000 / 0x00000000 | HLEN53[27:24] (RW)（Huffman 长度 53）、HCODE53[23:16] (RW)（Huffman 编码 53）、HLEN52[11:8] (RW)（Huffman 长度 52）、HCODE52[7:0] (RW)（Huffman 编码 52） | — |
| `JPEG_HUFFENC_AC0_27` | JPEG Huffman 编码器 AC0 | `0x56C` | `0x5200356C` | 32 | — | 0x00000000 / 0x00000000 | HLEN55[27:24] (RW)（Huffman 长度 55）、HCODE55[23:16] (RW)（Huffman 编码 55）、HLEN54[11:8] (RW)（Huffman 长度 54）、HCODE54[7:0] (RW)（Huffman 编码 54） | — |
| `JPEG_HUFFENC_AC0_28` | JPEG Huffman 编码器 AC0 | `0x570` | `0x52003570` | 32 | — | 0x00000000 / 0x00000000 | HLEN57[27:24] (RW)（Huffman 长度 57）、HCODE57[23:16] (RW)（Huffman 编码 57）、HLEN56[11:8] (RW)（Huffman 长度 56）、HCODE56[7:0] (RW)（Huffman 编码 56） | — |
| `JPEG_HUFFENC_AC0_29` | JPEG Huffman 编码器 AC0 | `0x574` | `0x52003574` | 32 | — | 0x00000000 / 0x00000000 | HLEN59[27:24] (RW)（Huffman 长度 59）、HCODE59[23:16] (RW)（Huffman 编码 59）、HLEN58[11:8] (RW)（Huffman 长度 58）、HCODE58[7:0] (RW)（Huffman 编码 58） | — |
| `JPEG_HUFFENC_AC0_30` | JPEG Huffman 编码器 AC0 | `0x578` | `0x52003578` | 32 | — | 0x00000000 / 0x00000000 | HLEN61[27:24] (RW)（Huffman 长度 61）、HCODE61[23:16] (RW)（Huffman 编码 61）、HLEN60[11:8] (RW)（Huffman 长度 60）、HCODE60[7:0] (RW)（Huffman 编码 60） | — |
| `JPEG_HUFFENC_AC0_31` | JPEG Huffman 编码器 AC0 | `0x57C` | `0x5200357C` | 32 | — | 0x00000000 / 0x00000000 | HLEN63[27:24] (RW)（Huffman 长度 63）、HCODE63[23:16] (RW)（Huffman 编码 63）、HLEN62[11:8] (RW)（Huffman 长度 62）、HCODE62[7:0] (RW)（Huffman 编码 62） | — |
| `JPEG_HUFFENC_AC0_32` | JPEG Huffman 编码器 AC0 | `0x580` | `0x52003580` | 32 | — | 0x00000000 / 0x00000000 | HLEN65[27:24] (RW)（Huffman 长度 65）、HCODE65[23:16] (RW)（Huffman 编码 65）、HLEN64[11:8] (RW)（Huffman 长度 64）、HCODE64[7:0] (RW)（Huffman 编码 64） | — |
| `JPEG_HUFFENC_AC0_33` | JPEG Huffman 编码器 AC0 | `0x584` | `0x52003584` | 32 | — | 0x00000000 / 0x00000000 | HLEN67[27:24] (RW)（Huffman 长度 67）、HCODE67[23:16] (RW)（Huffman 编码 67）、HLEN66[11:8] (RW)（Huffman 长度 66）、HCODE66[7:0] (RW)（Huffman 编码 66） | — |
| `JPEG_HUFFENC_AC0_34` | JPEG Huffman 编码器 AC0 | `0x588` | `0x52003588` | 32 | — | 0x00000000 / 0x00000000 | HLEN69[27:24] (RW)（Huffman 长度 69）、HCODE69[23:16] (RW)（Huffman 编码 69）、HLEN68[11:8] (RW)（Huffman 长度 68）、HCODE68[7:0] (RW)（Huffman 编码 68） | — |
| `JPEG_HUFFENC_AC0_35` | JPEG Huffman 编码器 AC0 | `0x58C` | `0x5200358C` | 32 | — | 0x00000000 / 0x00000000 | HLEN71[27:24] (RW)（Huffman 长度 71）、HCODE71[23:16] (RW)（Huffman 编码 71）、HLEN70[11:8] (RW)（Huffman 长度 70）、HCODE70[7:0] (RW)（Huffman 编码 70） | — |
| `JPEG_HUFFENC_AC0_36` | JPEG Huffman 编码器 AC0 | `0x590` | `0x52003590` | 32 | — | 0x00000000 / 0x00000000 | HLEN73[27:24] (RW)（Huffman 长度 73）、HCODE73[23:16] (RW)（Huffman 编码 73）、HLEN72[11:8] (RW)（Huffman 长度 72）、HCODE72[7:0] (RW)（Huffman 编码 72） | — |
| `JPEG_HUFFENC_AC0_37` | JPEG Huffman 编码器 AC0 | `0x594` | `0x52003594` | 32 | — | 0x00000000 / 0x00000000 | HLEN75[27:24] (RW)（Huffman 长度 75）、HCODE75[23:16] (RW)（Huffman 编码 75）、HLEN74[11:8] (RW)（Huffman 长度 74）、HCODE74[7:0] (RW)（Huffman 编码 74） | — |
| `JPEG_HUFFENC_AC0_38` | JPEG Huffman 编码器 AC0 | `0x598` | `0x52003598` | 32 | — | 0x00000000 / 0x00000000 | HLEN77[27:24] (RW)（Huffman 长度 77）、HCODE77[23:16] (RW)（Huffman 编码 77）、HLEN76[11:8] (RW)（Huffman 长度 76）、HCODE76[7:0] (RW)（Huffman 编码 76） | — |
| `JPEG_HUFFENC_AC0_39` | JPEG Huffman 编码器 AC0 | `0x59C` | `0x5200359C` | 32 | — | 0x00000000 / 0x00000000 | HLEN79[27:24] (RW)（Huffman 长度 79）、HCODE79[23:16] (RW)（Huffman 编码 79）、HLEN78[11:8] (RW)（Huffman 长度 78）、HCODE78[7:0] (RW)（Huffman 编码 78） | — |
| `JPEG_HUFFENC_AC0_40` | JPEG Huffman 编码器 AC0 | `0x5A0` | `0x520035A0` | 32 | — | 0x00000000 / 0x00000000 | HLEN81[27:24] (RW)（Huffman 长度 81）、HCODE81[23:16] (RW)（Huffman 编码 81）、HLEN80[11:8] (RW)（Huffman 长度 80）、HCODE80[7:0] (RW)（Huffman 编码 80） | — |
| `JPEG_HUFFENC_AC0_41` | JPEG Huffman 编码器 AC0 | `0x5A4` | `0x520035A4` | 32 | — | 0x00000000 / 0x00000000 | HLEN83[27:24] (RW)（Huffman 长度 83）、HCODE83[23:16] (RW)（Huffman 编码 83）、HLEN82[11:8] (RW)（Huffman 长度 82）、HCODE82[7:0] (RW)（Huffman 编码 82） | — |
| `JPEG_HUFFENC_AC0_42` | JPEG Huffman 编码器 AC0 | `0x5A8` | `0x520035A8` | 32 | — | 0x00000000 / 0x00000000 | HLEN85[27:24] (RW)（Huffman 长度 85）、HCODE85[23:16] (RW)（Huffman 编码 85）、HLEN84[11:8] (RW)（Huffman 长度 84）、HCODE84[7:0] (RW)（Huffman 编码 84） | — |
| `JPEG_HUFFENC_AC0_43` | JPEG Huffman 编码器 AC0 | `0x5AC` | `0x520035AC` | 32 | — | 0x00000000 / 0x00000000 | HLEN87[27:24] (RW)（Huffman 长度 87）、HCODE87[23:16] (RW)（Huffman 编码 87）、HLEN86[11:8] (RW)（Huffman 长度 86）、HCODE86[7:0] (RW)（Huffman 编码 86） | — |
| `JPEG_HUFFENC_AC0_44` | JPEG Huffman 编码器 AC0 | `0x5B0` | `0x520035B0` | 32 | — | 0x00000000 / 0x00000000 | HLEN89[27:24] (RW)（Huffman 长度 89）、HCODE89[23:16] (RW)（Huffman 编码 89）、HLEN88[11:8] (RW)（Huffman 长度 88）、HCODE88[7:0] (RW)（Huffman 编码 88） | — |
| `JPEG_HUFFENC_AC0_45` | JPEG Huffman 编码器 AC0 | `0x5B4` | `0x520035B4` | 32 | — | 0x00000000 / 0x00000000 | HLEN91[27:24] (RW)（Huffman 长度 91）、HCODE91[23:16] (RW)（Huffman 编码 91）、HLEN90[11:8] (RW)（Huffman 长度 90）、HCODE90[7:0] (RW)（Huffman 编码 90） | — |
| `JPEG_HUFFENC_AC0_46` | JPEG Huffman 编码器 AC0 | `0x5B8` | `0x520035B8` | 32 | — | 0x00000000 / 0x00000000 | HLEN93[27:24] (RW)（Huffman 长度 93）、HCODE93[23:16] (RW)（Huffman 编码 93）、HLEN92[11:8] (RW)（Huffman 长度 92）、HCODE92[7:0] (RW)（Huffman 编码 92） | — |
| `JPEG_HUFFENC_AC0_47` | JPEG Huffman 编码器 AC0 | `0x5BC` | `0x520035BC` | 32 | — | 0x00000000 / 0x00000000 | HLEN95[27:24] (RW)（Huffman 长度 95）、HCODE95[23:16] (RW)（Huffman 编码 95）、HLEN94[11:8] (RW)（Huffman 长度 94）、HCODE94[7:0] (RW)（Huffman 编码 94） | — |
| `JPEG_HUFFENC_AC0_48` | JPEG Huffman 编码器 AC0 | `0x5C0` | `0x520035C0` | 32 | — | 0x00000000 / 0x00000000 | HLEN97[27:24] (RW)（Huffman 长度 97）、HCODE97[23:16] (RW)（Huffman 编码 97）、HLEN96[11:8] (RW)（Huffman 长度 96）、HCODE96[7:0] (RW)（Huffman 编码 96） | — |
| `JPEG_HUFFENC_AC0_49` | JPEG Huffman 编码器 AC0 | `0x5C4` | `0x520035C4` | 32 | — | 0x00000000 / 0x00000000 | HLEN99[27:24] (RW)（Huffman 长度 99）、HCODE99[23:16] (RW)（Huffman 编码 99）、HLEN98[11:8] (RW)（Huffman 长度 98）、HCODE98[7:0] (RW)（Huffman 编码 98） | — |
| `JPEG_HUFFENC_AC0_50` | JPEG Huffman 编码器 AC0 | `0x5C8` | `0x520035C8` | 32 | — | 0x00000000 / 0x00000000 | HLEN101[27:24] (RW)（Huffman 长度 101）、HCODE101[23:16] (RW)（Huffman 编码 101）、HLEN100[11:8] (RW)（Huffman 长度 100）、HCODE100[7:0] (RW)（Huffman 编码 100） | — |
| `JPEG_HUFFENC_AC0_51` | JPEG Huffman 编码器 AC0 | `0x5CC` | `0x520035CC` | 32 | — | 0x00000000 / 0x00000000 | HLEN103[27:24] (RW)（Huffman 长度 103）、HCODE103[23:16] (RW)（Huffman 编码 103）、HLEN102[11:8] (RW)（Huffman 长度 102）、HCODE102[7:0] (RW)（Huffman 编码 102） | — |
| `JPEG_HUFFENC_AC0_52` | JPEG Huffman 编码器 AC0 | `0x5D0` | `0x520035D0` | 32 | — | 0x00000000 / 0x00000000 | HLEN105[27:24] (RW)（Huffman 长度 105）、HCODE105[23:16] (RW)（Huffman 编码 105）、HLEN104[11:8] (RW)（Huffman 长度 104）、HCODE104[7:0] (RW)（Huffman 编码 104） | — |
| `JPEG_HUFFENC_AC0_53` | JPEG Huffman 编码器 AC0 | `0x5D4` | `0x520035D4` | 32 | — | 0x00000000 / 0x00000000 | HLEN107[27:24] (RW)（Huffman 长度 107）、HCODE107[23:16] (RW)（Huffman 编码 107）、HLEN106[11:8] (RW)（Huffman 长度 106）、HCODE106[7:0] (RW)（Huffman 编码 106） | — |
| `JPEG_HUFFENC_AC0_54` | JPEG Huffman 编码器 AC0 | `0x5D8` | `0x520035D8` | 32 | — | 0x00000000 / 0x00000000 | HLEN109[27:24] (RW)（Huffman 长度 109）、HCODE109[23:16] (RW)（Huffman 编码 109）、HLEN108[11:8] (RW)（Huffman 长度 108）、HCODE108[7:0] (RW)（Huffman 编码 108） | — |
| `JPEG_HUFFENC_AC0_55` | JPEG Huffman 编码器 AC0 | `0x5DC` | `0x520035DC` | 32 | — | 0x00000000 / 0x00000000 | HLEN111[27:24] (RW)（Huffman 长度 111）、HCODE111[23:16] (RW)（Huffman 编码 111）、HLEN110[11:8] (RW)（Huffman 长度 110）、HCODE110[7:0] (RW)（Huffman 编码 110） | — |
| `JPEG_HUFFENC_AC1_0` | JPEG Huffman 编码器 AC1 | `0x5DC` | `0x520035DC` | 32 | — | 0x00000000 / 0x00000000 | HLEN1[27:24] (RW)（Huffman 长度 1）、HCODE1[23:16] (RW)（Huffman 编码 1）、HLEN0[11:8] (RW)（Huffman 长度 0）、HCODE0[7:0] (RW)（Huffman 编码 0） | 别名 JPEG_HUFFENC_AC0_55 |
| `JPEG_HUFFENC_AC0_56` | JPEG Huffman 编码器 AC0 | `0x5E0` | `0x520035E0` | 32 | — | 0x00000000 / 0x00000000 | HLEN113[27:24] (RW)（Huffman 长度 113）、HCODE113[23:16] (RW)（Huffman 编码 113）、HLEN112[11:8] (RW)（Huffman 长度 112）、HCODE112[7:0] (RW)（Huffman 编码 112） | — |
| `JPEG_HUFFENC_AC1_1` | JPEG Huffman 编码器 AC1 | `0x5E0` | `0x520035E0` | 32 | — | 0x00000000 / 0x00000000 | HLEN3[27:24] (RW)（Huffman 长度 3）、HCODE3[23:16] (RW)（Huffman 编码 3）、HLEN2[11:8] (RW)（Huffman 长度 2）、HCODE2[7:0] (RW)（Huffman 编码 2） | 别名 JPEG_HUFFENC_AC0_56 |
| `JPEG_HUFFENC_AC0_57` | JPEG Huffman 编码器 AC0 | `0x5E4` | `0x520035E4` | 32 | — | 0x00000000 / 0x00000000 | HLEN115[27:24] (RW)（Huffman 长度 115）、HCODE115[23:16] (RW)（Huffman 编码 115）、HLEN114[11:8] (RW)（Huffman 长度 114）、HCODE114[7:0] (RW)（Huffman 编码 114） | — |
| `JPEG_HUFFENC_AC1_2` | JPEG Huffman 编码器 AC1 | `0x5E4` | `0x520035E4` | 32 | — | 0x00000000 / 0x00000000 | HLEN5[27:24] (RW)（Huffman 长度 5）、HCODE5[23:16] (RW)（Huffman 编码 5）、HLEN4[11:8] (RW)（Huffman 长度 4）、HCODE4[7:0] (RW)（Huffman 编码 4） | 别名 JPEG_HUFFENC_AC0_57 |
| `JPEG_HUFFENC_AC0_58` | JPEG Huffman 编码器 AC0 | `0x5E8` | `0x520035E8` | 32 | — | 0x00000000 / 0x00000000 | HLEN117[27:24] (RW)（Huffman 长度 117）、HCODE117[23:16] (RW)（Huffman 编码 117）、HLEN116[11:8] (RW)（Huffman 长度 116）、HCODE116[7:0] (RW)（Huffman 编码 116） | — |
| `JPEG_HUFFENC_AC1_3` | JPEG Huffman 编码器 AC1 | `0x5E8` | `0x520035E8` | 32 | — | 0x00000000 / 0x00000000 | HLEN7[27:24] (RW)（Huffman 长度 7）、HCODE7[23:16] (RW)（Huffman 编码 7）、HLEN6[11:8] (RW)（Huffman 长度 6）、HCODE6[7:0] (RW)（Huffman 编码 6） | 别名 JPEG_HUFFENC_AC0_58 |
| `JPEG_HUFFENC_AC0_59` | JPEG Huffman 编码器 AC0 | `0x5EC` | `0x520035EC` | 32 | — | 0x00000000 / 0x00000000 | HLEN119[27:24] (RW)（Huffman 长度 119）、HCODE119[23:16] (RW)（Huffman 编码 119）、HLEN118[11:8] (RW)（Huffman 长度 118）、HCODE118[7:0] (RW)（Huffman 编码 118） | — |
| `JPEG_HUFFENC_AC1_4` | JPEG Huffman 编码器 AC1 | `0x5EC` | `0x520035EC` | 32 | — | 0x00000000 / 0x00000000 | HLEN9[27:24] (RW)（Huffman 长度 9）、HCODE9[23:16] (RW)（Huffman 编码 9）、HLEN8[11:8] (RW)（Huffman 长度 8）、HCODE8[7:0] (RW)（Huffman 编码 8） | 别名 JPEG_HUFFENC_AC0_59 |
| `JPEG_HUFFENC_AC0_60` | JPEG Huffman 编码器 AC0 | `0x5F0` | `0x520035F0` | 32 | — | 0x00000000 / 0x00000000 | HLEN121[27:24] (RW)（Huffman 长度 121）、HCODE121[23:16] (RW)（Huffman 编码 121）、HLEN120[11:8] (RW)（Huffman 长度 120）、HCODE120[7:0] (RW)（Huffman 编码 120） | — |
| `JPEG_HUFFENC_AC1_5` | JPEG Huffman 编码器 AC1 | `0x5F0` | `0x520035F0` | 32 | — | 0x00000000 / 0x00000000 | HLEN11[27:24] (RW)（Huffman 长度 11）、HCODE11[23:16] (RW)（Huffman 编码 11）、HLEN10[11:8] (RW)（Huffman 长度 10）、HCODE10[7:0] (RW)（Huffman 编码 10） | 别名 JPEG_HUFFENC_AC0_60 |
| `JPEG_HUFFENC_AC0_61` | JPEG Huffman 编码器 AC0 | `0x5F4` | `0x520035F4` | 32 | — | 0x00000000 / 0x00000000 | HLEN123[27:24] (RW)（Huffman 长度 123）、HCODE123[23:16] (RW)（Huffman 编码 123）、HLEN122[11:8] (RW)（Huffman 长度 122）、HCODE122[7:0] (RW)（Huffman 编码 122） | — |
| `JPEG_HUFFENC_AC1_6` | JPEG Huffman 编码器 AC1 | `0x5F4` | `0x520035F4` | 32 | — | 0x00000000 / 0x00000000 | HLEN13[27:24] (RW)（Huffman 长度 13）、HCODE13[23:16] (RW)（Huffman 编码 13）、HLEN12[11:8] (RW)（Huffman 长度 12）、HCODE12[7:0] (RW)（Huffman 编码 12） | 别名 JPEG_HUFFENC_AC0_61 |
| `JPEG_HUFFENC_AC0_62` | JPEG Huffman 编码器 AC0 | `0x5F8` | `0x520035F8` | 32 | — | 0x00000000 / 0x00000000 | HLEN125[27:24] (RW)（Huffman 长度 125）、HCODE125[23:16] (RW)（Huffman 编码 125）、HLEN124[11:8] (RW)（Huffman 长度 124）、HCODE124[7:0] (RW)（Huffman 编码 124） | — |
| `JPEG_HUFFENC_AC1_7` | JPEG Huffman 编码器 AC1 | `0x5F8` | `0x520035F8` | 32 | — | 0x00000000 / 0x00000000 | HLEN15[27:24] (RW)（Huffman 长度 15）、HCODE15[23:16] (RW)（Huffman 编码 15）、HLEN14[11:8] (RW)（Huffman 长度 14）、HCODE14[7:0] (RW)（Huffman 编码 14） | 别名 JPEG_HUFFENC_AC0_62 |
| `JPEG_HUFFENC_AC0_63` | JPEG Huffman 编码器 AC0 | `0x5FC` | `0x520035FC` | 32 | — | 0x00000000 / 0x00000000 | HLEN127[27:24] (RW)（Huffman 长度 127）、HCODE127[23:16] (RW)（Huffman 编码 127）、HLEN126[11:8] (RW)（Huffman 长度 126）、HCODE126[7:0] (RW)（Huffman 编码 126） | — |
| `JPEG_HUFFENC_AC1_8` | JPEG Huffman 编码器 AC1 | `0x5FC` | `0x520035FC` | 32 | — | 0x00000000 / 0x00000000 | HLEN17[27:24] (RW)（Huffman 长度 17）、HCODE17[23:16] (RW)（Huffman 编码 17）、HLEN16[11:8] (RW)（Huffman 长度 16）、HCODE16[7:0] (RW)（Huffman 编码 16） | 别名 JPEG_HUFFENC_AC0_63 |
| `JPEG_HUFFENC_AC0_64` | JPEG Huffman 编码器 AC0 | `0x600` | `0x52003600` | 32 | — | 0x00000000 / 0x00000000 | HLEN129[27:24] (RW)（Huffman 长度 129）、HCODE129[23:16] (RW)（Huffman 编码 129）、HLEN128[11:8] (RW)（Huffman 长度 128）、HCODE128[7:0] (RW)（Huffman 编码 128） | — |
| `JPEG_HUFFENC_AC1_9` | JPEG Huffman 编码器 AC1 | `0x600` | `0x52003600` | 32 | — | 0x00000000 / 0x00000000 | HLEN19[27:24] (RW)（Huffman 长度 19）、HCODE19[23:16] (RW)（Huffman 编码 19）、HLEN18[11:8] (RW)（Huffman 长度 18）、HCODE18[7:0] (RW)（Huffman 编码 18） | 别名 JPEG_HUFFENC_AC0_64 |
| `JPEG_HUFFENC_AC0_65` | JPEG Huffman 编码器 AC0 | `0x604` | `0x52003604` | 32 | — | 0x00000000 / 0x00000000 | HLEN131[27:24] (RW)（Huffman 长度 131）、HCODE131[23:16] (RW)（Huffman 编码 131）、HLEN130[11:8] (RW)（Huffman 长度 130）、HCODE130[7:0] (RW)（Huffman 编码 130） | — |
| `JPEG_HUFFENC_AC1_10` | JPEG Huffman 编码器 AC1 | `0x604` | `0x52003604` | 32 | — | 0x00000000 / 0x00000000 | HLEN21[27:24] (RW)（Huffman 长度 21）、HCODE21[23:16] (RW)（Huffman 编码 21）、HLEN20[11:8] (RW)（Huffman 长度 20）、HCODE20[7:0] (RW)（Huffman 编码 20） | 别名 JPEG_HUFFENC_AC0_65 |
| `JPEG_HUFFENC_AC0_66` | JPEG Huffman 编码器 AC0 | `0x608` | `0x52003608` | 32 | — | 0x00000000 / 0x00000000 | HLEN133[27:24] (RW)（Huffman 长度 133）、HCODE133[23:16] (RW)（Huffman 编码 133）、HLEN132[11:8] (RW)（Huffman 长度 132）、HCODE132[7:0] (RW)（Huffman 编码 132） | — |
| `JPEG_HUFFENC_AC1_11` | JPEG Huffman 编码器 AC1 | `0x608` | `0x52003608` | 32 | — | 0x00000000 / 0x00000000 | HLEN23[27:24] (RW)（Huffman 长度 23）、HCODE23[23:16] (RW)（Huffman 编码 23）、HLEN22[11:8] (RW)（Huffman 长度 22）、HCODE22[7:0] (RW)（Huffman 编码 22） | 别名 JPEG_HUFFENC_AC0_66 |
| `JPEG_HUFFENC_AC0_67` | JPEG Huffman 编码器 AC0 | `0x60C` | `0x5200360C` | 32 | — | 0x00000000 / 0x00000000 | HLEN135[27:24] (RW)（Huffman 长度 135）、HCODE135[23:16] (RW)（Huffman 编码 135）、HLEN134[11:8] (RW)（Huffman 长度 134）、HCODE134[7:0] (RW)（Huffman 编码 134） | — |
| `JPEG_HUFFENC_AC1_12` | JPEG Huffman 编码器 AC1 | `0x60C` | `0x5200360C` | 32 | — | 0x00000000 / 0x00000000 | HLEN25[27:24] (RW)（Huffman 长度 25）、HCODE25[23:16] (RW)（Huffman 编码 25）、HLEN24[11:8] (RW)（Huffman 长度 24）、HCODE24[7:0] (RW)（Huffman 编码 24） | 别名 JPEG_HUFFENC_AC0_67 |
| `JPEG_HUFFENC_AC0_68` | JPEG Huffman 编码器 AC0 | `0x610` | `0x52003610` | 32 | — | 0x00000000 / 0x00000000 | HLEN137[27:24] (RW)（Huffman 长度 137）、HCODE137[23:16] (RW)（Huffman 编码 137）、HLEN136[11:8] (RW)（Huffman 长度 136）、HCODE136[7:0] (RW)（Huffman 编码 136） | — |
| `JPEG_HUFFENC_AC1_13` | JPEG Huffman 编码器 AC1 | `0x610` | `0x52003610` | 32 | — | 0x00000000 / 0x00000000 | HLEN27[27:24] (RW)（Huffman 长度 27）、HCODE27[23:16] (RW)（Huffman 编码 27）、HLEN26[11:8] (RW)（Huffman 长度 26）、HCODE26[7:0] (RW)（Huffman 编码 26） | 别名 JPEG_HUFFENC_AC0_68 |
| `JPEG_HUFFENC_AC0_69` | JPEG Huffman 编码器 AC0 | `0x614` | `0x52003614` | 32 | — | 0x00000000 / 0x00000000 | HLEN139[27:24] (RW)（Huffman 长度 139）、HCODE139[23:16] (RW)（Huffman 编码 139）、HLEN138[11:8] (RW)（Huffman 长度 138）、HCODE138[7:0] (RW)（Huffman 编码 138） | — |
| `JPEG_HUFFENC_AC1_14` | JPEG Huffman 编码器 AC1 | `0x614` | `0x52003614` | 32 | — | 0x00000000 / 0x00000000 | HLEN29[27:24] (RW)（Huffman 长度 29）、HCODE29[23:16] (RW)（Huffman 编码 29）、HLEN28[11:8] (RW)（Huffman 长度 28）、HCODE28[7:0] (RW)（Huffman 编码 28） | 别名 JPEG_HUFFENC_AC0_69 |
| `JPEG_HUFFENC_AC0_70` | JPEG Huffman 编码器 AC0 | `0x618` | `0x52003618` | 32 | — | 0x00000000 / 0x00000000 | HLEN141[27:24] (RW)（Huffman 长度 141）、HCODE141[23:16] (RW)（Huffman 编码 141）、HLEN140[11:8] (RW)（Huffman 长度 140）、HCODE140[7:0] (RW)（Huffman 编码 140） | — |
| `JPEG_HUFFENC_AC1_15` | JPEG Huffman 编码器 AC1 | `0x618` | `0x52003618` | 32 | — | 0x00000000 / 0x00000000 | HLEN31[27:24] (RW)（Huffman 长度 31）、HCODE31[23:16] (RW)（Huffman 编码 31）、HLEN30[11:8] (RW)（Huffman 长度 30）、HCODE30[7:0] (RW)（Huffman 编码 30） | 别名 JPEG_HUFFENC_AC0_70 |
| `JPEG_HUFFENC_AC0_71` | JPEG Huffman 编码器 AC0 | `0x61C` | `0x5200361C` | 32 | — | 0x00000000 / 0x00000000 | HLEN143[27:24] (RW)（Huffman 长度 143）、HCODE143[23:16] (RW)（Huffman 编码 143）、HLEN142[11:8] (RW)（Huffman 长度 142）、HCODE142[7:0] (RW)（Huffman 编码 142） | — |
| `JPEG_HUFFENC_AC1_16` | JPEG Huffman 编码器 AC1 | `0x61C` | `0x5200361C` | 32 | — | 0x00000000 / 0x00000000 | HLEN33[27:24] (RW)（Huffman 长度 33）、HCODE33[23:16] (RW)（Huffman 编码 33）、HLEN32[11:8] (RW)（Huffman 长度 32）、HCODE32[7:0] (RW)（Huffman 编码 32） | 别名 JPEG_HUFFENC_AC0_71 |
| `JPEG_HUFFENC_AC0_72` | JPEG Huffman 编码器 AC0 | `0x620` | `0x52003620` | 32 | — | 0x00000000 / 0x00000000 | HLEN145[27:24] (RW)（Huffman 长度 145）、HCODE145[23:16] (RW)（Huffman 编码 145）、HLEN144[11:8] (RW)（Huffman 长度 144）、HCODE144[7:0] (RW)（Huffman 编码 144） | — |
| `JPEG_HUFFENC_AC1_17` | JPEG Huffman 编码器 AC1 | `0x620` | `0x52003620` | 32 | — | 0x00000000 / 0x00000000 | HLEN35[27:24] (RW)（Huffman 长度 35）、HCODE35[23:16] (RW)（Huffman 编码 35）、HLEN34[11:8] (RW)（Huffman 长度 34）、HCODE34[7:0] (RW)（Huffman 编码 34） | 别名 JPEG_HUFFENC_AC0_72 |
| `JPEG_HUFFENC_AC0_73` | JPEG Huffman 编码器 AC0 | `0x624` | `0x52003624` | 32 | — | 0x00000000 / 0x00000000 | HLEN147[27:24] (RW)（Huffman 长度 147）、HCODE147[23:16] (RW)（Huffman 编码 147）、HLEN146[11:8] (RW)（Huffman 长度 146）、HCODE146[7:0] (RW)（Huffman 编码 146） | — |
| `JPEG_HUFFENC_AC1_18` | JPEG Huffman 编码器 AC1 | `0x624` | `0x52003624` | 32 | — | 0x00000000 / 0x00000000 | HLEN37[27:24] (RW)（Huffman 长度 37）、HCODE37[23:16] (RW)（Huffman 编码 37）、HLEN36[11:8] (RW)（Huffman 长度 36）、HCODE36[7:0] (RW)（Huffman 编码 36） | 别名 JPEG_HUFFENC_AC0_73 |
| `JPEG_HUFFENC_AC0_74` | JPEG Huffman 编码器 AC0 | `0x628` | `0x52003628` | 32 | — | 0x00000000 / 0x00000000 | HLEN149[27:24] (RW)（Huffman 长度 149）、HCODE149[23:16] (RW)（Huffman 编码 149）、HLEN148[11:8] (RW)（Huffman 长度 148）、HCODE148[7:0] (RW)（Huffman 编码 148） | — |
| `JPEG_HUFFENC_AC1_19` | JPEG Huffman 编码器 AC1 | `0x628` | `0x52003628` | 32 | — | 0x00000000 / 0x00000000 | HLEN39[27:24] (RW)（Huffman 长度 39）、HCODE39[23:16] (RW)（Huffman 编码 39）、HLEN38[11:8] (RW)（Huffman 长度 38）、HCODE38[7:0] (RW)（Huffman 编码 38） | 别名 JPEG_HUFFENC_AC0_74 |
| `JPEG_HUFFENC_AC0_75` | JPEG Huffman 编码器 AC0 | `0x62C` | `0x5200362C` | 32 | — | 0x00000000 / 0x00000000 | HLEN151[27:24] (RW)（Huffman 长度 151）、HCODE151[23:16] (RW)（Huffman 编码 151）、HLEN150[11:8] (RW)（Huffman 长度 150）、HCODE150[7:0] (RW)（Huffman 编码 150） | — |
| `JPEG_HUFFENC_AC1_20` | JPEG Huffman 编码器 AC1 | `0x62C` | `0x5200362C` | 32 | — | 0x00000000 / 0x00000000 | HLEN41[27:24] (RW)（Huffman 长度 41）、HCODE41[23:16] (RW)（Huffman 编码 41）、HLEN40[11:8] (RW)（Huffman 长度 40）、HCODE40[7:0] (RW)（Huffman 编码 40） | 别名 JPEG_HUFFENC_AC0_75 |
| `JPEG_HUFFENC_AC0_76` | JPEG Huffman 编码器 AC0 | `0x630` | `0x52003630` | 32 | — | 0x00000000 / 0x00000000 | HLEN153[27:24] (RW)（Huffman 长度 153）、HCODE153[23:16] (RW)（Huffman 编码 153）、HLEN152[11:8] (RW)（Huffman 长度 152）、HCODE152[7:0] (RW)（Huffman 编码 152） | — |
| `JPEG_HUFFENC_AC1_21` | JPEG Huffman 编码器 AC1 | `0x630` | `0x52003630` | 32 | — | 0x00000000 / 0x00000000 | HLEN43[27:24] (RW)（Huffman 长度 43）、HCODE43[23:16] (RW)（Huffman 编码 43）、HLEN42[11:8] (RW)（Huffman 长度 42）、HCODE42[7:0] (RW)（Huffman 编码 42） | 别名 JPEG_HUFFENC_AC0_76 |
| `JPEG_HUFFENC_AC0_77` | JPEG Huffman 编码器 AC0 | `0x634` | `0x52003634` | 32 | — | 0x00000000 / 0x00000000 | HLEN155[27:24] (RW)（Huffman 长度 155）、HCODE155[23:16] (RW)（Huffman 编码 155）、HLEN154[11:8] (RW)（Huffman 长度 154）、HCODE154[7:0] (RW)（Huffman 编码 154） | — |
| `JPEG_HUFFENC_AC1_22` | JPEG Huffman 编码器 AC1 | `0x634` | `0x52003634` | 32 | — | 0x00000000 / 0x00000000 | HLEN45[27:24] (RW)（Huffman 长度 45）、HCODE45[23:16] (RW)（Huffman 编码 45）、HLEN44[11:8] (RW)（Huffman 长度 44）、HCODE44[7:0] (RW)（Huffman 编码 44） | 别名 JPEG_HUFFENC_AC0_77 |
| `JPEG_HUFFENC_AC0_78` | JPEG Huffman 编码器 AC0 | `0x638` | `0x52003638` | 32 | — | 0x00000000 / 0x00000000 | HLEN157[27:24] (RW)（Huffman 长度 157）、HCODE157[23:16] (RW)（Huffman 编码 157）、HLEN156[11:8] (RW)（Huffman 长度 156）、HCODE156[7:0] (RW)（Huffman 编码 156） | — |
| `JPEG_HUFFENC_AC1_23` | JPEG Huffman 编码器 AC1 | `0x638` | `0x52003638` | 32 | — | 0x00000000 / 0x00000000 | HLEN47[27:24] (RW)（Huffman 长度 47）、HCODE47[23:16] (RW)（Huffman 编码 47）、HLEN46[11:8] (RW)（Huffman 长度 46）、HCODE46[7:0] (RW)（Huffman 编码 46） | 别名 JPEG_HUFFENC_AC0_78 |
| `JPEG_HUFFENC_AC0_79` | JPEG Huffman 编码器 AC0 | `0x63C` | `0x5200363C` | 32 | — | 0x00000000 / 0x00000000 | HLEN159[27:24] (RW)（Huffman 长度 159）、HCODE159[23:16] (RW)（Huffman 编码 159）、HLEN158[11:8] (RW)（Huffman 长度 158）、HCODE158[7:0] (RW)（Huffman 编码 158） | — |
| `JPEG_HUFFENC_AC1_24` | JPEG Huffman 编码器 AC1 | `0x63C` | `0x5200363C` | 32 | — | 0x00000000 / 0x00000000 | HLEN49[27:24] (RW)（Huffman 长度 49）、HCODE49[23:16] (RW)（Huffman 编码 49）、HLEN48[11:8] (RW)（Huffman 长度 48）、HCODE48[7:0] (RW)（Huffman 编码 48） | 别名 JPEG_HUFFENC_AC0_79 |
| `JPEG_HUFFENC_AC0_80` | JPEG Huffman 编码器 AC0 | `0x640` | `0x52003640` | 32 | — | 0x00000000 / 0x00000000 | HLEN161[27:24] (RW)（Huffman 长度 161）、HCODE161[23:16] (RW)（Huffman 编码 161）、HLEN160[11:8] (RW)（Huffman 长度 160）、HCODE160[7:0] (RW)（Huffman 编码 160） | — |
| `JPEG_HUFFENC_AC1_25` | JPEG Huffman 编码器 AC1 | `0x640` | `0x52003640` | 32 | — | 0x00000000 / 0x00000000 | HLEN51[27:24] (RW)（Huffman 长度 51）、HCODE51[23:16] (RW)（Huffman 编码 51）、HLEN50[11:8] (RW)（Huffman 长度 50）、HCODE50[7:0] (RW)（Huffman 编码 50） | 别名 JPEG_HUFFENC_AC0_80 |
| `JPEG_HUFFENC_AC0_81` | JPEG Huffman 编码器 AC0 | `0x644` | `0x52003644` | 32 | — | 0x00000000 / 0x00000000 | HLEN163[27:24] (RW)（Huffman 长度 163）、HCODE163[23:16] (RW)（Huffman 编码 163）、HLEN162[11:8] (RW)（Huffman 长度 162）、HCODE162[7:0] (RW)（Huffman 编码 162） | — |
| `JPEG_HUFFENC_AC1_26` | JPEG Huffman 编码器 AC1 | `0x644` | `0x52003644` | 32 | — | 0x00000000 / 0x00000000 | HLEN53[27:24] (RW)（Huffman 长度 53）、HCODE53[23:16] (RW)（Huffman 编码 53）、HLEN52[11:8] (RW)（Huffman 长度 52）、HCODE52[7:0] (RW)（Huffman 编码 52） | 别名 JPEG_HUFFENC_AC0_81 |
| `JPEG_HUFFENC_AC0_82` | JPEG Huffman 编码器 AC0 | `0x648` | `0x52003648` | 32 | — | 0x00000000 / 0x00000000 | HLEN165[27:24] (RW)（Huffman 长度 165）、HCODE165[23:16] (RW)（Huffman 编码 165）、HLEN164[11:8] (RW)（Huffman 长度 164）、HCODE164[7:0] (RW)（Huffman 编码 164） | — |
| `JPEG_HUFFENC_AC1_27` | JPEG Huffman 编码器 AC1 | `0x648` | `0x52003648` | 32 | — | 0x00000000 / 0x00000000 | HLEN55[27:24] (RW)（Huffman 长度 55）、HCODE55[23:16] (RW)（Huffman 编码 55）、HLEN54[11:8] (RW)（Huffman 长度 54）、HCODE54[7:0] (RW)（Huffman 编码 54） | 别名 JPEG_HUFFENC_AC0_82 |
| `JPEG_HUFFENC_AC0_83` | JPEG Huffman 编码器 AC0 | `0x64C` | `0x5200364C` | 32 | — | 0x00000000 / 0x00000000 | HLEN167[27:24] (RW)（Huffman 长度 167）、HCODE167[23:16] (RW)（Huffman 编码 167）、HLEN166[11:8] (RW)（Huffman 长度 166）、HCODE166[7:0] (RW)（Huffman 编码 166） | — |
| `JPEG_HUFFENC_AC1_28` | JPEG Huffman 编码器 AC1 | `0x64C` | `0x5200364C` | 32 | — | 0x00000000 / 0x00000000 | HLEN57[27:24] (RW)（Huffman 长度 57）、HCODE57[23:16] (RW)（Huffman 编码 57）、HLEN56[11:8] (RW)（Huffman 长度 56）、HCODE56[7:0] (RW)（Huffman 编码 56） | 别名 JPEG_HUFFENC_AC0_83 |
| `JPEG_HUFFENC_AC0_84` | JPEG Huffman 编码器 AC0 | `0x650` | `0x52003650` | 32 | — | 0x00000000 / 0x00000000 | HLEN169[27:24] (RW)（Huffman 长度 169）、HCODE169[23:16] (RW)（Huffman 编码 169）、HLEN168[11:8] (RW)（Huffman 长度 168）、HCODE168[7:0] (RW)（Huffman 编码 168） | — |
| `JPEG_HUFFENC_AC1_29` | JPEG Huffman 编码器 AC1 | `0x650` | `0x52003650` | 32 | — | 0x00000000 / 0x00000000 | HLEN59[27:24] (RW)（Huffman 长度 59）、HCODE59[23:16] (RW)（Huffman 编码 59）、HLEN58[11:8] (RW)（Huffman 长度 58）、HCODE58[7:0] (RW)（Huffman 编码 58） | 别名 JPEG_HUFFENC_AC0_84 |
| `JPEG_HUFFENC_AC0_85` | JPEG Huffman 编码器 AC0 | `0x654` | `0x52003654` | 32 | — | 0x00000000 / 0x00000000 | HLEN171[27:24] (RW)（Huffman 长度 171）、HCODE171[23:16] (RW)（Huffman 编码 171）、HLEN170[11:8] (RW)（Huffman 长度 170）、HCODE170[7:0] (RW)（Huffman 编码 170） | — |
| `JPEG_HUFFENC_AC1_30` | JPEG Huffman 编码器 AC1 | `0x654` | `0x52003654` | 32 | — | 0x00000000 / 0x00000000 | HLEN61[27:24] (RW)（Huffman 长度 61）、HCODE61[23:16] (RW)（Huffman 编码 61）、HLEN60[11:8] (RW)（Huffman 长度 60）、HCODE60[7:0] (RW)（Huffman 编码 60） | 别名 JPEG_HUFFENC_AC0_85 |
| `JPEG_HUFFENC_AC0_86` | JPEG Huffman 编码器 AC0 | `0x658` | `0x52003658` | 32 | — | 0x00000000 / 0x00000000 | HLEN173[27:24] (RW)（Huffman 长度 173）、HCODE173[23:16] (RW)（Huffman 编码 173）、HLEN172[11:8] (RW)（Huffman 长度 172）、HCODE172[7:0] (RW)（Huffman 编码 172） | — |
| `JPEG_HUFFENC_AC1_31` | JPEG Huffman 编码器 AC1 | `0x658` | `0x52003658` | 32 | — | 0x00000000 / 0x00000000 | HLEN63[27:24] (RW)（Huffman 长度 63）、HCODE63[23:16] (RW)（Huffman 编码 63）、HLEN62[11:8] (RW)（Huffman 长度 62）、HCODE62[7:0] (RW)（Huffman 编码 62） | 别名 JPEG_HUFFENC_AC0_86 |
| `JPEG_HUFFENC_AC0_87` | JPEG Huffman 编码器 AC0 | `0x65C` | `0x5200365C` | 32 | — | 0x00000000 / 0x00000000 | HLEN175[27:24] (RW)（Huffman 长度 175）、HCODE175[23:16] (RW)（Huffman 编码 175）、HLEN174[11:8] (RW)（Huffman 长度 174）、HCODE174[7:0] (RW)（Huffman 编码 174） | — |
| `JPEG_HUFFENC_AC1_32` | JPEG Huffman 编码器 AC1 | `0x65C` | `0x5200365C` | 32 | — | 0x00000000 / 0x00000000 | HLEN65[27:24] (RW)（Huffman 长度 65）、HCODE65[23:16] (RW)（Huffman 编码 65）、HLEN64[11:8] (RW)（Huffman 长度 64）、HCODE64[7:0] (RW)（Huffman 编码 64） | 别名 JPEG_HUFFENC_AC0_87 |
| `JPEG_HUFFENC_AC1_33` | JPEG Huffman 编码器 AC1 | `0x660` | `0x52003660` | 32 | — | 0x00000000 / 0x00000000 | HLEN67[27:24] (RW)（Huffman 长度 67）、HCODE67[23:16] (RW)（Huffman 编码 67）、HLEN66[11:8] (RW)（Huffman 长度 66）、HCODE66[7:0] (RW)（Huffman 编码 66） | — |
| `JPEG_HUFFENC_AC1_34` | JPEG Huffman 编码器 AC1 | `0x664` | `0x52003664` | 32 | — | 0x00000000 / 0x00000000 | HLEN69[27:24] (RW)（Huffman 长度 69）、HCODE69[23:16] (RW)（Huffman 编码 69）、HLEN68[11:8] (RW)（Huffman 长度 68）、HCODE68[7:0] (RW)（Huffman 编码 68） | — |
| `JPEG_HUFFENC_AC1_35` | JPEG Huffman 编码器 AC1 | `0x668` | `0x52003668` | 32 | — | 0x00000000 / 0x00000000 | HLEN71[27:24] (RW)（Huffman 长度 71）、HCODE71[23:16] (RW)（Huffman 编码 71）、HLEN70[11:8] (RW)（Huffman 长度 70）、HCODE70[7:0] (RW)（Huffman 编码 70） | — |
| `JPEG_HUFFENC_AC1_36` | JPEG Huffman 编码器 AC1 | `0x66C` | `0x5200366C` | 32 | — | 0x00000000 / 0x00000000 | HLEN73[27:24] (RW)（Huffman 长度 73）、HCODE73[23:16] (RW)（Huffman 编码 73）、HLEN72[11:8] (RW)（Huffman 长度 72）、HCODE72[7:0] (RW)（Huffman 编码 72） | — |
| `JPEG_HUFFENC_AC1_37` | JPEG Huffman 编码器 AC1 | `0x670` | `0x52003670` | 32 | — | 0x00000000 / 0x00000000 | HLEN75[27:24] (RW)（Huffman 长度 75）、HCODE75[23:16] (RW)（Huffman 编码 75）、HLEN74[11:8] (RW)（Huffman 长度 74）、HCODE74[7:0] (RW)（Huffman 编码 74） | — |
| `JPEG_HUFFENC_AC1_38` | JPEG Huffman 编码器 AC1 | `0x674` | `0x52003674` | 32 | — | 0x00000000 / 0x00000000 | HLEN77[27:24] (RW)（Huffman 长度 77）、HCODE77[23:16] (RW)（Huffman 编码 77）、HLEN76[11:8] (RW)（Huffman 长度 76）、HCODE76[7:0] (RW)（Huffman 编码 76） | — |
| `JPEG_HUFFENC_AC1_39` | JPEG Huffman 编码器 AC1 | `0x678` | `0x52003678` | 32 | — | 0x00000000 / 0x00000000 | HLEN79[27:24] (RW)（Huffman 长度 79）、HCODE79[23:16] (RW)（Huffman 编码 79）、HLEN78[11:8] (RW)（Huffman 长度 78）、HCODE78[7:0] (RW)（Huffman 编码 78） | — |
| `JPEG_HUFFENC_AC1_40` | JPEG Huffman 编码器 AC1 | `0x67C` | `0x5200367C` | 32 | — | 0x00000000 / 0x00000000 | HLEN81[27:24] (RW)（Huffman 长度 81）、HCODE81[23:16] (RW)（Huffman 编码 81）、HLEN80[11:8] (RW)（Huffman 长度 80）、HCODE80[7:0] (RW)（Huffman 编码 80） | — |
| `JPEG_HUFFENC_AC1_41` | JPEG Huffman 编码器 AC1 | `0x680` | `0x52003680` | 32 | — | 0x00000000 / 0x00000000 | HLEN83[27:24] (RW)（Huffman 长度 83）、HCODE83[23:16] (RW)（Huffman 编码 83）、HLEN82[11:8] (RW)（Huffman 长度 82）、HCODE82[7:0] (RW)（Huffman 编码 82） | — |
| `JPEG_HUFFENC_AC1_42` | JPEG Huffman 编码器 AC1 | `0x684` | `0x52003684` | 32 | — | 0x00000000 / 0x00000000 | HLEN85[27:24] (RW)（Huffman 长度 85）、HCODE85[23:16] (RW)（Huffman 编码 85）、HLEN84[11:8] (RW)（Huffman 长度 84）、HCODE84[7:0] (RW)（Huffman 编码 84） | — |
| `JPEG_HUFFENC_AC1_43` | JPEG Huffman 编码器 AC1 | `0x688` | `0x52003688` | 32 | — | 0x00000000 / 0x00000000 | HLEN87[27:24] (RW)（Huffman 长度 87）、HCODE87[23:16] (RW)（Huffman 编码 87）、HLEN86[11:8] (RW)（Huffman 长度 86）、HCODE86[7:0] (RW)（Huffman 编码 86） | — |
| `JPEG_HUFFENC_AC1_44` | JPEG Huffman 编码器 AC1 | `0x68C` | `0x5200368C` | 32 | — | 0x00000000 / 0x00000000 | HLEN89[27:24] (RW)（Huffman 长度 89）、HCODE89[23:16] (RW)（Huffman 编码 89）、HLEN88[11:8] (RW)（Huffman 长度 88）、HCODE88[7:0] (RW)（Huffman 编码 88） | — |
| `JPEG_HUFFENC_AC1_45` | JPEG Huffman 编码器 AC1 | `0x690` | `0x52003690` | 32 | — | 0x00000000 / 0x00000000 | HLEN91[27:24] (RW)（Huffman 长度 91）、HCODE91[23:16] (RW)（Huffman 编码 91）、HLEN90[11:8] (RW)（Huffman 长度 90）、HCODE90[7:0] (RW)（Huffman 编码 90） | — |
| `JPEG_HUFFENC_AC1_46` | JPEG Huffman 编码器 AC1 | `0x694` | `0x52003694` | 32 | — | 0x00000000 / 0x00000000 | HLEN93[27:24] (RW)（Huffman 长度 93）、HCODE93[23:16] (RW)（Huffman 编码 93）、HLEN92[11:8] (RW)（Huffman 长度 92）、HCODE92[7:0] (RW)（Huffman 编码 92） | — |
| `JPEG_HUFFENC_AC1_47` | JPEG Huffman 编码器 AC1 | `0x698` | `0x52003698` | 32 | — | 0x00000000 / 0x00000000 | HLEN95[27:24] (RW)（Huffman 长度 95）、HCODE95[23:16] (RW)（Huffman 编码 95）、HLEN94[11:8] (RW)（Huffman 长度 94）、HCODE94[7:0] (RW)（Huffman 编码 94） | — |
| `JPEG_HUFFENC_AC1_48` | JPEG Huffman 编码器 AC1 | `0x69C` | `0x5200369C` | 32 | — | 0x00000000 / 0x00000000 | HLEN97[27:24] (RW)（Huffman 长度 97）、HCODE97[23:16] (RW)（Huffman 编码 97）、HLEN96[11:8] (RW)（Huffman 长度 96）、HCODE96[7:0] (RW)（Huffman 编码 96） | — |
| `JPEG_HUFFENC_AC1_49` | JPEG Huffman 编码器 AC1 | `0x6A0` | `0x520036A0` | 32 | — | 0x00000000 / 0x00000000 | HLEN99[27:24] (RW)（Huffman 长度 99）、HCODE99[23:16] (RW)（Huffman 编码 99）、HLEN98[11:8] (RW)（Huffman 长度 98）、HCODE98[7:0] (RW)（Huffman 编码 98） | — |
| `JPEG_HUFFENC_AC1_50` | JPEG Huffman 编码器 AC1 | `0x6A4` | `0x520036A4` | 32 | — | 0x00000000 / 0x00000000 | HLEN101[27:24] (RW)（Huffman 长度 101）、HCODE101[23:16] (RW)（Huffman 编码 101）、HLEN100[11:8] (RW)（Huffman 长度 100）、HCODE100[7:0] (RW)（Huffman 编码 100） | — |
| `JPEG_HUFFENC_AC1_51` | JPEG Huffman 编码器 AC1 | `0x6A8` | `0x520036A8` | 32 | — | 0x00000000 / 0x00000000 | HLEN103[27:24] (RW)（Huffman 长度 103）、HCODE103[23:16] (RW)（Huffman 编码 103）、HLEN102[11:8] (RW)（Huffman 长度 102）、HCODE102[7:0] (RW)（Huffman 编码 102） | — |
| `JPEG_HUFFENC_AC1_52` | JPEG Huffman 编码器 AC1 | `0x6AC` | `0x520036AC` | 32 | — | 0x00000000 / 0x00000000 | HLEN105[27:24] (RW)（Huffman 长度 105）、HCODE105[23:16] (RW)（Huffman 编码 105）、HLEN104[11:8] (RW)（Huffman 长度 104）、HCODE104[7:0] (RW)（Huffman 编码 104） | — |
| `JPEG_HUFFENC_AC1_53` | JPEG Huffman 编码器 AC1 | `0x6B0` | `0x520036B0` | 32 | — | 0x00000000 / 0x00000000 | HLEN107[27:24] (RW)（Huffman 长度 107）、HCODE107[23:16] (RW)（Huffman 编码 107）、HLEN106[11:8] (RW)（Huffman 长度 106）、HCODE106[7:0] (RW)（Huffman 编码 106） | — |
| `JPEG_HUFFENC_AC1_54` | JPEG Huffman 编码器 AC1 | `0x6B4` | `0x520036B4` | 32 | — | 0x00000000 / 0x00000000 | HLEN109[27:24] (RW)（Huffman 长度 109）、HCODE109[23:16] (RW)（Huffman 编码 109）、HLEN108[11:8] (RW)（Huffman 长度 108）、HCODE108[7:0] (RW)（Huffman 编码 108） | — |
| `JPEG_HUFFENC_AC1_55` | JPEG Huffman 编码器 AC1 | `0x6B8` | `0x520036B8` | 32 | — | 0x00000000 / 0x00000000 | HLEN111[27:24] (RW)（Huffman 长度 111）、HCODE111[23:16] (RW)（Huffman 编码 111）、HLEN110[11:8] (RW)（Huffman 长度 110）、HCODE110[7:0] (RW)（Huffman 编码 110） | — |
| `JPEG_HUFFENC_AC1_56` | JPEG Huffman 编码器 AC1 | `0x6BC` | `0x520036BC` | 32 | — | 0x00000000 / 0x00000000 | HLEN113[27:24] (RW)（Huffman 长度 113）、HCODE113[23:16] (RW)（Huffman 编码 113）、HLEN112[11:8] (RW)（Huffman 长度 112）、HCODE112[7:0] (RW)（Huffman 编码 112） | — |
| `JPEG_HUFFENC_AC1_57` | JPEG Huffman 编码器 AC1 | `0x6C0` | `0x520036C0` | 32 | — | 0x00000000 / 0x00000000 | HLEN115[27:24] (RW)（Huffman 长度 115）、HCODE115[23:16] (RW)（Huffman 编码 115）、HLEN114[11:8] (RW)（Huffman 长度 114）、HCODE114[7:0] (RW)（Huffman 编码 114） | — |
| `JPEG_HUFFENC_AC1_58` | JPEG Huffman 编码器 AC1 | `0x6C4` | `0x520036C4` | 32 | — | 0x00000000 / 0x00000000 | HLEN117[27:24] (RW)（Huffman 长度 117）、HCODE117[23:16] (RW)（Huffman 编码 117）、HLEN116[11:8] (RW)（Huffman 长度 116）、HCODE116[7:0] (RW)（Huffman 编码 116） | — |
| `JPEG_HUFFENC_AC1_59` | JPEG Huffman 编码器 AC1 | `0x6C8` | `0x520036C8` | 32 | — | 0x00000000 / 0x00000000 | HLEN119[27:24] (RW)（Huffman 长度 119）、HCODE119[23:16] (RW)（Huffman 编码 119）、HLEN118[11:8] (RW)（Huffman 长度 118）、HCODE118[7:0] (RW)（Huffman 编码 118） | — |
| `JPEG_HUFFENC_AC1_60` | JPEG Huffman 编码器 AC1 | `0x6CC` | `0x520036CC` | 32 | — | 0x00000000 / 0x00000000 | HLEN121[27:24] (RW)（Huffman 长度 121）、HCODE121[23:16] (RW)（Huffman 编码 121）、HLEN120[11:8] (RW)（Huffman 长度 120）、HCODE120[7:0] (RW)（Huffman 编码 120） | — |
| `JPEG_HUFFENC_AC1_61` | JPEG Huffman 编码器 AC1 | `0x6D0` | `0x520036D0` | 32 | — | 0x00000000 / 0x00000000 | HLEN123[27:24] (RW)（Huffman 长度 123）、HCODE123[23:16] (RW)（Huffman 编码 123）、HLEN122[11:8] (RW)（Huffman 长度 122）、HCODE122[7:0] (RW)（Huffman 编码 122） | — |
| `JPEG_HUFFENC_AC1_62` | JPEG Huffman 编码器 AC1 | `0x6D4` | `0x520036D4` | 32 | — | 0x00000000 / 0x00000000 | HLEN125[27:24] (RW)（Huffman 长度 125）、HCODE125[23:16] (RW)（Huffman 编码 125）、HLEN124[11:8] (RW)（Huffman 长度 124）、HCODE124[7:0] (RW)（Huffman 编码 124） | — |
| `JPEG_HUFFENC_AC1_63` | JPEG Huffman 编码器 AC1 | `0x6D8` | `0x520036D8` | 32 | — | 0x00000000 / 0x00000000 | HLEN127[27:24] (RW)（Huffman 长度 127）、HCODE127[23:16] (RW)（Huffman 编码 127）、HLEN126[11:8] (RW)（Huffman 长度 126）、HCODE126[7:0] (RW)（Huffman 编码 126） | — |
| `JPEG_HUFFENC_AC1_64` | JPEG Huffman 编码器 AC1 | `0x6DC` | `0x520036DC` | 32 | — | 0x00000000 / 0x00000000 | HLEN129[27:24] (RW)（Huffman 长度 129）、HCODE129[23:16] (RW)（Huffman 编码 129）、HLEN128[11:8] (RW)（Huffman 长度 128）、HCODE128[7:0] (RW)（Huffman 编码 128） | — |
| `JPEG_HUFFENC_AC1_65` | JPEG Huffman 编码器 AC1 | `0x6E0` | `0x520036E0` | 32 | — | 0x00000000 / 0x00000000 | HLEN131[27:24] (RW)（Huffman 长度 131）、HCODE131[23:16] (RW)（Huffman 编码 131）、HLEN130[11:8] (RW)（Huffman 长度 130）、HCODE130[7:0] (RW)（Huffman 编码 130） | — |
| `JPEG_HUFFENC_AC1_66` | JPEG Huffman 编码器 AC1 | `0x6E4` | `0x520036E4` | 32 | — | 0x00000000 / 0x00000000 | HLEN133[27:24] (RW)（Huffman 长度 133）、HCODE133[23:16] (RW)（Huffman 编码 133）、HLEN132[11:8] (RW)（Huffman 长度 132）、HCODE132[7:0] (RW)（Huffman 编码 132） | — |
| `JPEG_HUFFENC_AC1_67` | JPEG Huffman 编码器 AC1 | `0x6E8` | `0x520036E8` | 32 | — | 0x00000000 / 0x00000000 | HLEN135[27:24] (RW)（Huffman 长度 135）、HCODE135[23:16] (RW)（Huffman 编码 135）、HLEN134[11:8] (RW)（Huffman 长度 134）、HCODE134[7:0] (RW)（Huffman 编码 134） | — |
| `JPEG_HUFFENC_AC1_68` | JPEG Huffman 编码器 AC1 | `0x6EC` | `0x520036EC` | 32 | — | 0x00000000 / 0x00000000 | HLEN137[27:24] (RW)（Huffman 长度 137）、HCODE137[23:16] (RW)（Huffman 编码 137）、HLEN136[11:8] (RW)（Huffman 长度 136）、HCODE136[7:0] (RW)（Huffman 编码 136） | — |
| `JPEG_HUFFENC_AC1_69` | JPEG Huffman 编码器 AC1 | `0x6F0` | `0x520036F0` | 32 | — | 0x00000000 / 0x00000000 | HLEN139[27:24] (RW)（Huffman 长度 139）、HCODE139[23:16] (RW)（Huffman 编码 139）、HLEN138[11:8] (RW)（Huffman 长度 138）、HCODE138[7:0] (RW)（Huffman 编码 138） | — |
| `JPEG_HUFFENC_AC1_70` | JPEG Huffman 编码器 AC1 | `0x6F4` | `0x520036F4` | 32 | — | 0x00000000 / 0x00000000 | HLEN141[27:24] (RW)（Huffman 长度 141）、HCODE141[23:16] (RW)（Huffman 编码 141）、HLEN140[11:8] (RW)（Huffman 长度 140）、HCODE140[7:0] (RW)（Huffman 编码 140） | — |
| `JPEG_HUFFENC_AC1_71` | JPEG Huffman 编码器 AC1 | `0x6F8` | `0x520036F8` | 32 | — | 0x00000000 / 0x00000000 | HLEN143[27:24] (RW)（Huffman 长度 143）、HCODE143[23:16] (RW)（Huffman 编码 143）、HLEN142[11:8] (RW)（Huffman 长度 142）、HCODE142[7:0] (RW)（Huffman 编码 142） | — |
| `JPEG_HUFFENC_AC1_72` | JPEG Huffman 编码器 AC1 | `0x6FC` | `0x520036FC` | 32 | — | 0x00000000 / 0x00000000 | HLEN145[27:24] (RW)（Huffman 长度 145）、HCODE145[23:16] (RW)（Huffman 编码 145）、HLEN144[11:8] (RW)（Huffman 长度 144）、HCODE144[7:0] (RW)（Huffman 编码 144） | — |
| `JPEG_HUFFENC_AC1_73` | JPEG Huffman 编码器 AC1 | `0x700` | `0x52003700` | 32 | — | 0x00000000 / 0x00000000 | HLEN147[27:24] (RW)（Huffman 长度 147）、HCODE147[23:16] (RW)（Huffman 编码 147）、HLEN146[11:8] (RW)（Huffman 长度 146）、HCODE146[7:0] (RW)（Huffman 编码 146） | — |
| `JPEG_HUFFENC_AC1_74` | JPEG Huffman 编码器 AC1 | `0x704` | `0x52003704` | 32 | — | 0x00000000 / 0x00000000 | HLEN149[27:24] (RW)（Huffman 长度 149）、HCODE149[23:16] (RW)（Huffman 编码 149）、HLEN148[11:8] (RW)（Huffman 长度 148）、HCODE148[7:0] (RW)（Huffman 编码 148） | — |
| `JPEG_HUFFENC_AC1_75` | JPEG Huffman 编码器 AC1 | `0x708` | `0x52003708` | 32 | — | 0x00000000 / 0x00000000 | HLEN151[27:24] (RW)（Huffman 长度 151）、HCODE151[23:16] (RW)（Huffman 编码 151）、HLEN150[11:8] (RW)（Huffman 长度 150）、HCODE150[7:0] (RW)（Huffman 编码 150） | — |
| `JPEG_HUFFENC_AC1_76` | JPEG Huffman 编码器 AC1 | `0x70C` | `0x5200370C` | 32 | — | 0x00000000 / 0x00000000 | HLEN153[27:24] (RW)（Huffman 长度 153）、HCODE153[23:16] (RW)（Huffman 编码 153）、HLEN152[11:8] (RW)（Huffman 长度 152）、HCODE152[7:0] (RW)（Huffman 编码 152） | — |
| `JPEG_HUFFENC_AC1_77` | JPEG Huffman 编码器 AC1 | `0x710` | `0x52003710` | 32 | — | 0x00000000 / 0x00000000 | HLEN155[27:24] (RW)（Huffman 长度 155）、HCODE155[23:16] (RW)（Huffman 编码 155）、HLEN154[11:8] (RW)（Huffman 长度 154）、HCODE154[7:0] (RW)（Huffman 编码 154） | — |
| `JPEG_HUFFENC_AC1_78` | JPEG Huffman 编码器 AC1 | `0x714` | `0x52003714` | 32 | — | 0x00000000 / 0x00000000 | HLEN157[27:24] (RW)（Huffman 长度 157）、HCODE157[23:16] (RW)（Huffman 编码 157）、HLEN156[11:8] (RW)（Huffman 长度 156）、HCODE156[7:0] (RW)（Huffman 编码 156） | — |
| `JPEG_HUFFENC_AC1_79` | JPEG Huffman 编码器 AC1 | `0x718` | `0x52003718` | 32 | — | 0x00000000 / 0x00000000 | HLEN159[27:24] (RW)（Huffman 长度 159）、HCODE159[23:16] (RW)（Huffman 编码 159）、HLEN158[11:8] (RW)（Huffman 长度 158）、HCODE158[7:0] (RW)（Huffman 编码 158） | — |
| `JPEG_HUFFENC_AC1_80` | JPEG Huffman 编码器 AC1 | `0x71C` | `0x5200371C` | 32 | — | 0x00000000 / 0x00000000 | HLEN161[27:24] (RW)（Huffman 长度 161）、HCODE161[23:16] (RW)（Huffman 编码 161）、HLEN160[11:8] (RW)（Huffman 长度 160）、HCODE160[7:0] (RW)（Huffman 编码 160） | — |
| `JPEG_HUFFENC_AC1_81` | JPEG Huffman 编码器 AC1 | `0x720` | `0x52003720` | 32 | — | 0x00000000 / 0x00000000 | HLEN163[27:24] (RW)（Huffman 长度 163）、HCODE163[23:16] (RW)（Huffman 编码 163）、HLEN162[11:8] (RW)（Huffman 长度 162）、HCODE162[7:0] (RW)（Huffman 编码 162） | — |
| `JPEG_HUFFENC_AC1_82` | JPEG Huffman 编码器 AC1 | `0x724` | `0x52003724` | 32 | — | 0x00000000 / 0x00000000 | HLEN165[27:24] (RW)（Huffman 长度 165）、HCODE165[23:16] (RW)（Huffman 编码 165）、HLEN164[11:8] (RW)（Huffman 长度 164）、HCODE164[7:0] (RW)（Huffman 编码 164） | — |
| `JPEG_HUFFENC_AC1_83` | JPEG Huffman 编码器 AC1 | `0x728` | `0x52003728` | 32 | — | 0x00000000 / 0x00000000 | HLEN167[27:24] (RW)（Huffman 长度 167）、HCODE167[23:16] (RW)（Huffman 编码 167）、HLEN166[11:8] (RW)（Huffman 长度 166）、HCODE166[7:0] (RW)（Huffman 编码 166） | — |
| `JPEG_HUFFENC_AC1_84` | JPEG Huffman 编码器 AC1 | `0x72C` | `0x5200372C` | 32 | — | 0x00000000 / 0x00000000 | HLEN169[27:24] (RW)（Huffman 长度 169）、HCODE169[23:16] (RW)（Huffman 编码 169）、HLEN168[11:8] (RW)（Huffman 长度 168）、HCODE168[7:0] (RW)（Huffman 编码 168） | — |
| `JPEG_HUFFENC_AC1_85` | JPEG Huffman 编码器 AC1 | `0x730` | `0x52003730` | 32 | — | 0x00000000 / 0x00000000 | HLEN171[27:24] (RW)（Huffman 长度 171）、HCODE171[23:16] (RW)（Huffman 编码 171）、HLEN170[11:8] (RW)（Huffman 长度 170）、HCODE170[7:0] (RW)（Huffman 编码 170） | — |
| `JPEG_HUFFENC_AC1_86` | JPEG Huffman 编码器 AC1 | `0x734` | `0x52003734` | 32 | — | 0x00000000 / 0x00000000 | HLEN173[27:24] (RW)（Huffman 长度 173）、HCODE173[23:16] (RW)（Huffman 编码 173）、HLEN172[11:8] (RW)（Huffman 长度 172）、HCODE172[7:0] (RW)（Huffman 编码 172） | — |
| `JPEG_HUFFENC_AC1_87` | JPEG Huffman 编码器 AC1 | `0x738` | `0x52003738` | 32 | — | 0x00000000 / 0x00000000 | HLEN175[27:24] (RW)（Huffman 长度 175）、HCODE175[23:16] (RW)（Huffman 编码 175）、HLEN174[11:8] (RW)（Huffman 长度 174）、HCODE174[7:0] (RW)（Huffman 编码 174） | — |
| `JPEG_HUFFENC_DC0_0` | JPEG Huffman 编码器 DC0 | `0x7C0` | `0x520037C0` | 32 | — | 0x00000000 / 0x00000000 | HLEN1[27:24] (RW)（Huffman 长度 1）、HCODE1[23:16] (RW)（Huffman 编码 1）、HLEN0[11:8] (RW)（Huffman 长度 0）、HCODE0[7:0] (RW)（Huffman 编码 0） | — |
| `JPEG_HUFFENC_DC0_1` | JPEG Huffman 编码器 DC0 | `0x7C4` | `0x520037C4` | 32 | — | 0x00000000 / 0x00000000 | HLEN3[27:24] (RW)（Huffman 长度 3）、HCODE3[23:16] (RW)（Huffman 编码 3）、HLEN2[11:8] (RW)（Huffman 长度 2）、HCODE2[7:0] (RW)（Huffman 编码 2） | — |
| `JPEG_HUFFENC_DC0_2` | JPEG Huffman 编码器 DC0 | `0x7C8` | `0x520037C8` | 32 | — | 0x00000000 / 0x00000000 | HLEN5[27:24] (RW)（Huffman 长度 5）、HCODE5[23:16] (RW)（Huffman 编码 5）、HLEN4[11:8] (RW)（Huffman 长度 4）、HCODE4[7:0] (RW)（Huffman 编码 4） | — |
| `JPEG_HUFFENC_DC0_3` | JPEG Huffman 编码器 DC0 | `0x7CC` | `0x520037CC` | 32 | — | 0x00000000 / 0x00000000 | HLEN7[27:24] (RW)（Huffman 长度 7）、HCODE7[23:16] (RW)（Huffman 编码 7）、HLEN6[11:8] (RW)（Huffman 长度 6）、HCODE6[7:0] (RW)（Huffman 编码 6） | — |
| `JPEG_HUFFENC_DC0_4` | JPEG Huffman 编码器 DC0 | `0x7D0` | `0x520037D0` | 32 | — | 0x00000000 / 0x00000000 | HLEN9[27:24] (RW)（Huffman 长度 9）、HCODE9[23:16] (RW)（Huffman 编码 9）、HLEN8[11:8] (RW)（Huffman 长度 8）、HCODE8[7:0] (RW)（Huffman 编码 8） | — |
| `JPEG_HUFFENC_DC0_5` | JPEG Huffman 编码器 DC0 | `0x7D4` | `0x520037D4` | 32 | — | 0x00000000 / 0x00000000 | HLEN11[27:24] (RW)（Huffman 长度 11）、HCODE11[23:16] (RW)（Huffman 编码 11）、HLEN10[11:8] (RW)（Huffman 长度 10）、HCODE10[7:0] (RW)（Huffman 编码 10） | — |
| `JPEG_HUFFENC_DC0_6` | JPEG Huffman 编码器 DC0 | `0x7D8` | `0x520037D8` | 32 | — | 0x00000000 / 0x00000000 | HLEN13[27:24] (RW)（Huffman 长度 13）、HCODE13[23:16] (RW)（Huffman 编码 13）、HLEN12[11:8] (RW)（Huffman 长度 12）、HCODE12[7:0] (RW)（Huffman 编码 12） | — |
| `JPEG_HUFFENC_DC0_7` | JPEG Huffman 编码器 DC0 | `0x7DC` | `0x520037DC` | 32 | — | 0x00000000 / 0x00000000 | HLEN15[27:24] (RW)（Huffman 长度 15）、HCODE15[23:16] (RW)（Huffman 编码 15）、HLEN14[11:8] (RW)（Huffman 长度 14）、HCODE14[7:0] (RW)（Huffman 编码 14） | — |
| `JPEG_HUFFENC_DC1_0` | JPEG Huffman 编码器 DC1 | `0x89C` | `0x5200389C` | 32 | — | 0x00000000 / 0x00000000 | HLEN1[27:24] (RW)（Huffman 长度 1）、HCODE1[23:16] (RW)（Huffman 编码 1）、HLEN0[11:8] (RW)（Huffman 长度 0）、HCODE0[7:0] (RW)（Huffman 编码 0） | — |
| `JPEG_HUFFENC_DC1_1` | JPEG Huffman 编码器 DC1 | `0x8A0` | `0x520038A0` | 32 | — | 0x00000000 / 0x00000000 | HLEN3[27:24] (RW)（Huffman 长度 3）、HCODE3[23:16] (RW)（Huffman 编码 3）、HLEN2[11:8] (RW)（Huffman 长度 2）、HCODE2[7:0] (RW)（Huffman 编码 2） | — |
| `JPEG_HUFFENC_DC1_2` | JPEG Huffman 编码器 DC1 | `0x8A4` | `0x520038A4` | 32 | — | 0x00000000 / 0x00000000 | HLEN5[27:24] (RW)（Huffman 长度 5）、HCODE5[23:16] (RW)（Huffman 编码 5）、HLEN4[11:8] (RW)（Huffman 长度 4）、HCODE4[7:0] (RW)（Huffman 编码 4） | — |
| `JPEG_HUFFENC_DC1_3` | JPEG Huffman 编码器 DC1 | `0x8A8` | `0x520038A8` | 32 | — | 0x00000000 / 0x00000000 | HLEN7[27:24] (RW)（Huffman 长度 7）、HCODE7[23:16] (RW)（Huffman 编码 7）、HLEN6[11:8] (RW)（Huffman 长度 6）、HCODE6[7:0] (RW)（Huffman 编码 6） | — |
| `JPEG_HUFFENC_DC1_4` | JPEG Huffman 编码器 DC1 | `0x8AC` | `0x520038AC` | 32 | — | 0x00000000 / 0x00000000 | HLEN9[27:24] (RW)（Huffman 长度 9）、HCODE9[23:16] (RW)（Huffman 编码 9）、HLEN8[11:8] (RW)（Huffman 长度 8）、HCODE8[7:0] (RW)（Huffman 编码 8） | — |
| `JPEG_HUFFENC_DC1_5` | JPEG Huffman 编码器 DC1 | `0x8B0` | `0x520038B0` | 32 | — | 0x00000000 / 0x00000000 | HLEN11[27:24] (RW)（Huffman 长度 11）、HCODE11[23:16] (RW)（Huffman 编码 11）、HLEN10[11:8] (RW)（Huffman 长度 10）、HCODE10[7:0] (RW)（Huffman 编码 10） | — |
| `JPEG_HUFFENC_DC1_6` | JPEG Huffman 编码器 DC1 | `0x8B4` | `0x520038B4` | 32 | — | 0x00000000 / 0x00000000 | HLEN13[27:24] (RW)（Huffman 长度 13）、HCODE13[23:16] (RW)（Huffman 编码 13）、HLEN12[11:8] (RW)（Huffman 长度 12）、HCODE12[7:0] (RW)（Huffman 编码 12） | — |
| `JPEG_HUFFENC_DC1_7` | JPEG Huffman 编码器 DC1 | `0x8B8` | `0x520038B8` | 32 | — | 0x00000000 / 0x00000000 | HLEN15[27:24] (RW)（Huffman 长度 15）、HCODE15[23:16] (RW)（Huffman 编码 15）、HLEN14[11:8] (RW)（Huffman 长度 14）、HCODE14[7:0] (RW)（Huffman 编码 14） | — |

## JPEG_CMSIS

**模块用途**　JPEG 编解码器的芯片头文件补充视图，和 JPEG 主表对照使用。

基地址 `0x52003000` · CMSIS 补表

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `HUFFENC_AC1[55]` | Huffman 编码表补充条目 | `0x73C` | `0x5200373C` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[56]` | Huffman 编码表补充条目 | `0x740` | `0x52003740` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[57]` | Huffman 编码表补充条目 | `0x744` | `0x52003744` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[58]` | Huffman 编码表补充条目 | `0x748` | `0x52003748` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[59]` | Huffman 编码表补充条目 | `0x74C` | `0x5200374C` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[60]` | Huffman 编码表补充条目 | `0x750` | `0x52003750` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[61]` | Huffman 编码表补充条目 | `0x754` | `0x52003754` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[62]` | Huffman 编码表补充条目 | `0x758` | `0x52003758` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[63]` | Huffman 编码表补充条目 | `0x75C` | `0x5200375C` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[64]` | Huffman 编码表补充条目 | `0x760` | `0x52003760` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[65]` | Huffman 编码表补充条目 | `0x764` | `0x52003764` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[66]` | Huffman 编码表补充条目 | `0x768` | `0x52003768` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[67]` | Huffman 编码表补充条目 | `0x76C` | `0x5200376C` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[68]` | Huffman 编码表补充条目 | `0x770` | `0x52003770` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[69]` | Huffman 编码表补充条目 | `0x774` | `0x52003774` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[70]` | Huffman 编码表补充条目 | `0x778` | `0x52003778` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[71]` | Huffman 编码表补充条目 | `0x77C` | `0x5200377C` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[72]` | Huffman 编码表补充条目 | `0x780` | `0x52003780` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[73]` | Huffman 编码表补充条目 | `0x784` | `0x52003784` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[74]` | Huffman 编码表补充条目 | `0x788` | `0x52003788` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[75]` | Huffman 编码表补充条目 | `0x78C` | `0x5200378C` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[76]` | Huffman 编码表补充条目 | `0x790` | `0x52003790` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[77]` | Huffman 编码表补充条目 | `0x794` | `0x52003794` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[78]` | Huffman 编码表补充条目 | `0x798` | `0x52003798` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[79]` | Huffman 编码表补充条目 | `0x79C` | `0x5200379C` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[80]` | Huffman 编码表补充条目 | `0x7A0` | `0x520037A0` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[81]` | Huffman 编码表补充条目 | `0x7A4` | `0x520037A4` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[82]` | Huffman 编码表补充条目 | `0x7A8` | `0x520037A8` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[83]` | Huffman 编码表补充条目 | `0x7AC` | `0x520037AC` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[84]` | Huffman 编码表补充条目 | `0x7B0` | `0x520037B0` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[85]` | Huffman 编码表补充条目 | `0x7B4` | `0x520037B4` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[86]` | Huffman 编码表补充条目 | `0x7B8` | `0x520037B8` | 32 | — | — / — | — | — |
| `HUFFENC_AC1[87]` | Huffman 编码表补充条目 | `0x7BC` | `0x520037BC` | 32 | — | — / — | — | — |
| `HUFFENC_DC1[0]` | Huffman 编码表补充条目 | `0x7E0` | `0x520037E0` | 32 | — | — / — | — | — |
| `HUFFENC_DC1[1]` | Huffman 编码表补充条目 | `0x7E4` | `0x520037E4` | 32 | — | — / — | — | — |
| `HUFFENC_DC1[2]` | Huffman 编码表补充条目 | `0x7E8` | `0x520037E8` | 32 | — | — / — | — | — |
| `HUFFENC_DC1[3]` | Huffman 编码表补充条目 | `0x7EC` | `0x520037EC` | 32 | — | — / — | — | — |
| `HUFFENC_DC1[4]` | Huffman 编码表补充条目 | `0x7F0` | `0x520037F0` | 32 | — | — / — | — | — |
| `HUFFENC_DC1[5]` | Huffman 编码表补充条目 | `0x7F4` | `0x520037F4` | 32 | — | — / — | — | — |
| `HUFFENC_DC1[6]` | Huffman 编码表补充条目 | `0x7F8` | `0x520037F8` | 32 | — | — / — | — | — |
| `HUFFENC_DC1[7]` | Huffman 编码表补充条目 | `0x7FC` | `0x520037FC` | 32 | — | — / — | — | — |

## LTDC

**模块用途**　液晶显示控制器，从帧缓冲读取像素并生成显示接口的同步与数据时序。

基地址 `0x50001000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `LTDC_SSCR` | LTDC 同步大小配置寄存器 | `0x008` | `0x50001008` | 32 | — | 0x00000000 / 0xFFFFFFFF | HSW[27:16] (RW)（待核）、VSH[10:0] (RW)（待核） | — |
| `LTDC_BPCR` | LTDC 后沿配置寄存器 | `0x00C` | `0x5000100C` | 32 | — | 0x00000000 / 0xFFFFFFFF | AHBP[27:16] (RW)（待核）、AVBP[10:0] (RW)（待核） | — |
| `LTDC_AWCR` | LTDC 活动宽度配置寄存器 | `0x010` | `0x50001010` | 32 | — | 0x00000000 / 0xFFFFFFFF | AAW[27:16] (RW)（待核）、AAH[10:0] (RW)（待核） | — |
| `LTDC_TWCR` | LTDC 总计宽度配置寄存器 | `0x014` | `0x50001014` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOTALW[27:16] (RW)（待核）、TOTALH[10:0] (RW)（待核） | — |
| `LTDC_GCR` | LTDC 全局控制寄存器 | `0x018` | `0x50001018` | 32 | — | 0x00002220 / 0xFFFFFFFF | HSPOL[31] (RW)（水平同步极性）、VSPOL[30] (RW)（垂直同步极性）、DEPOL[29] (RW)（待核）、PCPOL[28] (RW)（像素时钟极性）、DEN[16] (RW)（待核）、DRW[14:12] (RO)（待核）、DGW[10:8] (RO)（待核）、DBW[6:4] (RO)（待核）、LTDCEN[0] (RW)（LCD-TFT 控制器使能） | — |
| `LTDC_SRCR` | LTDC 影子重装配置寄存器 | `0x024` | `0x50001024` | 32 | — | 0x00000000 / 0xFFFFFFFF | VBR[1] (RW)（待核）、IMR[0] (RW)（待核） | — |
| `LTDC_BCCR` | LTDC 背景颜色配置寄存器 | `0x02C` | `0x5000102C` | 32 | — | 0x00000000 / 0xFFFFFFFF | BCRED[23:16] (RW)（背景颜色红色值）、BCGREEN[15:8] (RW)（背景颜色绿色值）、BCBLUE[7:0] (RW)（背景颜色蓝色值） | — |
| `LTDC_IER` | LTDC 中断使能寄存器 | `0x034` | `0x50001034` | 32 | — | 0x00000000 / 0xFFFFFFFF | RRIE[3] (RW)（寄存器重装中断使能）、TERRIE[2] (RW)（传输错误中断使能）、FUIE[1] (RW)（FIFO 欠载中断使能）、LIE[0] (RW)（行中断使能） | — |
| `LTDC_ISR` | LTDC 中断状态寄存器 | `0x038` | `0x50001038` | 32 | — | 0x00000000 / 0xFFFFFFFF | RRIF[3] (RO)（寄存器重装中断标志）、TERRIF[2] (RO)（传输错误中断标志）、FUIF[1] (RO)（FIFO 欠载中断标志）、LIF[0] (RO)（行中断标志） | — |
| `LTDC_ICR` | LTDC 中断清除寄存器 | `0x03C` | `0x5000103C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CRRIF[3] (WO)（待核）、CTERRIF[2] (WO)（待核）、CFUIF[1] (WO)（待核）、CLIF[0] (WO)（待核） | — |
| `LTDC_LIPCR` | LTDC 行中断位置配置寄存器 | `0x040` | `0x50001040` | 32 | — | 0x00000000 / 0xFFFFFFFF | LIPOS[10:0] (RW)（行中断位置） | — |
| `LTDC_CPSR` | LTDC 当前位置状态寄存器 | `0x044` | `0x50001044` | 32 | — | 0x00000000 / 0xFFFFFFFF | CXPOS[31:16] (RO)（当前 X 位置）、CYPOS[15:0] (RO)（当前 Y 位置） | — |
| `LTDC_CDSR` | LTDC 当前显示状态寄存器 | `0x048` | `0x50001048` | 32 | — | 0x0000000F / 0xFFFFFFFF | HSYNCS[3] (RO)（水平同步显示状态）、VSYNCS[2] (RO)（垂直同步显示状态）、HDES[1] (RO)（水平数据使能显示状态）、VDES[0] (RO)（垂直数据使能显示状态） | — |
| `LTDC_L1CR` | LTDC 图层 1 控制寄存器 | `0x084` | `0x50001084` | 32 | — | 0x00000000 / 0xFFFFFFFF | CLUTEN[4] (RW)（颜色查找表使能）、COLKEN[1] (RW)（色键使能）、LEN[0] (RW)（图层使能） | — |
| `LTDC_L1WHPCR` | LTDC 图层 1 窗口水平位置配置寄存器 | `0x088` | `0x50001088` | 32 | — | 0x00000000 / 0xFFFFFFFF | WHSPPOS[27:16] (RW)（窗口水平停止位置）、WHSTPOS[11:0] (RW)（窗口水平启动位置） | — |
| `LTDC_L1WVPCR` | LTDC 图层 1 窗口垂直位置配置寄存器 | `0x08C` | `0x5000108C` | 32 | — | 0x00000000 / 0xFFFFFFFF | WVSPPOS[26:16] (RW)（窗口垂直停止位置）、WVSTPOS[10:0] (RW)（窗口垂直启动位置） | — |
| `LTDC_L1CKCR` | LTDC 图层 1 色键配置寄存器 | `0x090` | `0x50001090` | 32 | — | 0x00000000 / 0xFFFFFFFF | CKRED[23:16] (RW)（颜色密钥红色值）、CKGREEN[15:8] (RW)（颜色密钥绿色值）、CKBLUE[7:0] (RW)（颜色密钥蓝色值） | — |
| `LTDC_L1PFCR` | LTDC 图层 1 像素格式配置寄存器 | `0x094` | `0x50001094` | 32 | — | 0x00000000 / 0xFFFFFFFF | PF[2:0] (RW)（像素格式） | — |
| `LTDC_L1CACR` | LTDC 图层 1 恒定透明度配置寄存器 | `0x098` | `0x50001098` | 32 | — | 0x000000FF / 0xFFFFFFFF | CONSTA[7:0] (RW)（恒定透明度） | — |
| `LTDC_L1DCCR` | LTDC 图层 1 默认颜色配置寄存器 | `0x09C` | `0x5000109C` | 32 | — | 0x00000000 / 0xFFFFFFFF | DCALPHA[31:24] (RW)（默认颜色透明度）、DCRED[23:16] (RW)（默认颜色红色）、DCGREEN[15:8] (RW)（默认颜色绿色）、DCBLUE[7:0] (RW)（默认颜色蓝色） | — |
| `LTDC_L1BFCR` | LTDC 图层 1 混合系数配置寄存器 | `0x0A0` | `0x500010A0` | 32 | — | 0x00000607 / 0xFFFFFFFF | BF1[10:8] (RW)（待核）、BF2[2:0] (RW)（待核） | — |
| `LTDC_L1CFBAR` | LTDC 图层 1 颜色帧缓冲地址寄存器 | `0x0AC` | `0x500010AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | CFBADD[31:0] (RW)（颜色帧缓冲启动地址） | — |
| `LTDC_L1CFBLR` | LTDC 图层 1 颜色帧缓冲长度寄存器 | `0x0B0` | `0x500010B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | CFBP[28:16] (RW)（待核）、CFBLL[12:0] (RW)（颜色帧缓冲行长度） | — |
| `LTDC_L1CFBLNR` | LTDC 图层 1 颜色帧缓冲行编号寄存器 | `0x0B4` | `0x500010B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | CFBLNBR[10:0] (RW)（帧缓冲行编号） | — |
| `LTDC_L1CLUTWR` | LTDC 图层 1 颜色查找表写入寄存器 | `0x0C4` | `0x500010C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | CLUTADD[31:24] (WO)（颜色查找表地址）、RED[23:16] (WO)（红色值）、GREEN[15:8] (WO)（绿色值）、BLUE[7:0] (WO)（蓝色值） | — |
| `LTDC_L2CR` | LTDC 图层 2 控制寄存器 | `0x104` | `0x50001104` | 32 | — | 0x00000000 / 0xFFFFFFFF | CLUTEN[4] (RW)（颜色查找表使能）、COLKEN[1] (RW)（色键使能）、LEN[0] (RW)（图层使能） | — |
| `LTDC_L2WHPCR` | LTDC 图层 2 窗口水平位置配置寄存器 | `0x108` | `0x50001108` | 32 | — | 0x00000000 / 0xFFFFFFFF | WHSPPOS[27:16] (RW)（窗口水平停止位置）、WHSTPOS[11:0] (RW)（窗口水平启动位置） | — |
| `LTDC_L2WVPCR` | LTDC 图层 2 窗口垂直位置配置寄存器 | `0x10C` | `0x5000110C` | 32 | — | 0x00000000 / 0xFFFFFFFF | WVSPPOS[26:16] (RW)（窗口垂直停止位置）、WVSTPOS[10:0] (RW)（窗口垂直启动位置） | — |
| `LTDC_L2CKCR` | LTDC 图层 2 色键配置寄存器 | `0x110` | `0x50001110` | 32 | — | 0x00000000 / 0xFFFFFFFF | CKRED[23:16] (RW)（颜色密钥红色值）、CKGREEN[15:8] (RW)（颜色密钥绿色值）、CKBLUE[7:0] (RW)（颜色密钥蓝色值） | — |
| `LTDC_L2PFCR` | LTDC 图层 2 像素格式配置寄存器 | `0x114` | `0x50001114` | 32 | — | 0x00000000 / 0xFFFFFFFF | PF[2:0] (RW)（像素格式） | — |
| `LTDC_L2CACR` | LTDC 图层 2 恒定透明度配置寄存器 | `0x118` | `0x50001118` | 32 | — | 0x000000FF / 0xFFFFFFFF | CONSTA[7:0] (RW)（恒定透明度） | — |
| `LTDC_L2DCCR` | LTDC 图层 2 默认颜色配置寄存器 | `0x11C` | `0x5000111C` | 32 | — | 0x00000000 / 0xFFFFFFFF | DCALPHA[31:24] (RW)（默认颜色透明度）、DCRED[23:16] (RW)（默认颜色红色）、DCGREEN[15:8] (RW)（默认颜色绿色）、DCBLUE[7:0] (RW)（默认颜色蓝色） | — |
| `LTDC_L2BFCR` | LTDC 图层 2 混合系数配置寄存器 | `0x120` | `0x50001120` | 32 | — | 0x00000607 / 0xFFFFFFFF | BF1[10:8] (RW)（待核）、BF2[2:0] (RW)（待核） | — |
| `LTDC_L2CFBAR` | LTDC 图层 2 颜色帧缓冲地址寄存器 | `0x12C` | `0x5000112C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CFBADD[31:0] (RW)（颜色帧缓冲启动地址） | — |
| `LTDC_L2CFBLR` | LTDC 图层 2 颜色帧缓冲长度寄存器 | `0x130` | `0x50001130` | 32 | — | 0x00000000 / 0xFFFFFFFF | CFBP[28:16] (RW)（待核）、CFBLL[12:0] (RW)（颜色帧缓冲行长度） | — |
| `LTDC_L2CFBLNR` | LTDC 图层 2 颜色帧缓冲行编号寄存器 | `0x134` | `0x50001134` | 32 | — | 0x00000000 / 0xFFFFFFFF | CFBLNBR[10:0] (RW)（帧缓冲行编号） | — |
| `LTDC_L2CLUTWR` | LTDC 图层 2 颜色查找表写入寄存器 | `0x144` | `0x50001144` | 32 | — | 0x00000000 / 0xFFFFFFFF | CLUTADD[31:24] (WO)（颜色查找表地址）、RED[23:16] (WO)（红色值）、GREEN[15:8] (WO)（绿色值）、BLUE[7:0] (WO)（蓝色值） | — |

## PSSI

**模块用途**　并行同步从接口，以外部时钟为基准接收或发送并行数据。

基地址 `0x48000400` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `PSSI_CR` | PSSI 控制寄存器 | `0x000` | `0x48000400` | 32 | — | 0x40000000 / 0xFFFFFFFF | OUTEN[31] (RW)（数据方向选择位）、DMAEN[30] (RW)（DMA 使能位）、CKSRC[29] (RW)（时钟源）、DERDYCFG[20:18] (RW)（数据使能与就绪配置）、ENABLE[14] (RW)（PSSI 使能）、EDM[11:10] (RW)（扩展数据模式）、RDYPOL[8] (RW)（就绪 (PSSI_RDY) 极性）、DEPOL[6] (RW)（数据使能 (PSSI_DE) 极性）、CKPOL[5] (RW)（并行数据时钟极性） | — |
| `PSSI_SR` | PSSI 状态寄存器 | `0x004` | `0x48000404` | 32 | — | 0x00000000 / 0xFFFFFFFF | RTT1B[3] (RO)（待核）、RTT4B[2] (RO)（待核） | — |
| `PSSI_RIS` | PSSI 原始中断状态寄存器 | `0x008` | `0x48000408` | 32 | — | 0x00000000 / 0xFFFFFFFF | OVR_RIS[1] (RO)（数据缓冲区溢出/欠载原始中断状态） | — |
| `PSSI_IER` | PSSI 中断使能寄存器 | `0x00C` | `0x4800040C` | 32 | — | 0x00000000 / 0xFFFFFFFF | OVR_IE[1] (RW)（数据缓冲区溢出/欠载中断使能） | — |
| `PSSI_MIS` | PSSI 屏蔽后中断状态寄存器 | `0x010` | `0x48000410` | 32 | — | 0x00000000 / 0xFFFFFFFF | OVR_MIS[1] (RO)（数据缓冲区溢出/欠载屏蔽后中断状态） | — |
| `PSSI_ICR` | PSSI 中断清除寄存器 | `0x014` | `0x48000414` | 32 | — | 0x00000000 / 0xFFFFFFFF | OVR_ISC[1] (WO)（数据缓冲区溢出/欠载中断状态清除） | — |
| `PSSI_DR` | PSSI 数据寄存器 | `0x028` | `0x48000428` | 32 | — | 0x00000000 / 0xFFFFFFFF | BYTE3[31:24] (RW)（数据字节 3）、BYTE2[23:16] (RW)（数据字节 2）、BYTE1[15:8] (RW)（数据字节 1）、BYTE0[7:0] (RW)（数据字节 0） | — |
