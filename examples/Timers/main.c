#include "hard.h"

volatile unsigned int red[10]={10,20,30,40,50,60,70,80,90,200};
volatile unsigned int blue[10]={10,20,30,40,50,60,70,80,90,200};
volatile unsigned int green[10]={10,20,30,40,50,60,70,80,90,200};
volatile unsigned char i =0;

void mysystick_handler (void){ 
  i = (i<10)? i++ : 0;
}

void mypwm_handler(void)
{
  OCR1A = red[i];
  OCR1B = blue[i];
  OCR1C = green[i];
}


int main (void)

{
	GpioInitStructure_AVR ledrgb;
	SystickInitStructure_AVR base;//mode systick for timer
	PWMInitStructure_AVR mod; // mode Fast PWM for timer

	ledrgb.port =	LED_R;		//Same port for any pin of de led
	sens.modo = 	avr_GPIO_mode_Output;
	sens.pine s=	LED_R_PIN | LED_G_PIN | LED_B_PIN;
	init_gpio (ledrgb);
	
	base.time_ms = 1000; // TIMER time 1 sec
	base.timernumber = avr_TIM2;
	base.avr_systick_handler= mysystick_handler;
	init_Systick_timer(base);

	mod.timernumber = avr_TIM1;
	mod.output_Type = avr_TIM1_Out_Clear_OC1A | avr_TIM1_Out_Clear_OC1B | avr_TIM1_Out_Clear_OC1C;
	mod.ClockSource = avr_TIM_Clock_SystemClockPrescalingx64;
	mod.dutyA = mod.dutyB = mod.dutyC = 0xf0;
	mod.avr_pwm_handler = mypwm_handler;
	init_Fast_PWm_timer(mod);
	
	sei();
	while(1);

	return 0;
}
