%{
#include <stdio.h>
#include "alfa.h"
#include "tabla_hash.h"
#include "generacion.h"
#define LOCAL 0
#define GLOBAL 1

extern int yy_morph_error;
extern long yylin;
extern long yycol;
extern FILE * yyout;

hash_table *tabla_global = NULL;
hash_table *tabla_local = NULL;
int ambito = GLOBAL;

int num_variables_locales_actual;
int pos_variable_local_actual;
int num_parametros_actual;
int pos_parametro_actual;

int tipo_actual;
int clase_actual;
int tamanio_vector_actual;
int num_parametros_llamada_actual;

tuple **contents;
int i;

char nombre_funcion_actual[MAX_LONG_ID];

int etiqueta = 1;
int size = 0;

value *val_local = NULL;
value *val_global = NULL;
value *val = NULL;
int res;
char str_aux[MAX_LONG_ID];


int en_explist = FALSE;
/*VARIABLES PARA COMPROBAR RETORNOS*/
int existe_retorno = FALSE; /*FALSE: no existe retorno, TRUE: SI existe*/

int yylex();
void error_semantico(error_sem err, char* id);
void yyerror(const char * s);
%}

%union {
   info_atributos atributos;
}

%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token TOK_ARRAY
%token TOK_FUNCTION
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_SCANF
%token TOK_PRINTF
%token TOK_RETURN

%token TOK_PUNTOYCOMA
%token TOK_COMA
%token TOK_PARENTESISIZQUIERDO
%token TOK_PARENTESISDERECHO
%token TOK_CORCHETEIZQUIERDO
%token TOK_CORCHETEDERECHO
%token TOK_LLAVEIZQUIERDA
%token TOK_LLAVEDERECHA

%token TOK_ASIGNACION
%token TOK_MAS
%token TOK_MENOS
%token TOK_DIVISION

%token TOK_ASTERISCO
%token TOK_AND
%token TOK_OR
%token TOK_NOT
%token TOK_IGUAL
%token TOK_DISTINTO
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_MENOR
%token TOK_MAYOR

%token <atributos> TOK_CONSTANTE_ENTERA
%token TOK_TRUE
%token TOK_FALSE

%token <atributos> TOK_IDENTIFICADOR

%type <atributos> fn_name
%type <atributos> fn_declaration
%type <atributos> elemento_vector
%type <atributos> if_exp_sentencias
%type <atributos> if_exp
%type <atributos> while_exp
%type <atributos> while
%type <atributos> exp
%type <atributos> idf_llamada_funcion
%type <atributos> comparacion
%type <atributos> constante
%type <atributos> constante_logica
%type <atributos> constante_entera
%type <atributos> identificador

%left TOK_IGUAL TOK_MENORIGUAL TOK_MENOR TOK_MAYORIGUAL TOK_MAYOR TOK_DISTINTO
%left TOK_AND TOK_OR
%left TOK_MAS TOK_MENOS
%left TOK_ASTERISCO TOK_DIVISION
%right NEG TOK_NOT

%%

programa:                 inicioTabla TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones escritura_TS funciones escritura_main sentencias TOK_LLAVEDERECHA
                              {
                                escribir_fin(yyout);
                                wipe(tabla_global);
                              }
                          ;
inicioTabla:                /* empty */ {
                                /*Creamos la tabla global*/
                                tabla_global = create_table();
                                if (tabla_global == NULL)
                                {
                                  printf("Error creando la tabla global!\n");
                                  return -1;
                                }
                              }
                          ;

escritura_TS:                 {
                                //Aqui tenemos que crear la cabecera del segmento BSS y el de datos
                                escribir_cabecera_bss(yyout);

                                contents = extract_table_contents(tabla_global);
                                for(i = 0; i < tabla_global->n_elems; i++){
                                  declarar_variable(yyout, contents[i]->name, contents[i]->val->basic_type, contents[i]->val->size);
                                }

                                escribir_subseccion_data(yyout);
                                escribir_segmento_codigo(yyout);
                              }
                          ;
