/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "compiler.y"

void yyerror (char *s);
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include <string.h>
#include "tree.h"

extern struct scope_tree a_scope_treet;
extern struct sym_tab a_symbol_table;
extern int max_scope;

FILE *error, *output, *warn, *Sym_Table;

struct stack scope_stack;

int line_cnt;

/* Line 371 of yacc.c  */
#line 86 "compiler.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "compiler.tab.h".  */
#ifndef YY_YY_COMPILER_TAB_H_INCLUDED
# define YY_YY_COMPILER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CONST = 258,
     INT = 259,
     FLOAT = 260,
     CHAR = 261,
     BOOL = 262,
     FOR = 263,
     WHILE = 264,
     DO = 265,
     IF = 266,
     SWITCH = 267,
     BREAK = 268,
     DEFAULT = 269,
     CONTINUE = 270,
     CASE = 271,
     GOTO = 272,
     ELSE = 273,
     LE_OP = 274,
     GE_OP = 275,
     EQ_OP = 276,
     NE_OP = 277,
     AND_OP = 278,
     OR_OP = 279,
     XOR_OP = 280,
     LEFT_OP = 281,
     RIGHT_OP = 282,
     MAIN = 283,
     TRUE = 284,
     FALSE = 285,
     CHAR_VAL = 286,
     f_number = 287,
     number = 288,
     identifier = 289
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 20 "compiler.y"
int num; float f_num; struct tree * a_tree; char* str; int bool_val; char char_val;

