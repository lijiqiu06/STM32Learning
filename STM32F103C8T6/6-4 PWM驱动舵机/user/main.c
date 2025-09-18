#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Servo.h"
#include "Key.h"
//int main()
//{
//	uint16_t angle=0;
//	Servo_Init();
//	OLED_Init();
//	Key_Init();
//	OLED_ShowString(1,1,"Fall");
//	while(1)
//	{
//		
//		if(angle>180)
//		{
//			angle=0;
//		}
//		else
//		{
//			if(Get_KeyNum()==1)
//			{
//				angle+=30;
//			}
//		}
//		Set_Angle(angle);
//		OLED_ShowNum(2,1,angle,3);
//		
//	}
//}
int main()
{
	uint16_t angle=0;
	Servo_Init();
	OLED_Init();
	Key_Init();
	OLED_ShowString(1,1,"Fall");
	while(1)
	{
		for(angle=0;angle<180;angle++)
		{
			Set_Angle(angle);
		    OLED_ShowNum(2,1,angle,3);
			Delay_ms(10);
		}
		for(angle=180;angle>0;angle--)
		{
			Set_Angle(angle);
		    OLED_ShowNum(2,1,angle,3);
			Delay_ms(10);
		}
		
		
	}
}
