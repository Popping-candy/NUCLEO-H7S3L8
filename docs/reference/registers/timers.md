# 定时器、RTC 与看门狗寄存器

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
| [IWDG](#iwdg) | `0x58004800` | 6 | SVD |
| [LPTIM1](#lptim1) | `0x40002400` | 6 | SVD |
| [LPTIM2](#lptim2) | `0x58002400` | 6 | SVD |
| [LPTIM3](#lptim3) | `0x58002800` | 6 | SVD |
| [LPTIM4](#lptim4) | `0x58002C00` | 3 | SVD |
| [LPTIM5](#lptim5) | `0x58003000` | 3 | SVD |
| [RTC](#rtc) | `0x58004000` | 23 | SVD |
| [TAMP](#tamp) | `0x58004400` | 47 | SVD |
| [TAMP_CMSIS](#tamp_cmsis) | `0x58004400` | 1 | CMSIS 补表 |
| [TIM1](#tim1) | `0x42000000` | 30 | SVD |
| [TIM12](#tim12) | `0x40001800` | 15 | SVD |
| [TIM13](#tim13) | `0x40001C00` | 12 | SVD |
| [TIM14](#tim14) | `0x40002000` | 12 | SVD |
| [TIM15](#tim15) | `0x42004000` | 22 | SVD |
| [TIM16](#tim16) | `0x42004400` | 20 | SVD |
| [TIM17](#tim17) | `0x42004800` | 20 | SVD |
| [TIM2](#tim2) | `0x40000000` | 24 | SVD |
| [TIM3](#tim3) | `0x40000400` | 24 | SVD |
| [TIM4](#tim4) | `0x40000800` | 24 | SVD |
| [TIM5](#tim5) | `0x40000C00` | 24 | SVD |
| [TIM6](#tim6) | `0x40001000` | 8 | SVD |
| [TIM7](#tim7) | `0x40001400` | 8 | SVD |
| [TIM9](#tim9) | `0x42004C00` | 15 | SVD |
| [WWDG](#wwdg) | `0x40002C00` | 3 | SVD |

## IWDG

**模块用途**　独立看门狗，使用独立时钟计时。软件需要在超时前刷新计数，否则可触发系统复位。

基地址 `0x58004800` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `IWDG_KR` | IWDG 密钥寄存器 | `0x000` | `0x58004800` | 32 | — | 0x00000000 / 0xFFFFFFFF | KEY[15:0] (WO)（待核） | — |
| `IWDG_PR` | IWDG 预分频器寄存器 | `0x004` | `0x58004804` | 32 | — | 0x00000000 / 0xFFFFFFFF | PR[3:0] (RW)（预分频器分频器） | — |
| `IWDG_RLR` | IWDG 重装寄存器 | `0x008` | `0x58004808` | 32 | — | 0x00000FFF / 0xFFFFFFFF | RL[11:0] (RW)（看门狗计数器重装值） | — |
| `IWDG_SR` | IWDG 状态寄存器 | `0x00C` | `0x5800480C` | 32 | — | 0x00000000 / 0xFFFFFFFF | EWIF[14] (RO)（看门狗提前中断标志）、ONF[8] (RO)（看门狗使能状态位）、EWU[3] (RO)（待核）、WVU[2] (RO)（看门狗计数器窗口值更新）、RVU[1] (RO)（看门狗计数器重装值更新）、PVU[0] (RO)（看门狗预分频器值更新） | — |
| `IWDG_WINR` | IWDG 窗口寄存器 | `0x010` | `0x58004810` | 32 | — | 0x00000FFF / 0xFFFFFFFF | WIN[11:0] (RW)（看门狗计数器窗口值） | — |
| `IWDG_EWCR` | IWDG 提前唤醒中断寄存器 | `0x014` | `0x58004814` | 32 | — | 0x00000000 / 0xFFFFFFFF | EWIE[15] (RW)（看门狗提前中断使能）、EWIC[14] (WO)（看门狗提前中断应答）、EWIT[11:0] (RW)（看门狗计数器窗口值） | — |

## LPTIM1

**模块用途**　低功耗定时器，可在相应低功耗模式下进行计数、比较、触发或唤醒，具体能力取决于实例。

基地址 `0x40002400` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `LPTIM1_ISR_OUTPUT` | LPTIM1 中断与状态寄存器 | `0x000` | `0x40002400` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIEROK[24] (RO)（中断使能寄存器更新 OK）、CMP2OK[19] (RO)（比较寄存器 2 更新 OK）、CC2IF[9] (RO)（比较 2 中断标志）、REPOK[8] (RO)（重复寄存器更新 OK）、UE[7] (RO)（LPTIM 更新事件已发生）、DOWN[6] (RO)（待核）、UP[5] (RO)（待核）、ARROK[4] (RO)（待核）、CMP1OK[3] (RO)（比较寄存器 1 更新 OK）、EXTTRIG[2] (RO)（外部触发边沿事件）、ARRM[1] (RO)（待核）、CC1IF[0] (RO)（比较 1 中断标志） | — |
| `LPTIM1_ISR_INPUT` | LPTIM1 中断与状态寄存器 | `0x000` | `0x40002400` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIEROK[24] (RO)（中断使能寄存器更新 OK）、CC2OF[13] (RO)（待核）、CC1OF[12] (RO)（待核）、CC2IF[9] (RO)（捕获 2 中断标志）、REPOK[8] (RO)（重复寄存器更新 OK）、UE[7] (RO)（LPTIM 更新事件已发生）、DOWN[6] (RO)（待核）、UP[5] (RO)（待核）、ARROK[4] (RO)（待核）、EXTTRIG[2] (RO)（外部触发边沿事件）、ARRM[1] (RO)（待核）、CC1IF[0] (RO)（捕获 1 中断标志） | 别名 LPTIM1_ISR_OUTPUT |
| `LPTIM1_ICR_OUTPUT` | LPTIM1 中断清除寄存器 | `0x004` | `0x40002404` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIEROKCF[24] (WO)（中断使能寄存器更新 OK 清除标志）、CMP2OKCF[19] (WO)（比较寄存器 2 更新 OK 清除标志）、CC2CF[9] (WO)（捕获/比较 2 清除标志）、REPOKCF[8] (WO)（重复寄存器更新 OK 清除标志）、UECF[7] (WO)（更新事件清除标志）、DOWNCF[6] (WO)（待核）、UPCF[5] (WO)（待核）、ARROKCF[4] (WO)（待核）、CMP1OKCF[3] (WO)（比较寄存器 1 更新 OK 清除标志）、EXTTRIGCF[2] (WO)（外部触发有效边沿清除标志）、ARRMCF[1] (WO)（待核）、CC1CF[0] (WO)（捕获/比较 1 清除标志） | — |
| `LPTIM1_ICR_INPUT` | LPTIM1 中断清除寄存器 | `0x004` | `0x40002404` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIEROKCF[24] (WO)（中断使能寄存器更新 OK 清除标志）、CC2OCF[13] (WO)（待核）、CC1OCF[12] (WO)（待核）、CC2CF[9] (WO)（捕获/比较 2 清除标志）、REPOKCF[8] (WO)（重复寄存器更新 OK 清除标志）、UECF[7] (WO)（更新事件清除标志）、DOWNCF[6] (WO)（待核）、UPCF[5] (WO)（待核）、ARROKCF[4] (WO)（待核）、EXTTRIGCF[2] (WO)（外部触发有效边沿清除标志）、ARRMCF[1] (WO)（待核）、CC1CF[0] (WO)（捕获/比较 1 清除标志） | 别名 LPTIM1_ICR_OUTPUT |
| `LPTIM1_DIER_OUTPUT` | LPTIM1 中断使能寄存器 | `0x008` | `0x40002408` | 32 | — | 0x00000000 / 0xFFFFFFFF | UEDE[23] (RW)（更新事件 DMA 请求使能）、CMP2OKIE[19] (RW)（比较寄存器 2 更新 OK 中断使能）、CC2IE[9] (RW)（捕获/比较 2 中断使能）、REPOKIE[8] (RW)（重复寄存器更新 OK 中断使能）、UEIE[7] (RW)（更新事件中断使能）、DOWNIE[6] (RW)（待核）、UPIE[5] (RW)（待核）、ARROKIE[4] (RW)（待核）、CMP1OKIE[3] (RW)（比较寄存器 1 更新 OK 中断使能）、EXTTRIGIE[2] (RW)（外部触发有效边沿中断使能）、ARRMIE[1] (RW)（待核）、CC1IE[0] (RW)（捕获/比较 1 中断使能） | — |
| `LPTIM1_DIER_INPUT` | LPTIM1 中断使能寄存器 | `0x008` | `0x40002408` | 32 | — | 0x00000000 / 0xFFFFFFFF | CC2DE[25] (RW)（捕获/比较 2 DMA 请求使能）、UEDE[23] (RW)（更新事件 DMA 请求使能）、CC1DE[16] (RW)（捕获/比较 1 DMA 请求使能）、CC2OIE[13] (RW)（待核）、CC1OIE[12] (RW)（待核）、CC2IE[9] (RW)（捕获/比较 2 中断使能）、REPOKIE[8] (RW)（重复寄存器更新 OK 中断使能）、UEIE[7] (RW)（更新事件中断使能）、DOWNIE[6] (RW)（待核）、UPIE[5] (RW)（待核）、ARROKIE[4] (RW)（待核）、EXTTRIGIE[2] (RW)（外部触发有效边沿中断使能）、ARRMIE[1] (RW)（待核）、CC1IE[0] (RW)（捕获/比较 1 中断使能） | 别名 LPTIM1_DIER_OUTPUT |

## LPTIM2

**模块用途**　低功耗定时器，可在相应低功耗模式下进行计数、比较、触发或唤醒，具体能力取决于实例。

基地址 `0x58002400` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `LPTIM2_ISR_OUTPUT` | LPTIM2 中断与状态寄存器 | `0x000` | `0x58002400` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIEROK[24] (RO)（中断使能寄存器更新 OK）、CMP2OK[19] (RO)（比较寄存器 2 更新 OK）、CC2IF[9] (RO)（比较 2 中断标志）、REPOK[8] (RO)（重复寄存器更新 OK）、UE[7] (RO)（LPTIM 更新事件已发生）、DOWN[6] (RO)（待核）、UP[5] (RO)（待核）、ARROK[4] (RO)（待核）、CMP1OK[3] (RO)（比较寄存器 1 更新 OK）、EXTTRIG[2] (RO)（外部触发边沿事件）、ARRM[1] (RO)（待核）、CC1IF[0] (RO)（比较 1 中断标志） | — |
| `LPTIM2_ISR_INPUT` | LPTIM2 中断与状态寄存器 | `0x000` | `0x58002400` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIEROK[24] (RO)（中断使能寄存器更新 OK）、CC2OF[13] (RO)（待核）、CC1OF[12] (RO)（待核）、CC2IF[9] (RO)（捕获 2 中断标志）、REPOK[8] (RO)（重复寄存器更新 OK）、UE[7] (RO)（LPTIM 更新事件已发生）、DOWN[6] (RO)（待核）、UP[5] (RO)（待核）、ARROK[4] (RO)（待核）、EXTTRIG[2] (RO)（外部触发边沿事件）、ARRM[1] (RO)（待核）、CC1IF[0] (RO)（捕获 1 中断标志） | 别名 LPTIM2_ISR_OUTPUT |
| `LPTIM2_ICR_OUTPUT` | LPTIM2 中断清除寄存器 | `0x004` | `0x58002404` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIEROKCF[24] (WO)（中断使能寄存器更新 OK 清除标志）、CMP2OKCF[19] (WO)（比较寄存器 2 更新 OK 清除标志）、CC2CF[9] (WO)（捕获/比较 2 清除标志）、REPOKCF[8] (WO)（重复寄存器更新 OK 清除标志）、UECF[7] (WO)（更新事件清除标志）、DOWNCF[6] (WO)（待核）、UPCF[5] (WO)（待核）、ARROKCF[4] (WO)（待核）、CMP1OKCF[3] (WO)（比较寄存器 1 更新 OK 清除标志）、EXTTRIGCF[2] (WO)（外部触发有效边沿清除标志）、ARRMCF[1] (WO)（待核）、CC1CF[0] (WO)（捕获/比较 1 清除标志） | — |
| `LPTIM2_ICR_INPUT` | LPTIM2 中断清除寄存器 | `0x004` | `0x58002404` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIEROKCF[24] (WO)（中断使能寄存器更新 OK 清除标志）、CC2OCF[13] (WO)（待核）、CC1OCF[12] (WO)（待核）、CC2CF[9] (WO)（捕获/比较 2 清除标志）、REPOKCF[8] (WO)（重复寄存器更新 OK 清除标志）、UECF[7] (WO)（更新事件清除标志）、DOWNCF[6] (WO)（待核）、UPCF[5] (WO)（待核）、ARROKCF[4] (WO)（待核）、EXTTRIGCF[2] (WO)（外部触发有效边沿清除标志）、ARRMCF[1] (WO)（待核）、CC1CF[0] (WO)（捕获/比较 1 清除标志） | 别名 LPTIM2_ICR_OUTPUT |
| `LPTIM2_DIER_OUTPUT` | LPTIM2 中断使能寄存器 | `0x008` | `0x58002408` | 32 | — | 0x00000000 / 0xFFFFFFFF | UEDE[23] (RW)（更新事件 DMA 请求使能）、CMP2OKIE[19] (RW)（比较寄存器 2 更新 OK 中断使能）、CC2IE[9] (RW)（捕获/比较 2 中断使能）、REPOKIE[8] (RW)（重复寄存器更新 OK 中断使能）、UEIE[7] (RW)（更新事件中断使能）、DOWNIE[6] (RW)（待核）、UPIE[5] (RW)（待核）、ARROKIE[4] (RW)（待核）、CMP1OKIE[3] (RW)（比较寄存器 1 更新 OK 中断使能）、EXTTRIGIE[2] (RW)（外部触发有效边沿中断使能）、ARRMIE[1] (RW)（待核）、CC1IE[0] (RW)（捕获/比较 1 中断使能） | — |
| `LPTIM2_DIER_INPUT` | LPTIM2 中断使能寄存器 | `0x008` | `0x58002408` | 32 | — | 0x00000000 / 0xFFFFFFFF | CC2DE[25] (RW)（捕获/比较 2 DMA 请求使能）、UEDE[23] (RW)（更新事件 DMA 请求使能）、CC1DE[16] (RW)（捕获/比较 1 DMA 请求使能）、CC2OIE[13] (RW)（待核）、CC1OIE[12] (RW)（待核）、CC2IE[9] (RW)（捕获/比较 2 中断使能）、REPOKIE[8] (RW)（重复寄存器更新 OK 中断使能）、UEIE[7] (RW)（更新事件中断使能）、DOWNIE[6] (RW)（待核）、UPIE[5] (RW)（待核）、ARROKIE[4] (RW)（待核）、EXTTRIGIE[2] (RW)（外部触发有效边沿中断使能）、ARRMIE[1] (RW)（待核）、CC1IE[0] (RW)（捕获/比较 1 中断使能） | 别名 LPTIM2_DIER_OUTPUT |

## LPTIM3

**模块用途**　低功耗定时器，可在相应低功耗模式下进行计数、比较、触发或唤醒，具体能力取决于实例。

基地址 `0x58002800` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `LPTIM3_ISR_OUTPUT` | LPTIM3 中断与状态寄存器 | `0x000` | `0x58002800` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIEROK[24] (RO)（中断使能寄存器更新 OK）、CMP2OK[19] (RO)（比较寄存器 2 更新 OK）、CC2IF[9] (RO)（比较 2 中断标志）、REPOK[8] (RO)（重复寄存器更新 OK）、UE[7] (RO)（LPTIM 更新事件已发生）、DOWN[6] (RO)（待核）、UP[5] (RO)（待核）、ARROK[4] (RO)（待核）、CMP1OK[3] (RO)（比较寄存器 1 更新 OK）、EXTTRIG[2] (RO)（外部触发边沿事件）、ARRM[1] (RO)（待核）、CC1IF[0] (RO)（比较 1 中断标志） | — |
| `LPTIM3_ISR_INPUT` | LPTIM3 中断与状态寄存器 | `0x000` | `0x58002800` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIEROK[24] (RO)（中断使能寄存器更新 OK）、CC2OF[13] (RO)（待核）、CC1OF[12] (RO)（待核）、CC2IF[9] (RO)（捕获 2 中断标志）、REPOK[8] (RO)（重复寄存器更新 OK）、UE[7] (RO)（LPTIM 更新事件已发生）、DOWN[6] (RO)（待核）、UP[5] (RO)（待核）、ARROK[4] (RO)（待核）、EXTTRIG[2] (RO)（外部触发边沿事件）、ARRM[1] (RO)（待核）、CC1IF[0] (RO)（捕获 1 中断标志） | 别名 LPTIM3_ISR_OUTPUT |
| `LPTIM3_ICR_OUTPUT` | LPTIM3 中断清除寄存器 | `0x004` | `0x58002804` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIEROKCF[24] (WO)（中断使能寄存器更新 OK 清除标志）、CMP2OKCF[19] (WO)（比较寄存器 2 更新 OK 清除标志）、CC2CF[9] (WO)（捕获/比较 2 清除标志）、REPOKCF[8] (WO)（重复寄存器更新 OK 清除标志）、UECF[7] (WO)（更新事件清除标志）、DOWNCF[6] (WO)（待核）、UPCF[5] (WO)（待核）、ARROKCF[4] (WO)（待核）、CMP1OKCF[3] (WO)（比较寄存器 1 更新 OK 清除标志）、EXTTRIGCF[2] (WO)（外部触发有效边沿清除标志）、ARRMCF[1] (WO)（待核）、CC1CF[0] (WO)（捕获/比较 1 清除标志） | — |
| `LPTIM3_ICR_INPUT` | LPTIM3 中断清除寄存器 | `0x004` | `0x58002804` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIEROKCF[24] (WO)（中断使能寄存器更新 OK 清除标志）、CC2OCF[13] (WO)（待核）、CC1OCF[12] (WO)（待核）、CC2CF[9] (WO)（捕获/比较 2 清除标志）、REPOKCF[8] (WO)（重复寄存器更新 OK 清除标志）、UECF[7] (WO)（更新事件清除标志）、DOWNCF[6] (WO)（待核）、UPCF[5] (WO)（待核）、ARROKCF[4] (WO)（待核）、EXTTRIGCF[2] (WO)（外部触发有效边沿清除标志）、ARRMCF[1] (WO)（待核）、CC1CF[0] (WO)（捕获/比较 1 清除标志） | 别名 LPTIM3_ICR_OUTPUT |
| `LPTIM3_DIER_OUTPUT` | LPTIM3 中断使能寄存器 | `0x008` | `0x58002808` | 32 | — | 0x00000000 / 0xFFFFFFFF | UEDE[23] (RW)（更新事件 DMA 请求使能）、CMP2OKIE[19] (RW)（比较寄存器 2 更新 OK 中断使能）、CC2IE[9] (RW)（捕获/比较 2 中断使能）、REPOKIE[8] (RW)（重复寄存器更新 OK 中断使能）、UEIE[7] (RW)（更新事件中断使能）、DOWNIE[6] (RW)（待核）、UPIE[5] (RW)（待核）、ARROKIE[4] (RW)（待核）、CMP1OKIE[3] (RW)（比较寄存器 1 更新 OK 中断使能）、EXTTRIGIE[2] (RW)（外部触发有效边沿中断使能）、ARRMIE[1] (RW)（待核）、CC1IE[0] (RW)（捕获/比较 1 中断使能） | — |
| `LPTIM3_DIER_INPUT` | LPTIM3 中断使能寄存器 | `0x008` | `0x58002808` | 32 | — | 0x00000000 / 0xFFFFFFFF | CC2DE[25] (RW)（捕获/比较 2 DMA 请求使能）、UEDE[23] (RW)（更新事件 DMA 请求使能）、CC1DE[16] (RW)（捕获/比较 1 DMA 请求使能）、CC2OIE[13] (RW)（待核）、CC1OIE[12] (RW)（待核）、CC2IE[9] (RW)（捕获/比较 2 中断使能）、REPOKIE[8] (RW)（重复寄存器更新 OK 中断使能）、UEIE[7] (RW)（更新事件中断使能）、DOWNIE[6] (RW)（待核）、UPIE[5] (RW)（待核）、ARROKIE[4] (RW)（待核）、EXTTRIGIE[2] (RW)（外部触发有效边沿中断使能）、ARRMIE[1] (RW)（待核）、CC1IE[0] (RW)（捕获/比较 1 中断使能） | 别名 LPTIM3_DIER_OUTPUT |

## LPTIM4

**模块用途**　低功耗定时器，可在相应低功耗模式下进行计数、比较、触发或唤醒，具体能力取决于实例。

基地址 `0x58002C00` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `LPTIM4_ISR` | LPTIM4 中断与状态寄存器 | `0x000` | `0x58002C00` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIEROK[24] (RO)（中断使能寄存器更新 OK）、REPOK[8] (RO)（重复寄存器更新 OK）、UE[7] (RO)（LPTIM 更新事件已发生）、DOWN[6] (RO)（待核）、UP[5] (RO)（待核）、ARROK[4] (RO)（待核）、CMP1OK[3] (RO)（比较寄存器 1 更新 OK）、EXTTRIG[2] (RO)（外部触发边沿事件）、ARRM[1] (RO)（待核）、CC1IF[0] (RO)（比较 1 中断标志） | — |
| `LPTIM4_ICR` | LPTIM4 中断清除寄存器 | `0x004` | `0x58002C04` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIEROKCF[24] (WO)（中断使能寄存器更新 OK 清除标志）、REPOKCF[8] (WO)（重复寄存器更新 OK 清除标志）、UECF[7] (WO)（更新事件清除标志）、DOWNCF[6] (WO)（待核）、UPCF[5] (WO)（待核）、ARROKCF[4] (WO)（待核）、CMP1OKCF[3] (WO)（比较寄存器 1 更新 OK 清除标志）、EXTTRIGCF[2] (WO)（外部触发有效边沿清除标志）、ARRMCF[1] (WO)（待核）、CC1CF[0] (WO)（捕获/比较 1 清除标志） | — |
| `LPTIM4_DIER` | LPTIM4 中断使能寄存器 | `0x008` | `0x58002C08` | 32 | — | 0x00000000 / 0xFFFFFFFF | REPOKIE[8] (RW)（重复寄存器更新 OK 中断使能）、UEIE[7] (RW)（更新事件中断使能）、DOWNIE[6] (RW)（待核）、UPIE[5] (RW)（待核）、ARROKIE[4] (RW)（待核）、CMP1OKIE[3] (RW)（比较寄存器 1 更新 OK 中断使能）、EXTTRIGIE[2] (RW)（外部触发有效边沿中断使能）、ARRMIE[1] (RW)（待核）、CC1IE[0] (RW)（捕获/比较 1 中断使能） | — |

## LPTIM5

**模块用途**　低功耗定时器，可在相应低功耗模式下进行计数、比较、触发或唤醒，具体能力取决于实例。

基地址 `0x58003000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `LPTIM5_ISR` | LPTIM5 中断与状态寄存器 | `0x000` | `0x58003000` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIEROK[24] (RO)（中断使能寄存器更新 OK）、REPOK[8] (RO)（重复寄存器更新 OK）、UE[7] (RO)（LPTIM 更新事件已发生）、DOWN[6] (RO)（待核）、UP[5] (RO)（待核）、ARROK[4] (RO)（待核）、CMP1OK[3] (RO)（比较寄存器 1 更新 OK）、EXTTRIG[2] (RO)（外部触发边沿事件）、ARRM[1] (RO)（待核）、CC1IF[0] (RO)（比较 1 中断标志） | — |
| `LPTIM5_ICR` | LPTIM5 中断清除寄存器 | `0x004` | `0x58003004` | 32 | — | 0x00000000 / 0xFFFFFFFF | DIEROKCF[24] (WO)（中断使能寄存器更新 OK 清除标志）、REPOKCF[8] (WO)（重复寄存器更新 OK 清除标志）、UECF[7] (WO)（更新事件清除标志）、DOWNCF[6] (WO)（待核）、UPCF[5] (WO)（待核）、ARROKCF[4] (WO)（待核）、CMP1OKCF[3] (WO)（比较寄存器 1 更新 OK 清除标志）、EXTTRIGCF[2] (WO)（外部触发有效边沿清除标志）、ARRMCF[1] (WO)（待核）、CC1CF[0] (WO)（捕获/比较 1 清除标志） | — |
| `LPTIM5_DIER` | LPTIM5 中断使能寄存器 | `0x008` | `0x58003008` | 32 | — | 0x00000000 / 0xFFFFFFFF | REPOKIE[8] (RW)（重复寄存器更新 OK 中断使能）、UEIE[7] (RW)（更新事件中断使能）、DOWNIE[6] (RW)（待核）、UPIE[5] (RW)（待核）、ARROKIE[4] (RW)（待核）、CMP1OKIE[3] (RW)（比较寄存器 1 更新 OK 中断使能）、EXTTRIGIE[2] (RW)（外部触发有效边沿中断使能）、ARRMIE[1] (RW)（待核）、CC1IE[0] (RW)（捕获/比较 1 中断使能） | — |

## RTC

**模块用途**　实时时钟，用于保存日历和时间，也提供闹钟、周期唤醒及时间戳相关寄存器。

基地址 `0x58004000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `RTC_TR` | RTC 时间寄存器 | `0x000` | `0x58004000` | 32 | — | 0x00000000 / 0xFFFFFFFF | PM[22] (RW)（待核）、HT[21:20] (RW)（待核）、HU[19:16] (RW)（待核）、MNT[14:12] (RW)（待核）、MNU[11:8] (RW)（待核）、ST[6:4] (RW)（待核）、SU[3:0] (RW)（待核） | — |
| `RTC_DR` | RTC 日期寄存器 | `0x004` | `0x58004004` | 32 | — | 0x00002101 / 0xFFFFFFFF | YT[23:20] (RW)（待核）、YU[19:16] (RW)（待核）、WDU[15:13] (RW)（待核）、MT[12] (RW)（待核）、MU[11:8] (RW)（待核）、DT[5:4] (RW)（待核）、DU[3:0] (RW)（待核） | — |
| `RTC_SSR` | RTC 亚秒寄存器 | `0x008` | `0x58004008` | 32 | — | 0x00000000 / 0xFFFFFFFF | SS[31:0] (RO)（同步二进制计数器） | — |
| `RTC_ICSR` | RTC 初始化控制与状态寄存器 | `0x00C` | `0x5800400C` | 32 | — | 0x00000007 / 0xFFFFFFFF | RECALPF[16] (RO)（待核）、BCDU[12:10] (RW)（BCD 更新 (BIN = 10 或 11)）、BIN[9:8] (RW)（二进制模式）、INIT[7] (RW)（初始化模式）、INITF[6] (RO)（初始化标志）、RSF[5] (RW)（寄存器同步标志）、INITS[4] (RO)（初始化状态标志）、SHPF[3] (RO)（移位操作挂起）、WUTWF[2] (RO)（唤醒定时器写入标志） | — |
| `RTC_PRER` | RTC 预分频器寄存器 | `0x010` | `0x58004010` | 32 | — | 0x007F00FF / 0xFFFFFFFF | PREDIV_A[22:16] (RW)（异步预分频器系数）、PREDIV_S[14:0] (RW)（同步预分频器系数） | — |
| `RTC_WUTR` | RTC 唤醒定时器寄存器 | `0x014` | `0x58004014` | 32 | — | 0x0000FFFF / 0xFFFFFFFF | WUTOCLR[31:16] (RW)（唤醒自动重装输出清除值）、WUT[15:0] (RW)（唤醒自动重装值位） | — |
| `RTC_CR` | RTC 控制寄存器 | `0x018` | `0x58004018` | 32 | — | 0x00000000 / 0xFFFFFFFF | OUT2EN[31] (RW)（RTC_OUT2 输出使能）、TAMPALRM_TYPE[30] (RW)（待核）、TAMPALRM_PU[29] (RW)（TAMPALRM 上拉使能）、ALRBFCLR[28] (RW)（待核）、ALRAFCLR[27] (RW)（待核）、TAMPOE[26] (RW)（篡改检测输出使能的 TAMPALRM）、TAMPTS[25] (RW)（待核）、ITSE[24] (RW)（时间戳的内部事件使能）、COE[23] (RW)（校准输出使能）、OSEL[22:21] (RW)（输出选择）、POL[20] (RW)（输出极性）、COSEL[19] (RW)（校准输出选择）、BKP[18] (RW)（备份）、SUB1H[17] (WO)（待核）、ADD1H[16] (WO)（待核）、TSIE[15] (RW)（时间戳中断使能）、WUTIE[14] (RW)（唤醒定时器中断使能）、ALRBIE[13] (RW)（闹钟 B 中断使能）、ALRAIE[12] (RW)（闹钟中断使能）、TSE[11] (RW)（时间戳使能）、WUTE[10] (RW)（唤醒定时器使能）、ALRBE[9] (RW)（闹钟 B 使能）、ALRAE[8] (RW)（闹钟使能）、SSRUIE[7] (RW)（SSR 下溢中断使能）、FMT[6] (RW)（小时格式）、BYPSHAD[5] (RW)（待核）、REFCKON[4] (RW)（待核）、TSEDGE[3] (RW)（时间戳事件活动边沿）、WUCKSEL[2:0] (RW)（ck_wut 唤醒时钟选择） | — |
| `RTC_PRIVCFGR` | RTC 特权模式控制寄存器 | `0x01C` | `0x5800401C` | 32 | — | 0x00000000 / 0xFFFFFFFF | PRIV[15] (RW)（RTC 特权保护）、INITPRIV[14] (RW)（初始化特权保护）、CALPRIV[13] (RW)（待核）、TSPRIV[3] (RW)（时间戳特权保护）、WUTPRIV[2] (RW)（唤醒定时器特权保护）、ALRBPRIV[1] (RW)（闹钟 B 特权保护）、ALRAPRIV[0] (RW)（闹钟与 SSR 下溢特权保护） | — |
| `RTC_WPR` | RTC 写保护寄存器 | `0x024` | `0x58004024` | 32 | — | 0x00000000 / 0xFFFFFFFF | KEY[7:0] (WO)（写保护密钥） | — |
| `RTC_CALR` | RTC 校准寄存器 | `0x028` | `0x58004028` | 32 | — | 0x00000000 / 0xFFFFFFFF | CALP[15] (RW)（待核）、CALW8[14] (RW)（待核）、CALW16[13] (RW)（待核）、LPCAL[12] (RW)（RTC 低位-电源模式）、CALM[8:0] (RW)（校准减） | — |
| `RTC_SHIFTR` | RTC 移位控制寄存器 | `0x02C` | `0x5800402C` | 32 | — | 0x00000000 / 0xFFFFFFFF | ADD1S[31] (WO)（待核）、SUBFS[14:0] (WO)（待核） | — |
| `RTC_TSTR` | RTC 时间戳时间寄存器 | `0x030` | `0x58004030` | 32 | — | 0x00000000 / 0xFFFFFFFF | PM[22] (RO)（待核）、HT[21:20] (RO)（待核）、HU[19:16] (RO)（待核）、MNT[14:12] (RO)（待核）、MNU[11:8] (RO)（待核）、ST[6:4] (RO)（待核）、SU[3:0] (RO)（待核） | — |
| `RTC_TSDR` | RTC 时间戳日期寄存器 | `0x034` | `0x58004034` | 32 | — | 0x00000000 / 0xFFFFFFFF | WDU[15:13] (RO)（待核）、MT[12] (RO)（待核）、MU[11:8] (RO)（待核）、DT[5:4] (RO)（待核）、DU[3:0] (RO)（待核） | — |
| `RTC_TSSSR` | RTC 时间戳亚秒寄存器 | `0x038` | `0x58004038` | 32 | — | 0x00000000 / 0xFFFFFFFF | SS[31:0] (RO)（亚秒值/同步二进制计数器值） | — |
| `RTC_ALRMAR` | RTC 闹钟寄存器 | `0x040` | `0x58004040` | 32 | — | 0x00000000 / 0xFFFFFFFF | MSK4[31] (RW)（闹钟日期屏蔽）、WDSEL[30] (RW)（待核）、DT[29:28] (RW)（待核）、DU[27:24] (RW)（待核）、MSK3[23] (RW)（闹钟小时屏蔽）、PM[22] (RW)（待核）、HT[21:20] (RW)（待核）、HU[19:16] (RW)（待核）、MSK2[15] (RW)（闹钟分钟屏蔽）、MNT[14:12] (RW)（待核）、MNU[11:8] (RW)（待核）、MSK1[7] (RW)（闹钟秒屏蔽）、ST[6:4] (RW)（待核）、SU[3:0] (RW)（待核） | — |
| `RTC_ALRMASSR` | RTC 闹钟亚秒寄存器 | `0x044` | `0x58004044` | 32 | — | 0x00000000 / 0xFFFFFFFF | SSCLR[31] (RW)（待核）、MASKSS[29:24] (RW)（待核）、SS[14:0] (RW)（待核） | — |
| `RTC_ALRMBR` | RTC 闹钟 B 寄存器 | `0x048` | `0x58004048` | 32 | — | 0x00000000 / 0xFFFFFFFF | MSK4[31] (RW)（闹钟 B 日期屏蔽）、WDSEL[30] (RW)（待核）、DT[29:28] (RW)（待核）、DU[27:24] (RW)（待核）、MSK3[23] (RW)（闹钟 B 小时屏蔽）、PM[22] (RW)（待核）、HT[21:20] (RW)（待核）、HU[19:16] (RW)（待核）、MSK2[15] (RW)（闹钟 B 分钟屏蔽）、MNT[14:12] (RW)（待核）、MNU[11:8] (RW)（待核）、MSK1[7] (RW)（闹钟 B 秒屏蔽）、ST[6:4] (RW)（待核）、SU[3:0] (RW)（待核） | — |
| `RTC_ALRMBSSR` | RTC 闹钟 B 亚秒寄存器 | `0x04C` | `0x5800404C` | 32 | — | 0x00000000 / 0xFFFFFFFF | SSCLR[31] (RW)（待核）、MASKSS[29:24] (RW)（待核）、SS[14:0] (RW)（待核） | — |
| `RTC_SR` | RTC 状态寄存器 | `0x050` | `0x58004050` | 32 | — | 0x00000000 / 0xFFFFFFFF | SSRUF[6] (RO)（SSR 下溢标志）、ITSF[5] (RO)（内部时间戳标志）、TSOVF[4] (RO)（时间戳溢出标志）、TSF[3] (RO)（时间戳标志）、WUTF[2] (RO)（唤醒定时器标志）、ALRBF[1] (RO)（闹钟 B 标志）、ALRAF[0] (RO)（闹钟标志） | — |
| `RTC_MISR` | RTC 屏蔽后中断状态寄存器 | `0x054` | `0x58004054` | 32 | — | 0x00000000 / 0xFFFFFFFF | SSRUMF[6] (RO)（SSR 下溢屏蔽后标志）、ITSMF[5] (RO)（内部时间戳屏蔽后标志）、TSOVMF[4] (RO)（时间戳溢出屏蔽后标志）、TSMF[3] (RO)（时间戳屏蔽后标志）、WUTMF[2] (RO)（唤醒定时器屏蔽后标志）、ALRBMF[1] (RO)（闹钟 B 屏蔽后标志）、ALRAMF[0] (RO)（闹钟屏蔽后标志） | — |
| `RTC_SCR` | RTC 状态清除寄存器 | `0x05C` | `0x5800405C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CSSRUF[6] (WO)（清除 SSR 下溢标志）、CITSF[5] (WO)（清除内部时间戳标志）、CTSOVF[4] (WO)（清除时间戳溢出标志）、CTSF[3] (WO)（清除时间戳标志）、CWUTF[2] (WO)（清除唤醒定时器标志）、CALRBF[1] (WO)（清除闹钟 B 标志）、CALRAF[0] (WO)（清除闹钟标志） | — |
| `RTC_ALRABINR` | RTC 闹钟二进制模式寄存器 | `0x070` | `0x58004070` | 32 | — | 0x00000000 / 0xFFFFFFFF | SS[31:0] (RW)（同步计数器闹钟值内二进制模式） | — |
| `RTC_ALRBBINR` | RTC 闹钟 B 二进制模式寄存器 | `0x074` | `0x58004074` | 32 | — | 0x00000000 / 0xFFFFFFFF | SS[31:0] (RW)（同步计数器闹钟值内二进制模式） | — |

## TAMP

**模块用途**　防篡改控制器，可检测配置的篡改事件并按策略处理备份数据，同时提供备份寄存器。

基地址 `0x58004400` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `TAMP_CR1` | TAMP 控制寄存器 1 | `0x000` | `0x58004400` | 32 | — | 0x00000000 / 0xFFFFFFFF | ITAMP15E[30] (RW)（内部篡改 15 使能）、ITAMP11E[26] (RW)（内部篡改 11 使能）、ITAMP9E[24] (RW)（内部篡改 9 使能）、ITAMP8E[23] (RW)（内部篡改 8 使能）、ITAMP7E[22] (RW)（内部篡改 7 使能）、ITAMP6E[21] (RW)（内部篡改 6 使能）、ITAMP5E[20] (RW)（内部篡改 5 使能）、ITAMP4E[19] (RW)（内部篡改 4 使能）、ITAMP3E[18] (RW)（内部篡改 3 使能）、ITAMP2E[17] (RW)（内部篡改 2 使能）、ITAMP1E[16] (RW)（内部篡改 1 使能）、TAMP8E[7] (RW)（待核）、TAMP7E[6] (RW)（待核）、TAMP6E[5] (RW)（待核）、TAMP5E[4] (RW)（待核）、TAMP4E[3] (RW)（待核）、TAMP3E[2] (RW)（待核）、TAMP2E[1] (RW)（待核）、TAMP1E[0] (RW)（篡改检测的 TAMP_IN1 使能） | — |
| `TAMP_CR2` | TAMP 控制寄存器 2 | `0x004` | `0x58004404` | 32 | — | 0x00000000 / 0xFFFFFFFF | TAMP8TRG[31] (RW)（活动电平的篡改 8 输入 (活动模式禁用)）、TAMP7TRG[30] (RW)（活动电平的篡改 7 输入 (活动模式禁用)）、TAMP6TRG[29] (RW)（活动电平的篡改 6 输入 (活动模式禁用)）、TAMP5TRG[28] (RW)（活动电平的篡改 5 输入 (活动模式禁用)）、TAMP4TRG[27] (RW)（活动电平的篡改 4 输入 (活动模式禁用)）、TAMP3TRG[26] (RW)（活动电平的篡改 3 输入）、TAMP2TRG[25] (RW)（活动电平的篡改 2 输入）、TAMP1TRG[24] (RW)（活动电平的篡改 1 输入）、BKERASE[23] (WO)（待核）、BKBLOCK[22] (RW)（待核）、TAMP3MSK[18] (RW)（篡改 3 屏蔽）、TAMP2MSK[17] (RW)（篡改 2 屏蔽）、TAMP1MSK[16] (RW)（篡改 1 屏蔽）、TAMP8NOER[7] (RW)（待核）、TAMP7NOER[6] (RW)（待核）、TAMP6NOER[5] (RW)（待核）、TAMP5NOER[4] (RW)（待核）、TAMP4NOER[3] (RW)（待核）、TAMP3NOER[2] (RW)（待核）、TAMP2NOER[1] (RW)（待核）、TAMP1NOER[0] (RW)（待核） | — |
| `TAMP_CR3` | TAMP 控制寄存器 3 | `0x008` | `0x58004408` | 32 | — | 0x00000000 / 0xFFFFFFFF | ITAMP15NOER[14] (RW)（待核）、ITAMP11NOER[10] (RW)（待核）、ITAMP9NOER[8] (RW)（待核）、ITAMP8NOER[7] (RW)（待核）、ITAMP7NOER[6] (RW)（待核）、ITAMP6NOER[5] (RW)（待核）、ITAMP5NOER[4] (RW)（待核）、ITAMP4NOER[3] (RW)（待核）、ITAMP3NOER[2] (RW)（待核）、ITAMP2NOER[1] (RW)（待核）、ITAMP1NOER[0] (RW)（待核） | — |
| `TAMP_FLTCR` | TAMP 滤波控制寄存器 | `0x00C` | `0x5800440C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TAMPPUDIS[7] (RW)（TAMP_INx 上拉禁用）、TAMPPRCH[6:5] (RW)（待核）、TAMPFLT[4:3] (RW)（TAMP_INx 滤波计数）、TAMPFREQ[2:0] (RW)（篡改采样频率） | — |
| `TAMP_ATCR1` | TAMP 活动篡改控制寄存器 1 | `0x010` | `0x58004410` | 32 | — | 0x00070000 / 0xFFFFFFFF | FLTEN[31] (RW)（活动篡改滤波使能）、ATOSHARE[30] (RW)（待核）、ATPER[26:24] (RW)（待核）、ATCKSEL[18:16] (RW)（活动篡改 RTC 异步预分频器时钟选择）、ATOSEL4[15:14] (RW)（待核）、ATOSEL3[13:12] (RW)（待核）、ATOSEL2[11:10] (RW)（待核）、ATOSEL1[9:8] (RW)（待核）、TAMP8AM[7] (RW)（篡改 8 活动模式）、TAMP7AM[6] (RW)（篡改 7 活动模式）、TAMP6AM[5] (RW)（篡改 6 活动模式）、TAMP5AM[4] (RW)（篡改 5 活动模式）、TAMP4AM[3] (RW)（篡改 4 活动模式）、TAMP3AM[2] (RW)（篡改 3 活动模式）、TAMP2AM[1] (RW)（篡改 2 活动模式）、TAMP1AM[0] (RW)（篡改 1 活动模式） | — |
| `TAMP_ATSEEDR` | TAMP 活动篡改种子寄存器 | `0x014` | `0x58004414` | 32 | — | 0x00000000 / 0xFFFFFFFF | SEED[31:0] (WO)（待核） | — |
| `TAMP_ATOR` | TAMP 活动篡改输出寄存器 | `0x018` | `0x58004418` | 32 | — | 0x00000000 / 0xFFFFFFFF | INITS[15] (RO)（活动篡改初始化状态）、SEEDF[14] (RO)（待核）、PRNG[7:0] (RO)（待核） | — |
| `TAMP_ATCR2` | TAMP 活动篡改控制寄存器 2 | `0x01C` | `0x5800441C` | 32 | — | 0x00000000 / 0xFFFFFFFF | ATOSEL8[31:29] (RW)（待核）、ATOSEL7[28:26] (RW)（待核）、ATOSEL6[25:23] (RW)（待核）、ATOSEL5[22:20] (RW)（待核）、ATOSEL4[19:17] (RW)（待核）、ATOSEL3[16:14] (RW)（待核）、ATOSEL2[13:11] (RW)（待核）、ATOSEL1[10:8] (RW)（待核） | — |
| `TAMP_CFGR` | TAMP 配置寄存器 | `0x020` | `0x58004420` | 32 | — | 0x00000000 / 0xFFFFFFFF | BHKLOCK[30] (RW)（启动硬件密钥锁定）、BKPW[23:16] (RW)（备份寄存器写保护偏移）、BKPRW[7:0] (RW)（备份寄存器读取/写保护偏移） | — |
| `TAMP_PRIVCFGR` | TAMP 特权配置寄存器 | `0x024` | `0x58004424` | 32 | — | 0x00000000 / 0xFFFFFFFF | TAMPPRIV[31] (RW)（待核）、BKPWPRIV[30] (RW)（备份寄存器区域 2 特权保护）、BKPRWPRIV[29] (RW)（备份寄存器区域 1 特权保护）、CNT1PRIV[15] (RW)（单调递增计数器 1 特权保护） | — |
| `TAMP_IER` | TAMP 中断使能寄存器 | `0x02C` | `0x5800442C` | 32 | — | 0x00000000 / 0xFFFFFFFF | ITAMP15IE[30] (RW)（内部篡改 15 中断使能）、ITAMP11IE[26] (RW)（内部篡改 11 中断使能）、ITAMP9IE[24] (RW)（内部篡改 9 中断使能）、ITAMP8IE[23] (RW)（内部篡改 8 中断使能）、ITAMP7IE[22] (RW)（内部篡改 7 中断使能）、ITAMP6IE[21] (RW)（内部篡改 6 中断使能）、ITAMP5IE[20] (RW)（内部篡改 5 中断使能）、ITAMP4IE[19] (RW)（内部篡改 4 中断使能）、ITAMP3IE[18] (RW)（内部篡改 3 中断使能）、ITAMP2IE[17] (RW)（内部篡改 2 中断使能）、ITAMP1IE[16] (RW)（内部篡改 1 中断使能）、TAMP8IE[7] (RW)（篡改 8 中断使能）、TAMP7IE[6] (RW)（待核）、TAMP6IE[5] (RW)（篡改 6 中断使能）、TAMP5IE[4] (RW)（篡改 5 中断使能）、TAMP4IE[3] (RW)（篡改 4 中断使能）、TAMP3IE[2] (RW)（篡改 3 中断使能）、TAMP2IE[1] (RW)（篡改 2 中断使能）、TAMP1IE[0] (RW)（篡改 1 中断使能） | — |
| `TAMP_SR` | TAMP 状态寄存器 | `0x030` | `0x58004430` | 32 | — | 0x00000000 / 0xFFFFFFFF | ITAMP15F[30] (RW)（内部篡改 15 标志）、ITAMP11F[26] (RO)（内部篡改 11 标志）、ITAMP9F[24] (RO)（内部篡改 9 标志）、ITAMP8F[23] (RO)（内部篡改 8 标志）、ITAMP7F[22] (RO)（内部篡改 7 标志）、ITAMP6F[21] (RO)（内部篡改 6 标志）、ITAMP5F[20] (RO)（内部篡改 5 标志）、ITAMP4F[19] (RO)（内部篡改 4 标志）、ITAMP3F[18] (RO)（内部篡改 3 标志）、ITAMP2F[17] (RO)（内部篡改 2 标志）、ITAMP1F[16] (RO)（内部篡改 1 标志）、TAMP8F[7] (RO)（TAMP8 检测标志）、TAMP7F[6] (RO)（TAMP7 检测标志）、TAMP6F[5] (RO)（TAMP6 检测标志）、TAMP5F[4] (RO)（TAMP5 检测标志）、TAMP4F[3] (RO)（TAMP4 检测标志）、TAMP3F[2] (RO)（TAMP3 检测标志）、TAMP2F[1] (RO)（TAMP2 检测标志）、TAMP1F[0] (RO)（TAMP1 检测标志） | — |
| `TAMP_MISR` | TAMP 屏蔽后中断状态寄存器 | `0x034` | `0x58004434` | 32 | — | 0x00000000 / 0xFFFFFFFF | ITAMP15MF[30] (RO)（内部篡改 15 中断屏蔽后标志）、ITAMP11MF[26] (RO)（内部篡改 11 中断屏蔽后标志）、ITAMP9MF[24] (RO)（内部篡改 9 中断屏蔽后标志）、ITAMP8MF[23] (RO)（内部篡改 8 中断屏蔽后标志）、ITAMP7MF[22] (RO)（内部篡改 7 篡改中断屏蔽后标志）、ITAMP6MF[21] (RO)（内部篡改 6 中断屏蔽后标志）、ITAMP5MF[20] (RO)（内部篡改 5 中断屏蔽后标志）、ITAMP4MF[19] (RO)（内部篡改 4 中断屏蔽后标志）、ITAMP3MF[18] (RO)（内部篡改 3 中断屏蔽后标志）、ITAMP2MF[17] (RO)（内部篡改 2 中断屏蔽后标志）、ITAMP1MF[16] (RO)（内部篡改 1 中断屏蔽后标志）、TAMP8MF[7] (RO)（TAMP8 中断屏蔽后标志）、TAMP7MF[6] (RO)（TAMP7 中断屏蔽后标志）、TAMP6MF[5] (RO)（TAMP6 中断屏蔽后标志）、TAMP5MF[4] (RO)（TAMP5 中断屏蔽后标志）、TAMP4MF[3] (RO)（TAMP4 中断屏蔽后标志）、TAMP3MF[2] (RO)（TAMP3 中断屏蔽后标志）、TAMP2MF[1] (RO)（TAMP2 中断屏蔽后标志）、TAMP1MF[0] (RO)（TAMP1 中断屏蔽后标志） | — |
| `TAMP_SCR` | TAMP 状态清除寄存器 | `0x03C` | `0x5800443C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CITAMP15F[30] (WO)（清除 ITAMP15 检测标志）、CITAMP11F[26] (WO)（清除 ITAMP11 检测标志）、CITAMP9F[24] (WO)（清除 ITAMP9 检测标志）、CITAMP8F[23] (WO)（清除 ITAMP8 检测标志）、CITAMP7F[22] (WO)（清除 ITAMP7 检测标志）、CITAMP6F[21] (WO)（清除 ITAMP6 检测标志）、CITAMP5F[20] (WO)（清除 ITAMP5 检测标志）、CITAMP4F[19] (WO)（清除 ITAMP4 检测标志）、CITAMP3F[18] (WO)（清除 ITAMP3 检测标志）、CITAMP2F[17] (WO)（清除 ITAMP2 检测标志）、CITAMP1F[16] (WO)（清除 ITAMP1 检测标志）、CTAMP8F[7] (WO)（清除 TAMP8 检测标志）、CTAMP7F[6] (WO)（清除 TAMP7 检测标志）、CTAMP6F[5] (WO)（清除 TAMP6 检测标志）、CTAMP5F[4] (WO)（清除 TAMP5 检测标志）、CTAMP4F[3] (WO)（清除 TAMP4 检测标志）、CTAMP3F[2] (WO)（清除 TAMP3 检测标志）、CTAMP2F[1] (WO)（清除 TAMP2 检测标志）、CTAMP1F[0] (WO)（清除 TAMP1 检测标志） | — |
| `TAMP_COUNT1R` | TAMP 单调递增计数器 1 寄存器 | `0x040` | `0x58004440` | 32 | — | 0x00000000 / 0xFFFFFFFF | COUNT[31:0] (RO)（待核） | — |
| `TAMP_BKP0R` | TAMP 备份 0 寄存器 | `0x100` | `0x58004500` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP1R` | TAMP 备份 1 寄存器 | `0x104` | `0x58004504` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP2R` | TAMP 备份 2 寄存器 | `0x108` | `0x58004508` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP3R` | TAMP 备份 3 寄存器 | `0x10C` | `0x5800450C` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP4R` | TAMP 备份 4 寄存器 | `0x110` | `0x58004510` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP5R` | TAMP 备份 5 寄存器 | `0x114` | `0x58004514` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP6R` | TAMP 备份 6 寄存器 | `0x118` | `0x58004518` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP7R` | TAMP 备份 7 寄存器 | `0x11C` | `0x5800451C` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP8R` | TAMP 备份 8 寄存器 | `0x120` | `0x58004520` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP9R` | TAMP 备份 9 寄存器 | `0x124` | `0x58004524` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP10R` | TAMP 备份 10 寄存器 | `0x128` | `0x58004528` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP11R` | TAMP 备份 11 寄存器 | `0x12C` | `0x5800452C` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP12R` | TAMP 备份 12 寄存器 | `0x130` | `0x58004530` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP13R` | TAMP 备份 13 寄存器 | `0x134` | `0x58004534` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP14R` | TAMP 备份 14 寄存器 | `0x138` | `0x58004538` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP15R` | TAMP 备份 15 寄存器 | `0x13C` | `0x5800453C` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP16R` | TAMP 备份 16 寄存器 | `0x140` | `0x58004540` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP17R` | TAMP 备份 17 寄存器 | `0x144` | `0x58004544` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP18R` | TAMP 备份 18 寄存器 | `0x148` | `0x58004548` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP19R` | TAMP 备份 19 寄存器 | `0x14C` | `0x5800454C` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP20R` | TAMP 备份 20 寄存器 | `0x150` | `0x58004550` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP21R` | TAMP 备份 21 寄存器 | `0x154` | `0x58004554` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP22R` | TAMP 备份 22 寄存器 | `0x158` | `0x58004558` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP23R` | TAMP 备份 23 寄存器 | `0x15C` | `0x5800455C` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP24R` | TAMP 备份 24 寄存器 | `0x160` | `0x58004560` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP25R` | TAMP 备份 25 寄存器 | `0x164` | `0x58004564` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP26R` | TAMP 备份 26 寄存器 | `0x168` | `0x58004568` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP27R` | TAMP 备份 27 寄存器 | `0x16C` | `0x5800456C` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP28R` | TAMP 备份 28 寄存器 | `0x170` | `0x58004570` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP29R` | TAMP 备份 29 寄存器 | `0x174` | `0x58004574` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP30R` | TAMP 备份 30 寄存器 | `0x178` | `0x58004578` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |
| `TAMP_BKP31R` | TAMP 备份 31 寄存器 | `0x17C` | `0x5800457C` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKP[31:0] (RW)（备份数据，篡改事件后的保留取决于配置） | — |

## TAMP_CMSIS

**模块用途**　防篡改控制器的芯片头文件补充视图，和 TAMP 主表对照使用。

基地址 `0x58004400` · CMSIS 补表

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `RPCFGR` | 篡改模块的相关配置选项 | `0x054` | `0x58004454` | 32 | — | — / — | RPCFG0[0]（待核） | — |

## TIM1

**模块用途**　高级定时器，可用于输入捕获、输出比较和 PWM，并提供互补输出及刹车保护。

基地址 `0x42000000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `TIM1_CR1` | TIM1 控制寄存器 1 | `0x000` | `0x42000000` | 16 | — | 0x00000000 / 0x0000FFFF | DITHEN[12] (RW)（待核）、UIFREMAP[11] (RW)（待核）、CKD[9:8] (RW)（时钟分频）、ARPE[7] (RW)（自动重装预装载使能）、CMS[6:5] (RW)（待核）、DIR[4] (RW)（方向）、OPM[3] (RW)（待核）、URS[2] (RW)（更新请求源）、UDIS[1] (RW)（更新禁用）、CEN[0] (RW)（计数器使能） | — |
| `TIM1_CR2` | TIM1 控制寄存器 2 | `0x004` | `0x42000004` | 32 | — | 0x00000000 / 0xFFFFFFFF | MMS_1[25] (RW)（待核）、MMS2[23:20] (RW)（主设备模式选择 2）、OIS6[18] (RW)（输出空闲状态 6 (tim_oc6 输出)）、OIS5[16] (RW)（输出空闲状态 5 (tim_oc5 输出)）、OIS4N[15] (RW)（输出空闲状态 4 (tim_oc4n 输出)）、OIS4[14] (RW)（输出空闲状态 4 (tim_oc4 输出)）、OIS3N[13] (RW)（输出空闲状态 3 (tim_oc3n 输出)）、OIS3[12] (RW)（输出空闲状态 3 (tim_oc3n 输出)）、OIS2N[11] (RW)（输出空闲状态 2 (tim_oc2n 输出)）、OIS2[10] (RW)（输出空闲状态 2 (tim_oc2 输出)）、OIS1N[9] (RW)（输出空闲状态 1 (tim_oc1n 输出)）、OIS1[8] (RW)（输出空闲状态 1 (tim_oc1 输出)）、TI1S[7] (RW)（tim_ti1 选择）、MMS[6:4] (RW)（MMS[2:0]: 主设备模式选择）、CCDS[3] (RW)（捕获/比较 DMA 选择）、CCUS[2] (RW)（捕获/比较控制更新选择）、CCPC[0] (RW)（待核） | — |
| `TIM1_SMCR` | TIM1 从设备模式控制寄存器 | `0x008` | `0x42000008` | 32 | — | 0x00000000 / 0xFFFFFFFF | SMSPS[25] (RW)（SMS 预装载源）、SMSPE[24] (RW)（SMS 预装载使能）、TS_1[21:20] (RW)（待核）、SMS_1[16] (RW)（待核）、ETP[15] (RW)（外部触发极性）、ECE[14] (RW)（外部时钟使能）、ETPS[13:12] (RW)（外部触发预分频器）、ETF[11:8] (RW)（外部触发滤波）、MSM[7] (RW)（主设备/从设备模式）、TS[6:4] (RW)（TS[2:0]: 触发选择）、SMS[2:0] (RW)（SMS[2:0]: 从设备模式选择） | — |
| `TIM1_DIER` | TIM1 DMA/中断使能寄存器 | `0x00C` | `0x4200000C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TERRIE[23] (RW)（转换错误中断使能）、IERRIE[22] (RW)（索引错误中断使能）、DIRIE[21] (RW)（待核）、IDXIE[20] (RW)（索引中断使能）、TDE[14] (RW)（触发 DMA 请求使能）、COMDE[13] (RW)（COM DMA 请求使能）、CC4DE[12] (RW)（捕获/比较 4 DMA 请求使能）、CC3DE[11] (RW)（捕获/比较 3 DMA 请求使能）、CC2DE[10] (RW)（捕获/比较 2 DMA 请求使能）、CC1DE[9] (RW)（捕获/比较 1 DMA 请求使能）、UDE[8] (RW)（更新 DMA 请求使能）、BIE[7] (RW)（刹车中断使能）、TIE[6] (RW)（触发中断使能）、COMIE[5] (RW)（COM 中断使能）、CC4IE[4] (RW)（捕获/比较 4 中断使能）、CC3IE[3] (RW)（捕获/比较 3 中断使能）、CC2IE[2] (RW)（捕获/比较 2 中断使能）、CC1IE[1] (RW)（捕获/比较 1 中断使能）、UIE[0] (RW)（更新中断使能） | — |
| `TIM1_SR` | TIM1 状态寄存器 | `0x010` | `0x42000010` | 32 | — | 0x00000000 / 0xFFFFFFFF | TERRF[23] (RW)（转换错误中断标志）、IERRF[22] (RW)（索引错误中断标志）、DIRF[21] (RW)（待核）、IDXF[20] (RW)（索引中断标志）、CC6IF[17] (RW)（比较 6 中断标志）、CC5IF[16] (RW)（比较 5 中断标志）、SBIF[13] (RW)（系统刹车中断标志）、CC4OF[12] (RW)（待核）、CC3OF[11] (RW)（待核）、CC2OF[10] (RW)（待核）、CC1OF[9] (RW)（待核）、B2IF[8] (RW)（刹车 2 中断标志）、BIF[7] (RW)（刹车中断标志）、TIF[6] (RW)（触发中断标志）、COMIF[5] (RW)（COM 中断标志）、CC4IF[4] (RW)（捕获/比较 4 中断标志）、CC3IF[3] (RW)（捕获/比较 3 中断标志）、CC2IF[2] (RW)（捕获/比较 2 中断标志）、CC1IF[1] (RW)（捕获/比较 1 中断标志）、UIF[0] (RW)（更新中断标志） | — |
| `TIM1_EGR` | TIM1 事件生成寄存器 | `0x014` | `0x42000014` | 16 | — | 0x00000000 / 0x0000FFFF | B2G[8] (WO)（刹车 2 生成）、BG[7] (WO)（刹车生成）、TG[6] (WO)（触发生成）、COMG[5] (WO)（捕获/比较控制更新生成）、CC4G[4] (WO)（捕获/比较 4 生成）、CC3G[3] (WO)（捕获/比较 3 生成）、CC2G[2] (WO)（捕获/比较 2 生成）、CC1G[1] (WO)（捕获/比较 1 生成）、UG[0] (WO)（更新生成） | — |
| `TIM1_CCMR1_INPUT` | TIM1 捕获/比较模式寄存器 1 | `0x018` | `0x42000018` | 32 | — | 0x00000000 / 0xFFFFFFFF | IC2F[15:12] (RW)（输入捕获 2 滤波）、IC2PSC[11:10] (RW)（输入捕获 2 预分频器）、CC2S[9:8] (RW)（捕获/比较 2 选择）、IC1F[7:4] (RW)（输入捕获 1 滤波）、IC1PSC[3:2] (RW)（输入捕获 1 预分频器）、CC1S[1:0] (RW)（捕获/比较 1 选择） | — |
| `TIM1_CCMR1_OUTPUT` | TIM1 捕获/比较模式寄存器 1 | `0x018` | `0x42000018` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC2M_1[24] (RW)（待核）、OC1M_1[16] (RW)（待核）、OC2CE[15] (RW)（输出比较 2 清除使能）、OC2M[14:12] (RW)（OC2M[2:0]: 输出比较 2 模式）、OC2PE[11] (RW)（输出比较 2 预装载使能）、OC2FE[10] (RW)（输出比较 2 快速使能）、CC2S[9:8] (RW)（捕获/比较 2 选择）、OC1CE[7] (RW)（输出比较 1 清除使能）、OC1M[6:4] (RW)（OC1M[2:0]: 输出比较 1 模式）、OC1PE[3] (RW)（输出比较 1 预装载使能）、OC1FE[2] (RW)（输出比较 1 快速使能）、CC1S[1:0] (RW)（捕获/比较 1 选择） | 别名 TIM1_CCMR1_INPUT |
| `TIM1_CCMR2_INPUT` | TIM1 捕获/比较模式寄存器 2 | `0x01C` | `0x4200001C` | 32 | — | 0x00000000 / 0xFFFFFFFF | IC4F[15:12] (RW)（输入捕获 4 滤波）、IC4PSC[11:10] (RW)（输入捕获 4 预分频器）、CC4S[9:8] (RW)（捕获/比较 4 选择）、IC3F[7:4] (RW)（输入捕获 3 滤波）、IC3PSC[3:2] (RW)（输入捕获 3 预分频器）、CC3S[1:0] (RW)（捕获/比较 3 选择） | — |
| `TIM1_CCMR2_OUTPUT` | TIM1 捕获/比较模式寄存器 2 | `0x01C` | `0x4200001C` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC4M_1[24] (RW)（待核）、OC3M_1[16] (RW)（待核）、OC4CE[15] (RW)（输出比较 4 清除使能）、OC4M[14:12] (RW)（OC4M[2:0]: 输出比较 4 模式）、OC4PE[11] (RW)（输出比较 4 预装载使能）、OC4FE[10] (RW)（输出比较 4 快速使能）、CC4S[9:8] (RW)（捕获/比较 4 选择）、OC3CE[7] (RW)（输出比较 3 清除使能）、OC3M[6:4] (RW)（OC3M[2:0]: 输出比较 3 模式）、OC3PE[3] (RW)（输出比较 3 预装载使能）、OC3FE[2] (RW)（输出比较 3 快速使能）、CC3S[1:0] (RW)（捕获/比较 3 选择） | 别名 TIM1_CCMR2_INPUT |
| `TIM1_CCER` | TIM1 捕获/比较使能寄存器 | `0x020` | `0x42000020` | 32 | — | 0x00000000 / 0xFFFFFFFF | CC6P[21] (RW)（捕获/比较 6 输出极性）、CC6E[20] (RW)（捕获/比较 6 输出使能）、CC5P[17] (RW)（捕获/比较 5 输出极性）、CC5E[16] (RW)（捕获/比较 5 输出使能）、CC4NP[15] (RW)（待核）、CC4NE[14] (RW)（待核）、CC4P[13] (RW)（捕获/比较 4 输出极性）、CC4E[12] (RW)（捕获/比较 4 输出使能）、CC3NP[11] (RW)（待核）、CC3NE[10] (RW)（待核）、CC3P[9] (RW)（捕获/比较 3 输出极性）、CC3E[8] (RW)（捕获/比较 3 输出使能）、CC2NP[7] (RW)（待核）、CC2NE[6] (RW)（待核）、CC2P[5] (RW)（捕获/比较 2 输出极性）、CC2E[4] (RW)（捕获/比较 2 输出使能）、CC1NP[3] (RW)（待核）、CC1NE[2] (RW)（待核）、CC1P[1] (RW)（捕获/比较 1 输出极性）、CC1E[0] (RW)（捕获/比较 1 输出使能） | — |
| `TIM1_CNT` | TIM1 计数器 | `0x024` | `0x42000024` | 32 | — | 0x00000000 / 0xFFFFFFFF | UIFCPY[31] (RO)（待核）、CNT[15:0] (RW)（计数器值） | — |
| `TIM1_PSC` | TIM1 预分频器 | `0x028` | `0x42000028` | 16 | — | 0x00000000 / 0x0000FFFF | PSC[15:0] (RW)（预分频器值） | — |
| `TIM1_ARR` | TIM1 自动重装寄存器 | `0x02C` | `0x4200002C` | 32 | — | 0x0000FFFF / 0xFFFFFFFF | ARR[19:0] (RW)（自动重装值） | — |
| `TIM1_RCR` | TIM1 重复计数器寄存器 | `0x030` | `0x42000030` | 16 | — | 0x00000000 / 0x0000FFFF | REP[15:0] (RW)（重复计数器重装值） | — |
| `TIM1_CCR1` | TIM1 捕获/比较寄存器 1 | `0x034` | `0x42000034` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR1[19:0] (RW)（捕获/比较 1 值） | — |
| `TIM1_CCR2` | TIM1 捕获/比较寄存器 2 | `0x038` | `0x42000038` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR2[19:0] (RW)（捕获/比较 2 值） | — |
| `TIM1_CCR3` | TIM1 捕获/比较寄存器 3 | `0x03C` | `0x4200003C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR3[19:0] (RW)（捕获/比较值） | — |
| `TIM1_CCR4` | TIM1 捕获/比较寄存器 4 | `0x040` | `0x42000040` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR4[19:0] (RW)（捕获/比较值） | — |
| `TIM1_BDTR` | TIM1 刹车与死区时间寄存器 | `0x044` | `0x42000044` | 32 | — | 0x00000000 / 0xFFFFFFFF | BK2BID[29] (RW)（待核）、BKBID[28] (RW)（待核）、BK2DSRM[27] (RW)（待核）、BKDSRM[26] (RW)（待核）、BK2P[25] (RW)（刹车 2 极性）、BK2E[24] (RW)（刹车 2 使能）、BK2F[23:20] (RW)（刹车 2 滤波）、BKF[19:16] (RW)（刹车滤波）、MOE[15] (RW)（待核）、AOE[14] (RW)（待核）、BKP[13] (RW)（刹车极性）、BKE[12] (RW)（刹车使能）、OSSR[11] (RW)（待核）、OSSI[10] (RW)（待核）、LOCK[9:8] (RW)（锁定配置）、DTG[7:0] (RW)（待核） | — |
| `TIM1_CCR5` | TIM1 捕获/比较寄存器 5 | `0x048` | `0x42000048` | 32 | — | 0x00000000 / 0xFFFFFFFF | GC5C3[31] (RW)（待核）、GC5C2[30] (RW)（待核）、GC5C1[29] (RW)（待核）、CCR5[19:0] (RW)（捕获/比较 5 值） | — |
| `TIM1_CCR6` | TIM1 捕获/比较寄存器 6 | `0x04C` | `0x4200004C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR6[19:0] (RW)（捕获/比较 6 值） | — |
| `TIM1_CCMR3` | TIM1 捕获/比较模式寄存器 3 | `0x050` | `0x42000050` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC6M_1[24] (RW)（待核）、OC5M_1[16] (RW)（待核）、OC6CE[15] (RW)（输出比较 6 清除使能）、OC6M[14:12] (RW)（OC6M[2:0]: 输出比较 6 模式）、OC6PE[11] (RW)（输出比较 6 预装载使能）、OC6FE[10] (RW)（输出比较 6 快速使能）、OC5CE[7] (RW)（输出比较 5 清除使能）、OC5M[6:4] (RW)（OC5M[2:0]: 输出比较 5 模式）、OC5PE[3] (RW)（输出比较 5 预装载使能）、OC5FE[2] (RW)（输出比较 5 快速使能） | — |
| `TIM1_DTR2` | TIM1 定时器死区时间寄存器 2 | `0x054` | `0x42000054` | 32 | — | 0x00000000 / 0xFFFFFFFF | DTPE[17] (RW)（死区时间预装载使能）、DTAE[16] (RW)（死区时间非对称使能）、DTGF[7:0] (RW)（待核） | — |
| `TIM1_ECR` | TIM1 定时器编码器控制寄存器 | `0x058` | `0x42000058` | 32 | — | 0x00000000 / 0xFFFFFFFF | PWPRSC[26:24] (RW)（脉冲宽度预分频器）、PW[23:16] (RW)（脉冲宽度）、IPOS[7:6] (RW)（待核）、FIDX[5] (RW)（首个索引）、IBLK[4:3] (RW)（待核）、IDIR[2:1] (RW)（索引方向）、IE[0] (RW)（索引使能） | — |
| `TIM1_TISEL` | TIM1 定时器输入选择寄存器 | `0x05C` | `0x4200005C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TI4SEL[27:24] (RW)（待核）、TI3SEL[19:16] (RW)（待核）、TI2SEL[11:8] (RW)（待核）、TI1SEL[3:0] (RW)（待核） | — |
| `TIM1_AF1` | TIM1 复用功能选项寄存器 1 | `0x060` | `0x42000060` | 32 | — | 0x00000001 / 0xFFFFFFFF | ETRSEL[17:14] (RW)（etr_in 源选择）、BKCMP4P[13] (RW)（tim_brk_cmp4 输入极性）、BKCMP3P[12] (RW)（tim_brk_cmp3 输入极性）、BKCMP2P[11] (RW)（tim_brk_cmp2 输入极性）、BKCMP1P[10] (RW)（tim_brk_cmp1 输入极性）、BKINP[9] (RW)（TIMx_BKIN 输入极性）、BKCMP8E[8] (RW)（tim_brk_cmp8 使能）、BKCMP7E[7] (RW)（tim_brk_cmp7 使能）、BKCMP6E[6] (RW)（tim_brk_cmp6 使能）、BKCMP5E[5] (RW)（tim_brk_cmp5 使能）、BKCMP4E[4] (RW)（tim_brk_cmp4 使能）、BKCMP3E[3] (RW)（tim_brk_cmp3 使能）、BKCMP2E[2] (RW)（tim_brk_cmp2 使能）、BKCMP1E[1] (RW)（tim_brk_cmp1 使能）、BKINE[0] (RW)（TIMx_BKIN 输入使能） | — |
| `TIM1_AF2` | TIM1 复用功能寄存器 2 | `0x064` | `0x42000064` | 32 | — | 0x00000001 / 0xFFFFFFFF | OCRSEL[18:16] (RW)（ocref_clr 源选择）、BK2CMP4P[13] (RW)（tim_brk2_cmp4 输入极性）、BK2CMP3P[12] (RW)（tim_brk2_cmp3 输入极性）、BK2CMP2P[11] (RW)（tim_brk2_cmp2 输入极性）、BK2CMP1P[10] (RW)（tim_brk2_cmp1 输入极性）、BK2INP[9] (RW)（TIMx_BKIN2 输入极性）、BK2CMP8E[8] (RW)（tim_brk2_cmp8 使能）、BK2CMP7E[7] (RW)（tim_brk2_cmp7 使能）、BK2CMP6E[6] (RW)（tim_brk2_cmp6 使能）、BK2CMP5E[5] (RW)（tim_brk2_cmp5 使能）、BK2CMP4E[4] (RW)（tim_brk2_cmp4 使能）、BK2CMP3E[3] (RW)（tim_brk2_cmp3 使能）、BK2CMP2E[2] (RW)（tim_brk2_cmp2 使能）、BK2CMP1E[1] (RW)（tim_brk2_cmp1 使能）、BK2INE[0] (RW)（TIMx_BKIN2 输入使能） | — |
| `TIM1_DCR` | TIM1 DMA 控制寄存器 | `0x3DC` | `0x420003DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | DBSS[19:16] (RW)（DMA 突发源选择）、DBL[12:8] (RW)（DMA 突发长度）、DBA[4:0] (RW)（DMA 基址地址） | — |
| `TIM1_DMAR` | TIM1 DMA 地址的满传输 | `0x3E0` | `0x420003E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DMAB[31:0] (RW)（待核） | — |

## TIM12

**模块用途**　通用定时器，按实例提供计数、输入捕获、输出比较、PWM 或触发功能。以本实例表中的通道为准。

基地址 `0x40001800` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `TIM12_CR1` | TIM12 控制寄存器 1 | `0x000` | `0x40001800` | 16 | — | 0x00000000 / 0x0000FFFF | DITHEN[12] (RW)（待核）、UIFREMAP[11] (RW)（待核）、CKD[9:8] (RW)（时钟分频）、ARPE[7] (RW)（自动重装预装载使能）、OPM[3] (RW)（待核）、URS[2] (RW)（更新请求源）、UDIS[1] (RW)（更新禁用）、CEN[0] (RW)（计数器使能） | — |
| `TIM12_CR2` | TIM12 控制寄存器 2 | `0x004` | `0x40001804` | 16 | — | 0x00000000 / 0x0000FFFF | TI1S[7] (RW)（tim_ti1 选择）、MMS[6:4] (RW)（主设备模式选择） | — |
| `TIM12_SMCR` | TIM12 从设备模式控制寄存器 | `0x008` | `0x40001808` | 32 | — | 0x00000000 / 0xFFFFFFFF | TS_1[21:20] (RW)（待核）、SMS_1[16] (RW)（待核）、MSM[7] (RW)（主设备/从设备模式）、TS[6:4] (RW)（TS[0]: 触发选择）、SMS[2:0] (RW)（SMS[0]: 从设备模式选择） | — |
| `TIM12_DIER` | TIM12 中断使能寄存器 | `0x00C` | `0x4000180C` | 16 | — | 0x00000000 / 0x0000FFFF | TIE[6] (RW)（触发中断使能）、CC2IE[2] (RW)（捕获/比较 2 中断使能）、CC1IE[1] (RW)（捕获/比较 1 中断使能）、UIE[0] (RW)（更新中断使能） | — |
| `TIM12_SR` | TIM12 状态寄存器 | `0x010` | `0x40001810` | 16 | — | 0x00000000 / 0x0000FFFF | CC2OF[10] (RW)（待核）、CC1OF[9] (RW)（待核）、TIF[6] (RW)（触发中断标志）、CC2IF[2] (RW)（捕获/比较 2 中断标志）、CC1IF[1] (RW)（捕获/比较 1 中断标志）、UIF[0] (RW)（更新中断标志） | — |
| `TIM12_EGR` | TIM12 事件生成寄存器 | `0x014` | `0x40001814` | 16 | — | 0x00000000 / 0x0000FFFF | TG[6] (WO)（触发生成）、CC2G[2] (WO)（捕获/比较 2 生成）、CC1G[1] (WO)（捕获/比较 1 生成）、UG[0] (WO)（更新生成） | — |
| `TIM12_CCMR1_INPUT` | TIM12 捕获/比较模式寄存器 1 | `0x018` | `0x40001818` | 32 | — | 0x00000000 / 0xFFFFFFFF | IC2F[15:12] (RW)（输入捕获 2 滤波）、IC2PSC[11:10] (RW)（输入捕获 2 预分频器）、CC2S[9:8] (RW)（捕获/比较 2 选择）、IC1F[7:4] (RW)（输入捕获 1 滤波）、IC1PSC[3:2] (RW)（输入捕获 1 预分频器）、CC1S[1:0] (RW)（捕获/比较 1 选择） | — |
| `TIM12_CCMR1_OUTPUT` | TIM12 捕获/比较模式寄存器 1 | `0x018` | `0x40001818` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC2M_1[24] (RW)（待核）、OC1M_1[16] (RW)（待核）、OC2M[14:12] (RW)（OC2M[2:0]: 输出比较 2 模式）、OC2PE[11] (RW)（输出比较 2 预装载使能）、OC2FE[10] (RW)（输出比较 2 快速使能）、CC2S[9:8] (RW)（捕获/比较 2 选择）、OC1M[6:4] (RW)（待核）、OC1PE[3] (RW)（输出比较 1 预装载使能）、OC1FE[2] (RW)（输出比较 1 快速使能）、CC1S[1:0] (RW)（捕获/比较 1 选择） | 别名 TIM12_CCMR1_INPUT |
| `TIM12_CCER` | TIM12 捕获/比较使能寄存器 | `0x020` | `0x40001820` | 16 | — | 0x00000000 / 0x0000FFFF | CC2NP[7] (RW)（捕获/比较 2 输出极性）、CC2P[5] (RW)（捕获/比较 2 输出极性）、CC2E[4] (RW)（捕获/比较 2 输出使能）、CC1NP[3] (RW)（待核）、CC1P[1] (RW)（捕获/比较 1 输出极性）、CC1E[0] (RW)（捕获/比较 1 输出使能） | — |
| `TIM12_CNT` | TIM12 计数器 | `0x024` | `0x40001824` | 32 | — | 0x00000000 / 0xFFFFFFFF | UIFCPY[31] (RW)（待核）、CNT[15:0] (RW)（计数器值） | — |
| `TIM12_PSC` | TIM12 预分频器 | `0x028` | `0x40001828` | 16 | — | 0x00000000 / 0x0000FFFF | PSC[15:0] (RW)（预分频器值） | — |
| `TIM12_ARR` | TIM12 自动重装寄存器 | `0x02C` | `0x4000182C` | 32 | — | 0x0000FFFF / 0xFFFFFFFF | ARR[19:0] (RW)（自动重装值） | — |
| `TIM12_CCR1` | TIM12 捕获/比较寄存器 1 | `0x034` | `0x40001834` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR1[19:0] (RW)（捕获/比较 1 值） | — |
| `TIM12_CCR2` | TIM12 捕获/比较寄存器 2 | `0x038` | `0x40001838` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR2[19:0] (RW)（捕获/比较 2 值） | — |
| `TIM12_TISEL` | TIM12 定时器输入选择寄存器 | `0x05C` | `0x4000185C` | 16 | — | 0x00000000 / 0x0000FFFF | TI2SEL[11:8] (RW)（待核）、TI1SEL[3:0] (RW)（待核） | — |

## TIM13

**模块用途**　通用定时器，按实例提供计数、输入捕获、输出比较、PWM 或触发功能。以本实例表中的通道为准。

基地址 `0x40001C00` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `TIM13_CR1` | TIM13 控制寄存器 1 | `0x000` | `0x40001C00` | 16 | — | 0x00000000 / 0x0000FFFF | DITHEN[12] (RW)（待核）、UIFREMAP[11] (RW)（待核）、CKD[9:8] (RW)（时钟分频）、ARPE[7] (RW)（自动重装预装载使能）、OPM[3] (RW)（待核）、URS[2] (RW)（更新请求源）、UDIS[1] (RW)（更新禁用）、CEN[0] (RW)（计数器使能） | — |
| `TIM13_DIER` | TIM13 中断使能寄存器 | `0x00C` | `0x40001C0C` | 16 | — | 0x00000000 / 0x0000FFFF | CC1IE[1] (RW)（捕获/比较 1 中断使能）、UIE[0] (RW)（更新中断使能） | — |
| `TIM13_SR` | TIM13 状态寄存器 | `0x010` | `0x40001C10` | 16 | — | 0x00000000 / 0x0000FFFF | CC1OF[9] (RW)（待核）、CC1IF[1] (RW)（捕获/比较 1 中断标志）、UIF[0] (RW)（更新中断标志） | — |
| `TIM13_EGR` | TIM13 事件生成寄存器 | `0x014` | `0x40001C14` | 16 | — | 0x00000000 / 0x0000FFFF | CC1G[1] (WO)（捕获/比较 1 生成）、UG[0] (WO)（更新生成） | — |
| `TIM13_CCMR1_INPUT` | TIM13 捕获/比较模式寄存器 1 | `0x018` | `0x40001C18` | 32 | — | 0x00000000 / 0xFFFFFFFF | IC1F[7:4] (RW)（输入捕获 1 滤波）、IC1PSC[3:2] (RW)（输入捕获 1 预分频器）、CC1S[1:0] (RW)（捕获/比较 1 选择） | — |
| `TIM13_CCMR1_OUTPUT` | TIM13 捕获/比较模式寄存器 1 | `0x018` | `0x40001C18` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC1M_1[16] (RW)（待核）、OC1M[6:4] (RW)（待核）、OC1PE[3] (RW)（输出比较 1 预装载使能）、OC1FE[2] (RW)（输出比较 1 快速使能）、CC1S[1:0] (RW)（捕获/比较 1 选择） | 别名 TIM13_CCMR1_INPUT |
| `TIM13_CCER` | TIM13 捕获/比较使能寄存器 | `0x020` | `0x40001C20` | 16 | — | 0x00000000 / 0x0000FFFF | CC1NP[3] (RW)（待核）、CC1P[1] (RW)（捕获/比较 1 输出极性）、CC1E[0] (RW)（捕获/比较 1 输出使能） | — |
| `TIM13_CNT` | TIM13 计数器 | `0x024` | `0x40001C24` | 32 | — | 0x00000000 / 0xFFFFFFFF | UIFCPY[31] (RW)（待核）、CNT[15:0] (RW)（计数器值） | — |
| `TIM13_PSC` | TIM13 预分频器 | `0x028` | `0x40001C28` | 16 | — | 0x00000000 / 0x0000FFFF | PSC[15:0] (RW)（预分频器值） | — |
| `TIM13_ARR` | TIM13 自动重装寄存器 | `0x02C` | `0x40001C2C` | 32 | — | 0x0000FFFF / 0xFFFFFFFF | ARR[19:0] (RW)（自动重装值） | — |
| `TIM13_CCR1` | TIM13 捕获/比较寄存器 1 | `0x034` | `0x40001C34` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR1[19:0] (RW)（捕获/比较 1 值） | — |
| `TIM13_TISEL` | TIM13 定时器输入选择寄存器 | `0x05C` | `0x40001C5C` | 16 | — | 0x00000000 / 0x0000FFFF | TI1SEL[3:0] (RW)（待核） | — |

## TIM14

**模块用途**　通用定时器，按实例提供计数、输入捕获、输出比较、PWM 或触发功能。以本实例表中的通道为准。

基地址 `0x40002000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `TIM14_CR1` | TIM14 控制寄存器 1 | `0x000` | `0x40002000` | 16 | — | 0x00000000 / 0x0000FFFF | DITHEN[12] (RW)（待核）、UIFREMAP[11] (RW)（待核）、CKD[9:8] (RW)（时钟分频）、ARPE[7] (RW)（自动重装预装载使能）、OPM[3] (RW)（待核）、URS[2] (RW)（更新请求源）、UDIS[1] (RW)（更新禁用）、CEN[0] (RW)（计数器使能） | — |
| `TIM14_DIER` | TIM14 中断使能寄存器 | `0x00C` | `0x4000200C` | 16 | — | 0x00000000 / 0x0000FFFF | CC1IE[1] (RW)（捕获/比较 1 中断使能）、UIE[0] (RW)（更新中断使能） | — |
| `TIM14_SR` | TIM14 状态寄存器 | `0x010` | `0x40002010` | 16 | — | 0x00000000 / 0x0000FFFF | CC1OF[9] (RW)（待核）、CC1IF[1] (RW)（捕获/比较 1 中断标志）、UIF[0] (RW)（更新中断标志） | — |
| `TIM14_EGR` | TIM14 事件生成寄存器 | `0x014` | `0x40002014` | 16 | — | 0x00000000 / 0x0000FFFF | CC1G[1] (WO)（捕获/比较 1 生成）、UG[0] (WO)（更新生成） | — |
| `TIM14_CCMR1_INPUT` | TIM14 捕获/比较模式寄存器 1 | `0x018` | `0x40002018` | 32 | — | 0x00000000 / 0xFFFFFFFF | IC1F[7:4] (RW)（输入捕获 1 滤波）、IC1PSC[3:2] (RW)（输入捕获 1 预分频器）、CC1S[1:0] (RW)（捕获/比较 1 选择） | — |
| `TIM14_CCMR1_OUTPUT` | TIM14 捕获/比较模式寄存器 1 | `0x018` | `0x40002018` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC1M_1[16] (RW)（待核）、OC1M[6:4] (RW)（待核）、OC1PE[3] (RW)（输出比较 1 预装载使能）、OC1FE[2] (RW)（输出比较 1 快速使能）、CC1S[1:0] (RW)（捕获/比较 1 选择） | 别名 TIM14_CCMR1_INPUT |
| `TIM14_CCER` | TIM14 捕获/比较使能寄存器 | `0x020` | `0x40002020` | 16 | — | 0x00000000 / 0x0000FFFF | CC1NP[3] (RW)（待核）、CC1P[1] (RW)（捕获/比较 1 输出极性）、CC1E[0] (RW)（捕获/比较 1 输出使能） | — |
| `TIM14_CNT` | TIM14 计数器 | `0x024` | `0x40002024` | 32 | — | 0x00000000 / 0xFFFFFFFF | UIFCPY[31] (RW)（待核）、CNT[15:0] (RW)（计数器值） | — |
| `TIM14_PSC` | TIM14 预分频器 | `0x028` | `0x40002028` | 16 | — | 0x00000000 / 0x0000FFFF | PSC[15:0] (RW)（预分频器值） | — |
| `TIM14_ARR` | TIM14 自动重装寄存器 | `0x02C` | `0x4000202C` | 32 | — | 0x0000FFFF / 0xFFFFFFFF | ARR[19:0] (RW)（自动重装值） | — |
| `TIM14_CCR1` | TIM14 捕获/比较寄存器 1 | `0x034` | `0x40002034` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR1[19:0] (RW)（捕获/比较 1 值） | — |
| `TIM14_TISEL` | TIM14 定时器输入选择寄存器 | `0x05C` | `0x4000205C` | 16 | — | 0x00000000 / 0x0000FFFF | TI1SEL[3:0] (RW)（待核） | — |

## TIM15

**模块用途**　通用定时器，按实例提供计数、输入捕获、输出比较、PWM 或触发功能。以本实例表中的通道为准。

基地址 `0x42004000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `TIM15_CR1` | TIM15 控制寄存器 1 | `0x000` | `0x42004000` | 16 | — | 0x00000000 / 0x0000FFFF | DITHEN[12] (RW)（待核）、UIFREMAP[11] (RW)（待核）、CKD[9:8] (RW)（时钟分频）、ARPE[7] (RW)（自动重装预装载使能）、OPM[3] (RW)（待核）、URS[2] (RW)（更新请求源）、UDIS[1] (RW)（更新禁用）、CEN[0] (RW)（计数器使能） | — |
| `TIM15_CR2` | TIM15 控制寄存器 2 | `0x004` | `0x42004004` | 16 | — | 0x00000000 / 0x0000FFFF | OIS2[10] (RW)（输出空闲状态 2 (tim_oc2 输出)）、OIS1N[9] (RW)（输出空闲状态 1 (tim_oc1n 输出)）、OIS1[8] (RW)（输出空闲状态 1 (tim_oc1 输出)）、TI1S[7] (RW)（tim_ti1 选择）、MMS[6:4] (RW)（主设备模式选择）、CCDS[3] (RW)（捕获/比较 DMA 选择）、CCUS[2] (RW)（捕获/比较控制更新选择）、CCPC[0] (RW)（待核） | — |
| `TIM15_SMCR` | TIM15 从设备模式控制寄存器 | `0x008` | `0x42004008` | 32 | — | 0x00000000 / 0xFFFFFFFF | TS_1[21:20] (RW)（待核）、SMS_1[16] (RW)（待核）、MSM[7] (RW)（主设备/从设备模式）、TS[6:4] (RW)（TS[0]: 触发选择）、SMS[2:0] (RW)（SMS[0]: 从设备模式选择） | — |
| `TIM15_DIER` | TIM15 DMA/中断使能寄存器 | `0x00C` | `0x4200400C` | 16 | — | 0x00000000 / 0x0000FFFF | TDE[14] (RW)（触发 DMA 请求使能）、COMDE[13] (RW)（COM DMA 请求使能）、CC2DE[10] (RW)（捕获/比较 2 DMA 请求使能）、CC1DE[9] (RW)（捕获/比较 1 DMA 请求使能）、UDE[8] (RW)（更新 DMA 请求使能）、BIE[7] (RW)（刹车中断使能）、TIE[6] (RW)（触发中断使能）、COMIE[5] (RW)（COM 中断使能）、CC2IE[2] (RW)（捕获/比较 2 中断使能）、CC1IE[1] (RW)（捕获/比较 1 中断使能）、UIE[0] (RW)（更新中断使能） | — |
| `TIM15_SR` | TIM15 状态寄存器 | `0x010` | `0x42004010` | 16 | — | 0x00000000 / 0x0000FFFF | CC2OF[10] (RW)（待核）、CC1OF[9] (RW)（待核）、BIF[7] (RW)（刹车中断标志）、TIF[6] (RW)（触发中断标志）、COMIF[5] (RW)（COM 中断标志）、CC2IF[2] (RW)（捕获/比较 2 中断标志）、CC1IF[1] (RW)（捕获/比较 1 中断标志）、UIF[0] (RW)（更新中断标志） | — |
| `TIM15_EGR` | TIM15 事件生成寄存器 | `0x014` | `0x42004014` | 16 | — | 0x00000000 / 0x0000FFFF | BG[7] (WO)（刹车生成）、TG[6] (WO)（触发生成）、COMG[5] (RW)（捕获/比较控制更新生成）、CC2G[2] (WO)（捕获/比较 2 生成）、CC1G[1] (WO)（捕获/比较 1 生成）、UG[0] (WO)（更新生成） | — |
| `TIM15_CCMR1_INPUT` | TIM15 捕获/比较模式寄存器 1 [备选] | `0x018` | `0x42004018` | 32 | — | 0x00000000 / 0xFFFFFFFF | IC2F[15:12] (RW)（输入捕获 2 滤波）、IC2PSC[11:10] (RW)（输入捕获 2 预分频器）、CC2S[9:8] (RW)（捕获/比较 2 选择）、IC1F[7:4] (RW)（输入捕获 1 滤波）、IC1PSC[3:2] (RW)（输入捕获 1 预分频器）、CC1S[1:0] (RW)（捕获/比较 1 选择） | — |
| `TIM15_CCMR1_OUTPUT` | TIM15 捕获/比较模式寄存器 1 [备选] | `0x018` | `0x42004018` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC2M_1[24] (RW)（待核）、OC1M_1[16] (RW)（待核）、OC2CE[15] (RW)（输出比较 2 清除使能）、OC2M[14:12] (RW)（OC2M[2:0]: 输出比较 2 模式）、OC2PE[11] (RW)（输出比较 2 预装载使能）、OC2FE[10] (RW)（输出比较 2 快速使能）、CC2S[9:8] (RW)（捕获/比较 2 选择）、OC1CE[7] (RW)（输出比较 1 清除使能）、OC1M[6:4] (RW)（OC1M[2:0]: 输出比较 1 模式）、OC1PE[3] (RW)（输出比较 1 预装载使能）、OC1FE[2] (RW)（输出比较 1 快速使能）、CC1S[1:0] (RW)（捕获/比较 1 选择） | 别名 TIM15_CCMR1_INPUT |
| `TIM15_CCER` | TIM15 捕获/比较使能寄存器 | `0x020` | `0x42004020` | 16 | — | 0x00000000 / 0x0000FFFF | CC2NP[7] (RW)（待核）、CC2P[5] (RW)（捕获/比较 2 输出极性）、CC2E[4] (RW)（捕获/比较 2 输出使能）、CC1NP[3] (RW)（待核）、CC1NE[2] (RW)（待核）、CC1P[1] (RW)（捕获/比较 1 输出极性）、CC1E[0] (RW)（捕获/比较 1 输出使能） | — |
| `TIM15_CNT` | TIM15 计数器 | `0x024` | `0x42004024` | 32 | — | 0x00000000 / 0xFFFFFFFF | UIFCPY[31] (RO)（待核）、CNT[15:0] (RW)（计数器值） | — |
| `TIM15_PSC` | TIM15 预分频器 | `0x028` | `0x42004028` | 16 | — | 0x00000000 / 0x0000FFFF | PSC[15:0] (RW)（预分频器值） | — |
| `TIM15_ARR` | TIM15 自动重装寄存器 | `0x02C` | `0x4200402C` | 32 | — | 0x0000FFFF / 0xFFFFFFFF | ARR[19:0] (RW)（自动重装值） | — |
| `TIM15_RCR` | TIM15 重复计数器寄存器 | `0x030` | `0x42004030` | 16 | — | 0x00000000 / 0x0000FFFF | REP[7:0] (RW)（重复计数器重装值） | — |
| `TIM15_CCR1` | TIM15 捕获/比较寄存器 1 | `0x034` | `0x42004034` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR1[19:0] (RW)（捕获/比较 1 值） | — |
| `TIM15_CCR2` | TIM15 捕获/比较寄存器 2 | `0x038` | `0x42004038` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR2[19:0] (RW)（捕获/比较 2 值） | — |
| `TIM15_BDTR` | TIM15 刹车与死区时间寄存器 | `0x044` | `0x42004044` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKBID[28] (RW)（待核）、BKDSRM[26] (RW)（待核）、BKF[19:16] (RW)（刹车滤波）、MOE[15] (RW)（待核）、AOE[14] (RW)（待核）、BKP[13] (RW)（刹车极性）、BKE[12] (RW)（刹车使能）、OSSR[11] (RW)（待核）、OSSI[10] (RW)（待核）、LOCK[9:8] (RW)（锁定配置）、DTG[7:0] (RW)（待核） | — |
| `TIM15_DTR2` | TIM15 定时器死区时间寄存器 2 | `0x054` | `0x42004054` | 32 | — | 0x00000000 / 0xFFFFFFFF | DTPE[17] (RW)（死区时间预装载使能）、DTAE[16] (RW)（死区时间非对称使能）、DTGF[7:0] (RW)（待核） | — |
| `TIM15_TISEL` | TIM15 输入选择寄存器 | `0x05C` | `0x4200405C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TI2SEL[11:8] (RW)（待核）、TI1SEL[3:0] (RW)（待核） | — |
| `TIM15_AF1` | TIM15 复用功能寄存器 1 | `0x060` | `0x42004060` | 32 | — | 0x00000001 / 0xFFFFFFFF | BKCMP4P[13] (RW)（tim_brk_cmp4 输入极性）、BKCMP3P[12] (RW)（tim_brk_cmp3 输入极性）、BKCMP2P[11] (RW)（tim_brk_cmp2 输入极性）、BKCMP1P[10] (RW)（tim_brk_cmp1 输入极性）、BKINP[9] (RW)（TIMx_BKIN 输入极性）、BKCMP8E[8] (RW)（tim_brk_cmp8 使能）、BKCMP7E[7] (RW)（tim_brk_cmp7 使能）、BKCMP6E[6] (RW)（tim_brk_cmp6 使能）、BKCMP5E[5] (RW)（tim_brk_cmp5 使能）、BKCMP4E[4] (RW)（tim_brk_cmp4 使能）、BKCMP3E[3] (RW)（tim_brk_cmp3 使能）、BKCMP2E[2] (RW)（tim_brk_cmp2 使能）、BKCMP1E[1] (RW)（tim_brk_cmp1 使能）、BKINE[0] (RW)（TIMx_BKIN 输入使能） | — |
| `TIM15_AF2` | TIM15 复用功能寄存器 2 | `0x064` | `0x42004064` | 32 | — | 0x00000000 / 0xFFFFFFFF | OCRSEL[18:16] (RW)（ocref_clr 源选择） | — |
| `TIM15_DCR` | TIM15 DMA 控制寄存器 | `0x3DC` | `0x420043DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | DBSS[19:16] (RW)（DMA 突发源选择）、DBL[12:8] (RW)（DMA 突发长度）、DBA[4:0] (RW)（DMA 基址地址） | — |
| `TIM15_DMAR` | TIM15 DMA 地址的满传输 | `0x3E0` | `0x420043E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DMAB[31:0] (RW)（待核） | — |

## TIM16

**模块用途**　通用定时器，按实例提供计数、输入捕获、输出比较、PWM 或触发功能。以本实例表中的通道为准。

基地址 `0x42004400` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `TIM16_CR1` | TIM16 控制寄存器 1 | `0x000` | `0x42004400` | 16 | — | 0x00000000 / 0x0000FFFF | DITHEN[12] (RW)（待核）、UIFREMAP[11] (RW)（待核）、CKD[9:8] (RW)（时钟分频）、ARPE[7] (RW)（自动重装预装载使能）、OPM[3] (RW)（待核）、URS[2] (RW)（更新请求源）、UDIS[1] (RW)（更新禁用）、CEN[0] (RW)（计数器使能） | — |
| `TIM16_CR2` | TIM16 控制寄存器 2 | `0x004` | `0x42004404` | 16 | — | 0x00000000 / 0x0000FFFF | OIS1N[9] (RW)（输出空闲状态 1 (tim_oc1n 输出)）、OIS1[8] (RW)（输出空闲状态 1 (tim_oc1 输出)）、CCDS[3] (RW)（捕获/比较 DMA 选择）、CCUS[2] (RW)（捕获/比较控制更新选择）、CCPC[0] (RW)（待核） | — |
| `TIM16_DIER` | TIM16 DMA/中断使能寄存器 | `0x00C` | `0x4200440C` | 16 | — | 0x00000000 / 0x0000FFFF | CC1DE[9] (RW)（捕获/比较 1 DMA 请求使能）、UDE[8] (RW)（更新 DMA 请求使能）、BIE[7] (RW)（刹车中断使能）、COMIE[5] (RW)（COM 中断使能）、CC1IE[1] (RW)（捕获/比较 1 中断使能）、UIE[0] (RW)（更新中断使能） | — |
| `TIM16_SR` | TIM16 状态寄存器 | `0x010` | `0x42004410` | 16 | — | 0x00000000 / 0x0000FFFF | CC1OF[9] (RW)（待核）、BIF[7] (RW)（刹车中断标志）、COMIF[5] (RW)（COM 中断标志）、CC1IF[1] (RW)（捕获/比较 1 中断标志）、UIF[0] (RW)（更新中断标志） | — |
| `TIM16_EGR` | TIM16 事件生成寄存器 | `0x014` | `0x42004414` | 16 | — | 0x00000000 / 0x0000FFFF | BG[7] (WO)（刹车生成）、COMG[5] (WO)（捕获/比较控制更新生成）、CC1G[1] (WO)（捕获/比较 1 生成）、UG[0] (WO)（更新生成） | — |
| `TIM16_CCMR1_INPUT` | TIM16 捕获/比较模式寄存器 1 | `0x018` | `0x42004418` | 32 | — | 0x00000000 / 0xFFFFFFFF | IC1F[7:4] (RW)（输入捕获 1 滤波）、IC1PSC[3:2] (RW)（输入捕获 1 预分频器）、CC1S[1:0] (RW)（捕获/比较 1 选择） | — |
| `TIM16_CCMR1_OUTPUT` | TIM16 捕获/比较模式寄存器 1 [备选] | `0x018` | `0x42004418` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC2M_1[24] (RW)（待核）、OC1M_1[16] (RW)（待核）、OC2CE[15] (RW)（输出比较 2 清除使能）、OC2M[14:12] (RW)（OC2M[2:0]: 输出比较 2 模式）、OC2PE[11] (RW)（输出比较 2 预装载使能）、OC2FE[10] (RW)（输出比较 2 快速使能）、CC2S[9:8] (RW)（捕获/比较 2 选择）、OC1CE[7] (RW)（输出比较 1 清除使能）、OC1M[6:4] (RW)（OC1M[2:0]: 输出比较 1 模式）、OC1PE[3] (RW)（输出比较 1 预装载使能）、OC1FE[2] (RW)（输出比较 1 快速使能）、CC1S[1:0] (RW)（捕获/比较 1 选择） | 别名 TIM16_CCMR1_INPUT |
| `TIM16_CCER` | TIM16 捕获/比较使能寄存器 | `0x020` | `0x42004420` | 16 | — | 0x00000000 / 0x0000FFFF | CC1NP[3] (RW)（待核）、CC1NE[2] (RW)（待核）、CC1P[1] (RW)（捕获/比较 1 输出极性）、CC1E[0] (RW)（捕获/比较 1 输出使能） | — |
| `TIM16_CNT` | TIM16 计数器 | `0x024` | `0x42004424` | 32 | — | 0x00000000 / 0xFFFFFFFF | UIFCPY[31] (RO)（待核）、CNT[15:0] (RW)（计数器值） | — |
| `TIM16_PSC` | TIM16 预分频器 | `0x028` | `0x42004428` | 16 | — | 0x00000000 / 0x0000FFFF | PSC[15:0] (RW)（预分频器值） | — |
| `TIM16_ARR` | TIM16 自动重装寄存器 | `0x02C` | `0x4200442C` | 32 | — | 0x0000FFFF / 0xFFFFFFFF | ARR[19:0] (RW)（自动重装值） | — |
| `TIM16_RCR` | TIM16 重复计数器寄存器 | `0x030` | `0x42004430` | 16 | — | 0x00000000 / 0x0000FFFF | REP[7:0] (RW)（重复计数器重装值） | — |
| `TIM16_CCR1` | TIM16 捕获/比较寄存器 1 | `0x034` | `0x42004434` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR1[19:0] (RW)（捕获/比较 1 值） | — |
| `TIM16_BDTR` | TIM16 刹车与死区时间寄存器 | `0x044` | `0x42004444` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKBID[28] (RW)（待核）、BKDSRM[26] (RW)（待核）、BKF[19:16] (RW)（刹车滤波）、MOE[15] (RW)（待核）、AOE[14] (RW)（待核）、BKP[13] (RW)（刹车极性）、BKE[12] (RW)（刹车使能）、OSSR[11] (RW)（待核）、OSSI[10] (RW)（待核）、LOCK[9:8] (RW)（锁定配置）、DTG[7:0] (RW)（待核） | — |
| `TIM16_DTR2` | TIM16 定时器死区时间寄存器 2 | `0x054` | `0x42004454` | 32 | — | 0x00000000 / 0xFFFFFFFF | DTPE[17] (RW)（死区时间预装载使能）、DTAE[16] (RW)（死区时间非对称使能）、DTGF[7:0] (RW)（待核） | — |
| `TIM16_TISEL` | TIM16 输入选择寄存器 | `0x05C` | `0x4200445C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TI1SEL[3:0] (RW)（待核） | — |
| `TIM16_AF1` | TIM16 复用功能寄存器 1 | `0x060` | `0x42004460` | 32 | — | 0x00000001 / 0xFFFFFFFF | BKCMP4P[13] (RW)（tim_brk_cmp4 输入极性）、BKCMP3P[12] (RW)（tim_brk_cmp3 输入极性）、BKCMP2P[11] (RW)（tim_brk_cmp2 输入极性）、BKCMP1P[10] (RW)（tim_brk_cmp1 输入极性）、BKINP[9] (RW)（TIMx_BKIN 输入极性）、BKCMP8E[8] (RW)（tim_brk_cmp8 使能）、BKCMP7E[7] (RW)（tim_brk_cmp7 使能）、BKCMP6E[6] (RW)（tim_brk_cmp6 使能）、BKCMP5E[5] (RW)（tim_brk_cmp5 使能）、BKCMP4E[4] (RW)（tim_brk_cmp4 使能）、BKCMP3E[3] (RW)（tim_brk_cmp3 使能）、BKCMP2E[2] (RW)（tim_brk_cmp2 使能）、BKCMP1E[1] (RW)（tim_brk_cmp1 使能）、BKINE[0] (RW)（TIMx_BKIN 输入使能） | — |
| `TIM16_AF2` | TIM16 复用功能寄存器 2 | `0x064` | `0x42004464` | 32 | — | 0x00000000 / 0xFFFFFFFF | OCRSEL[18:16] (RW)（tim_ocref_clr 源选择） | — |
| `TIM16_DCR` | TIM16 DMA 控制寄存器 | `0x3DC` | `0x420047DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | DBSS[19:16] (RW)（DMA 突发源选择）、DBL[12:8] (RW)（DMA 突发长度）、DBA[4:0] (RW)（DMA 基址地址） | — |
| `TIM16_DMAR` | TIM16/TIM17 DMA 地址的满传输 | `0x3E0` | `0x420047E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DMAB[31:0] (RW)（待核） | — |

## TIM17

**模块用途**　通用定时器，按实例提供计数、输入捕获、输出比较、PWM 或触发功能。以本实例表中的通道为准。

基地址 `0x42004800` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `TIM17_CR1` | TIM17 控制寄存器 1 | `0x000` | `0x42004800` | 16 | — | 0x00000000 / 0x0000FFFF | DITHEN[12] (RW)（待核）、UIFREMAP[11] (RW)（待核）、CKD[9:8] (RW)（时钟分频）、ARPE[7] (RW)（自动重装预装载使能）、OPM[3] (RW)（待核）、URS[2] (RW)（更新请求源）、UDIS[1] (RW)（更新禁用）、CEN[0] (RW)（计数器使能） | — |
| `TIM17_CR2` | TIM17 控制寄存器 2 | `0x004` | `0x42004804` | 16 | — | 0x00000000 / 0x0000FFFF | OIS1N[9] (RW)（输出空闲状态 1 (tim_oc1n 输出)）、OIS1[8] (RW)（输出空闲状态 1 (tim_oc1 输出)）、CCDS[3] (RW)（捕获/比较 DMA 选择）、CCUS[2] (RW)（捕获/比较控制更新选择）、CCPC[0] (RW)（待核） | — |
| `TIM17_DIER` | TIM17 DMA/中断使能寄存器 | `0x00C` | `0x4200480C` | 16 | — | 0x00000000 / 0x0000FFFF | CC1DE[9] (RW)（捕获/比较 1 DMA 请求使能）、UDE[8] (RW)（更新 DMA 请求使能）、BIE[7] (RW)（刹车中断使能）、COMIE[5] (RW)（COM 中断使能）、CC1IE[1] (RW)（捕获/比较 1 中断使能）、UIE[0] (RW)（更新中断使能） | — |
| `TIM17_SR` | TIM17 状态寄存器 | `0x010` | `0x42004810` | 16 | — | 0x00000000 / 0x0000FFFF | CC1OF[9] (RW)（待核）、BIF[7] (RW)（刹车中断标志）、COMIF[5] (RW)（COM 中断标志）、CC1IF[1] (RW)（捕获/比较 1 中断标志）、UIF[0] (RW)（更新中断标志） | — |
| `TIM17_EGR` | TIM17 事件生成寄存器 | `0x014` | `0x42004814` | 16 | — | 0x00000000 / 0x0000FFFF | BG[7] (WO)（刹车生成）、COMG[5] (WO)（捕获/比较控制更新生成）、CC1G[1] (WO)（捕获/比较 1 生成）、UG[0] (WO)（更新生成） | — |
| `TIM17_CCMR1_INPUT` | TIM17 捕获/比较模式寄存器 1 | `0x018` | `0x42004818` | 32 | — | 0x00000000 / 0xFFFFFFFF | IC1F[7:4] (RW)（输入捕获 1 滤波）、IC1PSC[3:2] (RW)（输入捕获 1 预分频器）、CC1S[1:0] (RW)（捕获/比较 1 选择） | — |
| `TIM17_CCMR1_OUTPUT` | TIM17 捕获/比较模式寄存器 1 [备选] | `0x018` | `0x42004818` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC2M_1[24] (RW)（待核）、OC1M_1[16] (RW)（待核）、OC2CE[15] (RW)（输出比较 2 清除使能）、OC2M[14:12] (RW)（OC2M[2:0]: 输出比较 2 模式）、OC2PE[11] (RW)（输出比较 2 预装载使能）、OC2FE[10] (RW)（输出比较 2 快速使能）、CC2S[9:8] (RW)（捕获/比较 2 选择）、OC1CE[7] (RW)（输出比较 1 清除使能）、OC1M[6:4] (RW)（OC1M[2:0]: 输出比较 1 模式）、OC1PE[3] (RW)（输出比较 1 预装载使能）、OC1FE[2] (RW)（输出比较 1 快速使能）、CC1S[1:0] (RW)（捕获/比较 1 选择） | 别名 TIM17_CCMR1_INPUT |
| `TIM17_CCER` | TIM17 捕获/比较使能寄存器 | `0x020` | `0x42004820` | 16 | — | 0x00000000 / 0x0000FFFF | CC1NP[3] (RW)（待核）、CC1NE[2] (RW)（待核）、CC1P[1] (RW)（捕获/比较 1 输出极性）、CC1E[0] (RW)（捕获/比较 1 输出使能） | — |
| `TIM17_CNT` | TIM17 计数器 | `0x024` | `0x42004824` | 32 | — | 0x00000000 / 0xFFFFFFFF | UIFCPY[31] (RO)（待核）、CNT[15:0] (RW)（计数器值） | — |
| `TIM17_PSC` | TIM17 预分频器 | `0x028` | `0x42004828` | 16 | — | 0x00000000 / 0x0000FFFF | PSC[15:0] (RW)（预分频器值） | — |
| `TIM17_ARR` | TIM17 自动重装寄存器 | `0x02C` | `0x4200482C` | 32 | — | 0x0000FFFF / 0xFFFFFFFF | ARR[19:0] (RW)（自动重装值） | — |
| `TIM17_RCR` | TIM17 重复计数器寄存器 | `0x030` | `0x42004830` | 16 | — | 0x00000000 / 0x0000FFFF | REP[7:0] (RW)（重复计数器重装值） | — |
| `TIM17_CCR1` | TIM17 捕获/比较寄存器 1 | `0x034` | `0x42004834` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR1[19:0] (RW)（捕获/比较 1 值） | — |
| `TIM17_BDTR` | TIM17 刹车与死区时间寄存器 | `0x044` | `0x42004844` | 32 | — | 0x00000000 / 0xFFFFFFFF | BKBID[28] (RW)（待核）、BKDSRM[26] (RW)（待核）、BKF[19:16] (RW)（刹车滤波）、MOE[15] (RW)（待核）、AOE[14] (RW)（待核）、BKP[13] (RW)（刹车极性）、BKE[12] (RW)（刹车使能）、OSSR[11] (RW)（待核）、OSSI[10] (RW)（待核）、LOCK[9:8] (RW)（锁定配置）、DTG[7:0] (RW)（待核） | — |
| `TIM17_DTR2` | TIM17 定时器死区时间寄存器 2 | `0x054` | `0x42004854` | 32 | — | 0x00000000 / 0xFFFFFFFF | DTPE[17] (RW)（死区时间预装载使能）、DTAE[16] (RW)（死区时间非对称使能）、DTGF[7:0] (RW)（待核） | — |
| `TIM17_TISEL` | TIM17 输入选择寄存器 | `0x05C` | `0x4200485C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TI1SEL[3:0] (RW)（待核） | — |
| `TIM17_AF1` | TIM17 复用功能寄存器 1 | `0x060` | `0x42004860` | 32 | — | 0x00000001 / 0xFFFFFFFF | BKCMP4P[13] (RW)（tim_brk_cmp4 输入极性）、BKCMP3P[12] (RW)（tim_brk_cmp3 输入极性）、BKCMP2P[11] (RW)（tim_brk_cmp2 输入极性）、BKCMP1P[10] (RW)（tim_brk_cmp1 输入极性）、BKINP[9] (RW)（TIMx_BKIN 输入极性）、BKCMP8E[8] (RW)（tim_brk_cmp8 使能）、BKCMP7E[7] (RW)（tim_brk_cmp7 使能）、BKCMP6E[6] (RW)（tim_brk_cmp6 使能）、BKCMP5E[5] (RW)（tim_brk_cmp5 使能）、BKCMP4E[4] (RW)（tim_brk_cmp4 使能）、BKCMP3E[3] (RW)（tim_brk_cmp3 使能）、BKCMP2E[2] (RW)（tim_brk_cmp2 使能）、BKCMP1E[1] (RW)（tim_brk_cmp1 使能）、BKINE[0] (RW)（TIMx_BKIN 输入使能） | — |
| `TIM17_AF2` | TIM17 复用功能寄存器 2 | `0x064` | `0x42004864` | 32 | — | 0x00000000 / 0xFFFFFFFF | OCRSEL[18:16] (RW)（tim_ocref_clr 源选择） | — |
| `TIM17_DCR` | TIM17 DMA 控制寄存器 | `0x3DC` | `0x42004BDC` | 32 | — | 0x00000000 / 0xFFFFFFFF | DBSS[19:16] (RW)（DMA 突发源选择）、DBL[12:8] (RW)（DMA 突发长度）、DBA[4:0] (RW)（DMA 基址地址） | — |
| `TIM17_DMAR` | TIM16/TIM17 DMA 地址的满传输 | `0x3E0` | `0x42004BE0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DMAB[31:0] (RW)（待核） | — |

## TIM2

**模块用途**　通用定时器，按实例提供计数、输入捕获、输出比较、PWM 或触发功能。以本实例表中的通道为准。

基地址 `0x40000000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `TIM2_CR1` | TIM2 控制寄存器 1 | `0x000` | `0x40000000` | 16 | — | 0x00000000 / 0x0000FFFF | DITHEN[12] (RW)（待核）、UIFREMAP[11] (RW)（待核）、CKD[9:8] (RW)（时钟分频）、ARPE[7] (RW)（自动重装预装载使能）、CMS[6:5] (RW)（待核）、DIR[4] (RW)（方向）、OPM[3] (RW)（待核）、URS[2] (RW)（更新请求源）、UDIS[1] (RW)（更新禁用）、CEN[0] (RW)（计数器使能） | — |
| `TIM2_CR2` | TIM2 控制寄存器 2 | `0x004` | `0x40000004` | 32 | — | 0x00000000 / 0xFFFFFFFF | MMS_1[25] (RW)（待核）、TI1S[7] (RW)（tim_ti1 选择）、MMS[6:4] (RW)（MMS[0]: 主设备模式选择）、CCDS[3] (RW)（捕获/比较 DMA 选择） | — |
| `TIM2_SMCR` | TIM2 从设备模式控制寄存器 | `0x008` | `0x40000008` | 32 | — | 0x00000000 / 0xFFFFFFFF | SMSPS[25] (RW)（SMS 预装载源）、SMSPE[24] (RW)（SMS 预装载使能）、TS_1[21:20] (RW)（待核）、SMS_1[16] (RW)（待核）、ETP[15] (RW)（外部触发极性）、ECE[14] (RW)（外部时钟使能）、ETPS[13:12] (RW)（外部触发预分频器）、ETF[11:8] (RW)（外部触发滤波）、MSM[7] (RW)（主设备/从设备模式）、TS[6:4] (RW)（TS[0]: 触发选择）、OCCS[3] (RW)（OCREF 清除选择）、SMS[2:0] (RW)（SMS[0]: 从设备模式选择） | — |
| `TIM2_DIER` | TIM2 DMA/中断使能寄存器 | `0x00C` | `0x4000000C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TERRIE[23] (RW)（转换错误中断使能）、IERRIE[22] (RW)（索引错误中断使能）、DIRIE[21] (RW)（待核）、IDXIE[20] (RW)（索引中断使能）、TDE[14] (RW)（触发 DMA 请求使能）、CC4DE[12] (RW)（捕获/比较 4 DMA 请求使能）、CC3DE[11] (RW)（捕获/比较 3 DMA 请求使能）、CC2DE[10] (RW)（捕获/比较 2 DMA 请求使能）、CC1DE[9] (RW)（捕获/比较 1 DMA 请求使能）、UDE[8] (RW)（更新 DMA 请求使能）、TIE[6] (RW)（触发中断使能）、CC4IE[4] (RW)（捕获/比较 4 中断使能）、CC3IE[3] (RW)（捕获/比较 3 中断使能）、CC2IE[2] (RW)（捕获/比较 2 中断使能）、CC1IE[1] (RW)（捕获/比较 1 中断使能）、UIE[0] (RW)（更新中断使能） | — |
| `TIM2_SR` | TIM2 状态寄存器 | `0x010` | `0x40000010` | 32 | — | 0x00000000 / 0xFFFFFFFF | TERRF[23] (RW)（转换错误中断标志）、IERRF[22] (RW)（索引错误中断标志）、DIRF[21] (RW)（待核）、IDXF[20] (RW)（索引中断标志）、CC4OF[12] (RW)（待核）、CC3OF[11] (RW)（待核）、CC2OF[10] (RW)（待核）、CC1OF[9] (RW)（待核）、TIF[6] (RW)（触发中断标志）、CC4IF[4] (RW)（捕获/比较 4 中断标志）、CC3IF[3] (RW)（捕获/比较 3 中断标志）、CC2IF[2] (RW)（捕获/比较 2 中断标志）、CC1IF[1] (RW)（捕获/比较 1 中断标志）、UIF[0] (RW)（更新中断标志） | — |
| `TIM2_EGR` | TIM2 事件生成寄存器 | `0x014` | `0x40000014` | 16 | — | 0x00000000 / 0x0000FFFF | TG[6] (WO)（触发生成）、CC4G[4] (WO)（捕获/比较 4 生成）、CC3G[3] (WO)（捕获/比较 3 生成）、CC2G[2] (WO)（捕获/比较 2 生成）、CC1G[1] (WO)（捕获/比较 1 生成）、UG[0] (WO)（更新生成） | — |
| `TIM2_CCMR1_INPUT` | TIM2 捕获/比较模式寄存器 1 | `0x018` | `0x40000018` | 32 | — | 0x00000000 / 0xFFFFFFFF | IC2F[15:12] (RW)（输入捕获 2 滤波）、IC2PSC[11:10] (RW)（输入捕获 2 预分频器）、CC2S[9:8] (RW)（捕获/比较 2 选择）、IC1F[7:4] (RW)（输入捕获 1 滤波）、IC1PSC[3:2] (RW)（输入捕获 1 预分频器）、CC1S[1:0] (RW)（捕获/比较 1 选择） | — |
| `TIM2_CCMR1_OUTPUT` | TIM2 捕获/比较模式寄存器 1 | `0x018` | `0x40000018` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC2M_1[24] (RW)（待核）、OC1M_1[16] (RW)（待核）、OC2CE[15] (RW)（输出比较 2 清除使能）、OC2M[14:12] (RW)（OC2M[2:0]: 输出比较 2 模式）、OC2PE[11] (RW)（输出比较 2 预装载使能）、OC2FE[10] (RW)（输出比较 2 快速使能）、CC2S[9:8] (RW)（捕获/比较 2 选择）、OC1CE[7] (RW)（输出比较 1 清除使能）、OC1M[6:4] (RW)（OC1M[2:0]: 输出比较 1 模式）、OC1PE[3] (RW)（输出比较 1 预装载使能）、OC1FE[2] (RW)（输出比较 1 快速使能）、CC1S[1:0] (RW)（捕获/比较 1 选择） | 别名 TIM2_CCMR1_INPUT |
| `TIM2_CCMR2_INPUT` | TIM2 捕获/比较模式寄存器 2 | `0x01C` | `0x4000001C` | 32 | — | 0x00000000 / 0xFFFFFFFF | IC4F[15:12] (RW)（输入捕获 4 滤波）、IC4PSC[11:10] (RW)（输入捕获 4 预分频器）、CC4S[9:8] (RW)（捕获/比较 4 选择）、IC3F[7:4] (RW)（输入捕获 3 滤波）、IC3PSC[3:2] (RW)（输入捕获 3 预分频器）、CC3S[1:0] (RW)（捕获/比较 3 选择） | — |
| `TIM2_CCMR2_OUTPUT` | TIM2 捕获/比较模式寄存器 2 | `0x01C` | `0x4000001C` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC4M_1[24] (RW)（待核）、OC3M_1[16] (RW)（待核）、OC4CE[15] (RW)（输出比较 4 清除使能）、OC4M[14:12] (RW)（OC4M[2:0]: 输出比较 4 模式）、OC4PE[11] (RW)（输出比较 4 预装载使能）、OC4FE[10] (RW)（输出比较 4 快速使能）、CC4S[9:8] (RW)（捕获/比较 4 选择）、OC3CE[7] (RW)（输出比较 3 清除使能）、OC3M[6:4] (RW)（OC3M[2:0]: 输出比较 3 模式）、OC3PE[3] (RW)（输出比较 3 预装载使能）、OC3FE[2] (RW)（输出比较 3 快速使能）、CC3S[1:0] (RW)（捕获/比较 3 选择） | 别名 TIM2_CCMR2_INPUT |
| `TIM2_CCER` | TIM2 捕获/比较使能寄存器 | `0x020` | `0x40000020` | 16 | — | 0x00000000 / 0x0000FFFF | CC4NP[15] (RW)（捕获/比较 4 输出极性）、CC4P[13] (RW)（捕获/比较 4 输出极性）、CC4E[12] (RW)（捕获/比较 4 输出使能）、CC3NP[11] (RW)（捕获/比较 3 输出极性）、CC3P[9] (RW)（捕获/比较 3 输出极性）、CC3E[8] (RW)（捕获/比较 3 输出使能）、CC2NP[7] (RW)（捕获/比较 2 输出极性）、CC2P[5] (RW)（捕获/比较 2 输出极性）、CC2E[4] (RW)（捕获/比较 2 输出使能）、CC1NP[3] (RW)（捕获/比较 1 输出极性）、CC1P[1] (RW)（捕获/比较 1 输出极性）、CC1E[0] (RW)（捕获/比较 1 输出使能） | — |
| `TIM2_CNT` | TIM2 计数器 | `0x024` | `0x40000024` | 32 | — | 0x00000000 / 0xFFFFFFFF | UIFCPY_CNT[31] (RW)（待核）、CNT[30:0] (RW)（待核） | — |
| `TIM2_PSC` | TIM2 预分频器 | `0x028` | `0x40000028` | 16 | — | 0x00000000 / 0x0000FFFF | PSC[15:0] (RW)（预分频器值） | — |
| `TIM2_ARR` | TIM2 自动重装寄存器 | `0x02C` | `0x4000002C` | 32 | — | 0xFFFFFFFF / 0xFFFFFFFF | ARR[31:0] (RW)（自动重装值） | — |
| `TIM2_CCR1` | TIM2 捕获/比较寄存器 1 | `0x034` | `0x40000034` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR1[31:0] (RW)（捕获/比较 1 值） | — |
| `TIM2_CCR2` | TIM2 捕获/比较寄存器 2 | `0x038` | `0x40000038` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR2[31:0] (RW)（捕获/比较 2 值） | — |
| `TIM2_CCR3` | TIM2 捕获/比较寄存器 3 | `0x03C` | `0x4000003C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR3[31:0] (RW)（捕获/比较 3 值） | — |
| `TIM2_CCR4` | TIM2 捕获/比较寄存器 4 | `0x040` | `0x40000040` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR4[31:0] (RW)（捕获/比较 4 值） | — |
| `TIM2_ECR` | TIM2 定时器编码器控制寄存器 | `0x058` | `0x40000058` | 32 | — | 0x00000000 / 0xFFFFFFFF | PWPRSC[26:24] (RW)（脉冲宽度预分频器）、PW[23:16] (RW)（脉冲宽度）、IPOS[7:6] (RW)（待核）、FIDX[5] (RW)（首个索引）、IBLK[4:3] (RW)（待核）、IDIR[2:1] (RW)（索引方向）、IE[0] (RW)（索引使能） | — |
| `TIM2_TISEL` | TIM2 定时器输入选择寄存器 | `0x05C` | `0x4000005C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TI4SEL[27:24] (RW)（待核）、TI3SEL[19:16] (RW)（待核）、TI2SEL[11:8] (RW)（待核）、TI1SEL[3:0] (RW)（待核） | — |
| `TIM2_AF1` | TIM2 复用功能寄存器 1 | `0x060` | `0x40000060` | 32 | — | 0x00000000 / 0xFFFFFFFF | ETRSEL[17:14] (RW)（etr_in 源选择） | — |
| `TIM2_AF2` | TIM2 复用功能寄存器 2 | `0x064` | `0x40000064` | 32 | — | 0x00000000 / 0xFFFFFFFF | OCRSEL[18:16] (RW)（ocref_clr 源选择） | — |
| `TIM2_DCR` | TIM2 DMA 控制寄存器 | `0x3DC` | `0x400003DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | DBSS[19:16] (RW)（DMA 突发源选择）、DBL[12:8] (RW)（DMA 突发长度）、DBA[4:0] (RW)（DMA 基址地址） | — |
| `TIM2_DMAR` | TIM2 DMA 地址的满传输 | `0x3E0` | `0x400003E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DMAB[31:0] (RW)（待核） | — |

## TIM3

**模块用途**　通用定时器，按实例提供计数、输入捕获、输出比较、PWM 或触发功能。以本实例表中的通道为准。

基地址 `0x40000400` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `TIM3_CR1` | TIM3 控制寄存器 1 | `0x000` | `0x40000400` | 16 | — | 0x00000000 / 0x0000FFFF | DITHEN[12] (RW)（待核）、UIFREMAP[11] (RW)（待核）、CKD[9:8] (RW)（时钟分频）、ARPE[7] (RW)（自动重装预装载使能）、CMS[6:5] (RW)（待核）、DIR[4] (RW)（方向）、OPM[3] (RW)（待核）、URS[2] (RW)（更新请求源）、UDIS[1] (RW)（更新禁用）、CEN[0] (RW)（计数器使能） | — |
| `TIM3_CR2` | TIM3 控制寄存器 2 | `0x004` | `0x40000404` | 32 | — | 0x00000000 / 0xFFFFFFFF | MMS_1[25] (RW)（待核）、TI1S[7] (RW)（tim_ti1 选择）、MMS[6:4] (RW)（MMS[0]: 主设备模式选择）、CCDS[3] (RW)（捕获/比较 DMA 选择） | — |
| `TIM3_SMCR` | TIM3 从设备模式控制寄存器 | `0x008` | `0x40000408` | 32 | — | 0x00000000 / 0xFFFFFFFF | SMSPS[25] (RW)（SMS 预装载源）、SMSPE[24] (RW)（SMS 预装载使能）、TS_1[21:20] (RW)（待核）、SMS_1[16] (RW)（待核）、ETP[15] (RW)（外部触发极性）、ECE[14] (RW)（外部时钟使能）、ETPS[13:12] (RW)（外部触发预分频器）、ETF[11:8] (RW)（外部触发滤波）、MSM[7] (RW)（主设备/从设备模式）、TS[6:4] (RW)（TS[0]: 触发选择）、OCCS[3] (RW)（OCREF 清除选择）、SMS[2:0] (RW)（SMS[0]: 从设备模式选择） | — |
| `TIM3_DIER` | TIM3 DMA/中断使能寄存器 | `0x00C` | `0x4000040C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TERRIE[23] (RW)（转换错误中断使能）、IERRIE[22] (RW)（索引错误中断使能）、DIRIE[21] (RW)（待核）、IDXIE[20] (RW)（索引中断使能）、TDE[14] (RW)（触发 DMA 请求使能）、CC4DE[12] (RW)（捕获/比较 4 DMA 请求使能）、CC3DE[11] (RW)（捕获/比较 3 DMA 请求使能）、CC2DE[10] (RW)（捕获/比较 2 DMA 请求使能）、CC1DE[9] (RW)（捕获/比较 1 DMA 请求使能）、UDE[8] (RW)（更新 DMA 请求使能）、TIE[6] (RW)（触发中断使能）、CC4IE[4] (RW)（捕获/比较 4 中断使能）、CC3IE[3] (RW)（捕获/比较 3 中断使能）、CC2IE[2] (RW)（捕获/比较 2 中断使能）、CC1IE[1] (RW)（捕获/比较 1 中断使能）、UIE[0] (RW)（更新中断使能） | — |
| `TIM3_SR` | TIM3 状态寄存器 | `0x010` | `0x40000410` | 32 | — | 0x00000000 / 0xFFFFFFFF | TERRF[23] (RW)（转换错误中断标志）、IERRF[22] (RW)（索引错误中断标志）、DIRF[21] (RW)（待核）、IDXF[20] (RW)（索引中断标志）、CC4OF[12] (RW)（待核）、CC3OF[11] (RW)（待核）、CC2OF[10] (RW)（待核）、CC1OF[9] (RW)（待核）、TIF[6] (RW)（触发中断标志）、CC4IF[4] (RW)（捕获/比较 4 中断标志）、CC3IF[3] (RW)（捕获/比较 3 中断标志）、CC2IF[2] (RW)（捕获/比较 2 中断标志）、CC1IF[1] (RW)（捕获/比较 1 中断标志）、UIF[0] (RW)（更新中断标志） | — |
| `TIM3_EGR` | TIM3 事件生成寄存器 | `0x014` | `0x40000414` | 16 | — | 0x00000000 / 0x0000FFFF | TG[6] (WO)（触发生成）、CC4G[4] (WO)（捕获/比较 4 生成）、CC3G[3] (WO)（捕获/比较 3 生成）、CC2G[2] (WO)（捕获/比较 2 生成）、CC1G[1] (WO)（捕获/比较 1 生成）、UG[0] (WO)（更新生成） | — |
| `TIM3_CCMR1_INPUT` | TIM3 捕获/比较模式寄存器 1 | `0x018` | `0x40000418` | 32 | — | 0x00000000 / 0xFFFFFFFF | IC2F[15:12] (RW)（输入捕获 2 滤波）、IC2PSC[11:10] (RW)（输入捕获 2 预分频器）、CC2S[9:8] (RW)（捕获/比较 2 选择）、IC1F[7:4] (RW)（输入捕获 1 滤波）、IC1PSC[3:2] (RW)（输入捕获 1 预分频器）、CC1S[1:0] (RW)（捕获/比较 1 选择） | — |
| `TIM3_CCMR1_OUTPUT` | TIM3 捕获/比较模式寄存器 1 | `0x018` | `0x40000418` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC2M_1[24] (RW)（待核）、OC1M_1[16] (RW)（待核）、OC2CE[15] (RW)（输出比较 2 清除使能）、OC2M[14:12] (RW)（OC2M[2:0]: 输出比较 2 模式）、OC2PE[11] (RW)（输出比较 2 预装载使能）、OC2FE[10] (RW)（输出比较 2 快速使能）、CC2S[9:8] (RW)（捕获/比较 2 选择）、OC1CE[7] (RW)（输出比较 1 清除使能）、OC1M[6:4] (RW)（OC1M[2:0]: 输出比较 1 模式）、OC1PE[3] (RW)（输出比较 1 预装载使能）、OC1FE[2] (RW)（输出比较 1 快速使能）、CC1S[1:0] (RW)（捕获/比较 1 选择） | 别名 TIM3_CCMR1_INPUT |
| `TIM3_CCMR2_INPUT` | TIM3 捕获/比较模式寄存器 2 | `0x01C` | `0x4000041C` | 32 | — | 0x00000000 / 0xFFFFFFFF | IC4F[15:12] (RW)（输入捕获 4 滤波）、IC4PSC[11:10] (RW)（输入捕获 4 预分频器）、CC4S[9:8] (RW)（捕获/比较 4 选择）、IC3F[7:4] (RW)（输入捕获 3 滤波）、IC3PSC[3:2] (RW)（输入捕获 3 预分频器）、CC3S[1:0] (RW)（捕获/比较 3 选择） | — |
| `TIM2_CCMR3_OUTPUT` | TIM3 捕获/比较模式寄存器 2 | `0x01C` | `0x4000041C` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC4M_1[24] (RW)（待核）、OC3M_1[16] (RW)（待核）、OC4CE[15] (RW)（输出比较 4 清除使能）、OC4M[14:12] (RW)（OC4M[2:0]: 输出比较 4 模式）、OC4PE[11] (RW)（输出比较 4 预装载使能）、OC4FE[10] (RW)（输出比较 4 快速使能）、CC4S[9:8] (RW)（捕获/比较 4 选择）、OC3CE[7] (RW)（输出比较 3 清除使能）、OC3M[6:4] (RW)（OC3M[2:0]: 输出比较 3 模式）、OC3PE[3] (RW)（输出比较 3 预装载使能）、OC3FE[2] (RW)（输出比较 3 快速使能）、CC3S[1:0] (RW)（捕获/比较 3 选择） | 别名 TIM3_CCMR2_INPUT |
| `TIM3_CCER` | TIM3 捕获/比较使能寄存器 | `0x020` | `0x40000420` | 16 | — | 0x00000000 / 0x0000FFFF | CC4NP[15] (RW)（捕获/比较 4 输出极性）、CC4P[13] (RW)（捕获/比较 4 输出极性）、CC4E[12] (RW)（捕获/比较 4 输出使能）、CC3NP[11] (RW)（捕获/比较 3 输出极性）、CC3P[9] (RW)（捕获/比较 3 输出极性）、CC3E[8] (RW)（捕获/比较 3 输出使能）、CC2NP[7] (RW)（捕获/比较 2 输出极性）、CC2P[5] (RW)（捕获/比较 2 输出极性）、CC2E[4] (RW)（捕获/比较 2 输出使能）、CC1NP[3] (RW)（捕获/比较 1 输出极性）、CC1P[1] (RW)（捕获/比较 1 输出极性）、CC1E[0] (RW)（捕获/比较 1 输出使能） | — |
| `TIM3_CNT` | TIM3 计数器 | `0x024` | `0x40000424` | 32 | — | 0x00000000 / 0xFFFFFFFF | UIFCPY_CNT[31] (RW)（待核）、CNT[30:0] (RW)（待核） | — |
| `TIM3_PSC` | TIM3 预分频器 | `0x028` | `0x40000428` | 16 | — | 0x00000000 / 0x0000FFFF | PSC[15:0] (RW)（预分频器值） | — |
| `TIM3_ARR` | TIM3 自动重装寄存器 | `0x02C` | `0x4000042C` | 32 | — | 0xFFFFFFFF / 0xFFFFFFFF | ARR[31:0] (RW)（自动重装值） | — |
| `TIM3_CCR1` | TIM3 捕获/比较寄存器 1 | `0x034` | `0x40000434` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR1[31:0] (RW)（捕获/比较 1 值） | — |
| `TIM3_CCR2` | TIM3 捕获/比较寄存器 2 | `0x038` | `0x40000438` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR2[31:0] (RW)（捕获/比较 2 值） | — |
| `TIM3_CCR3` | TIM3 捕获/比较寄存器 3 | `0x03C` | `0x4000043C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR3[31:0] (RW)（捕获/比较 3 值） | — |
| `TIM3_CCR4` | TIM3 捕获/比较寄存器 4 | `0x040` | `0x40000440` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR4[31:0] (RW)（捕获/比较 4 值） | — |
| `TIM3_ECR` | TIM3 定时器编码器控制寄存器 | `0x058` | `0x40000458` | 32 | — | 0x00000000 / 0xFFFFFFFF | PWPRSC[26:24] (RW)（脉冲宽度预分频器）、PW[23:16] (RW)（脉冲宽度）、IPOS[7:6] (RW)（待核）、FIDX[5] (RW)（首个索引）、IBLK[4:3] (RW)（待核）、IDIR[2:1] (RW)（索引方向）、IE[0] (RW)（索引使能） | — |
| `TIM3_TISEL` | TIM3 定时器输入选择寄存器 | `0x05C` | `0x4000045C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TI4SEL[27:24] (RW)（待核）、TI3SEL[19:16] (RW)（待核）、TI2SEL[11:8] (RW)（待核）、TI1SEL[3:0] (RW)（待核） | — |
| `TIM3_AF1` | TIM3 复用功能寄存器 1 | `0x060` | `0x40000460` | 32 | — | 0x00000000 / 0xFFFFFFFF | ETRSEL[17:14] (RW)（etr_in 源选择） | — |
| `TIM3_AF2` | TIM3 复用功能寄存器 2 | `0x064` | `0x40000464` | 32 | — | 0x00000000 / 0xFFFFFFFF | OCRSEL[18:16] (RW)（ocref_clr 源选择） | — |
| `TIM3_DCR` | TIM3 DMA 控制寄存器 | `0x3DC` | `0x400007DC` | 32 | — | 0x00000000 / 0xFFFFFFFF | DBSS[19:16] (RW)（DMA 突发源选择）、DBL[12:8] (RW)（DMA 突发长度）、DBA[4:0] (RW)（DMA 基址地址） | — |
| `TIM3_DMAR` | TIM3 DMA 地址的满传输 | `0x3E0` | `0x400007E0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DMAB[31:0] (RW)（待核） | — |

## TIM4

**模块用途**　通用定时器，按实例提供计数、输入捕获、输出比较、PWM 或触发功能。以本实例表中的通道为准。

基地址 `0x40000800` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `TIM4_CR1` | TIM4 控制寄存器 1 | `0x000` | `0x40000800` | 16 | — | 0x00000000 / 0x0000FFFF | DITHEN[12] (RW)（待核）、UIFREMAP[11] (RW)（待核）、CKD[9:8] (RW)（时钟分频）、ARPE[7] (RW)（自动重装预装载使能）、CMS[6:5] (RW)（待核）、DIR[4] (RW)（方向）、OPM[3] (RW)（待核）、URS[2] (RW)（更新请求源）、UDIS[1] (RW)（更新禁用）、CEN[0] (RW)（计数器使能） | — |
| `TIM4_CR2` | TIM4 控制寄存器 2 | `0x004` | `0x40000804` | 32 | — | 0x00000000 / 0xFFFFFFFF | MMS_1[25] (RW)（待核）、TI1S[7] (RW)（tim_ti1 选择）、MMS[6:4] (RW)（MMS[0]: 主设备模式选择）、CCDS[3] (RW)（捕获/比较 DMA 选择） | — |
| `TIM4_SMCR` | TIM4 从设备模式控制寄存器 | `0x008` | `0x40000808` | 32 | — | 0x00000000 / 0xFFFFFFFF | SMSPS[25] (RW)（SMS 预装载源）、SMSPE[24] (RW)（SMS 预装载使能）、TS_1[21:20] (RW)（待核）、SMS_1[16] (RW)（待核）、ETP[15] (RW)（外部触发极性）、ECE[14] (RW)（外部时钟使能）、ETPS[13:12] (RW)（外部触发预分频器）、ETF[11:8] (RW)（外部触发滤波）、MSM[7] (RW)（主设备/从设备模式）、TS[6:4] (RW)（TS[0]: 触发选择）、OCCS[3] (RW)（OCREF 清除选择）、SMS[2:0] (RW)（SMS[0]: 从设备模式选择） | — |
| `TIM4_DIER` | TIM4 DMA/中断使能寄存器 | `0x00C` | `0x4000080C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TERRIE[23] (RW)（转换错误中断使能）、IERRIE[22] (RW)（索引错误中断使能）、DIRIE[21] (RW)（待核）、IDXIE[20] (RW)（索引中断使能）、TDE[14] (RW)（触发 DMA 请求使能）、CC4DE[12] (RW)（捕获/比较 4 DMA 请求使能）、CC3DE[11] (RW)（捕获/比较 3 DMA 请求使能）、CC2DE[10] (RW)（捕获/比较 2 DMA 请求使能）、CC1DE[9] (RW)（捕获/比较 1 DMA 请求使能）、UDE[8] (RW)（更新 DMA 请求使能）、TIE[6] (RW)（触发中断使能）、CC4IE[4] (RW)（捕获/比较 4 中断使能）、CC3IE[3] (RW)（捕获/比较 3 中断使能）、CC2IE[2] (RW)（捕获/比较 2 中断使能）、CC1IE[1] (RW)（捕获/比较 1 中断使能）、UIE[0] (RW)（更新中断使能） | — |
| `TIM4_SR` | TIM4 状态寄存器 | `0x010` | `0x40000810` | 32 | — | 0x00000000 / 0xFFFFFFFF | TERRF[23] (RW)（转换错误中断标志）、IERRF[22] (RW)（索引错误中断标志）、DIRF[21] (RW)（待核）、IDXF[20] (RW)（索引中断标志）、CC4OF[12] (RW)（待核）、CC3OF[11] (RW)（待核）、CC2OF[10] (RW)（待核）、CC1OF[9] (RW)（待核）、TIF[6] (RW)（触发中断标志）、CC4IF[4] (RW)（捕获/比较 4 中断标志）、CC3IF[3] (RW)（捕获/比较 3 中断标志）、CC2IF[2] (RW)（捕获/比较 2 中断标志）、CC1IF[1] (RW)（捕获/比较 1 中断标志）、UIF[0] (RW)（更新中断标志） | — |
| `TIM4_EGR` | TIM4 事件生成寄存器 | `0x014` | `0x40000814` | 16 | — | 0x00000000 / 0x0000FFFF | TG[6] (WO)（触发生成）、CC4G[4] (WO)（捕获/比较 4 生成）、CC3G[3] (WO)（捕获/比较 3 生成）、CC2G[2] (WO)（捕获/比较 2 生成）、CC1G[1] (WO)（捕获/比较 1 生成）、UG[0] (WO)（更新生成） | — |
| `TIM4_CCMR1_INPUT` | TIM4 捕获/比较模式寄存器 1 | `0x018` | `0x40000818` | 32 | — | 0x00000000 / 0xFFFFFFFF | IC2F[15:12] (RW)（输入捕获 2 滤波）、IC2PSC[11:10] (RW)（输入捕获 2 预分频器）、CC2S[9:8] (RW)（捕获/比较 2 选择）、IC1F[7:4] (RW)（输入捕获 1 滤波）、IC1PSC[3:2] (RW)（输入捕获 1 预分频器）、CC1S[1:0] (RW)（捕获/比较 1 选择） | — |
| `TIM4_CCMR1_OUTPUT` | TIM4 捕获/比较模式寄存器 1 | `0x018` | `0x40000818` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC2M_1[24] (RW)（待核）、OC1M_1[16] (RW)（待核）、OC2CE[15] (RW)（输出比较 2 清除使能）、OC2M[14:12] (RW)（OC2M[2:0]: 输出比较 2 模式）、OC2PE[11] (RW)（输出比较 2 预装载使能）、OC2FE[10] (RW)（输出比较 2 快速使能）、CC2S[9:8] (RW)（捕获/比较 2 选择）、OC1CE[7] (RW)（输出比较 1 清除使能）、OC1M[6:4] (RW)（OC1M[2:0]: 输出比较 1 模式）、OC1PE[3] (RW)（输出比较 1 预装载使能）、OC1FE[2] (RW)（输出比较 1 快速使能）、CC1S[1:0] (RW)（捕获/比较 1 选择） | 别名 TIM4_CCMR1_INPUT |
| `TIM4_CCMR2_INPUT` | TIM4 捕获/比较模式寄存器 2 | `0x01C` | `0x4000081C` | 32 | — | 0x00000000 / 0xFFFFFFFF | IC4F[15:12] (RW)（输入捕获 4 滤波）、IC4PSC[11:10] (RW)（输入捕获 4 预分频器）、CC4S[9:8] (RW)（捕获/比较 4 选择）、IC3F[7:4] (RW)（输入捕获 3 滤波）、IC3PSC[3:2] (RW)（输入捕获 3 预分频器）、CC3S[1:0] (RW)（捕获/比较 3 选择） | — |
| `TIM4_CCMR2_OUTPUT` | TIM4 捕获/比较模式寄存器 2 | `0x01C` | `0x4000081C` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC4M_1[24] (RW)（待核）、OC3M_1[16] (RW)（待核）、OC4CE[15] (RW)（输出比较 4 清除使能）、OC4M[14:12] (RW)（OC4M[2:0]: 输出比较 4 模式）、OC4PE[11] (RW)（输出比较 4 预装载使能）、OC4FE[10] (RW)（输出比较 4 快速使能）、CC4S[9:8] (RW)（捕获/比较 4 选择）、OC3CE[7] (RW)（输出比较 3 清除使能）、OC3M[6:4] (RW)（OC3M[2:0]: 输出比较 3 模式）、OC3PE[3] (RW)（输出比较 3 预装载使能）、OC3FE[2] (RW)（输出比较 3 快速使能）、CC3S[1:0] (RW)（捕获/比较 3 选择） | 别名 TIM4_CCMR2_INPUT |
| `TIM4_CCER` | TIM4 捕获/比较使能寄存器 | `0x020` | `0x40000820` | 16 | — | 0x00000000 / 0x0000FFFF | CC4NP[15] (RW)（捕获/比较 4 输出极性）、CC4P[13] (RW)（捕获/比较 4 输出极性）、CC4E[12] (RW)（捕获/比较 4 输出使能）、CC3NP[11] (RW)（捕获/比较 3 输出极性）、CC3P[9] (RW)（捕获/比较 3 输出极性）、CC3E[8] (RW)（捕获/比较 3 输出使能）、CC2NP[7] (RW)（捕获/比较 2 输出极性）、CC2P[5] (RW)（捕获/比较 2 输出极性）、CC2E[4] (RW)（捕获/比较 2 输出使能）、CC1NP[3] (RW)（捕获/比较 1 输出极性）、CC1P[1] (RW)（捕获/比较 1 输出极性）、CC1E[0] (RW)（捕获/比较 1 输出使能） | — |
| `TIM4_CNT` | TIM4 计数器 | `0x024` | `0x40000824` | 32 | — | 0x00000000 / 0xFFFFFFFF | UIFCPY_CNT[31] (RW)（待核）、CNT[30:0] (RW)（待核） | — |
| `TIM4_PSC` | TIM4 预分频器 | `0x028` | `0x40000828` | 16 | — | 0x00000000 / 0x0000FFFF | PSC[15:0] (RW)（预分频器值） | — |
| `TIM4_ARR` | TIM4 自动重装寄存器 | `0x02C` | `0x4000082C` | 32 | — | 0xFFFFFFFF / 0xFFFFFFFF | ARR[31:0] (RW)（自动重装值） | — |
| `TIM4_CCR1` | TIM4 捕获/比较寄存器 1 | `0x034` | `0x40000834` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR1[31:0] (RW)（捕获/比较 1 值） | — |
| `TIM4_CCR2` | TIM4 捕获/比较寄存器 2 | `0x038` | `0x40000838` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR2[31:0] (RW)（捕获/比较 2 值） | — |
| `TIM4_CCR3` | TIM4 捕获/比较寄存器 3 | `0x03C` | `0x4000083C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR3[31:0] (RW)（捕获/比较 3 值） | — |
| `TIM4_CCR4` | TIM4 捕获/比较寄存器 4 | `0x040` | `0x40000840` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR4[31:0] (RW)（捕获/比较 4 值） | — |
| `TIM4_ECR` | TIM4 定时器编码器控制寄存器 | `0x058` | `0x40000858` | 32 | — | 0x00000000 / 0xFFFFFFFF | PWPRSC[26:24] (RW)（脉冲宽度预分频器）、PW[23:16] (RW)（脉冲宽度）、IPOS[7:6] (RW)（待核）、FIDX[5] (RW)（首个索引）、IBLK[4:3] (RW)（待核）、IDIR[2:1] (RW)（索引方向）、IE[0] (RW)（索引使能） | — |
| `TIM4_TISEL` | TIM4 定时器输入选择寄存器 | `0x05C` | `0x4000085C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TI4SEL[27:24] (RW)（待核）、TI3SEL[19:16] (RW)（待核）、TI2SEL[11:8] (RW)（待核）、TI1SEL[3:0] (RW)（待核） | — |
| `TIM4_AF1` | TIM4 复用功能寄存器 1 | `0x060` | `0x40000860` | 32 | — | 0x00000000 / 0xFFFFFFFF | ETRSEL[17:14] (RW)（etr_in 源选择） | — |
| `TIM4_AF2` | TIM4 复用功能寄存器 2 | `0x064` | `0x40000864` | 32 | — | 0x00000000 / 0xFFFFFFFF | OCRSEL[18:16] (RW)（ocref_clr 源选择） | — |
| `TIM4_DCR` | TIM4 DMA 控制寄存器 | `0x3DC` | `0x40000BDC` | 32 | — | 0x00000000 / 0xFFFFFFFF | DBSS[19:16] (RW)（DMA 突发源选择）、DBL[12:8] (RW)（DMA 突发长度）、DBA[4:0] (RW)（DMA 基址地址） | — |
| `TIM4_DMAR` | TIM4 DMA 地址的满传输 | `0x3E0` | `0x40000BE0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DMAB[31:0] (RW)（待核） | — |

## TIM5

**模块用途**　通用定时器，按实例提供计数、输入捕获、输出比较、PWM 或触发功能。以本实例表中的通道为准。

基地址 `0x40000C00` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `TIM5_CR1` | TIM5 控制寄存器 1 | `0x000` | `0x40000C00` | 16 | — | 0x00000000 / 0x0000FFFF | DITHEN[12] (RW)（待核）、UIFREMAP[11] (RW)（待核）、CKD[9:8] (RW)（时钟分频）、ARPE[7] (RW)（自动重装预装载使能）、CMS[6:5] (RW)（待核）、DIR[4] (RW)（方向）、OPM[3] (RW)（待核）、URS[2] (RW)（更新请求源）、UDIS[1] (RW)（更新禁用）、CEN[0] (RW)（计数器使能） | — |
| `TIM5_CR2` | TIM5 控制寄存器 2 | `0x004` | `0x40000C04` | 32 | — | 0x00000000 / 0xFFFFFFFF | MMS_1[25] (RW)（待核）、TI1S[7] (RW)（tim_ti1 选择）、MMS[6:4] (RW)（MMS[0]: 主设备模式选择）、CCDS[3] (RW)（捕获/比较 DMA 选择） | — |
| `TIM5_SMCR` | TIM5 从设备模式控制寄存器 | `0x008` | `0x40000C08` | 32 | — | 0x00000000 / 0xFFFFFFFF | SMSPS[25] (RW)（SMS 预装载源）、SMSPE[24] (RW)（SMS 预装载使能）、TS_1[21:20] (RW)（待核）、SMS_1[16] (RW)（待核）、ETP[15] (RW)（外部触发极性）、ECE[14] (RW)（外部时钟使能）、ETPS[13:12] (RW)（外部触发预分频器）、ETF[11:8] (RW)（外部触发滤波）、MSM[7] (RW)（主设备/从设备模式）、TS[6:4] (RW)（TS[0]: 触发选择）、OCCS[3] (RW)（OCREF 清除选择）、SMS[2:0] (RW)（SMS[0]: 从设备模式选择） | — |
| `TIM5_DIER` | TIM5 DMA/中断使能寄存器 | `0x00C` | `0x40000C0C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TERRIE[23] (RW)（转换错误中断使能）、IERRIE[22] (RW)（索引错误中断使能）、DIRIE[21] (RW)（待核）、IDXIE[20] (RW)（索引中断使能）、TDE[14] (RW)（触发 DMA 请求使能）、CC4DE[12] (RW)（捕获/比较 4 DMA 请求使能）、CC3DE[11] (RW)（捕获/比较 3 DMA 请求使能）、CC2DE[10] (RW)（捕获/比较 2 DMA 请求使能）、CC1DE[9] (RW)（捕获/比较 1 DMA 请求使能）、UDE[8] (RW)（更新 DMA 请求使能）、TIE[6] (RW)（触发中断使能）、CC4IE[4] (RW)（捕获/比较 4 中断使能）、CC3IE[3] (RW)（捕获/比较 3 中断使能）、CC2IE[2] (RW)（捕获/比较 2 中断使能）、CC1IE[1] (RW)（捕获/比较 1 中断使能）、UIE[0] (RW)（更新中断使能） | — |
| `TIM5_SR` | TIM5 状态寄存器 | `0x010` | `0x40000C10` | 32 | — | 0x00000000 / 0xFFFFFFFF | TERRF[23] (RW)（转换错误中断标志）、IERRF[22] (RW)（索引错误中断标志）、DIRF[21] (RW)（待核）、IDXF[20] (RW)（索引中断标志）、CC4OF[12] (RW)（待核）、CC3OF[11] (RW)（待核）、CC2OF[10] (RW)（待核）、CC1OF[9] (RW)（待核）、TIF[6] (RW)（触发中断标志）、CC4IF[4] (RW)（捕获/比较 4 中断标志）、CC3IF[3] (RW)（捕获/比较 3 中断标志）、CC2IF[2] (RW)（捕获/比较 2 中断标志）、CC1IF[1] (RW)（捕获/比较 1 中断标志）、UIF[0] (RW)（更新中断标志） | — |
| `TIM5_EGR` | TIM5 事件生成寄存器 | `0x014` | `0x40000C14` | 16 | — | 0x00000000 / 0x0000FFFF | TG[6] (WO)（触发生成）、CC4G[4] (WO)（捕获/比较 4 生成）、CC3G[3] (WO)（捕获/比较 3 生成）、CC2G[2] (WO)（捕获/比较 2 生成）、CC1G[1] (WO)（捕获/比较 1 生成）、UG[0] (WO)（更新生成） | — |
| `TIM5_CCMR1_INPUT` | TIM5 捕获/比较模式寄存器 1 | `0x018` | `0x40000C18` | 32 | — | 0x00000000 / 0xFFFFFFFF | IC2F[15:12] (RW)（输入捕获 2 滤波）、IC2PSC[11:10] (RW)（输入捕获 2 预分频器）、CC2S[9:8] (RW)（捕获/比较 2 选择）、IC1F[7:4] (RW)（输入捕获 1 滤波）、IC1PSC[3:2] (RW)（输入捕获 1 预分频器）、CC1S[1:0] (RW)（捕获/比较 1 选择） | — |
| `TIM5_CCMR1_OUTPUT` | TIM5 捕获/比较模式寄存器 1 | `0x018` | `0x40000C18` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC2M_1[24] (RW)（待核）、OC1M_1[16] (RW)（待核）、OC2CE[15] (RW)（输出比较 2 清除使能）、OC2M[14:12] (RW)（OC2M[2:0]: 输出比较 2 模式）、OC2PE[11] (RW)（输出比较 2 预装载使能）、OC2FE[10] (RW)（输出比较 2 快速使能）、CC2S[9:8] (RW)（捕获/比较 2 选择）、OC1CE[7] (RW)（输出比较 1 清除使能）、OC1M[6:4] (RW)（OC1M[2:0]: 输出比较 1 模式）、OC1PE[3] (RW)（输出比较 1 预装载使能）、OC1FE[2] (RW)（输出比较 1 快速使能）、CC1S[1:0] (RW)（捕获/比较 1 选择） | 别名 TIM5_CCMR1_INPUT |
| `TIM5_CCMR2_INPUT` | TIM5 捕获/比较模式寄存器 2 | `0x01C` | `0x40000C1C` | 32 | — | 0x00000000 / 0xFFFFFFFF | IC4F[15:12] (RW)（输入捕获 4 滤波）、IC4PSC[11:10] (RW)（输入捕获 4 预分频器）、CC4S[9:8] (RW)（捕获/比较 4 选择）、IC3F[7:4] (RW)（输入捕获 3 滤波）、IC3PSC[3:2] (RW)（输入捕获 3 预分频器）、CC3S[1:0] (RW)（捕获/比较 3 选择） | — |
| `TIM5_CCMR2_OUTPUT` | TIM5 捕获/比较模式寄存器 2 | `0x01C` | `0x40000C1C` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC4M_1[24] (RW)（待核）、OC3M_1[16] (RW)（待核）、OC4CE[15] (RW)（输出比较 4 清除使能）、OC4M[14:12] (RW)（OC4M[2:0]: 输出比较 4 模式）、OC4PE[11] (RW)（输出比较 4 预装载使能）、OC4FE[10] (RW)（输出比较 4 快速使能）、CC4S[9:8] (RW)（捕获/比较 4 选择）、OC3CE[7] (RW)（输出比较 3 清除使能）、OC3M[6:4] (RW)（OC3M[2:0]: 输出比较 3 模式）、OC3PE[3] (RW)（输出比较 3 预装载使能）、OC3FE[2] (RW)（输出比较 3 快速使能）、CC3S[1:0] (RW)（捕获/比较 3 选择） | 别名 TIM5_CCMR2_INPUT |
| `TIM5_CCER` | TIM5 捕获/比较使能寄存器 | `0x020` | `0x40000C20` | 16 | — | 0x00000000 / 0x0000FFFF | CC4NP[15] (RW)（捕获/比较 4 输出极性）、CC4P[13] (RW)（捕获/比较 4 输出极性）、CC4E[12] (RW)（捕获/比较 4 输出使能）、CC3NP[11] (RW)（捕获/比较 3 输出极性）、CC3P[9] (RW)（捕获/比较 3 输出极性）、CC3E[8] (RW)（捕获/比较 3 输出使能）、CC2NP[7] (RW)（捕获/比较 2 输出极性）、CC2P[5] (RW)（捕获/比较 2 输出极性）、CC2E[4] (RW)（捕获/比较 2 输出使能）、CC1NP[3] (RW)（捕获/比较 1 输出极性）、CC1P[1] (RW)（捕获/比较 1 输出极性）、CC1E[0] (RW)（捕获/比较 1 输出使能） | — |
| `TIM5_CNT` | TIM5 计数器 | `0x024` | `0x40000C24` | 32 | — | 0x00000000 / 0xFFFFFFFF | UIFCPY_CNT[31] (RW)（待核）、CNT[30:0] (RW)（待核） | — |
| `TIM5_PSC` | TIM5 预分频器 | `0x028` | `0x40000C28` | 16 | — | 0x00000000 / 0x0000FFFF | PSC[15:0] (RW)（预分频器值） | — |
| `TIM5_ARR` | TIM5 自动重装寄存器 | `0x02C` | `0x40000C2C` | 32 | — | 0xFFFFFFFF / 0xFFFFFFFF | ARR[31:0] (RW)（自动重装值） | — |
| `TIM5_CCR1` | TIM5 捕获/比较寄存器 1 | `0x034` | `0x40000C34` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR1[31:0] (RW)（捕获/比较 1 值） | — |
| `TIM5_CCR2` | TIM5 捕获/比较寄存器 2 | `0x038` | `0x40000C38` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR2[31:0] (RW)（捕获/比较 2 值） | — |
| `TIM5_CCR3` | TIM5 捕获/比较寄存器 3 | `0x03C` | `0x40000C3C` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR3[31:0] (RW)（捕获/比较 3 值） | — |
| `TIM5_CCR4` | TIM5 捕获/比较寄存器 4 | `0x040` | `0x40000C40` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR4[31:0] (RW)（捕获/比较 4 值） | — |
| `TIM5_ECR` | TIM5 定时器编码器控制寄存器 | `0x058` | `0x40000C58` | 32 | — | 0x00000000 / 0xFFFFFFFF | PWPRSC[26:24] (RW)（脉冲宽度预分频器）、PW[23:16] (RW)（脉冲宽度）、IPOS[7:6] (RW)（待核）、FIDX[5] (RW)（首个索引）、IBLK[4:3] (RW)（待核）、IDIR[2:1] (RW)（索引方向）、IE[0] (RW)（索引使能） | — |
| `TIM5_TISEL` | TIM5 定时器输入选择寄存器 | `0x05C` | `0x40000C5C` | 32 | — | 0x00000000 / 0xFFFFFFFF | TI4SEL[27:24] (RW)（待核）、TI3SEL[19:16] (RW)（待核）、TI2SEL[11:8] (RW)（待核）、TI1SEL[3:0] (RW)（待核） | — |
| `TIM5_AF1` | TIM5 复用功能寄存器 1 | `0x060` | `0x40000C60` | 32 | — | 0x00000000 / 0xFFFFFFFF | ETRSEL[17:14] (RW)（etr_in 源选择） | — |
| `TIM5_AF2` | TIM5 复用功能寄存器 2 | `0x064` | `0x40000C64` | 32 | — | 0x00000000 / 0xFFFFFFFF | OCRSEL[18:16] (RW)（ocref_clr 源选择） | — |
| `TIM5_DCR` | TIM5 DMA 控制寄存器 | `0x3DC` | `0x40000FDC` | 32 | — | 0x00000000 / 0xFFFFFFFF | DBSS[19:16] (RW)（DMA 突发源选择）、DBL[12:8] (RW)（DMA 突发长度）、DBA[4:0] (RW)（DMA 基址地址） | — |
| `TIM5_DMAR` | TIM5 DMA 地址的满传输 | `0x3E0` | `0x40000FE0` | 32 | — | 0x00000000 / 0xFFFFFFFF | DMAB[31:0] (RW)（待核） | — |

## TIM6

**模块用途**　基本定时器，主要用于周期计时与内部触发。重点查看预分频、计数器和自动重装。

基地址 `0x40001000` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `TIM6_CR1` | TIM6 控制寄存器 1 | `0x000` | `0x40001000` | 16 | — | 0x00000000 / 0x0000FFFF | DITHEN[12] (RW)（待核）、UIFREMAP[11] (RW)（待核）、ARPE[7] (RW)（自动重装预装载使能）、OPM[3] (RW)（待核）、URS[2] (RW)（更新请求源）、UDIS[1] (RW)（更新禁用）、CEN[0] (RW)（计数器使能） | — |
| `TIM6_CR2` | TIM6 控制寄存器 2 | `0x004` | `0x40001004` | 16 | — | 0x00000000 / 0x0000FFFF | MMS[6:4] (RW)（主设备模式选择） | — |
| `TIM6_DIER` | TIM6 DMA/中断使能寄存器 | `0x00C` | `0x4000100C` | 16 | — | 0x00000000 / 0x0000FFFF | UDE[8] (RW)（更新 DMA 请求使能）、UIE[0] (RW)（更新中断使能） | — |
| `TIM6_SR` | TIM6 状态寄存器 | `0x010` | `0x40001010` | 16 | — | 0x00000000 / 0x0000FFFF | UIF[0] (RW)（更新中断标志） | — |
| `TIM6_EGR` | TIM6 事件生成寄存器 | `0x014` | `0x40001014` | 16 | — | 0x00000000 / 0x0000FFFF | UG[0] (WO)（更新生成） | — |
| `TIM6_CNT` | TIM6 计数器 | `0x024` | `0x40001024` | 32 | — | 0x00000000 / 0xFFFFFFFF | UIFCPY[31] (RO)（待核）、CNT[15:0] (RW)（计数器值） | — |
| `TIM6_PSC` | TIM6 预分频器 | `0x028` | `0x40001028` | 16 | — | 0x00000000 / 0x0000FFFF | PSC[15:0] (RW)（预分频器值） | — |
| `TIM6_ARR` | TIM6 自动重装寄存器 | `0x02C` | `0x4000102C` | 32 | — | 0x0000FFFF / 0xFFFFFFFF | ARR[19:0] (RW)（自动重装值） | — |

## TIM7

**模块用途**　基本定时器，主要用于周期计时与内部触发。重点查看预分频、计数器和自动重装。

基地址 `0x40001400` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `TIM7_CR1` | TIM7 控制寄存器 1 | `0x000` | `0x40001400` | 16 | — | 0x00000000 / 0x0000FFFF | DITHEN[12] (RW)（待核）、UIFREMAP[11] (RW)（待核）、ARPE[7] (RW)（自动重装预装载使能）、OPM[3] (RW)（待核）、URS[2] (RW)（更新请求源）、UDIS[1] (RW)（更新禁用）、CEN[0] (RW)（计数器使能） | — |
| `TIM7_CR2` | TIM7 控制寄存器 2 | `0x004` | `0x40001404` | 16 | — | 0x00000000 / 0x0000FFFF | MMS[6:4] (RW)（主设备模式选择） | — |
| `TIM7_DIER` | TIM7 DMA/中断使能寄存器 | `0x00C` | `0x4000140C` | 16 | — | 0x00000000 / 0x0000FFFF | UDE[8] (RW)（更新 DMA 请求使能）、UIE[0] (RW)（更新中断使能） | — |
| `TIM7_SR` | TIM7 状态寄存器 | `0x010` | `0x40001410` | 16 | — | 0x00000000 / 0x0000FFFF | UIF[0] (RW)（更新中断标志） | — |
| `TIM7_EGR` | TIM7 事件生成寄存器 | `0x014` | `0x40001414` | 16 | — | 0x00000000 / 0x0000FFFF | UG[0] (WO)（更新生成） | — |
| `TIM7_CNT` | TIM7 计数器 | `0x024` | `0x40001424` | 32 | — | 0x00000000 / 0xFFFFFFFF | UIFCPY[31] (RO)（待核）、CNT[15:0] (RW)（计数器值） | — |
| `TIM7_PSC` | TIM7 预分频器 | `0x028` | `0x40001428` | 16 | — | 0x00000000 / 0x0000FFFF | PSC[15:0] (RW)（预分频器值） | — |
| `TIM7_ARR` | TIM7 自动重装寄存器 | `0x02C` | `0x4000142C` | 32 | — | 0x0000FFFF / 0xFFFFFFFF | ARR[19:0] (RW)（自动重装值） | — |

## TIM9

**模块用途**　通用定时器，按实例提供计数、输入捕获、输出比较、PWM 或触发功能。以本实例表中的通道为准。

基地址 `0x42004C00` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `TIM9_CR1` | TIM9 控制寄存器 1 | `0x000` | `0x42004C00` | 16 | — | 0x00000000 / 0x0000FFFF | DITHEN[12] (RW)（待核）、UIFREMAP[11] (RW)（待核）、CKD[9:8] (RW)（时钟分频）、ARPE[7] (RW)（自动重装预装载使能）、OPM[3] (RW)（待核）、URS[2] (RW)（更新请求源）、UDIS[1] (RW)（更新禁用）、CEN[0] (RW)（计数器使能） | — |
| `TIM9_CR2` | TIM12 控制寄存器 2 | `0x004` | `0x42004C04` | 16 | — | 0x00000000 / 0x0000FFFF | TI1S[7] (RW)（tim_ti1 选择）、MMS[6:4] (RW)（主设备模式选择） | — |
| `TIM9_SMCR` | TIM9 从设备模式控制寄存器 | `0x008` | `0x42004C08` | 32 | — | 0x00000000 / 0xFFFFFFFF | TS_1[21:20] (RW)（待核）、SMS_1[16] (RW)（待核）、MSM[7] (RW)（主设备/从设备模式）、TS[6:4] (RW)（TS[0]: 触发选择）、SMS[2:0] (RW)（SMS[0]: 从设备模式选择） | — |
| `TIM9_DIER` | TIM9 中断使能寄存器 | `0x00C` | `0x42004C0C` | 16 | — | 0x00000000 / 0x0000FFFF | TIE[6] (RW)（触发中断使能）、CC2IE[2] (RW)（捕获/比较 2 中断使能）、CC1IE[1] (RW)（捕获/比较 1 中断使能）、UIE[0] (RW)（更新中断使能） | — |
| `TIM9_SR` | TIM9 状态寄存器 | `0x010` | `0x42004C10` | 16 | — | 0x00000000 / 0x0000FFFF | CC2OF[10] (RW)（待核）、CC1OF[9] (RW)（待核）、TIF[6] (RW)（触发中断标志）、CC2IF[2] (RW)（捕获/比较 2 中断标志）、CC1IF[1] (RW)（捕获/比较 1 中断标志）、UIF[0] (RW)（更新中断标志） | — |
| `TIM9_EGR` | TIM9 事件生成寄存器 | `0x014` | `0x42004C14` | 16 | — | 0x00000000 / 0x0000FFFF | TG[6] (WO)（触发生成）、CC2G[2] (WO)（捕获/比较 2 生成）、CC1G[1] (WO)（捕获/比较 1 生成）、UG[0] (WO)（更新生成） | — |
| `TIM9_CCMR1_INPUT` | TIM9 捕获/比较模式寄存器 1 | `0x018` | `0x42004C18` | 32 | — | 0x00000000 / 0xFFFFFFFF | IC2F[15:12] (RW)（输入捕获 2 滤波）、IC2PSC[11:10] (RW)（输入捕获 2 预分频器）、CC2S[9:8] (RW)（捕获/比较 2 选择）、IC1F[7:4] (RW)（输入捕获 1 滤波）、IC1PSC[3:2] (RW)（输入捕获 1 预分频器）、CC1S[1:0] (RW)（捕获/比较 1 选择） | — |
| `TIM9_CCMR1_OUTPUT` | TIM9 捕获/比较模式寄存器 1 | `0x018` | `0x42004C18` | 32 | — | 0x00000000 / 0xFFFFFFFF | OC2M_1[24] (RW)（待核）、OC1M_1[16] (RW)（待核）、OC2M[14:12] (RW)（OC2M[2:0]: 输出比较 2 模式）、OC2PE[11] (RW)（输出比较 2 预装载使能）、OC2FE[10] (RW)（输出比较 2 快速使能）、CC2S[9:8] (RW)（捕获/比较 2 选择）、OC1M[6:4] (RW)（待核）、OC1PE[3] (RW)（输出比较 1 预装载使能）、OC1FE[2] (RW)（输出比较 1 快速使能）、CC1S[1:0] (RW)（捕获/比较 1 选择） | 别名 TIM9_CCMR1_INPUT |
| `TIM9_CCER` | TIM9 捕获/比较使能寄存器 | `0x020` | `0x42004C20` | 16 | — | 0x00000000 / 0x0000FFFF | CC2NP[7] (RW)（捕获/比较 2 输出极性）、CC2P[5] (RW)（捕获/比较 2 输出极性）、CC2E[4] (RW)（捕获/比较 2 输出使能）、CC1NP[3] (RW)（待核）、CC1P[1] (RW)（捕获/比较 1 输出极性）、CC1E[0] (RW)（捕获/比较 1 输出使能） | — |
| `TIM9_CNT` | TIM9 计数器 | `0x024` | `0x42004C24` | 32 | — | 0x00000000 / 0xFFFFFFFF | UIFCPY[31] (RW)（待核）、CNT[15:0] (RW)（计数器值） | — |
| `TIM9_PSC` | TIM9 预分频器 | `0x028` | `0x42004C28` | 16 | — | 0x00000000 / 0x0000FFFF | PSC[15:0] (RW)（预分频器值） | — |
| `TIM9_ARR` | TIM9 自动重装寄存器 | `0x02C` | `0x42004C2C` | 32 | — | 0x0000FFFF / 0xFFFFFFFF | ARR[19:0] (RW)（自动重装值） | — |
| `TIM9_CCR1` | TIM9 捕获/比较寄存器 1 | `0x034` | `0x42004C34` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR1[19:0] (RW)（捕获/比较 1 值） | — |
| `TIM9_CCR2` | TIM9 捕获/比较寄存器 2 | `0x038` | `0x42004C38` | 32 | — | 0x00000000 / 0xFFFFFFFF | CCR2[19:0] (RW)（捕获/比较 2 值） | — |
| `TIM9_TISEL` | TIM9 定时器输入选择寄存器 | `0x05C` | `0x42004C5C` | 16 | — | 0x00000000 / 0x0000FFFF | TI2SEL[11:8] (RW)（待核）、TI1SEL[3:0] (RW)（待核） | — |

## WWDG

**模块用途**　窗口看门狗，要求软件在规定时间窗口内刷新计数。过早或过晚都可能触发复位。

基地址 `0x40002C00` · SVD

| 寄存器 | 中文用途 | 偏移 | 绝对地址 | 位宽 | 访问 | 复位值 / 掩码 | 位域 | 备注 |
| --- | --- | --- | --- | ---: | --- | --- | --- | --- |
| `CR` | 控制寄存器 | `0x000` | `0x40002C00` | 32 | RW | 0x0000007F / 0xFFFFFFFF | WDGA[7]（待核）、T[6:0]（7-位计数器 (MSB 至 LSB)） | — |
| `CFR` | 配置寄存器 | `0x004` | `0x40002C04` | 32 | RW | 0x0000007F / 0xFFFFFFFF | WDGTB[13:11]（定时器基址时间基址的）、EWI[9]（待核）、W[6:0]（7-位窗口值） | — |
| `SR` | 状态寄存器 | `0x008` | `0x40002C08` | 32 | RW | 0x00000000 / 0xFFFFFFFF | EWIF[0]（提前唤醒中断标志） | — |
