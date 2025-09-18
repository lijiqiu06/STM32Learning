#include "stm32f10x.h"                  // Device header
#include "Delay.h"

//LED_ON LED_OFF两函数适用于端口输出低电平时LED亮
void LED_ON(GPIO_TypeDef* GPIOX,uint16_t GPIOPin_X)
{
	GPIO_ResetBits(GPIOX,GPIOPin_X);
}

void LED_OFF(GPIO_TypeDef* GPIOX,uint16_t GPIOPin_X)
{
	GPIO_SetBits(GPIOX,GPIOPin_X);
}

//高低电平转换
void LED_Turn(GPIO_TypeDef* GPIOX,uint16_t GPIOPin_X)
{
	if(GPIO_ReadOutputDataBit(GPIOX,GPIOPin_X)==0)
	{
		GPIO_SetBits(GPIOX,GPIOPin_X);
	}
	else
	{
		GPIO_ResetBits(GPIOX,GPIOPin_X);
	}
}