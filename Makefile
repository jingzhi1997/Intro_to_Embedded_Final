#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here>
#
#------------------------------------------------------------------------------
include sources.mk

# Every makefile should contain this line, according to the GNU make manual:https://www.gnu.org/software/make/manual/html_node/Makefile-Basics.html, although SHELL is not used in this assignment.

SHELL = /bin/sh

# Platform Overrides
PLATFORM = 

# Default file name of .out and .map outputs
OUT_NAME = c1m2

# PLATFORM switch
ifeq ($(PLATFORM),HOST)

	CC = gcc
	LD = ld
	TARGET = HOST
	
	CFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(TARGET) $(INCLUDES)
	
	LDFLAGS = -Wl,-Map=$(OUT_NAME).map
	
	CPPFLAGS = -D$(TARGET) $(INCLUDES)
	
else ifeq ($(PLATFORM),MSP432)

	LINKER_FILE = ../msp432p401r.lds
	
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	TARGET = MSP432
	
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
	
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wall -Werror -g -O0 -std=c99 -D$(TARGET) $(INCLUDES)
	
	LDFLAGS = -Wl,-Map=$(OUT_NAME).map -T $(LINKER_FILE)
	
	CPPFLAGS = -D$(TARGET) $(INCLUDES)

else

$(error Unknown Platform.)
							
endif


OBJS = $(SOURCES:.c=.o)
ASMS = $(SOURCES:.c=.asm)
PPDS = $(SOURCES:.c=.i)


%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@
	
%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@
	
%.asm : %.c
	$(CC) -S $< $(CFLAGS) -o $@

# Only runs objdump utility if the final executable already exists
ifneq ("$(wildcard ./$(OUT_NAME).out)","")
	objdump -d $(OUT_NAME).out
endif

.PHONY : compile-all
compile-all:$(SOURCES)
	$(CC) -c $^ $(CFLAGS) 


.PHONY : build
build : $(OUT_NAME).out

$(OUT_NAME).out : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@


.PHONY: clean
clean:
	rm -f $(OBJS) $(ASMS) $(PPDS) $(OUT_NAME).out $(OUT_NAME).map
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

