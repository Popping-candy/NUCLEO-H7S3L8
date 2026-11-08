#ifndef PORT_H
#define PORT_H

#include "Gpio_Pins.h"

#define PORT_MODULE_ID             124U
#define PORT_SET_PIN_DIRECTION_API STD_OFF
#define PORT_SET_PIN_MODE_API       STD_OFF
#define PORT_DEV_ERROR_DETECT       STD_OFF
#define PORT_VERSION_INFO_API       STD_ON

typedef uint16 Port_PinType;
typedef uint8 Port_PinModeType;
#define PORT_PIN_MODE_DIO ((Port_PinModeType)0U)

/* 板载别名只表达接线关系，通用引脚编号见 Gpio_Pins.h。 */
#define PortConf_PortPin_LD1 ((Port_PinType)GPIO_PIN_PD10)
#define PortConf_PortPin_LD2 ((Port_PinType)GPIO_PIN_PD13)
#define PortConf_PortPin_LD3 ((Port_PinType)GPIO_PIN_PB7)
#define PortConf_PortPin_B2  ((Port_PinType)GPIO_PIN_PC13)

typedef enum {
    PORT_PIN_IN = 0,
    PORT_PIN_OUT = 1
} Port_PinDirectionType;

typedef enum {
    PORT_PULL_NONE = 0,
    PORT_PULL_UP = 1,
    PORT_PULL_DOWN = 2
} Port_PinPullType;

typedef struct {
    Port_PinType pin;
    Port_PinDirectionType direction;
    Port_PinPullType pull;
    uint8 initialLevel; /* 输出初值，输入忽略。填 STD_LOW 或 STD_HIGH。 */
} Port_PinConfigType;

typedef struct Port_ConfigTag {
    const Port_PinConfigType *pins;
    uint16 count;
} Port_ConfigType;

/* NULL 使用默认板级配置。传入自定义列表时，成功后该列表成为 Dio 的可访问集合。
 * 非法引脚、重复引脚或无效参数会拒绝整批配置。调用返回后不保存列表指针。
 */
void Port_Init(const Port_ConfigType *ConfigPtr);
void Port_RefreshPortDirection(void);
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo);

#endif
