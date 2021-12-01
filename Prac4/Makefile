CC = gcc
FLAGS = -g -Wall -pedantic
FSALIDA_PRUEBA = salida_prueba.txt
FSALIDA = salida.txt
FENTRADA = entrada.txt
EXE = prueba_tabla
TABLA_HASH = tabla_hash

all: $(EXE)

$(EXE): $(TABLA_HASH).c $(EXE).c
	$(CC) $(FLAGS) -c $(TABLA_HASH).c -lm
	$(CC) $(FLAGS) -o $(EXE) $(EXE).c $(TABLA_HASH).o -lm

valgrind: $(EXE)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(EXE) $(FENTRADA) $(FSALIDA_PRUEBA)

run: $(EXE)
	./$(EXE) $(FENTRADA) $(FSALIDA_PRUEBA)
	diff $(FSALIDA) $(FSALIDA_PRUEBA)

clean:
	-rm -f $(TABLA_HASH).o $(EXE)
	-rm -f $(FSALIDA_PRUEBA)
