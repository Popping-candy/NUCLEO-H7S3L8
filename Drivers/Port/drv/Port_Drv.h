#ifndef PORT_DRV_H
#define PORT_DRV_H

#include "Port.h"

void Port_DrvInit(const Port_ConfigType *config);
void Port_DrvRefreshDirection(void);

/* Dio 在 GPIO 临界区中读取这些掩码。调用方须先验证端口号。 */
uint16 Port_DrvConfiguredPins(uint8 port);
uint16 Port_DrvOutputPins(uint8 port);

bool Port_DrvConfigureAlternate(const Port_AlternatePinConfigType *pins, uint16 count);

#endif
