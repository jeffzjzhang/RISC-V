/* Declarations of parsing functions */

#include <stdio.h>
#include <stdlib.h>

#include "type.h"
#include "util.h"

/* core function: parsing the input from the user and 
 * return a Instruction-type data to continue parsing,
 * may alert when encounter an invalid instruction. */
Instruction parse_input(const char*);

/* core function: first stage parsing 
 * used to catagorised the instruction 
 * and invoke the specific function */
void parse_instr(Instrution);
