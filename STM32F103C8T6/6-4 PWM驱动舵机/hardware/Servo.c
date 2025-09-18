#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Servo_Init(void)
{
	PWM_Init();
	
}

void Set_Angle(float angle)
{
	PWM_setcompare2(angle/180*2000+500);
}
