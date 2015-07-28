#!/usr/bin/make
###############################################################################
# Makefile for the project GPIO
#  LICENCE
# *   Copyright (C) 2015 Damian Corbalan & David Caruso
# *
# *	 This program is free software; you can redistribute it and/or modify
# *   it under the terms of the GNU General Public License as published by
# *   the Free Software Foundation; either version 3 of the License, or
# *   any later version.
# *
# *   This program is distributed in the hope that it will be useful,
# *   but WITHOUT ANY WARRANTY; without even the implied warranty of
# *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# *   GNU General Public License for more details.
###############################################################################

## General Flags
OBJDIR=Generado
PRJ = gpio
MCU = atmega128
FCPU = 16000000UL
TARGET = $(OBJDIR)/$(PRJ).elf
CC = avr-gcc
OPT = s
AVR_API_R= ../../avr_api

VPATH = $(AVR_API_R)

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -gdwarf-2 -std=gnu99 -DF_CPU=$(FCPU) -O$(OPT) -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(OBJDIR)/$(*F).o -MF $(OBJDIR)/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=$(OBJDIR)/$(PRJ).map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Libraries
LIBS = -lm -lc 

C_FILES := $(wildcard *.c)
AVR_FILES := $(wildcard $(AVR_API_R)/*.c)
MY_OBJ_FILES := $(addprefix $(OBJDIR)/,$(notdir $(C_FILES:.c=.o)))
AVR_OBJ_FILES := $(addprefix $(OBJDIR)/,$(notdir $(AVR_FILES:.c=.o)))

## Objects that must be built in order to link
OBJECTS = $(AVR_OBJ_FILES) $(MY_OBJ_FILES)

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(OBJDIR) $(TARGET) $(OBJDIR)/$(PRJ).hex $(OBJDIR)/$(PRJ).eep $(OBJDIR)/$(PRJ).lss size

## Compile
$(OBJDIR):
	mkdir $@
	echo "$(AVR_FILES)"

$(OBJDIR)/%.o: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $< -o $@

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

$(OBJDIR)/%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

$(OBJDIR)/%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

$(OBJDIR)/%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}
	
$(OBJDIR)/$(PRJ).asm: ${TARGET}
	avr-objdump -S $< > $@

asm: $(OBJDIR)/$(PRJ).asm

## FUSES
low_fuse:
	avrdude -p $(MCU) -c usbtiny  -U lfuse:w:0xCE:m	 #    // grabación de Low Fuse internal clock

high_fuse:
	avrdude -p $(MCU) -c usbtiny  -U hfuse:w:0xC9:m	 #    // grabación de High Fuse

not_103c:
	avrdude -p $(MCU) -c usbtiny  -U efuse:w:0xFF:m	 #    // grabación de Low Fuse internal clock

erase:
	avrdude -p $(MCU) -c usbtiny  -e	                #    //borrado del micro
	
load_prg: 
	avrdude -p $(MCU) -c usbtiny  -U flash:w:$(OBJDIR)/$(PRJ).hex:a #    // grabación del programa
	
verify:	
	avrdude -p $(MCU) -c usbtiny  -U flash:v:$(OBJDIR)/$(PRJ).hex:a	#    // verificación

clean:
	rm -r $(OBJDIR)



