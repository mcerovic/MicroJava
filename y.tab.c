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
    int var_type = 0;
    int function_index = -1;
    int function_call_index = -1;

    int bool_return = 1;

    char* current_var = NULL;

    int stackN = 20;

    int p = 0;
    char** stack;

    void initStack() {
        p = 0;
        int i = 0;
        stack = (char**)malloc(stackN * sizeof(char*));

        for (i = 0; i < stackN; i++) {
            stack[i] = (char*)malloc(sizeof(char));
        }
    }

    void push(char* name) {
        stack[p] = name;
        p++;
    }

    void pop() {
        if (p > 0) {
            p--;
        } else {
            p = 0;
        }
    }

    char* top() {
        return stack[p - 1];
    }

    int isEmpty() {
        if (p <= 0) return 1;
        return 0;
    }



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
#line 253 "y.tab.c"

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
#define YYLAST   291

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNRULES -- Number of states.  */
#define YYNSTATES  239

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
      35,    37,    39,    40,    43,    48,    55,    60,    61,    65,
      71,    72,    75,    76,    86,    97,    98,   101,   102,   103,
     104,   117,   127,   128,   130,   134,   137,   142,   143,   146,
     149,   151,   156,   162,   167,   171,   175,   183,   195,   204,
     212,   215,   218,   222,   228,   234,   242,   251,   261,   263,
     267,   269,   273,   275,   279,   281,   284,   287,   291,   294,
     297,   299,   303,   307,   310,   313,   317,   319,   322,   325,
     329,   331,   335,   340,   342,   344,   346,   348,   351,   357,
     363,   367,   369,   370,   374,   376,   379,   382,   386,   388,
     390,   392,   394,   396
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,     3,    17,    44,    51,    48,    40,    54,
      41,    -1,    -1,    45,    44,    -1,     6,    16,    17,    30,
      47,    46,    33,    -1,    -1,    46,    34,    17,    30,    47,
      -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,    -1,
      49,    48,    -1,    16,    17,    50,    33,    -1,    16,    17,
      38,    39,    50,    33,    -1,    17,    17,    50,    33,    -1,
      -1,    34,    17,    50,    -1,    34,    17,    38,    39,    50,
      -1,    -1,    52,    51,    -1,    -1,     5,    17,    53,    40,
      48,    40,    54,    41,    41,    -1,     5,    17,    12,    17,
      40,    48,    40,    54,    41,    41,    -1,    -1,    55,    54,
      -1,    -1,    -1,    -1,    16,    17,    56,    36,    57,    59,
      37,    58,    48,    40,    61,    41,    -1,    10,    17,    36,
      59,    37,    48,    40,    61,    41,    -1,    -1,    60,    -1,
      59,    34,    60,    -1,    16,    17,    -1,    16,    17,    38,
      39,    -1,    -1,    62,    61,    -1,    74,    33,    -1,    49,
      -1,    74,    30,    69,    33,    -1,    74,    36,    64,    37,
      33,    -1,    74,    36,    37,    33,    -1,    74,    31,    33,
      -1,    74,    32,    33,    -1,    13,    36,    65,    37,    40,
      61,    41,    -1,    13,    36,    65,    37,    40,    61,    41,
      14,    40,    61,    41,    -1,    13,    36,    65,    37,    40,
      61,    41,    63,    -1,    11,    36,    65,    37,    40,    61,
      41,    -1,     4,    33,    -1,    15,    33,    -1,    15,    69,
      33,    -1,     9,    36,    74,    37,    33,    -1,     8,    36,
      69,    37,    33,    -1,     8,    36,    69,    34,    18,    37,
      33,    -1,    14,    13,    36,    65,    37,    40,    61,    41,
      -1,    63,    14,    13,    36,    65,    37,    40,    61,    41,
      -1,    69,    -1,    64,    34,    69,    -1,    66,    -1,    65,
      29,    66,    -1,    67,    -1,    66,    28,    67,    -1,    69,
      -1,    69,    68,    -1,    78,    69,    -1,    68,    78,    69,
      -1,    23,    71,    -1,    22,    71,    -1,    71,    -1,    23,
      71,    70,    -1,    22,    71,    70,    -1,    71,    70,    -1,
      79,    71,    -1,    79,    71,    70,    -1,    73,    -1,    73,
      72,    -1,    80,    73,    -1,    72,    80,    73,    -1,    74,
      -1,    74,    36,    37,    -1,    74,    36,    64,    37,    -1,
      18,    -1,    19,    -1,    20,    -1,    21,    -1,     7,    17,
      -1,     7,    17,    38,    69,    39,    -1,     7,    16,    38,
      69,    39,    -1,    36,    69,    37,    -1,    17,    -1,    -1,
      17,    75,    76,    -1,    77,    -1,    76,    77,    -1,    35,
      17,    -1,    38,    69,    39,    -1,    27,    -1,    22,    -1,
      23,    -1,    24,    -1,    25,    -1,    26,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   116,   116,   119,   121,   125,   142,   144,   148,   152,
     156,   160,   166,   168,   172,   223,   280,   309,   311,   315,
     321,   323,   328,   327,   352,   355,   357,   362,   374,   379,
     361,   392,   400,   402,   403,   407,   421,   438,   440,   444,
     445,   446,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   488,   489,   493,   494,
     498,   499,   503,   504,   508,   509,   513,   517,   521,   529,
     537,   545,   553,   561,   572,   587,   597,   601,   611,   618,
     628,   654,   655,   656,   660,   664,   668,   672,   678,   684,
     690,   697,   702,   701,   727,   728,   732,   755,   765,   772,
     776,   783,   784,   785
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
  "ClassList", "ClassDecl", "@1", "MethodDeclList", "MethodDecl", "@2",
  "@3", "@4", "FormPars", "FormPar", "Block", "Statement", "ElseIfList",
  "ActPars", "Condition", "CondTerm", "CondFact", "CondFactList",
  "Expression", "AddopTermList", "Term", "MulopFactorList", "Factor",
  "Designator", "@5", "DesignatorRepeatList", "DesignatorRepeat", "Relop",
  "Addop", "Mulop", 0
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
      47,    47,    48,    48,    49,    49,    49,    50,    50,    50,
      51,    51,    53,    52,    52,    54,    54,    56,    57,    58,
      55,    55,    59,    59,    59,    60,    60,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    67,    68,    68,    69,    69,
      69,    69,    69,    69,    70,    70,    71,    71,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    75,    74,    76,    76,    77,    77,    78,    79,
      79,    80,    80,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     0,     2,     7,     0,     5,     1,     1,
       1,     1,     0,     2,     4,     6,     4,     0,     3,     5,
       0,     2,     0,     9,    10,     0,     2,     0,     0,     0,
      12,     9,     0,     1,     3,     2,     4,     0,     2,     2,
       1,     4,     5,     4,     3,     3,     7,    11,     8,     7,
       2,     2,     3,     5,     5,     7,     8,     9,     1,     3,
       1,     3,     1,     3,     1,     2,     2,     3,     2,     2,
       1,     3,     3,     2,     2,     3,     1,     2,     2,     3,
       1,     3,     4,     1,     1,     1,     1,     2,     5,     5,
       3,     1,     0,     3,     1,     2,     2,     3,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     1,     0,    20,     3,     0,     0,
      12,    20,     4,     0,    22,     0,     0,     0,    12,    21,
       0,     0,     0,    17,    17,    25,    13,     8,     9,    10,
      11,     6,     0,    12,     0,     0,     0,     0,     0,     0,
       0,    25,     0,    12,     0,    17,    17,    14,    16,     0,
      27,     2,    26,     5,     0,     0,    25,     0,    18,     0,
      32,     0,     0,    25,     0,    17,    15,     0,     0,    33,
      28,     0,     0,     0,    19,    35,     0,    12,    32,     7,
       0,    23,     0,    34,     0,     0,    24,    36,    37,    29,
       0,     0,     0,     0,     0,     0,    91,    40,     0,    37,
       0,    12,    50,     0,     0,     0,     0,     0,    91,    83,
      84,    85,    86,     0,     0,    51,     0,     0,    70,    76,
      80,     0,    31,    38,     0,     0,     0,    39,     0,     0,
       0,     0,     0,    60,    62,    64,     0,     0,    87,    69,
      68,     0,    52,    99,   100,    73,     0,   101,   102,   103,
      77,     0,     0,     0,     0,    93,    94,     0,    44,    45,
       0,     0,    58,    37,     0,     0,     0,     0,     0,     0,
      98,    65,     0,     0,     0,     0,    72,    71,    90,    74,
       0,    78,    81,     0,    96,     0,    95,    41,    43,     0,
       0,     0,     0,    54,    53,    61,    37,    63,     0,    66,
      37,     0,     0,    75,    79,    82,    97,    59,    42,    30,
       0,     0,    67,     0,    89,    88,    55,    49,    46,     0,
      48,     0,    37,     0,     0,     0,     0,     0,    47,     0,
       0,     0,    37,     0,     0,    37,    56,     0,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     7,    42,    31,    17,    97,    36,    10,
      11,    22,    40,    41,    61,    78,   101,    68,    69,    98,
      99,   220,   161,   132,   133,   134,   171,   135,   145,   118,
     150,   119,   120,   121,   155,   156,   172,   146,   151
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -149
static const yytype_int16 yypact[] =
{
      14,    31,    62,    65,  -149,    48,   106,    65,    98,   100,
      61,   106,  -149,    88,   108,   104,   105,    83,    61,  -149,
      67,   116,    96,    13,   103,    25,  -149,  -149,  -149,  -149,
    -149,  -149,   101,    61,   123,   117,   110,   124,   125,   148,
     126,    25,    68,    61,   131,    42,   103,  -149,  -149,   130,
    -149,  -149,  -149,  -149,   155,   133,    25,   136,  -149,   143,
     162,   151,   149,    25,   147,   103,  -149,   173,   -14,  -149,
    -149,    67,   150,   154,  -149,   159,   162,    61,   162,  -149,
     164,  -149,   153,  -149,   166,    16,  -149,  -149,   185,  -149,
     170,   168,   171,   172,   174,   141,     5,  -149,   175,   185,
      37,    61,  -149,   163,   192,   163,   163,    93,    44,  -149,
    -149,  -149,  -149,    38,    38,  -149,   163,   178,    91,    80,
     176,    55,  -149,  -149,   163,   180,   181,  -149,   109,   177,
      57,   182,   -11,   187,  -149,   191,   -10,   183,   184,    91,
      91,   186,  -149,  -149,  -149,  -149,    38,  -149,  -149,  -149,
      80,    38,   132,   203,   163,    55,  -149,   193,  -149,  -149,
     194,    58,  -149,   185,   206,   195,   196,   163,   190,   163,
    -149,   191,   163,   197,   163,   163,  -149,  -149,  -149,    91,
      38,  -149,  -149,    63,  -149,   199,  -149,  -149,  -149,   163,
     198,   200,   188,  -149,  -149,   187,   185,  -149,   163,  -149,
     185,   201,   204,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
     202,   205,  -149,   207,  -149,  -149,  -149,  -149,   218,    -6,
     219,   208,   185,   221,   163,   209,   211,     7,  -149,   163,
     212,    23,   185,   213,   210,   185,  -149,   214,  -149
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,  -149,   229,  -149,  -149,   189,   -12,    -5,   -16,   228,
    -149,  -149,   -17,  -149,  -149,  -149,  -149,   167,   215,   -97,
    -149,  -149,    90,  -105,    82,    85,  -149,   -91,  -125,  -104,
    -149,  -148,   -88,  -149,  -149,   102,    87,  -149,   111
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -93
static const yytype_int16 yytable[] =
{
     100,   136,   123,   181,   117,    18,    26,   221,    37,   139,
     140,   100,   130,    18,   176,   177,   131,     1,   167,   167,
      76,    44,    24,    77,    52,   141,   168,   173,    18,    58,
      59,    55,   204,   157,   222,    38,   167,   162,    18,    64,
     -92,    39,   179,   -92,   230,   107,    72,    34,     3,    74,
      76,    35,   167,    89,   203,   108,   109,   110,   111,   112,
     233,   162,     4,   185,     8,    84,   191,   124,   125,   126,
     127,     5,    18,   128,   116,   100,    34,    15,    16,   -92,
      57,   199,   -92,   201,   202,    27,    28,    29,    30,   129,
     153,   164,   189,   154,   165,   190,    18,   189,   207,   211,
     205,    53,    54,   213,   147,   148,   149,   212,   100,   137,
     138,     9,   100,   143,   144,    13,   107,    14,    20,   227,
      21,    23,    24,    25,   231,   225,   108,   109,   110,   111,
     112,   113,   114,    32,   100,   234,    33,    34,   237,   107,
      45,    43,    49,    47,   100,   116,   160,   100,   107,   108,
     109,   110,   111,   112,   113,   114,    46,    48,   108,   109,
     110,   111,   112,   113,   114,    50,    60,    51,   116,   182,
     107,    56,    62,    63,   115,    65,    66,   116,    67,    71,
     108,   109,   110,   111,   112,   113,   114,    70,    73,    90,
      75,    80,    87,    91,    92,    81,    93,    82,    94,   116,
      95,    15,    96,   102,   103,    86,    88,   104,   105,   108,
     106,   142,   152,   158,   159,   169,   122,   163,   170,   166,
     184,   174,   175,   178,   192,   210,   187,   188,   193,   194,
     196,   208,   219,   223,   226,   216,    12,   200,   206,    19,
     214,   209,   183,   215,   224,    85,   217,   229,   218,   195,
     228,   236,   232,   235,   197,   238,     0,   186,   198,     0,
      79,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83
};

static const yytype_int16 yycheck[] =
{
      88,   106,    99,   151,    95,    10,    18,    13,    24,   113,
     114,    99,   103,    18,   139,   140,   104,     3,    29,    29,
      34,    33,    17,    37,    41,   116,    37,    37,    33,    45,
      46,    43,   180,   124,    40,    10,    29,   128,    43,    56,
      35,    16,   146,    38,    37,     7,    63,    34,    17,    65,
      34,    38,    29,    37,   179,    17,    18,    19,    20,    21,
      37,   152,     0,   154,    16,    77,   163,    30,    31,    32,
      33,     6,    77,    36,    36,   163,    34,    16,    17,    35,
      38,   172,    38,   174,   175,    18,    19,    20,    21,   101,
      35,    34,    34,    38,    37,    37,   101,    34,   189,   196,
      37,    33,    34,   200,    24,    25,    26,   198,   196,    16,
      17,     5,   200,    22,    23,    17,     7,    17,    30,   224,
      12,    17,    17,    40,   229,   222,    17,    18,    19,    20,
      21,    22,    23,    17,   222,   232,    40,    34,   235,     7,
      17,    40,    17,    33,   232,    36,    37,   235,     7,    17,
      18,    19,    20,    21,    22,    23,    39,    33,    17,    18,
      19,    20,    21,    22,    23,    17,    36,    41,    36,    37,
       7,    40,    17,    40,    33,    39,    33,    36,    16,    30,
      17,    18,    19,    20,    21,    22,    23,    36,    41,     4,
      17,    41,    39,     8,     9,    41,    11,    38,    13,    36,
      15,    16,    17,    33,    36,    41,    40,    36,    36,    17,
      36,    33,    36,    33,    33,    28,    41,    40,    27,    37,
      17,    38,    38,    37,    18,    37,    33,    33,    33,    33,
      40,    33,    14,    14,    13,    33,     7,    40,    39,    11,
      39,    41,   152,    39,    36,    78,    41,    36,    41,   167,
      41,    41,    40,    40,   169,    41,    -1,   155,   171,    -1,
      71,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    43,    17,     0,     6,    44,    45,    16,     5,
      51,    52,    44,    17,    17,    16,    17,    48,    49,    51,
      30,    12,    53,    17,    17,    40,    48,    18,    19,    20,
      21,    47,    17,    40,    34,    38,    50,    50,    10,    16,
      54,    55,    46,    40,    48,    17,    39,    33,    33,    17,
      17,    41,    54,    33,    34,    48,    40,    38,    50,    50,
      36,    56,    17,    40,    54,    39,    33,    16,    59,    60,
      36,    30,    54,    41,    50,    17,    34,    37,    57,    47,
      41,    41,    38,    60,    48,    59,    41,    39,    40,    37,
       4,     8,     9,    11,    13,    15,    17,    49,    61,    62,
      74,    58,    33,    36,    36,    36,    36,     7,    17,    18,
      19,    20,    21,    22,    23,    33,    36,    69,    71,    73,
      74,    75,    41,    61,    30,    31,    32,    33,    36,    48,
      69,    74,    65,    66,    67,    69,    65,    16,    17,    71,
      71,    69,    33,    22,    23,    70,    79,    24,    25,    26,
      72,    80,    36,    35,    38,    76,    77,    69,    33,    33,
      37,    64,    69,    40,    34,    37,    37,    29,    37,    28,
      27,    68,    78,    37,    38,    38,    70,    70,    37,    71,
      80,    73,    37,    64,    17,    69,    77,    33,    33,    34,
      37,    61,    18,    33,    33,    66,    40,    67,    78,    69,
      40,    69,    69,    70,    73,    37,    39,    69,    33,    41,
      37,    61,    69,    61,    39,    39,    33,    41,    41,    14,
      63,    13,    40,    14,    36,    61,    13,    65,    41,    36,
      37,    65,    40,    37,    61,    40,    41,    61,    41
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
        case 5:
#line 126 "parser.y"
    {
            if (level == GLOBAL_LEVEL) {
                if (lookup_id((char *)(yyvsp[(3) - (7)]), CONSTANT) == -1) {
                    int x = insert_symbol((char *)(yyvsp[(3) - (7)]), CONSTANT, (yyvsp[(2) - (7)]));

                    if ((yyvsp[(2) - (7)]) != (yyvsp[(5) - (7)])) {
                        printerror("Variable and Expression type don't match\n");
                    }

                } else {
                    printerror("Duplicate declaration: %s\n", (char *)(yyvsp[(3) - (7)]));
                }
            }
        }
    break;

  case 8:
#line 149 "parser.y"
    {
            (yyval) = NUMBER_TYPE;
        }
    break;

  case 9:
#line 153 "parser.y"
    {
            (yyval) = CHAR_TYPE;
        }
    break;

  case 10:
#line 157 "parser.y"
    {
            (yyval) = BOOL_TYPE;
        }
    break;

  case 11:
#line 161 "parser.y"
    {
            (yyval) = STRING_TYPE;
        }
    break;

  case 14:
#line 173 "parser.y"
    {
            if (level == GLOBAL_LEVEL) {

                if (lookup_id((char *)(yyvsp[(2) - (4)]), GLOBAL_VAR) == -1) {
                    insert_symbol((char *)(yyvsp[(2) - (4)]), GLOBAL_VAR, (yyvsp[(1) - (4)]));
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)(yyvsp[(2) - (4)]));
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), GLOBAL_VAR) == -1) {
                        insert_symbol(top(), GLOBAL_VAR, (yyvsp[(1) - (4)]));
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            } else if (level == LOCAL_LEVEL) {
                if (lookup_id((char *)(yyvsp[(2) - (4)]), LOCAL_VAR) == -1) {
                    insert_symbol((char *)(yyvsp[(2) - (4)]), LOCAL_VAR, (yyvsp[(1) - (4)]));
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)(yyvsp[(2) - (4)]));
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), LOCAL_VAR) == -1) {
                        insert_symbol(top(), LOCAL_VAR, (yyvsp[(1) - (4)]));
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            } else if (level == CLASS_LEVEL) {
                if (lookup_id((char *)(yyvsp[(2) - (4)]), CLASS_VAR) == -1) {
                    insert_symbol((char *)(yyvsp[(2) - (4)]), CLASS_VAR, (yyvsp[(1) - (4)]));
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)(yyvsp[(2) - (4)]));
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), CLASS_VAR) == -1) {
                        insert_symbol(top(), CLASS_VAR, (yyvsp[(1) - (4)]));
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            }
            // // print_symtab();
        }
    break;

  case 15:
