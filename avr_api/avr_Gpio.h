/*
 * Titel: avr_Gpio.h Header file and definitios for Gpio AVR API
 *
 *  Created on: 8 de jul. de 2015
 *      Author: Ing. Damian Corbalan
 *
  *   LICENCE
 *   Copyright (C) 2015 Damian Corbalan
 *
 *	 This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *
 *
 */

#ifndef AVR_GPIO_H_
#define AVR_GPIO_H_

#define defined_AVR_PORTA defined (__AVR_ATmega128__) || (__AVR_AT90S2313__) || (__AVR_ATtiny2313__)
#define defined_AVR_PORTB defined (__AVR_ATmega328__) || (__AVR_ATmega328P__) || (__AVR_ATmega8__) || (__AVR_ATmega88__) || (__AVR_ATmega88P__) || (__AVR_ATmega16__) ||(__AVR_ATmega168__) || (__AVR_ATmega168P__) || (__AVR_ATmega32__) || (__AVR_ATmega128__) || (__AVR_ATmega48P__) || (__AVR_ATmega48__)
#define defined_AVR_PORTC defined (__AVR_ATmega328__) || (__AVR_ATmega328P__) || (__AVR_ATmega8__) || (__AVR_ATmega88__) || (__AVR_ATmega88P__) || (__AVR_ATmega16__) ||(__AVR_ATmega168__) || (__AVR_ATmega168P__) || (__AVR_ATmega32__) || (__AVR_ATmega128__) || (__AVR_ATmega48P__) || (__AVR_ATmega48__)
#define defined_AVR_PORTD defined (__AVR_ATmega328__) || (__AVR_ATmega328P__) || (__AVR_ATmega8__) || (__AVR_ATmega88__) || (__AVR_ATmega88P__) || (__AVR_ATmega16__) ||(__AVR_ATmega168__) || (__AVR_ATmega168P__) || (__AVR_ATmega32__) || (__AVR_ATmega128__) || (__AVR_ATmega48P__) || (__AVR_ATmega48__)
#define defined_AVR_PORTE defined (__AVR_ATmega128__)
#define defined_AVR_PORTF defined (__AVR_ATmega128__)
#define defined_AVR_PORTG defined (__AVR_ATmega128__)

typedef enum{
	GPIO_PIN_0 = 1,
	GPIO_PIN_1 = 2,
	GPIO_PIN_2 = 4,
	GPIO_PIN_3 = 8,
	GPIO_PIN_4 = 16,
	GPIO_PIN_5 = 32,
	GPIO_PIN_6 = 64,
	GPIO_PIN_7 = 128,
}GPIO_PIN;

typedef enum{
	GPIO_A,
	GPIO_B,
	GPIO_C,
	GPIO_D,
	GPIO_E,
	GPIO_F,
	GPIO_G,
	GPIO_H,
}GPIO_PORT;

typedef enum{
	GPIO_mode_Input = 0,
	GPIO_mode_Output = 1,
}GPIO_MODE;

typedef struct
{
	GPIO_PORT port;
	GPIO_MODE modo;
	unsigned char pines;
}GpioInitStructure_AVR;
// Puerto, salida/entrada, pines a configurar como entrada.

void init_gpio(GpioInitStructure_AVR Gpio);
#define set_pin(port,pin) port|=pin
#define clear_pin(port,pin) port&=~pin

#ifndef REGBIT
// Macro y variable General para manejo de a bit.
typedef struct{
	unsigned char B0:1;
	unsigned char B1:1;
	unsigned char B2:1;
	unsigned char B3:1;
	unsigned char B4:1;
	unsigned char B5:1;
	unsigned char B6:1;
	unsigned char B7:1;
}bit_t;

#define REGBIT(reg,bit)		((volatile bit_t*)&reg)->B##bit	//Macro para manejar registros de a bit

#endif


// Los siguientes micros tienen GPIO A
#if defined_AVR_PORTA

#define GPIOA_OUT PORTA
#define GPIOA_IN  PINA

//PINES COMO SALIDA
#define GPIOA_OUT_0 REGBIT(GPIOA_OUT,0)
#define GPIOA_OUT_1 REGBIT(GPIOA_OUT,1)
#define GPIOA_OUT_2 REGBIT(GPIOA_OUT,2)
#define GPIOA_OUT_3 REGBIT(GPIOA_OUT,3)
#define GPIOA_OUT_4 REGBIT(GPIOA_OUT,4)
#define GPIOA_OUT_5 REGBIT(GPIOA_OUT,5)
#define GPIOA_OUT_6 REGBIT(GPIOA_OUT,6)
#define GPIOA_OUT_7 REGBIT(GPIOA_OUT,7)

