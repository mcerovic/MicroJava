
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

int first_empty = 0;

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

void return_main_table() {
    int i;

    first_empty = tmp.first_empty;
    for (i = 0; i < SYMBOL_TABLE_LENGTH; i++) {
        symbol_table[i] = tmp.symbol_table[i];
    }
}

void switch_table_to(char *name) {
    int i, k;

    for (i = 0; i < MAX_TABLES; i++) {
        if (clases[i].name != NULL && strcmp(name, clases[i].name) == 0) {
            k = i;
            printf("K: %s\n", clases[i].name);
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
        long number = atol(str);
        switch(type) {
          case NUMBER_TYPE : {
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
        if(symbol_table[i].class_type)
            free(symbol_table[i].class_type);
        symbol_table[i].name = 0;
        symbol_table[i].class_type = 0;
        symbol_table[i].kind = NO_KIND;
        symbol_table[i].type = NO_TYPE;
        symbol_table[i].attribute = NO_ATTRIBUTE;
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
    printf("\n         name             class            kind       type attr p1 p2 p3 p4 p5");
    printf("\n-- ---------------- ---------------- ---------------- ---- ---- -- -- -- -- --");
    for(i = 0; i < first_empty; i++) {
        printf("\n%2d %-16s %-16s %16s %4d %4d ", i,
               symbol_table[i].name,
               symbol_table[i].class_type,
               symbol_kinds[(int)(logarithm2(symbol_table[i].kind))],
               symbol_table[i].type,
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
