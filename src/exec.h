/* Declarations of execution unit core functions
 * and some wrapper functions. */

#include <stdio.h>
#include <stdlib.h>

#include "type.h"
#include "util.h"
#include "riscv.h"

/* core function: first stage processing 
 * used to invoke other detailed functions */
void exec_instr(Instruction);

/* core functions: second stage processing and print results 
 * @param: Instruction, to be executed 
 * @param: Processor, cpu state 
 * @param: Byte*, memory address to be accessed 
 * @return: void */
void exec_rtype_instr(Instruction, Processor*);
void exec_itype_except_load_instr(Instruction, Processor*);
void exec_itype_load_instr(Instruction, Processor*, Byte*);
void exec_stype_instr(Instruction, Processor*, Byte*);
void exec_sbtype_instr(Instruction, Processor*);
void exec_utype_instr(Instruction, Processor*);
void exec_ujtype_instr(Instruction, Processor*);
void exec_ecall_instr(Instruction, Byte*);

/* helper functions */
int check_alignment(Address, Alignment);