// PINES COMO ENTRADA
#define GPIOA_IN_0 REGBIT(GPIOA_IN,0)
#define GPIOA_IN_1 REGBIT(GPIOA_IN,1)
#define GPIOA_IN_2 REGBIT(GPIOA_IN,2)
#define GPIOA_IN_3 REGBIT(GPIOA_IN,3)
#define GPIOA_IN_4 REGBIT(GPIOA_IN,4)
#define GPIOA_IN_5 REGBIT(GPIOA_IN,5)
#define GPIOA_IN_6 REGBIT(GPIOA_IN,6)
#define GPIOA_IN_7 REGBIT(GPIOA_IN,7)


#endif

// Los Siguientes micros tienen puerto B
#if defined_AVR_PORTB

#define GPIOB_OUT PORTB
#define GPIOB_IN  PINB

#define GPIOB_OUT_0 REGBIT(GPIOB_OUT,0)
#define GPIOB_OUT_1 REGBIT(GPIOB_OUT,1)
#define GPIOB_OUT_2 REGBIT(GPIOB_OUT,2)
#define GPIOB_OUT_3 REGBIT(GPIOB_OUT,3)
#define GPIOB_OUT_4 REGBIT(GPIOB_OUT,4)
#define GPIOB_OUT_5 REGBIT(GPIOB_OUT,5)
#define GPIOB_OUT_6 REGBIT(GPIOB_OUT,6)
#define GPIOB_OUT_7 REGBIT(GPIOB_OUT,7)

#define GPIOB_IN_0 REGBIT(GPIOB_IN,0)
#define GPIOB_IN_1 REGBIT(GPIOB_IN,1)
#define GPIOB_IN_2 REGBIT(GPIOB_IN,2)
#define GPIOB_IN_3 REGBIT(GPIOB_IN,3)
#define GPIOB_IN_4 REGBIT(GPIOB_IN,4)
#define GPIOB_IN_5 REGBIT(GPIOB_IN,5)
#define GPIOB_IN_6 REGBIT(GPIOB_IN,6)
#define GPIOB_IN_7 REGBIT(GPIOB_IN,7)

#endif

//Los siguientes Micros tienen Puertos C
#if defined_AVR_PORTC

#define GPIOC_OUT PORTC
#define GPIOC_IN  PINC

#define GPIOC_OUT_0 REGBIT(GPIOC_OUT,0)
#define GPIOC_OUT_1 REGBIT(GPIOC_OUT,1)
#define GPIOC_OUT_2 REGBIT(GPIOC_OUT,2)
#define GPIOC_OUT_3 REGBIT(GPIOC_OUT,3)
#define GPIOC_OUT_4 REGBIT(GPIOC_OUT,4)
#define GPIOC_OUT_5 REGBIT(GPIOC_OUT,5)
#define GPIOC_OUT_6 REGBIT(GPIOC_OUT,6)
#define GPIOC_OUT_7 REGBIT(GPIOC_OUT,7)

#define GPIOC_IN_0 REGBIT(GPIOC_IN,0)
#define GPIOC_IN_1 REGBIT(GPIOC_IN,1)
#define GPIOC_IN_2 REGBIT(GPIOC_IN,2)
#define GPIOC_IN_3 REGBIT(GPIOC_IN,3)
#define GPIOC_IN_4 REGBIT(GPIOC_IN,4)
#define GPIOC_IN_5 REGBIT(GPIOC_IN,5)
#define GPIOC_IN_6 REGBIT(GPIOC_IN,6)
#define GPIOC_IN_7 REGBIT(GPIOC_IN,7)

#endif

//Los siguientes micros tienen puerto D
#if defined_AVR_PORTD

#define GPIOD_OUT PORTD
#define GPIOD_IN  PIND

#define GPIOD_OUT_0 REGBIT(GPIOD_OUT,0)
#define GPIOD_OUT_1 REGBIT(GPIOD_OUT,1)
#define GPIOD_OUT_2 REGBIT(GPIOD_OUT,2)
#define GPIOD_OUT_3 REGBIT(GPIOD_OUT,3)
#define GPIOD_OUT_4 REGBIT(GPIOD_OUT,4)
#define GPIOD_OUT_5 REGBIT(GPIOD_OUT,5)
#define GPIOD_OUT_6 REGBIT(GPIOD_OUT,6)
#define GPIOD_OUT_7 REGBIT(GPIOD_OUT,7)

#define GPIOD_IN_0 REGBIT(GPIOD_IN,0)
#define GPIOD_IN_1 REGBIT(GPIOD_IN,1)
#define GPIOD_IN_2 REGBIT(GPIOD_IN,2)
#define GPIOD_IN_3 REGBIT(GPIOD_IN,3)
#define GPIOD_IN_4 REGBIT(GPIOD_IN,4)
#define GPIOD_IN_5 REGBIT(GPIOD_IN,5)
#define GPIOD_IN_6 REGBIT(GPIOD_IN,6)
#define GPIOD_IN_7 REGBIT(GPIOD_IN,7)

