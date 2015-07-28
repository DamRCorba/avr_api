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
	TIM0_AVR = 0,
	TIM1_AVR= 1,
	TIM2_AVR = 2,
	TIM3_AVR =3,
}AVR_TIMERS_o;


typedef enum {
	AVR_TIM_Select_NoClockSource = 0,
	AVR_TIM_Select_SystemClockPrescalingx1 = 1,
	AVR_TIM_Select_SystemClockPrescalingx8 = 2,
	AVR_TIM_Select_SystemClockPrescalingx64 = 3,
	AVR_TIM_Select_SystemClockPrescalingx256 = 4,
	AVR_TIM_Select_SystemClockPrescalingx1024 = 5,
	AVR_TIM_Select_ExternalClock_Falling = 6,
	AVR_TIM_Select_ExternalClock_Rising = 7,
}AVR_TIM_Clock_Source_o;

typedef enum{
	NormalTop, //top on overflow
	PhaseCorrectPWMTop0xFF,
	CTCTopOCR0A,
	FastPwmTop0xFF,
	PhaseCorrectPWMTopOCR0A,
	FastPwmTopOCR0A,
}AVR_TIM_MODE_o;

#define TimerOutADisconnected 0x0001UL
#define TimerOutAToggle       0x0002UL
#define TimerOutASet 	      0x0004UL
#define TimerOutAClear 	      0x0008UL
#define TimerOutBDisconnected 0x0010UL
#define TimerOutBToggle       0x0020UL
#define TimerOutBSet 	      0x0040UL
#define TimerOutBClear 	      0x0080UL
#define TimerOutCDisconnected 0x0100UL
#define TimerOutCToggle       0x0200UL
#define TimerOutCSet 	      0x0400UL
#define TimerOutCClear        0x0800UL



typedef enum{
	TimerOverflowIrq_avr,
	TimerCompareMatchAIrq_avr,
	TimerCompareMatchBIrq_avr,
	TimerCompareMatchCIrq_avr,
	TimerInputCampture_avr,
}AVR_Interrupt_source_o;


#define Tim_Handler (*timer_irq_handler)
#define SysticHandler (*timer_as_Systic)
#define PWM_Handler (*timer_as_pwm)
void SysticHandler (void);
void Tim_Handler (void);
void PWM_Handler (void);

typedef struct{
	AVR_TIMERS_o timernumber;
	AVR_TIM_Clock_Source_o ClockSource;
	AVR_TIM_MODE_o TIMERMODE;
	unsigned int   output_Type;
	AVR_Interrupt_source_o IrqSource;
	void Tim_Handler (void);
}TimersInitStructure_AVR;

typedef struct{
	AVR_TIMERS_o timernumber;
	unsigned long time_ms;
	void SysticHandler (void);
}SystickInitStructure_AVR;

typedef struct{
	AVR_TIMERS_o timernumber;
	AVR_TIM_Clock_Source_o ClockSource;
	unsigned int   output_Type;
	unsigned int dutyA;
	unsigned int dutyB;
	unsigned int dutyC;
	void PWM_Handler (void);
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
