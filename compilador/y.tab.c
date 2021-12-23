/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

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

#line 120 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_MAIN = 258,
    TOK_INT = 259,
    TOK_BOOLEAN = 260,
    TOK_ARRAY = 261,
    TOK_FUNCTION = 262,
    TOK_IF = 263,
    TOK_ELSE = 264,
    TOK_WHILE = 265,
    TOK_SCANF = 266,
    TOK_PRINTF = 267,
    TOK_RETURN = 268,
    TOK_PUNTOYCOMA = 269,
    TOK_COMA = 270,
    TOK_PARENTESISIZQUIERDO = 271,
    TOK_PARENTESISDERECHO = 272,
    TOK_CORCHETEIZQUIERDO = 273,
    TOK_CORCHETEDERECHO = 274,
    TOK_LLAVEIZQUIERDA = 275,
    TOK_LLAVEDERECHA = 276,
    TOK_ASIGNACION = 277,
    TOK_MAS = 278,
    TOK_MENOS = 279,
    TOK_DIVISION = 280,
    TOK_ASTERISCO = 281,
    TOK_AND = 282,
    TOK_OR = 283,
    TOK_NOT = 284,
    TOK_IGUAL = 285,
    TOK_DISTINTO = 286,
    TOK_MENORIGUAL = 287,
    TOK_MAYORIGUAL = 288,
    TOK_MENOR = 289,
    TOK_MAYOR = 290,
    TOK_CONSTANTE_ENTERA = 291,
    TOK_TRUE = 292,
    TOK_FALSE = 293,
    TOK_IDENTIFICADOR = 294,
    NEG = 295
  };
#endif
/* Tokens.  */
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

#line 256 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYLAST   155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
       0,   121,   121,   129,   141,   154,   160,   162,   165,   168,
     173,   179,   182,   187,   193,   199,   201,   204,   207,   209,
     230,   245,   281,   284,   286,   289,   291,   294,   311,   314,
     316,   318,   321,   323,   326,   328,   330,   332,   335,   337,
     340,   367,   378,   407,   412,   418,   426,   438,   444,   456,
     464,   500,   506,   534,   547,   560,   573,   586,   599,   612,
     625,   638,   678,   687,   695,   701,   712,   727,   745,   751,
     754,   760,   763,   777,   791,   805,   819,   833,   848,   854,
     861,   868,   876,   884
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_MAIN", "TOK_INT", "TOK_BOOLEAN",
  "TOK_ARRAY", "TOK_FUNCTION", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_SCANF", "TOK_PRINTF", "TOK_RETURN", "TOK_PUNTOYCOMA", "TOK_COMA",
  "TOK_PARENTESISIZQUIERDO", "TOK_PARENTESISDERECHO",
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
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-68)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -38,     4,    12,   -38,    10,    62,   -38,   -38,    30,   -38,
      62,   -15,   -38,   -38,   -38,    14,    42,   -38,   -38,    23,
      61,    21,    30,   -38,    42,    -3,    81,   -38,   -15,   -38,
      58,    39,    -3,   -38,    89,    92,    70,     9,     9,    -6,
      95,    -3,   103,   -38,   -38,    96,   -38,   111,    -3,   -38,
      -3,     9,   -38,   -38,   -38,    30,   -38,   -38,   -38,   100,
       9,   -38,   -38,     9,     9,     9,   -38,   -38,     3,   -38,
     108,   106,   -38,   -38,   -38,   108,     9,     9,   -38,   -38,
     -38,     9,   117,   118,   119,    87,    84,   121,   127,   -38,
     102,    68,   125,   -38,   -38,     9,     9,     9,     9,     9,
       9,     9,    46,   108,   108,    -3,   134,   -38,   124,   -38,
     -38,   126,    30,   -38,   128,   -38,     9,     9,     9,     9,
       9,     9,   -38,    16,    16,   -38,   -38,    64,    64,    28,
     130,   -38,   129,   -38,    62,   127,   -38,   108,   108,   108,
     108,   108,   108,     9,   -38,   -38,   -38,   -38,   -38,   -38,
      28,   -38
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
     -38,   -38,   -38,   -38,   -38,   -10,   -38,   -38,   -38,    -5,
     -38,   123,   131,   -38,   -38,   -38,   -38,    17,    33,   -38,
     -38,   -30,   -38,   -38,   -38,   -38,   -19,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -37,   -38,   -38,    -1,
     -38,   -38,   -38,   132,   -38
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    16,    32,     9,    10,    11,    12,    13,
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
      17,    75,    59,    15,     3,    34,    45,    35,    36,    37,
      38,    79,    76,    45,    85,     4,    77,    31,    83,   -67,
      84,    76,    45,    90,    18,    63,    91,    93,    94,    45,
       5,    45,    21,    64,     6,     7,    39,    27,    65,   102,
     103,    97,    98,   143,   104,    29,    66,    67,    68,    22,
      86,    95,    96,    97,    98,    99,   100,    29,   123,   124,
     125,   126,   127,   128,   129,   131,     6,     7,     8,    95,
      96,    97,    98,    99,   100,   132,    28,    57,    58,   137,
     138,   139,   140,   141,   142,   115,    45,    95,    96,    97,
      98,    95,    96,    97,    98,    99,   100,    55,   116,   117,
     118,   119,   120,   121,   108,    60,   150,    86,    61,    62,
      95,    96,    97,    98,    99,   100,    78,    80,    81,   114,
      82,    89,   101,   109,   147,    95,    96,    97,    98,    99,
     100,    95,    96,    97,    98,    99,   100,   105,   111,   106,
     107,   112,   122,   -45,   133,   135,   134,   145,   136,   151,
     146,    56,   149,    30,     0,    33
};

