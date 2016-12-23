
// Parser for MicroJava

%{
    #include <stdio.h>
    #include "defs.h"

    int yyparse(void);
    int yylex(void);
    int yyerror(char *s);

    extern int line;
    int error_count = 0;
%}


%token _PROGRAM
%token _BREAK
%token _CLASS
%token _CONST
%token _NEW
%token _PRINT
%token _READ
%token _VOID
%token _WHILE
%token _EXTENDS
%token _IF
%token _ELSE
%token _RETURN
%token _TYPE

%token _ID
%token _NUMBER
%token _CHAR_CONST
%token _BOOL_CONST
%token _STRING_CONST

%token _PLUS
%token _MINUS
%token _TIMES
%token _DIV
%token _MOD
%token _RELOP
%token _AND
%token _OR
%token _ASSIGN
%token _INCREMENT
%token _DECREMENT
%token _SEMICOLON
%token _COMMA
%token _DOT
%token _LPAREN
%token _RPAREN
%token _LSQBRACKET
%token _RSQBRACKET
%token _LBRACKET
%token _RBRACKET


%%

Program
    : _PROGRAM _ID ConstList _LBRACKET MethodDecl _RBRACKET
    | _PROGRAM _ID ClassList _LBRACKET MethodDecl _RBRACKET
    | _PROGRAM _ID VarList _LBRACKET MethodDecl _RBRACKET
    | _PROGRAM _ID ConstList ClassList _LBRACKET MethodDecl _RBRACKET
    | _PROGRAM _ID ConstList VarList _LBRACKET MethodDecl _RBRACKET
    | _PROGRAM _ID ClassList VarList _LBRACKET MethodDecl _RBRACKET
    | _PROGRAM _ID ConstList ClassList VarList _LBRACKET MethodDecl _RBRACKET
    ;

ConstList
    : ConstDecl
    | ConstList ConstDecl
    ;

ConstDecl
    : _CONST _TYPE _ID _ASSIGN ConstType ConstDeclList _SEMICOLON
    ;

ConstDeclList
    :
    | ConstDeclList _COMMA _ID _ASSIGN ConstType
    ;

ConstType
    : _NUMBER
    | _CHAR_CONST
    | _BOOL_CONST
    | _STRING_CONST
    ;

VarList
    : VarDecl
    | VarList VarDecl
    ;

LocalVarList
    : VarDecl
    | LocalVarList VarDecl
    ;

VarDecl
    : _TYPE _ID VarDeclList _SEMICOLON
    | _TYPE _ID _LSQBRACKET _RSQBRACKET VarDeclList _SEMICOLON
    ;

VarDeclList
    :
    | VarDeclList _COMMA _ID
    | VarDeclList _COMMA _ID _LSQBRACKET _RSQBRACKET
    ;

ClassList
    : ClassDecl
    | ClassList ClassDecl
    ;

ClassDecl
    : _CLASS _ID _LBRACKET LocalVarList _LBRACKET _RBRACKET _RBRACKET
    | _CLASS _ID _LBRACKET LocalVarList _LBRACKET MethodDeclList _RBRACKET _RBRACKET
    | _CLASS _ID _EXTENDS _ID _LBRACKET LocalVarList _LBRACKET MethodDeclList _RBRACKET _RBRACKET
    ;

MethodDeclList
    : MethodDecl
    | MethodDeclList MethodDecl
    ;

MethodDecl
    : _TYPE _ID _LPAREN _RPAREN _LBRACKET Block _RBRACKET
    | _TYPE _ID _LPAREN _RPAREN _LBRACKET _RBRACKET
    | _VOID _ID _LPAREN _RPAREN _LBRACKET Block _RBRACKET
    | _TYPE _ID _LPAREN _RPAREN LocalVarList _LBRACKET Block _RBRACKET
    | _TYPE _ID _LPAREN FormPars _RPAREN LocalVarList _LBRACKET Block _RBRACKET
    | _VOID _ID _LPAREN _RPAREN LocalVarList _LBRACKET Block _RBRACKET
    | _VOID _ID _LPAREN FormPars _RPAREN _LBRACKET Block _RBRACKET
    | _VOID _ID _LPAREN FormPars _RPAREN _LBRACKET _RBRACKET
    ;

FormPars
    : FormPar
    | FormPars _COMMA FormPar
    ;

FormPar
    : _TYPE _ID
    | _TYPE _ID _LSQBRACKET _RSQBRACKET
    ;

Block
  : Statement
  | Block Statement
  ;

Statement
    : Designator
    | Designator _ASSIGN Expression _SEMICOLON
    | Designator _LPAREN ActPars _RPAREN _SEMICOLON
    | Designator _LPAREN _RPAREN _SEMICOLON
    | Designator _INCREMENT _SEMICOLON
    | Designator _DECREMENT _SEMICOLON
    | _IF _LPAREN Condition _RPAREN _LBRACKET Block _RBRACKET
    | _IF _LPAREN Condition _RPAREN _LBRACKET Block _RBRACKET _ELSE _LBRACKET Block _RBRACKET
    ;



ActPars
    : Expression
    | ActPars _COMMA Expression
    ;

Condition
    : CondTerm
    | Condition _OR CondTerm
    ;

CondTerm
    : CondFact
    | CondTerm _AND CondFact
    ;

CondFact
    : Expression
    | Expression CondFactList
    ;

CondFactList
    : Relop Expression
    | CondFactList Relop Expression
    ;

Expression
    : _MINUS Term
    | Term
    | _MINUS Term AddopTermList
    | Term AddopTermList
    ;

AddopTermList
    : Addop Term
    | Addop Term AddopTermList
    ;

Term
    : Factor
    | Factor MulopFactorList
    ;

MulopFactorList
    : Mulop Factor
    | MulopFactorList Mulop Factor
    ;

Factor
    : Designator
    | Designator _LPAREN _RPAREN
    | Designator _LPAREN ActPars _RPAREN
    | _NUMBER
    | _CHAR_CONST
    | _STRING_CONST
    | _NEW _ID
    | _NEW _ID _LSQBRACKET Expression _RSQBRACKET
    | _LPAREN Expression _RPAREN
    ;

Designator
    : _ID
    | _ID DesignatorRepeatList
    ;

DesignatorRepeatList
    : DesignatorRepeat
    | DesignatorRepeatList DesignatorRepeat
    ;

DesignatorRepeat
    : _DOT _ID
    | _LSQBRACKET Expression _RSQBRACKET
    ;

Relop
    : _RELOP
    ;

Addop
    : _PLUS
    | _MINUS
    ;

Mulop
    : _TIMES
    | _DIV
    | _MOD
    ;

%%

int yyerror(char *s) {
    fprintf(stderr, "\nERROR (%d): %s", line, s);
    error_count++;
    return 0;
}

int main() {
    printf("\nSTART\n");
    yyparse();
    printf("\nSTOP\n");
    return error_count;
}
