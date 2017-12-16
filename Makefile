include cfg/conf.mk

###############################################################################

.PHONY: clean dump install debug check_configured

PROJECT = bare_metal

OBJDUMP_FILE = output.txt

.DEFAULT_GOAL := $(PROJECT).bin

###############################################################################

TOOLCHAIN=arm-none-eabi-

CPU_DEFINES += -D__START=main

INCLUDES = -I include -I include/cmsis -I cfg/include

include rules/flags.mk

###############################################################################

# Shared
OBJECTS += src/startup.o
OBJECTS += src/main.o

# Processor Specific
OBJECTS += cfg/system.o
OBJECTS += cfg/vectors.o

# Drivers
OBJECTS += src/drivers/gpio.o
OBJECTS += src/drivers/rcc.o

$(OBJECTS): | check_configured

include rules/rules.mk