#endif


//Los siguientes micros tienen puerto E
#if defined_AVR_PORTE

#define GPIOE_OUT PORTE
#define GPIOE_IN  PINE

#define GPIOE_OUT_0 REGBIT(GPIOE_OUT,0)
#define GPIOE_OUT_1 REGBIT(GPIOE_OUT,1)
#define GPIOE_OUT_2 REGBIT(GPIOE_OUT,2)
#define GPIOE_OUT_3 REGBIT(GPIOE_OUT,3)
#define GPIOE_OUT_4 REGBIT(GPIOE_OUT,4)
#define GPIOE_OUT_5 REGBIT(GPIOE_OUT,5)
#define GPIOE_OUT_6 REGBIT(GPIOE_OUT,6)
#define GPIOE_OUT_7 REGBIT(GPIOE_OUT,7)

#define GPIOE_IN_0 REGBIT(GPIOE_IN,0)
#define GPIOE_IN_1 REGBIT(GPIOE_IN,1)
#define GPIOE_IN_2 REGBIT(GPIOE_IN,2)
#define GPIOE_IN_3 REGBIT(GPIOE_IN,3)
#define GPIOE_IN_4 REGBIT(GPIOE_IN,4)
#define GPIOE_IN_5 REGBIT(GPIOE_IN,5)
#define GPIOE_IN_6 REGBIT(GPIOE_IN,6)
#define GPIOE_IN_7 REGBIT(GPIOE_IN,7)

#endif

//Los siguientes micros tienen Puerto F
#if defined_AVR_PORTF

#define GPIOF_OUT PORTF
#define GPIOF_IN  PINF

#define GPIOF_OUT_0 REGBIT(GPIOF_OUT,0)
#define GPIOF_OUT_1 REGBIT(GPIOF_OUT,1)
#define GPIOF_OUT_2 REGBIT(GPIOF_OUT,2)
#define GPIOF_OUT_3 REGBIT(GPIOF_OUT,3)
#define GPIOF_OUT_4 REGBIT(GPIOF_OUT,4)
#define GPIOF_OUT_5 REGBIT(GPIOF_OUT,5)
#define GPIOF_OUT_6 REGBIT(GPIOF_OUT,6)
#define GPIOF_OUT_7 REGBIT(GPIOF_OUT,7)

#define GPIOF_IN_0 REGBIT(GPIOF_IN,0)
#define GPIOF_IN_1 REGBIT(GPIOF_IN,1)
#define GPIOF_IN_2 REGBIT(GPIOF_IN,2)
#define GPIOF_IN_3 REGBIT(GPIOF_IN,3)
#define GPIOF_IN_4 REGBIT(GPIOF_IN,4)
#define GPIOF_IN_5 REGBIT(GPIOF_IN,5)
#define GPIOF_IN_6 REGBIT(GPIOF_IN,6)
#define GPIOF_IN_7 REGBIT(GPIOF_IN,7)
#endif

//Los siguientes micros tienen puerto G
#if defined_AVR_PORTG

#define GPIOG_OUT PORTG
#define GPIOG_IN  PING

#define GPIOG_OUT_0 REGBIT(GPIOG_OUT,0)
#define GPIOG_OUT_1 REGBIT(GPIOG_OUT,1)
#define GPIOG_OUT_2 REGBIT(GPIOG_OUT,2)
#define GPIOG_OUT_3 REGBIT(GPIOG_OUT,3)
#define GPIOG_OUT_4 REGBIT(GPIOG_OUT,4)
#define GPIOG_OUT_5 REGBIT(GPIOG_OUT,5)
#define GPIOG_OUT_6 REGBIT(GPIOG_OUT,6)
#define GPIOG_OUT_7 REGBIT(GPIOG_OUT,7)

#define GPIOG_IN_0 REGBIT(GPIOG_IN,0)
#define GPIOG_IN_1 REGBIT(GPIOG_IN,1)
#define GPIOG_IN_2 REGBIT(GPIOG_IN,2)
#define GPIOG_IN_3 REGBIT(GPIOG_IN,3)
#define GPIOG_IN_4 REGBIT(GPIOG_IN,4)
#define GPIOG_IN_5 REGBIT(GPIOG_IN,5)
#define GPIOG_IN_6 REGBIT(GPIOG_IN,6)
#define GPIOG_IN_7 REGBIT(GPIOG_IN,7)

#endif



#endif /* AVR_GPIO_H_ */
