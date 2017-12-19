/* Implementations of the functions defined in the header file. */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "util.h"
#include "type.h"

typedef Instruction instr;

/* sign extends a bitfield with a given size */
int ext_signer(unsigned int field, unsigned int size) {
    return ((int)(field << size)) >> size;
}

int get_branch_offset(instr ins) {
    int off = 0;
    off += (ins.sbtype.imm7 & 0x40) << 6;
    off += (ins.sbtype.imm5 & 0x1) << 11;
    off += (ins.sbtype.imm7 & 0x3F) << 5;
    off += ins.sbtype.imm5 & 0x1E;
    return ext_signer(off, 19);
}

int get_jump_offset(instr ins) {
    int off = 0;
    off += ins.ujtype.imm & 0x80000;
    off += (ins.ujtype.imm & 0xFF) << 11;
    off += (ins.ujtype.imm & 0x00100) << 2;
    off += (ins.ujtype.imm & 0x7FE00) >> 9;
    off <<= 1;
    return ext_signer(off, 11);
}

int get_store_offset(instr ins) {
    return ext_signer((ins.stype.imm7 << 5) + ins.stype.imm5, 20);
}

void handle_invalid_instruction(instr ins) {
    printf("Invalid Instruction: 0x%08x\n", ins.bits);
}

void handle_invalid_read(Address addr) {
    printf("Bad read. Address: 0x%08x\n", addr);
    exit(-1);
}

void handle_invalid_write(Address addr) {
    printf("Bad write. Address: 0x%08x\n", addr);
    exit(-1);
}

bool check_align(Address addr, Alignment align) {
    if (addr > 0 && addr <= MEMORY_SIZE) {
        if (align == LENGTH_BYTE) {
            return true;
        } else if (align == LENGTH_HALF) {
            return addr % 2 == 0;
        } else if (align == LENGTH_WORD) {
            return addr % 4 == 0;
        } else if (align == LENGTH_DOUBLE) {
            return addr % 8 == 0;    
        } else {
            return false; /* unsupport type */
        }
    }
    return false;
}

Word loading(Byte* mem, Address addr, Alignment align, bool is_check_align) {
    if ((is_check_align && !check_align(addr, align)) || (address >= MEMORY_SIZE)) {
        handle_invalid_read(addr);
    }
    uint32_t data = 0;
    data += mem[addr];
    data += mem[addr + 1] << 8;
    data += mem[addr + 2] << 16;
    data += mem[addr + 3] << 24;
    return data;
}

void storing(Byte* mem, Address addr, Alignment align, Word val, bool is_check_align) {
    if ((is_check_align && !check_align(addr, align)) || (addr >= MEMORY_SIZE)) {
        handle_invalid_write(addr);
    }
    mem[addr] = val & 0xFF;
    mem[addr + 1] = (val >> 8) & 0xFF;
    mem[addr + 2] = (val >> 16) & 0xFF;
    mem[addr + 3] = (val >> 24) & 0xFF;
}
