#ifndef __MYPWM_H
#define __MYPWM_H
void MyPWM_Init(uint32_t RCC_APB2Periph,GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin,uint16_t compare);
void MyPWM_setcompare1(uint16_t compare);
#endif 
