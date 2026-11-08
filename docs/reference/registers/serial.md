# 串行通信、CAN 与音频寄存器

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
| [ADF](#adf) | `0x4002F000` | 15 | SVD |
| [CEC](#cec) | `0x40006C00` | 6 | SVD |
| [FDCAN1](#fdcan1) | `0x4000A000` | 37 | SVD |
| [FDCAN2](#fdcan2) | `0x4000A400` | 36 | SVD，继承 FDCAN1 |
| [FDCAN_CONFIG](#fdcan_config) | `0x4000A100` | 5 | CMSIS 补表 |
| [I2C1_I3C1](#i2c1_i3c1) | `0x40005400` | 11 | SVD |
| [I2C2](#i2c2) | `0x40005800` | 11 | SVD，继承 I2C1_I3C1 |
| [I2C3](#i2c3) | `0x40005C00` | 11 | SVD，继承 I2C1_I3C1 |
| [I3C1](#i3c1) | `0x40005400` | 30 | CMSIS 补表 |
| [LPUART1](#lpuart1) | `0x58000C00` | 12 | SVD |
| [LPUART1_CMSIS](#lpuart1_cmsis) | `0x58000C00` | 2 | CMSIS 补表 |
| [SAI1](#sai1) | `0x42005800` | 19 | SVD |
| [SAI2](#sai2) | `0x42005C00` | 19 | SVD，继承 SAI1 |
| [SPDIFRX](#spdifrx) | `0x40004000` | 9 | SVD |
| [SPI1](#spi1) | `0x42003000` | 14 | SVD |
| [SPI2](#spi2) | `0x40003800` | 14 | SVD，继承 SPI1 |
| [SPI3](#spi3) | `0x40003C00` | 14 | SVD，继承 SPI1 |
| [SPI4](#spi4) | `0x42003400` | 14 | SVD，继承 SPI1 |
| [SPI5](#spi5) | `0x42005000` | 14 | SVD，继承 SPI1 |
| [SPI6](#spi6) | `0x58001400` | 14 | SVD，继承 SPI1 |
| [UART4](#uart4) | `0x40004C00` | 14 | SVD，继承 USART1 |
| [UART5](#uart5) | `0x40005000` | 14 | SVD，继承 USART1 |
| [UART7](#uart7) | `0x40007800` | 14 | SVD，继承 USART1 |
| [UART8](#uart8) | `0x40007C00` | 14 | SVD，继承 USART1 |
| [USART1](#usart1) | `0x42001000` | 14 | SVD |
| [USART2](#usart2) | `0x40004400` | 14 | SVD，继承 USART1 |
| [USART3](#usart3) | `0x40004800` | 14 | SVD，继承 USART1 |

## ADF

**模块用途**　音频数字滤波器，用于采集数字音频并执行滤波与抽取。

基地址 `0x4002F000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `ADF_GCR` | ADF 全局控制寄存器 | `0x000` | `0x4002F000` | 32 | — | 0x00000000 / 0xFFFFFFFF | TRGO[0] (RW)（触发输出控制） | — |
| `ADF_CKGCR` | ADF 时钟发生器控制寄存器 | `0x004` | `0x4002F004` | 32 | — | 0x00000000 / 0xFFFFFFFF | CKGACTIVE[31] (RO)（时钟发生器活动标志）、PROCDIV[30:24] (RW)（分频器至控制串行接口时钟）、CCKDIV[19:16] (RW)（分频器至控制  ADF_CCK 时钟）、TRGSRC[15:12] (RW)（待核）、TRGSENS[8] (RW)（待核）、CCK1DIR[6] (RW)（ADF_CCK1 方向）、CCK0DIR[5] (RW)（ADF_CCK0 方向）、CKGMOD[4] (RW)（时钟发生器模式）、CCK1EN[2] (RW)（ADF_CCK1 时钟使能）、CCK0EN[1] (RW)（ADF_CCK0 时钟使能）、CKGDEN[0] (RW)（CKGEN 分频器使能） | — |
| `ADF_SITF0CR` | ADF 串行接口控制寄存器 0 | `0x080` | `0x4002F080` | 32 | — | 0x00001F00 / 0xFFFFFFFF | SITFACTIVE[31] (RO)（串行接口活动标志）、STH[12:8] (RW)（待核）、SITFMOD[5:4] (RW)（待核）、SCKSRC[2:1] (RW)（串行时钟源）、SITFEN[0] (RW)（串行接口使能） | — |
| `ADF_BSMX0CR` | ADF 位流矩阵控制寄存器 0 | `0x084` | `0x4002F084` | 32 | — | 0x00000000 / 0xFFFFFFFF | BSMXACTIVE[31] (RO)（BSMX 活动标志）、BSSEL[4:0] (RW)（位流选择） | — |
| `ADF_DFLT0CR` | ADF 数字滤波控制寄存器 0 | `0x088` | `0x4002F088` | 32 | — | 0x00000000 / 0xFFFFFFFF | DFLTACTIVE[31] (RO)（DFLT0 活动标志）、DFLTRUN[30] (RO)（待核）、NBDIS[27:20] (RW)（待核）、TRGSRC[15:12] (RW)（待核）、TRGSENS[8] (RW)（待核）、ACQMOD[6:4] (RW)（DFLT0 触发模式）、FTH[2] (RW)（RXFIFO 阈值选择）、DMAEN[1] (RW)（DMA 请求使能）、DFLTEN[0] (WO)（DFLT0 使能） | — |
| `ADF_DFLT0CICR` | ADF 数字滤波器配置寄存器 0 | `0x08C` | `0x4002F08C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SCALE[25:20] (RW)（待核）、MCICD8[16] (RW)（待核）、MCICD[15:8] (RW)（待核）、CICMOD[6:4] (RW)（待核）、DATSRC[1:0] (RW)（源数据的数字滤波） | — |
| `ADF_DFLT0RSFR` | ADF 重整形滤波配置寄存器 0 | `0x090` | `0x4002F090` | 32 | — | 0x00000000 / 0xFFFFFFFF | HPFC[9:8] (RW)（待核）、HPFBYP[7] (RW)（待核）、RSFLTD[4] (RW)（待核）、RSFLTBYP[0] (RW)（待核） | — |
| `ADF_DLY0CR` | ADF 延迟控制寄存器 0 | `0x0A4` | `0x4002F0A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | SKPBF[31] (RO)（待核）、SKPDLY[6:0] (RW)（待核） | — |
| `ADF_DFLT0IER` | ADF DFLT0 中断使能寄存器 | `0x0AC` | `0x4002F0AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | SDLVLIE[13] (RW)（SAD 声音-电平值就绪使能）、SDDETIE[12] (RW)（待核）、RFOVRIE[11] (RW)（重整形滤波溢出中断使能）、CKABIE[10] (RW)（待核）、SATIE[9] (RW)（待核）、DOVRIE[1] (RW)（数据溢出中断使能）、FTHIE[0] (RW)（RXFIFO 阈值中断使能） | — |
| `ADF_DFLT0ISR` | ADF DFLT0 中断状态寄存器 0 | `0x0B0` | `0x4002F0B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | SDLVLF[13] (RW)（声音电平值就绪标志）、SDDETF[12] (RW)（待核）、RFOVRF[11] (RW)（重整形滤波溢出检测标志）、CKABF[10] (RW)（待核）、SATF[9] (RW)（待核）、RXNEF[3] (RO)（待核）、DOVRF[1] (RW)（数据溢出标志）、FTHF[0] (RO)（RXFIFO 阈值标志） | — |
| `ADF_SADCR` | ADF SAD 控制寄存器 | `0x0B8` | `0x4002F0B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | SADACTIVE[31] (RO)（SAD 活动标志）、SADMOD[13:12] (RW)（待核）、FRSIZE[10:8] (RW)（帧大小）、HYSTEN[7] (RW)（待核）、SADST[5:4] (RO)（SAD 状态）、DETCFG[3] (RW)（声音触发事件配置）、DATCAP[2:1] (RW)（数据捕获模式）、SADEN[0] (RW)（待核） | — |
| `ADF_SADCFGR` | ADF SAD 配置寄存器 | `0x0BC` | `0x4002F0BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | ANMIN[28:16] (RW)（最小噪声电平）、HGOVR[14:12] (RW)（待核）、LFRNB[10:8] (RW)（待核）、ANSLP[6:4] (RW)（待核）、SNTHR[3:0] (RW)（待核） | — |
| `ADF_SADSDLVR` | ADF SAD 声音电平寄存器 | `0x0C0` | `0x4002F0C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | SDLVL[14:0] (RO)（待核） | — |
| `ADF_SADANLVR` | ADF SAD 环境噪声电平寄存器 | `0x0C4` | `0x4002F0C4` | 32 | — | 0x00000000 / 0xFFFFFFFF | ANLVL[14:0] (RO)（待核） | — |
| `ADF_DFLT0DR` | ADF 数字滤波数据寄存器 0 | `0x0F0` | `0x4002F0F0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DR[31:8] (RO)（待核） | — |

## CEC

**模块用途**　HDMI 消费电子控制接口，用于在单线总线上收发设备控制消息。

基地址 `0x40006C00` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `CEC_CR` | CEC 控制寄存器 | `0x000` | `0x40006C00` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXEOM[2] (RW)（发送结束的消息）、TXSOM[1] (RW)（发送启动的消息）、CECEN[0] (RW)（CEC 使能） | — |
| `CEC_CFGR` | CEC 配置寄存器 | `0x004` | `0x40006C04` | 32 | — | 0x00000000 / 0xFFFFFFFF | LSTN[31] (RW)（待核）、OAR[30:16] (RW)（待核）、SFTOP[8] (RW)（SFT 选项位）、BRDNOGEN[7] (RW)（待核）、LBPEGEN[6] (RW)（待核）、BREGEN[5] (RW)（待核）、BRESTP[4] (RW)（接收-停止的位上升沿错误）、RXTOL[3] (RW)（待核）、SFT[2:0] (RW)（待核） | — |
| `CEC_TXDR` | CEC 发送数据寄存器 | `0x008` | `0x40006C08` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXD[7:0] (WO)（发送数据） | — |
| `CEC_RXDR` | CEC 接收数据寄存器 | `0x00C` | `0x40006C0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXD[7:0] (RO)（接收数据） | — |
| `CEC_ISR` | CEC 中断与状态寄存器 | `0x010` | `0x40006C10` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXACKE[12] (RW)（待核）、TXERR[11] (RW)（发送-错误）、TXUDR[10] (RW)（发送-缓冲区欠载）、TXEND[9] (RW)（结束的发送）、TXBR[8] (RW)（发送-字节请求）、ARBLST[7] (RW)（待核）、RXACKE[6] (RW)（待核）、LBPE[5] (RW)（待核）、SBPE[4] (RW)（待核）、BRE[3] (RW)（接收-位上升沿错误）、RXOVR[2] (RW)（接收-溢出）、RXEND[1] (RW)（结束的接收）、RXBR[0] (RW)（接收-字节已接收） | — |
| `CEC_IER` | CEC 中断使能寄存器 | `0x014` | `0x40006C14` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXACKIE[12] (RW)（待核）、TXERRIE[11] (RW)（发送-错误中断使能）、TXUDRIE[10] (RW)（发送-欠载中断使能）、TXENDIE[9] (RW)（发送-结束的消息中断使能）、TXBRIE[8] (RW)（发送-字节请求中断使能）、ARBLSTIE[7] (RW)（待核）、RXACKIE[6] (RW)（待核）、LBPEIE[5] (RW)（待核）、SBPEIE[4] (RW)（待核）、BREIE[3] (RW)（位上升沿错误中断使能）、RXOVRIE[2] (RW)（接收-缓冲区溢出中断使能）、RXENDIE[1] (RW)（结束的接收中断使能）、RXBRIE[0] (RW)（接收-字节已接收中断使能） | — |

## FDCAN1

**模块用途**　CAN FD 控制器，通过外部 CAN 收发器通信，管理位时序、过滤、发送队列和接收 FIFO。

基地址 `0x4000A000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `FDCAN_CREL` | CAN 控制器核心版本 | `0x000` | `0x4000A000` | 32 | — | 0x32141218 / 0xFFFFFFFF | REL[31:28] (RO)（待核）、STEP[27:24] (RO)（待核）、SUBSTEP[23:20] (RO)（待核）、YEAR[19:16] (RO)（待核）、MON[15:8] (RO)（待核）、DAY[7:0] (RO)（待核） | — |
| `FDCAN_ENDN` | 字节序测试寄存器 | `0x004` | `0x4000A004` | 32 | — | 0x87654321 / 0xFFFFFFFF | ETV[31:0] (RO)（待核） | — |
| `FDCAN_DBTP` | FDCAN 数据位时序与预分频器寄存器 | `0x00C` | `0x4000A00C` | 32 | — | 0x00000A33 / 0xFFFFFFFF | TDC[23] (RW)（待核）、DBRP[20:16] (RW)（待核）、DTSEG1[12:8] (RW)（待核）、DTSEG2[7:4] (RW)（待核）、DSJW[3:0] (RW)（待核） | — |
| `FDCAN_TEST` | FDCAN 测试寄存器 | `0x010` | `0x4000A010` | 32 | — | 0x00000000 / 0xFFFFFFFF | RX[7] (RO)（接收引脚）、TX[6:5] (RW)（控制的发送引脚）、LBCK[4] (RW)（待核） | — |
| `FDCAN_RWD` | FDCAN RAM 看门狗寄存器 | `0x014` | `0x4000A014` | 32 | — | 0x00000000 / 0xFFFFFFFF | WDV[15:8] (RO)（看门狗值）、WDC[7:0] (RW)（看门狗配置） | — |
| `FDCAN_CCCR` | FDCAN CC 控制寄存器 | `0x018` | `0x4000A018` | 32 | — | 0x00000001 / 0xFFFFFFFF | NISO[15] (RW)（待核）、TXP[14] (RW)（待核）、EFBI[13] (RW)（待核）、PXHD[12] (RW)（待核）、BRSE[9] (RW)（待核）、FDOE[8] (RW)（FD 操作使能）、TEST[7] (RW)（测试模式使能）、DAR[6] (RW)（待核）、MON[5] (RW)（总线监测模式）、CSR[4] (RW)（时钟停止请求）、CSA[3] (RO)（时钟停止应答）、ASM[2] (RW)（待核）、CCE[1] (RW)（待核）、INIT[0] (RW)（初始化） | — |
| `FDCAN_NBTP` | 标称位时序和预分频配置 | `0x01C` | `0x4000A01C` | 32 | — | 0x06000A03 / 0xFFFFFFFF | NSJW[31:25] (RW)（待核）、NBRP[24:16] (RW)（待核）、NTSEG1[15:8] (RW)（待核）、NTSEG2[6:0] (RW)（待核） | — |
| `FDCAN_TSCC` | FDCAN 时间戳计数器配置寄存器 | `0x020` | `0x4000A020` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCP[19:16] (RW)（时间戳计数器预分频器）、TSS[1:0] (RW)（时间戳选择） | — |
| `FDCAN_TSCV` | FDCAN 时间戳计数器值寄存器 | `0x024` | `0x4000A024` | 32 | — | 0x00000000 / 0xFFFFFFFF | TSC[15:0] (RW)（时间戳计数器） | — |
| `FDCAN_TOCC` | FDCAN 超时计数器配置寄存器 | `0x028` | `0x4000A028` | 32 | — | 0xFFFF0000 / 0xFFFFFFFF | TOP[31:16] (RW)（超时周期）、TOS[2:1] (RW)（超时选择）、ETOC[0] (RW)（超时计数器使能） | — |
| `FDCAN_TOCV` | FDCAN 超时计数器值寄存器 | `0x02C` | `0x4000A02C` | 32 | — | 0x0000FFFF / 0xFFFFFFFF | TOC[15:0] (RW)（超时计数器） | — |
| `FDCAN_ECR` | FDCAN 错误计数器寄存器 | `0x040` | `0x4000A040` | 32 | — | 0x00000000 / 0xFFFFFFFF | CEL[23:16] (RW)（待核）、RP[15] (RO)（待核）、REC[14:8] (RO)（接收错误计数器）、TEC[7:0] (RO)（发送错误计数器） | — |
| `FDCAN_PSR` | FDCAN 协议状态寄存器 | `0x044` | `0x4000A044` | 32 | — | 0x00000707 / 0xFFFFFFFF | TDCV[22:16] (RO)（发送器延迟补偿值）、PXE[14] (RW)（待核）、REDL[13] (RW)（已接收 FDCAN 消息）、RBRS[12] (RW)（BRS 标志的末尾已接收 FDCAN 消息）、RESI[11] (RW)（ESI 标志的末尾已接收 FDCAN 消息）、DLEC[10:8] (RW)（数据末尾错误编码）、BO[7] (RO)（Bus_Off 状态）、EW[6] (RO)（待核）、EP[5] (RO)（待核）、ACT[4:3] (RO)（待核）、LEC[2:0] (RW)（末尾错误编码） | — |
| `FDCAN_TDCR` | FDCAN 发送器延迟补偿寄存器 | `0x048` | `0x4000A048` | 32 | — | 0x00000000 / 0xFFFFFFFF | TDCO[14:8] (RW)（发送器延迟补偿偏移）、TDCF[6:0] (RW)（发送器延迟补偿滤波窗口长度） | — |
| `FDCAN_IR` | FDCAN 中断寄存器 | `0x050` | `0x4000A050` | 32 | — | 0x00000000 / 0xFFFFFFFF | ARA[23] (RW)（访问至保留地址）、PED[22] (RW)（待核）、PEA[21] (RW)（待核）、WDI[20] (RW)（看门狗中断）、BO[19] (RW)（Bus_Off 状态）、EW[18] (RW)（待核）、EP[17] (RW)（待核）、ELO[16] (RW)（待核）、TOO[15] (RW)（超时已发生）、MRAF[14] (RW)（待核）、TSW[13] (RW)（待核）、TEFL[12] (RW)（待核）、TEFF[11] (RW)（发送事件 FIFO 满）、TEFN[10] (RW)（待核）、TFE[9] (RW)（发送 FIFO 空）、TCF[8] (RW)（发送取消完成）、TC[7] (RW)（发送完成）、HPM[6] (RW)（高位-优先级消息）、RF1L[5] (RW)（待核）、RF1F[4] (RW)（接收 FIFO 1 满）、RF1N[3] (RW)（待核）、RF0L[2] (RW)（待核）、RF0F[1] (RW)（接收 FIFO 0 满）、RF0N[0] (RW)（待核） | — |
| `FDCAN_IE` | FDCAN 中断使能寄存器 | `0x054` | `0x4000A054` | 32 | — | 0x00000000 / 0xFFFFFFFF | ARAE[23] (RW)（访问至保留地址使能）、PEDE[22] (RW)（协议错误内数据相位使能）、PEAE[21] (RW)（协议错误内仲裁相位使能）、WDIE[20] (RW)（看门狗中断使能）、BOE[19] (RW)（Bus_Off 状态）、EWE[18] (RW)（待核）、EPE[17] (RW)（待核）、ELOE[16] (RW)（待核）、TOOE[15] (RW)（超时已发生中断使能）、MRAFE[14] (RW)（待核）、TSWE[13] (RW)（待核）、TEFLE[12] (RW)（待核）、TEFFE[11] (RW)（发送事件 FIFO 满中断使能）、TEFNE[10] (RW)（待核）、TFEE[9] (RW)（发送 FIFO 空中断使能）、TCFE[8] (RW)（发送取消完成中断使能）、TCE[7] (RW)（发送完成中断使能）、HPME[6] (RW)（高位-优先级消息中断使能）、RF1LE[5] (RW)（待核）、RF1FE[4] (RW)（接收 FIFO 1 满中断使能）、RF1NE[3] (RW)（待核）、RF0LE[2] (RW)（待核）、RF0FE[1] (RW)（接收 FIFO 0 满中断使能）、RF0NE[0] (RW)（待核） | — |
| `FDCAN_ILS` | FDCAN 中断行选择寄存器 | `0x058` | `0x4000A058` | 32 | — | 0x00000000 / 0xFFFFFFFF | PERR[6] (RW)（待核）、BERR[5] (RW)（待核）、MISC[4] (RW)（待核）、TFERR[3] (RW)（待核）、SMSG[2] (RW)（待核）、RXFIFO1[1] (RW)（待核）、RXFIFO0[0] (RW)（待核） | — |
| `FDCAN_ILE` | FDCAN 中断行使能寄存器 | `0x05C` | `0x4000A05C` | 32 | — | 0x00000000 / 0xFFFFFFFF | EINT1[1] (RW)（使能中断行 1）、EINT0[0] (RW)（使能中断行 0） | — |
| `FDCAN_RXGFC` | FDCAN 全局滤波配置寄存器 | `0x080` | `0x4000A080` | 32 | — | 0x00000000 / 0xFFFFFFFF | LSE[27:24] (RW)（列表大小扩展）、LSS[20:16] (RW)（待核）、F0OM[9] (RW)（待核）、F1OM[8] (RW)（待核）、ANFS[5:4] (RW)（待核）、ANFE[3:2] (RW)（待核）、RRFS[1] (RW)（待核）、RRFE[0] (RW)（待核） | — |
| `FDCAN_XIDAM` | 扩展标识符过滤掩码 | `0x084` | `0x4000A084` | 32 | — | 0x1FFFFFFF / 0xFFFFFFFF | EIDM[28:0] (RW)（扩展 ID 屏蔽） | — |
| `FDCAN_HPMS` | FDCAN 高位-优先级消息状态寄存器 | `0x088` | `0x4000A088` | 32 | — | 0x00000000 / 0xFFFFFFFF | FLST[15] (RO)（滤波列表）、FIDX[12:8] (RO)（滤波索引）、MSI[7:6] (RO)（待核）、BIDX[2:0] (RO)（缓冲区索引） | — |
| `FDCAN_RXF0S` | FDCAN 接收 FIFO 0 状态寄存器 | `0x090` | `0x4000A090` | 32 | — | 0x00000000 / 0xFFFFFFFF | RF0L[25] (RO)（待核）、F0F[24] (RO)（接收 FIFO 0 满）、F0PI[17:16] (RO)（待核）、F0GI[9:8] (RO)（待核）、F0FL[3:0] (RO)（待核） | — |
| `FDCAN_RXF0A` | 确认已读取接收 FIFO 0 的条目 | `0x094` | `0x4000A094` | 32 | — | 0x00000000 / 0xFFFFFFFF | F0AI[2:0] (RW)（接收 FIFO 0 应答索引） | — |
| `FDCAN_RXF1S` | FDCAN 接收 FIFO 1 状态寄存器 | `0x098` | `0x4000A098` | 32 | — | 0x00000000 / 0xFFFFFFFF | RF1L[25] (RO)（待核）、F1F[24] (RO)（接收 FIFO 1 满）、F1PI[17:16] (RO)（待核）、F1GI[9:8] (RO)（待核）、F1FL[3:0] (RO)（待核） | — |
| `FDCAN_RXF1A` | 确认已读取接收 FIFO 1 的条目 | `0x09C` | `0x4000A09C` | 32 | — | 0x00000000 / 0xFFFFFFFF | F1AI[2:0] (RW)（接收 FIFO 1 应答索引） | — |
| `FDCAN_TXBC` | FDCAN 发送缓冲区配置寄存器 | `0x0C0` | `0x4000A0C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | TFQM[24] (RW)（发送 FIFO/队列模式） | — |
| `FDCAN_TXFQS` | FDCAN 发送 FIFO/队列状态寄存器 | `0x0C4` | `0x4000A0C4` | 32 | — | 0x00000003 / 0xFFFFFFFF | TFQF[21] (RO)（发送 FIFO/队列满）、TFQPI[17:16] (RO)（待核）、TFGI[9:8] (RO)（待核）、TFFL[2:0] (RO)（待核） | — |
| `FDCAN_TXBRP` | FDCAN 发送缓冲区请求挂起寄存器 | `0x0C8` | `0x4000A0C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | TRP[2:0] (RO)（发送请求挂起） | — |
| `FDCAN_TXBAR` | 添加发送请求 | `0x0CC` | `0x4000A0CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | AR[2:0] (RW)（待核） | — |
| `FDCAN_TXBCR` | 请求取消发送 | `0x0D0` | `0x4000A0D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | CR[2:0] (RW)（取消请求） | — |
| `FDCAN_TXBTO` | 已完成发送的缓冲区状态 | `0x0D4` | `0x4000A0D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | TO[2:0] (RO)（发送已发生） | — |
| `FDCAN_TXBCF` | 取消发送完成状态 | `0x0D8` | `0x4000A0D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | CF[2:0] (RO)（取消完成） | — |
| `FDCAN_TXBTIE` | FDCAN 发送缓冲区发送中断使能寄存器 | `0x0DC` | `0x4000A0DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TIE[2:0] (RW)（发送中断使能） | — |
| `FDCAN_TXBCIE` | 取消发送完成中断使能 | `0x0E0` | `0x4000A0E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | CFIE[2:0] (RW)（取消完成中断使能） | — |
| `FDCAN_TXEFS` | FDCAN 发送事件 FIFO 状态寄存器 | `0x0E4` | `0x4000A0E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | TEFL[25] (RO)（待核）、EFF[24] (RO)（事件 FIFO 满）、EFPI[17:16] (RO)（待核）、EFGI[9:8] (RO)（待核）、EFFL[2:0] (RO)（待核） | — |
| `FDCAN_TXEFA` | 确认已读取发送事件 FIFO 的条目 | `0x0E8` | `0x4000A0E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | EFAI[1:0] (RW)（事件 FIFO 应答索引） | — |
| `FDCAN_CKDIV` | FDCAN CFG 时钟分频寄存器 | `0x100` | `0x4000A100` | 32 | — | 0x00000000 / 0xFFFFFFFF | PDIV[3:0] (RW)（输入时钟分频） | — |

## FDCAN2

**模块用途**　CAN FD 控制器，通过外部 CAN 收发器通信，管理位时序、过滤、发送队列和接收 FIFO。

基地址 `0x4000A400` · SVD，继承 FDCAN1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `FDCAN_CREL` | CAN 控制器核心版本 | `0x000` | `0x4000A400` | 32 | — | 0x32141218 / 0xFFFFFFFF | REL[31:28] (RO)（待核）、STEP[27:24] (RO)（待核）、SUBSTEP[23:20] (RO)（待核）、YEAR[19:16] (RO)（待核）、MON[15:8] (RO)（待核）、DAY[7:0] (RO)（待核） | — |
| `FDCAN_ENDN` | 字节序测试寄存器 | `0x004` | `0x4000A404` | 32 | — | 0x87654321 / 0xFFFFFFFF | ETV[31:0] (RO)（待核） | — |
| `FDCAN_DBTP` | FDCAN 数据位时序与预分频器寄存器 | `0x00C` | `0x4000A40C` | 32 | — | 0x00000A33 / 0xFFFFFFFF | TDC[23] (RW)（待核）、DBRP[20:16] (RW)（待核）、DTSEG1[12:8] (RW)（待核）、DTSEG2[7:4] (RW)（待核）、DSJW[3:0] (RW)（待核） | — |
| `FDCAN_TEST` | FDCAN 测试寄存器 | `0x010` | `0x4000A410` | 32 | — | 0x00000000 / 0xFFFFFFFF | RX[7] (RO)（接收引脚）、TX[6:5] (RW)（控制的发送引脚）、LBCK[4] (RW)（待核） | — |
| `FDCAN_RWD` | FDCAN RAM 看门狗寄存器 | `0x014` | `0x4000A414` | 32 | — | 0x00000000 / 0xFFFFFFFF | WDV[15:8] (RO)（看门狗值）、WDC[7:0] (RW)（看门狗配置） | — |
| `FDCAN_CCCR` | FDCAN CC 控制寄存器 | `0x018` | `0x4000A418` | 32 | — | 0x00000001 / 0xFFFFFFFF | NISO[15] (RW)（待核）、TXP[14] (RW)（待核）、EFBI[13] (RW)（待核）、PXHD[12] (RW)（待核）、BRSE[9] (RW)（待核）、FDOE[8] (RW)（FD 操作使能）、TEST[7] (RW)（测试模式使能）、DAR[6] (RW)（待核）、MON[5] (RW)（总线监测模式）、CSR[4] (RW)（时钟停止请求）、CSA[3] (RO)（时钟停止应答）、ASM[2] (RW)（待核）、CCE[1] (RW)（待核）、INIT[0] (RW)（初始化） | — |
| `FDCAN_NBTP` | 标称位时序和预分频配置 | `0x01C` | `0x4000A41C` | 32 | — | 0x06000A03 / 0xFFFFFFFF | NSJW[31:25] (RW)（待核）、NBRP[24:16] (RW)（待核）、NTSEG1[15:8] (RW)（待核）、NTSEG2[6:0] (RW)（待核） | — |
| `FDCAN_TSCC` | FDCAN 时间戳计数器配置寄存器 | `0x020` | `0x4000A420` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCP[19:16] (RW)（时间戳计数器预分频器）、TSS[1:0] (RW)（时间戳选择） | — |
| `FDCAN_TSCV` | FDCAN 时间戳计数器值寄存器 | `0x024` | `0x4000A424` | 32 | — | 0x00000000 / 0xFFFFFFFF | TSC[15:0] (RW)（时间戳计数器） | — |
| `FDCAN_TOCC` | FDCAN 超时计数器配置寄存器 | `0x028` | `0x4000A428` | 32 | — | 0xFFFF0000 / 0xFFFFFFFF | TOP[31:16] (RW)（超时周期）、TOS[2:1] (RW)（超时选择）、ETOC[0] (RW)（超时计数器使能） | — |
| `FDCAN_TOCV` | FDCAN 超时计数器值寄存器 | `0x02C` | `0x4000A42C` | 32 | — | 0x0000FFFF / 0xFFFFFFFF | TOC[15:0] (RW)（超时计数器） | — |
| `FDCAN_ECR` | FDCAN 错误计数器寄存器 | `0x040` | `0x4000A440` | 32 | — | 0x00000000 / 0xFFFFFFFF | CEL[23:16] (RW)（待核）、RP[15] (RO)（待核）、REC[14:8] (RO)（接收错误计数器）、TEC[7:0] (RO)（发送错误计数器） | — |
| `FDCAN_PSR` | FDCAN 协议状态寄存器 | `0x044` | `0x4000A444` | 32 | — | 0x00000707 / 0xFFFFFFFF | TDCV[22:16] (RO)（发送器延迟补偿值）、PXE[14] (RW)（待核）、REDL[13] (RW)（已接收 FDCAN 消息）、RBRS[12] (RW)（BRS 标志的末尾已接收 FDCAN 消息）、RESI[11] (RW)（ESI 标志的末尾已接收 FDCAN 消息）、DLEC[10:8] (RW)（数据末尾错误编码）、BO[7] (RO)（Bus_Off 状态）、EW[6] (RO)（待核）、EP[5] (RO)（待核）、ACT[4:3] (RO)（待核）、LEC[2:0] (RW)（末尾错误编码） | — |
| `FDCAN_TDCR` | FDCAN 发送器延迟补偿寄存器 | `0x048` | `0x4000A448` | 32 | — | 0x00000000 / 0xFFFFFFFF | TDCO[14:8] (RW)（发送器延迟补偿偏移）、TDCF[6:0] (RW)（发送器延迟补偿滤波窗口长度） | — |
| `FDCAN_IR` | FDCAN 中断寄存器 | `0x050` | `0x4000A450` | 32 | — | 0x00000000 / 0xFFFFFFFF | ARA[23] (RW)（访问至保留地址）、PED[22] (RW)（待核）、PEA[21] (RW)（待核）、WDI[20] (RW)（看门狗中断）、BO[19] (RW)（Bus_Off 状态）、EW[18] (RW)（待核）、EP[17] (RW)（待核）、ELO[16] (RW)（待核）、TOO[15] (RW)（超时已发生）、MRAF[14] (RW)（待核）、TSW[13] (RW)（待核）、TEFL[12] (RW)（待核）、TEFF[11] (RW)（发送事件 FIFO 满）、TEFN[10] (RW)（待核）、TFE[9] (RW)（发送 FIFO 空）、TCF[8] (RW)（发送取消完成）、TC[7] (RW)（发送完成）、HPM[6] (RW)（高位-优先级消息）、RF1L[5] (RW)（待核）、RF1F[4] (RW)（接收 FIFO 1 满）、RF1N[3] (RW)（待核）、RF0L[2] (RW)（待核）、RF0F[1] (RW)（接收 FIFO 0 满）、RF0N[0] (RW)（待核） | — |
| `FDCAN_IE` | FDCAN 中断使能寄存器 | `0x054` | `0x4000A454` | 32 | — | 0x00000000 / 0xFFFFFFFF | ARAE[23] (RW)（访问至保留地址使能）、PEDE[22] (RW)（协议错误内数据相位使能）、PEAE[21] (RW)（协议错误内仲裁相位使能）、WDIE[20] (RW)（看门狗中断使能）、BOE[19] (RW)（Bus_Off 状态）、EWE[18] (RW)（待核）、EPE[17] (RW)（待核）、ELOE[16] (RW)（待核）、TOOE[15] (RW)（超时已发生中断使能）、MRAFE[14] (RW)（待核）、TSWE[13] (RW)（待核）、TEFLE[12] (RW)（待核）、TEFFE[11] (RW)（发送事件 FIFO 满中断使能）、TEFNE[10] (RW)（待核）、TFEE[9] (RW)（发送 FIFO 空中断使能）、TCFE[8] (RW)（发送取消完成中断使能）、TCE[7] (RW)（发送完成中断使能）、HPME[6] (RW)（高位-优先级消息中断使能）、RF1LE[5] (RW)（待核）、RF1FE[4] (RW)（接收 FIFO 1 满中断使能）、RF1NE[3] (RW)（待核）、RF0LE[2] (RW)（待核）、RF0FE[1] (RW)（接收 FIFO 0 满中断使能）、RF0NE[0] (RW)（待核） | — |
| `FDCAN_ILS` | FDCAN 中断行选择寄存器 | `0x058` | `0x4000A458` | 32 | — | 0x00000000 / 0xFFFFFFFF | PERR[6] (RW)（待核）、BERR[5] (RW)（待核）、MISC[4] (RW)（待核）、TFERR[3] (RW)（待核）、SMSG[2] (RW)（待核）、RXFIFO1[1] (RW)（待核）、RXFIFO0[0] (RW)（待核） | — |
| `FDCAN_ILE` | FDCAN 中断行使能寄存器 | `0x05C` | `0x4000A45C` | 32 | — | 0x00000000 / 0xFFFFFFFF | EINT1[1] (RW)（使能中断行 1）、EINT0[0] (RW)（使能中断行 0） | — |
| `FDCAN_RXGFC` | FDCAN 全局滤波配置寄存器 | `0x080` | `0x4000A480` | 32 | — | 0x00000000 / 0xFFFFFFFF | LSE[27:24] (RW)（列表大小扩展）、LSS[20:16] (RW)（待核）、F0OM[9] (RW)（待核）、F1OM[8] (RW)（待核）、ANFS[5:4] (RW)（待核）、ANFE[3:2] (RW)（待核）、RRFS[1] (RW)（待核）、RRFE[0] (RW)（待核） | — |
| `FDCAN_XIDAM` | 扩展标识符过滤掩码 | `0x084` | `0x4000A484` | 32 | — | 0x1FFFFFFF / 0xFFFFFFFF | EIDM[28:0] (RW)（扩展 ID 屏蔽） | — |
| `FDCAN_HPMS` | FDCAN 高位-优先级消息状态寄存器 | `0x088` | `0x4000A488` | 32 | — | 0x00000000 / 0xFFFFFFFF | FLST[15] (RO)（滤波列表）、FIDX[12:8] (RO)（滤波索引）、MSI[7:6] (RO)（待核）、BIDX[2:0] (RO)（缓冲区索引） | — |
| `FDCAN_RXF0S` | FDCAN 接收 FIFO 0 状态寄存器 | `0x090` | `0x4000A490` | 32 | — | 0x00000000 / 0xFFFFFFFF | RF0L[25] (RO)（待核）、F0F[24] (RO)（接收 FIFO 0 满）、F0PI[17:16] (RO)（待核）、F0GI[9:8] (RO)（待核）、F0FL[3:0] (RO)（待核） | — |
| `FDCAN_RXF0A` | 确认已读取接收 FIFO 0 的条目 | `0x094` | `0x4000A494` | 32 | — | 0x00000000 / 0xFFFFFFFF | F0AI[2:0] (RW)（接收 FIFO 0 应答索引） | — |
| `FDCAN_RXF1S` | FDCAN 接收 FIFO 1 状态寄存器 | `0x098` | `0x4000A498` | 32 | — | 0x00000000 / 0xFFFFFFFF | RF1L[25] (RO)（待核）、F1F[24] (RO)（接收 FIFO 1 满）、F1PI[17:16] (RO)（待核）、F1GI[9:8] (RO)（待核）、F1FL[3:0] (RO)（待核） | — |
| `FDCAN_RXF1A` | 确认已读取接收 FIFO 1 的条目 | `0x09C` | `0x4000A49C` | 32 | — | 0x00000000 / 0xFFFFFFFF | F1AI[2:0] (RW)（接收 FIFO 1 应答索引） | — |
| `FDCAN_TXBC` | FDCAN 发送缓冲区配置寄存器 | `0x0C0` | `0x4000A4C0` | 32 | — | 0x00000000 / 0xFFFFFFFF | TFQM[24] (RW)（发送 FIFO/队列模式） | — |
| `FDCAN_TXFQS` | FDCAN 发送 FIFO/队列状态寄存器 | `0x0C4` | `0x4000A4C4` | 32 | — | 0x00000003 / 0xFFFFFFFF | TFQF[21] (RO)（发送 FIFO/队列满）、TFQPI[17:16] (RO)（待核）、TFGI[9:8] (RO)（待核）、TFFL[2:0] (RO)（待核） | — |
| `FDCAN_TXBRP` | FDCAN 发送缓冲区请求挂起寄存器 | `0x0C8` | `0x4000A4C8` | 32 | — | 0x00000000 / 0xFFFFFFFF | TRP[2:0] (RO)（发送请求挂起） | — |
| `FDCAN_TXBAR` | 添加发送请求 | `0x0CC` | `0x4000A4CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | AR[2:0] (RW)（待核） | — |
| `FDCAN_TXBCR` | 请求取消发送 | `0x0D0` | `0x4000A4D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | CR[2:0] (RW)（取消请求） | — |
| `FDCAN_TXBTO` | 已完成发送的缓冲区状态 | `0x0D4` | `0x4000A4D4` | 32 | — | 0x00000000 / 0xFFFFFFFF | TO[2:0] (RO)（发送已发生） | — |
| `FDCAN_TXBCF` | 取消发送完成状态 | `0x0D8` | `0x4000A4D8` | 32 | — | 0x00000000 / 0xFFFFFFFF | CF[2:0] (RO)（取消完成） | — |
| `FDCAN_TXBTIE` | FDCAN 发送缓冲区发送中断使能寄存器 | `0x0DC` | `0x4000A4DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TIE[2:0] (RW)（发送中断使能） | — |
| `FDCAN_TXBCIE` | 取消发送完成中断使能 | `0x0E0` | `0x4000A4E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | CFIE[2:0] (RW)（取消完成中断使能） | — |
| `FDCAN_TXEFS` | FDCAN 发送事件 FIFO 状态寄存器 | `0x0E4` | `0x4000A4E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | TEFL[25] (RO)（待核）、EFF[24] (RO)（事件 FIFO 满）、EFPI[17:16] (RO)（待核）、EFGI[9:8] (RO)（待核）、EFFL[2:0] (RO)（待核） | — |
| `FDCAN_TXEFA` | 确认已读取发送事件 FIFO 的条目 | `0x0E8` | `0x4000A4E8` | 32 | — | 0x00000000 / 0xFFFFFFFF | EFAI[1:0] (RW)（事件 FIFO 应答索引） | — |

## FDCAN_CONFIG

**模块用途**　FDCAN 公共配置补充视图。公共时钟分频寄存器在 FDCAN1 主表中。

基地址 `0x4000A100` · CMSIS 补表

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `OPTR` | 选项配置寄存器 | `0x204` | `0x4000A304` | 32 | — | — / — | — | — |
| `HWCFG` | 硬件配置寄存器 | `0x2F0` | `0x4000A3F0` | 32 | — | — / — | — | — |
| `VERR` | 版本标识寄存器 | `0x2F4` | `0x4000A3F4` | 32 | — | — / — | — | — |
| `IPIDR` | 外设标识寄存器 | `0x2F8` | `0x4000A3F8` | 32 | — | — / — | — | — |
| `SIDR` | 大小标识寄存器 | `0x2FC` | `0x4000A3FC` | 32 | — | — / — | — | — |

## I2C1_I3C1

**模块用途**　I2C1 的 I²C 寄存器视图。它与 I3C1 共用基地址，具体寄存器含义随选用的模式变化。

基地址 `0x40005400` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `I2C_CR1` | I2C 控制寄存器 1 | `0x000` | `0x40005400` | 32 | — | 0x00000000 / 0xFFFFFFFF | STOPFACLR[31] (RW)（待核）、ADDRACLR[30] (RW)（待核）、FMP[24] (RW)（待核）、PECEN[23] (RW)（PEC 使能）、ALERTEN[22] (RW)（待核）、SMBDEN[21] (RW)（SMBUS 设备默认地址使能）、SMBHEN[20] (RW)（SMBUS 主机地址使能）、GCEN[19] (RW)（待核）、WUPEN[18] (RW)（唤醒来自停止模式使能）、NOSTRETCH[17] (RW)（待核）、SBC[16] (RW)（从设备字节控制）、RXDMAEN[15] (RW)（DMA 接收请求使能）、TXDMAEN[14] (RW)（DMA 发送请求使能）、ANFOFF[12] (RW)（模拟噪声滤波 OFF）、DNF[11:8] (RW)（数字噪声滤波）、ERRIE[7] (RW)（错误中断使能）、TCIE[6] (RW)（传输完成中断使能）、STOPIE[5] (RW)（停止检测中断使能）、NACKIE[4] (RW)（待核）、ADDRIE[3] (RW)（待核）、RXIE[2] (RW)（接收中断使能）、TXIE[1] (RW)（发送中断使能）、PE[0] (RW)（外设使能） | — |
| `I2C_CR2` | I2C 控制寄存器 2 | `0x004` | `0x40005404` | 32 | — | 0x00000000 / 0xFFFFFFFF | PECBYTE[26] (RW)（待核）、AUTOEND[25] (RW)（待核）、RELOAD[24] (RW)（NBYTES 重装模式）、NBYTES[23:16] (RW)（数量字节）、NACK[15] (RW)（NACK 生成 (从设备模式)）、STOP[14] (RW)（停止生成 (主设备模式)）、START[13] (RW)（启动生成）、HEAD10R[12] (RW)（待核）、ADD10[11] (RW)（待核）、RD_WRN[10] (RW)（传输方向 (主设备模式)）、SADD[9:0] (RW)（从设备地址 (主设备模式)） | — |
| `I2C_OAR1` | I2C 本机地址 1 寄存器 | `0x008` | `0x40005408` | 32 | — | 0x00000000 / 0xFFFFFFFF | OA1EN[15] (RW)（本机地址 1 使能）、OA1MODE[10] (RW)（本机地址 1 10-位模式）、OA1[9:0] (RW)（待核） | — |
| `I2C_OAR2` | I2C 本机地址 2 寄存器 | `0x00C` | `0x4000540C` | 32 | — | 0x00000000 / 0xFFFFFFFF | OA2EN[15] (RW)（本机地址 2 使能）、OA2MSK[10:8] (RW)（待核）、OA2[7:1] (RW)（接口地址） | — |
| `I2C_TIMINGR` | I2C 时序寄存器 | `0x010` | `0x40005410` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRESC[31:28] (RW)（时序预分频器）、SCLDEL[23:20] (RW)（待核）、SDADEL[19:16] (RW)（数据保持时间）、SCLH[15:8] (RW)（SCL 高位周期 (主设备模式)）、SCLL[7:0] (RW)（SCL 低位周期 (主设备模式)） | — |
| `I2C_TIMEOUTR` | I2C 超时寄存器 | `0x014` | `0x40005414` | 32 | — | 0x00000000 / 0xFFFFFFFF | TEXTEN[31] (RW)（扩展时钟超时使能）、TIMEOUTB[27:16] (RW)（总线超时 B）、TIMOUTEN[15] (RW)（时钟超时使能）、TIDLE[12] (RW)（空闲时钟超时检测）、TIMEOUTA[11:0] (RW)（总线超时） | — |
| `I2C_ISR` | I2C 中断与状态寄存器 | `0x018` | `0x40005418` | 32 | — | 0x00000001 / 0xFFFFFFFF | ADDCODE[23:17] (RO)（地址匹配编码 (从设备模式)）、DIR[16] (RO)（传输方向 (从设备模式)）、BUSY[15] (RO)（总线忙）、ALERT[13] (RO)（待核）、TIMEOUT[12] (RO)（待核）、PECERR[11] (RO)（PEC 错误内接收）、OVR[10] (RO)（溢出/欠载 (从设备模式)）、ARLO[9] (RO)（待核）、BERR[8] (RO)（总线错误）、TCR[7] (RO)（传输完成重装）、TC[6] (RO)（传输完成 (主设备模式)）、STOPF[5] (RO)（停止检测标志）、NACKF[4] (RO)（待核）、ADDR[3] (RO)（待核）、RXNE[2] (RO)（待核）、TXIS[1] (RW)（待核）、TXE[0] (RW)（待核） | — |
| `I2C_ICR` | I2C 中断清除寄存器 | `0x01C` | `0x4000541C` | 32 | — | 0x00000000 / 0xFFFFFFFF | ALERTCF[13] (WO)（待核）、TIMOUTCF[12] (WO)（超时检测清除标志）、PECCF[11] (WO)（PEC 错误清除标志）、OVRCF[10] (WO)（溢出/欠载清除标志）、ARLOCF[9] (WO)（待核）、BERRCF[8] (WO)（总线错误清除标志）、STOPCF[5] (WO)（停止检测清除标志）、NACKCF[4] (WO)（待核）、ADDRCF[3] (WO)（待核） | — |
| `I2C_PECR` | I2C PEC 寄存器 | `0x020` | `0x40005420` | 32 | — | 0x00000000 / 0xFFFFFFFF | PEC[7:0] (RO)（待核） | — |
| `I2C_RXDR` | I2C 接收数据寄存器 | `0x024` | `0x40005424` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXDATA[7:0] (RO)（8-位接收数据） | — |
| `I2C_TXDR` | I2C 发送数据寄存器 | `0x028` | `0x40005428` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXDATA[7:0] (RW)（8-位发送数据） | — |

## I2C2

**模块用途**　双线串行总线控制器，通过 SCL 和 SDA 与外部器件通信，可配置地址、时序以及收发。

基地址 `0x40005800` · SVD，继承 I2C1_I3C1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `I2C_CR1` | I2C 控制寄存器 1 | `0x000` | `0x40005800` | 32 | — | 0x00000000 / 0xFFFFFFFF | STOPFACLR[31] (RW)（待核）、ADDRACLR[30] (RW)（待核）、FMP[24] (RW)（待核）、PECEN[23] (RW)（PEC 使能）、ALERTEN[22] (RW)（待核）、SMBDEN[21] (RW)（SMBUS 设备默认地址使能）、SMBHEN[20] (RW)（SMBUS 主机地址使能）、GCEN[19] (RW)（待核）、WUPEN[18] (RW)（唤醒来自停止模式使能）、NOSTRETCH[17] (RW)（待核）、SBC[16] (RW)（从设备字节控制）、RXDMAEN[15] (RW)（DMA 接收请求使能）、TXDMAEN[14] (RW)（DMA 发送请求使能）、ANFOFF[12] (RW)（模拟噪声滤波 OFF）、DNF[11:8] (RW)（数字噪声滤波）、ERRIE[7] (RW)（错误中断使能）、TCIE[6] (RW)（传输完成中断使能）、STOPIE[5] (RW)（停止检测中断使能）、NACKIE[4] (RW)（待核）、ADDRIE[3] (RW)（待核）、RXIE[2] (RW)（接收中断使能）、TXIE[1] (RW)（发送中断使能）、PE[0] (RW)（外设使能） | — |
| `I2C_CR2` | I2C 控制寄存器 2 | `0x004` | `0x40005804` | 32 | — | 0x00000000 / 0xFFFFFFFF | PECBYTE[26] (RW)（待核）、AUTOEND[25] (RW)（待核）、RELOAD[24] (RW)（NBYTES 重装模式）、NBYTES[23:16] (RW)（数量字节）、NACK[15] (RW)（NACK 生成 (从设备模式)）、STOP[14] (RW)（停止生成 (主设备模式)）、START[13] (RW)（启动生成）、HEAD10R[12] (RW)（待核）、ADD10[11] (RW)（待核）、RD_WRN[10] (RW)（传输方向 (主设备模式)）、SADD[9:0] (RW)（从设备地址 (主设备模式)） | — |
| `I2C_OAR1` | I2C 本机地址 1 寄存器 | `0x008` | `0x40005808` | 32 | — | 0x00000000 / 0xFFFFFFFF | OA1EN[15] (RW)（本机地址 1 使能）、OA1MODE[10] (RW)（本机地址 1 10-位模式）、OA1[9:0] (RW)（待核） | — |
| `I2C_OAR2` | I2C 本机地址 2 寄存器 | `0x00C` | `0x4000580C` | 32 | — | 0x00000000 / 0xFFFFFFFF | OA2EN[15] (RW)（本机地址 2 使能）、OA2MSK[10:8] (RW)（待核）、OA2[7:1] (RW)（接口地址） | — |
| `I2C_TIMINGR` | I2C 时序寄存器 | `0x010` | `0x40005810` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRESC[31:28] (RW)（时序预分频器）、SCLDEL[23:20] (RW)（待核）、SDADEL[19:16] (RW)（数据保持时间）、SCLH[15:8] (RW)（SCL 高位周期 (主设备模式)）、SCLL[7:0] (RW)（SCL 低位周期 (主设备模式)） | — |
| `I2C_TIMEOUTR` | I2C 超时寄存器 | `0x014` | `0x40005814` | 32 | — | 0x00000000 / 0xFFFFFFFF | TEXTEN[31] (RW)（扩展时钟超时使能）、TIMEOUTB[27:16] (RW)（总线超时 B）、TIMOUTEN[15] (RW)（时钟超时使能）、TIDLE[12] (RW)（空闲时钟超时检测）、TIMEOUTA[11:0] (RW)（总线超时） | — |
| `I2C_ISR` | I2C 中断与状态寄存器 | `0x018` | `0x40005818` | 32 | — | 0x00000001 / 0xFFFFFFFF | ADDCODE[23:17] (RO)（地址匹配编码 (从设备模式)）、DIR[16] (RO)（传输方向 (从设备模式)）、BUSY[15] (RO)（总线忙）、ALERT[13] (RO)（待核）、TIMEOUT[12] (RO)（待核）、PECERR[11] (RO)（PEC 错误内接收）、OVR[10] (RO)（溢出/欠载 (从设备模式)）、ARLO[9] (RO)（待核）、BERR[8] (RO)（总线错误）、TCR[7] (RO)（传输完成重装）、TC[6] (RO)（传输完成 (主设备模式)）、STOPF[5] (RO)（停止检测标志）、NACKF[4] (RO)（待核）、ADDR[3] (RO)（待核）、RXNE[2] (RO)（待核）、TXIS[1] (RW)（待核）、TXE[0] (RW)（待核） | — |
| `I2C_ICR` | I2C 中断清除寄存器 | `0x01C` | `0x4000581C` | 32 | — | 0x00000000 / 0xFFFFFFFF | ALERTCF[13] (WO)（待核）、TIMOUTCF[12] (WO)（超时检测清除标志）、PECCF[11] (WO)（PEC 错误清除标志）、OVRCF[10] (WO)（溢出/欠载清除标志）、ARLOCF[9] (WO)（待核）、BERRCF[8] (WO)（总线错误清除标志）、STOPCF[5] (WO)（停止检测清除标志）、NACKCF[4] (WO)（待核）、ADDRCF[3] (WO)（待核） | — |
| `I2C_PECR` | I2C PEC 寄存器 | `0x020` | `0x40005820` | 32 | — | 0x00000000 / 0xFFFFFFFF | PEC[7:0] (RO)（待核） | — |
| `I2C_RXDR` | I2C 接收数据寄存器 | `0x024` | `0x40005824` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXDATA[7:0] (RO)（8-位接收数据） | — |
| `I2C_TXDR` | I2C 发送数据寄存器 | `0x028` | `0x40005828` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXDATA[7:0] (RW)（8-位发送数据） | — |

## I2C3

**模块用途**　双线串行总线控制器，通过 SCL 和 SDA 与外部器件通信，可配置地址、时序以及收发。

基地址 `0x40005C00` · SVD，继承 I2C1_I3C1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `I2C_CR1` | I2C 控制寄存器 1 | `0x000` | `0x40005C00` | 32 | — | 0x00000000 / 0xFFFFFFFF | STOPFACLR[31] (RW)（待核）、ADDRACLR[30] (RW)（待核）、FMP[24] (RW)（待核）、PECEN[23] (RW)（PEC 使能）、ALERTEN[22] (RW)（待核）、SMBDEN[21] (RW)（SMBUS 设备默认地址使能）、SMBHEN[20] (RW)（SMBUS 主机地址使能）、GCEN[19] (RW)（待核）、WUPEN[18] (RW)（唤醒来自停止模式使能）、NOSTRETCH[17] (RW)（待核）、SBC[16] (RW)（从设备字节控制）、RXDMAEN[15] (RW)（DMA 接收请求使能）、TXDMAEN[14] (RW)（DMA 发送请求使能）、ANFOFF[12] (RW)（模拟噪声滤波 OFF）、DNF[11:8] (RW)（数字噪声滤波）、ERRIE[7] (RW)（错误中断使能）、TCIE[6] (RW)（传输完成中断使能）、STOPIE[5] (RW)（停止检测中断使能）、NACKIE[4] (RW)（待核）、ADDRIE[3] (RW)（待核）、RXIE[2] (RW)（接收中断使能）、TXIE[1] (RW)（发送中断使能）、PE[0] (RW)（外设使能） | — |
| `I2C_CR2` | I2C 控制寄存器 2 | `0x004` | `0x40005C04` | 32 | — | 0x00000000 / 0xFFFFFFFF | PECBYTE[26] (RW)（待核）、AUTOEND[25] (RW)（待核）、RELOAD[24] (RW)（NBYTES 重装模式）、NBYTES[23:16] (RW)（数量字节）、NACK[15] (RW)（NACK 生成 (从设备模式)）、STOP[14] (RW)（停止生成 (主设备模式)）、START[13] (RW)（启动生成）、HEAD10R[12] (RW)（待核）、ADD10[11] (RW)（待核）、RD_WRN[10] (RW)（传输方向 (主设备模式)）、SADD[9:0] (RW)（从设备地址 (主设备模式)） | — |
| `I2C_OAR1` | I2C 本机地址 1 寄存器 | `0x008` | `0x40005C08` | 32 | — | 0x00000000 / 0xFFFFFFFF | OA1EN[15] (RW)（本机地址 1 使能）、OA1MODE[10] (RW)（本机地址 1 10-位模式）、OA1[9:0] (RW)（待核） | — |
| `I2C_OAR2` | I2C 本机地址 2 寄存器 | `0x00C` | `0x40005C0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | OA2EN[15] (RW)（本机地址 2 使能）、OA2MSK[10:8] (RW)（待核）、OA2[7:1] (RW)（接口地址） | — |
| `I2C_TIMINGR` | I2C 时序寄存器 | `0x010` | `0x40005C10` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRESC[31:28] (RW)（时序预分频器）、SCLDEL[23:20] (RW)（待核）、SDADEL[19:16] (RW)（数据保持时间）、SCLH[15:8] (RW)（SCL 高位周期 (主设备模式)）、SCLL[7:0] (RW)（SCL 低位周期 (主设备模式)） | — |
| `I2C_TIMEOUTR` | I2C 超时寄存器 | `0x014` | `0x40005C14` | 32 | — | 0x00000000 / 0xFFFFFFFF | TEXTEN[31] (RW)（扩展时钟超时使能）、TIMEOUTB[27:16] (RW)（总线超时 B）、TIMOUTEN[15] (RW)（时钟超时使能）、TIDLE[12] (RW)（空闲时钟超时检测）、TIMEOUTA[11:0] (RW)（总线超时） | — |
| `I2C_ISR` | I2C 中断与状态寄存器 | `0x018` | `0x40005C18` | 32 | — | 0x00000001 / 0xFFFFFFFF | ADDCODE[23:17] (RO)（地址匹配编码 (从设备模式)）、DIR[16] (RO)（传输方向 (从设备模式)）、BUSY[15] (RO)（总线忙）、ALERT[13] (RO)（待核）、TIMEOUT[12] (RO)（待核）、PECERR[11] (RO)（PEC 错误内接收）、OVR[10] (RO)（溢出/欠载 (从设备模式)）、ARLO[9] (RO)（待核）、BERR[8] (RO)（总线错误）、TCR[7] (RO)（传输完成重装）、TC[6] (RO)（传输完成 (主设备模式)）、STOPF[5] (RO)（停止检测标志）、NACKF[4] (RO)（待核）、ADDR[3] (RO)（待核）、RXNE[2] (RO)（待核）、TXIS[1] (RW)（待核）、TXE[0] (RW)（待核） | — |
| `I2C_ICR` | I2C 中断清除寄存器 | `0x01C` | `0x40005C1C` | 32 | — | 0x00000000 / 0xFFFFFFFF | ALERTCF[13] (WO)（待核）、TIMOUTCF[12] (WO)（超时检测清除标志）、PECCF[11] (WO)（PEC 错误清除标志）、OVRCF[10] (WO)（溢出/欠载清除标志）、ARLOCF[9] (WO)（待核）、BERRCF[8] (WO)（总线错误清除标志）、STOPCF[5] (WO)（停止检测清除标志）、NACKCF[4] (WO)（待核）、ADDRCF[3] (WO)（待核） | — |
| `I2C_PECR` | I2C PEC 寄存器 | `0x020` | `0x40005C20` | 32 | — | 0x00000000 / 0xFFFFFFFF | PEC[7:0] (RO)（待核） | — |
| `I2C_RXDR` | I2C 接收数据寄存器 | `0x024` | `0x40005C24` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXDATA[7:0] (RO)（8-位接收数据） | — |
| `I2C_TXDR` | I2C 发送数据寄存器 | `0x028` | `0x40005C28` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXDATA[7:0] (RW)（8-位发送数据） | — |

## I3C1

**模块用途**　I3C 总线控制器的寄存器视图，用于设备寻址、命令和数据传输，与 I2C1 共用基地址。

基地址 `0x40005400` · CMSIS 补表

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `CR` | 本次传输的消息类型、地址、方向和数据量 | `0x000` | `0x40005400` | 32 | — | — / — | MEND[31]（消息结束标记）、MTYPE[30:27]（消息类型）、ADD[23:17]（目标地址字段）、CCC[23:16]（通用命令码）、RNW[16]（读写方向）、DCNT[15:0]（数据字节数） | — |
| `CFGR` | I3C 控制器配置 | `0x004` | `0x40005404` | 32 | — | — / — | TSFSET[30]（传输置位）、CFLUSH[21]（控制 FIFO 清空）、CDMAEN[20]（控制 FIFO DMA 模式使能）、TMODE[19]（控制 FIFO 模式使能）、SMODE[18]（状态 FIFO 模式使能）、SFLUSH[17]（状态 FIFO 清空）、SDMAEN[16]（状态 FIFO DMA 模式使能）、TXTHRES[14]（发送 FIFO 阈值）、TXFLUSH[13]（发送 FIFO 清空）、TXDMAEN[12]（发送 FIFO DMA 模式使能）、RXTHRES[10]（接收 FIFO 阈值）、RXFLUSH[9]（接收 FIFO 清空）、RXDMAEN[8]（接收 FIFO DMA 模式使能）、HJACK[7]（待核）、HKSDAEN[5]（待核）、EXITPTRN[4]（待核）、RSTPTRN[3]（待核）、NOARBH[2]（待核）、CRINIT[1]（待核）、EN[0]（外设使能） | — |
| `RDR` | 接收数据寄存器 | `0x010` | `0x40005410` | 32 | — | — / — | RDB0[7:0]（接收数据字节 0） | — |
| `RDWR` | 按字读取接收数据 | `0x014` | `0x40005414` | 32 | — | — / — | RDB3[31:24]（接收数据字节 3）、RDBx[31:0]（待核）、RDB2[23:16]（接收数据字节 2）、RDB1[15:8]（接收数据字节 1）、RDB0[7:0]（接收数据字节 0） | — |
| `TDR` | 发送数据寄存器 | `0x018` | `0x40005418` | 32 | — | — / — | TDB0[7:0]（发送数据字节 0） | — |
| `TDWR` | 按字写入待发送数据 | `0x01C` | `0x4000541C` | 32 | — | — / — | TDB3[31:24]（发送数据字节 3）、TDBx[31:0]（待核）、TDB2[23:16]（发送数据字节 2）、TDB1[15:8]（发送数据字节 1）、TDB0[7:0]（发送数据字节 0） | — |
| `IBIDR` | 读取带内中断数据 | `0x020` | `0x40005420` | 32 | — | — / — | IBIDB3[31:24]（带内中断数据字节 3）、IBIDBx[31:0]（待核）、IBIDB2[23:16]（带内中断数据字节 2）、IBIDB1[15:8]（带内中断数据字节 1）、IBIDB0[7:0]（带内中断数据字节 0） | — |
| `TGTTDR` | 配置目标模式传输数据 | `0x024` | `0x40005424` | 32 | — | — / — | PRELOAD[16]（发送 FIFO 预装载使能/状态）、TGTTDCNT[15:0]（待核） | — |
| `SR` | 状态寄存器 | `0x030` | `0x40005430` | 32 | — | — / — | MID[31:24]（消息标识符）、DIR[18]（消息方向）、ABT[17]（待核）、XDCNT[15:0]（传输数据字节计数状态） | — |
| `SER` | 状态检测事件使能 | `0x034` | `0x40005434` | 32 | — | — / — | DERR[10]（待核）、DNACK[9]（待核）、ANACK[8]（待核）、COVR[7]（状态/控制 FIFO 溢出）、DOVR[6]（接收/发送 FIFO 溢出）、STALL[5]（SCL STALL 错误）、PERR[4]（协议错误）、CODERR[3:0]（协议错误编码） | — |
| `RMR` | 消息控制信息读回 | `0x040` | `0x40005440` | 32 | — | — / — | RADD[23:17]（待核）、RCODE[15:8]（CCC 编码的已接收命令）、IBIRDCNT[2:0]（待核） | — |
| `EVR` | 事件标志 | `0x050` | `0x40005450` | 32 | — | — / — | GRPF[31]（待核）、DEFF[30]（待核）、INTUPDF[29]（中断更新标志）、ASUPDF[28]（待核）、RSTF[27]（待核）、MRLUPDF[26]（最大值读取长度更新标志）、MWLUPDF[25]（最大值写入长度更新标志）、DAUPDF[24]（待核）、STAF[23]（待核）、GETF[22]（待核）、WKPF[21]（待核）、HJF[19]（待核）、CRUPDF[18]（待核）、CRF[17]（待核）、IBIENDF[16]（IBI 结束标志）、IBIF[15]（IBI 标志）、ERRF[11]（错误标志）、RXTGTENDF[10]（待核）、FCF[9]（帧完成标志）、RXLASTF[7]（末尾接收字节读取来自 FIFO）、TXLASTF[6]（待核）、RXFNEF[5]（待核）、TXFNFF[4]（待核）、SFNEF[3]（待核）、CFNFF[2]（待核）、TXFEF[1]（发送 FIFO 空标志）、CFEF[0]（控制 FIFO 空标志） | — |
| `IER` | 中断使能寄存器 | `0x054` | `0x40005454` | 32 | — | — / — | GRPIE[31]（待核）、DEFIE[30]（待核）、INTUPDIE[29]（中断更新中断使能）、ASUPDIE[28]（待核）、RSTIE[27]（待核）、MRLUPDIE[26]（最大值读取长度更新中断使能）、MWLUPDIE[25]（最大值写入长度更新中断使能）、DAUPDIE[24]（待核）、STAIE[23]（待核）、GETIE[22]（待核）、WKPIE[21]（待核）、HJIE[19]（待核）、CRUPDIE[18]（待核）、CRIE[17]（待核）、IBIENDIE[16]（IBI 结束中断使能）、IBIIE[15]（IBI 中断使能）、ERRIE[11]（错误中断使能）、RXTGTENDIE[10]（待核）、FCIE[9]（帧完成中断使能）、RXFNEIE[5]（待核）、TXFNFIE[4]（待核）、SFNEIE[3]（待核）、CFNFIE[2]（待核） | — |
| `CEVR` | 清除事件标志 | `0x058` | `0x40005458` | 32 | — | — / — | CGRPF[31]（待核）、CDEFF[30]（待核）、CINTUPDF[29]（中断更新清除标志）、CASUPDF[28]（待核）、CRSTF[27]（待核）、CMRLUPDF[26]（最大值读取长度更新清除标志）、CMWLUPDF[25]（最大值写入长度更新清除标志）、CDAUPDF[24]（待核）、CSTAF[23]（待核）、CGETF[22]（待核）、CWKPF[21]（待核）、CHJF[19]（待核）、CCRUPDF[18]（待核）、CCRF[17]（待核）、CIBIENDF[16]（IBI 结束清除标志）、CIBIF[15]（IBI 清除标志）、CERRF[11]（错误清除标志）、CRXTGTENDF[10]（待核）、CFCF[9]（帧完成清除标志） | — |
| `DEVR0` | 设备 0 配置和地址 | `0x060` | `0x40005460` | 32 | — | — / — | RSTVAL[24]（待核）、RSTACT[23:22]（待核）、AS[21:20]（待核）、HJEN[19]（待核）、CREN[17]（待核）、IBIEN[16]（IBI 使能）、DA[7:1]（动态地址）、DAVAL[0]（待核） | — |
| `DEVRX[0]` | 设备配置和地址条目 | `0x064` | `0x40005464` | 32 | — | — / — | DIS[31]（禁用寄存器访问）、SUSP[19]（待核）、IBIDEN[18]（带内中断数据使能）、CRACK[17]（控制器角色请求应答）、IBIACK[16]（带内中断应答）、DA[7:1]（动态地址） | — |
| `DEVRX[1]` | 设备配置和地址条目 | `0x068` | `0x40005468` | 32 | — | — / — | DIS[31]（禁用寄存器访问）、SUSP[19]（待核）、IBIDEN[18]（带内中断数据使能）、CRACK[17]（控制器角色请求应答）、IBIACK[16]（带内中断应答）、DA[7:1]（动态地址） | — |
| `DEVRX[2]` | 设备配置和地址条目 | `0x06C` | `0x4000546C` | 32 | — | — / — | DIS[31]（禁用寄存器访问）、SUSP[19]（待核）、IBIDEN[18]（带内中断数据使能）、CRACK[17]（控制器角色请求应答）、IBIACK[16]（带内中断应答）、DA[7:1]（动态地址） | — |
| `DEVRX[3]` | 设备配置和地址条目 | `0x070` | `0x40005470` | 32 | — | — / — | DIS[31]（禁用寄存器访问）、SUSP[19]（待核）、IBIDEN[18]（带内中断数据使能）、CRACK[17]（控制器角色请求应答）、IBIACK[16]（带内中断应答）、DA[7:1]（动态地址） | — |
| `MAXRLR` | 最大读传输长度 | `0x090` | `0x40005490` | 32 | — | — / — | IBIP[18:16]（IBI 有效载荷大小）、MRL[15:0]（最大读取长度） | — |
| `MAXWLR` | 最大写传输长度 | `0x094` | `0x40005494` | 32 | — | — / — | MWL[15:0]（最大写入长度） | — |
| `TIMINGR0` | 总线时序参数 | `0x0A0` | `0x400054A0` | 32 | — | — / — | SCLH_I2C[31:24]（待核）、SCLL_OD[23:16]（待核）、SCLH_I3C[15:8]（待核）、SCLL_PP[7:0]（待核） | — |
| `TIMINGR1` | 总线时序参数 | `0x0A4` | `0x400054A4` | 32 | — | — / — | SDA_HD[28]（待核）、FREE[22:16]（待核）、ASNCR[9:8]（待核）、AVAL[7:0]（待核） | — |
| `TIMINGR2` | 总线时序参数 | `0x0A8` | `0x400054A8` | 32 | — | — / — | STALL[15:8]（待核）、STALLA[3]（STALL 的 ACK 位）、STALLC[2]（STALL 的 PAR 位的 CCC 字节）、STALLD[1]（STALL 的 PAR 位的数据字节）、STALLT[0]（STALL 的 T 位） | — |
| `BCR` | 总线特性描述符 | `0x0C0` | `0x400054C0` | 32 | — | — / — | BCR[7:0]（总线特性）、BCR6[6]（总线特性描述符位 6）、BCR5[5]（总线特性描述符位 5）、BCR4[4]（总线特性描述符位 4）、BCR3[3]（总线特性描述符位 3）、BCR2[2]（总线特性描述符位 2）、BCR1[1]（总线特性描述符位 1）、BCR0[0]（总线特性描述符位 0） | — |
| `DCR` | 设备特性描述符 | `0x0C4` | `0x400054C4` | 32 | — | — / — | DCR[7:0]（待核） | — |
| `GETCAPR` | GETCAPS 能力数据 | `0x0C8` | `0x400054C8` | 32 | — | — / — | CAPPEND[14]（待核） | — |
| `CRCAPR` | 控制器角色能力数据 | `0x0CC` | `0x400054CC` | 32 | — | — / — | CAPGRP[9]（待核）、CAPDHOFF[3]（待核） | — |
| `GETMXDSR` | GETMXDS 最大数据速率数据 | `0x0D0` | `0x400054D0` | 32 | — | — / — | TSCO[24]（待核）、RDTURN[23:16]（待核）、FMT[9:8]（待核）、HOFFAS[1:0]（待核） | — |
| `EPIDR` | 扩展临时标识数据 | `0x0D4` | `0x400054D4` | 32 | — | — / — | MIPIMID[31:17]（待核）、IDTSEL[16]（待核）、MIPIID[15:12]（待核） | — |

## LPUART1

**模块用途**　低功耗串口，用于异步收发，也可按配置在低功耗场景接收或唤醒。

基地址 `0x58000C00` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `LPUART_CR1_ENABLED` | LPUART 控制寄存器 1 | `0x000` | `0x58000C00` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXFFIE[31] (RW)（RXFIFO 满中断使能）、TXFEIE[30] (RW)（TXFIFO 空中断使能）、FIFOEN[29] (RW)（FIFO 模式使能）、M1[28] (RW)（字长度）、DEAT[25:21] (RW)（待核）、DEDT[20:16] (RW)（待核）、CMIE[14] (RW)（待核）、MME[13] (RW)（待核）、M0[12] (RW)（字长度）、WAKE[11] (RW)（待核）、PCE[10] (RW)（奇偶校验使能）、PS[9] (RW)（选择奇校验或偶校验）、PEIE[8] (RW)（PE 中断使能）、TXFNFIE[7] (RW)（待核）、TCIE[6] (RW)（发送完成中断使能）、RXFNEIE[5] (RW)（待核）、IDLEIE[4] (RW)（空闲中断使能）、TE[3] (RW)（发送器使能）、RE[2] (RW)（接收器使能）、UESM[1] (RW)（LPUART 使能内低位-电源模式）、UE[0] (RW)（串口总使能） | — |
| `LPUART_CR1_DISABLED` | LPUART 控制寄存器 1 | `0x000` | `0x58000C00` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFOEN[29] (RW)（FIFO 模式使能）、M1[28] (RW)（字长度）、DEAT[25:21] (RW)（待核）、DEDT[20:16] (RW)（待核）、CMIE[14] (RW)（待核）、MME[13] (RW)（待核）、M0[12] (RW)（字长度）、WAKE[11] (RW)（待核）、PCE[10] (RW)（奇偶校验使能）、PS[9] (RW)（选择奇校验或偶校验）、PEIE[8] (RW)（PE 中断使能）、TXEIE[7] (RW)（发送数据寄存器空）、TCIE[6] (RW)（发送完成中断使能）、RXNEIE[5] (RW)（待核）、IDLEIE[4] (RW)（空闲中断使能）、TE[3] (RW)（发送器使能）、RE[2] (RW)（接收器使能）、UESM[1] (RW)（LPUART 使能内低位-电源模式）、UE[0] (RW)（串口总使能） | 别名 LPUART_CR1_ENABLED |
| `LPUART_CR2` | LPUART 控制寄存器 2 | `0x004` | `0x58000C04` | 32 | — | 0x00000000 / 0xFFFFFFFF | ADD[31:24] (RW)（待核）、MSBFIRST[19] (RW)（最高有效位首个）、DATAINV[18] (RW)（待核）、TXINV[17] (RW)（待核）、RXINV[16] (RW)（待核）、SWAP[15] (RW)（交换发送/接收引脚）、STOP[13:12] (RW)（停止位长度选择）、ADDM7[4] (RW)（7-位地址检测/4-位地址检测） | — |
| `LPUART_CR3` | LPUART 控制寄存器 3 | `0x008` | `0x58000C08` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXFTCFG[31:29] (RW)（TXFIFO 阈值配置）、RXFTIE[28] (RW)（RXFIFO 阈值中断使能）、RXFTCFG[27:25] (RW)（接收 FIFO 阈值配置）、TXFTIE[23] (RW)（TXFIFO 阈值中断使能）、WUFIE[22] (RW)（唤醒来自低位-电源模式中断使能）、WUS1[21] (RW)（唤醒来自低位-电源模式中断标志选择）、WUS0[20] (RW)（唤醒来自低位-电源模式中断标志选择）、DEP[15] (RW)（待核）、DEM[14] (RW)（待核）、DDRE[13] (RW)（DMA 禁用的接收错误）、OVRDIS[12] (RW)（溢出禁用）、CTSIE[10] (RW)（CTS 中断使能）、CTSE[9] (RW)（CTS 使能）、RTSE[8] (RW)（RTS 使能）、DMAT[7] (RW)（DMA 使能发送器）、DMAR[6] (RW)（DMA 使能接收器）、HDSEL[3] (RW)（待核）、EIE[0] (RW)（错误中断使能） | — |
| `LPUART_BRR` | 波特率配置寄存器 | `0x00C` | `0x58000C0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRR[19:0] (RW)（波特率分频参数） | — |
| `LPUART_RQR` | LPUART 请求寄存器 | `0x018` | `0x58000C18` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXFRQ[4] (WO)（发送数据清空请求）、RXFRQ[3] (WO)（接收数据清空请求）、MMRQ[2] (WO)（待核）、SBKRQ[1] (WO)（待核） | — |
| `LPUART_ISR_ENABLED` | LPUART 中断与状态寄存器 | `0x01C` | `0x58000C1C` | 32 | — | 0x008000C0 / 0xFFFFFFFF | TXFT[27] (RO)（TXFIFO 阈值标志）、RXFT[26] (RO)（RXFIFO 阈值标志）、RXFF[24] (RO)（RXFIFO 满）、TXFE[23] (RO)（TXFIFO 空）、REACK[22] (RO)（接收使能应答标志）、TEACK[21] (RO)（发送使能应答标志）、WUF[20] (RO)（唤醒来自低位-电源模式标志）、RWU[19] (RO)（待核）、SBKF[18] (RO)（待核）、CMF[17] (RO)（待核）、BUSY[16] (RO)（忙标志）、CTS[10] (RO)（CTS 标志）、CTSIF[9] (RO)（CTS 中断标志）、TXFNF[7] (RO)（发送 FIFO 未满）、TC[6] (RO)（发送完成）、RXFNE[5] (RO)（接收 FIFO 非空）、IDLE[4] (RO)（空闲行检测到）、ORE[3] (RO)（溢出错误）、NE[2] (RO)（起始位噪声检测标志）、FE[1] (RO)（帧错误）、PE[0] (RO)（校验错误） | — |
| `LPUART_ISR_DISABLED` | LPUART 中断与状态寄存器 | `0x01C` | `0x58000C1C` | 32 | — | 0x008000C0 / 0xFFFFFFFF | REACK[22] (RO)（接收使能应答标志）、TEACK[21] (RO)（发送使能应答标志）、WUF[20] (RO)（唤醒来自低位-电源模式标志）、RWU[19] (RO)（待核）、SBKF[18] (RO)（待核）、CMF[17] (RO)（待核）、BUSY[16] (RO)（忙标志）、CTS[10] (RO)（CTS 标志）、CTSIF[9] (RO)（CTS 中断标志）、TXE[7] (RO)（发送数据寄存器空）、TC[6] (RO)（发送完成）、RXNE[5] (RO)（接收数据寄存器非空）、IDLE[4] (RO)（空闲行检测到）、ORE[3] (RO)（溢出错误）、NE[2] (RO)（起始位噪声检测标志）、FE[1] (RO)（帧错误）、PE[0] (RO)（校验错误） | 别名 LPUART_ISR_ENABLED |
| `LPUART_ICR` | LPUART 中断标志清除寄存器 | `0x020` | `0x58000C20` | 32 | — | 0x00000000 / 0xFFFFFFFF | WUCF[20] (WO)（唤醒来自低位-电源模式清除标志）、CMCF[17] (WO)（待核）、CTSCF[9] (WO)（CTS 清除标志）、TCCF[6] (WO)（发送完成清除标志）、IDLECF[4] (WO)（空闲行检测到清除标志）、ORECF[3] (WO)（溢出错误清除标志）、NECF[2] (WO)（噪声检测到清除标志）、FECF[1] (WO)（帧错误清除标志）、PECF[0] (WO)（校验错误清除标志） | — |
| `LPUART_RDR` | 接收数据寄存器 | `0x024` | `0x58000C24` | 32 | — | 0x00000000 / 0xFFFFFFFF | RDR[8:0] (RO)（接收数据值） | — |
| `LPUART_TDR` | 发送数据寄存器 | `0x028` | `0x58000C28` | 32 | — | 0x00000000 / 0xFFFFFFFF | TDR[8:0] (RW)（发送数据值） | — |
| `LPUART_PRESC` | LPUART 预分频器寄存器 | `0x02C` | `0x58000C2C` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRESCALER[3:0] (RW)（时钟预分频器） | — |

## LPUART1_CMSIS

**模块用途**　低功耗串口的芯片头文件补充视图，和 LPUART1 主表对照使用。

基地址 `0x58000C00` · CMSIS 补表

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `GTPR` | 保护时间与预分频寄存器 | `0x010` | `0x58000C10` | 32 | — | — / — | GT[15:8]（待核）、PSC[7:0]（待核） | — |
| `RTOR` | 接收超时配置寄存器 | `0x014` | `0x58000C14` | 32 | — | — / — | BLEN[31:24]（待核）、RTO[23:0]（待核） | — |

## SAI1

**模块用途**　串行音频接口。使用时钟、帧和时隙配置与外部音频器件交换采样数据。

基地址 `0x42005800` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `SAI_GCR` | SAI 全局配置寄存器 | `0x000` | `0x42005800` | 32 | — | 0x00000000 / 0xFFFFFFFF | SYNCOUT[5:4] (RW)（待核）、SYNCIN[1:0] (RW)（待核） | — |
| `SAI_ACR1` | SAI 配置寄存器 1 | `0x004` | `0x42005804` | 32 | — | 0x00000040 / 0xFFFFFFFF | MCKEN[27] (RW)（主设备时钟生成使能）、OSR[26] (RW)（待核）、MCKDIV[25:20] (RW)（主设备时钟分频）、NODIV[19] (RW)（待核）、DMAEN[17] (RW)（DMA 使能）、SAIEN[16] (RW)（待核）、OUTDRIV[13] (RW)（待核）、MONO[12] (RW)（待核）、SYNCEN[11:10] (RW)（同步使能）、CKSTR[9] (RW)（待核）、LSBFIRST[8] (RW)（最低有效位首个）、DS[7:5] (RW)（数据大小）、PRTCFG[3:2] (RW)（协议配置）、MODE[1:0] (RW)（待核） | — |
| `SAI_ACR2` | SAI 配置寄存器 2 | `0x008` | `0x42005808` | 32 | — | 0x00000000 / 0xFFFFFFFF | COMP[15:14] (RW)（待核）、CPL[13] (RW)（待核）、MUTECNT[12:7] (RW)（待核）、MUTEVAL[6] (RW)（待核）、MUTE[5] (RW)（待核）、TRIS[4] (RW)（待核）、FFLUSH[3] (WO)（FIFO 清空）、FTH[2:0] (RW)（FIFO 阈值） | — |
| `SAI_AFRCR` | SAI 帧配置寄存器 | `0x00C` | `0x4200580C` | 32 | — | 0x00000007 / 0xFFFFFFFF | FSOFF[18] (RW)（帧同步偏移）、FSPOL[17] (RW)（帧同步极性）、FSDEF[16] (RO)（待核）、FSALL[14:8] (RW)（帧同步活动电平长度）、FRL[7:0] (RW)（帧长度） | — |
| `SAI_ASLOTR` | SAI 时隙寄存器 | `0x010` | `0x42005810` | 32 | — | 0x00000000 / 0xFFFFFFFF | SLOTEN[31:16] (RW)（时隙使能）、NBSLOT[11:8] (RW)（待核）、SLOTSZ[7:6] (RW)（时隙大小）、FBOFF[4:0] (RW)（首个位偏移） | — |
| `SAI_AIM` | SAI 中断屏蔽寄存器 | `0x014` | `0x42005814` | 32 | — | 0x00000000 / 0xFFFFFFFF | LFSDETIE[6] (RW)（待核）、AFSDETIE[5] (RW)（待核）、CNRDYIE[4] (RW)（待核）、FREQIE[3] (RW)（FIFO 请求中断使能）、WCKCFGIE[2] (RW)（待核）、MUTEDETIE[1] (RW)（待核）、OVRUDRIE[0] (RW)（溢出/欠载中断使能） | — |
| `SAI_ASR` | SAI 状态寄存器 | `0x018` | `0x42005818` | 32 | — | 0x00000008 / 0xFFFFFFFF | FLVL[18:16] (RO)（FIFO 电平阈值）、LFSDET[6] (RO)（待核）、AFSDET[5] (RO)（待核）、CNRDY[4] (RO)（待核）、FREQ[3] (RO)（FIFO 请求）、WCKCFG[2] (RO)（待核）、MUTEDET[1] (RO)（待核）、OVRUDR[0] (RO)（溢出 / 欠载） | — |
| `SAI_ACLRFR` | SAI 清除标志寄存器 | `0x01C` | `0x4200581C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CLFSDET[6] (WO)（待核）、CAFSDET[5] (WO)（待核）、CCNRDY[4] (WO)（待核）、CWCKCFG[2] (WO)（待核）、CMUTEDET[1] (WO)（待核）、COVRUDR[0] (WO)（清除溢出 / 欠载） | — |
| `SAI_ADR` | SAI 数据寄存器 | `0x020` | `0x42005820` | 32 | — | 0x00000000 / 0xFFFFFFFF | DATA[31:0] (RW)（数据） | — |
| `SAI_BCR1` | SAI 配置寄存器 1 | `0x024` | `0x42005824` | 32 | — | 0x00000040 / 0xFFFFFFFF | MCKEN[27] (RW)（主设备时钟生成使能）、OSR[26] (RW)（待核）、MCKDIV[25:20] (RW)（主设备时钟分频）、NODIV[19] (RW)（待核）、DMAEN[17] (RW)（DMA 使能）、SAIEN[16] (RW)（待核）、OUTDRIV[13] (RW)（待核）、MONO[12] (RW)（待核）、SYNCEN[11:10] (RW)（同步使能）、CKSTR[9] (RW)（待核）、LSBFIRST[8] (RW)（最低有效位首个）、DS[7:5] (RW)（数据大小）、PRTCFG[3:2] (RW)（协议配置）、MODE[1:0] (RW)（待核） | — |
| `SAI_BCR2` | SAI 配置寄存器 2 | `0x028` | `0x42005828` | 32 | — | 0x00000000 / 0xFFFFFFFF | COMP[15:14] (RW)（待核）、CPL[13] (RW)（待核）、MUTECNT[12:7] (RW)（待核）、MUTEVAL[6] (RW)（待核）、MUTE[5] (RW)（待核）、TRIS[4] (RW)（待核）、FFLUSH[3] (WO)（FIFO 清空）、FTH[2:0] (RW)（FIFO 阈值） | — |
| `SAI_BFRCR` | SAI 帧配置寄存器 | `0x02C` | `0x4200582C` | 32 | — | 0x00000007 / 0xFFFFFFFF | FSOFF[18] (RW)（帧同步偏移）、FSPOL[17] (RW)（帧同步极性）、FSDEF[16] (RO)（待核）、FSALL[14:8] (RW)（帧同步活动电平长度）、FRL[7:0] (RW)（帧长度） | — |
| `SAI_BSLOTR` | SAI 时隙寄存器 | `0x030` | `0x42005830` | 32 | — | 0x00000000 / 0xFFFFFFFF | SLOTEN[31:16] (RW)（时隙使能）、NBSLOT[11:8] (RW)（待核）、SLOTSZ[7:6] (RW)（时隙大小）、FBOFF[4:0] (RW)（首个位偏移） | — |
| `SAI_BIM` | SAI 中断屏蔽寄存器 | `0x034` | `0x42005834` | 32 | — | 0x00000000 / 0xFFFFFFFF | LFSDETIE[6] (RW)（待核）、AFSDETIE[5] (RW)（待核）、CNRDYIE[4] (RW)（待核）、FREQIE[3] (RW)（FIFO 请求中断使能）、WCKCFGIE[2] (RW)（待核）、MUTEDETIE[1] (RW)（待核）、OVRUDRIE[0] (RW)（溢出/欠载中断使能） | — |
| `SAI_BSR` | SAI 状态寄存器 | `0x038` | `0x42005838` | 32 | — | 0x00000008 / 0xFFFFFFFF | FLVL[18:16] (RO)（FIFO 电平阈值）、LFSDET[6] (RO)（待核）、AFSDET[5] (RO)（待核）、CNRDY[4] (RO)（待核）、FREQ[3] (RO)（FIFO 请求）、WCKCFG[2] (RO)（待核）、MUTEDET[1] (RO)（待核）、OVRUDR[0] (RO)（溢出 / 欠载） | — |
| `SAI_BCLRFR` | SAI 清除标志寄存器 | `0x03C` | `0x4200583C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CLFSDET[6] (WO)（待核）、CAFSDET[5] (WO)（待核）、CCNRDY[4] (WO)（待核）、CWCKCFG[2] (WO)（待核）、CMUTEDET[1] (WO)（待核）、COVRUDR[0] (WO)（清除溢出 / 欠载） | — |
| `SAI_BDR` | SAI 数据寄存器 | `0x040` | `0x42005840` | 32 | — | 0x00000000 / 0xFFFFFFFF | DATA[31:0] (RW)（数据） | — |
| `SAI_PDMCR` | SAI PDM 控制寄存器 | `0x044` | `0x42005844` | 32 | — | 0x00000000 / 0xFFFFFFFF | CKEN2[9] (RW)（时钟使能的位流时钟编号 2）、CKEN1[8] (RW)（时钟使能的位流时钟编号 1）、MICNBR[5:4] (RW)（待核）、PDMEN[0] (RW)（PDM 使能） | — |
| `SAI_PDMDLY` | SAI PDM 延迟寄存器 | `0x048` | `0x42005848` | 32 | — | 0x00000000 / 0xFFFFFFFF | DLYM4R[30:28] (RW)（待核）、DLYM4L[26:24] (RW)（待核）、DLYM3R[22:20] (RW)（待核）、DLYM3L[18:16] (RW)（待核）、DLYM2R[14:12] (RW)（待核）、DLYM2L[10:8] (RW)（待核）、DLYM1R[6:4] (RW)（待核）、DLYM1L[2:0] (RW)（待核） | — |

## SAI2

**模块用途**　串行音频接口。使用时钟、帧和时隙配置与外部音频器件交换采样数据。

基地址 `0x42005C00` · SVD，继承 SAI1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `SAI_GCR` | SAI 全局配置寄存器 | `0x000` | `0x42005C00` | 32 | — | 0x00000000 / 0xFFFFFFFF | SYNCOUT[5:4] (RW)（待核）、SYNCIN[1:0] (RW)（待核） | — |
| `SAI_ACR1` | SAI 配置寄存器 1 | `0x004` | `0x42005C04` | 32 | — | 0x00000040 / 0xFFFFFFFF | MCKEN[27] (RW)（主设备时钟生成使能）、OSR[26] (RW)（待核）、MCKDIV[25:20] (RW)（主设备时钟分频）、NODIV[19] (RW)（待核）、DMAEN[17] (RW)（DMA 使能）、SAIEN[16] (RW)（待核）、OUTDRIV[13] (RW)（待核）、MONO[12] (RW)（待核）、SYNCEN[11:10] (RW)（同步使能）、CKSTR[9] (RW)（待核）、LSBFIRST[8] (RW)（最低有效位首个）、DS[7:5] (RW)（数据大小）、PRTCFG[3:2] (RW)（协议配置）、MODE[1:0] (RW)（待核） | — |
| `SAI_ACR2` | SAI 配置寄存器 2 | `0x008` | `0x42005C08` | 32 | — | 0x00000000 / 0xFFFFFFFF | COMP[15:14] (RW)（待核）、CPL[13] (RW)（待核）、MUTECNT[12:7] (RW)（待核）、MUTEVAL[6] (RW)（待核）、MUTE[5] (RW)（待核）、TRIS[4] (RW)（待核）、FFLUSH[3] (WO)（FIFO 清空）、FTH[2:0] (RW)（FIFO 阈值） | — |
| `SAI_AFRCR` | SAI 帧配置寄存器 | `0x00C` | `0x42005C0C` | 32 | — | 0x00000007 / 0xFFFFFFFF | FSOFF[18] (RW)（帧同步偏移）、FSPOL[17] (RW)（帧同步极性）、FSDEF[16] (RO)（待核）、FSALL[14:8] (RW)（帧同步活动电平长度）、FRL[7:0] (RW)（帧长度） | — |
| `SAI_ASLOTR` | SAI 时隙寄存器 | `0x010` | `0x42005C10` | 32 | — | 0x00000000 / 0xFFFFFFFF | SLOTEN[31:16] (RW)（时隙使能）、NBSLOT[11:8] (RW)（待核）、SLOTSZ[7:6] (RW)（时隙大小）、FBOFF[4:0] (RW)（首个位偏移） | — |
| `SAI_AIM` | SAI 中断屏蔽寄存器 | `0x014` | `0x42005C14` | 32 | — | 0x00000000 / 0xFFFFFFFF | LFSDETIE[6] (RW)（待核）、AFSDETIE[5] (RW)（待核）、CNRDYIE[4] (RW)（待核）、FREQIE[3] (RW)（FIFO 请求中断使能）、WCKCFGIE[2] (RW)（待核）、MUTEDETIE[1] (RW)（待核）、OVRUDRIE[0] (RW)（溢出/欠载中断使能） | — |
| `SAI_ASR` | SAI 状态寄存器 | `0x018` | `0x42005C18` | 32 | — | 0x00000008 / 0xFFFFFFFF | FLVL[18:16] (RO)（FIFO 电平阈值）、LFSDET[6] (RO)（待核）、AFSDET[5] (RO)（待核）、CNRDY[4] (RO)（待核）、FREQ[3] (RO)（FIFO 请求）、WCKCFG[2] (RO)（待核）、MUTEDET[1] (RO)（待核）、OVRUDR[0] (RO)（溢出 / 欠载） | — |
| `SAI_ACLRFR` | SAI 清除标志寄存器 | `0x01C` | `0x42005C1C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CLFSDET[6] (WO)（待核）、CAFSDET[5] (WO)（待核）、CCNRDY[4] (WO)（待核）、CWCKCFG[2] (WO)（待核）、CMUTEDET[1] (WO)（待核）、COVRUDR[0] (WO)（清除溢出 / 欠载） | — |
| `SAI_ADR` | SAI 数据寄存器 | `0x020` | `0x42005C20` | 32 | — | 0x00000000 / 0xFFFFFFFF | DATA[31:0] (RW)（数据） | — |
| `SAI_BCR1` | SAI 配置寄存器 1 | `0x024` | `0x42005C24` | 32 | — | 0x00000040 / 0xFFFFFFFF | MCKEN[27] (RW)（主设备时钟生成使能）、OSR[26] (RW)（待核）、MCKDIV[25:20] (RW)（主设备时钟分频）、NODIV[19] (RW)（待核）、DMAEN[17] (RW)（DMA 使能）、SAIEN[16] (RW)（待核）、OUTDRIV[13] (RW)（待核）、MONO[12] (RW)（待核）、SYNCEN[11:10] (RW)（同步使能）、CKSTR[9] (RW)（待核）、LSBFIRST[8] (RW)（最低有效位首个）、DS[7:5] (RW)（数据大小）、PRTCFG[3:2] (RW)（协议配置）、MODE[1:0] (RW)（待核） | — |
| `SAI_BCR2` | SAI 配置寄存器 2 | `0x028` | `0x42005C28` | 32 | — | 0x00000000 / 0xFFFFFFFF | COMP[15:14] (RW)（待核）、CPL[13] (RW)（待核）、MUTECNT[12:7] (RW)（待核）、MUTEVAL[6] (RW)（待核）、MUTE[5] (RW)（待核）、TRIS[4] (RW)（待核）、FFLUSH[3] (WO)（FIFO 清空）、FTH[2:0] (RW)（FIFO 阈值） | — |
| `SAI_BFRCR` | SAI 帧配置寄存器 | `0x02C` | `0x42005C2C` | 32 | — | 0x00000007 / 0xFFFFFFFF | FSOFF[18] (RW)（帧同步偏移）、FSPOL[17] (RW)（帧同步极性）、FSDEF[16] (RO)（待核）、FSALL[14:8] (RW)（帧同步活动电平长度）、FRL[7:0] (RW)（帧长度） | — |
| `SAI_BSLOTR` | SAI 时隙寄存器 | `0x030` | `0x42005C30` | 32 | — | 0x00000000 / 0xFFFFFFFF | SLOTEN[31:16] (RW)（时隙使能）、NBSLOT[11:8] (RW)（待核）、SLOTSZ[7:6] (RW)（时隙大小）、FBOFF[4:0] (RW)（首个位偏移） | — |
| `SAI_BIM` | SAI 中断屏蔽寄存器 | `0x034` | `0x42005C34` | 32 | — | 0x00000000 / 0xFFFFFFFF | LFSDETIE[6] (RW)（待核）、AFSDETIE[5] (RW)（待核）、CNRDYIE[4] (RW)（待核）、FREQIE[3] (RW)（FIFO 请求中断使能）、WCKCFGIE[2] (RW)（待核）、MUTEDETIE[1] (RW)（待核）、OVRUDRIE[0] (RW)（溢出/欠载中断使能） | — |
| `SAI_BSR` | SAI 状态寄存器 | `0x038` | `0x42005C38` | 32 | — | 0x00000008 / 0xFFFFFFFF | FLVL[18:16] (RO)（FIFO 电平阈值）、LFSDET[6] (RO)（待核）、AFSDET[5] (RO)（待核）、CNRDY[4] (RO)（待核）、FREQ[3] (RO)（FIFO 请求）、WCKCFG[2] (RO)（待核）、MUTEDET[1] (RO)（待核）、OVRUDR[0] (RO)（溢出 / 欠载） | — |
| `SAI_BCLRFR` | SAI 清除标志寄存器 | `0x03C` | `0x42005C3C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CLFSDET[6] (WO)（待核）、CAFSDET[5] (WO)（待核）、CCNRDY[4] (WO)（待核）、CWCKCFG[2] (WO)（待核）、CMUTEDET[1] (WO)（待核）、COVRUDR[0] (WO)（清除溢出 / 欠载） | — |
| `SAI_BDR` | SAI 数据寄存器 | `0x040` | `0x42005C40` | 32 | — | 0x00000000 / 0xFFFFFFFF | DATA[31:0] (RW)（数据） | — |
| `SAI_PDMCR` | SAI PDM 控制寄存器 | `0x044` | `0x42005C44` | 32 | — | 0x00000000 / 0xFFFFFFFF | CKEN2[9] (RW)（时钟使能的位流时钟编号 2）、CKEN1[8] (RW)（时钟使能的位流时钟编号 1）、MICNBR[5:4] (RW)（待核）、PDMEN[0] (RW)（PDM 使能） | — |
| `SAI_PDMDLY` | SAI PDM 延迟寄存器 | `0x048` | `0x42005C48` | 32 | — | 0x00000000 / 0xFFFFFFFF | DLYM4R[30:28] (RW)（待核）、DLYM4L[26:24] (RW)（待核）、DLYM3R[22:20] (RW)（待核）、DLYM3L[18:16] (RW)（待核）、DLYM2R[14:12] (RW)（待核）、DLYM2L[10:8] (RW)（待核）、DLYM1R[6:4] (RW)（待核）、DLYM1L[2:0] (RW)（待核） | — |

## SPDIFRX

**模块用途**　S/PDIF 接收器，用于从数字音频流中恢复时钟并提取音频与状态数据。

基地址 `0x40004000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `SPDIFRX_CR` | SPDIFRX 控制寄存器 | `0x000` | `0x40004000` | 32 | — | 0x00000000 / 0xFFFFFFFF | CKSBKPEN[21] (RW)（备份符号时钟使能）、CKSEN[20] (RW)（符号时钟使能）、INSEL[18:16] (RW)（SPDIFRX 输入选择）、WFA[14] (RW)（待核）、NBTR[13:12] (RW)（待核）、CHSEL[11] (RW)（待核）、CBDMAEN[10] (RW)（待核）、PTMSK[9] (RW)（待核）、CUMSK[8] (RW)（待核）、VMSK[7] (RW)（待核）、PMSK[6] (RW)（待核）、DRFMT[5:4] (RW)（待核）、RXSTEO[3] (RW)（待核）、RXDMAEN[2] (RW)（待核）、SPDIFRXEN[1:0] (RW)（待核） | — |
| `SPDIFRX_IMR` | SPDIFRX 中断屏蔽寄存器 | `0x004` | `0x40004004` | 32 | — | 0x00000000 / 0xFFFFFFFF | IFEIE[6] (RW)（串行接口错误中断使能）、SYNCDIE[5] (RW)（待核）、SBLKIE[4] (RW)（同步块检测到中断使能）、OVRIE[3] (RW)（溢出错误中断使能）、PERRIE[2] (RW)（校验错误中断使能）、CSRNEIE[1] (RW)（控制缓冲区就绪中断使能）、RXNEIE[0] (RW)（RXNE 中断使能） | — |
| `SPDIFRX_SR` | SPDIFRX 状态寄存器 | `0x008` | `0x40004008` | 32 | — | 0x00000000 / 0xFFFFFFFF | WIDTH5[30:16] (RO)（待核）、TERR[8] (RO)（待核）、SERR[7] (RO)（同步错误）、FERR[6] (RO)（帧错误）、SYNCD[5] (RO)（待核）、SBD[4] (RO)（同步块检测到）、OVR[3] (RO)（溢出错误）、PERR[2] (RO)（校验错误）、CSRNE[1] (RO)（待核）、RXNE[0] (RO)（待核） | — |
| `SPDIFRX_IFCR` | SPDIFRX 中断标志清除寄存器 | `0x00C` | `0x4000400C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SYNCDCF[5] (WO)（待核）、SBDCF[4] (WO)（待核）、OVRCF[3] (WO)（待核）、PERRCF[2] (WO)（待核） | — |
| `SPDIFRX_FMT0_DR` | SPDIFRX 数据输入寄存器 | `0x010` | `0x40004010` | 32 | — | 0x00000000 / 0xFFFFFFFF | PT[29:28] (RO)（待核）、C[27] (RO)（通道状态位）、U[26] (RO)（用户位）、V[25] (RO)（待核）、PE[24] (RO)（校验错误位）、DR[23:0] (RO)（数据值） | — |
| `SPDIFRX_FMT0_DR_alternate1` | SPDIFRX 数据输入寄存器 | `0x010` | `0x40004010` | 32 | — | 0x00000000 / 0xFFFFFFFF | DR[31:8] (RO)（数据值）、PT[5:4] (RO)（待核）、C[3] (RO)（通道状态位）、U[2] (RO)（用户位）、V[1] (RO)（待核）、PE[0] (RO)（校验错误位） | 别名 SPDIFRX_FMT0_DR |
| `SPDIFRX_FMT0_DR_alternate2` | SPDIFRX 数据输入寄存器 | `0x010` | `0x40004010` | 32 | — | 0x00000000 / 0xFFFFFFFF | DRNL2[31:16] (RO)（数据值）、DRNL1[15:0] (RO)（数据值） | 别名 SPDIFRX_FMT0_DR |
| `SPDIFRX_CSR` | SPDIFRX 通道状态寄存器 | `0x014` | `0x40004014` | 32 | — | 0x00000000 / 0xFFFFFFFF | SOB[24] (RO)（启动的块）、CS[23:16] (RO)（待核）、USR[15:0] (RO)（待核） | — |
| `SPDIFRX_DIR` | S/PDIF 接收器调试信息 | `0x018` | `0x40004018` | 32 | — | 0x00000000 / 0xFFFFFFFF | TLO[28:16] (RO)（待核）、THI[12:0] (RO)（待核） | — |

## SPI1

**模块用途**　同步串行接口，按实例支持相应的收发及帧格式。主要配置时钟、数据宽度、片选和传输模式。

基地址 `0x42003000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `SPI_CR1` | SPI/I2S 控制寄存器 1 | `0x000` | `0x42003000` | 32 | — | 0x00000000 / 0xFFFFFFFF | IOLOCK[16] (RW)（待核）、TCRCINI[15] (RW)（待核）、RCRCINI[14] (RW)（待核）、CRC33_17[13] (RW)（32-位 CRC 多项式配置）、SSI[12] (RW)（待核）、HDDIR[11] (RW)（待核）、CSUSP[10] (WO)（主设备挂起请求）、CSTART[9] (RW)（主设备传输启动）、MASRX[8] (RW)（待核）、SPE[0] (RW)（串行外设使能） | — |
| `SPI_CR2` | SPI/I2S 控制寄存器 2 | `0x004` | `0x42003004` | 32 | — | 0x00000000 / 0xFFFFFFFF | TSIZE[15:0] (RW)（待核） | — |
| `SPI_CFG1` | SPI/I2S 配置寄存器 1 | `0x008` | `0x42003008` | 32 | — | 0x00070007 / 0xFFFFFFFF | BPASS[31] (RW)（待核）、MBR[30:28] (RW)（待核）、CRCEN[22] (RW)（待核）、CRCSIZE[20:16] (RW)（待核）、TXDMAEN[15] (RW)（待核）、RXDMAEN[14] (RW)（待核）、UDRCFG[9] (RW)（待核）、FTHLV[8:5] (RW)（FIFO 阈值）、DSIZE[4:0] (RW)（待核） | — |
| `SPI_CFG2` | SPI/I2S 配置寄存器 2 | `0x00C` | `0x4200300C` | 32 | — | 0x00000000 / 0xFFFFFFFF | AFCNTR[31] (RW)（待核）、SSOM[30] (RW)（SS 输出管理内主设备模式）、SSOE[29] (RW)（SS 输出使能）、SSIOP[28] (RW)（SS 输入/输出极性）、SSM[26] (RW)（待核）、CPOL[25] (RW)（时钟极性）、CPHA[24] (RW)（时钟相位）、LSBFRST[23] (RW)（数据帧格式）、MASTER[22] (RW)（SPI 主设备）、SP[21:19] (RW)（串行协议）、COMM[18:17] (RW)（SPI 通信模式）、IOSWP[15] (RW)（待核）、RDIOP[14] (RW)（待核）、RDIOM[13] (RW)（待核）、MIDI[7:4] (RW)（待核）、MSSI[3:0] (RW)（待核） | — |
| `SPI_IER` | SPI/I2S 中断使能寄存器 | `0x010` | `0x42003010` | 32 | — | 0x00000000 / 0xFFFFFFFF | MODFIE[9] (RW)（待核）、TIFREIE[8] (RW)（TIFRE 中断使能）、CRCEIE[7] (RW)（CRC 错误中断使能）、OVRIE[6] (RW)（OVR 中断使能）、UDRIE[5] (RW)（UDR 中断使能）、TXTFIE[4] (RW)（TXTFIE 中断使能）、EOTIE[3] (RW)（EOT, SUSP 与 TXC 中断使能）、DXPIE[2] (RW)（DXP 中断使能）、TXPIE[1] (RW)（TXP 中断使能）、RXPIE[0] (RW)（RXP 中断使能） | — |
| `SPI_SR` | SPI/I2S 状态寄存器 | `0x014` | `0x42003014` | 32 | — | 0x00001002 / 0xFFFFFFFF | CTSIZE[31:16] (RO)（待核）、RXWNE[15] (RO)（待核）、RXPLVL[14:13] (RO)（待核）、TXC[12] (RO)（待核）、SUSP[11] (RO)（挂起状态）、MODF[9] (RO)（待核）、TIFRE[8] (RO)（TI 帧格式错误）、CRCE[7] (RO)（CRC 错误）、OVR[6] (RO)（溢出）、UDR[5] (RO)（欠载）、TXTF[4] (RO)（待核）、EOT[3] (RO)（结束的传输）、DXP[2] (RO)（待核）、TXP[1] (RO)（待核）、RXP[0] (RO)（待核） | — |
| `SPI_IFCR` | SPI/I2S 中断/状态标志清除寄存器 | `0x018` | `0x42003018` | 32 | — | 0x00000000 / 0xFFFFFFFF | SUSPC[11] (WO)（挂起清除标志）、MODFC[9] (WO)（待核）、TIFREC[8] (WO)（TI 帧格式错误清除标志）、CRCEC[7] (WO)（CRC 错误清除标志）、OVRC[6] (WO)（溢出清除标志）、UDRC[5] (WO)（欠载清除标志）、TXTFC[4] (WO)（待核）、EOTC[3] (WO)（结束的传输清除标志） | — |
| `SPI_TXDR` | SPI/I2S 发送数据寄存器 | `0x020` | `0x42003020` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXDR[31:0] (WO)（发送数据寄存器） | — |
| `SPI_RXDR` | SPI/I2S 接收数据寄存器 | `0x030` | `0x42003030` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXDR[31:0] (RO)（接收数据寄存器） | — |
| `SPI_CRCPOLY` | SPI/I2S 多项式寄存器 | `0x040` | `0x42003040` | 32 | — | 0x00000107 / 0xFFFFFFFF | CRCPOLY[31:0] (RW)（CRC 多项式寄存器） | — |
| `SPI_TXCRC` | SPI/I2S 发送器 CRC 寄存器 | `0x044` | `0x42003044` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXCRC[31:0] (RO)（CRC 寄存器的发送器） | — |
| `SPI_RXCRC` | SPI/I2S 接收器 CRC 寄存器 | `0x048` | `0x42003048` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXCRC[31:0] (RO)（CRC 寄存器的接收器） | — |
| `SPI_UDRDR` | SPI/I2S 欠载数据寄存器 | `0x04C` | `0x4200304C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UDRDR[31:0] (RW)（待核） | — |
| `SPI_I2SCFGR` | SPI/I2S 配置寄存器 | `0x050` | `0x42003050` | 32 | — | 0x00000000 / 0xFFFFFFFF | MCKOE[25] (RW)（主设备时钟输出使能）、ODD[24] (RW)（奇数系数的预分频器）、I2SDIV[23:16] (RW)（待核）、DATFMT[14] (RW)（数据格式）、WSINV[13] (RW)（待核）、FIXCH[12] (RW)（待核）、CKPOL[11] (RW)（待核）、CHLEN[10] (RW)（待核）、DATLEN[9:8] (RW)（待核）、PCMSYNC[7] (RW)（PCM 帧同步）、I2SSTD[5:4] (RW)（待核）、I2SCFG[3:1] (RW)（I2S 配置模式）、I2SMOD[0] (RW)（I2S 模式选择） | — |

## SPI2

**模块用途**　同步串行接口，按实例支持相应的收发及帧格式。主要配置时钟、数据宽度、片选和传输模式。

基地址 `0x40003800` · SVD，继承 SPI1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `SPI_CR1` | SPI/I2S 控制寄存器 1 | `0x000` | `0x40003800` | 32 | — | 0x00000000 / 0xFFFFFFFF | IOLOCK[16] (RW)（待核）、TCRCINI[15] (RW)（待核）、RCRCINI[14] (RW)（待核）、CRC33_17[13] (RW)（32-位 CRC 多项式配置）、SSI[12] (RW)（待核）、HDDIR[11] (RW)（待核）、CSUSP[10] (WO)（主设备挂起请求）、CSTART[9] (RW)（主设备传输启动）、MASRX[8] (RW)（待核）、SPE[0] (RW)（串行外设使能） | — |
| `SPI_CR2` | SPI/I2S 控制寄存器 2 | `0x004` | `0x40003804` | 32 | — | 0x00000000 / 0xFFFFFFFF | TSIZE[15:0] (RW)（待核） | — |
| `SPI_CFG1` | SPI/I2S 配置寄存器 1 | `0x008` | `0x40003808` | 32 | — | 0x00070007 / 0xFFFFFFFF | BPASS[31] (RW)（待核）、MBR[30:28] (RW)（待核）、CRCEN[22] (RW)（待核）、CRCSIZE[20:16] (RW)（待核）、TXDMAEN[15] (RW)（待核）、RXDMAEN[14] (RW)（待核）、UDRCFG[9] (RW)（待核）、FTHLV[8:5] (RW)（FIFO 阈值）、DSIZE[4:0] (RW)（待核） | — |
| `SPI_CFG2` | SPI/I2S 配置寄存器 2 | `0x00C` | `0x4000380C` | 32 | — | 0x00000000 / 0xFFFFFFFF | AFCNTR[31] (RW)（待核）、SSOM[30] (RW)（SS 输出管理内主设备模式）、SSOE[29] (RW)（SS 输出使能）、SSIOP[28] (RW)（SS 输入/输出极性）、SSM[26] (RW)（待核）、CPOL[25] (RW)（时钟极性）、CPHA[24] (RW)（时钟相位）、LSBFRST[23] (RW)（数据帧格式）、MASTER[22] (RW)（SPI 主设备）、SP[21:19] (RW)（串行协议）、COMM[18:17] (RW)（SPI 通信模式）、IOSWP[15] (RW)（待核）、RDIOP[14] (RW)（待核）、RDIOM[13] (RW)（待核）、MIDI[7:4] (RW)（待核）、MSSI[3:0] (RW)（待核） | — |
| `SPI_IER` | SPI/I2S 中断使能寄存器 | `0x010` | `0x40003810` | 32 | — | 0x00000000 / 0xFFFFFFFF | MODFIE[9] (RW)（待核）、TIFREIE[8] (RW)（TIFRE 中断使能）、CRCEIE[7] (RW)（CRC 错误中断使能）、OVRIE[6] (RW)（OVR 中断使能）、UDRIE[5] (RW)（UDR 中断使能）、TXTFIE[4] (RW)（TXTFIE 中断使能）、EOTIE[3] (RW)（EOT, SUSP 与 TXC 中断使能）、DXPIE[2] (RW)（DXP 中断使能）、TXPIE[1] (RW)（TXP 中断使能）、RXPIE[0] (RW)（RXP 中断使能） | — |
| `SPI_SR` | SPI/I2S 状态寄存器 | `0x014` | `0x40003814` | 32 | — | 0x00001002 / 0xFFFFFFFF | CTSIZE[31:16] (RO)（待核）、RXWNE[15] (RO)（待核）、RXPLVL[14:13] (RO)（待核）、TXC[12] (RO)（待核）、SUSP[11] (RO)（挂起状态）、MODF[9] (RO)（待核）、TIFRE[8] (RO)（TI 帧格式错误）、CRCE[7] (RO)（CRC 错误）、OVR[6] (RO)（溢出）、UDR[5] (RO)（欠载）、TXTF[4] (RO)（待核）、EOT[3] (RO)（结束的传输）、DXP[2] (RO)（待核）、TXP[1] (RO)（待核）、RXP[0] (RO)（待核） | — |
| `SPI_IFCR` | SPI/I2S 中断/状态标志清除寄存器 | `0x018` | `0x40003818` | 32 | — | 0x00000000 / 0xFFFFFFFF | SUSPC[11] (WO)（挂起清除标志）、MODFC[9] (WO)（待核）、TIFREC[8] (WO)（TI 帧格式错误清除标志）、CRCEC[7] (WO)（CRC 错误清除标志）、OVRC[6] (WO)（溢出清除标志）、UDRC[5] (WO)（欠载清除标志）、TXTFC[4] (WO)（待核）、EOTC[3] (WO)（结束的传输清除标志） | — |
| `SPI_TXDR` | SPI/I2S 发送数据寄存器 | `0x020` | `0x40003820` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXDR[31:0] (WO)（发送数据寄存器） | — |
| `SPI_RXDR` | SPI/I2S 接收数据寄存器 | `0x030` | `0x40003830` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXDR[31:0] (RO)（接收数据寄存器） | — |
| `SPI_CRCPOLY` | SPI/I2S 多项式寄存器 | `0x040` | `0x40003840` | 32 | — | 0x00000107 / 0xFFFFFFFF | CRCPOLY[31:0] (RW)（CRC 多项式寄存器） | — |
| `SPI_TXCRC` | SPI/I2S 发送器 CRC 寄存器 | `0x044` | `0x40003844` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXCRC[31:0] (RO)（CRC 寄存器的发送器） | — |
| `SPI_RXCRC` | SPI/I2S 接收器 CRC 寄存器 | `0x048` | `0x40003848` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXCRC[31:0] (RO)（CRC 寄存器的接收器） | — |
| `SPI_UDRDR` | SPI/I2S 欠载数据寄存器 | `0x04C` | `0x4000384C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UDRDR[31:0] (RW)（待核） | — |
| `SPI_I2SCFGR` | SPI/I2S 配置寄存器 | `0x050` | `0x40003850` | 32 | — | 0x00000000 / 0xFFFFFFFF | MCKOE[25] (RW)（主设备时钟输出使能）、ODD[24] (RW)（奇数系数的预分频器）、I2SDIV[23:16] (RW)（待核）、DATFMT[14] (RW)（数据格式）、WSINV[13] (RW)（待核）、FIXCH[12] (RW)（待核）、CKPOL[11] (RW)（待核）、CHLEN[10] (RW)（待核）、DATLEN[9:8] (RW)（待核）、PCMSYNC[7] (RW)（PCM 帧同步）、I2SSTD[5:4] (RW)（待核）、I2SCFG[3:1] (RW)（I2S 配置模式）、I2SMOD[0] (RW)（I2S 模式选择） | — |

## SPI3

**模块用途**　同步串行接口，按实例支持相应的收发及帧格式。主要配置时钟、数据宽度、片选和传输模式。

基地址 `0x40003C00` · SVD，继承 SPI1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `SPI_CR1` | SPI/I2S 控制寄存器 1 | `0x000` | `0x40003C00` | 32 | — | 0x00000000 / 0xFFFFFFFF | IOLOCK[16] (RW)（待核）、TCRCINI[15] (RW)（待核）、RCRCINI[14] (RW)（待核）、CRC33_17[13] (RW)（32-位 CRC 多项式配置）、SSI[12] (RW)（待核）、HDDIR[11] (RW)（待核）、CSUSP[10] (WO)（主设备挂起请求）、CSTART[9] (RW)（主设备传输启动）、MASRX[8] (RW)（待核）、SPE[0] (RW)（串行外设使能） | — |
| `SPI_CR2` | SPI/I2S 控制寄存器 2 | `0x004` | `0x40003C04` | 32 | — | 0x00000000 / 0xFFFFFFFF | TSIZE[15:0] (RW)（待核） | — |
| `SPI_CFG1` | SPI/I2S 配置寄存器 1 | `0x008` | `0x40003C08` | 32 | — | 0x00070007 / 0xFFFFFFFF | BPASS[31] (RW)（待核）、MBR[30:28] (RW)（待核）、CRCEN[22] (RW)（待核）、CRCSIZE[20:16] (RW)（待核）、TXDMAEN[15] (RW)（待核）、RXDMAEN[14] (RW)（待核）、UDRCFG[9] (RW)（待核）、FTHLV[8:5] (RW)（FIFO 阈值）、DSIZE[4:0] (RW)（待核） | — |
| `SPI_CFG2` | SPI/I2S 配置寄存器 2 | `0x00C` | `0x40003C0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | AFCNTR[31] (RW)（待核）、SSOM[30] (RW)（SS 输出管理内主设备模式）、SSOE[29] (RW)（SS 输出使能）、SSIOP[28] (RW)（SS 输入/输出极性）、SSM[26] (RW)（待核）、CPOL[25] (RW)（时钟极性）、CPHA[24] (RW)（时钟相位）、LSBFRST[23] (RW)（数据帧格式）、MASTER[22] (RW)（SPI 主设备）、SP[21:19] (RW)（串行协议）、COMM[18:17] (RW)（SPI 通信模式）、IOSWP[15] (RW)（待核）、RDIOP[14] (RW)（待核）、RDIOM[13] (RW)（待核）、MIDI[7:4] (RW)（待核）、MSSI[3:0] (RW)（待核） | — |
| `SPI_IER` | SPI/I2S 中断使能寄存器 | `0x010` | `0x40003C10` | 32 | — | 0x00000000 / 0xFFFFFFFF | MODFIE[9] (RW)（待核）、TIFREIE[8] (RW)（TIFRE 中断使能）、CRCEIE[7] (RW)（CRC 错误中断使能）、OVRIE[6] (RW)（OVR 中断使能）、UDRIE[5] (RW)（UDR 中断使能）、TXTFIE[4] (RW)（TXTFIE 中断使能）、EOTIE[3] (RW)（EOT, SUSP 与 TXC 中断使能）、DXPIE[2] (RW)（DXP 中断使能）、TXPIE[1] (RW)（TXP 中断使能）、RXPIE[0] (RW)（RXP 中断使能） | — |
| `SPI_SR` | SPI/I2S 状态寄存器 | `0x014` | `0x40003C14` | 32 | — | 0x00001002 / 0xFFFFFFFF | CTSIZE[31:16] (RO)（待核）、RXWNE[15] (RO)（待核）、RXPLVL[14:13] (RO)（待核）、TXC[12] (RO)（待核）、SUSP[11] (RO)（挂起状态）、MODF[9] (RO)（待核）、TIFRE[8] (RO)（TI 帧格式错误）、CRCE[7] (RO)（CRC 错误）、OVR[6] (RO)（溢出）、UDR[5] (RO)（欠载）、TXTF[4] (RO)（待核）、EOT[3] (RO)（结束的传输）、DXP[2] (RO)（待核）、TXP[1] (RO)（待核）、RXP[0] (RO)（待核） | — |
| `SPI_IFCR` | SPI/I2S 中断/状态标志清除寄存器 | `0x018` | `0x40003C18` | 32 | — | 0x00000000 / 0xFFFFFFFF | SUSPC[11] (WO)（挂起清除标志）、MODFC[9] (WO)（待核）、TIFREC[8] (WO)（TI 帧格式错误清除标志）、CRCEC[7] (WO)（CRC 错误清除标志）、OVRC[6] (WO)（溢出清除标志）、UDRC[5] (WO)（欠载清除标志）、TXTFC[4] (WO)（待核）、EOTC[3] (WO)（结束的传输清除标志） | — |
| `SPI_TXDR` | SPI/I2S 发送数据寄存器 | `0x020` | `0x40003C20` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXDR[31:0] (WO)（发送数据寄存器） | — |
| `SPI_RXDR` | SPI/I2S 接收数据寄存器 | `0x030` | `0x40003C30` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXDR[31:0] (RO)（接收数据寄存器） | — |
| `SPI_CRCPOLY` | SPI/I2S 多项式寄存器 | `0x040` | `0x40003C40` | 32 | — | 0x00000107 / 0xFFFFFFFF | CRCPOLY[31:0] (RW)（CRC 多项式寄存器） | — |
| `SPI_TXCRC` | SPI/I2S 发送器 CRC 寄存器 | `0x044` | `0x40003C44` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXCRC[31:0] (RO)（CRC 寄存器的发送器） | — |
| `SPI_RXCRC` | SPI/I2S 接收器 CRC 寄存器 | `0x048` | `0x40003C48` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXCRC[31:0] (RO)（CRC 寄存器的接收器） | — |
| `SPI_UDRDR` | SPI/I2S 欠载数据寄存器 | `0x04C` | `0x40003C4C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UDRDR[31:0] (RW)（待核） | — |
| `SPI_I2SCFGR` | SPI/I2S 配置寄存器 | `0x050` | `0x40003C50` | 32 | — | 0x00000000 / 0xFFFFFFFF | MCKOE[25] (RW)（主设备时钟输出使能）、ODD[24] (RW)（奇数系数的预分频器）、I2SDIV[23:16] (RW)（待核）、DATFMT[14] (RW)（数据格式）、WSINV[13] (RW)（待核）、FIXCH[12] (RW)（待核）、CKPOL[11] (RW)（待核）、CHLEN[10] (RW)（待核）、DATLEN[9:8] (RW)（待核）、PCMSYNC[7] (RW)（PCM 帧同步）、I2SSTD[5:4] (RW)（待核）、I2SCFG[3:1] (RW)（I2S 配置模式）、I2SMOD[0] (RW)（I2S 模式选择） | — |

## SPI4

**模块用途**　同步串行接口，按实例支持相应的收发及帧格式。主要配置时钟、数据宽度、片选和传输模式。

基地址 `0x42003400` · SVD，继承 SPI1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `SPI_CR1` | SPI/I2S 控制寄存器 1 | `0x000` | `0x42003400` | 32 | — | 0x00000000 / 0xFFFFFFFF | IOLOCK[16] (RW)（待核）、TCRCINI[15] (RW)（待核）、RCRCINI[14] (RW)（待核）、CRC33_17[13] (RW)（32-位 CRC 多项式配置）、SSI[12] (RW)（待核）、HDDIR[11] (RW)（待核）、CSUSP[10] (WO)（主设备挂起请求）、CSTART[9] (RW)（主设备传输启动）、MASRX[8] (RW)（待核）、SPE[0] (RW)（串行外设使能） | — |
| `SPI_CR2` | SPI/I2S 控制寄存器 2 | `0x004` | `0x42003404` | 32 | — | 0x00000000 / 0xFFFFFFFF | TSIZE[15:0] (RW)（待核） | — |
| `SPI_CFG1` | SPI/I2S 配置寄存器 1 | `0x008` | `0x42003408` | 32 | — | 0x00070007 / 0xFFFFFFFF | BPASS[31] (RW)（待核）、MBR[30:28] (RW)（待核）、CRCEN[22] (RW)（待核）、CRCSIZE[20:16] (RW)（待核）、TXDMAEN[15] (RW)（待核）、RXDMAEN[14] (RW)（待核）、UDRCFG[9] (RW)（待核）、FTHLV[8:5] (RW)（FIFO 阈值）、DSIZE[4:0] (RW)（待核） | — |
| `SPI_CFG2` | SPI/I2S 配置寄存器 2 | `0x00C` | `0x4200340C` | 32 | — | 0x00000000 / 0xFFFFFFFF | AFCNTR[31] (RW)（待核）、SSOM[30] (RW)（SS 输出管理内主设备模式）、SSOE[29] (RW)（SS 输出使能）、SSIOP[28] (RW)（SS 输入/输出极性）、SSM[26] (RW)（待核）、CPOL[25] (RW)（时钟极性）、CPHA[24] (RW)（时钟相位）、LSBFRST[23] (RW)（数据帧格式）、MASTER[22] (RW)（SPI 主设备）、SP[21:19] (RW)（串行协议）、COMM[18:17] (RW)（SPI 通信模式）、IOSWP[15] (RW)（待核）、RDIOP[14] (RW)（待核）、RDIOM[13] (RW)（待核）、MIDI[7:4] (RW)（待核）、MSSI[3:0] (RW)（待核） | — |
| `SPI_IER` | SPI/I2S 中断使能寄存器 | `0x010` | `0x42003410` | 32 | — | 0x00000000 / 0xFFFFFFFF | MODFIE[9] (RW)（待核）、TIFREIE[8] (RW)（TIFRE 中断使能）、CRCEIE[7] (RW)（CRC 错误中断使能）、OVRIE[6] (RW)（OVR 中断使能）、UDRIE[5] (RW)（UDR 中断使能）、TXTFIE[4] (RW)（TXTFIE 中断使能）、EOTIE[3] (RW)（EOT, SUSP 与 TXC 中断使能）、DXPIE[2] (RW)（DXP 中断使能）、TXPIE[1] (RW)（TXP 中断使能）、RXPIE[0] (RW)（RXP 中断使能） | — |
| `SPI_SR` | SPI/I2S 状态寄存器 | `0x014` | `0x42003414` | 32 | — | 0x00001002 / 0xFFFFFFFF | CTSIZE[31:16] (RO)（待核）、RXWNE[15] (RO)（待核）、RXPLVL[14:13] (RO)（待核）、TXC[12] (RO)（待核）、SUSP[11] (RO)（挂起状态）、MODF[9] (RO)（待核）、TIFRE[8] (RO)（TI 帧格式错误）、CRCE[7] (RO)（CRC 错误）、OVR[6] (RO)（溢出）、UDR[5] (RO)（欠载）、TXTF[4] (RO)（待核）、EOT[3] (RO)（结束的传输）、DXP[2] (RO)（待核）、TXP[1] (RO)（待核）、RXP[0] (RO)（待核） | — |
| `SPI_IFCR` | SPI/I2S 中断/状态标志清除寄存器 | `0x018` | `0x42003418` | 32 | — | 0x00000000 / 0xFFFFFFFF | SUSPC[11] (WO)（挂起清除标志）、MODFC[9] (WO)（待核）、TIFREC[8] (WO)（TI 帧格式错误清除标志）、CRCEC[7] (WO)（CRC 错误清除标志）、OVRC[6] (WO)（溢出清除标志）、UDRC[5] (WO)（欠载清除标志）、TXTFC[4] (WO)（待核）、EOTC[3] (WO)（结束的传输清除标志） | — |
| `SPI_TXDR` | SPI/I2S 发送数据寄存器 | `0x020` | `0x42003420` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXDR[31:0] (WO)（发送数据寄存器） | — |
| `SPI_RXDR` | SPI/I2S 接收数据寄存器 | `0x030` | `0x42003430` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXDR[31:0] (RO)（接收数据寄存器） | — |
| `SPI_CRCPOLY` | SPI/I2S 多项式寄存器 | `0x040` | `0x42003440` | 32 | — | 0x00000107 / 0xFFFFFFFF | CRCPOLY[31:0] (RW)（CRC 多项式寄存器） | — |
| `SPI_TXCRC` | SPI/I2S 发送器 CRC 寄存器 | `0x044` | `0x42003444` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXCRC[31:0] (RO)（CRC 寄存器的发送器） | — |
| `SPI_RXCRC` | SPI/I2S 接收器 CRC 寄存器 | `0x048` | `0x42003448` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXCRC[31:0] (RO)（CRC 寄存器的接收器） | — |
| `SPI_UDRDR` | SPI/I2S 欠载数据寄存器 | `0x04C` | `0x4200344C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UDRDR[31:0] (RW)（待核） | — |
| `SPI_I2SCFGR` | SPI/I2S 配置寄存器 | `0x050` | `0x42003450` | 32 | — | 0x00000000 / 0xFFFFFFFF | MCKOE[25] (RW)（主设备时钟输出使能）、ODD[24] (RW)（奇数系数的预分频器）、I2SDIV[23:16] (RW)（待核）、DATFMT[14] (RW)（数据格式）、WSINV[13] (RW)（待核）、FIXCH[12] (RW)（待核）、CKPOL[11] (RW)（待核）、CHLEN[10] (RW)（待核）、DATLEN[9:8] (RW)（待核）、PCMSYNC[7] (RW)（PCM 帧同步）、I2SSTD[5:4] (RW)（待核）、I2SCFG[3:1] (RW)（I2S 配置模式）、I2SMOD[0] (RW)（I2S 模式选择） | — |

## SPI5

**模块用途**　同步串行接口，按实例支持相应的收发及帧格式。主要配置时钟、数据宽度、片选和传输模式。

基地址 `0x42005000` · SVD，继承 SPI1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `SPI_CR1` | SPI/I2S 控制寄存器 1 | `0x000` | `0x42005000` | 32 | — | 0x00000000 / 0xFFFFFFFF | IOLOCK[16] (RW)（待核）、TCRCINI[15] (RW)（待核）、RCRCINI[14] (RW)（待核）、CRC33_17[13] (RW)（32-位 CRC 多项式配置）、SSI[12] (RW)（待核）、HDDIR[11] (RW)（待核）、CSUSP[10] (WO)（主设备挂起请求）、CSTART[9] (RW)（主设备传输启动）、MASRX[8] (RW)（待核）、SPE[0] (RW)（串行外设使能） | — |
| `SPI_CR2` | SPI/I2S 控制寄存器 2 | `0x004` | `0x42005004` | 32 | — | 0x00000000 / 0xFFFFFFFF | TSIZE[15:0] (RW)（待核） | — |
| `SPI_CFG1` | SPI/I2S 配置寄存器 1 | `0x008` | `0x42005008` | 32 | — | 0x00070007 / 0xFFFFFFFF | BPASS[31] (RW)（待核）、MBR[30:28] (RW)（待核）、CRCEN[22] (RW)（待核）、CRCSIZE[20:16] (RW)（待核）、TXDMAEN[15] (RW)（待核）、RXDMAEN[14] (RW)（待核）、UDRCFG[9] (RW)（待核）、FTHLV[8:5] (RW)（FIFO 阈值）、DSIZE[4:0] (RW)（待核） | — |
| `SPI_CFG2` | SPI/I2S 配置寄存器 2 | `0x00C` | `0x4200500C` | 32 | — | 0x00000000 / 0xFFFFFFFF | AFCNTR[31] (RW)（待核）、SSOM[30] (RW)（SS 输出管理内主设备模式）、SSOE[29] (RW)（SS 输出使能）、SSIOP[28] (RW)（SS 输入/输出极性）、SSM[26] (RW)（待核）、CPOL[25] (RW)（时钟极性）、CPHA[24] (RW)（时钟相位）、LSBFRST[23] (RW)（数据帧格式）、MASTER[22] (RW)（SPI 主设备）、SP[21:19] (RW)（串行协议）、COMM[18:17] (RW)（SPI 通信模式）、IOSWP[15] (RW)（待核）、RDIOP[14] (RW)（待核）、RDIOM[13] (RW)（待核）、MIDI[7:4] (RW)（待核）、MSSI[3:0] (RW)（待核） | — |
| `SPI_IER` | SPI/I2S 中断使能寄存器 | `0x010` | `0x42005010` | 32 | — | 0x00000000 / 0xFFFFFFFF | MODFIE[9] (RW)（待核）、TIFREIE[8] (RW)（TIFRE 中断使能）、CRCEIE[7] (RW)（CRC 错误中断使能）、OVRIE[6] (RW)（OVR 中断使能）、UDRIE[5] (RW)（UDR 中断使能）、TXTFIE[4] (RW)（TXTFIE 中断使能）、EOTIE[3] (RW)（EOT, SUSP 与 TXC 中断使能）、DXPIE[2] (RW)（DXP 中断使能）、TXPIE[1] (RW)（TXP 中断使能）、RXPIE[0] (RW)（RXP 中断使能） | — |
| `SPI_SR` | SPI/I2S 状态寄存器 | `0x014` | `0x42005014` | 32 | — | 0x00001002 / 0xFFFFFFFF | CTSIZE[31:16] (RO)（待核）、RXWNE[15] (RO)（待核）、RXPLVL[14:13] (RO)（待核）、TXC[12] (RO)（待核）、SUSP[11] (RO)（挂起状态）、MODF[9] (RO)（待核）、TIFRE[8] (RO)（TI 帧格式错误）、CRCE[7] (RO)（CRC 错误）、OVR[6] (RO)（溢出）、UDR[5] (RO)（欠载）、TXTF[4] (RO)（待核）、EOT[3] (RO)（结束的传输）、DXP[2] (RO)（待核）、TXP[1] (RO)（待核）、RXP[0] (RO)（待核） | — |
| `SPI_IFCR` | SPI/I2S 中断/状态标志清除寄存器 | `0x018` | `0x42005018` | 32 | — | 0x00000000 / 0xFFFFFFFF | SUSPC[11] (WO)（挂起清除标志）、MODFC[9] (WO)（待核）、TIFREC[8] (WO)（TI 帧格式错误清除标志）、CRCEC[7] (WO)（CRC 错误清除标志）、OVRC[6] (WO)（溢出清除标志）、UDRC[5] (WO)（欠载清除标志）、TXTFC[4] (WO)（待核）、EOTC[3] (WO)（结束的传输清除标志） | — |
| `SPI_TXDR` | SPI/I2S 发送数据寄存器 | `0x020` | `0x42005020` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXDR[31:0] (WO)（发送数据寄存器） | — |
| `SPI_RXDR` | SPI/I2S 接收数据寄存器 | `0x030` | `0x42005030` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXDR[31:0] (RO)（接收数据寄存器） | — |
| `SPI_CRCPOLY` | SPI/I2S 多项式寄存器 | `0x040` | `0x42005040` | 32 | — | 0x00000107 / 0xFFFFFFFF | CRCPOLY[31:0] (RW)（CRC 多项式寄存器） | — |
| `SPI_TXCRC` | SPI/I2S 发送器 CRC 寄存器 | `0x044` | `0x42005044` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXCRC[31:0] (RO)（CRC 寄存器的发送器） | — |
| `SPI_RXCRC` | SPI/I2S 接收器 CRC 寄存器 | `0x048` | `0x42005048` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXCRC[31:0] (RO)（CRC 寄存器的接收器） | — |
| `SPI_UDRDR` | SPI/I2S 欠载数据寄存器 | `0x04C` | `0x4200504C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UDRDR[31:0] (RW)（待核） | — |
| `SPI_I2SCFGR` | SPI/I2S 配置寄存器 | `0x050` | `0x42005050` | 32 | — | 0x00000000 / 0xFFFFFFFF | MCKOE[25] (RW)（主设备时钟输出使能）、ODD[24] (RW)（奇数系数的预分频器）、I2SDIV[23:16] (RW)（待核）、DATFMT[14] (RW)（数据格式）、WSINV[13] (RW)（待核）、FIXCH[12] (RW)（待核）、CKPOL[11] (RW)（待核）、CHLEN[10] (RW)（待核）、DATLEN[9:8] (RW)（待核）、PCMSYNC[7] (RW)（PCM 帧同步）、I2SSTD[5:4] (RW)（待核）、I2SCFG[3:1] (RW)（I2S 配置模式）、I2SMOD[0] (RW)（I2S 模式选择） | — |

## SPI6

**模块用途**　同步串行接口，按实例支持相应的收发及帧格式。主要配置时钟、数据宽度、片选和传输模式。

基地址 `0x58001400` · SVD，继承 SPI1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `SPI_CR1` | SPI/I2S 控制寄存器 1 | `0x000` | `0x58001400` | 32 | — | 0x00000000 / 0xFFFFFFFF | IOLOCK[16] (RW)（待核）、TCRCINI[15] (RW)（待核）、RCRCINI[14] (RW)（待核）、CRC33_17[13] (RW)（32-位 CRC 多项式配置）、SSI[12] (RW)（待核）、HDDIR[11] (RW)（待核）、CSUSP[10] (WO)（主设备挂起请求）、CSTART[9] (RW)（主设备传输启动）、MASRX[8] (RW)（待核）、SPE[0] (RW)（串行外设使能） | — |
| `SPI_CR2` | SPI/I2S 控制寄存器 2 | `0x004` | `0x58001404` | 32 | — | 0x00000000 / 0xFFFFFFFF | TSIZE[15:0] (RW)（待核） | — |
| `SPI_CFG1` | SPI/I2S 配置寄存器 1 | `0x008` | `0x58001408` | 32 | — | 0x00070007 / 0xFFFFFFFF | BPASS[31] (RW)（待核）、MBR[30:28] (RW)（待核）、CRCEN[22] (RW)（待核）、CRCSIZE[20:16] (RW)（待核）、TXDMAEN[15] (RW)（待核）、RXDMAEN[14] (RW)（待核）、UDRCFG[9] (RW)（待核）、FTHLV[8:5] (RW)（FIFO 阈值）、DSIZE[4:0] (RW)（待核） | — |
| `SPI_CFG2` | SPI/I2S 配置寄存器 2 | `0x00C` | `0x5800140C` | 32 | — | 0x00000000 / 0xFFFFFFFF | AFCNTR[31] (RW)（待核）、SSOM[30] (RW)（SS 输出管理内主设备模式）、SSOE[29] (RW)（SS 输出使能）、SSIOP[28] (RW)（SS 输入/输出极性）、SSM[26] (RW)（待核）、CPOL[25] (RW)（时钟极性）、CPHA[24] (RW)（时钟相位）、LSBFRST[23] (RW)（数据帧格式）、MASTER[22] (RW)（SPI 主设备）、SP[21:19] (RW)（串行协议）、COMM[18:17] (RW)（SPI 通信模式）、IOSWP[15] (RW)（待核）、RDIOP[14] (RW)（待核）、RDIOM[13] (RW)（待核）、MIDI[7:4] (RW)（待核）、MSSI[3:0] (RW)（待核） | — |
| `SPI_IER` | SPI/I2S 中断使能寄存器 | `0x010` | `0x58001410` | 32 | — | 0x00000000 / 0xFFFFFFFF | MODFIE[9] (RW)（待核）、TIFREIE[8] (RW)（TIFRE 中断使能）、CRCEIE[7] (RW)（CRC 错误中断使能）、OVRIE[6] (RW)（OVR 中断使能）、UDRIE[5] (RW)（UDR 中断使能）、TXTFIE[4] (RW)（TXTFIE 中断使能）、EOTIE[3] (RW)（EOT, SUSP 与 TXC 中断使能）、DXPIE[2] (RW)（DXP 中断使能）、TXPIE[1] (RW)（TXP 中断使能）、RXPIE[0] (RW)（RXP 中断使能） | — |
| `SPI_SR` | SPI/I2S 状态寄存器 | `0x014` | `0x58001414` | 32 | — | 0x00001002 / 0xFFFFFFFF | CTSIZE[31:16] (RO)（待核）、RXWNE[15] (RO)（待核）、RXPLVL[14:13] (RO)（待核）、TXC[12] (RO)（待核）、SUSP[11] (RO)（挂起状态）、MODF[9] (RO)（待核）、TIFRE[8] (RO)（TI 帧格式错误）、CRCE[7] (RO)（CRC 错误）、OVR[6] (RO)（溢出）、UDR[5] (RO)（欠载）、TXTF[4] (RO)（待核）、EOT[3] (RO)（结束的传输）、DXP[2] (RO)（待核）、TXP[1] (RO)（待核）、RXP[0] (RO)（待核） | — |
| `SPI_IFCR` | SPI/I2S 中断/状态标志清除寄存器 | `0x018` | `0x58001418` | 32 | — | 0x00000000 / 0xFFFFFFFF | SUSPC[11] (WO)（挂起清除标志）、MODFC[9] (WO)（待核）、TIFREC[8] (WO)（TI 帧格式错误清除标志）、CRCEC[7] (WO)（CRC 错误清除标志）、OVRC[6] (WO)（溢出清除标志）、UDRC[5] (WO)（欠载清除标志）、TXTFC[4] (WO)（待核）、EOTC[3] (WO)（结束的传输清除标志） | — |
| `SPI_TXDR` | SPI/I2S 发送数据寄存器 | `0x020` | `0x58001420` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXDR[31:0] (WO)（发送数据寄存器） | — |
| `SPI_RXDR` | SPI/I2S 接收数据寄存器 | `0x030` | `0x58001430` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXDR[31:0] (RO)（接收数据寄存器） | — |
| `SPI_CRCPOLY` | SPI/I2S 多项式寄存器 | `0x040` | `0x58001440` | 32 | — | 0x00000107 / 0xFFFFFFFF | CRCPOLY[31:0] (RW)（CRC 多项式寄存器） | — |
| `SPI_TXCRC` | SPI/I2S 发送器 CRC 寄存器 | `0x044` | `0x58001444` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXCRC[31:0] (RO)（CRC 寄存器的发送器） | — |
| `SPI_RXCRC` | SPI/I2S 接收器 CRC 寄存器 | `0x048` | `0x58001448` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXCRC[31:0] (RO)（CRC 寄存器的接收器） | — |
| `SPI_UDRDR` | SPI/I2S 欠载数据寄存器 | `0x04C` | `0x5800144C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UDRDR[31:0] (RW)（待核） | — |
| `SPI_I2SCFGR` | SPI/I2S 配置寄存器 | `0x050` | `0x58001450` | 32 | — | 0x00000000 / 0xFFFFFFFF | MCKOE[25] (RW)（主设备时钟输出使能）、ODD[24] (RW)（奇数系数的预分频器）、I2SDIV[23:16] (RW)（待核）、DATFMT[14] (RW)（数据格式）、WSINV[13] (RW)（待核）、FIXCH[12] (RW)（待核）、CKPOL[11] (RW)（待核）、CHLEN[10] (RW)（待核）、DATLEN[9:8] (RW)（待核）、PCMSYNC[7] (RW)（PCM 帧同步）、I2SSTD[5:4] (RW)（待核）、I2SCFG[3:1] (RW)（I2S 配置模式）、I2SMOD[0] (RW)（I2S 模式选择） | — |

## UART4

**模块用途**　异步串口，用于通过 TX/RX 发送和接收字节。重点配置波特率、数据位、校验和停止位。

基地址 `0x40004C00` · SVD，继承 USART1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `USART_CR1_ENABLED` | USART 控制寄存器 1 | `0x000` | `0x40004C00` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXFFIE[31] (RW)（RXFIFO 满中断使能）、TXFEIE[30] (RW)（TXFIFO 空中断使能）、FIFOEN[29] (RW)（FIFO 模式使能）、M1[28] (RW)（字长度）、EOBIE[27] (RW)（结束的块中断使能）、RTOIE[26] (RW)（接收器超时中断使能）、DEAT[25:21] (RW)（待核）、DEDT[20:16] (RW)（待核）、OVER8[15] (RW)（选择 8 倍或 16 倍过采样）、CMIE[14] (RW)（待核）、MME[13] (RW)（待核）、M0[12] (RW)（字长度）、WAKE[11] (RW)（待核）、PCE[10] (RW)（奇偶校验使能）、PS[9] (RW)（选择奇校验或偶校验）、PEIE[8] (RW)（PE 中断使能）、TXFNFIE[7] (RW)（待核）、TCIE[6] (RW)（发送完成中断使能）、RXFNEIE[5] (RW)（待核）、IDLEIE[4] (RW)（空闲中断使能）、TE[3] (RW)（发送器使能）、RE[2] (RW)（接收器使能）、UESM[1] (RW)（USART 使能内低位-电源模式）、UE[0] (RW)（串口总使能） | — |
| `USART_CR1_DISABLED` | USART 控制寄存器 1 | `0x000` | `0x40004C00` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFOEN[29] (RW)（FIFO 模式使能）、M1[28] (RW)（字长度）、EOBIE[27] (RW)（结束的块中断使能）、RTOIE[26] (RW)（接收器超时中断使能）、DEAT[25:21] (RW)（待核）、DEDT[20:16] (RW)（待核）、OVER8[15] (RW)（选择 8 倍或 16 倍过采样）、CMIE[14] (RW)（待核）、MME[13] (RW)（待核）、M0[12] (RW)（字长度）、WAKE[11] (RW)（待核）、PCE[10] (RW)（奇偶校验使能）、PS[9] (RW)（选择奇校验或偶校验）、PEIE[8] (RW)（PE 中断使能）、TXEIE[7] (RW)（发送数据寄存器空）、TCIE[6] (RW)（发送完成中断使能）、RXNEIE[5] (RW)（待核）、IDLEIE[4] (RW)（空闲中断使能）、TE[3] (RW)（发送器使能）、RE[2] (RW)（接收器使能）、UESM[1] (RW)（USART 使能内低位-电源模式）、UE[0] (RW)（串口总使能） | 别名 USART_CR1_ENABLED |
| `USART_CR2` | USART 控制寄存器 2 | `0x004` | `0x40004C04` | 32 | — | 0x00000000 / 0xFFFFFFFF | ADD[31:24] (RW)（待核）、RTOEN[23] (RW)（接收器超时使能）、ABRMOD[22:21] (RW)（待核）、ABREN[20] (RW)（待核）、MSBFIRST[19] (RW)（最高有效位首个）、DATAINV[18] (RW)（待核）、TXINV[17] (RW)（待核）、RXINV[16] (RW)（待核）、SWAP[15] (RW)（交换发送/接收引脚）、LINEN[14] (RW)（LIN 模式使能）、STOP[13:12] (RW)（停止位长度选择）、CLKEN[11] (RW)（时钟使能）、CPOL[10] (RW)（时钟极性）、CPHA[9] (RW)（时钟相位）、LBCL[8] (RW)（末尾位时钟脉冲）、LBDIE[6] (RW)（LIN 刹车检测中断使能）、LBDL[5] (RW)（LIN 刹车检测长度）、ADDM7[4] (RW)（7-位地址检测/4-位地址检测）、DIS_NSS[3] (RW)（待核）、SLVEN[0] (RW)（同步从设备模式使能） | — |
| `USART_CR3` | USART 控制寄存器 3 | `0x008` | `0x40004C08` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXFTCFG[31:29] (RW)（TXFIFO 阈值配置）、RXFTIE[28] (RW)（RXFIFO 阈值中断使能）、RXFTCFG[27:25] (RW)（接收 FIFO 阈值配置）、TCBGTIE[24] (RW)（待核）、TXFTIE[23] (RW)（TXFIFO 阈值中断使能）、WUFIE[22] (RW)（唤醒来自低位-电源模式中断使能）、WUS1[21] (RW)（唤醒来自低位-电源模式中断标志选择）、WUS0[20] (RW)（唤醒来自低位-电源模式中断标志选择）、SCARCNT[19:17] (RW)（待核）、DEP[15] (RW)（待核）、DEM[14] (RW)（待核）、DDRE[13] (RW)（DMA 禁用的接收错误）、OVRDIS[12] (RW)（溢出禁用）、ONEBIT[11] (RW)（待核）、CTSIE[10] (RW)（CTS 中断使能）、CTSE[9] (RW)（CTS 使能）、RTSE[8] (RW)（RTS 使能）、DMAT[7] (RW)（DMA 使能发送器）、DMAR[6] (RW)（DMA 使能接收器）、SCEN[5] (RW)（待核）、NACK[4] (RW)（待核）、HDSEL[3] (RW)（待核）、IRLP[2] (RW)（待核）、IREN[1] (RW)（待核）、EIE[0] (RW)（错误中断使能） | — |
| `USART_BRR` | 波特率配置寄存器 | `0x00C` | `0x40004C0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRR[15:0] (RW)（波特率分频参数） | — |
| `USART_GTPR` | USART 保护时间和预分频寄存器 | `0x010` | `0x40004C10` | 32 | — | 0x00000000 / 0xFFFFFFFF | GT[15:8] (RW)（保护时间值）、PSC[7:0] (RW)（预分频器值） | — |
| `USART_RTOR` | USART 接收器超时寄存器 | `0x014` | `0x40004C14` | 32 | — | 0x00000000 / 0xFFFFFFFF | BLEN[31:24] (RW)（块长度）、RTO[23:0] (RW)（接收器超时值） | — |
| `USART_RQR` | USART 请求寄存器 | `0x018` | `0x40004C18` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXFRQ[4] (WO)（发送数据清空请求）、RXFRQ[3] (WO)（接收数据清空请求）、MMRQ[2] (WO)（待核）、SBKRQ[1] (WO)（待核）、ABRRQ[0] (WO)（待核） | — |
| `USART_ISR_ENABLED` | USART 中断与状态寄存器 | `0x01C` | `0x40004C1C` | 32 | — | 0x000000C0 / 0xF00FFFFF | TXFT[27] (RO)（TXFIFO 阈值标志）、RXFT[26] (RO)（RXFIFO 阈值标志）、TCBGT[25] (RO)（待核）、RXFF[24] (RO)（RXFIFO 满）、TXFE[23] (RO)（TXFIFO 空）、REACK[22] (RO)（接收使能应答标志）、TEACK[21] (RO)（发送使能应答标志）、WUF[20] (RO)（唤醒来自低位-电源模式标志）、RWU[19] (RO)（待核）、SBKF[18] (RO)（待核）、CMF[17] (RO)（待核）、BUSY[16] (RO)（忙标志）、ABRF[15] (RO)（待核）、ABRE[14] (RO)（待核）、UDR[13] (RO)（SPI 从设备欠载错误标志）、EOBF[12] (RO)（结束的块标志）、RTOF[11] (RO)（接收器超时）、CTS[10] (RO)（CTS 标志）、CTSIF[9] (RO)（CTS 中断标志）、LBDF[8] (RO)（LIN 刹车检测标志）、TXFNF[7] (RO)（发送 FIFO 未满）、TC[6] (RO)（发送完成）、RXFNE[5] (RO)（接收 FIFO 非空）、IDLE[4] (RO)（空闲行检测到）、ORE[3] (RO)（溢出错误）、NE[2] (RO)（噪声检测标志）、FE[1] (RO)（帧错误）、PE[0] (RO)（校验错误） | — |
| `USART_ISR_DISABLED` | USART 中断与状态寄存器 | `0x01C` | `0x40004C1C` | 32 | — | 0x000000C0 / 0xF00FFFFF | TCBGT[25] (RO)（待核）、REACK[22] (RO)（接收使能应答标志）、TEACK[21] (RO)（发送使能应答标志）、WUF[20] (RO)（唤醒来自低位-电源模式标志）、RWU[19] (RO)（待核）、SBKF[18] (RO)（待核）、CMF[17] (RO)（待核）、BUSY[16] (RO)（忙标志）、ABRF[15] (RO)（待核）、ABRE[14] (RO)（待核）、UDR[13] (RO)（SPI 从设备欠载错误标志）、EOBF[12] (RO)（结束的块标志）、RTOF[11] (RO)（接收器超时）、CTS[10] (RO)（CTS 标志）、CTSIF[9] (RO)（CTS 中断标志）、LBDF[8] (RO)（LIN 刹车检测标志）、TXE[7] (RO)（发送数据寄存器空）、TC[6] (RO)（发送完成）、RXNE[5] (RO)（接收数据寄存器非空）、IDLE[4] (RO)（空闲行检测到）、ORE[3] (RO)（溢出错误）、NE[2] (RO)（噪声检测标志）、FE[1] (RO)（帧错误）、PE[0] (RO)（校验错误） | 别名 USART_ISR_ENABLED |
| `USART_ICR` | USART 中断标志清除寄存器 | `0x020` | `0x40004C20` | 32 | — | 0x00000000 / 0xFFFFFFFF | WUCF[20] (WO)（唤醒来自低位-电源模式清除标志）、CMCF[17] (WO)（待核）、UDRCF[13] (WO)（SPI 从设备欠载清除标志）、EOBCF[12] (WO)（结束的块清除标志）、RTOCF[11] (WO)（接收器超时清除标志）、CTSCF[9] (WO)（CTS 清除标志）、LBDCF[8] (WO)（LIN 刹车检测清除标志）、TCBGTCF[7] (WO)（待核）、TCCF[6] (WO)（发送完成清除标志）、TXFECF[5] (WO)（TXFIFO 空清除标志）、IDLECF[4] (WO)（空闲行检测到清除标志）、ORECF[3] (WO)（溢出错误清除标志）、NECF[2] (WO)（噪声检测到清除标志）、FECF[1] (WO)（帧错误清除标志）、PECF[0] (WO)（校验错误清除标志） | — |
| `USART_RDR` | 接收数据寄存器 | `0x024` | `0x40004C24` | 32 | — | 0x00000000 / 0xFFFFFFFF | RDR[8:0] (RO)（接收数据值） | — |
| `USART_TDR` | 发送数据寄存器 | `0x028` | `0x40004C28` | 32 | — | 0x00000000 / 0xFFFFFFFF | TDR[8:0] (RW)（发送数据值） | — |
| `USART_PRESC` | USART 预分频器寄存器 | `0x02C` | `0x40004C2C` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRESCALER[3:0] (RW)（时钟预分频器） | — |

## UART5

**模块用途**　异步串口，用于通过 TX/RX 发送和接收字节。重点配置波特率、数据位、校验和停止位。

基地址 `0x40005000` · SVD，继承 USART1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `USART_CR1_ENABLED` | USART 控制寄存器 1 | `0x000` | `0x40005000` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXFFIE[31] (RW)（RXFIFO 满中断使能）、TXFEIE[30] (RW)（TXFIFO 空中断使能）、FIFOEN[29] (RW)（FIFO 模式使能）、M1[28] (RW)（字长度）、EOBIE[27] (RW)（结束的块中断使能）、RTOIE[26] (RW)（接收器超时中断使能）、DEAT[25:21] (RW)（待核）、DEDT[20:16] (RW)（待核）、OVER8[15] (RW)（选择 8 倍或 16 倍过采样）、CMIE[14] (RW)（待核）、MME[13] (RW)（待核）、M0[12] (RW)（字长度）、WAKE[11] (RW)（待核）、PCE[10] (RW)（奇偶校验使能）、PS[9] (RW)（选择奇校验或偶校验）、PEIE[8] (RW)（PE 中断使能）、TXFNFIE[7] (RW)（待核）、TCIE[6] (RW)（发送完成中断使能）、RXFNEIE[5] (RW)（待核）、IDLEIE[4] (RW)（空闲中断使能）、TE[3] (RW)（发送器使能）、RE[2] (RW)（接收器使能）、UESM[1] (RW)（USART 使能内低位-电源模式）、UE[0] (RW)（串口总使能） | — |
| `USART_CR1_DISABLED` | USART 控制寄存器 1 | `0x000` | `0x40005000` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFOEN[29] (RW)（FIFO 模式使能）、M1[28] (RW)（字长度）、EOBIE[27] (RW)（结束的块中断使能）、RTOIE[26] (RW)（接收器超时中断使能）、DEAT[25:21] (RW)（待核）、DEDT[20:16] (RW)（待核）、OVER8[15] (RW)（选择 8 倍或 16 倍过采样）、CMIE[14] (RW)（待核）、MME[13] (RW)（待核）、M0[12] (RW)（字长度）、WAKE[11] (RW)（待核）、PCE[10] (RW)（奇偶校验使能）、PS[9] (RW)（选择奇校验或偶校验）、PEIE[8] (RW)（PE 中断使能）、TXEIE[7] (RW)（发送数据寄存器空）、TCIE[6] (RW)（发送完成中断使能）、RXNEIE[5] (RW)（待核）、IDLEIE[4] (RW)（空闲中断使能）、TE[3] (RW)（发送器使能）、RE[2] (RW)（接收器使能）、UESM[1] (RW)（USART 使能内低位-电源模式）、UE[0] (RW)（串口总使能） | 别名 USART_CR1_ENABLED |
| `USART_CR2` | USART 控制寄存器 2 | `0x004` | `0x40005004` | 32 | — | 0x00000000 / 0xFFFFFFFF | ADD[31:24] (RW)（待核）、RTOEN[23] (RW)（接收器超时使能）、ABRMOD[22:21] (RW)（待核）、ABREN[20] (RW)（待核）、MSBFIRST[19] (RW)（最高有效位首个）、DATAINV[18] (RW)（待核）、TXINV[17] (RW)（待核）、RXINV[16] (RW)（待核）、SWAP[15] (RW)（交换发送/接收引脚）、LINEN[14] (RW)（LIN 模式使能）、STOP[13:12] (RW)（停止位长度选择）、CLKEN[11] (RW)（时钟使能）、CPOL[10] (RW)（时钟极性）、CPHA[9] (RW)（时钟相位）、LBCL[8] (RW)（末尾位时钟脉冲）、LBDIE[6] (RW)（LIN 刹车检测中断使能）、LBDL[5] (RW)（LIN 刹车检测长度）、ADDM7[4] (RW)（7-位地址检测/4-位地址检测）、DIS_NSS[3] (RW)（待核）、SLVEN[0] (RW)（同步从设备模式使能） | — |
| `USART_CR3` | USART 控制寄存器 3 | `0x008` | `0x40005008` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXFTCFG[31:29] (RW)（TXFIFO 阈值配置）、RXFTIE[28] (RW)（RXFIFO 阈值中断使能）、RXFTCFG[27:25] (RW)（接收 FIFO 阈值配置）、TCBGTIE[24] (RW)（待核）、TXFTIE[23] (RW)（TXFIFO 阈值中断使能）、WUFIE[22] (RW)（唤醒来自低位-电源模式中断使能）、WUS1[21] (RW)（唤醒来自低位-电源模式中断标志选择）、WUS0[20] (RW)（唤醒来自低位-电源模式中断标志选择）、SCARCNT[19:17] (RW)（待核）、DEP[15] (RW)（待核）、DEM[14] (RW)（待核）、DDRE[13] (RW)（DMA 禁用的接收错误）、OVRDIS[12] (RW)（溢出禁用）、ONEBIT[11] (RW)（待核）、CTSIE[10] (RW)（CTS 中断使能）、CTSE[9] (RW)（CTS 使能）、RTSE[8] (RW)（RTS 使能）、DMAT[7] (RW)（DMA 使能发送器）、DMAR[6] (RW)（DMA 使能接收器）、SCEN[5] (RW)（待核）、NACK[4] (RW)（待核）、HDSEL[3] (RW)（待核）、IRLP[2] (RW)（待核）、IREN[1] (RW)（待核）、EIE[0] (RW)（错误中断使能） | — |
| `USART_BRR` | 波特率配置寄存器 | `0x00C` | `0x4000500C` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRR[15:0] (RW)（波特率分频参数） | — |
| `USART_GTPR` | USART 保护时间和预分频寄存器 | `0x010` | `0x40005010` | 32 | — | 0x00000000 / 0xFFFFFFFF | GT[15:8] (RW)（保护时间值）、PSC[7:0] (RW)（预分频器值） | — |
| `USART_RTOR` | USART 接收器超时寄存器 | `0x014` | `0x40005014` | 32 | — | 0x00000000 / 0xFFFFFFFF | BLEN[31:24] (RW)（块长度）、RTO[23:0] (RW)（接收器超时值） | — |
| `USART_RQR` | USART 请求寄存器 | `0x018` | `0x40005018` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXFRQ[4] (WO)（发送数据清空请求）、RXFRQ[3] (WO)（接收数据清空请求）、MMRQ[2] (WO)（待核）、SBKRQ[1] (WO)（待核）、ABRRQ[0] (WO)（待核） | — |
| `USART_ISR_ENABLED` | USART 中断与状态寄存器 | `0x01C` | `0x4000501C` | 32 | — | 0x000000C0 / 0xF00FFFFF | TXFT[27] (RO)（TXFIFO 阈值标志）、RXFT[26] (RO)（RXFIFO 阈值标志）、TCBGT[25] (RO)（待核）、RXFF[24] (RO)（RXFIFO 满）、TXFE[23] (RO)（TXFIFO 空）、REACK[22] (RO)（接收使能应答标志）、TEACK[21] (RO)（发送使能应答标志）、WUF[20] (RO)（唤醒来自低位-电源模式标志）、RWU[19] (RO)（待核）、SBKF[18] (RO)（待核）、CMF[17] (RO)（待核）、BUSY[16] (RO)（忙标志）、ABRF[15] (RO)（待核）、ABRE[14] (RO)（待核）、UDR[13] (RO)（SPI 从设备欠载错误标志）、EOBF[12] (RO)（结束的块标志）、RTOF[11] (RO)（接收器超时）、CTS[10] (RO)（CTS 标志）、CTSIF[9] (RO)（CTS 中断标志）、LBDF[8] (RO)（LIN 刹车检测标志）、TXFNF[7] (RO)（发送 FIFO 未满）、TC[6] (RO)（发送完成）、RXFNE[5] (RO)（接收 FIFO 非空）、IDLE[4] (RO)（空闲行检测到）、ORE[3] (RO)（溢出错误）、NE[2] (RO)（噪声检测标志）、FE[1] (RO)（帧错误）、PE[0] (RO)（校验错误） | — |
| `USART_ISR_DISABLED` | USART 中断与状态寄存器 | `0x01C` | `0x4000501C` | 32 | — | 0x000000C0 / 0xF00FFFFF | TCBGT[25] (RO)（待核）、REACK[22] (RO)（接收使能应答标志）、TEACK[21] (RO)（发送使能应答标志）、WUF[20] (RO)（唤醒来自低位-电源模式标志）、RWU[19] (RO)（待核）、SBKF[18] (RO)（待核）、CMF[17] (RO)（待核）、BUSY[16] (RO)（忙标志）、ABRF[15] (RO)（待核）、ABRE[14] (RO)（待核）、UDR[13] (RO)（SPI 从设备欠载错误标志）、EOBF[12] (RO)（结束的块标志）、RTOF[11] (RO)（接收器超时）、CTS[10] (RO)（CTS 标志）、CTSIF[9] (RO)（CTS 中断标志）、LBDF[8] (RO)（LIN 刹车检测标志）、TXE[7] (RO)（发送数据寄存器空）、TC[6] (RO)（发送完成）、RXNE[5] (RO)（接收数据寄存器非空）、IDLE[4] (RO)（空闲行检测到）、ORE[3] (RO)（溢出错误）、NE[2] (RO)（噪声检测标志）、FE[1] (RO)（帧错误）、PE[0] (RO)（校验错误） | 别名 USART_ISR_ENABLED |
| `USART_ICR` | USART 中断标志清除寄存器 | `0x020` | `0x40005020` | 32 | — | 0x00000000 / 0xFFFFFFFF | WUCF[20] (WO)（唤醒来自低位-电源模式清除标志）、CMCF[17] (WO)（待核）、UDRCF[13] (WO)（SPI 从设备欠载清除标志）、EOBCF[12] (WO)（结束的块清除标志）、RTOCF[11] (WO)（接收器超时清除标志）、CTSCF[9] (WO)（CTS 清除标志）、LBDCF[8] (WO)（LIN 刹车检测清除标志）、TCBGTCF[7] (WO)（待核）、TCCF[6] (WO)（发送完成清除标志）、TXFECF[5] (WO)（TXFIFO 空清除标志）、IDLECF[4] (WO)（空闲行检测到清除标志）、ORECF[3] (WO)（溢出错误清除标志）、NECF[2] (WO)（噪声检测到清除标志）、FECF[1] (WO)（帧错误清除标志）、PECF[0] (WO)（校验错误清除标志） | — |
| `USART_RDR` | 接收数据寄存器 | `0x024` | `0x40005024` | 32 | — | 0x00000000 / 0xFFFFFFFF | RDR[8:0] (RO)（接收数据值） | — |
| `USART_TDR` | 发送数据寄存器 | `0x028` | `0x40005028` | 32 | — | 0x00000000 / 0xFFFFFFFF | TDR[8:0] (RW)（发送数据值） | — |
| `USART_PRESC` | USART 预分频器寄存器 | `0x02C` | `0x4000502C` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRESCALER[3:0] (RW)（时钟预分频器） | — |

## UART7

**模块用途**　异步串口，用于通过 TX/RX 发送和接收字节。重点配置波特率、数据位、校验和停止位。

基地址 `0x40007800` · SVD，继承 USART1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `USART_CR1_ENABLED` | USART 控制寄存器 1 | `0x000` | `0x40007800` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXFFIE[31] (RW)（RXFIFO 满中断使能）、TXFEIE[30] (RW)（TXFIFO 空中断使能）、FIFOEN[29] (RW)（FIFO 模式使能）、M1[28] (RW)（字长度）、EOBIE[27] (RW)（结束的块中断使能）、RTOIE[26] (RW)（接收器超时中断使能）、DEAT[25:21] (RW)（待核）、DEDT[20:16] (RW)（待核）、OVER8[15] (RW)（选择 8 倍或 16 倍过采样）、CMIE[14] (RW)（待核）、MME[13] (RW)（待核）、M0[12] (RW)（字长度）、WAKE[11] (RW)（待核）、PCE[10] (RW)（奇偶校验使能）、PS[9] (RW)（选择奇校验或偶校验）、PEIE[8] (RW)（PE 中断使能）、TXFNFIE[7] (RW)（待核）、TCIE[6] (RW)（发送完成中断使能）、RXFNEIE[5] (RW)（待核）、IDLEIE[4] (RW)（空闲中断使能）、TE[3] (RW)（发送器使能）、RE[2] (RW)（接收器使能）、UESM[1] (RW)（USART 使能内低位-电源模式）、UE[0] (RW)（串口总使能） | — |
| `USART_CR1_DISABLED` | USART 控制寄存器 1 | `0x000` | `0x40007800` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFOEN[29] (RW)（FIFO 模式使能）、M1[28] (RW)（字长度）、EOBIE[27] (RW)（结束的块中断使能）、RTOIE[26] (RW)（接收器超时中断使能）、DEAT[25:21] (RW)（待核）、DEDT[20:16] (RW)（待核）、OVER8[15] (RW)（选择 8 倍或 16 倍过采样）、CMIE[14] (RW)（待核）、MME[13] (RW)（待核）、M0[12] (RW)（字长度）、WAKE[11] (RW)（待核）、PCE[10] (RW)（奇偶校验使能）、PS[9] (RW)（选择奇校验或偶校验）、PEIE[8] (RW)（PE 中断使能）、TXEIE[7] (RW)（发送数据寄存器空）、TCIE[6] (RW)（发送完成中断使能）、RXNEIE[5] (RW)（待核）、IDLEIE[4] (RW)（空闲中断使能）、TE[3] (RW)（发送器使能）、RE[2] (RW)（接收器使能）、UESM[1] (RW)（USART 使能内低位-电源模式）、UE[0] (RW)（串口总使能） | 别名 USART_CR1_ENABLED |
| `USART_CR2` | USART 控制寄存器 2 | `0x004` | `0x40007804` | 32 | — | 0x00000000 / 0xFFFFFFFF | ADD[31:24] (RW)（待核）、RTOEN[23] (RW)（接收器超时使能）、ABRMOD[22:21] (RW)（待核）、ABREN[20] (RW)（待核）、MSBFIRST[19] (RW)（最高有效位首个）、DATAINV[18] (RW)（待核）、TXINV[17] (RW)（待核）、RXINV[16] (RW)（待核）、SWAP[15] (RW)（交换发送/接收引脚）、LINEN[14] (RW)（LIN 模式使能）、STOP[13:12] (RW)（停止位长度选择）、CLKEN[11] (RW)（时钟使能）、CPOL[10] (RW)（时钟极性）、CPHA[9] (RW)（时钟相位）、LBCL[8] (RW)（末尾位时钟脉冲）、LBDIE[6] (RW)（LIN 刹车检测中断使能）、LBDL[5] (RW)（LIN 刹车检测长度）、ADDM7[4] (RW)（7-位地址检测/4-位地址检测）、DIS_NSS[3] (RW)（待核）、SLVEN[0] (RW)（同步从设备模式使能） | — |
| `USART_CR3` | USART 控制寄存器 3 | `0x008` | `0x40007808` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXFTCFG[31:29] (RW)（TXFIFO 阈值配置）、RXFTIE[28] (RW)（RXFIFO 阈值中断使能）、RXFTCFG[27:25] (RW)（接收 FIFO 阈值配置）、TCBGTIE[24] (RW)（待核）、TXFTIE[23] (RW)（TXFIFO 阈值中断使能）、WUFIE[22] (RW)（唤醒来自低位-电源模式中断使能）、WUS1[21] (RW)（唤醒来自低位-电源模式中断标志选择）、WUS0[20] (RW)（唤醒来自低位-电源模式中断标志选择）、SCARCNT[19:17] (RW)（待核）、DEP[15] (RW)（待核）、DEM[14] (RW)（待核）、DDRE[13] (RW)（DMA 禁用的接收错误）、OVRDIS[12] (RW)（溢出禁用）、ONEBIT[11] (RW)（待核）、CTSIE[10] (RW)（CTS 中断使能）、CTSE[9] (RW)（CTS 使能）、RTSE[8] (RW)（RTS 使能）、DMAT[7] (RW)（DMA 使能发送器）、DMAR[6] (RW)（DMA 使能接收器）、SCEN[5] (RW)（待核）、NACK[4] (RW)（待核）、HDSEL[3] (RW)（待核）、IRLP[2] (RW)（待核）、IREN[1] (RW)（待核）、EIE[0] (RW)（错误中断使能） | — |
| `USART_BRR` | 波特率配置寄存器 | `0x00C` | `0x4000780C` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRR[15:0] (RW)（波特率分频参数） | — |
| `USART_GTPR` | USART 保护时间和预分频寄存器 | `0x010` | `0x40007810` | 32 | — | 0x00000000 / 0xFFFFFFFF | GT[15:8] (RW)（保护时间值）、PSC[7:0] (RW)（预分频器值） | — |
| `USART_RTOR` | USART 接收器超时寄存器 | `0x014` | `0x40007814` | 32 | — | 0x00000000 / 0xFFFFFFFF | BLEN[31:24] (RW)（块长度）、RTO[23:0] (RW)（接收器超时值） | — |
| `USART_RQR` | USART 请求寄存器 | `0x018` | `0x40007818` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXFRQ[4] (WO)（发送数据清空请求）、RXFRQ[3] (WO)（接收数据清空请求）、MMRQ[2] (WO)（待核）、SBKRQ[1] (WO)（待核）、ABRRQ[0] (WO)（待核） | — |
| `USART_ISR_ENABLED` | USART 中断与状态寄存器 | `0x01C` | `0x4000781C` | 32 | — | 0x000000C0 / 0xF00FFFFF | TXFT[27] (RO)（TXFIFO 阈值标志）、RXFT[26] (RO)（RXFIFO 阈值标志）、TCBGT[25] (RO)（待核）、RXFF[24] (RO)（RXFIFO 满）、TXFE[23] (RO)（TXFIFO 空）、REACK[22] (RO)（接收使能应答标志）、TEACK[21] (RO)（发送使能应答标志）、WUF[20] (RO)（唤醒来自低位-电源模式标志）、RWU[19] (RO)（待核）、SBKF[18] (RO)（待核）、CMF[17] (RO)（待核）、BUSY[16] (RO)（忙标志）、ABRF[15] (RO)（待核）、ABRE[14] (RO)（待核）、UDR[13] (RO)（SPI 从设备欠载错误标志）、EOBF[12] (RO)（结束的块标志）、RTOF[11] (RO)（接收器超时）、CTS[10] (RO)（CTS 标志）、CTSIF[9] (RO)（CTS 中断标志）、LBDF[8] (RO)（LIN 刹车检测标志）、TXFNF[7] (RO)（发送 FIFO 未满）、TC[6] (RO)（发送完成）、RXFNE[5] (RO)（接收 FIFO 非空）、IDLE[4] (RO)（空闲行检测到）、ORE[3] (RO)（溢出错误）、NE[2] (RO)（噪声检测标志）、FE[1] (RO)（帧错误）、PE[0] (RO)（校验错误） | — |
| `USART_ISR_DISABLED` | USART 中断与状态寄存器 | `0x01C` | `0x4000781C` | 32 | — | 0x000000C0 / 0xF00FFFFF | TCBGT[25] (RO)（待核）、REACK[22] (RO)（接收使能应答标志）、TEACK[21] (RO)（发送使能应答标志）、WUF[20] (RO)（唤醒来自低位-电源模式标志）、RWU[19] (RO)（待核）、SBKF[18] (RO)（待核）、CMF[17] (RO)（待核）、BUSY[16] (RO)（忙标志）、ABRF[15] (RO)（待核）、ABRE[14] (RO)（待核）、UDR[13] (RO)（SPI 从设备欠载错误标志）、EOBF[12] (RO)（结束的块标志）、RTOF[11] (RO)（接收器超时）、CTS[10] (RO)（CTS 标志）、CTSIF[9] (RO)（CTS 中断标志）、LBDF[8] (RO)（LIN 刹车检测标志）、TXE[7] (RO)（发送数据寄存器空）、TC[6] (RO)（发送完成）、RXNE[5] (RO)（接收数据寄存器非空）、IDLE[4] (RO)（空闲行检测到）、ORE[3] (RO)（溢出错误）、NE[2] (RO)（噪声检测标志）、FE[1] (RO)（帧错误）、PE[0] (RO)（校验错误） | 别名 USART_ISR_ENABLED |
| `USART_ICR` | USART 中断标志清除寄存器 | `0x020` | `0x40007820` | 32 | — | 0x00000000 / 0xFFFFFFFF | WUCF[20] (WO)（唤醒来自低位-电源模式清除标志）、CMCF[17] (WO)（待核）、UDRCF[13] (WO)（SPI 从设备欠载清除标志）、EOBCF[12] (WO)（结束的块清除标志）、RTOCF[11] (WO)（接收器超时清除标志）、CTSCF[9] (WO)（CTS 清除标志）、LBDCF[8] (WO)（LIN 刹车检测清除标志）、TCBGTCF[7] (WO)（待核）、TCCF[6] (WO)（发送完成清除标志）、TXFECF[5] (WO)（TXFIFO 空清除标志）、IDLECF[4] (WO)（空闲行检测到清除标志）、ORECF[3] (WO)（溢出错误清除标志）、NECF[2] (WO)（噪声检测到清除标志）、FECF[1] (WO)（帧错误清除标志）、PECF[0] (WO)（校验错误清除标志） | — |
| `USART_RDR` | 接收数据寄存器 | `0x024` | `0x40007824` | 32 | — | 0x00000000 / 0xFFFFFFFF | RDR[8:0] (RO)（接收数据值） | — |
| `USART_TDR` | 发送数据寄存器 | `0x028` | `0x40007828` | 32 | — | 0x00000000 / 0xFFFFFFFF | TDR[8:0] (RW)（发送数据值） | — |
| `USART_PRESC` | USART 预分频器寄存器 | `0x02C` | `0x4000782C` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRESCALER[3:0] (RW)（时钟预分频器） | — |

## UART8

**模块用途**　异步串口，用于通过 TX/RX 发送和接收字节。重点配置波特率、数据位、校验和停止位。

基地址 `0x40007C00` · SVD，继承 USART1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `USART_CR1_ENABLED` | USART 控制寄存器 1 | `0x000` | `0x40007C00` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXFFIE[31] (RW)（RXFIFO 满中断使能）、TXFEIE[30] (RW)（TXFIFO 空中断使能）、FIFOEN[29] (RW)（FIFO 模式使能）、M1[28] (RW)（字长度）、EOBIE[27] (RW)（结束的块中断使能）、RTOIE[26] (RW)（接收器超时中断使能）、DEAT[25:21] (RW)（待核）、DEDT[20:16] (RW)（待核）、OVER8[15] (RW)（选择 8 倍或 16 倍过采样）、CMIE[14] (RW)（待核）、MME[13] (RW)（待核）、M0[12] (RW)（字长度）、WAKE[11] (RW)（待核）、PCE[10] (RW)（奇偶校验使能）、PS[9] (RW)（选择奇校验或偶校验）、PEIE[8] (RW)（PE 中断使能）、TXFNFIE[7] (RW)（待核）、TCIE[6] (RW)（发送完成中断使能）、RXFNEIE[5] (RW)（待核）、IDLEIE[4] (RW)（空闲中断使能）、TE[3] (RW)（发送器使能）、RE[2] (RW)（接收器使能）、UESM[1] (RW)（USART 使能内低位-电源模式）、UE[0] (RW)（串口总使能） | — |
| `USART_CR1_DISABLED` | USART 控制寄存器 1 | `0x000` | `0x40007C00` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFOEN[29] (RW)（FIFO 模式使能）、M1[28] (RW)（字长度）、EOBIE[27] (RW)（结束的块中断使能）、RTOIE[26] (RW)（接收器超时中断使能）、DEAT[25:21] (RW)（待核）、DEDT[20:16] (RW)（待核）、OVER8[15] (RW)（选择 8 倍或 16 倍过采样）、CMIE[14] (RW)（待核）、MME[13] (RW)（待核）、M0[12] (RW)（字长度）、WAKE[11] (RW)（待核）、PCE[10] (RW)（奇偶校验使能）、PS[9] (RW)（选择奇校验或偶校验）、PEIE[8] (RW)（PE 中断使能）、TXEIE[7] (RW)（发送数据寄存器空）、TCIE[6] (RW)（发送完成中断使能）、RXNEIE[5] (RW)（待核）、IDLEIE[4] (RW)（空闲中断使能）、TE[3] (RW)（发送器使能）、RE[2] (RW)（接收器使能）、UESM[1] (RW)（USART 使能内低位-电源模式）、UE[0] (RW)（串口总使能） | 别名 USART_CR1_ENABLED |
| `USART_CR2` | USART 控制寄存器 2 | `0x004` | `0x40007C04` | 32 | — | 0x00000000 / 0xFFFFFFFF | ADD[31:24] (RW)（待核）、RTOEN[23] (RW)（接收器超时使能）、ABRMOD[22:21] (RW)（待核）、ABREN[20] (RW)（待核）、MSBFIRST[19] (RW)（最高有效位首个）、DATAINV[18] (RW)（待核）、TXINV[17] (RW)（待核）、RXINV[16] (RW)（待核）、SWAP[15] (RW)（交换发送/接收引脚）、LINEN[14] (RW)（LIN 模式使能）、STOP[13:12] (RW)（停止位长度选择）、CLKEN[11] (RW)（时钟使能）、CPOL[10] (RW)（时钟极性）、CPHA[9] (RW)（时钟相位）、LBCL[8] (RW)（末尾位时钟脉冲）、LBDIE[6] (RW)（LIN 刹车检测中断使能）、LBDL[5] (RW)（LIN 刹车检测长度）、ADDM7[4] (RW)（7-位地址检测/4-位地址检测）、DIS_NSS[3] (RW)（待核）、SLVEN[0] (RW)（同步从设备模式使能） | — |
| `USART_CR3` | USART 控制寄存器 3 | `0x008` | `0x40007C08` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXFTCFG[31:29] (RW)（TXFIFO 阈值配置）、RXFTIE[28] (RW)（RXFIFO 阈值中断使能）、RXFTCFG[27:25] (RW)（接收 FIFO 阈值配置）、TCBGTIE[24] (RW)（待核）、TXFTIE[23] (RW)（TXFIFO 阈值中断使能）、WUFIE[22] (RW)（唤醒来自低位-电源模式中断使能）、WUS1[21] (RW)（唤醒来自低位-电源模式中断标志选择）、WUS0[20] (RW)（唤醒来自低位-电源模式中断标志选择）、SCARCNT[19:17] (RW)（待核）、DEP[15] (RW)（待核）、DEM[14] (RW)（待核）、DDRE[13] (RW)（DMA 禁用的接收错误）、OVRDIS[12] (RW)（溢出禁用）、ONEBIT[11] (RW)（待核）、CTSIE[10] (RW)（CTS 中断使能）、CTSE[9] (RW)（CTS 使能）、RTSE[8] (RW)（RTS 使能）、DMAT[7] (RW)（DMA 使能发送器）、DMAR[6] (RW)（DMA 使能接收器）、SCEN[5] (RW)（待核）、NACK[4] (RW)（待核）、HDSEL[3] (RW)（待核）、IRLP[2] (RW)（待核）、IREN[1] (RW)（待核）、EIE[0] (RW)（错误中断使能） | — |
| `USART_BRR` | 波特率配置寄存器 | `0x00C` | `0x40007C0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRR[15:0] (RW)（波特率分频参数） | — |
| `USART_GTPR` | USART 保护时间和预分频寄存器 | `0x010` | `0x40007C10` | 32 | — | 0x00000000 / 0xFFFFFFFF | GT[15:8] (RW)（保护时间值）、PSC[7:0] (RW)（预分频器值） | — |
| `USART_RTOR` | USART 接收器超时寄存器 | `0x014` | `0x40007C14` | 32 | — | 0x00000000 / 0xFFFFFFFF | BLEN[31:24] (RW)（块长度）、RTO[23:0] (RW)（接收器超时值） | — |
| `USART_RQR` | USART 请求寄存器 | `0x018` | `0x40007C18` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXFRQ[4] (WO)（发送数据清空请求）、RXFRQ[3] (WO)（接收数据清空请求）、MMRQ[2] (WO)（待核）、SBKRQ[1] (WO)（待核）、ABRRQ[0] (WO)（待核） | — |
| `USART_ISR_ENABLED` | USART 中断与状态寄存器 | `0x01C` | `0x40007C1C` | 32 | — | 0x000000C0 / 0xF00FFFFF | TXFT[27] (RO)（TXFIFO 阈值标志）、RXFT[26] (RO)（RXFIFO 阈值标志）、TCBGT[25] (RO)（待核）、RXFF[24] (RO)（RXFIFO 满）、TXFE[23] (RO)（TXFIFO 空）、REACK[22] (RO)（接收使能应答标志）、TEACK[21] (RO)（发送使能应答标志）、WUF[20] (RO)（唤醒来自低位-电源模式标志）、RWU[19] (RO)（待核）、SBKF[18] (RO)（待核）、CMF[17] (RO)（待核）、BUSY[16] (RO)（忙标志）、ABRF[15] (RO)（待核）、ABRE[14] (RO)（待核）、UDR[13] (RO)（SPI 从设备欠载错误标志）、EOBF[12] (RO)（结束的块标志）、RTOF[11] (RO)（接收器超时）、CTS[10] (RO)（CTS 标志）、CTSIF[9] (RO)（CTS 中断标志）、LBDF[8] (RO)（LIN 刹车检测标志）、TXFNF[7] (RO)（发送 FIFO 未满）、TC[6] (RO)（发送完成）、RXFNE[5] (RO)（接收 FIFO 非空）、IDLE[4] (RO)（空闲行检测到）、ORE[3] (RO)（溢出错误）、NE[2] (RO)（噪声检测标志）、FE[1] (RO)（帧错误）、PE[0] (RO)（校验错误） | — |
| `USART_ISR_DISABLED` | USART 中断与状态寄存器 | `0x01C` | `0x40007C1C` | 32 | — | 0x000000C0 / 0xF00FFFFF | TCBGT[25] (RO)（待核）、REACK[22] (RO)（接收使能应答标志）、TEACK[21] (RO)（发送使能应答标志）、WUF[20] (RO)（唤醒来自低位-电源模式标志）、RWU[19] (RO)（待核）、SBKF[18] (RO)（待核）、CMF[17] (RO)（待核）、BUSY[16] (RO)（忙标志）、ABRF[15] (RO)（待核）、ABRE[14] (RO)（待核）、UDR[13] (RO)（SPI 从设备欠载错误标志）、EOBF[12] (RO)（结束的块标志）、RTOF[11] (RO)（接收器超时）、CTS[10] (RO)（CTS 标志）、CTSIF[9] (RO)（CTS 中断标志）、LBDF[8] (RO)（LIN 刹车检测标志）、TXE[7] (RO)（发送数据寄存器空）、TC[6] (RO)（发送完成）、RXNE[5] (RO)（接收数据寄存器非空）、IDLE[4] (RO)（空闲行检测到）、ORE[3] (RO)（溢出错误）、NE[2] (RO)（噪声检测标志）、FE[1] (RO)（帧错误）、PE[0] (RO)（校验错误） | 别名 USART_ISR_ENABLED |
| `USART_ICR` | USART 中断标志清除寄存器 | `0x020` | `0x40007C20` | 32 | — | 0x00000000 / 0xFFFFFFFF | WUCF[20] (WO)（唤醒来自低位-电源模式清除标志）、CMCF[17] (WO)（待核）、UDRCF[13] (WO)（SPI 从设备欠载清除标志）、EOBCF[12] (WO)（结束的块清除标志）、RTOCF[11] (WO)（接收器超时清除标志）、CTSCF[9] (WO)（CTS 清除标志）、LBDCF[8] (WO)（LIN 刹车检测清除标志）、TCBGTCF[7] (WO)（待核）、TCCF[6] (WO)（发送完成清除标志）、TXFECF[5] (WO)（TXFIFO 空清除标志）、IDLECF[4] (WO)（空闲行检测到清除标志）、ORECF[3] (WO)（溢出错误清除标志）、NECF[2] (WO)（噪声检测到清除标志）、FECF[1] (WO)（帧错误清除标志）、PECF[0] (WO)（校验错误清除标志） | — |
| `USART_RDR` | 接收数据寄存器 | `0x024` | `0x40007C24` | 32 | — | 0x00000000 / 0xFFFFFFFF | RDR[8:0] (RO)（接收数据值） | — |
| `USART_TDR` | 发送数据寄存器 | `0x028` | `0x40007C28` | 32 | — | 0x00000000 / 0xFFFFFFFF | TDR[8:0] (RW)（发送数据值） | — |
| `USART_PRESC` | USART 预分频器寄存器 | `0x02C` | `0x40007C2C` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRESCALER[3:0] (RW)（时钟预分频器） | — |

## USART1

**模块用途**　通用同步或异步串行接口，可作普通 UART 使用。USART3 在本板可连接 ST-LINK 虚拟串口，接线以板卡文档为准。

基地址 `0x42001000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `USART_CR1_ENABLED` | USART 控制寄存器 1 | `0x000` | `0x42001000` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXFFIE[31] (RW)（RXFIFO 满中断使能）、TXFEIE[30] (RW)（TXFIFO 空中断使能）、FIFOEN[29] (RW)（FIFO 模式使能）、M1[28] (RW)（字长度）、EOBIE[27] (RW)（结束的块中断使能）、RTOIE[26] (RW)（接收器超时中断使能）、DEAT[25:21] (RW)（待核）、DEDT[20:16] (RW)（待核）、OVER8[15] (RW)（选择 8 倍或 16 倍过采样）、CMIE[14] (RW)（待核）、MME[13] (RW)（待核）、M0[12] (RW)（字长度）、WAKE[11] (RW)（待核）、PCE[10] (RW)（奇偶校验使能）、PS[9] (RW)（选择奇校验或偶校验）、PEIE[8] (RW)（PE 中断使能）、TXFNFIE[7] (RW)（待核）、TCIE[6] (RW)（发送完成中断使能）、RXFNEIE[5] (RW)（待核）、IDLEIE[4] (RW)（空闲中断使能）、TE[3] (RW)（发送器使能）、RE[2] (RW)（接收器使能）、UESM[1] (RW)（USART 使能内低位-电源模式）、UE[0] (RW)（串口总使能） | — |
| `USART_CR1_DISABLED` | USART 控制寄存器 1 | `0x000` | `0x42001000` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFOEN[29] (RW)（FIFO 模式使能）、M1[28] (RW)（字长度）、EOBIE[27] (RW)（结束的块中断使能）、RTOIE[26] (RW)（接收器超时中断使能）、DEAT[25:21] (RW)（待核）、DEDT[20:16] (RW)（待核）、OVER8[15] (RW)（选择 8 倍或 16 倍过采样）、CMIE[14] (RW)（待核）、MME[13] (RW)（待核）、M0[12] (RW)（字长度）、WAKE[11] (RW)（待核）、PCE[10] (RW)（奇偶校验使能）、PS[9] (RW)（选择奇校验或偶校验）、PEIE[8] (RW)（PE 中断使能）、TXEIE[7] (RW)（发送数据寄存器空）、TCIE[6] (RW)（发送完成中断使能）、RXNEIE[5] (RW)（待核）、IDLEIE[4] (RW)（空闲中断使能）、TE[3] (RW)（发送器使能）、RE[2] (RW)（接收器使能）、UESM[1] (RW)（USART 使能内低位-电源模式）、UE[0] (RW)（串口总使能） | 别名 USART_CR1_ENABLED |
| `USART_CR2` | USART 控制寄存器 2 | `0x004` | `0x42001004` | 32 | — | 0x00000000 / 0xFFFFFFFF | ADD[31:24] (RW)（待核）、RTOEN[23] (RW)（接收器超时使能）、ABRMOD[22:21] (RW)（待核）、ABREN[20] (RW)（待核）、MSBFIRST[19] (RW)（最高有效位首个）、DATAINV[18] (RW)（待核）、TXINV[17] (RW)（待核）、RXINV[16] (RW)（待核）、SWAP[15] (RW)（交换发送/接收引脚）、LINEN[14] (RW)（LIN 模式使能）、STOP[13:12] (RW)（停止位长度选择）、CLKEN[11] (RW)（时钟使能）、CPOL[10] (RW)（时钟极性）、CPHA[9] (RW)（时钟相位）、LBCL[8] (RW)（末尾位时钟脉冲）、LBDIE[6] (RW)（LIN 刹车检测中断使能）、LBDL[5] (RW)（LIN 刹车检测长度）、ADDM7[4] (RW)（7-位地址检测/4-位地址检测）、DIS_NSS[3] (RW)（待核）、SLVEN[0] (RW)（同步从设备模式使能） | — |
| `USART_CR3` | USART 控制寄存器 3 | `0x008` | `0x42001008` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXFTCFG[31:29] (RW)（TXFIFO 阈值配置）、RXFTIE[28] (RW)（RXFIFO 阈值中断使能）、RXFTCFG[27:25] (RW)（接收 FIFO 阈值配置）、TCBGTIE[24] (RW)（待核）、TXFTIE[23] (RW)（TXFIFO 阈值中断使能）、WUFIE[22] (RW)（唤醒来自低位-电源模式中断使能）、WUS1[21] (RW)（唤醒来自低位-电源模式中断标志选择）、WUS0[20] (RW)（唤醒来自低位-电源模式中断标志选择）、SCARCNT[19:17] (RW)（待核）、DEP[15] (RW)（待核）、DEM[14] (RW)（待核）、DDRE[13] (RW)（DMA 禁用的接收错误）、OVRDIS[12] (RW)（溢出禁用）、ONEBIT[11] (RW)（待核）、CTSIE[10] (RW)（CTS 中断使能）、CTSE[9] (RW)（CTS 使能）、RTSE[8] (RW)（RTS 使能）、DMAT[7] (RW)（DMA 使能发送器）、DMAR[6] (RW)（DMA 使能接收器）、SCEN[5] (RW)（待核）、NACK[4] (RW)（待核）、HDSEL[3] (RW)（待核）、IRLP[2] (RW)（待核）、IREN[1] (RW)（待核）、EIE[0] (RW)（错误中断使能） | — |
| `USART_BRR` | 波特率配置寄存器 | `0x00C` | `0x4200100C` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRR[15:0] (RW)（波特率分频参数） | — |
| `USART_GTPR` | USART 保护时间和预分频寄存器 | `0x010` | `0x42001010` | 32 | — | 0x00000000 / 0xFFFFFFFF | GT[15:8] (RW)（保护时间值）、PSC[7:0] (RW)（预分频器值） | — |
| `USART_RTOR` | USART 接收器超时寄存器 | `0x014` | `0x42001014` | 32 | — | 0x00000000 / 0xFFFFFFFF | BLEN[31:24] (RW)（块长度）、RTO[23:0] (RW)（接收器超时值） | — |
| `USART_RQR` | USART 请求寄存器 | `0x018` | `0x42001018` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXFRQ[4] (WO)（发送数据清空请求）、RXFRQ[3] (WO)（接收数据清空请求）、MMRQ[2] (WO)（待核）、SBKRQ[1] (WO)（待核）、ABRRQ[0] (WO)（待核） | — |
| `USART_ISR_ENABLED` | USART 中断与状态寄存器 | `0x01C` | `0x4200101C` | 32 | — | 0x000000C0 / 0xF00FFFFF | TXFT[27] (RO)（TXFIFO 阈值标志）、RXFT[26] (RO)（RXFIFO 阈值标志）、TCBGT[25] (RO)（待核）、RXFF[24] (RO)（RXFIFO 满）、TXFE[23] (RO)（TXFIFO 空）、REACK[22] (RO)（接收使能应答标志）、TEACK[21] (RO)（发送使能应答标志）、WUF[20] (RO)（唤醒来自低位-电源模式标志）、RWU[19] (RO)（待核）、SBKF[18] (RO)（待核）、CMF[17] (RO)（待核）、BUSY[16] (RO)（忙标志）、ABRF[15] (RO)（待核）、ABRE[14] (RO)（待核）、UDR[13] (RO)（SPI 从设备欠载错误标志）、EOBF[12] (RO)（结束的块标志）、RTOF[11] (RO)（接收器超时）、CTS[10] (RO)（CTS 标志）、CTSIF[9] (RO)（CTS 中断标志）、LBDF[8] (RO)（LIN 刹车检测标志）、TXFNF[7] (RO)（发送 FIFO 未满）、TC[6] (RO)（发送完成）、RXFNE[5] (RO)（接收 FIFO 非空）、IDLE[4] (RO)（空闲行检测到）、ORE[3] (RO)（溢出错误）、NE[2] (RO)（噪声检测标志）、FE[1] (RO)（帧错误）、PE[0] (RO)（校验错误） | — |
| `USART_ISR_DISABLED` | USART 中断与状态寄存器 | `0x01C` | `0x4200101C` | 32 | — | 0x000000C0 / 0xF00FFFFF | TCBGT[25] (RO)（待核）、REACK[22] (RO)（接收使能应答标志）、TEACK[21] (RO)（发送使能应答标志）、WUF[20] (RO)（唤醒来自低位-电源模式标志）、RWU[19] (RO)（待核）、SBKF[18] (RO)（待核）、CMF[17] (RO)（待核）、BUSY[16] (RO)（忙标志）、ABRF[15] (RO)（待核）、ABRE[14] (RO)（待核）、UDR[13] (RO)（SPI 从设备欠载错误标志）、EOBF[12] (RO)（结束的块标志）、RTOF[11] (RO)（接收器超时）、CTS[10] (RO)（CTS 标志）、CTSIF[9] (RO)（CTS 中断标志）、LBDF[8] (RO)（LIN 刹车检测标志）、TXE[7] (RO)（发送数据寄存器空）、TC[6] (RO)（发送完成）、RXNE[5] (RO)（接收数据寄存器非空）、IDLE[4] (RO)（空闲行检测到）、ORE[3] (RO)（溢出错误）、NE[2] (RO)（噪声检测标志）、FE[1] (RO)（帧错误）、PE[0] (RO)（校验错误） | 别名 USART_ISR_ENABLED |
| `USART_ICR` | USART 中断标志清除寄存器 | `0x020` | `0x42001020` | 32 | — | 0x00000000 / 0xFFFFFFFF | WUCF[20] (WO)（唤醒来自低位-电源模式清除标志）、CMCF[17] (WO)（待核）、UDRCF[13] (WO)（SPI 从设备欠载清除标志）、EOBCF[12] (WO)（结束的块清除标志）、RTOCF[11] (WO)（接收器超时清除标志）、CTSCF[9] (WO)（CTS 清除标志）、LBDCF[8] (WO)（LIN 刹车检测清除标志）、TCBGTCF[7] (WO)（待核）、TCCF[6] (WO)（发送完成清除标志）、TXFECF[5] (WO)（TXFIFO 空清除标志）、IDLECF[4] (WO)（空闲行检测到清除标志）、ORECF[3] (WO)（溢出错误清除标志）、NECF[2] (WO)（噪声检测到清除标志）、FECF[1] (WO)（帧错误清除标志）、PECF[0] (WO)（校验错误清除标志） | — |
| `USART_RDR` | 接收数据寄存器 | `0x024` | `0x42001024` | 32 | — | 0x00000000 / 0xFFFFFFFF | RDR[8:0] (RO)（接收数据值） | — |
| `USART_TDR` | 发送数据寄存器 | `0x028` | `0x42001028` | 32 | — | 0x00000000 / 0xFFFFFFFF | TDR[8:0] (RW)（发送数据值） | — |
| `USART_PRESC` | USART 预分频器寄存器 | `0x02C` | `0x4200102C` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRESCALER[3:0] (RW)（时钟预分频器） | — |

## USART2

**模块用途**　通用同步或异步串行接口，可作普通 UART 使用。USART3 在本板可连接 ST-LINK 虚拟串口，接线以板卡文档为准。

基地址 `0x40004400` · SVD，继承 USART1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `USART_CR1_ENABLED` | USART 控制寄存器 1 | `0x000` | `0x40004400` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXFFIE[31] (RW)（RXFIFO 满中断使能）、TXFEIE[30] (RW)（TXFIFO 空中断使能）、FIFOEN[29] (RW)（FIFO 模式使能）、M1[28] (RW)（字长度）、EOBIE[27] (RW)（结束的块中断使能）、RTOIE[26] (RW)（接收器超时中断使能）、DEAT[25:21] (RW)（待核）、DEDT[20:16] (RW)（待核）、OVER8[15] (RW)（选择 8 倍或 16 倍过采样）、CMIE[14] (RW)（待核）、MME[13] (RW)（待核）、M0[12] (RW)（字长度）、WAKE[11] (RW)（待核）、PCE[10] (RW)（奇偶校验使能）、PS[9] (RW)（选择奇校验或偶校验）、PEIE[8] (RW)（PE 中断使能）、TXFNFIE[7] (RW)（待核）、TCIE[6] (RW)（发送完成中断使能）、RXFNEIE[5] (RW)（待核）、IDLEIE[4] (RW)（空闲中断使能）、TE[3] (RW)（发送器使能）、RE[2] (RW)（接收器使能）、UESM[1] (RW)（USART 使能内低位-电源模式）、UE[0] (RW)（串口总使能） | — |
| `USART_CR1_DISABLED` | USART 控制寄存器 1 | `0x000` | `0x40004400` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFOEN[29] (RW)（FIFO 模式使能）、M1[28] (RW)（字长度）、EOBIE[27] (RW)（结束的块中断使能）、RTOIE[26] (RW)（接收器超时中断使能）、DEAT[25:21] (RW)（待核）、DEDT[20:16] (RW)（待核）、OVER8[15] (RW)（选择 8 倍或 16 倍过采样）、CMIE[14] (RW)（待核）、MME[13] (RW)（待核）、M0[12] (RW)（字长度）、WAKE[11] (RW)（待核）、PCE[10] (RW)（奇偶校验使能）、PS[9] (RW)（选择奇校验或偶校验）、PEIE[8] (RW)（PE 中断使能）、TXEIE[7] (RW)（发送数据寄存器空）、TCIE[6] (RW)（发送完成中断使能）、RXNEIE[5] (RW)（待核）、IDLEIE[4] (RW)（空闲中断使能）、TE[3] (RW)（发送器使能）、RE[2] (RW)（接收器使能）、UESM[1] (RW)（USART 使能内低位-电源模式）、UE[0] (RW)（串口总使能） | 别名 USART_CR1_ENABLED |
| `USART_CR2` | USART 控制寄存器 2 | `0x004` | `0x40004404` | 32 | — | 0x00000000 / 0xFFFFFFFF | ADD[31:24] (RW)（待核）、RTOEN[23] (RW)（接收器超时使能）、ABRMOD[22:21] (RW)（待核）、ABREN[20] (RW)（待核）、MSBFIRST[19] (RW)（最高有效位首个）、DATAINV[18] (RW)（待核）、TXINV[17] (RW)（待核）、RXINV[16] (RW)（待核）、SWAP[15] (RW)（交换发送/接收引脚）、LINEN[14] (RW)（LIN 模式使能）、STOP[13:12] (RW)（停止位长度选择）、CLKEN[11] (RW)（时钟使能）、CPOL[10] (RW)（时钟极性）、CPHA[9] (RW)（时钟相位）、LBCL[8] (RW)（末尾位时钟脉冲）、LBDIE[6] (RW)（LIN 刹车检测中断使能）、LBDL[5] (RW)（LIN 刹车检测长度）、ADDM7[4] (RW)（7-位地址检测/4-位地址检测）、DIS_NSS[3] (RW)（待核）、SLVEN[0] (RW)（同步从设备模式使能） | — |
| `USART_CR3` | USART 控制寄存器 3 | `0x008` | `0x40004408` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXFTCFG[31:29] (RW)（TXFIFO 阈值配置）、RXFTIE[28] (RW)（RXFIFO 阈值中断使能）、RXFTCFG[27:25] (RW)（接收 FIFO 阈值配置）、TCBGTIE[24] (RW)（待核）、TXFTIE[23] (RW)（TXFIFO 阈值中断使能）、WUFIE[22] (RW)（唤醒来自低位-电源模式中断使能）、WUS1[21] (RW)（唤醒来自低位-电源模式中断标志选择）、WUS0[20] (RW)（唤醒来自低位-电源模式中断标志选择）、SCARCNT[19:17] (RW)（待核）、DEP[15] (RW)（待核）、DEM[14] (RW)（待核）、DDRE[13] (RW)（DMA 禁用的接收错误）、OVRDIS[12] (RW)（溢出禁用）、ONEBIT[11] (RW)（待核）、CTSIE[10] (RW)（CTS 中断使能）、CTSE[9] (RW)（CTS 使能）、RTSE[8] (RW)（RTS 使能）、DMAT[7] (RW)（DMA 使能发送器）、DMAR[6] (RW)（DMA 使能接收器）、SCEN[5] (RW)（待核）、NACK[4] (RW)（待核）、HDSEL[3] (RW)（待核）、IRLP[2] (RW)（待核）、IREN[1] (RW)（待核）、EIE[0] (RW)（错误中断使能） | — |
| `USART_BRR` | 波特率配置寄存器 | `0x00C` | `0x4000440C` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRR[15:0] (RW)（波特率分频参数） | — |
| `USART_GTPR` | USART 保护时间和预分频寄存器 | `0x010` | `0x40004410` | 32 | — | 0x00000000 / 0xFFFFFFFF | GT[15:8] (RW)（保护时间值）、PSC[7:0] (RW)（预分频器值） | — |
| `USART_RTOR` | USART 接收器超时寄存器 | `0x014` | `0x40004414` | 32 | — | 0x00000000 / 0xFFFFFFFF | BLEN[31:24] (RW)（块长度）、RTO[23:0] (RW)（接收器超时值） | — |
| `USART_RQR` | USART 请求寄存器 | `0x018` | `0x40004418` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXFRQ[4] (WO)（发送数据清空请求）、RXFRQ[3] (WO)（接收数据清空请求）、MMRQ[2] (WO)（待核）、SBKRQ[1] (WO)（待核）、ABRRQ[0] (WO)（待核） | — |
| `USART_ISR_ENABLED` | USART 中断与状态寄存器 | `0x01C` | `0x4000441C` | 32 | — | 0x000000C0 / 0xF00FFFFF | TXFT[27] (RO)（TXFIFO 阈值标志）、RXFT[26] (RO)（RXFIFO 阈值标志）、TCBGT[25] (RO)（待核）、RXFF[24] (RO)（RXFIFO 满）、TXFE[23] (RO)（TXFIFO 空）、REACK[22] (RO)（接收使能应答标志）、TEACK[21] (RO)（发送使能应答标志）、WUF[20] (RO)（唤醒来自低位-电源模式标志）、RWU[19] (RO)（待核）、SBKF[18] (RO)（待核）、CMF[17] (RO)（待核）、BUSY[16] (RO)（忙标志）、ABRF[15] (RO)（待核）、ABRE[14] (RO)（待核）、UDR[13] (RO)（SPI 从设备欠载错误标志）、EOBF[12] (RO)（结束的块标志）、RTOF[11] (RO)（接收器超时）、CTS[10] (RO)（CTS 标志）、CTSIF[9] (RO)（CTS 中断标志）、LBDF[8] (RO)（LIN 刹车检测标志）、TXFNF[7] (RO)（发送 FIFO 未满）、TC[6] (RO)（发送完成）、RXFNE[5] (RO)（接收 FIFO 非空）、IDLE[4] (RO)（空闲行检测到）、ORE[3] (RO)（溢出错误）、NE[2] (RO)（噪声检测标志）、FE[1] (RO)（帧错误）、PE[0] (RO)（校验错误） | — |
| `USART_ISR_DISABLED` | USART 中断与状态寄存器 | `0x01C` | `0x4000441C` | 32 | — | 0x000000C0 / 0xF00FFFFF | TCBGT[25] (RO)（待核）、REACK[22] (RO)（接收使能应答标志）、TEACK[21] (RO)（发送使能应答标志）、WUF[20] (RO)（唤醒来自低位-电源模式标志）、RWU[19] (RO)（待核）、SBKF[18] (RO)（待核）、CMF[17] (RO)（待核）、BUSY[16] (RO)（忙标志）、ABRF[15] (RO)（待核）、ABRE[14] (RO)（待核）、UDR[13] (RO)（SPI 从设备欠载错误标志）、EOBF[12] (RO)（结束的块标志）、RTOF[11] (RO)（接收器超时）、CTS[10] (RO)（CTS 标志）、CTSIF[9] (RO)（CTS 中断标志）、LBDF[8] (RO)（LIN 刹车检测标志）、TXE[7] (RO)（发送数据寄存器空）、TC[6] (RO)（发送完成）、RXNE[5] (RO)（接收数据寄存器非空）、IDLE[4] (RO)（空闲行检测到）、ORE[3] (RO)（溢出错误）、NE[2] (RO)（噪声检测标志）、FE[1] (RO)（帧错误）、PE[0] (RO)（校验错误） | 别名 USART_ISR_ENABLED |
| `USART_ICR` | USART 中断标志清除寄存器 | `0x020` | `0x40004420` | 32 | — | 0x00000000 / 0xFFFFFFFF | WUCF[20] (WO)（唤醒来自低位-电源模式清除标志）、CMCF[17] (WO)（待核）、UDRCF[13] (WO)（SPI 从设备欠载清除标志）、EOBCF[12] (WO)（结束的块清除标志）、RTOCF[11] (WO)（接收器超时清除标志）、CTSCF[9] (WO)（CTS 清除标志）、LBDCF[8] (WO)（LIN 刹车检测清除标志）、TCBGTCF[7] (WO)（待核）、TCCF[6] (WO)（发送完成清除标志）、TXFECF[5] (WO)（TXFIFO 空清除标志）、IDLECF[4] (WO)（空闲行检测到清除标志）、ORECF[3] (WO)（溢出错误清除标志）、NECF[2] (WO)（噪声检测到清除标志）、FECF[1] (WO)（帧错误清除标志）、PECF[0] (WO)（校验错误清除标志） | — |
| `USART_RDR` | 接收数据寄存器 | `0x024` | `0x40004424` | 32 | — | 0x00000000 / 0xFFFFFFFF | RDR[8:0] (RO)（接收数据值） | — |
| `USART_TDR` | 发送数据寄存器 | `0x028` | `0x40004428` | 32 | — | 0x00000000 / 0xFFFFFFFF | TDR[8:0] (RW)（发送数据值） | — |
| `USART_PRESC` | USART 预分频器寄存器 | `0x02C` | `0x4000442C` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRESCALER[3:0] (RW)（时钟预分频器） | — |

## USART3

**模块用途**　通用同步或异步串行接口，可作普通 UART 使用。USART3 在本板可连接 ST-LINK 虚拟串口，接线以板卡文档为准。

基地址 `0x40004800` · SVD，继承 USART1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `USART_CR1_ENABLED` | USART 控制寄存器 1 | `0x000` | `0x40004800` | 32 | — | 0x00000000 / 0xFFFFFFFF | RXFFIE[31] (RW)（RXFIFO 满中断使能）、TXFEIE[30] (RW)（TXFIFO 空中断使能）、FIFOEN[29] (RW)（FIFO 模式使能）、M1[28] (RW)（字长度）、EOBIE[27] (RW)（结束的块中断使能）、RTOIE[26] (RW)（接收器超时中断使能）、DEAT[25:21] (RW)（待核）、DEDT[20:16] (RW)（待核）、OVER8[15] (RW)（选择 8 倍或 16 倍过采样）、CMIE[14] (RW)（待核）、MME[13] (RW)（待核）、M0[12] (RW)（字长度）、WAKE[11] (RW)（待核）、PCE[10] (RW)（奇偶校验使能）、PS[9] (RW)（选择奇校验或偶校验）、PEIE[8] (RW)（PE 中断使能）、TXFNFIE[7] (RW)（待核）、TCIE[6] (RW)（发送完成中断使能）、RXFNEIE[5] (RW)（待核）、IDLEIE[4] (RW)（空闲中断使能）、TE[3] (RW)（发送器使能）、RE[2] (RW)（接收器使能）、UESM[1] (RW)（USART 使能内低位-电源模式）、UE[0] (RW)（串口总使能） | — |
| `USART_CR1_DISABLED` | USART 控制寄存器 1 | `0x000` | `0x40004800` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFOEN[29] (RW)（FIFO 模式使能）、M1[28] (RW)（字长度）、EOBIE[27] (RW)（结束的块中断使能）、RTOIE[26] (RW)（接收器超时中断使能）、DEAT[25:21] (RW)（待核）、DEDT[20:16] (RW)（待核）、OVER8[15] (RW)（选择 8 倍或 16 倍过采样）、CMIE[14] (RW)（待核）、MME[13] (RW)（待核）、M0[12] (RW)（字长度）、WAKE[11] (RW)（待核）、PCE[10] (RW)（奇偶校验使能）、PS[9] (RW)（选择奇校验或偶校验）、PEIE[8] (RW)（PE 中断使能）、TXEIE[7] (RW)（发送数据寄存器空）、TCIE[6] (RW)（发送完成中断使能）、RXNEIE[5] (RW)（待核）、IDLEIE[4] (RW)（空闲中断使能）、TE[3] (RW)（发送器使能）、RE[2] (RW)（接收器使能）、UESM[1] (RW)（USART 使能内低位-电源模式）、UE[0] (RW)（串口总使能） | 别名 USART_CR1_ENABLED |
| `USART_CR2` | USART 控制寄存器 2 | `0x004` | `0x40004804` | 32 | — | 0x00000000 / 0xFFFFFFFF | ADD[31:24] (RW)（待核）、RTOEN[23] (RW)（接收器超时使能）、ABRMOD[22:21] (RW)（待核）、ABREN[20] (RW)（待核）、MSBFIRST[19] (RW)（最高有效位首个）、DATAINV[18] (RW)（待核）、TXINV[17] (RW)（待核）、RXINV[16] (RW)（待核）、SWAP[15] (RW)（交换发送/接收引脚）、LINEN[14] (RW)（LIN 模式使能）、STOP[13:12] (RW)（停止位长度选择）、CLKEN[11] (RW)（时钟使能）、CPOL[10] (RW)（时钟极性）、CPHA[9] (RW)（时钟相位）、LBCL[8] (RW)（末尾位时钟脉冲）、LBDIE[6] (RW)（LIN 刹车检测中断使能）、LBDL[5] (RW)（LIN 刹车检测长度）、ADDM7[4] (RW)（7-位地址检测/4-位地址检测）、DIS_NSS[3] (RW)（待核）、SLVEN[0] (RW)（同步从设备模式使能） | — |
| `USART_CR3` | USART 控制寄存器 3 | `0x008` | `0x40004808` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXFTCFG[31:29] (RW)（TXFIFO 阈值配置）、RXFTIE[28] (RW)（RXFIFO 阈值中断使能）、RXFTCFG[27:25] (RW)（接收 FIFO 阈值配置）、TCBGTIE[24] (RW)（待核）、TXFTIE[23] (RW)（TXFIFO 阈值中断使能）、WUFIE[22] (RW)（唤醒来自低位-电源模式中断使能）、WUS1[21] (RW)（唤醒来自低位-电源模式中断标志选择）、WUS0[20] (RW)（唤醒来自低位-电源模式中断标志选择）、SCARCNT[19:17] (RW)（待核）、DEP[15] (RW)（待核）、DEM[14] (RW)（待核）、DDRE[13] (RW)（DMA 禁用的接收错误）、OVRDIS[12] (RW)（溢出禁用）、ONEBIT[11] (RW)（待核）、CTSIE[10] (RW)（CTS 中断使能）、CTSE[9] (RW)（CTS 使能）、RTSE[8] (RW)（RTS 使能）、DMAT[7] (RW)（DMA 使能发送器）、DMAR[6] (RW)（DMA 使能接收器）、SCEN[5] (RW)（待核）、NACK[4] (RW)（待核）、HDSEL[3] (RW)（待核）、IRLP[2] (RW)（待核）、IREN[1] (RW)（待核）、EIE[0] (RW)（错误中断使能） | — |
| `USART_BRR` | 波特率配置寄存器 | `0x00C` | `0x4000480C` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRR[15:0] (RW)（波特率分频参数） | — |
| `USART_GTPR` | USART 保护时间和预分频寄存器 | `0x010` | `0x40004810` | 32 | — | 0x00000000 / 0xFFFFFFFF | GT[15:8] (RW)（保护时间值）、PSC[7:0] (RW)（预分频器值） | — |
| `USART_RTOR` | USART 接收器超时寄存器 | `0x014` | `0x40004814` | 32 | — | 0x00000000 / 0xFFFFFFFF | BLEN[31:24] (RW)（块长度）、RTO[23:0] (RW)（接收器超时值） | — |
| `USART_RQR` | USART 请求寄存器 | `0x018` | `0x40004818` | 32 | — | 0x00000000 / 0xFFFFFFFF | TXFRQ[4] (WO)（发送数据清空请求）、RXFRQ[3] (WO)（接收数据清空请求）、MMRQ[2] (WO)（待核）、SBKRQ[1] (WO)（待核）、ABRRQ[0] (WO)（待核） | — |
| `USART_ISR_ENABLED` | USART 中断与状态寄存器 | `0x01C` | `0x4000481C` | 32 | — | 0x000000C0 / 0xF00FFFFF | TXFT[27] (RO)（TXFIFO 阈值标志）、RXFT[26] (RO)（RXFIFO 阈值标志）、TCBGT[25] (RO)（待核）、RXFF[24] (RO)（RXFIFO 满）、TXFE[23] (RO)（TXFIFO 空）、REACK[22] (RO)（接收使能应答标志）、TEACK[21] (RO)（发送使能应答标志）、WUF[20] (RO)（唤醒来自低位-电源模式标志）、RWU[19] (RO)（待核）、SBKF[18] (RO)（待核）、CMF[17] (RO)（待核）、BUSY[16] (RO)（忙标志）、ABRF[15] (RO)（待核）、ABRE[14] (RO)（待核）、UDR[13] (RO)（SPI 从设备欠载错误标志）、EOBF[12] (RO)（结束的块标志）、RTOF[11] (RO)（接收器超时）、CTS[10] (RO)（CTS 标志）、CTSIF[9] (RO)（CTS 中断标志）、LBDF[8] (RO)（LIN 刹车检测标志）、TXFNF[7] (RO)（发送 FIFO 未满）、TC[6] (RO)（发送完成）、RXFNE[5] (RO)（接收 FIFO 非空）、IDLE[4] (RO)（空闲行检测到）、ORE[3] (RO)（溢出错误）、NE[2] (RO)（噪声检测标志）、FE[1] (RO)（帧错误）、PE[0] (RO)（校验错误） | — |
| `USART_ISR_DISABLED` | USART 中断与状态寄存器 | `0x01C` | `0x4000481C` | 32 | — | 0x000000C0 / 0xF00FFFFF | TCBGT[25] (RO)（待核）、REACK[22] (RO)（接收使能应答标志）、TEACK[21] (RO)（发送使能应答标志）、WUF[20] (RO)（唤醒来自低位-电源模式标志）、RWU[19] (RO)（待核）、SBKF[18] (RO)（待核）、CMF[17] (RO)（待核）、BUSY[16] (RO)（忙标志）、ABRF[15] (RO)（待核）、ABRE[14] (RO)（待核）、UDR[13] (RO)（SPI 从设备欠载错误标志）、EOBF[12] (RO)（结束的块标志）、RTOF[11] (RO)（接收器超时）、CTS[10] (RO)（CTS 标志）、CTSIF[9] (RO)（CTS 中断标志）、LBDF[8] (RO)（LIN 刹车检测标志）、TXE[7] (RO)（发送数据寄存器空）、TC[6] (RO)（发送完成）、RXNE[5] (RO)（接收数据寄存器非空）、IDLE[4] (RO)（空闲行检测到）、ORE[3] (RO)（溢出错误）、NE[2] (RO)（噪声检测标志）、FE[1] (RO)（帧错误）、PE[0] (RO)（校验错误） | 别名 USART_ISR_ENABLED |
| `USART_ICR` | USART 中断标志清除寄存器 | `0x020` | `0x40004820` | 32 | — | 0x00000000 / 0xFFFFFFFF | WUCF[20] (WO)（唤醒来自低位-电源模式清除标志）、CMCF[17] (WO)（待核）、UDRCF[13] (WO)（SPI 从设备欠载清除标志）、EOBCF[12] (WO)（结束的块清除标志）、RTOCF[11] (WO)（接收器超时清除标志）、CTSCF[9] (WO)（CTS 清除标志）、LBDCF[8] (WO)（LIN 刹车检测清除标志）、TCBGTCF[7] (WO)（待核）、TCCF[6] (WO)（发送完成清除标志）、TXFECF[5] (WO)（TXFIFO 空清除标志）、IDLECF[4] (WO)（空闲行检测到清除标志）、ORECF[3] (WO)（溢出错误清除标志）、NECF[2] (WO)（噪声检测到清除标志）、FECF[1] (WO)（帧错误清除标志）、PECF[0] (WO)（校验错误清除标志） | — |
| `USART_RDR` | 接收数据寄存器 | `0x024` | `0x40004824` | 32 | — | 0x00000000 / 0xFFFFFFFF | RDR[8:0] (RO)（接收数据值） | — |
| `USART_TDR` | 发送数据寄存器 | `0x028` | `0x40004828` | 32 | — | 0x00000000 / 0xFFFFFFFF | TDR[8:0] (RW)（发送数据值） | — |
| `USART_PRESC` | USART 预分频器寄存器 | `0x02C` | `0x4000482C` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRESCALER[3:0] (RW)（时钟预分频器） | — |
