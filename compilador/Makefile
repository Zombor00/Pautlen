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

TESTS = tests/ejemplo_
CONDICIONALES_DIR=$(TESTS)condicionales/condicionales
FACTORIAL_DIR=$(TESTS)factorial/factorial
FUNCIONES_DIR=$(TESTS)funciones/funciones
FIBONACCI_DIR=$(TESTS)fibonacci/fibonacci
FUNC_VECT_DIR=$(TESTS)funciones_vectores/funciones_vectores
MAS_DIR=$(TESTS)mas/


LIB=lib/alfalib.o

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
	$(ALFA) $(CONDICIONALES_DIR).alfa $(CONDICIONALES_DIR)_output.asm

run_funciones: all
	$(ALFA) $(FUNCIONES_DIR).alfa $(FUNCIONES_DIR)_output.asm

run_fibonacci: all
	$(ALFA) $(FIBONACCI_DIR).alfa $(FIBONACCI_DIR)_output.asm

run_factorial: all
	$(ALFA) $(FACTORIAL_DIR).alfa $(FACTORIAL_DIR)_output.asm

run_funciones_vectores: all
	$(ALFA) $(FUNC_VECT_DIR).alfa $(FUNC_VECT_DIR)_output.asm

run_uno: all
	$(ALFA) $(MAS_DIR)uno.alfa $(MAS_DIR)uno_output.asm

run_dos: all
	$(ALFA) $(MAS_DIR)dos.alfa $(MAS_DIR)dos_output.asm

run_tres: all
	$(ALFA) $(MAS_DIR)tres.alfa $(MAS_DIR)tres_output.asm

run_cuatro: all
	$(ALFA) $(MAS_DIR)cuatro.alfa $(MAS_DIR)cuatro_output.asm

nasm_uno: run_uno
	$(NASM) $(MAS_DIR)uno.o $(NASMFLAGS) $(MAS_DIR)uno_output.asm
	$(CC) $(CFLAGS) -m32 -o $(MAS_DIR)uno $(MAS_DIR)uno.o $(LIB)
	./$(MAS_DIR)uno

nasm_dos: run_dos
	$(NASM) $(MAS_DIR)dos.o $(NASMFLAGS) $(MAS_DIR)dos_output.asm
	$(CC) $(CFLAGS) -m32 -o $(MAS_DIR)dos $(MAS_DIR)dos.o $(LIB)
	./$(MAS_DIR)dos

nasm_tres: run_tres
	$(NASM) $(MAS_DIR)tres.o $(NASMFLAGS) $(MAS_DIR)tres_output.asm
	$(CC) $(CFLAGS) -m32 -o $(MAS_DIR)tres $(MAS_DIR)tres.o $(LIB)
	./$(MAS_DIR)tres

nasm_cuatro: run_cuatro
	$(NASM) $(MAS_DIR)cuatro.o $(NASMFLAGS) $(MAS_DIR)cuatro_output.asm
	$(CC) $(CFLAGS) -m32 -o $(MAS_DIR)cuatro $(MAS_DIR)cuatro.o $(LIB)
	./$(MAS_DIR)cuatro

valgrind_condicionales: all
	$(VALGRIND) $(ALFA) $(CONDICIONALES_DIR).alfa $(CONDICIONALES_DIR)_output.asm

valgrind_funciones: all
	$(VALGRIND) $(ALFA) $(FUNCIONES_DIR).alfa $(FUNCIONES_DIR)_output.asm

valgrind_fibonacci: all
	$(VALGRIND) $(ALFA) $(FIBONACCI_DIR).alfa $(FIBONACCI_DIR)_output.asm

valgrind_factorial: all
	$(VALGRIND) $(ALFA) $(FACTORIAL_DIR).alfa $(FACTORIAL_DIR)_output.asm

valgrind_funciones_vectores: all
	$(VALGRIND) $(ALFA) $(FUNC_VECT_DIR).alfa $(FUNC_VECT_DIR)_output.asm


nasm_condicionales: run_condicionales
	$(NASM) $(CONDICIONALES_DIR).o $(NASMFLAGS) $(CONDICIONALES_DIR)_output.asm
	$(CC) $(CFLAGS) -m32 -o $(CONDICIONALES_DIR) $(CONDICIONALES_DIR).o $(LIB)
	./$(CONDICIONALES_DIR)

nasm_funciones: run_funciones
	$(NASM) $(FUNCIONES_DIR).o $(NASMFLAGS) $(FUNCIONES_DIR)_output.asm
	$(CC) $(CFLAGS) -m32 -o $(FUNCIONES_DIR) $(FUNCIONES_DIR).o $(LIB)
	./$(FUNCIONES_DIR)

nasm_fibonacci: run_fibonacci
	$(NASM) $(FIBONACCI_DIR).o $(NASMFLAGS) $(FIBONACCI_DIR)_output.asm
	$(CC) $(CFLAGS) -m32 -o $(FIBONACCI_DIR) $(FIBONACCI_DIR).o $(LIB)
	./$(FIBONACCI_DIR)

nasm_factorial: run_factorial
	$(NASM) $(FACTORIAL_DIR).o $(NASMFLAGS) $(FACTORIAL_DIR)_output.asm
	$(CC) $(CFLAGS) -m32 -o $(FACTORIAL_DIR) $(FACTORIAL_DIR).o $(LIB)
	./$(FACTORIAL_DIR)

nasm_funciones_vectores: run_funciones_vectores
	$(NASM) $(FUNC_VECT_DIR).o $(NASMFLAGS) $(FUNC_VECT_DIR)_output.asm
	$(CC) $(CFLAGS) -m32 -o $(FUNC_VECT_DIR) $(FUNC_VECT_DIR).o $(LIB)
	./$(FUNC_VECT_DIR)

clean:
	@rm -rvf $(BIN) $(OBJ) lex.yy.c lex.yy.o y.tab.h y.tab.c y.tab.o y.output alfa
	@rm -rvf $(CONDICIONALES_DIR) $(CONDICIONALES_DIR).o $(FUNCIONES_DIR) $(FUNCIONES_DIR).o
	@rm -rvf $(FIBONACCI_DIR) $(FIBONACCI_DIR).o $(FACTORIAL_DIR) $(FACTORIAL_DIR).o
	@rm -rvf $(FUNC_VECT_DIR) $(FUNC_VECT_DIR).o
	@rm -rvf $(MAS_DIR)uno.o $(MAS_DIR)uno $(MAS_DIR)dos.o $(MAS_DIR)dos
	@rm -rvf $(MAS_DIR)tres.o $(MAS_DIR)tres $(MAS_DIR)cuatro.o $(MAS_DIR)cuatro

