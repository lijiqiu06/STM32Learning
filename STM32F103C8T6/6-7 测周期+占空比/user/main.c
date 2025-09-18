#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "IC.h"
int main()
{
	OLED_Init();
	PWM_Init();
	IC_Init();
	PWM_setcompare3(99);
	PWM_SetPrescaler(7200-1);
	OLED_ShowString(1,7,"Fall");
	OLED_ShowString(2,1,"F=        Hz");
	OLED_ShowString(3,1,"Rate=   %");
	while(1)
	{
		OLED_ShowNum(2,3,get_f(),8);
		OLED_ShowNum(3,6,get_Rate(),3);
	}
	
	
}

