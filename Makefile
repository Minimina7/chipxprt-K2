CC = gcc
CFLAG = -c
FILENAME = fibonacci.bin


run: build/sim
	cd build && ./sim ../$(FILENAME)

all: createDR simulator.o load.o decoder.o immediate.o Mux.o ALU.o jump.o
	cd build && $(CC) -o sim simulator.o load.o decoder.o immediate.o Mux.o ALU.o jump.o

simulator.o: simulator.c
	cd build && $(CC) $(CFLAG) ../simulator.c

load.o: allFiles/load.c
	cd build && $(CC) $(CFLAG) ../allFiles/load.c

decoder.o: allFiles/decoder.c
	cd build && $(CC) $(CFLAG) ../allFiles/decoder.c

immediate.o: allFiles/immediate.c
	cd build && $(CC) $(CFLAG) ../allFiles/immediate.c

Mux.o: allFiles/Mux.c
	cd build && $(CC) $(CFLAG) ../allFiles/Mux.c

ALU.o: allFiles/ALU.c
	cd build && $(CC) $(CFLAG) ../allFiles/ALU.c

jump.o: allFiles/jump.c
	cd build && $(CC) $(CFLAG) ../allFiles/jump.c

createDR:
	mkdir -p build

clean : 
	rm -r build

help :
	@echo "This makefile for K2 project"
	@echo "The command (make all) will create directory and compile all file to object in the new directory"
	@echo "The command (make main.o) will create object of main.c and save it in bulid directory"	
	@echo "The command (make math.utils.o) will create object of main.c and save it in bulid directory"	
	@echo "The command (make string_utils.o) will create object of main.c and save it in bulid directory"	
	@echo "The command (make createDR) will create object of main.c and save it in bulid directory"	
	@echo "The command (make clean) will delete build directory"