#line 224 "parser.y"
    {
            if (level == GLOBAL_LEVEL) {

                if (lookup_id((char *)(yyvsp[(2) - (6)]), GLOBAL_VAR) == -1) {
                    int index = insert_symbol((char *)(yyvsp[(2) - (6)]), GLOBAL_VAR, (yyvsp[(1) - (6)]));
                    set_param_type(index, 1, REFERENCE_TYPE);
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)(yyvsp[(2) - (6)]));
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), GLOBAL_VAR) == -1) {
                        int index = insert_symbol(top(), GLOBAL_VAR, (yyvsp[(1) - (6)]));
                        set_param_type(index, 1, REFERENCE_TYPE);
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            } else if (level == LOCAL_LEVEL) {
                if (lookup_id((char *)(yyvsp[(2) - (6)]), LOCAL_VAR) == -1) {
                    int index = insert_symbol((char *)(yyvsp[(2) - (6)]), LOCAL_VAR, (yyvsp[(1) - (6)]));
                    set_param_type(index, 1, REFERENCE_TYPE);
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)(yyvsp[(2) - (6)]));
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), LOCAL_VAR) == -1) {
                        int index = insert_symbol(top(), LOCAL_VAR, (yyvsp[(1) - (6)]));
                        set_param_type(index, 1, REFERENCE_TYPE);
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            } else if (level == CLASS_LEVEL) {
                if (lookup_id((char *)(yyvsp[(2) - (6)]), CLASS_VAR) == -1) {
                    int index = insert_symbol((char *)(yyvsp[(2) - (6)]), CLASS_VAR, (yyvsp[(1) - (6)]));
                    set_param_type(index, 1, REFERENCE_TYPE);
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)(yyvsp[(2) - (6)]));
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), CLASS_VAR) == -1) {
                        int index = insert_symbol(top(), CLASS_VAR, (yyvsp[(1) - (6)]));
                        set_param_type(index, 1, REFERENCE_TYPE);
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            }
            // // print_symtab();
        }
    break;

  case 16:
#line 281 "parser.y"
    {
            if (level == GLOBAL_LEVEL) {

                if (lookup_id((char *)(yyvsp[(2) - (4)]), GLOBAL_VAR) == -1) {
                    int index = insert_symbol((char *)(yyvsp[(2) - (4)]), GLOBAL_VAR, REFERENCE_TYPE);
                    set_class_type(index, (char*)(yyvsp[(1) - (4)]));
                    set_param_type(index, 1, REFERENCE_TYPE);
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)(yyvsp[(2) - (4)]));
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), GLOBAL_VAR) == -1) {
                        int index = insert_symbol(top(), GLOBAL_VAR, REFERENCE_TYPE);
                        set_class_type(index, (char*)(yyvsp[(1) - (4)]));
                        set_param_type(index, 1, REFERENCE_TYPE);
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            }

            print_symtab();

        }
    break;

  case 18:
#line 312 "parser.y"
    {
            push((char *)(yyvsp[(2) - (3)]));
        }
    break;

  case 19:
#line 316 "parser.y"
    {
            push((char *)(yyvsp[(2) - (5)]));
        }
    break;

  case 22:
#line 328 "parser.y"
    {
            if (lookup_id((char*)(yyvsp[(2) - (2)]), CLASS) == -1) {
                int index = insert_symbol((char*)(yyvsp[(2) - (2)]), CLASS, -1);
                set_param_type(index, 1, REFERENCE_TYPE);
            } else {
                printerror("Duplicate class declaration: %s\n", top());
            }

            save_main_table();

            level = CLASS_LEVEL;


        }
    break;

  case 23:
