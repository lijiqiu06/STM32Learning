#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Key.h"
#include "Timer.h"
#include "MyCAN.h"
CanTxMsg TxMessagearr[]=
{
	{0x456,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0x11,0x22,0x33,0x44}},
	{0x123,0x13333333,CAN_Id_Extended,CAN_RTR_Data,4,{0xAA,0xBB,0xCC,0xDD}},
	{0x654,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0x00,0x00,0x00,0x00}},
	{0x123,0x11111111,CAN_Id_Extended,CAN_RTR_Remote,0,{0x00,0x00,0x00,0x00}},
};
 	
uint16_t TxMessagearrcount=0;                 
    

int main()
{
	OLED_Init();
	Timer_Init();
	Key_Init();
	MyCAN_Init();
	OLED_Printf(0,0,OLED_8X16,"TXID:");
	
	OLED_Printf(0,16,OLED_8X16,"RXID:");
	OLED_Printf(0,32,OLED_8X16,"DLC:");
	OLED_Printf(0,48,OLED_8X16,"Data:");
	while(1)
	{
		if(Key_Check(1,KEY_CLICK))
		{
			MyCAN_SendData(&TxMessagearr[TxMessagearrcount]);
			if(TxMessagearr[TxMessagearrcount].IDE==CAN_Id_Standard)
			{
				OLED_Printf(40,0,OLED_8X16,"        ");
				OLED_ShowHexNum(40,0,TxMessagearr[TxMessagearrcount].StdId,3,OLED_8X16);
			}
			else OLED_ShowHexNum(40,0,TxMessagearr[TxMessagearrcount].ExtId,8,OLED_8X16);
			if(TxMessagearrcount>=3) TxMessagearrcount=0;
			else TxMessagearrcount++;	
			
		}
		OLED_ShowNum(120,0,RXMsgFlag,1,OLED_8X16);
		if(RXMsgFlag==1)
		{
			RXMsgFlag=0;
			
			if(RxMessage.IDE==CAN_Id_Standard)  
			{
				OLED_Printf(40,16,OLED_8X16,"        ");
				OLED_ShowHexNum(40,16,RxMessage.StdId,3,OLED_8X16);
			}
			else OLED_ShowHexNum(40,16,RxMessage.ExtId,8,OLED_8X16);
			if(RxMessage.RTR==CAN_RTR_Data)
			{
				OLED_Printf(80,32,OLED_8X16,"      ");
				OLED_Printf(80,32,OLED_8X16,"Data");
				OLED_ShowHexNum(40,32,RxMessage.DLC,2,OLED_8X16);
				OLED_ShowHexNum(40,48,RxMessage.Data[0],2,OLED_8X16);
				OLED_ShowHexNum(64,48,RxMessage.Data[1],2,OLED_8X16);
				OLED_ShowHexNum(88,48,RxMessage.Data[2],2,OLED_8X16);
				OLED_ShowHexNum(112,48,RxMessage.Data[3],2,OLED_8X16);
			}
			else
			{
				OLED_ClearArea(40,32,128,32);
				OLED_Printf(80,32,OLED_8X16,"Remote");	
			}
			
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
