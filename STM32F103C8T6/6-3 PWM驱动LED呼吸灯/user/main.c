#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "MyPWM.h"


int main()
{
	OLED_Init();
	uint16_t compare=10;
	MyPWM_Init(RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_0,compare);
//	compare=50;
	MyPWM_setcompare1(compare);
	while(1)
	{
		
		OLED_ShowNum(1,1,compare,3);
	}
}
 
