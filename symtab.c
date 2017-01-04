
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "symtab.h"

#define MAX_UNSIGNED_NUMBER  (1L << TYPE_BIT_SIZE) - 1
#define MIN_INT_NUMBER       (-(1L << (TYPE_BIT_SIZE - 1)))
#define MAX_INT_NUMBER       ((1L << (TYPE_BIT_SIZE - 1)) - 1)

#define MAX_TABLES 10

typedef struct Table{
    char *name;
    int first_empty;
    SYMBOL_ENTRY symbol_table[SYMBOL_TABLE_LENGTH];
} Table;

Table clases[MAX_TABLES];
int number_of_classes = 0;
SYMBOL_ENTRY symbol_table[SYMBOL_TABLE_LENGTH];
Table tmp;
Table tmp2;
int first_empty = 0;




void initStack(Stack* s, int n) {
    int i;
    (*s).top = 0;
    (*s).stack = (STACK_NODE**)malloc(n * sizeof(STACK_NODE*));

}

void push(Stack* s, char* name, unsigned is_reference) {
    STACK_NODE* tmp = (STACK_NODE*)malloc(sizeof(STACK_NODE));
    tmp->name = name;

    if (is_reference == 1) {
        tmp->is_reference = 1;
    } else {
        tmp->is_reference = 0;
    }

    (*s).stack[(*s).top] = tmp;
    (*s).top++;
}

void pop(Stack* s) {
    if ((*s).top > 0) {
        free((*s).stack[(*s).top - 1]);
        (*s).top--;
    } else {
        (*s).top = 0;
    }
}

STACK_NODE* top(Stack* s) {
    return (*s).stack[(*s).top - 1];
}

int isEmpty(Stack* s) {
    if ((*s).top <= 0) return 1;
    return 0;
}

void declareClass(char* name, char* extends) {
    if (lookup_id(name, CLASS) == -1) {
        int index = insert_symbol(name, CLASS, -1);
        set_is_reference(index, 1);

        if (extends != NULL) {
            if (lookup_id(extends, CLASS) != -1) {

                set_extends_class(index, extends);
            } else {
                printerror("You can't extend undiclared class %s!\n", extends);
            }
        }
    } else {
        printerror("Duplicate class declaration: %s!\n", name);
    }
}

int checkIsDeclared(char* name, int depth) {
    int globalVarIndex = lookup_id(name, GLOBAL_VAR);
    int varIndex = lookup_id(name, LOCAL_VAR);
    int parameterIndex = lookup_id(name, PARAMETER);

    if (depth == 1) {
        if (varIndex == -1) {
            printerror("Duplicate variable declaration!");
            return 0;
        }
    } else if (depth == 2) {
        if (varIndex == -1 && parameterIndex == -1) {
            printerror("Duplicate variable declaration!");
            return 0;
        }
    } else if (depth == 3) {
        if (globalVarIndex == -1 && varIndex == -1 && parameterIndex == -1) {
            printerror("Duplicate variable declaration!");
            return 0;
        }
    }

    return 1;
}

int classLookUp(char* func, char* name, unsigned* type, char** call_table) {
    if (name == NULL) {

        *type = NO_TYPE;
        *call_table = NULL;
        return -1;
    }

    int classIndex = lookup_id(name, CLASS);
    char* extends = get_extends_class(classIndex);

    save_tmp_table();
    switch_table_to(name);
    int index = lookup_id(func, FUNCTION);
    if (index != -1) {

        *type = get_type(index);
        *call_table = name;
    }
    return_tmp_table();

    if (index != -1) {
        return index;
    }

    return classLookUp(func, extends, type, call_table);
}

int lookUpFunction(char* name, char* class, unsigned* type, char** call_table) {

    if (lookup_id(name, FUNCTION) != -1) {
        *type = NO_TYPE;
        *call_table = NULL;
        return lookup_id(name, FUNCTION);
    }

    if (class != NULL) {
        return classLookUp(name, class, type, call_table);
    }

    *type = NO_TYPE;
    *call_table = NULL;
    return -1;
}

int lookUpVariable(char* name) {
    int index = -1;

    // printf("Local %s\n", name);
    index = lookup_id(name, LOCAL_VAR);
    if (index != -1) return index;

    // printf("Parameter %s\n", name);
    index = lookup_id(name, PARAMETER);
    if (index != -1) return index;

    // printf("Class %s\n", name);
    index = lookup_id(name, CLASS_VAR);
    if (index != -1) return index;

    // printf("Global %s\n", name);
    index = lookup_id(name, GLOBAL_VAR);
    if (index != -1) return index;

    index = lookup_id(name, CONST_VAR);
    if (index != -1) return index;

    return index;
}

