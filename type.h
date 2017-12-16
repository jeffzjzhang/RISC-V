/* Define all types needed in other files. */

#include <stdint.h>

typedef uint8_t  Byte;
typedef uint16_t Half;
typedef uint32_t Word;
typedef uint64_t Double;

typedef int8_t  sByte;
typedef int16_t sHalf;
typedef int32_t sWord;
typedef int64_t sDouble; 

/* memory address is 32 bits */
typedef Word    Address;

/* register size is 32 bits */
typedef Word    Register;

/* processor structure: 
     32 general registers
     program counter
	 flag register
 */
typedef struct {
    Register X[32];
    Register PC;
	Register fReg;
} Processor;

/* length of data type in bytes, used to align memory */
typedef enum {
    LENGTH_BYTE = 1,
    LENGTH_HALF = 2,
    LENGTH_WORD = 4,
    LENGTH_DOUBLE = 8, /* may not used */
} Alignment;

/* total size of memory space */
#define MEMORY_SIZE (1024 * 1024)

/* instruction structure defines all the types required by RISC-V ISA:
     R -type: [ funct7 | rs2 | rs1 | funct3 | rd | opcode ]
     I -type: [ imm[11:0] | rs1 | funct3 | rd | opcode ]
     S -type: [ imm[11:5] | rs2 | rs1 | funct3 | imm[4:0] | opcode ]
     SB-type: [ imm[12|10:5] | rs2 | rs1 | funct3 | imm[4:1|11] | opcode ]
     U -type: [ imm[31:12] | rd | opcode ]
     UJ-type: [ imm[20|10:1|11|19:12] | rd | opcode ]
   For details, please refer to the RISC-V green card.  
   also add some extra structure to simplify the codes */
typedef union {
    /* to access the opcode easily and logically */
    struct {
        unsigned int opcode : 7;
        unsigned int        : 25;
    };

    /* just for debug */
    Double bits;

    /* R-type */
    struct {
        unsigned int opcode : 7;
        unsigned int rd     : 5;
        unsigned int funct3 : 3;
        unsigned int rs1    : 5;
        unsigned int rs2    : 5;
        unsigned int funct7 : 7;
    } rtype;

    /* I-type */
    struct {
        unsigned int opcode : 7;
        unsigned int rd     : 5;
        unsigned int funct3 : 3;
        unsigned int rs1    : 5;
        unsigned int imm20  : 12;
    } itype;

    /* S-type */
    struct {
        unsigned int opcode : 7;
        unsigned int imm5   : 5;
        unsigned int funct3 : 3;
        unsigned int rs1    : 5;
        unsigned int rs2    : 5;
        unsigned int imm7   : 7;
    } stype;

    /* SB-type */
    struct {
        unsigned int opcode : 7;
        unsigned int imm5   : 5;
        unsigned int funct3 : 3;
        unsigned int rs1    : 5;
        unsigned int rs2    : 5;
        unsigned int imm7   : 7;
    } sbtype;

    /* U-type */
    struct {
        unsigned int opcode : 7;
        unsigned int rd     : 5;
        unsigned int imm20  : 20;
    } utype;

    /* UJ-type */
    struct {
        unsigned int opcode : 7;
        unsigned int rd     : 5;
        unsigned int imm20  : 20;
    } ujtype;
} Instruction;   
