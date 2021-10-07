#include <stdio.h>
#include <stdlib.h>
#include "generacion.h"

/*
Alejandro Bravo, Daniel Brito, Carmen Díez
*/

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
  fprintf(fpasm,"\t_err_indice_fuera_rango db \"Indice fuera de rango\",0\n");
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
  fprintf(fpasm,"\tADD ESP, 4\n");
  fprintf(fpasm,"\tJMP fin\n");

  fprintf(fpasm,"fin_indice_fuera_rango:\n");
  fprintf(fpasm,"\tPUSH DWORD _err_indice_fuera_rango\n");
  fprintf(fpasm,"\tCALL print_string\n");
  fprintf(fpasm,"\tADD ESP, 4\n");
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
    fprintf(fpasm,"\tPUSH DWORD %s\n", nombre);
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
    fprintf(fpasm,"\tMOV DWORD EDX, [ECX]\n");
    fprintf(fpasm,"\tMOV DWORD [%s], EDX\n", nombre);
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
    fprintf(fpasm,"\tMOV DWORD EDX, [ECX]\n");
    fprintf(fpasm,"\tMOV DWORD %s, EDX\n", nombre);
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

/*Comprobar de aqui pa' bajo*/

void restar(FILE* fpasm, int es_variable_1, int es_variable_2){
  if(fpasm == NULL){
    printf("Error NULL file al restar");
    exit(1);
  }else if(es_variable_1 != VALOR_EXPLICITO && es_variable_1 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al restar");
    exit(1);
  }else if(es_variable_2 != VALOR_EXPLICITO && es_variable_2 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al restar");
    exit(1);
  }

  asignar_reg(fpasm, "EAX", es_variable_1);
  asignar_reg(fpasm, "EBX", es_variable_2);

  fprintf(fpasm,"\tSUB EAX, EBX\n");

  escribir_operando(fpasm, "EAX", VALOR_EXPLICITO);
}

void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){
  if(fpasm == NULL){
    printf("Error NULL file al multiplicar");
    exit(1);
  }else if(es_variable_1 != VALOR_EXPLICITO && es_variable_1 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al multiplicar");
    exit(1);
  }else if(es_variable_2 != VALOR_EXPLICITO && es_variable_2 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al multiplicar");
    exit(1);
  }

  asignar_reg(fpasm, "EAX", es_variable_1);
  asignar_reg(fpasm, "EBX", es_variable_2);

  fprintf(fpasm,"\tIMUL EBX\n");

  escribir_operando(fpasm, "EAX", VALOR_EXPLICITO);
}

void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){
  if(fpasm == NULL){
    printf("Error NULL file al dividir");
    exit(1);
  }else if(es_variable_1 != VALOR_EXPLICITO && es_variable_1 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al dividir");
    exit(1);
  }else if(es_variable_2 != VALOR_EXPLICITO && es_variable_2 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al dividir");
    exit(1);
  }


  asignar_reg(fpasm, "EAX", es_variable_1);
  asignar_reg(fpasm, "EBX", es_variable_2);

  //Comprobamos que no se divide entre cero
  fprintf(fpasm,"\tCMP EBX, 0\n");
  fprintf(fpasm,"\tJE div_0\n");

  //Ponemos el registro para dividir a cero
  fprintf(fpasm,"\tXOR EDX, EDX\n");

  fprintf(fpasm,"\tIDIV EBX\n");

  escribir_operando(fpasm, "EAX", VALOR_EXPLICITO);
}

void o(FILE* fpasm, int es_variable_1, int es_variable_2){
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

  fprintf(fpasm,"\tOR EAX, EBX\n");

  escribir_operando(fpasm, "EAX", VALOR_EXPLICITO);
}

void y(FILE* fpasm, int es_variable_1, int es_variable_2){
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

  fprintf(fpasm,"\tAND EAX, EBX\n");

  escribir_operando(fpasm, "EAX", VALOR_EXPLICITO);
}

