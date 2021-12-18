%{
#include <stdio.h>
#include "tabla_hash.h"
#define LOCAL 0
#define GLOBAL 1

extern int yy_morph_error;
extern long yylin;
extern long yycol;
extern FILE * yyout;

tuple **tabla_global = NULL;
tuple **tabla_local = NULL;
int ambito = GLOBAL;

int num_variables_locales_actual;
int pos_variable_local_actual;
int num_parametros_actual;
int pos_parametro_actual;

int tipo_actual;
int clase_actual;
int tamanio_vector_actual;

value *value_local = NULL;
value *value_global = NULL;
int res;

int yylex();
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

%type <atributos> exp
%type <atributos> constante
%type <atributos> identificador

%left TOK_IGUAL TOK_MENORIGUAL TOK_MENOR TOK_MAYORIGUAL TOK_MAYOR TOK_DISTINTO
%left TOK_AND TOK_OR
%left TOK_MAS TOK_MENOS
%left TOK_ASTERISCO TOK_DIVISION
%right NEG TOK_NOT

%%

programa:                 inicioTabla TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones funciones sentencias TOK_LLAVEDERECHA
                          {fprintf(yyout, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");}
                          ;
inicioTabla:              {
                            /*Creamos la tabla global*/
                            tabla_global = create_table();
                            if (tabla_global == NULL)
                            {
                              printf("Error creando la tabla global!\n");
                              //TODO: Comprobar valor del return
                              return 1;
                            }
                          };

declaraciones:            declaracion
                              {fprintf(yyout,";R2:\t<declaraciones> ::= <declaracion>\n");}
                          |   declaracion declaraciones
                              {fprintf(yyout,";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
                          ;
declaracion:              clase identificadores TOK_PUNTOYCOMA
                            {
                                fprintf(yyout,";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");

                            }
                          ;
clase:                    clase_escalar
                            {
                                fprintf(yyout,";R5:\t<clase> ::= <clase_escalar>\n");
                                clase_actual = ESCALAR;
                            }
                          |   clase_vector
                              {
                                fprintf(yyout,";R7:\t<clase> ::= <clase_vector>\n");
                                clase_actual = VECTOR;
                              }
                          ;
clase_escalar:            tipo
                              {fprintf(yyout,";R9:\t<clase_escalar> ::= <tipo>\n");}
                          ;
tipo:                     TOK_INT
                              {
                                fprintf(yyout,";R10:\t<tipo> ::= int\n");
                                //$$.valor = INT;
                                tipo_actual = INT;
                              }
                          |   TOK_BOOLEAN
                              {
                                fprintf(yyout,";R11:\t<tipo> ::= boolean\n");
                                //$$.valor = BOOLEAN;
                                tipo_actual = BOOLEAN;
                              }
                          ;
clase_vector:             TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO constante_entera TOK_CORCHETEDERECHO
                              {
                                fprintf(yyout,";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
                                tamanio_vector_actual = $4.valor;
                                if ((tamanio_vector_actual < 1) || (tamanio_vector_actual > MAX_TAMANIO_VECTOR)){
                                    yyerror(NULL); //TODO: pasamos null?
                                    //TODO: TERMINAR CON ERROR
                                }
                              }
                          ;
identificadores:          identificador
                              {fprintf(yyout,";R18:\t<identificadores> ::= <identificador>\n");}
                          |   identificador TOK_COMA identificadores
                              {fprintf(yyout,";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
                          ;
funciones:                funcion funciones
                              {fprintf(yyout,";R20:\t<funciones> ::= <funcion> <funciones>\n");}
                          |   /* vacío */
                              {fprintf(yyout,";R21:\t<funciones> ::= \n");}
                          ;
fn_name:                  TOK_FUNCTION tipo identificador
                              {
                                res = insert($3.id, FUNCION, $2.valor, 0, 0, 0, 0, 0, 0, tabla_global); //TODO: valores, $2.valor marcar en tipo
                                if(res == FOUND)
                                {
                                  /*Se encuentra el elemento solicitado, error semantico.*/
                                  printf("Identificador %s duplicado", $3.id);
                                  yyerror(NULL); //TODO: Dar error? para uqe deje de correr el programa
                                }
                                else if(res == INSERTED)
                                {
                                  /*No se encuentra el elemento solicitado, se abre el ambito local.*/
                                  tabla_local = create_table();
                                  if (tabla_local == NULL)
                                  {
                                    printf("Error creando la tabla local!\n");
                                    wipe(tabla_global);
                                    return 1;
                                  }
                                  res = insert($3.valor, FUNCION, $2.valor, 0, 0, 0, 0, 0, 0, tabla_local); //TODO: valores
                                  ambito = LOCAL;
                                  num_variables_locales_actual = 0;
                                  pos_variable_local_actual = 1;
                                  num_parametros_actual = 0;
                                  pos_parametro_actual = 0;
                                  $$.id = $3.id;
                                }
                              }
                          ;

fn_declaration:           fn_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion
                              {
                                $$.id = $1.id;
                                set($$.id, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE, num_parametros_actual, NO_CHANGE, NO_CHANGE, NO_CHANGE, tabla_local);
                              }
                              ;
funcion:                  fn_declaration sentencias TOK_LLAVEDERECHA
                              {
                                fprintf(yyout,";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");
                                wipe(tabla_local);
                                ambito = GLOBAL;
                                //TODO: este set???? pa que
                                set($1.id, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE, num_parametros_actual, NO_CHANGE, NO_CHANGE, NO_CHANGE, tabla_global);
                              }
                          ;

parametros_funcion:       parametro_funcion resto_parametros_funcion
                              {fprintf(yyout,";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
                          |   /* vacío */
                              {fprintf(yyout,";R24:\t<parametros_funcion> ::= \n");}
                          ;
resto_parametros_funcion: TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion
                              {fprintf(yyout,";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
                          |   /* vacío */
                              {fprintf(yyout,";R26:\t<resto_parametros_funcion> ::= \n");}
                          ;
parametro_funcion:        tipo idpf
                              {fprintf(yyout,";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");}
                          ;
idpf:                     TOK_IDENTIFICADOR
                            {
                                $$.id = $1.id;
                                res = insert($1.id, PARAMETRO, tipo_actual, clase_actual, 0, 0, pos_parametro_actual, 0, 0, tabla_local); //o insert
                                if(res == FOUND){
                                    /*TODO: error*/
                                } else {
                                    pos_parametro_actual++;
                                    num_parametros_actual++;
                                }
                            }

declaraciones_funcion:    declaraciones
                              {fprintf(yyout,";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
                          |   /* vacío */
                              {fprintf(yyout,";R29:\t<declaraciones_funcion> ::= \n");}
                          ;
sentencias:               sentencia
                              {fprintf(yyout,";R30:\t<sentencias> ::= <sentencia>\n");}
                          |   sentencia sentencias
                              {fprintf(yyout,";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
                          ;
sentencia:                sentencia_simple TOK_PUNTOYCOMA
                              {fprintf(yyout,";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
                          |   bloque
                              {fprintf(yyout,";R33:\t<sentencia> ::= <bloque>\n");}
                          ;
sentencia_simple:         asignacion
                              {fprintf(yyout,";R34:\t<sentencia_simple> ::= <asignacion>\n");}
                          |   lectura
                              {fprintf(yyout,";R35:\t<sentencia_simple> ::= <lectura>\n");}
                          |   escritura
                              {fprintf(yyout,";R36:\t<sentencia_simple> ::= <escritura>\n");}
                          |   retorno_funcion
                              {fprintf(yyout,";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
                          ;
bloque:                   condicional
                              {fprintf(yyout,";R40:\t<bloque> ::= <condicional>\n");}
                          |   bucle
                              {fprintf(yyout,";R41:\t<bloque> ::= <bucle>\n");}
                          ;
asignacion:               TOK_IDENTIFICADOR TOK_ASIGNACION exp /*TODO: aqui*/
                              {
                                fprintf(yyout,";R43:\t<asignacion> ::= <identificador> = <exp>\n");
                                res = get($1.id, tabla_local);
                                if(res == FOUND){
                                  /*id.valor = $3.valor en la tabla hash*/
                                }
                              }
                          |   elemento_vector TOK_ASIGNACION exp
                              {fprintf(yyout,";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");}
                          ;
elemento_vector:          TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO /*TODO: aqui*/
                              {fprintf(yyout,";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");}
                          ;
condicional:              TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
                              {fprintf(yyout,";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");}
                          |   TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
                              {fprintf(yyout,";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");}
                          ;
bucle:                    TOK_WHILE TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
                              {fprintf(yyout,";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");}
                          ;
lectura:                  TOK_SCANF TOK_IDENTIFICADOR
                              { //TODO: todo lo que hace de pila alfalib.o...
                                fprintf(yyout,";R54:\t<lectura> ::= scanf <identificador>\n");
                                value_global = get($2.id, tabla_global);
                                value_local = get($2.id, tabla_local);
                                if(value_local == NULL && value_global == NULL){
                                  yyerror(NULL);
                                  return(1);
                                  //TODO: handle error
                                } else if(value_local) {
                                  if(value_local->element_category == FUNCION
                                    || value_local->element_category == VECTOR){
                                    yyerror(NULL);
                                    return(1);
                                    //TODO: error
                                  } else {
                                    //direccion = en función de ebp y la posición del parámetro o variable local
                                    if(value_local->basic_type == INT){
                                      //llamar scan_int de alfalib.o
                                    } else if(value_local->basic_type == BOOLEAN){
                                      //llamar scan_boolean
                                    }
                                    //restaurar la pila
                                  }
                                } else {
                                  if(value_global->element_category == FUNCION
                                    || value_global->element_category == VECTOR){
                                    yyerror(NULL);
                                    return(1);
                                    //TODO: error
                                  } else {
                                    //direccion = su lexema $2.id??
                                    if(value_global->basic_type == INT){
                                      //llamar scan_int de alfalib.o
                                    } else if(value_global->basic_type == BOOLEAN){
                                      //llamar scan_boolean
                                    }
                                    //restaurar la pila
                                  }
                                }

                              }
                          ;
escritura:                TOK_PRINTF exp
                              {fprintf(yyout,";R56:\t<escritura> ::= printf <exp>\n");}
                          ;
retorno_funcion:          TOK_RETURN exp
                              {fprintf(yyout,";R61:\t<retorno_funcion> ::= return <exp>\n");}
                          ;
exp:                      exp TOK_MAS exp
                              {
                                fprintf(yyout,";R72:\t<exp> ::= <exp> + <exp>\n");
                                $$.valor = $1.valor + $3.valor;
                              }
                          |   exp TOK_MENOS exp
                              {
                                fprintf(yyout,";R73:\t<exp> ::= <exp> - <exp>\n");
                                $$.valor = $1.valor - $3.valor;
                              }
                          |   exp TOK_DIVISION exp
                              {
                                fprintf(yyout,";R74:\t<exp> ::= <exp> / <exp>\n");
                                $$.valor = $1.valor / $3.valor;
                              }
                          |   exp TOK_ASTERISCO exp
                              {
                                fprintf(yyout,";R75:\t<exp> ::= <exp> * <exp>\n");
                                $$.valor = $1.valor * $3.valor;
                              }
                          |   TOK_MENOS exp %prec NEG
                              {
                                fprintf(yyout,";R76:\t<exp> ::= - <exp>\n");
                                $$.valor = - $1.valor;
                              }
                          |   exp TOK_AND exp
                              {
                                fprintf(yyout,";R77:\t<exp> ::= exp> && <exp>\n");
                                $$.valor = $1.valor && $3.valor;
                              }
                          |   exp TOK_OR exp
                              {
                                fprintf(yyout,";R78:\t<exp> ::= <exp> || <exp>\n");
                                $$.valor = $1.valor || $3.valor;
                              }
                          |   TOK_NOT exp
                              {
                                fprintf(yyout,";R79:\t<exp> ::= ! <exp>\n");
                                $$.valor = ! $1.valor;
                              }
                          |   TOK_IDENTIFICADOR /*TODO: aqui*/
                              {fprintf(yyout,";R80:\t<exp> ::= <identificador>\n");}
                          |   constante
                              {fprintf(yyout,";R81:\t<exp> ::= <constante>\n");}
                          |   TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO
                              {fprintf(yyout,";R82:\t<exp> ::= ( <exp> )\n");}
                          |   TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO
                              {fprintf(yyout,";R83:\t<exp> ::= ( <comparacion> )\n");}
                          |   elemento_vector
                              {fprintf(yyout,";R85:\t<exp> ::= <elemento_vector>\n");}
                          |   TOK_IDENTIFICADOR TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO /*TODO: aqui*/
                              {fprintf(yyout,";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");}
                          ;
lista_expresiones:        exp resto_lista_expresiones
                              {fprintf(yyout,";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");}
                          |   /* vacío */
                              {fprintf(yyout,";R90:\t<lista_expresiones> ::= \n");}
                          ;
resto_lista_expresiones:  TOK_COMA exp resto_lista_expresiones
                              {fprintf(yyout,";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");}
                          |   /* vacío */
                              {fprintf(yyout,";R92:\t<resto_lista_expresiones> ::= \n");}
                          ;
comparacion:              exp TOK_IGUAL exp
                              {fprintf(yyout,";R93:\t<comparacion> ::= <exp> == <exp>\n");}
                          |   exp TOK_DISTINTO exp
                              {fprintf(yyout,";R94:\t<comparacion> ::= <exp> != <exp>\n");}
                          |   exp TOK_MENORIGUAL exp
                              {fprintf(yyout,";R95:\t<comparacion> ::= <exp> <= <exp>\n");}
                          |   exp TOK_MAYORIGUAL exp
                              {fprintf(yyout,";R96:\t<comparacion> ::= <exp> >= <exp>\n");}
                          |   exp TOK_MENOR exp
                              {fprintf(yyout,";R97:\t<comparacion> ::= <exp> < <exp>\n");}
                          |   exp TOK_MAYOR exp
                              {fprintf(yyout,";R98:\t<comparacion> ::= <exp> > <exp>\n");}
                          ;
constante:                constante_logica
                              {fprintf(yyout,";R99:\t<constante> ::= <constante_logica>\n");}
                          |   constante_entera
                              {fprintf(yyout,";R100:\t<constante> ::= <constante_entera>\n");}
                          ;
constante_logica:         TOK_TRUE
                              {fprintf(yyout,";R102:\t<constante_logica> ::= true\n");}
                          |   TOK_FALSE
                              {fprintf(yyout,";R103:\t<constante_logica> ::= false\n");}
                          ;
constante_entera:         TOK_CONSTANTE_ENTERA
                              {
                                fprintf(yyout,";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");
                                $$.valor = $1.valor;
                              }
                          ;
identificador:            TOK_IDENTIFICADOR
                              {
                                fprintf(yyout,";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
                                $$.id = $1.id;
                                pos_variable_local_actual++;
                                if(clase_actual == ESCALAR){
                                    size = 0;
                                } else{
                                    size = tamanio_vector_actual;
                                }
                                if(ambito == LOCAL){
                                    if(clase_actual != ESCALAR){
                                        res = insert($1.id, VARIABLE, tipo_actual, clase_actual, 0, 0, 0, num_variables_locales_actual, pos_variable_local_actual, tabla_local);
                                    } else{
                                        /*TODO: mensaje de error semántico y se termina el proceso de compilación con error.*/
                                        yyerror(NULL);
                                    }
                                } else {
                                    res = insert($1.id, VARIABLE, tipo_actual, clase_actual, size, 0, 0, 0, 0, tabla_global);
                                }
                                if(res == FOUND){
                                    /*TODO: wipear error irse*/
                                }
                              }

%%

void yyerror(const char * s) {
    if(!yy_morph_error) {
        printf("****Error sintactico en [lin %ld, col %ld]\n", yylin, yycol);
        return;
    }
}
