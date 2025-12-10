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
#line 37 "pokelang.y"

#include <string.h>

extern int yylex(); 
void yyerror(const char *s);
extern char *yytext;
extern int yyline;

/* TABELA DE SÍMBOLOS */

#define TYPE_UNDEFINED 0
#define TYPE_INTEGER   1
#define TYPE_VECTOR    2

typedef struct Symbol {
    char *name;
    int type;
    int size;
    int addr; 
} Symbol;

#define MAX_SYMBOLS 100
Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;
int varCount = 0; 

#line 98 "pokelang.tab.c"

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

#include "pokelang.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_IDENTIFICADOR = 3,        /* TOKEN_IDENTIFICADOR  */
  YYSYMBOL_TOKEN_NUMERO = 4,               /* TOKEN_NUMERO  */
  YYSYMBOL_TOKEN_STRING = 5,               /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_KW_POKEBALL = 6,          /* TOKEN_KW_POKEBALL  */
  YYSYMBOL_TOKEN_KW_PC = 7,                /* TOKEN_KW_PC  */
  YYSYMBOL_TOKEN_KW_CAPTURAR = 8,          /* TOKEN_KW_CAPTURAR  */
  YYSYMBOL_TOKEN_KW_ARREMESSE = 9,         /* TOKEN_KW_ARREMESSE  */
  YYSYMBOL_TOKEN_KW_IF = 10,               /* TOKEN_KW_IF  */
  YYSYMBOL_TOKEN_KW_ELSE = 11,             /* TOKEN_KW_ELSE  */
  YYSYMBOL_TOKEN_KW_WHILE = 12,            /* TOKEN_KW_WHILE  */
  YYSYMBOL_TOKEN_KW_FOR = 13,              /* TOKEN_KW_FOR  */
  YYSYMBOL_TOKEN_ABRE_PARENTESE = 14,      /* TOKEN_ABRE_PARENTESE  */
  YYSYMBOL_TOKEN_FECHA_PARENTESE = 15,     /* TOKEN_FECHA_PARENTESE  */
  YYSYMBOL_TOKEN_ABRE_CHAVE = 16,          /* TOKEN_ABRE_CHAVE  */
  YYSYMBOL_TOKEN_FECHA_CHAVE = 17,         /* TOKEN_FECHA_CHAVE  */
  YYSYMBOL_TOKEN_ABRE_COLCHETE = 18,       /* TOKEN_ABRE_COLCHETE  */
  YYSYMBOL_TOKEN_FECHA_COLCHETE = 19,      /* TOKEN_FECHA_COLCHETE  */
  YYSYMBOL_TOKEN_PONTO_VIRGULA = 20,       /* TOKEN_PONTO_VIRGULA  */
  YYSYMBOL_TOKEN_VIRGULA = 21,             /* TOKEN_VIRGULA  */
  YYSYMBOL_TOKEN_OP_ATRIBUICAO = 22,       /* TOKEN_OP_ATRIBUICAO  */
  YYSYMBOL_TOKEN_OP_MAIOR = 23,            /* TOKEN_OP_MAIOR  */
  YYSYMBOL_TOKEN_OP_MENOR = 24,            /* TOKEN_OP_MENOR  */
  YYSYMBOL_TOKEN_OP_MAIOR_IGUAL = 25,      /* TOKEN_OP_MAIOR_IGUAL  */
  YYSYMBOL_TOKEN_OP_MENOR_IGUAL = 26,      /* TOKEN_OP_MENOR_IGUAL  */
  YYSYMBOL_TOKEN_OP_IGUAL = 27,            /* TOKEN_OP_IGUAL  */
  YYSYMBOL_TOKEN_OP_DIFERENTE = 28,        /* TOKEN_OP_DIFERENTE  */
  YYSYMBOL_TOKEN_OP_E = 29,                /* TOKEN_OP_E  */
  YYSYMBOL_TOKEN_OP_OU = 30,               /* TOKEN_OP_OU  */
  YYSYMBOL_TOKEN_OP_NAO = 31,              /* TOKEN_OP_NAO  */
  YYSYMBOL_TOKEN_OP_SOMA = 32,             /* TOKEN_OP_SOMA  */
  YYSYMBOL_TOKEN_OP_SUB = 33,              /* TOKEN_OP_SUB  */
  YYSYMBOL_TOKEN_OP_MULT = 34,             /* TOKEN_OP_MULT  */
  YYSYMBOL_TOKEN_OP_DIV = 35,              /* TOKEN_OP_DIV  */
  YYSYMBOL_TOKEN_OP_MOD = 36,              /* TOKEN_OP_MOD  */
  YYSYMBOL_TOKEN_ERRO_LEXICO = 37,         /* TOKEN_ERRO_LEXICO  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_programa = 39,                  /* programa  */
  YYSYMBOL_lista_comandos = 40,            /* lista_comandos  */
  YYSYMBOL_comando = 41,                   /* comando  */
  YYSYMBOL_declaracao = 42,                /* declaracao  */
  YYSYMBOL_acesso_variavel = 43,           /* acesso_variavel  */
  YYSYMBOL_comando_atribuicao = 44,        /* comando_atribuicao  */
  YYSYMBOL_comando_selecao = 45,           /* comando_selecao  */
  YYSYMBOL_else_opcional = 46,             /* else_opcional  */
  YYSYMBOL_comando_jornada = 47,           /* comando_jornada  */
  YYSYMBOL_comando_ginasio = 48,           /* comando_ginasio  */
  YYSYMBOL_atribuicao_opcional = 49,       /* atribuicao_opcional  */
  YYSYMBOL_expressao_opcional = 50,        /* expressao_opcional  */
  YYSYMBOL_comando_captura = 51,           /* comando_captura  */
  YYSYMBOL_comando_arremesse = 52,         /* comando_arremesse  */
  YYSYMBOL_lista_argumentos = 53,          /* lista_argumentos  */
  YYSYMBOL_bloco_comandos = 54,            /* bloco_comandos  */
  YYSYMBOL_expressao = 55,                 /* expressao  */
  YYSYMBOL_erro_sintatico = 56             /* erro_sintatico  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  108

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   104,   104,   114,   115,   128,   129,   130,   131,   132,
     133,   134,   135,   138,   143,   150,   156,   164,   170,   177,
     178,   182,   188,   203,   204,   207,   208,   211,   217,   223,
     227,   236,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     262,   263
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
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_IDENTIFICADOR",
  "TOKEN_NUMERO", "TOKEN_STRING", "TOKEN_KW_POKEBALL", "TOKEN_KW_PC",
  "TOKEN_KW_CAPTURAR", "TOKEN_KW_ARREMESSE", "TOKEN_KW_IF",
  "TOKEN_KW_ELSE", "TOKEN_KW_WHILE", "TOKEN_KW_FOR",
  "TOKEN_ABRE_PARENTESE", "TOKEN_FECHA_PARENTESE", "TOKEN_ABRE_CHAVE",
  "TOKEN_FECHA_CHAVE", "TOKEN_ABRE_COLCHETE", "TOKEN_FECHA_COLCHETE",
  "TOKEN_PONTO_VIRGULA", "TOKEN_VIRGULA", "TOKEN_OP_ATRIBUICAO",
  "TOKEN_OP_MAIOR", "TOKEN_OP_MENOR", "TOKEN_OP_MAIOR_IGUAL",
  "TOKEN_OP_MENOR_IGUAL", "TOKEN_OP_IGUAL", "TOKEN_OP_DIFERENTE",
  "TOKEN_OP_E", "TOKEN_OP_OU", "TOKEN_OP_NAO", "TOKEN_OP_SOMA",
  "TOKEN_OP_SUB", "TOKEN_OP_MULT", "TOKEN_OP_DIV", "TOKEN_OP_MOD",
  "TOKEN_ERRO_LEXICO", "$accept", "programa", "lista_comandos", "comando",
  "declaracao", "acesso_variavel", "comando_atribuicao", "comando_selecao",
  "else_opcional", "comando_jornada", "comando_ginasio",
  "atribuicao_opcional", "expressao_opcional", "comando_captura",
  "comando_arremesse", "lista_argumentos", "bloco_comandos", "expressao",
  "erro_sintatico", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-56)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -56,     1,   130,   -56,   -16,     2,     8,   -10,    10,    12,
      14,    29,   -56,   -56,   -56,   -56,    26,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,    13,    -8,    51,    67,    13,    13,
      13,    67,    13,   -56,   -56,    13,    13,   -56,    96,   -56,
      75,    70,   -12,   157,    32,    48,    64,    68,   143,    78,
     157,   -56,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    71,    69,    72,    13,    79,
      79,    13,    13,   -56,   -56,   -13,   -13,   -13,   -13,   185,
     185,   171,   171,    18,    18,   -56,   -56,   -56,    74,   -56,
     -56,   157,   -56,    76,   -56,   157,    89,   157,   -56,   145,
      79,   -56,    67,   -56,   -56,    81,    79,   -56
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,    15,     0,     0,     0,     0,     0,
       0,     0,    51,    50,     4,     5,     0,     7,     8,    10,
      11,     6,     9,    12,     0,     0,     0,     0,     0,     0,
       0,    23,     0,    32,    34,     0,     0,    33,     0,    13,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
      48,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    17,    49,    40,    41,    42,    43,    44,
      45,    46,    47,    35,    36,    37,    38,    39,     0,    27,
      28,    30,     3,    19,    21,    24,     0,    26,    14,     0,
       0,    18,    23,    31,    20,     0,     0,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,   -56,    -1,   -56,   -56,    -2,   -56,   -56,   -56,   -56,
     -56,    -4,   -56,   -56,   -56,   -56,   -55,   -22,   -56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    14,    15,    37,    17,    18,   101,    19,
      20,    47,    96,    21,    22,    42,    93,    38,    23
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      16,     3,    24,    67,    27,    25,    43,    44,    45,    68,
      48,    26,    39,    49,    50,    94,     4,    33,    34,    60,
      61,    62,    63,    64,    28,    41,    29,    35,    30,    46,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    31,    36,   104,    91,    69,    32,    95,
      97,   107,    62,    63,    64,    52,    53,    54,    55,    56,
      57,    58,    59,    70,    60,    61,    62,    63,    64,    40,
       4,    52,    53,    54,    55,    56,    57,    58,    59,    65,
      60,    61,    62,    63,    64,    66,    71,   100,    72,    89,
      88,    99,    90,    74,    98,    92,   106,    16,   105,     0,
      46,    52,    53,    54,    55,    56,    57,    58,    59,   102,
      60,    61,    62,    63,    64,    51,     0,     0,     0,    52,
      53,    54,    55,    56,    57,    58,    59,     0,    60,    61,
      62,    63,    64,     4,     0,     0,     5,     6,     7,     8,
       9,     0,    10,    11,     0,     0,     0,    12,     4,     0,
      13,     5,     6,     7,     8,     9,     0,    10,    11,     0,
       0,     0,   103,    73,     0,    13,    52,    53,    54,    55,
      56,    57,    58,    59,     0,    60,    61,    62,    63,    64,
      52,    53,    54,    55,    56,    57,    58,    59,     0,    60,
      61,    62,    63,    64,    52,    53,    54,    55,    56,    57,
       0,     0,     0,    60,    61,    62,    63,    64,    52,    53,
      54,    55,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64
};

static const yytype_int8 yycheck[] =
{
       2,     0,    18,    15,    14,     3,    28,    29,    30,    21,
      32,     3,    20,    35,    36,    70,     3,     4,     5,    32,
      33,    34,    35,    36,    14,    27,    14,    14,    14,    31,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    14,    31,   100,    68,    15,    22,    71,
      72,   106,    34,    35,    36,    23,    24,    25,    26,    27,
      28,    29,    30,    15,    32,    33,    34,    35,    36,    18,
       3,    23,    24,    25,    26,    27,    28,    29,    30,     4,
      32,    33,    34,    35,    36,    15,    22,    11,    20,    20,
      19,    92,    20,    15,    20,    16,    15,    99,   102,    -1,
     102,    23,    24,    25,    26,    27,    28,    29,    30,    20,
      32,    33,    34,    35,    36,    19,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    32,    33,
      34,    35,    36,     3,    -1,    -1,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    17,     3,    -1,
      20,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    17,    20,    -1,    20,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    32,    33,    34,    35,    36,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,    40,     0,     3,     6,     7,     8,     9,    10,
      12,    13,    17,    20,    41,    42,    43,    44,    45,    47,
      48,    51,    52,    56,    18,     3,     3,    14,    14,    14,
      14,    14,    22,     4,     5,    14,    31,    43,    55,    20,
      18,    43,    53,    55,    55,    55,    43,    49,    55,    55,
      55,    19,    23,    24,    25,    26,    27,    28,    29,    30,
      32,    33,    34,    35,    36,     4,    15,    15,    21,    15,
      15,    22,    20,    20,    15,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    19,    20,
      20,    55,    16,    54,    54,    55,    50,    55,    20,    40,
      11,    46,    20,    17,    54,    49,    15,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    41,    41,
      41,    41,    41,    42,    42,    43,    43,    44,    45,    46,
      46,    47,    48,    49,    49,    50,    50,    51,    52,    53,
      53,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     6,     1,     4,     4,     6,     0,
       2,     5,     9,     0,     3,     0,     1,     5,     5,     1,
       3,     3,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       1,     1
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
  case 2: /* programa: lista_comandos  */
