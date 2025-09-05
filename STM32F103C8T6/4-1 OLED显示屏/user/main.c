#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Key.h"
#include "Timer.h"
uint16_t count=0;
int main()
{
	OLED_Init();
	Timer_Init();
	Key_Init();
	while(1)
	{
		if(Key_Check(1,KEY_CLICK)) count++;
		OLED_Printf(0,0,OLED_8X16,"%d",count);
		OLED_Update();
	}
	
}
 
void TIM1_UP_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
	{
		Key_Tick();
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	}
}
