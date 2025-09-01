#include "stm32f10x.h"                  // Device header

void MyCAN_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	
	CAN_InitTypeDef CAN_InitStruct;
	CAN_InitStruct.CAN_Mode = CAN_Mode_LoopBack;
	CAN_InitStruct.CAN_Prescaler = 48;
	CAN_InitStruct.CAN_SJW = CAN_SJW_2tq;
	CAN_InitStruct.CAN_BS1 = CAN_BS1_2tq;
	CAN_InitStruct.CAN_BS2 = CAN_BS2_3tq;
	CAN_InitStruct.CAN_NART = DISABLE;
	CAN_InitStruct.CAN_AWUM = DISABLE;
	CAN_InitStruct.CAN_RFLM = DISABLE;
	CAN_InitStruct.CAN_TTCM  =DISABLE;
	CAN_InitStruct.CAN_TXFP = DISABLE;
	CAN_InitStruct.CAN_ABOM = DISABLE;
	CAN_Init(CAN1, &CAN_InitStruct);
	
	CAN_FilterInitTypeDef CAN_FilterInitStruct;
	CAN_FilterInitStruct.CAN_FilterIdHigh = 0x200<<5;
	CAN_FilterInitStruct.CAN_FilterIdLow = 0x320<<5;
	CAN_FilterInitStruct.CAN_FilterMaskIdHigh = (0x700<<5)|0x8;
	CAN_FilterInitStruct.CAN_FilterMaskIdLow = (0x7F0<<5)|0x8;
	CAN_FilterInitStruct.CAN_FilterMode = CAN_FilterMode_IdMask;
	CAN_FilterInitStruct.CAN_FilterNumber = 0;
	CAN_FilterInitStruct.CAN_FilterScale = CAN_FilterScale_16bit;
	CAN_FilterInitStruct.CAN_FilterFIFOAssignment = CAN_Filter_FIFO0;
	CAN_FilterInitStruct.CAN_FilterActivation = ENABLE;
	CAN_FilterInit(&CAN_FilterInitStruct);
	
}

void MyCAN_SendData(CanTxMsg* TxMessage)
{
	
	uint8_t TransmitMailbox=CAN_Transmit(CAN1, TxMessage);
	uint32_t TimeOut;
	while(CAN_TransmitStatus(CAN1,TransmitMailbox)!=CAN_TxStatus_Ok)
	{
		TimeOut++;
		if(TimeOut>100000) break;
	}
}

uint8_t MyCAN_GetReceiveFlag(void)
{
	if(CAN_MessagePending(CAN1,CAN_FIFO0)>0) return 1;
	return 0;
}

void MyCAN_ReceiveData(CanRxMsg* RxMessage)
{
	CAN_Receive(CAN1,CAN_FIFO0,RxMessage);
}
