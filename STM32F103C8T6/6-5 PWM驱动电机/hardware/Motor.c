#include "stm32f10x.h"                  // Device header
#include "PWM.h"
void Motor_Init(void)
{
	PWM_Init();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
}

void Motor_SpeedChange(int16_t change)
{
	if(change>=0)PWM_setcompare3(change);
	else PWM_setcompare3(-change);
}

void Motor_Reserve(void)
{
   if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_5)==1)
   {
	   GPIO_SetBits(GPIOA,GPIO_Pin_4);
	   GPIO_ResetBits(GPIOA,GPIO_Pin_5);
   }
   else
   {
	   GPIO_SetBits(GPIOA,GPIO_Pin_5);
	   GPIO_ResetBits(GPIOA,GPIO_Pin_4);
   }
}
