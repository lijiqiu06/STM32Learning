#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "encoder.h"

int main()
{
	OLED_Init();
	OLED_ShowString(1,1,"Fall");
	
	encoder_init();
	while(1)
	{
	
		OLED_ShowSignedNum(3,1,getcount(),8);
		
	}
	
}
 
