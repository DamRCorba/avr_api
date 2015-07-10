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
	GPIO_Output,
	GPIO_Input,
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

//PINES COMO SALIDA
#define PORTA_0 REGBIT(PORTA,0)
#define PORTA_1 REGBIT(PORTA,1)
#define PORTA_2 REGBIT(PORTA,2)
#define PORTA_3 REGBIT(PORTA,3)
#define PORTA_4 REGBIT(PORTA,4)
#define PORTA_5 REGBIT(PORTA,5)
#define PORTA_6 REGBIT(PORTA,6)
#define PORTA_7 REGBIT(PORTA,7)

// PINES COMO ENTRADA
#define PINA_0 REGBIT(PINA,0)
#define PINA_1 REGBIT(PINA,1)
#define PINA_2 REGBIT(PINA,2)
#define PINA_3 REGBIT(PINA,3)
#define PINA_4 REGBIT(PINA,4)
#define PINA_5 REGBIT(PINA,5)
#define PINA_6 REGBIT(PINA,6)
#define PINA_7 REGBIT(PINA,7)


#endif

// Los Siguientes micros tienen puerto B
#if defined_AVR_PORTB

#define PORTB_0 REGBIT(PORTB,0)
#define PORTB_1 REGBIT(PORTB,1)
#define PORTB_2 REGBIT(PORTB,2)
#define PORTB_3 REGBIT(PORTB,3)
#define PORTB_4 REGBIT(PORTB,4)
#define PORTB_5 REGBIT(PORTB,5)
#define PORTB_6 REGBIT(PORTB,6)
#define PORTB_7 REGBIT(PORTB,7)

#define PINB_0 REGBIT(PINB,0)
#define PINB_1 REGBIT(PINB,1)
#define PINB_2 REGBIT(PINB,2)
#define PINB_3 REGBIT(PINB,3)
#define PINB_4 REGBIT(PINB,4)
#define PINB_5 REGBIT(PINB,5)
#define PINB_6 REGBIT(PINB,6)
#define PINB_7 REGBIT(PINB,7)

#endif

//Los siguientes Micros tienen Puertos C
#if defined_AVR_PORTC

#define PORTC_0 REGBIT(PORTC,0)
#define PORTC_1 REGBIT(PORTC,1)
#define PORTC_2 REGBIT(PORTC,2)
#define PORTC_3 REGBIT(PORTC,3)
#define PORTC_4 REGBIT(PORTC,4)
#define PORTC_5 REGBIT(PORTC,5)
#define PORTC_6 REGBIT(PORTC,6)
#define PORTC_7 REGBIT(PORTC,7)

#define PINC_0 REGBIT(PINC,0)
#define PINC_1 REGBIT(PINC,1)
#define PINC_2 REGBIT(PINC,2)
#define PINC_3 REGBIT(PINC,3)
#define PINC_4 REGBIT(PINC,4)
#define PINC_5 REGBIT(PINC,5)
#define PINC_6 REGBIT(PINC,6)
#define PINC_7 REGBIT(PINC,7)

#endif

//Los siguientes micros tienen puerto D
#if defined_AVR_PORTD

#define PORTD_0 REGBIT(PORTD,0)
#define PORTD_1 REGBIT(PORTD,1)
#define PORTD_2 REGBIT(PORTD,2)
#define PORTD_3 REGBIT(PORTD,3)
#define PORTD_4 REGBIT(PORTD,4)
#define PORTD_5 REGBIT(PORTD,5)
#define PORTD_6 REGBIT(PORTD,6)
#define PORTD_7 REGBIT(PORTD,7)

#define PIND_0 REGBIT(PIND,0)
#define PIND_1 REGBIT(PIND,1)
#define PIND_2 REGBIT(PIND,2)
#define PIND_3 REGBIT(PIND,3)
#define PIND_4 REGBIT(PIND,4)
#define PIND_5 REGBIT(PIND,5)
#define PIND_6 REGBIT(PIND,6)
#define PIND_7 REGBIT(PIND,7)

#endif


//Los siguientes micros tienen puerto E
#if defined_AVR_PORTE

#define PORTE_0 REGBIT(PORTE,0)
#define PORTE_1 REGBIT(PORTE,1)
#define PORTE_2 REGBIT(PORTE,2)
#define PORTE_3 REGBIT(PORTE,3)
#define PORTE_4 REGBIT(PORTE,4)
#define PORTE_5 REGBIT(PORTE,5)
#define PORTE_6 REGBIT(PORTE,6)
#define PORTE_7 REGBIT(PORTE,7)

#define PINE_0 REGBIT(PINE,0)
#define PINE_1 REGBIT(PINE,1)
#define PINE_2 REGBIT(PINE,2)
#define PINE_3 REGBIT(PINE,3)
#define PINE_4 REGBIT(PINE,4)
#define PINE_5 REGBIT(PINE,5)
#define PINE_6 REGBIT(PINE,6)
#define PINE_7 REGBIT(PINE,7)

#endif

//Los siguientes micros tienen Puerto F
#if defined_AVR_PORTF

#define PORTF_0 REGBIT(PORTF,0)
#define PORTF_1 REGBIT(PORTF,1)
#define PORTF_2 REGBIT(PORTF,2)
#define PORTF_3 REGBIT(PORTF,3)
#define PORTF_4 REGBIT(PORTF,4)
#define PORTF_5 REGBIT(PORTF,5)
#define PORTF_6 REGBIT(PORTF,6)
#define PORTF_7 REGBIT(PORTF,7)

#define PINF_0 REGBIT(PINF,0)
#define PINF_1 REGBIT(PINF,1)
#define PINF_2 REGBIT(PINF,2)
#define PINF_3 REGBIT(PINF,3)
#define PINF_4 REGBIT(PINF,4)
#define PINF_5 REGBIT(PINF,5)
#define PINF_6 REGBIT(PINF,6)
#define PINF_7 REGBIT(PINF,7)
#endif

//Los siguientes micros tienen puerto G
#if defined_AVR_PORTG

#define PORTG_0 REGBIT(PORTG,0)
#define PORTG_1 REGBIT(PORTG,1)
#define PORTG_2 REGBIT(PORTG,2)
#define PORTG_3 REGBIT(PORTG,3)
#define PORTG_4 REGBIT(PORTG,4)
#define PORTG_5 REGBIT(PORTG,5)
#define PORTG_6 REGBIT(PORTG,6)
#define PORTG_7 REGBIT(PORTG,7)

#define PING_0 REGBIT(PING,0)
#define PING_1 REGBIT(PING,1)
#define PING_2 REGBIT(PING,2)
#define PING_3 REGBIT(PING,3)
#define PING_4 REGBIT(PING,4)
#define PING_5 REGBIT(PING,5)
#define PING_6 REGBIT(PING,6)
#define PING_7 REGBIT(PING,7)

#endif



#endif /* AVR_GPIO_H_ */
