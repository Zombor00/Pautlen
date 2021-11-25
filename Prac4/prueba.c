#include "tabla_hash.h"

int main(){
  tuple* tabla_hash;
  value val = {0,0,0,0,0,0,0,0};
  value result;
  tabla_hash = create_table();
  if(tabla_hash != NULL){
    printf("TOMA YA!\n");
  }

  if(insert("HOLA", val, tabla_hash) == 0) printf("TOMA YA! x2\n");

  result = get("HOLA", tabla_hash);
  if(result != NULL) printf("TOMA YA! x3\n");

  if(insert("HOLA", val, tabla_hash) == 1) printf("TOMA YA! x4\n");
  return 0;
}