/* Line 387 of yacc.c  */
#line 166 "compiler.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_COMPILER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 194 "compiler.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   466

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,     2,     2,     2,     2,     2,
      35,    36,    42,    43,     2,    40,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    47,
      44,    46,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    11,    13,    15,    17,    19,    21,    23,
      25,    29,    32,    35,    37,    41,    45,    47,    51,    55,
      57,    61,    65,    69,    73,    75,    79,    83,    85,    89,
      91,    95,    97,   101,   103,   105,   109,   111,   113,   119,
     125,   129,   133,   139,   143,   149,   153,   160,   167,   174,
     181,   183,   185,   187,   189,   191,   193,   195,   198,   201,
     204,   206,   211,   215,   218,   222,   224,   227,   229,   232,
     238,   246,   252,   258,   266,   273,   281,   286,   293,   299,
     306,   311,   318,   323,   325,   330,   335,   340
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,     4,    28,    35,    36,    37,    69,    38,
      -1,    33,    -1,    32,    -1,    34,    -1,    29,    -1,    30,
      -1,    31,    -1,    52,    -1,    35,    63,    36,    -1,    39,
      51,    -1,    40,    51,    -1,    51,    -1,    53,    41,    51,
      -1,    53,    42,    51,    -1,    53,    -1,    54,    43,    53,
      -1,    54,    40,    53,    -1,    54,    -1,    55,    44,    54,
      -1,    55,    45,    54,    -1,    55,    19,    54,    -1,    55,
      20,    54,    -1,    55,    -1,    56,    21,    55,    -1,    56,
      22,    55,    -1,    56,    -1,    57,    25,    56,    -1,    57,
      -1,    58,    23,    57,    -1,    58,    -1,    59,    24,    58,
      -1,    59,    -1,    60,    -1,    34,    46,    62,    -1,    60,
      -1,    62,    -1,     4,    34,    46,    62,    47,    -1,     5,
      34,    46,    62,    47,    -1,     4,    34,    47,    -1,     5,
      34,    47,    -1,     7,    34,    46,    62,    47,    -1,     7,
      34,    47,    -1,     6,    34,    46,    62,    47,    -1,     6,
      34,    47,    -1,     3,     4,    34,    46,    62,    47,    -1,
       3,     5,    34,    46,    62,    47,    -1,     3,     6,    34,
      46,    62,    47,    -1,     3,     7,    34,    46,    62,    47,
      -1,    67,    -1,    68,    -1,    70,    -1,    71,    -1,    72,
      -1,    64,    -1,    65,    -1,    13,    47,    -1,     1,    47,
      -1,     1,    38,    -1,    73,    -1,    16,    61,    48,    66,
      -1,    14,    48,    66,    -1,    37,    38,    -1,    37,    69,
      38,    -1,    66,    -1,    69,    66,    -1,    47,    -1,    63,
      47,    -1,    11,    35,    63,    36,    68,    -1,    11,    35,
      63,    36,    68,    18,    68,    -1,    12,    35,    63,    36,
      68,    -1,     9,    35,    63,    36,    68,    -1,    10,    68,
       9,    35,    63,    36,    47,    -1,     8,    35,    70,    70,
      36,    68,    -1,     8,    35,    70,    70,    63,    36,    68,
      -1,     9,    63,    36,    68,    -1,    10,    68,     9,    63,
      36,    47,    -1,     8,    70,    70,    36,    68,    -1,     8,
      70,    70,    63,    36,    68,    -1,    11,    63,    36,    68,
      -1,    11,    63,    36,    68,    18,    68,    -1,    12,    63,
      36,    68,    -1,    63,    -1,     4,    34,    62,    47,    -1,
       5,    34,    62,    47,    -1,     7,    34,    62,    47,    -1,
       6,    34,    62,    47,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    51,    51,    56,    57,    58,    59,    60,    61,    62,
      63,    66,    67,    71,    72,    73,    76,    77,    78,    88,
      89,    90,    91,    92,    96,    97,    98,   102,   103,   107,
     108,   112,   113,   116,   119,   123,   124,   127,   134,   138,
     142,   147,   151,   155,   159,   163,   169,   170,   171,   172,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   189,   190,   193,   194,   197,   198,   201,   202,   205,
     206,   207,   212,   213,   214,   215,   220,   221,   222,   223,
     224,   225,   226,   227,   229,   230,   231,   232
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONST", "INT", "FLOAT", "CHAR", "BOOL",
  "FOR", "WHILE", "DO", "IF", "SWITCH", "BREAK", "DEFAULT", "CONTINUE",
  "CASE", "GOTO", "ELSE", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "XOR_OP", "LEFT_OP", "RIGHT_OP", "MAIN", "TRUE", "FALSE",
  "CHAR_VAL", "f_number", "number", "identifier", "'('", "')'", "'{'",
  "'}'", "'!'", "'-'", "'/'", "'*'", "'+'", "'<'", "'>'", "'='", "';'",
  "':'", "$accept", "main_func", "factor", "unary_exp", "mul_exp",
  "add_exp", "relational_exp", "equality_exp", "xor_exp", "and_exp",
  "or_exp", "conditional_exp", "constant_expression", "assignment",
  "expression", "declaration", "constant_declaration", "statement",
  "labeled_statement", "compound_statement", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "error_statement", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    40,    41,   123,   125,    33,
      45,    47,    42,    43,    60,    62,    61,    59,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    52,    52,    53,    53,    53,    54,    54,    54,    55,
      55,    55,    55,    55,    56,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    61,    62,    62,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    65,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    71,    72,    72,    72,    72,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     2,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     3,     1,     1,     5,     5,
       3,     3,     5,     3,     5,     3,     6,     6,     6,     6,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       1,     4,     3,     2,     3,     1,     2,     1,     2,     5,
       7,     5,     5,     7,     6,     7,     4,     6,     5,     6,
       4,     6,     4,     1,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     7,     8,     4,     3,     5,     0,     0,
       0,     0,    67,    13,     9,    16,    19,    24,    27,    29,
      31,    33,    36,    37,    83,    55,    56,    65,    50,    51,
       0,    52,    53,    54,    60,    59,    58,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     5,    34,     0,
       0,     0,    63,     0,    11,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
       2,    66,     0,     0,     0,     0,     0,    40,     0,     0,
      41,     0,     0,    45,     0,     0,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,     0,
      35,    10,    64,    14,    15,    18,    17,    22,    23,    20,
      21,    25,    26,    28,    30,    32,     0,     0,     0,     0,
       0,    84,     0,    85,     0,    87,     0,    86,     0,     0,
       0,    10,    76,     0,     0,    10,    80,    10,    82,    61,
       0,     0,     0,     0,    38,    39,    44,    42,     0,     0,
      78,     0,    72,     0,     0,    69,     0,    71,    46,    47,
      48,    49,    74,     0,    79,    10,    77,     0,    81,    75,
      73,    70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    79,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -48
