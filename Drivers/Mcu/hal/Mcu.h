#ifndef MCU_H
#define MCU_H

#include <stdbool.h>
#include "Std_Types.h"

typedef enum {
    MCU_CLOCK_HSI,
    MCU_CLOCK_PLL1_192MHZ,
    MCU_CLOCK_PLL1_600MHZ
} Mcu_ClockType;

typedef enum {
    MCU_SOURCE_HSI,
    MCU_SOURCE_CSI,
    MCU_SOURCE_HSE,
    MCU_SOURCE_PLL1,
    MCU_SOURCE_UNKNOWN
} Mcu_ClockSourceType;

typedef enum {
    MCU_PLL_UNLOCKED,
    MCU_PLL_LOCKED
} Mcu_PllStatusType;

typedef enum {
    MCU_CLOCK_OK,
    MCU_CLOCK_NOT_INITIALIZED,
    MCU_CLOCK_INVALID_PROFILE,
    MCU_CLOCK_HSI_TIMEOUT,
    MCU_CLOCK_HSI_SWITCH_TIMEOUT,
    MCU_CLOCK_SUPPLY_NOT_READY,
    MCU_CLOCK_VOS_TIMEOUT,
    MCU_CLOCK_HSE_STOP_TIMEOUT,
    MCU_CLOCK_HSE_TIMEOUT,
    MCU_CLOCK_PLL_SOURCE_IN_USE,
    MCU_CLOCK_PLL_STOP_TIMEOUT,
    MCU_CLOCK_PLL_LOCK_TIMEOUT,
    MCU_CLOCK_PLL_NOT_PREPARED,
    MCU_CLOCK_FLASH_TIMING_FAILED,
    MCU_CLOCK_PLL_SWITCH_TIMEOUT,
    MCU_CLOCK_SRAM_ECC_ENABLED  /* 600 MHz 档要求 SRAM ECC 关闭。 */
} Mcu_ClockResultType;

typedef struct {
    Mcu_ClockSourceType source;
    uint32 sysHz;   /* SYSCLK 多路选择器输出，未经过 CPU 分频。 */
    uint32 coreHz;
    uint32 ahbHz;
    uint32 apb1Hz;
    uint32 apb2Hz;
    uint32 apb4Hz;
    uint32 apb5Hz;
} Mcu_ClockInfoType;

/* 启动阶段串行调用。先 Mcu_Init，再选时钟方案，PLL 档最后执行分配。 */
void Mcu_Init(void);
Mcu_ClockResultType Mcu_InitClock(Mcu_ClockType profile);
Mcu_PllStatusType Mcu_GetPllStatus(void);
Mcu_ClockResultType Mcu_DistributePllClock(void);

/* 按当前寄存器配置计算标称频率，单位 Hz。 */
Mcu_ClockInfoType Mcu_GetClockInfo(void);
/* RCC_RSR 的原始标志位，可以同时有多个置位。 */
uint32 Mcu_GetResetRawValue(void);
/* 保留原始失败阶段，另行报告 HSI 回退是否完成。 */
Mcu_ClockResultType Mcu_GetLastClockError(void);
Mcu_ClockResultType Mcu_GetFallbackResult(void);

/* CMSIS 约定的 CPU 时钟快照，时钟切换后由驱动更新。 */
extern uint32 SystemCoreClock;

/* 启动阶段使能 USART3 门控并选择 PCLK1。共享选择器无法切换时返回 false。 */
bool Mcu_EnableUsart3Clock(void);
/* 返回 USART3 内核时钟的标称频率。门控关闭或来源不受支持时返回 0 Hz。 */
uint32 Mcu_GetUsart3ClockHz(void);

#endif