void cambiar_signo(FILE* fpasm, int es_variable){
  if(fpasm == NULL){
    printf("Error NULL file al sumar");
    exit(1);
  }else if(es_variable != VALOR_EXPLICITO && es_variable != VALOR_REFERENCIA){
    printf("Error tipo mal definido al sumar");
    exit(1);
  }

  asignar_reg(fpasm, "EAX", es_variable);

  fprintf(fpasm,"\tNEG EAX\n");

  escribir_operando(fpasm, "EAX", VALOR_EXPLICITO);
}

void no(FILE* fpasm, int es_variable, int cuantos_no){
  if(fpasm == NULL){
    printf("Error NULL file al no");
    exit(1);
  }else if(es_variable != VALOR_EXPLICITO){
    printf("Error tipo mal definido al no");
    exit(1);
  }

  asignar_reg(fpasm, "EAX", es_variable);

  fprintf(fpasm,"\tCMP EAX, 0\n");
  fprintf(fpasm,"\tJE no_%d\n", cuantos_no);

  fprintf(fpasm,"\tPUSH DWORD 0\n");
  fprintf(fpasm,"\tJMP no_fin_%d\n", cuantos_no);

  fprintf(fpasm,"no_%d:\n", etiqueta);
  fprintf(fpasm,"\tPUSH DWORD 1\n");

  fprintf(fpasm,"no_fin_%d:\n", cuantos_no);
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
  fprintf(fpasm,"\tJL es_menor_%d\n", etiqueta);

  // False: no es menor
  fprintf(fpasm,"\tPUSH DWORD 0\n");
  fprintf(fpasm,"\tJMP menor_fin_%d\n", etiqueta);

  fprintf(fpasm,"es_menor_%d:\n", etiqueta);
  fprintf(fpasm,"\tPUSH DWORD 1\n");

  fprintf(fpasm,"menor_fin_%d:\n", etiqueta);
}

void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  if(fpasm == NULL){
    printf("Error NULL file al mayor");
    exit(1);
  }else if(es_variable1 != VALOR_EXPLICITO && es_variable1 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al mayor");
    exit(1);
  }else if(es_variable2 != VALOR_EXPLICITO && es_variable2 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al mayor");
    exit(1);
  }
  asignar_reg(fpasm, "EAX", es_variable1);
  asignar_reg(fpasm, "EBX", es_variable2);

  fprintf(fpasm,"\tCMP EAX, EBX\n");
  fprintf(fpasm,"\tJG es_mayor_%d\n", etiqueta);

  // False: no es mayor
  fprintf(fpasm,"\tPUSH DWORD 0\n");
  fprintf(fpasm,"\tJMP mayor_fin_%d\n", etiqueta);

  fprintf(fpasm,"es_mayor_%d:\n", etiqueta);
  fprintf(fpasm,"\tPUSH DWORD 1\n");

  fprintf(fpasm,"mayor_fin_%d:\n", etiqueta);
}

void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  if(fpasm == NULL){
    printf("Error NULL file al distinto");
    exit(1);
  }else if(es_variable1 != VALOR_EXPLICITO && es_variable1 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al distinto");
    exit(1);
  }else if(es_variable2 != VALOR_EXPLICITO && es_variable2 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al distinto");
    exit(1);
  }
  asignar_reg(fpasm, "EAX", es_variable1);
  asignar_reg(fpasm, "EBX", es_variable2);

  fprintf(fpasm,"\tCMP EAX, EBX\n");
  fprintf(fpasm,"\tJNE es_distinto_%d\n", etiqueta);

  // False: no es distinto
  fprintf(fpasm,"\tPUSH DWORD 0\n");
  fprintf(fpasm,"\tJMP distinto_fin_%d\n", etiqueta);

  fprintf(fpasm,"es_distinto_%d:\n", etiqueta);
  fprintf(fpasm,"\tPUSH DWORD 1\n");

  fprintf(fpasm,"distinto_fin_%d:\n", etiqueta);
}

