#include <stdio.h>
#include <stdlib.h>
#include "doWhile.h"

int main (int argc, char** argv){
  FILE* salida;
  if (argc != 2) {
    fprintf (stdout, "ERROR POCOS ARGUMENTOS\n");
    return -1;
  }
  salida = fopen(argv[1],"w");

	int etiqueta = 0;

	escribir_subseccion_data(salida);
	escribir_cabecera_bss(salida);
	declarar_variable(salida, "x", ENTERO, 1);
	declarar_variable(salida, "y", ENTERO, 1);

	escribir_segmento_codigo(salida);
	escribir_inicio_main(salida);

	/* x=0; */
  escribir_operando(salida,"0",VALOR_EXPLICITO);
	asignar(salida,"x",VALOR_EXPLICITO);

	/* y=2; */
  escribir_operando(salida,"15",VALOR_EXPLICITO);
	asignar(salida,"y",VALOR_EXPLICITO);

	etiqueta++;
	dowhile_inicio(salida, etiqueta);

	escribir_operando(salida, "x", VALOR_REFERENCIA);
	escribir_operando(salida, "y", VALOR_REFERENCIA);

	sumar(salida, VALOR_REFERENCIA, VALOR_REFERENCIA);
	asignar(salida, "x", VALOR_EXPLICITO);

	escribir_operando(salida, "x", VALOR_REFERENCIA);
	escribir(salida, VALOR_REFERENCIA, ENTERO);

	escribir_operando(salida, "10",VALOR_EXPLICITO);
	escribir_operando(salida,"x",VALOR_REFERENCIA);
	menor(salida, VALOR_REFERENCIA, VALOR_EXPLICITO, etiqueta);

	dowhile_exp_pila(salida, 0, etiqueta);
	dowhile_fin(salida, etiqueta);

  escribir_fin(salida);

	fclose(salida);
	return 0;
}
