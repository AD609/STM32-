#include "stm32f10x.h"                  // Device header

void AD_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1|RCC_APB2Periph_GPIOA,ENABLE);	 // 开启 ADC1 和 GPIOA 的时钟（PA1 属于 GPIOA）
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);		//配置 ADC 时钟：72MHz / 6 = 12MHz (ADC 最大不能超过 14MHz)
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		  //  配置 PA1 为模拟输入引脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	ADC_RegularChannelConfig(ADC1,ADC_Channel_1,1,ADC_SampleTime_239Cycles5);
	
	ADC_InitTypeDef ADC_InitStructure;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;		  // 单次转换模式（每次调用需要手动触发）
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;  // 数据右对齐
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;   // 纯软件触发
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;  // 独立工作模式
	ADC_InitStructure.ADC_NbrOfChannel = 1;   // 只转换 1 个规则通道
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;   //非扫描模式
	ADC_Init(ADC1,&ADC_InitStructure);
	
		ADC_Cmd(ADC1,ENABLE);
   
	 // 校准 ADC
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1) == SET);  // 死循环等待，直到重置校准完成
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1) == SET);   // 死循环等待，直到启动校准完成
	
}

uint16_t Get_Value(void)
{
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);   // 软件触发一次 ADC 开始转换
	while(ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC) == RESET);// 死循环等待：检查转换结束标志位 EOC 是否被置位 (变为 SET)
                                                       // 如果一直卡在这里，说明 ADC 没转完，需要检查上面的配置
	return ADC_GetConversionValue(ADC1);     //  转换完成，读出数据寄存器并返回 (返回值为 0 ~ 4095)
}