void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  if(fpasm == NULL){
    printf("Error NULL file al menor_igual");
    exit(1);
  }else if(es_variable1 != VALOR_EXPLICITO && es_variable1 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al menor_igual");
    exit(1);
  }else if(es_variable2 != VALOR_EXPLICITO && es_variable2 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al menor_igual");
    exit(1);
  }
  asignar_reg(fpasm, "EAX", es_variable1);
  asignar_reg(fpasm, "EBX", es_variable2);

  fprintf(fpasm,"\tCMP EAX, EBX\n");
  fprintf(fpasm,"\tJLE es_menor_igual_%d\n", etiqueta);

  // False: no es menor o igual
  fprintf(fpasm,"\tPUSH DWORD 0\n");
  fprintf(fpasm,"\tJMP menor_igual_fin_%d\n", etiqueta);

  fprintf(fpasm,"es_menor_igual_%d:\n", etiqueta);
  fprintf(fpasm,"\tPUSH DWORD 1\n");

  fprintf(fpasm,"menor_igual_fin_%d:\n", etiqueta);
}

void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  if(fpasm == NULL){
    printf("Error NULL file al mayor_igual");
    exit(1);
  }else if(es_variable1 != VALOR_EXPLICITO && es_variable1 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al mayor_igual");
    exit(1);
  }else if(es_variable2 != VALOR_EXPLICITO && es_variable2 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al mayor_igual");
    exit(1);
  }
  asignar_reg(fpasm, "EAX", es_variable1);
  asignar_reg(fpasm, "EBX", es_variable2);

  fprintf(fpasm,"\tCMP EAX, EBX\n");
  fprintf(fpasm,"\tJGE es_mayor_igual_%d\n", etiqueta);

  // False: no es mayor o igual
  fprintf(fpasm,"\tPUSH DWORD 0\n");
  fprintf(fpasm,"\tJMP mayor_igual_fin_%d\n", etiqueta);

  fprintf(fpasm,"es_mayor_igual_%d:\n", etiqueta);
  fprintf(fpasm,"\tPUSH DWORD 1\n");

  fprintf(fpasm,"mayor_igual_fin_%d:\n", etiqueta);
}

void leer(FILE* fpasm, char* nombre, int tipo){
  if(fpasm == NULL){
    printf("Error NULL file al leer");
    exit(1);
  }else if(nombre == NULL){
    printf("Error NULL nombre al leer");
    exit(1);
  }else if(tipo != ENTERO && tipo != BOOLEANO){
    printf("Error tipo mal definido al leer");
    exit(1);
  }

  fprintf(fpasm,"\tPUSH DWORD %d\n", nombre); //TODO corcheetes mirar si falla
  if(tipo == ENTERO){
    fprintf(fpasm,"\tCALL scan_int\n");
  } else if(tipo == BOOLEANO){
    fprintf(fpasm,"\tCALL scan_boolean\n");
  }
  fprintf(fpasm,"\tADD ESP, 4\n");
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
    //Estos print_endofline en el futuro tal vez se deberian quitar
    //y aniadir una función a parte
    fprintf(fpasm,"\tCALL print_endofline\n");

  }else if(tipo == BOOLEANO){
    fprintf(fpasm,"\tCALL print_boolean\n");
    fprintf(fpasm,"\tCALL print_endofline\n");
  }
  fprintf(fpasm,"\tADD ESP, 4\n");
}



void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){
  if(fpasm == NULL){
    printf("Error NULL file al ifthenesle_inicio");
    exit(1);
  }else if(exp_es_variable != VALOR_EXPLICITO && exp_es_variable != VALOR_REFERENCIA){
    printf("Error tipo mal definido al ifthenesle_inicio");
    exit(1);
  }
  asignar_reg(fpasm, "EAX", exp_es_variable);
  fprintf(fpasm,"\tCMP EAX, 0\n");
  fprintf(fpasm,"\tJE NEAR fin_then_%d\n", etiqueta);
}

