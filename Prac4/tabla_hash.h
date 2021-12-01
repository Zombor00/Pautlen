#ifndef HEADER_HASH
#define HEADER_HASH

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 1048576
/*CATEGORY*/
#define ESCALAR 1
#define VECTOR 2
/*ELEMENT_CATEGORY*/
#define VARIABLE 1
#define PARAMETRO 2
#define FUNCION 3
/*BASIC TYPE*/
#define BOOLEAN 1
#define INT 2

/*Returning*/
#define ERROR -1
#define INSERTED 0
#define FOUND 1

typedef struct Value value;
typedef struct Tuple tuple;

struct Value
{
  int element_category;
  int basic_type;
  int category;
  int size;       /*size will be 0 if the element is not a vector*/
  int num_params; /*These only apply if the element is a function*/
  int pos_param;
  int num_local_variables;
  int pos_local_variable;
};

struct Tuple
{
  char *name;
  value *val;
};

tuple **create_table();
int hash(char *name);
int insert(char *name, int element_category, int basic_type, int category, int size,
           int num_params, int pos_param, int num_local_variables, int pos_local_variable, tuple **hash_table);
value *get(char *name, tuple **hash_table);
int wipe(tuple **hash_table);

#endif
