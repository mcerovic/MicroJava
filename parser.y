
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
        {
            check_main();
        }
    ;

ConstList
    :
    | ConstDecl ConstList
    ;

ConstDecl
    : _CONST _TYPE _ID _ASSIGN ConstType ConstDeclList _SEMICOLON
        {
            if (level == GLOBAL_LEVEL) {
                if (lookup_id((char *)$3, CONST_VAR) == -1) {
                    int index = insert_symbol((char *)$3, CONST_VAR, $2);

                    if ($2 != $5) {
                        printerror("Variable and Expression type don't match\n");
                    }

                } else {
                    printerror("Duplicate declaration of %s!\n", (char *)$3);
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
            try_to_insert_constant((char*)$1, NUMBER_TYPE);
        }
    | _CHAR_CONST
        {
            $$ = CHAR_TYPE;
            try_to_insert_constant((char*)$1, CHAR_TYPE);
        }
    | _BOOL_CONST
        {
            $$ = BOOL_TYPE;
            try_to_insert_constant((char*)$1, BOOL_TYPE);
        }
    | _STRING_CONST
        {
            $$ = STRING_TYPE;
            try_to_insert_constant((char*)$1, STRING_TYPE);
        }
    ;

VarList
    :
    | VarDecl VarList
    ;

VarDecl
    : _TYPE _ID VarDeclList _SEMICOLON
        {
            push(variables, (char*)$2, 0);

            while(!isEmpty(variables)) {
                int index = declareVariable($1, top(variables)->name, top(variables)->is_reference, NULL, level);
                if (index == -1) {
                    printerror("Duplicate declaration: %s\n", top(variables)->name);
                }
                pop(variables);
            }

        }
    | _TYPE _ID _LSQBRACKET _RSQBRACKET VarDeclList _SEMICOLON
        {
            push(variables, (char*)$2, 1);

            while(!isEmpty(variables)) {
                int index = declareVariable($1, top(variables)->name, top(variables)->is_reference, NULL, level);
                if (index == -1) {
                    printerror("Duplicate declaration: %s\n", top(variables)->name);
                }
                pop(variables);
            }
        }
    | _ID _ID VarDeclList _SEMICOLON
        {
            push(variables, (char*)$2, 1);

            while(!isEmpty(variables)) {
                int index = declareVariable(REFERENCE_TYPE, top(variables)->name, 1, (char*)$1, level);
                if (index == -1) {
                    printerror("Duplicate declaration: %s\n", top(variables)->name);
                }
                pop(variables);
            }
        }
    | _ID _ID _LSQBRACKET _RSQBRACKET VarDeclList _SEMICOLON
        {
            push(variables, (char*)$2, 1);

            while(!isEmpty(variables)) {
                int index = declareVariable(REFERENCE_TYPE, top(variables)->name, 1, (char*)$1, level);
                if (index == -1) {
                    printerror("Duplicate declaration: %s\n", top(variables)->name);
                }
                pop(variables);
            }
        }
    ;

VarDeclList
    :
    | _COMMA _ID VarDeclList
        {
            push(variables, (char*)$2, 0);
        }
    | _COMMA _ID _LSQBRACKET _RSQBRACKET VarDeclList
        {
            push(variables, (char*)$2, 1);
        }
    ;

ClassList
    :
    | ClassDecl ClassList
    ;

ClassDecl
    : _CLASS _ID
        {

            declareClass((char*)$2, NULL);
            save_main_table();
            level = CLASS_LEVEL;
            parent_class = NULL;

        }
    _LBRACKET VarList _LBRACKET MethodDeclList _RBRACKET _RBRACKET
        {
            save_class_table((char*)$2);
            return_main_table();
            level = GLOBAL_LEVEL;
            parent_class = NULL;
        }
    | _CLASS _ID _EXTENDS _ID
        {
            declareClass((char*)$2, (char*)$4);
            save_main_table();
            level = CLASS_LEVEL;
            parent_class = (char*)$4;
        }
      _LBRACKET VarList _LBRACKET MethodDeclList _RBRACKET _RBRACKET
        {
            save_class_table((char*)$2);
            return_main_table();
            level = GLOBAL_LEVEL;
            parent_class = NULL;
        }
    ;

MethodDeclList
    :
    | MethodDecl MethodDeclList
    ;

MethodDecl
    : _TYPE _ID
        {
            if (lookup_id((char *)$2, FUNCTION) == -1) {
                if (lookup_id((char *)$2, GLOBAL_VAR) == -1 && lookup_id((char *)$2, CLASS_VAR) == -1) {
                    function_index = insert_symbol((char *)$2, FUNCTION, $1);
                } else {
                    printerror("You are tryping to rediclare global or class variable %s to function!", (char *)$2);
                }
            } else {
                printerror("Duplicate function declaration: %s\n", (char *)$2);
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
            if (return_flag == 0) {
                printerror("You must return some value for %s function!\n", (char*)$2);
            }
            return_flag = 0;

            if (get_last_element() > function_index)
                clear_symbols(function_index + 1);
            level = GLOBAL_LEVEL;
        }
    | _VOID _ID
        {
            if (lookup_id((char *)$2, FUNCTION) == -1) {
                if (lookup_id((char *)$2, GLOBAL_VAR) == -1 && lookup_id((char *)$2, CLASS_VAR) == -1) {
                    function_index = insert_symbol((char *)$2, FUNCTION, NO_TYPE);
                } else {
                    printerror("You are tryping to rediclare global or class variable %s to function!", (char *)$2);
                }
            } else {
                printerror("Duplicate function declaration: %s\n", (char *)$2);
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
            if (return_flag == 1) {
                printerror("You can't return value from void function!\n");
            }
            return_flag = 0;

            if (get_last_element() > function_index)
                clear_symbols(function_index + 1);
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
            if (level == PARAMETER_LEVEL) {
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
            if (level == PARAMETER_LEVEL) {
                if (lookup_id((char *)$2, PARAMETER) == -1) {
                    int $$ = insert_symbol((char *)$2, PARAMETER, $1);
                    set_is_reference($$, 1);
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
    : Designator _SEMICOLON
    | VarDecl
    | Designator _ASSIGN Expression _SEMICOLON
        {

            if ($1 != $3) {
                printerror("Assignment of incompatible types!\n");
            }
        }
    | Designator _LPAREN ActPars _RPAREN _SEMICOLON
        {
            if (function_call_index == -1) {
                printerror("Called undiclared function!\n");
            }

            check_arguments_number(function_call_index, call_table, arg_num);
            // postavi tip povratne vrednosti funkcije u %13
            set_register_type(FUNCTION_REGISTER, get_type(function_call_index));
            // povratna vrednost funkcije se uvek nalazi u %13
            $$ = FUNCTION_REGISTER;

            call_table = NULL;
            arg_num = 0;
            function_call_index = -1;
        }
    | Designator _LPAREN _RPAREN _SEMICOLON
        {
            if (function_call_index == -1) {
                printerror("Called undiclared function!\n");
            }

            check_arguments_number(function_call_index, call_table, arg_num);
            // postavi tip povratne vrednosti funkcije u %13
            set_register_type(FUNCTION_REGISTER, get_type(function_call_index));
            // povratna vrednost funkcije se uvek nalazi u %13
            $$ = FUNCTION_REGISTER;

            call_table = NULL;
            arg_num = 0;
            function_call_index = -1;
        }
    | Designator _INCREMENT _SEMICOLON
        {
            if (variable_index == -1) {
                printerror("Used undiclared variable!\n");
            } else if ($1 != NUMBER_TYPE) {
                printerror("You tried to increment non number value!\n");
            }

            variable_index = -1;
        }
    | Designator _DECREMENT _SEMICOLON
        {
            if (variable_index == -1) {
                printerror("Used undiclared variable!\n");
            } else if ($1 != NUMBER_TYPE) {
                printerror("You tried to decrement non number value!\n");
            }

            variable_index = -1;
        }
    | _IF _LPAREN Condition _RPAREN _LBRACKET Block _RBRACKET
    | _IF _LPAREN Condition _RPAREN _LBRACKET Block _RBRACKET _ELSE _LBRACKET Block _RBRACKET
    | _IF _LPAREN Condition _RPAREN _LBRACKET Block _RBRACKET ElseIfList
    | _WHILE
        {
            while_flag = 1;
        }
      _LPAREN Condition _RPAREN _LBRACKET Block _RBRACKET
        {
            while_flag = 0;
        }
    | _BREAK _SEMICOLON
        {
            if (while_flag == 0) {
                printerror("You can use break only in loops!\n");
            }
        }
    | _RETURN _SEMICOLON
    | _RETURN Expression _SEMICOLON
        {
            return_flag = 1;
        }
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
        {
            arg_num = 1;

            check_argument_type(function_call_index, call_table, $1, arg_num);
        }
    | ActPars _COMMA Expression
        {
            arg_num++;
            check_argument_type(function_call_index, call_table, $3, arg_num);
        }
    ;

Condition
    : CondTerm
        {
            condError(&cond_error);
            $$ = $1;
        }
    | Condition _OR CondTerm
        {
            condError(&cond_error);
            $$ = $3;
        }
    ;

CondTerm
    : CondFact
        {
            $$ = $1;
        }
    | CondTerm _AND CondFact
        {
            $$ = $3;
        }
    ;

CondFact
    : Expression
        {
            $$ = $1;
        }
    | Expression CondFactList
        {
            if ($1 != $2 && cond_error == 0) {
                cond_error = 1;
            }
            $$ = $1;
        }
    ;

CondFactList
    : Relop Expression
        {
            if ($2 == REFERENCE_TYPE && strcmp((char*)$1, "!=") != 0 && strcmp((char*)$1, "==") != 0 && cond_error == 0) {
                cond_error = 2;
            }
            $$ = $2;
        }
    | CondFactList Relop Expression
        {
            if ($2 == REFERENCE_TYPE && strcmp((char*)$1, "!=") != 0 && strcmp((char*)$1, "==") != 0 && cond_error == 0) {
                cond_error = 2;
            }
            if ($1 != $3 && exp_error == 0) {
                cond_error = 1;
            }
            $$ = $3;
        }
    ;

Expression
    : _MINUS Term
        {
            if ($2 != NUMBER_TYPE && exp_error == 0) {
                exp_error = 1;
            }

            if (exp_level == 0) {
                expError(&exp_error);
            }

            $$ = $2;
        }
    | _PLUS Term
        {
            if ($2 != NUMBER_TYPE && exp_error == 0) {
                exp_error = 2;
            }

            if (exp_level == 0) {
                expError(&exp_error);
            }
            $$ = $2;
        }
    | Term
        {
            if (exp_level == 0) {
                expError(&exp_error);
            }
            $$ = $1;
        }
    | _MINUS Term AddopTermList
        {
            if ($2 != NUMBER_TYPE && exp_error == 0) {
                exp_error = 2;
            }

            if (exp_level == 0) {
                expError(&exp_error);
            }
            $$ = $2;
        }
    | _PLUS Term AddopTermList
        {
            if ($2 != NUMBER_TYPE && exp_error == 0) {
                exp_error = 2;
            }

            if (exp_level == 0) {
                expError(&exp_error);
            }
            $$ = $2;
        }
    | Term AddopTermList
        {
            if ($1 != $2 && exp_error == 0) {
                exp_error = 3;
            }

            if (exp_level == 0) {
                expError(&exp_error);
            }
            $$ = $1;
        }
    ;

AddopTermList
    : Addop Term
        {
            if ($1 == 1) {
                if ($2 != NUMBER_TYPE && $2 != STRING_TYPE && exp_error == 0) {
                    exp_error = 4;
                }
            } else {
                if ($2 != NUMBER_TYPE && exp_error == 0) {
                    exp_error = 5;
                }
            }

            $$ = $2;
        }
    | Addop Term AddopTermList
        {
            if ($1 == 1) {
                if ($2 != NUMBER_TYPE && $2 != STRING_TYPE && exp_error == 0) {
                    exp_error = 4;
                }
            } else {
                if ($2 != NUMBER_TYPE && exp_error == 0) {
                    exp_error = 3;
                }
            }
            if ($2 != $3 && exp_error == 0) {
                exp_error = 3;
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
            if ($1 != NUMBER_TYPE && exp_error == 0) {

                exp_error = 3;
            }
            if ($1 != $2 && exp_error == 0) {

                exp_error = 3;
            }
            $$ = $1;
        }
    ;

MulopFactorList
    : Mulop Factor
        {
            $$ = $2;
        }
    | Mulop Factor MulopFactorList
        {
            if ($2 != NUMBER_TYPE && exp_error == 0) {
                exp_error = 3;
            }
            if ($2 != $3 && exp_error == 0) {
                exp_error = 3;
            }

            $$ = $2;
        }
    ;

Factor
    : Designator
        {
            if (variable_index == -1) {
                printerror("Used undiclared variable %s!\n", get_name(variable_index));
            }

            variable_index = -1;
            $$ = $1;
        }
    | Designator _LPAREN _RPAREN
        {
            if (function_call_index == -1) {
                printerror("Called undiclared function!\n");
            }

            check_arguments_number(function_call_index, call_table, arg_num);
            // postavi tip povratne vrednosti funkcije u %13
            set_register_type(FUNCTION_REGISTER, get_type(function_call_index));
            // povratna vrednost funkcije se uvek nalazi u %13
            $$ = FUNCTION_REGISTER;

            call_table = NULL;
            function_call_index = -1;
            arg_num = 1;
            $$ = $1;
        }
    | Designator _LPAREN ActPars _RPAREN
        {
            if (function_call_index == -1) {
                printerror("Called undiclared function %s!\n", get_name(function_call_index));
            }

            printf("Ovde %d %s %d\n", function_call_index, call_table, arg_num);
            check_arguments_number(function_call_index, call_table, arg_num);
            // postavi tip povratne vrednosti funkcije u %13
            set_register_type(FUNCTION_REGISTER, get_type(function_call_index));
            // povratna vrednost funkcije se uvek nalazi u %13
            $$ = FUNCTION_REGISTER;

            call_table = NULL;
            function_call_index = -1;
            arg_num = 1;
            $$ = $1;
        }
    | _NUMBER
        {
            $$ = NUMBER_TYPE;
            try_to_insert_constant((char*)$1, NUMBER_TYPE);
        }
    | _CHAR_CONST
        {
            $$ = CHAR_TYPE;
            try_to_insert_constant((char*)$1, CHAR_TYPE);
        }
    | _BOOL_CONST
        {
            $$ = BOOL_TYPE;
            try_to_insert_constant((char*)$1, BOOL_TYPE);
        }
    | _STRING_CONST
        {
            $$ = STRING_TYPE;
            try_to_insert_constant((char*)$1, STRING_TYPE);
        }
    | _NEW _ID
        {
            $$ = REFERENCE_TYPE;
        }
    | _NEW _ID _LSQBRACKET Expression _RSQBRACKET
        {
            if ($4 != NUMBER_TYPE) {
                printerror("Array length must be number!\n");
            }
            $$ = REFERENCE_TYPE;
        }
    | _NEW _TYPE _LSQBRACKET Expression _RSQBRACKET
        {
            if ($4 != NUMBER_TYPE) {
                printerror("Array length must be number!\n");
            }
            $$ = REFERENCE_TYPE;
        }
    | _LPAREN
        {
            exp_level++;
        }
      Expression _RPAREN
        {
            exp_level--;
            $$ = $3;
        }
    ;

Designator
    : _ID
        {
            $$ = NO_TYPE;
            int varIndex = lookUpVariable((char*)$1);

            if (varIndex != -1) {
                variable_index = varIndex;
                if (get_is_reference(varIndex) == 1) {
                    $$ = REFERENCE_TYPE;
                } else {
                    $$ = get_type(varIndex);
                }
            } else {
                int funcIndex = lookUpFunction((char*)$1, parent_class, &tmp_type, &call_table);

                if (funcIndex != -1) {
                    function_call_index = funcIndex;
                    $$ = tmp_type;
                } else {
                    printerror("Undiclared variable or function!\n");
                }
            }


        }
    | _ID
        {
            $$ = NO_TYPE;
            int varIndex = lookUpVariable((char*)$1);

            if (varIndex != -1) {
                variable_index = varIndex;
                if (get_is_reference(varIndex) == 1) {
                    $$ = REFERENCE_TYPE;

                    parent_class = get_class_type(varIndex);
                } else {
                    $$ = get_type(varIndex);
                }
            }


        }
      DesignatorRepeatList

    ;

DesignatorRepeatList
    : DesignatorRepeat
    | DesignatorRepeatList DesignatorRepeat
    ;

DesignatorRepeat
    : _DOT _ID
        {
            $$ = NO_TYPE;
            int varIndex = lookUpVariable((char*)$2);

            if (varIndex != -1) {
                variable_index = varIndex;
                if (get_is_reference(varIndex) == 1) {
                    $$ = REFERENCE_TYPE;
                } else {
                    $$ = get_type(varIndex);
                }
            } else {
                int funcIndex = lookUpFunction((char*)$2, parent_class, &tmp_type, &call_table);

                if (funcIndex != -1) {
                    function_call_index = funcIndex;
                    $$ = tmp_type;
                } else {
                    printerror("Undiclared variable or function!\n");
                }
            }
        }
    | _LSQBRACKET Expression _RSQBRACKET
        {
            if ($2 != NUMBER_TYPE) {
                printerror("To access some array element you must pass number!\n");
            }
        }
    ;

Relop
    : _RELOP
        {
            $$ = $1;
        }
    ;

Addop
    : _PLUS
        {
            $$ = 1;
        }
    | _MINUS
        {
            $$ = 2;
        }
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

    init_symtab();

    variables = (Stack*)malloc(sizeof(Stack));
    initStack(variables, 100);

    yyparse();

    print_symtab();

    clear_symtab();
    printf("\nSTOP\n");
    return error_count;
}
