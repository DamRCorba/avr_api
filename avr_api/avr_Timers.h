/*
  * Title: avr_Timers.h Definitions for Timers
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

#ifndef AVR_TIMERS_H_
#define AVR_TIMERS_H_

#include "avr_api.h"

typedef enum
{
	avr_TIM0 = 0,
	avr_TIM1= 1,
	avr_TIM2 = 2,
	avr_TIM3 =3,
}TIMERS_o;


typedef enum {
	avr_TIM_Clock_NoClockSource = 0,
	avr_TIM_Clock_SystemClockPrescalingx1 = 1,
	avr_TIM_Clock_SystemClockPrescalingx8 = 2,
	avr_TIM_Clock_SystemClockPrescalingx64 = 3,
	avr_TIM_Clock_SystemClockPrescalingx256 = 4,
	avr_TIM_Clock_SystemClockPrescalingx1024 = 5,
	avr_TIM_Clock_ExternalClock_Falling = 6,
	avr_TIM_Clock_ExternalClock_Rising = 7,
}TIM_Clock_Source_o;

typedef enum{
	avr_TIM_MODE_NormalTop, //top on overflow
	avr_TIM_MODE_PhaseCorrectPWMTop0xFF,
	avr_TIM_MODE_CTCTopOCR0A,
	avr_TIM_MODE_FastPwmTop0xFF,
	avr_TIM_MODE_PhaseCorrectPWMTopOCR0A,
	avr_TIM_MODE_FastPwmTopOCR0A,
}TIM_MODE_o;

#define avr_TIM3_Out_Normal_OC3A	0 //~((1<<COM1A1)|(1<<(COM1A0))) // Ver como implementar 0 No se usa
#define avr_TIM3_Out_Toggle_OC3A	(1<<(COM3A0))
#define avr_TIM3_Out_Clear_OC3A	(1<<(COM3A1))
#define avr_TIM3_Out_Set_OC3A	((1<<COM3A1)|(1<<(COM1A0)))
#define avr_TIM3_Out_Normal_OC3B	0	//&~((1<<COM1B1)|(1<<(COM1B0))) no se usa
#define avr_TIM3_Out_Toggle_OC3B	(1<<(COM3B0))
#define avr_TIM3_Out_Clear_OC3B	(1<<(COM3B1))
#define avr_TIM3_Out_Set_OC3B	((1<<COM3B1)|(1<<(COM3B0)))


#define avr_TIM1_Out_Normal_OC1A	0 //~((1<<COM1A1)|(1<<(COM1A0))) // Ver como implementar 0 No se usa
#define avr_TIM1_Out_Toggle_OC1A	(1<<(COM1A0))
#define avr_TIM1_Out_Clear_OC1A	(1<<(COM1A1))
#define avr_TIM1_Out_Set_OC1A	((1<<COM1A1)|(1<<(COM1A0)))
#define avr_TIM1_Out_Normal_OC1B	0	//&~((1<<COM1B1)|(1<<(COM1B0))) no se usa
#define avr_TIM1_Out_Toggle_OC1B	(1<<(COM1B0))
#define avr_TIM1_Out_Clear_OC1B	(1<<(COM1B1))
#define avr_TIM1_Out_Set_OC1B	((1<<COM1B1)|(1<<(COM1B0)))
#define avr_TIM1_Out_Normal_OC1C	0	//&~((1<<COM1C1)|(1<<(COM1C0))) no se usa
#define avr_TIM1_Out_Toggle_OC1C	(1<<(COM1C0))
#define avr_TIM1_Out_Clear_OC1C	(1<<(COM1C1))
#define avr_TIM1_Out_Set_OC1C	((1<<COM1C1)|(1<<(COM1C0)))




typedef enum{
	avr_TIM_Interrupt_source_TimerOverflowIrq_avr,
	avr_TIM_Interrupt_source_TimerCompareMatchAIrq_avr,
	avr_TIM_Interrupt_source_TimerCompareMatchBIrq_avr,
	avr_TIM_Interrupt_source_TimerCompareMatchCIrq_avr,
	avr_TIM_Interrupt_source_TimerInputCampture_avr,
}Interrupt_source_o;


void (*avr_systick_handler) (void);
void (*timer_irq_handler) (void);
void (*avr_pwm_handler) (void);

typedef struct{
	TIMERS_o timernumber;
	TIM_Clock_Source_o ClockSource;
	TIM_MODE_o TIMERMODE;
	unsigned int   output_Type;
	Interrupt_source_o IrqSource;
	void (*timer_irq_handler) (void);
}TimersInitStructure_AVR;

typedef struct{
	TIMERS_o timernumber;
	unsigned long time_ms;
	void (*avr_systick_handler) (void);
}SystickInitStructure_AVR;

typedef struct{
	TIMERS_o timernumber;
	TIM_Clock_Source_o ClockSource;
	unsigned int   output_Type;
	unsigned int dutyA;
	unsigned int dutyB;
	unsigned int dutyC;
	void (*avr_pwm_handler) (void);
}PWMInitStructure_AVR;




#define defined_TIM0 defined (__AVR_ATmega328__) || (__AVR_ATmega328P__) || (__AVR_ATmega8__) || (__AVR_ATmega88__) || (__AVR_ATmega88P__) || (__AVR_ATmega16__) ||(__AVR_ATmega168__) || (__AVR_ATmega168P__) || (__AVR_ATmega32__) || (__AVR_ATmega128__) || (__AVR_ATmega48P__) || (__AVR_ATmega48__)
#define defined_TIM1 defined (__AVR_ATmega328__) || (__AVR_ATmega328P__) || (__AVR_ATmega8__) || (__AVR_ATmega88__) || (__AVR_ATmega88P__) || (__AVR_ATmega16__) ||(__AVR_ATmega168__) || (__AVR_ATmega168P__) || (__AVR_ATmega32__) || (__AVR_ATmega128__) || (__AVR_ATmega48P__) || (__AVR_ATmega48__)
#define defined_TIM2 defined (__AVR_ATmega328__) || (__AVR_ATmega328P__) || (__AVR_ATmega8__) || (__AVR_ATmega88__) || (__AVR_ATmega88P__) || (__AVR_ATmega16__) ||(__AVR_ATmega168__) || (__AVR_ATmega168P__) || (__AVR_ATmega32__) || (__AVR_ATmega128__) || (__AVR_ATmega48P__) || (__AVR_ATmega48__)
#define defined_TIM3 defined (__AVR_ATmega128__)

#if defined_TIM0
void (*tim0irq_user_handler)(void);
#endif

#if defined_TIM1
void (*tim1irq_user_handler)(void);
#endif

#if defined_TIM2
void (*tim2irq_user_handler)(void);
#endif

#if defined_TIM3
void (*tim3irq_user_handler)(void);
#endif

void init_generic_timer(TimersInitStructure_AVR);
void init_Systick_timer(SystickInitStructure_AVR);
void init_Fast_PWm_timer(PWMInitStructure_AVR);


extern volatile bit_t systick_interrupt_flag;
#define Systick_in_Tim0 systick_interrupt_flag.B0
#define Systick_in_Tim1 systick_interrupt_flag.B1
#define Systick_in_Tim2 systick_interrupt_flag.B2
#define Systick_in_Tim3 systick_interrupt_flag.B3



#endif /* AVR_TIMERS_H_ */
