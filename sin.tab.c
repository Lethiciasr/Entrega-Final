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
#line 1 "sin.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tabela.h"

int dentro_funcao = 0; // Flag para rastrear se estamos dentro de uma função (Item 2)
int cont_read = 0;
int houve_erro = 0;
int dentro_switch = 0;
extern int yylex();
extern int yylineno;
void yyerror(const char *s) {
    fprintf(stderr, "\n----------------------------------------\n");
    fprintf(stderr, "Erro na linha %d:\n", yylineno);
    fprintf(stderr, "%s\n", s);
    fprintf(stderr, "----------------------------------------\n");
    houve_erro = 1;
}

char buf[200];
char c_decl[5000] = "";
char c_body[5000] = "";
char declaracoes_temp[5000] = "";
char inc_3ac[200] = "";
char inc_c[200] = "";   
char switch_exp[50] = "";
char switch_fim[50] = "";
char pilha_inicio[20][50];
char pilha_fim[20][50];
int topo_laco = 0;

Simbolo *simbolo_array_atual = NULL;
int idx_array_atual = 0;
int tam_array_atual = 0;

int escopo_atual = 0;

// Buffer para acumular o Código Intermediário (TAC) das funções (Item 4)
char instrucoes_funcao[10000] = "";

// Função auxiliar para gerenciar se a instrução vai para a main ou para uma função (Item 6)
void adicionar_instrucao(char *texto) {
    if (dentro_funcao)
        strcat(instrucoes_funcao, texto);
    else
        strcat(instrucoes, texto);
}

#line 122 "sin.tab.c"

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

