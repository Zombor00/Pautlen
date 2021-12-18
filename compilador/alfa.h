#ifndef _ALFA_H

/*CATEGORY / CLASE*/
#define ESCALAR 1
#define VECTOR 2
/*BASIC TYPE / TIPO*/
#define INT 1
#define BOOLEAN 2

/*ES DIRECCION*/
#define VALOR_EXPLICITO 0
#define VALOR_REFERENCIA 1

/*TAMAÑOS*/
#define MAX_LONG_ID 100
#define MAX_TAMANIO_VECTOR 64

struct _info_atributos {
	char nombre[MAX_LONG_ID + 1];
	int valor_entero;
	int tipo; 					/*INT o BOOLEAN*/
	int es_direccion; 	/*atributo que indica si un símbolo representa una
											 dirección de memoria o es un valor constante.*/
	int etiqueta; 			/*atributo necesario para gestión de sentencias
											 condicionales e iterativas. Es un atributo
											 definido exclusivamente para la generación de código.*/
};
typedef struct _info_atributos info_atributos;

#endif
