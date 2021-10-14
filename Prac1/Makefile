CC=gcc
CFLAGS=-Wall -g
EXE = ejemplo8

main: generacion.c $(EXE).c lib/alfalib.o
	$(CC) $(CFLAGS) -o $(EXE)_asm generacion.c $(EXE).c
	./$(EXE)_asm $(EXE).asm
	nasm -g -o $(EXE).o -f elf32 $(EXE).asm
	$(CC) $(CFLAGS) -m32 -o $(EXE) $(EXE).o lib/alfalib.o

.PHONY: clean
clean:
	rm -rf *.o *.asm $(EXE) $(EXE)_asm