#include "sin.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_INT = 3,                  /* TOKEN_INT  */
  YYSYMBOL_TOKEN_FLOAT = 4,                /* TOKEN_FLOAT  */
  YYSYMBOL_TOKEN_CHAR = 5,                 /* TOKEN_CHAR  */
  YYSYMBOL_TOKEN_BOOL = 6,                 /* TOKEN_BOOL  */
  YYSYMBOL_TOKEN_STRING = 7,               /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_PRINT = 8,                /* TOKEN_PRINT  */
  YYSYMBOL_TOKEN_READ = 9,                 /* TOKEN_READ  */
  YYSYMBOL_TOKEN_IF = 10,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 11,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_WHILE = 12,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_DO = 13,                  /* TOKEN_DO  */
  YYSYMBOL_TOKEN_FOR = 14,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_SWITCH = 15,              /* TOKEN_SWITCH  */
  YYSYMBOL_TOKEN_CASE = 16,                /* TOKEN_CASE  */
  YYSYMBOL_TOKEN_DEFAULT = 17,             /* TOKEN_DEFAULT  */
  YYSYMBOL_TOKEN_BREAK = 18,               /* TOKEN_BREAK  */
  YYSYMBOL_TOKEN_CONTINUE = 19,            /* TOKEN_CONTINUE  */
  YYSYMBOL_TOKEN_MAIN = 20,                /* TOKEN_MAIN  */
  YYSYMBOL_TOKEN_RETURN = 21,              /* TOKEN_RETURN  */
  YYSYMBOL_STRING_LIT = 22,                /* STRING_LIT  */
  YYSYMBOL_BOOL_LIT = 23,                  /* BOOL_LIT  */
  YYSYMBOL_NUM_INT = 24,                   /* NUM_INT  */
  YYSYMBOL_NUM_FLOAT = 25,                 /* NUM_FLOAT  */
  YYSYMBOL_CHAR_LIT = 26,                  /* CHAR_LIT  */
  YYSYMBOL_ID = 27,                        /* ID  */
  YYSYMBOL_LOWER_THAN_ELSE = 28,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_OR = 29,                        /* OR  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_EQ = 31,                        /* EQ  */
  YYSYMBOL_NE = 32,                        /* NE  */
  YYSYMBOL_33_ = 33,                       /* '<'  */
  YYSYMBOL_34_ = 34,                       /* '>'  */
  YYSYMBOL_LE = 35,                        /* LE  */
  YYSYMBOL_GE = 36,                        /* GE  */
  YYSYMBOL_PLUS = 37,                      /* PLUS  */
  YYSYMBOL_38_ = 38,                       /* '-'  */
  YYSYMBOL_39_ = 39,                       /* '*'  */
  YYSYMBOL_40_ = 40,                       /* '/'  */
  YYSYMBOL_NOT = 41,                       /* NOT  */
  YYSYMBOL_UMINUS = 42,                    /* UMINUS  */
  YYSYMBOL_CAST = 43,                      /* CAST  */
  YYSYMBOL_ASSIGN = 44,                    /* ASSIGN  */
  YYSYMBOL_PLUS_ASSIGN = 45,               /* PLUS_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 46,              /* MINUS_ASSIGN  */
  YYSYMBOL_MULT_ASSIGN = 47,               /* MULT_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 48,                /* DIV_ASSIGN  */
  YYSYMBOL_INC = 49,                       /* INC  */
  YYSYMBOL_DEC = 50,                       /* DEC  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* ';'  */
  YYSYMBOL_54_ = 54,                       /* '{'  */
  YYSYMBOL_55_ = 55,                       /* '}'  */
  YYSYMBOL_56_ = 56,                       /* ','  */
  YYSYMBOL_57_ = 57,                       /* '['  */
  YYSYMBOL_58_ = 58,                       /* ']'  */
  YYSYMBOL_59_ = 59,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_programa = 61,                  /* programa  */
  YYSYMBOL_elementos_globais = 62,         /* elementos_globais  */
  YYSYMBOL_tipo = 63,                      /* tipo  */
  YYSYMBOL_funcao = 64,                    /* funcao  */
  YYSYMBOL_65_1 = 65,                      /* $@1  */
  YYSYMBOL_bloco_funcao = 66,              /* bloco_funcao  */
  YYSYMBOL_parametros_opc = 67,            /* parametros_opc  */
  YYSYMBOL_parametros_lista = 68,          /* parametros_lista  */
  YYSYMBOL_bloco = 69,                     /* bloco  */
  YYSYMBOL_70_2 = 70,                      /* $@2  */
  YYSYMBOL_comandos_bloco = 71,            /* comandos_bloco  */
  YYSYMBOL_comandos = 72,                  /* comandos  */
  YYSYMBOL_comando = 73,                   /* comando  */
  YYSYMBOL_declaracao = 74,                /* declaracao  */
  YYSYMBOL_75_3 = 75,                      /* $@3  */
  YYSYMBOL_lista_inicializadores = 76,     /* lista_inicializadores  */
  YYSYMBOL_elemento_inicializador = 77,    /* elemento_inicializador  */
  YYSYMBOL_atribuicao = 78,                /* atribuicao  */
  YYSYMBOL_if_inicio = 79,                 /* if_inicio  */
  YYSYMBOL_condicao_if = 80,               /* condicao_if  */
  YYSYMBOL_81_4 = 81,                      /* @4  */
  YYSYMBOL_laco_while = 82,                /* laco_while  */
  YYSYMBOL_83_5 = 83,                      /* @5  */
  YYSYMBOL_laco_do_while = 84,             /* laco_do_while  */
  YYSYMBOL_85_6 = 85,                      /* @6  */
  YYSYMBOL_laco_for = 86,                  /* laco_for  */
  YYSYMBOL_87_7 = 87,                      /* @7  */
  YYSYMBOL_88_8 = 88,                      /* @8  */
  YYSYMBOL_89_9 = 89,                      /* $@9  */
  YYSYMBOL_estrutura_switch = 90,          /* estrutura_switch  */
  YYSYMBOL_91_10 = 91,                     /* $@10  */
  YYSYMBOL_casos = 92,                     /* casos  */
  YYSYMBOL_93_11 = 93,                     /* @11  */
  YYSYMBOL_caso_default = 94,              /* caso_default  */
  YYSYMBOL_expressao = 95,                 /* expressao  */
  YYSYMBOL_termo = 96,                     /* termo  */
  YYSYMBOL_fator = 97,                     /* fator  */
  YYSYMBOL_chamada_argumentos = 98,        /* chamada_argumentos  */
  YYSYMBOL_chamada_argumentos_lista = 99   /* chamada_argumentos_lista  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   531

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


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
      51,    52,    39,     2,    56,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    53,
      33,     2,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    35,    36,
      37,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,   101,   103,   104,   108,   110,   111,   112,
     114,   119,   119,   142,   152,   153,   157,   170,   187,   187,
     195,   196,   200,   205,   209,   210,   212,   214,   215,   216,
     217,   218,   239,   263,   279,   289,   302,   310,   319,   354,
     360,   360,   374,   375,   379,   399,   433,   448,   464,   466,
     468,   470,   472,   504,   520,   538,   537,   563,   563,   588,
     588,   610,   619,   625,   610,   641,   641,   658,   658,   674,
     678,   683,   687,   701,   715,   729,   743,   751,   759,   767,
     775,   783,   791,   799,   807,   816,   825,   835,   839,   843,
     854,   861,   868,   875,   882,   890,   896,   913,   940,   942,
     946,   950
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
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_INT",
  "TOKEN_FLOAT", "TOKEN_CHAR", "TOKEN_BOOL", "TOKEN_STRING", "TOKEN_PRINT",
  "TOKEN_READ", "TOKEN_IF", "TOKEN_ELSE", "TOKEN_WHILE", "TOKEN_DO",
  "TOKEN_FOR", "TOKEN_SWITCH", "TOKEN_CASE", "TOKEN_DEFAULT",
  "TOKEN_BREAK", "TOKEN_CONTINUE", "TOKEN_MAIN", "TOKEN_RETURN",
  "STRING_LIT", "BOOL_LIT", "NUM_INT", "NUM_FLOAT", "CHAR_LIT", "ID",
  "LOWER_THAN_ELSE", "OR", "AND", "EQ", "NE", "'<'", "'>'", "LE", "GE",
  "PLUS", "'-'", "'*'", "'/'", "NOT", "UMINUS", "CAST", "ASSIGN",
  "PLUS_ASSIGN", "MINUS_ASSIGN", "MULT_ASSIGN", "DIV_ASSIGN", "INC", "DEC",
  "'('", "')'", "';'", "'{'", "'}'", "','", "'['", "']'", "':'", "$accept",
  "programa", "elementos_globais", "tipo", "funcao", "$@1", "bloco_funcao",
  "parametros_opc", "parametros_lista", "bloco", "$@2", "comandos_bloco",
  "comandos", "comando", "declaracao", "$@3", "lista_inicializadores",
  "elemento_inicializador", "atribuicao", "if_inicio", "condicao_if", "@4",
  "laco_while", "@5", "laco_do_while", "@6", "laco_for", "@7", "@8", "$@9",
  "estrutura_switch", "$@10", "casos", "@11", "caso_default", "expressao",
  "termo", "fator", "chamada_argumentos", "chamada_argumentos_lista", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      48,  -117,  -117,  -117,  -117,  -117,     7,   -11,   -10,    48,
      -5,  -117,   -37,   -41,  -117,    48,     5,   250,    48,    18,
    -117,     4,  -117,  -117,  -117,  -117,  -117,   -32,   250,   250,
      40,   491,  -117,  -117,    33,     9,  -117,    10,  -117,  -117,
     250,   250,  -117,  -117,    17,   347,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,    14,  -117,
      28,   166,   273,    21,  -117,   189,   250,  -117,   218,   163,
     175,   175,    80,    80,    80,    80,   -13,   -13,  -117,  -117,
      48,    22,  -117,    26,    42,    43,  -117,  -117,    45,    46,
      39,    49,   250,    38,    74,    50,  -117,   166,    53,    54,
       4,  -117,  -117,    61,  -117,  -117,   285,   250,  -117,  -117,
    -117,  -117,   166,  -117,    68,   250,    76,   250,    72,     4,
      97,   250,  -117,  -117,   310,   250,   250,   250,   250,   250,
    -117,  -117,   250,   -39,  -117,  -117,  -117,  -117,   114,  -117,
    -117,  -117,    73,   250,   371,    75,   395,   250,   117,    99,
      98,   419,  -117,   491,   491,   491,   491,   491,   201,  -117,
    -117,    95,   101,   491,   100,   106,  -117,   443,   103,   250,
    -117,  -117,   111,     4,  -117,   250,  -117,  -117,     4,   250,
     231,   250,   109,   250,  -117,  -117,  -117,   467,   111,   322,
     144,   491,  -117,  -117,   250,   148,    97,   102,   108,   113,
     130,  -117,   166,  -117,   129,   166,  -117,  -117,   144,   166,
    -117,   131,  -117
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     6,     7,     8,     9,    10,     0,     0,     0,     5,
       0,     1,     0,    37,     4,     5,     0,     0,    15,     0,
       3,     0,    93,    94,    90,    91,    92,    89,     0,     0,
       0,    38,    87,    88,     0,     0,    14,     0,    18,     2,
      99,     0,    85,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    11,
      39,    21,   100,     0,    98,     0,     0,    95,    83,    82,
      78,    79,    80,    81,    76,    77,    72,    73,    74,    75,
       0,     0,    40,     0,     0,     0,    57,    59,     0,     0,
       0,     0,     0,    89,     0,     0,    20,    23,     0,     0,
       0,    26,    27,     0,    29,    30,     0,     0,    97,    96,
      86,    17,    21,    12,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    34,     0,     0,     0,     0,     0,     0,
      46,    47,     0,    37,    19,    22,    24,    25,    54,    28,
      36,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,    45,    48,    49,    50,    51,     0,    55,
      13,     0,    43,    44,     0,     0,    53,     0,     0,     0,
      61,    65,    96,     0,    41,     0,    31,    32,     0,     0,
       0,     0,     0,     0,    56,    42,    58,     0,     0,     0,
      69,    52,    60,    62,     0,    71,     0,     0,     0,     0,
       0,    67,     0,    66,     0,     0,    70,    63,    69,    21,
      68,     0,    64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,    13,    41,  -117,  -117,  -117,  -117,   125,   -99,
    -117,  -110,   -89,  -117,     6,  -117,    31,  -117,  -116,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,     8,  -117,  -117,   -17,  -117,  -117,  -117,   135
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,    94,     9,    81,   113,    35,    36,    39,
      61,    95,    96,    97,    98,   114,   161,   162,    99,   100,
     101,   173,   102,   118,   103,   119,   104,   181,   196,   209,
     105,   182,   195,   205,   199,   106,    32,    33,    63,    64
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,   138,   142,    17,   150,    17,    10,    11,   135,    12,
      18,    42,    43,    45,    16,    10,    19,    13,    19,    40,
     148,    10,    14,    62,    65,    41,    56,    57,    20,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     8,    37,     1,     2,     3,     4,     5,    15,   110,
       8,     1,     2,     3,     4,     5,     8,    21,    38,    34,
      58,    59,    22,    23,    24,    25,    26,    27,    60,    66,
      80,    44,    82,   108,   184,   124,   112,   115,    28,   186,
     200,    29,   125,   126,   127,   128,   129,   130,   131,    40,
      62,    30,   122,   116,   117,   132,   120,   121,   144,   211,
     146,   133,   123,   145,   151,   134,   136,   137,   153,   154,
     155,   156,   157,   206,   139,   158,   208,    54,    55,    56,
      57,    34,   143,   147,   149,   159,   163,   165,   160,   168,
     167,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   125,   126,   127,   128,   129,   130,   131,
     174,   170,   180,   176,   179,   183,   169,   175,   163,   177,
     194,   201,   187,   190,   189,   198,   191,   202,   203,     1,
       2,     3,     4,     5,    83,    84,    85,   197,    86,    87,
      88,    89,   204,   207,    90,    91,   212,    92,    22,    23,
      24,    25,    26,    93,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    28,   111,   185,    29,    50,    51,
      52,    53,    54,    55,    56,    57,   210,    30,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,   141,     0,     0,     0,     0,   109,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,   172,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    22,    23,    24,    25,    26,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,   188,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,   140,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   152,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   193,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   164,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   166,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   178,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   192,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57
};

static const yytype_int16 yycheck[] =
{
      17,   100,   112,    44,   120,    44,     0,     0,    97,    20,
      51,    28,    29,    30,    51,     9,    57,    27,    57,    51,
     119,    15,     9,    40,    41,    57,    39,    40,    15,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,     0,    24,     3,     4,     5,     6,     7,    53,    66,
       9,     3,     4,     5,     6,     7,    15,    52,    54,    18,
      27,    52,    22,    23,    24,    25,    26,    27,    58,    52,
      56,    30,    44,    52,   173,    92,    54,    51,    38,   178,
     196,    41,    44,    45,    46,    47,    48,    49,    50,    51,
     107,    51,    53,    51,    51,    57,    51,    51,   115,   209,
     117,    27,    53,    27,   121,    55,    53,    53,   125,   126,
     127,   128,   129,   202,    53,   132,   205,    37,    38,    39,
      40,    80,    54,    51,    27,    11,   143,    52,    55,    12,
     147,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    44,    45,    46,    47,    48,    49,    50,
      55,    53,   169,    53,    51,    44,    57,    56,   175,    53,
      16,    59,   179,    54,   181,    17,   183,    59,    55,     3,
       4,     5,     6,     7,     8,     9,    10,   194,    12,    13,
      14,    15,    52,    54,    18,    19,    55,    21,    22,    23,
      24,    25,    26,    27,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    38,    80,   175,    41,    33,    34,
      35,    36,    37,    38,    39,    40,   208,    51,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,   107,    -1,    -1,    -1,    -1,    58,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    58,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    58,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    61,    62,    63,    64,
      74,     0,    20,    27,    62,    53,    51,    44,    51,    57,
      62,    52,    22,    23,    24,    25,    26,    27,    38,    41,
      51,    95,    96,    97,    63,    67,    68,    24,    54,    69,
      51,    57,    95,    95,    63,    95,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    27,    52,
      58,    70,    95,    98,    99,    95,    52,    52,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      56,    65,    44,     8,     9,    10,    12,    13,    14,    15,
      18,    19,    21,    27,    63,    71,    72,    73,    74,    78,
      79,    80,    82,    84,    86,    90,    95,    56,    52,    58,
      95,    68,    54,    66,    75,    51,    51,    51,    83,    85,
      51,    51,    53,    53,    95,    44,    45,    46,    47,    48,
      49,    50,    57,    27,    55,    72,    53,    53,    69,    53,
      53,    99,    71,    54,    95,    27,    95,    51,    69,    27,
      78,    95,    53,    95,    95,    95,    95,    95,    95,    11,
      55,    76,    77,    95,    52,    52,    52,    95,    12,    57,
      53,    52,    58,    81,    55,    56,    53,    53,    52,    51,
      95,    87,    91,    44,    69,    76,    69,    95,    58,    95,
      54,    95,    52,    53,    16,    92,    88,    95,    17,    94,
      78,    59,    59,    55,    52,    93,    72,    54,    72,    89,
      92,    71,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    62,    62,    63,    63,    63,    63,
      63,    65,    64,    66,    67,    67,    68,    68,    70,    69,
      71,    71,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    74,    74,
      75,    74,    76,    76,    77,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    80,    81,    80,    83,    82,    85,
      84,    87,    88,    89,    86,    91,    90,    93,    92,    92,
      94,    94,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    96,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    98,    98,
      99,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     2,     0,     1,     1,     1,     1,
       1,     0,     7,     3,     1,     0,     2,     4,     0,     4,
       1,     0,     2,     1,     2,     2,     1,     1,     2,     1,
       1,     5,     5,     2,     2,     3,     2,     2,     4,     5,
       0,    10,     3,     1,     1,     3,     2,     2,     3,     3,
       3,     3,     6,     4,     2,     0,     5,     0,     6,     0,
       7,     0,     0,     0,    14,     0,     9,     0,     6,     0,
       3,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     4,     1,     0,
       1,     3
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
  case 2: /* programa: elementos_globais TOKEN_MAIN '(' ')' bloco  */
