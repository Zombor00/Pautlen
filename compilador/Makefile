CC = gcc
BISON = bison
FLEX = flex
ALFA=./alfa
NASM = nasm -g -o

BIN = alfa
CFLAGS = -Wall -g
CYYFLAGS =

FLEXFLAGS =

BISONFLAGS = -dyv

NASMFLAGS = -f elf32

OBJ = tabla_hash.o generacion.o compilador.o

TESTS=

VALGRIND=valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt

all: ${BIN}

alfa: y.tab.o lex.yy.o $(OBJ)
	$(CC) -o $(ALFA) $^

lex.yy.o: lex.yy.c
	$(CC) ${CYYFLAGS} -c -o $@ $<

y.tab.o: y.tab.c
	$(CC) ${CYYFLAGS} -c -o $@ $<

%.o: %.c
	$(CC) ${CFLAGS} -c -o $@ $<

y.tab.c: alfa.y
	$(BISON) $(BISONFLAGS) alfa.y

y.tab.h: alfa.y
	$(BISON) $(BISONFLAGS) alfa.y

lex.yy.c: alfa.l y.tab.h
	$(FLEX) $(FLEXFLAGS) alfa.l

run_condicionales: all
	$(ALFA) tests/ejemplo_condicionales/condicionales.alfa tests/ejemplo_condicionales/output.asm

valgrind_condicionales: all
	$(VALGRIND) $(ALFA) tests/ejemplo_condicionales/condicionales.alfa tests/ejemplo_condicionales/output.asm

valgrind_funciones: all
	$(VALGRIND) $(ALFA) tests/ejemplo_funciones/funciones.alfa tests/ejemplo_funciones/output.asm

nasm_condicionales: run_condicionales
	$(NASM) tests/ejemplo_condicionales/condicionales.o $(NASMFLAGS) tests/ejemplo_condicionales/output.asm
	$(CC) $(CFLAGS) -m32 -o tests/ejemplo_condicionales/condicionales tests/ejemplo_condicionales/condicionales.o lib/alfalib.o
	./tests/ejemplo_condicionales/condicionales

valgrind_nasm_condicionales:
	$(VALGRIND) ./tests/ejemplo_condicionales/condicionales

clean:
	@rm -rvf $(BIN) $(OBJ) lex.yy.c lex.yy.o y.tab.h y.tab.c y.tab.o y.output alfa /tests/ejemplo_condicionales/condicionales /tests/ejemplo_condicionales/condicionales.o
