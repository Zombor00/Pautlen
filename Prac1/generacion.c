#include <stdio.h>
#include "generacion.h"

void escribir_cabecera_bss(FILE* fpasm){
  if(fpasm == NULL){
    printf("Error NULL file al escribir la cabecera bss");
    exit(1);
  }

  fprintf(fpasm,"segment .bss\n");
  fprintf(fpasm,"__esp resd 4\n");
}

void escribir_subseccion_data(FILE* fpasm){
  if(fpasm == NULL){
    printf("Error NULL file al escribir la subseccion data");
    exit(1);
  }

  fprintf(fpasm,"segment .data\n");
  fprintf(fpasm,"_err_div_0 db \"División por 0\",0\n");
}

void declarar_variable(FILE* fpasm, char *nombre, int tipo, int tamano){
  if(fpasm == NULL){
    printf("Error NULL file al declarar variable");
    exit(1);
  }else if(nombre == NULL){
    printf("Error NULL nombre al declarar variable");
    exit(1);
  }else if(tipo != ENTERO || tipo != BOOLEANO){
    printf("Error tipo no definido al declarar variable");
    exit(1);
  }else if(tamano <= 0){
    printf("El tamano tiene que ser mayor que cero al declarar una variable");
    exit(1);
  }

  /*Tal vez hay que buscar la seccion .bss y luego escribir ahí*/
  fprintf(fpasm,"%s resd %d", nombre, tamano);

}

void escribir_segmento_codigo(FILE* fpasm){
  if(fpasm == NULL){
    printf("Error NULL file al escribir la segmento codigo");
    exit(1);
  }

  fprintf(fpasm,"segment .text\n");
  fprintf(fpasm,"\tglobal main\n");
  fprintf(fpasm,"\textern print_int, print_boolean, print_string, print_blank,
                  print_endofline, scan_int, scan_boolean\n");
}

void escribir_inicio_main(FILE* fpasm){
  if(fpasm == NULL){
    printf("Error NULL file al escribir main");
    exit(1);
  }

  fprintf(fpasm,"main:\n");
  fprintf(fpasm,"MOV DWORD __esp, ESP\n");
}

void escribir_fin(FILE* fpasm){
  if(fpasm == NULL){
    printf("Error NULL file al escribir fin");
    exit(1);
  }

  fprintf(fpasm,"fin:\n");
  fprintf(fpasm,"\tMOV DWORD ESP, __esp\n");
  fprintf(fpasm,"\tret\n");

  fprintf(fpasm,"div_0:\n");
  fprintf(fpasm,"\tPUSH DWORD _err_div_0\n");
  fprintf(fpasm,"\tCALL print_string\n");
  fprintf(fpasm,"\tADD ESP, 4\n");//TODO: SE PUEDE QUITAR?
  fprintf(fpasm,"\tJMP fin:\n");
}

void escribir_operando(FILE* fpasm, char* nombre, int es_variable){
  if(fpasm == NULL){
    printf("Error NULL file al escribir operando");
    exit(1);
  }else if(nombre == NULL){
    printf("Error NULL nombre al escribir operando");
    exit(1);
  }else if(es_variable != VALOR_EXPLICITO && es_variable != 1){
    printf("Error tipo mal definido al escribir operando");
    exit(1);
  }
  if(es_variable == 1){
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
    fprintf(fpasm,"\tPOP DWORD EAX\n");
    fprintf(fpasm,"\tMOV DWORD %s, [EAX]\n", nombre);
  }else{
    fprintf(fpasm,"\tPOP DWORD [%s]\n", nombre);
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

  asignar(fpasm, "EAX", es_variable_1);
  asignar(fpasm, "EBX", es_variable_2);

  fprintf(fpasm,"\tADD EAX, EBX\n");

  escribir_operando(fpasm, "EAX", VALOR_EXPLICITO);
}

void restar(FILE* fpasm, int es_variable_1, int es_variable_2){
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

  asignar(fpasm, "EAX", es_variable_1);
  asignar(fpasm, "EBX", es_variable_2);

  fprintf(fpasm,"\tSUB EAX, EBX\n");

  escribir_operando(fpasm, "EAX", VALOR_EXPLICITO);
}

void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){
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

  asignar(fpasm, "EAX", es_variable_1);
  asignar(fpasm, "EBX", es_variable_2);

  fprintf(fpasm,"\tIMUL EBX\n");

  escribir_operando(fpasm, "EAX", VALOR_EXPLICITO);
}

void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){
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


  asignar(fpasm, "EAX", es_variable_1);
  asignar(fpasm, "EBX", es_variable_2);

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

  asignar(fpasm, "EAX", es_variable_1);
  asignar(fpasm, "EBX", es_variable_2);

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

  asignar(fpasm, "EAX", es_variable_1);
  asignar(fpasm, "EBX", es_variable_2);

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

  asignar(fpasm, "EAX", es_variable);

  fprintf(fpasm,"\tNEG EAX\n");

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

  asignar(fpasm, "EAX", es_variable);
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
  }else if(es_variable_1 != VALOR_EXPLICITO && es_variable_1 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al menor");
    exit(1);
  }else if(es_variable_2 != VALOR_EXPLICITO && es_variable_2 != VALOR_REFERENCIA){
    printf("Error tipo mal definido al menor");
    exit(1);
  }
  asignar(fpasm, "EAX", es_variable_1);
  asignar(fpasm, "EBX", es_variable_2);

  fprintf(fpasm,"\tCMP EAX, EBX\n");
  //TODO: comprobar flags del sistema después de un CMP
  fprintf(fpasm,"\tPUSH DWORD CF\n");
  fprintf(fpasm,"\tJL %d\n", etiqueta);
}
