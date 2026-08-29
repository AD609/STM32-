#include "stm32f10x.h"                  // Device header
#include	"LED.h"
#include	"PWM.h"
#include	"Delay.h"
#include	"Key.h"

uint8_t i;
uint8_t Speed = 30;
uint8_t KeyNum;

int main(void)
{
	SystemInit();
	PWM_Init();
	Key_Init();
	
  while(1)
  { 
		
		for(i=0;i<=100;i++)
		{	
			KeyNum = Key_GetNum();
			if(KeyNum == 1)
			{
				Speed -=10;
				if (Speed < 10)
				{
					Speed = 30;
				}
				KeyNum = 0;
			}
			PWM_Compare1(i);
			Delay_ms(Speed);
		}	
		for(i=0;i<=100;i++)
		{
			KeyNum = Key_GetNum();
			if(KeyNum == 1)
			{
				Speed -=10;
				if (Speed < 10)
				{
					Speed = 30;
				}
				KeyNum = 0;
			}
			PWM_Compare1(100-i);
			Delay_ms(Speed);
		}
  }
}
