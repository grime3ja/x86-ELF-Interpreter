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
    ins.icode = memory[cpu->pc] >> 4;
    ins.ifun.b = 0;
    ins.valP = cpu->pc;
    switch (ins.icode) {
        case HALT:
            // ins.valP = cpu->pc + 1;
            ins.valP += 1;
            break;
        case NOP:
            ins.valP += 1;
            break;
        case RET:
            ins.ifun.b = 0;
            ins.valP += 1;
            break;
        case CMOV:
            ins.ifun.b = memory[cpu->pc] & 0x0f;
            ins.ra = memory[cpu->pc + 1] >> 4;
            ins.rb = memory[cpu->pc + 1] & 0x0f;
            ins.valP += 2;
            break;
        case IRMOVQ:
            ins.ifun.b = 0;
            ins.ra = memory[cpu->pc + 1] >> 4;
            ins.rb = memory[cpu->pc + 1] & 0x0f;
            // valC ← M8[PC+2]
            ins.valP += 10;
            break;
        case RMMOVQ:
            ins.ra = memory[cpu->pc + 1] >> 4;
            ins.rb = memory[cpu->pc + 1] & 0x0f;
            // valC ← M8[PC+2]
            ins.valP += 10;
            break;
        case MRMOVQ:
            ins.ra = memory[cpu->pc + 1] >> 4;
            ins.rb = memory[cpu->pc + 1] & 0x0f;
            // valC ← M8[PC+2]
            ins.valP += 10;
            break;
        case OPQ:
            ins.ifun.b = memory[cpu->pc] & 0x0f;
            ins.ra = memory[cpu->pc + 1] >> 4;
            ins.rb = memory[cpu->pc + 1] & 0x0f;
            ins.valP += 2;
            break;
        case JUMP:
            ins.ra = memory[cpu->pc + 1] >> 4;
            ins.rb = 0xf;
            break;
        case CALL:

            break;
        case PUSHQ:
            ins.ra = memory[cpu->pc + 1] >> 4;
            ins.rb = 0xf;
            ins.valP += 2;
            break;
        case POPQ:
            ins.ra = memory[cpu->pc + 1] >> 4;
            ins.rb = 0xf;
            ins.valP += 2;
            break;
        // TODO
        case IOTRAP:

            break;
        case INVALID:
            break;
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
    bool rb = false;
    switch(inst->icode) {
        case HALT:
            printf("halt");
            break;
        case NOP:
            printf("nop");
            break;
        case CMOV:
            switch(inst->ifun.b) {
                case RRMOVQ:
                    printf("rrmovq ");
                    break;
                case CMOVLE:
                    printf("cmovle ");
                    break;
                case CMOVL:
                    printf("cmovl ");
                    break;
                case CMOVE:
                    printf("cmove ");
                    break;
                case CMOVNE:
                    printf("cmovne ");
                    break;
                case CMOVGE:
                    printf("cmovge ");
                    break;
                case CMOVG:
                    printf("cmovg ");
                    break;
                case BADCMOV:
                    printf("badcmov ");
                    break;
            }
            rb = true;
            break;
        // TODO
        case IRMOVQ:
            break;
        case RMMOVQ:
            break;
        case MRMOVQ:
            break;
        case OPQ:
            switch(inst->ifun.b) {
                case ADD:
                    printf("addq ");
                    break;
                case SUB:
                    printf("subq ");
                    break;
                case AND:
                    printf("andq ");
                    break;
                case XOR:
                    printf("xorq ");
                    break;
                case BADOP:
                    printf("badopq ");
                    break;
            }
            rb = true;
            break;
        case JUMP:
            break;
        case CALL:
            break;
        case RET:
            printf("ret");
            break;
        case PUSHQ:
            printf("pushq ");
            break;
        case POPQ:
            printf("popq ");
            break;
        // TODO
        case IOTRAP:
            break;
        case INVALID:
            break;
    }
    for (int i = 0; i < 2; i++) {
        if (inst->ra + i == RAX) {
            printf("%%rax");
        } else if (inst->ra + i == RCX) {
            printf("%%rcx");
        } else if (inst->ra + i == RDX) {
            printf("%%rdx");
        } else if (inst->ra + i == RBX) {
            printf("%%rbx");
        } else if (inst->ra + i == RSP) {
            printf("%%rsp");
        } else if (inst->ra + i == RBP) {
            printf("%%rbx");
        } else if (inst->ra + i == RSI) {
            printf("%%rsi");
        } else if (inst->ra + i == RDI) {
            printf("%%rdi");
        } else if (inst->ra + i == R8) {
            printf("%%r8");
        } else if (inst->ra + i == R9) {
            printf("%%r9");
        } else if (inst->ra + i == R10) {
            printf("%%r10");
        } else if (inst->ra + i == R11) {
            printf("%%r11");
        } else if (inst->ra + i == R12) {
            printf("%%r12");
        } else if (inst->ra + i == R13) {
            printf("%%r13");
        } else if (inst->ra + i == R14) {
            printf("%%r14");
        } else if (inst->ra + i == NOREG) {
            printf("noreg");
        }
        rb ? printf(", ") : i++;
        rb = false;
    }
    printf("\n");
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
        // print current address and raw bytes of instruction
        printf("  0x%lx: ", cpu.pc);
        
        printf("%x%x ", ins.icode, ins.ifun.b);
        printf("%x%x ", ins.ra, ins.rb);

        printf("|   ");
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

