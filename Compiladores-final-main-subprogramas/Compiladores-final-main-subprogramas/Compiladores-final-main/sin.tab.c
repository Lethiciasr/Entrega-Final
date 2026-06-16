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

#line 110 "sin.tab.c"

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
  YYSYMBOL_TOKEN_FOR = 3,                  /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_MAIN = 4,                 /* TOKEN_MAIN  */
  YYSYMBOL_TOKEN_RETURN = 5,               /* TOKEN_RETURN  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_NUM_INT = 7,                    /* NUM_INT  */
  YYSYMBOL_NUM_FLOAT = 8,                  /* NUM_FLOAT  */
  YYSYMBOL_CHAR_LIT = 9,                   /* CHAR_LIT  */
  YYSYMBOL_BOOL_LIT = 10,                  /* BOOL_LIT  */
  YYSYMBOL_STRING_LIT = 11,                /* STRING_LIT  */
  YYSYMBOL_TOKEN_INT = 12,                 /* TOKEN_INT  */
  YYSYMBOL_TOKEN_FLOAT = 13,               /* TOKEN_FLOAT  */
  YYSYMBOL_TOKEN_CHAR = 14,                /* TOKEN_CHAR  */
  YYSYMBOL_TOKEN_BOOL = 15,                /* TOKEN_BOOL  */
  YYSYMBOL_TOKEN_STRING = 16,              /* TOKEN_STRING  */
  YYSYMBOL_ASSIGN = 17,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 18,                      /* PLUS  */
  YYSYMBOL_TOKEN_PRINT = 19,               /* TOKEN_PRINT  */
  YYSYMBOL_TOKEN_READ = 20,                /* TOKEN_READ  */
  YYSYMBOL_TOKEN_IF = 21,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 22,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_WHILE = 23,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_DO = 24,                  /* TOKEN_DO  */
  YYSYMBOL_TOKEN_SWITCH = 25,              /* TOKEN_SWITCH  */
  YYSYMBOL_TOKEN_CASE = 26,                /* TOKEN_CASE  */
  YYSYMBOL_TOKEN_DEFAULT = 27,             /* TOKEN_DEFAULT  */
  YYSYMBOL_TOKEN_BREAK = 28,               /* TOKEN_BREAK  */
  YYSYMBOL_TOKEN_CONTINUE = 29,            /* TOKEN_CONTINUE  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_EQ = 32,                        /* EQ  */
  YYSYMBOL_NE = 33,                        /* NE  */
  YYSYMBOL_LE = 34,                        /* LE  */
  YYSYMBOL_GE = 35,                        /* GE  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_PLUS_ASSIGN = 37,               /* PLUS_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 38,              /* MINUS_ASSIGN  */
  YYSYMBOL_MULT_ASSIGN = 39,               /* MULT_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 40,                /* DIV_ASSIGN  */
  YYSYMBOL_INC = 41,                       /* INC  */
  YYSYMBOL_DEC = 42,                       /* DEC  */
  YYSYMBOL_43_ = 43,                       /* '<'  */
  YYSYMBOL_44_ = 44,                       /* '>'  */
  YYSYMBOL_45_ = 45,                       /* '-'  */
  YYSYMBOL_46_ = 46,                       /* '*'  */
  YYSYMBOL_47_ = 47,                       /* '/'  */
  YYSYMBOL_CAST = 48,                      /* CAST  */
  YYSYMBOL_UMINUS = 49,                    /* UMINUS  */
  YYSYMBOL_50_ = 50,                       /* '('  */
  YYSYMBOL_51_ = 51,                       /* ')'  */
  YYSYMBOL_52_ = 52,                       /* ';'  */
  YYSYMBOL_53_ = 53,                       /* '{'  */
  YYSYMBOL_54_ = 54,                       /* '}'  */
  YYSYMBOL_55_ = 55,                       /* ','  */
  YYSYMBOL_56_ = 56,                       /* ':'  */
  YYSYMBOL_57_ = 57,                       /* '['  */
  YYSYMBOL_58_ = 58,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_programa = 60,                  /* programa  */
  YYSYMBOL_elementos_globais = 61,         /* elementos_globais  */
  YYSYMBOL_tipo = 62,                      /* tipo  */
  YYSYMBOL_funcao = 63,                    /* funcao  */
  YYSYMBOL_64_1 = 64,                      /* $@1  */
  YYSYMBOL_bloco_funcao = 65,              /* bloco_funcao  */
  YYSYMBOL_parametros_opc = 66,            /* parametros_opc  */
  YYSYMBOL_parametros_lista = 67,          /* parametros_lista  */
  YYSYMBOL_bloco = 68,                     /* bloco  */
  YYSYMBOL_69_2 = 69,                      /* $@2  */
  YYSYMBOL_comandos_bloco = 70,            /* comandos_bloco  */
  YYSYMBOL_if_cond = 71,                   /* if_cond  */
  YYSYMBOL_for_init = 72,                  /* for_init  */
  YYSYMBOL_incremento_for = 73,            /* incremento_for  */
  YYSYMBOL_casos_lista = 74,               /* casos_lista  */
  YYSYMBOL_caso = 75,                      /* caso  */
  YYSYMBOL_76_3 = 76,                      /* @3  */
  YYSYMBOL_default_caso = 77,              /* default_caso  */
  YYSYMBOL_78_4 = 78,                      /* $@4  */
  YYSYMBOL_comando = 79,                   /* comando  */
  YYSYMBOL_80_5 = 80,                      /* @5  */
  YYSYMBOL_81_6 = 81,                      /* @6  */
  YYSYMBOL_82_7 = 82,                      /* @7  */
  YYSYMBOL_83_8 = 83,                      /* @8  */
  YYSYMBOL_84_9 = 84,                      /* @9  */
  YYSYMBOL_85_10 = 85,                     /* @10  */
  YYSYMBOL_86_11 = 86,                     /* $@11  */
  YYSYMBOL_declaracao = 87,                /* declaracao  */
  YYSYMBOL_88_12 = 88,                     /* $@12  */
  YYSYMBOL_lista_inicializadores = 89,     /* lista_inicializadores  */
  YYSYMBOL_elemento_inicializador = 90,    /* elemento_inicializador  */
  YYSYMBOL_atribuicao = 91,                /* atribuicao  */
  YYSYMBOL_expressao = 92,                 /* expressao  */
  YYSYMBOL_termo = 93,                     /* termo  */
  YYSYMBOL_fator = 94,                     /* fator  */
  YYSYMBOL_chamada_argumentos = 95,        /* chamada_argumentos  */
  YYSYMBOL_chamada_argumentos_lista = 96   /* chamada_argumentos_lista  */
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

