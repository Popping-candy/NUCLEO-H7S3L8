# STM32CubeIDE for Visual Studio Code 中文指南

[返回首页](../../README.md) · [上电与调试](../firmware/bringup-debug.md) · [内存与存储](../firmware/memory-storage.md)

本篇包含 ST 官方入口页的中文译述、各章节的中文导读，以及面向 NUCLEO-H7S3L8 的操作说明。按 2026-11-08 查阅的 `latest/en` 页面整理。菜单保留英文原名，方便在 VS Code 里查找。工具版本与字段支持请结合已安装版本核对。 [ST 英文原文](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/index.html)

## 官方首页中文译述

欢迎访问 STM32CubeIDE for Visual Studio Code 文档门户。

- 首次创建或导入工程的用户，可从[首次创建工程](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/getting_started/first_project_creation.html)开始。
- 已使用过 2.x 扩展的用户，可阅读[从 2.x 迁移到 3.x](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/tutorials/migration.html)，了解升级前需要留意的事项。
- 想先了解产品的用户，可通过[英文首页](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/index.html)观看入门视频。

## 官方章节中文导读

| 章节 | 子主题与阅读用途 |
| --- | --- |
| 简介 | 产品概览、系统要求、发行说明。先核对操作系统和扩展版本。 [系统要求](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/introduction/system_requirements.html) · [发行说明](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/introduction/release_note.html) |
| 基本概念 | 用户界面、命令行工具、扩展包、Bundle、CMake、编译工具链、ST Arm Clang。Bundle 管理配套工具，CMake 管理项目的构建规则。 [Bundle](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/basic_concepts/bundles.html) |
| 入门 | 安装扩展、从目标芯片或板卡创建、从 CubeMX 生成、从固件包导入示例。 [安装](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/getting_started/installation.html) · [首次创建工程](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/getting_started/first_project_creation.html) |
| 工作区与扩展操作 | 工作区上下文、扩展命令、项目文件、多工程。打开根目录后，先确认命令对应哪个工程。 [工作区概览](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/workspace_and_extension_workflow/workspace_overview.html) · [多工程](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/workspace_and_extension_workflow/multi_project_workspaces.html) |
| 专题教程 | 旧版迁移、双核、低功耗、RTOS、固件安全和完整性。H7S3 是单核，Boot 和 App 是不同启动阶段，按各自镜像和符号处理。 [迁移](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/tutorials/migration.html) · [专题导航](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/index.html) |
| 开发 | 工程管理、代码编辑、构建、调试、API、外部工具集成、测试和验证。 [工程](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/development/projects.html) · [构建](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/development/build.html) · [调试](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/development/debug.html) · [测试](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/development/testing_validation.html) |
| 排障 | 常见问题、已知问题和支持渠道。先保存版本、构建或探针日志及最小复现。 [已知问题](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/troubleshooting/known_issues.html) |

## 1. 安装与版本记录

1. 在 VS Code 的 **Extensions** 中搜索并安装 ST 发布的 **STM32CubeIDE for Visual Studio Code** 扩展。按扩展提示完成开发工具设置，安装或选择需要的 Bundle 和工具链。
2. 要配置外设并生成初始化代码时，准备支持目标板的 **STM32CubeMX** 及 **STM32CubeH7RS** 固件包。准备 **STM32CubeProgrammer** 用于验证 SWD、单独烧录和外部存储操作。
3. 用 CN5 连接板卡，在 STM32 视图确认 ST-LINK。若首次启动提示探针固件需要更新，可通过 STM32 的设备视图处理。
4. 记录 VS Code 扩展、Bundle/编译器、CubeMX、固件包、Programmer 和探针固件版本。2.x 升级到 3.x 时，检查旧扩展及重复的调试/语言服务。3.x 的工具配置采用 Bundle 工作流。

原文：[安装](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/getting_started/installation.html) · [迁移](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/tutorials/migration.html)

## 2. 创建或导入工程

