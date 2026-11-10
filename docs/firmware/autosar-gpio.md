# Port / Dio 驱动与全封装 GPIO

[开发笔记](../README.md) · [工程文件](project-layout.md) · [GPIO 寄存器分表](../reference/registers/gpio.md)

Port 配置引脚方向、上下拉和输出初值。Dio 通过同一份配置读取数字电平，并限制写入范围。公开函数沿用项目现有的 AUTOSAR Classic Port / Dio 接口，默认配置对应 MB1737 B02。自定义配置结构为本项目定义。 [Port SWS](https://www.autosar.org/fileadmin/standards/R25-11/CP/AUTOSAR_CP_SWS_PortDriver.pdf) · [Dio SWS](https://www.autosar.org/fileadmin/standards/R25-11/CP/AUTOSAR_CP_SWS_DIODriver.pdf)

## 从接口读到寄存器

| 层 | 文件 | 职责 |
| --- | --- | --- |
| HAL | [Port.h](../../Drivers/Port/hal/Port.h) · [Dio.h](../../Drivers/Dio/hal/Dio.h) | 应用包含这两个头文件。HAL 在本工程中指对外接口层。 |
| DRV | [Port_Drv.c](../../Drivers/Port/drv/Port_Drv.c) · [Dio_Drv.c](../../Drivers/Dio/drv/Dio_Drv.c) | Port 校验并应用引脚配置。Dio 根据配置生成通道、端口和组的访问掩码。 |
| REG | [Gpio_Reg.h](../../Drivers/Gpio/reg/Gpio_Reg.h) | Port 与 Dio 共用同一组 GPIO/RCC 寄存器访问函数，包含 MODER 位操作、IDR 读取、BSRR 单次写入和临界区。 |
| 芯片配置 | [Gpio_Pins.h](../../Drivers/Gpio/Gpio_Pins.h) · [Gpio_Pins.c](../../Drivers/Gpio/Gpio_Pins.c) | GPIO 编号、封装球位与有效引脚掩码。 |

[main.c](../../Src/main.c) 调用 Port_Init(NULL)，驱动先使能时钟，再把三个 LED 的输出锁存值设为低，最后写 MODER 切换到输出。应用随后通过 Dio 依次写 PD10、PD13 和 PB7 的 BSRR，演示三颗灯的逐个亮灭。

| 默认通道 | 引脚 | 方向与初值 |
| --- | --- | --- |
| DioConf_DioChannel_LD1 | PD10 | 推挽输出，初始低，写 STD_HIGH 点亮 |
| DioConf_DioChannel_LD2 | PD13 | 推挽输出，初始低，写 STD_HIGH 点亮 |
| DioConf_DioChannel_LD3 | PB7 | 推挽输出，初始低，写 STD_HIGH 点亮 |
| DioConf_DioChannel_B2 | PC13 | 上拉输入，按下读 STD_LOW |

## 使用其他引脚

选择 Gpio_Pins.h 中的 GPIO_PIN_Pxx，再把引脚、方向、上下拉和输出初值放入 Port_PinConfigType 数组。将数组和条目数放进 Port_ConfigType，传给 Port_Init。初始化后，Dio_ReadChannel 和 Dio_WriteChannel 可直接使用该 GPIO_PIN_Pxx。端口 API 使用对应的 DioConf_DioPort_GPIOx。通道组由端口号、连续位掩码和最低位偏移组成。

自定义列表成为本次初始化的有效集合。需要同时使用默认灯和按键时，也把它们写入列表。整表校验通过后才访问寄存器。未列出的引脚保持原硬件状态，Dio 对其读零、写入忽略。Port_RefreshPortDirection 只恢复有效集合的 MODER 输入或输出位，不重载输出电平。Dio 读 IDR 采样电平，端口、组和掩码写入只更新已配置为输出的位。

## 配置外设复用

`Port_ConfigureAlternate()` 接收 `Port_AlternatePinConfigType` 数组。每项给出封装引脚、AF 编号、上下拉、输出速度和推挽或开漏。驱动校验引脚存在、参数范围和重复项。AF 对应哪个外设由芯片复用表决定，调用方需核对。配置成功的引脚从 Dio 掩码移除，`Port_RefreshPortDirection()` 跳过这些引脚。板载 VCP 的 PD8/PD9 是已验证的例子。 [USART3 复用实测](uart.md)

## 封装与板级边界

STM32H7S3L8H6 的 TFBGA225 OCTO SMPS 封装数据列出 12 个端口、152 个带 GPIO 功能的球位，计入可复用的 PH0 和 PH1。端口 A～G 各有 16 位，H、M、N、O、P 按封装掩码校验。封装球位与板上可用连接是两回事。手动配置前检查该脚是否接到了晶振、SWD、外部存储或板载外设，并核对 I/O 供电域。默认配置只初始化表中的四个引脚。 [ST 封装数据](https://github.com/STMicroelectronics/STM32_open_pin_data/blob/master/mcu/STM32H7S3L8Hx.xml) · [DS14359 数据手册](https://www.st.com/resource/en/datasheet/stm32h7s3l8.pdf) · [板卡硬件](../board/hardware.md)

普通 GPIO 配置支持数字输入和低速推挽输出。Port_SetPinMode、Port_SetPinDirection、DET、MemMap 与 ECUC 生成未接入，vendor ID 仍使用本地占位值 0。
