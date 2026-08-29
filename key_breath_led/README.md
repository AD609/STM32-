# 按键控制 LED 呼吸灯

基于 STM32F103C8 的按键控制 LED 呼吸灯实验。

## 功能说明

- 使用 PWM 控制 LED 亮度，实现呼吸灯效果
- 通过按键切换或控制呼吸灯状态

## 主要知识点

- GPIO 输入（按键）
- 定时器 + PWM 输出
- LED 驱动

## 工程结构

```
key_breath_led/
├── Hardware/     # 硬件驱动（Key、LED、PWM、OLED、Speed）
├── System/       # 系统文件（Delay、Timer）
├── Library/      # 标准外设库
├── start/        # 启动文件
└── user/         # 主程序
```

## 开发环境

- 芯片：STM32F103C8
- IDE：Keil uVision 5