| 起点 | 操作 |
| --- | --- |
| 有官方板卡示例 | 在 STM32Cube 视图选择 **Import STM32Cube example(s)**，选固件包根目录、目标示例和导出位置。确认生成后是否包含所需的 Boot/App 上下文 |
| 需要配置完整外设 | CubeMX 中选 NUCLEO-H7S3L8 或准确料号，核对板卡引脚，在工程设置中选择 **CMake** 工具链并生成。保留 `.ioc` |
| 需要空白工程 | 从扩展的新建工程操作开始，选板卡或器件、目录和工具链。可选目标受已安装设备包影响 |
| 已有 CMake 工程 | 打开包含项目定义和 CMake 文件的根目录，按提示发现项目。多个工程时先选对活动目录和目标 |

从 64 KiB 片内点灯开始时，先用[官方片内模板](https://github.com/STMicroelectronics/STM32CubeH7RS/tree/main/Projects/NUCLEO-H7S3L8/Templates/Template)核对链接布局。导入后的地址和预设以实际生成工程为准。 [建工程原文](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/getting_started/first_project_creation.html) · [扩展命令](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/workspace_and_extension_workflow/extension_commands.html)

## 3. 构建与定位产物

- 在 CMake 视图选择配置预设和目标，首次用调试预设，依次 Configure、Build。CLI 可先运行 `cmake --list-presets`，然后按工程实际的配置和构建预设执行 `cmake --preset <配置预设>` 和 `cmake --build --preset <构建预设>`。终端需能找到相应工具链，工程也需定义对应预设。
- 构建后找到新生成的 ELF，核对当前目标、入口和段地址。有 MAP 时一起检查。切换 Debug/Release 或编译器后重新配置，再验证调试使用的 ELF 是否跟随切换。
- 排错先看 CMake configure、编译、链接哪一步最早失败。头文件可被编辑器索引但构建找不到时，检查目标的 include 配置。出现区域溢出时，查看链接脚本及 MAP。
- 将 `.ioc`、可复现的 CMake 配置、启动代码和链接脚本纳入版本控制。重新生成后核对差异，按生成器规则保留自定义代码。 [构建原文](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/development/build.html) · [工作区原文](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/workspace_and_extension_workflow/workspace_overview.html)

## 4. 启动调试与外部 Flash

1. 首次用 **Run and Debug**（`Ctrl+Shift+D`）选 ST-LINK。先验证片内 ELF 可下载且能停在 `main`，再试单步、调用栈和寄存器。
2. 要保存配置，从调试界面创建工程根目录的 `.vscode/launch.json`。常用字段包括 `type`（如 `stlinkgdbtarget`）、`request`、`runEntry`、`preBuild`、`imagesAndSymbols`。用扩展的自动补全核对本机版本字段。
3. 外部 XIP 工程要处理片内 Boot ELF、外部 App ELF 和板卡对应的 `.stldr`。官方 ST-LINK GDB 配置提供 `serverExtLoader`，含 `loader` 和 `initialize`。初次可在 CubeProgrammer 分别烧写和校验两份镜像，再回 VS Code 配置 Boot/App 符号和断点。
4. 已运行的目标可按调试文档配置 attach，核对仅加载符号、复位和停点设置。普通 launch 能停在 `main` 后，再按需查看外设寄存器、内存、反汇编、Fault Analyzer、Live Watch 或 RTOS 视图。串口日志从 CN5 的 COM 口另开终端读取。
5. 完成调试后退出会话并复位，再做一次断电重启，确认独立启动。 [调试原文](https://dev.st.com/stm32cube-docs/stm32cubeide-vscode/latest/en/docs/markup/development/debug.html) · [板卡启动流程](../firmware/bringup-debug.md)

## 5. 常见卡点

| 现象 | 检查项 |
| --- | --- |
| 没有项目或没有 Build 按钮 | 根目录、项目发现、CMake 配置预设和扩展是否就绪 |
| 找不到工具链 | Bundle 是否已安装、预设引用是否正确、终端与扩展使用的环境是否一致 |
| 构建成功但调试找不到 ELF | 活动工程与预设、生成目录、`imagesAndSymbols` |
| 探针可见但无法连接目标 | 是否插 CN5、目标供电、JP2、探针固件、是否被另一工具占用 |
| 外部应用无法停在入口 | Boot 是否执行、NOR 是否已映射、App 装载地址及调试符号是否匹配 |
| 补全、诊断或调试视图重复 | 2.x 遗留扩展、重复的 C/C++ 语言服务或调试组件 |
