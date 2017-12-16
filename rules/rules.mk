%.o: %.cpp
	+@echo "building $(notdir $<)"
	@$(TOOLCHAIN)g++ $(CXXFLAGS) -c -o $@ $<

%.o: %.c
	+@echo "building $(notdir $<)"
	@$(TOOLCHAIN)gcc $(CFLAGS) -c -o $@ $<

$(PROJECT).elf: $(OBJECTS)
	+@echo ""
	+@echo "linking $(notdir $@)"
	@$(TOOLCHAIN)gcc $(CFLAGS) $^ $(LFLAGS) -o $@

$(PROJECT).bin: $(PROJECT).elf
	@$(TOOLCHAIN)objcopy -O binary $< $@
	+@echo "Ready to flash $@."

###############################################################################

$(OBJDUMP_FILE): $(PROJECT).bin
	@$(TOOLCHAIN)objdump -D $(PROJECT).elf > $(OBJDUMP_FILE)
	+@echo "Dumping disassembly from $(PROJECT).elf to $(OBJDUMP_FILE)."

debug: install
	sleep 2
	st-util &
	sleep 2
	@$(TOOLCHAIN)gdb $(PROJECT).elf
	pkill st-util

install: $(PROJECT).bin
	@./cfg/install.sh

dump: $(OBJDUMP_FILE)
	@vim $(OBJDUMP_FILE)

clean:
	@rm -f *.bin *.map *.elf $(CPUDIR) $(OBJDUMP_FILE)
	@find . -name '*.o' -delete
	+@echo "clean complete."

cfg/conf.mk:
	@echo ""
	@echo "Run ./configure.sh to configure your build first."
	@echo ""

check_configured:
	@test -d cfg
	+@echo "Configured for:" && echo ""
	+@readlink cfg
	+@echo ""
