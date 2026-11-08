#include <stddef.h>
#include "Dio.h"
#include "Dio_Drv.h"

enum { DIO_LD1_BIT = DioConf_DioChannel_LD1 % 16U };

const Dio_ChannelGroupType Dio_Ld1Group = {
    .mask = 1U << DIO_LD1_BIT,
    .offset = DIO_LD1_BIT,
    .port = (Dio_PortType)(DioConf_DioChannel_LD1 / 16U)
};

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    return Dio_DrvReadChannel(ChannelId);
}

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    Dio_DrvWriteChannel(ChannelId, Level);
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    return Dio_DrvReadPort(PortId);
}

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    Dio_DrvWritePort(PortId, Level, UINT16_MAX);
}

Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr)
{
    return Dio_DrvReadGroup(ChannelGroupIdPtr);
}

void Dio_WriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr,
                           Dio_PortLevelType Level)
{
    Dio_DrvWriteGroup(ChannelGroupIdPtr, Level);
}

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    return Dio_DrvFlipChannel(ChannelId);
}

void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level,
                         Dio_PortLevelType Mask)
{
    Dio_DrvWritePort(PortId, Level, Mask);
}

void Dio_GetVersionInfo(Std_VersionInfoType *VersionInfo)
{
    if (VersionInfo != NULL) {
        *VersionInfo = (Std_VersionInfoType){0U, DIO_MODULE_ID, 1U, 0U, 0U};
    }
}
