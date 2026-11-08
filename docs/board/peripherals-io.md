# 外设与 I/O

[返回首页](../../README.md) · [硬件引脚](hardware.md) · [内存与存储](../firmware/memory-storage.md)

板级连线查 UM3276/B02 原理图，复用功能和电气限制查 DS14359，时钟、寄存器、DMA 请求和中断查 RM0477，已知限制查 ES0596。引脚以实际工程配置和接线记录为准。使用 CubeMX 时一并核对 `.ioc`。 [资料入口](../reference/references.md) · [ST 板卡示例](https://github.com/STMicroelectronics/STM32CubeH7RS/tree/main/Projects/NUCLEO-H7S3L8/Examples)

## GPIO 入门与 LD1 点灯

GPIO 是通用输入／输出。以 `PD10` 为例，`D` 是端口组，`10` 是该组的引脚编号。固件通过 GPIOD 的配置寄存器选择这个引脚的用途。高、低电平是相对 GND 的电压，默认 3.3 V 配置下，推挽输出的高电平通常接近 3.3 V，低电平接近 0 V。数字输入则按芯片阈值把电压判成 0 或 1。 [ST GPIO 配置说明 AN4899](https://www.st.com/resource/en/application_note/dm00315319-stm32-gpio-configuration-for-hardware-settings-and-low-power-consumption-stmicroelectronics.pdf)

| 模式或设置 | 初学时怎么理解 |
| --- | --- |
| 输入 | MCU 读取外部电平，例如读 B2。内部上拉或下拉可在外部没有驱动时提供默认状态，避免悬空 |
| 推挽输出 | MCU 主动驱动高和低电平。适合本板 LD1 |
| 开漏输出 | 只主动拉低，释放时通常由外部上拉提供高电平。常见于 I²C |
| 复用功能（AF） | 由 UART、SPI、定时器等片上外设使用该引脚 |
| 模拟 | 用于 ADC 等模拟功能，或按器件要求关闭数字路径 |
| 输出速度 | 影响电平转换的快慢。点灯用低速，闪烁周期由程序延时或定时器决定 |

### 为什么 PD10 写 1 会亮

默认焊桥下，目标 MCU 的 PD10 控制板上的三极管。PD10 输出高电平时，三极管导通，形成 `板上 3V3 → 限流电阻和 LD1 → 三极管 → GND` 的电流路径。输出低电平时，三极管截止，LD1 熄灭。这个实验只需用 CN5 给板子供电并烧录，LD1 电路已经接在板上。LD5 绿色电源灯由板上 5 V 电源轨驱动，观察点灯结果时认准丝印 **LD1**。 [板载灯和焊桥](hardware.md#共有多少指示灯) · [UM3276 §7.5](https://www.st.com/resource/en/user_manual/um3276-stm32h7rx7sx-nucleo144-board-mb1737-stmicroelectronics.pdf#page=21)

### 从常亮到闪烁

1. **开端口时钟。** 在 RCC 中使能 GPIOD 的外设时钟，GPIO 配置才能正常生效。
2. **配置引脚。** 将 PD10 配置为 GPIO 推挽输出、低速、无内部上下拉。可以先把输出锁存值设为低，再切到输出模式，使初始状态为灭。
3. **先让灯常亮。** 把 PD10 写高，保持主循环运行。构建并烧录 Debug ELF，退出暂停状态后观察 LD1。用寄存器时，`MODER` 管方向和模式，`OTYPER` 选推挽或开漏，`BSRR` 可设高或清低某个输出位。 [RM0477 GPIO 章节](https://www.st.com/resource/en/reference_manual/rm0477-stm32h7rx7sx-armbased-32bit-mcus-stmicroelectronics.pdf)
4. **再做闪烁。** 循环执行「PD10 写高 → 等 500 ms → PD10 写低 → 等 500 ms」。亮灭各 500 ms，完整周期约 1 s。现有工程尚未引入 HAL，`HAL_Delay()` 只有在引入 HAL 并完成时基初始化后才可用。想要稳定的 500 ms，可以用 SysTick 或定时器提供时间基准。 [当前工程与构建方式](../firmware/project-layout.md)
5. **灯不亮时从外到内查。** 先确认 CN5、LD5 和跳线，再确认调试器已经继续运行到写 GPIO 之后。接着查 GPIOD 时钟、PD10 模式和输出锁存值，最后核对 LD1 的默认 SB50/SB49 接法。

上面的寄存器实验可用于理解点灯原理。当前 `main()` 通过 [Port / Dio](../firmware/autosar-gpio.md) 调用驱动，已在实板核对三灯的切换顺序。 [上板检查与调试](../firmware/bringup-debug.md#第一次上板)

### 寄存器级实验：让 PD10 输出高电平

这是 STM32H7S3L8 的片内裸机示例。RCC 基地址是 `0x58024400`，其 `AHB4ENR` 偏移是 `0x140`，所以实际地址是 **`0x58024540`**。GPIOD 基地址是 `0x58020C00`。先使能时钟，再配置输出特性和初始状态，最后切换模式和点亮。 [ST 芯片头文件](https://github.com/STMicroelectronics/cmsis-device-h7rs/blob/main/Include/stm32h7s3xx.h) · [ST GPIOD 时钟使能实现](https://github.com/STMicroelectronics/stm32h7rsxx-hal-driver/blob/main/Inc/stm32h7rsxx_hal_rcc.h#L984)

| 顺序 | 寄存器（32 位地址） | 要修改的位 | 写法与作用 |
| --- | --- | --- | --- |
| 1 | `RCC_AHB4ENR`（`0x58024540`） | bit 3，`GPIODEN` | 置 1 并回读该寄存器，启用 GPIOD |
| 2 | `GPIOD_OTYPER`（`0x58020C04`） | bit 10 | 清 0，选推挽 |
| 3 | `GPIOD_OSPEEDR`（`0x58020C08`） | bits [21:20] | 写 `00`，选低速 |
| 4 | `GPIOD_PUPDR`（`0x58020C0C`） | bits [21:20] | 写 `00`，关内部上下拉 |
| 5 | `GPIOD_BSRR`（`0x58020C18`） | bit 26，`BR10` | 直接写 `0x04000000`，把输出锁存值预置为低 |
| 6 | `GPIOD_MODER`（`0x58020C00`） | bits [21:20] | 写 `01`，把 PD10 切为 GPIO 输出 |
| 7 | `GPIOD_BSRR`（`0x58020C18`） | bit 10，`BS10` | 直接写 `0x00000400`，拉高 PD10，LD1 亮 |

`MODER`、`OSPEEDR` 和 `PUPDR` 每个引脚用两位，所以 PD10 从第 `2 × 10 = 20` 位起。修改这些寄存器时先读出旧值，用掩码只改 PD10 对应的位。**`BSRR` 是写入动作**，低半区的 bit 10 置位 PD10，高半区的 bit `16 + 10 = 26` 清位 PD10。用 `=` 直接写掩码。

下面这段只依赖标准头文件，可以作为当前裸机 `main.c` 的完整点灯示例。 `volatile` 让编译器保留对硬件地址的读写。

```c
#include <stdint.h>

#define REG32(address) (*(volatile uint32_t *)(uintptr_t)(address))

#define RCC_AHB4ENR    REG32(0x58024540UL)
#define GPIOD_MODER    REG32(0x58020C00UL)
#define GPIOD_OTYPER   REG32(0x58020C04UL)
#define GPIOD_OSPEEDR  REG32(0x58020C08UL)
#define GPIOD_PUPDR    REG32(0x58020C0CUL)
#define GPIOD_BSRR     REG32(0x58020C18UL)

int main(void)
{
    const uint32_t pin_mask = 1U << 10;
    const uint32_t field_shift = 2U * 10U;
    const uint32_t field_mask = 3U << field_shift;

    RCC_AHB4ENR |= 1U << 3;        // GPIOD 时钟
    (void)RCC_AHB4ENR;            // 回读，让时钟使能生效

    GPIOD_OTYPER  &= ~pin_mask;   // 推挽
    GPIOD_OSPEEDR &= ~field_mask; // 低速
    GPIOD_PUPDR   &= ~field_mask; // 无上下拉
    GPIOD_BSRR = pin_mask << 16;  // 预置输出为低，LD1 初始熄灭
    GPIOD_MODER = (GPIOD_MODER & ~field_mask) | (1U << field_shift);

    GPIOD_BSRR = pin_mask;        // PD10 输出高，LD1 常亮

    for (;;) {
    }
}
```

验证时先运行到最后的 `GPIOD_BSRR` 写入之后。调试器可看 `GPIOD_ODR`（`0x58020C14`）bit 10 为 1，表示软件要求输出高。也可看 `GPIOD_IDR`（`0x58020C10`）bit 10，检查实际采样到的引脚电平。关灯时向 `BSRR` 写 `0x04000000`。闪烁就是在两次写入之间加入延时。 [RM0477 的 RCC 与 GPIO 章节](https://www.st.com/resource/en/reference_manual/rm0477-stm32h7rx7sx-armbased-32bit-mcus-stmicroelectronics.pdf)

## 外设配置速查

| 模块 | 配置与接线 | 如何验证 |
| --- | --- | --- |
| GPIO 输出 | PD10 推挽输出驱动 LD1，先确认时钟和有效电平。GPIO speed 控制边沿，按信号需要设置 | 用固定周期闪灯。排针输出可用示波器验证电平和周期 |
| GPIO 输入 / EXTI | PC13 对应 B2，按下为低。先轮询确认电平，再配下降沿、EXTI/NVIC 和消抖 | 每次按键只累计一次事件。中断中记录标志，主循环打印 |
| UART / USART | VCP 用 USART3 PD8/PD9。外接 TTL 串口时 TX↔RX、共地、核对电平 | 先用阻塞发送，再做接收回显。最后加中断或 DMA、超时与丢包计数 |
| I²C / I3C | CN7 上 PB8/PB9 可作 I²C1，开漏、外部上拉。I3C 另查可用实例和引脚，按目标器件配置 | 从 100 kHz I²C 起步，读器件 ID。观察地址、ACK、重复起始和上升时间 |
| SPI / I²S / SAI | SPI1 可用 CN7；核对 CPOL/CPHA、位序、CS 时序。音频另检查 BCLK、WS、MCLK 和编解码器 | SPI 先读器件 ID，再看波形。音频先输出已知采样率的单音 |
| TIM / PWM / 捕获 | 可用 PD15/TIM4_CH4。核对定时器内核时钟、PSC、ARR、CCR 和计数模式 | 示波器量频率与占空比，再做输入捕获或编码器 |
| ADC | 从 Zio 模拟排针选用 DS14359 支持的 ADC 通道。核对 VREFP、输入幅度、源阻抗和采样时间 | 先校准，再测已知直流电压。之后改用 TIM 触发和 DMA 采样 |
| GPDMA / HPDMA | 查请求映射、可达存储区、宽度、增量和缓冲区所有权。启用 Cache 时按内存章节处理一致性 | 用固定数据校验，分别验证传输完成、中途停止和错误中断 |
| FDCAN | MCU 提供控制器，外接 CAN 收发器。核对时钟、仲裁/数据相位位时序和总线两端终端电阻 | 先内部回环，再双节点通信。读取错误计数和 bus-off 状态 |
| USB HS / UCPD | 目标 USB 数据走 CN2。先选 Device 示例，确认 USB 时钟、VBUS/CC 处理和端点配置 | 主机看到预期 VID/PID 后，再验证 CDC/HID 等类的数据收发 |
| Ethernet | CN4、LAN8742A、RMII。先查 PHY 时钟/复位、MDIO，再查 MAC、DMA 描述符和网络栈 | 先确认链路和 PHY 寄存器，再试静态 IP、ARP 和 ping |
| RTC / LPTIM / 低功耗 | LSE 用于精确低速基准。确认备份域和唤醒源；进入低功耗后复核时钟恢复 | 脱离调试器复测唤醒和时间保持，测电流时按 JP2 测量方案操作 |
| IWDG / WWDG | 配置超时或窗口，保存复位原因，再将喂狗条件绑定到主任务健康状态 | 有意停喂，确认复位原因及恢复路径。调试冻结设置单独记录 |
| XSPI / SDMMC / FMC | 板载 NOR 用 XSPI。SDMMC 可接外部卡座，FMC 外接存储按实物和电气时序设计 | 先做已知内容读写校验，掉电重启后重读，最后做吞吐和边界测试 |
| CRC / RNG / 加密 | 查对应外设时钟和官方示例；CRC 参数包括多项式、初值和反射，密钥及安全状态独立规划 | 先用已知向量校验 CRC/AES 等算法，检查 RNG 错误标志 |

边沿对齐、向上计数的常见 PWM 配置中，频率为 `fTIM / ((PSC + 1) × (ARR + 1))`。以 PWM 模式 1、有效高为例，占空比通常为 `CCR / (ARR + 1)`，端点和反相输出要按实际配置复核。用 CubeMX 时看 TIM 内核时钟，结合 RCC 的时钟规则核对。

## 外设联调顺序

1. 开始前把引脚、AF、时钟源、工作电平和板载复用写下来。
2. 先用最低可用速率和阻塞传输验证连线及协议，再逐步引入中断、DMA、RTOS 或高速模式。
3. 量化验证结果，例如 ADC 采样误差、PWM 频率、I²C 连续读取错误率或以太网丢包率。
4. 出问题先分层定位。没有时钟或边沿时查电源和 GPIO，信号正确但读数错时查协议时序，DMA 偶发失败时查总线可达性、Cache 和缓冲区复用。