#line 94 "sin.y"
                                                 {
        // Encerra a construção colocando o bloco principal da main no corpo de C
        strcat(c_body, (yyvsp[0].info).c_expr);
    }
#line 1422 "sin.tab.c"
    break;

  case 6: /* tipo: TOKEN_INT  */
#line 108 "sin.y"
                   { (yyval.info).tipo_val = T_INT; }
#line 1428 "sin.tab.c"
    break;

  case 7: /* tipo: TOKEN_FLOAT  */
#line 110 "sin.y"
                 { (yyval.info).tipo_val = T_FLOAT; }
#line 1434 "sin.tab.c"
    break;

  case 8: /* tipo: TOKEN_CHAR  */
#line 111 "sin.y"
                   { (yyval.info).tipo_val = T_CHAR; }
#line 1440 "sin.tab.c"
    break;

  case 9: /* tipo: TOKEN_BOOL  */
#line 112 "sin.y"
                   { (yyval.info).tipo_val = T_BOOL; }
#line 1446 "sin.tab.c"
    break;

  case 10: /* tipo: TOKEN_STRING  */
#line 114 "sin.y"
                 { (yyval.info).tipo_val = T_STRING; }
#line 1452 "sin.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 119 "sin.y"
                                     {
        dentro_funcao = 1; // Ativa a flag de função ao entrar nela
        // Insere a assinatura da função na tabela de símbolos (escopo global 0)
        inserir_funcao((yyvsp[-3].valor_str), (yyvsp[-4].info).tipo_val, (yyvsp[-1].lista_params).qtd, (yyvsp[-1].lista_params).tipos);
        // Inicializa o cabeçalho no buffer C global de declarações externas
        char const* t_nome = ((yyvsp[-4].info).tipo_val == T_INT) ?
                             "int" : 
                             (((yyvsp[-4].info).tipo_val == T_FLOAT) ? "float" : 
                             (((yyvsp[-4].info).tipo_val == T_CHAR) ? "char" : "int"));
        sprintf(buf, "\n%s %s(%s) {\n", t_nome, (yyvsp[-3].valor_str), (yyvsp[-1].lista_params).c_args);
        strcat(c_code_body, buf); 
        
        // Entra no nível interno de escopo para as variáveis locais e parâmetros
        escopo_atual++;
    }
#line 1472 "sin.tab.c"
    break;

  case 12: /* funcao: tipo ID '(' parametros_opc ')' $@1 bloco_funcao  */
#line 134 "sin.y"
                 {
        dentro_funcao = 0; // Desativa a flag de função ao sair dela
        escopo_atual--;
        strcat(c_code_body, "}\n\n");
    }
#line 1482 "sin.tab.c"
    break;

  case 13: /* bloco_funcao: '{' comandos_bloco '}'  */
#line 142 "sin.y"
                             {
        strcat(c_code_body, instrucoes_funcao);

        instrucoes_funcao[0] = '\0';

        remover_simbolos_do_nivel(escopo_atual);
    }
#line 1494 "sin.tab.c"
    break;

  case 14: /* parametros_opc: parametros_lista  */
#line 152 "sin.y"
                       { (yyval.lista_params) = (yyvsp[0].lista_params); }
#line 1500 "sin.tab.c"
    break;

  case 15: /* parametros_opc: %empty  */
#line 153 "sin.y"
                       { (yyval.lista_params).qtd = 0; (yyval.lista_params).c_args = strdup(""); }
#line 1506 "sin.tab.c"
    break;

  case 16: /* parametros_lista: tipo ID  */
#line 157 "sin.y"
              {
        (yyval.lista_params).qtd = 1;
        (yyval.lista_params).tipos[0] = (yyvsp[-1].info).tipo_val;
        char temp_arg[100];
        char const* t_nome = ((yyvsp[-1].info).tipo_val == T_INT) ?
                             "int" : (((yyvsp[-1].info).tipo_val == T_FLOAT) ? "float" : "char");
        
        // Insere o parâmetro no escopo interno da função (escopo_atual + 1)
        Simbolo* s = inserir((yyvsp[0].valor_str), (yyvsp[-1].info).tipo_val, escopo_atual + 1);
        sprintf(temp_arg, "%s %s", t_nome, s->temp);
        (yyval.lista_params).c_args = strdup(temp_arg);
    }
#line 1523 "sin.tab.c"
    break;

  case 17: /* parametros_lista: tipo ID ',' parametros_lista  */
#line 170 "sin.y"
                                 {
        (yyval.lista_params).qtd = (yyvsp[0].lista_params).qtd + 1;
        (yyval.lista_params).tipos[0] = (yyvsp[-3].info).tipo_val;
        for(int i = 0; i < (yyvsp[0].lista_params).qtd; i++) {
            (yyval.lista_params).tipos[i+1] = (yyvsp[0].lista_params).tipos[i];
        }
        char temp_arg[400];
        char const* t_nome = ((yyvsp[-3].info).tipo_val == T_INT) ?
                             "int" : (((yyvsp[-3].info).tipo_val == T_FLOAT) ? "float" : "char");
        
        Simbolo* s = inserir((yyvsp[-2].valor_str), (yyvsp[-3].info).tipo_val, escopo_atual + 1);
        sprintf(temp_arg, "%s %s, %s", t_nome, s->temp, (yyvsp[0].lista_params).c_args);
        (yyval.lista_params).c_args = strdup(temp_arg);
    }
#line 1542 "sin.tab.c"
    break;

  case 18: /* $@2: %empty  */
#line 187 "sin.y"
          { escopo_atual++; }
#line 1548 "sin.tab.c"
    break;

  case 19: /* bloco: '{' $@2 comandos_bloco '}'  */
#line 187 "sin.y"
                                                 { 
        remover_simbolos_do_nivel(escopo_atual);
        escopo_atual--; 
        (yyval.info).c_expr = (yyvsp[-1].info).c_expr;
    }
#line 1558 "sin.tab.c"
    break;

  case 20: /* comandos_bloco: comandos  */
#line 195 "sin.y"
               { (yyval.info) = (yyvsp[0].info); }
#line 1564 "sin.tab.c"
    break;

  case 21: /* comandos_bloco: %empty  */
#line 196 "sin.y"
                  { (yyval.info).c_expr = strdup(""); }
#line 1570 "sin.tab.c"
    break;

  case 22: /* comandos: comando comandos  */
