#Main application file name
MAIN_APP = main

## For testing
TEST_MAIN = maintest

TEST_SRC = main.c\
src/ECG_trans2.c\

unity/unity.c

TEST_INC = -Iheader\
-Iunity\

#Main hex file path in windows format
MAIN_HEX_PATH = C:\Project\M2-EmbSys\Project\3_Implementation\$(MAIN_APP).hex

ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	   EXEC = out
   endif
endif

# Compiler and other Section
CC = avr-gcc
OBJCOPY = avr-objcopy.exe
# AVRDUDE := avrdude

#Options for avr-gcc
CFLAGS = -g -Os -o

#Linking options for avr-gcc
LFLAGS = -Os -mmcu=atmega328 -o

#Options for HEX file generation
HFLAGS = -j .text -j .data -O ihex


# Sources files needed for building the application 
SRC = src/$(MAIN_APP).c src/project.c 


# The headers files needed for building the application
INCLUDE = -Iheader/project.h.

# commands Section
Burn : Build
	$(AVRDUDE) $(DUDEFLAGS)

Build : $(MAIN_APP).elf
	$(OBJCOPY) $(HFLAGS) $< $(MAIN_APP).hex
	
$(MAIN_APP).elf: $(MAIN_APP).o
	$(CC) $(SRC) $(INCLUDE) $(LFLAGS) $@
	
$(MAIN_APP).o:$(SRC)
	$(CC) $^ $(INCLUDE) $(CFLAGS) $@

build_test : 
	gcc $(TEST_SRC) $(TEST_INC) -o $(call FixPath,$(TEST_MAIN).$(EXEC)) -lm

run_test : build_test
	./$(call FixPath,$(TEST_MAIN).$(EXEC))
	
static_analysis:
	cppcheck --enable=all $(SRC)

clear :
	rm -r *.o *.elf *.hex *.out


