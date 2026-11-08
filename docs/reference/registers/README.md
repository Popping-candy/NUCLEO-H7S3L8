# STM32H7S3L8 外设寄存器表

[返回开发笔记](../../README.md) · [官方资料](../references.md)

目标为 NUCLEO-H7S3L8 上的 STM32H7S3L8H6。共 **105 个 SVD 外设块、15 个 CMSIS 补充视图、6,020 条寄存器记录、25,387 条位域记录**。记录数包含重复实例和不同工作模式的寄存器别名。

## 如何查

- 先按下表进入对应分类，再按外设实例或地址搜索。例如 [GPIOD](gpio.md#gpiod)、[RCC](system.md#rcc) 的 RCC_AHB4ENR（0x58024540）。
- 绝对地址等于实例基地址加偏移。FIELD[msb:lsb] 表示位范围，单个数字表示一位。mask 表示不连续的位掩码。同类不同实例各自列出。
- RW、RO、WO 分别表示读写、只读、只写，RW1 / WO1 表示只允许写一次。— 表示数据源未标注。复位掩码中的 1 表示复位值适用的位；掩码为 0 时不要据表推断复位状态。
- 同地址的别名或模式视图保留。I2C1 和 I3C1 共用地址，按实际选择的外设模式解读。读副作用仅列出 SVD 已标注的项目。
- 以 SVD 的寄存器和位域清单为基础，并补入芯片头文件中的寄存器视图。补表的复位值、精确访问类型及部分位域可能缺失。写一清零、保留位、时序及依赖条件按 RM0477 和 ES0596 核对。
- 范围为片上外设寄存器。内核专用寄存器、板外器件和 PKA 工作 RAM 等内存窗口另查原文。定时器、DMA 通道和 USB 端点按 SVD 的实例定义列出。AXI 互连端口的实例差异见 RM0477 的 AXI interconnect register map。

## 中文注释

- 每个实例标题下有模块用途。每张分表开头解释表格字段，寄存器行另有「中文用途」列。
- 位域沿用 ST 的英文标识与位号，中文短注写在全角括号中。标有「待核」的项目需按原始寄存器名查 RM0477，尤其是 SVD 描述缺失或芯片头文件补充的视图。
- 中文短注用于快速理解字段职责。写入值编码、清除方式和允许访问的时机按原文对应寄存器节核对。

## 分类

| 分类 | 实例/视图 | 寄存器 |
| --- | ---: | ---: |
| [系统、时钟、电源与调试](system.md) | 5 | 122 |
| [GPIO 与外部中断](gpio.md) | 13 | 146 |
| [定时器、RTC 与看门狗](timers.md) | 24 | 362 |
| [模拟采样与参考电压](analog.md) | 5 | 76 |
| [串行通信、CAN 与音频](serial.md) | 27 | 405 |
| [以太网、USB 与 Type-C](network-usb.md) | 7 | 693 |
| [存储、缓存与 DMA](memory-dma.md) | 20 | 623 |
| [安全、加密与数学运算](crypto.md) | 10 | 345 |
| [图像、显示与并行接口](graphics.md) | 9 | 3,248 |

## 数据版本与核对

- ST 产品页列出的 STM32H7RS SVD v1.3。下载入口返回错误时采用公开镜像的 STM32H7S.svd。文件 SHA-256 为 `45d37a14a56554062060ce26552084200642102fd7fc3828557fb44948851d92`。 [ST 产品资料](https://www.st.com/en/microcontrollers-microprocessors/stm32h7s3l8.html#documentation) · [SVD 镜像](https://raw.githubusercontent.com/modm-io/cmsis-svd-stm32/main/stm32h7rs/STM32H7S.svd)
- 补表取自 ST 的 stm32h7s3xx.h。文件 SHA-256 为 `9782bcee34f7e8425e46cc30c33d3107f857c3c5da1581c432da9855670362d1`。 [ST 芯片头文件](https://github.com/STMicroelectronics/cmsis-device-h7rs/blob/main/Include/stm32h7s3xx.h)
- 地址交叉核对中，ADC12 公共块的 SVD 偏移改为相对该块基址，EXTI 的触发及屏蔽相关偏移和 DBGMCU_AHB5FZR 按芯片头文件取值。
- FDCAN_CKDIV 为公共时钟分频寄存器，列在 FDCAN1 地址下，移除 FDCAN2 从 SVD 继承的同名条目。 [ST HAL FDCAN 实现](https://github.com/STMicroelectronics/stm32h7rsxx-hal-driver/blob/main/Src/stm32h7rsxx_hal_fdcan.c#L380)
- 访问顺序、位域用途和芯片勘误请查 [RM0477](https://www.st.com/resource/en/reference_manual/rm0477-stm32h7rx7sx-armbased-32bit-mcus-stmicroelectronics.pdf) · [ES0596](https://www.st.com/resource/en/errata_sheet/es0596-stm32h7rxx7sxx-device-errata-stmicroelectronics.pdf)。
