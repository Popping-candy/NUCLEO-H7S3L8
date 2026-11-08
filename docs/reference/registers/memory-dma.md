# 存储、缓存与 DMA寄存器

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
| [DLYB1](#dlyb1) | `0x52008000` | 2 | SVD |
| [DLYB2](#dlyb2) | `0x48002800` | 2 | SVD，继承 DLYB1 |
| [FLASH](#flash) | `0x52002000` | 43 | SVD |
| [FMC](#fmc) | `0x52004000` | 24 | SVD |
| [FMC_Bank1E_R](#fmc_bank1e_r) | `0x52004104` | 3 | CMSIS 补表 |
| [GPDMA](#gpdma) | `0x40021000` | 171 | SVD |
| [HPDMA](#hpdma) | `0x52000000` | 171 | SVD |
| [ICACHE](#icache) | `0x52015000` | 6 | SVD |
| [RAMCFG](#ramcfg) | `0x58027000` | 31 | SVD |
| [RAMECC1](#ramecc1) | `0x52009000` | 1 | CMSIS 补表 |
| [RAMECC1_Monitor0](#ramecc1_monitor0) | `0x52009020` | 6 | CMSIS 补表 |
| [RAMECC1_Monitor1](#ramecc1_monitor1) | `0x52009040` | 6 | CMSIS 补表 |
| [RAMECC1_Monitor2](#ramecc1_monitor2) | `0x52009060` | 6 | CMSIS 补表 |
| [RAMECC1_Monitor3](#ramecc1_monitor3) | `0x52009080` | 6 | CMSIS 补表 |
| [RAMECC1_Monitor4](#ramecc1_monitor4) | `0x520090A0` | 6 | CMSIS 补表 |
| [SDMMC1](#sdmmc1) | `0x52007000` | 38 | SVD |
| [SDMMC2](#sdmmc2) | `0x48002400` | 38 | SVD，继承 SDMMC1 |
| [XSPI1](#xspi1) | `0x52005000` | 31 | SVD |
| [XSPI2](#xspi2) | `0x5200A000` | 31 | SVD，继承 XSPI1 |
| [XSPIM1](#xspim1) | `0x5200B400` | 1 | SVD |

## DLYB1

**模块用途**　可调延迟块，用于校准相连存储接口的信号采样时序。

基地址 `0x52008000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `DLYB_CR` | DLYB 控制寄存器 | `0x000` | `0x52008000` | 32 | — | 0x00000000 / 0xFFFFFFFF | SEN[1] (RW)（待核）、DEN[0] (RW)（延迟块使能位） | — |
| `DLYB_CFGR` | DLYB 配置寄存器 | `0x004` | `0x52008004` | 32 | — | 0x00000000 / 0xFFFFFFFF | LNGF[31] (RO)（长度有效标志）、LNG[27:16] (RO)（延迟行长度值）、UNIT[14:8] (RW)（待核）、SEL[3:0] (RW)（相位的输出时钟） | — |

## DLYB2

**模块用途**　可调延迟块，用于校准相连存储接口的信号采样时序。

基地址 `0x48002800` · SVD，继承 DLYB1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `DLYB_CR` | DLYB 控制寄存器 | `0x000` | `0x48002800` | 32 | — | 0x00000000 / 0xFFFFFFFF | SEN[1] (RW)（待核）、DEN[0] (RW)（延迟块使能位） | — |
| `DLYB_CFGR` | DLYB 配置寄存器 | `0x004` | `0x48002804` | 32 | — | 0x00000000 / 0xFFFFFFFF | LNGF[31] (RO)（长度有效标志）、LNG[27:16] (RO)（延迟行长度值）、UNIT[14:8] (RW)（待核）、SEL[3:0] (RW)（相位的输出时钟） | — |

## FLASH

**模块用途**　片内闪存控制器，管理擦除、编程、访问等待周期、保护配置和错误状态。

基地址 `0x52002000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `FLASH_ACR` | 访问控制寄存器 | `0x000` | `0x52002000` | 32 | — | 0x00000013 / 0xFFFFFFFF | WRHIGHFREQ[5:4] (RW)（待核）、LATENCY[3:0] (RW)（读取延迟） | — |
| `FLASH_KEYR` | 闪存控制密钥寄存器 | `0x004` | `0x52002004` | 32 | — | 0x00000000 / 0xFFFFFFFF | CUKEY[31:0] (WO)（控制解锁密钥） | — |
| `FLASH_CR` | 闪存控制寄存器 | `0x010` | `0x52002010` | 32 | — | 0x00000001 / 0xFFFFFFFF | ALL_BANKS[24] (RW)（待核）、CRC_EN[17] (RW)（CRC 使能）、PG_OTP[16] (RW)（待核）、SSN[8:6] (RW)（扇区擦除选择编号，按 ST 芯片头文件修正）、START[5] (RW)（擦除启动控制位）、FW[4] (RW)（待核）、BER[3] (RW)（存储体擦除请求）、SER[2] (RW)（扇区擦除请求）、PG[1] (RW)（内部缓冲区控制位）、LOCK[0] (RW)（配置锁定位） | — |
| `FLASH_SR` | 闪存状态寄存器 | `0x014` | `0x52002014` | 32 | — | 0x00000000 / 0xFFFFFFFF | RCHECKF[25] (RO)（待核）、IS_OPTCHANGE[6] (RO)（待核）、IS_ERASE[5] (RO)（待核）、IS_PROGRAM[4] (RO)（待核）、CRC_BUSY[3] (RO)（CRC 忙标志）、QW[2] (RO)（待核）、WBNE[1] (RO)（待核）、BUSY[0] (RO)（忙标志） | — |
| `FLASH_FCR` | 闪存状态寄存器 | `0x018` | `0x52002018` | 32 | — | 0x00000000 / 0xFFFFFFFF | RCHECKF[25] (WO)（待核） | — |
| `FLASH_IER` | 闪存中断使能寄存器 | `0x020` | `0x52002020` | 32 | — | 0x00000000 / 0xFFFFFFFF | CRCRDERRIE[28] (RW)（CRC 读取错误中断使能位）、CRCENDIE[27] (RW)（CRC 结束的计算中断使能位）、DBECCERRIE[26] (RW)（待核）、SNECCERRIE[25] (RW)（ECC 单次纠正错误中断使能位）、RDSERRIE[24] (RW)（读取安全错误中断使能位）、INCERRIE[21] (RW)（待核）、OBLERRIE[20] (RW)（待核）、STRBERRIE[19] (RW)（待核）、PGSERRIE[18] (RW)（编程序列错误中断使能位）、WRPERRIE[17] (RW)（写保护错误中断使能位）、EOPIE[16] (RW)（结束-的-编程中断控制位） | — |
| `FLASH_ISR` | 闪存中断状态寄存器 | `0x024` | `0x52002024` | 32 | — | 0x00000000 / 0xFFFFFFFF | CRCRDERRF[28] (RO)（CRC 读取错误标志）、CRCENDF[27] (RO)（CRC 结束标志）、DBECCERRF[26] (RO)（待核）、SNECCERRF[25] (RO)（ECC 单次错误标志）、RDSERRF[24] (RO)（读取安全错误标志）、INCERRF[21] (RO)（待核）、OBLERRF[20] (RO)（待核）、STRBERRF[19] (RO)（待核）、PGSERRF[18] (RO)（编程序列错误标志）、WRPERRF[17] (RO)（写保护错误标志）、EOPF[16] (RO)（结束-的-编程标志） | — |
| `FLASH_ICR` | 闪存中断清除寄存器 | `0x028` | `0x52002028` | 32 | — | 0x00000000 / 0xFFFFFFFF | CRCRDERRF[28] (WO)（CRC 错误清除标志）、CRCENDF[27] (WO)（CRC 结束清除标志）、DBECCERRF[26] (WO)（待核）、SNECCERRF[25] (WO)（ECC 单次错误清除标志）、RDSERRF[24] (WO)（读取安全错误清除标志）、INCERRF[21] (WO)（待核）、OBLERRF[20] (WO)（待核）、STRBERRF[19] (WO)（待核）、PGSERRF[18] (WO)（编程序列错误清除标志）、WRPERRF[17] (WO)（写保护错误清除标志）、EOPF[16] (WO)（结束-的-编程清除标志） | — |
| `FLASH_CRCCR` | 闪存 CRC 控制寄存器 | `0x030` | `0x52002030` | 32 | — | 0x001C0000 / 0xFFFFFFFF | ALL_SECT[24] (RW)（待核）、CRC_BURST[21:20] (RW)（CRC 突发大小）、CLEAN_CRC[17] (WO)（CRC 清除位）、START_CRC[16] (RW)（CRC 起始位）、CLEAN_SECT[11] (WO)（CRC 扇区列表清除位）、ADD_SECT[10] (WO)（CRC 扇区选择位）、CRC_BY_SECT[9] (RW)（CRC 扇区模式选择位）、CRC_SECT[1:0] (RW)（CRC 扇区编号） | — |
| `FLASH_CRCSADDR` | 闪存 CRC 启动地址寄存器 | `0x034` | `0x52002034` | 32 | — | 0x00000000 / 0xFFFFFFFF | CRC_START_ADDR[16:6] (RW)（CRC 启动地址） | — |
| `FLASH_CRCEADDR` | 闪存 CRC 结束地址寄存器 | `0x038` | `0x52002038` | 32 | — | 0x00000000 / 0xFFFFFFFF | CRC_END_ADDR[16:6] (RW)（CRC 结束地址） | — |
| `FLASH_CRCDATAR` | 闪存 CRC 数据寄存器 | `0x03C` | `0x5200203C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CRC_DATA[31:0] (RO)（CRC 结果） | — |
| `FLASH_ECCSFADDR` | 闪存 ECC 单次错误故障地址 | `0x040` | `0x52002040` | 32 | — | 0x00000000 / 0xFFFFFFFF | SEC_FADD[31:0] (RO)（ECC 单次错误纠正故障地址） | — |
| `FLASH_ECCDFADDR` | 闪存 ECC 双比特错误地址 | `0x044` | `0x52002044` | 32 | — | 0x00000000 / 0xFFFFFFFF | DED_FADD[31:0] (RO)（待核） | — |
| `FLASH_OPTKEYR` | 闪存选项密钥寄存器 | `0x100` | `0x52002100` | 32 | — | 0x00000000 / 0xFFFFFFFF | OCUKEY[31:0] (WO)（选项配置解锁密钥） | — |
| `FLASH_OPTCR` | 闪存选项控制寄存器 | `0x104` | `0x52002104` | 32 | — | 0x00000001 / 0x0FFFFFFF | OPTERRIE[30] (RW)（待核）、KTEIE[28] (RW)（密钥传输错误中断使能位）、KVEIE[27] (RW)（密钥有效错误中断使能位）、PG_OPT[1] (RW)（编程选项）、OPTLOCK[0] (RW)（选项锁定） | — |
| `FLASH_OPTISR` | 闪存选项中断状态寄存器 | `0x108` | `0x52002108` | 32 | — | 0x00000000 / 0x00000000 | OPTERRF[30] (RO)（待核）、KTEF[28] (RO)（密钥传输错误标志）、KVEF[27] (RO)（密钥有效错误标志） | — |
| `FLASH_OPTICR` | 闪存选项中断清除寄存器 | `0x10C` | `0x5200210C` | 32 | — | 0x00000000 / 0x00000000 | OPTERRF[30] (WO)（待核）、KTEF[28] (WO)（密钥传输错误标志）、KVEF[27] (WO)（密钥有效错误标志） | — |
| `FLASH_OBKCR` | 闪存选项字节密钥控制寄存器 | `0x110` | `0x52002110` | 32 | — | 0x00000C00 / 0xFFFFFFFF | KEYSTART[15] (RW)（密钥选项启动）、KEYPROG[14] (RW)（密钥编程）、OBKSIZE[11:10] (RW)（选项字节密钥大小）、NEXTKL[9:8] (RW)（待核）、OBKINDEX[4:0] (RW)（选项字节密钥索引） | — |
| `FLASH_OBKDR0` | 闪存选项字节密钥数据寄存器 0 | `0x118` | `0x52002118` | 32 | — | 0x00000000 / 0xFFFFFFFF | OBKDATA[31:0] (RW)（选项字节密钥数据, 位 [31+x:0+x]） | — |
| `FLASH_OBKDR1` | 闪存选项字节密钥数据寄存器 1 | `0x11C` | `0x5200211C` | 32 | — | 0x00000000 / 0xFFFFFFFF | OBKDATA[31:0] (RW)（选项字节密钥数据, 位 [31+x:0+x]） | — |
| `FLASH_OBKDR2` | 闪存选项字节密钥数据寄存器 2 | `0x120` | `0x52002120` | 32 | — | 0x00000000 / 0xFFFFFFFF | OBKDATA[31:0] (RW)（选项字节密钥数据, 位 [31+x:0+x]） | — |
| `FLASH_OBKDR3` | 闪存选项字节密钥数据寄存器 3 | `0x124` | `0x52002124` | 32 | — | 0x00000000 / 0xFFFFFFFF | OBKDATA[31:0] (RW)（选项字节密钥数据, 位 [31+x:0+x]） | — |
| `FLASH_OBKDR4` | 闪存选项字节密钥数据寄存器 4 | `0x128` | `0x52002128` | 32 | — | 0x00000000 / 0xFFFFFFFF | OBKDATA[31:0] (RW)（选项字节密钥数据, 位 [31+x:0+x]） | — |
| `FLASH_OBKDR5` | 闪存选项字节密钥数据寄存器 5 | `0x12C` | `0x5200212C` | 32 | — | 0x00000000 / 0xFFFFFFFF | OBKDATA[31:0] (RW)（选项字节密钥数据, 位 [31+x:0+x]） | — |
| `FLASH_OBKDR6` | 闪存选项字节密钥数据寄存器 6 | `0x130` | `0x52002130` | 32 | — | 0x00000000 / 0xFFFFFFFF | OBKDATA[31:0] (RW)（选项字节密钥数据, 位 [31+x:0+x]） | — |
| `FLASH_OBKDR7` | 闪存选项字节密钥数据寄存器 7 | `0x134` | `0x52002134` | 32 | — | 0x00000000 / 0xFFFFFFFF | OBKDATA[31:0] (RW)（选项字节密钥数据, 位 [31+x:0+x]） | — |
| `FLASH_NVSR` | 闪存非易失状态寄存器 | `0x200` | `0x52002200` | 32 | — | 0x00000000 / 0xFFFF0000 | NVSTATE[7:0] (RO)（非易失状态） | — |
| `FLASH_NVSRP` | 闪存安全状态寄存器编程 | `0x204` | `0x52002204` | 32 | — | 0x00000000 / 0xFFFF0000 | NVSTATE[7:0] (RW)（非易失状态编程） | — |
| `FLASH_ROTSR` | 闪存 ROT 状态寄存器 | `0x208` | `0x52002208` | 32 | — | 0x00000000 / 0xFFFF0000 | IROT_SELECT[31:24] (RO)（待核）、DBG_AUTH[15:8] (RO)（待核）、OEM_PROVD[7:0] (RO)（待核） | — |
| `FLASH_ROTSRP` | 闪存 ROT 状态寄存器编程 | `0x20C` | `0x5200220C` | 32 | — | 0x00000000 / 0xFFFF0000 | IROT_SELECT[31:24] (RO)（待核）、DBG_AUTH[15:8] (RW)（待核）、OEM_PROVD[7:0] (RW)（待核） | — |
| `FLASH_OTPLSR` | 闪存 OTP 锁定状态寄存器 | `0x210` | `0x52002210` | 32 | — | 0x00000000 / 0xFFFF0000 | OTPL[15:0] (RO)（OTP 锁定 n） | — |
| `FLASH_OTPLSRP` | 闪存 OTP 锁定状态寄存器编程 | `0x214` | `0x52002214` | 32 | — | 0x00000000 / 0xFFFF0000 | OTPL[15:0] (RW)（OTP 锁定 n 编程） | — |
| `FLASH_WRPSR` | 闪存写保护状态寄存器 | `0x218` | `0x52002218` | 32 | — | 0x00000000 / 0xFFFF0000 | WRPS[7:0] (RW)（写保护的扇区 n） | — |
| `FLASH_WRPSRP` | 闪存写保护状态寄存器编程 | `0x21C` | `0x5200221C` | 32 | — | 0x00000000 / 0xFFFF0000 | WRPS[7:0] (RW)（写保护的扇区 n 编程） | — |
| `FLASH_HDPSR` | 闪存隐藏保护状态寄存器 | `0x230` | `0x52002230` | 32 | — | 0x00000000 / 0xF000FFFF | HDP_AREA_END[24:16] (RO)（待核）、HDP_AREA_START[8:0] (RO)（待核） | — |
| `FLASH_HDPSRP` | 闪存隐藏保护状态寄存器编程 | `0x234` | `0x52002234` | 32 | — | 0x00000000 / 0xF000FFFF | HDP_AREA_END[24:16] (RW)（待核）、HDP_AREA_START[8:0] (RW)（待核） | — |
| `FLASH_EPOCHSR` | 闪存安全版本纪元状态寄存器 | `0x250` | `0x52002250` | 32 | — | 0x00000000 / 0xFFFF0000 | EPOCH[23:0] (RO)（安全版本纪元） | — |
| `FLASH_EPOCHSRP` | 闪存 ROT 状态寄存器编程 | `0x254` | `0x52002254` | 32 | — | 0x00000000 / 0xFFFF0000 | EPOCH[23:0] (RW)（安全版本纪元编程） | — |
| `FLASH_OBW1SR` | 闪存选项字节字 1 状态寄存器 | `0x260` | `0x52002260` | 32 | — | 0x00000000 / 0x00000000 | VDDIO_HSLV[29] (RO)（待核）、PERSO_OK[28] (RO)（待核）、IWDG_FZ_SDBY[18] (RO)（IWDG 待机模式冻结）、IWDG_FZ_STOP[17] (RO)（IWDG 停止模式冻结）、OCTO2_HSLV[9] (RO)（待核）、OCTO1_HSLV[8] (RO)（待核）、NRST_STBY[7] (RO)（复位的待机模式）、NRST_STOP[6] (RO)（复位的停止模式）、IWDG_HW[4] (RO)（待核）、BOR_LEV[3:2] (RO)（待核） | — |
| `FLASH_OBW1SRP` | 闪存选项字节字 1 状态寄存器编程 | `0x264` | `0x52002264` | 32 | — | 0x00000000 / 0x00000000 | VDDIO_HSLV[29] (RW)（待核）、IWDG_FZ_SDBY[18] (RW)（IWDG 待机模式冻结编程）、IWDG_FZ_STOP[17] (RW)（IWDG 停止模式冻结）、OCTO2_HSLV[9] (RW)（待核）、OCTO1_HSLV[8] (RW)（待核）、NRST_STBY[7] (RW)（复位的待机模式编程）、NRST_STOP[6] (RW)（复位的停止模式编程）、IWDG_HW[4] (RW)（待核）、BOR_LEV[3:2] (RW)（待核） | — |
| `FLASH_OBW2SR` | 闪存选项字节字 2 状态寄存器 | `0x268` | `0x52002268` | 32 | — | 0x00000000 / 0x00000000 | I2C_NI3C[9] (RO)（待核）、ECC_ON_SRAM[8] (RO)（ECC 的 SRAM）、DTCM_AXI_SHARE[6:4] (RO)（DTCM SRAM 配置）、ITCM_AXI_SHARE[2:0] (RO)（ITCM SRAM 配置） | — |
| `FLASH_OBW2SRP` | 闪存选项字节字 2 状态寄存器编程 | `0x26C` | `0x5200226C` | 32 | — | 0x00000000 / 0x00000000 | I2C_NI3C[9] (RW)（待核）、ECC_ON_SRAM[8] (RW)（ECC 的 SRAM 编程）、DTCM_AXI_SHARE[6:4] (RW)（待核）、ITCM_AXI_SHARE[2:0] (RW)（待核） | — |

## FMC

**模块用途**　灵活存储控制器，用于接入并行外部存储器，配置各 Bank 的总线宽度、读写时序及工作模式。

基地址 `0x52004000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `FMC_BCR1` | SRAM 或 NOR 存储体的片选控制 | `0x000` | `0x52004000` | 32 | — | 0x000030DB / 0xFFFFFFFF | FMCEN[31] (RW)（FMC 使能）、BMAP[25:24] (RW)（待核）、WFDIS[21] (RW)（写入 FIFO 禁用）、CCLKEN[20] (RW)（连续时钟使能）、CBURSTRW[19] (RW)（写入突发使能）、CPSIZE[18:16] (RW)（CRAM 页大小）、ASYNCWAIT[15] (RW)（待核）、EXTMOD[14] (RW)（扩展模式使能）、WAITEN[13] (RW)（待核）、WREN[12] (RW)（写入使能位）、WAITCFG[11] (RW)（待核）、WAITPOL[9] (RW)（待核）、BURSTEN[8] (RW)（突发使能位）、FACCEN[6] (RW)（闪存访问使能）、MWID[5:4] (RW)（存储器数据总线宽度）、MTYP[3:2] (RW)（待核）、MUXEN[1] (RW)（待核）、MBKEN[0] (RW)（存储器存储体使能位） | — |
| `FMC_BTR1` | SRAM 或 NOR 存储体的片选读写时序 | `0x004` | `0x52004004` | 32 | — | 0x0FFFFFFF / 0xFFFFFFFF | ACCMOD[29:28] (RW)（访问模式）、DATLAT[27:24] (RW)（待核）、CLKDIV[23:20] (RW)（待核）、BUSTURN[19:16] (RW)（待核）、DATAST[15:8] (RW)（待核）、ADDHLD[7:4] (RW)（待核）、ADDSET[3:0] (RW)（待核） | — |
| `FMC_BCR2` | SRAM 或 NOR 存储体的片选控制 | `0x008` | `0x52004008` | 32 | — | 0x000030D2 / 0xFFFFFFFF | FMCEN[31] (RW)（FMC 使能）、BMAP[25:24] (RW)（待核）、WFDIS[21] (RW)（写入 FIFO 禁用）、CCLKEN[20] (RW)（连续时钟使能）、CBURSTRW[19] (RW)（写入突发使能）、CPSIZE[18:16] (RW)（CRAM 页大小）、ASYNCWAIT[15] (RW)（待核）、EXTMOD[14] (RW)（扩展模式使能）、WAITEN[13] (RW)（待核）、WREN[12] (RW)（写入使能位）、WAITCFG[11] (RW)（待核）、WAITPOL[9] (RW)（待核）、BURSTEN[8] (RW)（突发使能位）、FACCEN[6] (RW)（闪存访问使能）、MWID[5:4] (RW)（存储器数据总线宽度）、MTYP[3:2] (RW)（待核）、MUXEN[1] (RW)（待核）、MBKEN[0] (RW)（存储器存储体使能位） | — |
| `FMC_BTR2` | SRAM 或 NOR 存储体的片选读写时序 | `0x00C` | `0x5200400C` | 32 | — | 0x0FFFFFFF / 0xFFFFFFFF | ACCMOD[29:28] (RW)（访问模式）、DATLAT[27:24] (RW)（待核）、CLKDIV[23:20] (RW)（待核）、BUSTURN[19:16] (RW)（待核）、DATAST[15:8] (RW)（待核）、ADDHLD[7:4] (RW)（待核）、ADDSET[3:0] (RW)（待核） | — |
| `FMC_BCR3` | SRAM 或 NOR 存储体的片选控制 | `0x010` | `0x52004010` | 32 | — | 0x000030D2 / 0xFFFFFFFF | FMCEN[31] (RW)（FMC 使能）、BMAP[25:24] (RW)（待核）、WFDIS[21] (RW)（写入 FIFO 禁用）、CCLKEN[20] (RW)（连续时钟使能）、CBURSTRW[19] (RW)（写入突发使能）、CPSIZE[18:16] (RW)（CRAM 页大小）、ASYNCWAIT[15] (RW)（待核）、EXTMOD[14] (RW)（扩展模式使能）、WAITEN[13] (RW)（待核）、WREN[12] (RW)（写入使能位）、WAITCFG[11] (RW)（待核）、WAITPOL[9] (RW)（待核）、BURSTEN[8] (RW)（突发使能位）、FACCEN[6] (RW)（闪存访问使能）、MWID[5:4] (RW)（存储器数据总线宽度）、MTYP[3:2] (RW)（待核）、MUXEN[1] (RW)（待核）、MBKEN[0] (RW)（存储器存储体使能位） | — |
| `FMC_BTR3` | SRAM 或 NOR 存储体的片选读写时序 | `0x014` | `0x52004014` | 32 | — | 0x0FFFFFFF / 0xFFFFFFFF | ACCMOD[29:28] (RW)（访问模式）、DATLAT[27:24] (RW)（待核）、CLKDIV[23:20] (RW)（待核）、BUSTURN[19:16] (RW)（待核）、DATAST[15:8] (RW)（待核）、ADDHLD[7:4] (RW)（待核）、ADDSET[3:0] (RW)（待核） | — |
| `FMC_BCR4` | SRAM 或 NOR 存储体的片选控制 | `0x018` | `0x52004018` | 32 | — | 0x000030D2 / 0xFFFFFFFF | FMCEN[31] (RW)（FMC 使能）、BMAP[25:24] (RW)（待核）、WFDIS[21] (RW)（写入 FIFO 禁用）、CCLKEN[20] (RW)（连续时钟使能）、CBURSTRW[19] (RW)（写入突发使能）、CPSIZE[18:16] (RW)（CRAM 页大小）、ASYNCWAIT[15] (RW)（待核）、EXTMOD[14] (RW)（扩展模式使能）、WAITEN[13] (RW)（待核）、WREN[12] (RW)（写入使能位）、WAITCFG[11] (RW)（待核）、WAITPOL[9] (RW)（待核）、BURSTEN[8] (RW)（突发使能位）、FACCEN[6] (RW)（闪存访问使能）、MWID[5:4] (RW)（存储器数据总线宽度）、MTYP[3:2] (RW)（待核）、MUXEN[1] (RW)（待核）、MBKEN[0] (RW)（存储器存储体使能位） | — |
| `FMC_BTR4` | SRAM 或 NOR 存储体的片选读写时序 | `0x01C` | `0x5200401C` | 32 | — | 0x0FFFFFFF / 0xFFFFFFFF | ACCMOD[29:28] (RW)（访问模式）、DATLAT[27:24] (RW)（待核）、CLKDIV[23:20] (RW)（待核）、BUSTURN[19:16] (RW)（待核）、DATAST[15:8] (RW)（待核）、ADDHLD[7:4] (RW)（待核）、ADDSET[3:0] (RW)（待核） | — |
| `FMC_PCR` | NAND 闪存控制寄存器 | `0x080` | `0x52004080` | 32 | — | 0x00000018 / 0xFFFFFFFF | ECCPS[19:17] (RW)（ECC 页大小）、TAR3[16] (RW)（ALE 至 RE 延迟）、TAR2[15] (RW)（ALE 至 RE 延迟）、TAR1[14] (RW)（ALE 至 RE 延迟）、TAR0[13] (RW)（ALE 至 RE 延迟）、TCLR[12:9] (RW)（CLE 至 RE 延迟）、ECCEN[6] (RW)（待核）、PWID[5:4] (RW)（数据总线宽度）、PBKEN[2] (RW)（NAND 闪存存储器存储体使能位）、PWAITEN[1] (RW)（待核） | — |
| `FMC_SR` | FIFO 状态与中断寄存器 | `0x084` | `0x52004084` | 32 | — | 0x00000040 / 0xFFFFFFFF | FEMPT[6] (RO)（FIFO 空）、IFEN[5] (RW)（中断下降沿边沿检测使能位）、ILEN[4] (RW)（中断高位-电平检测使能位）、IREN[3] (RW)（中断上升沿边沿检测使能位）、IFS[2] (RW)（中断下降沿边沿状态）、ILS[1] (RW)（中断高位-电平状态）、IRS[0] (RW)（中断上升沿边沿状态） | — |
| `FMC_PMEM` | 公共存储器空间时序寄存器 | `0x088` | `0x52004088` | 32 | — | 0xFCFCFCFC / 0xFFFFFFFF | MEMHIZ[31:24] (RW)（待核）、MEMHOLD[23:16] (RW)（公共存储器保持时间）、MEMWAIT[15:8] (RW)（待核）、MEMSET[7:0] (RW)（待核） | — |
| `FMC_PATT` | 属性存储器空间时序寄存器 | `0x08C` | `0x5200408C` | 32 | — | 0xFCFCFCFC / 0xFFFFFFFF | ATTHIZ[31:24] (RW)（待核）、ATTHOLD[23:16] (RW)（属性存储器保持时间）、ATTWAIT[15:8] (RW)（待核）、ATTSET[7:0] (RW)（待核） | — |
| `FMC_ECCR` | ECC 结果寄存器 | `0x094` | `0x52004094` | 32 | — | 0x00000000 / 0xFFFFFFFF | ECC[31:0] (RO)（ECC 结果） | — |
| `FMC_BWTR1` | SRAM/NOR-闪存写入时序寄存器的存储体 1 | `0x104` | `0x52004104` | 32 | — | 0x0FFFFFFF / 0xFFFFFFFF | ACCMOD[29:28] (RW)（访问模式）、BUSTURN[19:16] (RW)（待核）、DATAST[15:8] (RW)（待核）、ADDHLD[7:4] (RW)（待核）、ADDSET[3:0] (RW)（待核） | — |
| `FMC_BWTR2` | SRAM/NOR-闪存写入时序寄存器的存储体 2 | `0x10C` | `0x5200410C` | 32 | — | 0x0FFFFFFF / 0xFFFFFFFF | ACCMOD[29:28] (RW)（访问模式）、BUSTURN[19:16] (RW)（待核）、DATAST[15:8] (RW)（待核）、ADDHLD[7:4] (RW)（待核）、ADDSET[3:0] (RW)（待核） | — |
| `FMC_BWTR3` | SRAM/NOR-闪存写入时序寄存器的存储体 3 | `0x114` | `0x52004114` | 32 | — | 0x0FFFFFFF / 0xFFFFFFFF | ACCMOD[29:28] (RW)（访问模式）、BUSTURN[19:16] (RW)（待核）、DATAST[15:8] (RW)（待核）、ADDHLD[7:4] (RW)（待核）、ADDSET[3:0] (RW)（待核） | — |
| `FMC_BWTR4` | SRAM/NOR-闪存写入时序寄存器的存储体 4 | `0x11C` | `0x5200411C` | 32 | — | 0x0FFFFFFF / 0xFFFFFFFF | ACCMOD[29:28] (RW)（访问模式）、BUSTURN[19:16] (RW)（待核）、DATAST[15:8] (RW)（待核）、ADDHLD[7:4] (RW)（待核）、ADDSET[3:0] (RW)（待核） | — |
| `FMC_SDCR1` | SDRAM 控制寄存器的 SDRAM 存储器存储体 1 | `0x140` | `0x52004140` | 32 | — | 0x000002D0 / 0xFFFFFFFF | RPIPE[14:13] (RW)（读取流水线）、RBURST[12] (RW)（突发读取）、SDCLK[11:10] (RW)（SDRAM 时钟配置）、WP[9] (RW)（写保护）、CAS[8:7] (RW)（CAS 延迟）、NB[6] (RW)（待核）、MWID[5:4] (RW)（存储器数据总线宽度）、NR[3:2] (RW)（数量行地址位）、NC[1:0] (RW)（数量列地址位） | — |
| `FMC_SDCR2` | SDRAM 控制寄存器的 SDRAM 存储器存储体 2 | `0x144` | `0x52004144` | 32 | — | 0x000002D0 / 0xFFFFFFFF | RPIPE[14:13] (RW)（读取流水线）、RBURST[12] (RW)（突发读取）、SDCLK[11:10] (RW)（SDRAM 时钟配置）、WP[9] (RW)（写保护）、CAS[8:7] (RW)（CAS 延迟）、NB[6] (RW)（待核）、MWID[5:4] (RW)（存储器数据总线宽度）、NR[3:2] (RW)（数量行地址位）、NC[1:0] (RW)（数量列地址位） | — |
| `FMC_SDTR1` | SDRAM 时序寄存器的 SDRAM 存储器存储体 1 | `0x148` | `0x52004148` | 32 | — | 0x0FFFFFFF / 0xFFFFFFFF | TRCD[27:24] (RW)（行至列延迟）、TRP[23:20] (RW)（待核）、TWR[19:16] (RW)（恢复延迟）、TRC[15:12] (RW)（行周期延迟）、TRAS[11:8] (RW)（待核）、TXSR[7:4] (RW)（待核）、TMRD[3:0] (RW)（待核） | — |
| `FMC_SDTR2` | SDRAM 时序寄存器的 SDRAM 存储器存储体 2 | `0x14C` | `0x5200414C` | 32 | — | 0x0FFFFFFF / 0xFFFFFFFF | TRCD[27:24] (RW)（行至列延迟）、TRP[23:20] (RW)（待核）、TWR[19:16] (RW)（恢复延迟）、TRC[15:12] (RW)（行周期延迟）、TRAS[11:8] (RW)（待核）、TXSR[7:4] (RW)（待核）、TMRD[3:0] (RW)（待核） | — |
| `FMC_SDCMR` | SDRAM 命令模式寄存器 | `0x150` | `0x52004150` | 32 | — | 0x00000000 / 0xFFFFFFFF | MRD[22:9] (RW)（待核）、NRFS[8:5] (RW)（待核）、CTB1[4] (RW)（待核）、CTB2[3] (RW)（待核）、MODE[2:0] (RW)（命令模式） | — |
| `FMC_SDRTR` | SDRAM 刷新定时器寄存器 | `0x154` | `0x52004154` | 32 | — | 0x00000000 / 0xFFFFFFFF | REIE[14] (RW)（RES 中断使能）、COUNT[13:1] (RW)（刷新定时器计数）、CRE[0] (WO)（清除刷新错误标志） | — |
| `FMC_SDSR` | SDRAM 状态寄存器 | `0x158` | `0x52004158` | 32 | — | 0x00000000 / 0xFFFFFFFF | MODES2[4:3] (RO)（状态模式的存储体 2）、MODES1[2:1] (RO)（状态模式的存储体 1）、RE[0] (RO)（刷新错误标志） | — |

## FMC_Bank1E_R

**模块用途**　FMC Bank 1 的扩展写时序寄存器，适用于分别配置读、写时序的场景。

基地址 `0x52004104` · CMSIS 补表

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `BWTR[1]` | 外部 SRAM 或 NOR 的扩展写时序 | `0x004` | `0x52004108` | 32 | — | — / — | — | — |
| `BWTR[3]` | 外部 SRAM 或 NOR 的扩展写时序 | `0x00C` | `0x52004110` | 32 | — | — / — | — | — |
| `BWTR[5]` | 外部 SRAM 或 NOR 的扩展写时序 | `0x014` | `0x52004118` | 32 | — | — / — | — | — |

## GPDMA

**模块用途**　通用 DMA 控制器，按通道搬运外设或内存数据，并支持触发、突发传输和链表。

基地址 `0x40021000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `GPDMA_PRIVCFGR` | GPDMA 特权配置寄存器 | `0x004` | `0x40021004` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIV15[15] (RW)（特权状态的通道 x）、PRIV14[14] (RW)（特权状态的通道 x）、PRIV13[13] (RW)（特权状态的通道 x）、PRIV12[12] (RW)（特权状态的通道 x）、PRIV11[11] (RW)（特权状态的通道 x）、PRIV10[10] (RW)（特权状态的通道 x）、PRIV9[9] (RW)（特权状态的通道 x）、PRIV8[8] (RW)（特权状态的通道 x）、PRIV7[7] (RW)（特权状态的通道 x）、PRIV6[6] (RW)（特权状态的通道 x）、PRIV5[5] (RW)（特权状态的通道 x）、PRIV4[4] (RW)（特权状态的通道 x）、PRIV3[3] (RW)（特权状态的通道 x）、PRIV2[2] (RW)（特权状态的通道 x）、PRIV1[1] (RW)（特权状态的通道 x）、PRIV0[0] (RW)（特权状态的通道 x） | — |
| `GPDMA_RCFGLOCKR` | GPDMA 配置锁定寄存器 | `0x008` | `0x40021008` | 32 | — | 0x00000000 / 0xFFFFFFFF | LOCK15[15] (RW)（锁定对应 DMA 通道的特权配置）、LOCK14[14] (RW)（锁定对应 DMA 通道的特权配置）、LOCK13[13] (RW)（锁定对应 DMA 通道的特权配置）、LOCK12[12] (RW)（锁定对应 DMA 通道的特权配置）、LOCK11[11] (RW)（锁定对应 DMA 通道的特权配置）、LOCK10[10] (RW)（锁定对应 DMA 通道的特权配置）、LOCK9[9] (RW)（锁定对应 DMA 通道的特权配置）、LOCK8[8] (RW)（锁定对应 DMA 通道的特权配置）、LOCK7[7] (RW)（锁定对应 DMA 通道的特权配置）、LOCK6[6] (RW)（锁定对应 DMA 通道的特权配置）、LOCK5[5] (RW)（锁定对应 DMA 通道的特权配置）、LOCK4[4] (RW)（锁定对应 DMA 通道的特权配置）、LOCK3[3] (RW)（锁定对应 DMA 通道的特权配置）、LOCK2[2] (RW)（锁定对应 DMA 通道的特权配置）、LOCK1[1] (RW)（锁定对应 DMA 通道的特权配置）、LOCK0[0] (RW)（锁定对应 DMA 通道的特权配置） | — |
| `GPDMA_MISR` | GPDMA 屏蔽后中断状态寄存器 | `0x00C` | `0x4002100C` | 32 | — | 0x00000000 / 0xFFFFFFFF | MIS15[15] (RO)（屏蔽后中断状态的通道 x）、MIS14[14] (RO)（屏蔽后中断状态的通道 x）、MIS13[13] (RO)（屏蔽后中断状态的通道 x）、MIS12[12] (RO)（屏蔽后中断状态的通道 x）、MIS11[11] (RO)（屏蔽后中断状态的通道 x）、MIS10[10] (RO)（屏蔽后中断状态的通道 x）、MIS9[9] (RO)（屏蔽后中断状态的通道 x）、MIS8[8] (RO)（屏蔽后中断状态的通道 x）、MIS7[7] (RO)（屏蔽后中断状态的通道 x）、MIS6[6] (RO)（屏蔽后中断状态的通道 x）、MIS5[5] (RO)（屏蔽后中断状态的通道 x）、MIS4[4] (RO)（屏蔽后中断状态的通道 x）、MIS3[3] (RO)（屏蔽后中断状态的通道 x）、MIS2[2] (RO)（屏蔽后中断状态的通道 x）、MIS1[1] (RO)（屏蔽后中断状态的通道 x）、MIS0[0] (RO)（屏蔽后中断状态的通道 x） | — |
| `GPDMA_C0LBAR` | GPDMA 通道 0 链表基址地址寄存器 | `0x050` | `0x40021050` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 GPDMA 通道 x） | — |
| `GPDMA_C0FCR` | GPDMA 通道 0 清除标志寄存器 | `0x05C` | `0x4002105C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `GPDMA_C0SR` | GPDMA 通道 0 状态寄存器 | `0x060` | `0x40021060` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[23:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `GPDMA_C0CR` | GPDMA 通道 0 控制寄存器 | `0x064` | `0x40021064` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `GPDMA_C0TR1` | GPDMA 通道 0 传输寄存器 1 | `0x090` | `0x40021090` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `GPDMA_C0TR2` | GPDMA 通道 0 传输寄存器 2 | `0x094` | `0x40021094` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[6:0] (RW)（GPDMA 硬件请求选择） | — |
| `GPDMA_C0BR1` | GPDMA 通道 0 块寄存器 1 | `0x098` | `0x40021098` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `GPDMA_C0SAR` | GPDMA 通道 0 源地址寄存器 | `0x09C` | `0x4002109C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `GPDMA_C0DAR` | GPDMA 通道 0 目标地址寄存器 | `0x0A0` | `0x400210A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `GPDMA_C0LLR` | GPDMA 通道 0 链表地址寄存器 | `0x0CC` | `0x400210CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 GPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 GPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 GPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 GPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 GPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 GPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `GPDMA_C1LBAR` | GPDMA 通道 1 链表基址地址寄存器 | `0x0D0` | `0x400210D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 GPDMA 通道 x） | — |
| `GPDMA_C1FCR` | GPDMA 通道 1 清除标志寄存器 | `0x0DC` | `0x400210DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `GPDMA_C1SR` | GPDMA 通道 1 状态寄存器 | `0x0E0` | `0x400210E0` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[23:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `GPDMA_C1CR` | GPDMA 通道 1 控制寄存器 | `0x0E4` | `0x400210E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `GPDMA_C1TR1` | GPDMA 通道 1 传输寄存器 1 | `0x110` | `0x40021110` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `GPDMA_C1TR2` | GPDMA 通道 1 传输寄存器 2 | `0x114` | `0x40021114` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[6:0] (RW)（GPDMA 硬件请求选择） | — |
| `GPDMA_C1BR1` | GPDMA 通道 1 块寄存器 1 | `0x118` | `0x40021118` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `GPDMA_C1SAR` | GPDMA 通道 1 源地址寄存器 | `0x11C` | `0x4002111C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `GPDMA_C1DAR` | GPDMA 通道 1 目标地址寄存器 | `0x120` | `0x40021120` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `GPDMA_C1LLR` | GPDMA 通道 1 链表地址寄存器 | `0x14C` | `0x4002114C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 GPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 GPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 GPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 GPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 GPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 GPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `GPDMA_C2LBAR` | GPDMA 通道 2 链表基址地址寄存器 | `0x150` | `0x40021150` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 GPDMA 通道 x） | — |
| `GPDMA_C2FCR` | GPDMA 通道 2 清除标志寄存器 | `0x15C` | `0x4002115C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `GPDMA_C2SR` | GPDMA 通道 2 状态寄存器 | `0x160` | `0x40021160` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[23:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `GPDMA_C2CR` | GPDMA 通道 2 控制寄存器 | `0x164` | `0x40021164` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `GPDMA_C2TR1` | GPDMA 通道 2 传输寄存器 1 | `0x190` | `0x40021190` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `GPDMA_C2TR2` | GPDMA 通道 2 传输寄存器 2 | `0x194` | `0x40021194` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[6:0] (RW)（GPDMA 硬件请求选择） | — |
| `GPDMA_C2BR1` | GPDMA 通道 2 块寄存器 1 | `0x198` | `0x40021198` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `GPDMA_C2SAR` | GPDMA 通道 2 源地址寄存器 | `0x19C` | `0x4002119C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `GPDMA_C2DAR` | GPDMA 通道 2 目标地址寄存器 | `0x1A0` | `0x400211A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `GPDMA_C2LLR` | GPDMA 通道 2 链表地址寄存器 | `0x1CC` | `0x400211CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 GPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 GPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 GPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 GPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 GPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 GPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `GPDMA_C3LBAR` | GPDMA 通道 3 链表基址地址寄存器 | `0x1D0` | `0x400211D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 GPDMA 通道 x） | — |
| `GPDMA_C3FCR` | GPDMA 通道 3 清除标志寄存器 | `0x1DC` | `0x400211DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `GPDMA_C3SR` | GPDMA 通道 3 状态寄存器 | `0x1E0` | `0x400211E0` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[23:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `GPDMA_C3CR` | GPDMA 通道 3 控制寄存器 | `0x1E4` | `0x400211E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `GPDMA_C3TR1` | GPDMA 通道 3 传输寄存器 1 | `0x210` | `0x40021210` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `GPDMA_C3TR2` | GPDMA 通道 3 传输寄存器 2 | `0x214` | `0x40021214` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[6:0] (RW)（GPDMA 硬件请求选择） | — |
| `GPDMA_C3BR1` | GPDMA 通道 3 块寄存器 1 | `0x218` | `0x40021218` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `GPDMA_C3SAR` | GPDMA 通道 3 源地址寄存器 | `0x21C` | `0x4002121C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `GPDMA_C3DAR` | GPDMA 通道 3 目标地址寄存器 | `0x220` | `0x40021220` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `GPDMA_C3LLR` | GPDMA 通道 3 链表地址寄存器 | `0x24C` | `0x4002124C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 GPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 GPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 GPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 GPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 GPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 GPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `GPDMA_C4LBAR` | GPDMA 通道 4 链表基址地址寄存器 | `0x250` | `0x40021250` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 GPDMA 通道 x） | — |
| `GPDMA_C4FCR` | GPDMA 通道 4 清除标志寄存器 | `0x25C` | `0x4002125C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `GPDMA_C4SR` | GPDMA 通道 4 状态寄存器 | `0x260` | `0x40021260` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[23:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `GPDMA_C4CR` | GPDMA 通道 4 控制寄存器 | `0x264` | `0x40021264` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `GPDMA_C4TR1` | GPDMA 通道 4 传输寄存器 1 | `0x290` | `0x40021290` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `GPDMA_C4TR2` | GPDMA 通道 4 传输寄存器 2 | `0x294` | `0x40021294` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[6:0] (RW)（GPDMA 硬件请求选择） | — |
| `GPDMA_C4BR1` | GPDMA 通道 4 块寄存器 1 | `0x298` | `0x40021298` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `GPDMA_C4SAR` | GPDMA 通道 4 源地址寄存器 | `0x29C` | `0x4002129C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `GPDMA_C4DAR` | GPDMA 通道 4 目标地址寄存器 | `0x2A0` | `0x400212A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `GPDMA_C4LLR` | GPDMA 通道 4 链表地址寄存器 | `0x2CC` | `0x400212CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 GPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 GPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 GPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 GPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 GPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 GPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `GPDMA_C5LBAR` | GPDMA 通道 5 链表基址地址寄存器 | `0x2D0` | `0x400212D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 GPDMA 通道 x） | — |
| `GPDMA_C5FCR` | GPDMA 通道 5 清除标志寄存器 | `0x2DC` | `0x400212DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `GPDMA_C5SR` | GPDMA 通道 5 状态寄存器 | `0x2E0` | `0x400212E0` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[23:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `GPDMA_C5CR` | GPDMA 通道 5 控制寄存器 | `0x2E4` | `0x400212E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `GPDMA_C5TR1` | GPDMA 通道 5 传输寄存器 1 | `0x310` | `0x40021310` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `GPDMA_C5TR2` | GPDMA 通道 5 传输寄存器 2 | `0x314` | `0x40021314` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[6:0] (RW)（GPDMA 硬件请求选择） | — |
| `GPDMA_C5BR1` | GPDMA 通道 5 块寄存器 1 | `0x318` | `0x40021318` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `GPDMA_C5SAR` | GPDMA 通道 5 源地址寄存器 | `0x31C` | `0x4002131C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `GPDMA_C5DAR` | GPDMA 通道 5 目标地址寄存器 | `0x320` | `0x40021320` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `GPDMA_C5LLR` | GPDMA 通道 5 链表地址寄存器 | `0x34C` | `0x4002134C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 GPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 GPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 GPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 GPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 GPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 GPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `GPDMA_C6LBAR` | GPDMA 通道 6 链表基址地址寄存器 | `0x350` | `0x40021350` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 GPDMA 通道 x） | — |
| `GPDMA_C6FCR` | GPDMA 通道 6 清除标志寄存器 | `0x35C` | `0x4002135C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `GPDMA_C6SR` | GPDMA 通道 6 状态寄存器 | `0x360` | `0x40021360` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[23:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `GPDMA_C6CR` | GPDMA 通道 6 控制寄存器 | `0x364` | `0x40021364` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `GPDMA_C6TR1` | GPDMA 通道 6 传输寄存器 1 | `0x390` | `0x40021390` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `GPDMA_C6TR2` | GPDMA 通道 6 传输寄存器 2 | `0x394` | `0x40021394` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[6:0] (RW)（GPDMA 硬件请求选择） | — |
| `GPDMA_C6BR1` | GPDMA 通道 6 块寄存器 1 | `0x398` | `0x40021398` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `GPDMA_C6SAR` | GPDMA 通道 6 源地址寄存器 | `0x39C` | `0x4002139C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `GPDMA_C6DAR` | GPDMA 通道 6 目标地址寄存器 | `0x3A0` | `0x400213A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `GPDMA_C6LLR` | GPDMA 通道 6 链表地址寄存器 | `0x3CC` | `0x400213CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 GPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 GPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 GPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 GPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 GPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 GPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `GPDMA_C7LBAR` | GPDMA 通道 7 链表基址地址寄存器 | `0x3D0` | `0x400213D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 GPDMA 通道 x） | — |
| `GPDMA_C7FCR` | GPDMA 通道 7 清除标志寄存器 | `0x3DC` | `0x400213DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `GPDMA_C7SR` | GPDMA 通道 7 状态寄存器 | `0x3E0` | `0x400213E0` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[23:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `GPDMA_C7CR` | GPDMA 通道 7 控制寄存器 | `0x3E4` | `0x400213E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `GPDMA_C7TR1` | GPDMA 通道 7 传输寄存器 1 | `0x410` | `0x40021410` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `GPDMA_C7TR2` | GPDMA 通道 7 传输寄存器 2 | `0x414` | `0x40021414` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[6:0] (RW)（GPDMA 硬件请求选择） | — |
| `GPDMA_C7BR1` | GPDMA 通道 7 块寄存器 1 | `0x418` | `0x40021418` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `GPDMA_C7SAR` | GPDMA 通道 7 源地址寄存器 | `0x41C` | `0x4002141C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `GPDMA_C7DAR` | GPDMA 通道 7 目标地址寄存器 | `0x420` | `0x40021420` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `GPDMA_C7LLR` | GPDMA 通道 7 链表地址寄存器 | `0x44C` | `0x4002144C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 GPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 GPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 GPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 GPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 GPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 GPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `GPDMA_C8LBAR` | GPDMA 通道 8 链表基址地址寄存器 | `0x450` | `0x40021450` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 GPDMA 通道 x） | — |
| `GPDMA_C8FCR` | GPDMA 通道 8 清除标志寄存器 | `0x45C` | `0x4002145C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `GPDMA_C8SR` | GPDMA 通道 8 状态寄存器 | `0x460` | `0x40021460` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[23:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `GPDMA_C8CR` | GPDMA 通道 8 控制寄存器 | `0x464` | `0x40021464` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `GPDMA_C8TR1` | GPDMA 通道 8 传输寄存器 1 | `0x490` | `0x40021490` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `GPDMA_C8TR2` | GPDMA 通道 8 传输寄存器 2 | `0x494` | `0x40021494` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[6:0] (RW)（GPDMA 硬件请求选择） | — |
| `GPDMA_C8BR1` | GPDMA 通道 8 块寄存器 1 | `0x498` | `0x40021498` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `GPDMA_C8SAR` | GPDMA 通道 8 源地址寄存器 | `0x49C` | `0x4002149C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `GPDMA_C8DAR` | GPDMA 通道 8 目标地址寄存器 | `0x4A0` | `0x400214A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `GPDMA_C8LLR` | GPDMA 通道 8 链表地址寄存器 | `0x4CC` | `0x400214CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 GPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 GPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 GPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 GPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 GPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 GPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `GPDMA_C9LBAR` | GPDMA 通道 9 链表基址地址寄存器 | `0x4D0` | `0x400214D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 GPDMA 通道 x） | — |
| `GPDMA_C9FCR` | GPDMA 通道 9 清除标志寄存器 | `0x4DC` | `0x400214DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `GPDMA_C9SR` | GPDMA 通道 9 状态寄存器 | `0x4E0` | `0x400214E0` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[23:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `GPDMA_C9CR` | GPDMA 通道 9 控制寄存器 | `0x4E4` | `0x400214E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `GPDMA_C9TR1` | GPDMA 通道 9 传输寄存器 1 | `0x510` | `0x40021510` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `GPDMA_C9TR2` | GPDMA 通道 9 传输寄存器 2 | `0x514` | `0x40021514` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[6:0] (RW)（GPDMA 硬件请求选择） | — |
| `GPDMA_C9BR1` | GPDMA 通道 9 块寄存器 1 | `0x518` | `0x40021518` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `GPDMA_C9SAR` | GPDMA 通道 9 源地址寄存器 | `0x51C` | `0x4002151C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `GPDMA_C9DAR` | GPDMA 通道 9 目标地址寄存器 | `0x520` | `0x40021520` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `GPDMA_C9LLR` | GPDMA 通道 9 链表地址寄存器 | `0x54C` | `0x4002154C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 GPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 GPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 GPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 GPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 GPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 GPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `GPDMA_C10LBAR` | GPDMA 通道 10 链表基址地址寄存器 | `0x550` | `0x40021550` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 GPDMA 通道 x） | — |
| `GPDMA_C10FCR` | GPDMA 通道 10 清除标志寄存器 | `0x55C` | `0x4002155C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `GPDMA_C10SR` | GPDMA 通道 10 状态寄存器 | `0x560` | `0x40021560` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[23:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `GPDMA_C10CR` | GPDMA 通道 10 控制寄存器 | `0x564` | `0x40021564` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `GPDMA_C10TR1` | GPDMA 通道 10 传输寄存器 1 | `0x590` | `0x40021590` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `GPDMA_C10TR2` | GPDMA 通道 10 传输寄存器 2 | `0x594` | `0x40021594` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[6:0] (RW)（GPDMA 硬件请求选择） | — |
| `GPDMA_C10BR1` | GPDMA 通道 10 块寄存器 1 | `0x598` | `0x40021598` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `GPDMA_C10SAR` | GPDMA 通道 10 源地址寄存器 | `0x59C` | `0x4002159C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `GPDMA_C10DAR` | GPDMA 通道 10 目标地址寄存器 | `0x5A0` | `0x400215A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `GPDMA_C10LLR` | GPDMA 通道 10 链表地址寄存器 | `0x5CC` | `0x400215CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 GPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 GPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 GPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 GPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 GPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 GPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `GPDMA_C11LBAR` | GPDMA 通道 11 链表基址地址寄存器 | `0x5D0` | `0x400215D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 GPDMA 通道 x） | — |
| `GPDMA_C11FCR` | GPDMA 通道 11 清除标志寄存器 | `0x5DC` | `0x400215DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `GPDMA_C11SR` | GPDMA 通道 11 状态寄存器 | `0x5E0` | `0x400215E0` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[23:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `GPDMA_C11CR` | GPDMA 通道 11 控制寄存器 | `0x5E4` | `0x400215E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `GPDMA_C11TR1` | GPDMA 通道 11 传输寄存器 1 | `0x610` | `0x40021610` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `GPDMA_C11TR2` | GPDMA 通道 11 传输寄存器 2 | `0x614` | `0x40021614` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[6:0] (RW)（GPDMA 硬件请求选择） | — |
| `GPDMA_C11BR1` | GPDMA 通道 11 块寄存器 1 | `0x618` | `0x40021618` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `GPDMA_C11SAR` | GPDMA 通道 11 源地址寄存器 | `0x61C` | `0x4002161C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `GPDMA_C11DAR` | GPDMA 通道 11 目标地址寄存器 | `0x620` | `0x40021620` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `GPDMA_C11LLR` | GPDMA 通道 11 链表地址寄存器 | `0x64C` | `0x4002164C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 GPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 GPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 GPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 GPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 GPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 GPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `GPDMA_C12LBAR` | GPDMA 通道 12 链表基址地址寄存器 | `0x650` | `0x40021650` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 GPDMA 通道 x） | — |
| `GPDMA_C12FCR` | GPDMA 通道 12 清除标志寄存器 | `0x65C` | `0x4002165C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `GPDMA_C12SR` | GPDMA 通道 12 状态寄存器 | `0x660` | `0x40021660` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[23:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `GPDMA_C12CR` | GPDMA 通道 12 控制寄存器 | `0x664` | `0x40021664` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `GPDMA_C12TR1` | GPDMA 通道 12 传输寄存器 1 | `0x690` | `0x40021690` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `GPDMA_C12TR2` | GPDMA 通道 12 传输寄存器 2 | `0x694` | `0x40021694` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[6:0] (RW)（GPDMA 硬件请求选择） | — |
| `GPDMA_C12BR1` | GPDMA 通道 12 备选块寄存器 1 | `0x698` | `0x40021698` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRDDEC[31] (RW)（待核）、BRSDEC[30] (RW)（待核）、DDEC[29] (RW)（目标地址减量）、SDEC[28] (RW)（源地址减量）、BRC[26:16] (RW)（待核）、BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `GPDMA_C12SAR` | GPDMA 通道 12 源地址寄存器 | `0x69C` | `0x4002169C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `GPDMA_C12DAR` | GPDMA 通道 12 目标地址寄存器 | `0x6A0` | `0x400216A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `GPDMA_C12TR3` | GPDMA 通道 12 传输寄存器 3 | `0x6A4` | `0x400216A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAO[28:16] (RW)（目标地址偏移增量）、SAO[12:0] (RW)（源地址偏移增量） | — |
| `GPDMA_C12BR2` | GPDMA 通道 12 块寄存器 2 | `0x6A8` | `0x400216A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRDAO[31:16] (RW)（待核）、BRSAO[15:0] (RW)（待核） | — |
| `GPDMA_C12LLR` | GPDMA 通道 12 备选链表地址寄存器 | `0x6CC` | `0x400216CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 GPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 GPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 GPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 GPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 GPDMA_CxDAR 寄存器来自存储器）、UT3[26] (RW)（更新 GPDMA_CxTR3 来自存储器）、UB2[25] (RW)（更新 GPDMA_CxBR2 来自存储器）、ULL[16] (RW)（更新 GPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `GPDMA_C13LBAR` | GPDMA 通道 13 链表基址地址寄存器 | `0x6D0` | `0x400216D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 GPDMA 通道 x） | — |
| `GPDMA_C13FCR` | GPDMA 通道 13 清除标志寄存器 | `0x6DC` | `0x400216DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `GPDMA_C13SR` | GPDMA 通道 13 状态寄存器 | `0x6E0` | `0x400216E0` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[23:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `GPDMA_C13CR` | GPDMA 通道 13 控制寄存器 | `0x6E4` | `0x400216E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `GPDMA_C13TR1` | GPDMA 通道 13 传输寄存器 1 | `0x710` | `0x40021710` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `GPDMA_C13TR2` | GPDMA 通道 13 传输寄存器 2 | `0x714` | `0x40021714` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[6:0] (RW)（GPDMA 硬件请求选择） | — |
| `GPDMA_C13BR1` | GPDMA 通道 13 备选块寄存器 1 | `0x718` | `0x40021718` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRDDEC[31] (RW)（待核）、BRSDEC[30] (RW)（待核）、DDEC[29] (RW)（目标地址减量）、SDEC[28] (RW)（源地址减量）、BRC[26:16] (RW)（待核）、BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `GPDMA_C13SAR` | GPDMA 通道 13 源地址寄存器 | `0x71C` | `0x4002171C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `GPDMA_C13DAR` | GPDMA 通道 13 目标地址寄存器 | `0x720` | `0x40021720` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `GPDMA_C13TR3` | GPDMA 通道 13 传输寄存器 3 | `0x724` | `0x40021724` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAO[28:16] (RW)（目标地址偏移增量）、SAO[12:0] (RW)（源地址偏移增量） | — |
| `GPDMA_C13BR2` | GPDMA 通道 13 块寄存器 2 | `0x728` | `0x40021728` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRDAO[31:16] (RW)（待核）、BRSAO[15:0] (RW)（待核） | — |
| `GPDMA_C13LLR` | GPDMA 通道 13 备选链表地址寄存器 | `0x74C` | `0x4002174C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 GPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 GPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 GPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 GPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 GPDMA_CxDAR 寄存器来自存储器）、UT3[26] (RW)（更新 GPDMA_CxTR3 来自存储器）、UB2[25] (RW)（更新 GPDMA_CxBR2 来自存储器）、ULL[16] (RW)（更新 GPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `GPDMA_C14LBAR` | GPDMA 通道 14 链表基址地址寄存器 | `0x750` | `0x40021750` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 GPDMA 通道 x） | — |
| `GPDMA_C14FCR` | GPDMA 通道 14 清除标志寄存器 | `0x75C` | `0x4002175C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `GPDMA_C14SR` | GPDMA 通道 14 状态寄存器 | `0x760` | `0x40021760` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[23:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `GPDMA_C14CR` | GPDMA 通道 14 控制寄存器 | `0x764` | `0x40021764` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `GPDMA_C14TR1` | GPDMA 通道 14 传输寄存器 1 | `0x790` | `0x40021790` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `GPDMA_C14TR2` | GPDMA 通道 14 传输寄存器 2 | `0x794` | `0x40021794` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[6:0] (RW)（GPDMA 硬件请求选择） | — |
| `GPDMA_C14BR1` | GPDMA 通道 14 备选块寄存器 1 | `0x798` | `0x40021798` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRDDEC[31] (RW)（待核）、BRSDEC[30] (RW)（待核）、DDEC[29] (RW)（目标地址减量）、SDEC[28] (RW)（源地址减量）、BRC[26:16] (RW)（待核）、BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `GPDMA_C14SAR` | GPDMA 通道 14 源地址寄存器 | `0x79C` | `0x4002179C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `GPDMA_C14DAR` | GPDMA 通道 14 目标地址寄存器 | `0x7A0` | `0x400217A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `GPDMA_C14TR3` | GPDMA 通道 14 传输寄存器 3 | `0x7A4` | `0x400217A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAO[28:16] (RW)（目标地址偏移增量）、SAO[12:0] (RW)（源地址偏移增量） | — |
| `GPDMA_C14BR2` | GPDMA 通道 14 块寄存器 2 | `0x7A8` | `0x400217A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRDAO[31:16] (RW)（待核）、BRSAO[15:0] (RW)（待核） | — |
| `GPDMA_C14LLR` | GPDMA 通道 14 备选链表地址寄存器 | `0x7CC` | `0x400217CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 GPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 GPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 GPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 GPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 GPDMA_CxDAR 寄存器来自存储器）、UT3[26] (RW)（更新 GPDMA_CxTR3 来自存储器）、UB2[25] (RW)（更新 GPDMA_CxBR2 来自存储器）、ULL[16] (RW)（更新 GPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `GPDMA_C15LBAR` | GPDMA 通道 15 链表基址地址寄存器 | `0x7D0` | `0x400217D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 GPDMA 通道 x） | — |
| `GPDMA_C15FCR` | GPDMA 通道 15 清除标志寄存器 | `0x7DC` | `0x400217DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `GPDMA_C15SR` | GPDMA 通道 15 状态寄存器 | `0x7E0` | `0x400217E0` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[23:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `GPDMA_C15CR` | GPDMA 通道 15 控制寄存器 | `0x7E4` | `0x400217E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `GPDMA_C15TR1` | GPDMA 通道 15 传输寄存器 1 | `0x810` | `0x40021810` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `GPDMA_C15TR2` | GPDMA 通道 15 传输寄存器 2 | `0x814` | `0x40021814` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[6:0] (RW)（GPDMA 硬件请求选择） | — |
| `GPDMA_C15BR1` | GPDMA 通道 15 备选块寄存器 1 | `0x818` | `0x40021818` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRDDEC[31] (RW)（待核）、BRSDEC[30] (RW)（待核）、DDEC[29] (RW)（目标地址减量）、SDEC[28] (RW)（源地址减量）、BRC[26:16] (RW)（待核）、BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `GPDMA_C15SAR` | GPDMA 通道 15 源地址寄存器 | `0x81C` | `0x4002181C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `GPDMA_C15DAR` | GPDMA 通道 15 目标地址寄存器 | `0x820` | `0x40021820` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `GPDMA_C15TR3` | GPDMA 通道 15 传输寄存器 3 | `0x824` | `0x40021824` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAO[28:16] (RW)（目标地址偏移增量）、SAO[12:0] (RW)（源地址偏移增量） | — |
| `GPDMA_C15BR2` | GPDMA 通道 15 块寄存器 2 | `0x828` | `0x40021828` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRDAO[31:16] (RW)（待核）、BRSAO[15:0] (RW)（待核） | — |
| `GPDMA_C15LLR` | GPDMA 通道 15 备选链表地址寄存器 | `0x84C` | `0x4002184C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 GPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 GPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 GPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 GPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 GPDMA_CxDAR 寄存器来自存储器）、UT3[26] (RW)（更新 GPDMA_CxTR3 来自存储器）、UB2[25] (RW)（更新 GPDMA_CxBR2 来自存储器）、ULL[16] (RW)（更新 GPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |

## HPDMA

**模块用途**　高性能 DMA 控制器，按通道组织数据传输。使用源、目的地址和块长度配置数据搬运。

基地址 `0x52000000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `HPDMA_PRIVCFGR` | HPDMA 特权配置寄存器 | `0x004` | `0x52000004` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIV15[15] (RW)（特权状态的通道 x）、PRIV14[14] (RW)（特权状态的通道 x）、PRIV13[13] (RW)（特权状态的通道 x）、PRIV12[12] (RW)（特权状态的通道 x）、PRIV11[11] (RW)（特权状态的通道 x）、PRIV10[10] (RW)（特权状态的通道 x）、PRIV9[9] (RW)（特权状态的通道 x）、PRIV8[8] (RW)（特权状态的通道 x）、PRIV7[7] (RW)（特权状态的通道 x）、PRIV6[6] (RW)（特权状态的通道 x）、PRIV5[5] (RW)（特权状态的通道 x）、PRIV4[4] (RW)（特权状态的通道 x）、PRIV3[3] (RW)（特权状态的通道 x）、PRIV2[2] (RW)（特权状态的通道 x）、PRIV1[1] (RW)（特权状态的通道 x）、PRIV0[0] (RW)（特权状态的通道 x） | — |
| `HPDMA_RCFGLOCKR` | HPDMA 配置锁定寄存器 | `0x008` | `0x52000008` | 32 | — | 0x00000000 / 0xFFFFFFFF | LOCK15[15] (RW)（锁定对应 DMA 通道的特权配置）、LOCK14[14] (RW)（锁定对应 DMA 通道的特权配置）、LOCK13[13] (RW)（锁定对应 DMA 通道的特权配置）、LOCK12[12] (RW)（锁定对应 DMA 通道的特权配置）、LOCK11[11] (RW)（锁定对应 DMA 通道的特权配置）、LOCK10[10] (RW)（锁定对应 DMA 通道的特权配置）、LOCK9[9] (RW)（锁定对应 DMA 通道的特权配置）、LOCK8[8] (RW)（锁定对应 DMA 通道的特权配置）、LOCK7[7] (RW)（锁定对应 DMA 通道的特权配置）、LOCK6[6] (RW)（锁定对应 DMA 通道的特权配置）、LOCK5[5] (RW)（锁定对应 DMA 通道的特权配置）、LOCK4[4] (RW)（锁定对应 DMA 通道的特权配置）、LOCK3[3] (RW)（锁定对应 DMA 通道的特权配置）、LOCK2[2] (RW)（锁定对应 DMA 通道的特权配置）、LOCK1[1] (RW)（锁定对应 DMA 通道的特权配置）、LOCK0[0] (RW)（锁定对应 DMA 通道的特权配置） | — |
| `HPDMA_MISR` | HPDMA 屏蔽后中断状态寄存器 | `0x00C` | `0x5200000C` | 32 | — | 0x00000000 / 0xFFFFFFFF | MIS15[15] (RO)（屏蔽后中断状态的通道 x）、MIS14[14] (RO)（屏蔽后中断状态的通道 x）、MIS13[13] (RO)（屏蔽后中断状态的通道 x）、MIS12[12] (RO)（屏蔽后中断状态的通道 x）、MIS11[11] (RO)（屏蔽后中断状态的通道 x）、MIS10[10] (RO)（屏蔽后中断状态的通道 x）、MIS9[9] (RO)（屏蔽后中断状态的通道 x）、MIS8[8] (RO)（屏蔽后中断状态的通道 x）、MIS7[7] (RO)（屏蔽后中断状态的通道 x）、MIS6[6] (RO)（屏蔽后中断状态的通道 x）、MIS5[5] (RO)（屏蔽后中断状态的通道 x）、MIS4[4] (RO)（屏蔽后中断状态的通道 x）、MIS3[3] (RO)（屏蔽后中断状态的通道 x）、MIS2[2] (RO)（屏蔽后中断状态的通道 x）、MIS1[1] (RO)（屏蔽后中断状态的通道 x）、MIS0[0] (RO)（屏蔽后中断状态的通道 x） | — |
| `HPDMA_C0LBAR` | HPDMA 通道 0 链表基址地址寄存器 | `0x050` | `0x52000050` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 HPDMA 通道 x） | — |
| `HPDMA_C0FCR` | HPDMA 通道 0 清除标志寄存器 | `0x05C` | `0x5200005C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `HPDMA_C0SR` | HPDMA 通道 0 状态寄存器 | `0x060` | `0x52000060` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[24:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `HPDMA_C0CR` | HPDMA 通道 0 控制寄存器 | `0x064` | `0x52000064` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `HPDMA_C0TR1` | HPDMA 通道 0 传输寄存器 1 | `0x090` | `0x52000090` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DWX[28] (RW)（目标端字交换）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `HPDMA_C0TR2` | HPDMA 通道 0 传输寄存器 2 | `0x094` | `0x52000094` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[4:0] (RW)（硬件请求选择） | — |
| `HPDMA_C0BR1` | HPDMA 通道 0 块寄存器 1 | `0x098` | `0x52000098` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `HPDMA_C0SAR` | HPDMA 通道 0 源地址寄存器 | `0x09C` | `0x5200009C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `HPDMA_C0DAR` | HPDMA 通道 0 目标地址寄存器 | `0x0A0` | `0x520000A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `HPDMA_C0LLR` | HPDMA 通道 0 链表地址寄存器 | `0x0CC` | `0x520000CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 HPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 HPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 HPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 HPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 HPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 HPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `HPDMA_C1LBAR` | HPDMA 通道 1 链表基址地址寄存器 | `0x0D0` | `0x520000D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 HPDMA 通道 x） | — |
| `HPDMA_C1FCR` | HPDMA 通道 1 清除标志寄存器 | `0x0DC` | `0x520000DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `HPDMA_C1SR` | HPDMA 通道 1 状态寄存器 | `0x0E0` | `0x520000E0` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[24:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `HPDMA_C1CR` | HPDMA 通道 1 控制寄存器 | `0x0E4` | `0x520000E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `HPDMA_C1TR1` | HPDMA 通道 1 传输寄存器 1 | `0x110` | `0x52000110` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DWX[28] (RW)（目标端字交换）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `HPDMA_C1TR2` | HPDMA 通道 1 传输寄存器 2 | `0x114` | `0x52000114` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[4:0] (RW)（硬件请求选择） | — |
| `HPDMA_C1BR1` | HPDMA 通道 1 块寄存器 1 | `0x118` | `0x52000118` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `HPDMA_C1SAR` | HPDMA 通道 1 源地址寄存器 | `0x11C` | `0x5200011C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `HPDMA_C1DAR` | HPDMA 通道 1 目标地址寄存器 | `0x120` | `0x52000120` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `HPDMA_C1LLR` | HPDMA 通道 1 链表地址寄存器 | `0x14C` | `0x5200014C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 HPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 HPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 HPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 HPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 HPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 HPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `HPDMA_C2LBAR` | HPDMA 通道 2 链表基址地址寄存器 | `0x150` | `0x52000150` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 HPDMA 通道 x） | — |
| `HPDMA_C2FCR` | HPDMA 通道 2 清除标志寄存器 | `0x15C` | `0x5200015C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `HPDMA_C2SR` | HPDMA 通道 2 状态寄存器 | `0x160` | `0x52000160` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[24:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `HPDMA_C2CR` | HPDMA 通道 2 控制寄存器 | `0x164` | `0x52000164` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `HPDMA_C2TR1` | HPDMA 通道 2 传输寄存器 1 | `0x190` | `0x52000190` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DWX[28] (RW)（目标端字交换）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `HPDMA_C2TR2` | HPDMA 通道 2 传输寄存器 2 | `0x194` | `0x52000194` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[4:0] (RW)（硬件请求选择） | — |
| `HPDMA_C2BR1` | HPDMA 通道 2 块寄存器 1 | `0x198` | `0x52000198` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `HPDMA_C2SAR` | HPDMA 通道 2 源地址寄存器 | `0x19C` | `0x5200019C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `HPDMA_C2DAR` | HPDMA 通道 2 目标地址寄存器 | `0x1A0` | `0x520001A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `HPDMA_C2LLR` | HPDMA 通道 2 链表地址寄存器 | `0x1CC` | `0x520001CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 HPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 HPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 HPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 HPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 HPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 HPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `HPDMA_C3LBAR` | HPDMA 通道 3 链表基址地址寄存器 | `0x1D0` | `0x520001D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 HPDMA 通道 x） | — |
| `HPDMA_C3FCR` | HPDMA 通道 3 清除标志寄存器 | `0x1DC` | `0x520001DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `HPDMA_C3SR` | HPDMA 通道 3 状态寄存器 | `0x1E0` | `0x520001E0` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[24:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `HPDMA_C3CR` | HPDMA 通道 3 控制寄存器 | `0x1E4` | `0x520001E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `HPDMA_C3TR1` | HPDMA 通道 3 传输寄存器 1 | `0x210` | `0x52000210` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DWX[28] (RW)（目标端字交换）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `HPDMA_C3TR2` | HPDMA 通道 3 传输寄存器 2 | `0x214` | `0x52000214` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[4:0] (RW)（硬件请求选择） | — |
| `HPDMA_C3BR1` | HPDMA 通道 3 块寄存器 1 | `0x218` | `0x52000218` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `HPDMA_C3SAR` | HPDMA 通道 3 源地址寄存器 | `0x21C` | `0x5200021C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `HPDMA_C3DAR` | HPDMA 通道 3 目标地址寄存器 | `0x220` | `0x52000220` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `HPDMA_C3LLR` | HPDMA 通道 3 链表地址寄存器 | `0x24C` | `0x5200024C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 HPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 HPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 HPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 HPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 HPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 HPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `HPDMA_C4LBAR` | HPDMA 通道 4 链表基址地址寄存器 | `0x250` | `0x52000250` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 HPDMA 通道 x） | — |
| `HPDMA_C4FCR` | HPDMA 通道 4 清除标志寄存器 | `0x25C` | `0x5200025C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `HPDMA_C4SR` | HPDMA 通道 4 状态寄存器 | `0x260` | `0x52000260` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[24:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `HPDMA_C4CR` | HPDMA 通道 4 控制寄存器 | `0x264` | `0x52000264` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `HPDMA_C4TR1` | HPDMA 通道 4 传输寄存器 1 | `0x290` | `0x52000290` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DWX[28] (RW)（目标端字交换）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `HPDMA_C4TR2` | HPDMA 通道 4 传输寄存器 2 | `0x294` | `0x52000294` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[4:0] (RW)（硬件请求选择） | — |
| `HPDMA_C4BR1` | HPDMA 通道 4 块寄存器 1 | `0x298` | `0x52000298` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `HPDMA_C4SAR` | HPDMA 通道 4 源地址寄存器 | `0x29C` | `0x5200029C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `HPDMA_C4DAR` | HPDMA 通道 4 目标地址寄存器 | `0x2A0` | `0x520002A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `HPDMA_C4LLR` | HPDMA 通道 4 链表地址寄存器 | `0x2CC` | `0x520002CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 HPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 HPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 HPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 HPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 HPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 HPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `HPDMA_C5LBAR` | HPDMA 通道 5 链表基址地址寄存器 | `0x2D0` | `0x520002D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 HPDMA 通道 x） | — |
| `HPDMA_C5FCR` | HPDMA 通道 5 清除标志寄存器 | `0x2DC` | `0x520002DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `HPDMA_C5SR` | HPDMA 通道 5 状态寄存器 | `0x2E0` | `0x520002E0` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[24:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `HPDMA_C5CR` | HPDMA 通道 5 控制寄存器 | `0x2E4` | `0x520002E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `HPDMA_C5TR1` | HPDMA 通道 5 传输寄存器 1 | `0x310` | `0x52000310` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DWX[28] (RW)（目标端字交换）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `HPDMA_C5TR2` | HPDMA 通道 5 传输寄存器 2 | `0x314` | `0x52000314` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[4:0] (RW)（硬件请求选择） | — |
| `HPDMA_C5BR1` | HPDMA 通道 5 块寄存器 1 | `0x318` | `0x52000318` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `HPDMA_C5SAR` | HPDMA 通道 5 源地址寄存器 | `0x31C` | `0x5200031C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `HPDMA_C5DAR` | HPDMA 通道 5 目标地址寄存器 | `0x320` | `0x52000320` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `HPDMA_C5LLR` | HPDMA 通道 5 链表地址寄存器 | `0x34C` | `0x5200034C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 HPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 HPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 HPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 HPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 HPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 HPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `HPDMA_C6LBAR` | HPDMA 通道 6 链表基址地址寄存器 | `0x350` | `0x52000350` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 HPDMA 通道 x） | — |
| `HPDMA_C6FCR` | HPDMA 通道 6 清除标志寄存器 | `0x35C` | `0x5200035C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `HPDMA_C6SR` | HPDMA 通道 6 状态寄存器 | `0x360` | `0x52000360` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[24:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `HPDMA_C6CR` | HPDMA 通道 6 控制寄存器 | `0x364` | `0x52000364` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `HPDMA_C6TR1` | HPDMA 通道 6 传输寄存器 1 | `0x390` | `0x52000390` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DWX[28] (RW)（目标端字交换）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `HPDMA_C6TR2` | HPDMA 通道 6 传输寄存器 2 | `0x394` | `0x52000394` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[4:0] (RW)（硬件请求选择） | — |
| `HPDMA_C6BR1` | HPDMA 通道 6 块寄存器 1 | `0x398` | `0x52000398` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `HPDMA_C6SAR` | HPDMA 通道 6 源地址寄存器 | `0x39C` | `0x5200039C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `HPDMA_C6DAR` | HPDMA 通道 6 目标地址寄存器 | `0x3A0` | `0x520003A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `HPDMA_C6LLR` | HPDMA 通道 6 链表地址寄存器 | `0x3CC` | `0x520003CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 HPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 HPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 HPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 HPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 HPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 HPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `HPDMA_C7LBAR` | HPDMA 通道 7 链表基址地址寄存器 | `0x3D0` | `0x520003D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 HPDMA 通道 x） | — |
| `HPDMA_C7FCR` | HPDMA 通道 7 清除标志寄存器 | `0x3DC` | `0x520003DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `HPDMA_C7SR` | HPDMA 通道 7 状态寄存器 | `0x3E0` | `0x520003E0` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[24:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `HPDMA_C7CR` | HPDMA 通道 7 控制寄存器 | `0x3E4` | `0x520003E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `HPDMA_C7TR1` | HPDMA 通道 7 传输寄存器 1 | `0x410` | `0x52000410` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DWX[28] (RW)（目标端字交换）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `HPDMA_C7TR2` | HPDMA 通道 7 传输寄存器 2 | `0x414` | `0x52000414` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[4:0] (RW)（硬件请求选择） | — |
| `HPDMA_C7BR1` | HPDMA 通道 7 块寄存器 1 | `0x418` | `0x52000418` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `HPDMA_C7SAR` | HPDMA 通道 7 源地址寄存器 | `0x41C` | `0x5200041C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `HPDMA_C7DAR` | HPDMA 通道 7 目标地址寄存器 | `0x420` | `0x52000420` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `HPDMA_C7LLR` | HPDMA 通道 7 链表地址寄存器 | `0x44C` | `0x5200044C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 HPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 HPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 HPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 HPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 HPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 HPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `HPDMA_C8LBAR` | HPDMA 通道 8 链表基址地址寄存器 | `0x450` | `0x52000450` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 HPDMA 通道 x） | — |
| `HPDMA_C8FCR` | HPDMA 通道 8 清除标志寄存器 | `0x45C` | `0x5200045C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `HPDMA_C8SR` | HPDMA 通道 8 状态寄存器 | `0x460` | `0x52000460` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[24:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `HPDMA_C8CR` | HPDMA 通道 8 控制寄存器 | `0x464` | `0x52000464` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `HPDMA_C8TR1` | HPDMA 通道 8 传输寄存器 1 | `0x490` | `0x52000490` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DWX[28] (RW)（目标端字交换）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `HPDMA_C8TR2` | HPDMA 通道 8 传输寄存器 2 | `0x494` | `0x52000494` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[4:0] (RW)（硬件请求选择） | — |
| `HPDMA_C8BR1` | HPDMA 通道 8 块寄存器 1 | `0x498` | `0x52000498` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `HPDMA_C8SAR` | HPDMA 通道 8 源地址寄存器 | `0x49C` | `0x5200049C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `HPDMA_C8DAR` | HPDMA 通道 8 目标地址寄存器 | `0x4A0` | `0x520004A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `HPDMA_C8LLR` | HPDMA 通道 8 链表地址寄存器 | `0x4CC` | `0x520004CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 HPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 HPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 HPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 HPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 HPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 HPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `HPDMA_C9LBAR` | HPDMA 通道 9 链表基址地址寄存器 | `0x4D0` | `0x520004D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 HPDMA 通道 x） | — |
| `HPDMA_C9FCR` | HPDMA 通道 9 清除标志寄存器 | `0x4DC` | `0x520004DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `HPDMA_C9SR` | HPDMA 通道 9 状态寄存器 | `0x4E0` | `0x520004E0` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[24:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `HPDMA_C9CR` | HPDMA 通道 9 控制寄存器 | `0x4E4` | `0x520004E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `HPDMA_C9TR1` | HPDMA 通道 9 传输寄存器 1 | `0x510` | `0x52000510` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DWX[28] (RW)（目标端字交换）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `HPDMA_C9TR2` | HPDMA 通道 9 传输寄存器 2 | `0x514` | `0x52000514` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[4:0] (RW)（硬件请求选择） | — |
| `HPDMA_C9BR1` | HPDMA 通道 9 块寄存器 1 | `0x518` | `0x52000518` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `HPDMA_C9SAR` | HPDMA 通道 9 源地址寄存器 | `0x51C` | `0x5200051C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `HPDMA_C9DAR` | HPDMA 通道 9 目标地址寄存器 | `0x520` | `0x52000520` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `HPDMA_C9LLR` | HPDMA 通道 9 链表地址寄存器 | `0x54C` | `0x5200054C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 HPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 HPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 HPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 HPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 HPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 HPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `HPDMA_C10LBAR` | HPDMA 通道 10 链表基址地址寄存器 | `0x550` | `0x52000550` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 HPDMA 通道 x） | — |
| `HPDMA_C10FCR` | HPDMA 通道 10 清除标志寄存器 | `0x55C` | `0x5200055C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `HPDMA_C10SR` | HPDMA 通道 10 状态寄存器 | `0x560` | `0x52000560` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[24:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `HPDMA_C10CR` | HPDMA 通道 10 控制寄存器 | `0x564` | `0x52000564` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `HPDMA_C10TR1` | HPDMA 通道 10 传输寄存器 1 | `0x590` | `0x52000590` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DWX[28] (RW)（目标端字交换）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `HPDMA_C10TR2` | HPDMA 通道 10 传输寄存器 2 | `0x594` | `0x52000594` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[4:0] (RW)（硬件请求选择） | — |
| `HPDMA_C10BR1` | HPDMA 通道 10 块寄存器 1 | `0x598` | `0x52000598` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `HPDMA_C10SAR` | HPDMA 通道 10 源地址寄存器 | `0x59C` | `0x5200059C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `HPDMA_C10DAR` | HPDMA 通道 10 目标地址寄存器 | `0x5A0` | `0x520005A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `HPDMA_C10LLR` | HPDMA 通道 10 链表地址寄存器 | `0x5CC` | `0x520005CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 HPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 HPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 HPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 HPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 HPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 HPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `HPDMA_C11LBAR` | HPDMA 通道 11 链表基址地址寄存器 | `0x5D0` | `0x520005D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 HPDMA 通道 x） | — |
| `HPDMA_C11FCR` | HPDMA 通道 11 清除标志寄存器 | `0x5DC` | `0x520005DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `HPDMA_C11SR` | HPDMA 通道 11 状态寄存器 | `0x5E0` | `0x520005E0` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[24:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `HPDMA_C11CR` | HPDMA 通道 11 控制寄存器 | `0x5E4` | `0x520005E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `HPDMA_C11TR1` | HPDMA 通道 11 传输寄存器 1 | `0x610` | `0x52000610` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DWX[28] (RW)（目标端字交换）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `HPDMA_C11TR2` | HPDMA 通道 11 传输寄存器 2 | `0x614` | `0x52000614` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[4:0] (RW)（硬件请求选择） | — |
| `HPDMA_C11BR1` | HPDMA 通道 11 块寄存器 1 | `0x618` | `0x52000618` | 32 | — | 0x00000000 / 0xFFFFFFFF | BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `HPDMA_C11SAR` | HPDMA 通道 11 源地址寄存器 | `0x61C` | `0x5200061C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `HPDMA_C11DAR` | HPDMA 通道 11 目标地址寄存器 | `0x620` | `0x52000620` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `HPDMA_C11LLR` | HPDMA 通道 11 链表地址寄存器 | `0x64C` | `0x5200064C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 HPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 HPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 HPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 HPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 HPDMA_CxDAR 寄存器来自存储器）、ULL[16] (RW)（更新 HPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `HPDMA_C12LBAR` | HPDMA 通道 12 链表基址地址寄存器 | `0x650` | `0x52000650` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 HPDMA 通道 x） | — |
| `HPDMA_C12FCR` | HPDMA 通道 12 清除标志寄存器 | `0x65C` | `0x5200065C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `HPDMA_C12SR` | HPDMA 通道 12 状态寄存器 | `0x660` | `0x52000660` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[24:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `HPDMA_C12CR` | HPDMA 通道 12 控制寄存器 | `0x664` | `0x52000664` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `HPDMA_C12TR1` | HPDMA 通道 12 传输寄存器 1 | `0x690` | `0x52000690` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DWX[28] (RW)（目标端字交换）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `HPDMA_C12TR2` | HPDMA 通道 12 传输寄存器 2 | `0x694` | `0x52000694` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[4:0] (RW)（硬件请求选择） | — |
| `HPDMA_C12BR1` | HPDMA 通道 12 备选块寄存器 1 | `0x698` | `0x52000698` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRDDEC[31] (RW)（待核）、BRSDEC[30] (RW)（待核）、DDEC[29] (RW)（目标地址减量）、SDEC[28] (RW)（源地址减量）、BRC[26:16] (RW)（待核）、BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `HPDMA_C12SAR` | HPDMA 通道 12 源地址寄存器 | `0x69C` | `0x5200069C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `HPDMA_C12DAR` | HPDMA 通道 12 目标地址寄存器 | `0x6A0` | `0x520006A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `HPDMA_C12TR3` | HPDMA 通道 12 传输寄存器 3 | `0x6A4` | `0x520006A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAO[28:16] (RW)（目标地址偏移增量）、SAO[12:0] (RW)（源地址偏移增量） | — |
| `HPDMA_C12BR2` | HPDMA 通道 12 块寄存器 2 | `0x6A8` | `0x520006A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRDAO[31:16] (RW)（待核）、BRSAO[15:0] (RW)（待核） | — |
| `HPDMA_C12LLR` | HPDMA 通道 12 备选链表地址寄存器 | `0x6CC` | `0x520006CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 HPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 HPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 HPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 HPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 HPDMA_CxDAR 寄存器来自存储器）、UT3[26] (RW)（更新 HPDMA_CxTR3 来自存储器）、UB2[25] (RW)（更新 HPDMA_CxBR2 来自存储器）、ULL[16] (RW)（更新 HPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `HPDMA_C13LBAR` | HPDMA 通道 13 链表基址地址寄存器 | `0x6D0` | `0x520006D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 HPDMA 通道 x） | — |
| `HPDMA_C13FCR` | HPDMA 通道 13 清除标志寄存器 | `0x6DC` | `0x520006DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `HPDMA_C13SR` | HPDMA 通道 13 状态寄存器 | `0x6E0` | `0x520006E0` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[24:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `HPDMA_C13CR` | HPDMA 通道 13 控制寄存器 | `0x6E4` | `0x520006E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `HPDMA_C13TR1` | HPDMA 通道 13 传输寄存器 1 | `0x710` | `0x52000710` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DWX[28] (RW)（目标端字交换）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `HPDMA_C13TR2` | HPDMA 通道 13 传输寄存器 2 | `0x714` | `0x52000714` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[4:0] (RW)（硬件请求选择） | — |
| `HPDMA_C13BR1` | HPDMA 通道 13 备选块寄存器 1 | `0x718` | `0x52000718` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRDDEC[31] (RW)（待核）、BRSDEC[30] (RW)（待核）、DDEC[29] (RW)（目标地址减量）、SDEC[28] (RW)（源地址减量）、BRC[26:16] (RW)（待核）、BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `HPDMA_C13SAR` | HPDMA 通道 13 源地址寄存器 | `0x71C` | `0x5200071C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `HPDMA_C13DAR` | HPDMA 通道 13 目标地址寄存器 | `0x720` | `0x52000720` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `HPDMA_C13TR3` | HPDMA 通道 13 传输寄存器 3 | `0x724` | `0x52000724` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAO[28:16] (RW)（目标地址偏移增量）、SAO[12:0] (RW)（源地址偏移增量） | — |
| `HPDMA_C13BR2` | HPDMA 通道 13 块寄存器 2 | `0x728` | `0x52000728` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRDAO[31:16] (RW)（待核）、BRSAO[15:0] (RW)（待核） | — |
| `HPDMA_C13LLR` | HPDMA 通道 13 备选链表地址寄存器 | `0x74C` | `0x5200074C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 HPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 HPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 HPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 HPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 HPDMA_CxDAR 寄存器来自存储器）、UT3[26] (RW)（更新 HPDMA_CxTR3 来自存储器）、UB2[25] (RW)（更新 HPDMA_CxBR2 来自存储器）、ULL[16] (RW)（更新 HPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `HPDMA_C14LBAR` | HPDMA 通道 14 链表基址地址寄存器 | `0x750` | `0x52000750` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 HPDMA 通道 x） | — |
| `HPDMA_C14FCR` | HPDMA 通道 14 清除标志寄存器 | `0x75C` | `0x5200075C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `HPDMA_C14SR` | HPDMA 通道 14 状态寄存器 | `0x760` | `0x52000760` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[24:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `HPDMA_C14CR` | HPDMA 通道 14 控制寄存器 | `0x764` | `0x52000764` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `HPDMA_C14TR1` | HPDMA 通道 14 传输寄存器 1 | `0x790` | `0x52000790` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DWX[28] (RW)（目标端字交换）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `HPDMA_C14TR2` | HPDMA 通道 14 传输寄存器 2 | `0x794` | `0x52000794` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[4:0] (RW)（硬件请求选择） | — |
| `HPDMA_C14BR1` | HPDMA 通道 14 备选块寄存器 1 | `0x798` | `0x52000798` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRDDEC[31] (RW)（待核）、BRSDEC[30] (RW)（待核）、DDEC[29] (RW)（目标地址减量）、SDEC[28] (RW)（源地址减量）、BRC[26:16] (RW)（待核）、BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `HPDMA_C14SAR` | HPDMA 通道 14 源地址寄存器 | `0x79C` | `0x5200079C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `HPDMA_C14DAR` | HPDMA 通道 14 目标地址寄存器 | `0x7A0` | `0x520007A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `HPDMA_C14TR3` | HPDMA 通道 14 传输寄存器 3 | `0x7A4` | `0x520007A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAO[28:16] (RW)（目标地址偏移增量）、SAO[12:0] (RW)（源地址偏移增量） | — |
| `HPDMA_C14BR2` | HPDMA 通道 14 块寄存器 2 | `0x7A8` | `0x520007A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRDAO[31:16] (RW)（待核）、BRSAO[15:0] (RW)（待核） | — |
| `HPDMA_C14LLR` | HPDMA 通道 14 备选链表地址寄存器 | `0x7CC` | `0x520007CC` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 HPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 HPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 HPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 HPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 HPDMA_CxDAR 寄存器来自存储器）、UT3[26] (RW)（更新 HPDMA_CxTR3 来自存储器）、UB2[25] (RW)（更新 HPDMA_CxBR2 来自存储器）、ULL[16] (RW)（更新 HPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |
| `HPDMA_C15LBAR` | HPDMA 通道 15 链表基址地址寄存器 | `0x7D0` | `0x520007D0` | 32 | — | 0x00000000 / 0xFFFFFFFF | LBA[31:16] (RW)（链表基址地址的 HPDMA 通道 x） | — |
| `HPDMA_C15FCR` | HPDMA 通道 15 清除标志寄存器 | `0x7DC` | `0x520007DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | TOF[14] (WO)（触发溢出清除标志）、SUSPF[13] (WO)（完成挂起清除标志）、USEF[12] (WO)（用户设置错误清除标志）、ULEF[11] (WO)（清除链表更新错误标志）、DTEF[10] (WO)（数据传输错误清除标志）、HTF[9] (WO)（半传输清除标志）、TCF[8] (WO)（传输完成清除标志） | — |
| `HPDMA_C15SR` | HPDMA 通道 15 状态寄存器 | `0x7E0` | `0x520007E0` | 32 | — | 0x00000001 / 0xFFFFFFFF | FIFOL[24:16] (RO)（FIFO 当前水位）、TOF[14] (RO)（触发溢出标志）、SUSPF[13] (RO)（完成挂起标志）、USEF[12] (RO)（用户设置错误标志）、ULEF[11] (RO)（链表更新错误标志）、DTEF[10] (RO)（数据传输错误标志）、HTF[9] (RO)（半传输标志）、TCF[8] (RO)（传输完成标志）、IDLEF[0] (RO)（通道空闲标志） | — |
| `HPDMA_C15CR` | HPDMA 通道 15 控制寄存器 | `0x7E4` | `0x520007E4` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIO[23:22] (RW)（通道仲裁优先级）、LAP[17] (RW)（链表读取所用的主端口选择）、LSM[16] (RW)（链表执行步进模式）、TOIE[14] (RW)（触发溢出中断使能）、SUSPIE[13] (RW)（完成挂起中断使能）、USEIE[12] (RW)（用户设置错误中断使能）、ULEIE[11] (RW)（更新链表时发生传输错误的中断使能）、DTEIE[10] (RW)（数据传输错误中断使能）、HTIE[9] (RW)（半传输完成中断使能）、TCIE[8] (RW)（传输完成中断使能）、SUSP[2] (RW)（挂起）、RESET[1] (WO)（复位）、EN[0] (RW)（使能） | — |
| `HPDMA_C15TR1` | HPDMA 通道 15 传输寄存器 1 | `0x810` | `0x52000810` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAP[30] (RW)（目标传输分配端口）、DWX[28] (RW)（目标端字交换）、DHX[27] (RW)（目标端半字交换）、DBX[26] (RW)（目标端字节交换）、DBL_1[25:20] (RW)（目标突发长度减一）、DINC[19] (RW)（目标地址递增配置）、DDW_LOG2[17:16] (RW)（目标传输数据宽度编码）、SAP[14] (RW)（源传输分配端口）、SBX[13] (RW)（源端字节交换）、PAM[12:11] (RW)（填充/对齐模式）、SBL_1[9:4] (RW)（源突发长度减一）、SINC[3] (RW)（源地址递增配置）、SDW_LOG2[1:0] (RW)（源传输数据宽度编码） | — |
| `HPDMA_C15TR2` | HPDMA 通道 15 传输寄存器 2 | `0x814` | `0x52000814` | 32 | — | 0x00000000 / 0xFFFFFFFF | TCEM[31:30] (RW)（传输完成事件模式）、TRIGPOL[25:24] (RW)（触发事件极性）、TRIGSEL[21:16] (RW)（触发事件输入选择）、TRIGM[15:14] (RW)（触发模式）、PFREQ[12] (RW)（外设流控模式下的硬件请求配置）、BREQ[11] (RW)（块硬件请求）、DREQ[10] (RW)（目标硬件请求）、SWREQ[9] (RW)（软件请求）、REQSEL[4:0] (RW)（硬件请求选择） | — |
| `HPDMA_C15BR1` | HPDMA 通道 15 备选块寄存器 1 | `0x818` | `0x52000818` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRDDEC[31] (RW)（待核）、BRSDEC[30] (RW)（待核）、DDEC[29] (RW)（目标地址减量）、SDEC[28] (RW)（源地址减量）、BRC[26:16] (RW)（待核）、BNDT[15:0] (RW)（块数量数据字节至传输来自源） | — |
| `HPDMA_C15SAR` | HPDMA 通道 15 源地址寄存器 | `0x81C` | `0x5200081C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SA[31:0] (RW)（源地址） | — |
| `HPDMA_C15DAR` | HPDMA 通道 15 目标地址寄存器 | `0x820` | `0x52000820` | 32 | — | 0x00000000 / 0xFFFFFFFF | DA[31:0] (RW)（目标地址） | — |
| `HPDMA_C15TR3` | HPDMA 通道 15 传输寄存器 3 | `0x824` | `0x52000824` | 32 | — | 0x00000000 / 0xFFFFFFFF | DAO[28:16] (RW)（目标地址偏移增量）、SAO[12:0] (RW)（源地址偏移增量） | — |
| `HPDMA_C15BR2` | HPDMA 通道 15 块寄存器 2 | `0x828` | `0x52000828` | 32 | — | 0x00000000 / 0xFFFFFFFF | BRDAO[31:16] (RW)（待核）、BRSAO[15:0] (RW)（待核） | — |
| `HPDMA_C15LLR` | HPDMA 通道 15 备选链表地址寄存器 | `0x84C` | `0x5200084C` | 32 | — | 0x00000000 / 0xFFFFFFFF | UT1[31] (RW)（更新 HPDMA_CxTR1 来自存储器）、UT2[30] (RW)（更新 HPDMA_CxTR2 来自存储器）、UB1[29] (RW)（更新 HPDMA_CxBR1 来自存储器）、USA[28] (RW)（更新 HPDMA_CxSAR 来自存储器）、UDA[27] (RW)（更新 HPDMA_CxDAR 寄存器来自存储器）、UT3[26] (RW)（更新 HPDMA_CxTR3 来自存储器）、UB2[25] (RW)（更新 HPDMA_CxBR2 来自存储器）、ULL[16] (RW)（更新 HPDMA_CxLLR 寄存器来自存储器）、LA[15:2] (RW)（下一链表项地址的低位） | — |

## ICACHE

**模块用途**　指令缓存控制器，管理缓存使能、失效、监测和地址区域配置。

基地址 `0x52015000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `ICACHE_CR` | ICACHE 控制寄存器 | `0x000` | `0x52015000` | 32 | — | 0x00000004 / 0xFFFFFFFF | MISSMRST[19] (RW)（未命中监测复位）、HITMRST[18] (RW)（命中监测复位）、MISSMEN[17] (RW)（未命中监测使能）、HITMEN[16] (RW)（命中监测使能）、WAYSEL[2] (RW)（待核）、CACHEINV[1] (WO)（缓存失效）、EN[0] (RW)（使能） | — |
| `ICACHE_SR` | ICACHE 状态寄存器 | `0x004` | `0x52015004` | 32 | — | 0x00000001 / 0xFFFFFFFF | ERRF[2] (RO)（缓存错误标志）、BSYENDF[1] (RO)（忙结束标志）、BUSYF[0] (RO)（忙标志） | — |
| `ICACHE_IER` | ICACHE 中断使能寄存器 | `0x008` | `0x52015008` | 32 | — | 0x00000000 / 0xFFFFFFFF | ERRIE[2] (RW)（中断使能的缓存错误）、BSYENDIE[1] (RW)（中断使能的忙结束） | — |
| `ICACHE_FCR` | ICACHE 清除标志寄存器 | `0x00C` | `0x5201500C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CERRF[2] (WO)（清除缓存错误标志）、CBSYENDF[1] (WO)（清除忙结束标志） | — |
| `ICACHE_HMONR` | ICACHE 命中监测寄存器 | `0x010` | `0x52015010` | 32 | — | 0x00000000 / 0xFFFFFFFF | HITMON[31:0] (RO)（缓存命中监测计数器） | — |
| `ICACHE_MMONR` | ICACHE 未命中监测寄存器 | `0x014` | `0x52015014` | 32 | — | 0x00000000 / 0xFFFFFFFF | MISSMON[15:0] (RO)（缓存未命中监测计数器） | — |

## RAMCFG

**模块用途**　RAM 错误监测相关寄存器块。该 SVD 视图列出全局中断及监测器的状态、错误地址和数据。

基地址 `0x58027000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `RAMECC_IER` | RAMECC 中断使能寄存器 | `0x000` | `0x58027000` | 32 | — | 0x00000000 / 0xFFFFFFFF | GECCDEBWIE[3] (RW)（待核）、GECCDEIE[2] (RW)（待核）、GECCSEIE[1] (RW)（全局 ECC 单次错误中断使能）、GIE[0] (RW)（全局中断使能） | — |
| `RAMECC_M1CR` | RAMECC 监测 1 配置寄存器 | `0x020` | `0x58027020` | 32 | — | 0x00000000 / 0xFFFFFFFF | ECCTEA[17:16] (RW)（ECC 测试 ECC 访问）、ECCDEBWCEN[8] (RW)（待核）、ECCDECEN[7] (RW)（待核）、ECCSECEN[6] (RW)（ECC 单次错误计数器使能）、ECCELEN[5] (RW)（待核）、ECCDEBWIE[4] (RW)（待核）、ECCDEIE[3] (RW)（待核）、ECCSEIE[2] (RW)（ECC 单次错误中断使能） | — |
| `RAMECC_M1SR` | RAMECC 监测 1 状态寄存器 | `0x024` | `0x58027024` | 32 | — | 0x00000000 / 0xFFFFFFFF | DEBWDF[2] (RW)（待核）、DEDF[1] (RW)（待核）、SEDCF[0] (RW)（待核） | — |
| `RAMECC_M1FAR` | RAMECC 监测 1 发生错误的地址寄存器 | `0x028` | `0x58027028` | 32 | — | 0x00000000 / 0xFFFFFFFF | FADD[31:0] (RO)（ECC 错误发生错误的地址） | — |
| `RAMECC_M1FDRL` | RAMECC 监测 1 发生错误的数据低位寄存器 | `0x02C` | `0x5802702C` | 32 | — | 0x00000000 / 0xFFFFFFFF | FDATAL[31:0] (RO)（发生错误的数据低位） | — |
| `RAMECC_M1FDRH` | RAMECC 监测 1 发生错误的数据高位寄存器 | `0x030` | `0x58027030` | 32 | — | 0x00000000 / 0xFFFFFFFF | FDATAH[31:0] (RO)（发生错误的数据高位 (64-位存储器)） | — |
| `RAMECC_M1FECR` | RAMECC 监测 1 发生错误的 ECC 错误编码寄存器 | `0x034` | `0x58027034` | 32 | — | 0x00000000 / 0xFFFFFFFF | FEC[31:0] (RO)（发生错误的错误编码） | — |
| `RAMECC_M2CR` | RAMECC 监测 2 配置寄存器 | `0x040` | `0x58027040` | 32 | — | 0x00000000 / 0xFFFFFFFF | ECCTEA[17:16] (RW)（ECC 测试 ECC 访问）、ECCDEBWCEN[8] (RW)（待核）、ECCDECEN[7] (RW)（待核）、ECCSECEN[6] (RW)（ECC 单次错误计数器使能）、ECCELEN[5] (RW)（待核）、ECCDEBWIE[4] (RW)（待核）、ECCDEIE[3] (RW)（待核）、ECCSEIE[2] (RW)（ECC 单次错误中断使能） | — |
| `RAMECC_M2SR` | RAMECC 监测 2 状态寄存器 | `0x044` | `0x58027044` | 32 | — | 0x00000000 / 0xFFFFFFFF | DEBWDF[2] (RW)（待核）、DEDF[1] (RW)（待核）、SEDCF[0] (RW)（待核） | — |
| `RAMECC_M2FAR` | RAMECC 监测 2 发生错误的地址寄存器 | `0x048` | `0x58027048` | 32 | — | 0x00000000 / 0xFFFFFFFF | FADD[31:0] (RO)（ECC 错误发生错误的地址） | — |
| `RAMECC_M2FDRL` | RAMECC 监测 2 发生错误的数据低位寄存器 | `0x04C` | `0x5802704C` | 32 | — | 0x00000000 / 0xFFFFFFFF | FDATAL[31:0] (RO)（发生错误的数据低位） | — |
| `RAMECC_M2FDRH` | RAMECC 监测 2 发生错误的数据高位寄存器 | `0x050` | `0x58027050` | 32 | — | 0x00000000 / 0xFFFFFFFF | FDATAH[31:0] (RO)（发生错误的数据高位 (64-位存储器)） | — |
| `RAMECC_M2FECR` | RAMECC 监测 2 发生错误的 ECC 错误编码寄存器 | `0x054` | `0x58027054` | 32 | — | 0x00000000 / 0xFFFFFFFF | FEC[31:0] (RO)（发生错误的错误编码） | — |
| `RAMECC_M3CR` | RAMECC 监测 3 配置寄存器 | `0x060` | `0x58027060` | 32 | — | 0x00000000 / 0xFFFFFFFF | ECCTEA[17:16] (RW)（ECC 测试 ECC 访问）、ECCDEBWCEN[8] (RW)（待核）、ECCDECEN[7] (RW)（待核）、ECCSECEN[6] (RW)（ECC 单次错误计数器使能）、ECCELEN[5] (RW)（待核）、ECCDEBWIE[4] (RW)（待核）、ECCDEIE[3] (RW)（待核）、ECCSEIE[2] (RW)（ECC 单次错误中断使能） | — |
| `RAMECC_M3SR` | RAMECC 监测 3 状态寄存器 | `0x064` | `0x58027064` | 32 | — | 0x00000000 / 0xFFFFFFFF | DEBWDF[2] (RW)（待核）、DEDF[1] (RW)（待核）、SEDCF[0] (RW)（待核） | — |
| `RAMECC_M3FAR` | RAMECC 监测 3 发生错误的地址寄存器 | `0x068` | `0x58027068` | 32 | — | 0x00000000 / 0xFFFFFFFF | FADD[31:0] (RO)（ECC 错误发生错误的地址） | — |
| `RAMECC_M3FDRL` | RAMECC 监测 3 发生错误的数据低位寄存器 | `0x06C` | `0x5802706C` | 32 | — | 0x00000000 / 0xFFFFFFFF | FDATAL[31:0] (RO)（发生错误的数据低位） | — |
| `RAMECC_M3FDRH` | RAMECC 监测 3 发生错误的数据高位寄存器 | `0x070` | `0x58027070` | 32 | — | 0x00000000 / 0xFFFFFFFF | FDATAH[31:0] (RO)（发生错误的数据高位 (64-位存储器)） | — |
| `RAMECC_M3FECR` | RAMECC 监测 3 发生错误的 ECC 错误编码寄存器 | `0x074` | `0x58027074` | 32 | — | 0x00000000 / 0xFFFFFFFF | FEC[31:0] (RO)（发生错误的错误编码） | — |
| `RAMECC_M4CR` | RAMECC 监测 4 配置寄存器 | `0x080` | `0x58027080` | 32 | — | 0x00000000 / 0xFFFFFFFF | ECCTEA[17:16] (RW)（ECC 测试 ECC 访问）、ECCDEBWCEN[8] (RW)（待核）、ECCDECEN[7] (RW)（待核）、ECCSECEN[6] (RW)（ECC 单次错误计数器使能）、ECCELEN[5] (RW)（待核）、ECCDEBWIE[4] (RW)（待核）、ECCDEIE[3] (RW)（待核）、ECCSEIE[2] (RW)（ECC 单次错误中断使能） | — |
| `RAMECC_M4SR` | RAMECC 监测 4 状态寄存器 | `0x084` | `0x58027084` | 32 | — | 0x00000000 / 0xFFFFFFFF | DEBWDF[2] (RW)（待核）、DEDF[1] (RW)（待核）、SEDCF[0] (RW)（待核） | — |
| `RAMECC_M4FAR` | RAMECC 监测 4 发生错误的地址寄存器 | `0x088` | `0x58027088` | 32 | — | 0x00000000 / 0xFFFFFFFF | FADD[31:0] (RO)（ECC 错误发生错误的地址） | — |
| `RAMECC_M4FDRL` | RAMECC 监测 4 发生错误的数据低位寄存器 | `0x08C` | `0x5802708C` | 32 | — | 0x00000000 / 0xFFFFFFFF | FDATAL[31:0] (RO)（发生错误的数据低位） | — |
| `RAMECC_M4FDRH` | RAMECC 监测 4 发生错误的数据高位寄存器 | `0x090` | `0x58027090` | 32 | — | 0x00000000 / 0xFFFFFFFF | FDATAH[31:0] (RO)（发生错误的数据高位 (64-位存储器)） | — |
| `RAMECC_M4FECR` | RAMECC 监测 4 发生错误的 ECC 错误编码寄存器 | `0x094` | `0x58027094` | 32 | — | 0x00000000 / 0xFFFFFFFF | FEC[31:0] (RO)（发生错误的错误编码） | — |
| `RAMECC_M5CR` | RAMECC 监测 5 配置寄存器 | `0x0A0` | `0x580270A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | ECCTEA[17:16] (RW)（ECC 测试 ECC 访问）、ECCDEBWCEN[8] (RW)（待核）、ECCDECEN[7] (RW)（待核）、ECCSECEN[6] (RW)（ECC 单次错误计数器使能）、ECCELEN[5] (RW)（待核）、ECCDEBWIE[4] (RW)（待核）、ECCDEIE[3] (RW)（待核）、ECCSEIE[2] (RW)（ECC 单次错误中断使能） | — |
| `RAMECC_M5SR` | RAMECC 监测 5 状态寄存器 | `0x0A4` | `0x580270A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | DEBWDF[2] (RW)（待核）、DEDF[1] (RW)（待核）、SEDCF[0] (RW)（待核） | — |
| `RAMECC_M5FAR` | RAMECC 监测 5 发生错误的地址寄存器 | `0x0A8` | `0x580270A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | FADD[31:0] (RO)（ECC 错误发生错误的地址） | — |
| `RAMECC_M5FDRL` | RAMECC 监测 5 发生错误的数据低位寄存器 | `0x0AC` | `0x580270AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | FDATAL[31:0] (RO)（发生错误的数据低位） | — |
| `RAMECC_M5FDRH` | RAMECC 监测 5 发生错误的数据高位寄存器 | `0x0B0` | `0x580270B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | FDATAH[31:0] (RO)（发生错误的数据高位 (64-位存储器)） | — |
| `RAMECC_M5FECR` | RAMECC 监测 5 发生错误的 ECC 错误编码寄存器 | `0x0B4` | `0x580270B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | FEC[31:0] (RO)（发生错误的错误编码） | — |

## RAMECC1

**模块用途**　RAM ECC 监测全局控制，可配置错误事件的中断。具体故障信息查看各监测器。

基地址 `0x52009000` · CMSIS 补表

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `IER` | 配置 RAM ECC 全局错误中断 | `0x000` | `0x52009000` | 32 | — | — / — | GECCDEBWIE[3]（待核）、GECCDEIE[2]（待核）、GECCSEIE[1]（待核）、GIE[0]（待核） | — |

## RAMECC1_Monitor0

**模块用途**　独立的 RAM ECC 监测通道，记录被监测存储区的错误类型、地址、数据与校验信息。

基地址 `0x52009020` · CMSIS 补表

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `CR` | 配置 RAM ECC 监测通道 | `0x000` | `0x52009020` | 32 | — | — / — | ECCELEN[5]（错误记录锁存使能）、ECCDEBWIE[4]（字节写期间双比特错误中断使能）、ECCDEIE[3]（双比特错误中断使能）、ECCSEIE[2]（单比特错误中断使能） | — |
| `SR` | 查看 RAM ECC 错误状态 | `0x004` | `0x52009024` | 32 | — | — / — | DEBWDF[2]（字节写时检测到双比特错误）、DEDF[1]（检测到双比特错误）、SEDCF[0]（检测到并纠正单比特错误） | — |
| `FAR` | 错误发生地址 | `0x008` | `0x52009028` | 32 | — | — / — | FADD[31:0]（待核） | — |
| `FDRL` | 错误数据低字 | `0x00C` | `0x5200902C` | 32 | — | — / — | FDATAL[31:0]（待核） | — |
| `FDRH` | 错误数据高字 | `0x010` | `0x52009030` | 32 | — | — / — | FDATAH[31:0]（待核） | — |
| `FECR` | 错误校验码 | `0x014` | `0x52009034` | 32 | — | — / — | FEC[31:0]（待核） | — |

## RAMECC1_Monitor1

**模块用途**　独立的 RAM ECC 监测通道，记录被监测存储区的错误类型、地址、数据与校验信息。

基地址 `0x52009040` · CMSIS 补表

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `CR` | 配置 RAM ECC 监测通道 | `0x000` | `0x52009040` | 32 | — | — / — | ECCELEN[5]（错误记录锁存使能）、ECCDEBWIE[4]（字节写期间双比特错误中断使能）、ECCDEIE[3]（双比特错误中断使能）、ECCSEIE[2]（单比特错误中断使能） | — |
| `SR` | 查看 RAM ECC 错误状态 | `0x004` | `0x52009044` | 32 | — | — / — | DEBWDF[2]（字节写时检测到双比特错误）、DEDF[1]（检测到双比特错误）、SEDCF[0]（检测到并纠正单比特错误） | — |
| `FAR` | 错误发生地址 | `0x008` | `0x52009048` | 32 | — | — / — | FADD[31:0]（待核） | — |
| `FDRL` | 错误数据低字 | `0x00C` | `0x5200904C` | 32 | — | — / — | FDATAL[31:0]（待核） | — |
| `FDRH` | 错误数据高字 | `0x010` | `0x52009050` | 32 | — | — / — | FDATAH[31:0]（待核） | — |
| `FECR` | 错误校验码 | `0x014` | `0x52009054` | 32 | — | — / — | FEC[31:0]（待核） | — |

## RAMECC1_Monitor2

**模块用途**　独立的 RAM ECC 监测通道，记录被监测存储区的错误类型、地址、数据与校验信息。

基地址 `0x52009060` · CMSIS 补表

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `CR` | 配置 RAM ECC 监测通道 | `0x000` | `0x52009060` | 32 | — | — / — | ECCELEN[5]（错误记录锁存使能）、ECCDEBWIE[4]（字节写期间双比特错误中断使能）、ECCDEIE[3]（双比特错误中断使能）、ECCSEIE[2]（单比特错误中断使能） | — |
| `SR` | 查看 RAM ECC 错误状态 | `0x004` | `0x52009064` | 32 | — | — / — | DEBWDF[2]（字节写时检测到双比特错误）、DEDF[1]（检测到双比特错误）、SEDCF[0]（检测到并纠正单比特错误） | — |
| `FAR` | 错误发生地址 | `0x008` | `0x52009068` | 32 | — | — / — | FADD[31:0]（待核） | — |
| `FDRL` | 错误数据低字 | `0x00C` | `0x5200906C` | 32 | — | — / — | FDATAL[31:0]（待核） | — |
| `FDRH` | 错误数据高字 | `0x010` | `0x52009070` | 32 | — | — / — | FDATAH[31:0]（待核） | — |
| `FECR` | 错误校验码 | `0x014` | `0x52009074` | 32 | — | — / — | FEC[31:0]（待核） | — |

## RAMECC1_Monitor3

**模块用途**　独立的 RAM ECC 监测通道，记录被监测存储区的错误类型、地址、数据与校验信息。

基地址 `0x52009080` · CMSIS 补表

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `CR` | 配置 RAM ECC 监测通道 | `0x000` | `0x52009080` | 32 | — | — / — | ECCELEN[5]（错误记录锁存使能）、ECCDEBWIE[4]（字节写期间双比特错误中断使能）、ECCDEIE[3]（双比特错误中断使能）、ECCSEIE[2]（单比特错误中断使能） | — |
| `SR` | 查看 RAM ECC 错误状态 | `0x004` | `0x52009084` | 32 | — | — / — | DEBWDF[2]（字节写时检测到双比特错误）、DEDF[1]（检测到双比特错误）、SEDCF[0]（检测到并纠正单比特错误） | — |
| `FAR` | 错误发生地址 | `0x008` | `0x52009088` | 32 | — | — / — | FADD[31:0]（待核） | — |
| `FDRL` | 错误数据低字 | `0x00C` | `0x5200908C` | 32 | — | — / — | FDATAL[31:0]（待核） | — |
| `FDRH` | 错误数据高字 | `0x010` | `0x52009090` | 32 | — | — / — | FDATAH[31:0]（待核） | — |
| `FECR` | 错误校验码 | `0x014` | `0x52009094` | 32 | — | — / — | FEC[31:0]（待核） | — |

## RAMECC1_Monitor4

**模块用途**　独立的 RAM ECC 监测通道，记录被监测存储区的错误类型、地址、数据与校验信息。

基地址 `0x520090A0` · CMSIS 补表

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `CR` | 配置 RAM ECC 监测通道 | `0x000` | `0x520090A0` | 32 | — | — / — | ECCELEN[5]（错误记录锁存使能）、ECCDEBWIE[4]（字节写期间双比特错误中断使能）、ECCDEIE[3]（双比特错误中断使能）、ECCSEIE[2]（单比特错误中断使能） | — |
| `SR` | 查看 RAM ECC 错误状态 | `0x004` | `0x520090A4` | 32 | — | — / — | DEBWDF[2]（字节写时检测到双比特错误）、DEDF[1]（检测到双比特错误）、SEDCF[0]（检测到并纠正单比特错误） | — |
| `FAR` | 错误发生地址 | `0x008` | `0x520090A8` | 32 | — | — / — | FADD[31:0]（待核） | — |
| `FDRL` | 错误数据低字 | `0x00C` | `0x520090AC` | 32 | — | — / — | FDATAL[31:0]（待核） | — |
| `FDRH` | 错误数据高字 | `0x010` | `0x520090B0` | 32 | — | — / — | FDATAH[31:0]（待核） | — |
| `FECR` | 错误校验码 | `0x014` | `0x520090B4` | 32 | — | — / — | FEC[31:0]（待核） | — |

## SDMMC1

**模块用途**　SD/MMC 控制器，用于发卡命令、收取响应以及在数据线与内存间传输数据。

基地址 `0x52007000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `SDMMC_POWER` | SDMMC 电源控制寄存器 | `0x000` | `0x52007000` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIRPOL[4] (RW)（待核）、VSWITCHEN[3] (RW)（待核）、VSWITCH[2] (RW)（待核）、PWRCTRL[1:0] (RW)（SDMMC 状态控制位） | — |
| `SDMMC_CLKCR` | SDMMC 时钟控制寄存器 | `0x004` | `0x52007004` | 32 | — | 0x00000000 / 0xFFFFFFFF | SELCLKRX[21:20] (RW)（接收时钟选择）、BUSSPEED[19] (RW)（待核）、DDR[18] (RW)（待核）、HWFC_EN[17] (RW)（硬件流控制使能）、NEGEDGE[16] (RW)（待核）、WIDBUS[15:14] (RW)（待核）、PWRSAV[12] (RW)（待核）、CLKDIV[9:0] (RW)（待核） | — |
| `SDMMC_ARGR` | SDMMC 参数寄存器 | `0x008` | `0x52007008` | 32 | — | 0x00000000 / 0xFFFFFFFF | CMDARG[31:0] (RW)（命令参数） | — |
| `SDMMC_CMDR` | SDMMC 命令寄存器 | `0x00C` | `0x5200700C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CMDSUSPEND[16] (RW)（待核）、BOOTEN[15] (RW)（待核）、BOOTMODE[14] (RW)（待核）、DTHOLD[13] (RW)（待核）、CPSMEN[12] (RW)（待核）、WAITPEND[11] (RW)（待核）、WAITINT[10] (RW)（待核）、WAITRESP[9:8] (RW)（待核）、CMDSTOP[7] (RW)（待核）、CMDTRANS[6] (RW)（待核）、CMDINDEX[5:0] (RW)（命令索引） | — |
| `SDMMC_RESPCMDR` | SDMMC 命令响应寄存器 | `0x010` | `0x52007010` | 32 | — | 0x00000000 / 0xFFFFFFFF | RESPCMD[5:0] (RO)（响应命令索引） | — |
| `SDMMC_RESP1R` | SDMMC 响应 1 寄存器 | `0x014` | `0x52007014` | 32 | — | 0x00000000 / 0xFFFFFFFF | CARDSTATUS[31:0] (RO)（待核） | — |
| `SDMMC_RESP2R` | SDMMC 响应 2 寄存器 | `0x018` | `0x52007018` | 32 | — | 0x00000000 / 0xFFFFFFFF | CARDSTATUS[31:0] (RO)（待核） | — |
| `SDMMC_RESP3R` | SDMMC 响应 3 寄存器 | `0x01C` | `0x5200701C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CARDSTATUS[31:0] (RO)（待核） | — |
| `SDMMC_RESP4R` | SDMMC 响应 4 寄存器 | `0x020` | `0x52007020` | 32 | — | 0x00000000 / 0xFFFFFFFF | CARDSTATUS[31:0] (RO)（待核） | — |
| `SDMMC_DTIMER` | SDMMC 数据定时器寄存器 | `0x024` | `0x52007024` | 32 | — | 0x00000000 / 0xFFFFFFFF | DATATIME[31:0] (RW)（数据与 R1b 忙超时周期） | — |
| `SDMMC_DLENR` | SDMMC 数据长度寄存器 | `0x028` | `0x52007028` | 32 | — | 0x00000000 / 0xFFFFFFFF | DATALENGTH[24:0] (RW)（数据长度值） | — |
| `SDMMC_DCTRL` | SDMMC 数据控制寄存器 | `0x02C` | `0x5200702C` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFORST[13] (RW)（待核）、BOOTACKEN[12] (RW)（使能接收的启动应答）、SDIOEN[11] (RW)（待核）、RWMOD[10] (RW)（待核）、RWSTOP[9] (RW)（待核）、RWSTART[8] (RW)（待核）、DBLOCKSIZE[7:4] (RW)（数据块大小）、DTMODE[3:2] (RW)（数据传输模式选择）、DTDIR[1] (RW)（数据传输方向选择）、DTEN[0] (RW)（数据传输使能位） | — |
| `SDMMC_DCNTR` | SDMMC 数据计数器寄存器 | `0x030` | `0x52007030` | 32 | — | 0x00000000 / 0xFFFFFFFF | DATACOUNT[24:0] (RO)（数据计数值） | — |
| `SDMMC_STAR` | SDMMC 状态寄存器 | `0x034` | `0x52007034` | 32 | — | 0x00000000 / 0xFFFFFFFF | IDMABTC[28] (RO)（IDMA 缓冲区传输完成）、IDMATE[27] (RO)（IDMA 传输错误）、CKSTOP[26] (RO)（待核）、VSWEND[25] (RO)（待核）、ACKTIMEOUT[24] (RO)（启动应答超时）、ACKFAIL[23] (RO)（待核）、SDIOIT[22] (RO)（SDIO 中断已接收）、BUSYD0END[21] (RO)（待核）、BUSYD0[20] (RO)（待核）、RXFIFOE[19] (RO)（接收 FIFO 空）、TXFIFOE[18] (RO)（发送 FIFO 空）、RXFIFOF[17] (RO)（接收 FIFO 满）、TXFIFOF[16] (RO)（发送 FIFO 满）、RXFIFOHF[15] (RO)（待核）、TXFIFOHE[14] (RO)（待核）、CPSMACT[13] (RO)（待核）、DPSMACT[12] (RO)（待核）、DABORT[11] (RO)（待核）、DBCKEND[10] (RO)（待核）、DHOLD[9] (RO)（数据传输保持）、DATAEND[8] (RO)（待核）、CMDSENT[7] (RO)（待核）、CMDREND[6] (RO)（待核）、RXOVERR[5] (RO)（待核）、TXUNDERR[4] (RO)（待核）、DTIMEOUT[3] (RO)（数据超时）、CTIMEOUT[2] (RO)（命令响应超时）、DCRCFAIL[1] (RO)（待核）、CCRCFAIL[0] (RO)（待核） | — |
| `SDMMC_ICR` | SDMMC 中断清除寄存器 | `0x038` | `0x52007038` | 32 | — | 0x00000000 / 0xFFFFFFFF | IDMABTCC[28] (RW)（IDMA 缓冲区传输完成清除位）、IDMATEC[27] (RW)（IDMA 传输错误清除位）、CKSTOPC[26] (RW)（CKSTOP 清除标志位）、VSWENDC[25] (RW)（VSWEND 清除标志位）、ACKTIMEOUTC[24] (RW)（ACKTIMEOUT 清除标志位）、ACKFAILC[23] (RW)（ACKFAIL 清除标志位）、SDIOITC[22] (RW)（SDIOIT 清除标志位）、BUSYD0ENDC[21] (RW)（BUSYD0END 清除标志位）、DABORTC[11] (RW)（DABORT 清除标志位）、DBCKENDC[10] (RW)（DBCKEND 清除标志位）、DHOLDC[9] (RW)（DHOLD 清除标志位）、DATAENDC[8] (RW)（DATAEND 清除标志位）、CMDSENTC[7] (RW)（CMDSENT 清除标志位）、CMDRENDC[6] (RW)（CMDREND 清除标志位）、RXOVERRC[5] (RW)（RXOVERR 清除标志位）、TXUNDERRC[4] (RW)（TXUNDERR 清除标志位）、DTIMEOUTC[3] (RW)（DTIMEOUT 清除标志位）、CTIMEOUTC[2] (RW)（CTIMEOUT 清除标志位）、DCRCFAILC[1] (RW)（DCRCFAIL 清除标志位）、CCRCFAILC[0] (RW)（CCRCFAIL 清除标志位） | — |
| `SDMMC_MASKR` | SDMMC 屏蔽寄存器 | `0x03C` | `0x5200703C` | 32 | — | 0x00000000 / 0xFFFFFFFF | IDMABTCIE[28] (RW)（IDMA 缓冲区传输完成中断使能）、CKSTOPIE[26] (RW)（待核）、VSWENDIE[25] (RW)（待核）、ACKTIMEOUTIE[24] (RW)（应答超时中断使能）、ACKFAILIE[23] (RW)（待核）、SDIOITIE[22] (RW)（SDIO 模式中断已接收中断使能）、BUSYD0ENDIE[21] (RW)（BUSYD0END 中断使能）、TXFIFOEIE[18] (RW)（发送 FIFO 空中断使能）、RXFIFOFIE[17] (RW)（接收 FIFO 满中断使能）、RXFIFOHFIE[15] (RW)（待核）、TXFIFOHEIE[14] (RW)（待核）、DABORTIE[11] (RW)（待核）、DBCKENDIE[10] (RW)（数据块结束中断使能）、DHOLDIE[9] (RW)（数据保持中断使能）、DATAENDIE[8] (RW)（数据结束中断使能）、CMDSENTIE[7] (RW)（待核）、CMDRENDIE[6] (RW)（命令响应已接收中断使能）、RXOVERRIE[5] (RW)（接收 FIFO 溢出错误中断使能）、TXUNDERRIE[4] (RW)（发送 FIFO 欠载错误中断使能）、DTIMEOUTIE[3] (RW)（数据超时中断使能）、CTIMEOUTIE[2] (RW)（命令超时中断使能）、DCRCFAILIE[1] (RW)（待核）、CCRCFAILIE[0] (RW)（待核） | — |
| `SDMMC_ACKTIMER` | SDMMC 应答定时器寄存器 | `0x040` | `0x52007040` | 32 | — | 0x00000000 / 0xFFFFFFFF | ACKTIME[24:0] (RW)（启动应答超时周期） | — |
| `SDMMC_IDMACTRLR` | SDMMC DMA 控制寄存器 | `0x050` | `0x52007050` | 32 | — | 0x00000000 / 0xFFFFFFFF | IDMABMODE[1] (RW)（缓冲区模式选择）、IDMAEN[0] (RW)（IDMA 使能） | — |
| `SDMMC_IDMABSIZER` | SDMMC IDMA 缓冲区大小寄存器 | `0x054` | `0x52007054` | 32 | — | 0x00000000 / 0xFFFFFFFF | IDMABNDT[16:5] (RW)（待核） | — |
| `SDMMC_IDMABASER` | SDMMC IDMA 缓冲区基址地址寄存器 | `0x058` | `0x52007058` | 32 | — | 0x00000000 / 0xFFFFFFFF | IDMABASE[31:0] (RW)（待核） | — |
| `SDMMC_IDMALAR` | SDMMC IDMA 链接列表地址寄存器 | `0x064` | `0x52007064` | 32 | — | 0x00000000 / 0xFFFFFFFF | ULA[31] (RW)（待核）、ULS[30] (RW)（待核）、ABR[29] (RW)（应答链接列表缓冲区就绪）、IDMALA[15:2] (RW)（待核） | — |
| `SDMMC_IDMABAR` | SDMMC IDMA 链接列表存储器基址寄存器 | `0x068` | `0x52007068` | 32 | — | 0x00000000 / 0xFFFFFFFF | IDMABA[31:2] (RW)（待核） | — |
| `SDMMC_FIFOR0` | SDMMC 数据 FIFO 寄存器 0 | `0x080` | `0x52007080` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR1` | SDMMC 数据 FIFO 寄存器 1 | `0x084` | `0x52007084` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR2` | SDMMC 数据 FIFO 寄存器 2 | `0x088` | `0x52007088` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR3` | SDMMC 数据 FIFO 寄存器 3 | `0x08C` | `0x5200708C` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR4` | SDMMC 数据 FIFO 寄存器 4 | `0x090` | `0x52007090` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR5` | SDMMC 数据 FIFO 寄存器 5 | `0x094` | `0x52007094` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR6` | SDMMC 数据 FIFO 寄存器 6 | `0x098` | `0x52007098` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR7` | SDMMC 数据 FIFO 寄存器 7 | `0x09C` | `0x5200709C` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR8` | SDMMC 数据 FIFO 寄存器 8 | `0x0A0` | `0x520070A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR9` | SDMMC 数据 FIFO 寄存器 9 | `0x0A4` | `0x520070A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR10` | SDMMC 数据 FIFO 寄存器 10 | `0x0A8` | `0x520070A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR11` | SDMMC 数据 FIFO 寄存器 11 | `0x0AC` | `0x520070AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR12` | SDMMC 数据 FIFO 寄存器 12 | `0x0B0` | `0x520070B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR13` | SDMMC 数据 FIFO 寄存器 13 | `0x0B4` | `0x520070B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR14` | SDMMC 数据 FIFO 寄存器 14 | `0x0B8` | `0x520070B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR15` | SDMMC 数据 FIFO 寄存器 15 | `0x0BC` | `0x520070BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |

## SDMMC2

**模块用途**　SD/MMC 控制器，用于发卡命令、收取响应以及在数据线与内存间传输数据。

基地址 `0x48002400` · SVD，继承 SDMMC1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `SDMMC_POWER` | SDMMC 电源控制寄存器 | `0x000` | `0x48002400` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIRPOL[4] (RW)（待核）、VSWITCHEN[3] (RW)（待核）、VSWITCH[2] (RW)（待核）、PWRCTRL[1:0] (RW)（SDMMC 状态控制位） | — |
| `SDMMC_CLKCR` | SDMMC 时钟控制寄存器 | `0x004` | `0x48002404` | 32 | — | 0x00000000 / 0xFFFFFFFF | SELCLKRX[21:20] (RW)（接收时钟选择）、BUSSPEED[19] (RW)（待核）、DDR[18] (RW)（待核）、HWFC_EN[17] (RW)（硬件流控制使能）、NEGEDGE[16] (RW)（待核）、WIDBUS[15:14] (RW)（待核）、PWRSAV[12] (RW)（待核）、CLKDIV[9:0] (RW)（待核） | — |
| `SDMMC_ARGR` | SDMMC 参数寄存器 | `0x008` | `0x48002408` | 32 | — | 0x00000000 / 0xFFFFFFFF | CMDARG[31:0] (RW)（命令参数） | — |
| `SDMMC_CMDR` | SDMMC 命令寄存器 | `0x00C` | `0x4800240C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CMDSUSPEND[16] (RW)（待核）、BOOTEN[15] (RW)（待核）、BOOTMODE[14] (RW)（待核）、DTHOLD[13] (RW)（待核）、CPSMEN[12] (RW)（待核）、WAITPEND[11] (RW)（待核）、WAITINT[10] (RW)（待核）、WAITRESP[9:8] (RW)（待核）、CMDSTOP[7] (RW)（待核）、CMDTRANS[6] (RW)（待核）、CMDINDEX[5:0] (RW)（命令索引） | — |
| `SDMMC_RESPCMDR` | SDMMC 命令响应寄存器 | `0x010` | `0x48002410` | 32 | — | 0x00000000 / 0xFFFFFFFF | RESPCMD[5:0] (RO)（响应命令索引） | — |
| `SDMMC_RESP1R` | SDMMC 响应 1 寄存器 | `0x014` | `0x48002414` | 32 | — | 0x00000000 / 0xFFFFFFFF | CARDSTATUS[31:0] (RO)（待核） | — |
| `SDMMC_RESP2R` | SDMMC 响应 2 寄存器 | `0x018` | `0x48002418` | 32 | — | 0x00000000 / 0xFFFFFFFF | CARDSTATUS[31:0] (RO)（待核） | — |
| `SDMMC_RESP3R` | SDMMC 响应 3 寄存器 | `0x01C` | `0x4800241C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CARDSTATUS[31:0] (RO)（待核） | — |
| `SDMMC_RESP4R` | SDMMC 响应 4 寄存器 | `0x020` | `0x48002420` | 32 | — | 0x00000000 / 0xFFFFFFFF | CARDSTATUS[31:0] (RO)（待核） | — |
| `SDMMC_DTIMER` | SDMMC 数据定时器寄存器 | `0x024` | `0x48002424` | 32 | — | 0x00000000 / 0xFFFFFFFF | DATATIME[31:0] (RW)（数据与 R1b 忙超时周期） | — |
| `SDMMC_DLENR` | SDMMC 数据长度寄存器 | `0x028` | `0x48002428` | 32 | — | 0x00000000 / 0xFFFFFFFF | DATALENGTH[24:0] (RW)（数据长度值） | — |
| `SDMMC_DCTRL` | SDMMC 数据控制寄存器 | `0x02C` | `0x4800242C` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFORST[13] (RW)（待核）、BOOTACKEN[12] (RW)（使能接收的启动应答）、SDIOEN[11] (RW)（待核）、RWMOD[10] (RW)（待核）、RWSTOP[9] (RW)（待核）、RWSTART[8] (RW)（待核）、DBLOCKSIZE[7:4] (RW)（数据块大小）、DTMODE[3:2] (RW)（数据传输模式选择）、DTDIR[1] (RW)（数据传输方向选择）、DTEN[0] (RW)（数据传输使能位） | — |
| `SDMMC_DCNTR` | SDMMC 数据计数器寄存器 | `0x030` | `0x48002430` | 32 | — | 0x00000000 / 0xFFFFFFFF | DATACOUNT[24:0] (RO)（数据计数值） | — |
| `SDMMC_STAR` | SDMMC 状态寄存器 | `0x034` | `0x48002434` | 32 | — | 0x00000000 / 0xFFFFFFFF | IDMABTC[28] (RO)（IDMA 缓冲区传输完成）、IDMATE[27] (RO)（IDMA 传输错误）、CKSTOP[26] (RO)（待核）、VSWEND[25] (RO)（待核）、ACKTIMEOUT[24] (RO)（启动应答超时）、ACKFAIL[23] (RO)（待核）、SDIOIT[22] (RO)（SDIO 中断已接收）、BUSYD0END[21] (RO)（待核）、BUSYD0[20] (RO)（待核）、RXFIFOE[19] (RO)（接收 FIFO 空）、TXFIFOE[18] (RO)（发送 FIFO 空）、RXFIFOF[17] (RO)（接收 FIFO 满）、TXFIFOF[16] (RO)（发送 FIFO 满）、RXFIFOHF[15] (RO)（待核）、TXFIFOHE[14] (RO)（待核）、CPSMACT[13] (RO)（待核）、DPSMACT[12] (RO)（待核）、DABORT[11] (RO)（待核）、DBCKEND[10] (RO)（待核）、DHOLD[9] (RO)（数据传输保持）、DATAEND[8] (RO)（待核）、CMDSENT[7] (RO)（待核）、CMDREND[6] (RO)（待核）、RXOVERR[5] (RO)（待核）、TXUNDERR[4] (RO)（待核）、DTIMEOUT[3] (RO)（数据超时）、CTIMEOUT[2] (RO)（命令响应超时）、DCRCFAIL[1] (RO)（待核）、CCRCFAIL[0] (RO)（待核） | — |
| `SDMMC_ICR` | SDMMC 中断清除寄存器 | `0x038` | `0x48002438` | 32 | — | 0x00000000 / 0xFFFFFFFF | IDMABTCC[28] (RW)（IDMA 缓冲区传输完成清除位）、IDMATEC[27] (RW)（IDMA 传输错误清除位）、CKSTOPC[26] (RW)（CKSTOP 清除标志位）、VSWENDC[25] (RW)（VSWEND 清除标志位）、ACKTIMEOUTC[24] (RW)（ACKTIMEOUT 清除标志位）、ACKFAILC[23] (RW)（ACKFAIL 清除标志位）、SDIOITC[22] (RW)（SDIOIT 清除标志位）、BUSYD0ENDC[21] (RW)（BUSYD0END 清除标志位）、DABORTC[11] (RW)（DABORT 清除标志位）、DBCKENDC[10] (RW)（DBCKEND 清除标志位）、DHOLDC[9] (RW)（DHOLD 清除标志位）、DATAENDC[8] (RW)（DATAEND 清除标志位）、CMDSENTC[7] (RW)（CMDSENT 清除标志位）、CMDRENDC[6] (RW)（CMDREND 清除标志位）、RXOVERRC[5] (RW)（RXOVERR 清除标志位）、TXUNDERRC[4] (RW)（TXUNDERR 清除标志位）、DTIMEOUTC[3] (RW)（DTIMEOUT 清除标志位）、CTIMEOUTC[2] (RW)（CTIMEOUT 清除标志位）、DCRCFAILC[1] (RW)（DCRCFAIL 清除标志位）、CCRCFAILC[0] (RW)（CCRCFAIL 清除标志位） | — |
| `SDMMC_MASKR` | SDMMC 屏蔽寄存器 | `0x03C` | `0x4800243C` | 32 | — | 0x00000000 / 0xFFFFFFFF | IDMABTCIE[28] (RW)（IDMA 缓冲区传输完成中断使能）、CKSTOPIE[26] (RW)（待核）、VSWENDIE[25] (RW)（待核）、ACKTIMEOUTIE[24] (RW)（应答超时中断使能）、ACKFAILIE[23] (RW)（待核）、SDIOITIE[22] (RW)（SDIO 模式中断已接收中断使能）、BUSYD0ENDIE[21] (RW)（BUSYD0END 中断使能）、TXFIFOEIE[18] (RW)（发送 FIFO 空中断使能）、RXFIFOFIE[17] (RW)（接收 FIFO 满中断使能）、RXFIFOHFIE[15] (RW)（待核）、TXFIFOHEIE[14] (RW)（待核）、DABORTIE[11] (RW)（待核）、DBCKENDIE[10] (RW)（数据块结束中断使能）、DHOLDIE[9] (RW)（数据保持中断使能）、DATAENDIE[8] (RW)（数据结束中断使能）、CMDSENTIE[7] (RW)（待核）、CMDRENDIE[6] (RW)（命令响应已接收中断使能）、RXOVERRIE[5] (RW)（接收 FIFO 溢出错误中断使能）、TXUNDERRIE[4] (RW)（发送 FIFO 欠载错误中断使能）、DTIMEOUTIE[3] (RW)（数据超时中断使能）、CTIMEOUTIE[2] (RW)（命令超时中断使能）、DCRCFAILIE[1] (RW)（待核）、CCRCFAILIE[0] (RW)（待核） | — |
| `SDMMC_ACKTIMER` | SDMMC 应答定时器寄存器 | `0x040` | `0x48002440` | 32 | — | 0x00000000 / 0xFFFFFFFF | ACKTIME[24:0] (RW)（启动应答超时周期） | — |
| `SDMMC_IDMACTRLR` | SDMMC DMA 控制寄存器 | `0x050` | `0x48002450` | 32 | — | 0x00000000 / 0xFFFFFFFF | IDMABMODE[1] (RW)（缓冲区模式选择）、IDMAEN[0] (RW)（IDMA 使能） | — |
| `SDMMC_IDMABSIZER` | SDMMC IDMA 缓冲区大小寄存器 | `0x054` | `0x48002454` | 32 | — | 0x00000000 / 0xFFFFFFFF | IDMABNDT[16:5] (RW)（待核） | — |
| `SDMMC_IDMABASER` | SDMMC IDMA 缓冲区基址地址寄存器 | `0x058` | `0x48002458` | 32 | — | 0x00000000 / 0xFFFFFFFF | IDMABASE[31:0] (RW)（待核） | — |
| `SDMMC_IDMALAR` | SDMMC IDMA 链接列表地址寄存器 | `0x064` | `0x48002464` | 32 | — | 0x00000000 / 0xFFFFFFFF | ULA[31] (RW)（待核）、ULS[30] (RW)（待核）、ABR[29] (RW)（应答链接列表缓冲区就绪）、IDMALA[15:2] (RW)（待核） | — |
| `SDMMC_IDMABAR` | SDMMC IDMA 链接列表存储器基址寄存器 | `0x068` | `0x48002468` | 32 | — | 0x00000000 / 0xFFFFFFFF | IDMABA[31:2] (RW)（待核） | — |
| `SDMMC_FIFOR0` | SDMMC 数据 FIFO 寄存器 0 | `0x080` | `0x48002480` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR1` | SDMMC 数据 FIFO 寄存器 1 | `0x084` | `0x48002484` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR2` | SDMMC 数据 FIFO 寄存器 2 | `0x088` | `0x48002488` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR3` | SDMMC 数据 FIFO 寄存器 3 | `0x08C` | `0x4800248C` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR4` | SDMMC 数据 FIFO 寄存器 4 | `0x090` | `0x48002490` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR5` | SDMMC 数据 FIFO 寄存器 5 | `0x094` | `0x48002494` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR6` | SDMMC 数据 FIFO 寄存器 6 | `0x098` | `0x48002498` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR7` | SDMMC 数据 FIFO 寄存器 7 | `0x09C` | `0x4800249C` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR8` | SDMMC 数据 FIFO 寄存器 8 | `0x0A0` | `0x480024A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR9` | SDMMC 数据 FIFO 寄存器 9 | `0x0A4` | `0x480024A4` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR10` | SDMMC 数据 FIFO 寄存器 10 | `0x0A8` | `0x480024A8` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR11` | SDMMC 数据 FIFO 寄存器 11 | `0x0AC` | `0x480024AC` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR12` | SDMMC 数据 FIFO 寄存器 12 | `0x0B0` | `0x480024B0` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR13` | SDMMC 数据 FIFO 寄存器 13 | `0x0B4` | `0x480024B4` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR14` | SDMMC 数据 FIFO 寄存器 14 | `0x0B8` | `0x480024B8` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |
| `SDMMC_FIFOR15` | SDMMC 数据 FIFO 寄存器 15 | `0x0BC` | `0x480024BC` | 32 | — | 0x00000000 / 0xFFFFFFFF | FIFODATA[31:0] (RW)（接收与发送 FIFO 数据） | — |

## XSPI1

**模块用途**　扩展 SPI 存储接口，用于访问串行 NOR 或 RAM。配置命令、地址、数据阶段以及存储映射等模式。

基地址 `0x52005000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `XSPI_CR` | XSPI 控制寄存器 | `0x000` | `0x52005000` | 32 | — | 0x00000000 / 0xFFFFFFFF | MSEL[31:30] (RW)（闪存选择）、FMODE[29:28] (RW)（待核）、CSSEL[24] (RW)（片选选择）、PMM[23] (RW)（轮询匹配模式）、APMS[22] (RW)（待核）、TOIE[20] (RW)（超时中断使能）、SMIE[19] (RW)（状态匹配中断使能）、FTIE[18] (RW)（FIFO 阈值中断使能）、TCIE[17] (RW)（传输完成中断使能）、TEIE[16] (RW)（传输错误中断使能）、FTHRES[13:8] (RW)（FIFO 阈值）、DMM[6] (RW)（双路-存储器配置）、TCEN[3] (RW)（超时计数器使能）、DMAEN[2] (RW)（DMA 使能）、ABORT[1] (RW)（中止请求）、EN[0] (RW)（使能） | — |
| `XSPI_DCR1` | XSPI 设备配置寄存器 1 | `0x008` | `0x52005008` | 32 | — | 0x00000000 / 0xFFFFFFFF | MTYP[26:24] (RW)（待核）、DEVSIZE[20:16] (RW)（设备大小）、CSHT[13:8] (RW)（待核）、FRCK[1] (RW)（待核）、CKMODE[0] (RW)（时钟模式 0/模式 3） | — |
| `XSPI_DCR2` | XSPI 设备配置寄存器 2 | `0x00C` | `0x5200500C` | 32 | — | 0x00000000 / 0xFFFFFFFF | WRAPSIZE[18:16] (RW)（回绕大小）、PRESCALER[7:0] (RW)（时钟预分频器） | — |
| `XSPI_DCR3` | XSPI 设备配置寄存器 3 | `0x010` | `0x52005010` | 32 | — | 0x00000000 / 0xFFFFFFFF | CSBOUND[20:16] (RW)（待核）、MAXTRAN[7:0] (RW)（最大传输） | — |
| `XSPI_DCR4` | XSPI 设备配置寄存器 4 | `0x014` | `0x52005014` | 32 | — | 0x00000000 / 0xFFFFFFFF | REFRESH[31:0] (RW)（待核） | — |
| `XSPI_SR` | XSPI 状态寄存器 | `0x020` | `0x52005020` | 32 | — | 0x00000000 / 0xFFFFFFFF | FLEVEL[14:8] (RO)（FIFO 电平）、BUSY[5] (RO)（忙）、TOF[4] (RO)（超时标志）、SMF[3] (RO)（状态匹配标志）、FTF[2] (RO)（FIFO 阈值标志）、TCF[1] (RO)（传输完成标志）、TEF[0] (RO)（传输错误标志） | — |
| `XSPI_FCR` | XSPI 清除标志寄存器 | `0x024` | `0x52005024` | 32 | — | 0x00000000 / 0xFFFFFFFF | CTOF[4] (WO)（清除超时标志）、CSMF[3] (WO)（清除状态匹配标志）、CTCF[1] (WO)（清除传输完成标志）、CTEF[0] (WO)（清除传输错误标志） | — |
| `XSPI_DLR` | XSPI 数据长度寄存器 | `0x040` | `0x52005040` | 32 | — | 0x00000000 / 0xFFFFFFFF | DL[31:0] (RW)（数据长度） | — |
| `XSPI_AR` | 本次访问的外部地址 | `0x048` | `0x52005048` | 32 | — | 0x00000000 / 0xFFFFFFFF | ADDRESS[31:0] (RW)（地址） | — |
| `XSPI_DR` | XSPI 数据寄存器 | `0x050` | `0x52005050` | 32 | — | 0x00000000 / 0xFFFFFFFF | DATA[31:0] (RW)（数据） | — |
| `XSPI_PSMKR` | 自动轮询状态位掩码 | `0x080` | `0x52005080` | 32 | — | 0x00000000 / 0xFFFFFFFF | MASK[31:0] (RW)（状态屏蔽） | — |
| `XSPI_PSMAR` | 自动轮询状态匹配值 | `0x088` | `0x52005088` | 32 | — | 0x00000000 / 0xFFFFFFFF | MATCH[31:0] (RW)（状态匹配） | — |
| `XSPI_PIR` | 自动轮询间隔 | `0x090` | `0x52005090` | 32 | — | 0x00000000 / 0xFFFFFFFF | INTERVAL[15:0] (RW)（轮询间隔） | — |
| `XSPI_CCR` | 通信阶段及总线模式配置 | `0x100` | `0x52005100` | 32 | — | 0x00000000 / 0xFFFFFFFF | DQSE[29] (RW)（DQS 使能）、DDTR[27] (RW)（待核）、DMODE[26:24] (RW)（数据模式）、ABSIZE[21:20] (RW)（备选字节大小）、ABDTR[19] (RW)（待核）、ABMODE[18:16] (RW)（备选-字节模式）、ADSIZE[13:12] (RW)（地址大小）、ADDTR[11] (RW)（待核）、ADMODE[10:8] (RW)（地址模式）、ISIZE[5:4] (RW)（指令大小）、IDTR[3] (RW)（待核）、IMODE[2:0] (RW)（指令模式） | — |
| `XSPI_TCR` | XSPI 时序配置寄存器 | `0x108` | `0x52005108` | 32 | — | 0x00000000 / 0xFFFFFFFF | SSHIFT[30] (RW)（采样移位）、DHQC[28] (RW)（待核）、DCYC[4:0] (RW)（待核） | — |
| `XSPI_IR` | XSPI 指令寄存器 | `0x110` | `0x52005110` | 32 | — | 0x00000000 / 0xFFFFFFFF | INSTRUCTION[31:0] (RW)（指令） | — |
| `XSPI_ABR` | XSPI 备选字节寄存器 | `0x120` | `0x52005120` | 32 | — | 0x00000000 / 0xFFFFFFFF | ALTERNATE[31:0] (RW)（备选字节） | — |
| `XSPI_LPTR` | XSPI 低位-电源超时寄存器 | `0x130` | `0x52005130` | 32 | — | 0x00000000 / 0xFFFFFFFF | TIMEOUT[15:0] (RW)（超时周期） | — |
| `XSPI_WPCCR` | 回绕访问的通信配置 | `0x140` | `0x52005140` | 32 | — | 0x00000000 / 0xFFFFFFFF | DQSE[29] (RW)（DQS 使能）、DDTR[27] (RW)（待核）、DMODE[26:24] (RW)（数据模式）、ABSIZE[21:20] (RW)（备选字节大小）、ABDTR[19] (RW)（待核）、ABMODE[18:16] (RW)（备选-字节模式）、ADSIZE[13:12] (RW)（地址大小）、ADDTR[11] (RW)（待核）、ADMODE[10:8] (RW)（地址模式）、ISIZE[5:4] (RW)（指令大小）、IDTR[3] (RW)（待核）、IMODE[2:0] (RW)（指令模式） | — |
| `XSPI_WPTCR` | 回绕访问的时序配置 | `0x148` | `0x52005148` | 32 | — | 0x00000000 / 0xFFFFFFFF | SSHIFT[30] (RW)（采样移位）、DHQC[28] (RW)（待核）、DCYC[4:0] (RW)（待核） | — |
| `XSPI_WPIR` | 回绕访问指令 | `0x150` | `0x52005150` | 32 | — | 0x00000000 / 0xFFFFFFFF | INSTRUCTION[31:0] (RW)（指令） | — |
| `XSPI_WPABR` | 回绕访问备选字节 | `0x160` | `0x52005160` | 32 | — | 0x00000000 / 0xFFFFFFFF | ALTERNATE[31:0] (RW)（备选字节） | — |
| `XSPI_WCCR` | 写访问的通信配置 | `0x180` | `0x52005180` | 32 | — | 0x00000000 / 0xFFFFFFFF | DQSE[29] (RW)（DQS 使能）、DDTR[27] (RW)（待核）、DMODE[26:24] (RW)（数据模式）、ABSIZE[21:20] (RW)（备选字节大小）、ABDTR[19] (RW)（待核）、ABMODE[18:16] (RW)（备选-字节模式）、ADSIZE[13:12] (RW)（地址大小）、ADDTR[11] (RW)（待核）、ADMODE[10:8] (RW)（地址模式）、ISIZE[5:4] (RW)（指令大小）、IDTR[3] (RW)（待核）、IMODE[2:0] (RW)（指令模式） | — |
| `XSPI_WTCR` | XSPI 写入时序配置寄存器 | `0x188` | `0x52005188` | 32 | — | 0x00000000 / 0xFFFFFFFF | DCYC[4:0] (RW)（待核） | — |
| `XSPI_WIR` | XSPI 写入指令寄存器 | `0x190` | `0x52005190` | 32 | — | 0x00000000 / 0xFFFFFFFF | INSTRUCTION[31:0] (RW)（指令） | — |
| `XSPI_WABR` | XSPI 写入备选字节寄存器 | `0x1A0` | `0x520051A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | ALTERNATE[31:0] (RW)（备选字节） | — |
| `XSPI_HLCR` | HyperBus 访问延迟配置 | `0x200` | `0x52005200` | 32 | — | 0x00000000 / 0xFFFFFFFF | TRWR[23:16] (RW)（读取写入恢复时间）、TACC[15:8] (RW)（访问时间）、WZL[1] (RW)（待核）、LM[0] (RW)（延迟模式） | — |
| `XSPI_CALFCR` | XSPI 满-周期校准配置 | `0x210` | `0x52005210` | 32 | — | 0x00000000 / 0xFFFFFFFF | CALMAX[31] (RO)（最大值值）、COARSE[20:16] (RO)（待核）、FINE[6:0] (RO)（待核） | — |
| `XSPI_CALMR` | XSPI DLL 主设备校准配置 | `0x218` | `0x52005218` | 32 | — | 0x00000000 / 0xFFFFFFFF | COARSE[20:16] (RW)（待核）、FINE[6:0] (RW)（待核） | — |
| `XSPI_CALSOR` | XSPI DLL 从设备输出校准配置 | `0x220` | `0x52005220` | 32 | — | 0x00000000 / 0xFFFFFFFF | COARSE[20:16] (RW)（待核）、FINE[6:0] (RW)（待核） | — |
| `XSPI_CALSIR` | XSPI DLL 从设备输入校准配置 | `0x228` | `0x52005228` | 32 | — | 0x00000000 / 0xFFFFFFFF | COARSE[20:16] (RW)（待核）、FINE[6:0] (RW)（待核） | — |

## XSPI2

**模块用途**　扩展 SPI 存储接口，用于访问串行 NOR 或 RAM。配置命令、地址、数据阶段以及存储映射等模式。

基地址 `0x5200A000` · SVD，继承 XSPI1

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `XSPI_CR` | XSPI 控制寄存器 | `0x000` | `0x5200A000` | 32 | — | 0x00000000 / 0xFFFFFFFF | MSEL[31:30] (RW)（闪存选择）、FMODE[29:28] (RW)（待核）、CSSEL[24] (RW)（片选选择）、PMM[23] (RW)（轮询匹配模式）、APMS[22] (RW)（待核）、TOIE[20] (RW)（超时中断使能）、SMIE[19] (RW)（状态匹配中断使能）、FTIE[18] (RW)（FIFO 阈值中断使能）、TCIE[17] (RW)（传输完成中断使能）、TEIE[16] (RW)（传输错误中断使能）、FTHRES[13:8] (RW)（FIFO 阈值）、DMM[6] (RW)（双路-存储器配置）、TCEN[3] (RW)（超时计数器使能）、DMAEN[2] (RW)（DMA 使能）、ABORT[1] (RW)（中止请求）、EN[0] (RW)（使能） | — |
| `XSPI_DCR1` | XSPI 设备配置寄存器 1 | `0x008` | `0x5200A008` | 32 | — | 0x00000000 / 0xFFFFFFFF | MTYP[26:24] (RW)（待核）、DEVSIZE[20:16] (RW)（设备大小）、CSHT[13:8] (RW)（待核）、FRCK[1] (RW)（待核）、CKMODE[0] (RW)（时钟模式 0/模式 3） | — |
| `XSPI_DCR2` | XSPI 设备配置寄存器 2 | `0x00C` | `0x5200A00C` | 32 | — | 0x00000000 / 0xFFFFFFFF | WRAPSIZE[18:16] (RW)（回绕大小）、PRESCALER[7:0] (RW)（时钟预分频器） | — |
| `XSPI_DCR3` | XSPI 设备配置寄存器 3 | `0x010` | `0x5200A010` | 32 | — | 0x00000000 / 0xFFFFFFFF | CSBOUND[20:16] (RW)（待核）、MAXTRAN[7:0] (RW)（最大传输） | — |
| `XSPI_DCR4` | XSPI 设备配置寄存器 4 | `0x014` | `0x5200A014` | 32 | — | 0x00000000 / 0xFFFFFFFF | REFRESH[31:0] (RW)（待核） | — |
| `XSPI_SR` | XSPI 状态寄存器 | `0x020` | `0x5200A020` | 32 | — | 0x00000000 / 0xFFFFFFFF | FLEVEL[14:8] (RO)（FIFO 电平）、BUSY[5] (RO)（忙）、TOF[4] (RO)（超时标志）、SMF[3] (RO)（状态匹配标志）、FTF[2] (RO)（FIFO 阈值标志）、TCF[1] (RO)（传输完成标志）、TEF[0] (RO)（传输错误标志） | — |
| `XSPI_FCR` | XSPI 清除标志寄存器 | `0x024` | `0x5200A024` | 32 | — | 0x00000000 / 0xFFFFFFFF | CTOF[4] (WO)（清除超时标志）、CSMF[3] (WO)（清除状态匹配标志）、CTCF[1] (WO)（清除传输完成标志）、CTEF[0] (WO)（清除传输错误标志） | — |
| `XSPI_DLR` | XSPI 数据长度寄存器 | `0x040` | `0x5200A040` | 32 | — | 0x00000000 / 0xFFFFFFFF | DL[31:0] (RW)（数据长度） | — |
| `XSPI_AR` | 本次访问的外部地址 | `0x048` | `0x5200A048` | 32 | — | 0x00000000 / 0xFFFFFFFF | ADDRESS[31:0] (RW)（地址） | — |
| `XSPI_DR` | XSPI 数据寄存器 | `0x050` | `0x5200A050` | 32 | — | 0x00000000 / 0xFFFFFFFF | DATA[31:0] (RW)（数据） | — |
| `XSPI_PSMKR` | 自动轮询状态位掩码 | `0x080` | `0x5200A080` | 32 | — | 0x00000000 / 0xFFFFFFFF | MASK[31:0] (RW)（状态屏蔽） | — |
| `XSPI_PSMAR` | 自动轮询状态匹配值 | `0x088` | `0x5200A088` | 32 | — | 0x00000000 / 0xFFFFFFFF | MATCH[31:0] (RW)（状态匹配） | — |
| `XSPI_PIR` | 自动轮询间隔 | `0x090` | `0x5200A090` | 32 | — | 0x00000000 / 0xFFFFFFFF | INTERVAL[15:0] (RW)（轮询间隔） | — |
| `XSPI_CCR` | 通信阶段及总线模式配置 | `0x100` | `0x5200A100` | 32 | — | 0x00000000 / 0xFFFFFFFF | DQSE[29] (RW)（DQS 使能）、DDTR[27] (RW)（待核）、DMODE[26:24] (RW)（数据模式）、ABSIZE[21:20] (RW)（备选字节大小）、ABDTR[19] (RW)（待核）、ABMODE[18:16] (RW)（备选-字节模式）、ADSIZE[13:12] (RW)（地址大小）、ADDTR[11] (RW)（待核）、ADMODE[10:8] (RW)（地址模式）、ISIZE[5:4] (RW)（指令大小）、IDTR[3] (RW)（待核）、IMODE[2:0] (RW)（指令模式） | — |
| `XSPI_TCR` | XSPI 时序配置寄存器 | `0x108` | `0x5200A108` | 32 | — | 0x00000000 / 0xFFFFFFFF | SSHIFT[30] (RW)（采样移位）、DHQC[28] (RW)（待核）、DCYC[4:0] (RW)（待核） | — |
| `XSPI_IR` | XSPI 指令寄存器 | `0x110` | `0x5200A110` | 32 | — | 0x00000000 / 0xFFFFFFFF | INSTRUCTION[31:0] (RW)（指令） | — |
| `XSPI_ABR` | XSPI 备选字节寄存器 | `0x120` | `0x5200A120` | 32 | — | 0x00000000 / 0xFFFFFFFF | ALTERNATE[31:0] (RW)（备选字节） | — |
| `XSPI_LPTR` | XSPI 低位-电源超时寄存器 | `0x130` | `0x5200A130` | 32 | — | 0x00000000 / 0xFFFFFFFF | TIMEOUT[15:0] (RW)（超时周期） | — |
| `XSPI_WPCCR` | 回绕访问的通信配置 | `0x140` | `0x5200A140` | 32 | — | 0x00000000 / 0xFFFFFFFF | DQSE[29] (RW)（DQS 使能）、DDTR[27] (RW)（待核）、DMODE[26:24] (RW)（数据模式）、ABSIZE[21:20] (RW)（备选字节大小）、ABDTR[19] (RW)（待核）、ABMODE[18:16] (RW)（备选-字节模式）、ADSIZE[13:12] (RW)（地址大小）、ADDTR[11] (RW)（待核）、ADMODE[10:8] (RW)（地址模式）、ISIZE[5:4] (RW)（指令大小）、IDTR[3] (RW)（待核）、IMODE[2:0] (RW)（指令模式） | — |
| `XSPI_WPTCR` | 回绕访问的时序配置 | `0x148` | `0x5200A148` | 32 | — | 0x00000000 / 0xFFFFFFFF | SSHIFT[30] (RW)（采样移位）、DHQC[28] (RW)（待核）、DCYC[4:0] (RW)（待核） | — |
| `XSPI_WPIR` | 回绕访问指令 | `0x150` | `0x5200A150` | 32 | — | 0x00000000 / 0xFFFFFFFF | INSTRUCTION[31:0] (RW)（指令） | — |
| `XSPI_WPABR` | 回绕访问备选字节 | `0x160` | `0x5200A160` | 32 | — | 0x00000000 / 0xFFFFFFFF | ALTERNATE[31:0] (RW)（备选字节） | — |
| `XSPI_WCCR` | 写访问的通信配置 | `0x180` | `0x5200A180` | 32 | — | 0x00000000 / 0xFFFFFFFF | DQSE[29] (RW)（DQS 使能）、DDTR[27] (RW)（待核）、DMODE[26:24] (RW)（数据模式）、ABSIZE[21:20] (RW)（备选字节大小）、ABDTR[19] (RW)（待核）、ABMODE[18:16] (RW)（备选-字节模式）、ADSIZE[13:12] (RW)（地址大小）、ADDTR[11] (RW)（待核）、ADMODE[10:8] (RW)（地址模式）、ISIZE[5:4] (RW)（指令大小）、IDTR[3] (RW)（待核）、IMODE[2:0] (RW)（指令模式） | — |
| `XSPI_WTCR` | XSPI 写入时序配置寄存器 | `0x188` | `0x5200A188` | 32 | — | 0x00000000 / 0xFFFFFFFF | DCYC[4:0] (RW)（待核） | — |
| `XSPI_WIR` | XSPI 写入指令寄存器 | `0x190` | `0x5200A190` | 32 | — | 0x00000000 / 0xFFFFFFFF | INSTRUCTION[31:0] (RW)（指令） | — |
| `XSPI_WABR` | XSPI 写入备选字节寄存器 | `0x1A0` | `0x5200A1A0` | 32 | — | 0x00000000 / 0xFFFFFFFF | ALTERNATE[31:0] (RW)（备选字节） | — |
| `XSPI_HLCR` | HyperBus 访问延迟配置 | `0x200` | `0x5200A200` | 32 | — | 0x00000000 / 0xFFFFFFFF | TRWR[23:16] (RW)（读取写入恢复时间）、TACC[15:8] (RW)（访问时间）、WZL[1] (RW)（待核）、LM[0] (RW)（延迟模式） | — |
| `XSPI_CALFCR` | XSPI 满-周期校准配置 | `0x210` | `0x5200A210` | 32 | — | 0x00000000 / 0xFFFFFFFF | CALMAX[31] (RO)（最大值值）、COARSE[20:16] (RO)（待核）、FINE[6:0] (RO)（待核） | — |
| `XSPI_CALMR` | XSPI DLL 主设备校准配置 | `0x218` | `0x5200A218` | 32 | — | 0x00000000 / 0xFFFFFFFF | COARSE[20:16] (RW)（待核）、FINE[6:0] (RW)（待核） | — |
| `XSPI_CALSOR` | XSPI DLL 从设备输出校准配置 | `0x220` | `0x5200A220` | 32 | — | 0x00000000 / 0xFFFFFFFF | COARSE[20:16] (RW)（待核）、FINE[6:0] (RW)（待核） | — |
| `XSPI_CALSIR` | XSPI DLL 从设备输入校准配置 | `0x228` | `0x5200A228` | 32 | — | 0x00000000 / 0xFFFFFFFF | COARSE[20:16] (RW)（待核）、FINE[6:0] (RW)（待核） | — |

## XSPIM1

**模块用途**　XSPI I/O 管理器，用于配置 XSPI 接口之间的 I/O 连接与分配。

基地址 `0x5200B400` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `XSPIM_CR` | XSPIM 控制寄存器 | `0x000` | `0x5200B400` | 32 | RW | 0x00000000 / 0xFFFFFFFF | REQ2ACK_TIME[23:16]（REQ 至 ACK 时间）、CSSEL_OVR_O2[6]（待核）、CSSEL_OVR_O1[5]（待核）、CSSEL_OVR_EN[4]（待核）、MODE[1]（待核）、MUXEN[0]（待核） | — |
