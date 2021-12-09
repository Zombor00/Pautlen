#include "tabla_hash.h"
#define LOCAL 0
#define GLOBAL 1

int main(int argc, char *argv[])
{

  FILE *entrada = NULL;
  FILE *salida = NULL;
  tuple **tabla_global = NULL;
  tuple **tabla_local = NULL;
  value *result = NULL;
  value *result_local = NULL;
  int num;
  int res;
  int ambito = GLOBAL;
  char buf[256];
  char *aux1 = NULL;
  char *aux2 = NULL;

  /* Comprobamos que se pasan los argumentos correctamente */
  if (argc != 3)
  {
    printf("Debe indicarse file de entrada y de salida\n");
    return 1;
  }

  /* Leemos el fichero de entrada */
  entrada = fopen(argv[1], "r");
  if (entrada == NULL)
  {
    printf("Error leyendo el fichero de entrada!\n");
    return 1;
  }

  /* Creamos el fichera de salida */
  salida = fopen(argv[2], "w");
  if (salida == NULL)
  {
    printf("Error creando el fichero de salida!\n");
    fclose(entrada);
    return 1;
  }

  /*Creamos la tabla global*/
  tabla_global = create_table();
  if (tabla_global == NULL)
  {
    printf("Error creando la tabla global!\n");
    fclose(entrada);
    fclose(salida);
    return 1;
  }

  /*Leemos linea a linea el fichero de entrada*/
  while (fgets(buf, sizeof(buf), entrada) != NULL)
  {
    aux1 = strchr(buf, ' ');
    aux2 = strchr(buf, '\t');
    /*Busqueda pues solo hay identificador, no entero*/
    if (aux1 == NULL && aux2 == NULL)
    {
      buf[strlen(buf) - 1] = 0;
      /*Si estamos en ámbito local buscamos primero en la tabla local*/
      if(ambito == LOCAL)
      {
        result_local = get(buf, tabla_local);
        /*Se encuentra el elemento solicitado en la tabla local*/
        if(result_local != NULL){
          fprintf(salida, "%s\t%d\n", buf, result_local->basic_type);
          fflush(salida);
          continue;
        }
      }
      /*Buscamos en el ámbito global*/
      result = get(buf, tabla_global);
      if (result != NULL)
      {
        /*Se encuentra el elemento solicitado*/
        fprintf(salida, "%s\t%d\n", buf, result->basic_type);
        fflush(salida);
      }
      else
      {
        /*No se encuentra el elemento solicitado*/
        fprintf(salida, "%s\t-1\n", buf);
        fflush(salida);
      }
    }
    /*Caso de que no es búsqueda*/
    else
    {
      /*Parseamos la linea dependiendo de si hay un espacio o un tabulador*/
      if (aux2 != NULL)
      {
        aux2[0] = 0;
        aux2++;
        aux2[strlen(aux2) - 1] = 0;
        num = atoi(aux2);
      }
      else
      {
        aux1[0] = 0;
        aux1++;
        aux1[strlen(aux1) - 1] = 0;
        num = atoi(aux1);
      }

      /*Si el segundo elemento es positivo, insertamos elemento*/
      if (num > 0)
      {
        if(ambito == GLOBAL){
          res = insert(buf, 0, num, 0, 0, 0, 0, 0, 0, tabla_global);
        }
        else
        {
          res = insert(buf, 0, num, 0, 0, 0, 0, 0, 0, tabla_local);
        }
        /*Elemento ya insertado*/
        if (res == FOUND)
        {
          fprintf(salida, "-1\t%s\n", buf);
          fflush(salida);
        }
        /*Elemento insertado correctamente*/
        else if (res == INSERTED)
        {
          fprintf(salida, "%s\n", buf);
          fflush(salida);
        }else if(res == ERROR){
          printf("La tabla hash está llena! Modificar tamanio en el .h");
          fflush(salida);
        }
      }
      /*Cierre de ámbito local*/
      else if(strcmp(buf, "cierre") == 0 && num == -999)
      {
        wipe(tabla_local);
        tabla_local = NULL;
        fprintf(salida, "cierre\n");
        fflush(salida);
        ambito = GLOBAL;
      }
      /*Si el segundo elemento es negativo, y no es un cierre se procede a abrir ámbito local*/
      else if (num < 0)
      {
        res = insert(buf, 0, num, 0, 0, 0, 0, 0, 0, tabla_global);
        /*Encontrado, por tanto, no abrimos ámbito local*/
        if (res == FOUND)
        {
          fprintf(salida, "-1\t%s\n", buf);
          fflush(salida);
        }
        /*Abrimos el ámbito local*/
        else if (res == INSERTED)
        {
          fprintf(salida, "%s\n", buf);
          fflush(salida);
          tabla_local = create_table();
          if (tabla_local == NULL)
          {
            printf("Error creando la tabla local!\n");
            fclose(entrada);
            fclose(salida);
            wipe(tabla_global);
            return 1;
          }

          res = insert(buf, 0, num, 0, 0, 0, 0, 0, 0, tabla_local);
          ambito = LOCAL;
        }
        else if(res == ERROR)
        {
          printf("La tabla hash está llena! Modificar tamanio en el .h");
          fflush(salida);
        }
      }
    }
  }
  fclose(entrada);
  fclose(salida);
  if(tabla_local != NULL)
  {
    wipe(tabla_local);
  }
  wipe(tabla_global);
  return 0;
}
