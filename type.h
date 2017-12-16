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
     32 registers
     program counter
 */
typedef struct {
    Register X[32];
    Register PC;
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

