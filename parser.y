
// Parser for MicroJava

%{
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
    : _PROGRAM _ID ConstList ClassList VarList _LBRACKET MethodDeclList _RBRACKET
    ;

ConstList
    :
    | ConstDecl ConstList
    ;

ConstDecl
    : _CONST _TYPE _ID _ASSIGN ConstType ConstDeclList _SEMICOLON
        {
            if (level == GLOBAL_LEVEL) {
                if (lookup_id((char *)$3, CONSTANT) == -1) {
                    int x = insert_symbol((char *)$3, CONSTANT, $2);

                    if ($2 != $5) {
                        printerror("Variable and Expression type don't match\n");
                    }

                } else {
                    printerror("Duplicate declaration: %s\n", (char *)$3);
                }
            }
        }
    ;

ConstDeclList
    :
    | ConstDeclList _COMMA _ID _ASSIGN ConstType
    ;

ConstType
    : _NUMBER
        {
            $$ = NUMBER_TYPE;
        }
    | _CHAR_CONST
        {
            $$ = CHAR_TYPE;
        }
    | _BOOL_CONST
        {
            $$ = BOOL_TYPE;
        }
    | _STRING_CONST
        {
            $$ = STRING_TYPE;
        }
    ;

VarList
    :
    | VarDecl VarList
    ;

VarDecl
    : _TYPE _ID VarDeclList _SEMICOLON
        {
            if (level == GLOBAL_LEVEL) {

                if (lookup_id((char *)$2, GLOBAL_VAR) == -1) {
                    insert_symbol((char *)$2, GLOBAL_VAR, $1);
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)$2);
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), GLOBAL_VAR) == -1) {
                        insert_symbol(top(), GLOBAL_VAR, $1);
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            } else if (level == LOCAL_LEVEL) {
                if (lookup_id((char *)$2, LOCAL_VAR) == -1) {
                    insert_symbol((char *)$2, LOCAL_VAR, $1);
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)$2);
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), LOCAL_VAR) == -1) {
                        insert_symbol(top(), LOCAL_VAR, $1);
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            }
            // print_symtab();
        }
    | _TYPE _ID _LSQBRACKET _RSQBRACKET VarDeclList _SEMICOLON
        {
            if (level == GLOBAL_LEVEL) {

                if (lookup_id((char *)$2, GLOBAL_VAR) == -1) {
                    int index = insert_symbol((char *)$2, GLOBAL_VAR, REFERENCE_TYPE);
                    set_attribute(index, $1);
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)$2);
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), GLOBAL_VAR) == -1) {
                        int index = insert_symbol(top(), GLOBAL_VAR, REFERENCE_TYPE);
                        set_attribute(index, $1);
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            } else if (level == LOCAL_LEVEL) {
                if (lookup_id((char *)$2, LOCAL_VAR) == -1) {
                    int index = insert_symbol((char *)$2, LOCAL_VAR, REFERENCE_TYPE);
                    set_param_type(index, 1, $1);
                } else {
                    printerror("Duplicate declaration: %s\n", (char *)$2);
                }

                while(!isEmpty()) {
                    if (lookup_id(top(), LOCAL_VAR) == -1) {
                        int index = insert_symbol(top(), LOCAL_VAR, REFERENCE_TYPE);
                        set_param_type(index, 1, $1);
                    } else {
                        printerror("Duplicate declaration: %s\n", top());
                    }
                    pop();
                }
            }
            // print_symtab();
        }
    ;

VarDeclList
    :
    | _COMMA _ID VarDeclList
        {
            push((char *)$2);
        }
    | _COMMA _ID _LSQBRACKET _RSQBRACKET VarDeclList
        {
            push((char *)$2);
        }
    ;

ClassList
    :
    | ClassDecl ClassList
    ;

ClassDecl
    : _CLASS _ID _LBRACKET VarList _LBRACKET MethodDeclList _RBRACKET _RBRACKET
    | _CLASS _ID _EXTENDS _ID _LBRACKET VarList _LBRACKET MethodDeclList _RBRACKET _RBRACKET
    ;

MethodDeclList
    :
    | MethodDecl MethodDeclList
    ;

