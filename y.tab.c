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


#line 130 "y.tab.c" /* yacc.c:339  */

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

#line 263 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   256

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  237

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
       0,   115,   115,   118,   120,   124,   141,   143,   147,   151,
     155,   159,   165,   167,   171,   207,   247,   276,   278,   282,
     288,   290,   295,   294,   314,   317,   319,   324,   336,   341,
     323,   354,   362,   364,   365,   369,   383,   400,   402,   406,
     407,   408,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   435,   436,   440,   441,
     445,   446,   450,   451,   455,   456,   460,   461,   465,   473,
     481,   489,   497,   505,   516,   523,   533,   537,   547,   554,
     564,   590,   591,   592,   596,   600,   604,   605,   606,   612,
     619,   624,   623,   649,   650,   654,   674,   684,   688,   689,
     693,   694,   695
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
  "ClassList", "ClassDecl", "$@1", "MethodDeclList", "MethodDecl", "$@2",
  "$@3", "$@4", "FormPars", "FormPar", "Block", "Statement", "ElseIfList",
  "ActPars", "Condition", "CondTerm", "CondFact", "CondFactList",
  "Expression", "AddopTermList", "Term", "MulopFactorList", "Factor",
  "Designator", "@5", "DesignatorRepeatList", "DesignatorRepeat", "Relop",
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

