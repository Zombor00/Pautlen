#include "tabla_hash.h"

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
  }

  /*Leemos linea a linea*/
  while (fgets(buf, sizeof(buf), entrada) != NULL)
  {
    aux1 = strchr(buf, ' ');
    aux2 = strchr(buf, '\t');
    /*Extracción en ámbito global*/
    if (aux1 == NULL && aux2 == NULL)
    {
      buf[strlen(buf) - 1] = 0;
      result = get(buf, tabla_global);
      if (result == NULL)
      {
        /*No se encuentra el elemento solicitado*/
        fprintf(salida, "%s\t-1\n", buf);
        fflush(salida);
      }
      else
      {
        /*Se encuentra el elemento solicitado*/
        fprintf(salida, "%s\t%d\n", buf, result->basic_type);
        fflush(salida);
      }
    }
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
        res = insert(buf, 0, num, 0, 0, 0, 0, 0, 0, tabla_global);
        if (res == FOUND)
        {
          /*TODO: res == ERROR con frees y demás*/
          fprintf(salida, "-1\t%s\n", buf);
          fflush(salida);
        }
        else if (res == INSERTED)
        {
          fprintf(salida, "%s\n", buf);
          fflush(salida);
        }
      }
      /*Si el segundo elemento es negativo, abrimos ámbito local*/
      else if (num < 0)
      {
        res = insert(buf, 0, num, 0, 0, 0, 0, 0, 0, tabla_global);
        if (res == FOUND)
        {
          /*TODO: res == ERROR con frees y demás*/
          fprintf(salida, "-1\t%s\n", buf);
          fflush(salida);
        }
        else if (res == INSERTED)
        {

          fprintf(salida, "%s\n", buf);
          fflush(salida);
          tabla_local = create_table();
          if (tabla_local == NULL)
          {
            printf("Error creando la tabla local!\n");
          }

          insert(buf, 0, num, 0, 0, 0, 0, 0, 0, tabla_local);

          while (fgets(buf, sizeof(buf), entrada) != NULL)
          {
            aux1 = strchr(buf, ' ');
            aux2 = strchr(buf, '\t');
            if (aux1 == NULL && aux2 == NULL)
            {
              buf[strlen(buf) - 1] = 0;
              result_local = get(buf, tabla_local);
              result = get(buf, tabla_global);
              if (result == NULL && result_local == NULL)
              {
                fprintf(salida, "%s\t-1\n", buf);
                fflush(salida);
              }
              else if (result_local != NULL)
              {
                fprintf(salida, "%s\t%d\n", buf, result_local->basic_type);
                fflush(salida);
              }
              else
              {
                fprintf(salida, "%s\t%d\n", buf, result->basic_type);
                fflush(salida);
              }
            }
            else
            {
              if (aux1 == NULL)
              {
                aux2[0] = 0;
                aux2++;
                aux2[strlen(aux2) - 1] = 0;
                num = atoi(aux2);
              }
              else if (aux2 == NULL)
              {
                aux1[0] = 0;
                aux1++;
                aux1[strlen(aux1) - 1] = 0;
                num = atoi(aux1);
              }
              if (num > 0)
              {
                res = insert(buf, 0, num, 0, 0, 0, 0, 0, 0, tabla_local);
                if (res == FOUND)
                {
                  /*TODO: res == ERROR con frees y demás*/
                  fprintf(salida, "-1\t%s\n", buf);
                  fflush(salida);
                }
                else if (res == INSERTED)
                {
                  fprintf(salida, "%s\n", buf);
                  fflush(salida);
                }
              }
              else if (strcmp(buf, "cierre") == 0 && num == -999)
              {
                wipe(tabla_local);
                tabla_local = NULL;
                fprintf(salida, "cierre\n");
                fflush(salida);
                break;
              }
            }
          }
        }
      }
    }
  }
  fclose(entrada);
  fclose(salida);
  wipe(tabla_global);
  return 0;
}