#line 200 "sin.y"
                       {
        char *res = (char*) malloc(strlen((yyvsp[-1].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 2);
        sprintf(res, "%s%s", (yyvsp[-1].info).c_expr, (yyvsp[0].info).c_expr);
        (yyval.info).c_expr = res;
    }
#line 1580 "sin.tab.c"
    break;

  case 23: /* comandos: comando  */
#line 205 "sin.y"
              { (yyval.info) = (yyvsp[0].info); }
#line 1586 "sin.tab.c"
    break;

  case 24: /* comando: declaracao ';'  */
#line 209 "sin.y"
                       { (yyval.info) = (yyvsp[-1].info); }
#line 1592 "sin.tab.c"
    break;

  case 25: /* comando: atribuicao ';'  */
#line 210 "sin.y"
                       { (yyval.info) = (yyvsp[-1].info); }
#line 1598 "sin.tab.c"
    break;

  case 26: /* comando: condicao_if  */
#line 212 "sin.y"
                     { (yyval.info) = (yyvsp[0].info); }
#line 1604 "sin.tab.c"
    break;

  case 27: /* comando: laco_while  */
#line 214 "sin.y"
                     { (yyval.info) = (yyvsp[0].info); }
#line 1610 "sin.tab.c"
    break;

  case 28: /* comando: laco_do_while ';'  */
#line 215 "sin.y"
                        { (yyval.info) = (yyvsp[-1].info); }
#line 1616 "sin.tab.c"
    break;

  case 29: /* comando: laco_for  */
#line 216 "sin.y"
                       { (yyval.info) = (yyvsp[0].info); }
#line 1622 "sin.tab.c"
    break;

  case 30: /* comando: estrutura_switch  */
#line 217 "sin.y"
                       { (yyval.info) = (yyvsp[0].info); }
#line 1628 "sin.tab.c"
    break;

  case 31: /* comando: TOKEN_PRINT '(' expressao ')' ';'  */
#line 218 "sin.y"
                                        {
        char* c_out = (char*) malloc(256);
        if ((yyvsp[-2].info).tipo_val == T_INT) {
            sprintf(buf, "printf(\"%%d\\n\", %s);\n", (yyvsp[-2].info).temp);
            sprintf(c_out, "printf(\"%%d\\n\", %s);\n", (yyvsp[-2].info).c_expr);
        } else if ((yyvsp[-2].info).tipo_val == T_FLOAT) {
            sprintf(buf, "printf(\"%%f\\n\", %s);\n", (yyvsp[-2].info).temp);
            sprintf(c_out, "printf(\"%%f\\n\", %s);\n", (yyvsp[-2].info).c_expr);
        } else if ((yyvsp[-2].info).tipo_val == T_CHAR) {
            sprintf(buf, "printf(\"%%c\\n\", %s);\n", (yyvsp[-2].info).temp);
            sprintf(c_out, "printf(\"%%c\\n\", %s);\n", (yyvsp[-2].info).c_expr);
        } else if ((yyvsp[-2].info).tipo_val == T_BOOL) {
            sprintf(buf, "printf(\"%%s\\n\", %s ? \"true\" : \"false\");\n", (yyvsp[-2].info).temp);
            sprintf(c_out, "printf(\"%%s\\n\", %s ? \"true\" : \"false\");\n", (yyvsp[-2].info).c_expr);
        } else if ((yyvsp[-2].info).tipo_val == T_STRING) {
            sprintf(buf, "printf(\"%%s\\n\", %s);\n", (yyvsp[-2].info).temp);
            sprintf(c_out, "printf(\"%%s\\n\", %s);\n", (yyvsp[-2].info).c_expr);
        }
        adicionar_instrucao(buf); // Substituído para suportar subprogramas (Item 7)
        (yyval.info).c_expr = c_out;
    }
#line 1654 "sin.tab.c"
    break;

  case 32: /* comando: TOKEN_READ '(' ID ')' ';'  */
#line 239 "sin.y"
                                {
        Simbolo *s = buscar((yyvsp[-2].valor_str));
        char* c_out = (char*) malloc(256);
        if (s == NULL) {
            yyerror("Erro Semantico: Variavel nao declarada.");
            (yyval.info).c_expr = strdup("");
        } else {
            if (s->tipo == T_INT) {
                sprintf(buf, "scanf(\"%%d\", &%s);\n", s->temp);
                sprintf(c_out, "scanf(\"%%d\", &%s);\n", s->nome);
            } else if (s->tipo == T_FLOAT) {
                sprintf(buf, "scanf(\"%%f\", &%s);\n", s->temp);
                sprintf(c_out, "scanf(\"%%f\", &%s);\n", s->nome);
            } else if (s->tipo == T_CHAR) {
                sprintf(buf, "scanf(\" %%c\", &%s);\n", s->temp);
                sprintf(c_out, "scanf(\" %%c\", &%s);\n", s->nome);
            } else if (s->tipo == T_STRING) {
                sprintf(buf, "scanf(\"%%s\", %s);\n", s->temp);
                sprintf(c_out, "scanf(\"%%s\", %s);\n", s->nome);
            }
            adicionar_instrucao(buf); // Substituído para suportar subprogramas (Item 7)
            (yyval.info).c_expr = c_out;
        }
    }
#line 1683 "sin.tab.c"
    break;

  case 33: /* comando: TOKEN_BREAK ';'  */
#line 263 "sin.y"
                      {
        if (!dentro_switch && topo_laco == 0) {
            yyerror("Erro Semantico: 'break' usado fora de laco ou switch.");
        }
        char* c_out = (char*) malloc(100);
        if (dentro_switch) {
            sprintf(buf, "goto %s;\n", switch_fim);
            sprintf(c_out, "break;\n");
        } else {
            sprintf(buf, "goto %s;\n", pilha_fim[topo_laco - 1]);
            sprintf(c_out, "break;\n");
        }
        adicionar_instrucao(buf); // Substituído para suportar subprogramas (Item 7)
        (yyval.info).c_expr = c_out;
    }
#line 1703 "sin.tab.c"
    break;

  case 34: /* comando: TOKEN_CONTINUE ';'  */
#line 279 "sin.y"
                       {
        if (topo_laco == 0) {
            yyerror("Erro Semantico: 'continue' usado fora de um laco.");
        }
        char* c_out = (char*) malloc(100);
        sprintf(buf, "goto %s;\n", pilha_inicio[topo_laco - 1]);
        sprintf(c_out, "continue;\n");
        adicionar_instrucao(buf); // Substituído para suportar subprogramas (Item 7)
        (yyval.info).c_expr = c_out;
    }
#line 1718 "sin.tab.c"
    break;

  case 35: /* comando: TOKEN_RETURN expressao ';'  */
#line 289 "sin.y"
                                 {
    char* c_out = (char*) malloc(256);

    sprintf(buf, "return %s;\n", (yyvsp[-1].info).temp);

    if (escopo_atual > 0)
        strcat(instrucoes_funcao, buf);
    else
        strcat(instrucoes, buf);

    sprintf(c_out, "return %s;\n", (yyvsp[-1].info).c_expr);
    (yyval.info).c_expr = c_out;
    }
#line 1736 "sin.tab.c"
    break;

  case 36: /* comando: expressao ';'  */
#line 302 "sin.y"
                    {
        char* c_out = (char*) malloc(strlen((yyvsp[-1].info).c_expr) + 5);
        sprintf(c_out, "%s;\n", (yyvsp[-1].info).c_expr);
        (yyval.info).c_expr = c_out;
    }
#line 1746 "sin.tab.c"
    break;

  case 37: /* declaracao: tipo ID  */
#line 310 "sin.y"
              {
        if (buscar((yyvsp[0].valor_str)) != NULL && buscar((yyvsp[0].valor_str))->nivel == escopo_atual) {
            yyerror("Erro Semantico: Variavel ja declarada neste escopo.");
        } else {
            inserir((yyvsp[0].valor_str), (yyvsp[-1].info).tipo_val, escopo_atual);
        }
        (yyval.info).c_expr = strdup("");
    }
#line 1759 "sin.tab.c"
    break;

  case 38: /* declaracao: tipo ID ASSIGN expressao  */
#line 319 "sin.y"
                             {
        Simbolo *s = buscar((yyvsp[-2].valor_str));
        if (s != NULL && s->nivel == escopo_atual) {
            yyerror("Erro Semantico: Variavel ja declarada neste escopo.");
        } else {
            s = inserir((yyvsp[-2].valor_str), (yyvsp[-3].info).tipo_val, escopo_atual);
            char* expr_temp = (yyvsp[0].info).temp;
            char* expr_c = (yyvsp[0].info).c_expr;
            if ((yyvsp[-3].info).tipo_val == T_FLOAT && (yyvsp[0].info).tipo_val == T_INT) {
                expr_temp = gerar_cast((yyvsp[0].info).temp, T_FLOAT);
                char* cast_c = (char*) malloc(strlen((yyvsp[0].info).c_expr) + 20);
                sprintf(cast_c, "(float)(%s)", (yyvsp[0].info).c_expr);
                expr_c = cast_c;
            } else if ((yyvsp[-3].info).tipo_val == T_INT && (yyvsp[0].info).tipo_val == T_FLOAT) {
                expr_temp = gerar_cast((yyvsp[0].info).temp, T_INT);
                char* cast_c = (char*) malloc(strlen((yyvsp[0].info).c_expr) + 20);
                sprintf(cast_c, "(int)(%s)", (yyvsp[0].info).c_expr);
                expr_c = cast_c;
            }
            if ((yyvsp[-3].info).tipo_val == T_STRING) {
                sprintf(buf, "strcpy(%s, %s);\n", s->temp, expr_temp);
                adicionar_instrucao(buf); // Alterado (Item 7)
                char* c_out = (char*) malloc(256);
                sprintf(c_out, "strcpy(%s, %s);\n", s->nome, expr_c);
                (yyval.info).c_expr = c_out;
            } else {
                sprintf(buf, "%s = %s;\n", s->temp, expr_temp);
                adicionar_instrucao(buf); // Alterado (Item 7)
                char* c_out = (char*) malloc(256);
                sprintf(c_out, "%s = %s;\n", s->nome, expr_c);
                (yyval.info).c_expr = c_out;
            }
        }
    }
#line 1798 "sin.tab.c"
    break;

  case 39: /* declaracao: tipo ID '[' NUM_INT ']'  */
#line 354 "sin.y"
                            {
        int tam = atoi((yyvsp[-1].valor_str));
        inserir_array((yyvsp[-3].valor_str), (yyvsp[-4].info).tipo_val, escopo_atual, tam);
        (yyval.info).c_expr = strdup("");
    }
#line 1808 "sin.tab.c"
    break;

  case 40: /* $@3: %empty  */
#line 360 "sin.y"
                                   {
        int tam = atoi((yyvsp[-2].valor_str));
        simbolo_array_atual = inserir_array((yyvsp[-4].valor_str), (yyvsp[-5].info).tipo_val, escopo_atual, tam);
        idx_array_atual = 0;
        tam_array_atual = tam;
    }
#line 1819 "sin.tab.c"
    break;

  case 41: /* declaracao: tipo ID '[' NUM_INT ']' ASSIGN $@3 '{' lista_inicializadores '}'  */
#line 365 "sin.y"
                                    {
        if (idx_array_atual < tam_array_atual) {
            yyerror("Erro Semantico: Elementos insuficientes na inicializacao da matriz.");
        }
        (yyval.info).c_expr = strdup("");
    }
#line 1830 "sin.tab.c"
    break;

  case 44: /* elemento_inicializador: expressao  */
#line 379 "sin.y"
                {
        if (simbolo_array_atual != NULL) {
            if (idx_array_atual < tam_array_atual) {
                char* expr_temp = (yyvsp[0].info).temp;
                if (simbolo_array_atual->tipo == T_FLOAT && (yyvsp[0].info).tipo_val == T_INT) {
                    expr_temp = gerar_cast((yyvsp[0].info).temp, T_FLOAT);
                } else if (simbolo_array_atual->tipo == T_INT && (yyvsp[0].info).tipo_val == T_FLOAT) {
                    expr_temp = gerar_cast((yyvsp[0].info).temp, T_INT);
                }
                sprintf(buf, "%s[%d] = %s;\n", simbolo_array_atual->temp, idx_array_atual, expr_temp);
                adicionar_instrucao(buf); // Alterado (Item 7)
                idx_array_atual++;
            } else {
                yyerror("Erro Semantico: Excesso de elementos na inicializacao da matriz.");
            }
        }
    }
#line 1852 "sin.tab.c"
    break;

  case 45: /* atribuicao: ID ASSIGN expressao  */
#line 399 "sin.y"
                          {
        Simbolo *s = buscar((yyvsp[-2].valor_str));
        if (s == NULL) {
            yyerror("Erro Semantico: Variavel nao declarada.");
            (yyval.info).c_expr = strdup("");
        } else {
            char* expr_temp = (yyvsp[0].info).temp;
            char* expr_c = (yyvsp[0].info).c_expr;
            if (s->tipo == T_FLOAT && (yyvsp[0].info).tipo_val == T_INT) {
                expr_temp = gerar_cast((yyvsp[0].info).temp, T_FLOAT);
                char* cast_c = (char*) malloc(strlen((yyvsp[0].info).c_expr) + 20);
                sprintf(cast_c, "(float)(%s)", (yyvsp[0].info).c_expr);
                expr_c = cast_c;
            } else if (s->tipo == T_INT && (yyvsp[0].info).tipo_val == T_FLOAT) {
                expr_temp = gerar_cast((yyvsp[0].info).temp, T_INT);
                char* cast_c = (char*) malloc(strlen((yyvsp[0].info).c_expr) + 20);
                sprintf(cast_c, "(int)(%s)", (yyvsp[0].info).c_expr);
                expr_c = cast_c;
            }
            if (s->tipo == T_STRING) {
                sprintf(buf, "strcpy(%s, %s);\n", s->temp, expr_temp);
                adicionar_instrucao(buf); // Alterado (Item 7)
                char* c_out = (char*) malloc(256);
                sprintf(c_out, "strcpy(%s, %s);\n", s->nome, expr_c);
                (yyval.info).c_expr = c_out;
            } else {
                sprintf(buf, "%s = %s;\n", s->temp, expr_temp);
                adicionar_instrucao(buf); // Alterado (Item 7)
                char* c_out = (char*) malloc(256);
                sprintf(c_out, "%s = %s;\n", s->nome, expr_c);
                (yyval.info).c_expr = c_out;
            }
        }
    }
#line 1891 "sin.tab.c"
    break;

  case 46: /* atribuicao: ID INC  */
#line 433 "sin.y"
             {
    Simbolo *s = buscar((yyvsp[-1].valor_str));

    if (s == NULL) {
        yyerror("Erro Semantico: Variavel nao declarada.");
        (yyval.info).c_expr = strdup("");
    } else {
        sprintf(buf, "%s = %s + 1;\n", s->temp, s->temp);
        adicionar_instrucao(buf);

        char *c_out = (char*) malloc(100);
        sprintf(c_out, "%s++;\n", s->nome);
        (yyval.info).c_expr = c_out;
    }
    }
#line 1911 "sin.tab.c"
    break;

  case 47: /* atribuicao: ID DEC  */
#line 448 "sin.y"
             {
        Simbolo *s = buscar((yyvsp[-1].valor_str));

        if (s == NULL) {
            yyerror("Erro Semantico: Variavel nao declarada.");
            (yyval.info).c_expr = strdup("");
        } else {
            sprintf(buf, "%s = %s - 1;\n", s->temp, s->temp);
            adicionar_instrucao(buf);

            char *c_out = (char*) malloc(100);
            sprintf(c_out, "%s--;\n", s->nome);
            (yyval.info).c_expr = c_out;
        }
    }
#line 1931 "sin.tab.c"
    break;

  case 48: /* atribuicao: ID PLUS_ASSIGN expressao  */
#line 464 "sin.y"
                              { (yyval.info).c_expr = strdup(""); }
#line 1937 "sin.tab.c"
    break;

  case 49: /* atribuicao: ID MINUS_ASSIGN expressao  */
#line 466 "sin.y"
                              { (yyval.info).c_expr = strdup(""); }
#line 1943 "sin.tab.c"
    break;

  case 50: /* atribuicao: ID MULT_ASSIGN expressao  */
#line 468 "sin.y"
                              { (yyval.info).c_expr = strdup(""); }
#line 1949 "sin.tab.c"
    break;

  case 51: /* atribuicao: ID DIV_ASSIGN expressao  */
#line 470 "sin.y"
                              { (yyval.info).c_expr = strdup(""); }
#line 1955 "sin.tab.c"
    break;

  case 52: /* atribuicao: ID '[' expressao ']' ASSIGN expressao  */
#line 472 "sin.y"
                                          {
        Simbolo *s = buscar((yyvsp[-5].valor_str));
        if (s == NULL) {
            yyerror("Erro Semantico: Matriz nao declarada.");
            (yyval.info).c_expr = strdup("");
        } else if (!s->array) {
            yyerror("Erro Semantico: Identificador nao eh uma matriz.");
            (yyval.info).c_expr = strdup("");
        } else {
            char* expr_temp = (yyvsp[0].info).temp;
            char* expr_c = (yyvsp[0].info).c_expr;
            if (s->tipo == T_FLOAT && (yyvsp[0].info).tipo_val == T_INT) {
                expr_temp = gerar_cast((yyvsp[0].info).temp, T_FLOAT);
                char* cast_c = (char*) malloc(strlen((yyvsp[0].info).c_expr) + 20);
                sprintf(cast_c, "(float)(%s)", (yyvsp[0].info).c_expr);
                expr_c = cast_c;
            } else if (s->tipo == T_INT && (yyvsp[0].info).tipo_val == T_FLOAT) {
                expr_temp = gerar_cast((yyvsp[0].info).temp, T_INT);
                char* cast_c = (char*) malloc(strlen((yyvsp[0].info).c_expr) + 20);
                sprintf(cast_c, "(int)(%s)", (yyvsp[0].info).c_expr);
                expr_c = cast_c;
            }
            sprintf(buf, "%s[%s] = %s;\n", s->temp, (yyvsp[-3].info).temp, expr_temp);
            adicionar_instrucao(buf); // Alterado (Item 7)
            char* c_out = (char*) malloc(256);
            sprintf(c_out, "%s[%s] = %s;\n", s->nome, (yyvsp[-3].info).c_expr, expr_c);
            (yyval.info).c_expr = c_out;
        }
    }
#line 1989 "sin.tab.c"
    break;

  case 53: /* if_inicio: TOKEN_IF '(' expressao ')'  */
#line 505 "sin.y"
      {
          char *l_false = novo_label();

          sprintf(buf,
                  "if (!%s) goto %s;\n",
                  (yyvsp[-1].info).temp,
                  l_false);

          adicionar_instrucao(buf);

          (yyval.valor_str) = strdup(l_false);
      }
#line 2006 "sin.tab.c"
    break;

  case 54: /* condicao_if: if_inicio bloco  */
#line 521 "sin.y"
      {
          sprintf(buf, "%s:\n", (yyvsp[-1].valor_str));
          adicionar_instrucao(buf);

          char *c_out = (char*) malloc(
              strlen((yyvsp[0].info).c_expr) +
              strlen((yyvsp[-1].valor_str)) + 200
          );

          sprintf(c_out,
                  "if (...) {\n%s}\n",
                  (yyvsp[0].info).c_expr);

          (yyval.info).c_expr = c_out;
      }
#line 2026 "sin.tab.c"
    break;

  case 55: /* @4: %empty  */
#line 538 "sin.y"
      {
          char *l_fim = novo_label();

          sprintf(buf,
                  "goto %s;\n%s:\n",
                  l_fim,
                  (yyvsp[-2].valor_str));

          adicionar_instrucao(buf);

          (yyval.valor_str) = l_fim;
      }
#line 2043 "sin.tab.c"
    break;

  case 56: /* condicao_if: if_inicio bloco TOKEN_ELSE @4 bloco  */
#line 551 "sin.y"
      {
          sprintf(buf,
                  "%s:\n",
                  (yyvsp[-1].valor_str));

          adicionar_instrucao(buf);

          (yyval.info).c_expr = strdup("");
      }
#line 2057 "sin.tab.c"
    break;

  case 57: /* @5: %empty  */
#line 563 "sin.y"
                  {
        char *l_inicio = novo_label();
        char *l_fim = novo_label();
        strcpy(pilha_inicio[topo_laco], l_inicio);
        strcpy(pilha_fim[topo_laco], l_fim);
        topo_laco++;
        sprintf(buf, "%s:\n", l_inicio);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.valor_str) = l_inicio;
    }
#line 2072 "sin.tab.c"
    break;

  case 58: /* laco_while: TOKEN_WHILE @5 '(' expressao ')' bloco  */
#line 572 "sin.y"
                              {
        char *l_inicio = (yyvsp[-4].valor_str);
        char *l_fim = pilha_fim[topo_laco - 1];
        sprintf(buf, "if (!%s) goto %s;\n", (yyvsp[-2].info).temp, l_fim);
        adicionar_instrucao(buf); // Alterado (Item 7)
        char *c_out = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 200);
        sprintf(c_out, "while (%s) {\n%s}\n", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
        
        sprintf(buf, "goto %s;\n%s:\n", l_inicio, l_fim);
        adicionar_instrucao(buf); // Alterado (Item 7)
        topo_laco--;
        (yyval.info).c_expr = c_out;
    }
#line 2090 "sin.tab.c"
    break;

  case 59: /* @6: %empty  */
#line 588 "sin.y"
               {
        char *l_inicio = novo_label();
        char *l_fim = novo_label();
        strcpy(pilha_inicio[topo_laco], l_inicio);
        strcpy(pilha_fim[topo_laco], l_fim);
        topo_laco++;
        sprintf(buf, "%s:\n", l_inicio);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.valor_str) = l_inicio;
    }
