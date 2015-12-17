/*
  * Title: avr_Timers.c Timers libs for AVR8
 *  Created on: 8 de jul. de 2015
 *      Author: Ing. Damian Corbalan
 *      brief: This library can manipulate timers to do a systick interrupt, a fast pwm or
 *      a general use timer interrupt.
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


#include "avr_Timers.h"
#include <avr/io.h>
#include <avr/interrupt.h>


volatile bit_t systick_interrupt_flag = {0};
volatile unsigned int tcnt0_value = 0;
volatile unsigned int tcnt1_value = 0;
volatile unsigned int tcnt2_value = 0;
volatile unsigned int tcnt3_value = 0;

//this is a null function for non interrupt purpose
static void null_timer_interrupt(void){}
static TIM_Clock_Source_o getprescaler(unsigned long,unsigned char);

/*
 * This function initializes the timer in any configuration available
 * the timer init structure has all the needed parameters to the startup configuration.
 * TODO: init_generic_timer
 */
void init_generic_timer(TimersInitStructure_AVR generic_time)
{
	switch(generic_time.timernumber)
	{
#if defined_TIM0
	case avr_TIM0: tim0irq_user_handler = null_timer_interrupt; //generic interrupt call
					break;
#endif
#if defined_TIM1
	case avr_TIM1: tim1irq_user_handler = null_timer_interrupt; //generic interrupt call
					break;
#endif
#if defined_TIM2
	case avr_TIM2: tim2irq_user_handler = null_timer_interrupt; //generic interrupt call
					break;
#endif
#if defined_TIM3
	case avr_TIM3: tim3irq_user_handler = null_timer_interrupt; //generic interrupt call
					break;
#endif
	default: break;
	}

}


/*
 *	This function initializes the timer to interrupt in a given time.
 *	Its auto calculates the prescaler an the TCNTX value.
 */
