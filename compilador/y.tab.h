/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 151 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
