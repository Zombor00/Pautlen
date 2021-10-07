CC=gcc
CFLAGS=-Wall -g
main: generacion.c ej.c
	$(CC) $(CFLAGS) -o ej generacion.c ej.c

nasm: ej.o alfalib.o
	nasm -g -o ej.o -f elf32 ej.asm
	$(CC) $(CFLAGS) -m32 -o ej2 ej2.o alfalib.o

.PHONY: clean
clean:
	rm -rf *.o
