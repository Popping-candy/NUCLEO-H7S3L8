#ifndef DIO_H
#define DIO_H

#include "Gpio_Pins.h"

#define DIO_MODULE_ID         120U
#define DIO_DEV_ERROR_DETECT  STD_OFF
#define DIO_VERSION_INFO_API  STD_ON
#define DIO_FLIP_CHANNEL_API  STD_ON

typedef uint16 Dio_ChannelType;
typedef uint8 Dio_PortType;
typedef uint8 Dio_LevelType;
typedef uint16 Dio_PortLevelType;

/* mask 是同一端口上连续的有效位，offset 是掩码最低有效位的位号。 */
typedef struct {
    Dio_PortLevelType mask;
    uint8 offset;
    Dio_PortType port;
} Dio_ChannelGroupType;

#define DioConf_DioPort_GPIOA ((Dio_PortType)GPIO_PORT_A)
#define DioConf_DioPort_GPIOB ((Dio_PortType)GPIO_PORT_B)
#define DioConf_DioPort_GPIOC ((Dio_PortType)GPIO_PORT_C)
#define DioConf_DioPort_GPIOD ((Dio_PortType)GPIO_PORT_D)
#define DioConf_DioPort_GPIOE ((Dio_PortType)GPIO_PORT_E)
#define DioConf_DioPort_GPIOF ((Dio_PortType)GPIO_PORT_F)
#define DioConf_DioPort_GPIOG ((Dio_PortType)GPIO_PORT_G)
#define DioConf_DioPort_GPIOH ((Dio_PortType)GPIO_PORT_H)
#define DioConf_DioPort_GPIOM ((Dio_PortType)GPIO_PORT_M)
#define DioConf_DioPort_GPION ((Dio_PortType)GPIO_PORT_N)
#define DioConf_DioPort_GPIOO ((Dio_PortType)GPIO_PORT_O)
#define DioConf_DioPort_GPIOP ((Dio_PortType)GPIO_PORT_P)

#define DioConf_DioChannel_LD1 ((Dio_ChannelType)GPIO_PIN_PD10)
#define DioConf_DioChannel_LD2 ((Dio_ChannelType)GPIO_PIN_PD13)
#define DioConf_DioChannel_LD3 ((Dio_ChannelType)GPIO_PIN_PB7)
#define DioConf_DioChannel_B2  ((Dio_ChannelType)GPIO_PIN_PC13)

extern const Dio_ChannelGroupType Dio_Ld1Group;
#define DioConf_DioChannelGroup_LD1 (&Dio_Ld1Group)

/* 通道可使用任一 GPIO_PIN_Pxx。未配置或时钟关闭时读零，写操作忽略。 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr);
void Dio_WriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr,
                           Dio_PortLevelType Level);
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level,
                         Dio_PortLevelType Mask);
void Dio_GetVersionInfo(Std_VersionInfoType *VersionInfo);

#endif
