
#ifndef SYMTAB_H
#define SYMTAB_H

#define PARAM_NUMBER   5

// Element tabele simbola
typedef struct sym_entry {
    char *name;               // ime simbola
    char *class_type;         //
    char *extends_class;
    unsigned kind;            // vrsta simbola
    unsigned type;            // tip vrednosti simbola
    unsigned is_reference;
    int attribute;            // dodatni attribut
    unsigned *param_types;    // tipovi parametara
} SYMBOL_ENTRY;

typedef struct STACK_NODE {
    char *name;
    unsigned is_reference;
} STACK_NODE;

typedef struct Stack {
    int top;
    STACK_NODE** stack;
} Stack;

void initStack(Stack* s, int n);
void push(Stack* s, char* name, unsigned is_reference);
void pop(Stack* s);
STACK_NODE* top(Stack* s);
int isEmpty(Stack* s);

int classLookUp(char* func, char* name, unsigned* type, char** call_table);
int lookUpFunction(char* name, char* class, unsigned* type, char** call_table);

void declareClass(char* name, char* extends);
int lookUpVariable(char* name);
int declareVariable(int type, char* name, int is_reference, char* class_type, int level);
int checkIsDeclared(char* name, int depth);

void condError(int* type);
void expError(int* type);

void save_class_table(char *name);
void save_main_table();

void save_tmp_table();
void return_tmp_table();


void return_main_table();
void switch_table_to(char *name);

unsigned get_is_reference(int index);
void set_is_reference(int index, unsigned is_reference);

char* get_class_type(int index);
void set_class_type(int index, char* class_type);

char* get_extends_class(int index);
void set_extends_class(int index, char* extends_class);

// Vraca indeks prvog sledeceg praznog elementa.
int  get_next_empty_element(void);

// Vraca indeks poslednjeg zauzetog elementa.
int get_last_element(void);

// Ubacuje simbol sa datom oznakom simbola i tipom simbola i vraca indeks ubacenog elementa u tabeli simbola ili -1.
int  insert_symbol(char *name, unsigned kind, unsigned type);

// Proverava da li se simbol vec nalazi u tabeli simbola, ako se ne nalazi ubacuje ga, ako se nalazi ispisuje gresku.
// Vraca indeks elementa u tabeli simbola.
int  try_to_insert_id(char *name, unsigned kind, unsigned type);

// Ubacuje konstantu u tabelu simbola (ako vec ne postoji).
int  try_to_insert_constant(char *str, unsigned type);

// Vraca indeks pronadjenog simbola ili vraca -1.
int  lookup_id(char *name, unsigned kind);

// Vraca indeks pronadjenog simbola (konstante) ili vraca -1.
int  lookup_constant(char *name, unsigned type);

// set i get metode za polja jednog elementa tabele simbola
char*    get_name(int index);
unsigned get_kind(int index);
unsigned get_type(int index);
void     set_attribute(int index, int attribute);
unsigned get_attribute(int index);
void     set_param_type(int index, unsigned number, unsigned type);
unsigned get_param_type(int index, unsigned number);
void     set_register_type(int register_index, unsigned type);

// Brise elemente tabele simbola  od pocetnog indeksa do kraja tabele
void     clear_symbols(unsigned begin_index);

// Brise sve elemente tabele simbola.
void     clear_symtab(void);

// Ispisuje sve elemente tabele simbola.
void     print_symtab(void);
unsigned logarithm2(unsigned value);

// Inicijalizacija tabele simbola.
void     init_symtab(void);

#endif
