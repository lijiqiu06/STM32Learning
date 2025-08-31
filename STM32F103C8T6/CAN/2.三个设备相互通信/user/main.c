#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Key.h"
#include "Timer.h"
#include "MyCAN.h"
uint16_t count=0;
int main()
{
	OLED_Init();
	Timer_Init();
	Key_Init();
	MyCAN_Init();
	while(1)
	{
		if(Key_Check(1,KEY_CLICK))
		{
			uint8_t senddata[]={0x11,0x33};
			MyCAN_SendData(0x333,2,senddata);
		}
		
		if(MyCAN_GetReceiveFlag())
		{
			uint32_t ID;
			uint16_t length;
			uint8_t receivedata[10];
			MyCAN_ReceiveData(&ID,&length,receivedata);
			
			OLED_ShowHexNum(0,16,ID,3,OLED_8X16);
			OLED_ShowHexNum(0,32,length,2,OLED_8X16);
			OLED_ShowHexNum(0,48,receivedata[0],2,OLED_8X16);
			OLED_ShowHexNum(32,48,receivedata[1],2,OLED_8X16);
		}

		OLED_Update();
	}
	
}
 
void TIM1_UP_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
	{
		Key_Tick();
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	}
}