#if 1

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
#endif /* 1 */

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
#define YYLAST   245

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      50,    51,    46,     2,    55,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    52,
      43,     2,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    86,    86,    92,    93,    94,    98,    99,   100,   101,
     102,   106,   106,   122,   130,   131,   135,   145,   161,   161,
     169,   174,   177,   193,   208,   220,   232,   246,   247,   248,
     251,   251,   273,   273,   279,   280,   281,   282,   283,   290,
     303,   325,   332,   332,   346,   352,   346,   374,   374,   388,
     395,   388,   420,   420,   437,   449,   458,   472,   486,   500,
     514,   525,   536,   550,   558,   566,   570,   570,   580,   581,
     585,   599,   613,   620,   627,   634,   641,   645,   649,   659,
     666,   669,   680,   681,   685,   686
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_FOR",
  "TOKEN_MAIN", "TOKEN_RETURN", "ID", "NUM_INT", "NUM_FLOAT", "CHAR_LIT",
  "BOOL_LIT", "STRING_LIT", "TOKEN_INT", "TOKEN_FLOAT", "TOKEN_CHAR",
  "TOKEN_BOOL", "TOKEN_STRING", "ASSIGN", "PLUS", "TOKEN_PRINT",
  "TOKEN_READ", "TOKEN_IF", "TOKEN_ELSE", "TOKEN_WHILE", "TOKEN_DO",
  "TOKEN_SWITCH", "TOKEN_CASE", "TOKEN_DEFAULT", "TOKEN_BREAK",
  "TOKEN_CONTINUE", "AND", "OR", "EQ", "NE", "LE", "GE", "NOT",
  "PLUS_ASSIGN", "MINUS_ASSIGN", "MULT_ASSIGN", "DIV_ASSIGN", "INC", "DEC",
  "'<'", "'>'", "'-'", "'*'", "'/'", "CAST", "UMINUS", "'('", "')'", "';'",
  "'{'", "'}'", "','", "':'", "'['", "']'", "$accept", "programa",
  "elementos_globais", "tipo", "funcao", "$@1", "bloco_funcao",
  "parametros_opc", "parametros_lista", "bloco", "$@2", "comandos_bloco",
  "if_cond", "for_init", "incremento_for", "casos_lista", "caso", "@3",
  "default_caso", "$@4", "comando", "@5", "@6", "@7", "@8", "@9", "@10",
  "$@11", "declaracao", "$@12", "lista_inicializadores",
  "elemento_inicializador", "atribuicao", "expressao", "termo", "fator",
  "chamada_argumentos", "chamada_argumentos_lista", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,   -70,   -70,   -70,   -70,   -70,     6,    28,    12,    -1,
     -10,   -70,    -6,    14,   -70,    -1,    -5,    -3,    -1,    51,
     -70,    27,    -2,   -70,    -3,    15,   -70,   -70,    73,    30,
     -70,    31,   -70,   -70,    -3,   157,    -3,    -3,    -3,    -3,
      42,   -70,    76,   131,    41,    47,   -70,   -70,   -23,   -23,
     -70,   -70,    -1,    46,    58,    50,    -3,    13,    54,    59,
      62,   -70,   -70,    64,    66,    75,   111,   -70,    71,   131,
     131,    80,    81,    56,    -3,   -70,   -70,   131,   -70,   -70,
     134,    74,    -3,    -3,    -3,    -3,    -3,    89,    97,    -3,
      -3,   147,    -3,   107,   131,    -3,   -70,   -70,   -12,   -70,
     142,   -70,   -70,   -70,   -70,   -70,   108,    -3,   148,   122,
     -70,    15,    77,   121,   124,   140,   -70,   -70,    -9,   164,
     126,   173,    -3,   155,   176,   -70,   -70,   125,   128,    15,
      -3,   -70,   -70,   -70,   -70,   -70,   163,   141,   144,   -70,
     187,   166,   -70,   131,   -70,    -3,    15,    -3,    -3,   -70,
     -70,   -70,    -3,   145,   -70,   -70,   143,   154,   131,   194,
       2,   -70,   -70,   -70,   161,    -3,   151,   160,     2,   -70,
     191,   -70,    38,   -70,   -70,   -70,    65,   174,   -70,   131,
      -3,   -70,   -70,   131,   131,   -70,    15,   -70,   -70
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     6,     7,     8,     9,    10,     0,     0,     0,     5,
       0,     1,     0,    63,     4,     5,     0,     0,    15,     0,
       3,     0,    78,    79,     0,    64,    76,    77,     0,     0,
      14,     0,    18,     2,    83,     0,     0,     0,     0,     0,
      16,    11,    65,    21,    84,     0,    82,    80,    72,    73,
      74,    75,     0,     0,     0,     0,     0,    78,     0,     0,
       0,    44,    47,     0,     0,     0,     0,    37,     0,     0,
      21,     0,     0,     0,     0,    81,    17,    21,    12,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    55,    63,    19,
      41,    20,    34,    35,    36,    85,     0,     0,     0,     0,
      38,    71,     0,     0,     0,     0,    60,    61,     0,     0,
       0,     0,     0,     0,     0,    42,    13,     0,    69,    70,
       0,    49,    56,    57,    58,    59,     0,     0,     0,    22,
       0,     0,    52,     0,    67,     0,    23,     0,     0,    39,
      40,    45,     0,     0,    43,    68,     0,     0,     0,     0,
      29,    50,    62,    46,     0,     0,     0,     0,    29,    28,
       0,    48,     0,    32,    53,    27,     0,     0,    30,    21,
       0,    25,    26,     0,    21,    33,    24,    51,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,     1,    25,   -70,   -70,   -70,   -70,   165,   205,
     -70,   -69,   -70,   -70,   -70,    60,   -70,   -70,   -70,   -70,
     -67,   -70,   -70,   -70,   -70,   -70,   -70,   -70,    26,   -70,
      84,   -70,   -70,   -17,   -70,   -70,   -70,   156
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,    66,     9,    53,    78,    29,    30,    67,
      43,    68,    69,   109,   177,   167,   168,   184,   169,   179,
      70,   143,    93,   158,    94,   147,   170,   153,    71,   107,
     127,   128,    72,    73,    26,    27,    45,    46
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      25,   101,   100,    22,    23,    17,    11,    35,   106,    36,
      14,     1,     2,     3,     4,     5,    20,    44,    13,    48,
      49,    50,    51,    38,    39,     8,    10,   123,   165,   166,
      82,    17,    12,    36,     8,    10,    37,    38,    39,    81,
       8,    10,    15,    28,    16,    19,    21,    24,    34,   136,
      83,    84,    85,    86,    87,    88,    36,    44,    31,    36,
      37,    38,    39,    34,    18,   111,   112,   113,   114,   115,
      89,    19,   118,   119,    36,   121,   154,    28,   124,    40,
      32,    41,   180,    37,    38,    39,    37,    38,    39,    42,
     129,   163,    36,    54,   178,    36,    74,    52,    75,    77,
      80,    37,    38,    39,    90,   140,   181,   182,   104,    91,
     185,    79,    92,   146,    95,   188,   187,    98,    96,    37,
      38,    39,    37,    38,    39,    99,   110,    97,   129,   132,
     156,   157,   102,   103,    55,   159,    56,    57,    23,    36,
     108,   116,    36,     1,     2,     3,     4,     5,   172,   117,
      58,    59,    60,   120,    61,    62,    63,   122,    36,    64,
      65,    36,   126,   186,   125,   130,    37,    38,    39,    37,
      38,    39,    36,   133,   131,    36,   134,   138,   141,   144,
     148,    24,    36,   145,    32,    37,    38,    39,    37,    38,
      39,    36,   135,   149,    36,   161,   150,   176,   160,    37,
      38,    39,    37,    38,    39,    36,   162,   173,    47,    37,
      38,    39,    36,   171,   174,   137,   152,    76,    37,    38,
      39,    37,    38,    39,   139,   183,    33,   142,   175,   155,
     105,     0,    37,    38,    39,     0,     0,     0,   151,    37,
      38,    39,     0,     0,     0,   164
};

