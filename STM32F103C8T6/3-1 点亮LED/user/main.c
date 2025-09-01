#include "stm32f10x.h"    // Device header
#include "Delay.h"

int main()
{
	//1.
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	//2.
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	
	
	while(1)
	{
		GPIO_ResetBits(GPIOC,GPIO_Pin_13);
//		Delay_ms(1000);
//		GPIO_SetBits(GPIOC,GPIO_Pin_13);
//		Delay_ms(100);
//		
//		GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_RESET);//低电平
//		Delay_ms(1000);
//		GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_SET);//高电平
//		Delay_ms(100);
	}
}