#line 343 "parser.y"
    {
            print_symtab();
            save_class_table((char*)(yyvsp[(2) - (9)]));
            return_main_table();

            level = GLOBAL_LEVEL;

            print_symtab();
        }
    break;

  case 27:
#line 362 "parser.y"
    {
            if (lookup_id((char *)(yyvsp[(2) - (2)]), GLOBAL_VAR) == -1 &&
                lookup_id((char *)(yyvsp[(2) - (2)]), FUNCTION) == -1) {

                function_index = insert_symbol((char *)(yyvsp[(2) - (2)]), FUNCTION, (yyvsp[(1) - (2)]));

            } else {
                printerror("Duplicate parameter: %s\n", (char *)(yyvsp[(2) - (2)]));
            }

        }
    break;

  case 28:
#line 374 "parser.y"
    {
            level = PARAMETER_LEVEL;
            par_num = 0;
        }
    break;

  case 29:
#line 379 "parser.y"
    {
            set_attribute(function_index, par_num);
            level = LOCAL_LEVEL;
            var_num = 0;
        }
    break;

  case 30:
#line 385 "parser.y"
    {
            // print_symtab();
            if (get_last_element() > function_index)
                clear_symbols(function_index + 1);
            // print_symtab();
            level = GLOBAL_LEVEL;
        }
    break;

  case 31:
#line 393 "parser.y"
    {

            level = LOCAL_LEVEL;
            level = GLOBAL_LEVEL;
        }
    break;

  case 35:
#line 408 "parser.y"
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

  case 36:
#line 422 "parser.y"
    {
            if (level == PARAMETER_LEVEL) {
                if (lookup_id((char *)(yyvsp[(2) - (4)]), PARAMETER) == -1) {
                    int (yyval) = insert_symbol((char *)(yyvsp[(2) - (4)]), PARAMETER, (yyvsp[(1) - (4)]));
                    set_param_type((yyval), 1, REFERENCE_TYPE);
                    par_num++;
                    set_attribute((yyval), par_num);
                    set_param_type(function_index, par_num, (yyvsp[(1) - (4)]));
                } else {
                    printerror("Duplicate parameter: %s\n", (char *)(yyvsp[(2) - (4)]));
                }

            }
        }
    break;

  case 41:
#line 447 "parser.y"
    {
            printf("\n%s %d\n", (char*)(yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));

            int globalVarIndex = lookup_id((char*)(yyvsp[(1) - (4)]), GLOBAL_VAR);
            int varIndex = lookup_id((char*)(yyvsp[(1) - (4)]), LOCAL_VAR);
            int parameterIndex = lookup_id((char*)(yyvsp[(1) - (4)]), PARAMETER);
            int varType = -1;

            if (globalVarIndex != -1) {
                varType = get_type(globalVarIndex);
            }

            if (varIndex != -1) {
                varType = get_type(varIndex);
            }

            if (parameterIndex != -1) {
                varType = get_type(parameterIndex);
            }

            if (varType != (yyvsp[(3) - (4)])) {
                printerror("You tried assignment of incompatible types!");
            }
        }
    break;

  case 66:
#line 514 "parser.y"
    {

        }
    break;

  case 68:
#line 522 "parser.y"
    {
            (yyval) = (yyvsp[(2) - (2)]);
            if (bool_return == 0 || (yyvsp[(2) - (2)]) != NUMBER_TYPE) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
    break;

  case 69:
#line 530 "parser.y"
    {
            (yyval) = (yyvsp[(2) - (2)]);
            if (bool_return == 0 || (yyvsp[(2) - (2)]) != NUMBER_TYPE) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
    break;

  case 70:
#line 538 "parser.y"
    {
            (yyval) = (yyvsp[(1) - (1)]);
            if (bool_return == 0) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
    break;

  case 71:
#line 546 "parser.y"
    {
            (yyval) = (yyvsp[(2) - (3)]);
            if (bool_return == 0 || (yyvsp[(3) - (3)]) != NUMBER_TYPE) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
    break;

  case 72:
#line 554 "parser.y"
    {
            (yyval) = (yyvsp[(2) - (3)]);
            if (bool_return == 0 || (yyvsp[(3) - (3)]) != NUMBER_TYPE) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
    break;

  case 73:
#line 562 "parser.y"
    {
            (yyval) = (yyvsp[(1) - (2)]);
            if (bool_return == 0 || (yyvsp[(1) - (2)]) != (yyvsp[(2) - (2)])) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
    break;

  case 74:
#line 573 "parser.y"
    {
            if ((yyvsp[(1) - (2)]) == 1) {
                // Addop is plus
                if ((yyvsp[(2) - (2)]) != STRING_TYPE && (yyvsp[(2) - (2)]) != NUMBER_TYPE) {
                    bool_return = 0;
                }
            } else {
                if ((yyvsp[(2) - (2)]) != NUMBER_TYPE) {
                    bool_return = 0;
                }
            }

            (yyval) = (yyvsp[(2) - (2)]);
        }
    break;

  case 75:
#line 588 "parser.y"
    {
            if ((yyvsp[(2) - (3)]) != (yyvsp[(3) - (3)]) || (yyvsp[(2) - (3)]) != NUMBER_TYPE) {
                bool_return = 0;
            }
            (yyval) = (yyvsp[(2) - (3)]);
        }
    break;

  case 76:
#line 598 "parser.y"
    {
            (yyval) = (yyvsp[(1) - (1)]);
        }
    break;

  case 77:
#line 602 "parser.y"
    {
            if ((yyvsp[(1) - (2)]) != (yyvsp[(2) - (2)])) {
                bool_return = 0;
            }
            (yyval) = (yyvsp[(1) - (2)]);
        }
    break;

  case 78:
#line 612 "parser.y"
    {
            if ((yyvsp[(2) - (2)]) != NUMBER_TYPE) {
                bool_return = 0;
            }
            (yyval) = (yyvsp[(2) - (2)]);
        }
    break;

  case 79:
#line 619 "parser.y"
    {
            if ((yyvsp[(1) - (3)]) != (yyvsp[(3) - (3)]) || (yyvsp[(1) - (3)]) != NUMBER_TYPE) {
                bool_return = 0;
            }
            (yyval) = (yyvsp[(1) - (3)]);
        }
    break;

  case 80:
#line 629 "parser.y"
    {

            (yyval) = -1;

            int globalVarIndex = lookup_id((char*)(yyvsp[(1) - (1)]), GLOBAL_VAR);
            int varIndex = lookup_id((char*)(yyvsp[(1) - (1)]), LOCAL_VAR);
            int parameterIndex = lookup_id((char*)(yyvsp[(1) - (1)]), PARAMETER);

            if (globalVarIndex != -1) {
                (yyval) = get_type(globalVarIndex);
            }

            if (varIndex != -1) {
                (yyval) = get_type(varIndex);
            }

            if (parameterIndex != -1) {
                (yyval) = get_type(parameterIndex);
            }

            if (globalVarIndex == -1 && varIndex == -1 &&  parameterIndex == -1) {
                printerror("Undiclared variable: %s\n", (char *)(yyvsp[(1) - (1)]));
            }

        }
    break;

  case 83:
#line 657 "parser.y"
    {
            (yyval) = NUMBER_TYPE;
        }
    break;

  case 84:
#line 661 "parser.y"
    {
            (yyval) = CHAR_TYPE;
        }
    break;

  case 85:
#line 665 "parser.y"
    {
            (yyval) = BOOL_TYPE;
        }
    break;

  case 86:
#line 669 "parser.y"
    {
            (yyval) = STRING_TYPE;
        }
    break;

  case 87:
#line 673 "parser.y"
    {
            if (lookup_id((char*)(yyvsp[(2) - (2)]), CLASS) == -1) {
                printerror("You are tryping to create instance of undiclared class %s", (char*)(yyvsp[(2) - (2)]));
            }
        }
    break;

  case 88:
#line 679 "parser.y"
    {
            if ((yyvsp[(4) - (5)]) != NUMBER_TYPE) {
                printerror("In new %s[x] x must be integer!\n", (char*)(yyvsp[(2) - (5)]));
            }
        }
    break;

  case 89:
#line 685 "parser.y"
    {
            if ((yyvsp[(4) - (5)]) != NUMBER_TYPE) {
                printerror("Length of array must be number!\n");
            }
        }
    break;

  case 90:
#line 691 "parser.y"
    {
            (yyval) = (yyvsp[(2) - (3)]);
        }
    break;

  case 91:
#line 698 "parser.y"
    {
            (yyval) = (yyvsp[(1) - (1)]);
        }
    break;

  case 92:
#line 702 "parser.y"
    {
            current_var = (char*)(yyvsp[(1) - (1)]);
        }
    break;

  case 93:
#line 706 "parser.y"
    {
            (yyval) = (yyvsp[(1) - (3)]);

            if ((yyvsp[(2) - (3)]) == REFERENCE_TYPE) {

                int globalVarIndex = lookup_id((char*)(yyvsp[(1) - (3)]), GLOBAL_VAR);
                int varIndex = lookup_id((char*)(yyvsp[(1) - (3)]), LOCAL_VAR);
                int parameterIndex = lookup_id((char*)(yyvsp[(1) - (3)]), PARAMETER);

                if ((globalVarIndex == -1 || get_param_type(globalVarIndex, 1) != REFERENCE_TYPE) &&
                    (varIndex == -1 || get_param_type(varIndex, 1) != REFERENCE_TYPE) &&
                    (parameterIndex == -1 && get_param_type(parameterIndex, 1) != REFERENCE_TYPE)) {
                    printerror("Used undiclared variable: %s\n", (char *)(yyvsp[(1) - (3)]));
                }

            }

        }
    break;

  case 96:
#line 733 "parser.y"
    {
            save_main_table();
            if (current_var != NULL) {
                printf("%s\n", current_var);

                int index = lookup_id(current_var, GLOBAL_VAR);
                if (index != -1 && get_class_type(index) != NULL) {
                    char* className =  get_class_type(index);
                    switch_table_to(className);

                    int functionIndex = lookup_id((char*)(yyvsp[(2) - (2)]), FUNCTION);
                    int varIndex = lookup_id((char*)(yyvsp[(2) - (2)]), CLASS_VAR);

                    if (functionIndex == -1 && varIndex == -1) {
                        printerror("Function or Variable %s is undeclared in %s class\n", (char*)(yyvsp[(2) - (2)]), className);
                    }
                }
            }
            return_main_table();
            current_var = NULL;

        }
    break;

  case 97:
#line 756 "parser.y"
    {
            if ((yyvsp[(2) - (3)]) != NUMBER_TYPE) {
                printerror("Array index must be number!\n");
            }
            (yyval) = REFERENCE_TYPE;
        }
    break;

  case 98:
#line 766 "parser.y"
    {
            printf("Relop: %s\n", (char*)(yyvsp[(1) - (1)]));
        }
    break;

  case 99:
#line 773 "parser.y"
    {
            (yyval) = 1;
        }
    break;

  case 100:
#line 777 "parser.y"
    {
            (yyval) = 2;
        }
    break;


/* Line 1267 of yacc.c.  */
#line 2336 "y.tab.c"
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


#line 788 "parser.y"


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
    initStack();
    init_symtab();
    yyparse();

    clear_symtab();
    printf("\nSTOP\n");
    return error_count;
}