void init_Systick_timer(SystickInitStructure_AVR Systick_data)
{
	TIM_Clock_Source_o prescaler = avr_TIM_Clock_NoClockSource;
	unsigned int prescaler_value[6] = {0, 1 , 8, 64 , 256 ,1024};
	unsigned int pres_val[8] = {0,1,8,32,64,128,256,1024};

	/*  Abstract: Prescaler and tcnt calculation explanation
	 * (1/Ftim)*tcnt = time => tcnt/Ftim = time
	 * Ftim = F_CPU/prescaler => (tcnt*prescaler)/F_CPU = time
	 * time * F_CPU = tcnt*prescaler - First rule
	 *
	 * Second rule - Max time for prescaler
	 * if 8 bit
	 * if (256 * prescaler > tcnt*prescaler) => prescaler ++;
	 * if 16 bit
	 * if (0xffff * prescaler > tcnt*prescaler) => prescaler ++;
	 *
	 * when we had selected the prescaler window we only have a variable
	 *
	 * tcnt = time * F_CPU / prescaler;
	 *
	 */

	switch(Systick_data.timernumber)
	{
#if defined_TIM0
	case avr_TIM0:  prescaler = getprescaler(Systick_data.time_ms, 8);
					switch(prescaler){
					case	avr_TIM_Clock_SystemClockPrescalingx64: prescaler =4;
						break;
					case avr_TIM_Clock_SystemClockPrescalingx256: prescaler =6;
											break;
					case avr_TIM_Clock_SystemClockPrescalingx1024: prescaler =7;
											break;
					default: break;

					}
					//time * F_CPU / prescaler = counternumber
					TCCR0 = 0x00 | prescaler; //Normal mode + prescaler
					TIMSK |= (1<<TOIE0);	  //Enable Overflow interrupt for timer 0
					Systick_in_Tim0 = 1;	  // flag to recharge TCNT value
					tcnt0_value = 256 - (unsigned int)((float)(F_CPU * Systick_data.time_ms) / (float)(1000 * pres_val[prescaler]));
					TCNT0 = tcnt0_value;
					tim0irq_user_handler = (Systick_data.avr_systick_handler)?
											Systick_data.avr_systick_handler  :
											null_timer_interrupt; //generic interrupt call
					break;
#endif
#if defined_TIM1
	case avr_TIM1: prescaler = getprescaler(Systick_data.time_ms, 16);
				   TCCR1A = TCCR1C = 0x00;
				   TCCR1B = 0x00 | prescaler;
				   Systick_in_Tim1 = 1;	  // flag to recharge TCNT value
				   TIMSK |= (1<<TOIE1);	  //Enable Overflow interrupt for timer 1
				   tcnt1_value = 65536 - (unsigned int)((float)(F_CPU * Systick_data.time_ms) / (float)(1000 * prescaler_value[prescaler]));
				   TCNT1 = tcnt1_value;
				   tim1irq_user_handler = (Systick_data.avr_systick_handler) ?
										   Systick_data.avr_systick_handler  :
										   null_timer_interrupt; //generic interrupt call
					break;
#endif
#if defined_TIM2
	case avr_TIM2:  prescaler = getprescaler(Systick_data.time_ms, 8);
					TCCR2 = 0x00 | prescaler; //Normal mode + prescaler
					TIMSK |= (1<<TOIE2);	  //Enable Overflow interrupt for timer 0
					Systick_in_Tim2 = 1;	  // flag to recharge TCNT value
					tcnt2_value = 256 - (unsigned int)((float)(F_CPU * Systick_data.time_ms) / (float)(1000 * prescaler_value[prescaler]));
					TCNT2 = tcnt2_value;
					tim2irq_user_handler = (Systick_data.avr_systick_handler)?
											Systick_data.avr_systick_handler  :
											null_timer_interrupt; //generic interrupt call
					break;
#endif
#if defined_TIM3
	case avr_TIM3: prescaler = getprescaler(Systick_data.time_ms, 16);

		           TCCR3A = TCCR3C = 0x00;
				   TCCR3B = 0x00 | prescaler;
				   Systick_in_Tim3 = 1;	  // flag to recharge TCNT value
			   	   ETIMSK |= (1<<TOIE3);	  //Enable Overflow interrupt for timer 1
				   tcnt3_value = 65536 - (unsigned int)((float)(F_CPU * Systick_data.time_ms) / (float)(1000 * prescaler_value[prescaler]));
				   TCNT3 = tcnt3_value;
				   tim3irq_user_handler = (Systick_data.avr_systick_handler) ?
										   Systick_data.avr_systick_handler  :
										   null_timer_interrupt; //generic interrupt call

					break;
#endif
	default: break;
	}

}


/*
  function that initializes the timer as PWM signal.
  
  TODO: confifuration for Timer 2 and Timer 3
 */
void init_Fast_PWm_timer(PWMInitStructure_AVR Pwm_states)
{
	switch(Pwm_states.timernumber)
		{
#if defined_TIM0
	case avr_TIM0:	TCNT0 = 0x00;
					TCCR0 |= (1<< WGM00) | (1<< WGM01); // Setea al Timer 0 como Fast PWM
					TCCR0 |= Pwm_states.ClockSource; // revisar valores de variables
					TCCR0 |= Pwm_states.output_Type;
					OCR0 = Pwm_states.dutyA;
					TIMSK |= (1<<TOIE0);	  //Enable Overflow interrupt for timer 0
					tim0irq_user_handler = (Pwm_states.avr_pwm_handler) ?
											Pwm_states.avr_pwm_handler  :
											null_timer_interrupt; //generic interrupt call
					break;
#endif
#if defined_TIM1
	case avr_TIM1:  TCNT1 = 0x00;
					TCCR1A |=  (1<< WGM10); // Setea al Timer 0 como Fast PWM
					TCCR1B |= (1<< WGM12);
					TCCR1B |= Pwm_states.ClockSource; // revisar valores de variables
					TCCR1A |= Pwm_states.output_Type;
					OCR1A = Pwm_states.dutyA;
					OCR1B = Pwm_states.dutyB;
					OCR1C = Pwm_states.dutyC;
					TIMSK |= (1<<TOIE1);	  //Enable Overflow interrupt for timer 0
					tim1irq_user_handler = (Pwm_states.avr_pwm_handler) ?
											Pwm_states.avr_pwm_handler  :
											null_timer_interrupt; //generic interrupt call
					break;
#endif
#if defined_TIM2
	case avr_TIM2: tim2irq_user_handler = null_timer_interrupt; //generic interrupt call
					break;
#endif
#if defined_TIM3
	case avr_TIM3: TCNT3 = 0x00;
					TCCR3A |=  (1<< WGM30); // Setea al Timer 0 como Fast PWM
					TCCR3B |= (1<< WGM32);
					TCCR3B |= Pwm_states.ClockSource; // revisar valores de variables
					TCCR3A |= Pwm_states.output_Type;
					OCR3A = Pwm_states.dutyA;
					OCR3B = Pwm_states.dutyB;
					OCR3C = Pwm_states.dutyC;
					ETIMSK |= (1<<TOIE3);	  //Enable Overflow interrupt for timer 0
					tim3irq_user_handler = (Pwm_states.avr_pwm_handler) ?
											Pwm_states.avr_pwm_handler :
											null_timer_interrupt; //generic interrupt call
	break;
#endif
		default: break;
		}



}