static const yytype_int16 yycheck[] =
{
      17,    70,    69,     6,     7,    17,     0,    24,    77,    18,
       9,    12,    13,    14,    15,    16,    15,    34,     6,    36,
      37,    38,    39,    46,    47,     0,     0,    94,    26,    27,
      17,    17,     4,    18,     9,     9,    45,    46,    47,    56,
      15,    15,    52,    18,    50,    57,    51,    50,    50,    58,
      37,    38,    39,    40,    41,    42,    18,    74,     7,    18,
      45,    46,    47,    50,    50,    82,    83,    84,    85,    86,
      57,    57,    89,    90,    18,    92,   143,    52,    95,     6,
      53,    51,    17,    45,    46,    47,    45,    46,    47,    58,
     107,   158,    18,    17,    56,    18,    55,    55,    51,    53,
      50,    45,    46,    47,    50,   122,    41,    42,    52,    50,
     179,    53,    50,   130,    50,   184,   183,     6,    52,    45,
      46,    47,    45,    46,    47,    54,    52,    52,   145,    52,
     147,   148,    52,    52,     3,   152,     5,     6,     7,    18,
       6,    52,    18,    12,    13,    14,    15,    16,   165,    52,
      19,    20,    21,     6,    23,    24,    25,    50,    18,    28,
      29,    18,    54,   180,    22,    17,    45,    46,    47,    45,
      46,    47,    18,    52,    52,    18,    52,    51,    23,    54,
      17,    50,    18,    55,    53,    45,    46,    47,    45,    46,
      47,    18,    52,    52,    18,    52,    52,     6,    53,    45,
      46,    47,    45,    46,    47,    18,    52,    56,    51,    45,
      46,    47,    18,    52,    54,    51,    50,    52,    45,    46,
      47,    45,    46,    47,    51,    51,    21,    51,   168,   145,
      74,    -1,    45,    46,    47,    -1,    -1,    -1,    51,    45,
      46,    47,    -1,    -1,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    13,    14,    15,    16,    60,    61,    62,    63,
      87,     0,     4,     6,    61,    52,    50,    17,    50,    57,
      61,    51,     6,     7,    50,    92,    93,    94,    62,    66,
      67,     7,    53,    68,    50,    92,    18,    45,    46,    47,
       6,    51,    58,    69,    92,    95,    96,    51,    92,    92,
      92,    92,    55,    64,    17,     3,     5,     6,    19,    20,
      21,    23,    24,    25,    28,    29,    62,    68,    70,    71,
      79,    87,    91,    92,    55,    51,    67,    53,    65,    53,
      50,    92,    17,    37,    38,    39,    40,    41,    42,    57,
      50,    50,    50,    81,    83,    50,    52,    52,     6,    54,
      79,    70,    52,    52,    52,    96,    70,    88,     6,    72,
      52,    92,    92,    92,    92,    92,    52,    52,    92,    92,
       6,    92,    50,    79,    92,    22,    54,    89,    90,    92,
      17,    52,    52,    52,    52,    52,    58,    51,    51,    51,
      92,    23,    51,    80,    54,    55,    92,    84,    17,    52,
      52,    51,    50,    86,    79,    89,    92,    92,    82,    92,
      53,    52,    52,    79,    51,    26,    27,    74,    75,    77,
      85,    52,    92,    56,    54,    74,     6,    73,    56,    78,
      17,    41,    42,    51,    76,    70,    92,    79,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    61,    61,    62,    62,    62,    62,
      62,    64,    63,    65,    66,    66,    67,    67,    69,    68,
      70,    70,    71,    72,    73,    73,    73,    74,    74,    74,
      76,    75,    78,    77,    79,    79,    79,    79,    79,    79,
      79,    79,    80,    79,    81,    82,    79,    83,    79,    84,
      85,    79,    86,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    87,    87,    87,    88,    87,    89,    89,
      90,    91,    92,    92,    92,    92,    92,    93,    94,    94,
      94,    94,    95,    95,    96,    96
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     2,     0,     1,     1,     1,     1,
       1,     0,     7,     3,     1,     0,     2,     4,     0,     4,
       2,     0,     4,     3,     3,     2,     2,     2,     1,     0,
       0,     5,     0,     4,     2,     2,     2,     1,     3,     5,
       5,     2,     0,     5,     0,     0,     7,     0,     8,     0,
       0,    11,     0,     8,     2,     2,     4,     4,     4,     4,
       3,     3,     7,     2,     4,     5,     0,    10,     3,     1,
       1,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       3,     4,     1,     0,     1,     3
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
#line 86 "sin.y"
                                                 {
        strcat(c_body, (yyvsp[0].info).c_expr);
    }
#line 1602 "sin.tab.c"
    break;

  case 6: /* tipo: TOKEN_INT  */
#line 98 "sin.y"
                   { (yyval.info).tipo_val = T_INT; }
#line 1608 "sin.tab.c"
    break;

  case 7: /* tipo: TOKEN_FLOAT  */
#line 99 "sin.y"
                   { (yyval.info).tipo_val = T_FLOAT; }
#line 1614 "sin.tab.c"
    break;

  case 8: /* tipo: TOKEN_CHAR  */
#line 100 "sin.y"
                   { (yyval.info).tipo_val = T_CHAR; }
#line 1620 "sin.tab.c"
    break;

  case 9: /* tipo: TOKEN_BOOL  */
#line 101 "sin.y"
                   { (yyval.info).tipo_val = T_BOOL; }
#line 1626 "sin.tab.c"
    break;

  case 10: /* tipo: TOKEN_STRING  */
#line 102 "sin.y"
                   { (yyval.info).tipo_val = T_STRING; }
#line 1632 "sin.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 106 "sin.y"
                                     {
        char const* t_nome = ((yyvsp[-4].info).tipo_val == T_INT) ? "int" : 
                             (((yyvsp[-4].info).tipo_val == T_FLOAT) ? "float" : 
                             (((yyvsp[-4].info).tipo_val == T_CHAR) ? "char" : "int"));
                             
        sprintf(buf, "\n%s %s(%s) {\n", t_nome, (yyvsp[-3].valor_str), (yyvsp[-1].lista_params).c_args);
        strcat(c_code_body, buf); 
        
        escopo_atual++; 
    }
#line 1647 "sin.tab.c"
    break;

  case 12: /* funcao: tipo ID '(' parametros_opc ')' $@1 bloco_funcao  */
#line 116 "sin.y"
                 {
        escopo_atual--;
    }
#line 1655 "sin.tab.c"
    break;

  case 13: /* bloco_funcao: '{' comandos_bloco '}'  */
#line 122 "sin.y"
                             {
        strcat(c_code_body, (yyvsp[-1].info).c_expr);
        strcat(c_code_body, "}\n\n");
        remover_simbolos_do_nivel(escopo_atual);
    }
#line 1665 "sin.tab.c"
    break;

  case 14: /* parametros_opc: parametros_lista  */
#line 130 "sin.y"
                       { (yyval.lista_params) = (yyvsp[0].lista_params); }
#line 1671 "sin.tab.c"
    break;

  case 15: /* parametros_opc: %empty  */
#line 131 "sin.y"
                       { (yyval.lista_params).qtd = 0; (yyval.lista_params).c_args = strdup(""); }
#line 1677 "sin.tab.c"
    break;

  case 16: /* parametros_lista: tipo ID  */
#line 135 "sin.y"
              {
        (yyval.lista_params).qtd = 1;
        (yyval.lista_params).tipos[0] = (yyvsp[-1].info).tipo_val;
        char temp_arg[100];
        char const* t_nome = ((yyvsp[-1].info).tipo_val == T_INT) ? "int" : (((yyvsp[-1].info).tipo_val == T_FLOAT) ? "float" : "char");
        
        Simbolo* s = inserir((yyvsp[0].valor_str), (yyvsp[-1].info).tipo_val, escopo_atual + 1);
        sprintf(temp_arg, "%s %s", t_nome, s->temp);
        (yyval.lista_params).c_args = strdup(temp_arg);
    }
#line 1692 "sin.tab.c"
    break;

  case 17: /* parametros_lista: tipo ID ',' parametros_lista  */
#line 145 "sin.y"
                                   {
        (yyval.lista_params).qtd = (yyvsp[0].lista_params).qtd + 1;
        (yyval.lista_params).tipos[0] = (yyvsp[-3].info).tipo_val;
        for(int i = 0; i < (yyvsp[0].lista_params).qtd; i++) {
            (yyval.lista_params).tipos[i+1] = (yyvsp[0].lista_params).tipos[i];
        }
        char temp_arg[400];
        char const* t_nome = ((yyvsp[-3].info).tipo_val == T_INT) ? "int" : (((yyvsp[-3].info).tipo_val == T_FLOAT) ? "float" : "char");
        
        Simbolo* s = inserir((yyvsp[-2].valor_str), (yyvsp[-3].info).tipo_val, escopo_atual + 1);
        sprintf(temp_arg, "%s %s, %s", t_nome, s->temp, (yyvsp[0].lista_params).c_args);
        (yyval.lista_params).c_args = strdup(temp_arg);
    }
#line 1710 "sin.tab.c"
    break;

  case 18: /* $@2: %empty  */
#line 161 "sin.y"
          { escopo_atual++; }
#line 1716 "sin.tab.c"
    break;

  case 19: /* bloco: '{' $@2 comandos_bloco '}'  */
#line 161 "sin.y"
                                                 { 
        remover_simbolos_do_nivel(escopo_atual);
        escopo_atual--; 
        (yyval.info).c_expr = (yyvsp[-1].info).c_expr;
    }
#line 1726 "sin.tab.c"
    break;

  case 20: /* comandos_bloco: comando comandos_bloco  */
#line 169 "sin.y"
                             {
        char *res = (char*) malloc(strlen((yyvsp[-1].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 2);
        sprintf(res, "%s%s", (yyvsp[-1].info).c_expr, (yyvsp[0].info).c_expr);
        (yyval.info).c_expr = res;
    }
#line 1736 "sin.tab.c"
    break;

  case 21: /* comandos_bloco: %empty  */
#line 174 "sin.y"
                  { (yyval.info).c_expr = strdup(""); }
#line 1742 "sin.tab.c"
    break;

  case 22: /* if_cond: TOKEN_IF '(' expressao ')'  */
#line 177 "sin.y"
                                     {
    if ((yyvsp[-1].info).tipo_val != T_BOOL) {
        yyerror("Erro Semantico: A condicao do 'if' deve ser booleana.");
    }
    char* l_false = novo_label();
    char* t_inv = novo_temp(T_BOOL);
    sprintf(buf, "%s = !%s;\n", t_inv, (yyvsp[-1].info).temp);
    strcat(instrucoes, buf);
    sprintf(buf, "if (%s) goto %s;\n", t_inv, l_false);
    strcat(instrucoes, buf);
    strcat(instrucoes, "\n");
    
    (yyval.valor_str) = l_false; 
}
#line 1761 "sin.tab.c"
    break;

  case 23: /* for_init: ID ASSIGN expressao  */
#line 193 "sin.y"
                               {
    Simbolo *s = buscar((yyvsp[-2].valor_str));
    if (!s) {
        yyerror("Erro: Variavel nao declarada na inicializacao do for.");
        (yyval.valor_str) = strdup("");
    } else {
        sprintf(buf, "%s = %s;\n", s->temp, (yyvsp[0].info).temp);
        strcat(instrucoes, buf);
        char* init_str = (char*) malloc(256);
        sprintf(init_str, "%s = %s", s->temp, (yyvsp[0].info).temp);
        (yyval.valor_str) = init_str;
    }
}
#line 1779 "sin.tab.c"
    break;

  case 24: /* incremento_for: ID ASSIGN expressao  */
#line 208 "sin.y"
                                     {
    Simbolo *s = buscar((yyvsp[-2].valor_str));
    if (!s) {
        yyerror("Erro: Variavel nao declarada no incremento do for.");
        (yyval.valor_str) = strdup("");
    } else {
        sprintf(inc_3ac, "%s = %s;\n", s->temp, (yyvsp[0].info).temp);
        char* inc_str = (char*) malloc(256);
        sprintf(inc_str, "%s = %s", s->temp, (yyvsp[0].info).temp);
        (yyval.valor_str) = inc_str;
    }
}
#line 1796 "sin.tab.c"
    break;

  case 25: /* incremento_for: ID INC  */
#line 220 "sin.y"
         {
    Simbolo *s = buscar((yyvsp[-1].valor_str));
    if (!s) {
        yyerror("Erro: Variavel nao declarada no incremento do for.");
        (yyval.valor_str) = strdup("");
    } else {
        sprintf(inc_3ac, "%s = %s + 1;\n", s->temp, s->temp);
        char* inc_str = (char*) malloc(256);
        sprintf(inc_str, "%s++", s->temp);
        (yyval.valor_str) = inc_str;
    }
}
#line 1813 "sin.tab.c"
    break;

  case 26: /* incremento_for: ID DEC  */
#line 232 "sin.y"
         {
    Simbolo *s = buscar((yyvsp[-1].valor_str));
    if (!s) {
        yyerror("Erro: Variavel nao declarada no decremento do for.");
        (yyval.valor_str) = strdup("");
    } else {
        sprintf(inc_3ac, "%s = %s - 1;\n", s->temp, s->temp);
        char* inc_str = (char*) malloc(256);
        sprintf(inc_str, "%s--", s->temp);
        (yyval.valor_str) = inc_str;
    }
}
#line 1830 "sin.tab.c"
    break;

  case 30: /* @3: %empty  */
#line 251 "sin.y"
                                {
        char* l_proximo = novo_label();
        char* t_cmp = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s == %s;\n", t_cmp, switch_exp, (yyvsp[-1].info).temp);
        strcat(instrucoes, buf);
        char* t_inv = novo_temp(T_BOOL);
        sprintf(buf, "%s = !%s;\n", t_inv, t_cmp);
        strcat(instrucoes, buf);
        sprintf(buf, "if (%s) goto %s;\n", t_inv, l_proximo);
        strcat(instrucoes, buf);

        sprintf(buf, "case %s:\n", (yyvsp[-1].info).temp);
        strcat(c_body, buf);
        (yyval.valor_str) = l_proximo;
    }
#line 1850 "sin.tab.c"
    break;

  case 31: /* caso: TOKEN_CASE expressao ':' @3 comandos_bloco  */
#line 265 "sin.y"
                     {
        sprintf(buf, "goto %s;\n", switch_fim);
        strcat(instrucoes, buf);
        sprintf(buf, "%s:\n", (yyvsp[-1].valor_str));
        strcat(instrucoes, buf);
    }
#line 1861 "sin.tab.c"
    break;

  case 32: /* $@4: %empty  */
#line 273 "sin.y"
                                 {
        strcat(c_body, "default:\n");
    }
#line 1869 "sin.tab.c"
    break;

  case 34: /* comando: declaracao ';'  */
#line 279 "sin.y"
                     { (yyval.info) = (yyvsp[-1].info); }
#line 1875 "sin.tab.c"
    break;

  case 35: /* comando: atribuicao ';'  */
#line 280 "sin.y"
                     { (yyval.info) = (yyvsp[-1].info); }
#line 1881 "sin.tab.c"
    break;

  case 36: /* comando: expressao ';'  */
#line 281 "sin.y"
                    { (yyval.info).c_expr = strdup(""); }
#line 1887 "sin.tab.c"
    break;

  case 37: /* comando: bloco  */
#line 282 "sin.y"
            { (yyval.info) = (yyvsp[0].info); }
#line 1893 "sin.tab.c"
    break;

  case 38: /* comando: TOKEN_RETURN expressao ';'  */
#line 283 "sin.y"
                                 {
        char* c_out = (char*) malloc(256);
        sprintf(buf, "return %s;\n", (yyvsp[-1].info).temp);
        strcat(instrucoes, buf);
        sprintf(c_out, "return %s;\n", (yyvsp[-1].info).temp);
        (yyval.info).c_expr = c_out;
    }
#line 1905 "sin.tab.c"
    break;

  case 39: /* comando: TOKEN_PRINT '(' expressao ')' ';'  */
#line 290 "sin.y"
                                        {
        char* c_out = (char*) malloc(256);
        char* formato = "";
        if ((yyvsp[-2].info).tipo_val == T_INT || (yyvsp[-2].info).tipo_val == T_BOOL) formato = "%d";
        else if ((yyvsp[-2].info).tipo_val == T_FLOAT) formato = "%f";
        else if ((yyvsp[-2].info).tipo_val == T_CHAR) formato = "%c";
        else if ((yyvsp[-2].info).tipo_val == T_STRING) formato = "%s";
        
        sprintf(buf, "printf(\"%s\\n\", %s);\n", formato, (yyvsp[-2].info).temp);
        strcat(instrucoes, buf);
        sprintf(c_out, "printf(\"%s\\n\", %s);\n", formato, (yyvsp[-2].info).temp);
        (yyval.info).c_expr = c_out;
    }
#line 1923 "sin.tab.c"
    break;

  case 40: /* comando: TOKEN_READ '(' ID ')' ';'  */
#line 303 "sin.y"
                                {
        char* c_out = (char*) malloc(256);
        Simbolo *s = buscar((yyvsp[-2].valor_str));
        if (!s) {
            yyerror("Erro Semantico: Variavel nao declarada para leitura.");
        } else {
            char* formato = "";
            if (s->tipo == T_INT || s->tipo == T_BOOL) formato = "%d";
            else if (s->tipo == T_FLOAT) formato = "%f";
            else if (s->tipo == T_CHAR) formato = " %c";

            if (s->tipo == T_STRING) {
                sprintf(buf, "scanf(\"%%255s\", %s);\n", s->temp);
                sprintf(c_out, "scanf(\"%%255s\", %s);\n", s->temp);
            } else {
                sprintf(buf, "scanf(\"%s\", &%s);\n", formato, s->temp);
                sprintf(c_out, "scanf(\"%s\", &%s);\n", formato, s->temp);
            }
            strcat(instrucoes, buf);
        }
        (yyval.info).c_expr = c_out;
    }
#line 1950 "sin.tab.c"
    break;

  case 41: /* comando: if_cond comando  */
#line 325 "sin.y"
                      {
        char* c_out = (char*) malloc(1024);
        sprintf(buf, "%s:\n", (yyvsp[-1].valor_str));
        strcat(instrucoes, buf);
        sprintf(c_out, "if (%s) {\n%s}\n", (yyvsp[-1].valor_str), (yyvsp[0].info).c_expr);
        (yyval.info).c_expr = c_out;
    }
#line 1962 "sin.tab.c"
    break;

  case 42: /* @5: %empty  */
#line 332 "sin.y"
                                 {
        char* l_fim = novo_label();
        sprintf(buf, "goto %s;\n", l_fim);
        strcat(instrucoes, buf);
        sprintf(buf, "%s:\n", (yyvsp[-2].valor_str));
        strcat(instrucoes, buf);
        (yyval.valor_str) = l_fim;
    }
#line 1975 "sin.tab.c"
    break;

  case 43: /* comando: if_cond comando TOKEN_ELSE @5 comando  */
#line 339 "sin.y"
              {
        char* c_out = (char*) malloc(2048);
        sprintf(buf, "%s:\n", (yyvsp[-1].valor_str));
        strcat(instrucoes, buf);
        sprintf(c_out, "if (...) {\n%s} else {\n%s}\n", (yyvsp[-3].info).c_expr, (yyvsp[0].info).c_expr);
        (yyval.info).c_expr = c_out;
    }
#line 1987 "sin.tab.c"
    break;

  case 44: /* @6: %empty  */
#line 346 "sin.y"
                  {
        char* l_inicio = novo_label();
        sprintf(buf, "%s:\n", l_inicio);
        strcat(instrucoes, buf);
        (yyval.valor_str) = l_inicio; 
        strcpy(pilha_inicio[topo_laco], l_inicio);
    }
#line 1999 "sin.tab.c"
    break;

  case 45: /* @7: %empty  */
#line 352 "sin.y"
                        {
        if ((yyvsp[-1].info).tipo_val != T_BOOL) yyerror("Erro Semantico: Condicao deve ser booleana.");
        char* l_fim = novo_label();
        char* t_inv = novo_temp(T_BOOL);
        sprintf(buf, "%s = !%s;\n", t_inv, (yyvsp[-1].info).temp);
        strcat(instrucoes, buf);
        sprintf(buf, "if (%s) goto %s;\n", t_inv, l_fim);
        strcat(instrucoes, buf);
        (yyval.valor_str) = l_fim; 
        strcpy(pilha_fim[topo_laco], l_fim);
        topo_laco++;
    }
#line 2016 "sin.tab.c"
    break;

  case 46: /* comando: TOKEN_WHILE @6 '(' expressao ')' @7 comando  */
#line 363 "sin.y"
              { 
        topo_laco--;
        sprintf(buf, "goto %s;\n", pilha_inicio[topo_laco]);
        strcat(instrucoes, buf);
        sprintf(buf, "%s:\n", pilha_fim[topo_laco]);
        strcat(instrucoes, buf);
        
        char* c_out = (char*) malloc(1024);
        sprintf(c_out, "while (%s) {\n%s}\n", (yyvsp[-3].info).temp, (yyvsp[0].info).c_expr);
        (yyval.info).c_expr = c_out;
    }
#line 2032 "sin.tab.c"
    break;

  case 47: /* @8: %empty  */
#line 374 "sin.y"
               {
        char* l_inicio = novo_label();
        sprintf(buf, "%s:\n", l_inicio);
        strcat(instrucoes, buf);
        (yyval.valor_str) = l_inicio;
    }
#line 2043 "sin.tab.c"
    break;

  case 48: /* comando: TOKEN_DO @8 comando TOKEN_WHILE '(' expressao ')' ';'  */
#line 379 "sin.y"
                                                {
        if ((yyvsp[-2].info).tipo_val != T_BOOL) yyerror("Erro Semantico: Condicao do do-while deve ser booleana.");
        sprintf(buf, "if (%s) goto %s;\n", (yyvsp[-2].info).temp, (yyvsp[-6].valor_str));
        strcat(instrucoes, buf);
        
        char* c_out = (char*) malloc(1024);
        sprintf(c_out, "do {\n%s} while (%s);\n", (yyvsp[-5].info).c_expr, (yyvsp[-2].info).temp);
        (yyval.info).c_expr = c_out;
    }
#line 2057 "sin.tab.c"
    break;

  case 49: /* @9: %empty  */
#line 388 "sin.y"
                                 {
        char* l_inicio = novo_label();
        char* l_incremento = novo_label(); 
        sprintf(buf, "%s:\n", l_inicio);
        strcat(instrucoes, buf);
        (yyval.valor_str) = l_inicio; 
        strcpy(pilha_inicio[topo_laco], l_incremento);
    }
#line 2070 "sin.tab.c"
    break;

  case 50: /* @10: %empty  */
#line 395 "sin.y"
                    {
        if ((yyvsp[-1].info).tipo_val != T_BOOL) yyerror("Erro Semantico: Condicao do for deve ser booleana.");
        char* l_fim = novo_label();
        char* t_inv = novo_temp(T_BOOL);
        sprintf(buf, "%s = !%s;\n", t_inv, (yyvsp[-1].info).temp);
        strcat(instrucoes, buf);
        sprintf(buf, "if (%s) goto %s;\n", t_inv, l_fim);
        strcat(instrucoes, buf);
        (yyval.valor_str) = l_fim;
        strcpy(pilha_fim[topo_laco], l_fim);
        topo_laco++;
    }
#line 2087 "sin.tab.c"
    break;

  case 51: /* comando: TOKEN_FOR '(' for_init ';' @9 expressao ';' @10 incremento_for ')' comando  */
#line 406 "sin.y"
                                 {
        topo_laco--; 
        sprintf(buf, "%s:\n", pilha_inicio[topo_laco]);
        strcat(instrucoes, buf);
        strcat(instrucoes, inc_3ac);
        sprintf(buf, "goto %s;\n", (yyvsp[-6].valor_str));
        strcat(instrucoes, buf);
        sprintf(buf, "%s:\n", (yyvsp[-3].valor_str));
        strcat(instrucoes, buf);
        
        char* c_out = (char*) malloc(2048);
        sprintf(c_out, "for (%s; %s; %s) {\n%s}\n", (yyvsp[-8].valor_str), (yyvsp[-5].info).temp, (yyvsp[-2].valor_str), (yyvsp[0].info).c_expr);
        (yyval.info).c_expr = c_out;
    }
#line 2106 "sin.tab.c"
    break;

  case 52: /* $@11: %empty  */
#line 420 "sin.y"
                                     {
        dentro_switch++;
        strcpy(switch_exp, (yyvsp[-1].info).temp);
        strcpy(switch_fim, novo_label());
        strcpy(pilha_fim[topo_laco], switch_fim);
        strcpy(pilha_inicio[topo_laco], "ERRO_CONTINUE_SWITCH");
        topo_laco++;
    }
#line 2119 "sin.tab.c"
    break;

  case 53: /* comando: TOKEN_SWITCH '(' expressao ')' $@11 '{' casos_lista '}'  */
#line 427 "sin.y"
                          {
        dentro_switch--;
        topo_laco--;
        sprintf(buf, "%s:\n", switch_fim);
        strcat(instrucoes, buf);
        
        char* c_out = (char*) malloc(512);
        sprintf(c_out, "switch (%s) { /* ... */ }\n", (yyvsp[-5].info).temp);
        (yyval.info).c_expr = c_out;
    }
#line 2134 "sin.tab.c"
    break;

  case 54: /* comando: TOKEN_BREAK ';'  */
#line 437 "sin.y"
                      {
        if (topo_laco > 0) {
            sprintf(buf, "goto %s;\n", pilha_fim[topo_laco - 1]);
            strcat(instrucoes, buf);
        } else if (dentro_switch > 0) {
            sprintf(buf, "goto %s;\n", switch_fim);
            strcat(instrucoes, buf);
        } else {
            yyerror("Erro Semantico: 'break' usado fora de laco ou switch.");
        }
        (yyval.info).c_expr = strdup("break;\n");
    }
#line 2151 "sin.tab.c"
    break;

  case 55: /* comando: TOKEN_CONTINUE ';'  */
#line 449 "sin.y"
                         {
        if (topo_laco == 0) {
            yyerror("Erro Semantico: 'continue' usado fora de laco.");
        } else {
            sprintf(buf, "goto %s;\n", pilha_inicio[topo_laco - 1]);
            strcat(instrucoes, buf);
        }
        (yyval.info).c_expr = strdup("continue;\n");
    }
#line 2165 "sin.tab.c"
    break;

  case 56: /* comando: ID PLUS_ASSIGN expressao ';'  */
#line 458 "sin.y"
                                   {
        Simbolo *s = buscar((yyvsp[-3].valor_str));
        char* c_out = (char*) malloc(256);
        if (!s) yyerror("Erro Semantico: Variavel nao declarada.");
        else {
            char* t_op = novo_temp(s->tipo);
            sprintf(buf, "%s = %s + %s;\n", t_op, s->temp, (yyvsp[-1].info).temp);
            strcat(instrucoes, buf);
            sprintf(buf, "%s = %s;\n", s->temp, t_op);
            strcat(instrucoes, buf);
            sprintf(c_out, "%s += %s;\n", s->temp, (yyvsp[-1].info).temp);
        }
        (yyval.info).c_expr = c_out;
    }
#line 2184 "sin.tab.c"
    break;

  case 57: /* comando: ID MINUS_ASSIGN expressao ';'  */
#line 472 "sin.y"
                                    {
        Simbolo *s = buscar((yyvsp[-3].valor_str));
        char* c_out = (char*) malloc(256);
        if (!s) yyerror("Erro Semantico: Variavel nao declarada.");
        else {
            char* t_op = novo_temp(s->tipo);
            sprintf(buf, "%s = %s - %s;\n", t_op, s->temp, (yyvsp[-1].info).temp);
            strcat(instrucoes, buf);
            sprintf(buf, "%s = %s;\n", s->temp, t_op);
            strcat(instrucoes, buf);
            sprintf(c_out, "%s -= %s;\n", s->temp, (yyvsp[-1].info).temp);
        }
        (yyval.info).c_expr = c_out;
    }
#line 2203 "sin.tab.c"
    break;

  case 58: /* comando: ID MULT_ASSIGN expressao ';'  */
#line 486 "sin.y"
                                   {
        Simbolo *s = buscar((yyvsp[-3].valor_str));
        char* c_out = (char*) malloc(256);
        if (!s) yyerror("Erro Semantico: Variavel nao declarada.");
        else {
            char* t_op = novo_temp(s->tipo);
            sprintf(buf, "%s = %s * %s;\n", t_op, s->temp, (yyvsp[-1].info).temp);
            strcat(instrucoes, buf);
            sprintf(buf, "%s = %s;\n", s->temp, t_op);
            strcat(instrucoes, buf);
            sprintf(c_out, "%s *= %s;\n", s->temp, (yyvsp[-1].info).temp);
        }
        (yyval.info).c_expr = c_out;
    }
#line 2222 "sin.tab.c"
    break;

  case 59: /* comando: ID DIV_ASSIGN expressao ';'  */
#line 500 "sin.y"
                                  {
        Simbolo *s = buscar((yyvsp[-3].valor_str));
        char* c_out = (char*) malloc(256);
        if (!s) yyerror("Erro Semantico: Variavel nao declarada.");
        else {
            char* t_op = novo_temp(s->tipo);
            sprintf(buf, "%s = %s / %s;\n", t_op, s->temp, (yyvsp[-1].info).temp);
            strcat(instrucoes, buf);
            sprintf(buf, "%s = %s;\n", s->temp, t_op);
            strcat(instrucoes, buf);
            sprintf(c_out, "%s /= %s;\n", s->temp, (yyvsp[-1].info).temp);
        }
        (yyval.info).c_expr = c_out;
    }
#line 2241 "sin.tab.c"
    break;

  case 60: /* comando: ID INC ';'  */
#line 514 "sin.y"
                 {
        Simbolo *s = buscar((yyvsp[-2].valor_str));
        if (!s) yyerror("Erro Semantico: Variavel nao declarada.");
        else {
            sprintf(buf, "%s = %s + 1;\n", s->temp, s->temp);
            strcat(instrucoes, buf);
        }
        char* c_out = (char*) malloc(256);
        sprintf(c_out, "%s++;\n", s ? s->temp : (yyvsp[-2].valor_str));
        (yyval.info).c_expr = c_out;
    }
#line 2257 "sin.tab.c"
    break;

  case 61: /* comando: ID DEC ';'  */
#line 525 "sin.y"
                 {
        Simbolo *s = buscar((yyvsp[-2].valor_str));
        if (!s) yyerror("Erro Semantico: Variavel nao declarada.");
        else {
            sprintf(buf, "%s = %s - 1;\n", s->temp, s->temp);
            strcat(instrucoes, buf);
        }
        char* c_out = (char*) malloc(256);
        sprintf(c_out, "%s--;\n", s ? s->temp : (yyvsp[-2].valor_str));
        (yyval.info).c_expr = c_out;
    }
#line 2273 "sin.tab.c"
    break;

  case 62: /* comando: ID '[' expressao ']' ASSIGN expressao ';'  */
#line 536 "sin.y"
                                                {
        Simbolo *s = buscar((yyvsp[-6].valor_str));
        if (!s) yyerror("Erro Semantico: Matriz nao declarada.");
        else {
            sprintf(buf, "%s[%s] = %s;\n", s->temp, (yyvsp[-4].info).temp, (yyvsp[-1].info).temp);
            strcat(instrucoes, buf);
        }
        char* c_out = (char*) malloc(256);
        sprintf(c_out, "%s[%s] = %s;\n", s ? s->temp : (yyvsp[-6].valor_str), (yyvsp[-4].info).temp, (yyvsp[-1].info).temp);
        (yyval.info).c_expr = c_out;
    }
#line 2289 "sin.tab.c"
    break;

  case 63: /* declaracao: tipo ID  */
#line 550 "sin.y"
              {
        if (buscar((yyvsp[0].valor_str)) != NULL && buscar((yyvsp[0].valor_str))->nivel == escopo_atual) {
            yyerror("Erro Semantico: Variavel ja declarada.");
        } else {
            inserir((yyvsp[0].valor_str), (yyvsp[-1].info).tipo_val, escopo_atual);
        }
        (yyval.info).c_expr = strdup("");
    }
#line 2302 "sin.tab.c"
    break;

  case 64: /* declaracao: tipo ID ASSIGN expressao  */
#line 558 "sin.y"
                               {
        Simbolo *s = inserir((yyvsp[-2].valor_str), (yyvsp[-3].info).tipo_val, escopo_atual);
        sprintf(buf, "%s = %s;\n", s->temp, (yyvsp[0].info).temp);
        strcat(instrucoes, buf);
        char* c_out = (char*) malloc(256);
        sprintf(c_out, "%s = %s;\n", s->temp, (yyvsp[0].info).temp);
        (yyval.info).c_expr = c_out;
    }
#line 2315 "sin.tab.c"
    break;

  case 65: /* declaracao: tipo ID '[' NUM_INT ']'  */
#line 566 "sin.y"
                              {
        inserir_array((yyvsp[-3].valor_str), (yyvsp[-4].info).tipo_val, escopo_atual, atoi((yyvsp[-1].valor_str)));
        (yyval.info).c_expr = strdup("");
    }
#line 2324 "sin.tab.c"
    break;

  case 66: /* $@12: %empty  */
#line 570 "sin.y"
                                         {
        simbolo_array_atual = inserir_array((yyvsp[-5].valor_str), (yyvsp[-6].info).tipo_val, escopo_atual, atoi((yyvsp[-3].valor_str)));
        idx_array_atual = 0;
        tam_array_atual = atoi((yyvsp[-3].valor_str));
    }
#line 2334 "sin.tab.c"
    break;

  case 67: /* declaracao: tipo ID '[' NUM_INT ']' ASSIGN '{' $@12 lista_inicializadores '}'  */
#line 574 "sin.y"
                                {
        (yyval.info).c_expr = strdup("");
    }
#line 2342 "sin.tab.c"
    break;

  case 70: /* elemento_inicializador: expressao  */
#line 585 "sin.y"
                {
        if (simbolo_array_atual) {
            if (idx_array_atual < tam_array_atual) {
                sprintf(buf, "%s[%d] = %s;\n", simbolo_array_atual->temp, idx_array_atual, (yyvsp[0].info).temp);
                strcat(instrucoes, buf);
                idx_array_atual++;
            } else {
                yyerror("Erro Semantico: Excesso de elementos na matriz.");
            }
        }
    }
#line 2358 "sin.tab.c"
    break;

  case 71: /* atribuicao: ID ASSIGN expressao  */
#line 599 "sin.y"
                          {
        Simbolo *s = buscar((yyvsp[-2].valor_str));
        if (!s) yyerror("Erro Semantico: Variavel nao declarada.");
        else {
            sprintf(buf, "%s = %s;\n", s->temp, (yyvsp[0].info).temp);
            strcat(instrucoes, buf);
        }
        char* c_out = (char*) malloc(256);
        sprintf(c_out, "%s = %s;\n", s ? s->temp : (yyvsp[-2].valor_str), (yyvsp[0].info).temp);
        (yyval.info).c_expr = c_out;
    }
#line 2374 "sin.tab.c"
    break;

  case 72: /* expressao: expressao PLUS expressao  */
#line 613 "sin.y"
                               {
        char *t = novo_temp(T_INT);
        sprintf(buf, "%s = %s + %s;\n", t, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
        strcat(instrucoes, buf);
        (yyval.info).temp = t;
        (yyval.info).tipo_val = T_INT;
    }
#line 2386 "sin.tab.c"
    break;

  case 73: /* expressao: expressao '-' expressao  */
#line 620 "sin.y"
                              {
        char *t = novo_temp(T_INT);
        sprintf(buf, "%s = %s - %s;\n", t, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
        strcat(instrucoes, buf);
        (yyval.info).temp = t;
        (yyval.info).tipo_val = T_INT;
    }
#line 2398 "sin.tab.c"
    break;

  case 74: /* expressao: expressao '*' expressao  */
#line 627 "sin.y"
                              {
        char *t = novo_temp(T_INT);
        sprintf(buf, "%s = %s * %s;\n", t, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
        strcat(instrucoes, buf);
        (yyval.info).temp = t;
        (yyval.info).tipo_val = T_INT;
    }
#line 2410 "sin.tab.c"
    break;

  case 75: /* expressao: expressao '/' expressao  */
#line 634 "sin.y"
                              {
        char *t = novo_temp(T_INT);
        sprintf(buf, "%s = %s / %s;\n", t, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
        strcat(instrucoes, buf);
        (yyval.info).temp = t;
        (yyval.info).tipo_val = T_INT;
    }
#line 2422 "sin.tab.c"
    break;

  case 76: /* expressao: termo  */
#line 641 "sin.y"
            { (yyval.info) = (yyvsp[0].info); }
#line 2428 "sin.tab.c"
    break;

  case 77: /* termo: fator  */
#line 645 "sin.y"
            { (yyval.info) = (yyvsp[0].info); }
#line 2434 "sin.tab.c"
    break;

  case 78: /* fator: ID  */
#line 649 "sin.y"
         {
        Simbolo *s = buscar((yyvsp[0].valor_str));
        if (!s) {
            yyerror("Erro Semantico: Identificador nao encontrado.");
            (yyval.info).temp = strdup("0");
        } else {
            (yyval.info).temp = s->temp;
            (yyval.info).tipo_val = s->tipo;
        }
    }
#line 2449 "sin.tab.c"
    break;

  case 79: /* fator: NUM_INT  */
#line 659 "sin.y"
              {
        char *t = novo_temp(T_INT);
        sprintf(buf, "%s = %s;\n", t, (yyvsp[0].valor_str));
        strcat(instrucoes, buf);
        (yyval.info).temp = t;
        (yyval.info).tipo_val = T_INT;
    }
#line 2461 "sin.tab.c"
    break;

  case 80: /* fator: '(' expressao ')'  */
#line 666 "sin.y"
                        {
        (yyval.info) = (yyvsp[-1].info);
    }
#line 2469 "sin.tab.c"
    break;

  case 81: /* fator: ID '(' chamada_argumentos ')'  */
#line 669 "sin.y"
                                    {
        Simbolo *s = buscar((yyvsp[-3].valor_str));
        char *t = novo_temp(T_INT);
        sprintf(buf, "%s = %s(%s);\n", t, (yyvsp[-3].valor_str), (yyvsp[-1].info).temp);
        strcat(instrucoes, buf);
        (yyval.info).temp = t;
        (yyval.info).tipo_val = T_INT;
    }
#line 2482 "sin.tab.c"
    break;

  case 82: /* chamada_argumentos: chamada_argumentos_lista  */
#line 680 "sin.y"
                               { (yyval.info) = (yyvsp[0].info); }
#line 2488 "sin.tab.c"
    break;

  case 83: /* chamada_argumentos: %empty  */
#line 681 "sin.y"
                  { (yyval.info).temp = strdup(""); }
#line 2494 "sin.tab.c"
    break;

  case 84: /* chamada_argumentos_lista: expressao  */
#line 685 "sin.y"
                { (yyval.info).temp = strdup((yyvsp[0].info).temp); }
#line 2500 "sin.tab.c"
    break;

  case 85: /* chamada_argumentos_lista: expressao ',' chamada_argumentos_lista  */
#line 686 "sin.y"
                                             {
        char *t_buf = (char*) malloc(strlen((yyvsp[-2].info).temp) + strlen((yyvsp[0].info).temp) + 5);
        sprintf(t_buf, "%s, %s", (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
        (yyval.info).temp = t_buf;
    }
#line 2510 "sin.tab.c"
    break;


#line 2514 "sin.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 693 "sin.y"


#include <stdlib.h> 

int main() {
    yyparse();
    if (houve_erro) {
        return 1;
    }

    gerar_declaracoes_finais();

    /* 1. IMPRESSÃO NO TERMINAL */
    printf("#include <stdio.h>\n");
    printf("#include <stdlib.h>\n");
    printf("#include <string.h>\n");
    printf("#include <stdbool.h>\n\n");
    printf("%s\n", c_code_decl);
    printf("%s", c_code_body);
    printf("int main()\n{\n");
    printf("%s\n", c_body);
    printf("    return 0;\n}\n");

    /* 2. SALVANDO NO ARQUIVO SAIDA.C */
    FILE *arquivo_c = fopen("saida.c", "w");
    if (!arquivo_c) return 1;
    fprintf(arquivo_c, "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <stdbool.h>\n\n");
    fprintf(arquivo_c, "%s\n", c_code_decl);
    fprintf(arquivo_c, "%s", c_code_body);
    fprintf(arquivo_c, "int main()\n{\n");
    fprintf(arquivo_c, "%s", c_body);
    fprintf(arquivo_c, "    return 0;\n}\n");
    fclose(arquivo_c);
    return 0;
}
