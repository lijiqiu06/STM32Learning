#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Port.h"
//按着亮，不按就灭，按着一个另外一个也能操控
int main()
{
	GPIOPort_Init(RCC_APB2Periph_GPIOA,GPIOA,GPIO_Mode_Out_PP,GPIO_Pin_0|GPIO_Pin_1,GPIO_Speed_50MHz);
	
	GPIOPort_Init(RCC_APB2Periph_GPIOB,GPIOB,GPIO_Mode_IPU,GPIO_Pin_0|GPIO_Pin_11,GPIO_Speed_50MHz);
	
	while(1)
	{
		uint8_t Bbit11 = GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11);
		
		uint8_t Bbit0 = GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0);
	    if(Bbit11==0)
		{
			LED_ON(GPIOA,GPIO_Pin_1);
		}
		else
		{
		    LED_OFF(GPIOA,GPIO_Pin_1);
		}
		
		 if(Bbit0==0)
		{
			LED_ON(GPIOA,GPIO_Pin_0);
		}
		else
		{
		    LED_OFF(GPIOA,GPIO_Pin_0);
		}
	}
}
