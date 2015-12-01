#ifndef HARD_H_
#define HARD_H_

#include "../../avr_api/avr_api.h"



#define PUL1_IRQ avr_INT7

#define LED_1_GPIO_PORT			avr_GPIO_D
#define LED_1_GPIO_PIN			avr_GPIO_PIN_4
#define LED_1					avr_GPIOD_OUT_4

#define LED_2_GPIO_PORT			avr_GPIO_D
#define LED_2_GPIO_PIN			avr_GPIO_PIN_5
#define LED_2					avr_GPIOD_OUT_5

#define LED_3_GPIO_PORT			avr_GPIO_D
#define LED_3_GPIO_PIN			avr_GPIO_PIN_6
#define LED_3					avr_GPIOD_OUT_6

#define LED_4_GPIO_PORT			avr_GPIO_D
#define LED_4_GPIO_PIN			avr_GPIO_PIN_7
#define LED_4					avr_GPIOD_OUT_7



#endif /* HARD_H_ */
