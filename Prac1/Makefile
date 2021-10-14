CC=gcc
CFLAGS=-Wall -g
EXE = ejemplo1 ejemplo2 ejemplo3 ejemplo4 ejemplo5 ejemplo6 ejemplo7 ejemplo8 ejemplo9

main: generacion.c $(EXE) lib/alfalib.o
$(EXE):
	$(CC) $(CFLAGS) -o $@_asm generacion.c $@.c
	./$@_asm $@.asm
	nasm -g -o $@.o -f elf32 $@.asm
	$(CC) $(CFLAGS) -m32 -o $@ $@.o lib/alfalib.o

.PHONY: clean
clean:
	rm -rf *.o *.asm $(EXE) $(EXE)_asm
