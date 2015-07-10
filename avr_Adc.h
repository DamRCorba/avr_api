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
	ADC_canal0 = 0,	//ADC0
	ADC_canal1,		//ADC1
	ADC_canal2,		//ADC2
	ADC_canal3,		//ADC3
	ADC_canal4,		//ADC4
	ADC_canal5,		//ADC5
	ADC_canal6,		//ADC6
	ADC_canal7,		//ADC7
}CANAL_ADC;

typedef enum				//Prescaler para ADC
{
	ADC_Prescaler_2 = 1,		//(1) -> Clock MCU /2
	ADC_Prescaler_4,			//(2) -> Clock MCU /4
	ADC_Prescaler_8,			//(3) -> Clock MCU /8
	ADC_Prescaler_16,			//(4) -> Clock MCU /16
	ADC_Prescaler_32,			//(5) -> Clock MCU /32
	ADC_Prescaler_64,			//(6) -> Clock MCU /64
	ADC_Prescaler_128,			//(7) -> Clock MCU /128
}PRES_ADC;

typedef enum		//Modos de funcionamiento
{
	ADC_freerunning,			//Convierte siempre y continuamente
	ADC_Single_Conversion,		//Una Sola Conversion
	ADC_interrupt_request,		//Habilita para convertir continuamente y con salto de interrupcion
}MODE_ADC;

typedef enum
{
	ADC_8Bit_RES,
	ADC_10Bit_RES,
}ADC_RES_t;

typedef enum		//Mensajes de error del ADC
{
	ADC_ERR = 0,
	ADC_OK,
}ADC_ERROR;

typedef enum
{
	AVR_AREF = 0,
	AVR_AVcc = 1,
	AVR_Internal = 3,
}ADC_REF_t;
/* *********************** MACROS para manejo de ADC ************************ */
//Macros generales
#define set_ADC_Channel(canal)	ADMUX&=0xE0;ADMUX|=(CANAL_ADC)canal	//seleccion de canal
#define comienzo_conversion()	ADCSRA|=1<<ADSC
#define adc_handler (*avr_adc_irq)
void (*interrupcion_adc)(void);

typedef struct
{
	MODE_ADC mode;
	PRES_ADC prescaler;
	CANAL_ADC channel ;
	ADC_RES_t resolution;
	ADC_REF_t reference;
	void adc_handler(void);
}AdcInitStructure_AVR;

typedef unsigned int ADC_Value_AVR_t;

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
ADC_Value_AVR_t leer_ADC(CANAL_ADC);										//Lee el canal pedido, modo single conversion

/*
 * Funcion de interrupcion para modo Interrupt o Freerunning
 *
 */


#define ADC_RETURN_8BIT_RES (unsigned char)ADCH
#define ADC_RETURN_10BIT_RES  ADCL | (ADCH<<8)



#endif /* AVR_ADC_H_ */
