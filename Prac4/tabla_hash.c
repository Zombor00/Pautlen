#include "tabla_hash.h"

tuple **create_table()
{
  tuple **hash_table = NULL;
  hash_table = (tuple **)malloc(sizeof(tuple *) * MAX_SIZE);
  if (hash_table == NULL)
  {
    printf("Error creating hash_table!");
  }
  return hash_table;
}

int hash(char *name)
{
  int hash_val = 5381;
  int c;

  while (c = *name++)
    hash_val = ((hash_val << 5) + hash_val) + c; /* hash * 33 + c */

  return hash_val % MAX_SIZE;
}

int insert(char *name, value *val, tuple **hash_table)
{
  int hash_val = 0;
  tuple *tuple_found;
  tuple *tuple_new;
  int i;

  hash_val = hash(name);
  fprintf(stderr, "El valor hash es: %d \n", hash_val);
  tuple_found = NULL;

  for (i = 0; i < MAX_SIZE; i++)
  {
    tuple_found = hash_table[hash_val];
    if (tuple_found == NULL)
    {
      tuple_new = (tuple *)malloc(sizeof(tuple));
      tuple_new->name = name;
      tuple_new->val = val;
      hash_table[hash_val] = tuple_new;
      return INSERTED;
    }
    else if (strcmp(tuple_found->name, name) == 0)
    {
      return FOUND;
    }
    else
    {
      /*Si encuentras algo y no es la tuple a insertar, colisión.*/
      hash_val = (hash_val + 1) % MAX_SIZE;
    }
  }
  return ERROR;
}

value *get(char *name, tuple **hash_table)
{
  int hash_val = 0;
  tuple *tuple_found;
  int i;
  hash_val = hash(name);
  for (i = 0; i < MAX_SIZE; i++)
  {
    tuple_found = hash_table[hash_val];
    if (tuple_found == NULL)
    {
      return NULL;
    }
    else if (strcmp(tuple_found->name, name) == 0)
    {
      return tuple_found->val;
    }
    else
    {
      /*Si encuentras algo y no es la tuple a insertar, colisión.*/
      hash_val = (hash_val + 1) % MAX_SIZE;
    }
  }
  return NULL;
}

int wipe(tuple **hash_table)
{
  int i;
  if (!hash_table)
  {
    return -1;
  }
  for (i = 0; i < MAX_SIZE; i++)
  {
    if (hash_table[i])
    {
      /*If the element at hash position i exists we free it*/
      free(hash_table[i]);
    }
  }
  free(hash_table);
  return 0;
}
