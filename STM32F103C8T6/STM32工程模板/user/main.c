#include "stm32f10x.h"                  // Device header


int main()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	//RCC->APB2ENR = 0x00000010;寄存器操作
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	//GPIOC->CRH = 0x00300000;
	//GPIO_SetBits(GPIOC,GPIO_Pin_13);//高电平
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);//低电平
	//GPIOC->ODR = 0x00000000;
    while(1)
	{
	
	}
}
