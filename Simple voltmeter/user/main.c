#include "stm32f10x.h"                  // Device header
//#include	"AD.h"
#include	"Serial.h"
//#include	"OLED.h"
//#include	"LED.h" 
#include	"Delay.h"

//uint16_t VALUE;
//float Voltage;

//int main(void)
//{	
//	
//	AD_Init();
//	Serial_Init();
//	LED_Init();
//	OLED_Init();
//	OLED_ShowString(1,1,"VALUE:");
//	OLED_ShowString(2,1,"Voltage:");
//	
//  while(1)
//  {
//		
//		VALUE = Get_Value();
//		Voltage = (float)VALUE /4095 * 3.3;
//		OLED_ShowNum(1,7,VALUE,4);
//		OLED_ShowNum(2,9,Voltage,1);
//		OLED_ShowNum(2,11,(uint16_t)(Voltage * 100 ) % 100,2);
//		printf("VALUE: %.2f V\r\n",Voltage);
//		Delay_ms(100);
////		printf("OK\r\n");
//		if (Voltage >= 2.50)
//		{
//			LED_ON();
//			Delay_ms(500);
//			LED_OFF();
//			Delay_ms(500);	
//		}
//		else 
//		{
//			LED_OFF();
//		}
//		Delay_ms(100);
//	}
//}
int main(void)
{
	Serial_Init();
	while(1)
	{
		printf("hello\r\n");
		Delay_ms(1000);
	}
}
