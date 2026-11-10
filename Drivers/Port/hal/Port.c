#include <stddef.h>
#include "Port.h"
#include "Port_Drv.h"

void Port_Init(const Port_ConfigType *ConfigPtr)
{
    Port_DrvInit(ConfigPtr);
}

void Port_RefreshPortDirection(void)
{
    Port_DrvRefreshDirection();
}

void Port_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    if (versioninfo != NULL) {
        *versioninfo = (Std_VersionInfoType){0U, PORT_MODULE_ID, 1U, 0U, 0U};
    }
}

bool Port_ConfigureAlternate(const Port_AlternatePinConfigType *pins, uint16 count)
{
    return Port_DrvConfigureAlternate(pins, count);
}
