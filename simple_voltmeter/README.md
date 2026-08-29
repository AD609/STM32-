# Simple Voltmeter（简易电压表）

基于 STM32F103C8 的简易电压表项目。

## 功能说明

- 通过 ADC 采集模拟电压
- 使用 OLED 显示电压值
- 支持串口输出测量结果

## 主要知识点

- ADC 模数转换
- OLED 显示（含字库）
- 串口通信（USART）
- GPIO / LED

## 工程结构

```
Simple voltmeter/
├── Hardware/     # 硬件驱动（AD、LED、OLED、Serial）
├── System/       # 系统文件（Delay）
├── Library/      # 标准外设库
├── start/        # 启动文件
└── user/         # 主程序
```

## 开发环境

- 芯片：STM32F103C8
- IDE：Keil uVision 5
