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

//函数适用于按开关输入低电平
uint8_t Get_KeyNum(GPIO_TypeDef* GPIOX,uint16_t GPIOPin_X)
{
	int KeyNUM=0;
	if(GPIO_ReadInputDataBit(GPIOX,GPIOPin_X)==0)
	{
		Delay_ms(20);//逃过波动区域(感觉如果不是高低电平转换就不用延时)
		while(GPIO_ReadInputDataBit(GPIOX,GPIOPin_X)==0);//在程序眼里你按一下等于长按
		Delay_ms(20);
		KeyNUM=1;
	}
	return KeyNUM;
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

