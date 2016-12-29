
#ifndef DEFS_H
#define DEFS_H

#define bool int
#define TRUE  1
#define FALSE 0

#define SYMBOL_TABLE_LENGTH 64

#define NO_ATTRIBUTE -1

//tipovi podataka (moze ih biti maksimalno 8)
enum { NO_TYPE, NUMBER_TYPE, CHAR_TYPE, BOOL_TYPE, STRING_TYPE, REFERENCE_TYPE };

// vrste simbola (moze ih biti maksimalno 32)
enum { NO_KIND = 0x1, WORKING_REGISTER = 0x2, GLOBAL_VAR = 0x4, FUNCTION = 0x8, PARAMETER = 0x10,
       LOCAL_VAR = 0x20, CONSTANT = 0x40, CLASS_VAR = 0x80 };

static char *symbol_kinds[] = { "NONE", "WORKING_REGISTER", "GLOBAL_VAR", "FUNCTION", "PARAMETER", "LOCAL_VAR", "CONSTANT", "CLASS" };

//konstante relacionih operatora
enum { LT, GT, LE, GE, EQ, NE };

//konstante nivoa opsega vazenja
enum { GLOBAL_LEVEL, LOCAL_LEVEL, PARAMETER_LEVEL, CLASS_LEVEL };

#define FUNCTION_REGISTER        13
#define TYPE_BIT_SIZE            16
#define CHAR_BUFFER_LENGTH       128

//pomocni makroi za ispis
#define printerror(args...) sprintf(char_buffer, args), yyerror(char_buffer)
#define printwarning(args...) sprintf(char_buffer, args), warning(char_buffer)
extern int yyerror(char *s);
extern void warning(char *s);
extern char char_buffer[CHAR_BUFFER_LENGTH];

#endif
