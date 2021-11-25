#ifndef HEADER_HASH
#define HEADER_HASH

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 1024
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

typedef struct Value value;
typedef struct Tuple tuple;

tuple* create_table();
int hash(char* name);
int insert(char* name, value val, tuple* hash_table);
value get(char* name, tuple* hash_table);

#endif
