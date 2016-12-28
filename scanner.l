/* Scanner for MicroJava */

%{
    #include <string.h>
    #include "y.tab.h"
    #include "defs.h"

    int line = 1;

    extern YYSTYPE yylval;
%}

char                        [_a-zA-Z0-9]
letter                      [_a-zA-Z]
digit                       [0-9]


%%

[ \t]+                      {   /* skip */    }

"program"                   {   return _PROGRAM;  }
"break"                     {   return _BREAK;    }
"class"                     {   return _CLASS;    }
"const"                     {   return _CONST;    }
"new"                       {   return _NEW;      }
"print"                     {   return _PRINT;    }
"read"                      {   return _READ;     }
"void"                      {   return _VOID;     }
"while"                     {   return _WHILE;    }
"extends"                   {   return _EXTENDS;  }
"if"                        {   return _IF;       }
"else"                      {   return _ELSE;     }
"return"                    {   return _RETURN;   }
"int"                       {   yylval = NUMBER_TYPE; return _TYPE;   }
"bool"                      {   yylval = BOOL_TYPE; return _TYPE;     }
"string"                    {   yylval = STRING_TYPE; return _TYPE;   }
"char"                      {   yylval = CHAR_TYPE; return _TYPE;     }

("true"|"false")                {   yylval = (int)strdup(yytext); return _BOOL_CONST;   }

{letter}({letter}|{digit}|"_")* {   yylval = (int)strdup(yytext); return _ID;           }

{digit}({digit})*               {   yylval = (int)strdup(yytext); return _NUMBER;       }

[\']{char}[\']                  {   yylval = (int)strdup(yytext); return _CHAR_CONST;   }

[\"]({char})*[\"]               {   yylval = (int)strdup(yytext); return _STRING_CONST; }

"+"                         {   return _PLUS;       }
"-"                         {   return _MINUS;      }
"*"                         {   return _TIMES;      }
"/"                         {   return _DIV;        }
"%"                         {   return _MOD;        }
"=="                        {   return _RELOP;      }
"!="                        {   return _RELOP;      }
">"                         {   return _RELOP;      }
">="                        {   return _RELOP;      }
"<"                         {   return _RELOP;      }
"<="                        {   return _RELOP;      }
"&&"                        {   return _AND;        }
"||"                        {   return _OR;         }
"="                         {   return _ASSIGN;     }
"++"                        {   return _INCREMENT;  }
"--"                        {   return _DECREMENT;  }
";"                         {   return _SEMICOLON;  }
","                         {   return _COMMA;      }
"."                         {   return _DOT;        }
"("                         {   return _LPAREN;     }
")"                         {   return _RPAREN;     }
"["                         {   return _LSQBRACKET; }
"]"                         {   return _RSQBRACKET; }
"{"                         {   return _LBRACKET;   }
"}"                         {   return _RBRACKET;   }


\/\/.*                      {   /* skip */   }

"\n"                        {   line++;    }
.                           {   printf("\nLEXICAL ERROR on character %c (line %d)", yytext[0], line);   }

%%

int yywrap() {
    return 1;
}
