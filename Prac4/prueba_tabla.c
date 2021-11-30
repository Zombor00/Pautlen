#include "tabla_hash.h"

int main(){

  extern FILE* entrada;
  extern FILE* salida;
  tuple** tabla_global = NULL;
  tuple** tabla_local = NULL;
  value* result = NULL;
  char* string = NULL;
  int* num = NULL;

  /* Comprobamos que se pasan los argumentos correctamente */
  if (argc != 3){
    printf("Debe indicarse file de entrada y de salida\n");
    return 1;
  }

  /* Leemos el fichero de entrada */
  entrada = fopen(argv[1], "r");
  if(yyin == NULL){
    printf("Error leyendo el fichero de entrada!\n");
    return 1;
  }

  /* Creamos el fichera de salida */
  salida = fopen(argv[2], "w");
  if(yyout == NULL){
    printf("Error creando el fichero de salida!\n");
    fclose(yyin);
    return 1;
  }

  /*Creamos la tabla global*/
  tabla_global = create_table();
  if(tabla_global != NULL){
    printf("Error creando la tabla global!\n");
  }

  fscanf(entrada, "%s %d", &string, &num);
  while(string != NULL){
    if(num == NULL){
      result = get(string, tabla_global);
    }else if(num != NULL && num > 0){
      insert(string, 0, 0, 0, 0, 0, 0, 0, 0, tabla_global);
    }else if(num != NULL && num < 0){
      insert(string, 0, 0, 0, 0, 0, 0, 0, 0, tabla_global);
      /*Creamos la tabla local*/
      if(tabla_local != NULL){
        wipe(tabla_local);
        tabla_local = NULL;
      }
      tabla_local = create_table();
      if(tabla_local != NULL){
        printf("Error creando la tabla local!\n");
      }
      insert(string, 0, 0, 0, 0, 0, 0, 0, 0, tabla_local);
    }
  }

  /*
  if(insert("HOLA", 0, 0, 0, 0, 0, 0, 0, 0, tabla_hash) == INSERTED) printf("TOMA YA! x2\n");

  result = get("HOLA", tabla_hash);
  if(result != NULL) printf("TOMA YA! x3\n");

  if(insert("HOLA", 0, 0, 0, 0, 0, 0, 0, 0, tabla_hash) == FOUND) printf("TOMA YA! x4\n");
  wipe(tabla_hash);
  */
  return 0;
}
