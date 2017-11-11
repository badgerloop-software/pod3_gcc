include makefile.conf

###############################################################################
# Default Settings
PROJECT=e2c
.PHONY: clean FORCE
.DEFAULT_GOAL := $(PROJECT).bin
PROC_DIR=proc
INCLUDES=-I include -I include/CMSIS
TERMINAL=gnome-terminal
CORE=CM$(CORTEX_M)
###############################################################################


###############################################################################
TOOLCHAIN=arm-none-eabi-
CFLAGS= -Wall $(ARCH_FLAGS) $(CPU_DEFINES) $(INCLUDES) -Wall -Os
# -Os -nostdlib -lnosys

LDLIBS = -lm
# Linker Settings
LFLAGS=$(ARCH_FLAGS) $(CPU_DEFINES) -T$(PROC_DIR)/STM32L432KCUx_FLASH.ld -Wl,--gc-sections
###############################################################################


###############################################################################
# Global Objects
OBJECTS += src/common/main.o
#OBJECTS += src/common/post.o
#OBJECTS += src/common/retarget.o
#OBJECTS += src/common/pcbuffer.o
#OBJECTS += src/common/handlers.o
#OBJECTS += src/common/nuc32.o

# Conditional Objects
OBJECTS += $(PROC_DIR)/system_stm32l4xx.o
OBJECTS += $(PROC_DIR)/startup_stm32l432xx.o
#OBJECTS += src/drivers/$(PROC_PREFIX)gpio.o
#OBJECTS += src/drivers/$(PROC_PREFIX)rcc.o
#OBJECTS += src/drivers/$(PROC_PREFIX)usart.o
#OBJECTS += src/drivers/timer.o

CPUDIR := include/proc

###############################################################################
# Source Rules
%.o: %.s
	+@echo "building $(notdir $<)"
	@$(TOOLCHAIN)gcc $(CFLAGS) -c -o $@ $<

%.o: %.c
	+@echo "building $(notdir $<)"
	@$(TOOLCHAIN)gcc $(CFLAGS) -c -o $@ $<

$(PROJECT).elf: $(OBJECTS)
	+@echo "linking $(notdir $@)"
	@$(TOOLCHAIN)gcc $(LFLAGS) $^ $(CFLAGS) -o $@

$(PROJECT).bin: $(PROJECT).elf
	@$(TOOLCHAIN)objcopy -O binary $< $@
	+@echo "Ready to flash $@."

# Project Rules
$(OBJECTS): | $(CPUDIR) FORCE

$(CPUDIR):
	+@echo "Creating $@"
	@ln -s ../$(PROC_DIR) $@

clean:
	@rm -f *.bin *.map *.elf $(CPUDIR) output.txt
	@find . -name '*.o' -delete

install: $(PROJECT).bin
	./$(PROC_DIR)/install.sh

%_config:
	@echo $@
###############################################################################
