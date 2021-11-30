prueba: tabla_hash.c prueba.c
	gcc -c tabla_hash.c -lm
	gcc -o prueba prueba.c tabla_hash.o -lm

clean:
	-rm -f tabla_hash.o
	-rm -f prueba

valgrind: prueba
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./prueba
