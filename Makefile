#
# Badgerloop Controls Team
#
# Authors: Vaughn Kottler
#

# Pull in processor-specific config
include config.mk
PROJECT = $(PROC)
PROC_DIR = proc/$(PROC)
include $(PROC_DIR)/conf.mk

# Pull in other project configs
include cc.mk
include objects.mk

###############################################################################
# Default Settings

CPUDIR = include/proc

.DEFAULT_GOAL = $(PROJECT).bin
.PHONY: clean FORCE

INCLUDES = -I include -I include/cmsis -I $(PROC_DIR)
DEFINES = -D__STARTUP_CLEAR_BSS -D__START=main
###############################################################################


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

FORCE:
	+@echo "Re-building timestamps"

$(OBJECTS): | $(CPUDIR) FORCE

clean:
	@rm -f *.bin *.map *.elf $(CPUDIR) output.txt
	@find . -name '*.o' -delete

install: $(PROJECT).bin
	./$(PROC_DIR)/install.sh

$(CPUDIR):
	+@echo "Creating $@"
	@ln -s ../$(PROC_DIR) $@
###############################################################################


###############################################################################
# Debug related recipes

debug: $(PROJECT).bin
	./$(PROC_DIR)/debug.sh

TERMINAL=gnome-terminal
OBJDUMP_FILE=output.txt

$(OBJDUMP_FILE): $(PROJECT).bin
	$(TOOLCHAIN)objdump -D $(PROJECT).elf > $(OBJDUMP_FILE)

dump: $(OBJDUMP_FILE)
	$(TERMINAL) -e "vim $(OBJDUMP_FILE)"
###############################################################################
