/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "alfa.y"

#include <stdio.h>
#include "alfa.h"
#include "tabla_hash.h"
#include "generacion.h"
#define LOCAL 0
#define GLOBAL 1

extern int yy_morph_error;
extern long yylin;
extern long yycol;

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

#line 121 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOK_MAIN = 258,                /* TOK_MAIN  */
    TOK_INT = 259,                 /* TOK_INT  */
    TOK_BOOLEAN = 260,             /* TOK_BOOLEAN  */
    TOK_ARRAY = 261,               /* TOK_ARRAY  */
    TOK_FUNCTION = 262,            /* TOK_FUNCTION  */
    TOK_IF = 263,                  /* TOK_IF  */
    TOK_ELSE = 264,                /* TOK_ELSE  */
    TOK_WHILE = 265,               /* TOK_WHILE  */
    TOK_SCANF = 266,               /* TOK_SCANF  */
    TOK_PRINTF = 267,              /* TOK_PRINTF  */
    TOK_RETURN = 268,              /* TOK_RETURN  */
    TOK_PUNTOYCOMA = 269,          /* TOK_PUNTOYCOMA  */
    TOK_COMA = 270,                /* TOK_COMA  */
    TOK_PARENTESISIZQUIERDO = 271, /* TOK_PARENTESISIZQUIERDO  */
    TOK_PARENTESISDERECHO = 272,   /* TOK_PARENTESISDERECHO  */
    TOK_CORCHETEIZQUIERDO = 273,   /* TOK_CORCHETEIZQUIERDO  */
    TOK_CORCHETEDERECHO = 274,     /* TOK_CORCHETEDERECHO  */
    TOK_LLAVEIZQUIERDA = 275,      /* TOK_LLAVEIZQUIERDA  */
    TOK_LLAVEDERECHA = 276,        /* TOK_LLAVEDERECHA  */
    TOK_ASIGNACION = 277,          /* TOK_ASIGNACION  */
    TOK_MAS = 278,                 /* TOK_MAS  */
    TOK_MENOS = 279,               /* TOK_MENOS  */
    TOK_DIVISION = 280,            /* TOK_DIVISION  */
    TOK_ASTERISCO = 281,           /* TOK_ASTERISCO  */
    TOK_AND = 282,                 /* TOK_AND  */
    TOK_OR = 283,                  /* TOK_OR  */
    TOK_NOT = 284,                 /* TOK_NOT  */
    TOK_IGUAL = 285,               /* TOK_IGUAL  */
    TOK_DISTINTO = 286,            /* TOK_DISTINTO  */
    TOK_MENORIGUAL = 287,          /* TOK_MENORIGUAL  */
    TOK_MAYORIGUAL = 288,          /* TOK_MAYORIGUAL  */
    TOK_MENOR = 289,               /* TOK_MENOR  */
    TOK_MAYOR = 290,               /* TOK_MAYOR  */
    TOK_CONSTANTE_ENTERA = 291,    /* TOK_CONSTANTE_ENTERA  */
    TOK_TRUE = 292,                /* TOK_TRUE  */
    TOK_FALSE = 293,               /* TOK_FALSE  */
    TOK_IDENTIFICADOR = 294,       /* TOK_IDENTIFICADOR  */
    NEG = 295                      /* NEG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TOK_MAIN 258
#define TOK_INT 259
#define TOK_BOOLEAN 260
#define TOK_ARRAY 261
#define TOK_FUNCTION 262
#define TOK_IF 263
#define TOK_ELSE 264
#define TOK_WHILE 265
#define TOK_SCANF 266
#define TOK_PRINTF 267
#define TOK_RETURN 268
#define TOK_PUNTOYCOMA 269
#define TOK_COMA 270
#define TOK_PARENTESISIZQUIERDO 271
#define TOK_PARENTESISDERECHO 272
#define TOK_CORCHETEIZQUIERDO 273
#define TOK_CORCHETEDERECHO 274
#define TOK_LLAVEIZQUIERDA 275
#define TOK_LLAVEDERECHA 276
#define TOK_ASIGNACION 277
#define TOK_MAS 278
#define TOK_MENOS 279
#define TOK_DIVISION 280
#define TOK_ASTERISCO 281
#define TOK_AND 282
#define TOK_OR 283
#define TOK_NOT 284
#define TOK_IGUAL 285
#define TOK_DISTINTO 286
#define TOK_MENORIGUAL 287
#define TOK_MAYORIGUAL 288
#define TOK_MENOR 289
#define TOK_MAYOR 290
#define TOK_CONSTANTE_ENTERA 291
#define TOK_TRUE 292
#define TOK_FALSE 293
#define TOK_IDENTIFICADOR 294
#define NEG 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 51 "alfa.y"

   info_atributos atributos;

#line 258 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOK_MAIN = 3,                   /* TOK_MAIN  */
  YYSYMBOL_TOK_INT = 4,                    /* TOK_INT  */
  YYSYMBOL_TOK_BOOLEAN = 5,                /* TOK_BOOLEAN  */
  YYSYMBOL_TOK_ARRAY = 6,                  /* TOK_ARRAY  */
  YYSYMBOL_TOK_FUNCTION = 7,               /* TOK_FUNCTION  */
  YYSYMBOL_TOK_IF = 8,                     /* TOK_IF  */
  YYSYMBOL_TOK_ELSE = 9,                   /* TOK_ELSE  */
  YYSYMBOL_TOK_WHILE = 10,                 /* TOK_WHILE  */
  YYSYMBOL_TOK_SCANF = 11,                 /* TOK_SCANF  */
  YYSYMBOL_TOK_PRINTF = 12,                /* TOK_PRINTF  */
  YYSYMBOL_TOK_RETURN = 13,                /* TOK_RETURN  */
  YYSYMBOL_TOK_PUNTOYCOMA = 14,            /* TOK_PUNTOYCOMA  */
  YYSYMBOL_TOK_COMA = 15,                  /* TOK_COMA  */
  YYSYMBOL_TOK_PARENTESISIZQUIERDO = 16,   /* TOK_PARENTESISIZQUIERDO  */
  YYSYMBOL_TOK_PARENTESISDERECHO = 17,     /* TOK_PARENTESISDERECHO  */
  YYSYMBOL_TOK_CORCHETEIZQUIERDO = 18,     /* TOK_CORCHETEIZQUIERDO  */
  YYSYMBOL_TOK_CORCHETEDERECHO = 19,       /* TOK_CORCHETEDERECHO  */
  YYSYMBOL_TOK_LLAVEIZQUIERDA = 20,        /* TOK_LLAVEIZQUIERDA  */
  YYSYMBOL_TOK_LLAVEDERECHA = 21,          /* TOK_LLAVEDERECHA  */
  YYSYMBOL_TOK_ASIGNACION = 22,            /* TOK_ASIGNACION  */
  YYSYMBOL_TOK_MAS = 23,                   /* TOK_MAS  */
  YYSYMBOL_TOK_MENOS = 24,                 /* TOK_MENOS  */
  YYSYMBOL_TOK_DIVISION = 25,              /* TOK_DIVISION  */
  YYSYMBOL_TOK_ASTERISCO = 26,             /* TOK_ASTERISCO  */
  YYSYMBOL_TOK_AND = 27,                   /* TOK_AND  */
  YYSYMBOL_TOK_OR = 28,                    /* TOK_OR  */
  YYSYMBOL_TOK_NOT = 29,                   /* TOK_NOT  */
  YYSYMBOL_TOK_IGUAL = 30,                 /* TOK_IGUAL  */
  YYSYMBOL_TOK_DISTINTO = 31,              /* TOK_DISTINTO  */
  YYSYMBOL_TOK_MENORIGUAL = 32,            /* TOK_MENORIGUAL  */
  YYSYMBOL_TOK_MAYORIGUAL = 33,            /* TOK_MAYORIGUAL  */
  YYSYMBOL_TOK_MENOR = 34,                 /* TOK_MENOR  */
  YYSYMBOL_TOK_MAYOR = 35,                 /* TOK_MAYOR  */
  YYSYMBOL_TOK_CONSTANTE_ENTERA = 36,      /* TOK_CONSTANTE_ENTERA  */
  YYSYMBOL_TOK_TRUE = 37,                  /* TOK_TRUE  */
  YYSYMBOL_TOK_FALSE = 38,                 /* TOK_FALSE  */
  YYSYMBOL_TOK_IDENTIFICADOR = 39,         /* TOK_IDENTIFICADOR  */
  YYSYMBOL_NEG = 40,                       /* NEG  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_programa = 42,                  /* programa  */
  YYSYMBOL_inicioTabla = 43,               /* inicioTabla  */
  YYSYMBOL_escritura_TS = 44,              /* escritura_TS  */
  YYSYMBOL_escritura_main = 45,            /* escritura_main  */
  YYSYMBOL_declaraciones = 46,             /* declaraciones  */
  YYSYMBOL_declaracion = 47,               /* declaracion  */
  YYSYMBOL_clase = 48,                     /* clase  */
  YYSYMBOL_clase_escalar = 49,             /* clase_escalar  */
  YYSYMBOL_tipo = 50,                      /* tipo  */
  YYSYMBOL_clase_vector = 51,              /* clase_vector  */
  YYSYMBOL_identificadores = 52,           /* identificadores  */
  YYSYMBOL_funciones = 53,                 /* funciones  */
  YYSYMBOL_funcion = 54,                   /* funcion  */
  YYSYMBOL_fn_declaration = 55,            /* fn_declaration  */
  YYSYMBOL_fn_name = 56,                   /* fn_name  */
  YYSYMBOL_parametros_funcion = 57,        /* parametros_funcion  */
  YYSYMBOL_resto_parametros_funcion = 58,  /* resto_parametros_funcion  */
  YYSYMBOL_parametro_funcion = 59,         /* parametro_funcion  */
  YYSYMBOL_idpf = 60,                      /* idpf  */
  YYSYMBOL_declaraciones_funcion = 61,     /* declaraciones_funcion  */
  YYSYMBOL_sentencias = 62,                /* sentencias  */
  YYSYMBOL_sentencia = 63,                 /* sentencia  */
  YYSYMBOL_sentencia_simple = 64,          /* sentencia_simple  */
  YYSYMBOL_bloque = 65,                    /* bloque  */
  YYSYMBOL_asignacion = 66,                /* asignacion  */
  YYSYMBOL_elemento_vector = 67,           /* elemento_vector  */
  YYSYMBOL_condicional = 68,               /* condicional  */
  YYSYMBOL_if_exp_sentencias = 69,         /* if_exp_sentencias  */
  YYSYMBOL_if_exp = 70,                    /* if_exp  */
  YYSYMBOL_bucle = 71,                     /* bucle  */
  YYSYMBOL_while_exp = 72,                 /* while_exp  */
  YYSYMBOL_while = 73,                     /* while  */
  YYSYMBOL_lectura = 74,                   /* lectura  */
  YYSYMBOL_escritura = 75,                 /* escritura  */
  YYSYMBOL_retorno_funcion = 76,           /* retorno_funcion  */
  YYSYMBOL_exp = 77,                       /* exp  */
  YYSYMBOL_idf_llamada_funcion = 78,       /* idf_llamada_funcion  */
  YYSYMBOL_lista_expresiones = 79,         /* lista_expresiones  */
  YYSYMBOL_resto_lista_expresiones = 80,   /* resto_lista_expresiones  */
  YYSYMBOL_comparacion = 81,               /* comparacion  */
  YYSYMBOL_constante = 82,                 /* constante  */
  YYSYMBOL_constante_logica = 83,          /* constante_logica  */
  YYSYMBOL_constante_entera = 84,          /* constante_entera  */
  YYSYMBOL_identificador = 85              /* identificador  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   121,   121,   133,   145,   160,   166,   168,   171,   174,
     179,   185,   188,   193,   199,   205,   207,   210,   213,   215,
     234,   250,   286,   289,   291,   294,   296,   299,   316,   319,
     321,   323,   326,   328,   331,   333,   335,   337,   340,   342,
     345,   374,   386,   416,   421,   427,   435,   447,   453,   465,
     473,   509,   515,   536,   549,   562,   575,   588,   601,   615,
     628,   641,   685,   695,   704,   710,   725,   740,   758,   764,
     767,   773,   776,   790,   804,   818,   832,   846,   861,   868,
     876,   883,   891,   899
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOK_MAIN", "TOK_INT",
  "TOK_BOOLEAN", "TOK_ARRAY", "TOK_FUNCTION", "TOK_IF", "TOK_ELSE",
  "TOK_WHILE", "TOK_SCANF", "TOK_PRINTF", "TOK_RETURN", "TOK_PUNTOYCOMA",
  "TOK_COMA", "TOK_PARENTESISIZQUIERDO", "TOK_PARENTESISDERECHO",
  "TOK_CORCHETEIZQUIERDO", "TOK_CORCHETEDERECHO", "TOK_LLAVEIZQUIERDA",
  "TOK_LLAVEDERECHA", "TOK_ASIGNACION", "TOK_MAS", "TOK_MENOS",
  "TOK_DIVISION", "TOK_ASTERISCO", "TOK_AND", "TOK_OR", "TOK_NOT",
  "TOK_IGUAL", "TOK_DISTINTO", "TOK_MENORIGUAL", "TOK_MAYORIGUAL",
  "TOK_MENOR", "TOK_MAYOR", "TOK_CONSTANTE_ENTERA", "TOK_TRUE",
  "TOK_FALSE", "TOK_IDENTIFICADOR", "NEG", "$accept", "programa",
  "inicioTabla", "escritura_TS", "escritura_main", "declaraciones",
  "declaracion", "clase", "clase_escalar", "tipo", "clase_vector",
  "identificadores", "funciones", "funcion", "fn_declaration", "fn_name",
  "parametros_funcion", "resto_parametros_funcion", "parametro_funcion",
  "idpf", "declaraciones_funcion", "sentencias", "sentencia",
  "sentencia_simple", "bloque", "asignacion", "elemento_vector",
  "condicional", "if_exp_sentencias", "if_exp", "bucle", "while_exp",
  "while", "lectura", "escritura", "retorno_funcion", "exp",
  "idf_llamada_funcion", "lista_expresiones", "resto_lista_expresiones",
  "comparacion", "constante", "constante_logica", "constante_entera",
  "identificador", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-48)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-68)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -48,     4,    18,   -48,    -1,    51,   -48,   -48,    11,   -48,
      51,   -32,   -48,   -48,   -48,     7,    23,   -48,   -48,    24,
      55,    36,    11,   -48,    23,    35,    57,   -48,   -32,   -48,
      52,    37,    35,   -48,    62,    72,    50,    61,    61,   -13,
      81,    35,    89,   -48,   -48,    82,   -48,    96,    35,   -48,
      35,    61,   -48,   -48,   -48,    51,   -48,   -48,   -48,    92,
      61,   -48,   -48,    61,    61,    61,   -48,   -48,    -6,   -48,
      26,   105,   -48,   -48,   -48,    26,    61,    61,   -48,   -48,
     -48,    61,   102,   104,   112,   103,    95,   106,   121,   -48,
     115,    84,   119,   -48,   -48,    61,    61,    61,    61,    61,
      61,    61,    68,    26,    26,    35,   128,   -48,   124,   -48,
     -48,   125,    51,   -48,   126,   -48,    61,    61,    61,    61,
      61,    61,   -48,    16,    16,   -48,   -48,    43,    43,     9,
     130,   -48,   127,   -48,    51,   121,   -48,    26,    26,    26,
      26,    26,    26,    61,   -48,   -48,   -48,   -48,   -48,   -48,
       9,   -48
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,    12,    13,     0,     4,
       6,     0,     9,    11,    10,     0,    18,     7,    83,     0,
      15,     0,     0,     5,    18,     0,     0,     8,     0,    82,
       0,     0,     0,    17,     0,     0,     0,     0,     0,     0,
       0,    30,     0,    33,    34,     0,    38,     0,     0,    39,
       0,     0,    35,    36,    37,    23,    16,    14,    21,     0,
       0,    49,    50,     0,     0,     0,    80,    81,    61,    65,
      51,     0,    62,    78,    79,    52,     0,     0,    19,    31,
      32,     0,     0,     0,     0,     0,     0,     0,    25,     2,
       0,     0,     0,    57,    60,     0,     0,     0,     0,     0,
       0,    69,     0,    40,    41,     0,    43,    47,     0,    27,
      26,     0,     0,    22,     0,    63,     0,     0,     0,     0,
       0,     0,    64,    53,    54,    55,    56,    58,    59,    71,
       0,    42,     0,    48,    29,    25,    46,    72,    73,    74,
      75,    76,    77,     0,    68,    66,    44,    28,    20,    24,
      71,    70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -48,   -48,   -48,   -48,   -48,   -10,   -48,   -47,   -48,    -5,
     -48,   122,   129,   -48,   -48,   -48,   -48,    14,    39,   -48,
     -48,   -30,   -48,   -48,   -48,   -48,   -19,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -37,   -48,   -48,     2,
     -48,   -48,   -48,   133,   -48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    16,    32,     9,    10,    11,    12,    13,
      14,    19,    23,    24,    25,    26,    87,   113,    88,   110,
     148,    40,    41,    42,    43,    44,    69,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    70,    71,   130,   144,
      92,    72,    73,    74,    20
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    75,    59,    15,     3,    76,    45,    18,    86,    77,
     -67,    79,    76,    45,    85,     6,     7,    31,    83,     5,
      84,     4,    45,    90,   143,    21,    91,    93,    94,    45,
      22,    45,    95,    96,    97,    98,    99,   100,    27,   102,
     103,    97,    98,    34,   104,    35,    36,    37,    38,    95,
      96,    97,    98,    99,   100,     6,     7,     8,   123,   124,
     125,   126,   127,   128,   129,    86,    95,    96,    97,    98,
      28,    57,    29,    55,    39,   132,    58,    63,    60,   137,
     138,   139,   140,   141,   142,    64,    45,   131,    61,    62,
      65,    95,    96,    97,    98,    99,   100,    29,    66,    67,
      68,   115,    78,    80,    81,    82,   150,    95,    96,    97,
      98,    99,   100,    89,   116,   117,   118,   119,   120,   121,
     108,   101,   105,   111,   147,   106,    95,    96,    97,    98,
      99,   100,   114,   107,   109,   112,   122,   -45,    95,    96,
      97,    98,    99,   100,   133,   134,   136,   145,   146,   149,
      56,   135,   151,    33,    30
};

static const yytype_uint8 yycheck[] =
{
      10,    38,    32,     8,     0,    18,    25,    39,    55,    22,
      16,    41,    18,    32,    51,     4,     5,    22,    48,    20,
      50,     3,    41,    60,    15,    18,    63,    64,    65,    48,
       7,    50,    23,    24,    25,    26,    27,    28,    14,    76,
      77,    25,    26,     8,    81,    10,    11,    12,    13,    23,
      24,    25,    26,    27,    28,     4,     5,     6,    95,    96,
      97,    98,    99,   100,   101,   112,    23,    24,    25,    26,
      15,    19,    36,    16,    39,   105,    39,    16,    16,   116,
     117,   118,   119,   120,   121,    24,   105,    19,    16,    39,
      29,    23,    24,    25,    26,    27,    28,    36,    37,    38,
      39,    17,    21,    14,    22,     9,   143,    23,    24,    25,
      26,    27,    28,    21,    30,    31,    32,    33,    34,    35,
      17,    16,    20,    17,   134,    21,    23,    24,    25,    26,
      27,    28,    17,    21,    39,    14,    17,     9,    23,    24,
      25,    26,    27,    28,    20,    20,    20,    17,    21,   135,
      28,   112,   150,    24,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    43,     0,     3,    20,     4,     5,     6,    46,
      47,    48,    49,    50,    51,    50,    44,    46,    39,    52,
      85,    18,     7,    53,    54,    55,    56,    14,    15,    36,
      84,    50,    45,    53,     8,    10,    11,    12,    13,    39,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    16,    52,    19,    39,    62,
      16,    16,    39,    16,    24,    29,    37,    38,    39,    67,
      77,    78,    82,    83,    84,    77,    18,    22,    21,    62,
      14,    22,     9,    62,    62,    77,    48,    57,    59,    21,
      77,    77,    81,    77,    77,    23,    24,    25,    26,    27,
      28,    16,    77,    77,    77,    20,    21,    21,    17,    39,
      60,    17,    14,    58,    17,    17,    30,    31,    32,    33,
      34,    35,    17,    77,    77,    77,    77,    77,    77,    77,
      79,    19,    62,    20,    20,    59,    20,    77,    77,    77,
      77,    77,    77,    15,    80,    17,    21,    46,    61,    58,
      77,    80
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    44,    45,    46,    46,    47,    48,
      48,    49,    50,    50,    51,    52,    52,    53,    53,    54,
      55,    56,    57,    57,    58,    58,    59,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    64,    64,    65,    65,
      66,    66,    67,    68,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    78,    79,    79,
      80,    80,    81,    81,    81,    81,    81,    81,    82,    82,
      83,    83,    84,    85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     9,     0,     0,     0,     1,     2,     3,     1,
       1,     1,     1,     1,     5,     1,     3,     2,     0,     3,
       6,     3,     2,     0,     3,     0,     2,     1,     1,     0,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     3,     5,     3,     5,     3,     4,     2,
       2,     2,     2,     3,     3,     3,     3,     2,     3,     3,
       2,     1,     1,     3,     3,     1,     4,     1,     2,     0,
       3,     0,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: inicioTabla TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones escritura_TS funciones escritura_main sentencias TOK_LLAVEDERECHA  */
