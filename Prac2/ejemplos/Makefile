all: ej1 ej2

ej1: ejemplo1.l
	flex ejemplo1.l
	gcc -Wall -o ejemplo1 lex.yy.c

ej2: ejemplo2.l
	flex ejemplo2.l
	gcc -c -o lex.yy.o lex.yy.c
	gcc -Wall -ansi -pedantic -c -o prueba.o prueba.c
	gcc -o prueba lex.yy.o prueba.o

alfa_prueba: alfa.l
	flex alfa.l
	gcc -c -o lex.yy.o lex.yy.c
	gcc -Wall -ansi -pedantic -c -o alfa_prueba.o alfa_prueba.c
	gcc -o alfa_prueba lex.yy.o alfa_prueba.o

clean:
	rm -rf lex.yy.o lex.yy.c
	rm -rf prueba.o prueba ejemplo1 alfa_prueba.o alfa_prueba