/*
Generación de código para el inicio de una estructura if-then-else
Como es el inicio de uno bloque de control de flujo de programa que requiere de una nueva
etiqueta deben ejecutarse antes las tareas correspondientes a esta situación
exp_es_variable
Es 1 si la expresión de la condición es algo asimilable a una variable (identificador,
elemento de vector)
Es 0 en caso contrario (constante u otro tipo de expresión)
*/

void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){
  if(fpasm == NULL){
    printf("Error NULL file al ifthenesle_inicio");
    exit(1);
  }else if(exp_es_variable != VALOR_EXPLICITO && exp_es_variable != VALOR_REFERENCIA){
    printf("Error tipo mal definido al ifthenesle_inicio");
    exit(1);
  }
  asignar_reg(fpasm, "EAX", exp_es_variable);
  fprintf(fpasm,"\tCMP EAX, 0\n");
  fprintf(fpasm,"\tJE NEAR fin_ifthen_%d\n", etiqueta);
}
/*
Generación de código para el inicio de una estructura if-then
Como es el inicio de uno bloque de control de flujo de programa que requiere de una nueva
etiqueta deben ejecutarse antes las tareas correspondientes a esta situación
exp_es_variable
Es 1 si la expresión de la condición es algo asimilable a una variable (identificador,
elemento de vector)
Es 0 en caso contrario (constante u otro tipo de expresión)
*/

void ifthen_fin(FILE * fpasm, int etiqueta){
  if(fpasm == NULL){
    printf("Error NULL file dowhile inicio");
    exit(1);
  }
  fprintf(fpasm,"ifthen_fin_%d:\n", etiqueta);
}
/*
Generación de código para el fin de una estructura if-then
Como es el fin de uno bloque de control de flujo de programa que hace uso de la etiqueta
del mismo se requiere que antes de su invocación tome el valor de la etiqueta que le toca
según se ha explicado
Y tras ser invocada debe realizar el proceso para ajustar la información de las etiquetas
puesto que se ha liberado la última de ellas.
*/

void ifthenelse_fin_then(FILE * fpasm, int etiqueta){
  if(fpasm == NULL){
    printf("Error NULL file dowhile inicio");
    exit(1);
  }
  fprintf(fpasm,"ifthenelse_fin_then_%d:\n", etiqueta);
}
/*
Generación de código para el fin de la rama then de una estructura if-then-else
Sólo necesita usar la etiqueta adecuada, aunque es el final de una rama, luego debe venir
otra (la rama else) antes de que se termine la estructura y se tenga que ajustar las etiquetas
por lo que sólo se necesita que se utilice la etiqueta que corresponde al momento actual.
*/

void ifthenelse_fin(FILE * fpasm, int etiqueta){
  if(fpasm == NULL){
    printf("Error NULL file dowhile inicio");
    exit(1);
  }
  fprintf(fpasm,"ifthenelse_fin_%d:\n", etiqueta);
}
/*
Generación de código para el fin de una estructura if-then-else
Como es el fin de uno bloque de control de flujo de programa que hace uso de la etiqueta
del mismo se requiere que antes de su invocación tome el valor de la etiqueta que le toca
según se ha explicado
Y tras ser invocada debe realizar el proceso para ajustar la información de las etiquetas
puesto que se ha liberado la última de ellas.
*/

void while_inicio(FILE * fpasm, int etiqueta){
  if(fpasm == NULL){
    printf("Error NULL file while_inicio");
    exit(1);
  }
  fprintf(fpasm,"while_ini_%d:\n", etiqueta);
}
/*
Generación de código para el inicio de una estructura while
Como es el inicio de uno bloque de control de flujo de programa que requiere de una nueva
etiqueta deben ejecutarse antes las tareas correspondientes a esta situación
exp_es_variable
Es 1 si la expresión de la condición es algo asimilable a una variable (identificador,
elemento de vector)
Es 0 en caso contrario (constante u otro tipo de expresión)
*/

