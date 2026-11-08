#include <stddef.h>
#include "Efls_Drv.h"
#include "Efls_Reg.h"

extern const uint8 __efls_start[];
extern const uint8 __FLASH_BEGIN[];

static uint32 lastFlags;

static bool Efls_InRange(uint32 offset, uint32 length)
{
    /* 先比较 offset，再做减法，避免 offset + length 溢出。 */
    return offset <= EFLS_REGION_SIZE && length <= EFLS_REGION_SIZE - offset;
}

static bool Efls_IsBlank(uintptr_t address, uint32 length)
{
    const volatile uint8 *data = (const volatile uint8 *)address;
    for (uint32 i = 0U; i < length; ++i) {
        if (data[i] != 0xFFU) {
            return false;
        }
    }
    return true;
}

Efls_ResultType Efls_DrvRead(uint32 offset, void *destination, uint32 length)
{
    if (!Efls_InRange(offset, length) || (length != 0U && destination == NULL)) {
        return EFLS_INVALID_ARGUMENT;
    }
    const uint32 state = Efls_RegEnterCritical();
    if (!Efls_RegReady()) {
        Efls_RegExitCritical(state);
        return EFLS_BUSY;
    }

    const volatile uint8 *data = (const volatile uint8 *)((uintptr_t)__efls_start + offset);
    uint8 *output = destination;
    for (uint32 i = 0U; i < length; ++i) {
        output[i] = data[i];
    }
    Efls_RegExitCritical(state);
    return EFLS_OK;
}

Efls_ResultType Efls_DrvBlankCheck(uint32 offset, uint32 length)
{
    if (!Efls_InRange(offset, length)) {
        return EFLS_INVALID_ARGUMENT;
    }
    const uint32 state = Efls_RegEnterCritical();
    Efls_ResultType result = EFLS_BUSY;
    if (Efls_RegReady()) {
        result = Efls_IsBlank((uintptr_t)__efls_start + offset, length)
                 ? EFLS_OK : EFLS_NOT_BLANK;
    }
    Efls_RegExitCritical(state);
    return result;
}

Efls_ResultType Efls_DrvErase(uint32 offset, uint32 length)
{
    if (offset != 0U || length != EFLS_SECTOR_SIZE) {
        return EFLS_INVALID_ARGUMENT;
    }
    const uint32 state = Efls_RegEnterCritical();
    Efls_ResultType result = EFLS_BUSY;
    if (Efls_RegReady()) {
        result = EFLS_CACHE_ENABLED;
        if (!Efls_RegDataCacheEnabled()) {
            const uint32 sector = ((uintptr_t)__efls_start - (uintptr_t)__FLASH_BEGIN) / EFLS_SECTOR_SIZE;
            result = Efls_RegErase(sector, &lastFlags);
            if (result == EFLS_OK && !Efls_IsBlank((uintptr_t)__efls_start, length)) {
                result = EFLS_VERIFY_FAILED;
            }
        }
    }
    Efls_RegExitCritical(state);
    return result;
}

Efls_ResultType Efls_DrvWrite(uint32 offset, const void *source, uint32 length)
{
    if (!Efls_InRange(offset, length) || length == 0U || source == NULL ||
        offset % EFLS_WRITE_SIZE != 0U || length % EFLS_WRITE_SIZE != 0U) {
        return EFLS_INVALID_ARGUMENT;
    }
    const uintptr_t base = (uintptr_t)__efls_start;
    const uintptr_t srcAddress = (uintptr_t)source;
    if (srcAddress < base + EFLS_REGION_SIZE &&
        (srcAddress >= base || base - srcAddress < length)) {
        return EFLS_INVALID_ARGUMENT;
    }

    const uint32 state = Efls_RegEnterCritical();
    const uintptr_t address = base + offset;
    Efls_ResultType result = EFLS_OK;
    if (!Efls_RegReady()) {
        result = EFLS_BUSY;
    } else if (Efls_RegDataCacheEnabled()) {
        result = EFLS_CACHE_ENABLED;
    } else if (!Efls_IsBlank(address, length)) {
        /* ECC 按 16 字节更新，拒绝对已写入的 Flash word 二次编程。 */
        result = EFLS_NOT_BLANK;
    }

    const uint8 *bytes = source;
    for (uint32 i = 0U; result == EFLS_OK && i < length; i += EFLS_WRITE_SIZE) {
        uint16 words[EFLS_WRITE_SIZE / sizeof(uint16)];
        bool allOnes = true;
        for (uint32 j = 0U; j < EFLS_WRITE_SIZE; j += 2U) {
            words[j / 2U] = (uint16)((uint16)bytes[i + j] | ((uint16)bytes[i + j + 1U] << 8U));
            allOnes = allOnes && words[j / 2U] == UINT16_MAX;
        }
        /* 全 FF 的块保留擦除态，避免写入没有可见变化的 ECC 数据。 */
        if (!allOnes) {
            result = Efls_RegProgram(address + i, words, &lastFlags);
        }
        if (result == EFLS_OK) {
            const volatile uint8 *written = (const volatile uint8 *)(address + i);
            for (uint32 j = 0U; j < EFLS_WRITE_SIZE; ++j) {
                if (written[j] != bytes[i + j]) {
                    result = EFLS_VERIFY_FAILED;
                    break;
                }
            }
        }
    }

    Efls_RegExitCritical(state);
    return result;
}

uint32 Efls_DrvLastFlags(void)
{
    return lastFlags;
}
