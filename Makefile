# Default target
default: all


#==============================================================================#
# Build Options                                                                #
#==============================================================================#

TARGET := tnt

OPT_FLAGS := -mips1 -O1

VERSION := J


#==============================================================================#
# Target Executable and Sources                                                #
#==============================================================================#

# BUILD_DIR is the location where all build artifacts are placed
BUILD_DIR      := build
#BUILD_DIR      := expected/build
ROM            := $(BUILD_DIR)/$(TARGET).z64
ELF            := $(BUILD_DIR)/$(TARGET).elf
LD_SCRIPT      := newtetris.ld

# Directories containing source files
SRC_DIRS := assets assets/y assets/image assets/anim assets/dcm assets/x asm asm/data src src/newtetris src/ultralib/gu asm/newtetris asm/data/newtetris asm/data/rsp asm/ultralib/audio asm/ultralib/debug asm/ultralib/gu asm/ultralib/io asm/ultralib/libc asm/ultralib/os asm/ultralib/sched asm/ultralib/vimodes asm/data/ultralib/audio asm/data/ultralib/debug asm/data/ultralib/gu asm/data/ultralib/io asm/data/ultralib/libc asm/data/ultralib/os asm/data/ultralib/sched asm/data/ultralib/vimodes

# Source code files
C_FILES           := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES           := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.s))
BIN_FILES         := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.bin))

# Object files
O_FILES := $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
           $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.o)) \
           $(foreach file,$(BIN_FILES),$(BUILD_DIR)/$(file:.bin=.o))

# Files with GLOBAL_ASM blocks
GLOBAL_ASM_C_FILES != test -d src && find src -type f -name '*.c' -print0 | xargs -0 grep -l 'GLOBAL_ASM('
GLOBAL_ASM_O_FILES = $(foreach file,$(GLOBAL_ASM_C_FILES),$(BUILD_DIR)/$(file:.c=.o))


#==============================================================================#
# Compiler Options                                                             #
#==============================================================================#

CROSS ?= mips64-linux-gnu-

AS            := $(CROSS)as
LD            := $(CROSS)ld
OBJCOPY       := $(CROSS)objcopy

ifeq ($(CROSS),mips64-linux-gnu-)
  LDFLAGS     := -melf32btsmip
else
  LDFLAGS     :=
endif

IDO_ROOT      := /opt/ido-static-recomp/5.3/bin
CC            := $(IDO_ROOT)/cc

VERSION_D := 1
VERSION_E := 2
VERSION_F := 3
VERSION_G := 4
VERSION_H := 5
VERSION_I := 6
VERSION_J := 7
VERSION_K := 8
VERSION_L := 9

VERSION_DEFINE := -DBUILD_VERSION=$(VERSION_$(VERSION))

TARGET_CFLAGS := -nostdinc -D_LANGUAGE_C -DNDEBUG -D_FINALROM -DF3DEX_GBI_2 -D_MIPS_SZLONG=32 $(VERSION_DEFINE)

INCLUDE_DIRS := /opt/ultralib/include /opt/ultralib/include/ido include include/minilzo

DEF_INC_CFLAGS := $(foreach i,$(INCLUDE_DIRS),-I$(i))

CFLAGS = -G 0 $(OPT_FLAGS) $(TARGET_CFLAGS) $(DEF_INC_CFLAGS)
CFLAGS += -non_shared -Wab,-r4300_mul -Xcpluscomm -fullwarn -32

ASFLAGS := $(foreach i,$(INCLUDE_DIRS),-I$(i)) -march=vr4300 -mabi=32


#==============================================================================#
# Main Targets                                                                 #
#==============================================================================#

all: $(ROM)

clean:
	$(RM) -r $(BUILD_DIR)

ALL_DIRS := $(addprefix $(BUILD_DIR)/,$(SRC_DIRS))

# Make sure build directory exists before compiling anything
$(shell mkdir -p $(ALL_DIRS))


#==============================================================================#
# Generated Source Code Files                                                  #
#==============================================================================#

# Run asm-processor
$(GLOBAL_ASM_O_FILES): CC := python3 /opt/asm-processor/build.py $(CC) -- $(AS) $(ASFLAGS) --


#==============================================================================#
# Compilation Recipes                                                          #
#==============================================================================#

# Compile C code
$(BUILD_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

# Alternate compiler flags needed for matching
$(BUILD_DIR)/src/newtetris/contq.o: OPT_FLAGS := -mips2 -O2
$(BUILD_DIR)/src/newtetris/sprite.o: OPT_FLAGS := -mips2 -O2
$(BUILD_DIR)/src/newtetris/frametime.o: OPT_FLAGS := -mips2 -O2

# Assemble assembly code
$(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

# Create .o files from .bin files
$(BUILD_DIR)/%.o: %.bin
	$(LD) $(LDFLAGS) -r -b binary -o $@ $<

# Link tnt64 ELF file
$(ELF): $(O_FILES) $(LD_SCRIPT) undefined_syms_auto.txt
	$(LD) $(LDFLAGS) -T $(LD_SCRIPT) -T undefined_syms_auto.txt -o $@

# Build ROM
$(ROM): $(ELF)
	$(OBJCOPY) $< $@ -O binary



.PHONY: all clean default
# with no prerequisites, .SECONDARY causes no intermediate target to be removed
.SECONDARY:

# Remove built-in rules, to improve performance
MAKEFLAGS += --no-builtin-rules

# --- Debugging
# run `make print-VARIABLE` to debug that variable
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
