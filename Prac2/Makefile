all: pruebaMorfo

pruebaMorfo: alfa.l pruebaMorfo.c
	flex alfa.l
	gcc -c -o lex.yy.o lex.yy.c
	gcc -Wall -ansi -pedantic -c -o pruebaMorfo.o pruebaMorfo.c
	gcc -o pruebaMorfo lex.yy.o pruebaMorfo.o

clean:
	rm -rf lex.yy.o lex.yy.c
	rm -rf pruebaMorfo.o pruebaMorfo
