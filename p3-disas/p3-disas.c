/*
 * CS 261 PA3: Mini-ELF disassembler
 *
 * Name: 
 */

#include "p3-disas.h"

/**********************************************************************
 *                         REQUIRED FUNCTIONS
 *********************************************************************/

y86_inst_t fetch (y86_t *cpu, byte_t *memory)
{
    y86_inst_t ins;
    if (cpu == NULL) {
        ins.icode = INVALID;
        return ins;
    }
    if (memory == NULL) {
        ins.icode = INVALID;
        cpu->stat = INS;
        return ins;
    }
    switch (memory[cpu->pc] >> 4) {
        case HALT:
            ins.icode = HALT;
            ins.ifun.b = 0;
            ins.valP = cpu->pc + 1;
            break;
        case NOP:
            ins.icode = NOP;
            ins.ifun.b = 0;
            ins.valP = cpu->pc + 1;
            break;
        case RET:
            ins.icode = RET;
            ins.ifun.b = 0;
            ins.valP = cpu->pc + 1;
            break;
        // case CMOV:
        //     ins.icode = CMOV;
        //     ins.ifun.cmov = CMOV;
        //     ins.rb = memory[cpu->pc + 1];
        //     ins.ra = memory[(cpu->pc + 1) >> 8];
        // default:
        //     ins.icode = INVALID;
        //     cpu->stat = INS;
        //     break;
    }
    return ins;
}

/**********************************************************************
 *                         OPTIONAL FUNCTIONS
 *********************************************************************/

void disassemble (y86_inst_t *inst)
{
    switch(inst->icode) {
        case HALT:
            printf("halt\n");
            break;
        case NOP:
            printf("nop\n");
            break;
        case RET:
            printf("ret\n");
            break;
    }
}

void disassemble_code (byte_t *memory, elf_phdr_t *phdr, elf_hdr_t *hdr)
{
    y86_t cpu;			// CPU struct to store "fake" PC
    y86_inst_t ins;		// struct to hold fetched instruction

    // start at beginning of the segment
    cpu.pc = phdr->p_vaddr;

    printf("Disassembly of executable contents:\n");
    printf("  0x100:                               | .pos 0x100 code\n");
    printf("  0x100:                               | _start:\n");

    // iterate through the segment one instruction at a time
    while (cpu.pc < phdr->p_vaddr + phdr->p_size) {
        ins = fetch (&cpu, memory);         // stage 1: fetch instruction

        // abort with error if instruction was invalid
        if (ins.icode == INVALID) {
            printf("Invalid opcode: 0x%2x\n", memory[cpu.pc]);
            break;
        }
        // TODO: print current address and raw bytes of instruction
        printf("  0x%lx: %02x", cpu.pc, ins.icode << 4);

        disassemble (&ins);                 // stage 2: print disassembly
        cpu.pc = ins.valP;                  // stage 3: update PC (go to next instruction)
    }
    printf("\n");
}

void disassemble_data (byte_t *memory, elf_phdr_t *phdr)
{
}

void disassemble_rodata (byte_t *memory, elf_phdr_t *phdr)
{
}

