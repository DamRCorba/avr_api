/*
 * Title: avr_Extint.c API for external interrupts.
 *
 *  Created on: 8 de jul. de 2015
 *      Author: Ing. Damian Corbalan
 *      Brief: Api source file to use External interrupts
 *
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

#include "avr_Extint.h"




void init_extern_interrupt(ExternalInterruptInitStructure_AVR ExternalIrq_init)
{
	switch (ExternalIrq_init.interrupcion){
	case avr_INT0: 	EICRA &= ~3; //limpia los valores del control para esta interrupcion
					EICRA |= ((ExternalIrq_init.modo == avr_ext_int_lowlevel) ? 0 : ((ExternalIrq_init.modo == avr_ext_int_anychange) ? 0x01 :
							 ((ExternalIrq_init.modo == avr_ext_int_fallingedge) ? 0x02 : ((ExternalIrq_init.modo == avr_ext_int_risingedge) ? 0x03 : 0))));
					interrupcion_external0 = ExternalIrq_init.avr_ext_interrupt_handler;
					break;
	case avr_INT1: 	EICRA &= ~0x0c; //limpia los valores del control para esta interrupcion
					EICRA |= ((ExternalIrq_init.modo == avr_ext_int_lowlevel) ? 0 : ((ExternalIrq_init.modo == avr_ext_int_anychange) ? 0x04 :
							 ((ExternalIrq_init.modo == avr_ext_int_fallingedge) ?  0x08 : ((ExternalIrq_init.modo == avr_ext_int_risingedge) ? 0x0c : 0))));
					interrupcion_external1 = ExternalIrq_init.avr_ext_interrupt_handler;
					break;
	case avr_INT2:
					EICRA &= ~0x30; //limpia los valores del control para esta interrupcion
					EICRA |= ((ExternalIrq_init.modo == avr_ext_int_lowlevel) ? 0 : ((ExternalIrq_init.modo == avr_ext_int_anychange) ? 0x10 :
							 ((ExternalIrq_init.modo == avr_ext_int_fallingedge) ?  0x20 : ((ExternalIrq_init.modo == avr_ext_int_risingedge) ? 0x30 : 0))));
					interrupcion_external2 = ExternalIrq_init.avr_ext_interrupt_handler;
					break;
	case avr_INT3:
					EICRA &= ~0xc0; //limpia los valores del control para esta interrupcion
					EICRA |= ((ExternalIrq_init.modo == avr_ext_int_lowlevel) ? 0 : ((ExternalIrq_init.modo == avr_ext_int_anychange) ? 0x40 :
							((ExternalIrq_init.modo == avr_ext_int_fallingedge) ? 0x80 : ((ExternalIrq_init.modo == avr_ext_int_risingedge) ? 12 : 0xc0))));
					interrupcion_external3 = ExternalIrq_init.avr_ext_interrupt_handler;
					break;

	case avr_INT4:	EICRB &= ~3; //limpia los valores del control para esta interrupcion
					EICRB |= ((ExternalIrq_init.modo == avr_ext_int_lowlevel) ? 0 : ((ExternalIrq_init.modo == avr_ext_int_anychange) ? 1 :
							 ((ExternalIrq_init.modo == avr_ext_int_fallingedge) ? 2 : ((ExternalIrq_init.modo == avr_ext_int_risingedge) ? 3 : 0))));
					interrupcion_external4 = ExternalIrq_init.avr_ext_interrupt_handler;
					break;
	case avr_INT5:
					EICRB &= ~0x0c; //limpia los valores del control para esta interrupcion
					EICRB |= ((ExternalIrq_init.modo == avr_ext_int_lowlevel) ? 0 : ((ExternalIrq_init.modo == avr_ext_int_anychange) ? 4 :
							((ExternalIrq_init.modo == avr_ext_int_fallingedge) ?  8 : ((ExternalIrq_init.modo == avr_ext_int_risingedge) ? 12 : 0))));
					interrupcion_external5 = ExternalIrq_init.avr_ext_interrupt_handler;
					break;
	case avr_INT6:	EICRB &= ~0x30; //limpia los valores del control para esta interrupcion
					EICRB |= ((ExternalIrq_init.modo == avr_ext_int_lowlevel) ? 0 : ((ExternalIrq_init.modo == avr_ext_int_anychange) ? 0x10 :
							 ((ExternalIrq_init.modo == avr_ext_int_fallingedge) ? 0x20 : ((ExternalIrq_init.modo == avr_ext_int_risingedge) ? 0x30 : 0))));
					interrupcion_external6 = ExternalIrq_init.avr_ext_interrupt_handler;
					break;
	case avr_INT7:
					EICRB &= ~0xc0; //limpia los valores del control para esta interrupcion
					EICRB |= ((ExternalIrq_init.modo == avr_ext_int_lowlevel) ? 0 : ((ExternalIrq_init.modo == avr_ext_int_anychange) ? 0x40 :
							((ExternalIrq_init.modo == avr_ext_int_fallingedge) ?  0x80 : ((ExternalIrq_init.modo == avr_ext_int_risingedge) ? 0xc0 : 0))));
					interrupcion_external7 = ExternalIrq_init.avr_ext_interrupt_handler;
					break;
	default: break;

	}

	EIMSK |= 1 << ExternalIrq_init.interrupcion;
	EIFR |= 1 << ExternalIrq_init.interrupcion;
}


ISR(INT0_vect)
{
	(*interrupcion_external0)();
}

ISR(INT1_vect)
{
	(*interrupcion_external1)();
}

ISR(INT2_vect)
{
	(*interrupcion_external2)();
}
ISR(INT3_vect)
{
	(*interrupcion_external3)();
}
ISR(INT4_vect)
{
	(*interrupcion_external4)();
}
ISR(INT5_vect)
{
	(*interrupcion_external5)();
}
ISR(INT6_vect)
{
	(*interrupcion_external6)();
}
ISR(INT7_vect)
{
	(*interrupcion_external7)();
}



#if defined_AVR_PCINT
//Funcion de incializacion
/**
 *  Se podria usar la misma rutina de interrupcion para pines conectados en diferentes PCINT
 */
void init_Pcint(PcintInitStructure_AVR pcint_struct)
{

	unsigned char aux;

	aux = (unsigned char)pcint_struct.pines & 0xff;
	if(aux)//PCINT0
	{
	interrupcion_PCINT0 = pcint_struct.avr_pcint_handler; //tener cuidado en las redefiniciones de la funcion de interrupcion
	PCICR |= AVR_PCIE0;
	PCIFR |= AVR_PCIF0;
	PCMSK0 |= pcint_struct.pines;
	}
	aux = (unsigned char)((pcint_struct.pines >> 8)& 0xff);
	if (aux) // PCINT1
	{
	interrupcion_PCINT1 = pcint_struct.avr_pcint_handler;
	PCICR |= AVR_PCIE1;
	PCIFR |= AVR_PCIF1;
	PCMSK1 |= pcint_struct.pines>>8;
	}
	aux = (unsigned char)((pcint_struct.pines >> 16)& 0xff);
	if (aux) // PCINT2
	{
	interrupcion_PCINT2 = pcint_struct.avr_pcint_handler;
	PCICR |= AVR_PCIE2;
	PCIFR |= AVR_PCIF2;
	PCMSK2 |= pcint_struct.pines>>16;
	}

}


ISR(PCINT0_vect)
{
	(*interrupcion_PCINT0)();
}

ISR(PCINT1_vect)
{
	(*interrupcion_PCINT1)();
}

ISR(PCINT2_vect)
{
	(*interrupcion_PCINT2)();
}
#endif

