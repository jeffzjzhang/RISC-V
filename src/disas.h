/* Declarations of disassembler core functions
 * and some format printing functions. */

#include <stdio.h>
#include <stdlib.h>

#include "type.h"
#include "util.h"

/* core function: first stage decoding
 * used to invoke other detailed functions */
void decode_instruction(Instruction);

/* core functions: second stage decoding and invoke print functions */
void decode_rtype_instr(Instruction);
void decode_itype_except_load_instr(Instruction);
void decode_itype_load_instr(Instruction);
void decode_stype_instr(Instruction);
void decode_sbtype_instr(Instruction);
void decode_utype_instr(Instruction);
void decode_ujtype_instr(Instruction);
void decode_ecall_instr(Instruction); /* ecall belongs to i-type */

/* a wrapper for ugly print formats */
void print_rtype_instr(Instruction);
void print_itype_except_load_instr(Instruction);
void print_itype_load_instr(Instruction);
void print_stype_instr(Instruction);
void print_sbtype_instr(Instruction);
void print_utype_instr(Instruction);
void print_ujtype_instr(Instruction);
void print_ecall_instr(Instruction);
