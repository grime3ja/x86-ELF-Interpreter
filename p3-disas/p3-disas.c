/*
 * CS 261 PA3: Mini-ELF disassembler
 *
 * Name: Jacob Grimes
 */

#include "p3-disas.h"
int disassemble_icode(y86_inst_t *inst);
char * disassemble_register(y86_regnum_t reg);

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
    // setting default values to limit code repetition
    ins.icode = memory[cpu->pc] >> 4;
    ins.ifun.b = 0;
    ins.valP = cpu->pc;

    switch (ins.icode) {
        case HALT:
            // if the low order 4 bits aren't 0
            if ((memory[cpu->pc] & 0x0f) != 0) {
                ins.icode = INVALID;
                cpu->stat = INS;
                break;
            }
            ins.valP += 1;
            break;
        case NOP:
            if ((memory[cpu->pc] & 0x0f) != 0) {
                ins.icode = INVALID;
                cpu->stat = INS;
                break;
            }
            ins.valP += 1;
            break;
        case CMOV:
            ins.ifun.b = memory[cpu->pc] & 0x0f;
            ins.ra = memory[cpu->pc + 1] >> 4;
            ins.rb = memory[cpu->pc + 1] & 0x0f;
            ins.valP += 2;
            if (ins.ifun.b > 6 || ins.ra > 14 || ins.rb > 14) {
                ins.icode = INVALID;
                cpu->stat = INS;
                break;
            }
            break;
        case IRMOVQ:
            ins.ra = memory[cpu->pc + 1] >> 4;
            ins.rb = memory[cpu->pc + 1] & 0x0f;
            // copy 8 bytes from memory into valC
            memcpy(&ins.valC.v, &memory[cpu->pc + 2], 8);
            ins.valP += 10;
            if ((memory[cpu->pc] & 0x0f) != 0 || ins.ra != 0xf || ins.rb > 14) {
                ins.icode = INVALID;
                cpu->stat = INS;
                break;
            }
            break;
        case RMMOVQ:
            ins.ra = memory[cpu->pc + 1] >> 4;
            ins.rb = memory[cpu->pc + 1] & 0x0f;
            memcpy(&ins.valC.d, &memory[cpu->pc + 2], 8);
            ins.valP += 10;
            if ((memory[cpu->pc] & 0x0f) != 0 || ins.ra > 14) {
                ins.icode = INVALID;
                cpu->stat = INS;
                break;
            }
            break;
        case MRMOVQ:
            ins.ra = memory[cpu->pc + 1] >> 4;
            ins.rb = memory[cpu->pc + 1] & 0x0f;
            memcpy(&ins.valC.v, &memory[cpu->pc + 2], 8);
            ins.valP += 10;
            if ((memory[cpu->pc] & 0x0f) != 0 || ins.ra > 14) {
                ins.icode = INVALID;
                cpu->stat = INS;
                break;
            }
            break;
        case OPQ:
            ins.ifun.b = memory[cpu->pc] & 0x0f;
            ins.ra = memory[cpu->pc + 1] >> 4;
            ins.rb = memory[cpu->pc + 1] & 0x0f;
            ins.valP += 2;
            // testing for edge cases in memory
            if (ins.ifun.b > 3 || ins.ra > 14 || ins.rb > 14) {
                ins.icode = INVALID;
                cpu->stat = INS;
                break;
            }
            break;
        case JUMP:
            ins.ifun.b = memory[cpu->pc] & 0x0f;
            memcpy(&ins.valC.dest, &memory[cpu->pc + 1], 8);
            ins.valP += 9;
            if (ins.ifun.b > 6) {
                ins.icode = INVALID;
                cpu->stat = INS;
                break;
            }
            break;
        case CALL:
            if ((memory[cpu->pc] & 0x0f) != 0) {
                ins.icode = INVALID;
                cpu->stat = INS;
                break;
            }
            memcpy(&ins.valC.dest, &memory[cpu->pc + 1], 8);
            ins.valP += 9;
            break;
        case RET:
            if ((memory[cpu->pc] & 0x0f) != 0) {
                ins.icode = INVALID;
                cpu->stat = INS;
                break;
            }
            ins.valP += 1;
            break;
        case PUSHQ:
            if ((memory[cpu->pc] & 0x0f) != 0 || (memory[cpu->pc + 1] >> 4) > 14 || (memory[cpu->pc + 1] & 0x0f) != 0xf) {
                ins.icode = INVALID;
                cpu->stat = INS;
                break;
            }
            ins.ra = memory[cpu->pc + 1] >> 4;
            ins.rb = 0xf;
            ins.valP += 2;
            break;
        case POPQ:
            if ((memory[cpu->pc] & 0x0f) != 0 || (memory[cpu->pc + 1] >> 4) > 14 || (memory[cpu->pc + 1] & 0x0f) != 0xf) {
                ins.icode = INVALID;
                cpu->stat = INS;
                break;
            }
            ins.ra = memory[cpu->pc + 1] >> 4;
            ins.rb = 0xf;
            ins.valP += 2;
            break;
        case IOTRAP:
            ins.ifun.b = memory[cpu->pc] & 0x0f;
            ins.valP += 1;
            if (ins.ifun.b > 5) {
                ins.icode = INVALID;
                cpu->stat = INS;
                break;
            }
            break;
        default:
            ins.icode = INVALID;
            cpu->stat = INS;
    }
    return ins;
}