#line 2105 "sin.tab.c"
    break;

  case 60: /* laco_do_while: TOKEN_DO @6 bloco TOKEN_WHILE '(' expressao ')'  */
#line 597 "sin.y"
                                          {
        char *l_inicio = (yyvsp[-5].valor_str);
        char *l_fim = pilha_fim[topo_laco - 1];
        sprintf(buf, "if (%s) goto %s;\n%s:\n", (yyvsp[-1].info).temp, l_inicio, l_fim);
        adicionar_instrucao(buf); // Alterado (Item 7)
        char *c_out = (char*) malloc(strlen((yyvsp[-4].info).c_expr) + strlen((yyvsp[-1].info).c_expr) + 200);
        sprintf(c_out, "do {\n%s} while (%s);\n", (yyvsp[-4].info).c_expr, (yyvsp[-1].info).c_expr);
        topo_laco--;
        (yyval.info).c_expr = c_out;
    }
#line 2120 "sin.tab.c"
    break;

  case 61: /* @7: %empty  */
#line 610 "sin.y"
                                   {
        char *l_inicio = novo_label();
        char *l_fim = novo_label();
        strcpy(pilha_inicio[topo_laco], l_inicio);
        strcpy(pilha_fim[topo_laco], l_fim);
        topo_laco++;
        sprintf(buf, "%s:\n", l_inicio);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.valor_str) = l_inicio;
    }