static const yytype_int16 yycheck[] =
{
      10,    38,    32,     8,     0,     8,    25,    10,    11,    12,
      13,    41,    18,    32,    51,     3,    22,    22,    48,    16,
      50,    18,    41,    60,    39,    16,    63,    64,    65,    48,
      20,    50,    18,    24,     4,     5,    39,    14,    29,    76,
      77,    25,    26,    15,    81,    36,    37,    38,    39,     7,
      55,    23,    24,    25,    26,    27,    28,    36,    95,    96,
      97,    98,    99,   100,   101,    19,     4,     5,     6,    23,
      24,    25,    26,    27,    28,   105,    15,    19,    39,   116,
     117,   118,   119,   120,   121,    17,   105,    23,    24,    25,
      26,    23,    24,    25,    26,    27,    28,    16,    30,    31,
      32,    33,    34,    35,    17,    16,   143,   112,    16,    39,
      23,    24,    25,    26,    27,    28,    21,    14,    22,    17,
       9,    21,    16,    39,   134,    23,    24,    25,    26,    27,
      28,    23,    24,    25,    26,    27,    28,    20,    17,    21,
      21,    14,    17,     9,    20,   112,    20,    17,    20,   150,
      21,    28,   135,    21,    -1,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
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
      14,    22,     9,    62,    62,    77,    50,    57,    59,    21,
      77,    77,    81,    77,    77,    23,    24,    25,    26,    27,
      28,    16,    77,    77,    77,    20,    21,    21,    17,    39,
      60,    17,    14,    58,    17,    17,    30,    31,    32,    33,
      34,    35,    17,    77,    77,    77,    77,    77,    77,    77,
      79,    19,    62,    20,    20,    59,    20,    77,    77,    77,
      77,    77,    77,    15,    80,    17,    21,    46,    61,    58,
      77,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 122 "alfa.y"
                              {
                                fprintf(yyout, ";R1:\t<programa> ::= <inicioTabla> main { <declaraciones> <escritura_TS> <funciones> <escritura_main> <sentencias> }\n");

                                escribir_fin(yyout);
                                wipe(tabla_global);
                              }
#line 1557 "y.tab.c"
    break;

  case 3:
#line 129 "alfa.y"
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
#line 1572 "y.tab.c"
    break;

  case 4:
#line 141 "alfa.y"
                              {
                                fprintf(yyout, ";R:\t<escritura_TS>:\n");
                                //Aqui tenemos que crear la cabecera del segmento BSS y el de datos
                                escribir_cabecera_bss(yyout);

                                contents = extract_table_contents(tabla_global);
                                for(i = 0; i < tabla_global->n_elems; i++){
                                  declarar_variable(yyout, contents[i]->name, contents[i]->val->basic_type, contents[i]->val->size);
                                }
                                escribir_subseccion_data(yyout);
                                escribir_segmento_codigo(yyout);
                              }
#line 1589 "y.tab.c"
    break;

  case 5:
#line 154 "alfa.y"
                              {
                                fprintf(yyout, ";R:\t<escritura_main>:\n");
                                escribir_inicio_main(yyout);
                              }
#line 1598 "y.tab.c"
    break;

  case 6:
#line 161 "alfa.y"
                              {fprintf(yyout,";R2:\t<declaraciones> ::= <declaracion>\n");}
#line 1604 "y.tab.c"
    break;

  case 7:
#line 163 "alfa.y"
                              {fprintf(yyout,";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
#line 1610 "y.tab.c"
    break;

  case 8:
#line 166 "alfa.y"
                              {fprintf(yyout,";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");}
#line 1616 "y.tab.c"
    break;

  case 9:
#line 169 "alfa.y"
                              {
                                fprintf(yyout,";R5:\t<clase> ::= <clase_escalar>\n");
                                clase_actual = ESCALAR;
                              }
#line 1625 "y.tab.c"
    break;

  case 10:
#line 174 "alfa.y"
                              {
                                fprintf(yyout,";R7:\t<clase> ::= <clase_vector>\n");
                                clase_actual = VECTOR;
                              }
#line 1634 "y.tab.c"
    break;

  case 11:
#line 180 "alfa.y"
                              {fprintf(yyout,";R9:\t<clase_escalar> ::= <tipo>\n");}
#line 1640 "y.tab.c"
    break;

  case 12:
#line 183 "alfa.y"
                              {
                                fprintf(yyout,";R10:\t<tipo> ::= int\n");
                                tipo_actual = INT;
                              }
#line 1649 "y.tab.c"
    break;

  case 13:
#line 188 "alfa.y"
                              {
                                {fprintf(yyout,";R11:\t<tipo> ::= boolean\n");}
                                tipo_actual = BOOLEAN;
                              }
#line 1658 "y.tab.c"
    break;

  case 14:
#line 194 "alfa.y"
                              {
                                fprintf(yyout,";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
                                tamanio_vector_actual = (yyvsp[-1].atributos).valor_entero;
                              }
#line 1667 "y.tab.c"
    break;

  case 15:
#line 200 "alfa.y"
                              {fprintf(yyout,";R18:\t<identificadores> ::= <identificador>\n");}
#line 1673 "y.tab.c"
    break;

  case 16:
#line 202 "alfa.y"
                              {fprintf(yyout,";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
#line 1679 "y.tab.c"
    break;

  case 17:
#line 205 "alfa.y"
                              {fprintf(yyout,";R20:\t<funciones> ::= <funcion> <funciones>\n");}
#line 1685 "y.tab.c"
    break;

  case 18:
#line 207 "alfa.y"
                              {fprintf(yyout,";R21:\t<funciones> ::= \n");}
#line 1691 "y.tab.c"
    break;

  case 19:
#line 210 "alfa.y"
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
                                //TODO:falta comprobar el tipo del return

                                wipe(tabla_local);
                                ambito = GLOBAL;
                                set((yyvsp[-2].atributos).nombre, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE, num_parametros_actual, NO_CHANGE, num_variables_locales_actual, NO_CHANGE, tabla_global);
                                existe_retorno = FALSE;
                              }
#line 1715 "y.tab.c"
    break;

  case 20:
#line 231 "alfa.y"
                              {
                                fprintf(yyout,";R:\t<fn_declaration> ::= <fn_name> ( <parametros> ) { <declaraciones_funcion>\n");

                                strcpy((yyval.atributos).nombre, (yyvsp[-5].atributos).nombre);
                                res = set((yyvsp[-5].atributos).nombre, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE, num_parametros_actual, NO_CHANGE, num_variables_locales_actual, NO_CHANGE, tabla_global);
                                res = set((yyvsp[-5].atributos).nombre, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE, num_parametros_actual, NO_CHANGE, num_variables_locales_actual, NO_CHANGE, tabla_local);
                                if(res == ERROR){
                                  error_semantico(VARIABLE_NO_DECLARADA, (yyvsp[-5].atributos).nombre);
                                  return -1;
                                }
                                declararFuncion(yyout, (yyvsp[-5].atributos).nombre, num_variables_locales_actual);
                              }
#line 1732 "y.tab.c"
    break;

  case 21:
#line 246 "alfa.y"
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
#line 1771 "y.tab.c"
    break;

  case 22:
#line 282 "alfa.y"
                              {fprintf(yyout,";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1777 "y.tab.c"
    break;

  case 23:
#line 284 "alfa.y"
                              {fprintf(yyout,";R24:\t<parametros_funcion> ::= \n");}
#line 1783 "y.tab.c"
    break;

  case 24:
#line 287 "alfa.y"
                              {fprintf(yyout,";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1789 "y.tab.c"
    break;

  case 25:
#line 289 "alfa.y"
                              {fprintf(yyout,";R26:\t<resto_parametros_funcion> ::= \n");}
#line 1795 "y.tab.c"
    break;

  case 26:
#line 292 "alfa.y"
                              {fprintf(yyout,";R27:\t<parametro_funcion> ::= <tipo> <idpf>\n");}
#line 1801 "y.tab.c"
    break;

  case 27:
#line 295 "alfa.y"
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
#line 1821 "y.tab.c"
    break;

  case 28:
#line 312 "alfa.y"
                              {fprintf(yyout,";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
#line 1827 "y.tab.c"
    break;

  case 29:
#line 314 "alfa.y"
                              {fprintf(yyout,";R29:\t<declaraciones_funcion> ::= \n");}
#line 1833 "y.tab.c"
    break;

  case 30:
#line 317 "alfa.y"
                              {fprintf(yyout,";R30:\t<sentencias> ::= <sentencia>\n");}
#line 1839 "y.tab.c"
    break;

  case 31:
#line 319 "alfa.y"
                              {fprintf(yyout,";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
#line 1845 "y.tab.c"
    break;

  case 32:
#line 322 "alfa.y"
                              {fprintf(yyout,";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
#line 1851 "y.tab.c"
    break;

  case 33:
#line 324 "alfa.y"
                              {fprintf(yyout,";R33:\t<sentencia> ::= <bloque>\n");}
#line 1857 "y.tab.c"
    break;

  case 34:
#line 327 "alfa.y"
                              {fprintf(yyout,";R34:\t<sentencia_simple> ::= <asignacion>\n");}
#line 1863 "y.tab.c"
    break;

  case 35:
#line 329 "alfa.y"
                              {fprintf(yyout,";R35:\t<sentencia_simple> ::= <lectura>\n");}
#line 1869 "y.tab.c"
    break;

  case 36:
#line 331 "alfa.y"
                              {fprintf(yyout,";R36:\t<sentencia_simple> ::= <escritura>\n");}
#line 1875 "y.tab.c"
    break;

  case 37:
#line 333 "alfa.y"
                              {fprintf(yyout,";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
#line 1881 "y.tab.c"
    break;

  case 38:
#line 336 "alfa.y"
                              {fprintf(yyout,";R40:\t<bloque> ::= <condicional>\n");}
#line 1887 "y.tab.c"
    break;

  case 39:
#line 338 "alfa.y"
                              {fprintf(yyout,";R41:\t<bloque> ::= <bucle>\n");}
#line 1893 "y.tab.c"
    break;

  case 40:
#line 341 "alfa.y"
                              {
                                /*TODO: cambiar para que llame a escribirParametro, escribirVariableLocal, asignarDestinoEnPila*/
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
                                        escribirVariableLocal(yyout, val->pos_local_variable);
                                        asignarDestinoEnPila(yyout, (yyvsp[0].atributos).es_direccion);
                                      } else {
                                        asignar(yyout, (yyvsp[-2].atributos).nombre, (yyvsp[0].atributos).es_direccion);
                                      }
                                  } else {
                                    error_semantico(ASIGN_INCOMPATIBLE, NULL);
                                    return -1;
                                  }
                                }
                              }
#line 1924 "y.tab.c"
    break;

  case 41:
#line 368 "alfa.y"
                              {
                                fprintf(yyout,";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
                                if((yyvsp[-2].atributos).tipo == (yyvsp[0].atributos).tipo){
                                  asignarDestinoEnPila(yyout, (yyvsp[0].atributos).es_direccion);
                                } else {
                                  error_semantico(ASIGN_INCOMPATIBLE, NULL);
                                  return -1;
                                }
                              }
#line 1938 "y.tab.c"
    break;

  case 42:
#line 379 "alfa.y"
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
#line 1970 "y.tab.c"
    break;

  case 43:
#line 408 "alfa.y"
                              {
                                fprintf(yyout,";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
                                ifthen_fin(yyout, (yyvsp[-2].atributos).etiqueta);
                              }
#line 1979 "y.tab.c"
    break;

  case 44:
#line 413 "alfa.y"
                              {
                                fprintf(yyout,";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
                                ifthenelse_fin(yyout, (yyvsp[-4].atributos).etiqueta);
                              }
#line 1988 "y.tab.c"
    break;

  case 45:
#line 419 "alfa.y"
                              {
                                fprintf(yyout,";R:\t<if_exp_sentencias> ::= <if_exp> <sentencias> }\n");

                                (yyval.atributos).etiqueta = (yyvsp[-2].atributos).etiqueta;
                                ifthenelse_fin_then(yyout, (yyvsp[-2].atributos).etiqueta);
                              }
#line 1999 "y.tab.c"
    break;

  case 46:
#line 427 "alfa.y"
                              {
                                fprintf(yyout,";R:\t<if_exp> ::= if ( <exp> ) {\n");

                                if((yyvsp[-2].atributos).tipo != BOOLEAN){
                                  error_semantico(CONDICIONAL_INT, NULL);
                                }
                                (yyval.atributos).etiqueta = etiqueta;
                                ifthenelse_inicio(yyout, (yyvsp[-2].atributos).es_direccion, (yyval.atributos).etiqueta);
                                etiqueta++;
                              }
#line 2014 "y.tab.c"
    break;

  case 47:
#line 439 "alfa.y"
                              {
                                fprintf(yyout,";R52:\t<bucle> ::= <while_exp> <sentencias> }\n");
                                while_fin(yyout, (yyvsp[-2].atributos).etiqueta);
                              }
#line 2023 "y.tab.c"
    break;

  case 48:
#line 445 "alfa.y"
                              {
                                fprintf(yyout,";R:\t<while_exp> ::= <while> <exp> ) } \n");

                                if((yyvsp[-2].atributos).tipo != BOOLEAN){
                                  error_semantico(CONDICIONAL_INT, NULL);
                                  return -1;
                                }
                                (yyval.atributos).etiqueta = (yyvsp[-3].atributos).etiqueta;
                                while_exp_pila(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[-3].atributos).etiqueta);
                              }
#line 2038 "y.tab.c"
    break;

  case 49:
#line 457 "alfa.y"
                              {
                                fprintf(yyout,";R:\t<while> ::= while (\n");
                                (yyval.atributos).etiqueta = etiqueta;
                                while_inicio(yyout, (yyval.atributos).etiqueta);
                                etiqueta++;
                              }
#line 2049 "y.tab.c"
    break;

  case 50:
#line 465 "alfa.y"
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
#line 2088 "y.tab.c"
    break;

  case 51:
#line 501 "alfa.y"
                              {
                                fprintf(yyout,";R56:\t<escritura> ::= printf <exp>\n");
                                escribir(yyout, (yyvsp[0].atributos).es_direccion, (yyvsp[0].atributos).tipo);
                              }
#line 2097 "y.tab.c"
    break;

  case 52:
#line 507 "alfa.y"
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
                                /*TODO:THIS NO SENSE: Las direcciones de
                                    exp siempre tienen
                                    que ser 0 ó 1.,?? 
                                if($2.valor_entero != 0 && $2.valor_entero != 1){
                                  fprintf(stderr, "Error valor ilegal! en valor_entero");
                                  return -1;
                                }*/
                                if(val->basic_type != (yyvsp[0].atributos).tipo){
                                  error_semantico(RETORNO_DIFERENTE_TIPO, NULL);
                                  return -1;
                                }
                                /*Actualizamos variable de retorno*/
                                existe_retorno = TRUE;
                                retornarFuncion(yyout, (yyvsp[0].atributos).es_direccion);
                              }
#line 2128 "y.tab.c"
    break;

  case 53:
#line 535 "alfa.y"
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
#line 2145 "y.tab.c"
    break;

  case 54:
#line 548 "alfa.y"
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
#line 2162 "y.tab.c"
    break;

  case 55:
#line 561 "alfa.y"
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
#line 2179 "y.tab.c"
    break;

  case 56:
#line 574 "alfa.y"
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
#line 2196 "y.tab.c"
    break;

  case 57:
#line 587 "alfa.y"
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
#line 2213 "y.tab.c"
    break;

  case 58:
#line 600 "alfa.y"
                              {
                                fprintf(yyout,";R77:\t<exp> ::= exp> && <exp>\n");
                                if((yyvsp[-2].atributos).tipo == BOOLEAN && (yyvsp[0].atributos).tipo == BOOLEAN){
                                  (yyval.atributos).tipo = BOOLEAN;
                                  (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero && (yyvsp[0].atributos).valor_entero;
                                  (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                  y(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
                                } else {
                                  error_semantico(OPERACION_LOGICA_INT, NULL);
                                  return -1;
                                }
                              }
#line 2230 "y.tab.c"
    break;

  case 59:
#line 613 "alfa.y"
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
#line 2247 "y.tab.c"
    break;

  case 60:
#line 626 "alfa.y"
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
#line 2264 "y.tab.c"
    break;

  case 61:
#line 639 "alfa.y"
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
                                      escribirParametro(yyout, val_local->pos_param, get(nombre_funcion_actual, tabla_global)->num_params);
                                    }else{
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
                                    escribir_operando(yyout, (yyvsp[0].atributos).nombre, VALOR_REFERENCIA);
                                    if(en_explist == TRUE){
                                      operandoEnPilaAArgumento(yyout, VALOR_REFERENCIA);
                                    }
                                  }
                                }
                                strcpy((yyval.atributos).nombre, (yyvsp[0].atributos).nombre);
                              }
#line 2308 "y.tab.c"
    break;

  case 62:
#line 679 "alfa.y"
                              {
                                fprintf(yyout,";R81:\t<exp> ::= <constante>\n");
                                (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
                                (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
                                sprintf(str_aux, "%d", (yyvsp[0].atributos).valor_entero);
                                escribir_operando(yyout, str_aux, VALOR_EXPLICITO);
                              }
#line 2321 "y.tab.c"
    break;

  case 63:
#line 688 "alfa.y"
                              {
                                fprintf(yyout,";R82:\t<exp> ::= ( <exp> )\n");
                                (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;
                                sprintf(str_aux, "%d", (yyvsp[-1].atributos).valor_entero);
                                escribir_operando(yyout, str_aux, VALOR_EXPLICITO);
                              }
#line 2333 "y.tab.c"
    break;

  case 64:
#line 696 "alfa.y"
                              {
                                fprintf(yyout,";R83:\t<exp> ::= ( <comparacion> )\n");
                                (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;
                              }
#line 2343 "y.tab.c"
    break;

  case 65:
#line 702 "alfa.y"
                              {
                                fprintf(yyout,";R85:\t<exp> ::= <elemento_vector>\n");
                                (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
                                if(en_explist == TRUE){
                                  escribirParametro(yyout, pos_parametro_actual, num_parametros_actual);
                                } else {
                                  escribir_operando(yyout, (yyvsp[0].atributos).nombre, (yyvsp[0].atributos).es_direccion);
                                }
                              }
#line 2358 "y.tab.c"
    break;

  case 66:
#line 713 "alfa.y"
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
#line 2376 "y.tab.c"
    break;

  case 67:
#line 728 "alfa.y"
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
#line 2398 "y.tab.c"
    break;

  case 68:
#line 746 "alfa.y"
                              {
                                fprintf(yyout,";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
                                num_parametros_llamada_actual++;
                              }
#line 2407 "y.tab.c"
    break;

  case 69:
#line 751 "alfa.y"
                              {fprintf(yyout,";R90:\t<lista_expresiones> ::= \n");}
#line 2413 "y.tab.c"
    break;

  case 70:
#line 755 "alfa.y"
                              {
                                fprintf(yyout,";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");
                                num_parametros_llamada_actual++;
                              }
#line 2422 "y.tab.c"
    break;

  case 71:
#line 760 "alfa.y"
                              {fprintf(yyout,";R92:\t<resto_lista_expresiones> ::= \n");}
#line 2428 "y.tab.c"
    break;

  case 72:
#line 764 "alfa.y"
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
#line 2446 "y.tab.c"
    break;

  case 73:
#line 778 "alfa.y"
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
#line 2464 "y.tab.c"
    break;

  case 74:
#line 792 "alfa.y"
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
#line 2482 "y.tab.c"
    break;

  case 75:
#line 806 "alfa.y"
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
#line 2500 "y.tab.c"
    break;

  case 76:
#line 820 "alfa.y"
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
#line 2518 "y.tab.c"
    break;

  case 77:
#line 834 "alfa.y"
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
#line 2536 "y.tab.c"
    break;

  case 78:
#line 849 "alfa.y"
                              {
                                fprintf(yyout,";R99:\t<constante> ::= <constante_logica>\n");
                                (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
                              }
#line 2546 "y.tab.c"
    break;

  case 79:
#line 855 "alfa.y"
                              {
                                fprintf(yyout,";R100:\t<constante> ::= <constante_entera>\n");
                                (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
                              }
#line 2556 "y.tab.c"
    break;

  case 80:
#line 862 "alfa.y"
                              {
                                fprintf(yyout,";R102:\t<constante_logica> ::= true\n");
                                (yyval.atributos).tipo = BOOLEAN;
                                (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                escribir_operando(yyout, "1", VALOR_EXPLICITO);
                              }
#line 2567 "y.tab.c"
    break;

  case 81:
#line 869 "alfa.y"
                              {
                                fprintf(yyout,";R103:\t<constante_logica> ::= false\n");
                                (yyval.atributos).tipo = BOOLEAN;
                                (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                                escribir_operando(yyout, "0", VALOR_EXPLICITO);
                              }
#line 2578 "y.tab.c"
    break;

  case 82:
#line 877 "alfa.y"
                              {
                                fprintf(yyout,";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");
                                (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
                                (yyval.atributos).tipo = INT;
                                (yyval.atributos).es_direccion = VALOR_EXPLICITO;
                              }
#line 2589 "y.tab.c"
    break;

  case 83:
#line 885 "alfa.y"
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
#line 2622 "y.tab.c"
    break;


#line 2626 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 914 "alfa.y"


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
