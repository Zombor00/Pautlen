#include <stdio.h>
#include <stdlib.h>
#include "doWhile.h"

void escribir_cabecera_bss(FILE* fpasm){
  if(fpasm == NULL){
    printf("Error NULL file al escribir la cabecera bss");
    exit(1);
  }

  fprintf(fpasm,"segment .bss\n");
  fprintf(fpasm,"\t__esp resd 1\n");
}

void escribir_subseccion_data(FILE* fpasm){
  if(fpasm == NULL){
    printf("Error NULL file al escribir la subseccion data");
    exit(1);
  }

  fprintf(fpasm,"segment .data\n");
  fprintf(fpasm,"\t_err_div_0 db \"División por 0\",0\n");
}

void declarar_variable(FILE* fpasm, char *nombre, int tipo, int tamano){
  if(fpasm == NULL){
    printf("Error NULL file al declarar variable\n");
    exit(1);
  }else if(nombre == NULL){
    printf("Error NULL nombre al declarar variable");
    exit(1);
  }else if(tipo != ENTERO && tipo != BOOLEANO){
    printf("Error tipo no definido al declarar variable");
    exit(1);
  }else if(tamano <= 0){
    printf("El tamano tiene que ser mayor que cero al declarar una variable");
    exit(1);
  }

  // TODO: poner _%s ?
  /*Tal vez hay que buscar la seccion .bss y luego escribir ahí*/
  fprintf(fpasm,"\t%s resd %d\n", nombre, tamano);

}

void escribir_segmento_codigo(FILE* fpasm){
  if(fpasm == NULL){
    printf("Error NULL file al escribir la segmento codigo");
    exit(1);
  }

  fprintf(fpasm,"segment .text\n");
  fprintf(fpasm,"\tglobal main\n");
  fprintf(fpasm,"\textern print_int, print_boolean, print_string, print_blank, print_endofline\n");
  fprintf(fpasm,"\textern scan_int, scan_boolean\n");
}

void escribir_inicio_main(FILE* fpasm){
  if(fpasm == NULL){
    printf("Error NULL file al escribir main");
    exit(1);
  }

  fprintf(fpasm,"main:\n");
  fprintf(fpasm,"\tMOV DWORD [__esp], ESP\n");
}

void escribir_fin(FILE* fpasm){
  if(fpasm == NULL){
    printf("Error NULL file al escribir fin");
    exit(1);
  }

  fprintf(fpasm,"fin:\n");
  fprintf(fpasm,"\tMOV DWORD ESP, [__esp]\n");
  fprintf(fpasm,"\tret\n");

  fprintf(fpasm,"div_0:\n");
  fprintf(fpasm,"\tPUSH DWORD _err_div_0\n");
  fprintf(fpasm,"\tCALL print_string\n");
  fprintf(fpasm,"\tADD ESP, 4\n");//TODO: SE PUEDE QUITAR?
  fprintf(fpasm,"\tJMP fin\n");
}

void escribir_operando(FILE* fpasm, char* nombre, int es_variable){
  if(fpasm == NULL){
    printf("Error NULL file al escribir operando");
    exit(1);
  }else if(nombre == NULL){
    printf("Error NULL nombre al escribir operando");
    exit(1);
  }else if(es_variable != VALOR_EXPLICITO && es_variable != VALOR_REFERENCIA){
    printf("Error tipo mal definido al escribir operando");
    exit(1);
  }
  if(es_variable == VALOR_REFERENCIA){
    fprintf(fpasm,"\tPUSH DWORD [%s]\n", nombre);
  }else{
    fprintf(fpasm,"\tPUSH DWORD %s\n", nombre);
  }
}

void asignar(FILE* fpasm, char* nombre, int es_variable){
  if(fpasm == NULL){
    printf("Error NULL file al asignar");
    exit(VALOR_REFERENCIA);
  }else if(nombre == NULL){
    printf("Error NULL nombre al asignar");
    exit(1);
  }else if(es_variable != VALOR_EXPLICITO && es_variable != VALOR_REFERENCIA){
    printf("Error tipo mal definido al asignar");
    exit(1);
  }

  if(es_variable == VALOR_REFERENCIA){
    fprintf(fpasm,"\tPOP DWORD ECX\n");
    fprintf(fpasm,"\tMOV DWORD [%s], ECX\n", nombre);
  }else{
    fprintf(fpasm,"\tPOP DWORD [%s]\n", nombre);
  }
}

void asignar_reg(FILE* fpasm, char* nombre, int es_variable){
  if(fpasm == NULL){
    printf("Error NULL file al asignar");
    exit(VALOR_REFERENCIA);
  }else if(nombre == NULL){
    printf("Error NULL nombre al asignar");
    exit(1);
  }else if(es_variable != VALOR_EXPLICITO && es_variable != VALOR_REFERENCIA){
    printf("Error tipo mal definido al asignar");
    exit(1);
  }

  if(es_variable == VALOR_REFERENCIA){
    fprintf(fpasm,"\tPOP DWORD ECX\n");
    fprintf(fpasm,"\tMOV DWORD %s, ECX\n", nombre);
  }else{
    fprintf(fpasm,"\tPOP DWORD %s\n", nombre);
  }
}

