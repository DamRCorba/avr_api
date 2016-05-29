# AVR API
Avr Api para ATmega128

El presente proyecto es una API para el microcontrolador Atmega128 de ATMEL.

El API esta escrito siguendo el modelo CMSIS para hacerlo mas familiar.

## GPIO

Para la configuracion de puertos la API provee varios elementos.

### void init_gpio(GpioInitStructure_AVR Gpio);

inicializa al puerto utilizando la Estructura.
```
typedef struct
{
	GPIO_PORT port; // ejemplo - avr_GPIO_A
	GPIO_MODE modo; // avr_GPIO_mode_Input - avr_GPIO_mode_Output
	unsigned char pines; // avr_GPIO_PIN_0 | avr_GPIO_PIN_1
}GpioInitStructure_AVR;
```
Una vez configurado el puerto, se lo puede usar con:

 **set_pin(avr_GPIO_A,0)**

 **clear_pin(avr_GPIO_A,0)**

o bien con macros resueltas

**avr_GPIOA_OUT_0** = 1; //set

**avr_GPIOA_OUT_0** = 0; //clear

Para leer los puertos
**avr_GPIOA_IN_0**

Si quiero leer el o escribir el puerto completo en lugar de a bit.

**avr_GPIOA_OUT**

**avr_GPIOA_IN**

Incluso se puede cambiar la direccion utilizando
**avr_GPIOA_DIR**

*Nota: El ejemplo de arriba es valido para el puerto A, Para el resto de los puertos reemplazar A por la letra corresponiente al puerto.*

## Interrupciones Externas
Las Interrupciones externas del micro pueden ser configuradas por medio de la funcion.

### void init_extern_interrupt(ExternalInterruptInitStructure_AVR);

Al igual que el gpio la configuracion se realiza mediante una Estructura


```
typedef struct
{
	external_interrupt_t interrupcion;				// avr_INT0 ---- avr_INT7
	external_interrupt_mode modo;
	void (*avr_ext_interrupt_handler)(void);		// Funcion de atencion de interrupcion
} ExternalInterruptInitStructure_AVR;
```

los modos de interrupcion son:

```
avr_ext_int_lowlevel
avr_ext_int_anychange
avr_ext_int_fallingedge
avr_ext_int_risingedge
```

## TIMERS
Los *Timers* son sin duda los perifericos mas versatilez de los microcontroladores, la api permite utilizarlos como **Systick** y como **FastPwm**

Para usar a un Timer como Systick se utiliza la funcion

### void init_Systick_timer(SystickInitStructure_AVR);

La estructura de configuración es:

```
typedef struct{
	TIMERS_o timernumber;
	unsigned long time_ms;
	void (*avr_systick_handler) (void);
}SystickInitStructure_AVR;
```
Donde:
timernumber: avr_TIM0, avr_TIM1, avr_TIM2 o avr_TIM3
time_ms: Tiempo en milisegundos.
avr_systick_handler: puntero a funcion de interrupción.

Para usar PWM

### void init_Fast_Pwm_timer(PWMInitStructure_AVR);

Esta estructura es un poco mas compleja.

```
typedef struct{
	TIMERS_o timernumber;
	TIM_Clock_Source_o ClockSource;
	unsigned int output_type;
	unsigned int dutyA;
	unsigned int dutyB;
	unsigned int dutyC;
	void (*avr_pwm_handler) (void);
}PWMInitStructure_AVR;
```
Donde:
timernumber: avr_TIM0, avr_TIM1, avr_TIM2 o avr_TIM3
ClockSource: Fuente de clock / Prescaler
output_type: comportamiento de los pines de salida
dutyX: Ciclo de actividad de cada señal de PWM
avr_pwm_handler: Puntero a funcion para la rutina de interrupcion del overflow.

## ADC
El conversor analogico digital puede ser utilizado tanto con una funcion bloqueante como con interrupciones, para ellos la api facilita las siguientes funciones de configuracion y uso:

