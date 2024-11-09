CC = gcc
CFLAG = -c
FILENAME = fibonacci


run: build/sim
	cd build && ./assembler ../$(FILENAME.asm)
	cd build && ./sim ../$(FILENAME.bin)

all: createDR simulator.o load.o decoder.o immediate.o Mux.o ALU.o jump.o fetch.o
	cd build && $(CC) -o sim simulator.o load.o decoder.o immediate.o Mux.o ALU.o jump.o fetch.o
	cd build && $(CC) -o assembler convbin_code.c

%.o: %.c
	cd build && $(CC) $(CFLAG) ../$<

%.o: allFiles/%.c
	cd build && $(CC) $(CFLAG) ../$<

createDR:
	mkdir -p build

clean : 
	rm -r build

help :
	@echo "This makefile for K2 project"
	@echo "The command (make all) will create directory and compile all file to object in the new directory and make executable file named sim"	
	@echo "The command (make createDR) will create a new directory called bulid "	
	@echo "The command (make clean) will delete build directory"