MethodDecl
    : _TYPE _ID
        {
            if (lookup_id((char *)$2, GLOBAL_VAR) == -1 &&
                lookup_id((char *)$2, FUNCTION) == -1) {

                function_index = insert_symbol((char *)$2, FUNCTION, $1);

            } else {
                printerror("Duplicate parameter: %s\n", (char *)$2);
            }

        }
    _LPAREN
        {
            level = PARAMETER_LEVEL;
            par_num = 0;
        }
    FormPars _RPAREN
        {
            set_attribute(function_index, par_num);
            level = LOCAL_LEVEL;
            var_num = 0;
        }
    VarList _LBRACKET Block _RBRACKET
        {
            print_symtab();
            if (get_last_element() > function_index)
                clear_symbols(function_index + 1);
            print_symtab();
            level = GLOBAL_LEVEL;
        }
    | _VOID _ID _LPAREN FormPars _RPAREN VarList _LBRACKET Block _RBRACKET
        {

            level = LOCAL_LEVEL;
            level = GLOBAL_LEVEL;
        }
    ;

FormPars
    :
    | FormPar
    | FormPars _COMMA FormPar
    ;

FormPar
    : _TYPE _ID
        {
            if (level = PARAMETER_LEVEL) {
                if (lookup_id((char *)$2, PARAMETER) == -1) {
                    $$ = insert_symbol((char *)$2, PARAMETER, $1);
                    par_num++;
                    set_attribute($$, par_num);
                    set_param_type(function_index, par_num, $1);
                } else {
                    printerror("Duplicate parameter: %s\n", (char *)$2);
                }

            }
        }
    | _TYPE _ID _LSQBRACKET _RSQBRACKET
        {
            if (level = PARAMETER_LEVEL) {
                if (lookup_id((char *)$2, PARAMETER) == -1) {
                    int $$ = insert_symbol((char *)$2, PARAMETER, REFERENCE_TYPE);
                    set_param_type($$, 1, $1);
                    par_num++;
                    set_attribute($$, par_num);
                    set_param_type(function_index, par_num, $1);
                } else {
                    printerror("Duplicate parameter: %s\n", (char *)$2);
                }

            }
        }
    ;

Block
    :
    | Statement Block
    ;

Statement
    : Designator
    | VarDecl
    | Designator _ASSIGN Expression _SEMICOLON
        {
            // print_symtab();
            printf("%s\n", (char*)$1);
            if (lookup_id((char *)$1, LOCAL_VAR) == -1 &&
                lookup_id((char *)$1, GLOBAL_VAR) == -1 &&
                lookup_id((char *)$1, PARAMETER) == -1) {
                printerror("----- Used undiclared variable: %s\n", (char *)$1);
            }


        }
    | Designator _LPAREN ActPars _RPAREN _SEMICOLON
    | Designator _LPAREN _RPAREN _SEMICOLON
    | Designator _INCREMENT _SEMICOLON
    | Designator _DECREMENT _SEMICOLON
    | _IF _LPAREN Condition _RPAREN _LBRACKET Block _RBRACKET
    | _IF _LPAREN Condition _RPAREN _LBRACKET Block _RBRACKET _ELSE _LBRACKET Block _RBRACKET
    | _IF _LPAREN Condition _RPAREN _LBRACKET Block _RBRACKET ElseIfList
    | _WHILE _LPAREN Condition _RPAREN _LBRACKET Block _RBRACKET
    | _BREAK _SEMICOLON
    | _RETURN _SEMICOLON
    | _RETURN Expression _SEMICOLON
    | _READ _LPAREN Designator _RPAREN _SEMICOLON
    | _PRINT _LPAREN Expression _RPAREN _SEMICOLON
    | _PRINT _LPAREN Expression _COMMA _NUMBER _RPAREN _SEMICOLON
    ;

