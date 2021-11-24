#include <stdio.h>
#include <string.h>

int yylex();
int yyparse();

int main(int argc, char** argv) {
    extern FILE* yyout;
    extern FILE* yyin;

    /* Comprobamos que se pasan los argumentos correctamente */
    if (argc != 3){
        printf("Debe indicarse file de entrada y de salida\n");
        return 1;
    }

    /* Leemos el fichero de entrada */
    yyin = fopen(argv[1], "r");
    if(yyin == NULL){
        return 1;
    }

    /* Creamos el fichera de salida */
    yyout = fopen(argv[2], "w");
    if(yyout == NULL){
        fclose(yyin);
        return 1;
    }

    /* Llamamos al parser */
    yyparse();

    fclose(yyin);
    fclose(yyout);
    return 0;
}
