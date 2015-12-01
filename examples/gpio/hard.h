#ifndef HARD_H_
#define HARD_H_

#include "../../avr_api/avr_api.h"


#define SENS_PORT avr_GPIO_F

#define SENS_DER_PIN avr_GPIO_PIN_0 		//Sensor derecho mas alejado
#define SENS_DERC_PIN avr_GPIO_PIN_1		//Sensor derecho central
#define SENS_CEN_PIN avr_GPIO_PIN_2			//Sensor central
#define SENS_IZQC_PIN avr_GPIO_PIN_3		//Sensor izquierdo central
#define SENS_IZQ_PIN avr_GPIO_PIN_4			//Sensor izquierdo mas alejado

#define SENS_DER avr_GPIOF_OUT_0 		//Sensor derecho mas alejado
#define SENS_DERC avr_GPIOF_OUT_1		//Sensor derecho central
#define SENS_CEN avr_GPIOF_OUT_2			//Sensor central
#define SENS_IZQC avr_GPIOF_OUT_3		//Sensor izquierdo central
#define SENS_IZQ avr_GPIOF_OUT_4			//Sensor izquierdo mas alejado

#endif /* HARD_H_ */
