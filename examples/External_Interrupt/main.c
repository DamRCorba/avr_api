#include "hard.h"
//Funcion que se usara para atender la interrupcion de un pulsador
void SW1_handler(void){
  LED_1 ^=1; //LED_1 togle
  
}


int main (void)

{
	GpioInitStructure_AVR leds;//GPIO only for led use
	//example of External Interrupt Init
	ExternalInterruptInitStructure_AVR pulsadores_irq;
	
	pulsadores_irq.modo = avr_ext_int_lowlevel;
	pulsadores_irq.interrupcion= PUL1_IRQ;
	pulsadores_irq.avr_ext_interrupt_handler=SW1_handler;
	init_extern_interrupt(pulsadores_irq);
	
	//Led init
	
	leds.modo = avr_GPIO_mode_Output;
	leds.port = LED_1_GPIO_PORT; // es el mismo puerto para todos los leds.
	leds.pines = LED_1_GPIO_PIN | LED_2_GPIO_PIN | LED_3_GPIO_PIN | LED_4_GPIO_PIN;
	init_gpio(leds);
	
	sei();//SEI instruccion not inculude in api
	while(1){
	}
	
	

	return 0;
}