#define YYTABLE_NINF -92

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,     5,    10,    52,  -130,    22,    51,    52,    58,    60,
      50,    51,  -130,    53,    73,    70,    87,    55,    50,  -130,
     100,    94,    75,     9,    57,    21,  -130,  -130,  -130,  -130,
    -130,  -130,    99,    50,   110,   102,   113,   117,   142,   152,
     141,    21,   128,    50,   131,    46,    57,  -130,  -130,   147,
    -130,  -130,  -130,  -130,   167,   145,    21,   149,  -130,   154,
     170,   155,   160,    21,   151,    57,  -130,   172,    65,  -130,
    -130,   100,   156,   157,  -130,   161,   170,    50,   170,  -130,
     162,  -130,   163,  -130,   164,    66,  -130,  -130,   159,  -130,
     168,   169,   171,   173,   174,   107,    25,  -130,   165,   159,
      40,    50,  -130,   130,   176,   130,   130,   148,    74,  -130,
    -130,  -130,   137,   137,  -130,   130,   175,   158,   153,   177,
      78,  -130,  -130,   130,   178,   179,    32,   180,    97,   181,
     -12,   166,  -130,   187,    -8,   183,   184,   158,   158,   182,
    -130,  -130,  -130,  -130,   137,  -130,  -130,  -130,   153,   137,
      71,   198,   130,    78,  -130,   190,  -130,  -130,   191,   101,
    -130,   159,   199,   192,   193,   130,   188,   130,  -130,   187,
     130,   189,   130,   130,  -130,  -130,  -130,   158,   137,  -130,
    -130,   123,  -130,   194,  -130,  -130,  -130,   130,   197,   186,
     195,  -130,  -130,   166,   159,  -130,   130,  -130,   159,   196,
     200,  -130,  -130,  -130,  -130,  -130,  -130,  -130,   201,   202,
    -130,   203,  -130,  -130,  -130,  -130,   217,    -7,   222,   204,
     159,   224,   130,   205,   206,     7,  -130,   130,   207,    28,
     159,   208,   209,   159,  -130,   210,  -130
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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
       0,     0,     0,     0,     0,     0,    90,    40,     0,    37,
      39,    12,    50,     0,     0,     0,     0,     0,    90,    83,
      84,    85,     0,     0,    51,     0,     0,    70,    76,    80,
       0,    31,    38,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    62,    64,     0,     0,    86,    69,    68,     0,
      52,    98,    99,    73,     0,   100,   101,   102,    77,     0,
       0,     0,     0,    92,    93,     0,    44,    45,     0,     0,
      58,    37,     0,     0,     0,     0,     0,     0,    97,    65,
       0,     0,     0,     0,    72,    71,    89,    74,     0,    78,
      81,     0,    95,     0,    94,    41,    43,     0,     0,     0,
       0,    54,    53,    61,    37,    63,     0,    66,    37,     0,
       0,    75,    79,    82,    96,    59,    42,    30,     0,     0,
      67,     0,    88,    87,    55,    49,    46,     0,    48,     0,
      37,     0,     0,     0,     0,     0,    47,     0,     0,     0,
      37,     0,     0,    37,    56,     0,    57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,   231,  -130,  -130,   124,   -15,    -3,   -19,   185,
    -130,  -130,   -22,  -130,  -130,  -130,  -130,   122,   140,   -97,
    -130,  -130,    91,  -105,    80,    82,  -130,   -91,  -129,   -99,
    -130,  -126,   -88,  -130,  -130,   103,    83,  -130,   105
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     7,    42,    31,    17,    97,    36,    10,
      11,    22,    40,    41,    61,    78,   101,    68,    69,    98,
      99,   218,   159,   130,   131,   132,   169,   133,   143,   117,
     148,   118,   119,   120,   153,   154,   170,   144,   149
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     100,   134,   122,    26,   116,    37,   219,    18,   174,   175,
       4,   100,   128,   137,   138,    18,   129,   165,    44,    52,
       1,   165,     3,   179,   139,   166,    58,    59,    55,   171,
      18,    38,   155,   220,    64,   160,   165,    39,     8,   107,
      18,    72,    24,    34,   228,   177,    74,    35,   201,   108,
     109,   110,   202,   111,   112,   113,     9,   165,     5,   160,
     -91,   183,    84,   -91,   189,   231,    15,    16,   115,   158,
     123,   124,   125,   100,    18,    13,   126,    14,   107,   197,
      34,   199,   200,    20,    57,    21,   127,    23,   108,   109,
     110,    34,   111,   112,   113,    25,   205,   209,    18,    76,
      76,   211,    77,    89,    24,   210,   100,   115,   180,   -91,
     100,    32,   -91,   151,   107,    33,   152,   225,    27,    28,
      29,    30,   229,   223,   108,   109,   110,    45,   111,   112,
     113,   162,   100,   232,   163,   187,   235,   107,   188,    43,
     114,    46,   100,   115,   107,   100,    47,   108,   109,   110,
      48,   111,   112,   113,   108,   109,   110,   187,   111,    49,
     203,    53,    54,    90,   135,   136,   115,    91,    92,    50,
      93,    56,    94,   115,    95,    15,    96,   145,   146,   147,
     141,   142,    51,    60,    62,    63,    67,    66,    65,    75,
      71,    70,    73,   108,   167,    79,    19,    80,    81,    82,
      85,   102,    87,    86,    88,   103,   121,   104,   140,   105,
     106,   156,   157,   150,   168,   182,    83,   190,   164,   176,
     161,   172,   173,   185,   186,   191,   192,   207,   194,   198,
     206,   217,   208,   204,   214,   212,   221,   224,    12,   213,
     222,   181,   227,   215,   216,   193,   226,   230,   233,   195,
     234,   236,   196,   178,     0,     0,   184
};

