/*
  * Title: avr_Adc.c
 *
 *  Created on: 8 de jul. de 2015
 *      Author: Ing. Damian Corbalan
 *      brief: Adc libs for AVR8 microcontrollers
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




#include "avr_Adc.h"

void null_adc_irq(void) {
}

static ADC_RES_t avr_resolucion_ADC = avr_ADC_RES_10Bit; // valor por defecto

/*
 *  leer_ADC
 *  Parametro: Numero de canal a convertir.
 *  Devuelve el valor en 10 bit de resulucion de la cuenta.
 */
avr_ADC_Value_t leer_ADC(ADC_CANAL_t canal) {
	int valor = 0;

	avr_ADC_set_Channel(canal);//Selecciona el canal

	avr_ADC_comienzo_conversion();			// Empieza la conversion
	if (avr_resolucion_ADC == avr_ADC_RES_10Bit) {
		while (!(ADCSRA & (1 << ADIF)))
			;	//Espera hasta que la conversion este terminada
		valor = avr_ADC_RETURN_10BIT_RES;

	}
	if (avr_resolucion_ADC == avr_ADC_RES_8Bit) {
		while (!(ADCSRA & (1 << ADIF)))
			;	//Espera hasta que la conversion este terminada
		valor = avr_ADC_RETURN_8BIT_RES;	//Devuelve el valor convertido
	}
	return valor;	//Devuelve el valor convertido
}

/*
 * 	init_adc(modo,canal)
 * 	Brief: inicializa el ADC dependiendo el modo. Conversion solamente en 8 bits
 * 	Parametros: Modo->freerunning
 * 				Modo->Interrupt Request
 * 	devuelve Exito o fracaso
 *
 * Modo FreeRunning: Las muestras del ADC actualizan los registros continuamente. Se utiliza con un solo Canal de ADC, no permite multiplexar
 * Modo Single_Conversion: El adc solo hara una conversion por cada vez que se lo solicite
 * Modo_interrupt_request: El adc estara continuamente convirtiendo y con cada fin de conversion ira a una rutina de interrupcion en donde se cambiara de canal.
 *
 * Como se usara presicion de 8bits se setea en todos ADLAR para acomodar el dato en la izquierda y se leera la parte alta.
 * De esta forma se truncaran los bits menos significativos de la conversion.
 */
ADC_ERROR init_adc(AdcInitStructure_AVR ADC_init)			//Inicializa ADC
{

	ADCSRA = 0x00;
	if (ADC_init.prescaler > avr_ADC_Prescaler_128)	//Si el prescales seleccionado es mayor que el maximo posible devuelve error
		return avr_ADC_ERR;
	ADCSRA |= ADC_init.prescaler;		//Configura el prescaler
	switch (ADC_init.mode) {
	case avr_ADC_MODE_Freerunning:
		ADCSRA |= (1 << ADEN); //Habilita el ADC
		ADCSRA |= (1 << ADFR); //Configura el modo Freerunning
		ADCSRA |= (1 << ADIE); //Habilita la interrupcion de fin de conversion
		avr_ADC_set_Channel(ADC_init.channel);
		avr_ADC_comienzo_conversion();	//Comienza la conversion
		avr_adc_handler = ADC_init.avr_adc_handler;
		break;
	case avr_ADC_MODE_Single_Conversion:
		ADCSRA |= (1 << ADEN); //Habilita el ADC para el modo Single Conversion
		avr_adc_handler = null_adc_irq;
		break;
	case avr_ADC_MODE_Interrupt_request:
		ADCSRA |= (1 << ADEN); //Habilita el ADC
		ADCSRA |= (1 << ADIE); //Habilita la interrupcion de fin de conversion
		avr_ADC_set_Channel(ADC_init.channel);
		avr_ADC_comienzo_conversion();	//Comienza la conversion
		avr_adc_handler = ADC_init.avr_adc_handler; //Inicializa el puntero de lectura
		break;
	default:
		return avr_ADC_ERR;		//Caso de error de configuracion
	}
	if (ADC_init.resolution == avr_ADC_RES_8Bit) {
		ADMUX |= (1 << ADLAR);
	} //Acomoda a la izquierda para conversion de 8 bits
	avr_resolucion_ADC = ADC_init.resolution;
	ADMUX &= ~ ((1<<REFS1)|(1<<REFS0)); // pone la referencia por defecto como AREF
	if(ADC_init.reference == avr_ADC_REF_AVcc)
		ADMUX |= (1<<REFS0);
	if(ADC_init.reference == avr_ADC_REF_Internal)
		ADMUX |= ((1<<REFS1)|(1<<REFS0));
	return avr_ADC_OK;			//Configuracion exitosa
}

// Llamado de interrupcion del micro para fin de conversion.
ISR(ADC_vect) {
	(*avr_adc_handler)();//Dependiendo el modo de funcionamiento usara una rutina diferente en la interrupcion
}