// privates and ISR vector calling
/*  Abstract: Prescaler and tcnt calculation explanation
 * (1/Ftim)*couternumber = time => counternumber/Ftim = time
 * Ftim = F_CPU/prescaler
 *  => time = (counternumber * prescaler) / F_CPU
 *  => time * F_CPU / prescaler = counternumber
 *  => time in seconds, F_CPU in Hertz - First Rule
 *  => maxTime = 256 * prescaler / F_CPU for 8 bits
 *  => maxTime = 0x10000 * prescaler / F_CPU for 16 bits
 *
 * Second rule - Max time for prescaler
 * if 8 bit
 * if (256 * prescaler > tcnt*prescaler) => prescaler ++;
 * if 16 bit
 * if (0xffff * prescaler > tcnt*prescaler) => prescaler ++;
 *
 * when we had selected the prescaler window we only have a variable
 *
 * tcnt = time * F_CPU / prescaler;
 *
 */
static TIM_Clock_Source_o getprescaler(unsigned long ctime, unsigned char blength){

	TIM_Clock_Source_o prescaler = avr_TIM_Clock_SystemClockPrescalingx1;

	unsigned int prescaler_values[5] = {1 , 8, 64 , 256 ,1024};
	unsigned int pres_val[7] = {1,8,32,64,128,256,1024};
	unsigned char pos = 0;

	for(pos = 0; pos <= avr_TIM_Clock_SystemClockPrescalingx1024; pos++){
		if(blength == 8)
			{
			if((unsigned long)(0x100 * prescaler_values[pos]) >= ((ctime)*F_CPU/1000))
					return (prescaler + pos);

			}
		if(blength == 16)
			{
			if((unsigned long)(0x10000 * prescaler_values[pos]) >= ((ctime)*F_CPU/1000))
				return (prescaler + pos);
			}
		if(!blength)
		{
			if((unsigned long)(0x100 * pres_val[pos]) >= ((ctime)*F_CPU/1000))
								return (prescaler + pos);
		}

	}
	return avr_TIM_Clock_NoClockSource;	//If the it can select a prescaler it will return no clock

}

// TODO: call another type of interrupt request

// Overflow interrupt Vectors

#if defined_TIM0
ISR(TIMER0_OVF_vect)
{
	if(Systick_in_Tim0) TCNT0 = tcnt0_value; // if used like systick it reload the value to the timer
	(*tim0irq_user_handler)();
}
#endif

#if defined_TIM1
ISR(TIMER1_OVF_vect)
{
	if(Systick_in_Tim1) TCNT1 = tcnt1_value; // if used like systick it reload the value to the timer
	(*tim1irq_user_handler)();
}
#endif


#if defined_TIM2
ISR(TIMER2_OVF_vect)
{
	if(Systick_in_Tim2) TCNT2 = tcnt2_value; // if used like systick it reload the value to the timer
	(*tim2irq_user_handler)();
}
#endif


#if defined_TIM3
ISR(TIMER3_OVF_vect)
{
	if(Systick_in_Tim3) TCNT3 = tcnt3_value; // if used like systick it reload the value to the timer
	(*tim3irq_user_handler)();
}
#endif