static const yytype_int16 yycheck[] =
{
      88,   106,    99,    18,    95,    24,    13,    10,   137,   138,
       0,    99,   103,   112,   113,    18,   104,    29,    33,    41,
       3,    29,    17,   149,   115,    37,    45,    46,    43,    37,
      33,    10,   123,    40,    56,   126,    29,    16,    16,     7,
      43,    63,    17,    34,    37,   144,    65,    38,   177,    17,
      18,    19,   178,    21,    22,    23,     5,    29,     6,   150,
      35,   152,    77,    38,   161,    37,    16,    17,    36,    37,
      30,    31,    32,   161,    77,    17,    36,    17,     7,   170,
      34,   172,   173,    30,    38,    12,   101,    17,    17,    18,
      19,    34,    21,    22,    23,    40,   187,   194,   101,    34,
      34,   198,    37,    37,    17,   196,   194,    36,    37,    35,
     198,    17,    38,    35,     7,    40,    38,   222,    18,    19,
      20,    21,   227,   220,    17,    18,    19,    17,    21,    22,
      23,    34,   220,   230,    37,    34,   233,     7,    37,    40,
      33,    39,   230,    36,     7,   233,    33,    17,    18,    19,
      33,    21,    22,    23,    17,    18,    19,    34,    21,    17,
      37,    33,    34,     4,    16,    17,    36,     8,     9,    17,
      11,    40,    13,    36,    15,    16,    17,    24,    25,    26,
      22,    23,    41,    36,    17,    40,    16,    33,    39,    17,
      30,    36,    41,    17,    28,    71,    11,    41,    41,    38,
      78,    33,    39,    41,    40,    36,    41,    36,    33,    36,
      36,    33,    33,    36,    27,    17,    76,    18,    37,    37,
      40,    38,    38,    33,    33,    33,    33,    41,    40,    40,
      33,    14,    37,    39,    33,    39,    14,    13,     7,    39,
      36,   150,    36,    41,    41,   165,    41,    40,    40,   167,
      41,    41,   169,   148,    -1,    -1,   153
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
      19,    21,    22,    23,    33,    36,    69,    71,    73,    74,
      75,    41,    61,    30,    31,    32,    36,    48,    69,    74,
      65,    66,    67,    69,    65,    16,    17,    71,    71,    69,
      33,    22,    23,    70,    79,    24,    25,    26,    72,    80,
      36,    35,    38,    76,    77,    69,    33,    33,    37,    64,
      69,    40,    34,    37,    37,    29,    37,    28,    27,    68,
      78,    37,    38,    38,    70,    70,    37,    71,    80,    73,
      37,    64,    17,    69,    77,    33,    33,    34,    37,    61,
      18,    33,    33,    66,    40,    67,    78,    69,    40,    69,
      69,    70,    73,    37,    39,    69,    33,    41,    37,    61,
      69,    61,    39,    39,    33,    41,    41,    14,    63,    13,
      40,    14,    36,    61,    13,    65,    41,    36,    37,    65,
      40,    37,    61,    40,    41,    61,    41
};

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
      74,    75,    74,    76,    76,    77,    77,    78,    79,    79,
      80,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     0,     2,     7,     0,     5,     1,     1,
       1,     1,     0,     2,     4,     6,     4,     0,     3,     5,
       0,     2,     0,     9,    10,     0,     2,     0,     0,     0,
      12,     9,     0,     1,     3,     2,     4,     0,     2,     1,
       1,     4,     5,     4,     3,     3,     7,    11,     8,     7,
       2,     2,     3,     5,     5,     7,     8,     9,     1,     3,
       1,     3,     1,     3,     1,     2,     2,     3,     2,     2,
       1,     3,     3,     2,     2,     3,     1,     2,     2,     3,
       1,     3,     4,     1,     1,     1,     2,     5,     5,     3,
       1,     0,     3,     1,     2,     2,     3,     1,     1,     1,
       1,     1,     1
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
#line 125 "parser.y" /* yacc.c:1646  */
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
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 148 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = NUMBER_TYPE;
        }
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 152 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = CHAR_TYPE;
        }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 156 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = BOOL_TYPE;
        }
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 160 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = STRING_TYPE;
        }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 172 "parser.y" /* yacc.c:1646  */
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
            // // print_symtab();
        }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 208 "parser.y" /* yacc.c:1646  */
    {
            if (level == GLOBAL_LEVEL) {

                if (lookup_id((char *)(yyvsp[-4]), GLOBAL_VAR) == -1) {
                    int index = insert_symbol((char *)(yyvsp[-4]), GLOBAL_VAR, (yyvsp[-5]));
                    set_param_type(index, 1, REFERENCE_TYPE);
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)(yyvsp[-4]));
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), GLOBAL_VAR) == -1) {
                        int index = insert_symbol(top(), GLOBAL_VAR, (yyvsp[-5]));
                        set_param_type(index, 1, REFERENCE_TYPE);
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            } else if (level == LOCAL_LEVEL) {
                if (lookup_id((char *)(yyvsp[-4]), LOCAL_VAR) == -1) {
                    int index = insert_symbol((char *)(yyvsp[-4]), LOCAL_VAR, (yyvsp[-5]));
                    set_param_type(index, 1, REFERENCE_TYPE);
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)(yyvsp[-4]));
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), LOCAL_VAR) == -1) {
                        int index = insert_symbol(top(), LOCAL_VAR, (yyvsp[-5]));
                        set_param_type(index, 1, REFERENCE_TYPE);
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            }
            // // print_symtab();
        }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 248 "parser.y" /* yacc.c:1646  */
    {
            if (level == GLOBAL_LEVEL) {

                if (lookup_id((char *)(yyvsp[-2]), GLOBAL_VAR) == -1) {
                    int index = insert_symbol((char *)(yyvsp[-2]), GLOBAL_VAR, REFERENCE_TYPE);
                    set_class_type(index, (char*)(yyvsp[-3]));
                    set_param_type(index, 1, REFERENCE_TYPE);
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)(yyvsp[-2]));
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), GLOBAL_VAR) == -1) {
                        int index = insert_symbol(top(), GLOBAL_VAR, REFERENCE_TYPE);
                        set_class_type(index, (char*)(yyvsp[-3]));
                        set_param_type(index, 1, REFERENCE_TYPE);
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            }

            print_symtab();

        }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 279 "parser.y" /* yacc.c:1646  */
    {
            push((char *)(yyvsp[-1]));
        }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 283 "parser.y" /* yacc.c:1646  */
    {
            push((char *)(yyvsp[-3]));
        }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 295 "parser.y" /* yacc.c:1646  */
    {
            if (lookup_id((char*)(yyvsp[0]), CLASS_VAR) == -1) {
                int index = insert_symbol((char*)(yyvsp[0]), CLASS_VAR, -1);
                set_param_type(index, 1, REFERENCE_TYPE);
            } else {
                printerror("Duplicate class declaration: %s\n", top());
            }

            save_main_table();


        }
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 308 "parser.y" /* yacc.c:1646  */
    {
            print_symtab();
            save_class_table((char*)(yyvsp[-7]));
            return_main_table();
            print_symtab();
        }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 324 "parser.y" /* yacc.c:1646  */
    {
            if (lookup_id((char *)(yyvsp[0]), GLOBAL_VAR) == -1 &&
                lookup_id((char *)(yyvsp[0]), FUNCTION) == -1) {

                function_index = insert_symbol((char *)(yyvsp[0]), FUNCTION, (yyvsp[-1]));

            } else {
                printerror("Duplicate parameter: %s\n", (char *)(yyvsp[0]));
            }

        }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 336 "parser.y" /* yacc.c:1646  */
    {
            level = PARAMETER_LEVEL;
            par_num = 0;
        }
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 341 "parser.y" /* yacc.c:1646  */
    {
            set_attribute(function_index, par_num);
            level = LOCAL_LEVEL;
            var_num = 0;
        }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 347 "parser.y" /* yacc.c:1646  */
    {
            // print_symtab();
            if (get_last_element() > function_index)
                clear_symbols(function_index + 1);
            // print_symtab();
            level = GLOBAL_LEVEL;
        }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 355 "parser.y" /* yacc.c:1646  */
    {

            level = LOCAL_LEVEL;
            level = GLOBAL_LEVEL;
        }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 370 "parser.y" /* yacc.c:1646  */
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
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 384 "parser.y" /* yacc.c:1646  */
    {
            if (level = PARAMETER_LEVEL) {
                if (lookup_id((char *)(yyvsp[-2]), PARAMETER) == -1) {
                    int (yyval) = insert_symbol((char *)(yyvsp[-2]), PARAMETER, (yyvsp[-3]));
                    set_param_type((yyval), 1, REFERENCE_TYPE);
                    par_num++;
                    set_attribute((yyval), par_num);
                    set_param_type(function_index, par_num, (yyvsp[-3]));
                } else {
                    printerror("Duplicate parameter: %s\n", (char *)(yyvsp[-2]));
                }

            }
        }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 409 "parser.y" /* yacc.c:1646  */
    {
            // // print_symtab();
            /*printf("%s\n", (char*)$1);
            if (lookup_id((char *)$1, LOCAL_VAR) == -1 &&
                lookup_id((char *)$1, GLOBAL_VAR) == -1 &&
                lookup_id((char *)$1, PARAMETER) == -1) {
                printerror("----- Used undiclared variable: %s\n", (char *)$1);
            }*/
        }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 466 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
            if (bool_return == 0 || (yyvsp[0]) != NUMBER_TYPE) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 474 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
            if (bool_return == 0 || (yyvsp[0]) != NUMBER_TYPE) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 482 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
            if (bool_return == 0) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 490 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1]);
            if (bool_return == 0 || (yyvsp[0]) != NUMBER_TYPE) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 498 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1]);
            if (bool_return == 0 || (yyvsp[0]) != NUMBER_TYPE) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 506 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1]);
            if ((yyvsp[-1]) != (yyvsp[0])) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 517 "parser.y" /* yacc.c:1646  */
    {
            if ((yyvsp[0]) != NUMBER_TYPE) {
                bool_return = 0;
            }
            (yyval) = (yyvsp[0]);
        }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 524 "parser.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-1]) != (yyvsp[0]) || (yyvsp[-1]) != NUMBER_TYPE) {
                bool_return = 0;
            }
            (yyval) = (yyvsp[-1]);
        }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 534 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
        }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 538 "parser.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-1]) != (yyvsp[0])) {
                bool_return = 0;
            }
            (yyval) = (yyvsp[-1]);
        }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 548 "parser.y" /* yacc.c:1646  */
    {
            if ((yyvsp[0]) != NUMBER_TYPE) {
                bool_return = 0;
            }
            (yyval) = (yyvsp[0]);
        }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 555 "parser.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-2]) != (yyvsp[0]) || (yyvsp[-2]) != NUMBER_TYPE) {
                bool_return = 0;
            }
            (yyval) = (yyvsp[-2]);
        }
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 565 "parser.y" /* yacc.c:1646  */
    {

            (yyval) = -1;

            int globalVarIndex = lookup_id((char*)(yyvsp[0]), GLOBAL_VAR);
            int varIndex = lookup_id((char*)(yyvsp[0]), LOCAL_VAR);
            int parameterIndex = lookup_id((char*)(yyvsp[0]), PARAMETER);

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
                printerror("!! Undiclared variable: %s\n", (char *)(yyvsp[0]));
            }

        }
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 593 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = NUMBER_TYPE;
        }
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 597 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = CHAR_TYPE;
        }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 601 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = STRING_TYPE;
        }
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 607 "parser.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-1]) != NUMBER_TYPE) {
                printerror("Length of array must be number!\n");
            }
        }
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 613 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1]);
        }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 620 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
        }
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 624 "parser.y" /* yacc.c:1646  */
    {
            current_var = (char*)(yyvsp[0]);
        }
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 628 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-2]);

            if ((yyvsp[-1]) == REFERENCE_TYPE) {

                printf("Designator array\n");
                int globalVarIndex = lookup_id((char*)(yyvsp[-2]), GLOBAL_VAR);
                int varIndex = lookup_id((char*)(yyvsp[-2]), LOCAL_VAR);
                int parameterIndex = lookup_id((char*)(yyvsp[-2]), PARAMETER);

                if ((globalVarIndex == -1 || get_param_type(globalVarIndex, 1) != REFERENCE_TYPE) &&
                    (varIndex == -1 || get_param_type(varIndex, 1) != REFERENCE_TYPE) &&
                    (parameterIndex == -1 && get_param_type(parameterIndex, 1) != REFERENCE_TYPE)) {
                    printerror("Used undiclared variable: %s\n", (char *)(yyvsp[-2]));
                }
            }

        }
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 655 "parser.y" /* yacc.c:1646  */
    {
            save_main_table();
            if (current_var != NULL) {
                printf("%s\n", current_var);

                int index = lookup_id(current_var, GLOBAL_VAR);
                if (index != -1 && get_class_type(index) != NULL) {
                    char* className =  get_class_type(index);
                    switch_table_to(className);
                    int index = lookup_id((char*)(yyvsp[0]), FUNCTION);
                    if (index == -1) {
                        printerror("Function %s is undeclared!\n", (char*)(yyvsp[0]));
                    }
                }
            }
            return_main_table();
            current_var = NULL;

        }
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 675 "parser.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-1]) != NUMBER_TYPE) {
                printerror("Array index must be number!\n");
            }
            (yyval) = REFERENCE_TYPE;
        }
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2100 "y.tab.c" /* yacc.c:1646  */
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
#line 698 "parser.y" /* yacc.c:1906  */


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
