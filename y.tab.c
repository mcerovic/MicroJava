/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "parser.y" /* yacc.c:339  */

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


#line 128 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "y.tab.h".  */
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 261 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   261

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  230

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   113,   113,   116,   118,   122,   139,   141,   145,   149,
     153,   157,   163,   165,   169,   205,   247,   249,   253,   259,
     261,   265,   266,   269,   271,   276,   288,   293,   275,   306,
     314,   316,   317,   321,   335,   352,   354,   358,   359,   360,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   389,   390,   394,   395,   399,   400,
     404,   405,   409,   410,   414,   415,   419,   427,   435,   443,
     451,   459,   470,   477,   487,   491,   501,   508,   518,   539,
     540,   541,   545,   549,   553,   554,   555,   561,   568,   572,
     600,   601,   605,   606,   616,   620,   621,   625,   626,   627
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "ClassList", "ClassDecl", "MethodDeclList", "MethodDecl", "$@1", "$@2",
  "$@3", "FormPars", "FormPar", "Block", "Statement", "ElseIfList",
  "ActPars", "Condition", "CondTerm", "CondFact", "CondFactList",
  "Expression", "AddopTermList", "Term", "MulopFactorList", "Factor",
  "Designator", "DesignatorRepeatList", "DesignatorRepeat", "Relop",
  "Addop", "Mulop", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -130

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-130)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,     8,    62,    25,  -130,    48,    66,    25,    60,    71,
      63,    66,  -130,    78,     3,    89,    85,    63,  -130,   147,
     120,    63,    -8,    12,  -130,  -130,  -130,  -130,  -130,  -130,
     102,   104,   122,    74,   121,   139,   141,   129,    12,     7,
      63,    12,    38,   137,  -130,   126,  -130,  -130,  -130,  -130,
     146,   136,   138,   142,  -130,   145,   161,   148,   150,    12,
     151,   137,  -130,   165,    44,  -130,  -130,   147,   152,  -130,
    -130,   153,   161,    63,   161,  -130,   154,   155,  -130,   143,
      73,  -130,  -130,   144,  -130,   156,   160,   162,   163,   164,
     105,    76,  -130,   166,   144,    54,    63,  -130,   128,   168,
     128,   128,    77,  -130,  -130,  -130,    39,    39,  -130,   128,
     157,    96,   149,   167,   169,   128,    76,  -130,  -130,  -130,
     128,   171,   172,    31,   170,    95,   174,    -5,   159,  -130,
     175,    -2,   176,   177,    96,    96,   179,  -130,  -130,  -130,
    -130,    39,  -130,  -130,  -130,   149,    39,    80,  -130,   158,
    -130,   173,  -130,  -130,   180,    99,  -130,   144,   183,   184,
     185,   128,   181,   128,  -130,   175,   128,   182,   128,   128,
    -130,  -130,  -130,    96,    39,  -130,  -130,   135,  -130,  -130,
    -130,   128,   186,   187,   188,  -130,  -130,   159,   144,  -130,
     128,  -130,   144,   190,   191,  -130,  -130,  -130,  -130,  -130,
    -130,   193,   192,  -130,   194,  -130,  -130,  -130,  -130,   195,
       5,   198,   196,   144,   207,   128,   197,   200,    22,  -130,
     128,   199,    26,   144,   201,   202,   144,  -130,   203,  -130
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     1,     0,    19,     3,     0,     0,
      12,    19,     4,     0,     0,     0,     0,    12,    20,     0,
       0,    12,    16,    23,    13,     8,     9,    10,    11,     6,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
      12,    23,    16,    16,    14,     0,    25,     2,    24,     5,
       0,     0,     0,     0,    17,     0,    30,     0,     0,    23,
       0,    16,    15,     0,     0,    31,    26,     0,     0,    21,
      18,    33,     0,    12,    30,     7,     0,     0,    32,     0,
       0,    22,    34,    35,    27,     0,     0,     0,     0,     0,
       0,    88,    38,     0,    35,    37,    12,    48,     0,     0,
       0,     0,     0,    81,    82,    83,     0,     0,    49,     0,
       0,    68,    74,    78,     0,     0,    89,    90,    29,    36,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    60,
      62,     0,     0,    84,    67,    66,     0,    50,    95,    96,
      71,     0,    97,    98,    99,    75,     0,     0,    92,     0,
      91,     0,    42,    43,     0,     0,    56,    35,     0,     0,
       0,     0,     0,     0,    94,    63,     0,     0,     0,     0,
      70,    69,    87,    72,     0,    76,    79,     0,    93,    39,
      41,     0,     0,     0,     0,    52,    51,    59,    35,    61,
       0,    64,    35,     0,     0,    73,    77,    80,    57,    40,
      28,     0,     0,    65,     0,    86,    85,    53,    47,    44,
       0,    46,     0,    35,     0,     0,     0,     0,     0,    45,
       0,     0,     0,    35,     0,     0,    35,    54,     0,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,   216,  -130,  -130,   178,    -4,    -7,   -22,   213,
    -130,    32,  -130,  -130,  -130,  -130,   114,   189,   -92,  -130,
    -130,    61,  -100,    70,    64,  -130,   -86,  -129,   -99,  -130,
    -127,   -83,  -130,   118,    72,  -130,    97
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     7,    39,    29,    16,    92,    34,    10,
      11,    37,    38,    57,    74,    96,    64,    65,    93,    94,
     211,   155,   127,   128,   129,   165,   130,   140,   111,   145,
     112,   113,   116,   117,   166,   141,   146
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      95,   131,   119,    17,   110,   170,   171,   134,   135,     1,
      17,    95,   125,    24,    17,    20,   126,    31,   212,   175,
      54,    55,    35,   136,   161,     3,    32,   161,    36,   149,
      33,     5,   162,    17,   151,   167,    51,   156,   102,    70,
      49,    50,   173,    21,   195,   213,   102,   196,    91,   103,
     104,   161,   105,   106,   107,   161,    91,   103,   104,   221,
     105,   156,     4,   224,     8,   183,    17,   109,   154,    79,
      48,     9,    32,    52,    95,   109,    53,    13,    72,    15,
     191,    73,   193,   194,   120,   121,   122,   102,    14,    17,
     123,    68,   124,   132,   133,   198,   202,    91,   103,   104,
     204,   105,   106,   107,   203,    95,    22,    72,    19,    95,
      84,   114,   102,    43,   115,   218,   109,   176,   138,   139,
     222,   216,    91,   103,   104,    23,   105,   106,   107,   158,
      95,   225,   159,   181,   228,   102,   182,    30,   108,    42,
      95,   109,    40,    95,    41,    91,   103,   104,    85,   105,
     106,   107,    86,    87,    44,    88,    45,    89,    46,    90,
      15,    91,    56,    58,   109,    25,    26,    27,    28,   181,
      47,    32,   197,   142,   143,   144,    59,    63,    62,    60,
      67,    61,    71,    83,    66,    91,   148,   163,    80,    97,
     137,    77,    69,    76,    82,    81,    98,   178,    99,   100,
     101,   184,   164,   147,   152,   153,   179,   118,   177,   210,
     157,   160,   214,   180,   168,   169,   172,   185,   186,   199,
     217,   188,   192,    12,    18,   201,   207,   189,   200,   205,
     206,   187,   215,   208,   150,   209,   220,   190,   219,   223,
       0,   226,   174,   227,   229,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78
};