#line 122 "alfa.y"
                              {
                                fprintf(yyout, ";R1:\t<programa> ::= <inicioTabla> main { <declaraciones> <escritura_TS> <funciones> <escritura_main> <sentencias> }\n");

                                escribir_fin(yyout);
                                if(ambito == LOCAL){
                                  wipe(tabla_local);
                                }
                                wipe(tabla_global);
                                return 0;
                              }
#line 1447 "y.tab.c"
    break;

  case 3: /* inicioTabla: %empty  */
#line 133 "alfa.y"
                                        {
                                fprintf(yyout, ";R:\t<inicioTabla>:\n");
                                /*Creamos la tabla global*/
                                tabla_global = create_table();
                                if (tabla_global == NULL)
                                {
                                  printf("Error creando la tabla global!\n");
                                  return -1;
                                }
                              }
#line 1462 "y.tab.c"
    break;

  case 4: /* escritura_TS: %empty  */
#line 145 "alfa.y"
                              {
                                fprintf(yyout, ";R:\t<escritura_TS>:\n");
                                //Aqui tenemos que crear la cabecera del segmento BSS y el de datos
                                escribir_cabecera_bss(yyout);

                                contents = extract_table_contents(tabla_global);
                                for(i = 0; i < tabla_global->n_elems; i++){
                                  declarar_variable(yyout, contents[i]->name, contents[i]->val->basic_type, contents[i]->val->size);
                                }
                                free(contents);

                                escribir_subseccion_data(yyout);
                                escribir_segmento_codigo(yyout);
                              }
