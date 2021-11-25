#include "tabla_hash.h"

struct Value{
  int element_category;
  int basic_type;
  int category;
  int size; /*size will be 0 if the element is not a vector*/
  int num_params; /*These only apply if the element is a function*/
  int pos_param;
  int num_local_variables;
  int pos_local_variable;
};

struct Tuple{
   char* name;
   value val;
};

tuple* create_table(){
  tuple* hash_table = NULL;
  hash_table = (tuple*)malloc(sizeof(tuple) * MAX_SIZE);
  if(hash_table == NULL){
    printf("Error creating hash_table!");
  }
  return hash_table;
}

int hash(char* name){
  int i = 0;
  int hash_val = 0;
  while(name[i] != '0'){
    /*Que mierda de Hash te inventaste el otro día ALejandro*/
    hash_val = (int)(hash_val + (name[i] - 48) * pow(23,i)) % MAX_SIZE;
  }
}

int insert(char* name, value val, tuple* hash_table){
  int hash_val = 0;
  hash_val = hash(name);
  tuple* tuple_found = NULL;
  tuple tuple_new;
  int i;
  for(i = 0; i < MAX_SIZE; i++){
    tuple_found = &hash_table[hash_val];
    if(tuple_found == NULL){
      tuple_new = {name, val};
      hash_table[hash_val] = tuple_new;
      return 0;
    }else if(strcmp(tuple_found.name, name) == 0){
      return 1;
    }else{
      //Si encuentras algo y no es la tuple a insertar, colisión.
      hash_val = (hash_val + 1) % MAX_SIZE
    }
  }
  return NULL;
}

value get(char* name, tuple* hash_table){
  int hash_val = 0;
  hash_val = hash(name);
  tuple* tuple_found;
  int i;
  for(i = 0; i < MAX_SIZE; i++){
    tuple_found = hash_table[hash_val];
    if(tuple_found == NULL){
      return NULL;
    }else if(strcmp(tuple_found.name, name) == 0){
      return tuple_found.val;
    }else{
      //Si encuentras algo y no es la tuple a insertar, colisión.
      hash_val = (hash_val + 1) % MAX_SIZE
    }
  }
  return NULL;
}
