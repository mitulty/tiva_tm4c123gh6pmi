# Toolchain
GCC       = arm-none-eabi-gcc
LD        = arm-none-eabi-gcc  # Use GCC for linking
AS        = arm-none-eabi-as
READELF   = arm-none-eabi-readelf
OBJDUMP   = arm-none-eabi-objdump
OBJCOPY   = arm-none-eabi-objcopy
SYMBOL    = arm-none-eabi-nm

# Directories and includes
SRCS_DIR := firmware firmware/ivt firmware/nvic firmware/systick startup_code 
SRCS_DIR += FreeRTOS-Kernel/portable/MemMang FreeRTOS-Kernel FreeRTOS-Kernel/portable/GCC/ARM_CM4F
SRCS_DIR += drivers/gpio

INCLUDES := -Ifirmware -Ifirmware/ivt -Ifirmware/nvic -Ifirmware/systick
INCLUDES += -IFreeRTOS-Kernel/portable/GCC/ARM_CM4F -IFreeRTOS-Kernel/include
INCLUDES += -Idrivers/gpio
OBJ_DIR = obj

# Flags
C_DEFINES := -D__VFP_FP__ -D__NVIC_PRIO_BITS=4 
CFLAGS = -mcpu=cortex-m4 -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wall -g -O2 -ffreestanding -nostdlib
ASFLAGS = $(CFLAGS)

# Files
TARGET = main
LD_SCRIPT   = firmware/$(TARGET).ld
LD_MAP      = $(TARGET).map
READELF_OUT = $(TARGET).elf.s

# Source and object files
SRC_C = $(foreach dir, $(SRCS_DIR), $(wildcard $(dir)/*.c))
SRC_S = $(foreach dir, $(SRCS_DIR), $(wildcard $(dir)/*.S))
SRC_ALL = $(SRC_C) $(SRC_S)

OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_C))
OBJ_FILES += $(patsubst %.S, $(OBJ_DIR)/%.o, $(SRC_S))

# Default target
all: $(READELF_OUT) mainobjdump symbolgen

executable: $(TARGET).elf
	@echo "Generating executable..."
	$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin

# Linking
$(TARGET).elf: $(OBJ_FILES) $(LD_SCRIPT)
	@echo "Linking..."
	# $(LD) $(CFLAGS) $(OBJ_FILES) -T$(LD_SCRIPT) -Wl,-Map=$(LD_MAP),--gc-sections -o $(TARGET).elf
	$(LD) $(CFLAGS) $(OBJ_FILES) -T$(LD_SCRIPT) -Wl,-Map=$(LD_MAP) -o $(TARGET).elf
	$(OBJCOPY) -O binary $@ $(TARGET).bin
	@echo "Build complete: $@"

# Generate objdump
mainobjdump: $(TARGET).elf
	$(OBJDUMP) -D $< > $<.s

# Generate symbols
symbolgen: $(TARGET).elf
	$(SYMBOL) $< 

# Generate readelf output
$(READELF_OUT): $(TARGET).elf
	$(READELF) -a $^ > $@

# Compile C files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	$(GCC) $(INCLUDES) $(C_DEFINES) $(CFLAGS) -c $< -o $@

# Assemble .S files
$(OBJ_DIR)/%.o: %.S
	@mkdir -p $(dir $@)
	@echo "Assembling $<..."
	$(GCC) $(INCLUDES) $(C_DEFINES) $(ASFLAGS) -c $< -o $@

# Clean target
clean:
	rm -rf $(OBJ_DIR) *.elf *.bin *.map *.s *.txt *.map
	@echo "Cleaned."

.PHONY: all clean mainobjdump symbolgen
