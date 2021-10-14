CC=gcc
CFLAGS=-Wall -g
EJ = ejemplos/
EXE = $(EJ)ejemplo1 $(EJ)ejemplo2 $(EJ)ejemplo3 $(EJ)ejemplo4 $(EJ)ejemplo5 $(EJ)ejemplo6 $(EJ)ejemplo7 $(EJ)ejemplo8 $(EJ)ejemplo9

all: generacion.c $(EXE) lib/alfalib.o
$(EXE):
	$(CC) $(CFLAGS) -o $@_asm generacion.c $@.c
	./$@_asm $@.asm
	nasm -g -o $@.o -f elf32 $@.asm
	$(CC) $(CFLAGS) -m32 -o $@ $@.o lib/alfalib.o

.PHONY: clean
clean:
	rm -rf $(EJ)*.o $(EJ)*.asm $(EXE) $(EJ)*_asm
