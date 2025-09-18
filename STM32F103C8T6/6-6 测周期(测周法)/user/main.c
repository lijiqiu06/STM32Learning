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
	PWM_setcompare3(50);
	PWM_SetPrescaler(720-1);
	OLED_ShowString(1,7,"Fall");
	OLED_ShowString(2,1,"F=     Hz");
	while(1)
	{
		OLED_ShowNum(2,3,get_f(),5);
	}
	
	
}

