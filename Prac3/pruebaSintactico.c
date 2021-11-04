#include <stdio.h>
#include <string.h>

int yylex();
int yyparse();

FILE * yyin;

int main(int argc, char ** argv) {
    extern FILE * yyout = NULL;
    extern FILE * yyin = NULL;

    if (argc != 3)
    {
        printf("Debe indicar file de entrada y de salida\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        return 1;
    }
    yyout = fopen(argv[2], "w");
    if(out == NULL) {
        fclose(yyin);
        return 1;
    }

    yyparse();

    fclose(yyin);
    fclose(yyout);
    return 0;
}