void while_exp_pila (FILE * fpasm, int exp_es_variable, int etiqueta){
  if(fpasm == NULL){
    printf("Error NULL file while_exp_pila");
    exit(1);
  }

  asignar_reg(fpasm, "EAX", exp_es_variable);

  // Si el cmp anterior era False while_fin, si no while_ini
  fprintf(fpasm, "\tCMP EAX, 0\n");
  fprintf(fpasm, "\tJE while_fin_%d\n", etiqueta);
  fprintf(fpasm, "\tJMP while_ini%d\n", etiqueta);
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

void while_fin(FILE * fpasm, int etiqueta){
  if(fpasm == NULL){
    printf("Error NULL file while_fin");
    exit(1);
  }
  fprintf(fpasm,"while_fin_%d:\n", etiqueta);
}
/*
Generación de código para el final de una estructura while
Como es el fin de uno bloque de control de flujo de programa que hace uso de la etiqueta
del mismo se requiere que antes de su invocación tome el valor de la etiqueta que le toca
según se ha explicado
Y tras ser invocada debe realizar el proceso para ajustar la información de las etiquetas
puesto que se ha liberado la última de ellas.
*/

void escribir_elemento_vector(FILE * fpasm,char * nombre_vector,
int tam_max, int exp_es_direccion){
  if(fpasm == NULL || nombre_vector == NULL || tam_max < 0){
    printf("Error NULL file al escribir_elemento_vector");
    exit(1);
  }else if(exp_es_direccion != VALOR_EXPLICITO && exp_es_direccion != VALOR_REFERENCIA){
    printf("Error tipo mal definido al escribir_elemento_vector");
    exit(1);
  }
  asignar_reg(fpasm, "EAX", exp_es_direccion);
  fprintf(fpasm,"\tCMP EAX, 0\n");
  fprintf(fpasm,"\tJL NEAR fin_indice_fuera_rango\n"); //TODO: colocar esta etiqueta en algun lado
  fprintf(fpasm,"\tCMP EAX, %d\n", (tam_max-1));
  fprintf(fpasm,"\tJG NEAR fin_indice_fuera_rango\n");
  fprintf(fpasm,"\tMOV DWORD EDX, %s\n", nombre_vector);
  fprintf(fpasm,"\tLEA EAX, [EDX + EAX*4]\n");
  fprintf(fpasm,"\tPUSH DWORD EAX\n");
}
/*
Generación de código para indexar un vector
Cuyo nombre es nombre_vector
Declarado con un tamaño tam_max
La expresión que lo indexa está en la cima de la pila
Puede ser una variable (o algo equivalente) en cuyo caso exp_es_direccion vale 1
Puede ser un valor concreto (en ese caso exp_es_direccion vale 0)
Según se especifica en el material, es suficiente con utilizar dos registros para realizar esta
tarea.
*/

void declararFuncion(FILE * fd_asm, char * nombre_funcion, int num_var_loc){
  if(fd_asm == NULL || nombre_funcion == NULL || num_var_loc < 0){
    printf("Error NULL file al declararFuncion");
    exit(1);
  }
  fprintf(fd_asm,"%s:\n", nombre_funcion);
  fprintf(fpasm,"\tPUSH DWORD EBP\n");
  fprintf(fpasm,"\tMOV DWORD EBP, ESP\n");
  fprintf(fpasm,"\tSUB ESP, 4*%d\n", num_var_loc); //TODO: Igual falla!

}
/*
Generación de código para iniciar la declaración de una función.
Es necesario proporcionar
Su nombre
Su número de variables locales
*/

void retornarFuncion(FILE * fd_asm, int es_variable){
  if(fd_asm == NULL){
    printf("Error NULL file al retornarFuncion");
    exit(1);
  }else if(es_variable != VALOR_EXPLICITO && es_variable != VALOR_REFERENCIA){
    printf("Error tipo mal definido al retornarFuncion");
    exit(1);
  }
  asignar_reg(fd_asm, "EAX", es_variable);
  fprintf(fd_asm, "\tmov esp,ebp\n"); /* restaurar el puntero de pila */
  fprintf(fd_asm, "\tpop ebp\n"); /* sacar de la pila ebp */
  fprintf(fd_asm, "\tret\n");
}
/*
Generación de código para el retorno de una función.
La expresión que se retorna está en la cima de la pila.
Puede ser una variable (o algo equivalente) en cuyo caso exp_es_direccion vale 1
Puede ser un valor concreto (en ese caso exp_es_direccion vale 0)
*/

void escribirParametro(FILE* fpasm, int pos_parametro, int num_total_parametros){
  //TODO: control de errores
  int d_ebp;
  d_ebp = 4*(1 + num_total_parametros-pos_parametro);
  fprintf(fpasm, "\tLEA EAX, [EBP + %d]\n", d_ebp);
  fprintf(fpasm, "\tPUSH DWORD EAX");
}
/*
Función para dejar en la cima de la pila la dirección efectiva del parámetro que ocupa la
posición pos_parametro (recuerda que los parámetros se ordenan con origen 0) de un total
de num_total_parametros
*/

void escribirVariableLocal(FILE* fpasm, int posicion_variable_local){
  int d_ebp;
  d_ebp = 4*posicion_variable_local;
  fprintf(fpasm, "\tLEA EAX, [EBP - %d]\n", d_ebp);
  fprintf(fpasm, "\tPUSH DWORD EAX");
}
/*
Función para dejar en la cima de la pila la dirección efectiva de la variable local que ocupa
la posición posicion_variable_local (recuerda que ordenadas con origen 1)
*/

void asignarDestinoEnPila(FILE* fpasm, int es_variable);
/*
Función para poder asignar a un destino que no es una variable “global” (tipo _x) por
ejemplo parámetros o variables locales (ya que en ese caso su nombre real de alto nivel, no
se tiene en cuenta pues es realmente un desplazamiento a partir de ebp: ebp+4 o ebp-8 por
ejemplo).
Se debe asumir que en la pila estará
Primero (en la cima) lo que hay que asignar
Debajo (se ha introducido en la pila antes) la dirección donde hay que asignar
es_variable
Es 1 si la expresión que se va a asignar es algo asimilable a una variable
(identificador, o elemento de vector)
Es 0 en caso contrario (constante u otro tipo de expresión)
*/

void operandoEnPilaAArgumento(FILE * fd_asm, int es_variable) {
  if(es_variable == 1){
    fprintf(fpasm, "\tPOP DWORD EAX\n");
    fprintf(fpasm, "\tMOV EAX, [EAX]\n");
    fprintf(fpasm, "\tPUSH DWORD EAX");
  }
}
/*
Como habrás visto en el material, nuestro convenio de llamadas a las funciones asume que
los argumentos se pasan por valor, esto significa que siempre se dejan en la pila “valores” y
no “variables”
Esta función realiza la tarea de dado un operando escrito en la pila y sabiendo si es variable
o no (es_variable) se deja en la pila el valor correspondiente
*/

void llamarFuncion(FILE * fd_asm, char * nombre_funcion, int num_argumentos){
      fprintf(fpasm, "\tCALL %s\n", nombre_funcion);
      fprintf(fpasm, "\tADD ESP, %d\n", num_argumentos*4);
      fprintf(fpasm, "\tPUSH DWORD EAX");
}
/*
Esta función genera código para llamar a la función nombre_funcion asumiendo que los
argumentos están en la pila en el orden fijado en el material de la asignatura.
Debe dejar en la cima de la pila el retorno de la función tras haberla limpiado de sus
argumentos
Para limpiar la pila puede utilizar la función de nombre limpiarPila
*/

void limpiarPila(FILE * fd_asm, int num_argumentos);
/*
Genera código para limpiar la pila tras invocar una función
Esta función es necesaria para completar la llamada a métodos, su gestión dificulta el
conocimiento por parte de la función de llamada del número de argumentos que hay en la
pila
*/
