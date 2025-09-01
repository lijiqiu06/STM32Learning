#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Port.h"
//按一下亮，再按一下灭，一个长按就不能操控另外一个
int main()
{
	GPIOPort_Init(RCC_APB2Periph_GPIOA,GPIOA,GPIO_Mode_Out_PP,GPIO_Pin_0|GPIO_Pin_1,GPIO_Speed_50MHz);
	
	GPIOPort_Init(RCC_APB2Periph_GPIOB,GPIOB,GPIO_Mode_IPU,GPIO_Pin_0|GPIO_Pin_11,GPIO_Speed_50MHz);
	
	while(1)
	{
		uint8_t Bbit11 = Get_KeyNum(GPIOB,GPIO_Pin_11);
		
		uint8_t Bbit0 = Get_KeyNum(GPIOB,GPIO_Pin_0);
	    if(Bbit11)
		{
			LED_Turn(GPIOA,GPIO_Pin_1);
		}
		 if(Bbit0)
		{
			LED_Turn(GPIOA,GPIO_Pin_0);
		}
	}
}
