# avr_api
Avr Api para ATmega128

El presente proyecto es una API para el microcontrolador Atmega128 de ATMEL.

El API esta escrito siguendo el modelo CMSIS para hacerlo mas familiar.

## GPIO

Para la configuracion de puertos la API provee varios elementos.

### void init_gpio(GpioInitStructure_AVR Gpio);

inicializa al puerto utilizando la Estructura.

typedef struct
{
	GPIO_PORT port; // ejemplo - avr_GPIO_A
	GPIO_MODE modo; // avr_GPIO_mode_Input - avr_GPIO_mode_Output
	unsigned char pines; // avr_GPIO_PIN_0 | avr_GPIO_PIN_1
}GpioInitStructure_AVR;

Una vez configurado el puerto, se lo puede usar con:

 **set_pin(avr_GPIO_A,0)**
 **clear_pin(avr_GPIO_A,0)**

o bien con macros resueltas

**avr_GPIOA_OUT_0** = 1; //set
**avr_GPIOA_OUT_0** = 0; //clear

Para leer los puertos
**avr_GPIOA_IN_0**

Si quiero leer el o escribir el puerto completo en lugar de a bit.

**avr_GPIOA_OUT
avr_GPIOA_IN**

Incluso se puede cambiar la direccion utilizando
**avr_GPIOA_DIR**

*Nota: El ejemplo de arriba es valido para el puerto A, Para el resto de los puertos reemplazar A por la letra corresponiente al puerto.*