/**********************************************************************
 *                         OPTIONAL FUNCTIONS
 *********************************************************************/

void disassemble (y86_inst_t *inst)
{
    int registers = disassemble_icode(inst);
    if (registers < 1) {
        printf("\n");
        return;
    }
    char *ra = disassemble_register(inst->ra);
    char *rb = disassemble_register(inst->rb);

    if (registers > 0 && inst->ra != 0xf) {
        if (inst->icode == MRMOVQ) {
            if (inst->rb == 0xf) {
                printf("0x%lx", inst->valC.d);
            } else {
                printf("0x%lx(%s)", inst->valC.d, rb);
            }
        } else {
            printf("%s", ra);
        }
    }
    if (registers > 1) {
        printf(", ");
        if (inst->icode == MRMOVQ) {
            printf("%s", ra);
        } else if (inst->icode == RMMOVQ) {
            if (inst->rb == 0xf) {
                printf("0x%lx", inst->valC.d);
            } else {
                printf("0x%lx(%s)", inst->valC.d, rb);
            }
        } else {
            printf("%s", rb);
        }
    }
    printf("\n");
}


void disassemble_code (byte_t *memory, elf_phdr_t *phdr, elf_hdr_t *hdr)
{
    y86_t cpu;			// CPU struct to store "fake" PC
    y86_inst_t ins;		// struct to hold fetched instruction

    // start at beginning of the segment
    cpu.pc = phdr->p_vaddr;

    printf("  0x%03x:                               | .pos 0x%03x code\n", phdr->p_vaddr, phdr->p_vaddr);

    // iterate through the segment one instruction at a time
    while (cpu.pc < phdr->p_vaddr + phdr->p_size) {
        if (cpu.pc == hdr->e_entry) {
            printf("  0x%03x:%31s| _start:\n", hdr->e_entry, " ");
        }
        ins = fetch (&cpu, memory);         // stage 1: fetch instruction

        // abort with error if instruction was invalid
        if (ins.icode == INVALID) {
            printf("Invalid opcode: 0x%2x\n", memory[cpu.pc]);
            break;
        }
        // print current address and raw bytes of instruction
        printf("  0x%03lx: ", cpu.pc);
        
        printf("%x%x ", ins.icode, ins.ifun.b);
        switch (ins.valP - cpu.pc) {
            case 10:
                printf("%x%x ", ins.ra, ins.rb);
                for (int i = cpu.pc + 2; i < cpu.pc + 10; i++) {
                    printf("%02x ", memory[i]);
                }
                break;
            case 9:
                for (int i = cpu.pc + 1; i < cpu.pc + 9; i++) {
                    printf("%02x ", memory[i]);
                }
                printf("%3s", " ");
                break;
            case 2:
                printf("%x%x ", ins.ra, ins.rb);
                printf("%24s", " ");
                break;
            case 1:
                printf("%27s", " ");
                break;
            default:
                printf("%30s", " ");
        }

        printf("|   ");
        disassemble (&ins);                 // stage 2: print disassembly
        cpu.pc = ins.valP;                  // stage 3: update PC (go to next instruction)
    }
    printf("\n");
}

int disassemble_icode(y86_inst_t *inst)
{
    int registers = 0;
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
            registers = 2;
            break;
        // TODO
        case IRMOVQ:
            printf("irmovq 0x%lx", inst->valC.v);
            registers = 2;
            break;
        case RMMOVQ:
            printf("rmmovq ");
            registers = 2;
            break;
        case MRMOVQ:
            printf("mrmovq ");
            registers = 2;
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
            registers = 2;
            break;
        case JUMP:
            switch (inst->ifun.b) {
                case JMP:
                    printf("jmp ");
                    break;
                case JLE:
                    printf("jle ");
                    break;
                case JL:
                    printf("jl ");
                    break;
                case JE:
                    printf("je ");
                    break;
                case JNE:
                    printf("jne ");
                    break;
                case JGE:
                    printf("jge ");
                    break;
                case JG:
                    printf("jg ");
                    break;
                case BADJUMP:
                    printf("badjump");
                    break;
            }
            printf("0x%lx", inst->valC.dest);
            break;
        case CALL:
            printf("call 0x%lx", inst->valC.dest);
            break;
        case RET:
            printf("ret");
            break;
        case PUSHQ:
            printf("pushq ");
            registers = 1;
            break;
        case POPQ:
            printf("popq ");
            registers = 1;
            break;
        // TODO
        case IOTRAP:
            printf("iotrap %d", inst->ifun.trap);
            break;
        case INVALID:
            break;
    }
    return registers;
}

char * disassemble_register (y86_regnum_t reg)
{
    switch(reg) {
        case RAX:
            return "%rax";
        case RCX:
            return "%rcx";
        case RDX:
            return "%rdx";
        case RBX:
            return "%rbx";
        case RSP:
            return "%rsp";
        case RBP:
            return "%rbp";
        case RSI:
            return "%rsi";
        case RDI:
            return "%rdi";
        case R8:
            return "%r8";
        case R9:
            return "%r9";
        case R10:
            return "%r10";
        case R11:
            return "%r11";
        case R12:
            return "%r12";
        case R13:
            return "%r13";
        case R14:
            return "%r14";
        case NOREG:
            return "noreg";
    }
    return NULL;
}

void disassemble_data (byte_t *memory, elf_phdr_t *phdr)
{
}

void disassemble_rodata (byte_t *memory, elf_phdr_t *phdr)
{
}