static const yytype_int16 yycheck[] =
{
      83,   101,    94,    10,    90,   134,   135,   106,   107,     3,
      17,    94,    98,    17,    21,    12,    99,    21,    13,   146,
      42,    43,    10,   109,    29,    17,    34,    29,    16,   115,
      38,     6,    37,    40,   120,    37,    40,   123,     7,    61,
      33,    34,   141,    40,   173,    40,     7,   174,    17,    18,
      19,    29,    21,    22,    23,    29,    17,    18,    19,    37,
      21,   147,     0,    37,    16,   157,    73,    36,    37,    73,
      38,     5,    34,    41,   157,    36,    38,    17,    34,    16,
     166,    37,   168,   169,    30,    31,    32,     7,    17,    96,
      36,    59,    96,    16,    17,   181,   188,    17,    18,    19,
     192,    21,    22,    23,   190,   188,    17,    34,    30,   192,
      37,    35,     7,    39,    38,   215,    36,    37,    22,    23,
     220,   213,    17,    18,    19,    40,    21,    22,    23,    34,
     213,   223,    37,    34,   226,     7,    37,    17,    33,    17,
     223,    36,    40,   226,    40,    17,    18,    19,     4,    21,
      22,    23,     8,     9,    33,    11,    17,    13,    17,    15,
      16,    17,    36,    17,    36,    18,    19,    20,    21,    34,
      41,    34,    37,    24,    25,    26,    40,    16,    33,    41,
      30,    39,    17,    40,    36,    17,    17,    28,    74,    33,
      33,    38,    41,    41,    39,    41,    36,    39,    36,    36,
      36,    18,    27,    36,    33,    33,    33,    41,   147,    14,
      40,    37,    14,    33,    38,    38,    37,    33,    33,    33,
      13,    40,    40,     7,    11,    37,    33,   163,    41,    39,
      39,   161,    36,    41,   116,    41,    36,   165,    41,    40,
      -1,    40,   145,    41,    41,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    43,    17,     0,     6,    44,    45,    16,     5,
      51,    52,    44,    17,    17,    16,    48,    49,    51,    30,
      12,    40,    17,    40,    48,    18,    19,    20,    21,    47,
      17,    48,    34,    38,    50,    10,    16,    53,    54,    46,
      40,    40,    17,    39,    33,    17,    17,    41,    53,    33,
      34,    48,    53,    38,    50,    50,    36,    55,    17,    40,
      41,    39,    33,    16,    58,    59,    36,    30,    53,    41,
      50,    17,    34,    37,    56,    47,    41,    38,    59,    48,
      58,    41,    39,    40,    37,     4,     8,     9,    11,    13,
      15,    17,    49,    60,    61,    73,    57,    33,    36,    36,
      36,    36,     7,    18,    19,    21,    22,    23,    33,    36,
      68,    70,    72,    73,    35,    38,    74,    75,    41,    60,
      30,    31,    32,    36,    48,    68,    73,    64,    65,    66,
      68,    64,    16,    17,    70,    70,    68,    33,    22,    23,
      69,    77,    24,    25,    26,    71,    78,    36,    17,    68,
      75,    68,    33,    33,    37,    63,    68,    40,    34,    37,
      37,    29,    37,    28,    27,    67,    76,    37,    38,    38,
      69,    69,    37,    70,    78,    72,    37,    63,    39,    33,
      33,    34,    37,    60,    18,    33,    33,    65,    40,    66,
      76,    68,    40,    68,    68,    69,    72,    37,    68,    33,
      41,    37,    60,    68,    60,    39,    39,    33,    41,    41,
      14,    62,    13,    40,    14,    36,    60,    13,    64,    41,
      36,    37,    64,    40,    37,    60,    40,    41,    60,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    46,    46,    47,    47,
      47,    47,    48,    48,    49,    49,    50,    50,    50,    51,
      51,    52,    52,    53,    53,    55,    56,    57,    54,    54,
      58,    58,    58,    59,    59,    60,    60,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    62,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    67,    68,    68,    68,    68,
      68,    68,    69,    69,    70,    70,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    73,    73,
      74,    74,    75,    75,    76,    77,    77,    78,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     0,     2,     7,     0,     5,     1,     1,
       1,     1,     0,     2,     4,     6,     0,     3,     5,     0,
       2,     8,    10,     0,     2,     0,     0,     0,    12,     9,
       0,     1,     3,     2,     4,     0,     2,     1,     1,     4,
       5,     4,     3,     3,     7,    11,     8,     7,     2,     2,
       3,     5,     5,     7,     8,     9,     1,     3,     1,     3,
       1,     3,     1,     2,     2,     3,     2,     2,     1,     3,
       3,     2,     2,     3,     1,     2,     2,     3,     1,     3,
       4,     1,     1,     1,     2,     5,     5,     3,     1,     2,
       1,     2,     2,     3,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
        case 5:
#line 123 "parser.y" /* yacc.c:1646  */
    {
            if (level == GLOBAL_LEVEL) {
                if (lookup_id((char *)(yyvsp[-4]), CONSTANT) == -1) {
                    int x = insert_symbol((char *)(yyvsp[-4]), CONSTANT, (yyvsp[-5]));

                    if ((yyvsp[-5]) != (yyvsp[-2])) {
                        printerror("Variable and Expression type don't match\n");
                    }

                } else {
                    printerror("Duplicate declaration: %s\n", (char *)(yyvsp[-4]));
                }
            }
        }
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 146 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = NUMBER_TYPE;
        }
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 150 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = CHAR_TYPE;
        }
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 154 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = BOOL_TYPE;
        }
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 158 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = STRING_TYPE;
        }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 170 "parser.y" /* yacc.c:1646  */
    {
            if (level == GLOBAL_LEVEL) {

                if (lookup_id((char *)(yyvsp[-2]), GLOBAL_VAR) == -1) {
                    insert_symbol((char *)(yyvsp[-2]), GLOBAL_VAR, (yyvsp[-3]));
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)(yyvsp[-2]));
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), GLOBAL_VAR) == -1) {
                        insert_symbol(top(), GLOBAL_VAR, (yyvsp[-3]));
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            } else if (level == LOCAL_LEVEL) {
                if (lookup_id((char *)(yyvsp[-2]), LOCAL_VAR) == -1) {
                    insert_symbol((char *)(yyvsp[-2]), LOCAL_VAR, (yyvsp[-3]));
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)(yyvsp[-2]));
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), LOCAL_VAR) == -1) {
                        insert_symbol(top(), LOCAL_VAR, (yyvsp[-3]));
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            }
            // print_symtab();
        }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 206 "parser.y" /* yacc.c:1646  */
    {
            if (level == GLOBAL_LEVEL) {

                if (lookup_id((char *)(yyvsp[-4]), GLOBAL_VAR) == -1) {
                    int index = insert_symbol((char *)(yyvsp[-4]), GLOBAL_VAR, REFERENCE_TYPE);
                    set_attribute(index, (yyvsp[-5]));
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)(yyvsp[-4]));
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), GLOBAL_VAR) == -1) {
                        int index = insert_symbol(top(), GLOBAL_VAR, REFERENCE_TYPE);
                        set_attribute(index, (yyvsp[-5]));
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            } else if (level == LOCAL_LEVEL) {
                if (lookup_id((char *)(yyvsp[-4]), LOCAL_VAR) == -1) {
                    int index = insert_symbol((char *)(yyvsp[-4]), LOCAL_VAR, REFERENCE_TYPE);
                    set_param_type(index, 1, (yyvsp[-5]));
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)(yyvsp[-4]));
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), LOCAL_VAR) == -1) {
                        int index = insert_symbol(top(), LOCAL_VAR, REFERENCE_TYPE);
                        set_param_type(index, 1, (yyvsp[-5]));
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            }
            // print_symtab();
        }
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 250 "parser.y" /* yacc.c:1646  */
    {
            push((char *)(yyvsp[-1]));
        }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 254 "parser.y" /* yacc.c:1646  */
    {
            push((char *)(yyvsp[-3]));
        }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 276 "parser.y" /* yacc.c:1646  */
    {
            if (lookup_id((char *)(yyvsp[0]), GLOBAL_VAR) == -1 &&
                lookup_id((char *)(yyvsp[0]), FUNCTION) == -1) {

                function_index = insert_symbol((char *)(yyvsp[0]), FUNCTION, (yyvsp[-1]));

            } else {
                printerror("Duplicate parameter: %s\n", (char *)(yyvsp[0]));
            }

        }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 288 "parser.y" /* yacc.c:1646  */
    {
            level = PARAMETER_LEVEL;
            par_num = 0;
        }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 293 "parser.y" /* yacc.c:1646  */
    {
            set_attribute(function_index, par_num);
            level = LOCAL_LEVEL;
            var_num = 0;
        }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 299 "parser.y" /* yacc.c:1646  */
    {
            print_symtab();
            if (get_last_element() > function_index)
                clear_symbols(function_index + 1);
            print_symtab();
            level = GLOBAL_LEVEL;
        }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 307 "parser.y" /* yacc.c:1646  */
    {

            level = LOCAL_LEVEL;
            level = GLOBAL_LEVEL;
        }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 322 "parser.y" /* yacc.c:1646  */
    {
            if (level = PARAMETER_LEVEL) {
                if (lookup_id((char *)(yyvsp[0]), PARAMETER) == -1) {
                    (yyval) = insert_symbol((char *)(yyvsp[0]), PARAMETER, (yyvsp[-1]));
                    par_num++;
                    set_attribute((yyval), par_num);
                    set_param_type(function_index, par_num, (yyvsp[-1]));
                } else {
                    printerror("Duplicate parameter: %s\n", (char *)(yyvsp[0]));
                }

            }
        }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 336 "parser.y" /* yacc.c:1646  */
    {
            if (level = PARAMETER_LEVEL) {
                if (lookup_id((char *)(yyvsp[-2]), PARAMETER) == -1) {
                    int (yyval) = insert_symbol((char *)(yyvsp[-2]), PARAMETER, REFERENCE_TYPE);
                    set_param_type((yyval), 1, (yyvsp[-3]));
                    par_num++;
                    set_attribute((yyval), par_num);
                    set_param_type(function_index, par_num, (yyvsp[-3]));
                } else {
                    printerror("Duplicate parameter: %s\n", (char *)(yyvsp[-2]));
                }

            }
        }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 361 "parser.y" /* yacc.c:1646  */
    {
            // print_symtab();
            printf("%s\n", (char*)(yyvsp[-3]));
            if (lookup_id((char *)(yyvsp[-3]), LOCAL_VAR) == -1 &&
                lookup_id((char *)(yyvsp[-3]), GLOBAL_VAR) == -1 &&
                lookup_id((char *)(yyvsp[-3]), PARAMETER) == -1) {
                printerror("----- Used undiclared variable: %s\n", (char *)(yyvsp[-3]));
            }


        }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 420 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
            if (bool_return == 0 || (yyvsp[0]) != NUMBER_TYPE) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 428 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
            if (bool_return == 0 || (yyvsp[0]) != NUMBER_TYPE) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 436 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
            if (bool_return == 0) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 444 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1]);
            if (bool_return == 0 || (yyvsp[0]) != NUMBER_TYPE) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 452 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1]);
            if (bool_return == 0 || (yyvsp[0]) != NUMBER_TYPE) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 460 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1]);
            if ((yyvsp[-1]) != (yyvsp[0])) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 471 "parser.y" /* yacc.c:1646  */
    {
            if ((yyvsp[0]) != NUMBER_TYPE) {
                bool_return = 0;
            }
            (yyval) = (yyvsp[0]);
        }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 478 "parser.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-1]) != (yyvsp[0]) || (yyvsp[-1]) != NUMBER_TYPE) {
                bool_return = 0;
            }
            (yyval) = (yyvsp[-1]);
        }
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 488 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
        }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 492 "parser.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-1]) != (yyvsp[0])) {
                bool_return = 0;
            }
            (yyval) = (yyvsp[-1]);
        }
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 502 "parser.y" /* yacc.c:1646  */
    {
            if ((yyvsp[0]) != NUMBER_TYPE) {
                bool_return = 0;
            }
            (yyval) = (yyvsp[0]);
        }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 509 "parser.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-2]) != (yyvsp[0]) || (yyvsp[-2]) != NUMBER_TYPE) {
                bool_return = 0;
            }
            (yyval) = (yyvsp[-2]);
        }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 519 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = -1;
            if (level == LOCAL_LEVEL) {
                printf("Ovde\n");
                int var = lookup_id((char*)(yyvsp[0]), LOCAL_VAR);
                int parameter = lookup_id((char*)(yyvsp[0]), PARAMETER);
                if (var != -1 || parameter != -1) {
                    (yyval) = get_type(index);
                } else {
                    printerror("-Undiclared local variable: %s\n", (char *)(yyvsp[0]));
                }
            } else if (level == GLOBAL_LEVEL) {
                int index = lookup_id((char*)(yyvsp[0]), GLOBAL_VAR);
                if (index != -1) {
                    (yyval) = get_type(index);
                } else {
                    printerror("Undiclared local variable: %s\n", (char *)(yyvsp[0]));
                }
            }
        }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 542 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = NUMBER_TYPE;
        }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 546 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = CHAR_TYPE;
        }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 550 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = STRING_TYPE;
        }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 556 "parser.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-1]) != NUMBER_TYPE) {
                printerror("Length of array must be number!\n");
            }
        }
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 562 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1]);
        }
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 569 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
        }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 573 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1]);
            if ((yyvsp[0]) == REFERENCE_TYPE) {
                if (level == LOCAL_LEVEL) {
                    int index = lookup_id((char*)(yyvsp[-1]), LOCAL_VAR);
                    if (index != -1) {
                        if (get_type(index) != REFERENCE_TYPE) {
                            printerror("Local variable %s is not array!\n", (char *)(yyvsp[-1]));
                        }
                    } else {
                        printerror("Undiclared local variable: %s\n", (char *)(yyvsp[-1]));
                    }
                } else if (level == LOCAL_LEVEL) {
                    int index = lookup_id((char*)(yyvsp[-1]), GLOBAL_VAR);
                    if (index != -1) {
                        if (get_type(index) != REFERENCE_TYPE) {
                            printerror("Global variable %s is not array!\n", (char *)(yyvsp[-1]));
                        }
                    } else {
                        printerror("Undiclared global variable: %s\n", (char *)(yyvsp[-1]));
                    }
                }
            }
        }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 607 "parser.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-1]) != NUMBER_TYPE) {
                printerror("Array index must be number!\n");
            }
            (yyval) = REFERENCE_TYPE;
        }
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2006 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
  return yyresult;
}
#line 630 "parser.y" /* yacc.c:1906  */


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
