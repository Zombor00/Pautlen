/*Mismo ejemplo que el ejemplo5 dado pero con un if anidado en el que si
m>2 imprime el numero 24*/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generacion.h"
int main (int argc, char ** argv)
{
  if (argc != 2) {fprintf (stdout, "ERROR POCOS ARGUMENTOS\n"); return -1;}
  int etiqueta = 0;
  int getiqueta = 0;
  int etiquetas[MAX_ETIQUETAS];
  int cima_etiquetas=-1;
  FILE * fd_asm;
  fd_asm = fopen(argv[1],"w");
  escribir_subseccion_data(fd_asm);
  escribir_cabecera_bss(fd_asm);
  //int m;
  declarar_variable(fd_asm,"m", 1, 1);
  //int [4] v;
  declarar_variable(fd_asm, "v", 1, 4);
  escribir_segmento_codigo(fd_asm);
  escribir_inicio_main(fd_asm);
  //m=0;
  escribir_operando(fd_asm,"0",0);
  asignar(fd_asm,"m",0);
  //While. Gestion inicial de las etiquetas, guardado de etiqueta.
  getiqueta++;
  cima_etiquetas++;
  etiquetas[cima_etiquetas]=getiqueta;
  //Inicio del while. Impresion de la etiqueta.
  etiqueta = etiquetas[cima_etiquetas];
  while_inicio(fd_asm, etiqueta);
  //Condicion del bucle while.
  escribir_operando(fd_asm,"m",1);
  escribir_operando(fd_asm,"4",0);
  menor_igual(fd_asm,1,0,etiqueta);
  //Recuperamos la etiqueta para imprimir la comparacion del while.
  etiqueta = etiquetas[cima_etiquetas];
  while_exp_pila(fd_asm, 0, etiqueta);

  //printf m
  escribir_operando(fd_asm,"m",1);
  escribir(fd_asm,1,ENTERO);

  /*Inicio if anidado*/
  //Gestion de etiquetas para abrir el ambito del if. Esta sera la etiqueta que tenga.
  getiqueta++;
  cima_etiquetas++;
  etiquetas[cima_etiquetas]=getiqueta;
  etiqueta = getiqueta;
  //Condición del if. Salto a fin si, si la condicion se da.
  escribir_operando(fd_asm,"m",1);
  escribir_operando(fd_asm,"2",0);
  mayor(fd_asm,1,0,etiqueta);
  ifthen_inicio(fd_asm, 0, etiqueta);
  //printf 24
  escribir_operando(fd_asm,"24",0);
  escribir(fd_asm,0,ENTERO);
  //Fin del condicional if. Imprimimos la etiqueta de ambito del fin del condicional y restamos el contador.
  etiqueta = etiquetas[cima_etiquetas];
  ifthen_fin(fd_asm, etiqueta);
  //Al cerrar el ámbito, decrementamos el contador de cima de etiquetas.
  cima_etiquetas--;
  /*Fin if anidado*/


  //v[m] = m*10;
  escribir_operando(fd_asm,"m",1);
  escribir_operando(fd_asm,"10",0);
  multiplicar(fd_asm,1,0);
  escribir_operando(fd_asm,"m",1);
  escribir_elemento_vector(fd_asm,"v", 4, 1);
  asignarDestinoEnPila(fd_asm,0);
  //m = m + 1
  escribir_operando(fd_asm,"m",1);
  escribir_operando(fd_asm,"1",0);
  sumar(fd_asm,1,0);
  asignar(fd_asm,"m",0);

  //Recuperamos la etiqueta para imprimir el fin de etiqueta del while.
  etiqueta = etiquetas[cima_etiquetas];
  while_fin(fd_asm, etiqueta);
  //Al cerrar el ámbito, decrementamos el contador de cima de etiquetas.
  cima_etiquetas--;
  escribir_fin(fd_asm);
  fclose(fd_asm);
}
