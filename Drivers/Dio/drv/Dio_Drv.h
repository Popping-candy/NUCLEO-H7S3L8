#ifndef DIO_DRV_H
#define DIO_DRV_H

#include "Dio.h"

Dio_LevelType Dio_DrvReadChannel(Dio_ChannelType channel);
void Dio_DrvWriteChannel(Dio_ChannelType channel, Dio_LevelType level);
Dio_PortLevelType Dio_DrvReadPort(Dio_PortType port);
void Dio_DrvWritePort(Dio_PortType port, Dio_PortLevelType level, Dio_PortLevelType mask);
Dio_PortLevelType Dio_DrvReadGroup(const Dio_ChannelGroupType *group);
void Dio_DrvWriteGroup(const Dio_ChannelGroupType *group, Dio_PortLevelType level);
Dio_LevelType Dio_DrvFlipChannel(Dio_ChannelType channel);

#endif
