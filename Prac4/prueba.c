#include "tabla_hash.h"

int main(){
  tuple** tabla_hash;
  value* val = NULL;
  value* result = NULL;

  val = (value*)malloc(sizeof(value));
  val->element_category = 0;
  val->basic_type = 0;
  val->category = 0;
  val->size = 0;
  val->num_params = 0;
  val->pos_param = 0;
  val->num_local_variables = 0;
  val->pos_local_variable = 0;

  tabla_hash = create_table();
  if(tabla_hash != NULL){
    printf("TOMA YA!\n");
  }

  if(insert("HOLA", val, tabla_hash) == INSERTED) printf("TOMA YA! x2\n");

  result = get("HOLA", tabla_hash);
  if(result != NULL) printf("TOMA YA! x3\n");

  if(insert("HOLA", val, tabla_hash) == FOUND) printf("TOMA YA! x4\n");
  return 0;
}
