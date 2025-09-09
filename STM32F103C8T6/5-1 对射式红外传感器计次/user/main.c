#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "countsenser.h"

int main()
{
	OLED_Init();
	OLED_ShowString(1,1,"Fall");
	countsenser_init();
	while(1)
	{
		uint16_t current_count=get_count();
		OLED_ShowNum(3,1,current_count,8);
	}
	
}
 
