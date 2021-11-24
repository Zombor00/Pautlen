PRUEBAS = ficheros_de_prueba_sintactico/
IN_SUFIX = entrada_sin_
OUT_SUFIX = salida_sin_
OUT_TEST_SUFIX = mi_salida_sin_

all: pruebaSintactico

run: pruebaSintactico examples

examples: pruebaSintactico
	@echo
	./pruebaSintactico $(PRUEBAS)$(IN_SUFIX)1.txt $(PRUEBAS)$(OUT_TEST_SUFIX)1.txt
	diff -Bb $(PRUEBAS)$(OUT_SUFIX)1.txt $(PRUEBAS)$(OUT_TEST_SUFIX)1.txt
	@echo
	./pruebaSintactico $(PRUEBAS)$(IN_SUFIX)2.txt $(PRUEBAS)$(OUT_TEST_SUFIX)2.txt
	diff -Bb $(PRUEBAS)$(OUT_SUFIX)1.txt $(PRUEBAS)$(OUT_TEST_SUFIX)1.txt
	@echo
	./pruebaSintactico $(PRUEBAS)$(IN_SUFIX)3.txt $(PRUEBAS)$(OUT_TEST_SUFIX)3.txt
	diff -Bb $(PRUEBAS)$(OUT_SUFIX)1.txt $(PRUEBAS)$(OUT_TEST_SUFIX)1.txt

pruebaSintactico: y.tab.o lex.yy.o pruebaSintactico.o
	gcc -o pruebaSintactico y.tab.o lex.yy.o pruebaSintactico.o

pruebaSintactico.o: pruebaSintactico.c
	gcc -Wall -ansi -pedantic -c -o pruebaSintactico.o pruebaSintactico.c

lex.yy.o: lex.yy.c
	gcc -ansi -pedantic -c -o lex.yy.o lex.yy.c

lex.yy.c: alfa.l y.tab.h
	flex alfa.l

y.tab.o: y.tab.c
	gcc -ansi -pedantic -c -o y.tab.o y.tab.c

y.tab.c: alfa.y
	bison -dyv alfa.y

y.tab.h: alfa.y
	bison -dyv alfa.y

clean:
	rm -rf -rf pruebaSintactico *.o lex.yy.c y.tab.h y.tab.c y.output $(PRUEBAS)$(OUT_TEST_SUFIX)1.txt $(PRUEBAS)$(OUT_TEST_SUFIX)2.txt $(PRUEBAS)$(OUT_TEST_SUFIX)3.txt
