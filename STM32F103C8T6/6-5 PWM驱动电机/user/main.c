#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Motor.h"
#include "Key.h"
int main()
{
	OLED_Init();
	Motor_Init();
	Key_Init();
	int16_t speed=0;
	while(1)
	{
		if(speed>100)
		{
			Motor_Reserve();
			speed=-100;
		}
		else
		{
			if(Get_KeyNum0()==1)
			{
				speed+=1;
				Motor_SpeedChange(speed);
			}
			else if(Get_KeyNum1()==1)
			{
				speed-=1;
				Motor_SpeedChange(speed);
			}
		}
		OLED_ShowSignedNum(2,1,speed,3);
	}
	
	
}

