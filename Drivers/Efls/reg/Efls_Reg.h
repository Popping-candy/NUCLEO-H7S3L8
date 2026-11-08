#ifndef EFLS_REG_H
#define EFLS_REG_H

#include <stdbool.h>
#include "Efls.h"

bool Efls_RegReady(void);
bool Efls_RegDataCacheEnabled(void);
Efls_ResultType Efls_RegErase(uint32 sector, uint32 *flags);
Efls_ResultType Efls_RegProgram(uintptr_t address, const uint16 *words, uint32 *flags);

static inline uint32 Efls_RegEnterCritical(void)
{
    uint32 state;
    __asm volatile ("mrs %0, primask\n\tcpsid i" : "=r"(state) : : "memory");
    return state;
}

static inline void Efls_RegExitCritical(uint32 state)
{
    __asm volatile ("msr primask, %0" : : "r"(state) : "memory");
}

#endif
