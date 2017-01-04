/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _PROGRAM = 258,
     _BREAK = 259,
     _CLASS = 260,
     _CONST = 261,
     _NEW = 262,
     _PRINT = 263,
     _READ = 264,
     _VOID = 265,
     _WHILE = 266,
     _EXTENDS = 267,
     _IF = 268,
     _ELSE = 269,
     _RETURN = 270,
     _TYPE = 271,
     _ID = 272,
     _NUMBER = 273,
     _CHAR_CONST = 274,
     _BOOL_CONST = 275,
     _STRING_CONST = 276,
     _PLUS = 277,
     _MINUS = 278,
     _TIMES = 279,
     _DIV = 280,
     _MOD = 281,
     _RELOP = 282,
     _AND = 283,
     _OR = 284,
     _ASSIGN = 285,
     _INCREMENT = 286,
     _DECREMENT = 287,
     _SEMICOLON = 288,
     _COMMA = 289,
     _DOT = 290,
     _LPAREN = 291,
     _RPAREN = 292,
     _LSQBRACKET = 293,
     _RSQBRACKET = 294,
     _LBRACKET = 295,
     _RBRACKET = 296
   };
#endif
/* Tokens.  */
#define _PROGRAM 258
#define _BREAK 259
#define _CLASS 260
#define _CONST 261
#define _NEW 262
#define _PRINT 263
#define _READ 264
#define _VOID 265
#define _WHILE 266
#define _EXTENDS 267
#define _IF 268
#define _ELSE 269
#define _RETURN 270
#define _TYPE 271
#define _ID 272
#define _NUMBER 273
#define _CHAR_CONST 274
#define _BOOL_CONST 275
#define _STRING_CONST 276
#define _PLUS 277
#define _MINUS 278
#define _TIMES 279
#define _DIV 280
#define _MOD 281
#define _RELOP 282
#define _AND 283
#define _OR 284
#define _ASSIGN 285
#define _INCREMENT 286
#define _DECREMENT 287
#define _SEMICOLON 288
#define _COMMA 289
#define _DOT 290
#define _LPAREN 291
#define _RPAREN 292
#define _LSQBRACKET 293
#define _RSQBRACKET 294
#define _LBRACKET 295
#define _RBRACKET 296




/* Copy the first part of user declarations.  */
#line 4 "parser.y"

    #include <stdio.h>
    #include "defs.h"
    #include "symtab.h"
    #include "semantic.h"

    int yyparse(void);
    int yylex(void);
    int yyerror(char *s);
    void warning(char *s);

    extern int line;
    int error_count = 0;
    char char_buffer[CHAR_BUFFER_LENGTH];
    int level = GLOBAL_LEVEL;
    int var_num = 0;
    int arg_num = 0;
    int par_num = 0;

    char* call_table = NULL;
    int function_index = -1;
    int function_call_index = -1;

    char* parent_class = NULL;
    unsigned tmp_type = NO_TYPE;

    int variable_index = -1;

    int while_flag = 0;
    int return_flag = 0;

    int cond_error = 0;
    int cond_level = 0;

    int exp_error = 0;
    int exp_level = 0;

    int func_call = 0;

    Stack* variables;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 231 "y.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNRULES -- Number of states.  */
