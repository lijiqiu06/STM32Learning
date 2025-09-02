#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Key.h"
#include "Timer.h"
#include "MyCAN.h"
CanTxMsg TxMessage_Req_data={0x111,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0x11,0x22,0x33,0x44}};
CanTxMsg TxMessage_Req_Remote={0x1FF,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0x00,0x00,0x00,0x00}};              
    
CanRxMsg RxMessage;
int main()
{
	OLED_Init();
	Timer_Init();
	Key_Init();
	MyCAN_Init();
	OLED_Printf(0,0,OLED_8X16,"TXID:");
	
	OLED_Printf(0,16,OLED_8X16,"TIM:");
	OLED_Printf(0,32,OLED_8X16,"TRI:");
	OLED_Printf(0,48,OLED_8X16,"REQ:"); 
	while(1)
	{
		if(Key_Check(1,KEY_CLICK))
		{
			MyCAN_SendData(&TxMessage_Req_data);
		}
		else if(Key_Check(1,KEY_DOUBLE))
		{
			MyCAN_SendData(&TxMessage_Req_Remote);
//			OLED_Printf(40,48,OLED_8X16,"Remote");
		}
		
		if(MyCAN_GetReceiveFlag())
		{
			
			MyCAN_ReceiveData(&RxMessage);
			if(RxMessage.RTR==CAN_RTR_Data)
			{
				if(RxMessage.IDE==CAN_Id_Standard&&RxMessage.StdId==0x100)  
				{
					OLED_Printf(40,16,OLED_8X16,"%X %X %X %X",RxMessage.Data[0],RxMessage.Data[1],RxMessage.Data[2],RxMessage.Data[3]);
				}
				
				if(RxMessage.IDE==CAN_Id_Standard&&RxMessage.StdId==0x200)  
				{
					OLED_Printf(40,32,OLED_8X16,"%X %X %X %X",RxMessage.Data[0],RxMessage.Data[1],RxMessage.Data[2],RxMessage.Data[3]);
				}
				
				if(RxMessage.IDE==CAN_Id_Standard&&RxMessage.StdId==0x300)  
				{
					OLED_Printf(40,48,OLED_8X16,"%X %X %X %X",RxMessage.Data[0],RxMessage.Data[1],RxMessage.Data[2],RxMessage.Data[3]);
				}
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