ElseIfList
    : _ELSE _IF _LPAREN Condition _RPAREN _LBRACKET Block _RBRACKET
    | ElseIfList _ELSE _IF _LPAREN Condition _RPAREN _LBRACKET Block _RBRACKET
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
        {
            $$ = $2;
            if (bool_return == 0 || $2 != NUMBER_TYPE) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
    | _PLUS Term
        {
            $$ = $2;
            if (bool_return == 0 || $2 != NUMBER_TYPE) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
    | Term
        {
            $$ = $1;
            if (bool_return == 0) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
    | _MINUS Term AddopTermList
        {
            $$ = $2;
            if (bool_return == 0 || $3 != NUMBER_TYPE) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
    | _PLUS Term AddopTermList
        {
            $$ = $2;
            if (bool_return == 0 || $3 != NUMBER_TYPE) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
    | Term AddopTermList
        {
            $$ = $1;
            if ($1 != $2) {
                printerror("Expression uses incompatible types!\n");
            }
            bool_return = 1;
        }
    ;

AddopTermList
    : Addop Term
        {
            if ($2 != NUMBER_TYPE) {
                bool_return = 0;
            }
            $$ = $2;
        }
    | Addop Term AddopTermList
        {
            if ($2 != $3 || $2 != NUMBER_TYPE) {
                bool_return = 0;
            }
            $$ = $2;
        }
    ;

Term
    : Factor
        {
            $$ = $1;
        }
    | Factor MulopFactorList
        {
            if ($1 != $2) {
                bool_return = 0;
            }
            $$ = $1;
        }
    ;

MulopFactorList
    : Mulop Factor
        {
            if ($2 != NUMBER_TYPE) {
                bool_return = 0;
            }
            $$ = $2;
        }
    | MulopFactorList Mulop Factor
        {
            if ($1 != $3 || $1 != NUMBER_TYPE) {
                bool_return = 0;
            }
            $$ = $1;
        }
    ;

Factor
    : Designator
        {
            // umesto get_type vrati get_param
            // treba proveriti LOCAL_VAR, GLOBAL_VAR i PARAMETER nezavisno od levela
            $$ = -1;
            if (level == LOCAL_LEVEL) {
                printf("Ovde\n");
                int varIndex = lookup_id((char*)$1, LOCAL_VAR);
                int parameterIndex = lookup_id((char*)$1, PARAMETER);
                if (var != -1 || parameter != -1) {
                    $$ = get_type(index);
                } else {
                    printerror("-Undiclared local variable: %s\n", (char *)$1);
                }
            } else if (level == GLOBAL_LEVEL) {
                int index = lookup_id((char*)$1, GLOBAL_VAR);
                if (index != -1) {
                    $$ = get_type(index);
                } else {
                    printerror("Undiclared local variable: %s\n", (char *)$1);
                }
            }
        }
    | Designator _LPAREN _RPAREN
    | Designator _LPAREN ActPars _RPAREN
    | _NUMBER
        {
            $$ = NUMBER_TYPE;
        }
    | _CHAR_CONST
        {
            $$ = CHAR_TYPE;
        }
    | _STRING_CONST
        {
            $$ = STRING_TYPE;
        }
    | _NEW _ID
    | _NEW _ID _LSQBRACKET Expression _RSQBRACKET
    | _NEW _TYPE _LSQBRACKET Expression _RSQBRACKET
        {
            if ($4 != NUMBER_TYPE) {
                printerror("Length of array must be number!\n");
            }
        }
    | _LPAREN Expression _RPAREN
        {
            $$ = $2;
        }
    ;

Designator
    : _ID
        {
            $$ = $1;
        }
    | _ID DesignatorRepeatList
        {
            // isti problem kao gore (Designator)
            $$ = $1;
            if ($2 == REFERENCE_TYPE) {
                if (level == LOCAL_LEVEL) {
                    int index = lookup_id((char*)$1, LOCAL_VAR);
                    if (index != -1) {
                        if (get_type(index) != REFERENCE_TYPE) {
                            printerror("Local variable %s is not array!\n", (char *)$1);
                        }
                    } else {
                        printerror("Undiclared local variable: %s\n", (char *)$1);
                    }
                } else if (level == GLOBAL_VAR) {
                    int index = lookup_id((char*)$1, GLOBAL_VAR);
                    if (index != -1) {
                        if (get_type(index) != REFERENCE_TYPE) {
                            printerror("Global variable %s is not array!\n", (char *)$1);
                        }
                    } else {
                        printerror("Undiclared global variable: %s\n", (char *)$1);
                    }
                }
            }
        }
    ;

DesignatorRepeatList
    : DesignatorRepeat
    | DesignatorRepeatList DesignatorRepeat
    ;

DesignatorRepeat
    : _DOT _ID
    | _LSQBRACKET Expression _RSQBRACKET
        {
            if ($2 != NUMBER_TYPE) {
                printerror("Array index must be number!\n");
            }
            $$ = REFERENCE_TYPE;
        }
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