escritura_main:               {escribir_inicio_main(yyout);}
                          ;

declaraciones:            declaracion

                          |   declaracion declaraciones

                          ;
declaracion:              clase identificadores TOK_PUNTOYCOMA

                          ;
clase:                    clase_escalar
                              {clase_actual = ESCALAR;}
                          |   clase_vector
                              {clase_actual = VECTOR;}
                          ;
clase_escalar:            tipo

                          ;
tipo:                     TOK_INT
                              {tipo_actual = INT;}
                          |   TOK_BOOLEAN
                              {tipo_actual = BOOLEAN;}
                          ;
clase_vector:             TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO constante_entera TOK_CORCHETEDERECHO
                              {tamanio_vector_actual = $4.valor_entero;}
                          ;
identificadores:          identificador

                          |   identificador TOK_COMA identificadores

                          ;
funciones:                funcion funciones

                          |   /* vacío */

                          ;
fn_name:                  TOK_FUNCTION tipo identificador
                              {
                                if(ambito == LOCAL){
                                  error_semantico(VAR_LOCAL_NO_ESCALAR, NULL);
                                  return -1;
                                }
                                res = insert($3.nombre, FUNCION, tipo_actual, clase_actual, 0, 0, 0, 0, 0, tabla_global);
                                if(res == FOUND)
                                {
                                  /*Se encuentra el elemento solicitado, error semantico.*/
                                  error_semantico(DECLARACION_DUPLICADA, NULL);
                                  return -1;
                                }
                                else if(res == INSERTED)
                                {
                                  /*No se encuentra el elemento solicitado, se abre el ambito local.*/
                                  tabla_local = create_table();
                                  if (tabla_local == NULL)
                                  {
                                    printf("Error creando la tabla local!\n");
                                    wipe(tabla_global);
                                    return -1;
                                  }
                                  res = insert($3.nombre, FUNCION, tipo_actual, 0, 0, 0, 0, 0, 0, tabla_local);
                                  ambito = LOCAL;
                                  num_variables_locales_actual = 0;
                                  pos_variable_local_actual = 1;
                                  num_parametros_actual = 0;
                                  pos_parametro_actual = 0;
                                  strcpy($$.nombre, $3.nombre);
                                  strcpy(nombre_funcion_actual, $$.nombre);
                                }
                              }
                          ;

fn_declaration:           fn_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion
                              {
                                strcpy($$.nombre, $1.nombre);
                                res = set($1.nombre, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE, num_parametros_actual, NO_CHANGE, num_variables_locales_actual, NO_CHANGE, tabla_local);
                                if(res == ERROR){
                                  error_semantico(VARIABLE_NO_DECLARADA, $1.nombre);
                                  return -1;
                                }
                                declararFuncion(yyout, $1.nombre, num_variables_locales_actual);
                              }
                          ;
funcion:                  fn_declaration sentencias TOK_LLAVEDERECHA
                              {
                                /*Hay que comprobar que haya un return y que el tipo del retorno sea = tipo de la variable retornada por la funcion*/
                                if(existe_retorno == FALSE){
                                  error_semantico(FUNC_NO_RETURN, NULL);
                                  return -1;
                                }
                                val = get($1.nombre, tabla_global);
                                if(val == NULL){
                                  error_semantico(VARIABLE_NO_DECLARADA, $1.nombre);
                                  return -1;
                                }

                                wipe(tabla_local);
                                ambito = GLOBAL;
                                set($1.nombre, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE, num_parametros_actual, NO_CHANGE, num_variables_locales_actual, NO_CHANGE, tabla_global);
                                existe_retorno = FALSE;
                              }
                          ;

parametros_funcion:       parametro_funcion resto_parametros_funcion

                          |   /* vacío */

                          ;
resto_parametros_funcion: TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion

                          |   /* vacío */

                          ;
parametro_funcion:        tipo idpf

                          ;
