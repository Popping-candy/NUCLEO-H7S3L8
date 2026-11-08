#include "Dio_Drv.h"
#include "Gpio_Reg.h"
#include "Port_Drv.h"

static bool Dio_GroupValid(const Dio_ChannelGroupType *group)
{
    if (group == NULL || group->offset >= 16U || group->mask == 0U ||
        (group->mask & Gpio_PackageMask(group->port)) != group->mask) {
        return false;
    }

    /* 移到 bit 0 后应是一串连续的 1。另查左移还原，防止丢掉低位。 */
    const uint32 aligned = (uint32)group->mask >> group->offset;
    return (aligned & 1U) != 0U && (aligned & (aligned + 1U)) == 0U &&
           (aligned << group->offset) == group->mask;
}

Dio_PortLevelType Dio_DrvReadPort(Dio_PortType port)
{
    if (Gpio_PackageMask(port) == 0U) {
        return 0U;
    }

    const uint32 lock = Gpio_RegLock();
    const uint16 selected = Port_DrvConfiguredPins(port);
    /* IDR 读的是实际采样电平，输出引脚也用这一寄存器回读。 */
    const uint16 level = selected != 0U && Gpio_RegClockEnabled(port)
                         ? Gpio_RegReadInputs(port) & selected : 0U;
    Gpio_RegUnlock(lock);
    return level;
}

void Dio_DrvWritePort(Dio_PortType port, Dio_PortLevelType level, Dio_PortLevelType mask)
{
    if (Gpio_PackageMask(port) == 0U) {
        return;
    }

    const uint32 lock = Gpio_RegLock();
    /* 同一份 Port 配置决定输出权限，掩码写入不影响输入或未登记引脚。 */
    const uint16 selected = mask & Port_DrvOutputPins(port);
    if (selected != 0U && Gpio_RegClockEnabled(port)) {
        Gpio_RegWriteOutputs(port, selected, level);
    }
    Gpio_RegUnlock(lock);
}

Dio_LevelType Dio_DrvReadChannel(Dio_ChannelType channel)
{
    if (!Gpio_PinExists(channel)) {
        return STD_LOW;
    }

    return (Dio_DrvReadPort(Gpio_PinPort(channel)) & Gpio_PinBit(channel)) != 0U
           ? STD_HIGH : STD_LOW;
}

void Dio_DrvWriteChannel(Dio_ChannelType channel, Dio_LevelType level)
{
    if (Gpio_PinExists(channel) && (level == STD_LOW || level == STD_HIGH)) {
        const uint16 bit = Gpio_PinBit(channel);
        Dio_DrvWritePort(Gpio_PinPort(channel), level == STD_HIGH ? bit : 0U, bit);
    }
}

Dio_PortLevelType Dio_DrvReadGroup(const Dio_ChannelGroupType *group)
{
    if (!Dio_GroupValid(group)) {
        return 0U;
    }

    return (Dio_DrvReadPort(group->port) & group->mask) >> group->offset;
}

void Dio_DrvWriteGroup(const Dio_ChannelGroupType *group, Dio_PortLevelType level)
{
    if (Dio_GroupValid(group)) {
        const uint16 shifted = (uint16)((uint32)level << group->offset);
        Dio_DrvWritePort(group->port, shifted, group->mask);
    }
}

Dio_LevelType Dio_DrvFlipChannel(Dio_ChannelType channel)
{
    if (!Gpio_PinExists(channel)) {
        return STD_LOW;
    }

    const uint8 port = Gpio_PinPort(channel);
    const uint16 bit = Gpio_PinBit(channel);
    const uint32 lock = Gpio_RegLock();
    Dio_LevelType level = STD_LOW;
    if ((Port_DrvConfiguredPins(port) & bit) != 0U && Gpio_RegClockEnabled(port)) {
        level = (Gpio_RegReadInputs(port) & bit) != 0U ? STD_HIGH : STD_LOW;
        /* 输入只返回采样值。输出的读、取反、写操作共用一个临界区。 */
        if ((Port_DrvOutputPins(port) & bit) != 0U) {
            level = (Dio_LevelType)(level == STD_HIGH ? STD_LOW : STD_HIGH);
            Gpio_RegWriteOutputs(port, bit, level == STD_HIGH ? bit : 0U);
        }
    }
    Gpio_RegUnlock(lock);
    return level;
}
