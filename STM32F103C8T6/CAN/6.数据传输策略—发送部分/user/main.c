#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Key.h"
#include "Timer.h"
#include "MyCAN.h"
CanTxMsg TxMessage_Tim={0x100,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0x11,0x22,0x33,0x44}};
CanTxMsg TxMessage_Tri={0x200,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0x11,0x22,0x33,0x44}};
CanTxMsg TxMessage_Req={0x300,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0x11,0x22,0x33,0x44}};


 	
                
    
CanRxMsg RxMessage;
uint16_t TimCount;
uint8_t TimFlag;
uint8_t TriggerFlag;
uint8_t RequestFlag;
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
		//定时发送
		if(TimFlag==1)
		{
			TimFlag=0;
			MyCAN_SendData(&TxMessage_Tim);
			OLED_Printf(40,16,OLED_8X16,"%X %X %X %X",TxMessage_Tim.Data[0],TxMessage_Tim.Data[1],TxMessage_Tim.Data[2],TxMessage_Tim.Data[3]);
			TxMessage_Tim.Data[0]++;
			TxMessage_Tim.Data[1]++;
			TxMessage_Tim.Data[2]++;
			TxMessage_Tim.Data[3]++;
		}
		
		//触发发送
		if(Key_Check(1,KEY_CLICK)==1) TriggerFlag=1;
		if(TriggerFlag==1)
		{
			TriggerFlag=0;
			MyCAN_SendData(&TxMessage_Tri);
			OLED_Printf(40,32,OLED_8X16,"%X %X %X %X",TxMessage_Tri.Data[0],TxMessage_Tri.Data[1],TxMessage_Tri.Data[2],TxMessage_Tri.Data[3]);
			TxMessage_Tri.Data[0]++;
			TxMessage_Tri.Data[1]++;
			TxMessage_Tri.Data[2]++;
			TxMessage_Tri.Data[3]++;
		}
			
		//请求发送
		if(MyCAN_GetReceiveFlag()==1)
		{
			MyCAN_ReceiveData(&RxMessage);
			if(RxMessage.RTR==CAN_RTR_Data&&RxMessage.IDE==CAN_Id_Standard&&RxMessage.StdId==0x111) RequestFlag=1;
			else if(RxMessage.RTR==CAN_RTR_Remote&&RxMessage.IDE==CAN_Id_Standard&&RxMessage.StdId==0x1FF) RequestFlag=1;
		}
		if(RequestFlag==1)
		{
			RequestFlag=0;
			MyCAN_SendData(&TxMessage_Req);
			OLED_Printf(40,48,OLED_8X16,"%X %X %X %X",TxMessage_Req.Data[0],TxMessage_Req.Data[1],TxMessage_Req.Data[2],TxMessage_Req.Data[3]);
			TxMessage_Req.Data[0]++;
			TxMessage_Req.Data[1]++;
			TxMessage_Req.Data[2]++;
			TxMessage_Req.Data[3]++;
		}
		
		
		
		
//		if(MyCAN_GetReceiveFlag())
//		{
//			
//			MyCAN_ReceiveData(&RxMessage);
//			if(RxMessage.IDE==CAN_Id_Standard)  
//			{
//				OLED_Printf(40,16,OLED_8X16,"        ");
//				OLED_ShowHexNum(40,16,RxMessage.StdId,3,OLED_8X16);
//			}
//			else OLED_ShowHexNum(40,16,RxMessage.ExtId,8,OLED_8X16);
//			if(RxMessage.RTR==CAN_RTR_Data)
//			{
//				OLED_Printf(80,32,OLED_8X16,"      ");
//				OLED_Printf(80,32,OLED_8X16,"Data");
//				OLED_ShowHexNum(40,32,RxMessage.DLC,2,OLED_8X16);
//				OLED_ShowHexNum(40,48,RxMessage.Data[0],2,OLED_8X16);
//				OLED_ShowHexNum(64,48,RxMessage.Data[1],2,OLED_8X16);
//				OLED_ShowHexNum(88,48,RxMessage.Data[2],2,OLED_8X16);
//				OLED_ShowHexNum(112,48,RxMessage.Data[3],2,OLED_8X16);
//			}
//			else
//			{
//				OLED_ClearArea(40,32,128,32);
//				OLED_Printf(80,32,OLED_8X16,"Remote");	
//			}
//			
//		}

		OLED_Update();
	}
	
}
 
void TIM1_UP_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
	{
		TimCount++;
		if(TimCount>=500)
		{
			TimCount=0;
			TimFlag=1;
		}
		Key_Tick();
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	}
}
