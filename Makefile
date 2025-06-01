# Variables for utilities
GCC       = arm-none-eabi-gcc
LD        = arm-none-eabi-ld
AS        = arm-none-eabi-as
READELF   = arm-none-eabi-readelf
OBJDUMP   = arm-none-eabi-objdump
OBJCOPY   = arm-none-eabi-objcopy
SYMBOL    = arm-none-eabi-nm

# Variables for source files and object files
SRCS_DIR  = firmware startup_code drivers
# Collect all source files from the specified directories
SRCS := $(foreach dir,$(SRCS_DIR),$(wildcard $(dir)/*.c) $(wildcard $(dir)/*.S))
# Convert .c and .asm files to .o files
OBJS := $(SRCS:.c=.o)
OBJS := $(OBJS:.S=.o)

TARGET = main

# variable for linker scrtip, map file and the readelf output
LD_SCRIPT   = firmware/$(TARGET).ld
LD_MAP      = $(TARGET).map
READELF_OUT = $(TARGET).txt

build: $(TARGET).elf
# Default target to build the project
	@echo "Building the project..."

# this is executed on running 'make'
all: $(READELF_OUT) mainobjdump symbolgen
	@

#genrates objdump of main.elf
mainobjdump: $(TARGET).elf
	$(OBJDUMP) -D $< > $<.s

#generates symbol
symbolgen: $(TARGET).elf
	$(SYMBOL) $< 

# generates the log
$(READELF_OUT): $(TARGET).elf
	$(READELF) -a $^ > $@

# output file
main.elf: $(OBJS) $(LD_SCRIPT)
	@echo "Source files: $(SRCS)"
	@echo "Object files: $(OBJS)"
	$(LD) -T$(LD_SCRIPT) -Map=$(LD_MAP) -o $@ $(OBJS)
	$(OBJCOPY) -O binary $@ $(TARGET).bin
	@echo "Linking complete: $@"
	@echo "Map file generated: $(LD_MAP)"

%.o: %.c
	@echo "Compiling $< to $@"
	@$(GCC) -mapcs-frame -mcpu=cortex-m4 -mlittle-endian -mthumb -Wall -c -g -Os $< -o $@

%.o: %.S
	@echo "Assembling $< to $@"
	@$(GCC) -mcpu=cortex-m4 -mlittle-endian -mthumb -Wall -c -g $< -o $@


clean:
	rm -f *.o *.elf* *.txt *.map *.log *.bin firmware/*.o firmware/*.elf* firmware/*.txt firmware/*.map \
	firmware/*.bin drivers/*.o drivers/*.elf drivers/*.txt drivers/*.map drivers/*.s drivers/*.bin \
	startup_code/*.o startup_code/*.elf* startup_code/*.txt startup_code/*.map startup_code/*.bin
	rm -f $(READELF_OUT) mainobjdump symbolgen
	rm -f $(TARGET).elf $(LD_MAP) $(TARGET).txt
	rm -f $(OBJS)
	@echo "Cleaned up all generated files."

.PHONY: clean mainobjdump all