#line 105 "pokelang.y"
    {
        (yyval.node) = new_node(NODE_PROGRAMA, (yyvsp[0].node), NULL);
        printf("; --- Inicio do Codigo Assembly Raposeitor ---\n");
        gera_codigo((yyval.node));
        printf("; --- Fim do Codigo ---\n");
    }
#line 1242 "pokelang.tab.c"
    break;

  case 3: /* lista_comandos: %empty  */
#line 114 "pokelang.y"
    { (yyval.node) = NULL; }
#line 1248 "pokelang.tab.c"
    break;

  case 4: /* lista_comandos: lista_comandos comando  */
#line 116 "pokelang.y"
    {
        if ((yyvsp[-1].node) == NULL) {
            (yyval.node) = (yyvsp[0].node);
        } else {
            ASTNode *p = (yyvsp[-1].node);
            while (p->next != NULL) p = p->next;
            p->next = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-1].node);
        }
    }
#line 1263 "pokelang.tab.c"
    break;

  case 5: /* comando: declaracao  */
#line 128 "pokelang.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1269 "pokelang.tab.c"
    break;

  case 6: /* comando: comando_captura  */
#line 129 "pokelang.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1275 "pokelang.tab.c"
    break;

  case 7: /* comando: comando_atribuicao  */
#line 130 "pokelang.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1281 "pokelang.tab.c"
    break;

  case 8: /* comando: comando_selecao  */