int declareVariable(int type, char* name, int is_reference, char* class_type, int level) {
    int index = -1;

    if (level == GLOBAL_LEVEL) {
        if (lookup_id(name, GLOBAL_VAR) == -1) {
            index = insert_symbol(name, GLOBAL_VAR, type);
            set_is_reference(index, is_reference);

            if (class_type != NULL) {
                set_class_type(index, class_type);
            }

        }
    } else if (level == LOCAL_LEVEL) {
        if (lookup_id(name, LOCAL_VAR) == -1 && lookup_id(name, CLASS_VAR) == -1 &&
            lookup_id(name, PARAMETER) == -1 && lookup_id(name, GLOBAL_VAR) == -1 &&
            lookup_id(name, FUNCTION) == -1 && lookup_id(name, CONST_VAR) == -1)  {

            index = insert_symbol(name, LOCAL_VAR, type);
            set_is_reference(index, is_reference);

            if (class_type != NULL) {
                set_class_type(index, class_type);
            }
        }
    } else if (level == CLASS_LEVEL) {
        if (lookup_id(name, CLASS_VAR) == -1 && lookup_id(name, GLOBAL_VAR) == -1 && lookup_id(name, FUNCTION) == -1) {
            index = insert_symbol(name, CLASS_VAR, type);
            set_is_reference(index, is_reference);

            if (class_type != NULL) {
                set_class_type(index, class_type);
            }
        }
    } else if (level == PARAMETER_LEVEL && lookup_id(name, CLASS_VAR) == -1 && lookup_id(name, GLOBAL_VAR) == -1 && lookup_id(name, FUNCTION) == -1) {
        if (lookup_id(name, PARAMETER) == -1) {
            index = insert_symbol(name, PARAMETER, type);
            set_is_reference(index, is_reference);

            if (class_type != NULL) {
                set_class_type(index, class_type);
            }
        }
    }

    return index;
}

void condError(int* type) {
    // 1 Condition has incompatible types!
    // 2 With reference types you can only use '!=' and '=='!
    if (*type == 1) {
        printerror("Condition has incompatible types!\n");
    } else if (*type == 2) {
        printerror("With reference types you can only use '!=' and '=='!\n");
    }

    *type = 0;
}

void expError(int* type) {
    // 1 You can't use minus sign before non number type!
    // 2 You can't use plus sign before non number type!
    // 3 Expression has incompatible types!
    // 4 You can only use plus sign with numbers and strings!
    // 5 You can only use minus sign with numbers!
    if (*type == 1) {
        printerror("You can't use minus sign before non number type!\n");
    } else if (*type == 2) {
        printerror("You can't use plus sign before non number type!\n");
    } else if (*type == 3) {
        printerror("Expression has incompatible types!\n");
    } else if (*type == 4) {
        printerror("You can only use plus sign with numbers and strings!\n");
    } else if (*type == 5) {
        printerror("You can only use minus sign with numbers!\n");
    }

    *type = 0;
}

void save_class_table(char *name) {
    int i;

    clases[number_of_classes].name = name;
    clases[number_of_classes].first_empty = first_empty;

    for (i = 0; i < SYMBOL_TABLE_LENGTH; i++) {
        clases[number_of_classes].symbol_table[i] = symbol_table[i];
    }

    number_of_classes++;
}

void save_main_table() {
    int i;

    tmp.first_empty = first_empty;
    for (i = 0; i < SYMBOL_TABLE_LENGTH; i++) {
        tmp.symbol_table[i] = symbol_table[i];
    }

}

void save_tmp_table() {
    int i;

    tmp2.first_empty = first_empty;
    for (i = 0; i < SYMBOL_TABLE_LENGTH; i++) {
        tmp2.symbol_table[i] = symbol_table[i];
    }

}

void return_main_table() {
    int i;

    first_empty = tmp.first_empty;
    for (i = 0; i < SYMBOL_TABLE_LENGTH; i++) {
        symbol_table[i] = tmp.symbol_table[i];
    }
}

void return_tmp_table() {
    int i;

    first_empty = tmp2.first_empty;
    for (i = 0; i < SYMBOL_TABLE_LENGTH; i++) {
        symbol_table[i] = tmp2.symbol_table[i];
    }
}

