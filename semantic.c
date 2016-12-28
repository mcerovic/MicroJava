
#include <stdio.h>
#include "semantic.h"

extern char char_buffer[CHAR_BUFFER_LENGTH];
extern int line;

// Proverava da li se ime main nalazi u tabeli simbola ili ne,
// i da li je njen tip 'int'.
void check_main() {
    int index;
    if((index = lookup_id("main", FUNCTION)) == -1)
        printerror("undefined reference to 'main'");
    if(get_type(index) != NUMBER_TYPE)
        printwarning("return type of 'main' is not int");
}

// Proverava da li su isti tipovi elemenata tabele simbola.
bool check_types(int first_index, int second_index) {
    unsigned t1 = get_type(first_index);
    unsigned t2 = get_type(second_index);
    if(t1 == t2 && t1 != NO_TYPE)
        return TRUE;
    else
        return FALSE;
}

// Proverava da li n-ti argument po tipu odgovara n-tom parametru funkcije
bool check_argument_type(int function_call_index, int arg_index, int arg_num) {
    if(get_param_type(function_call_index, arg_num) == get_type(arg_index))
        return TRUE;
    printerror("incompatible type for argument %d in '%s'", arg_num, get_name(function_call_index));
    return FALSE;
}

// Proverava da li broj argumenata poziva funkcije
// odgovara broju parametara funkcije
bool check_arguments_number(int function_call_index, int arg_num) {
    if(get_attribute(function_call_index) == arg_num)
        return TRUE;
    printerror("wrong number of arguments to function '%s'", get_name(function_call_index));
    return FALSE;
}
