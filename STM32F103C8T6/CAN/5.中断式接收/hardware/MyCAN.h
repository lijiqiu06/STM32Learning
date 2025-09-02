#ifndef __MYCAN_H
#define __MYCAN_H

extern CanRxMsg RxMessage;
extern uint8_t RXMsgFlag;
void MyCAN_Init(void);
void MyCAN_SendData(CanTxMsg* TxMessage);

#endif
