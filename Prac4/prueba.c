#include "tabla_hash.h"

int main(){
  tuple** tabla_hash = NULL;
  value* result = NULL;

  tabla_hash = create_table();
  if(tabla_hash != NULL){
    printf("TOMA YA!\n");
  }

  if(insert("HOLA", 0, 0, 0, 0, 0, 0, 0, 0, tabla_hash) == INSERTED) printf("TOMA YA! x2\n");

  result = get("HOLA", tabla_hash);
  if(result != NULL) printf("TOMA YA! x3\n");

  if(insert("HOLA", 0, 0, 0, 0, 0, 0, 0, 0, tabla_hash) == FOUND) printf("TOMA YA! x4\n");
  wipe(tabla_hash);
  return 0;
}
