#include "stm32f10x.h"                  // Device header
#include <stdio.h>

void Serial_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //无硬件流控
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_Parity = USART_Parity_No;			//无校验
	USART_InitStructure.USART_StopBits = USART_StopBits_1;   // 1个停止位
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;  // 8位数据
	USART_Init(USART1,&USART_InitStructure);
	
	
	
	USART_Cmd(USART1,ENABLE);
}

 //重定向 fputc 函数
int fputc(int ch, FILE *f)
{
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET); // 等待上一个字节发送完成（直到发送数据寄存器为空 TXE）
    USART_SendData(USART1, (uint8_t)ch);  // 将字符通过 USART1 发送出去
    return ch;
}