#line 131 "pokelang.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1287 "pokelang.tab.c"
    break;

  case 9: /* comando: comando_arremesse  */
#line 132 "pokelang.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1293 "pokelang.tab.c"
    break;

  case 10: /* comando: comando_jornada  */
#line 133 "pokelang.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1299 "pokelang.tab.c"
    break;

  case 11: /* comando: comando_ginasio  */
#line 134 "pokelang.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1305 "pokelang.tab.c"
    break;

  case 12: /* comando: erro_sintatico  */
#line 135 "pokelang.y"
                     { yyerrok; (yyval.node) = NULL; }
#line 1311 "pokelang.tab.c"
    break;

  case 13: /* declaracao: TOKEN_KW_POKEBALL TOKEN_IDENTIFICADOR TOKEN_PONTO_VIRGULA  */
#line 139 "pokelang.y"
    {
        sym_insert((yyvsp[-1].stringValue), TYPE_INTEGER, 0);
        (yyval.node) = NULL; 
    }
#line 1320 "pokelang.tab.c"
    break;

  case 14: /* declaracao: TOKEN_KW_PC TOKEN_IDENTIFICADOR TOKEN_ABRE_COLCHETE TOKEN_NUMERO TOKEN_FECHA_COLCHETE TOKEN_PONTO_VIRGULA  */