void switch_table_to(char *name) {
    int i, k;


    for (i = 0; i < MAX_TABLES; i++) {
        if (clases[i].name != NULL && strcmp(name, clases[i].name) == 0) {
            k = i;
            break;
        }
    }

    first_empty = clases[k].first_empty;
    for (i = 0; i < SYMBOL_TABLE_LENGTH; i++) {

        symbol_table[i] = clases[k].symbol_table[i];
    }

}

// Vraca indeks prvog sledeceg praznog elementa.
int get_next_empty_element(void) {
    if(first_empty < SYMBOL_TABLE_LENGTH)
        return first_empty++;
    else {
        printerror("Compiler error! Symbol table overflow!");
        exit(EXIT_FAILURE);
    }
}

// Vraca indeks poslednjeg zauzetog elementa.
int get_last_element(void) {
    return first_empty-1;
}

// Ubacuje simbol sa datom oznakom simbola i tipom simbola i vraca indeks ubacenog elementa u tabeli simbola ili -1.
int insert_symbol(char *name, unsigned kind, unsigned type) {
    int index = get_next_empty_element();
    symbol_table[index].name = name;
    symbol_table[index].kind = kind;
    symbol_table[index].type = type;
    return index;
}

// Proverava da li se simbol vec nalazi u tabeli simbola, ako se ne nalazi ubacuje ga, ako se nalazi ispisuje gresku.
// Vraca indeks elementa u tabeli simbola.
int try_to_insert_id(char *name, unsigned kind, unsigned type) {
    int index;
    if( (index = lookup_id(name, kind)) == -1 )
        index = insert_symbol(name, kind, type);
    else {
        printerror("redefinition of '%s'", name);
    }
    return index;
}

// Ubacuje konstantu u tabelu simbola (ako vec ne postoji).
int try_to_insert_constant(char *str, unsigned type) {
    int index;
    if( (index = lookup_constant(str, type)) == -1 ) {
        // provera opsega za konstante
        switch(type) {
          case NUMBER_TYPE : {
              long number = atol(str);
              if( number < MIN_INT_NUMBER || number > MAX_INT_NUMBER)
                  printerror("constant out of range");
          }; break;
        }
        index = insert_symbol(str, CONSTANT, type);
    }
    return index;
}

// Vraca indeks pronadjenog simbola ili vraca -1.
int lookup_id(char *name, unsigned kind) {
    int i;
    for(i = first_empty - 1; i > FUNCTION_REGISTER; i--) {
        if (kind == CONSTANT || kind == GLOBAL_VAR) {
            if(strcmp(symbol_table[i].name, name) == 0 && (symbol_table[i].kind & CONSTANT || symbol_table[i].kind & GLOBAL_VAR))
                return i;
        } else {
            if(strcmp(symbol_table[i].name, name) == 0 && symbol_table[i].kind & kind)
                return i;
        }
    }
    return -1;
}

// Vraca indeks pronadjenog simbola (konstante) ili vraca -1.
int lookup_constant(char *name, unsigned type) {
    int i;
    for(i = first_empty - 1; i > FUNCTION_REGISTER; i--) {
        if(strcmp(symbol_table[i].name, name) == 0 && symbol_table[i].type == type)
            return i;
    }
    return -1;
}


char *get_name(int index) {
    if(index > -1 && index < SYMBOL_TABLE_LENGTH)
        return symbol_table[index].name;
    return "?";
}

unsigned get_kind(int index) {
    if(index > -1 && index < SYMBOL_TABLE_LENGTH)
        return symbol_table[index].kind;
    return NO_KIND;
}

unsigned get_type(int index) {
    if(index > -1 && index < SYMBOL_TABLE_LENGTH)
        return symbol_table[index].type;
    return NO_TYPE;
}

unsigned get_is_reference(int index) {
    if(index > -1 && index < SYMBOL_TABLE_LENGTH)
        return symbol_table[index].is_reference;
    return 0;
}

void set_is_reference(int index, unsigned is_reference) {
    if(index > -1 && index < SYMBOL_TABLE_LENGTH)
        symbol_table[index].is_reference = is_reference;
}

char* get_extends_class(int index) {
    if(index > -1 && index < SYMBOL_TABLE_LENGTH)
        return symbol_table[index].extends_class;
    return NULL;
}

void set_extends_class(int index, char* extends_class) {
    if(index > -1 && index < SYMBOL_TABLE_LENGTH)
        symbol_table[index].extends_class = extends_class;
}

