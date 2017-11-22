#
# Badgerloop Controls Team
#
# Authors: Vaughn Kottler
#

TOOLCHAIN=arm-none-eabi-

FPU = -mfpu=fpv4-sp-d16 -mfloat-abi=softfp

# -Os -nostdlib -lnosys
CFLAGS = $(FPU) $(ARCH_FLAGS) $(DEFINES) $(CPU_DEFINES) $(INCLUDES)
CFLAGS += -Wall -ffunction-sections -fdata-sections -fno-builtin -Os

# Linker Settings
LFLAGS = --specs=nosys.specs -Wl,--gc-sections -Wl,-Map=$(PROJECT).map
LFAGS += -T$(PROC_DIR)/link.ld