#line 144 "pokelang.y"
    {
        sym_insert((yyvsp[-4].stringValue), TYPE_VECTOR, atoi((yyvsp[-2].stringValue)));
        (yyval.node) = NULL;
    }
#line 1329 "pokelang.tab.c"
    break;

  case 15: /* acesso_variavel: TOKEN_IDENTIFICADOR  */
#line 151 "pokelang.y"
    {
        Symbol *s = sym_check_usage((yyvsp[0].stringValue));
        if (s->type != TYPE_INTEGER) { fprintf(stderr, "Erro tipo: %s e vetor.\n", s->name); exit(1); }
        (yyval.node) = new_leaf(NODE_VAR, (yyvsp[0].stringValue));
    }
#line 1339 "pokelang.tab.c"
    break;

  case 16: /* acesso_variavel: TOKEN_IDENTIFICADOR TOKEN_ABRE_COLCHETE expressao TOKEN_FECHA_COLCHETE  */
#line 157 "pokelang.y"
    {
        Symbol *s = sym_check_usage((yyvsp[-3].stringValue));
        if (s->type != TYPE_VECTOR) { fprintf(stderr, "Erro tipo: %s e int.\n", s->name); exit(1); }
        (yyval.node) = new_node(NODE_VETOR_ACESSO, new_leaf(NODE_VAR, (yyvsp[-3].stringValue)), (yyvsp[-1].node)); 
    }
