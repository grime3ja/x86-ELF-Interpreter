/*
 * CS 261 PA4: Mini-ELF interpreter
 *
 * Name: Jacob Grimes
 */

#include "p4-interp.h"

/**********************************************************************
 *                         REQUIRED FUNCTIONS
 *********************************************************************/

y86_reg_t decode_execute (y86_t *cpu, y86_inst_t *inst, bool *cnd, y86_reg_t *valA)
{
    y86_reg_t valE = 0;
    if (cpu == NULL) {
        inst->icode = INVALID;
        return valE;
    }
    if (inst == NULL || cnd == NULL || valA == NULL) {
        cpu->stat = INS;
        inst->icode = INVALID;
        return valE;
    }
    switch (inst->icode) {
        case HALT:
            cpu->stat = HLT;
            break;
        case NOP:
            break;
        case CMOV:
            // *valA = inst->ra;
            // valA = cpu->reg[]
            valE = *valA;
            // Cnd ← Cond(CC,ifun)
        case IRMOVQ:
            valE = inst->valC.v;
            break;
        case RMMOVQ:
            *valA = inst->ra;
            valE = inst->rb + inst->valC.d;
            break;
        case MRMOVQ:
            valE = inst->rb + inst->valC.d;
            break;
        default:
            break;
    }
    return valE;
}

void memory_wb_pc (y86_t *cpu, y86_inst_t *inst, byte_t *memory,
        bool cnd, y86_reg_t valA, y86_reg_t valE)
{
    switch (inst->icode) {
        case HALT:
            cpu->pc = inst->valP;
            break;
        case NOP:
            cpu->pc = inst->valP;
            break;
        case CMOV:
            // Cnd ? R[rB] ← valE 
            break;
        case IRMOVQ:
            inst->rb = valE;
            break;
        case RMMOVQ:
            memcpy(&valE, &valA, 8);
            break;
        case MRMOVQ:
            memcpy(&(inst->ra), &valE, 8);
            break;
        default:
            break;
    }
}

/**********************************************************************
 *                         OPTIONAL FUNCTIONS
 *********************************************************************/

void dump_cpu_state (y86_t *cpu)
{
    printf("Y86 CPU state:\n");

    printf("    PC: %016lx   ", cpu->pc);
    printf("flags: Z%d S%d O%d     ", cpu->zf & 0xf, cpu->sf & 0xf, cpu->of & 0xf);
    switch (cpu->stat) {
        case AOK:
            printf("AOK");
            break;
        case HLT:
            printf("HLT");
            break;
        case ADR:
            printf("ADR");
            break;
        default:
            printf("INS");
            break;
    }
    printf("\n");
    
    printf("  %%rax: %016lx    %%rcx: %016lx\n", cpu->reg[0], cpu->reg[1]);
    printf("  %%rdx: %016lx    %%rbx: %016lx\n", cpu->reg[2], cpu->reg[3]);
    printf("  %%rsp: %016lx    %%rbp: %016lx\n", cpu->reg[4], cpu->reg[5]);
    printf("  %%rsi: %016lx    %%rdi: %016lx\n", cpu->reg[6], cpu->reg[7]);
    printf("   %%r8: %016lx     %%r9: %016lx\n", cpu->reg[8], cpu->reg[9]);
    printf("  %%r10: %016lx    %%r11: %016lx\n", cpu->reg[10], cpu->reg[11]);
    printf("  %%r12: %016lx    %%r13: %016lx\n", cpu->reg[12], cpu->reg[13]);
    printf("  %%r14: %016lx\n", cpu->reg[14]);
}

