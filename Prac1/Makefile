CC=gcc
CFLAGS=-Wall -g
EXE = ejemplo1
EXE_ASM = ejemplo1_asm

main: generacion.c ejemplo1.c alfalib.o
	$(CC) $(CFLAGS) -o $(EXE_ASM) generacion.c $(EXE).c
	./$(EXE_ASM) $(EXE).asm
	nasm -g -o $(EXE).o -f elf32 $(EXE).asm
	$(CC) $(CFLAGS) -m32 -o $(EXE) $(EXE).o alfalib.o

.PHONY: clean
clean:
	rm -rf *.o *.asm $(EXE) $(EXE_ASM)
