/* Declerations of print formats, helper functions and exception handler. */

#include "type.h"

typedef Instruction instruc;
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
int get_branch_offset(instruc);
int get_jal_offset(instruc);
int get_store_offset(instruc);

/* exception handler */
int handle_invalid_instruction(instruc);
int handle_invalid_read(instruc);
int handle_invalid_write(instruc);

/* load or store data into memory */
Word loading(Byte*, Address, Alignment, bool);
void storing(Byte*, Address, Alignment, Word, bool);
