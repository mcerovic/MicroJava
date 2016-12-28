
#ifndef SYMTAB_H
#define SYMTAB_H

#define PARAM_NUMBER   5

// Element tabele simbola
typedef struct sym_entry {
    char *name;               // ime simbola
    unsigned kind;            // vrsta simbola
    unsigned type;            // tip vrednosti simbola
    int attribute;            // dodatni attribut
    unsigned *param_types;    // tipovi parametara
} SYMBOL_ENTRY;

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
