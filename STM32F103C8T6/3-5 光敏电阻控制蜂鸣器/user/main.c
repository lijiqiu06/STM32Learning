#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Port.h"

int main()
{
	GPIOPort_Init(RCC_APB2Periph_GPIOB,GPIOB,GPIO_Mode_IN_FLOATING,GPIO_Pin_0,GPIO_Speed_50MHz);
	GPIOPort_Init(RCC_APB2Periph_GPIOB,GPIOB,GPIO_Mode_Out_PP,GPIO_Pin_8,GPIO_Speed_50MHz);
	GPIOPort_Init(RCC_APB2Periph_GPIOA,GPIOA,GPIO_Mode_Out_PP,GPIO_Pin_0,GPIO_Speed_50MHz);
	while(1)
	{
		uint8_t Bbit0=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0);
		if(Bbit0==1)
		{
			LED_ON(GPIOB,GPIO_Pin_8);
			LED_ON(GPIOA,GPIO_Pin_0);
		}
		else
		{
			LED_OFF(GPIOB,GPIO_Pin_8);
			LED_OFF(GPIOA,GPIO_Pin_0);
		}
	}
}
