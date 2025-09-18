#ifndef LED_H
#define LED_H
void LED_ON(GPIO_TypeDef* GPIOX,uint16_t GPIOPin_X);
void LED_OFF(GPIO_TypeDef* GPIOX,uint16_t GPIOPin_X);
void LED_Turn(GPIO_TypeDef* GPIOX,uint16_t GPIOPin_X);
#endif