#line 1481 "y.tab.c"
    break;

  case 5: /* escritura_main: %empty  */
#line 160 "alfa.y"
                              {
                                fprintf(yyout, ";R:\t<escritura_main>:\n");
                                escribir_inicio_main(yyout);
                              }
#line 1490 "y.tab.c"
    break;

  case 6: /* declaraciones: declaracion  */
#line 167 "alfa.y"
                              {fprintf(yyout,";R2:\t<declaraciones> ::= <declaracion>\n");}
#line 1496 "y.tab.c"
    break;

  case 7: /* declaraciones: declaracion declaraciones  */
#line 169 "alfa.y"
                              {fprintf(yyout,";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
#line 1502 "y.tab.c"
    break;

  case 8: /* declaracion: clase identificadores TOK_PUNTOYCOMA  */
#line 172 "alfa.y"
                              {fprintf(yyout,";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");}
#line 1508 "y.tab.c"
    break;

  case 9: /* clase: clase_escalar  */
#line 175 "alfa.y"
                              {
                                fprintf(yyout,";R5:\t<clase> ::= <clase_escalar>\n");
                                clase_actual = ESCALAR;
                              }
#line 1517 "y.tab.c"
    break;

  case 10: /* clase: clase_vector  */
#line 180 "alfa.y"
                              {
                                fprintf(yyout,";R7:\t<clase> ::= <clase_vector>\n");
                                clase_actual = VECTOR;
                              }
#line 1526 "y.tab.c"
    break;

  case 11: /* clase_escalar: tipo  */
#line 186 "alfa.y"
                              {fprintf(yyout,";R9:\t<clase_escalar> ::= <tipo>\n");}
#line 1532 "y.tab.c"
    break;

  case 12: /* tipo: TOK_INT  */
#line 189 "alfa.y"
                              {
                                fprintf(yyout,";R10:\t<tipo> ::= int\n");
                                tipo_actual = INT;
                              }
#line 1541 "y.tab.c"
    break;

  case 13: /* tipo: TOK_BOOLEAN  */
#line 194 "alfa.y"
                              {
                                fprintf(yyout,";R11:\t<tipo> ::= boolean\n");
                                tipo_actual = BOOLEAN;
                              }
#line 1550 "y.tab.c"
    break;

  case 14: /* clase_vector: TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO constante_entera TOK_CORCHETEDERECHO  */
#line 200 "alfa.y"
                              {
                                fprintf(yyout,";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
                                tamanio_vector_actual = (yyvsp[-1].atributos).valor_entero;
                              }
#line 1559 "y.tab.c"
    break;

  case 15: /* identificadores: identificador  */
#line 206 "alfa.y"
                              {fprintf(yyout,";R18:\t<identificadores> ::= <identificador>\n");}
#line 1565 "y.tab.c"
    break;

  case 16: /* identificadores: identificador TOK_COMA identificadores  */
#line 208 "alfa.y"
                              {fprintf(yyout,";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
#line 1571 "y.tab.c"
    break;

  case 17: /* funciones: funcion funciones  */
#line 211 "alfa.y"
                              {fprintf(yyout,";R20:\t<funciones> ::= <funcion> <funciones>\n");}
#line 1577 "y.tab.c"
    break;

  case 18: /* funciones: %empty  */
#line 213 "alfa.y"
                              {fprintf(yyout,";R21:\t<funciones> ::= \n");}
#line 1583 "y.tab.c"
    break;

  case 19: /* funcion: fn_declaration sentencias TOK_LLAVEDERECHA  */
#line 216 "alfa.y"
                              {
                                fprintf(yyout,";R22:\t<funcion> ::=  <fn_declaration> <sentencias> }\n");
                                /*Hay que comprobar que haya un return y que el tipo del retorno sea = tipo de la variable retornada por la funcion*/
                                if(existe_retorno == FALSE){
                                  error_semantico(FUNC_NO_RETURN, NULL);
                                  return -1;
                                }
                                val = get((yyvsp[-2].atributos).nombre, tabla_global);
                                if(val == NULL){
                                  error_semantico(VARIABLE_NO_DECLARADA, (yyvsp[-2].atributos).nombre);
                                  return -1;
                                }
                                wipe(tabla_local);
                                ambito = GLOBAL;
                                set((yyvsp[-2].atributos).nombre, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE, num_parametros_actual, NO_CHANGE, num_variables_locales_actual, NO_CHANGE, tabla_global);
                                existe_retorno = FALSE;
                              }
#line 1605 "y.tab.c"
    break;

  case 20: /* fn_declaration: fn_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion  */
#line 235 "alfa.y"
                              {
                                fprintf(yyout,";R:\t<fn_declaration> ::= <fn_name> ( <parametros> ) { <declaraciones_funcion>\n");

                                strcpy((yyval.atributos).nombre, (yyvsp[-5].atributos).nombre);
                                res = set((yyvsp[-5].atributos).nombre, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE, num_parametros_actual, NO_CHANGE, num_variables_locales_actual, NO_CHANGE, tabla_global);
                                res = set((yyvsp[-5].atributos).nombre, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE, num_parametros_actual, NO_CHANGE, num_variables_locales_actual, NO_CHANGE, tabla_local);
                                if(res == ERROR){
                                  error_semantico(VARIABLE_NO_DECLARADA, (yyvsp[-5].atributos).nombre);
                                  return -1;
                                }
                                fprintf(yyout, "; declararFuncion:\n");
                                declararFuncion(yyout, (yyvsp[-5].atributos).nombre, num_variables_locales_actual);
                              }
#line 1623 "y.tab.c"
    break;

  case 21: /* fn_name: TOK_FUNCTION tipo TOK_IDENTIFICADOR  */
#line 251 "alfa.y"
                              {
                                fprintf(yyout,";R:\t<fn_name> ::= function <tipo> TOK_IDENTIFICADOR\n");

                                if(ambito == LOCAL){
                                  error_semantico(VAR_LOCAL_NO_ESCALAR, NULL);
                                  return -1;
                                }
                                res = insert((yyvsp[0].atributos).nombre, FUNCION, tipo_actual, clase_actual, 0, 0, 0, 0, 0, tabla_global);
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
                                  res = insert((yyvsp[0].atributos).nombre, FUNCION, tipo_actual, 0, 0, 0, 0, 0, 0, tabla_local);
                                  ambito = LOCAL;
                                  num_variables_locales_actual = 0;
                                  pos_variable_local_actual = 1;
                                  num_parametros_actual = 0;
                                  pos_parametro_actual = 0;
                                  strcpy((yyval.atributos).nombre, (yyvsp[0].atributos).nombre);
                                  strcpy(nombre_funcion_actual, (yyval.atributos).nombre);
                                }
                              }
#line 1662 "y.tab.c"
    break;

  case 22: /* parametros_funcion: parametro_funcion resto_parametros_funcion  */
#line 287 "alfa.y"
                              {fprintf(yyout,";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1668 "y.tab.c"
    break;

  case 23: /* parametros_funcion: %empty  */
#line 289 "alfa.y"
                              {fprintf(yyout,";R24:\t<parametros_funcion> ::= \n");}
#line 1674 "y.tab.c"
    break;

  case 24: /* resto_parametros_funcion: TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion  */
#line 292 "alfa.y"
                              {fprintf(yyout,";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1680 "y.tab.c"
    break;

  case 25: /* resto_parametros_funcion: %empty  */
#line 294 "alfa.y"
                              {fprintf(yyout,";R26:\t<resto_parametros_funcion> ::= \n");}
#line 1686 "y.tab.c"
    break;

  case 26: /* parametro_funcion: clase idpf  */
#line 297 "alfa.y"
                              {fprintf(yyout,";R27:\t<parametro_funcion> ::= <clase> <idpf>\n");}
#line 1692 "y.tab.c"
    break;

  case 27: /* idpf: TOK_IDENTIFICADOR  */
#line 300 "alfa.y"
                            {
                              fprintf(yyout,";R:\t<idpf> ::= TOK_IDENTIFICADOR\n");

                              if(clase_actual == VECTOR){
                                error_semantico(PARAM_ES_FUNC, NULL);
                                return -1;
                              }
                              res = insert((yyvsp[0].atributos).nombre, PARAMETRO, tipo_actual, clase_actual, 1, 0, pos_parametro_actual, 0, 0, tabla_local);
                              if(res == FOUND){
                                  error_semantico(DECLARACION_DUPLICADA, NULL);
                                  return -1;
                              }
                              pos_parametro_actual++;
                              num_parametros_actual++;
                            }
#line 1712 "y.tab.c"
    break;

  case 28: /* declaraciones_funcion: declaraciones  */
#line 317 "alfa.y"
                              {fprintf(yyout,";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
#line 1718 "y.tab.c"
    break;

  case 29: /* declaraciones_funcion: %empty  */
#line 319 "alfa.y"
                              {fprintf(yyout,";R29:\t<declaraciones_funcion> ::= \n");}
#line 1724 "y.tab.c"
    break;

  case 30: /* sentencias: sentencia  */
#line 322 "alfa.y"
                              {fprintf(yyout,";R30:\t<sentencias> ::= <sentencia>\n");}
#line 1730 "y.tab.c"
    break;

  case 31: /* sentencias: sentencia sentencias  */
#line 324 "alfa.y"
                              {fprintf(yyout,";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
#line 1736 "y.tab.c"
    break;

  case 32: /* sentencia: sentencia_simple TOK_PUNTOYCOMA  */
#line 327 "alfa.y"
                              {fprintf(yyout,";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
#line 1742 "y.tab.c"
    break;

  case 33: /* sentencia: bloque  */
#line 329 "alfa.y"
                              {fprintf(yyout,";R33:\t<sentencia> ::= <bloque>\n");}
#line 1748 "y.tab.c"
    break;

  case 34: /* sentencia_simple: asignacion  */
#line 332 "alfa.y"
                              {fprintf(yyout,";R34:\t<sentencia_simple> ::= <asignacion>\n");}
#line 1754 "y.tab.c"
    break;

  case 35: /* sentencia_simple: lectura  */
#line 334 "alfa.y"
                              {fprintf(yyout,";R35:\t<sentencia_simple> ::= <lectura>\n");}
#line 1760 "y.tab.c"
    break;

  case 36: /* sentencia_simple: escritura  */
#line 336 "alfa.y"
                              {fprintf(yyout,";R36:\t<sentencia_simple> ::= <escritura>\n");}
#line 1766 "y.tab.c"
    break;

  case 37: /* sentencia_simple: retorno_funcion  */
#line 338 "alfa.y"
                              {fprintf(yyout,";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
#line 1772 "y.tab.c"
    break;

  case 38: /* bloque: condicional  */
#line 341 "alfa.y"
                              {fprintf(yyout,";R40:\t<bloque> ::= <condicional>\n");}
#line 1778 "y.tab.c"
    break;

  case 39: /* bloque: bucle  */
#line 343 "alfa.y"
                              {fprintf(yyout,";R41:\t<bloque> ::= <bucle>\n");}
#line 1784 "y.tab.c"
    break;

  case 40: /* asignacion: TOK_IDENTIFICADOR TOK_ASIGNACION exp  */
#line 346 "alfa.y"
                              {
                                fprintf(yyout,";R43:\t<asignacion> ::= TOK_IDENTIFICADOR = <exp>\n");
                                val = NULL;
                                if(ambito == LOCAL){
                                  val = get((yyvsp[-2].atributos).nombre, tabla_local);
                                }
                                if(val == NULL){
                                  val = get((yyvsp[-2].atributos).nombre, tabla_global);
                                }

                                if(val){ /*Si encontramos el simbolo en el ambito local / global */
                                  if(val->element_category != FUNCION && val->category == ESCALAR
                                    && val->basic_type == (yyvsp[0].atributos).tipo){
                                      if(ambito == LOCAL){
                                        fprintf(yyout, "; escribirVariableLocal:\n");
                                        escribirVariableLocal(yyout, val->pos_local_variable);
                                        fprintf(yyout, "; asignarDestinoEnPila:\n");
                                        asignarDestinoEnPila(yyout, (yyvsp[0].atributos).es_direccion);
                                      } else {
                                        fprintf(yyout, "; asignar:\n");
                                        asignar(yyout, (yyvsp[-2].atributos).nombre, (yyvsp[0].atributos).es_direccion);
                                      }
                                  } else {
                                    error_semantico(ASIGN_INCOMPATIBLE, NULL);
                                    return -1;
                                  }
                                }
                              }
#line 1817 "y.tab.c"
    break;

  case 41: /* asignacion: elemento_vector TOK_ASIGNACION exp  */
#line 375 "alfa.y"
                              {
                                fprintf(yyout,";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
                                if((yyvsp[-2].atributos).tipo == (yyvsp[0].atributos).tipo){
                                  fprintf(yyout, "; asignarDestinoEnPilaVector:\n");
                                  asignarDestinoEnPilaVector(yyout, (yyvsp[0].atributos).es_direccion);
                                } else {
                                  error_semantico(ASIGN_INCOMPATIBLE, NULL);
                                  return -1;
                                }
                              }
#line 1832 "y.tab.c"
    break;

  case 42: /* elemento_vector: TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO  */
#line 387 "alfa.y"
                              {
                                fprintf(yyout,";R48:\t<elemento_vector> ::= TOK_IDENTIFICADOR [ <exp> ]\n");
                                if(ambito == LOCAL){
                                  val = get((yyvsp[-3].atributos).nombre, tabla_local);
                                } else {
                                  val = get((yyvsp[-3].atributos).nombre, tabla_global);
                                }
                                if(val){
                                  if(val->category == VECTOR){
                                    if((yyvsp[-1].atributos).tipo == INT){
                                      (yyval.atributos).tipo = val->basic_type;
                                      (yyval.atributos).es_direccion = VALOR_REFERENCIA;
                                      fprintf(yyout, "; escribir_elemento_vector:\n");
                                      escribir_elemento_vector(yyout, (yyvsp[-3].atributos).nombre, val->size, (yyvsp[-1].atributos).es_direccion);
                                    }else{
                                      error_semantico(INDEX_INT, NULL);
                                      return -1;
                                    }
                                  }else{
                                    error_semantico(INDEX_NO_VECTOR, NULL);
                                    return -1;
                                  }
                                }else {
                                  error_semantico(VARIABLE_NO_DECLARADA, (yyvsp[-3].atributos).nombre);
                                  return -1;
                                }

                              }
#line 1865 "y.tab.c"
    break;

  case 43: /* condicional: if_exp sentencias TOK_LLAVEDERECHA  */
#line 417 "alfa.y"
                              {
                                fprintf(yyout,";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
                                ifthen_fin(yyout, (yyvsp[-2].atributos).etiqueta);
                              }
#line 1874 "y.tab.c"
    break;

  case 44: /* condicional: if_exp_sentencias TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA  */
#line 422 "alfa.y"
                              {
                                fprintf(yyout,";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
                                ifthenelse_fin(yyout, (yyvsp[-4].atributos).etiqueta);
                              }
#line 1883 "y.tab.c"
    break;

  case 45: /* if_exp_sentencias: if_exp sentencias TOK_LLAVEDERECHA  */
#line 428 "alfa.y"
                              {
                                fprintf(yyout,";R:\t<if_exp_sentencias> ::= <if_exp> <sentencias> }\n");

                                (yyval.atributos).etiqueta = (yyvsp[-2].atributos).etiqueta;
                                ifthenelse_fin_then(yyout, (yyvsp[-2].atributos).etiqueta);
                              }
#line 1894 "y.tab.c"
    break;

  case 46: /* if_exp: TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA  */
#line 436 "alfa.y"
                              {
                                fprintf(yyout,";R:\t<if_exp> ::= if ( <exp> ) {\n");

                                if((yyvsp[-2].atributos).tipo != BOOLEAN){
                                  error_semantico(CONDICIONAL_INT, NULL);
                                }
                                (yyval.atributos).etiqueta = etiqueta;
                                ifthenelse_inicio(yyout, (yyvsp[-2].atributos).es_direccion, (yyval.atributos).etiqueta);
                                etiqueta++;
                              }
#line 1909 "y.tab.c"
    break;

  case 47: /* bucle: while_exp sentencias TOK_LLAVEDERECHA  */
#line 448 "alfa.y"
                              {
                                fprintf(yyout,";R52:\t<bucle> ::= <while_exp> <sentencias> }\n");
                                while_fin(yyout, (yyvsp[-2].atributos).etiqueta);
                              }
#line 1918 "y.tab.c"
    break;

  case 48: /* while_exp: while exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA  */
#line 454 "alfa.y"
                              {
                                fprintf(yyout,";R:\t<while_exp> ::= <while> <exp> ) } \n");

                                if((yyvsp[-2].atributos).tipo != BOOLEAN){
                                  error_semantico(CONDICIONAL_INT, NULL);
                                  return -1;
                                }
                                (yyval.atributos).etiqueta = (yyvsp[-3].atributos).etiqueta;
                                while_exp_pila(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[-3].atributos).etiqueta);
                              }
#line 1933 "y.tab.c"
    break;

  case 49: /* while: TOK_WHILE TOK_PARENTESISIZQUIERDO  */
#line 466 "alfa.y"
                              {
                                fprintf(yyout,";R:\t<while> ::= while (\n");
                                (yyval.atributos).etiqueta = etiqueta;
                                while_inicio(yyout, (yyval.atributos).etiqueta);
                                etiqueta++;
                              }
#line 1944 "y.tab.c"
    break;

  case 50: /* lectura: TOK_SCANF TOK_IDENTIFICADOR  */
#line 474 "alfa.y"
                              {
                                fprintf(yyout,";R54:\t<lectura> ::= scanf TOK_IDENTIFICADOR\n");
                                val_global = get((yyvsp[0].atributos).nombre, tabla_global);
                                val_local = NULL;
                                if(ambito == LOCAL){
                                 val_local = get((yyvsp[0].atributos).nombre, tabla_local);
                                }
                                if(val_global == NULL && val_local == NULL){
                                  error_semantico(VARIABLE_NO_DECLARADA, (yyvsp[0].atributos).nombre);
                                  return -1;
                                } else if(val_local) { //Si la encontramos en la tabla local
                                  if(val_local->element_category == FUNCION || val_local->category == VECTOR){
                                    error_semantico(LECTURA_ERROR, NULL);
                                    return -1;
                                  } else {
                                    if(val_local->basic_type == INT){
                                      leer(yyout, (yyvsp[0].atributos).nombre, INT);
                                    } else if(val_local->basic_type == BOOLEAN){
                                      leer(yyout, (yyvsp[0].atributos).nombre, BOOLEAN);
                                    }
                                  }
                                } else { //si la encontramos en la tabla global
                                  if(val_global->element_category == FUNCION || val_global->element_category == VECTOR){
                                    error_semantico(LECTURA_ERROR, NULL);
                                    return -1;
                                  } else {
                                    if(val_global->basic_type == INT){
                                      leer(yyout, (yyvsp[0].atributos).nombre, INT);
                                    } else if(val_global->basic_type == BOOLEAN){
                                      leer(yyout, (yyvsp[0].atributos).nombre, BOOLEAN);
                                    }
                                  }
                                }
                              }
#line 1983 "y.tab.c"
    break;

  case 51: /* escritura: TOK_PRINTF exp  */
#line 510 "alfa.y"
                              {
                                fprintf(yyout,";R56:\t<escritura> ::= printf <exp>\n");
                                escribir(yyout, (yyvsp[0].atributos).es_direccion, (yyvsp[0].atributos).tipo);
                              }
#line 1992 "y.tab.c"
    break;

  case 52: /* retorno_funcion: TOK_RETURN exp  */
#line 516 "alfa.y"
                              {
                                fprintf(yyout,";R61:\t<retorno_funcion> ::= return <exp>\n");
                                if (ambito != LOCAL){
                                  error_semantico(RETURN_OUT_FUNC, NULL);
                                  return -1;
                                }
                                val = get(nombre_funcion_actual, tabla_local);
                                if(!val){
                                  error_semantico(VARIABLE_NO_DECLARADA, nombre_funcion_actual);
                                  return -1;
                                }
                                if(val->basic_type != (yyvsp[0].atributos).tipo){
                                  error_semantico(RETORNO_DIFERENTE_TIPO, NULL);
                                  return -1;
                                }
                                /*Actualizamos variable de retorno*/
                                existe_retorno = TRUE;
                                retornarFuncion(yyout, (yyvsp[0].atributos).es_direccion);
                              }
#line 2016 "y.tab.c"
    break;

  case 53: /* exp: exp TOK_MAS exp  */
#line 537 "alfa.y"
                              {
                                fprintf(yyout,";R72:\t<exp> ::= <exp> + <exp>\n");
                                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
                                  (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero + (yyvsp[0].atributos).valor_entero;
                                  (yyval.atributos).tipo = INT;
                                  (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                  sumar(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
                                } else {
                                  error_semantico(OPERACION_ARITMETICA_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
#line 2033 "y.tab.c"
    break;

  case 54: /* exp: exp TOK_MENOS exp  */
#line 550 "alfa.y"
                              {
                                fprintf(yyout,";R73:\t<exp> ::= <exp> - <exp>\n");
                                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
                                  (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero - (yyvsp[0].atributos).valor_entero;
                                  (yyval.atributos).tipo = INT;
                                  (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                  restar(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
                                } else {
                                  error_semantico(OPERACION_ARITMETICA_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
#line 2050 "y.tab.c"
    break;

  case 55: /* exp: exp TOK_DIVISION exp  */
#line 563 "alfa.y"
                              {
                                fprintf(yyout,";R74:\t<exp> ::= <exp> / <exp>\n");
                                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
                                  (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero / (yyvsp[0].atributos).valor_entero;
                                  (yyval.atributos).tipo = INT;
                                  (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                  dividir(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
                                } else {
                                  error_semantico(OPERACION_ARITMETICA_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
#line 2067 "y.tab.c"
    break;

  case 56: /* exp: exp TOK_ASTERISCO exp  */
#line 576 "alfa.y"
                              {
                                fprintf(yyout,";R75:\t<exp> ::= <exp> * <exp>\n");
                                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
                                  (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero * (yyvsp[0].atributos).valor_entero;
                                  (yyval.atributos).tipo = INT;
                                  (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                  multiplicar(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
                                } else {
                                  error_semantico(OPERACION_ARITMETICA_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
#line 2084 "y.tab.c"
    break;

  case 57: /* exp: TOK_MENOS exp  */
#line 589 "alfa.y"
                              {
                                fprintf(yyout,";R76:\t<exp> ::= - <exp>\n");
                                if((yyvsp[0].atributos).tipo == INT){
                                  (yyval.atributos).valor_entero = - (yyvsp[0].atributos).valor_entero;
                                  (yyval.atributos).tipo = INT;
                                  (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                  cambiar_signo(yyout, (yyvsp[0].atributos).es_direccion);
                                } else {
                                  error_semantico(OPERACION_ARITMETICA_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
#line 2101 "y.tab.c"
    break;

  case 58: /* exp: exp TOK_AND exp  */
#line 602 "alfa.y"
                              {
                                fprintf(yyout,";R77:\t<exp> ::= <exp> && <exp>\n");
                                if((yyvsp[-2].atributos).tipo == BOOLEAN && (yyvsp[0].atributos).tipo == BOOLEAN){
                                  (yyval.atributos).tipo = BOOLEAN;
                                  (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero && (yyvsp[0].atributos).valor_entero;
                                  (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                  fprintf(yyout, ";mm %d %d\n", (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
                                  y(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
                                } else {
                                  error_semantico(OPERACION_LOGICA_INT, NULL);
                                  return -1;
                                }
                              }
#line 2119 "y.tab.c"
    break;

  case 59: /* exp: exp TOK_OR exp  */
#line 616 "alfa.y"
                              {
                                fprintf(yyout,";R78:\t<exp> ::= <exp> || <exp>\n");
                                if((yyvsp[-2].atributos).tipo == BOOLEAN && (yyvsp[0].atributos).tipo == BOOLEAN){
                                  (yyval.atributos).tipo = BOOLEAN;
                                  (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero || (yyvsp[0].atributos).valor_entero;
                                  (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                  o(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
                                } else {
                                  error_semantico(OPERACION_LOGICA_INT, NULL);
                                  return -1;
                                }
                              }
#line 2136 "y.tab.c"
    break;

  case 60: /* exp: TOK_NOT exp  */
#line 629 "alfa.y"
                              {
                                fprintf(yyout,";R79:\t<exp> ::= ! <exp>\n");
                                if((yyvsp[0].atributos).tipo == BOOLEAN){
                                  (yyval.atributos).tipo = BOOLEAN;
                                  (yyval.atributos).valor_entero = ! (yyvsp[0].atributos).valor_entero;
                                  (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                  no(yyout, (yyvsp[0].atributos).es_direccion, 1);
                                } else {
                                  error_semantico(OPERACION_LOGICA_INT, NULL);
                                  return -1;
                                }
                              }
#line 2153 "y.tab.c"
    break;

  case 61: /* exp: TOK_IDENTIFICADOR  */
#line 642 "alfa.y"
                              {
                                fprintf(yyout,";R80:\t<exp> ::= TOK_IDENTIFICADOR\n");
                                val_local = NULL;
                                if(ambito == LOCAL){
                                  val_local = get((yyvsp[0].atributos).nombre, tabla_local);
                                }

                                val_global = get((yyvsp[0].atributos).nombre, tabla_global);
                                if(val_local == NULL && val_global == NULL){
                                  error_semantico(VARIABLE_NO_DECLARADA, (yyvsp[0].atributos).nombre);
                                  return -1;
                                } else if(val_local) {
                                  if(val_local->element_category == FUNCION || val_local->category == VECTOR){
                                    error_semantico(ASIGN_INCOMPATIBLE, NULL);
                                    return -1;
                                  } else {
                                    (yyval.atributos).tipo = val_local->basic_type;
                                    (yyval.atributos).es_direccion = VALOR_REFERENCIA;
                                    if(val_local->element_category == PARAMETRO){
                                      fprintf(yyout, "; escribirParametro:\n");
                                      escribirParametro(yyout, val_local->pos_param, get(nombre_funcion_actual, tabla_global)->num_params);
                                    }else{
                                      fprintf(yyout, "; escribirVariableLocal:\n");
                                      escribirVariableLocal(yyout, val_local->pos_local_variable);
                                    }
                                  }
                                } else {
                                  if(val_global->element_category == FUNCION || val_global->category == VECTOR){
                                    error_semantico(ASIGN_INCOMPATIBLE, NULL);
                                    return -1;
                                  } else {
                                    (yyval.atributos).tipo = val_global->basic_type;
                                    (yyval.atributos).es_direccion = VALOR_REFERENCIA;
                                    fprintf(yyout, "; escribir_operando:\n");
                                    escribir_operando(yyout, (yyvsp[0].atributos).nombre, VALOR_REFERENCIA);
                                    if(en_explist == TRUE){
                                      fprintf(yyout, "; operandoEnPilaAArgumento:\n");
                                      operandoEnPilaAArgumento(yyout, VALOR_REFERENCIA);
                                    }
                                  }
                                }
                                strcpy((yyval.atributos).nombre, (yyvsp[0].atributos).nombre);
                              }
#line 2201 "y.tab.c"
    break;

  case 62: /* exp: constante  */
#line 686 "alfa.y"
                              {
                                fprintf(yyout,";R81:\t<exp> ::= <constante>\n");
                                (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
                                (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
                                sprintf(str_aux, "%d", (yyvsp[0].atributos).valor_entero);
                                fprintf(yyout, "; escribir_operando:\n");
                                escribir_operando(yyout, str_aux, VALOR_EXPLICITO);
                              }
#line 2215 "y.tab.c"
    break;

  case 63: /* exp: TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO  */
#line 696 "alfa.y"
                              {
                                fprintf(yyout,";R82:\t<exp> ::= ( <exp> )\n");
                                (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;
                                sprintf(str_aux, "%d", (yyvsp[-1].atributos).valor_entero);
                                fprintf(yyout, "; escribir_operando:\n");
                                escribir_operando(yyout, str_aux, VALOR_EXPLICITO);
                              }
#line 2228 "y.tab.c"
    break;

  case 64: /* exp: TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO  */
#line 705 "alfa.y"
                              {
                                fprintf(yyout,";R83:\t<exp> ::= ( <comparacion> )\n");
                                (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;
                              }
#line 2238 "y.tab.c"
    break;

  case 65: /* exp: elemento_vector  */
#line 711 "alfa.y"
                              {
                                fprintf(yyout,";R85:\t<exp> ::= <elemento_vector>\n");
                                (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;

                                if(en_explist == TRUE){
                                  fprintf(yyout, "; escribirParametro:\n");
                                  operandoEnPilaAArgumento(yyout, (yyvsp[0].atributos).es_direccion);
                                  //escribirParametro(yyout, pos_parametro_actual, num_parametros_actual);
                                } else {
                                  fprintf(yyout, "; escribir_operando:\n");
                                  escribir_operando(yyout, (yyvsp[0].atributos).nombre, (yyvsp[0].atributos).es_direccion);
                                }
                              }
#line 2257 "y.tab.c"
    break;

  case 66: /* exp: idf_llamada_funcion TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO  */
#line 726 "alfa.y"
                              {
                                fprintf(yyout,";R88:\t<exp> ::= <idf_llamada_funcion> ( <lista_expresiones> )\n");
                                val = get((yyvsp[-3].atributos).nombre, tabla_global);
                                if(val->num_params == num_parametros_llamada_actual){
                                  llamarFuncion(yyout, (yyvsp[-3].atributos).nombre, num_parametros_llamada_actual);
                                  en_explist = FALSE;
                                  (yyval.atributos).tipo = val->basic_type;
                                  (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                } else {
                                  error_semantico(NUMERO_PARAMS_FUNC, NULL);
                                  return -1;
                                }
                              }
#line 2275 "y.tab.c"
    break;

  case 67: /* idf_llamada_funcion: TOK_IDENTIFICADOR  */
#line 741 "alfa.y"
                              {
                                fprintf(yyout,";R:\t<idf_llamada_funcion> ::= TOK_IDENTIFICADOR\n");

                                val = get((yyvsp[0].atributos).nombre, tabla_global);
                                if(val == NULL){
                                  error_semantico(VARIABLE_NO_DECLARADA, (yyvsp[0].atributos).nombre);
                                } else { //Si encuentra la función
                                  if(val->element_category == FUNCION && en_explist == FALSE){
                                    num_parametros_llamada_actual = 0;
                                    en_explist = TRUE;
                                    strcpy((yyval.atributos).nombre, (yyvsp[0].atributos).nombre);
                                  } else {
                                    error_semantico(LLAMADA_NO_FUNCION, NULL);
                                    return -1;
                                  }
                                }
                              }
#line 2297 "y.tab.c"
    break;

  case 68: /* lista_expresiones: exp resto_lista_expresiones  */
#line 759 "alfa.y"
                              {
                                fprintf(yyout,";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
                                num_parametros_llamada_actual++;
                              }
#line 2306 "y.tab.c"
    break;

  case 69: /* lista_expresiones: %empty  */
#line 764 "alfa.y"
                              {fprintf(yyout,";R90:\t<lista_expresiones> ::= \n");}
#line 2312 "y.tab.c"
    break;

  case 70: /* resto_lista_expresiones: TOK_COMA exp resto_lista_expresiones  */
#line 768 "alfa.y"
                              {
                                fprintf(yyout,";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");
                                num_parametros_llamada_actual++;
                              }
#line 2321 "y.tab.c"
    break;

  case 71: /* resto_lista_expresiones: %empty  */
#line 773 "alfa.y"
                              {fprintf(yyout,";R92:\t<resto_lista_expresiones> ::= \n");}
#line 2327 "y.tab.c"
    break;

  case 72: /* comparacion: exp TOK_IGUAL exp  */
#line 777 "alfa.y"
                              {
                                fprintf(yyout,";R93:\t<comparacion> ::= <exp> == <exp>\n");
                                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
                                  (yyval.atributos).tipo = BOOLEAN;
                                  (yyval.atributos).valor_entero = ((yyvsp[-2].atributos).valor_entero == (yyvsp[0].atributos).valor_entero);
                                  (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                  igual(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
                                  etiqueta++;
                                } else {
                                  error_semantico(COMPARACION_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
#line 2345 "y.tab.c"
    break;

  case 73: /* comparacion: exp TOK_DISTINTO exp  */
#line 791 "alfa.y"
                              {
                                fprintf(yyout,";R94:\t<comparacion> ::= <exp> != <exp>\n");
                                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
                                  (yyval.atributos).tipo = BOOLEAN;
                                  (yyval.atributos).valor_entero = ((yyvsp[-2].atributos).valor_entero != (yyvsp[0].atributos).valor_entero);
                                  (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                  distinto(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
                                  etiqueta++;
                                } else {
                                  error_semantico(COMPARACION_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
#line 2363 "y.tab.c"
    break;

  case 74: /* comparacion: exp TOK_MENORIGUAL exp  */
#line 805 "alfa.y"
                              {
                                fprintf(yyout,";R95:\t<comparacion> ::= <exp> <= <exp>\n");
                                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
                                  (yyval.atributos).tipo = BOOLEAN;
                                  (yyval.atributos).valor_entero = ((yyvsp[-2].atributos).valor_entero <= (yyvsp[0].atributos).valor_entero);
                                  (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                  menor_igual(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
                                  etiqueta++;
                                } else {
                                  error_semantico(COMPARACION_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
#line 2381 "y.tab.c"
    break;

  case 75: /* comparacion: exp TOK_MAYORIGUAL exp  */
#line 819 "alfa.y"
                              {
                                fprintf(yyout,";R96:\t<comparacion> ::= <exp> >= <exp>\n");
                                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
                                  (yyval.atributos).tipo = BOOLEAN;
                                  (yyval.atributos).valor_entero = ((yyvsp[-2].atributos).valor_entero >= (yyvsp[0].atributos).valor_entero);
                                  (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                  mayor_igual(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
                                  etiqueta++;
                                } else {
                                  error_semantico(COMPARACION_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
#line 2399 "y.tab.c"
    break;

  case 76: /* comparacion: exp TOK_MENOR exp  */
#line 833 "alfa.y"
                              {
                                fprintf(yyout,";R97:\t<comparacion> ::= <exp> < <exp>\n");
                                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
                                  (yyval.atributos).tipo = BOOLEAN;
                                  (yyval.atributos).valor_entero = ((yyvsp[-2].atributos).valor_entero < (yyvsp[0].atributos).valor_entero);
                                  (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                  menor(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
                                  etiqueta++;
                                } else {
                                  error_semantico(COMPARACION_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
#line 2417 "y.tab.c"
    break;

  case 77: /* comparacion: exp TOK_MAYOR exp  */
#line 847 "alfa.y"
                              {
                                fprintf(yyout,";R98:\t<comparacion> ::= <exp> > <exp>\n");
                                if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
                                  (yyval.atributos).tipo = BOOLEAN;
                                  (yyval.atributos).valor_entero = ((yyvsp[-2].atributos).valor_entero > (yyvsp[0].atributos).valor_entero);
                                  (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                  mayor(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
                                  etiqueta++;
                                } else {
                                  error_semantico(COMPARACION_BOOLEAN, NULL);
                                  return -1;
                                }
                              }
#line 2435 "y.tab.c"
    break;

  case 78: /* constante: constante_logica  */
#line 862 "alfa.y"
                              {
                                fprintf(yyout,";R99:\t<constante> ::= <constante_logica>\n");
                                (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
                                (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
                              }
#line 2446 "y.tab.c"
    break;

  case 79: /* constante: constante_entera  */
#line 869 "alfa.y"
                              {
                                fprintf(yyout,";R100:\t<constante> ::= <constante_entera>\n");
                                (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
                                (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
                              }
#line 2457 "y.tab.c"
    break;

  case 80: /* constante_logica: TOK_TRUE  */
#line 877 "alfa.y"
                              {
                                fprintf(yyout,";R102:\t<constante_logica> ::= true\n");
                                (yyval.atributos).tipo = BOOLEAN;
                                (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                (yyval.atributos).valor_entero = 1;
                              }
#line 2468 "y.tab.c"
    break;

  case 81: /* constante_logica: TOK_FALSE  */
#line 884 "alfa.y"
                              {
                                fprintf(yyout,";R103:\t<constante_logica> ::= false\n");
                                (yyval.atributos).tipo = BOOLEAN;
                                (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                (yyval.atributos).valor_entero = 0;
                              }
#line 2479 "y.tab.c"
    break;

  case 82: /* constante_entera: TOK_CONSTANTE_ENTERA  */
#line 892 "alfa.y"
                              {
                                fprintf(yyout,";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");
                                (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
                                (yyval.atributos).tipo = INT;
                                (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                              }
#line 2490 "y.tab.c"
    break;

  case 83: /* identificador: TOK_IDENTIFICADOR  */
#line 900 "alfa.y"
                              {
                                fprintf(yyout,";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
                                strcpy((yyval.atributos).nombre, (yyvsp[0].atributos).nombre);
                                if(clase_actual == ESCALAR){
                                    size = 1;
                                } else{ //clase_actual == VECTOR
                                    size = tamanio_vector_actual;
                                    if ((size < 1) || (size > MAX_TAMANIO_VECTOR)){
                                      error_semantico(MAX_TAM_VECTOR, (yyvsp[0].atributos).nombre);
                                      return -1;
                                    }
                                }
                                if(ambito == LOCAL){
                                    if(clase_actual == ESCALAR){
                                        num_variables_locales_actual++;
                                        res = insert((yyvsp[0].atributos).nombre, VARIABLE, tipo_actual, clase_actual, 1, 0, 0, num_variables_locales_actual, pos_variable_local_actual, tabla_local);
                                        pos_variable_local_actual++;
                                    } else{ //if clase_actual == VECTOR
                                        error_semantico(VAR_LOCAL_NO_ESCALAR, NULL);
                                        return -1;
                                    }
                                } else {
                                    res = insert((yyvsp[0].atributos).nombre, VARIABLE, tipo_actual, clase_actual, size, 0, 0, 0, 0, tabla_global);
                                }
                                if(res == FOUND){
                                    error_semantico(DECLARACION_DUPLICADA, NULL);
                                    return -1;
                                }
                              }
#line 2524 "y.tab.c"
    break;


#line 2528 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 930 "alfa.y"


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
