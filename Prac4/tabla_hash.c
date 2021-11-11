#import <string.h>
#import <stdlib.h>

#define TAMANO_MAX 1024

struct Tupla{
   char* name;
   int val;
}tupla;

tupla hash_table[TAMANO_MAX];

int hash(char* name){
  int i = 0;
  int hash_val = 0;
  while(name[i] != '0'){
    hash_val = (hash_val + (name[i] - 48) * (23)**i) % TAMANO_MAX;
  }
}

int insertar(char* name, int val){
  int hash_val = 0;
  hash_val = hash(name);
  tupla tupla_found;
  tupla tupla_new;
  int i;
  for(i = 0; i < TAMANO_MAX; i++)
    tupla_found = hash_table[hash_val];
    if(tupla_found == NULL){
      tupla_new = {name, val};
      hash_table[hash_val] = tupla_new;
    }else if(strcmp(tupla_found.name, name) == 0){
      return 0;
    }else{
      //Si encuentras algo y no es la tupla a insertar, colisión.
      hash_val = (hash_val + 1) % TAMANO_MAX
    }
  }
}

int insertar(char* name, int val){
  int hash_val = 0;
  hash_val = hash(name);
  tupla tupla_found;
  tupla tupla_new;
  int i;
  for(i = 0; i < TAMANO_MAX; i++)
    tupla_found = hash_table[hash_val];
    if(tupla_found == NULL){
      tupla_new = {name, val};
      hash_table[hash_val] = tupla_new;
    }else if(strcmp(tupla_found.name, name) == 0){
      return 0;
    }else{
      //Si encuentras algo y no es la tupla a insertar, colisión.
      hash_val = (hash_val + 1) % TAMANO_MAX
    }
  }
}
