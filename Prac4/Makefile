all: tabla_hash.c prueba.c
	gcc -c tabla_hash.c -lm
	gcc -o prueba_tabla prueba_tabla.c tabla_hash.o -lm

prueba: tabla_hash.c prueba.c
	gcc -c tabla_hash.c -lm
	gcc -o prueba prueba.c tabla_hash.o -lm

clean:
	-rm -f tabla_hash.o
	-rm -f prueba
	-rm -f tabla

valgrind: prueba
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./prueba