idpf:                     TOK_IDENTIFICADOR
                            {
                              if(clase_actual == VECTOR){
                                error_semantico(PARAM_ES_FUNC, NULL);
                                return -1;
                              }
                              res = insert($1.nombre, PARAMETRO, tipo_actual, clase_actual, 0, 0, pos_parametro_actual, 0, 0, tabla_local);
                              if(res == FOUND){
                                  error_semantico(DECLARACION_DUPLICADA, NULL);
                                  return -1;
                              }
                              pos_parametro_actual++;
                              num_parametros_actual++;
                            }
                          ;
declaraciones_funcion:    declaraciones

                          |   /* vacío */

                          ;
sentencias:               sentencia

                          |   sentencia sentencias

                          ;
sentencia:                sentencia_simple TOK_PUNTOYCOMA

                          |   bloque

                          ;
sentencia_simple:         asignacion

                          |   lectura

                          |   escritura

                          |   retorno_funcion

                          ;
bloque:                   condicional

                          |   bucle

                          ;


asignacion:               TOK_IDENTIFICADOR TOK_ASIGNACION exp
                              {
                                if(ambito == LOCAL){
                                  val = get($1.nombre, tabla_local);
                                } else {
                                  val = get($1.nombre, tabla_global);
                                }
                                if(val){ /*Si encontramos el simbolo en el ambito local / global */
                                  if(val->element_category != FUNCION && val->category == ESCALAR
                                    && val->basic_type == $3.tipo){
                                      asignar(yyout, $1.nombre, $3.es_direccion);
                                  } else {
                                    error_semantico(ASIGN_INCOMPATIBLE, NULL);
                                    return -1;
                                  }
                                }
                              }
                          |   elemento_vector TOK_ASIGNACION exp
                              {
                                if($1.tipo == $3.tipo){
                                  asignarDestinoEnPila(yyout, $3.es_direccion);
                                } else {
                                  error_semantico(ASIGN_INCOMPATIBLE, NULL);
                                  return -1;
                                }
                              }
                          ;
elemento_vector:          TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO
                              {
                                if(ambito == LOCAL){
                                  val = get($1.nombre, tabla_local);
                                } else {
                                  val = get($1.nombre, tabla_global);
                                }
                                if(val){
                                  if(val->category == VECTOR){
                                    if($3.tipo == INT){
                                      $$.tipo = val->basic_type;
                                      $$.es_direccion = VALOR_REFERENCIA;
                                      escribir_elemento_vector(yyout, $1.nombre, val->size, $3.es_direccion);
                                    }else{
                                      error_semantico(INDEX_INT, NULL);
                                      return -1;
                                    }
                                  }else{
                                    error_semantico(INDEX_NO_VECTOR, NULL);
                                    return -1;
                                  }
                                }else {
                                  error_semantico(VARIABLE_NO_DECLARADA, $1.nombre);
                                  return -1;
                                }

                              }
                          ;
condicional:              if_exp sentencias TOK_LLAVEDERECHA
                              {
                                ifthen_fin(yyout, $1.etiqueta);
                              }
                          | if_exp_sentencias TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
                              {
                                ifthenelse_fin(yyout, $1.etiqueta);
                              }
                          ;
if_exp_sentencias:        if_exp sentencias TOK_LLAVEDERECHA
                              {
                                $$.etiqueta = $1.etiqueta;
                                ifthenelse_fin_then(yyout, $1.etiqueta);
                              }
                          ;
if_exp:                   TOK_IF TOK_PARENTESISDERECHO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA
                              {
                                if($3.tipo != BOOLEAN){
                                  error_semantico(CONDICIONAL_INT, NULL);
                                }
                                $$.etiqueta = etiqueta++;
                                ifthen_inicio(yyout, $3.es_direccion, $$.etiqueta);
                              }
                          ;
bucle:                    while_exp sentencias TOK_LLAVEDERECHA
                              {
                                while_fin(yyout, $1.etiqueta);
                              }
                          ;
