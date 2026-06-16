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

#ifndef YY_YY_SIN_TAB_H_INCLUDED
# define YY_YY_SIN_TAB_H_INCLUDED
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
    TOKEN_FOR = 258,               /* TOKEN_FOR  */
    TOKEN_MAIN = 259,              /* TOKEN_MAIN  */
    TOKEN_RETURN = 260,            /* TOKEN_RETURN  */
    ID = 261,                      /* ID  */
    NUM_INT = 262,                 /* NUM_INT  */
    NUM_FLOAT = 263,               /* NUM_FLOAT  */
    CHAR_LIT = 264,                /* CHAR_LIT  */
    BOOL_LIT = 265,                /* BOOL_LIT  */
    STRING_LIT = 266,              /* STRING_LIT  */
    TOKEN_INT = 267,               /* TOKEN_INT  */
    TOKEN_FLOAT = 268,             /* TOKEN_FLOAT  */
    TOKEN_CHAR = 269,              /* TOKEN_CHAR  */
    TOKEN_BOOL = 270,              /* TOKEN_BOOL  */
    TOKEN_STRING = 271,            /* TOKEN_STRING  */
    ASSIGN = 272,                  /* ASSIGN  */
    PLUS = 273,                    /* PLUS  */
    TOKEN_PRINT = 274,             /* TOKEN_PRINT  */
    TOKEN_READ = 275,              /* TOKEN_READ  */
    TOKEN_IF = 276,                /* TOKEN_IF  */
    TOKEN_ELSE = 277,              /* TOKEN_ELSE  */
    TOKEN_WHILE = 278,             /* TOKEN_WHILE  */
    TOKEN_DO = 279,                /* TOKEN_DO  */
    TOKEN_SWITCH = 280,            /* TOKEN_SWITCH  */
    TOKEN_CASE = 281,              /* TOKEN_CASE  */
    TOKEN_DEFAULT = 282,           /* TOKEN_DEFAULT  */
    TOKEN_BREAK = 283,             /* TOKEN_BREAK  */
    TOKEN_CONTINUE = 284,          /* TOKEN_CONTINUE  */
    AND = 285,                     /* AND  */
    OR = 286,                      /* OR  */
    EQ = 287,                      /* EQ  */
    NE = 288,                      /* NE  */
    LE = 289,                      /* LE  */
    GE = 290,                      /* GE  */
    NOT = 291,                     /* NOT  */
    PLUS_ASSIGN = 292,             /* PLUS_ASSIGN  */
    MINUS_ASSIGN = 293,            /* MINUS_ASSIGN  */
    MULT_ASSIGN = 294,             /* MULT_ASSIGN  */
    DIV_ASSIGN = 295,              /* DIV_ASSIGN  */
    INC = 296,                     /* INC  */
    DEC = 297,                     /* DEC  */
    CAST = 298,                    /* CAST  */
    UMINUS = 299                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 40 "sin.y"

    char* valor_str;
    struct {
        char* temp;
        char* c_expr;
        int tipo_val;
        int tam_str;
    } info;
    
    struct {
        int qtd;
        Tipo tipos[10];
        char* c_args;
    } lista_params;

#line 124 "sin.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SIN_TAB_H_INCLUDED  */
