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

## ADC
El conversor analogico digital puede ser utilizado tanto con una funcion bloqueante como con interrupciones, para ellos la api facilita las siguientes funciones de configuracion.