while_exp:                while exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA
                              {
                                if($2.tipo != BOOLEAN){
                                  error_semantico(CONDICIONAL_INT, NULL);
                                  return -1;
                                }
                                $$.etiqueta = $2.etiqueta;
                                while_exp_pila(yyout, $2.es_direccion, $2.etiqueta);
                              }
                          ;
while:                    TOK_WHILE TOK_PARENTESISIZQUIERDO
                              {
                                $$.etiqueta = etiqueta++;
                                while_inicio(yyout, $$.etiqueta);
                              }
                          ;
lectura:                  TOK_SCANF TOK_IDENTIFICADOR
                              {
                                val_global = get($2.nombre, tabla_global);
                                val_local = get($2.nombre, tabla_local);
                                if(val_local == NULL && val_global == NULL){
                                  error_semantico(VARIABLE_NO_DECLARADA, $2.nombre);
                                  return -1;
                                } else if(val_local) { //Si la encontramos en la tabla local
                                  if(val_local->element_category == FUNCION || val_local->category == VECTOR){
                                    error_semantico(LECTURA_ERROR, NULL);
                                    return -1;
                                  } else {
                                    if(val_local->basic_type == INT){
                                      leer(yyout, $2.nombre, INT);
                                    } else if(val_local->basic_type == BOOLEAN){
                                      leer(yyout, $2.nombre, BOOLEAN);
                                    }
                                  }
                                } else { //si la encontramos en la tabla global
                                  if(val_global->element_category == FUNCION || val_global->element_category == VECTOR){
                                    error_semantico(LECTURA_ERROR, NULL);
                                    return -1;
                                  } else {
                                    if(val_global->basic_type == INT){
                                      leer(yyout, $2.nombre, INT);
                                    } else if(val_global->basic_type == BOOLEAN){
                                      leer(yyout, $2.nombre, BOOLEAN);
                                    }
                                  }
                                }
                              }
                          ;
escritura:                TOK_PRINTF exp
                              {
                                escribir(yyout, $2.es_direccion, $2.tipo);
                              }
                          ;
retorno_funcion:          TOK_RETURN exp
                              {
                                if (ambito != LOCAL){
                                  error_semantico(RETURN_OUT_FUNC, NULL);
                                  return -1;
                                }
                                val = get(nombre_funcion_actual, tabla_local);
                                if(!val){
                                  error_semantico(VARIABLE_NO_DECLARADA, nombre_funcion_actual);
                                  return -1;
                                }
                                if($2.valor_entero != 0 && $2.valor_entero != 1){
                                  /*TODO: Las direcciones de
                                    exp siempre tienen
                                    que ser 0 ó 1.,??*/
                                  fprintf(stderr, "Error valor ilegal! en valor_entero");
                                  return -1;
                                }
                                if(val->basic_type != $2.tipo){
                                  error_semantico(RETORNO_DIFERENTE_TIPO, NULL);
                                  return -1;
                                }
                                /*Actualizamos variable de retorno*/
                                existe_retorno = TRUE;
                                retornarFuncion(yyout, $2.es_direccion);
                              }
                          ;
