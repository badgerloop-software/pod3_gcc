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

OBJECTS += src/startup.o
OBJECTS += src/main.o

OBJECTS += cfg/system.o
OBJECTS += cfg/vectors.o

$(OBJECTS): | check_configured

include rules/rules.mk