char* get_class_type(int index) {
    if(index > -1 && index < SYMBOL_TABLE_LENGTH)
        return symbol_table[index].class_type;
    return NULL;
}

void set_class_type(int index, char* class_type) {
    if(index > -1 && index < SYMBOL_TABLE_LENGTH)
        symbol_table[index].class_type = class_type;
}

void set_attribute(int index, int attribute) {
    if(index > -1 && index < SYMBOL_TABLE_LENGTH)
        symbol_table[index].attribute = attribute;
}

unsigned get_attribute(int index) {
    if(index > -1 && index < SYMBOL_TABLE_LENGTH)
        return symbol_table[index].attribute;
    return NO_ATTRIBUTE;
}

void set_param_type(int index, unsigned number, unsigned type) {
    if(index > -1 && index < SYMBOL_TABLE_LENGTH) {
        if(symbol_table[index].param_types == 0) {
            symbol_table[index].param_types = malloc(sizeof(unsigned) * PARAM_NUMBER);
            int i;
            for(i = 0; i < PARAM_NUMBER; i++)
                symbol_table[index].param_types[i] = NO_TYPE;
        }
        if(number > 0 && number <= PARAM_NUMBER)
            symbol_table[index].param_types[number - 1] = type;
    }
}

unsigned get_param_type(int index, unsigned number) {
    if(index > -1 && index < SYMBOL_TABLE_LENGTH)
        if(symbol_table[index].param_types && number > 0 && number <= PARAM_NUMBER)
            return symbol_table[index].param_types[number - 1];
    return NO_TYPE;
}


void set_register_type(int register_index, unsigned type) {
    if(register_index >= 0 && register_index <= FUNCTION_REGISTER)
        symbol_table[register_index].type = type;
}

// Brise elemente tabele simbola  od pocetnog indeksa do kraja tabele
void clear_symbols(unsigned begin_index) {
    int i;
    if(begin_index >= first_empty) {
        printerror("Compiler error! Wrong clear symbols argument");
        exit(EXIT_FAILURE);
    }
    for(i = begin_index; i < first_empty; i++) {
        if(symbol_table[i].name)
            free(symbol_table[i].name);
        symbol_table[i].name = 0;
        symbol_table[i].class_type = 0;
        symbol_table[i].extends_class = 0;
        symbol_table[i].kind = NO_KIND;
        symbol_table[i].type = NO_TYPE;
        symbol_table[i].attribute = NO_ATTRIBUTE;
        symbol_table[i].is_reference = 0;
        if(symbol_table[i].param_types)
            free(symbol_table[i].param_types);
        symbol_table[i].param_types = 0;
    }
    first_empty = begin_index;
}

// Brise sve elemente tabele simbola.
void clear_symtab(void) {
    first_empty = SYMBOL_TABLE_LENGTH - 1;
    clear_symbols(0);
}

// Ispisuje sve elemente tabele simbola.
void print_symtab(void) {
    int i,j;
    printf("\n\nSYMBOL TABLE\n");
    printf("\n         name             class           extends            kind       type ref attr p1 p2 p3 p4 p5");
    printf("\n-- ---------------- ---------------- ----------------- ---------------- ---- --- ---- -- -- -- -- --");
    for(i = 0; i < first_empty; i++) {
        printf("\n%2d %-16s %-16s %16s %16s %4d %3d %4d ", i,
               symbol_table[i].name,
               symbol_table[i].class_type,
               symbol_table[i].extends_class,
               symbol_kinds[(int)(logarithm2(symbol_table[i].kind))],
               symbol_table[i].type,
               symbol_table[i].is_reference,
               symbol_table[i].attribute);
        if(symbol_table[i].param_types) {
            for(j = 0; j < PARAM_NUMBER; j++)
                printf("%2d ", symbol_table[i].param_types[j]);
        }
        else
            printf(" -");
    }
    printf("\n\n");
}

unsigned logarithm2(unsigned value) {
    unsigned mask = 1;
    int i = 0;
    for(i = 0; i < 32; i++) {
        if(value & mask)
            return i;
        mask <<= 1;
    }
    return 0; // ovo ne bi smelo da se desi; indeksiraj string "NONE"
}

// Inicijalizacija tabele simbola.
void init_symtab(void) {
    clear_symtab();

    int i = 0;
    char s[4];
    for(i = 0; i < 14; i++) {
        sprintf(s, "%%%d", i);
        insert_symbol(strdup(s),  WORKING_REGISTER, NO_TYPE);
    }
}