exp:                      exp TOK_MAS exp
                              {
                                if($1.tipo == INT && $3.tipo == INT){
                                  $$.valor_entero = $1.valor_entero + $3.valor_entero;
                                  $$.tipo = INT;
                                  sumar(yyout, $1.es_direccion, $3.es_direccion);
                                } else {
                                  error_semantico(OPERACION_ARITMETICA_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
                          |   exp TOK_MENOS exp
                              {
                                if($1.tipo == INT && $3.tipo == INT){
                                  $$.valor_entero = $1.valor_entero - $3.valor_entero;
                                  $$.tipo = INT;
                                  restar(yyout, $1.es_direccion, $3.es_direccion);
                                } else {
                                  error_semantico(OPERACION_ARITMETICA_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
                          |   exp TOK_DIVISION exp
                              {
                                if($1.tipo == INT && $3.tipo == INT){
                                  $$.valor_entero = $1.valor_entero / $3.valor_entero;
                                  $$.tipo = INT;
                                  dividir(yyout, $1.es_direccion, $3.es_direccion);
                                } else {
                                  error_semantico(OPERACION_ARITMETICA_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
                          |   exp TOK_ASTERISCO exp
                              {
                                if($1.tipo == INT && $3.tipo == INT){
                                  $$.valor_entero = $1.valor_entero * $3.valor_entero;
                                  $$.tipo = INT;
                                  multiplicar(yyout, $1.es_direccion, $3.es_direccion);
                                } else {
                                  error_semantico(OPERACION_ARITMETICA_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
                          |   TOK_MENOS exp %prec NEG
                              {
                                if($2.tipo == INT){
                                  $$.valor_entero = - $2.valor_entero;
                                  $$.tipo = INT;
                                  cambiar_signo(yyout, $2.es_direccion);
                                } else {
                                  error_semantico(OPERACION_ARITMETICA_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
                          |   exp TOK_AND exp
                              {
                                if($1.tipo == BOOLEAN && $3.tipo == BOOLEAN){
                                  $$.tipo = BOOLEAN;
                                  $$.valor_entero = $1.valor_entero && $3.valor_entero;
                                  $$.es_direccion = VALOR_EXPLICITO;
                                  y(yyout, $1.es_direccion, $3.es_direccion);
                                } else {
                                  error_semantico(OPERACION_LOGICA_INT, NULL);
                                  return -1;
                                }
                              }
                          |   exp TOK_OR exp
                              {
                                if($1.tipo == BOOLEAN && $3.tipo == BOOLEAN){
                                  $$.tipo = BOOLEAN;
                                  $$.valor_entero = $1.valor_entero || $3.valor_entero;
                                  $$.es_direccion = VALOR_EXPLICITO;
                                  o(yyout, $1.es_direccion, $3.es_direccion);
                                } else {
                                  error_semantico(OPERACION_LOGICA_INT, NULL);
                                  return -1;
                                }
                              }
                          |   TOK_NOT exp
                              {
                                if($2.tipo == BOOLEAN){
                                  $$.tipo = BOOLEAN;
                                  $$.valor_entero = ! $2.valor_entero;
                                  $$.es_direccion = VALOR_EXPLICITO;
                                  no(yyout, $2.es_direccion, 1);
                                } else {
                                  error_semantico(OPERACION_LOGICA_INT, NULL);
                                  return -1;
                                }
                              }
                          |   TOK_IDENTIFICADOR
                              {
                                val_local = get($1.nombre, tabla_local);
                                val_global = get($1.nombre, tabla_global);
                                if(val_local == NULL && val_global == NULL){
                                  error_semantico(VARIABLE_NO_DECLARADA, $1.nombre);
                                  return -1;
                                } else if(val_local) {
                                  if(val_local->element_category == FUNCION || val_local->category == VECTOR){
                                    error_semantico(ASIGN_INCOMPATIBLE, NULL);
                                    return -1;
                                  } else {
                                    $$.tipo = val_local->basic_type;
                                    $$.es_direccion = VALOR_REFERENCIA;
                                    if(en_explist == TRUE){
                                      escribirParametro(yyout, val_local->pos_param, val_local->num_params);
                                    } else {
                                      escribir_operando(yyout, $1.nombre, VALOR_REFERENCIA);
                                    }
                                  }
                                } else {
                                  if(val_global->element_category == FUNCION || val_global->category == VECTOR){
                                    error_semantico(ASIGN_INCOMPATIBLE, NULL);
                                    return -1;
                                  } else {
                                    $$.tipo = val_global->basic_type;
                                    $$.es_direccion = VALOR_REFERENCIA;
                                    if(en_explist == TRUE){
                                      escribirParametro(yyout, val_global->pos_param, val_global->num_params);
                                    } else {
                                      escribir_operando(yyout, $1.nombre, VALOR_REFERENCIA);
                                    }                                  }
                                }
                                strcpy($$.nombre, $1.nombre);
                              }
                          |   constante
                              {
                                $$.tipo = $1.tipo;
                                $$.es_direccion = $1.es_direccion;
                                $$.valor_entero = $1.valor_entero;
                                sprintf(str_aux, "%d", $1.valor_entero);
                                escribir_operando(yyout, str_aux, VALOR_EXPLICITO);
                              }
                          |   TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO
                              {
                                $$.tipo = $2.tipo;
                                $$.es_direccion = $2.es_direccion;
                                sprintf(str_aux, "%d", $2.valor_entero);
                                escribir_operando(yyout, str_aux, VALOR_EXPLICITO);
                              }
                          |   TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO
                              {
                                $$.tipo = $2.tipo;
                                $$.es_direccion = $2.es_direccion;
                                sprintf(str_aux, "%d", $2.valor_entero);
                                escribir_operando(yyout, str_aux, VALOR_EXPLICITO);
                              }
                          |   elemento_vector
                              {
                                $$.tipo = $1.tipo;
                                $$.es_direccion = $1.es_direccion;
                                if(en_explist == TRUE){
                                  escribirParametro(yyout, pos_parametro_actual, num_parametros_actual);
                                } else {
                                  escribir_operando(yyout, $1.nombre, $1.es_direccion);
                                }
                              }
                          |   idf_llamada_funcion TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO
                              {
                                val = get($1.nombre, tabla_global);
                                if(val->num_params == num_parametros_llamada_actual){
                                  llamarFuncion(yyout, $1.nombre, num_parametros_llamada_actual);
                                  en_explist = FALSE;
                                  $$.tipo = val->basic_type;
                                  $$.es_direccion = VALOR_EXPLICITO;
                                } else {
                                  error_semantico(NUMERO_PARAMS_FUNC, NULL);
                                  return -1;
                                }
                              }
                          ;
idf_llamada_funcion:      TOK_IDENTIFICADOR
                              {
                                val = get($1.nombre, tabla_global);
                                if(val == NULL){
                                  error_semantico(VARIABLE_NO_DECLARADA, $1.nombre);
                                } else { //Si encuentra la función
                                  if(val->element_category == FUNCION && en_explist == FALSE){
                                    num_parametros_llamada_actual = 0;
                                    en_explist = TRUE;
                                    strcpy($$.nombre, $1.nombre);
                                  } else {
                                    error_semantico(LLAMADA_NO_FUNCION, NULL);
                                    return -1;
                                  }
                                }
                              }
lista_expresiones:        exp resto_lista_expresiones
                              {
                                num_parametros_llamada_actual++;
                              }
                          |   /* vacío */

                          ;
resto_lista_expresiones:  TOK_COMA exp resto_lista_expresiones
                              {
                                num_parametros_llamada_actual++;
                              }
                          |   /* vacío */

                          ;
comparacion:              exp TOK_IGUAL exp
                              {
                                if($1.tipo == INT && $3.tipo == INT){
                                  $$.tipo = BOOLEAN;
                                  $$.valor_entero = ($1.valor_entero == $3.valor_entero);
                                  $$.es_direccion = VALOR_EXPLICITO;
                                  igual(yyout, $1.es_direccion, $3.es_direccion, etiqueta);
                                  etiqueta++;
                                } else {
                                  error_semantico(COMPARACION_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
                          |   exp TOK_DISTINTO exp
                              {
                                if($1.tipo == INT && $3.tipo == INT){
                                  $$.tipo = BOOLEAN;
                                  $$.valor_entero = ($1.valor_entero != $3.valor_entero);
                                  $$.es_direccion = VALOR_EXPLICITO;
                                  distinto(yyout, $1.es_direccion, $3.es_direccion, etiqueta);
                                  etiqueta++;
                                } else {
                                  error_semantico(COMPARACION_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
                          |   exp TOK_MENORIGUAL exp
                              {
                                if($1.tipo == INT && $3.tipo == INT){
                                  $$.tipo = BOOLEAN;
                                  $$.valor_entero = ($1.valor_entero <= $3.valor_entero);
                                  $$.es_direccion = VALOR_EXPLICITO;
                                  menor_igual(yyout, $1.es_direccion, $3.es_direccion, etiqueta);
                                  etiqueta++;
                                } else {
                                  error_semantico(COMPARACION_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
                          |   exp TOK_MAYORIGUAL exp
                              {
                                if($1.tipo == INT && $3.tipo == INT){
                                  $$.tipo = BOOLEAN;
                                  $$.valor_entero = ($1.valor_entero >= $3.valor_entero);
                                  $$.es_direccion = VALOR_EXPLICITO;
                                  mayor_igual(yyout, $1.es_direccion, $3.es_direccion, etiqueta);
                                  etiqueta++;
                                } else {
                                  error_semantico(COMPARACION_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
                          |   exp TOK_MENOR exp
                              {
                                if($1.tipo == INT && $3.tipo == INT){
                                  $$.tipo = BOOLEAN;
                                  $$.valor_entero = ($1.valor_entero < $3.valor_entero);
                                  $$.es_direccion = VALOR_EXPLICITO;
                                  menor(yyout, $1.es_direccion, $3.es_direccion, etiqueta);
                                  etiqueta++;
                                } else {
                                  error_semantico(COMPARACION_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
                          |   exp TOK_MAYOR exp
                              {
                                if($1.tipo == INT && $3.tipo == INT){
                                  $$.tipo = BOOLEAN;
                                  $$.valor_entero = ($1.valor_entero > $3.valor_entero);
                                  $$.es_direccion = VALOR_EXPLICITO;
                                  mayor(yyout, $1.es_direccion, $3.es_direccion, etiqueta);
                                  etiqueta++;
                                } else {
                                  error_semantico(COMPARACION_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
                          ;
constante:                constante_logica
                              {
                                $$.tipo = $1.tipo;
                                $$.es_direccion = $1.es_direccion;
                              }
                          |   constante_entera
                              {
                                $$.tipo = $1.tipo;
                                $$.es_direccion = $1.es_direccion;
                              }
                          ;
constante_logica:         TOK_TRUE
                              {
                                $$.tipo = BOOLEAN;
                                $$.es_direccion = VALOR_EXPLICITO;
                                escribir_operando(yyout, "1", VALOR_EXPLICITO);
                              }
                          |   TOK_FALSE
                              {
                                $$.tipo = BOOLEAN;
                                $$.es_direccion = VALOR_EXPLICITO;
                                escribir_operando(yyout, "0", VALOR_EXPLICITO);
                              }
                          ;
constante_entera:         TOK_CONSTANTE_ENTERA
                              {
                                $$.valor_entero = $1.valor_entero;
                                $$.tipo = INT;
                                $$.es_direccion = VALOR_EXPLICITO;
                                sprintf(str_aux, "%d", $1.valor_entero);
                                escribir_operando(yyout, str_aux, VALOR_EXPLICITO);
                              }
                          ;
identificador:            TOK_IDENTIFICADOR
                              {
                                strcpy($$.nombre, $1.nombre);
                                pos_variable_local_actual++;
                                if(clase_actual == ESCALAR){
                                    size = 0;
                                } else{ //clase_actual == VECTOR
                                    size = tamanio_vector_actual;
                                    if ((size < 1) || (size > MAX_TAMANIO_VECTOR)){
                                      error_semantico(MAX_TAM_VECTOR, $1.nombre);
                                      return -1;
                                    }
                                }
                                if(ambito == LOCAL){
                                    if(clase_actual == ESCALAR){
                                        res = insert($1.nombre, VARIABLE, tipo_actual, clase_actual, 0, 0, 0, num_variables_locales_actual, pos_variable_local_actual, tabla_local);
                                    } else{ //if clase_actual == VECTOR
                                        error_semantico(VAR_LOCAL_NO_ESCALAR, NULL);
                                        return -1;
                                    }
                                } else {
                                    res = insert($1.nombre, VARIABLE, tipo_actual, clase_actual, size, 0, 0, 0, 0, tabla_global);
                                }
                                if(res == FOUND){
                                    error_semantico(DECLARACION_DUPLICADA, NULL);
                                    return -1;
                                }
                              }

%%

void error_semantico(error_sem err, char* id) {
  if(err == DECLARACION_DUPLICADA){
    printf("****Error semantico en lin %ld: Declaracion duplicada.\n", yylin);
  } else if(err == VARIABLE_NO_DECLARADA){
    printf("****Error semantico en lin %ld: Acceso a variable no declarada (%s).\n", yylin, id);
  } else if(err == OPERACION_ARITMETICA_BOOLEAN){
    printf("****Error semantico en lin %ld: Operacion aritmetica con operandos boolean.\n", yylin);
  }else if(err == OPERACION_LOGICA_INT){
    printf("****Error semantico en lin %ld: Operacion logica con operandos int.\n", yylin);
  }else if(err == COMPARACION_BOOLEAN){
    printf("****Error semantico en lin %ld: Comparacion con operandos boolean.\n", yylin);
  }else if(err == CONDICIONAL_INT){
    printf("****Error semantico en lin %ld: Condicional con condicion de tipo int.\n", yylin);
  }else if(err == BUCLE_INT){
    printf("****Error semantico en lin %ld: Bucle con condicion de tipo int.\n", yylin);
  }else if(err == NUMERO_PARAMS_FUNC){
    printf("****Error semantico en lin %ld: Numero incorrecto de parametros en llamada a funcion.\n", yylin);
  }else if(err == ASIGN_INCOMPATIBLE){
    printf("****Error semantico en lin %ld: Asignacion incompatible.\n", yylin);
  }else if(err == MAX_TAM_VECTOR){
    printf("****Error semantico en lin %ld: El tamanyo del vector %s excede los limites permitidos (1,64).\n", yylin, id);
  }else if(err == INDEX_NO_VECTOR){
    printf("****Error semantico en lin %ld: Intento de indexacion de una variable que no es de tipo vector.\n", yylin);
  }else if(err == INDEX_INT){
    printf("****Error semantico en lin %ld: El indice en una operacion de indexacion tiene que ser de tipo entero.\n", yylin);
  }else if(err == FUNC_NO_RETURN){
    printf("****Error semantico en lin %ld: Funcion %s sin sentencia de retorno.\n", yylin, id);
  }else if(err == RETURN_OUT_FUNC){
    printf("****Error semantico en lin %ld: Sentencia de retorno fuera del cuerpo de una función.\n", yylin);
  }else if(err == PARAM_ES_FUNC){
    printf("****Error semantico en lin %ld: No esta permitido el uso de llamadas a funciones como parametros de otras funciones.\n", yylin);
  }else if(err == VAR_LOCAL_NO_ESCALAR){
    printf("****Error semantico en lin %ld: Variable local de tipo no escalar..\n", yylin);
  }else if(err == LECTURA_ERROR){
    printf("****Error semantico en lin %ld: Lectura no posible para Funcion o Vector\n", yylin);
  }else if(err == RETORNO_DIFERENTE_TIPO){
    printf("****Error semantico en lin %ld: El tipo del retorno la función no coincide con el tipo retornado\n", yylin);
  }else if(err == LLAMADA_NO_FUNCION){
    printf("****Error semantico en lin %ld: Llamada de tipo función a un elemento que no lo es\n", yylin);
  }else if(err == DIF_TIPOS){
    printf("****Error semantico en lin %ld: Intento de operación entre 2 variables de distinto tipo\n", yylin);
  }else if(err == PARAM_ES_VECTOR){
    printf("****Error semantico en lin %ld: No esta permitido el uso de vectores en los parametros de una función.\n", yylin);
  }

  wipe(tabla_global);
  if (ambito == LOCAL){
    wipe(tabla_local);
  }
}

void yyerror(const char * s) {
    if(!yy_morph_error) {
        printf("****Error sintactico en [lin %ld, col %ld]\n", yylin, yycol);
    }
    wipe(tabla_global);
    if (ambito == LOCAL){
      wipe(tabla_local);
    }
    return;
}