void sumar(FILE* fpasm, int es_variable_1, int es_variable_2){
  if(fpasm == NULL){
    printf("Error NULL file al sumar");
    exit(1);
  }else if(es_variable_1 != VALOR_EXPLICITO && es_variable_1 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al sumar");
    exit(1);
  }else if(es_variable_2 != VALOR_EXPLICITO && es_variable_2 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al sumar");
    exit(1);
  }

  asignar_reg(fpasm, "EAX", es_variable_1);
  asignar_reg(fpasm, "EBX", es_variable_2);

  fprintf(fpasm,"\tADD EAX, EBX\n");

  escribir_operando(fpasm, "EAX", VALOR_EXPLICITO);
}

void escribir(FILE* fpasm, int es_variable, int tipo){
  if(fpasm == NULL){
    printf("Error NULL file al escribir");
    exit(1);
  }else if(es_variable != VALOR_EXPLICITO && es_variable != VALOR_REFERENCIA){
    printf("Error tipo mal definido al escribir");
    exit(1);
  }else if(tipo != ENTERO && tipo != BOOLEANO){
    printf("Error tipo mal definido al escribir");
    exit(1);
  }

  asignar_reg(fpasm, "EAX", es_variable);
  fprintf(fpasm,"\tPUSH DWORD EAX\n");
  if(tipo == ENTERO){
    fprintf(fpasm,"\tCALL print_int\n");
  }else if(tipo == BOOLEANO){
    fprintf(fpasm,"\tCALL print_boolean\n");
  }
  fprintf(fpasm,"\tADD ESP, 4\n");
}

void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  if(fpasm == NULL){
    printf("Error NULL file al menor");
    exit(1);
  }else if(es_variable1 != VALOR_EXPLICITO && es_variable1 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al menor");
    exit(1);
  }else if(es_variable2 != VALOR_EXPLICITO && es_variable2 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al menor");
    exit(1);
  }
  asignar_reg(fpasm, "EAX", es_variable1);
  asignar_reg(fpasm, "EBX", es_variable2);

  fprintf(fpasm,"\tCMP EAX, EBX\n");
  //TODO: comprobar flags del sistema después de un CMP
  //fprintf(fpasm,"\tPUSH DWORD CF\n");
  fprintf(fpasm,"\tJL es_menor_%d\n", etiqueta);

  // False: no es menor
  fprintf(fpasm,"\tPUSH DWORD 0\n");
  fprintf(fpasm,"\tJMP menor_fin_%d\n", etiqueta);

  fprintf(fpasm,"es_menor_%d:\n", etiqueta);
  fprintf(fpasm,"\tPUSH DWORD 1\n");

  fprintf(fpasm,"menor_fin_%d:\n", etiqueta);
}

/*ejercicio dowhile*/
void dowhile_inicio(FILE * fpasm, int etiqueta){
  if(fpasm == NULL){
    printf("Error NULL file dowhile inicio");
    exit(1);
  }
  fprintf(fpasm,"dowhile_ini_%d:\n", etiqueta);
}

/*
Generación de código para el inicio de una estructura do-while
Como es el inicio de uno bloque de control de flujo de programa en este ejercicio opcional no es necesario
 tener encuenta control de
 s para do-while anidado.
*/

void dowhile_exp_pila (FILE * fpasm, int exp_es_variable, int etiqueta){
  if(fpasm == NULL){
    printf("Error NULL file dowhile inicio");
    exit(1);
  }

  asignar_reg(fpasm, "EAX", exp_es_variable);

  // Si el cmp anterior era False dowhile_fin, si no dowhile_fin
  fprintf(fpasm, "\tCMP EAX, 0\n");
  fprintf(fpasm, "\tJE dowhile_fin_%d\n", etiqueta);
  fprintf(fpasm, "\tJMP dowhile_ini_%d\n", etiqueta);
  //fprintf(fpasm,"jmp %d\n", etiqueta);
}
/*
Generación de código para el momento en el que se ha generado el código de la expresión
de control del bucle
Sólo necesita usar la etiqueta adecuada, por lo que sólo se necesita que se recupere el valor
de la etiqueta que corresponde al momento actual.
exp_es_variable
Es 1 si la expresión de la condición es algo asimilable a una variable (identificador,
o elemento de vector)
Es 0 en caso contrario (constante u otro tipo de expresión)
*/


void dowhile_fin(FILE * fpasm, int etiqueta){
  if(fpasm == NULL){
    printf("Error NULL file dowhile inicio");
    exit(1);
  }
  fprintf(fpasm,"dowhile_fin_%d:\n", etiqueta);
}
/*
Generación de código para el final de una estructura dowhile
Como es el fin de uno bloque de control de flujo de programa que hace uso de la etiqueta
del mismo se requiere que antes de su invocación tome el valor de la etiqueta que le toca
según se ha explicado
Y tras ser invocada debe realizar el proceso para ajustar la información de las etiquetas
puesto que se ha liberado la última de ellas.
*/
