#ifndef PORT_H
#define PORT_H

#include <stdbool.h>
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

typedef enum {
    PORT_SPEED_LOW,
    PORT_SPEED_MEDIUM,
    PORT_SPEED_HIGH,
    PORT_SPEED_VERY_HIGH
} Port_PinSpeedType;

typedef enum {
    PORT_OUTPUT_PUSH_PULL,
    PORT_OUTPUT_OPEN_DRAIN
} Port_PinOutputType;

typedef struct {
    Port_PinType pin;
    uint8 alternateFunction; /* AF0~AF15，实际映射由芯片引脚表决定。 */
    Port_PinPullType pull;
    Port_PinSpeedType speed;
    Port_PinOutputType outputType;
} Port_AlternatePinConfigType;

/* NULL 使用默认板级配置。传入自定义列表时，成功后该列表成为 Dio 的可访问集合。
 * 非法引脚、重复引脚或无效参数会拒绝整批配置。调用返回后不保存列表指针。
 */
void Port_Init(const Port_ConfigType *ConfigPtr);
void Port_RefreshPortDirection(void);
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo);

/* 批量配置复用引脚。整表校验成功才写寄存器，成功后 Dio 不再访问这些引脚。 */
bool Port_ConfigureAlternate(const Port_AlternatePinConfigType *pins, uint16 count);

#endif
