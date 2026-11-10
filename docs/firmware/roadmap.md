# 外设与存储开发路线图

[开发笔记](../README.md) · [板级接线](../board/peripherals-io.md) · [内存与存储](memory-storage.md)

USART3 调试串口已上板验证。下一阶段先做 XSPI 与 Fls，再接常用通信 I/O。外存与其他总线可以复用现有串口记录错误和超时。

| 阶段 | 模块 | 第一版范围 | 验收条件 |
| --- | --- | --- | --- |
| 1 · [已完成](uart.md) | Port 复用、Mcu 外设时钟、Uart | Port 支持指定 AF、输出类型、速度和上下拉。Mcu 明确 USART3 内核时钟。Uart 先做阻塞发送、接收和超时，使用 PD8/PD9 及 ST-LINK VCP。 | 115200 8N1 能输出启动信息并做字节回显。分别验证默认 PLL 档和 HSI 档。 |
| 2 | Xspi、Fls | Xspi 管控制器与传输，Fls 管板载 MX25UW25645G 的指令、容量、擦除、页边界和状态轮询。首版用间接命令模式，先读 JEDEC ID/SFDP，再读外存。 | 与官方 loader 对读同一段数据。根据全片转储确认实验扇区，备份后擦除、跨页编程、读回校验，复位后重读。保留旧 XIP 镜像及已有数据。 |
| 3 | I2c、Spi、Icu、Gpt | I2c 和 Spi 先做主机轮询收发。Icu 先用 B2 验证 EXTI 输入事件。Gpt 提供可复用的超时和周期事件。需要持续收发的通道再接中断与 Dma。 | I2c 读器件标识并处理 NACK，Spi 通过回环或读取器件 ID 验证时序，B2 触发事件，定时周期可测。 |
| 4 | Can、Eth、Usb | Can 从 FDCAN 内部回环开始，再接外置收发器做双节点通信。Eth 先读 PHY ID、检查链路，再接网络栈。Usb 先做用户 USB 口的设备枚举和 CDC。 | CAN 双节点互发、网口能收发数据、用户 USB 能枚举和回显。以太网与 DMA 一起验证缓冲区和 Cache 一致性。 |
| 5 | Fls 映射、Boot / App | 间接模式稳定后加入只读内存映射，再分离 Boot 和 App，根据应用规模选 XIP 或 LRUN。 | 冷启动能进入正确应用，验证镜像边界、VTOR 和启动失败处理。 |

## 模块边界

- Port 统一管理引脚电气配置和 AF。Dio 继续负责数字电平。当前已验证 USART3 所需的复用配置。接入板载 NOR 前核对 SWD、晶振和其他板载外设占用。
- Uart、I2c、Spi 和 Xspi 沿用 HAL、DRV、REG 分层。轮询版本先建立统一的超时和错误返回约定。时钟门控及内核时钟来源通过 Mcu 查询，驱动按实际时钟计算时序。
- Efls 管片内末尾 8 KiB，Fls 管板载 32 MiB NOR。两者可以用相似的读、写、擦除接口名称，但各自检查地址范围、对齐和擦写粒度。Xspi 负责总线事务。CubeProgrammer 的外部 loader 用于主机烧录和对读，运行时初始化由本项目的驱动完成。
- Adc、Pwm、Wdg、Rtc 和 SDMMC 按应用需要加入。可用板载 B2、LED 和现有串口建立最小验收，再接外部设备。

## 板卡依据

USART3 的 PD8/PD9 默认连到 ST-LINK VCP，CN5 用于调试和串口。板载 NOR 已在 0x70000000 经官方 loader 完整读回，旧镜像保存在转储中。用户 USB 口为 CN2。FDCAN 双节点实验需要外置收发器和正确的终端。 [UM3276](https://www.st.com/resource/en/user_manual/um3276-stm32h7rx7sx-nucleo144-board-mb1737-stmicroelectronics.pdf) · [ST MX25UW25645G 组件](https://github.com/STMicroelectronics/stm32-mx25uw25645g) · [Efls 与旧镜像记录](efls.md)
