#include <stdio.h>
#include <string.h>

int yylex();
int yyparse();
FILE * yyout = NULL;

int main(int argc, char ** argv) {
    extern FILE * yyin;

    if(argc != 3){
      return 1;
    }

    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        return 1;
    }
    out = fopen(argv[2], "w");
    if(out == NULL) {
        fclose(yyin);
        return 1;
    }

    yyparse();

    fclose(yyin);
    fclose(out);
    return 0;
}
