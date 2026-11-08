# 系统、时钟、电源与调试寄存器

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
| [CRS](#crs) | `0x40008400` | 4 | SVD |
| [DBGMCU](#dbgmcu) | `0x5C001000` | 20 | SVD |
| [PWR](#pwr) | `0x58024800` | 17 | SVD |
| [RCC](#rcc) | `0x58024400` | 64 | SVD |
| [SBS](#sbs) | `0x58000400` | 17 | SVD |

## CRS

**模块用途**　时钟恢复系统，根据参考同步信号修整内部 48 MHz 振荡器。

基地址 `0x40008400` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `CRS_CR` | CRS 控制寄存器 | `0x000` | `0x40008400` | 32 | — | 0x00002000 / 0xFFFFFFFF | TRIM[13:8] (RW)（待核）、SWSYNC[7] (RW)（待核）、AUTOTRIMEN[6] (RW)（待核）、CEN[5] (RW)（频率错误计数器使能）、ESYNCIE[3] (RW)（待核）、ERRIE[2] (RW)（同步或微调错误中断使能）、SYNCWARNIE[1] (RW)（待核）、SYNCOKIE[0] (RW)（同步事件 OK 中断使能） | — |
| `CRS_CFGR` | CRS 配置寄存器 | `0x004` | `0x40008404` | 32 | — | 0x2022BB7F / 0xFFFFFFFF | SYNCPOL[31] (RW)（同步极性选择）、SYNCSRC[29:28] (RW)（待核）、SYNCDIV[26:24] (RW)（同步分频器）、FELIM[23:16] (RW)（频率错误限制）、RELOAD[15:0] (RW)（计数器重装值） | — |
| `CRS_ISR` | CRS 中断与状态寄存器 | `0x008` | `0x40008408` | 32 | — | 0x00000000 / 0xFFFFFFFF | FECAP[31:16] (RO)（频率错误捕获）、FEDIR[15] (RO)（频率错误方向）、TRIMOVF[10] (RO)（微调溢出或下溢）、SYNCMISS[9] (RO)（同步丢失）、SYNCERR[8] (RO)（同步错误）、ESYNCF[3] (RO)（待核）、ERRF[2] (RO)（错误标志）、SYNCWARNF[1] (RO)（待核）、SYNCOKF[0] (RO)（同步事件 OK 标志） | — |
| `CRS_ICR` | CRS 中断标志清除寄存器 | `0x00C` | `0x4000840C` | 32 | — | 0x00000000 / 0xFFFFFFFF | ESYNCC[3] (RW)（待核）、ERRC[2] (RW)（错误清除标志）、SYNCWARNC[1] (RW)（待核）、SYNCOKC[0] (RW)（同步事件 OK 清除标志） | — |

## DBGMCU

**模块用途**　微控制器调试控制器，用于读取芯片标识并配置调试暂停时的外设冻结行为。

基地址 `0x5C001000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `DBGMCU_IDC` | DBGMCU 标识编码寄存器 | `0x000` | `0x5C001000` | 32 | — | 0x00006485 / 0x0000FFFF | REV_ID[31:16] (RO)（修订号）、DEV_ID[11:0] (RO)（设备 ID） | — |
| `DBGMCU_CR` | DBGMCU 配置寄存器 | `0x004` | `0x5C001004` | 32 | — | 0x00000000 / 0xFFFFFFFF | TRGOEN[28] (RW)（外部触发输出使能）、D1DBGCKEN[21] (RW)（D1 调试时钟使能）、TRACECLKEN[20] (RW)（待核）、DCRT[16] (RW)（待核）、DBGSTBY[2] (RW)（调试内待机模式使能）、DBGSTOP[1] (RW)（调试内停止模式使能）、DBGSLEEP[0] (RW)（调试内睡眠模式使能） | — |
| `DBGMCU_AHB5FZR` | DBGMCU AHB5 外设冻结寄存器 | `0x01C` | `0x5C00101C` | 32 | — | 0x00000000 / 0xFFFFFFFF | DBG_HPDMA_15_STOP[15] (RW)（HPDMA 通道 15 停止内调试）、DBG_HPDMA_14_STOP[14] (RW)（HPDMA 通道 14 停止内调试）、DBG_HPDMA_13_STOP[13] (RW)（HPDMA 通道 13 停止内调试）、DBG_HPDMA_12_STOP[12] (RW)（HPDMA 通道 12 停止内调试）、DBG_HPDMA_11_STOP[11] (RW)（HPDMA 通道 11 停止内调试）、DBG_HPDMA_10_STOP[10] (RW)（HPDMA 通道 10 停止内调试）、DBG_HPDMA_9_STOP[9] (RW)（HPDMA 通道 9 停止内调试）、DBG_HPDMA_8_STOP[8] (RW)（HPDMA 通道 8 停止内调试）、DBG_HPDMA_7_STOP[7] (RW)（HPDMA 通道 7 停止内调试）、DBG_HPDMA_6_STOP[6] (RW)（HPDMA 通道 6 停止内调试）、DBG_HPDMA_5_STOP[5] (RW)（HPDMA 通道 5 停止内调试）、DBG_HPDMA_4_STOP[4] (RW)（HPDMA 通道 4 停止内调试）、DBG_HPDMA_3_STOP[3] (RW)（HPDMA 通道 3 停止内调试）、DBG_HPDMA_2_STOP[2] (RW)（HPDMA 通道 2 停止内调试）、DBG_HPDMA_1_STOP[1] (RW)（HPDMA 通道 1 停止内调试）、DBG_HPDMA_0_STOP[0] (RW)（HPDMA 通道 0 停止内调试） | 偏移按 CMSIS |
| `DBGMCU_AHB1FZR` | DBGMCU AHB1 外设冻结寄存器 | `0x024` | `0x5C001024` | 32 | — | 0x00000000 / 0xFFFFFFFF | DBG_GPDMA_15_STOP[15] (RW)（GPDMA 通道 15 停止内调试）、DBG_GPDMA_14_STOP[14] (RW)（GPDMA 通道 14 停止内调试）、DBG_GPDMA_13_STOP[13] (RW)（GPDMA 通道 13 停止内调试）、DBG_GPDMA_12_STOP[12] (RW)（GPDMA 通道 12 停止内调试）、DBG_GPDMA_11_STOP[11] (RW)（GPDMA 通道 11 停止内调试）、DBG_GPDMA_10_STOP[10] (RW)（GPDMA 通道 10 停止内调试）、DBG_GPDMA_9_STOP[9] (RW)（GPDMA 通道 9 停止内调试）、DBG_GPDMA_8_STOP[8] (RW)（GPDMA 通道 8 停止内调试）、DBG_GPDMA_7_STOP[7] (RW)（GPDMA 通道 7 停止内调试）、DBG_GPDMA_6_STOP[6] (RW)（GPDMA 通道 6 停止内调试）、DBG_GPDMA_5_STOP[5] (RW)（GPDMA 通道 5 停止内调试）、DBG_GPDMA_4_STOP[4] (RW)（GPDMA 通道 4 停止内调试）、DBG_GPDMA_3_STOP[3] (RW)（GPDMA 通道 3 停止内调试）、DBG_GPDMA_2_STOP[2] (RW)（GPDMA 通道 2 停止内调试）、DBG_GPDMA_1_STOP[1] (RW)（GPDMA 通道 1 停止内调试）、DBG_GPDMA_0_STOP[0] (RW)（GPDMA 通道 0 停止内调试） | — |
| `DBGMCU_APB1FZR` | DBGMCU APB1 外设冻结寄存器 | `0x03C` | `0x5C00103C` | 32 | — | 0x00000000 / 0xFFFFFFFF | I2C3[23] (RW)（I2C3 SMBUS 超时停止内调试）、I2C2[22] (RW)（I2C2 SMBUS 超时停止内调试）、I2C1[21] (RW)（I2C1 SMBUS 超时停止内调试）、WWDG[11] (RW)（WWDG 停止内调试）、LPTIM1[9] (RW)（LPTIM1 停止内调试）、TIM14[8] (RW)（TIM14 停止内调试）、TIM13[7] (RW)（TIM13 停止内调试）、TIM12[6] (RW)（TIM12 停止内调试）、TIM7[5] (RW)（TIM7 停止内调试）、TIM6[4] (RW)（TIM6 停止内调试）、TIM5[3] (RW)（TIM5 停止内调试）、TIM4[2] (RW)（TIM4 停止内调试）、TIM3[1] (RW)（TIM3 停止内调试）、TIM2[0] (RW)（TIM2 停止内调试） | — |
| `DBGMCU_APB2FZ` | DBGMCU APB2 外设冻结寄存器 | `0x04C` | `0x5C00104C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TIM9[19] (RW)（TIM9 停止内调试）、TIM17[18] (RW)（TIM17 停止内调试）、TIM16[17] (RW)（TIM16 停止内调试）、TIM15[16] (RW)（TIM15 停止内调试）、TIM1[0] (RW)（TIM1 停止内调试） | — |
| `DBGMCU_APB4FZR` | DBGMCU APB4 外设冻结寄存器 | `0x054` | `0x5C001054` | 32 | — | 0x00000000 / 0xFFFFFFFF | IWDG[18] (RW)（待核）、RTC[16] (RW)（RTC 停止内调试）、LPTIM5[12] (RW)（LPTIM5 停止内调试）、LPTIM4[11] (RW)（LPTIM4 停止内调试）、LPTIM3[10] (RW)（LPTIM2 停止内调试）、LPTIM2[9] (RW)（LPTIM2 停止内调试） | — |
| `DBGMCU_SR` | DBGMCU 状态寄存器 | `0x0FC` | `0x5C0010FC` | 32 | — | 0x00010003 / 0xFFFFFFFF | AP_ENABLED[31:16] (RO)（待核）、AP_PRESENT[15:0] (RO)（待核） | — |
| `DBGMCU_DBG_AUTH_HOST` | DBGMCU 调试认证邮箱主机寄存器 | `0x100` | `0x5C001100` | 32 | — | 0x00000000 / 0x00000000 | MESSAGE[31:0] (RW)（调试主机至设备邮箱消息） | — |
| `DBGMCU_DBG_AUTH_DEVICE` | DBGMCU 调试认证邮箱设备寄存器 | `0x104` | `0x5C001104` | 32 | — | 0x00000000 / 0x00000000 | MESSAGE[31:0] (RW)（设备至调试主机邮箱消息） | — |
| `DBGMCU_DBG_AUTH_ACK` | DBGMCU 调试认证邮箱应答寄存器 | `0x108` | `0x5C001108` | 32 | — | 0x00000000 / 0xFFFFFFFF | DEV_ACK[1] (RW)（设备至设备应答）、HOST_ACK[0] (RW)（主机至设备应答） | — |
| `DBGMCU_PIDR4` | DBGMCU 外设标识寄存器 4 | `0xFD0` | `0x5C001FD0` | 32 | — | 0x00000000 / 0xFFFFFFFF | SIZE[7:4] (RO)（待核）、JEP106CON[3:0] (RO)（待核） | — |
| `DBGMCU_PIDR0` | DBGMCU 外设标识寄存器 0 | `0xFE0` | `0x5C001FE0` | 32 | — | 0x00000000 / 0xFFFFFFFF | PARTNUM[7:0] (RO)（待核） | — |
| `DBGMCU_PIDR1` | DBGMCU 外设标识寄存器 1 | `0xFE4` | `0x5C001FE4` | 32 | — | 0x00000000 / 0xFFFFFFFF | JEP106ID[7:4] (RO)（待核）、PARTNUM[3:0] (RO)（待核） | — |
| `DBGMCU_PIDR2` | DBGMCU 外设标识寄存器 2 | `0xFE8` | `0x5C001FE8` | 32 | — | 0x0000000A / 0xFFFFFFFF | REVISION[7:4] (RO)（组件修订号编号）、JEDEC[3] (RO)（待核）、JEP106ID[2:0] (RO)（待核） | — |
| `DBGMCU_PIDR3` | DBGMCU 外设标识寄存器 3 | `0xFEC` | `0x5C001FEC` | 32 | — | 0x00000000 / 0xFFFFFFFF | REVAND[7:4] (RO)（待核）、CMOD[3:0] (RO)（待核） | — |
| `DBGMCU_CIDR0` | DBGMCU 组件标识寄存器 | `0xFF0` | `0x5C001FF0` | 32 | — | 0x0000000D / 0xFFFFFFFF | PREAMBLE[7:0] (RO)（待核） | — |
| `DBGMCU_CIDR1` | DBGMCU 组件标识寄存器 | `0xFF4` | `0x5C001FF4` | 32 | — | 0x000000F0 / 0xFFFFFFFF | CLASS[7:4] (RO)（待核）、PREAMBLE[3:0] (RO)（待核） | — |
| `DBGMCU_CIDR2` | DBGMCU 组件标识寄存器 | `0xFF8` | `0x5C001FF8` | 32 | — | 0x00000005 / 0xFFFFFFFF | PREAMBLE[7:0] (RO)（待核） | — |
| `DBGMCU_CIDR3` | DBGMCU 组件标识寄存器 | `0xFFC` | `0x5C001FFC` | 32 | — | 0x000000B1 / 0xFFFFFFFF | PREAMBLE[7:0] (RO)（待核） | — |

## PWR

**模块用途**　电源控制器，管理供电模式、电压等级、低功耗进入和唤醒相关配置。

基地址 `0x58024800` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `PWR_CR1` | PWR 控制寄存器 1 | `0x000` | `0x58024800` | 32 | — | 0x00000001 / 0xFFFFFFFF | ALS[15:14] (RW)（待核）、AVDEN[13] (RW)（外设电压监测的 VDDA 使能）、AVDREADY[12] (RW)（模拟电压就绪）、BOOSTE[11] (RW)（待核）、RLPSN[10] (RW)（RAM 低功耗模式禁用内停止）、FLPS[9] (RW)（闪存低位-电源模式内停止模式）、DBP[8] (RW)（禁用备份域写保护）、PLS[7:5] (RW)（待核）、PVDE[4] (RW)（待核）、SVOS[0] (RW)（待核） | — |
| `PWR_SR1` | PWR 控制状态寄存器 1 | `0x004` | `0x58024804` | 32 | — | 0x00000000 / 0xFFFFFFFF | AVDO[13] (RO)（待核）、PVDO[4] (RO)（待核）、ACTVOSRDY[1] (RO)（待核）、ACTVOS[0] (RO)（待核） | — |
| `PWR_CSR1` | PWR 控制状态寄存器 1 | `0x008` | `0x58024808` | 32 | — | 0x00000000 / 0xFFFFFFFF | TEMPH[23] (RO)（待核）、TEMPL[22] (RO)（待核）、VBATH[21] (RO)（待核）、VBATL[20] (RO)（待核）、BRRDY[16] (RO)（待核）、MONEN[4] (RW)（待核）、BREN[0] (RW)（待核） | — |
| `PWR_CSR2` | PWR 控制寄存器 2 | `0x00C` | `0x5802480C` | 32 | — | 0x00000006 / 0xFFFFFFFF | USBHSREGEN[27] (RW)（待核）、USB33RDY[26] (RO)（待核）、USBREGEN[25] (RW)（待核）、USB33DEN[24] (RW)（待核）、SDEXTRDY[16] (RO)（待核）、EN_XSPIM2[15] (RW)（待核）、EN_XSPIM1[14] (RW)（待核）、XSPICAP2[13:12] (RW)（待核）、XSPICAP1[11:10] (RW)（待核）、VBRS[9] (RW)（待核）、VBE[8] (RW)（待核）、SDHILEVEL[4] (RW1)（待核）、SMPSEXTHP[3] (RW1)（SMPS 外部供电协商选择）、SDEN[2] (RW1)（待核）、LDOEN[1] (RW1)（待核）、BYPASS[0] (RW1)（待核） | — |
| `PWR_CSR3` | PWR CPU 控制寄存器 3 | `0x010` | `0x58024810` | 32 | — | 0x00000000 / 0xFFFFFFFF | SBF[9] (RO)（待核）、STOPF[8] (RO)（停止标志）、CSSF[1] (RW)（待核）、PDDS[0] (RW)（待核） | — |
| `PWR_CSR4` | PWR 控制状态寄存器 4 | `0x014` | `0x58024814` | 32 | — | 0x00000002 / 0xFFFFFFFF | VOSRDY[1] (RO)（VOS 就绪位）、VOS[0] (RW)（待核） | — |
| `PWR_WKUPCR` | PWR 唤醒清除寄存器 | `0x020` | `0x58024820` | 32 | — | 0x00000000 / 0xFFFFFFFF | WKUPC4[3] (RW)（清除唤醒引脚标志的 WKUP4）、WKUPC3[2] (RW)（清除唤醒引脚标志的 WKUP3）、WKUPC2[1] (RW)（清除唤醒引脚标志的 WKUP2）、WKUPC1[0] (RW)（清除唤醒引脚标志的 WKUP1） | — |
| `PWR_WKUPFR` | PWR 唤醒标志寄存器 | `0x024` | `0x58024824` | 32 | — | 0x00000000 / 0xFFFFFFFF | WKUPF4[3] (RO)（唤醒引脚 WKUP4 标志）、WKUPF3[2] (RO)（唤醒引脚 WKUP3 标志）、WKUPF2[1] (RO)（唤醒引脚 WKUP2 标志）、WKUPF1[0] (RO)（唤醒引脚 WKUP1 标志） | — |
| `PWR_WKUPEPR` | PWR 唤醒使能与极性寄存器 | `0x028` | `0x58024828` | 32 | — | 0x00000000 / 0xFFFFFFFF | WKUPPUPD4[23:22] (RW)（待核）、WKUPPUPD3[21:20] (RW)（待核）、WKUPPUPD2[19:18] (RW)（待核）、WKUPPUPD1[17:16] (RW)（待核）、WKUPP4[11] (RW)（待核）、WKUPP3[10] (RW)（待核）、WKUPP2[9] (RW)（待核）、WKUPP1[8] (RW)（待核）、WKUPEN4[3] (RW)（待核）、WKUPEN3[2] (RW)（待核）、WKUPEN2[1] (RW)（待核）、WKUPEN1[0] (RW)（待核） | — |
| `PWR_UCPDR` | USB Type-C 和供电协商相关电源配置 | `0x02C` | `0x5802482C` | 32 | — | 0x00000002 / 0xFFFFFFFF | UCPD_STBY[1] (RW)（UCPD 待机模式）、UCPD_DBDIS[0] (RW)（待核） | — |
| `PWR_APCR` | 应用上下拉配置 | `0x030` | `0x58024830` | 32 | — | 0x00030000 / 0xFFFFFFFF | I3CPB9_PU[31] (RW)（端口 PB9 I3C 上拉位）、I3CPB8_PU[30] (RW)（端口 PB8 I3C 上拉位）、I3CPB7_PU[29] (RW)（端口 PB7 I3C 上拉位）、I3CPB6_PU[28] (RW)（端口 PB6 I3C 上拉位）、PO5_PUPD[17] (RW)（待核）、PN7_PUPD[16] (RW)（待核）、APC[0] (RW)（待核） | — |
| `PWR_PUCRN` | PWR 端口 N 上拉控制寄存器 | `0x034` | `0x58024834` | 32 | — | 0x00000000 / 0xFFFFFFFF | PUN12[12] (RW)（端口 N 上拉位 12）、PUN6[6] (RW)（端口 N 上拉位 6）、PUN1[1] (RW)（端口 N 上拉位 1） | — |
| `PWR_PDCRN` | PWR 端口 N 下拉控制寄存器 | `0x038` | `0x58024838` | 32 | — | 0x00000000 / 0xFFFFFFFF | PDN12[12] (RW)（端口 N 下拉位 12）、PDN8N11[8] (RW)（待核）、PDN6[6] (RW)（端口 N 下拉位 6）、PDN2N5[2] (RW)（待核）、PDN1[1] (RW)（端口 N 下拉位 1）、PDN0[0] (RW)（端口 N 下拉位 0） | — |
| `PWR_PUCRO` | PWR 端口 O 上拉控制寄存器 | `0x03C` | `0x5802483C` | 32 | — | 0x00000000 / 0xFFFFFFFF | PUO4[4] (RW)（端口 O 上拉位 4）、PUO1[1] (RW)（(n = 1 至 0) 端口 O 上拉位）、PUO0[0] (RW)（(n = 1 至 0) 端口 O 上拉位） | — |
| `PWR_PDCRO` | PWR 端口 O 下拉控制寄存器 | `0x040` | `0x58024840` | 32 | — | 0x00000000 / 0xFFFFFFFF | PDO4[4] (RW)（端口 O 下拉位 y）、PDO3[3] (RW)（端口 O 下拉位 y）、PDO2[2] (RW)（端口 O 下拉位 y）、PDO1[1] (RW)（端口 O 下拉位 y）、PDO0[0] (RW)（端口 O 下拉位 y） | — |
| `PWR_PDCRP` | PWR 端口 P 下拉控制寄存器 | `0x044` | `0x58024844` | 32 | — | 0x00000000 / 0xFFFFFFFF | PDP12P15[12] (RW)（待核）、PDP8P11[8] (RW)（待核）、PDP4P7[4] (RW)（待核）、PDP0P3[0] (RW)（待核） | — |
| `PWR_PDR1` | PWR 调试寄存器 1 | `0x050` | `0x58024850` | 32 | — | 0x00000000 / 0xFFFFFFFF | SYNC_ADC[16] (RW)（待核）、SDFPWMEN[3] (RW)（待核）、UNLOCKED[0] (RW)（待核） | — |

## RCC

**模块用途**　复位与时钟控制器，管理振荡器、PLL、总线分频、外设时钟和外设复位。GPIO 点灯从对应端口的时钟使能开始。

基地址 `0x58024400` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `RCC_CR` | 配置和检查内部及外部时钟源 | `0x000` | `0x58024400` | 32 | RW | 0x00000025 / 0xFFFFFFFF | PLL3RDY[29] (RO)（PLL3 时钟就绪标志）、PLL3ON[28]（PLL3 使能）、PLL2RDY[27] (RO)（PLL2 时钟就绪标志）、PLL2ON[26]（PLL2 使能）、PLL1RDY[25] (RO)（PLL1 时钟就绪标志）、PLL1ON[24]（PLL1 使能）、HSECSSON[20]（HSE 时钟安全系统使能）、HSEEXT[19]（待核）、HSEBYP[18]（待核）、HSERDY[17] (RO)（HSE 时钟就绪标志）、HSEON[16]（HSE 时钟使能）、HSI48RDY[13] (RO)（HSI48 时钟就绪标志）、HSI48ON[12]（HSI48 时钟使能）、CSIKERON[9]（CSI 时钟使能内停止模式）、CSIRDY[8] (RO)（CSI 时钟就绪标志）、CSION[7]（CSI 时钟使能）、HSIDIVF[5] (RO)（HSI 分频器标志）、HSIDIV[4:3]（HSI 时钟分频）、HSIRDY[2] (RO)（HSI 时钟就绪标志）、HSIKERON[1]（HSI 时钟使能内停止模式）、HSION[0]（HSI 时钟使能） | — |
| `RCC_HSICFGR` | RCC HSI 校准寄存器 | `0x004` | `0x58024404` | 32 | RW | 0x40000000 / 0xFFFFF000 | HSITRIM[30:24]（HSI 时钟微调）、HSICAL[11:0] (RO)（HSI 时钟校准） | — |
| `RCC_CRRCR` | 时钟恢复用 RC 振荡器配置和状态 | `0x008` | `0x58024408` | 32 | RO | 0x00000000 / 0xFFFFF000 | HSI48CAL[9:0]（待核） | — |
| `RCC_CSICFGR` | RCC CSI 校准寄存器 | `0x00C` | `0x5802440C` | 32 | RW | 0x20000000 / 0xFFFFF000 | CSITRIM[29:24]（CSI 时钟微调）、CSICAL[7:0] (RO)（CSI 时钟校准） | — |
| `RCC_CFGR` | 配置系统时钟选择及相关时钟选项 | `0x010` | `0x58024410` | 32 | RW | 0x00000000 / 0xFFFFFFFF | MCO2SEL[31:29]（待核）、MCO2PRE[28:25]（MCO2 预分频器）、MCO1SEL[24:22]（待核）、MCO1PRE[21:18]（MCO1 预分频器）、TIMPRE[15]（定时器时钟预分频器选择）、RTCPRE[13:8]（HSE 分频系数的 RTC 时钟）、STOPKERWUCK[7]（待核）、STOPWUCK[6]（待核）、SWS[5:3] (RO)（系统时钟切换状态）、SW[2:0]（系统时钟切换） | — |
| `RCC_CDCFGR` | RCC CPU 域时钟配置寄存器 | `0x018` | `0x58024418` | 32 | RW | 0x00000000 / 0xFFFFFFFF | CPRE[3:0]（CPU 域核心预分频器） | — |
| `RCC_BMCFGR` | RCC AHB 时钟配置寄存器 | `0x01C` | `0x5802441C` | 32 | RW | 0x00000000 / 0xFFFFFFFF | BMPRE[3:0]（总线矩阵时钟预分频器） | — |
| `RCC_APBCFGR` | RCC APB 时钟配置寄存器 | `0x020` | `0x58024420` | 32 | RW | 0x00000000 / 0xFFFFFFFF | PPRE5[14:12]（CPU 域 APB5 预分频器）、PPRE4[10:8]（CPU 域 APB4 预分频器）、PPRE2[6:4]（CPU 域 APB2 预分频器）、PPRE1[2:0]（CPU 域 APB1 预分频器） | — |
| `RCC_PLLCKSELR` | 选择 PLL 输入时钟和预分频 | `0x028` | `0x58024428` | 32 | RW | 0x02020200 / 0xFFFFFFFF | DIVM3[25:20]（预分频器的 PLL3）、DIVM2[17:12]（预分频器的 PLL2）、DIVM1[9:4]（预分频器的 PLL1）、PLLSRC[1:0]（待核） | — |
| `RCC_PLLCFGR` | PLL 工作参数和输出配置 | `0x02C` | `0x5802442C` | 32 | RW | 0x00000000 / 0xFFFFFFFF | PLL3SEN[30]（PLL3 DIVS 分频器输出使能）、PLL3REN[29]（PLL3 DIVR 分频器输出使能）、PLL3QEN[28]（PLL3 DIVQ 分频器输出使能）、PLL3PEN[27]（PLL3 DIVP 分频器输出使能）、PLL3RGE[26:25]（PLL3 输入频率范围）、PLL3SSCGEN[24]（PLL3 SSCG 使能）、PLL3VCOSEL[23]（PLL3 VCO 选择）、PLL3FRACEN[22]（待核）、PLL2TEN[20]（PLL2 DIVT 分频器输出使能）、PLL2SEN[19]（PLL2 DIVS 分频器输出使能）、PLL2REN[18]（PLL2 DIVR 分频器输出使能）、PLL2QEN[17]（PLL2 DIVQ 分频器输出使能）、PLL2PEN[16]（PLL2 DIVP 分频器输出使能）、PLL2RGE[15:14]（PLL2 输入频率范围）、PLL2SSCGEN[13]（PLL2 SSCG 使能）、PLL2VCOSEL[12]（PLL2 VCO 选择）、PLL2FRACLEN[11]（待核）、PLL1SEN[8]（PLL1 DIVS 分频器输出使能）、PLL1QEN[6]（PLL1 DIVQ 分频器输出使能）、PLL1PEN[5]（PLL1 DIVP 分频器输出使能）、PLL1RGE[4:3]（PLL1 输入频率范围）、PLL1SSCGEN[2]（PLL1 SSCG 使能）、PLL1VCOSEL[1]（PLL1 VCO 选择）、PLL1FRACEN[0]（待核） | — |
| `RCC_PLL1DIVR1` | RCC PLL1 分频器配置寄存器 1 | `0x030` | `0x58024430` | 32 | RW | 0x01010280 / 0xFFFFFFFF | DIVQ[22:16]（PLL Q 路输出分频系数）、DIVP[15:9]（PLL P 路输出分频系数）、DIVN[8:0]（PLL 倍频系数） | — |
| `RCC_PLL1FRACR` | RCC PLL1 小数分频器寄存器 | `0x034` | `0x58024434` | 32 | RW | 0x00000000 / 0xFFFFFFFF | FRACN[15:3]（PLL 倍频的小数部分） | — |
| `RCC_PLL2DIVR1` | RCC PLL2 分频器配置寄存器 1 | `0x038` | `0x58024438` | 32 | RW | 0x01010280 / 0xFFFFFFFF | DIVR[30:24]（PLL R 路输出分频系数）、DIVQ[22:16]（PLL Q 路输出分频系数）、DIVP[15:9]（PLL P 路输出分频系数）、DIVN[8:0]（PLL 倍频系数） | — |
| `RCC_PLL2FRACR` | RCC PLL2 小数分频器寄存器 | `0x03C` | `0x5802443C` | 32 | RW | 0x00000000 / 0xFFFFFFFF | FRACN[15:3]（PLL 倍频的小数部分） | — |
| `RCC_PLL3DIVR1` | RCC PLL3 分频器配置寄存器 1 | `0x040` | `0x58024440` | 32 | RW | 0x01010280 / 0xFFFFFFFF | DIVR[30:24]（PLL R 路输出分频系数）、DIVQ[22:16]（PLL Q 路输出分频系数）、DIVP[15:9]（PLL P 路输出分频系数）、DIVN[8:0]（PLL 倍频系数） | — |
| `RCC_PLL3FRACR` | RCC PLL3 小数分频器寄存器 | `0x044` | `0x58024444` | 32 | RW | 0x00000000 / 0xFFFFFFFF | FRACN[15:3]（PLL 倍频的小数部分） | — |
| `RCC_CCIPR1` | RCC AHB 外设内核时钟选择寄存器 | `0x04C` | `0x5802444C` | 32 | RW | 0x00000A00 / 0xFFFFFFFF | CKPERSEL[29:28]（per_ck 时钟源选择）、PSSISEL[27]（PSSI 内核时钟源选择）、ADCSEL[25:24]（SAR ADC 内核时钟源选择）、ADF1SEL[22:20]（ADF 内核时钟源选择）、ETH1PHYCKSEL[18]（待核）、ETH1REFCKSEL[17:16]（待核）、OTGFSSEL[15:14]（OTGFS 内核时钟源选择）、USBPHYCSEL[13:12]（USBPHYC 内核时钟源选择）、USBREFCKSEL[11:8]（USBPHYC 内核时钟频率选择）、XSPI2SEL[7:6]（XSPI2 内核时钟源选择）、XSPI1SEL[5:4]（XSPI1 内核时钟源选择）、SDMMC12SEL[2]（SDMMC1 与 SDMMC2 内核时钟源选择）、FMCSEL[1:0]（FMC 内核时钟源选择） | — |
| `RCC_CCIPR2` | RCC APB1 外设内核时钟选择寄存器 | `0x050` | `0x58024450` | 32 | RW | 0x00000000 / 0xFFFFFFFF | CECSEL[29:28]（HDMI-CEC 内核时钟源选择）、SPDIFRXSEL[25:24]（SPDIFRX 内核时钟源选择）、FDCANSEL[23:22]（FDCAN 内核时钟源选择）、LPTIM1SEL[18:16]（LPTIM1 内核时钟源选择）、I2C1_I3C1SEL[13:12]（I2C1 或 I3C1 内核时钟源选择）、I2C23SEL[9:8]（I2C2, I2C3 内核时钟源选择）、SPI23SEL[6:4]（SPI/I2S2 与 SPI/I2S3 内核时钟源选择）、UART234578SEL[2:0]（USART2,3, UART4,5,7,8 (APB1) 内核时钟源选择） | — |
| `RCC_CCIPR3` | RCC APB2 外设内核时钟选择寄存器 | `0x054` | `0x58024454` | 32 | RW | 0x00000000 / 0xFFFFFFFF | SAI2SEL[22:20]（SAI2 内核时钟源选择）、SAI1SEL[18:16]（SAI1 内核时钟源选择）、SPI1SEL[10:8]（SPI/I2S1 内核时钟源选择）、SPI45SEL[6:4]（SPI4 与 5 内核时钟源选择）、USART1SEL[2:0]（USART1 内核时钟源选择） | — |
| `RCC_CCIPR4` | RCC APB4,5 外设内核时钟选择寄存器 | `0x058` | `0x58024458` | 32 | RW | 0x00000000 / 0xFFFFFFFF | LPTIM45SEL[14:12]（LPTIM4, 与 LPTIM5 内核时钟源选择）、LPTIM23SEL[10:8]（LPTIM2 与 LPTIM3 内核时钟源选择）、SPI6SEL[6:4]（SPI/I2S6 内核时钟源选择）、LPUART1SEL[2:0]（LPUART1 内核时钟源选择） | — |
| `RCC_CIER` | 时钟事件中断使能 | `0x060` | `0x58024460` | 32 | RW | 0x00000000 / 0xFFFFFFFF | LSECSSIE[9]（LSE 时钟安全系统中断使能）、PLL3RDYIE[8]（PLL3 就绪中断使能）、PLL2RDYIE[7]（PLL2 就绪中断使能）、PLL1RDYIE[6]（PLL1 就绪中断使能）、HSI48RDYIE[5]（HSI48 就绪中断使能）、CSIRDYIE[4]（CSI 就绪中断使能）、HSERDYIE[3]（HSE 就绪中断使能）、HSIRDYIE[2]（HSI 就绪中断使能）、LSERDYIE[1]（LSE 就绪中断使能）、LSIRDYIE[0]（LSI 就绪中断使能） | — |
| `RCC_CIFR` | 时钟事件中断标志 | `0x064` | `0x58024464` | 32 | RO | 0x00000000 / 0xFFFFFFFF | HSECSSF[10]（HSE 时钟安全系统中断标志）、LSECSSF[9]（LSE 时钟安全系统中断标志）、PLL3RDYF[8]（PLL3 就绪中断标志）、PLL2RDYF[7]（PLL2 就绪中断标志）、PLL1RDYF[6]（PLL1 就绪中断标志）、HSI48RDYF[5]（HSI48 就绪中断标志）、CSIRDYF[4]（CSI 就绪中断标志）、HSERDYF[3]（HSE 就绪中断标志）、HSIRDYF[2]（HSI 就绪中断标志）、LSERDYF[1]（LSE 就绪中断标志）、LSIRDYF[0]（LSI 就绪中断标志） | — |
| `RCC_CICR` | 清除时钟事件中断标志 | `0x068` | `0x58024468` | 32 | RW | 0x00000000 / 0xFFFFFFFF | HSECSSC[10]（HSE 时钟安全系统中断清除）、LSECSSC[9]（LSE 时钟安全系统中断清除）、PLL3RDYC[8]（PLL3 就绪中断清除）、PLL2RDYC[7]（PLL2 就绪中断清除）、PLL1RDYC[6]（PLL1 就绪中断清除）、HSI48RDYC[5]（HSI48 就绪中断清除）、CSIRDYC[4]（CSI 就绪中断清除）、HSERDYC[3]（HSE 就绪中断清除）、HSIRDYC[2]（HSI 就绪中断清除）、LSERDYC[1]（LSE 就绪中断清除）、LSIRDYC[0]（LSI 就绪中断清除） | — |
| `RCC_BDCR` | RCC 备份域控制寄存器 | `0x070` | `0x58024470` | 32 | RW1 | 0x00000010 / 0xFFFFFFFF | VSWRST[16] (RW)（待核）、RTCEN[15] (RW)（RTC 时钟使能）、LSECSSRA[12] (RW)（待核）、RTCSEL[9:8]（RTC 时钟源选择）、LSEEXT[7] (RW)（待核）、LSECSSD[6] (RO)（待核）、LSECSSON[5] (RW)（LSE 时钟安全系统使能）、LSEDRV[4:3] (RW)（待核）、LSEBYP[2] (RW)（待核）、LSERDY[1] (RO)（LSE 振荡器就绪）、LSEON[0] (RW)（LSE 振荡器使能） | — |
| `RCC_CSR` | RCC 时钟控制与状态寄存器 | `0x074` | `0x58024474` | 32 | RW | 0x00000000 / 0xFFFFFFFF | LSIRDY[1] (RO)（LSI 振荡器就绪）、LSION[0]（LSI 振荡器使能） | — |
| `RCC_AHB5RSTR` | AHB5 外设复位控制 | `0x07C` | `0x5802447C` | 32 | RW | 0x00000000 / 0xFFFFFFFF | GPU2DRST[20]（GPU2D 块复位）、GFXMMURST[19]（GFXMMU 块复位）、XSPIMRST[14]（XSPIM 复位）、XSPI2RST[12]（XSPI2 与 MCE2 块复位）、SDMMC1RST[8]（SDMMC1 与 DB_SDMMC1 块复位）、XSPI1RST[5]（XSPI1 与 MCE1 块复位）、FMCRST[4]（FMC 与 MCE3 块复位）、JPEGRST[3]（JPEG 块复位）、DMA2DRST[1]（DMA2D 块复位）、HPDMA1RST[0]（HPDMA1 块复位） | — |
| `RCC_AHB1RSTR` | AHB1 外设复位控制 | `0x080` | `0x58024480` | 32 | RW | 0x00000000 / 0xFFFFFFFF | ADF1RST[31]（ADF 块复位）、OTGFSRST[27]（OTGFS 块复位）、USBPHYCRST[26]（USBPHYC 块复位）、OTGHSRST[25]（OTGHS 块复位）、ETH1RST[15]（ETH1 块复位）、ADC12RST[5]（ADC1 与 2 块复位）、GPDMA1RST[4]（GPDMA1 块复位） | — |
| `RCC_AHB2RSTR` | AHB2 外设复位控制 | `0x084` | `0x58024484` | 32 | RW | 0x00000000 / 0xFFFFFFFF | CORDICRST[14]（CORDIC 复位）、SDMMC2RST[9]（SDMMC2 与 SDMMC2 延迟块复位）、PSSIRST[1]（PSSI 块复位） | — |
| `RCC_AHB4RSTR` | AHB4 外设复位控制 | `0x088` | `0x58024488` | 32 | RW | 0x00000000 / 0xFFFFFFFF | CRCRST[19]（CRC 块复位）、GPIOPRST[15]（GPIOP 端口复位）、GPIOORST[14]（GPIOO 端口复位）、GPIONRST[13]（GPION 端口复位）、GPIOMRST[12]（GPIOM 端口复位）、GPIOHRST[7]（GPIOH 端口复位）、GPIOGRST[6]（GPIOG 端口复位）、GPIOFRST[5]（GPIOF 端口复位）、GPIOERST[4]（GPIOE 端口复位）、GPIODRST[3]（GPIOD 端口复位）、GPIOCRST[2]（GPIOC 端口复位）、GPIOBRST[1]（GPIOB 端口复位）、GPIOARST[0]（GPIOA 端口复位） | — |
| `RCC_APB5RSTR` | APB5 外设复位控制 | `0x08C` | `0x5802448C` | 32 | RW | 0x00000000 / 0xFFFFFFFF | GFXTIMRST[4]（GFXTIM 块复位）、DCMIPPRST[2]（DCMIPP 块复位）、LTDCRST[1]（LTDC 块复位） | — |
| `RCC_APB1RSTR1` | RCC APB1 外设复位寄存器 1 | `0x090` | `0x58024490` | 32 | RW | 0x00000000 / 0xFFFFFFFF | UART8RST[31]（UART8 块复位）、UART7RST[30]（UART7 块复位）、CECRST[27]（HDMI-CEC 块复位）、I2C3RST[23]（I2C3 块复位）、I2C2RST[22]（I2C2 块复位）、I2C1_I3C1RST[21]（I2C1/I3C1 块复位）、UART5RST[20]（UART5 块复位）、UART4RST[19]（UART4 块复位）、USART3RST[18]（USART3 块复位）、USART2RST[17]（USART2 块复位）、SPDIFRXRST[16]（SPDIFRX 块复位）、SPI3RST[15]（SPI2S3 块复位）、SPI2RST[14]（SPI2S2 块复位）、LPTIM1RST[9]（LPTIM1 块复位）、TIM14RST[8]（TIM14 块复位）、TIM13RST[7]（TIM13 块复位）、TIM12RST[6]（TIM12 块复位）、TIM7RST[5]（TIM7 块复位）、TIM6RST[4]（TIM6 块复位）、TIM5RST[3]（TIM5 块复位）、TIM4RST[2]（TIM4 块复位）、TIM3RST[1]（TIM3 块复位）、TIM2RST[0]（TIM2 块复位） | — |
| `RCC_APB1RSTR2` | RCC APB1 外设复位寄存器 2 | `0x094` | `0x58024494` | 32 | RW | 0x00000000 / 0xFFFFFFFF | UCPD1RST[27]（UCPD 块复位）、FDCANRST[8]（FDCAN 块复位）、MDIOSRST[5]（MDIOS 块复位）、CRSRST[1]（时钟恢复系统复位） | — |
| `RCC_APB2RSTR` | APB2 外设复位控制 | `0x098` | `0x58024498` | 32 | RW | 0x00000000 / 0xFFFFFFFF | SAI2RST[23]（SAI2 块复位）、SAI1RST[22]（SAI1 块复位）、SPI5RST[20]（SPI5 块复位）、TIM9RST[19]（TIM9 块复位）、TIM17RST[18]（TIM17 块复位）、TIM16RST[17]（TIM16 块复位）、TIM15RST[16]（TIM15 块复位）、SPI4RST[13]（SPI4 块复位）、SPI1RST[12]（SPI2S1 块复位）、USART1RST[4]（USART1 块复位）、TIM1RST[0]（TIM1 块复位） | — |
| `RCC_APB4RSTR` | APB4 外设复位控制 | `0x09C` | `0x5802449C` | 32 | RW | 0x00000000 / 0xFFFFFFFF | DTSRST[26]（DTS 块复位）、VREFRST[15]（VREF 块复位）、LPTIM5RST[12]（LPTIM5 块复位）、LPTIM4RST[11]（LPTIM4 块复位）、LPTIM3RST[10]（LPTIM3 块复位）、LPTIM2RST[9]（LPTIM2 块复位）、SPI6RST[5]（SPI/I2S6 块复位）、LPUART1RST[3]（LPUART1 块复位）、SBSRST[1]（SBS 块复位） | — |
| `RCC_AHB3RSTR` | AHB3 外设复位控制 | `0x0A4` | `0x580244A4` | 32 | RW | 0x00000000 / 0xFFFFFFFF | PKARST[6]（PKA 块复位）、SAESRST[4]（SAES 块复位）、CRYPRST[2]（CRYP 块复位）、HASHRST[1]（哈希块复位）、RNGRST[0]（随机编号发生器块复位） | — |
| `RCC_CKGDISR` | 禁止指定 AXI 时钟门控 | `0x0B0` | `0x580244B0` | 32 | RW | 0x80000000 / 0xFFFFFFFF | JTAGCKG[31]（待核）、EXTICKG[30]（EXTI 时钟门控禁用）、FLASHCKG[21]（AXI 从设备闪存接口 (FLIFT) 时钟门控禁用）、AXISRAM1CKG[20]（AXI 从设备 SRAM1 / 错误编码纠正 (ECC) 时钟门控禁用）、AXISRAM2CKG[19]（AXI 从设备 SRAM2 时钟门控禁用）、AXISRAM3CKG[18]（AXI 矩阵从设备 SRAM3 时钟门控禁用）、AXISRAM4CKG[17]（AXI 矩阵从设备 SRAM4 时钟门控禁用）、XSPI2CKG[16]（AXI 从设备 XSPI2 与 MCE2 时钟门控禁用）、XSPI1CKG[15]（AXI 从设备 XSPI1 与 MCE1 时钟门控禁用）、FMCCKG[14]（AXI 从设备 FMC 与 MCE3 时钟门控禁用）、AHBSCKG[13]（AXI 从设备 AHB 时钟门控禁用）、GFXMMUMCKG[12]（AXI 主设备 GFXMMU 时钟门控禁用）、LTDCCKG[11]（AXI 主设备 LTDC 时钟门控禁用）、GFXMMUSCKG[10]（AXI 矩阵从设备 GFXMMU 时钟门控禁用）、DMA2DCKG[9]（AXI 主设备 DMA2D 时钟门控禁用）、DCMIPPCKG[8]（AXI 主设备 DCMIPP 时钟门控禁用）、GPU2DCLCKG[7]（AXI 主设备缓存 GPU2D 时钟门控禁用）、GPU2DS1CKG[6]（AXI 主设备 1 GPU2D 时钟门控禁用）、GPU2DS0CKG[5]（AXI 主设备 0 GPU2D 时钟门控禁用）、CPUCKG[4]（AXI 主设备 CPU 时钟门控禁用）、HPDMA1CKG[3]（AXI 主设备 HPDMA1 时钟门控禁用）、SDMMC1CKG[2]（AXI 主设备 SDMMC1 时钟门控禁用）、AHBMCKG[1]（AXI 主设备 AHB 时钟门控禁用）、AXICKG[0]（待核） | — |
| `RCC_PLL1DIVR2` | RCC PLL1 分频器配置寄存器 2 | `0x0C0` | `0x580244C0` | 32 | RW | 0x00000101 / 0xFFFFFFFF | DIVS[2:0]（PLL S 路输出分频系数） | — |
| `RCC_PLL2DIVR2` | RCC PLL2 分频器配置寄存器 2 | `0x0C4` | `0x580244C4` | 32 | RW | 0x00000101 / 0xFFFFFFFF | DIVT[10:8]（PLL2 DIVT 分频系数）、DIVS[2:0]（PLL S 路输出分频系数） | — |
| `RCC_PLL3DIVR2` | RCC PLL3 分频器配置寄存器 2 | `0x0C8` | `0x580244C8` | 32 | RW | 0x00000101 / 0xFFFFFFFF | DIVS[2:0]（PLL S 路输出分频系数） | — |
| `RCC_PLL1SSCGR` | RCC PLL1 扩频时钟发生器寄存器 | `0x0CC` | `0x580244CC` | 32 | RW | 0x00000000 / 0xFFFFFFFF | INCSTEP[30:16]（扩频调制增量）、SPREADSEL[15]（扩频调制模式选择）、RPDFNDIS[14]（待核）、TPDFNDIS[13]（待核）、MODPER[12:0]（扩频调制周期） | — |
| `RCC_PLL2SSCGR` | RCC PLL2 扩频时钟发生器寄存器 | `0x0D0` | `0x580244D0` | 32 | RW | 0x00000000 / 0xFFFFFFFF | INCSTEP[30:16]（扩频调制增量）、SPREADSEL[15]（扩频调制模式选择）、RPDFNDIS[14]（待核）、TPDFNDIS[13]（待核）、MODPER[12:0]（扩频调制周期） | — |
| `RCC_PLL3SSCGR` | RCC PLL3 扩频时钟发生器寄存器 | `0x0D4` | `0x580244D4` | 32 | RW | 0x00000000 / 0xFFFFFFFF | INCSTEP[30:16]（扩频调制增量）、SPREADSEL[15]（扩频调制模式选择）、RPDFNDIS[14]（待核）、TPDFNDIS[13]（待核）、MODPER[12:0]（扩频调制周期） | — |
| `RCC_CKPROTR` | RCC 时钟保护寄存器 | `0x100` | `0x58024500` | 32 | RW | 0x00000000 / 0xFFFFFFFF | FMCSWP[14:12] (RO)（FMC 内核时钟切换位置）、XSPI2SWP[10:8] (RO)（XSPI2 内核时钟切换位置）、XSPI1SWP[6:4] (RO)（XSPI1 内核时钟切换位置）、FMCCKP[1]（FMC 时钟保护）、XSPICKP[0]（XSPI 时钟保护） | — |
| `RCC_RSR` | RCC 复位状态寄存器 | `0x130` | `0x58024530` | 32 | RW | 0x00E00000 / 0xFFFFFFFF | LPWRRSTF[30] (RO)（待核）、WWDGRSTF[28] (RO)（待核）、IWDGRSTF[26] (RO)（待核）、SFTRSTF[24] (RO)（待核）、PORRSTF[23] (RO)（待核）、PINRSTF[22] (RO)（待核）、BORRSTF[21] (RO)（待核）、OBLRSTF[17] (RO)（待核）、RMVF[16]（待核） | — |
| `RCC_AHB5ENR` | AHB5 外设时钟使能 | `0x134` | `0x58024534` | 32 | RW | 0x00000000 / 0xFFFFFFFF | GPU2DEN[20]（GPU2D 外设时钟使能）、GFXMMUEN[19]（GFXMMU 外设时钟使能）、XSPIMEN[14]（XSPIM 外设时钟使能）、XSPI2EN[12]（XSPI2 与 MCE2 外设时钟使能）、SDMMC1EN[8]（SDMMC1 与 DB_SDMMC1 外设时钟使能）、XSPI1EN[5]（XSPI1 与 MCE1 外设时钟使能）、FMCEN[4]（FMC 与 MCE3 外设时钟使能）、JPEGEN[3]（JPEG 外设时钟使能）、DMA2DEN[1]（DMA2D 外设时钟使能）、HPDMA1EN[0]（HPDMA1 外设时钟使能） | — |
| `RCC_AHB1ENR` | AHB1 外设时钟使能 | `0x138` | `0x58024538` | 32 | RW | 0x00000000 / 0xFFFFFFFF | ADF1EN[31]（ADF 时钟使能）、OTGFSEN[27]（OTGFS 外设时钟使能）、USBPHYCEN[26]（USBPHYC 时钟使能）、OTGHSEN[25]（OTGHS 时钟使能）、ETH1RXEN[17]（ETH1 接收时钟使能）、ETH1TXEN[16]（ETH1 发送时钟使能）、ETH1MACEN[15]（ETH1 MAC 外设时钟使能）、ADC12EN[5]（ADC1 与 2 外设时钟使能）、GPDMA1EN[4]（GPDMA1 时钟使能） | — |
| `RCC_AHB2ENR` | AHB2 外设时钟使能 | `0x13C` | `0x5802453C` | 32 | RW | 0x00000000 / 0xFFFFFFFF | SRAM2EN[30]（SRAM2 时钟使能）、SRAM1EN[29]（SRAM1 时钟使能）、CORDICEN[14]（CORDIC 时钟使能）、SDMMC2EN[9]（SDMMC2 与 SDMMC2 延迟时钟使能）、PSSIEN[1]（PSSI 外设时钟使能） | — |
| `RCC_AHB4ENR` | AHB4 外设时钟使能 | `0x140` | `0x58024540` | 32 | RW | 0x00000000 / 0xFFFFFFFF | BKPRAMEN[28]（备份 RAM 时钟使能）、CRCEN[19]（CRC 时钟使能）、GPIOPEN[15]（GPIOP 端口时钟使能）、GPIOOEN[14]（GPIOO 端口时钟使能）、GPIONEN[13]（GPION 端口时钟使能）、GPIOMEN[12]（GPIOM 端口时钟使能）、GPIOHEN[7]（GPIOH 端口时钟使能）、GPIOGEN[6]（GPIOG 端口时钟使能）、GPIOFEN[5]（GPIOF 端口时钟使能）、GPIOEEN[4]（GPIOE 端口时钟使能）、GPIODEN[3]（GPIOD 端口时钟使能）、GPIOCEN[2]（GPIOC 端口时钟使能）、GPIOBEN[1]（GPIOB 端口时钟使能）、GPIOAEN[0]（GPIOA 端口时钟使能） | — |
| `RCC_APB5ENR` | APB5 外设时钟使能 | `0x144` | `0x58024544` | 32 | RW | 0x00000000 / 0xFFFFFFFF | GFXTIMEN[4]（GFXTIM 外设时钟使能）、DCMIPPEN[2]（DCMIPP 外设时钟使能）、LTDCEN[1]（LTDC 外设时钟使能） | — |
| `RCC_APB1ENR1` | RCC APB1 时钟使能寄存器 1 | `0x148` | `0x58024548` | 32 | RW | 0x00000000 / 0xFFFFFFFF | UART8EN[31]（UART8 外设时钟使能）、UART7EN[30]（UART7 外设时钟使能）、CECEN[27]（HDMI-CEC 外设时钟使能）、I2C3EN[23]（I2C3 外设时钟使能）、I2C2EN[22]（I2C2 外设时钟使能）、I2C1_I3C1EN[21]（I2C1/I3C1 外设时钟使能）、UART5EN[20]（UART5 外设时钟使能）、UART4EN[19]（UART4 外设时钟使能）、USART3EN[18]（USART3 外设时钟使能）、USART2EN[17]（USART2peripheral 时钟使能）、SPDIFRXEN[16]（SPDIFRX 外设时钟使能）、SPI3EN[15]（SPI3 外设时钟使能）、SPI2EN[14]（SPI2 外设时钟使能）、WWDGEN[11]（WWDG 时钟使能）、LPTIM1EN[9]（LPTIM1 外设时钟使能）、TIM14EN[8]（TIM14 外设时钟使能）、TIM13EN[7]（TIM13 外设时钟使能）、TIM12EN[6]（TIM12 外设时钟使能）、TIM7EN[5]（TIM7 外设时钟使能）、TIM6EN[4]（TIM6 外设时钟使能）、TIM5EN[3]（TIM5 外设时钟使能）、TIM4EN[2]（TIM4 外设时钟使能）、TIM3EN[1]（TIM3 外设时钟使能）、TIM2EN[0]（TIM2 外设时钟使能） | — |
| `RCC_APB1ENR2` | RCC APB1 时钟使能寄存器 2 | `0x14C` | `0x5802454C` | 32 | RW | 0x00000000 / 0xFFFFFFFF | UCPD1EN[27]（UCPD 外设时钟使能）、FDCANEN[8]（FDCAN 外设时钟使能）、MDIOSEN[5]（MDIOS 外设时钟使能）、CRSEN[1]（时钟恢复系统外设时钟使能） | — |
| `RCC_APB2ENR` | APB2 外设时钟使能 | `0x150` | `0x58024550` | 32 | RW | 0x00000000 / 0xFFFFFFFF | SAI2EN[23]（SAI2 外设时钟使能）、SAI1EN[22]（SAI1 外设时钟使能）、SPI5EN[20]（SPI5 外设时钟使能）、TIM9EN[19]（TIM9 外设时钟使能）、TIM17EN[18]（TIM17 外设时钟使能）、TIM16EN[17]（TIM16 外设时钟使能）、TIM15EN[16]（TIM15 外设时钟使能）、SPI4EN[13]（SPI4 外设时钟使能）、SPI1EN[12]（SPI2S1 外设时钟使能）、USART1EN[4]（USART1 外设时钟使能）、TIM1EN[0]（TIM1 外设时钟使能） | — |
| `RCC_APB4ENR` | APB4 外设时钟使能 | `0x154` | `0x58024554` | 32 | RW | 0x00010000 / 0xFFFFFFFF | DTSEN[26]（温度传感器外设时钟使能）、RTCAPBEN[16]（RTC APB 时钟使能）、VREFEN[15]（VREF 外设时钟使能）、LPTIM5EN[12]（LPTIM5 外设时钟使能）、LPTIM4EN[11]（LPTIM4 外设时钟使能）、LPTIM3EN[10]（LPTIM3 外设时钟使能）、LPTIM2EN[9]（LPTIM2 外设时钟使能）、SPI6EN[5]（SPI/I2S6 外设时钟使能）、LPUART1EN[3]（LPUART1 外设时钟使能）、SBSEN[1]（SBS 外设时钟使能） | — |
| `RCC_AHB3ENR` | AHB3 外设时钟使能 | `0x158` | `0x58024558` | 32 | RW | 0x00000000 / 0xFFFFFFFF | PKAEN[6]（PKA 外设时钟使能）、SAESEN[4]（SAES 外设时钟使能）、CRYPEN[2]（CRYP 外设时钟使能）、HASHEN[1]（哈希外设时钟使能）、RNGEN[0]（RNG 外设时钟使能） | — |
| `RCC_AHB5LPENR` | AHB5 外设低功耗时钟使能 | `0x15C` | `0x5802455C` | 32 | RW | 0xF018513F / 0xFFFFFFFF | AXISRAMLPEN[31]（AXISRAM[4:1] 低位-电源外设时钟使能）、ITCMLPEN[30]（ITCM 低位-电源外设时钟使能）、DTCM2LPEN[29]（DTCM2 低位-电源外设时钟使能）、DTCM1LPEN[28]（DTCM1 低位-电源外设时钟使能）、GPU2DLPEN[20]（GPU2D 低位-电源外设时钟使能）、GFXMMULPEN[19]（GFXMMU 低位-电源外设时钟使能）、XSPIMLPEN[14]（XSPIM 低位-电源外设时钟使能）、XSPI2LPEN[12]（XSPI2 与 MCE2 低位-电源外设时钟使能）、SDMMC1LPEN[8]（SDMMC1 与 SDMMC1 延迟低位-电源外设时钟使能）、XSPI1LPEN[5]（XSPI1 与 MCE1 低位-电源外设时钟使能）、FMCLPEN[4]（FMC 与 MCE3 外设时钟使能内低位-电源模式）、JPEGLPEN[3]（JPEG 时钟使能内低位-电源模式）、FLASHLPEN[2]（闪存低位-电源外设时钟使能）、DMA2DLPEN[1]（DMA2D 低位-电源外设时钟使能）、HPDMA1LPEN[0]（HPDMA1 低位-电源外设时钟使能） | — |
| `RCC_AHB1LPENR` | AHB1 外设低功耗时钟使能 | `0x160` | `0x58024560` | 32 | RW | 0x8E038030 / 0xFFFFFFFF | ADF1LPEN[31]（ADF 时钟使能内低位-电源模式）、OTGFSLPEN[27]（OTGFS 时钟使能内低位-电源模式）、USBPHYCLPEN[26]（USBPHYC 外设时钟使能内低位-电源模式）、OTGHSLPEN[25]（OTGHS 外设时钟使能内低位-电源模式）、UCPDCTRL[24]（待核）、ETH1RXLPEN[17]（ETH1 接收外设时钟使能内低位-电源模式）、ETH1TXLPEN[16]（ETH1 发送外设时钟使能内低位-电源模式）、ETH1MACLPEN[15]（ETH1 MAC 外设时钟使能内低位-电源模式）、ADC12LPEN[5]（ADC1 与 2 外设时钟使能内低位-电源模式）、GPDMA1LPEN[4]（GPDMA1 时钟使能内低位-电源模式） | — |
| `RCC_AHB2LPENR` | AHB2 外设低功耗时钟使能 | `0x164` | `0x58024564` | 32 | RW | 0x60004202 / 0xFFFFFFFF | SRAM2LPEN[30]（SRAM2 时钟使能内低位-电源模式）、SRAM1LPEN[29]（SRAM1 时钟使能内低位-电源模式）、CORDICLPEN[14]（CORDIC 时钟使能内低位-电源模式）、SDMMC2LPEN[9]（SDMMC2 与 SDMMC2 延迟时钟使能内低位-电源模式）、PSSILPEN[1]（PSSI 外设时钟使能内低位-电源模式） | — |
| `RCC_AHB4LPENR` | AHB4 外设低功耗时钟使能 | `0x168` | `0x58024568` | 32 | RW | 0x1008F0FF / 0xFFFFFFFF | BKPRAMLPEN[28]（备份 RAM 时钟使能内低位-电源模式）、CRCLPEN[19]（CRC 时钟使能内低位-电源模式）、GPIOPLPEN[15]（GPIOP 外设时钟使能内低位-电源模式）、GPIOOLPEN[14]（GPIOO 外设时钟使能内低位-电源模式）、GPIONLPEN[13]（GPION 外设时钟使能内低位-电源模式）、GPIOMLPEN[12]（GPIOM 外设时钟使能内低位-电源模式）、GPIOHLPEN[7]（GPIOH 外设时钟使能内低位-电源模式）、GPIOGLPEN[6]（GPIOG 外设时钟使能内低位-电源模式）、GPIOFLPEN[5]（GPIOF 外设时钟使能内低位-电源模式）、GPIOELPEN[4]（GPIOE 外设时钟使能内低位-电源模式）、GPIODLPEN[3]（GPIOD 外设时钟使能内低位-电源模式）、GPIOCLPEN[2]（GPIOC 外设时钟使能内低位-电源模式）、GPIOBLPEN[1]（GPIOB 外设时钟使能内低位-电源模式）、GPIOALPEN[0]（GPIOA 外设时钟使能内低位-电源模式） | — |
| `RCC_AHB3LPENR` | AHB3 外设低功耗时钟使能 | `0x16C` | `0x5802456C` | 32 | RW | 0x00000057 / 0xFFFFFFFF | PKALPEN[6]（PKA 外设时钟使能内低位-电源模式）、SAESLPEN[4]（SAES 外设时钟使能内低位-电源模式）、CRYPLPEN[2]（CRYP 外设时钟使能内低位-电源模式）、HASHLPEN[1]（哈希外设时钟使能内低位-电源模式）、RNGLPEN[0]（RNG 外设时钟使能内低位-电源模式） | — |
| `RCC_APB1LPENR1` | RCC APB1 低位-电源时钟使能寄存器 1 | `0x170` | `0x58024570` | 32 | RW | 0xC8FFCBFF / 0xFFFFFFFF | UART8LPEN[31]（UART8 外设时钟使能内低位-电源模式）、UART7LPEN[30]（UART7 外设时钟使能内低位-电源模式）、CECLPEN[27]（HDMI-CEC 外设时钟使能内低位-电源模式）、I2C3LPEN[23]（I2C3 外设时钟使能内低位-电源模式）、I2C2LPEN[22]（I2C2 外设时钟使能内低位-电源模式）、I2C1_I3C1LPEN[21]（I2C1/I3C1 外设时钟使能内低位-电源模式）、UART5LPEN[20]（UART5 外设时钟使能内低位-电源模式）、UART4LPEN[19]（UART4 外设时钟使能内低位-电源模式）、USART3LPEN[18]（USART3 外设时钟使能内低位-电源模式）、USART2LPEN[17]（USART2 外设时钟使能内低位-电源模式）、SPDIFRXLPEN[16]（SPDIFRX 外设时钟使能内低位-电源模式）、SPI3LPEN[15]（SPI3 外设时钟使能内低位-电源模式）、SPI2LPEN[14]（SPI2 外设时钟使能内低位-电源模式）、WWDGLPEN[11]（WWDG 时钟使能内低位-电源模式）、LPTIM1LPEN[9]（LPTIM1 外设时钟使能内低位-电源模式）、TIM14LPEN[8]（TIM14 外设时钟使能内低位-电源模式）、TIM13LPEN[7]（TIM13 外设时钟使能内低位-电源模式）、TIM12LPEN[6]（TIM12 外设时钟使能内低位-电源模式）、TIM7LPEN[5]（TIM7 外设时钟使能内低位-电源模式）、TIM6LPEN[4]（TIM6 外设时钟使能内低位-电源模式）、TIM5LPEN[3]（TIM5 外设时钟使能内低位-电源模式）、TIM4LPEN[2]（TIM4 外设时钟使能内低位-电源模式）、TIM3LPEN[1]（TIM3 外设时钟使能内低位-电源模式）、TIM2LPEN[0]（TIM2 外设时钟使能内低位-电源模式） | — |
| `RCC_APB1LPENR2` | RCC APB1 低位-电源时钟使能寄存器 2 | `0x174` | `0x58024574` | 32 | RW | 0x08000122 / 0xFFFFFFFF | UCPD1LPEN[27]（UCPD 外设时钟使能内低位-电源模式）、FDCANLPEN[8]（FDCAN 外设时钟使能内低位-电源模式）、MDIOSLPEN[5]（MDIOS 外设时钟使能内低位-电源模式）、CRSLPEN[1]（时钟恢复系统外设时钟使能内低位-电源模式） | — |
| `RCC_APB2LPENR` | APB2 外设低功耗时钟使能 | `0x178` | `0x58024578` | 32 | RW | 0x00DF3011 / 0xFFFFFFFF | SAI2LPEN[23]（SAI2 外设时钟使能内低位-电源模式）、SAI1LPEN[22]（SAI1 外设时钟使能内低位-电源模式）、SPI5LPEN[20]（SPI5 外设时钟使能内低位-电源模式）、TIM9LPEN[19]（TIM9 外设时钟使能内低位-电源模式）、TIM17LPEN[18]（TIM17 外设时钟使能内低位-电源模式）、TIM16LPEN[17]（TIM16 外设时钟使能内低位-电源模式）、TIM15LPEN[16]（TIM15 外设时钟使能内低位-电源模式）、SPI4LPEN[13]（SPI4 外设时钟使能内低位-电源模式）、SPI1LPEN[12]（SPI2S1 外设时钟使能内低位-电源模式）、USART1LPEN[4]（USART1 外设时钟使能内低位-电源模式）、TIM1LPEN[0]（TIM1 外设时钟使能内低位-电源模式） | — |
| `RCC_APB4LPENR` | APB4 外设低功耗时钟使能 | `0x17C` | `0x5802457C` | 32 | RW | 0x04019E2A / 0xFFFFFFFF | DTSLPEN[26]（温度传感器外设时钟使能内低位-电源模式）、RTCAPBLPEN[16]（RTC APB 时钟使能内低位-电源模式）、VREFLPEN[15]（VREF 外设时钟使能内低位-电源模式）、LPTIM5LPEN[12]（LPTIM5 外设时钟使能内低位-电源模式）、LPTIM4LPEN[11]（LPTIM4 外设时钟使能内低位-电源模式）、LPTIM3LPEN[10]（LPTIM3 外设时钟使能内低位-电源模式）、LPTIM2LPEN[9]（LPTIM2 外设时钟使能内低位-电源模式）、SPI6LPEN[5]（SPI/I2S6 外设时钟使能内低位-电源模式）、LPUART1LPEN[3]（LPUART1 外设时钟使能内低位-电源模式）、SBSLPEN[1]（SBS 外设时钟使能内低位-电源模式） | — |
| `RCC_APB5LPENR` | APB5 外设低功耗时钟使能 | `0x180` | `0x58024580` | 32 | RW | 0x00000016 / 0xFFFFFFFF | GFXTIMLPEN[4]（GFXTIM 外设时钟使能内低位-电源模式）、DCMIPPLPEN[2]（DCMIPP 外设时钟使能内低位-电源模式）、LTDCLPEN[1]（LTDC 外设时钟使能内低位-电源模式） | — |

## SBS

**模块用途**　系统配置模块，集中管理启动、系统互连、外部中断引脚选择以及部分外设选项。

基地址 `0x58000400` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `SBS_BOOTSR` | SBS 启动状态寄存器 | `0x000` | `0x58000400` | 32 | — | 0x00000000 / 0xFFFFFFFF | INITVTOR[31:0] (RO)（待核） | — |
| `SBS_HDPLCR` | SBS 隐藏保护控制寄存器 | `0x010` | `0x58000410` | 32 | — | 0x000000B4 / 0xFFFFFFFF | INCR_HDPL[7:0] (RW)（增量 HDPL） | — |
| `SBS_HDPLSR` | SBS 隐藏保护状态寄存器 | `0x014` | `0x58000414` | 32 | — | 0x00000000 / 0xFFFFFF00 | HDPL[7:0] (RO)（隐藏保护电平） | — |
| `SBS_DBGCR` | SBS 调试控制寄存器 | `0x020` | `0x58000420` | 32 | — | 0x00000000 / 0xFFFFFFFF | DBG_AUTH_HDPL[23:16] (RW)（待核）、DBG_UNLOCK[15:8] (RW)（调试解锁）、AP_UNLOCK[7:0] (RW)（访问端口解锁） | — |
| `SBS_DBGLOCKR` | SBS 调试锁定寄存器 | `0x024` | `0x58000424` | 32 | — | 0x000000B4 / 0xFFFFFFFF | DBGCFG_LOCK[7:0] (RW)（调试配置锁定） | — |
| `SBS_RSSCMDR` | SBS RSS 命令寄存器 | `0x034` | `0x58000434` | 32 | — | 0x00000000 / 0xFFFFFFFF | RSSCMD[15:0] (RW)（RSS 命令） | — |
| `SBS_PMCR` | SBS 产品模式与配置寄存器 | `0x100` | `0x58000500` | 32 | — | 0x00000000 / 0xFFFFFFFF | AXIRAM_WS[28] (RW)（待核）、ETH_PHYSEL[23:21] (RW)（待核）、BOOSTVDDSEL[9] (RW)（待核）、BOOSTEN[8] (RW)（待核）、FMPLUS_PB9[7] (RW)（待核）、FMPLUS_PB8[6] (RW)（待核）、FMPLUS_PB7[5] (RW)（待核）、FMPLUS_PB6[4] (RW)（待核） | — |
| `SBS_FPUIMR` | SBS FPU 中断屏蔽寄存器 | `0x104` | `0x58000504` | 32 | — | 0x0000001F / 0xFFFFFFFF | FPU_IE[5:0] (RW)（FPU 中断使能） | — |
| `SBS_MESR` | SBS 存储器擦除状态寄存器 | `0x108` | `0x58000508` | 32 | — | 0x00000000 / 0xFFFFFFFF | MEF[0] (RO)（存储器擦除标志） | — |
| `SBS_CCCSR` | SBS I/O 补偿单元控制与状态寄存器 | `0x110` | `0x58000510` | 32 | — | 0x00000000 / 0xFFFFFFFF | OCTO2_IOHSLV[18] (RW)（待核）、OCTO1_IOHSLV[17] (RW)（待核）、IOHSLV[16] (RW)（待核）、OCTO2_COMP_RDY[10] (RO)（XSPIM_P2 补偿单元就绪）、OCTO1_COMP_RDY[9] (RO)（XSPIM_P1 补偿单元就绪）、COMP_RDY[8] (RO)（补偿单元就绪）、OCTO2_COMP_CODESEL[5] (RO)（XSPIM_P2 补偿单元编码选择）、OCTO2_COMP_EN[4] (RO)（XSPIM_P2 补偿单元使能）、OCTO1_COMP_CODESEL[3] (RW)（XSPIM_P1 补偿单元编码选择）、OCTO1_COMP_EN[2] (RW)（XSPIM_P1 补偿单元使能）、COMP_CODESEL[1] (RW)（补偿单元编码选择）、COMP_EN[0] (RW)（补偿单元使能） | — |
| `SBS_CCVALR` | 读取 I/O 补偿单元的值 | `0x114` | `0x58000514` | 32 | — | 0x00000088 / 0xFFFFFFFF | OCTO2_PSRC[23:20] (RO)（待核）、OCTO2_NSRC[19:16] (RO)（待核）、OCTO1_PSRC[15:12] (RO)（待核）、OCTO1_NSRC[11:8] (RO)（待核）、PSRC[7:4] (RO)（待核）、NSRC[3:0] (RO)（待核） | — |
| `SBS_CCSWVALR` | 设置 I/O 补偿单元的软件值 | `0x118` | `0x58000518` | 32 | — | 0x00000088 / 0xFFFFFFFF | OCTO2_SW_PSRC[23:20] (RW)（待核）、OCTO2_SW_NSRC[19:16] (RW)（待核）、OCTO1_SW_PSRC[15:12] (RW)（待核）、OCTO1_SW_NSRC[11:8] (RW)（待核）、SW_PSRC[7:4] (RW)（待核）、SW_NSRC[3:0] (RW)（待核） | — |
| `SBS_BKLOCKR` | SBS 刹车锁死寄存器 | `0x120` | `0x58000520` | 32 | — | 0x00000088 / 0xFFFFFFFF | ARAM1ECC_BL[23] (RW)（AXIRAM1 ECC 错误刹车锁定）、ARAM3ECC_BL[21] (RW)（AXIRAM3 ECC 错误刹车锁定）、ITCMECC_BL[14] (RW)（ITCM ECC 错误刹车锁定）、DTCMECC_BL[13] (RW)（DTCM ECC 错误刹车锁定）、BKRAMECC_BL[7] (RW)（备份 RAM ECC 错误刹车锁定）、CM7LCKUP_BL[6] (RW)（待核）、FLASHECC_BL[3] (RW)（闪存 ECC 错误刹车锁定）、PVD_BL[2] (RW)（PVD 刹车锁定） | — |
| `SBS_EXTICR0` | SBS 外部中断配置寄存器 0 | `0x130` | `0x58000530` | 32 | — | 0x00000000 / 0xFFFFFFFF | PC_EXTI3[15:12] (RO)（端口配置 EXTI {0 * 4 + i}）、PC_EXTI2[11:8] (RO)（端口配置 EXTI {0 * 4 + i}）、PC_EXTI1[7:4] (RO)（端口配置 EXTI {0 * 4 + i}）、PC_EXTI0[3:0] (RO)（端口配置 EXTI {0 * 4 + i}） | — |
| `SBS_EXTICR1` | SBS 外部中断配置寄存器 1 | `0x134` | `0x58000534` | 32 | — | 0x00000000 / 0xFFFFFFFF | PC_EXTI7[15:12] (RO)（端口配置 EXTI {1 * 4 + i}）、PC_EXTI6[11:8] (RO)（端口配置 EXTI {1 * 4 + i}）、PC_EXTI5[7:4] (RO)（端口配置 EXTI {1 * 4 + i}）、PC_EXTI4[3:0] (RO)（端口配置 EXTI {1 * 4 + i}） | — |
| `SBS_EXTICR2` | SBS 外部中断配置寄存器 2 | `0x138` | `0x58000538` | 32 | — | 0x00000000 / 0xFFFFFFFF | PC_EXTI11[15:12] (RO)（端口配置 EXTI {2 * 4 + i}）、PC_EXTI10[11:8] (RO)（端口配置 EXTI {2 * 4 + i}）、PC_EXTI9[7:4] (RO)（端口配置 EXTI {2 * 4 + i}）、PC_EXTI8[3:0] (RO)（端口配置 EXTI {2 * 4 + i}） | — |
| `SBS_EXTICR3` | SBS 外部中断配置寄存器 3 | `0x13C` | `0x5800053C` | 32 | — | 0x00000000 / 0xFFFFFFFF | PC_EXTI15[15:12] (RO)（端口配置 EXTI {3 * 4 + i}）、PC_EXTI14[11:8] (RO)（端口配置 EXTI {3 * 4 + i}）、PC_EXTI13[7:4] (RO)（端口配置 EXTI {3 * 4 + i}）、PC_EXTI12[3:0] (RO)（端口配置 EXTI {3 * 4 + i}） | — |
