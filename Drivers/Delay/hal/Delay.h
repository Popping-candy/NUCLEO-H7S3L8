#ifndef DELAY_H
#define DELAY_H

#include <stdbool.h>
#include "Std_Types.h"

/* 在 MCU 时钟配置后调用。返回 false 表示周期计数器无法启用。 */
bool Delay_Init(void);

/* 阻塞延时。零立即成功，计数器或核心时钟不可用时返回 false。
 * 延时期间保持核心频率与 DWT 配置稳定。中断可能延长返回时间。
 */
bool Delay_Us(uint32 microseconds);
bool Delay_Ms(uint32 milliseconds);

#endif
