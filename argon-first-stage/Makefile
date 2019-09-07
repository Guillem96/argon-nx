ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

include $(DEVKITARM)/base_rules

TARGET          := argon-nx
BUILD           := build
OUTPUT          := ../output
SOURCEDIR       := src
SOURCES         := src \
			src/ianos \
			src/libs/fatfs src/libs/elfload src/libs/compr \
			src/core \
			src/gfx \
			src/mem \
			src/menu/gui \
			src/power \
			src/sec \
			src/soc \
			src/storage \
			src/utils

INCLUDES        := include
VPATH           = $(dir $(wildcard ./$(SOURCEDIR)/*/)) $(dir $(wildcard ./$(SOURCEDIR)/*/*/))
VPATH 		+= $(dir $(wildcard ./$(SOURCEDIR)/*/*/*/)) $(dir $(wildcard ./$(SOURCEDIR)/*/*/*/*/))
CFILES          := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
SFILES          := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))

OFILES_SRC      := $(SFILES:.s=.o) $(CFILES:.c=.o)
HFILES_BIN      := $(addsuffix .h,$(subst .,_,$(BINFILES)))

OBJS            = $(addprefix $(BUILD)/$(TARGET)/, $(OFILES_SRC))


INCLUDE         :=$(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir)) \
		  $(foreach dir,$(LIBDIRS),-I$(dir)/include) \
		  -I$(BUILD)/$(TARGET)

ARCH := -march=armv4t -mtune=arm7tdmi -mthumb -mthumb-interwork
CFLAGS = $(INCLUDE) $(ARCH) -O2 -nostdlib -ffunction-sections -fdata-sections -fomit-frame-pointer -fno-inline -std=gnu11 -Wall
LDFLAGS = $(ARCH) -nostartfiles -lgcc -Wl,--nmagic,--gc-sections


.PHONY: all clean

all: directories $(TARGET).bin
	@echo $(HFILES_BIN)
	@echo -n "Payload size is "
	@wc -c < $(OUTPUT)/$(TARGET).bin
	@echo "Max size is 126296 Bytes."

directories:
	@mkdir -p "$(BUILD)"
	@mkdir -p "$(BUILD)/$(TARGET)"
	@mkdir -p "$(OUTPUT)"
	
clean:
	@rm -rf $(OBJS)
	@rm -rf $(BUILD)
	@rm -f $(OUTPUT)/$(TARGET).bin

$(MODULEDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

$(TARGET).bin: $(BUILD)/$(TARGET)/$(TARGET).elf $(MODULEDIRS)
	$(OBJCOPY) -S -O binary $< $(OUTPUT)/$@

$(BUILD)/$(TARGET)/$(TARGET).elf: $(OBJS)
	$(CC) $(LDFLAGS) -T $(SOURCEDIR)/link.ld $^ -o $@

$(BUILD)/$(TARGET)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/$(TARGET)/%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

$(OFILES_SRC): $(HFILES_BIN)

print-%  : ; @echo $* = $($*)
