/*
 * Title: avr_Extint.h
 *
 *  Created on: 8 de jul. de 2015
 *      Author: Ing. Damian Corbalan
 *      brief: Definitions for External interrupt api
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

#ifndef AVR_EXTINT_H_
#define AVR_EXTINT_H_
#include <avr/io.h>
#include <avr/interrupt.h>

//Micros con PCINT
#define defined_AVR_PCINT defined (__AVR_ATmega328__) || (__AVR_ATmega328P__) || (__AVR_ATmega88__) || (__AVR_ATmega88P__) ||(__AVR_ATmega168__) || (__AVR_ATmega168P__) || (__AVR_ATmega48P__) || (__AVR_ATmega48__)



typedef enum
{
	avr_INT0 = 0,
	avr_INT1,
	avr_INT2,
	avr_INT3,
	avr_INT4,
	avr_INT5,
	avr_INT6,
	avr_INT7,
}external_interrupt_t;
// Interrupciones Externas
typedef enum
{
	avr_ext_int_lowlevel = 0,
	avr_ext_int_anychange = 1,
	avr_ext_int_fallingedge = 2,
	avr_ext_int_risingedge = 3,
}external_interrupt_mode;



void (*avr_ext_interrupt_handler)(void);

typedef struct
{
	external_interrupt_t interrupcion;				// INT0;INT1
	external_interrupt_mode modo;					// Nivel bajo, cualquier cambio, flanco descendente, flanco ascendente
	void (*avr_ext_interrupt_handler)(void);			// Funcion de atencion de interrupcion
} ExternalInterruptInitStructure_AVR;

//PCINT
#if defined_AVR_PCINT
typedef enum
{
	AVR_PCIE0 = 1<<1,
	AVR_PCIE1 = 1<<2,
	AVR_PCIE2 = 1<<3,
	AVR_PCIE3,
}PcintE_t;
typedef enum
{
	AVR_PCIF0 = 1<<1,
	AVR_PCIF1 = 1<<2,
	AVR_PCIF2 = 1<<3,
	AVR_PCIF3,
}Pcintf_t;


	//PCMSK0
#define	avr_PCINT0  1
#define avr_PCINT1  1<<1
#define avr_PCINT2  1<<2
#define avr_PCINT3  1<<3
#define avr_PCINT4  1<<4
#define avr_PCINT5  1<<5
#define avr_PCINT6  1<<6
#define avr_PCINT7  1<<7
	//PCMSK1
#define avr_PCINT8   0x000100UL
#define avr_PCINT9   0x000200UL
#define avr_PCINT10  0x000400UL
#define avr_PCINT11  0x000800UL
#define avr_PCINT12  0x001000UL
#define avr_PCINT13  0x002000UL
#define avr_PCINT14  0x004000UL
//PCMSK2
#define avr_PCINT16  0x010000UL
#define avr_PCINT17  0x020000UL
#define avr_PCINT18  0x040000UL
#define avr_PCINT19  0x080000UL
#define avr_PCINT20  0x100000UL
#define avr_PCINT21  0x200000UL
#define avr_PCINT22  0x400000UL
#define avr_PCINT23  0x800000UL

#include <stdint.h>

typedef unsigned long avr_pcint_pin_t;
void (*avr_pcint_handler)(void);
typedef struct{
	Avr_Pcint_pin_t pines;
	void (*avr_pcint_handler)(void);
}PcintInitStructure_AVR;

void init_Pcint(PcintInitStructure_AVR);



void (*interrupcion_PCINT0)(void);
void (*interrupcion_PCINT1)(void);
void (*interrupcion_PCINT2)(void);

#endif
void (*interrupcion_external0)(void);
void (*interrupcion_external1)(void);
void (*interrupcion_external2)(void);
void (*interrupcion_external3)(void);
void (*interrupcion_external4)(void);
void (*interrupcion_external5)(void);
void (*interrupcion_external6)(void);
void (*interrupcion_external7)(void);



/*
 * init_extern_interrupt
 * Inicializa la interrupcion externa
 * parametros:
 * interupcion: INT0, INT1
 * modo: nivel bajo, cualquie cambio, flanco descendente, flanco ascendente.
 * interrupcion externa funcion de atencion para el salto del la interrupcion.
 *
 */
void init_extern_interrupt(ExternalInterruptInitStructure_AVR);



#endif /* AVR_EXTINT_H_ */