#line 2135 "sin.tab.c"
    break;

  case 62: /* @8: %empty  */
#line 619 "sin.y"
                    {
        char *l_corpo = novo_label();
        char *l_fim = pilha_fim[topo_laco - 1];
        sprintf(buf, "if (%s) goto %s;\ngoto %s;\n%s:\n", (yyvsp[-1].info).temp, l_corpo, l_fim, l_corpo);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.valor_str) = l_corpo;
    }
#line 2147 "sin.tab.c"
    break;

  case 63: /* $@9: %empty  */
#line 625 "sin.y"
                         { escopo_atual++; }
#line 2153 "sin.tab.c"
    break;

  case 64: /* laco_for: TOKEN_FOR '(' atribuicao ';' @7 expressao ';' @8 atribuicao ')' '{' $@9 comandos_bloco '}'  */
#line 625 "sin.y"
                                                                {
        remover_simbolos_do_nivel(escopo_atual);
        escopo_atual--;
        char *l_inicio = (yyvsp[-9].valor_str);
        char *l_fim = pilha_fim[topo_laco - 1];
        sprintf(buf, "goto %s;\n%s:\n", l_inicio, l_fim);
        adicionar_instrucao(buf); // Alterado (Item 7)
        char *c_out = (char*) malloc(strlen((yyvsp[-11].info).c_expr) + strlen((yyvsp[-8].info).c_expr) + strlen((yyvsp[-5].info).c_expr) + strlen((yyvsp[-1].info).c_expr) + 300);
        sprintf(c_out,
        "for (%s; %s; %s) {\n%s}\n", (yyvsp[-11].info).c_expr, (yyvsp[-8].info).c_expr, (yyvsp[-5].info).c_expr, (yyvsp[-1].info).c_expr);
        topo_laco--;
        (yyval.info).c_expr = c_out;
    }
#line 2171 "sin.tab.c"
    break;

  case 65: /* $@10: %empty  */
#line 641 "sin.y"
                                     {
        dentro_switch = 1;
        char *l_fim = novo_label();
        strcpy(switch_fim, l_fim);
        strcpy(switch_exp, (yyvsp[-1].info).temp);
    }
#line 2182 "sin.tab.c"
    break;

  case 66: /* estrutura_switch: TOKEN_SWITCH '(' expressao ')' $@10 '{' casos caso_default '}'  */
#line 646 "sin.y"
                                 {
        sprintf(buf, "%s:\n", switch_fim);
        adicionar_instrucao(buf); // Alterado (Item 7)
        dentro_switch = 0;
        
        char *c_out = (char*) malloc(strlen((yyvsp[-6].info).c_expr) + strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[-1].info).c_expr) + 200);
        sprintf(c_out, "switch (%s) {\n%s%s}\n", (yyvsp[-6].info).c_expr, (yyvsp[-2].info).c_expr, (yyvsp[-1].info).c_expr);
        (yyval.info).c_expr = c_out;
    }
#line 2196 "sin.tab.c"
    break;

  case 67: /* @11: %empty  */
#line 658 "sin.y"
                               {
        char *l_prox = novo_label();
        char *t_cmp = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s == %s;\nif (!%s) goto %s;\n", t_cmp, switch_exp, (yyvsp[-1].info).temp, t_cmp, l_prox);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.valor_str) = l_prox;
    }
#line 2208 "sin.tab.c"
    break;

  case 68: /* casos: TOKEN_CASE expressao ':' @11 comandos casos  */
