
prueba: 
	gcc -c tabla_hash.c -lm
	gcc -o prueba prueba.c tabla_hash.o -lm

clean:
	-rm -f tabla_hash.o
	-rm -f prueba