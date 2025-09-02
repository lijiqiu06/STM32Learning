#ifndef __MYCAN_H
#define __MYCAN_H
void MyCAN_Init(void);
void MyCAN_SendData(CanTxMsg* TxMessage);
uint8_t MyCAN_GetReceiveFlag(void);
void MyCAN_ReceiveData(CanRxMsg* RxMessage);
#endif
