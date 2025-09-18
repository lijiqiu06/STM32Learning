#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"

#include "Capture.h"
#include "timer.h"
uint16_t count=0;
uint32_t f=1000000;
uint16_t i=0;
int main()
{
	OLED_Init();
	Capture_Init();
	timer_init();
	while(1)
	{
		
		OLED_ShowNum(2,1,TIM_GetCounter(TIM2),8);
		OLED_ShowSignedNum(3,1,f,8);
		OLED_ShowNum(4,1,i,8);
	}
	
	
}

