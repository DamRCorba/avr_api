/*
 *  Title: avr_api.h
 *
 *  Created on: 8 de jul. de 2015
 *      Author: Ing. Damian Corbalan
 *      brief: This libs makes an api function lib for AVR8 microcontrollers.
 *      The code was designed to look like CMSIS structures for ARM with the purpose to do a generic structure
 *      By the way the libs works with external interruption, GPIO, an ADC. The uart lib is based on Peter Fleury libs
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

#ifndef AVR_API_H_
#define AVR_API_H_
/***********************************************************************************************/
//inclusiones generales.
#include <avr/io.h>
#include <avr/interrupt.h>
/***********************************************************************************************/
/***********************************************************************************************/
// Macro y variable General para manejo de a bit.
typedef struct
	{
	unsigned char B0:1;
	unsigned char B1:1;
	unsigned char B2:1;
	unsigned char B3:1;
	unsigned char B4:1;
	unsigned char B5:1;
	unsigned char B6:1;
	unsigned char B7:1;
	}bit_t;

#define REGBIT(reg,bt)	((volatile bit_t*)&reg)->B##bt	//MACRO PARA MANEJAR REGISTROS DE A BIT.
/***********************************************************************************************/
/***********************************************************************************************/
// Librerias de perifericos. Comentar la que no se use.
#include "avr_Extint.h"	    //Libreria para Interrupciones Externas
#include "avr_Timers.h"		//Libreria para control de Timers
#include "avr_Adc.h"		//Librerias ADC
#include "avr_Spi.h"		//Librerias SPI
#include "avr_Uart.h"		//Librerias UART
#include "avr_Gpio.h"		//Librerias para puertos de proposito general.
/***********************************************************************************************/


#endif /* AVR_API_H_ */
