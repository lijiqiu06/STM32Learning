#ifndef __Port_H
#define __Port_H
void GPIOPort_Init(uint32_t RCC_APB2PeriphX,GPIO_TypeDef* GPIOX,GPIOMode_TypeDef GPIOMode_X,uint16_t GPIOPin_X,GPIOSpeed_TypeDef GPIOSpeed_X);

uint8_t Get_KeyNum(GPIO_TypeDef* GPIOX,uint16_t GPIOPin_X);

#endif
