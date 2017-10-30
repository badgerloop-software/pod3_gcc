include makefile.conf

###############################################################################
# Default Settings
PROJECT=e2c
.PHONY: clean FORCE
.DEFAULT_GOAL := $(PROJECT).bin
PROC_DIR=proc
INCLUDES=-I include -I include/CMSIS
TERMINAL=gnome-terminal
DEFINES:=-D__STARTUP_CLEAR_BSS -D__START=main
CORE=CM$(CORTEX_M)
###############################################################################


###############################################################################
# Cross Compiler Settings

FPU = -mfpu=fpv4-sp-d16 -mfloat-abi=softfp

TOOLCHAIN=arm-none-eabi-
CFLAGS=$(FPU) $(ARCH_FLAGS) $(DEFINES) $(CPU_DEFINES) $(INCLUDES) -Wall -ffunction-sections -fdata-sections -fno-builtin -Os
# -Os -nostdlib -lnosys

LDLIBS = -lm
# Linker Settings
LFLAGS=--specs=nosys.specs -Wl,--gc-sections -Wl,-Map=$(PROJECT).map -T$(PROC_DIR)/link.ld
###############################################################################


###############################################################################
# Global Objects
OBJECTS += src/common/main.o

# Conditional Objects
OBJECTS += $(PROC_DIR)/system_stm32l4xx.o
OBJECTS += $(PROC_DIR)/m4start.o

CPUDIR := include/proc

###############################################################################
# Source Rules
%.o: %.S
	+@echo "building $(notdir $<)"
	@$(TOOLCHAIN)gcc $(CFLAGS) $(LDLIBS) -c -o $@ $<

%.o: %.c
	+@echo "building $(notdir $<)"
	@$(TOOLCHAIN)gcc $(CFLAGS) $(LDLIBS) -c -o $@ $<

$(PROJECT).elf: $(OBJECTS)
	+@echo "linking $(notdir $@)"
	@$(TOOLCHAIN)gcc $(LFLAGS) $^ $(CFLAGS) $(LDLIBS) -o $@

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
