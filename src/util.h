/* Declerations of print formats, helper functions and exception handler. */

#include "type.h"

typedef Instruction instr;
typedef Address     addr;

/* macros of printf formats */
#define RTYPE  "%s x%d, x%d, x%d\n"
#define ITYPE  "%s x%d, x%d, %d\n"
#define MEM    "%s x%d, %d(x%d)\n" /* load and store */
#define LUI    "lui x%d, %d\n"
#define JAL    "jal x%d, %d\n"
#define BRANCH "%s x%d, x%d, %d\n"
#define ECALL  "ecall\n"

/* helper functions */
int ext_signer(unsigned int, unsigned int);
int get_branch_offset(instr);
int get_jal_offset(instr);
int get_store_offset(instr);

/* exception handler */
int handle_invalid_instruction(instr);
int handle_invalid_read(instr);
int handle_invalid_write(instr);

/* check that the address is aligned correctly */
bool check_align(Address, Alignment); 

/* load or store data into memory */
Word loading(Byte*, Address, Alignment, bool);
void storing(Byte*, Address, Alignment, Word, bool);
