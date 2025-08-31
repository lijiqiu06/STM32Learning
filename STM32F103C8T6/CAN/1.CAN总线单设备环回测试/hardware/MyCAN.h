#ifndef __MYCAN_H
#define __MYCAN_H
void MyCAN_Init(void);
void MyCAN_SendData(uint32_t ID,uint16_t length,uint8_t*data);
uint8_t MyCAN_GetReceiveFlag(void);
void MyCAN_ReceiveData(uint32_t *ID,uint16_t *length,uint8_t*data);
#endif
