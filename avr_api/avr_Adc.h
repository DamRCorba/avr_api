/*
 * avr_Adc.h
 *
 *  Created on: 8 de jul. de 2015
 *      Author: Ing. Damian Corbalan
 *      brief: Header file for ADC definitions.
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
 */

#ifndef AVR_ADC_H_
#define AVR_ADC_H_

#include <avr/interrupt.h>

#ifndef ADFR
#define ADFR 5			//Bit de Freerunning en ADCSRA
#endif

/* *********************** Definiciones de ADC ************************ */
typedef enum			//Definiciones de canales de ADC
{
	avr_ADC_canal0 = 0,	//ADC0
	avr_ADC_canal1 = 1,		//ADC1
	avr_ADC_canal2 = 2,		//ADC2
	avr_ADC_canal3 = 3,		//ADC3
	avr_ADC_canal4 = 4,		//ADC4
	avr_ADC_canal5 = 5,		//ADC5
	avr_ADC_canal6 = 6,		//ADC6
	avr_ADC_canal7 = 7,		//ADC7
}ADC_CANAL_t;

typedef enum				//Prescaler para ADC
{
	avr_ADC_Prescaler_2 = 1,		//(1) -> Clock MCU /2
	avr_ADC_Prescaler_4,			//(2) -> Clock MCU /4
	avr_ADC_Prescaler_8,			//(3) -> Clock MCU /8
	avr_ADC_Prescaler_16,			//(4) -> Clock MCU /16
	avr_ADC_Prescaler_32,			//(5) -> Clock MCU /32
	avr_ADC_Prescaler_64,			//(6) -> Clock MCU /64
	avr_ADC_Prescaler_128,			//(7) -> Clock MCU /128
}ADC_PRES_t;

typedef enum		//Modos de funcionamiento
{
	avr_ADC_MODE_Freerunning,			//Convierte siempre y continuamente
	avr_ADC_MODE_Single_Conversion,		//Una Sola Conversion
	avr_ADC_MODE_Interrupt_request,		//Habilita para convertir continuamente y con salto de interrupcion
}ADC_MODE_t;

typedef enum
{
	avr_ADC_RES_8Bit,
	avr_ADC_RES_10Bit,
}ADC_RES_t;

typedef enum		//Mensajes de error del ADC
{
	avr_ADC_ERR = 0,
	avr_ADC_OK,
}ADC_ERROR;

typedef enum
{
	avr_ADC_REF_AREF = 0,
	avr_ADC_REF_AVcc = 1,
	avr_ADC_REF_Internal = 3,
}ADC_REF_t;
/* *********************** MACROS para manejo de ADC ************************ */
//Macros generales
#define avr_ADC_set_Channel(canal)	    ADMUX&=0xE0;ADMUX|=(ADC_CANAL_t)canal	//seleccion de canal
#define avr_ADC_comienzo_conversion()	ADCSRA|=1<<ADSC

void (*avr_adc_handler)(void);

typedef struct
{
	ADC_MODE_t mode;
	ADC_PRES_t prescaler;
	ADC_CANAL_t channel ;
	ADC_RES_t resolution;
	ADC_REF_t reference;
	void (*avr_adc_handler)(void);
}AdcInitStructure_AVR;

typedef unsigned int avr_ADC_Value_t;

/* *********************** Funciones para manejo de ADC ************************ */

/*
 *  init_adc
 *  param:
 *  		modo: 	ADC_freerunning				Convierte siempre y continuamente
					ADC_Single_Conversion		Una Sola Conversion
					ADC_interrupt_request		Habilita para convertir continuamente y con salto de interrupcion
			fr_div:  	ADC_Prescaler_2				Clock MCU /2
					ADC_Prescaler_4 			Clock MCU /4
					ADC_Prescaler_8 			Clock MCU /8
					ADC_Prescaler_16 			Clock MCU /16
					ADC_Prescaler_32			Clock MCU /32
					ADC_Prescaler_64			Clock MCU /64
					ADC_Prescaler_128			Clock MCU /128
			ch:		Canal a convertir de 0 a 7 en la mayoria de los AVR
			void (*interrupcion_adc)(void); funcion de interrupcion para modo freerun o interrupt request
 */


void adc_handler(void);
ADC_ERROR init_adc(AdcInitStructure_AVR ADC_init);			    //Inicializa ADC, MODO, Prescaler, Canales.

/*  leer_ADC
 *  Parametro: Numero de canal a convertir.
 *  Devuelve el valor en 10 bit de resulucion de la cuenta.
 */
avr_ADC_Value_t leer_ADC(ADC_CANAL_t canal);										//Lee el canal pedido, modo single conversion

/*
 * Funcion de interrupcion para modo Interrupt o Freerunning
 *
 */


#define avr_ADC_RETURN_8BIT_RES (unsigned char)ADCH
#define avr_ADC_RETURN_10BIT_RES  ADCL | (ADCH<<8)



#endif /* AVR_ADC_H_ */