#define YYNSTATES  248

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    12,    13,    16,    24,    25,    31,    33,
      35,    37,    39,    40,    43,    48,    55,    60,    67,    68,
      72,    78,    79,    82,    83,    93,    94,   106,   107,   110,
     111,   112,   113,   126,   127,   128,   129,   142,   143,   145,
     149,   152,   157,   158,   161,   164,   166,   171,   177,   182,
     186,   190,   198,   210,   219,   220,   229,   232,   235,   239,
     245,   251,   259,   268,   278,   280,   284,   286,   290,   292,
     296,   298,   301,   304,   308,   311,   314,   316,   320,   324,
     327,   330,   334,   336,   339,   342,   346,   348,   352,   357,
     359,   361,   363,   365,   368,   374,   380,   381,   386,   388,
     389,   393,   395,   398,   401,   405,   407,   409,   411,   413,
     415
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,     3,    17,    44,    51,    48,    40,    55,
      41,    -1,    -1,    45,    44,    -1,     6,    16,    17,    30,
      47,    46,    33,    -1,    -1,    46,    34,    17,    30,    47,
      -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,    -1,
      49,    48,    -1,    16,    17,    50,    33,    -1,    16,    17,
      38,    39,    50,    33,    -1,    17,    17,    50,    33,    -1,
      17,    17,    38,    39,    50,    33,    -1,    -1,    34,    17,
      50,    -1,    34,    17,    38,    39,    50,    -1,    -1,    52,
      51,    -1,    -1,     5,    17,    53,    40,    48,    40,    55,
      41,    41,    -1,    -1,     5,    17,    12,    17,    54,    40,
      48,    40,    55,    41,    41,    -1,    -1,    56,    55,    -1,
      -1,    -1,    -1,    16,    17,    57,    36,    58,    63,    37,
      59,    48,    40,    65,    41,    -1,    -1,    -1,    -1,    10,
      17,    60,    36,    61,    63,    37,    62,    48,    40,    65,
      41,    -1,    -1,    64,    -1,    63,    34,    64,    -1,    16,
      17,    -1,    16,    17,    38,    39,    -1,    -1,    66,    65,
      -1,    80,    33,    -1,    49,    -1,    80,    30,    74,    33,
      -1,    80,    36,    69,    37,    33,    -1,    80,    36,    37,
      33,    -1,    80,    31,    33,    -1,    80,    32,    33,    -1,
      13,    36,    70,    37,    40,    65,    41,    -1,    13,    36,
      70,    37,    40,    65,    41,    14,    40,    65,    41,    -1,
      13,    36,    70,    37,    40,    65,    41,    68,    -1,    -1,
      11,    67,    36,    70,    37,    40,    65,    41,    -1,     4,
      33,    -1,    15,    33,    -1,    15,    74,    33,    -1,     9,
      36,    80,    37,    33,    -1,     8,    36,    74,    37,    33,
      -1,     8,    36,    74,    34,    18,    37,    33,    -1,    14,
      13,    36,    70,    37,    40,    65,    41,    -1,    68,    14,
      13,    36,    70,    37,    40,    65,    41,    -1,    74,    -1,
      69,    34,    74,    -1,    71,    -1,    70,    29,    71,    -1,
      72,    -1,    71,    28,    72,    -1,    74,    -1,    74,    73,
      -1,    84,    74,    -1,    73,    84,    74,    -1,    23,    76,
      -1,    22,    76,    -1,    76,    -1,    23,    76,    75,    -1,
      22,    76,    75,    -1,    76,    75,    -1,    85,    76,    -1,
      85,    76,    75,    -1,    78,    -1,    78,    77,    -1,    86,
      78,    -1,    86,    78,    77,    -1,    80,    -1,    80,    36,
      37,    -1,    80,    36,    69,    37,    -1,    18,    -1,    19,
      -1,    20,    -1,    21,    -1,     7,    17,    -1,     7,    17,
      38,    74,    39,    -1,     7,    16,    38,    74,    39,    -1,
      -1,    36,    79,    74,    37,    -1,    17,    -1,    -1,    17,
      81,    82,    -1,    83,    -1,    82,    83,    -1,    35,    17,
      -1,    38,    74,    39,    -1,    27,    -1,    22,    -1,    23,
      -1,    24,    -1,    25,    -1,    26,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,   100,   102,   106,   123,   125,   129,   134,
     139,   144,   151,   153,   157,   170,   182,   194,   208,   210,
     214,   220,   222,   227,   226,   243,   242,   258,   260,   265,
     277,   282,   264,   299,   311,   316,   298,   334,   336,   337,
     341,   355,   371,   373,   377,   378,   379,   386,   402,   418,
     428,   438,   439,   440,   442,   441,   449,   455,   456,   460,
     461,   462,   466,   467,   471,   477,   485,   490,   498,   502,
     509,   513,   523,   530,   543,   555,   566,   573,   584,   595,
     609,   623,   643,   647,   662,   666,   680,   689,   706,   724,
     729,   734,   739,   744,   748,   755,   763,   762,   774,   800,
     799,   822,   823,   827,   850,   859,   866,   870,   877,   878,
     879
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_PROGRAM", "_BREAK", "_CLASS", "_CONST",
  "_NEW", "_PRINT", "_READ", "_VOID", "_WHILE", "_EXTENDS", "_IF", "_ELSE",
  "_RETURN", "_TYPE", "_ID", "_NUMBER", "_CHAR_CONST", "_BOOL_CONST",
  "_STRING_CONST", "_PLUS", "_MINUS", "_TIMES", "_DIV", "_MOD", "_RELOP",
  "_AND", "_OR", "_ASSIGN", "_INCREMENT", "_DECREMENT", "_SEMICOLON",
  "_COMMA", "_DOT", "_LPAREN", "_RPAREN", "_LSQBRACKET", "_RSQBRACKET",
  "_LBRACKET", "_RBRACKET", "$accept", "Program", "ConstList", "ConstDecl",
  "ConstDeclList", "ConstType", "VarList", "VarDecl", "VarDeclList",
  "ClassList", "ClassDecl", "@1", "@2", "MethodDeclList", "MethodDecl",
  "@3", "@4", "@5", "@6", "@7", "@8", "FormPars", "FormPar", "Block",
  "Statement", "@9", "ElseIfList", "ActPars", "Condition", "CondTerm",
  "CondFact", "CondFactList", "Expression", "AddopTermList", "Term",
  "MulopFactorList", "Factor", "@10", "Designator", "@11",
  "DesignatorRepeatList", "DesignatorRepeat", "Relop", "Addop", "Mulop", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    46,    46,    47,    47,
      47,    47,    48,    48,    49,    49,    49,    49,    50,    50,
      50,    51,    51,    53,    52,    54,    52,    55,    55,    57,
      58,    59,    56,    60,    61,    62,    56,    63,    63,    63,
      64,    64,    65,    65,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    67,    66,    66,    66,    66,    66,
      66,    66,    68,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    74,    74,    74,    74,
      75,    75,    76,    76,    77,    77,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    79,    78,    80,    81,
      80,    82,    82,    83,    83,    84,    85,    85,    86,    86,
      86
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     0,     2,     7,     0,     5,     1,     1,
       1,     1,     0,     2,     4,     6,     4,     6,     0,     3,
       5,     0,     2,     0,     9,     0,    11,     0,     2,     0,
       0,     0,    12,     0,     0,     0,    12,     0,     1,     3,
       2,     4,     0,     2,     2,     1,     4,     5,     4,     3,
       3,     7,    11,     8,     0,     8,     2,     2,     3,     5,
       5,     7,     8,     9,     1,     3,     1,     3,     1,     3,
       1,     2,     2,     3,     2,     2,     1,     3,     3,     2,
       2,     3,     1,     2,     2,     3,     1,     3,     4,     1,
       1,     1,     1,     2,     5,     5,     0,     4,     1,     0,
       3,     1,     2,     2,     3,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     1,     0,    21,     3,     0,     0,
      12,    21,     4,     0,    23,     0,     0,     0,    12,    22,
       0,     0,     0,    18,    18,    27,    13,     8,     9,    10,
      11,     6,    25,    12,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,    18,    18,    14,    18,
      16,    33,    29,     2,    28,     5,     0,    12,    27,     0,
      19,     0,     0,     0,     0,     0,     0,     0,    18,    15,
      17,    34,    30,     0,    27,     0,    20,    37,    37,     7,
       0,    24,     0,     0,    38,     0,     0,    40,     0,    35,
      31,    26,     0,    39,    12,    12,    41,     0,     0,    42,
      42,     0,     0,     0,    54,     0,     0,    98,    45,     0,
      42,     0,     0,    56,     0,     0,     0,     0,     0,    98,
      89,    90,    91,    92,     0,     0,    57,    96,     0,    76,
      82,    86,     0,    36,    43,     0,     0,     0,    44,     0,
      32,     0,     0,     0,     0,    66,    68,    70,     0,    93,
      75,    74,     0,    58,   106,   107,    79,     0,   108,   109,
     110,    83,     0,     0,     0,     0,   100,   101,     0,    49,
      50,     0,     0,    64,     0,     0,     0,     0,     0,     0,
       0,   105,    71,     0,     0,     0,    78,    77,     0,    80,
      84,    87,     0,   103,     0,   102,    46,    48,     0,     0,
       0,    60,    59,     0,    67,    42,    69,     0,    72,     0,
       0,    97,    81,    85,    88,   104,    65,    47,     0,    42,
       0,    73,    95,    94,    61,     0,    51,    55,     0,    53,
       0,    42,     0,     0,     0,     0,     0,    52,     0,     0,
       0,    42,     0,     0,    42,    62,     0,    63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     7,    43,    31,    17,   108,    36,    10,
      11,    22,    44,    41,    42,    64,    78,    95,    63,    77,
      94,    83,    84,   109,   110,   116,   229,   172,   144,   145,
     146,   182,   147,   156,   129,   161,   130,   152,   131,   132,
     166,   167,   183,   157,   162
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -141
static const yytype_int16 yypact[] =
{
       7,     8,    71,    78,  -141,    83,   104,    78,    94,   108,
      53,   104,  -141,    99,   157,   124,   160,   127,    53,  -141,
     129,   161,   139,     3,    22,    10,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,    53,   163,   142,   149,   144,   151,   168,
     169,   146,    10,   118,   148,   152,    45,   156,  -141,   156,
    -141,  -141,  -141,  -141,  -141,  -141,   172,    53,    10,   154,
    -141,   158,   162,   164,   165,   166,   159,   153,   156,  -141,
    -141,  -141,  -141,   129,    10,   167,  -141,   181,   181,  -141,
     170,  -141,   185,    24,  -141,    48,   171,   175,   181,  -141,
    -141,  -141,   176,  -141,    53,    53,  -141,   174,   177,   155,
     155,   173,   180,   182,  -141,   183,    95,     1,  -141,   179,
     155,    64,   184,  -141,   117,   186,   187,   117,    87,    70,
    -141,  -141,  -141,  -141,   137,   137,  -141,  -141,   188,   138,
     150,   190,    84,  -141,  -141,   117,   189,   191,  -141,    27,
    -141,    89,   192,   117,    -6,   199,  -141,   178,   193,   194,
     138,   138,   117,  -141,  -141,  -141,  -141,   137,  -141,  -141,
    -141,  -141,   137,    55,   211,   117,    84,  -141,   197,  -141,
    -141,   200,    93,  -141,   216,   202,   203,    -2,   117,   198,
     117,  -141,   178,   117,   117,   117,  -141,  -141,   204,   138,
     150,  -141,   128,  -141,   201,  -141,  -141,  -141,   117,   206,
     205,  -141,  -141,   207,   199,   155,  -141,   117,  -141,   209,
     210,  -141,  -141,  -141,  -141,  -141,  -141,  -141,   212,   155,
     196,  -141,  -141,  -141,  -141,   213,   195,  -141,    -7,   229,
     208,   155,   233,   117,   214,   215,    28,  -141,   117,   217,
      30,   155,   218,   219,   155,  -141,   220,  -141
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,   243,  -141,  -141,   125,   -14,    -5,   -17,   241,
    -141,  -141,  -141,   -34,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,   126,   119,   -98,  -141,  -141,  -141,    47,  -140,    75,
      76,  -141,   -97,  -136,  -103,    69,   100,  -141,   -99,  -141,
    -141,    97,    82,  -141,  -141
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -100
static const yytype_int16 yytable[] =
{
     111,   111,   112,   177,    26,    18,   230,    38,    54,   128,
       1,   111,   134,    18,   186,   187,   142,   141,    24,    45,
      39,   150,   151,   178,    67,     3,    40,   178,    18,    60,
      61,   179,    62,   231,   118,   203,   -99,    34,   168,   -99,
      80,    35,   173,    66,   119,   120,   121,   122,   123,   124,
     125,    76,    18,   212,   189,   188,    34,   178,    88,   178,
      37,    89,   118,   127,   171,   239,   173,   242,   194,    15,
      16,     4,   119,   120,   121,   122,   123,   124,   125,    34,
      97,    98,    88,    59,     5,    90,   208,   209,   210,    18,
      18,   127,   191,   236,   135,   136,   137,   138,   240,     8,
     139,   216,   118,   148,   149,   -99,   111,   220,   -99,     9,
     221,    13,   119,   120,   121,   122,   123,   124,   125,   164,
     111,   225,   165,   174,   118,    14,   175,   198,   126,    20,
     199,   127,   111,   234,   119,   120,   121,   122,   123,   124,
     125,    23,   111,   243,   118,   111,   246,    27,    28,    29,
      30,    55,    56,   127,   119,   120,   121,   122,   123,   101,
     154,   155,   198,   102,   103,   214,   104,    25,   105,    21,
     106,    15,   107,   127,   158,   159,   160,    24,    32,    33,
      46,    47,    48,    49,    50,    51,    52,    53,    57,    65,
      34,    69,    58,    68,    75,    70,    73,    82,    79,    74,
      71,    72,    87,   119,    85,   181,   113,    93,    81,   228,
     192,    86,    91,    92,    99,    96,   114,   100,   115,   117,
     133,   153,   169,   143,   170,   140,   163,   180,   193,   176,
     196,   184,   185,   197,   200,   201,   202,   226,   205,   217,
     215,   211,   218,   232,   233,   224,   235,   219,   222,   223,
      12,   238,    19,   204,   227,   237,   206,   241,   244,   213,
     245,   247,   190,   195,   207
};

static const yytype_uint8 yycheck[] =
{
      99,   100,   100,   143,    18,    10,    13,    24,    42,   106,
       3,   110,   110,    18,   150,   151,   115,   114,    17,    33,
      10,   124,   125,    29,    58,    17,    16,    29,    33,    46,
      47,    37,    49,    40,     7,    37,    35,    34,   135,    38,
      74,    38,   139,    57,    17,    18,    19,    20,    21,    22,
      23,    68,    57,   189,   157,   152,    34,    29,    34,    29,
      38,    37,     7,    36,    37,    37,   163,    37,   165,    16,
      17,     0,    17,    18,    19,    20,    21,    22,    23,    34,
      94,    95,    34,    38,     6,    37,   183,   184,   185,    94,
      95,    36,    37,   233,    30,    31,    32,    33,   238,    16,
      36,   198,     7,    16,    17,    35,   205,   205,    38,     5,
     207,    17,    17,    18,    19,    20,    21,    22,    23,    35,
     219,   219,    38,    34,     7,    17,    37,    34,    33,    30,
      37,    36,   231,   231,    17,    18,    19,    20,    21,    22,
      23,    17,   241,   241,     7,   244,   244,    18,    19,    20,
      21,    33,    34,    36,    17,    18,    19,    20,    21,     4,
      22,    23,    34,     8,     9,    37,    11,    40,    13,    12,
      15,    16,    17,    36,    24,    25,    26,    17,    17,    40,
      17,    39,    33,    39,    33,    17,    17,    41,    40,    17,
      34,    33,    40,    39,    41,    33,    30,    16,    73,    40,
      36,    36,    17,    17,    78,    27,    33,    88,    41,    14,
     163,    41,    41,    38,    40,    39,    36,    40,    36,    36,
      41,    33,    33,    36,    33,    41,    36,    28,    17,    37,
      33,    38,    38,    33,    18,    33,    33,    41,    40,    33,
      39,    37,    37,    14,    36,    33,    13,    40,    39,    39,
       7,    36,    11,   178,    41,    41,   180,    40,    40,   190,
      41,    41,   162,   166,   182
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    43,    17,     0,     6,    44,    45,    16,     5,
      51,    52,    44,    17,    17,    16,    17,    48,    49,    51,
      30,    12,    53,    17,    17,    40,    48,    18,    19,    20,
      21,    47,    17,    40,    34,    38,    50,    38,    50,    10,
      16,    55,    56,    46,    54,    48,    17,    39,    33,    39,
      33,    17,    17,    41,    55,    33,    34,    40,    40,    38,
      50,    50,    50,    60,    57,    17,    48,    55,    39,    33,
      33,    36,    36,    30,    40,    41,    50,    61,    58,    47,
      55,    41,    16,    63,    64,    63,    41,    17,    34,    37,
      37,    41,    38,    64,    62,    59,    39,    48,    48,    40,
      40,     4,     8,     9,    11,    13,    15,    17,    49,    65,
      66,    80,    65,    33,    36,    36,    67,    36,     7,    17,
      18,    19,    20,    21,    22,    23,    33,    36,    74,    76,
      78,    80,    81,    41,    65,    30,    31,    32,    33,    36,
      41,    74,    80,    36,    70,    71,    72,    74,    16,    17,
      76,    76,    79,    33,    22,    23,    75,    85,    24,    25,
      26,    77,    86,    36,    35,    38,    82,    83,    74,    33,
      33,    37,    69,    74,    34,    37,    37,    70,    29,    37,
      28,    27,    73,    84,    38,    38,    75,    75,    74,    76,
      78,    37,    69,    17,    74,    83,    33,    33,    34,    37,
      18,    33,    33,    37,    71,    40,    72,    84,    74,    74,
      74,    37,    75,    77,    37,    39,    74,    33,    37,    40,
      65,    74,    39,    39,    33,    65,    41,    41,    14,    68,
      13,    40,    14,    36,    65,    13,    70,    41,    36,    37,
      70,    40,    37,    65,    40,    41,    65,    41
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
#line 95 "parser.y"
    {
            check_main();
        }
    break;

  case 5:
#line 107 "parser.y"
    {
            if (level == GLOBAL_LEVEL) {
                if (lookup_id((char *)(yyvsp[(3) - (7)]), CONST_VAR) == -1) {
                    int index = insert_symbol((char *)(yyvsp[(3) - (7)]), CONST_VAR, (yyvsp[(2) - (7)]));

                    if ((yyvsp[(2) - (7)]) != (yyvsp[(5) - (7)])) {
                        printerror("Variable and Expression type don't match\n");
                    }

                } else {
                    printerror("Duplicate declaration of %s!\n", (char *)(yyvsp[(3) - (7)]));
                }
            }
        }
    break;

  case 8:
#line 130 "parser.y"
    {
            (yyval) = NUMBER_TYPE;
            try_to_insert_constant((char*)(yyvsp[(1) - (1)]), NUMBER_TYPE);
        }
    break;

  case 9:
#line 135 "parser.y"
    {
            (yyval) = CHAR_TYPE;
            try_to_insert_constant((char*)(yyvsp[(1) - (1)]), CHAR_TYPE);
        }
    break;

  case 10:
#line 140 "parser.y"
    {
            (yyval) = BOOL_TYPE;
            try_to_insert_constant((char*)(yyvsp[(1) - (1)]), BOOL_TYPE);
        }
    break;

  case 11:
#line 145 "parser.y"
    {
            (yyval) = STRING_TYPE;
            try_to_insert_constant((char*)(yyvsp[(1) - (1)]), STRING_TYPE);
        }
    break;

  case 14:
#line 158 "parser.y"
    {
            push(variables, (char*)(yyvsp[(2) - (4)]), 0);

            while(!isEmpty(variables)) {
                int index = declareVariable((yyvsp[(1) - (4)]), top(variables)->name, top(variables)->is_reference, NULL, level);
                if (index == -1) {
                    printerror("Duplicate declaration: %s\n", top(variables)->name);
                }
                pop(variables);
            }

        }
    break;

  case 15:
#line 171 "parser.y"
    {
            push(variables, (char*)(yyvsp[(2) - (6)]), 1);

            while(!isEmpty(variables)) {
                int index = declareVariable((yyvsp[(1) - (6)]), top(variables)->name, top(variables)->is_reference, NULL, level);
                if (index == -1) {
                    printerror("Duplicate declaration: %s\n", top(variables)->name);
                }
                pop(variables);
            }
        }
    break;

  case 16:
#line 183 "parser.y"
    {
            push(variables, (char*)(yyvsp[(2) - (4)]), 1);

            while(!isEmpty(variables)) {
                int index = declareVariable(REFERENCE_TYPE, top(variables)->name, 1, (char*)(yyvsp[(1) - (4)]), level);
                if (index == -1) {
                    printerror("Duplicate declaration: %s\n", top(variables)->name);
                }
                pop(variables);
            }
        }
    break;

  case 17:
#line 195 "parser.y"
    {
            push(variables, (char*)(yyvsp[(2) - (6)]), 1);

            while(!isEmpty(variables)) {
                int index = declareVariable(REFERENCE_TYPE, top(variables)->name, 1, (char*)(yyvsp[(1) - (6)]), level);
                if (index == -1) {
                    printerror("Duplicate declaration: %s\n", top(variables)->name);
                }
                pop(variables);
            }
        }
    break;

  case 19:
#line 211 "parser.y"
    {
            push(variables, (char*)(yyvsp[(2) - (3)]), 0);
        }
    break;

  case 20:
#line 215 "parser.y"
    {
            push(variables, (char*)(yyvsp[(2) - (5)]), 1);
        }
    break;

  case 23:
#line 227 "parser.y"
    {

            declareClass((char*)(yyvsp[(2) - (2)]), NULL);
            save_main_table();
            level = CLASS_LEVEL;
            parent_class = NULL;

        }
    break;

  case 24:
#line 236 "parser.y"
    {
            save_class_table((char*)(yyvsp[(2) - (9)]));
            return_main_table();
            level = GLOBAL_LEVEL;
            parent_class = NULL;
        }
    break;

  case 25:
#line 243 "parser.y"
    {
            declareClass((char*)(yyvsp[(2) - (4)]), (char*)(yyvsp[(4) - (4)]));
            save_main_table();
            level = CLASS_LEVEL;
            parent_class = (char*)(yyvsp[(4) - (4)]);
        }
    break;

  case 26:
#line 250 "parser.y"
    {
            save_class_table((char*)(yyvsp[(2) - (11)]));
            return_main_table();
            level = GLOBAL_LEVEL;
            parent_class = NULL;
        }
    break;

  case 29:
#line 265 "parser.y"
    {
            if (lookup_id((char *)(yyvsp[(2) - (2)]), FUNCTION) == -1) {
                if (lookup_id((char *)(yyvsp[(2) - (2)]), GLOBAL_VAR) == -1 && lookup_id((char *)(yyvsp[(2) - (2)]), CLASS_VAR) == -1) {
                    function_index = insert_symbol((char *)(yyvsp[(2) - (2)]), FUNCTION, (yyvsp[(1) - (2)]));
                } else {
                    printerror("You are tryping to rediclare global or class variable %s to function!", (char *)(yyvsp[(2) - (2)]));
                }
            } else {
                printerror("Duplicate function declaration: %s\n", (char *)(yyvsp[(2) - (2)]));
            }
        }
    break;

  case 30:
#line 277 "parser.y"
    {
            level = PARAMETER_LEVEL;
            par_num = 0;
        }
    break;

  case 31:
#line 282 "parser.y"
    {
            set_attribute(function_index, par_num);
            level = LOCAL_LEVEL;
            var_num = 0;
        }
    break;

  case 32:
#line 288 "parser.y"
    {
            if (return_flag == 0) {
                printerror("You must return some value for %s function!\n", (char*)(yyvsp[(2) - (12)]));
            }
            return_flag = 0;

            if (get_last_element() > function_index)
                clear_symbols(function_index + 1);
            level = GLOBAL_LEVEL;
        }
    break;

  case 33:
#line 299 "parser.y"
    {
            if (lookup_id((char *)(yyvsp[(2) - (2)]), FUNCTION) == -1) {
                if (lookup_id((char *)(yyvsp[(2) - (2)]), GLOBAL_VAR) == -1 && lookup_id((char *)(yyvsp[(2) - (2)]), CLASS_VAR) == -1) {
                    function_index = insert_symbol((char *)(yyvsp[(2) - (2)]), FUNCTION, NO_TYPE);
                } else {
                    printerror("You are tryping to rediclare global or class variable %s to function!", (char *)(yyvsp[(2) - (2)]));
                }
            } else {
                printerror("Duplicate function declaration: %s\n", (char *)(yyvsp[(2) - (2)]));
            }
        }
    break;

  case 34:
#line 311 "parser.y"
    {
            level = PARAMETER_LEVEL;
            par_num = 0;
        }
    break;

  case 35:
#line 316 "parser.y"
    {
            set_attribute(function_index, par_num);
            level = LOCAL_LEVEL;
            var_num = 0;
        }
    break;

  case 36:
#line 322 "parser.y"
    {
            if (return_flag == 1) {
                printerror("You can't return value from void function!\n");
            }
            return_flag = 0;

            if (get_last_element() > function_index)
                clear_symbols(function_index + 1);
            level = GLOBAL_LEVEL;
        }
    break;

  case 40:
#line 342 "parser.y"
    {
            if (level == PARAMETER_LEVEL) {
                if (lookup_id((char *)(yyvsp[(2) - (2)]), PARAMETER) == -1) {
                    (yyval) = insert_symbol((char *)(yyvsp[(2) - (2)]), PARAMETER, (yyvsp[(1) - (2)]));
                    par_num++;
                    set_attribute((yyval), par_num);
                    set_param_type(function_index, par_num, (yyvsp[(1) - (2)]));
                } else {
                    printerror("Duplicate parameter: %s\n", (char *)(yyvsp[(2) - (2)]));
                }

            }
        }
    break;

  case 41:
#line 356 "parser.y"
    {
            if (level == PARAMETER_LEVEL) {
                if (lookup_id((char *)(yyvsp[(2) - (4)]), PARAMETER) == -1) {
                    int (yyval) = insert_symbol((char *)(yyvsp[(2) - (4)]), PARAMETER, (yyvsp[(1) - (4)]));
                    set_is_reference((yyval), 1);
                    par_num++;
                    set_attribute((yyval), par_num);
                    set_param_type(function_index, par_num, (yyvsp[(1) - (4)]));
                } else {
                    printerror("Duplicate parameter: %s\n", (char *)(yyvsp[(2) - (4)]));
                }
            }
        }
    break;

  case 46:
#line 380 "parser.y"
    {

            if ((yyvsp[(1) - (4)]) != (yyvsp[(3) - (4)])) {
                printerror("Assignment of incompatible types!\n");
            }
        }
    break;

  case 47:
#line 387 "parser.y"
    {
            if (function_call_index == -1) {
                printerror("Called undiclared function!\n");
            }

            check_arguments_number(function_call_index, call_table, arg_num);
            // postavi tip povratne vrednosti funkcije u %13
            set_register_type(FUNCTION_REGISTER, get_type(function_call_index));
            // povratna vrednost funkcije se uvek nalazi u %13
            (yyval) = FUNCTION_REGISTER;

            call_table = NULL;
            arg_num = 0;
            function_call_index = -1;
        }
    break;

  case 48:
#line 403 "parser.y"
    {
            if (function_call_index == -1) {
                printerror("Called undiclared function!\n");
            }

            check_arguments_number(function_call_index, call_table, arg_num);
            // postavi tip povratne vrednosti funkcije u %13
            set_register_type(FUNCTION_REGISTER, get_type(function_call_index));
            // povratna vrednost funkcije se uvek nalazi u %13
            (yyval) = FUNCTION_REGISTER;

            call_table = NULL;
            arg_num = 0;
            function_call_index = -1;
        }
    break;

  case 49:
#line 419 "parser.y"
    {
            if (variable_index == -1) {
                printerror("Used undiclared variable!\n");
            } else if ((yyvsp[(1) - (3)]) != NUMBER_TYPE) {
                printerror("You tried to increment non number value!\n");
            }

            variable_index = -1;
        }
    break;

  case 50:
#line 429 "parser.y"
    {
            if (variable_index == -1) {
                printerror("Used undiclared variable!\n");
            } else if ((yyvsp[(1) - (3)]) != NUMBER_TYPE) {
                printerror("You tried to decrement non number value!\n");
            }

            variable_index = -1;
        }
    break;

  case 54:
#line 442 "parser.y"
    {
            while_flag = 1;
        }
    break;

  case 55:
#line 446 "parser.y"
    {
            while_flag = 0;
        }
    break;

  case 56:
#line 450 "parser.y"
    {
            if (while_flag == 0) {
                printerror("You can use break only in loops!\n");
            }
        }
    break;

  case 58:
#line 457 "parser.y"
    {
            return_flag = 1;
        }
    break;

  case 64:
#line 472 "parser.y"
    {
            arg_num = 1;

            check_argument_type(function_call_index, call_table, (yyvsp[(1) - (1)]), arg_num);
        }
    break;

  case 65:
#line 478 "parser.y"
    {
            arg_num++;
            check_argument_type(function_call_index, call_table, (yyvsp[(3) - (3)]), arg_num);
        }
    break;

  case 66:
#line 486 "parser.y"
    {
            condError(&cond_error);
            (yyval) = (yyvsp[(1) - (1)]);
        }
    break;

  case 67:
#line 491 "parser.y"
    {
            condError(&cond_error);
            (yyval) = (yyvsp[(3) - (3)]);
        }
    break;

  case 68:
#line 499 "parser.y"
    {
            (yyval) = (yyvsp[(1) - (1)]);
        }
    break;

  case 69:
#line 503 "parser.y"
    {
            (yyval) = (yyvsp[(3) - (3)]);
        }
    break;

  case 70:
#line 510 "parser.y"
    {
            (yyval) = (yyvsp[(1) - (1)]);
        }
    break;

  case 71:
#line 514 "parser.y"
    {
            if ((yyvsp[(1) - (2)]) != (yyvsp[(2) - (2)]) && cond_error == 0) {
                cond_error = 1;
            }
            (yyval) = (yyvsp[(1) - (2)]);
        }
    break;

  case 72:
#line 524 "parser.y"
    {
            if ((yyvsp[(2) - (2)]) == REFERENCE_TYPE && strcmp((char*)(yyvsp[(1) - (2)]), "!=") != 0 && strcmp((char*)(yyvsp[(1) - (2)]), "==") != 0 && cond_error == 0) {
                cond_error = 2;
            }
            (yyval) = (yyvsp[(2) - (2)]);
        }
    break;

  case 73:
#line 531 "parser.y"
    {
            if ((yyvsp[(2) - (3)]) == REFERENCE_TYPE && strcmp((char*)(yyvsp[(1) - (3)]), "!=") != 0 && strcmp((char*)(yyvsp[(1) - (3)]), "==") != 0 && cond_error == 0) {
                cond_error = 2;
            }
            if ((yyvsp[(1) - (3)]) != (yyvsp[(3) - (3)]) && exp_error == 0) {
                cond_error = 1;
            }
            (yyval) = (yyvsp[(3) - (3)]);
        }
    break;

  case 74:
#line 544 "parser.y"
    {
            if ((yyvsp[(2) - (2)]) != NUMBER_TYPE && exp_error == 0) {
                exp_error = 1;
            }

            if (exp_level == 0) {
                expError(&exp_error);
            }

            (yyval) = (yyvsp[(2) - (2)]);
        }
    break;

  case 75:
#line 556 "parser.y"
    {
            if ((yyvsp[(2) - (2)]) != NUMBER_TYPE && exp_error == 0) {
                exp_error = 2;
            }

            if (exp_level == 0) {
                expError(&exp_error);
            }
            (yyval) = (yyvsp[(2) - (2)]);
        }
    break;

  case 76:
#line 567 "parser.y"
    {
            if (exp_level == 0) {
                expError(&exp_error);
            }
            (yyval) = (yyvsp[(1) - (1)]);
        }
    break;

  case 77:
#line 574 "parser.y"
    {
            if ((yyvsp[(2) - (3)]) != NUMBER_TYPE && exp_error == 0) {
                exp_error = 2;
            }

            if (exp_level == 0) {
                expError(&exp_error);
            }
            (yyval) = (yyvsp[(2) - (3)]);
        }
    break;

  case 78:
#line 585 "parser.y"
    {
            if ((yyvsp[(2) - (3)]) != NUMBER_TYPE && exp_error == 0) {
                exp_error = 2;
            }

            if (exp_level == 0) {
                expError(&exp_error);
            }
            (yyval) = (yyvsp[(2) - (3)]);
        }
    break;

  case 79:
#line 596 "parser.y"
    {
            if ((yyvsp[(1) - (2)]) != (yyvsp[(2) - (2)]) && exp_error == 0) {
                exp_error = 3;
            }

            if (exp_level == 0) {
                expError(&exp_error);
            }
            (yyval) = (yyvsp[(1) - (2)]);
        }
    break;

  case 80:
#line 610 "parser.y"
    {
            if ((yyvsp[(1) - (2)]) == 1) {
                if ((yyvsp[(2) - (2)]) != NUMBER_TYPE && (yyvsp[(2) - (2)]) != STRING_TYPE && exp_error == 0) {
                    exp_error = 4;
                }
            } else {
                if ((yyvsp[(2) - (2)]) != NUMBER_TYPE && exp_error == 0) {
                    exp_error = 5;
                }
            }

            (yyval) = (yyvsp[(2) - (2)]);
        }
    break;

  case 81:
#line 624 "parser.y"
    {
            if ((yyvsp[(1) - (3)]) == 1) {
                if ((yyvsp[(2) - (3)]) != NUMBER_TYPE && (yyvsp[(2) - (3)]) != STRING_TYPE && exp_error == 0) {
                    exp_error = 4;
                }
            } else {
                if ((yyvsp[(2) - (3)]) != NUMBER_TYPE && exp_error == 0) {
                    exp_error = 3;
                }
            }
            if ((yyvsp[(2) - (3)]) != (yyvsp[(3) - (3)]) && exp_error == 0) {
                exp_error = 3;
            }

            (yyval) = (yyvsp[(2) - (3)]);
        }
    break;

  case 82:
#line 644 "parser.y"
    {
            (yyval) = (yyvsp[(1) - (1)]);
        }
    break;

  case 83:
#line 648 "parser.y"
    {
            if ((yyvsp[(1) - (2)]) != NUMBER_TYPE && exp_error == 0) {

                exp_error = 3;
            }
            if ((yyvsp[(1) - (2)]) != (yyvsp[(2) - (2)]) && exp_error == 0) {

                exp_error = 3;
            }
            (yyval) = (yyvsp[(1) - (2)]);
        }
    break;

  case 84:
#line 663 "parser.y"
    {
            (yyval) = (yyvsp[(2) - (2)]);
        }
    break;

  case 85:
#line 667 "parser.y"
    {
            if ((yyvsp[(2) - (3)]) != NUMBER_TYPE && exp_error == 0) {
                exp_error = 3;
            }
            if ((yyvsp[(2) - (3)]) != (yyvsp[(3) - (3)]) && exp_error == 0) {
                exp_error = 3;
            }

            (yyval) = (yyvsp[(2) - (3)]);
        }
    break;

  case 86:
#line 681 "parser.y"
    {
            if (variable_index == -1) {
                printerror("Used undiclared variable %s!\n", get_name(variable_index));
            }

            variable_index = -1;
            (yyval) = (yyvsp[(1) - (1)]);
        }
    break;

  case 87:
#line 690 "parser.y"
    {
            if (function_call_index == -1) {
                printerror("Called undiclared function!\n");
            }

            check_arguments_number(function_call_index, call_table, arg_num);
            // postavi tip povratne vrednosti funkcije u %13
            set_register_type(FUNCTION_REGISTER, get_type(function_call_index));
            // povratna vrednost funkcije se uvek nalazi u %13
            (yyval) = FUNCTION_REGISTER;

            call_table = NULL;
            function_call_index = -1;
            arg_num = 1;
            (yyval) = (yyvsp[(1) - (3)]);
        }
    break;

  case 88:
#line 707 "parser.y"
    {
            if (function_call_index == -1) {
                printerror("Called undiclared function %s!\n", get_name(function_call_index));
            }

            printf("Ovde %d %s %d\n", function_call_index, call_table, arg_num);
            check_arguments_number(function_call_index, call_table, arg_num);
            // postavi tip povratne vrednosti funkcije u %13
            set_register_type(FUNCTION_REGISTER, get_type(function_call_index));
            // povratna vrednost funkcije se uvek nalazi u %13
            (yyval) = FUNCTION_REGISTER;

            call_table = NULL;
            function_call_index = -1;
            arg_num = 1;
            (yyval) = (yyvsp[(1) - (4)]);
        }
    break;

  case 89:
#line 725 "parser.y"
    {
            (yyval) = NUMBER_TYPE;
            try_to_insert_constant((char*)(yyvsp[(1) - (1)]), NUMBER_TYPE);
        }
    break;

  case 90:
#line 730 "parser.y"
    {
            (yyval) = CHAR_TYPE;
            try_to_insert_constant((char*)(yyvsp[(1) - (1)]), CHAR_TYPE);
        }
    break;

  case 91:
#line 735 "parser.y"
    {
            (yyval) = BOOL_TYPE;
            try_to_insert_constant((char*)(yyvsp[(1) - (1)]), BOOL_TYPE);
        }
    break;

  case 92:
#line 740 "parser.y"
    {
            (yyval) = STRING_TYPE;
            try_to_insert_constant((char*)(yyvsp[(1) - (1)]), STRING_TYPE);
        }
    break;

  case 93:
#line 745 "parser.y"
    {
            (yyval) = REFERENCE_TYPE;
        }
    break;

  case 94:
#line 749 "parser.y"
    {
            if ((yyvsp[(4) - (5)]) != NUMBER_TYPE) {
                printerror("Array length must be number!\n");
            }
            (yyval) = REFERENCE_TYPE;
        }
    break;

  case 95:
#line 756 "parser.y"
    {
            if ((yyvsp[(4) - (5)]) != NUMBER_TYPE) {
                printerror("Array length must be number!\n");
            }
            (yyval) = REFERENCE_TYPE;
        }
    break;

  case 96:
#line 763 "parser.y"
    {
            exp_level++;
        }
    break;

  case 97:
#line 767 "parser.y"
    {
            exp_level--;
            (yyval) = (yyvsp[(3) - (4)]);
        }
    break;

  case 98:
#line 775 "parser.y"
    {
            (yyval) = NO_TYPE;
            int varIndex = lookUpVariable((char*)(yyvsp[(1) - (1)]));

            if (varIndex != -1) {
                variable_index = varIndex;
                if (get_is_reference(varIndex) == 1) {
                    (yyval) = REFERENCE_TYPE;
                } else {
                    (yyval) = get_type(varIndex);
                }
            } else {
                int funcIndex = lookUpFunction((char*)(yyvsp[(1) - (1)]), parent_class, &tmp_type, &call_table);

                if (funcIndex != -1) {
                    function_call_index = funcIndex;
                    (yyval) = tmp_type;
                } else {
                    printerror("Undiclared variable or function!\n");
                }
            }


        }
    break;

  case 99:
#line 800 "parser.y"
    {
            (yyval) = NO_TYPE;
            int varIndex = lookUpVariable((char*)(yyvsp[(1) - (1)]));

            if (varIndex != -1) {
                variable_index = varIndex;
                if (get_is_reference(varIndex) == 1) {
                    (yyval) = REFERENCE_TYPE;

                    parent_class = get_class_type(varIndex);
                } else {
                    (yyval) = get_type(varIndex);
                }
            }


        }
    break;

  case 103:
#line 828 "parser.y"
    {
            (yyval) = NO_TYPE;
            int varIndex = lookUpVariable((char*)(yyvsp[(2) - (2)]));

            if (varIndex != -1) {
                variable_index = varIndex;
                if (get_is_reference(varIndex) == 1) {
                    (yyval) = REFERENCE_TYPE;
                } else {
                    (yyval) = get_type(varIndex);
                }
            } else {
                int funcIndex = lookUpFunction((char*)(yyvsp[(2) - (2)]), parent_class, &tmp_type, &call_table);

                if (funcIndex != -1) {
                    function_call_index = funcIndex;
                    (yyval) = tmp_type;
                } else {
                    printerror("Undiclared variable or function!\n");
                }
            }
        }
    break;

  case 104:
#line 851 "parser.y"
    {
            if ((yyvsp[(2) - (3)]) != NUMBER_TYPE) {
                printerror("To access some array element you must pass number!\n");
            }
        }
    break;

  case 105:
#line 860 "parser.y"
    {
            (yyval) = (yyvsp[(1) - (1)]);
        }
    break;

  case 106:
#line 867 "parser.y"
    {
            (yyval) = 1;
        }
    break;

  case 107:
#line 871 "parser.y"
    {
            (yyval) = 2;
        }
    break;


/* Line 1267 of yacc.c.  */
#line 2531 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 882 "parser.y"


int yyerror(char *s) {
    fprintf(stderr, "\nERROR (%d): %s", line, s);
    error_count++;
    return 0;
}

void warning(char *s) {
    fprintf(stderr, "\nWARNING (%d): %s", line, s);
}

int main() {
    printf("\nSTART\n");

    init_symtab();

    variables = (Stack*)malloc(sizeof(Stack));
    initStack(variables, 100);

    yyparse();

    print_symtab();

    clear_symtab();
    printf("\nSTOP\n");
    return error_count;
}

