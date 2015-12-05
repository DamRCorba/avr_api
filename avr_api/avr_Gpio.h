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
	avr_GPIO_PIN_0 = 1,
	avr_GPIO_PIN_1 = 2,
	avr_GPIO_PIN_2 = 4,
	avr_GPIO_PIN_3 = 8,
	avr_GPIO_PIN_4 = 16,
	avr_GPIO_PIN_5 = 32,
	avr_GPIO_PIN_6 = 64,
	avr_GPIO_PIN_7 = 128,
}GPIO_PIN;

typedef enum{
	avr_GPIO_A,
	avr_GPIO_B,
	avr_GPIO_C,
	avr_GPIO_D,
	avr_GPIO_E,
	avr_GPIO_F,
	avr_GPIO_G,
	avr_GPIO_H,
}GPIO_PORT;

typedef enum{
	avr_GPIO_mode_Input = 0,
	avr_GPIO_mode_Output = 1,
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

#define avr_GPIOA_OUT PORTA
#define avr_GPIOA_IN  PINA
#define avr_GPIOA_DIR DDRA

//PINES COMO SALIDA
#define avr_GPIOA_OUT_0 REGBIT(avr_GPIOA_OUT,0)
#define avr_GPIOA_OUT_1 REGBIT(avr_GPIOA_OUT,1)
#define avr_GPIOA_OUT_2 REGBIT(avr_GPIOA_OUT,2)
#define avr_GPIOA_OUT_3 REGBIT(avr_GPIOA_OUT,3)
#define avr_GPIOA_OUT_4 REGBIT(avr_GPIOA_OUT,4)
#define avr_GPIOA_OUT_5 REGBIT(avr_GPIOA_OUT,5)
#define avr_GPIOA_OUT_6 REGBIT(avr_GPIOA_OUT,6)
#define avr_GPIOA_OUT_7 REGBIT(avr_GPIOA_OUT,7)

// PINES COMO ENTRADA
#define avr_GPIOA_IN_0 REGBIT(avr_GPIOA_IN,0)
#define avr_GPIOA_IN_1 REGBIT(avr_GPIOA_IN,1)
#define avr_GPIOA_IN_2 REGBIT(avr_GPIOA_IN,2)
#define avr_GPIOA_IN_3 REGBIT(avr_GPIOA_IN,3)
#define avr_GPIOA_IN_4 REGBIT(avr_GPIOA_IN,4)
#define avr_GPIOA_IN_5 REGBIT(avr_GPIOA_IN,5)
#define avr_GPIOA_IN_6 REGBIT(avr_GPIOA_IN,6)
#define avr_GPIOA_IN_7 REGBIT(avr_GPIOA_IN,7)

#define avr_GPIOA_DIR_0	REGBIT(avr_GPIOA_DIR,0)
#define avr_GPIOA_DIR_1	REGBIT(avr_GPIOA_DIR,1)
#define avr_GPIOA_DIR_2	REGBIT(avr_GPIOA_DIR,2)
#define avr_GPIOA_DIR_3	REGBIT(avr_GPIOA_DIR,3)
#define avr_GPIOA_DIR_4	REGBIT(avr_GPIOA_DIR,4)
#define avr_GPIOA_DIR_5	REGBIT(avr_GPIOA_DIR,5)
#define avr_GPIOA_DIR_6	REGBIT(avr_GPIOA_DIR,6)
#define avr_GPIOA_DIR_7	REGBIT(avr_GPIOA_DIR,7)

#endif

// Los Siguientes micros tienen puerto B
#if defined_AVR_PORTB

#define avr_GPIOB_OUT PORTB
#define avr_GPIOB_IN  PINB
#define avr_GPIOB_DIR DDRB

#define avr_GPIOB_OUT_0 REGBIT(avr_GPIOB_OUT,0)
#define avr_GPIOB_OUT_1 REGBIT(avr_GPIOB_OUT,1)
#define avr_GPIOB_OUT_2 REGBIT(avr_GPIOB_OUT,2)
#define avr_GPIOB_OUT_3 REGBIT(avr_GPIOB_OUT,3)
#define avr_GPIOB_OUT_4 REGBIT(avr_GPIOB_OUT,4)
#define avr_GPIOB_OUT_5 REGBIT(avr_GPIOB_OUT,5)
#define avr_GPIOB_OUT_6 REGBIT(avr_GPIOB_OUT,6)
#define avr_GPIOB_OUT_7 REGBIT(avr_GPIOB_OUT,7)

#define avr_GPIOB_IN_0 REGBIT(avr_GPIOB_IN,0)
#define avr_GPIOB_IN_1 REGBIT(avr_GPIOB_IN,1)
#define avr_GPIOB_IN_2 REGBIT(avr_GPIOB_IN,2)
#define avr_GPIOB_IN_3 REGBIT(avr_GPIOB_IN,3)
#define avr_GPIOB_IN_4 REGBIT(avr_GPIOB_IN,4)
#define avr_GPIOB_IN_5 REGBIT(avr_GPIOB_IN,5)
#define avr_GPIOB_IN_6 REGBIT(avr_GPIOB_IN,6)
#define avr_GPIOB_IN_7 REGBIT(avr_GPIOB_IN,7)

#define avr_GPIOB_DIR_0	REGBIT(avr_GPIOB_DIR,0)
#define avr_GPIOB_DIR_1	REGBIT(avr_GPIOB_DIR,1)
#define avr_GPIOB_DIR_2	REGBIT(avr_GPIOB_DIR,2)
#define avr_GPIOB_DIR_3	REGBIT(avr_GPIOB_DIR,3)
#define avr_GPIOB_DIR_4	REGBIT(avr_GPIOB_DIR,4)
#define avr_GPIOB_DIR_5	REGBIT(avr_GPIOB_DIR,5)
#define avr_GPIOB_DIR_6	REGBIT(avr_GPIOB_DIR,6)
#define avr_GPIOB_DIR_7	REGBIT(avr_GPIOB_DIR,7)

#endif

//Los siguientes Micros tienen Puertos C
#if defined_AVR_PORTC

#define avr_GPIOC_OUT PORTC
#define avr_GPIOC_IN  PINC
#define avr_GPIOC_DIR DDR

#define avr_GPIOC_OUT_0 REGBIT(avr_GPIOC_OUT,0)
#define avr_GPIOC_OUT_1 REGBIT(avr_GPIOC_OUT,1)
#define avr_GPIOC_OUT_2 REGBIT(avr_GPIOC_OUT,2)
#define avr_GPIOC_OUT_3 REGBIT(avr_GPIOC_OUT,3)
#define avr_GPIOC_OUT_4 REGBIT(avr_GPIOC_OUT,4)
#define avr_GPIOC_OUT_5 REGBIT(avr_GPIOC_OUT,5)
#define avr_GPIOC_OUT_6 REGBIT(avr_GPIOC_OUT,6)
#define avr_GPIOC_OUT_7 REGBIT(avr_GPIOC_OUT,7)

#define avr_GPIOC_IN_0 REGBIT(avr_GPIOC_IN,0)
#define avr_GPIOC_IN_1 REGBIT(avr_GPIOC_IN,1)
#define avr_GPIOC_IN_2 REGBIT(avr_GPIOC_IN,2)
#define avr_GPIOC_IN_3 REGBIT(avr_GPIOC_IN,3)
#define avr_GPIOC_IN_4 REGBIT(avr_GPIOC_IN,4)
#define avr_GPIOC_IN_5 REGBIT(avr_GPIOC_IN,5)
#define avr_GPIOC_IN_6 REGBIT(avr_GPIOC_IN,6)
#define avr_GPIOC_IN_7 REGBIT(avr_GPIOC_IN,7)

#define avr_GPIOC_DIR_0	REGBIT(avr_GPIOC_DIR,0)
#define avr_GPIOC_DIR_1	REGBIT(avr_GPIOC_DIR,1)
#define avr_GPIOC_DIR_2	REGBIT(avr_GPIOC_DIR,2)
#define avr_GPIOC_DIR_3	REGBIT(avr_GPIOC_DIR,3)
#define avr_GPIOC_DIR_4	REGBIT(avr_GPIOC_DIR,4)
#define avr_GPIOC_DIR_5	REGBIT(avr_GPIOC_DIR,5)
#define avr_GPIOC_DIR_6	REGBIT(avr_GPIOC_DIR,6)
#define avr_GPIOC_DIR_7	REGBIT(avr_GPIOC_DIR,7)

#endif

//Los siguientes micros tienen puerto D
#if defined_AVR_PORTD

#define avr_GPIOD_OUT PORTD
#define avr_GPIOD_IN  PIND
#define avr_GPIOD_DIR DDRD

#define avr_GPIOD_OUT_0 REGBIT(avr_GPIOD_OUT,0)
#define avr_GPIOD_OUT_1 REGBIT(avr_GPIOD_OUT,1)
#define avr_GPIOD_OUT_2 REGBIT(avr_GPIOD_OUT,2)
#define avr_GPIOD_OUT_3 REGBIT(avr_GPIOD_OUT,3)
#define avr_GPIOD_OUT_4 REGBIT(avr_GPIOD_OUT,4)
#define avr_GPIOD_OUT_5 REGBIT(avr_GPIOD_OUT,5)
#define avr_GPIOD_OUT_6 REGBIT(avr_GPIOD_OUT,6)
#define avr_GPIOD_OUT_7 REGBIT(avr_GPIOD_OUT,7)

#define avr_GPIOD_IN_0 REGBIT(avr_GPIOD_IN,0)
#define avr_GPIOD_IN_1 REGBIT(avr_GPIOD_IN,1)
#define avr_GPIOD_IN_2 REGBIT(avr_GPIOD_IN,2)
#define avr_GPIOD_IN_3 REGBIT(avr_GPIOD_IN,3)
#define avr_GPIOD_IN_4 REGBIT(avr_GPIOD_IN,4)
#define avr_GPIOD_IN_5 REGBIT(avr_GPIOD_IN,5)
#define avr_GPIOD_IN_6 REGBIT(avr_GPIOD_IN,6)
#define avr_GPIOD_IN_7 REGBIT(avr_GPIOD_IN,7)

#define avr_GPIOD_DIR_0	REGBIT(avr_GPIOD_DIR,0)
#define avr_GPIOD_DIR_1	REGBIT(avr_GPIOD_DIR,1)
#define avr_GPIOD_DIR_2	REGBIT(avr_GPIOD_DIR,2)
#define avr_GPIOD_DIR_3	REGBIT(avr_GPIOD_DIR,3)
#define avr_GPIOD_DIR_4	REGBIT(avr_GPIOD_DIR,4)
#define avr_GPIOD_DIR_5	REGBIT(avr_GPIOD_DIR,5)
#define avr_GPIOD_DIR_6	REGBIT(avr_GPIOD_DIR,6)
#define avr_GPIOD_DIR_7	REGBIT(avr_GPIOD_DIR,7)

#endif


//Los siguientes micros tienen puerto E
#if defined_AVR_PORTE

#define avr_GPIOE_OUT PORTE
#define avr_GPIOE_IN  PINE
#define avr_GPIOE_DIR DDRE

#define avr_GPIOE_OUT_0 REGBIT(avr_GPIOE_OUT,0)
#define avr_GPIOE_OUT_1 REGBIT(avr_GPIOE_OUT,1)
#define avr_GPIOE_OUT_2 REGBIT(avr_GPIOE_OUT,2)
#define avr_GPIOE_OUT_3 REGBIT(avr_GPIOE_OUT,3)
#define avr_GPIOE_OUT_4 REGBIT(avr_GPIOE_OUT,4)
#define avr_GPIOE_OUT_5 REGBIT(avr_GPIOE_OUT,5)
#define avr_GPIOE_OUT_6 REGBIT(avr_GPIOE_OUT,6)
#define avr_GPIOE_OUT_7 REGBIT(avr_GPIOE_OUT,7)

#define avr_GPIOE_IN_0 REGBIT(avr_GPIOE_IN,0)
#define avr_GPIOE_IN_1 REGBIT(avr_GPIOE_IN,1)
#define avr_GPIOE_IN_2 REGBIT(avr_GPIOE_IN,2)
#define avr_GPIOE_IN_3 REGBIT(avr_GPIOE_IN,3)
#define avr_GPIOE_IN_4 REGBIT(avr_GPIOE_IN,4)
#define avr_GPIOE_IN_5 REGBIT(avr_GPIOE_IN,5)
#define avr_GPIOE_IN_6 REGBIT(avr_GPIOE_IN,6)
#define avr_GPIOE_IN_7 REGBIT(avr_GPIOE_IN,7)

#define avr_GPIOE_DIR_0	REGBIT(avr_GPIOE_DIR,0)
#define avr_GPIOE_DIR_1	REGBIT(avr_GPIOE_DIR,1)
#define avr_GPIOE_DIR_2	REGBIT(avr_GPIOE_DIR,2)
#define avr_GPIOE_DIR_3	REGBIT(avr_GPIOE_DIR,3)
#define avr_GPIOE_DIR_4	REGBIT(avr_GPIOE_DIR,4)
#define avr_GPIOE_DIR_5	REGBIT(avr_GPIOE_DIR,5)
#define avr_GPIOE_DIR_6	REGBIT(avr_GPIOE_DIR,6)
#define avr_GPIOE_DIR_7	REGBIT(avr_GPIOE_DIR,7)

#endif

//Los siguientes micros tienen Puerto F
#if defined_AVR_PORTF

#define avr_GPIOF_OUT PORTF
#define avr_GPIOF_IN  PINF
#define avr_GPIOF_DIR DDRF

#define avr_GPIOF_OUT_0 REGBIT(avr_GPIOF_OUT,0)
#define avr_GPIOF_OUT_1 REGBIT(avr_GPIOF_OUT,1)
#define avr_GPIOF_OUT_2 REGBIT(avr_GPIOF_OUT,2)
#define avr_GPIOF_OUT_3 REGBIT(avr_GPIOF_OUT,3)
#define avr_GPIOF_OUT_4 REGBIT(avr_GPIOF_OUT,4)
#define avr_GPIOF_OUT_5 REGBIT(avr_GPIOF_OUT,5)
#define avr_GPIOF_OUT_6 REGBIT(avr_GPIOF_OUT,6)
#define avr_GPIOF_OUT_7 REGBIT(avr_GPIOF_OUT,7)

#define avr_GPIOF_IN_0 REGBIT(avr_GPIOF_IN,0)
#define avr_GPIOF_IN_1 REGBIT(avr_GPIOF_IN,1)
#define avr_GPIOF_IN_2 REGBIT(avr_GPIOF_IN,2)
#define avr_GPIOF_IN_3 REGBIT(avr_GPIOF_IN,3)
#define avr_GPIOF_IN_4 REGBIT(avr_GPIOF_IN,4)
#define avr_GPIOF_IN_5 REGBIT(avr_GPIOF_IN,5)
#define avr_GPIOF_IN_6 REGBIT(avr_GPIOF_IN,6)
#define avr_GPIOF_IN_7 REGBIT(avr_GPIOF_IN,7)

#define avr_GPIOF_DIR_0	REGBIT(avr_GPIOF_DIR,0)
#define avr_GPIOF_DIR_1	REGBIT(avr_GPIOF_DIR,1)
#define avr_GPIOF_DIR_2	REGBIT(avr_GPIOF_DIR,2)
#define avr_GPIOF_DIR_3	REGBIT(avr_GPIOF_DIR,3)
#define avr_GPIOF_DIR_4	REGBIT(avr_GPIOF_DIR,4)
#define avr_GPIOF_DIR_5	REGBIT(avr_GPIOF_DIR,5)
#define avr_GPIOF_DIR_6	REGBIT(avr_GPIOF_DIR,6)
#define avr_GPIOF_DIR_7	REGBIT(avr_GPIOF_DIR,7)

#endif

//Los siguientes micros tienen puerto G
#if defined_AVR_PORTG

#define avr_GPIOG_OUT PORTG
#define avr_GPIOG_IN  PING
#define avr_GPIOG_DIR DDRG

#define avr_GPIOG_OUT_0 REGBIT(avr_GPIOG_OUT,0)
#define avr_GPIOG_OUT_1 REGBIT(avr_GPIOG_OUT,1)
#define avr_GPIOG_OUT_2 REGBIT(avr_GPIOG_OUT,2)
#define avr_GPIOG_OUT_3 REGBIT(avr_GPIOG_OUT,3)
#define avr_GPIOG_OUT_4 REGBIT(avr_GPIOG_OUT,4)
#define avr_GPIOG_OUT_5 REGBIT(avr_GPIOG_OUT,5)
#define avr_GPIOG_OUT_6 REGBIT(avr_GPIOG_OUT,6)
#define avr_GPIOG_OUT_7 REGBIT(avr_GPIOG_OUT,7)

#define avr_GPIOG_IN_0 REGBIT(avr_GPIOG_IN,0)
#define avr_GPIOG_IN_1 REGBIT(avr_GPIOG_IN,1)
#define avr_GPIOG_IN_2 REGBIT(avr_GPIOG_IN,2)
#define avr_GPIOG_IN_3 REGBIT(avr_GPIOG_IN,3)
#define avr_GPIOG_IN_4 REGBIT(avr_GPIOG_IN,4)
#define avr_GPIOG_IN_5 REGBIT(avr_GPIOG_IN,5)
#define avr_GPIOG_IN_6 REGBIT(avr_GPIOG_IN,6)
#define avr_GPIOG_IN_7 REGBIT(avr_GPIOG_IN,7)

#define avr_GPIOG_DIR_0	REGBIT(avr_GPIOG_DIR,0)
#define avr_GPIOG_DIR_1	REGBIT(avr_GPIOG_DIR,1)
#define avr_GPIOG_DIR_2	REGBIT(avr_GPIOG_DIR,2)
#define avr_GPIOG_DIR_3	REGBIT(avr_GPIOG_DIR,3)
#define avr_GPIOG_DIR_4	REGBIT(avr_GPIOG_DIR,4)
#define avr_GPIOG_DIR_5	REGBIT(avr_GPIOG_DIR,5)
#define avr_GPIOG_DIR_6	REGBIT(avr_GPIOG_DIR,6)
#define avr_GPIOG_DIR_7	REGBIT(avr_GPIOG_DIR,7)

#endif



#endif /* AVR_GPIO_H_ */
