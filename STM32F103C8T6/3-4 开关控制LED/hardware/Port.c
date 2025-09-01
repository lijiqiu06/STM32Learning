#include "stm32f10x.h"                  // Device header
#include "Delay.h"
//常规端口初始化
void GPIOPort_Init(uint32_t RCC_APB2PeriphX,GPIO_TypeDef* GPIOX,GPIOMode_TypeDef GPIOMode_X,uint16_t GPIOPin_X,GPIOSpeed_TypeDef GPIOSpeed_X)
{
	RCC_APB2PeriphClockCmd(RCC_APB2PeriphX,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIOMode_X;
	GPIO_InitStruct.GPIO_Pin=GPIOPin_X;
	GPIO_InitStruct.GPIO_Speed=GPIOSpeed_X;
	GPIO_Init(GPIOX,&GPIO_InitStruct);
}

//LED_ON LED_OFF两函数适用于端口输出低电平时LED亮
void LED_ON(GPIO_TypeDef* GPIOX,uint16_t GPIOPin_X)
{
	GPIO_ResetBits(GPIOX,GPIOPin_X);
}

void LED_OFF(GPIO_TypeDef* GPIOX,uint16_t GPIOPin_X)
{
	GPIO_SetBits(GPIOX,GPIOPin_X);
}



