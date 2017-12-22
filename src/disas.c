/* Implementations of the functions defined in the header file. */

#include <stdio.h>
#include <stdlib.h>

#include "disas.h"

void decode_instruction(Instruction instr) {
    switch(instr.opcode) {
        case 0x33: /* r-type */
            write_rtype(instr);
    }
} 
