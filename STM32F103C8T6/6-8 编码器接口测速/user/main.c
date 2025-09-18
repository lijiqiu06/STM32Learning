#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "encoder.h"
#include "timer.h"

int16_t speed=0;
int main()
{
	OLED_Init();
	encoder_init();
	timer_init();
	OLED_ShowString(1,7,"Fall");
	
	while(1)
	{
		OLED_ShowSignedNum(2,3,speed,8);
		
	}
	
	
}

void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)
	{
		speed=getcount();
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
	}
	
}