#line 1349 "pokelang.tab.c"
    break;

  case 17: /* comando_atribuicao: acesso_variavel TOKEN_OP_ATRIBUICAO expressao TOKEN_PONTO_VIRGULA  */
#line 165 "pokelang.y"
    {
        (yyval.node) = new_node(NODE_ATRIBUICAO, (yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 1357 "pokelang.tab.c"
    break;

  case 18: /* comando_selecao: TOKEN_KW_IF TOKEN_ABRE_PARENTESE expressao TOKEN_FECHA_PARENTESE bloco_comandos else_opcional  */
#line 171 "pokelang.y"
    {
        (yyval.node) = new_triple_node(NODE_IF, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1365 "pokelang.tab.c"
    break;

  case 19: /* else_opcional: %empty  */
#line 177 "pokelang.y"
    { (yyval.node) = NULL; }
#line 1371 "pokelang.tab.c"
    break;

  case 20: /* else_opcional: TOKEN_KW_ELSE bloco_comandos  */
#line 179 "pokelang.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1377 "pokelang.tab.c"
    break;

  case 21: /* comando_jornada: TOKEN_KW_WHILE TOKEN_ABRE_PARENTESE expressao TOKEN_FECHA_PARENTESE bloco_comandos  */
#line 183 "pokelang.y"
    {
        (yyval.node) = new_node(NODE_WHILE, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1385 "pokelang.tab.c"
    break;

  case 22: /* comando_ginasio: TOKEN_KW_FOR TOKEN_ABRE_PARENTESE atribuicao_opcional TOKEN_PONTO_VIRGULA expressao_opcional TOKEN_PONTO_VIRGULA atribuicao_opcional TOKEN_FECHA_PARENTESE bloco_comandos  */
#line 189 "pokelang.y"
    {
        (yyval.node) = new_triple_node(NODE_FOR, (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[0].node));
        if ((yyvsp[-2].node) != NULL && (yyval.node)->extra != NULL) {
             ASTNode *body = (yyval.node)->extra;
             ASTNode *cmds = body->left;
             if (cmds == NULL) body->left = (yyvsp[-2].node);
             else {
                 while (cmds->next != NULL) cmds = cmds->next;
                 cmds->next = (yyvsp[-2].node);
             }
        }
    }
#line 1402 "pokelang.tab.c"
    break;

  case 23: /* atribuicao_opcional: %empty  */
#line 203 "pokelang.y"
                                 { (yyval.node) = NULL; }
#line 1408 "pokelang.tab.c"
    break;

  case 24: /* atribuicao_opcional: acesso_variavel TOKEN_OP_ATRIBUICAO expressao  */
#line 204 "pokelang.y"
                                                    { (yyval.node) = new_node(NODE_ATRIBUICAO, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1414 "pokelang.tab.c"
    break;

  case 25: /* expressao_opcional: %empty  */
#line 207 "pokelang.y"
                                { (yyval.node) = NULL; }
#line 1420 "pokelang.tab.c"
    break;

  case 26: /* expressao_opcional: expressao  */
#line 208 "pokelang.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1426 "pokelang.tab.c"
    break;

  case 27: /* comando_captura: TOKEN_KW_CAPTURAR TOKEN_ABRE_PARENTESE acesso_variavel TOKEN_FECHA_PARENTESE TOKEN_PONTO_VIRGULA  */
#line 212 "pokelang.y"
    {
        (yyval.node) = new_node(NODE_CAPTURA, (yyvsp[-2].node), NULL);
    }
#line 1434 "pokelang.tab.c"
    break;

  case 28: /* comando_arremesse: TOKEN_KW_ARREMESSE TOKEN_ABRE_PARENTESE lista_argumentos TOKEN_FECHA_PARENTESE TOKEN_PONTO_VIRGULA  */
#line 218 "pokelang.y"
    {
        (yyval.node) = new_node(NODE_ARREMESSE, (yyvsp[-2].node), NULL);
    }
#line 1442 "pokelang.tab.c"
    break;

  case 29: /* lista_argumentos: expressao  */
#line 224 "pokelang.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1450 "pokelang.tab.c"
    break;

  case 30: /* lista_argumentos: lista_argumentos TOKEN_VIRGULA expressao  */
#line 228 "pokelang.y"
    {
        ASTNode *p = (yyvsp[-2].node);
        while (p->next != NULL) p = p->next;
        p->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1461 "pokelang.tab.c"
    break;

  case 31: /* bloco_comandos: TOKEN_ABRE_CHAVE lista_comandos TOKEN_FECHA_CHAVE  */
#line 237 "pokelang.y"
    {
        (yyval.node) = new_node(NODE_BLOCO, (yyvsp[-1].node), NULL);
    }
#line 1469 "pokelang.tab.c"
    break;

  case 32: /* expressao: TOKEN_NUMERO  */
#line 242 "pokelang.y"
                        { (yyval.node) = new_leaf(NODE_CONST_INT, (yyvsp[0].stringValue)); }
#line 1475 "pokelang.tab.c"
    break;

  case 33: /* expressao: acesso_variavel  */
#line 243 "pokelang.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1481 "pokelang.tab.c"
    break;

  case 34: /* expressao: TOKEN_STRING  */
#line 244 "pokelang.y"
                        { (yyval.node) = new_leaf(NODE_STRING, (yyvsp[0].stringValue)); }
#line 1487 "pokelang.tab.c"
    break;

  case 35: /* expressao: expressao TOKEN_OP_SOMA expressao  */
#line 245 "pokelang.y"
                                        { (yyval.node) = new_node(NODE_OP_SOMA, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1493 "pokelang.tab.c"
    break;

  case 36: /* expressao: expressao TOKEN_OP_SUB expressao  */
#line 246 "pokelang.y"
                                        { (yyval.node) = new_node(NODE_OP_SUB, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1499 "pokelang.tab.c"
    break;

  case 37: /* expressao: expressao TOKEN_OP_MULT expressao  */
#line 247 "pokelang.y"
                                        { (yyval.node) = new_node(NODE_OP_MULT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1505 "pokelang.tab.c"
    break;

  case 38: /* expressao: expressao TOKEN_OP_DIV expressao  */
#line 248 "pokelang.y"
                                        { (yyval.node) = new_node(NODE_OP_DIV, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1511 "pokelang.tab.c"
    break;

  case 39: /* expressao: expressao TOKEN_OP_MOD expressao  */
#line 249 "pokelang.y"
                                        { (yyval.node) = new_node(NODE_OP_MOD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1517 "pokelang.tab.c"
    break;

  case 40: /* expressao: expressao TOKEN_OP_MAIOR expressao  */
#line 250 "pokelang.y"
                                         { (yyval.node) = new_node(NODE_OP_MAIOR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1523 "pokelang.tab.c"
    break;

  case 41: /* expressao: expressao TOKEN_OP_MENOR expressao  */
#line 251 "pokelang.y"
                                         { (yyval.node) = new_node(NODE_OP_MENOR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1529 "pokelang.tab.c"
    break;

  case 42: /* expressao: expressao TOKEN_OP_MAIOR_IGUAL expressao  */
#line 252 "pokelang.y"
                                               { (yyval.node) = new_node(NODE_OP_MAIOR_IGUAL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1535 "pokelang.tab.c"
    break;

  case 43: /* expressao: expressao TOKEN_OP_MENOR_IGUAL expressao  */
#line 253 "pokelang.y"
                                               { (yyval.node) = new_node(NODE_OP_MENOR_IGUAL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1541 "pokelang.tab.c"
    break;

  case 44: /* expressao: expressao TOKEN_OP_IGUAL expressao  */
#line 254 "pokelang.y"
                                         { (yyval.node) = new_node(NODE_OP_IGUAL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1547 "pokelang.tab.c"
    break;

  case 45: /* expressao: expressao TOKEN_OP_DIFERENTE expressao  */
#line 255 "pokelang.y"
                                             { (yyval.node) = new_node(NODE_OP_DIFERENTE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1553 "pokelang.tab.c"
    break;

  case 46: /* expressao: expressao TOKEN_OP_E expressao  */
#line 256 "pokelang.y"
                                     { (yyval.node) = new_node(NODE_OP_E, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1559 "pokelang.tab.c"
    break;

  case 47: /* expressao: expressao TOKEN_OP_OU expressao  */
#line 257 "pokelang.y"
                                      { (yyval.node) = new_node(NODE_OP_OU, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1565 "pokelang.tab.c"
    break;

  case 48: /* expressao: TOKEN_OP_NAO expressao  */
#line 258 "pokelang.y"
                             { (yyval.node) = new_node(NODE_OP_NAO, (yyvsp[0].node), NULL); }
#line 1571 "pokelang.tab.c"
    break;

  case 49: /* expressao: TOKEN_ABRE_PARENTESE expressao TOKEN_FECHA_PARENTESE  */
#line 259 "pokelang.y"
                                                           { (yyval.node) = (yyvsp[-1].node); }
#line 1577 "pokelang.tab.c"
    break;

  case 50: /* erro_sintatico: TOKEN_PONTO_VIRGULA  */
#line 262 "pokelang.y"
                                    { (yyval.node) = NULL; }
#line 1583 "pokelang.tab.c"
    break;

  case 51: /* erro_sintatico: TOKEN_FECHA_CHAVE  */
#line 263 "pokelang.y"
                                    { (yyval.node) = NULL; }
#line 1589 "pokelang.tab.c"
    break;


#line 1593 "pokelang.tab.c"

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

#line 266 "pokelang.y"

/* IMPLEMENTAÇÃO EM C */

Symbol* sym_lookup(char *name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) return &symbolTable[i];
    }
    return NULL;
}

void sym_insert(char *name, int type, int size) {
    if (sym_lookup(name) == NULL) {
        symbolTable[symbolCount].name = strdup(name);
        symbolTable[symbolCount].type = type;
        symbolTable[symbolCount].size = size;
        symbolTable[symbolCount].addr = varCount;
        if (type == TYPE_VECTOR) varCount += size;
        else varCount++;
        symbolCount++;
    }
}

struct Symbol* sym_check_usage(char *name) {
    Symbol *s = sym_lookup(name);
    if (s == NULL) {
        fprintf(stderr, "[ERRO SEMANTICO] Linha %d: Variavel '%s' nao declarada.\n", yyline, name);
        exit(1);
    }
    return s;
}

ASTNode* new_node(NodeType type, ASTNode *left, ASTNode *right) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type;
    node->value = NULL;
    node->left = left;
    node->right = right;
    node->extra = NULL;
    node->next = NULL;
    return node;
}

ASTNode* new_leaf(NodeType type, char *value) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type;
    node->value = strdup(value);
    node->left = NULL;
    node->right = NULL;
    node->extra = NULL;
    node->next = NULL;
    return node;
}

ASTNode* new_triple_node(NodeType type, ASTNode *c1, ASTNode *c2, ASTNode *c3) {
    ASTNode *node = new_node(type, c1, c2);
    node->extra = c3;
    return node;
}

int tempCount = 0;
int labelCount = 0;

char* new_temp() {
    char* temp = (char*)malloc(20);
    sprintf(temp, "%%t%d", tempCount++);
    return temp;
}

char* new_label() {
    char* lbl = (char*)malloc(20);
    sprintf(lbl, "R%d", labelCount++);
    return lbl;
}

char* gera_codigo(ASTNode *node) {
    if (node == NULL) return NULL;

    char *v1, *v2, *temp, *lbl_true, *lbl_false, *lbl_end;
    Symbol *sym;

    switch(node->type) {
        case NODE_PROGRAMA:
        case NODE_BLOCO:
            {
                ASTNode *aux = node->left;
                while (aux != NULL) {
                    gera_codigo(aux);
                    aux = aux->next;
                }
            }
            return NULL;

        case NODE_ATRIBUICAO:
            v2 = gera_codigo(node->right);
            if (node->left->type == NODE_VAR) {
                sym = sym_lookup(node->left->value);
                printf("  mov %%r%d, %s\n", sym->addr, v2);
            } else if (node->left->type == NODE_VETOR_ACESSO) {
                sym = sym_lookup(node->left->left->value);
                v1 = gera_codigo(node->left->right);
                /* CORREÇÃO: Usar literal (%d) não registrador (%%r%d) para a base */
                printf("  store %s, %s(%d)\n", v2, v1, sym->addr);
            }
            return NULL;

        case NODE_VAR:
            sym = sym_lookup(node->value);
            temp = (char*)malloc(20);
            sprintf(temp, "%%r%d", sym->addr);
            return temp;

        case NODE_CONST_INT:
            return node->value;

        case NODE_VETOR_ACESSO:
            sym = sym_lookup(node->left->value);
            v2 = gera_codigo(node->right);
            temp = new_temp();
            /* CORREÇÃO: Usar literal (%d) não registrador (%%r%d) para a base */
            printf("  load %s, %s(%d)\n", temp, v2, sym->addr);
            return temp;

        case NODE_OP_SOMA:
        case NODE_OP_SUB:
        case NODE_OP_MULT:
        case NODE_OP_DIV:
        case NODE_OP_MOD:
            v1 = gera_codigo(node->left);
            v2 = gera_codigo(node->right);
            temp = new_temp();
            char *op = "add";
            if (node->type == NODE_OP_SUB) op = "sub";
            if (node->type == NODE_OP_MULT) op = "mult";
            if (node->type == NODE_OP_DIV) op = "div";
            if (node->type == NODE_OP_MOD) op = "mod";
            printf("  %s %s, %s, %s\n", op, temp, v1, v2);
            return temp;

        case NODE_OP_MAIOR:
        case NODE_OP_MENOR:
        case NODE_OP_IGUAL:
        case NODE_OP_DIFERENTE:
        case NODE_OP_E:
        case NODE_OP_OU:
        case NODE_OP_MAIOR_IGUAL:
        case NODE_OP_MENOR_IGUAL:
            v1 = gera_codigo(node->left);
            v2 = gera_codigo(node->right);
            temp = new_temp();
            char *cmd = "equal";
            if (node->type == NODE_OP_MAIOR) cmd = "greater";
            if (node->type == NODE_OP_MENOR) cmd = "less";
            if (node->type == NODE_OP_DIFERENTE) cmd = "diff";
            if (node->type == NODE_OP_E) cmd = "and";
            if (node->type == NODE_OP_OU) cmd = "or";
            if (node->type == NODE_OP_MAIOR_IGUAL) cmd = "greatereq";
            if (node->type == NODE_OP_MENOR_IGUAL) cmd = "lesseq";
            printf("  %s %s, %s, %s\n", cmd, temp, v1, v2);
            return temp;

        case NODE_IF:
            lbl_false = new_label();
            lbl_end = new_label();
            v1 = gera_codigo(node->left);
            printf("  jf %s, %s\n", v1, lbl_false);
            gera_codigo(node->right);
            if (node->extra != NULL) printf("  jump %s\n", lbl_end);
            printf("  label %s\n", lbl_false);
            if (node->extra != NULL) {
                gera_codigo(node->extra);
                printf("  label %s\n", lbl_end);
            }
            return NULL;

        case NODE_WHILE:
            lbl_true = new_label();
            lbl_end = new_label();
            printf("  label %s\n", lbl_true);
            v1 = gera_codigo(node->left);
            printf("  jf %s, %s\n", v1, lbl_end);
            gera_codigo(node->right);
            printf("  jump %s\n", lbl_true);
            printf("  label %s\n", lbl_end);
            return NULL;
            
        case NODE_FOR:
            lbl_true = new_label();
            lbl_end = new_label();
            if (node->left != NULL) gera_codigo(node->left);
            printf("  label %s\n", lbl_true);
            if (node->right != NULL) {
                v1 = gera_codigo(node->right);
                printf("  jf %s, %s\n", v1, lbl_end);
            }
            gera_codigo(node->extra);
            printf("  jump %s\n", lbl_true);
            printf("  label %s\n", lbl_end);
            return NULL;

        case NODE_CAPTURA:
            if (node->left->type == NODE_VAR) {
                sym = sym_lookup(node->left->value);
                printf("  read %%r%d\n", sym->addr);
            }
            else if (node->left->type == NODE_VETOR_ACESSO) {
                temp = new_temp();
                printf("  read %s\n", temp);
                sym = sym_lookup(node->left->left->value); /* Nome */
                v1 = gera_codigo(node->left->right);       /* Indice */
                printf("  store %s, %s(%d)\n", temp, v1, sym->addr);
            }
            return NULL;

        case NODE_ARREMESSE:
            {
                ASTNode *arg = node->left;
                while (arg != NULL) {
                    if (arg->type == NODE_STRING) {
                        printf("  printf %s\n", arg->value);
                    } else {
                        v1 = gera_codigo(arg);
                        printf("  printv %s\n", v1);
                    }
                    arg = arg->next;
                }
            }
            return NULL;
            
        case NODE_STRING:
            return node->value;

        default:
            return NULL;
    }
}

int main(int argc, char **argv) {
    if (yyparse() == 0) {
        /* Sucesso */
    }
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro na linha %d: %s\n", yyline, s);
}
