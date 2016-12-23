/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