### ADC_ERROR init_adc(AdcInitStructure_AVR ADC_init);

ADC_ERROR podra ser error o Exito.


La Estructura de configuracion del ADC se compone por
```
typedef struct
{
	ADC_MODE_t mode;
	ADC_PRES_t prescaler;
	ADC_CANAL_t channel ;
	ADC_RES_t resolution;
	ADC_REF_t reference;
	void (*avr_adc_handler)(void);
}AdcInitStructure_AVR;
```

Donde:
```
mode: 	
	avr_ADC_MODE_Freerunning,		//Convierte siempre y continuamente
	avr_ADC_MODE_Single_Conversion,		//Una Sola Conversion
	avr_ADC_MODE_Interrupt_request,		//Habilita para conve
```
```
prescaler:
	avr_ADC_Prescaler_2 = 1,		//(1) -> Clock MCU /2
	avr_ADC_Prescaler_4,			//(2) -> Clock MCU /4
	avr_ADC_Prescaler_8,			//(3) -> Clock MCU /8
	avr_ADC_Prescaler_16,			//(4) -> Clock MCU /16
	avr_ADC_Prescaler_32,			//(5) -> Clock MCU /32
	avr_ADC_Prescaler_64,			//(6) -> Clock MCU /64
	avr_ADC_Prescaler_128,			//(7) -> Clock MCU /128
```
```
channel:
	avr_ADC_canal0 = 0,		//ADC0
	avr_ADC_canal1 = 1,		//ADC1
	avr_ADC_canal2 = 2,		//ADC2
	avr_ADC_canal3 = 3,		//ADC3
	avr_ADC_canal4 = 4,		//ADC4
	avr_ADC_canal5 = 5,		//ADC5
	avr_ADC_canal6 = 6,		//ADC6
	avr_ADC_canal7 = 7,		//ADC7
```
```
resolution:
	avr_ADC_RES_8Bit,
	avr_ADC_RES_10Bit,
```
```
reference:
	avr_ADC_REF_AREF = 0,
	avr_ADC_REF_AVcc = 1,
	avr_ADC_REF_Internal = 3,
```
```
avr_adc_handler:
		Es la funcion que quiero que se ejecute con el fin de conversion
```

El Valor de la conversion se obtiene por medio de las macros:

**avr_ADC_RETURN_8BIT_RES**

**avr_ADC_RETURN_10BIT_RES**

Finalmente si queremos utilizar al ADC sin interrupciones y con su funcion bloqueante usaremos:

### avr_ADC_Value_t leer_ADC(ADC_CANAL_t canal);									

Solo se le da el canal a convertir y devolvera el valor convertido, esta funcion es bloqueante y la resolucion, referencia y clock del ADC dependera de la funcion init_adc.


## UART

Las libreias UART de la api son las libreias creadas por Peter Fleury con un agregado para manejarlas con el mismo formato de la API.

### void init_uart_avr(UartInitStructure);

La estructura esta formada por:

```
typedef struct
{
	unsigned int baudrate;
	uarts_t uart_port;
}UartInitStructure;
```
donde el baudrate se expresa en valor numerico(9600 por ejemplo).
Y uart_port puede ser avr_UART0 o avr_UART1.

Dentro de las librerias de Peter Fleury disponemos de varias funciones para leer y escribir el puerto. Las mas destacadas son:

### unsigned int uart_getc(void);
Lee un caracter recibido en el puerto UART0

### void uart_putc(unsigned char data);
Escribe un caracter en el puerto UART0

### void uart_puts(const char *s );
Escribe una cadena de caracteres en el puerto UART0

### unsigned int uart1_getc(void);
Lee un caracter recibido en el puerto UART1

### void uart1_putc(unsigned char data);
Escribe un caracter en el puerto UART1

### void uart1_puts(const char *s );
Escribe una cadena de caracteres en el puerto UART1


Para mas informacion sobre las libreias de Peter Fleury. Visite el sitio del autor
Peter Fleury pfleury@gmx.ch  http://jump.to/fleury




