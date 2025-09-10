#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "timer.h"

int main()
{
	OLED_Init();
	OLED_ShowString(1,1,"Fall");
	
	timer_init();
	while(1)
	{
		OLED_ShowNum(3,1,getcount(),8);
		
		OLED_ShowNum(4,1,TIM_GetCounter(TIM2),8);
	}
	
}
 
