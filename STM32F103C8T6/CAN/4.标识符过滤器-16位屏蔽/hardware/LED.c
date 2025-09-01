#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	
}

//LED_ON LED_OFF两函数适用于端口输出低电平时LED亮
void LED_ON(void)
{
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);
}

void LED_OFF(void)
{
	GPIO_SetBits(GPIOC,GPIO_Pin_13);
}