#line 664 "sin.y"
                     {
        char *l_prox = (yyvsp[-2].valor_str);
        sprintf(buf, "%s:\n", l_prox);
        adicionar_instrucao(buf); // Alterado (Item 7)
        
        char *c_out = (char*) malloc(strlen((yyvsp[-4].info).c_expr) + strlen((yyvsp[-1].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 100);
        sprintf(c_out, "case %s:\n%s%s", (yyvsp[-4].info).c_expr, (yyvsp[-1].info).c_expr, (yyvsp[0].info).c_expr);
        (yyval.info).c_expr = c_out;
    }
#line 2222 "sin.tab.c"
    break;

  case 69: /* casos: %empty  */
#line 674 "sin.y"
                { (yyval.info).c_expr = strdup(""); }
#line 2228 "sin.tab.c"
    break;

  case 70: /* caso_default: TOKEN_DEFAULT ':' comandos  */
#line 678 "sin.y"
                                 {
        char *c_out = (char*) malloc(strlen((yyvsp[0].info).c_expr) + 50);
        sprintf(c_out, "default:\n%s", (yyvsp[0].info).c_expr);
        (yyval.info).c_expr = c_out;
    }
#line 2238 "sin.tab.c"
    break;

  case 71: /* caso_default: %empty  */
#line 683 "sin.y"
                  { (yyval.info).c_expr = strdup(""); }
#line 2244 "sin.tab.c"
    break;

  case 72: /* expressao: expressao PLUS expressao  */
#line 687 "sin.y"
                               {
        int t_res = ((yyvsp[-2].info).tipo_val == T_FLOAT || (yyvsp[0].info).tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
        char *t = novo_temp(t_res);
        char *e1 = (yyvsp[-2].info).temp, *e2 = (yyvsp[0].info).temp;
        if (t_res == T_FLOAT && (yyvsp[-2].info).tipo_val == T_INT) e1 = gerar_cast((yyvsp[-2].info).temp, T_FLOAT);
        if (t_res == T_FLOAT && (yyvsp[0].info).tipo_val == T_INT) e2 = gerar_cast((yyvsp[0].info).temp, T_FLOAT);
        sprintf(buf, "%s = %s + %s;\n", t, e1, e2);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t;
        (yyval.info).tipo_val = t_res;
        char *c_out = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 10);
        sprintf(c_out, "%s + %s", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
        (yyval.info).c_expr = c_out;
    }
#line 2263 "sin.tab.c"
    break;

  case 73: /* expressao: expressao '-' expressao  */
#line 701 "sin.y"
                              {
        int t_res = ((yyvsp[-2].info).tipo_val == T_FLOAT || (yyvsp[0].info).tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
        char *t = novo_temp(t_res);
        char *e1 = (yyvsp[-2].info).temp, *e2 = (yyvsp[0].info).temp;
        if (t_res == T_FLOAT && (yyvsp[-2].info).tipo_val == T_INT) e1 = gerar_cast((yyvsp[-2].info).temp, T_FLOAT);
        if (t_res == T_FLOAT && (yyvsp[0].info).tipo_val == T_INT) e2 = gerar_cast((yyvsp[0].info).temp, T_FLOAT);
        sprintf(buf, "%s = %s - %s;\n", t, e1, e2);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t;
        (yyval.info).tipo_val = t_res;
        char *c_out = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 10);
        sprintf(c_out, "%s - %s", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
        (yyval.info).c_expr = c_out;
    }
#line 2282 "sin.tab.c"
    break;

  case 74: /* expressao: expressao '*' expressao  */
#line 715 "sin.y"
                              {
        int t_res = ((yyvsp[-2].info).tipo_val == T_FLOAT || (yyvsp[0].info).tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
        char *t = novo_temp(t_res);
        char *e1 = (yyvsp[-2].info).temp, *e2 = (yyvsp[0].info).temp;
        if (t_res == T_FLOAT && (yyvsp[-2].info).tipo_val == T_INT) e1 = gerar_cast((yyvsp[-2].info).temp, T_FLOAT);
        if (t_res == T_FLOAT && (yyvsp[0].info).tipo_val == T_INT) e2 = gerar_cast((yyvsp[0].info).temp, T_FLOAT);
        sprintf(buf, "%s = %s * %s;\n", t, e1, e2);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t;
        (yyval.info).tipo_val = t_res;
        char *c_out = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 10);
        sprintf(c_out, "%s * %s", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
        (yyval.info).c_expr = c_out;
    }
#line 2301 "sin.tab.c"
    break;

  case 75: /* expressao: expressao '/' expressao  */
#line 729 "sin.y"
                              {
        int t_res = ((yyvsp[-2].info).tipo_val == T_FLOAT || (yyvsp[0].info).tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
        char *t = novo_temp(t_res);
        char *e1 = (yyvsp[-2].info).temp, *e2 = (yyvsp[0].info).temp;
        if (t_res == T_FLOAT && (yyvsp[-2].info).tipo_val == T_INT) e1 = gerar_cast((yyvsp[-2].info).temp, T_FLOAT);
        if (t_res == T_FLOAT && (yyvsp[0].info).tipo_val == T_INT) e2 = gerar_cast((yyvsp[0].info).temp, T_FLOAT);
        sprintf(buf, "%s = %s / %s;\n", t, e1, e2);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t;
        (yyval.info).tipo_val = t_res;
        char *c_out = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 10);
        sprintf(c_out, "%s / %s", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
        (yyval.info).c_expr = c_out;
    }
#line 2320 "sin.tab.c"
    break;

  case 76: /* expressao: expressao LE expressao  */
#line 743 "sin.y"
                             {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s <= %s;\n", t, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t; (yyval.info).tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 10);
        sprintf(c_out, "%s <= %s", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr); (yyval.info).c_expr = c_out;
    }
#line 2333 "sin.tab.c"
    break;

  case 77: /* expressao: expressao GE expressao  */
#line 751 "sin.y"
                             {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s >= %s;\n", t, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t; (yyval.info).tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 10);
        sprintf(c_out, "%s >= %s", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr); (yyval.info).c_expr = c_out;
    }
#line 2346 "sin.tab.c"
    break;

  case 78: /* expressao: expressao EQ expressao  */
#line 759 "sin.y"
                             {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s == %s;\n", t, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t; (yyval.info).tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 10);
        sprintf(c_out, "%s == %s", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr); (yyval.info).c_expr = c_out;
    }
#line 2359 "sin.tab.c"
    break;

  case 79: /* expressao: expressao NE expressao  */
#line 767 "sin.y"
                             {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s != %s;\n", t, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t; (yyval.info).tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 10);
        sprintf(c_out, "%s != %s", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr); (yyval.info).c_expr = c_out;
    }
#line 2372 "sin.tab.c"
    break;

  case 80: /* expressao: expressao '<' expressao  */
#line 775 "sin.y"
                              {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s < %s;\n", t, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t; (yyval.info).tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 10);
        sprintf(c_out, "%s < %s", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr); (yyval.info).c_expr = c_out;
    }
#line 2385 "sin.tab.c"
    break;

  case 81: /* expressao: expressao '>' expressao  */
#line 783 "sin.y"
                              {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s > %s;\n", t, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t; (yyval.info).tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 10);
        sprintf(c_out, "%s > %s", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr); (yyval.info).c_expr = c_out;
    }
#line 2398 "sin.tab.c"
    break;

  case 82: /* expressao: expressao AND expressao  */
#line 791 "sin.y"
                              {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s && %s;\n", t, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t; (yyval.info).tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 10);
        sprintf(c_out, "%s && %s", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr); (yyval.info).c_expr = c_out;
    }
#line 2411 "sin.tab.c"
    break;

  case 83: /* expressao: expressao OR expressao  */
#line 799 "sin.y"
                             {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s || %s;\n", t, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t; (yyval.info).tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 10);
        sprintf(c_out, "%s || %s", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr); (yyval.info).c_expr = c_out;
    }
#line 2424 "sin.tab.c"
    break;

  case 84: /* expressao: NOT expressao  */
#line 807 "sin.y"
                    {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = !%s;\n", t, (yyvsp[0].info).temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t; (yyval.info).tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen((yyvsp[0].info).c_expr) + 5);
        sprintf(c_out, "!%s", (yyvsp[0].info).c_expr); (yyval.info).c_expr = c_out;
    }
#line 2437 "sin.tab.c"
    break;

  case 85: /* expressao: '-' expressao  */
#line 816 "sin.y"
                               {
        char *t = novo_temp((yyvsp[0].info).tipo_val);
        sprintf(buf, "%s = -%s;\n", t, (yyvsp[0].info).temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t; (yyval.info).tipo_val = (yyvsp[0].info).tipo_val;
        char *c_out = (char*) malloc(strlen((yyvsp[0].info).c_expr) + 5);
        sprintf(c_out, "-%s", (yyvsp[0].info).c_expr); (yyval.info).c_expr = c_out;
    }
#line 2450 "sin.tab.c"
    break;

  case 86: /* expressao: '(' tipo ')' expressao  */
#line 825 "sin.y"
                                      {
        char *t = novo_temp((yyvsp[-2].info).tipo_val);
        const char* s_tipo = ((yyvsp[-2].info).tipo_val == T_FLOAT) ? "float" : "int";
        sprintf(buf, "%s = (%s) %s;\n", t, s_tipo, (yyvsp[0].info).temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t; (yyval.info).tipo_val = (yyvsp[-2].info).tipo_val;
        char *c_out = (char*) malloc(strlen((yyvsp[0].info).c_expr) + 20);
        sprintf(c_out, "(%s)(%s)", s_tipo, (yyvsp[0].info).c_expr);
        (yyval.info).c_expr = c_out;
    }
#line 2465 "sin.tab.c"
    break;

  case 87: /* expressao: termo  */
#line 835 "sin.y"
            { (yyval.info) = (yyvsp[0].info); }
#line 2471 "sin.tab.c"
    break;

  case 88: /* termo: fator  */
#line 839 "sin.y"
            { (yyval.info) = (yyvsp[0].info); }
#line 2477 "sin.tab.c"
    break;

  case 89: /* fator: ID  */
#line 843 "sin.y"
         {
        Simbolo *s = buscar((yyvsp[0].valor_str));
        if (s == NULL) {
            yyerror("Erro Semantico: Variavel nao declarada.");
            (yyval.info).temp = strdup("0"); (yyval.info).tipo_val = T_INT; (yyval.info).c_expr = strdup("0");
        } else {
            (yyval.info).temp = s->temp;
            (yyval.info).tipo_val = s->tipo; (yyval.info).c_expr = s->nome;
        }
    }
#line 2492 "sin.tab.c"
    break;

  case 90: /* fator: NUM_INT  */
#line 854 "sin.y"
            {
        char *t = novo_temp(T_INT);
        sprintf(buf, "%s = %s;\n", t, (yyvsp[0].valor_str));
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t; (yyval.info).tipo_val = T_INT; (yyval.info).c_expr = (yyvsp[0].valor_str);
    }
#line 2503 "sin.tab.c"
    break;

  case 91: /* fator: NUM_FLOAT  */
#line 861 "sin.y"
              {
        char *t = novo_temp(T_FLOAT);
        sprintf(buf, "%s = %s;\n", t, (yyvsp[0].valor_str));
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t; (yyval.info).tipo_val = T_FLOAT; (yyval.info).c_expr = (yyvsp[0].valor_str);
    }
#line 2514 "sin.tab.c"
    break;

  case 92: /* fator: CHAR_LIT  */
#line 868 "sin.y"
             {
        char *t = novo_temp(T_CHAR);
        sprintf(buf, "%s = %s;\n", t, (yyvsp[0].valor_str));
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t; (yyval.info).tipo_val = T_CHAR; (yyval.info).c_expr = (yyvsp[0].valor_str);
    }
#line 2525 "sin.tab.c"
    break;

  case 93: /* fator: STRING_LIT  */
#line 875 "sin.y"
               {
        int tam = strlen((yyvsp[0].valor_str)) - 2 + 1; // desconta aspas e conta \0
        char *t = novo_temp_str(tam);
        sprintf(buf, "strcpy(%s, %s);\n", t, (yyvsp[0].valor_str));
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t; (yyval.info).tipo_val = T_STRING; (yyval.info).c_expr = (yyvsp[0].valor_str);
    }
#line 2537 "sin.tab.c"
    break;

  case 94: /* fator: BOOL_LIT  */
#line 882 "sin.y"
               {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s;\n", t, strcmp((yyvsp[0].valor_str),"true")==0 ? "1" : "0");
        adicionar_instrucao(buf); // Alterado (Item 7)
        (yyval.info).temp = t; (yyval.info).tipo_val = T_BOOL;
        (yyval.info).c_expr = strcmp((yyvsp[0].valor_str),"true")==0 ? "true" : "false";
    }
#line 2549 "sin.tab.c"
    break;

  case 95: /* fator: '(' expressao ')'  */
#line 890 "sin.y"
                      {
        (yyval.info).temp = (yyvsp[-1].info).temp; (yyval.info).tipo_val = (yyvsp[-1].info).tipo_val;
        char *c_out = (char*) malloc(strlen((yyvsp[-1].info).c_expr) + 5);
        sprintf(c_out, "(%s)", (yyvsp[-1].info).c_expr); (yyval.info).c_expr = c_out;
    }
#line 2559 "sin.tab.c"
    break;

  case 96: /* fator: ID '[' expressao ']'  */
#line 896 "sin.y"
                         {
        Simbolo *s = buscar((yyvsp[-3].valor_str));
        if (s == NULL) {
            yyerror("Erro Semantico: Matriz nao declarada.");
            (yyval.info).temp = strdup("0"); (yyval.info).tipo_val = T_INT; (yyval.info).c_expr = strdup("0");
        } else if (!s->array) {
            yyerror("Erro Semantico: O identificador nao eh uma matriz.");
            (yyval.info).temp = strdup("0"); (yyval.info).tipo_val = T_INT; (yyval.info).c_expr = strdup("0");
        } else {
            char *t = novo_temp(s->tipo);
            sprintf(buf, "%s = %s[%s];\n", t, s->temp, (yyvsp[-1].info).temp);
            adicionar_instrucao(buf); // Alterado (Item 7)
            (yyval.info).temp = t; (yyval.info).tipo_val = s->tipo;
            char *c_out = (char*) malloc(strlen(s->nome) + strlen((yyvsp[-1].info).c_expr) + 5);
            sprintf(c_out, "%s[%s]", s->nome, (yyvsp[-1].info).c_expr); (yyval.info).c_expr = c_out;
        }
    }
#line 2581 "sin.tab.c"
    break;

  case 97: /* fator: ID '(' chamada_argumentos ')'  */
#line 913 "sin.y"
                                    {
        // Regra para Chamada de Funções como Expressões
        Simbolo *s = buscar((yyvsp[-3].valor_str));
        if (s == NULL || !s->eh_funcao) {
            yyerror("Erro Semantico: Funcao nao declarada.");
            (yyval.info).temp = strdup("0"); (yyval.info).tipo_val = T_INT; (yyval.info).c_expr = strdup("0");
        } else {
            char *t = novo_temp(s->tipo);
            (yyval.info).temp = t;
            (yyval.info).tipo_val = s->tipo;
            
            // Mensagem de log para verificar resolução de nomes de funções (Item 9)
            printf("FUNCAO CHAMADA: %s\n", s->temp);

            // Grava no Código Intermediário de 3 Endereços (TAC)
            sprintf(buf, "%s = %s(%s);\n", t, s->temp, (yyvsp[-1].info).temp);
            adicionar_instrucao(buf); // Alterado (Item 7)
            
            // Grava na expressão traduzida de C
            char *c_out = (char*) malloc(strlen(s->nome) + strlen((yyvsp[-1].info).c_expr) + 5);
            sprintf(c_out, "%s(%s)", s->nome, (yyvsp[-1].info).c_expr);
            (yyval.info).c_expr = c_out;
        }
    }
#line 2610 "sin.tab.c"
    break;

  case 98: /* chamada_argumentos: chamada_argumentos_lista  */
#line 940 "sin.y"
                               { (yyval.info) = (yyvsp[0].info); }
#line 2616 "sin.tab.c"
    break;

  case 99: /* chamada_argumentos: %empty  */
#line 942 "sin.y"
                { (yyval.info).temp = strdup(""); (yyval.info).c_expr = strdup(""); }
#line 2622 "sin.tab.c"
    break;

  case 100: /* chamada_argumentos_lista: expressao  */
#line 946 "sin.y"
                { 
        (yyval.info).temp = strdup((yyvsp[0].info).temp);
        (yyval.info).c_expr = strdup((yyvsp[0].info).c_expr); 
    }
#line 2631 "sin.tab.c"
    break;

  case 101: /* chamada_argumentos_lista: expressao ',' chamada_argumentos_lista  */
#line 950 "sin.y"
                                             {
        char *t_buf = (char*) malloc(strlen((yyvsp[-2].info).temp) + strlen((yyvsp[0].info).temp) + 5);
        char *c_buf = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 5);
        sprintf(t_buf, "%s, %s", (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
        sprintf(c_buf, "%s, %s", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
        (yyval.info).temp = t_buf;
        (yyval.info).c_expr = c_buf;
    }
#line 2644 "sin.tab.c"
    break;


#line 2648 "sin.tab.c"

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

#line 960 "sin.y"


#include <stdlib.h> // Necessário para a função system()

int main() {
    yyparse();
    if (houve_erro) {
        return 1;
    }

    gerar_declaracoes_finais();

    /* 1. VISUALIZAÇÃO DO CÓDIGO INTERMEDIÁRIO (Terminal) */
    printf("#include <stdio.h>\n");
    printf("#include <stdlib.h>\n");
    printf("#include <string.h>\n");
    printf("#include <stdbool.h>\n\n");

    // Imprime definições de funções globais fora da main no terminal
    printf("%s", c_code_body);

    printf("int main()\n");
    printf("{\n");
    printf("%s\n", declaracoes);
    printf("%s", instrucoes);
    printf("    return 0;\n");
    printf("}\n");

    /* 2. GERAÇÃO DO CÓDIGO (Arquivo saida.c) */
    FILE *arquivo_c = fopen("saida.c", "w");
    if (!arquivo_c) {
        printf("Erro: Nao foi possivel criar o arquivo saida.c\n");
        return 1;
    }

    fprintf(arquivo_c, "#include <stdio.h>\n");
    fprintf(arquivo_c, "#include <stdlib.h>\n");
    fprintf(arquivo_c, "#include <string.h>\n");
    fprintf(arquivo_c, "#include <stdbool.h>\n\n");

    /* Declaracoes de temporarios */
    fprintf(arquivo_c, "%s\n", c_code_decl);

    /* Funcoes geradas */
    fprintf(arquivo_c, "%s", c_code_body);

    fprintf(arquivo_c, "int main()\n");
    fprintf(arquivo_c, "{\n");

    /* Codigo intermediario da main */
    fprintf(arquivo_c, "%s", declaracoes);
    fprintf(arquivo_c, "%s", instrucoes);

    /* TEMPORARIAMENTE COMENTADO PARA TESTE */
    /* fprintf(arquivo_c, "%s", c_body); */

    fprintf(arquivo_c, "    return 0;\n");
    fprintf(arquivo_c, "}\n");

    fclose(arquivo_c);
    return 0;
    }
