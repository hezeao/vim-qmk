# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 项目概述

这是 [QMK 固件](https://qmk.fm) 仓库 —— 基于 TMK 的开源键盘固件。本仓库是一个社区 fork，用于开发和维护个人的 Keychron V4 ANSI 键盘的 Vim 风格键位映射。

## 构建与烧录

本项目的构建目标：`keychron/v4/ansi`，键位映射：`vim`

```bash
# 编译固件
make keychron/v4/ansi:vim

# 编译并烧录（键盘进入 DFU 模式后）
make keychron/v4/ansi:vim:flash

# 编译默认键位（用于参考对比）
make keychron/v4/ansi:default
```

**进入 DFU/烧录模式**：按住键盘左上角 Esc 键（矩阵位置 K00）的同时插入 USB 线。

## 项目架构

### 构建系统

- 顶层 `Makefile` 解析 `make <键盘>:<键位映射>[:目标]` 格式，委托给 `qmk` CLI（Python 包）执行实际构建
- `builddefs/build_keyboard.mk` —— 核心构建编排：收集键盘路径下各级 rules.mk/config.h/.c，调用 qmk CLI 根据 keyboard.json 生成代码，调用平台工具链编译
- `builddefs/common_features.mk` —— QMK 核心源文件（quantum.c, action_layer.c 等）
- `platforms/chibios/flash.mk` —— STM32 平台的 DFU 烧录逻辑（Keychron V4 使用 STM32L432 芯片，stm32-dfu bootloader）

### 键盘配置层级

配置沿目录层级向上继承：`keychron/` → `keychron/v4/` → `keychron/v4/ansi/`

| 层级 | 关键文件 | 作用 |
|---|---|---|
| keyboards/keychron/ | 厂商级 | Keychron 通用配置 |
| keyboards/keychron/v4/ | v4.c, config.h, mcuconf.h | V4 系列共用逻辑（Dip 开关切换 Mac/Win 层、RGB 大小写指示、I2C 驱动配置） |
| keyboards/keychron/v4/ansi/ | keyboard.json, ansi.c | ANSI 变体定义（矩阵引脚、USB ID、布局、88 灯珠 RGB 矩阵） |

### Keychron V4 硬件参数

- **主控**: STM32L432 (ARM Cortex-M4)
- **Bootloader**: stm32-dfu
- **USB**: VID 0x3434 / PID 0x0340
- **矩阵**: 5 行 × 14 列 (ROW2COL)
- **布局**: 60% ANSI (61 键)
- **功能**: bootmagic, dip_switch, extrakey, mousekey, nkro, rgb_matrix (SNLED27351 驱动)

## 键位映射设计 (keyboards/keychron/v4/ansi/keymaps/vim/)

### 层级结构（5 层）

| 层级 | 索引 | 用途 |
|---|---|---|
| `MAC_BASE` | 0 | macOS 标准 60% 布局 (`KC_LCMD`, `KC_LOPT`) |
| `WIN_BASE` | 1 | Windows 标准 60% 布局 (`KC_LALT`, `KC_LWIN`) |
| `NORMAL` | 2 | Vim Normal 模式导航层（h/j/k/l → 方向键） |
| `VISUAL` | 3 | Vim Visual 模式（导航键加 Shift 修饰，模拟选区） |
| `REPLACE` | 4 | 占位空层（全 `XXXXXXX`） |

### 核心机制

**层级切换**：通过 `key_override` 的 `custom_action` 回调 `set_mode()` 实现层间切换（而非传统 `MO()`/`TG()` 瞬态切换）。`set_mode()` 在按键按下时调用 `layer_move()` 直接设置当前活动层。

**Key Overrides（6 个）**：

| Override | 触发键组合 | 效果 |
|---|---|---|
| `normal_override` | Ctrl + Esc | 切换到 NORMAL 层（抑制 Ctrl） |
| `insert_override` | 按 I 键（在层 2/3） | 返回 MAC_BASE 层（模拟 Vim `i` 进入插入模式） |
| `visual_override` | 按 V 键（在层 2） | 切换到 VISUAL 层（模拟 Vim `v` 进入可视模式） |
| `delete_key_override` | Shift + Backspace | 输出 Delete |
| `caps_lock_override` | Shift + Esc | 输出 Caps Lock |
| `ctrl_h_override` | Ctrl + H（仅层 1） | 输出 Backspace |

**Mod 中和器** (`config.h`):
- 使用 `KC_F18` 作为 Dummy Mod Neutralizer keycode
- 中和左 Alt、左 GUI、右 GUI、以及左 GUI+ESC 组合键
- 目的：防止层级切换时修饰键卡住

**RGB 层级指示** (`rgb_matrix_indicators_advanced_user`):
- 层 1 (WIN_BASE): 紫色 (204, 0, 255)
- 层 2 (NORMAL): 青色 (0, 204, 187)
- 层 3 (VISUAL): 橙色 (238, 119, 34)
- 其他层: 保持默认 RGB 效果

### 编译依赖

键位映射的 `rules.mk` 仅启用一项额外功能：
```makefile
KEY_OVERRIDE_ENABLE = yes
```

## 代码风格

- 使用 `#include QMK_KEYBOARD_H` 而非具体板卡头文件
- 层级枚举优于 `#define`
- 键位映射使用 `clang-format off` 保持对齐的可读性
- 版权声明使用 GPL2+ 许可证（SPDX 格式）
- 所有新文件名和目录名必须小写
