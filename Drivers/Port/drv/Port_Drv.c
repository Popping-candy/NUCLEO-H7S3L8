#include "Port_Drv.h"
#include "Gpio_Reg.h"

/* MB1737 B02 默认焊桥。仅初始化显式列出的引脚，保留 SWD、晶振和板载外设。 */
static const Port_PinConfigType defaultPins[] = {
    {PortConf_PortPin_LD1, PORT_PIN_OUT, PORT_PULL_NONE, STD_LOW},
    {PortConf_PortPin_LD2, PORT_PIN_OUT, PORT_PULL_NONE, STD_LOW},
    {PortConf_PortPin_LD3, PORT_PIN_OUT, PORT_PULL_NONE, STD_LOW},
    {PortConf_PortPin_B2,  PORT_PIN_IN,  PORT_PULL_UP,   STD_LOW}
};

static const Port_ConfigType defaultConfig = {
    defaultPins, sizeof defaultPins / sizeof defaultPins[0]
};

static uint16 configuredPins[GPIO_PORT_SLOTS];
static uint16 outputPins[GPIO_PORT_SLOTS];

void Port_DrvInit(const Port_ConfigType *config)
{
    if (config == NULL) {
        config = &defaultConfig;
    }
    if (config->pins == NULL || config->count == 0U || config->count > GPIO_PIN_COUNT) {
        return;
    }

    uint16 selected[GPIO_PORT_SLOTS] = {0};
    uint16 outputs[GPIO_PORT_SLOTS] = {0};

    /* 先校验整张配置表，确保无效条目不会导致 GPIO 只改了一半。 */
    for (uint16 i = 0U; i < config->count; ++i) {
        const Port_PinConfigType *pin = &config->pins[i];
        if (!Gpio_PinExists(pin->pin) ||
            (pin->direction != PORT_PIN_IN && pin->direction != PORT_PIN_OUT) ||
            (unsigned int)pin->pull > PORT_PULL_DOWN ||
            (pin->direction == PORT_PIN_OUT && pin->initialLevel > STD_HIGH)) {
            return;
        }

        const uint8 port = Gpio_PinPort(pin->pin);
        const uint16 bit = Gpio_PinBit(pin->pin);
        if ((selected[port] & bit) != 0U) {
            return;
        }
        selected[port] |= bit;
        if (pin->direction == PORT_PIN_OUT) {
            outputs[port] |= bit;
        }
    }

    const uint32 lock = Gpio_RegLock();
    for (uint8 port = 0U; port < GPIO_PORT_SLOTS; ++port) {
        if (selected[port] != 0U) {
            Gpio_RegEnableClock(port);
        }
    }
    for (uint16 i = 0U; i < config->count; ++i) {
        const Port_PinConfigType *pin = &config->pins[i];
        Gpio_RegConfigure(Gpio_PinPort(pin->pin), Gpio_PinIndex(pin->pin),
                          pin->direction == PORT_PIN_OUT, (uint8)pin->pull,
                          pin->initialLevel == STD_HIGH);
    }
    for (uint8 port = 0U; port < GPIO_PORT_SLOTS; ++port) {
        configuredPins[port] = selected[port];
        outputPins[port] = outputs[port];
    }
    Gpio_RegUnlock(lock);
}

void Port_DrvRefreshDirection(void)
{
    const uint32 lock = Gpio_RegLock();
    for (uint8 port = 0U; port < GPIO_PORT_SLOTS; ++port) {
        if (configuredPins[port] == 0U || !Gpio_RegClockEnabled(port)) {
            continue;
        }
        for (uint8 pin = 0U; pin < 16U; ++pin) {
            const uint16 bit = (uint16)(1UL << pin);
            if ((configuredPins[port] & bit) != 0U) {
                /* 刷新只恢复 MODER，不重置输出电平或上下拉。 */
                Gpio_RegSetDirection(port, pin, (outputPins[port] & bit) != 0U);
            }
        }
    }
    Gpio_RegUnlock(lock);
}

uint16 Port_DrvConfiguredPins(uint8 port)
{
    return configuredPins[port];
}

uint16 Port_DrvOutputPins(uint8 port)
{
    return outputPins[port];
}

bool Port_DrvConfigureAlternate(const Port_AlternatePinConfigType *pins, uint16 count)
{
    if (pins == NULL || count == 0U || count > GPIO_PIN_COUNT) {
        return false;
    }

    uint16 selected[GPIO_PORT_SLOTS] = {0};
    for (uint16 i = 0U; i < count; ++i) {
        const Port_AlternatePinConfigType *pin = &pins[i];
        if (!Gpio_PinExists(pin->pin) || pin->alternateFunction > 15U ||
            (unsigned int)pin->pull > PORT_PULL_DOWN ||
            (unsigned int)pin->speed > PORT_SPEED_VERY_HIGH ||
            (unsigned int)pin->outputType > PORT_OUTPUT_OPEN_DRAIN) {
            return false;
        }

        const uint8 port = Gpio_PinPort(pin->pin);
        const uint16 bit = Gpio_PinBit(pin->pin);
        if ((selected[port] & bit) != 0U) {
            return false;
        }
        selected[port] |= bit;
    }

    const uint32 lock = Gpio_RegLock();
    for (uint8 port = 0U; port < GPIO_PORT_SLOTS; ++port) {
        if (selected[port] != 0U) {
            Gpio_RegEnableClock(port);
            /* 复用引脚交给外设，Dio 和方向刷新都跳过它们。 */
            configuredPins[port] &= (uint16)~selected[port];
            outputPins[port] &= (uint16)~selected[port];
        }
    }
    for (uint16 i = 0U; i < count; ++i) {
        const Port_AlternatePinConfigType *pin = &pins[i];
        Gpio_RegConfigureAlternate(Gpio_PinPort(pin->pin), Gpio_PinIndex(pin->pin),
                                   pin->alternateFunction, (uint8)pin->pull, (uint8)pin->speed,
                                   pin->outputType == PORT_OUTPUT_OPEN_DRAIN);
    }
    Gpio_RegUnlock(lock);
    return true;
}