static const yytype_int16 yypact[] =
{
      -3,   -21,    14,    -2,   -48,    12,    17,   314,   -34,    19,
      24,    30,    34,    40,   352,   257,    41,   302,   390,    32,
      29,   402,   -48,   -48,   -48,   -48,   -48,    35,   414,   179,
     402,   402,   -48,   -48,   -48,    -4,    -8,   -14,     6,    55,
      60,    61,   -48,   -48,    37,   -48,   -48,   -48,   -48,   -48,
     224,   -48,   -48,   -48,   -48,   -48,   -48,    52,    62,    65,
      74,    10,    58,    89,   333,   371,    37,   371,   414,    59,
      85,   414,    76,   414,    79,   -48,   314,   -48,   -48,    68,
     414,    90,   -48,   269,   -48,   -48,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   -48,
     -48,   -48,    64,    81,    84,    86,   414,   -48,    78,   414,
     -48,    87,   414,   -48,    91,   414,   -48,    92,   -26,   371,
     167,    95,    41,   426,    97,    41,   101,    41,   -48,   314,
     -48,   -48,   -48,   -48,   -48,    -4,    -4,    -8,    -8,    -8,
      -8,   -14,   -14,     6,    55,    60,   414,   414,   414,   414,
      93,   -48,    94,   -48,    99,   -48,   100,   -48,   212,    41,
     106,    41,   -48,   414,   108,    41,   130,    41,   -48,   -48,
     103,   107,   109,   111,   -48,   -48,   -48,   -48,    41,   117,
     -48,    41,   -48,   119,   112,   142,    41,   -48,   -48,   -48,
     -48,   -48,   -48,    41,   -48,   114,   -48,    41,   -48,   -48,
     -48,   -48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -48,   -48,   -11,   -48,   -42,   -20,   -43,    67,    69,    66,
     -48,   146,   -48,   -46,    -6,   -48,   -48,   -47,   -48,   -16,
     139,   -12,   -48,   -48,   -48
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      70,     1,    67,   101,    55,    90,    91,     3,    66,    69,
     131,    72,    74,    56,     4,   108,   111,   114,   117,    84,
      85,    99,    81,    57,    58,    59,    60,    94,    95,   128,
      92,    93,    88,     5,   130,    89,   101,    86,    87,    22,
      23,    24,    25,    26,    27,    28,   135,   136,     6,    30,
      31,   141,   142,   119,     7,   120,   106,   107,    61,   118,
     150,    66,   121,   152,    62,   124,   154,   126,    63,   156,
     137,   138,   139,   140,    64,   133,   134,    76,    29,    75,
      96,    80,   169,    97,    99,    98,   102,    22,    23,    24,
      25,    26,    27,    28,   123,   122,   103,    30,    31,   104,
     170,   171,   172,   173,   109,   110,   162,   158,   105,   166,
     146,   168,   125,    66,   160,   127,   129,   164,    22,    23,
      24,    25,    26,    27,    28,   151,   131,   147,    30,    31,
     148,   161,   149,   165,   153,   112,   113,   167,   155,   157,
     174,   175,   181,   180,   184,   182,   176,   177,   186,   185,
     188,   187,   179,   193,   189,   195,   190,   183,   191,   196,
     197,   200,   192,   143,   145,   194,   144,    78,    83,     0,
     198,     0,     0,     0,     0,     0,     0,   199,     0,     0,
       8,   201,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,    21,    22,    23,    24,    25,
      26,    27,    28,   159,     0,     0,    30,    31,    22,    23,
      24,    25,    26,    27,    28,     0,    29,    82,    30,    31,
       0,     0,     0,     0,     0,     8,    32,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
      21,    22,    23,    24,    25,    26,    27,    28,   178,     0,
       0,    30,    31,    22,    23,    24,    25,    26,    27,    28,
       0,    29,   100,    30,    31,     0,     0,     0,     0,     0,
       8,    32,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,    21,    22,    23,    24,    25,
      26,    27,    68,     0,     0,     0,    30,    31,    22,    23,
      24,    25,    26,    27,    28,     0,    29,   132,    30,    31,
       0,     0,     0,     0,     0,     8,    32,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
      21,    22,    23,    24,    25,    26,    27,    71,     0,     0,
       0,    30,    31,    22,    23,    24,    25,    26,    27,    28,
       0,    29,     0,    30,    31,     0,     0,     0,     0,     0,
       0,    32,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    30,    31,     0,     0,     0,     0,     0,   115,
     116,    22,    23,    24,    25,    26,    27,    65,     0,     0,
       0,    30,    31,     0,     0,     0,     0,     0,     0,    32,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      30,    31,     0,     0,     0,     0,     0,     0,    32,    22,
      23,    24,    25,    26,    27,    73,     0,     0,     0,    30,
      31,    22,    23,    24,    25,    26,    77,    28,     0,     0,
       0,    30,    31,    22,    23,    24,    25,    26,    27,    28,
       0,     0,     0,    30,    31,    22,    23,    24,    25,    26,
      27,   163,     0,     0,     0,    30,    31
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-48)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      16,     4,    14,    50,    38,    19,    20,    28,    14,    15,
      36,    17,    18,    47,     0,    61,    62,    63,    64,    30,
      31,    47,    28,     4,     5,     6,     7,    21,    22,    76,
      44,    45,    40,    35,    80,    43,    83,    41,    42,    29,
      30,    31,    32,    33,    34,    35,    88,    89,    36,    39,
      40,    94,    95,    65,    37,    67,    46,    47,    34,    65,
     106,    67,    68,   109,    34,    71,   112,    73,    34,   115,
      90,    91,    92,    93,    34,    86,    87,    48,    37,    47,
      25,    46,   129,    23,    47,    24,    34,    29,    30,    31,
      32,    33,    34,    35,     9,    36,    34,    39,    40,    34,
     146,   147,   148,   149,    46,    47,   122,   119,    34,   125,
      46,   127,    36,   119,   120,    36,    48,   123,    29,    30,
      31,    32,    33,    34,    35,    47,    36,    46,    39,    40,
      46,    36,    46,    36,    47,    46,    47,    36,    47,    47,
      47,    47,    36,   159,    36,   161,    47,    47,    18,   165,
      47,   167,   158,    36,    47,    36,    47,   163,    47,    47,
      18,    47,   178,    96,    98,   181,    97,    21,    29,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
       1,   197,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    40,    29,    30,
      31,    32,    33,    34,    35,    -1,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,     1,    47,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    40,    29,    30,    31,    32,    33,    34,    35,
      -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
       1,    47,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    29,    30,
      31,    32,    33,    34,    35,    -1,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,     1,    47,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    40,    29,    30,    31,    32,    33,    34,    35,
      -1,    37,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    46,
      47,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    40,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    40,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    50,    28,     0,    35,    36,    37,     1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    16,    29,    30,    31,    32,    33,    34,    35,    37,
      39,    40,    47,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    38,    47,     4,     5,     6,
       7,    34,    34,    34,    34,    35,    63,    70,    35,    63,
      68,    35,    63,    35,    63,    47,    48,    34,    60,    61,
      46,    63,    38,    69,    51,    51,    41,    42,    40,    43,
      19,    20,    44,    45,    21,    22,    25,    23,    24,    47,
      38,    66,    34,    34,    34,    34,    46,    47,    62,    46,
      47,    62,    46,    47,    62,    46,    47,    62,    63,    70,
      70,    63,    36,     9,    63,    36,    63,    36,    66,    48,
      62,    36,    38,    51,    51,    53,    53,    54,    54,    54,
      54,    55,    55,    56,    57,    58,    46,    46,    46,    46,
      62,    47,    62,    47,    62,    47,    62,    47,    70,    36,
      63,    36,    68,    35,    63,    36,    68,    36,    68,    66,
      62,    62,    62,    62,    47,    47,    47,    47,    36,    63,
      68,    36,    68,    63,    36,    68,    18,    68,    47,    47,
      47,    47,    68,    36,    68,    36,    47,    18,    68,    68,
      47,    68
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
      yychar = YYLEX;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 51 "compiler.y"
    {get_TAC((yyvsp[(6) - (7)].a_tree), 0, 0, 0);}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 56 "compiler.y"
    {(yyval.a_tree) = make_number((yyvsp[(1) - (1)].num));}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 57 "compiler.y"
    {(yyval.a_tree) = make_f_number((yyvsp[(1) - (1)].f_num));}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 58 "compiler.y"
    {(yyval.a_tree) = make_variable((yyvsp[(1) - (1)].str));}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 59 "compiler.y"
    {(yyval.a_tree) = make_bool((yyvsp[(1) - (1)].bool_val));}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 60 "compiler.y"
    {(yyval.a_tree) = make_bool((yyvsp[(1) - (1)].bool_val));}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 61 "compiler.y"
    {(yyval.a_tree) = make_char((yyvsp[(1) - (1)].char_val));}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 62 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 63 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(2) - (3)].a_tree);}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 66 "compiler.y"
    {(yyval.a_tree) = make_uni_operator((yyvsp[(2) - (2)].a_tree), not);}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 67 "compiler.y"
    {(yyval.a_tree) = make_uni_operator((yyvsp[(2) - (2)].a_tree), minus);}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 71 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 72 "compiler.y"
    {(yyval.a_tree) = make_operator((yyvsp[(1) - (3)].a_tree), over, (yyvsp[(3) - (3)].a_tree));}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 73 "compiler.y"
    {(yyval.a_tree) = make_operator((yyvsp[(1) - (3)].a_tree), star, (yyvsp[(3) - (3)].a_tree));}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 76 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 77 "compiler.y"
    {(yyval.a_tree) = make_operator((yyvsp[(1) - (3)].a_tree), plus, (yyvsp[(3) - (3)].a_tree));}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 78 "compiler.y"
    {(yyval.a_tree) = make_operator((yyvsp[(1) - (3)].a_tree), minus, (yyvsp[(3) - (3)].a_tree));}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 88 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 89 "compiler.y"
    {(yyval.a_tree) = make_operator((yyvsp[(1) - (3)].a_tree), LT,  (yyvsp[(3) - (3)].a_tree));}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 90 "compiler.y"
    {(yyval.a_tree) = make_operator((yyvsp[(1) - (3)].a_tree), GT,  (yyvsp[(3) - (3)].a_tree));}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 91 "compiler.y"
    {(yyval.a_tree) = make_operator((yyvsp[(1) - (3)].a_tree), LTE,  (yyvsp[(3) - (3)].a_tree));}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 92 "compiler.y"
    {(yyval.a_tree) = make_operator((yyvsp[(1) - (3)].a_tree), GTE,  (yyvsp[(3) - (3)].a_tree));}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 96 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 97 "compiler.y"
    {(yyval.a_tree) = make_operator((yyvsp[(1) - (3)].a_tree), EQEQ,  (yyvsp[(3) - (3)].a_tree));}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 98 "compiler.y"
    {(yyval.a_tree) = make_operator((yyvsp[(1) - (3)].a_tree), NE,  (yyvsp[(3) - (3)].a_tree));}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 102 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 103 "compiler.y"
    {(yyval.a_tree) = make_operator((yyvsp[(1) - (3)].a_tree), xor, (yyvsp[(3) - (3)].a_tree));}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 107 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 108 "compiler.y"
    {(yyval.a_tree) = make_operator((yyvsp[(1) - (3)].a_tree), and, (yyvsp[(3) - (3)].a_tree));}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 112 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 113 "compiler.y"
    {(yyval.a_tree) = make_operator((yyvsp[(1) - (3)].a_tree), or, (yyvsp[(3) - (3)].a_tree));}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 116 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 119 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 123 "compiler.y"
    {(yyval.a_tree) = make_operator(make_variable((yyvsp[(1) - (3)].str)), EQ, (yyvsp[(3) - (3)].a_tree));}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 124 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 127 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 134 "compiler.y"
    {
                                                    (yyval.a_tree) = make_alloc(make_variable((yyvsp[(2) - (5)].str)), (yyvsp[(4) - (5)].a_tree), integer);
                                                   //insert_symbol(make_symbol($2, integer));
                                                }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 138 "compiler.y"
    {
                                                   (yyval.a_tree) = make_alloc(make_variable((yyvsp[(2) - (5)].str)), (yyvsp[(4) - (5)].a_tree), numeric);
                                                   /*//insert_symbol(make_symbol($2, numeric));*/
                                                }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 142 "compiler.y"
    {

                                                   (yyval.a_tree) = make_alloc(make_variable((yyvsp[(2) - (3)].str)), NULL, integer);
                                                   //insert_symbol(make_symbol($2, integer));
                                                    }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 147 "compiler.y"
    {
                                                   (yyval.a_tree) = make_alloc(make_variable((yyvsp[(2) - (3)].str)), NULL, numeric);
                                                   //insert_symbol(make_symbol($2, numeric));
                                               }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 151 "compiler.y"
    {
                                                   (yyval.a_tree) = make_alloc(make_variable((yyvsp[(2) - (5)].str)), (yyvsp[(4) - (5)].a_tree), boolean);
                                                   //insert_symbol(make_symbol($2, boolean));
                                                }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 155 "compiler.y"
    {
                                                   (yyval.a_tree) = make_alloc(make_variable((yyvsp[(2) - (3)].str)), NULL, boolean);
                                                   //insert_symbol(make_symbol($2, boolean));
                                               }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 159 "compiler.y"
    {
                                                   (yyval.a_tree) = make_alloc(make_variable((yyvsp[(2) - (5)].str)), (yyvsp[(4) - (5)].a_tree), character);
                                                   //insert_symbol(make_symbol($2, character));
                                               }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 163 "compiler.y"
    {
                                                   (yyval.a_tree) = make_alloc(make_variable((yyvsp[(2) - (3)].str)), NULL, character);
                                                   //insert_symbol(make_symbol($2, character));
                                               }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 169 "compiler.y"
    {(yyval.a_tree) = make_const(make_variable((yyvsp[(3) - (6)].str)), (yyvsp[(5) - (6)].a_tree), integer);}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 170 "compiler.y"
    {(yyval.a_tree) = make_const(make_variable((yyvsp[(3) - (6)].str)), (yyvsp[(5) - (6)].a_tree), numeric);}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 171 "compiler.y"
    {(yyval.a_tree) = make_const(make_variable((yyvsp[(3) - (6)].str)), (yyvsp[(5) - (6)].a_tree), character);}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 172 "compiler.y"
    {(yyval.a_tree) = make_const(make_variable((yyvsp[(3) - (6)].str)), (yyvsp[(5) - (6)].a_tree), boolean);}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 176 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 177 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 178 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 179 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 180 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 181 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 182 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (1)].a_tree);}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 183 "compiler.y"
    {(yyval.a_tree) = make_break();}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 184 "compiler.y"
    {(yyval.a_tree) = NULL;}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 185 "compiler.y"
    {(yyval.a_tree) = NULL;}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 186 "compiler.y"
    {(yyval.a_tree) = NULL;}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 189 "compiler.y"
    {(yyval.a_tree) = make_case((yyvsp[(2) - (4)].a_tree), (yyvsp[(4) - (4)].a_tree));}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 190 "compiler.y"
    {(yyval.a_tree) = make_default((yyvsp[(3) - (3)].a_tree));}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 193 "compiler.y"
    {(yyval.a_tree) = make_compund_stmt(NULL);}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 194 "compiler.y"
    {(yyval.a_tree) = make_compund_stmt((yyvsp[(2) - (3)].a_tree));}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 197 "compiler.y"
    {(yyval.a_tree) = make_list((yyvsp[(1) - (1)].a_tree)); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 198 "compiler.y"
    {(yyval.a_tree) = add_child_to_list((yyvsp[(1) - (2)].a_tree), (yyvsp[(2) - (2)].a_tree));}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 201 "compiler.y"
    {(yyval.a_tree) = NULL;}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 202 "compiler.y"
    {(yyval.a_tree) = (yyvsp[(1) - (2)].a_tree);}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 205 "compiler.y"
    {(yyval.a_tree) = make_if((yyvsp[(3) - (5)].a_tree), (yyvsp[(5) - (5)].a_tree));}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 206 "compiler.y"
    {(yyval.a_tree) = make_if_else((yyvsp[(3) - (7)].a_tree), (yyvsp[(5) - (7)].a_tree), (yyvsp[(7) - (7)].a_tree));}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 207 "compiler.y"
    {(yyval.a_tree) = make_switch((yyvsp[(3) - (5)].a_tree), ((yyvsp[(5) - (5)].a_tree))->body.a_compund_stmt.stmt);}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 212 "compiler.y"
    {(yyval.a_tree) = make_while((yyvsp[(3) - (5)].a_tree), (yyvsp[(5) - (5)].a_tree));}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 213 "compiler.y"
    {(yyval.a_tree) = make_do_while((yyvsp[(5) - (7)].a_tree), (yyvsp[(2) - (7)].a_tree));}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 214 "compiler.y"
    {(yyval.a_tree) = make_for((yyvsp[(3) - (6)].a_tree), (yyvsp[(4) - (6)].a_tree), NULL, (yyvsp[(6) - (6)].a_tree));}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 215 "compiler.y"
    {(yyval.a_tree) = make_for((yyvsp[(3) - (7)].a_tree), (yyvsp[(4) - (7)].a_tree), (yyvsp[(5) - (7)].a_tree), (yyvsp[(7) - (7)].a_tree));}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 220 "compiler.y"
    {(yyval.a_tree) = NULL; fprintf(error, "expected \'(\'\n");}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 221 "compiler.y"
    {(yyval.a_tree) = NULL; fprintf(error, "expected \'(\'\n");}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 222 "compiler.y"
    {(yyval.a_tree) = NULL; fprintf(error, "expected \'(\'\n");}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 223 "compiler.y"
    {fprintf(error, "expected \'(\'\n"); (yyval.a_tree)= NULL;}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 224 "compiler.y"
    {(yyval.a_tree) = NULL; fprintf(error, "expected \'(\'\n");}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 225 "compiler.y"
    {(yyval.a_tree) = NULL; fprintf(error, "expected \'(\'\n");}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 226 "compiler.y"
    {(yyval.a_tree) = NULL; fprintf(error, "expected \'(\'\n");}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 227 "compiler.y"
    {(yyval.a_tree) = NULL; fprintf(error, "expected ;\n");}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 229 "compiler.y"
    {(yyval.a_tree) = NULL; fprintf(error, "expected =\n");}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 230 "compiler.y"
    {(yyval.a_tree) = NULL; fprintf(error, "expected =\n");}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 231 "compiler.y"
    {(yyval.a_tree) = NULL; fprintf(error, "expected =\n");}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 232 "compiler.y"
    {(yyval.a_tree) = NULL; fprintf(error, "expected =\n");}
    break;


/* Line 1792 of yacc.c  */
#line 2150 "compiler.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 239 "compiler.y"
                     /* C code */

int main (void){
    line_cnt = 1;
    max_scope = 0;
    cur_reg_id = 0;
    cur_label_id = 0;


    output = fopen("out.txt", "w");
    error = fopen("errors.txt", "w");
	warn = fopen("warns.txt", "w");
	Sym_Table = fopen("sym_tab.txt", "w");

    init_table(&a_symbol_table);
    init_scope_tree(&a_scope_tree, 0);

    /* -------------------------- */
    yyparse ( );

	write_sym_tab(Sym_Table, &a_symbol_table);

    fclose(error);
	fclose(warn);
	fclose(Sym_Table);
    fclose(output);
    return 0;
}

void yyerror (char *s) {
	fprintf(error, "syntex error:line:%d\n", line_cnt);
}
