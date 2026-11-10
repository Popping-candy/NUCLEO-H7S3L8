#ifndef EFLS_H
#define EFLS_H

#include "Std_Types.h"

#define EFLS_SECTOR_SIZE 8192U
#define EFLS_WRITE_SIZE  16U
#define EFLS_REGION_SIZE EFLS_SECTOR_SIZE

typedef enum {
    EFLS_OK,
    EFLS_INVALID_ARGUMENT,
    EFLS_BUSY,
    EFLS_NOT_BLANK,
    EFLS_LOCK_FAILED,
    EFLS_CONTROLLER_ERROR,
    EFLS_TIMEOUT,
    EFLS_VERIFY_FAILED,
    EFLS_CACHE_ENABLED,
    EFLS_TIMEBASE_UNAVAILABLE
} Efls_ResultType;

/* 偏移以链接脚本保留的数据区为起点。接口用于线程上下文中的同步操作。 */
Efls_ResultType Efls_Read(uint32 offset, void *destination, uint32 length);
Efls_ResultType Efls_BlankCheck(uint32 offset, uint32 length);

/* 擦除以 8 KiB 扇区为单位。编程以 16 字节为单位，先检查目标均为擦除态。
 * 擦写需要 D-Cache 关闭。驱动启用 DWT 后按当前 SystemCoreClock 计算等待预算。
 */
Efls_ResultType Efls_Erase(uint32 offset, uint32 length);
Efls_ResultType Efls_Write(uint32 offset, const void *source, uint32 length);

/* 最近一次实际擦写操作的 FLASH_ISR 快照。 */
uint32 Efls_GetLastFlashFlags(void);

#endif
