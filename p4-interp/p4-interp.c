/*
 * CS 261 PA4: Mini-ELF interpreter
 *
 * Name: Jacob Grimes
 */

#include "p4-interp.h"

char buffer[100];
int index;

/**********************************************************************
 *                         REQUIRED FUNCTIONS
 *********************************************************************/

y86_reg_t decode_execute (y86_t *cpu, y86_inst_t *inst, bool *cnd, y86_reg_t *valA)
{
    y86_reg_t valE = 0;
    y86_reg_t valB = 0;
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
            *valA = cpu->reg[inst->ra];
            valE = cpu->reg[inst->ra];
            switch (inst->ifun.cmov) {
                case RRMOVQ:
                    *cnd = true;
                    break;
                case CMOVLE:
                    *cnd = (cpu->sf ^ cpu->of) | cpu->zf;
                    break;
                case CMOVL:
                    *cnd = cpu->sf ^ cpu->of;
                    break;
                case CMOVE:
                    *cnd = cpu->zf;
                    break;
                case CMOVNE:
                    *cnd = !cpu->zf;
                    break;
                case CMOVGE:
                    *cnd = !(cpu->sf ^ cpu->of);
                    break;
                case CMOVG:
                    *cnd = !(cpu->sf ^ cpu->of) & !cpu->zf;
                    break;
                default:
                    cpu->stat = INS;
                    inst->ifun.cmov = BADCMOV;
                    break;
            }
            break;
        case JUMP:
            switch(inst->ifun.jump) {
                case JMP:
                    *cnd = true;
                    break;
                case JLE:
                    *cnd = (cpu->sf ^ cpu->of) | cpu->zf;
                    break;
                case JL:
                    *cnd = cpu->sf ^ cpu->of;
                    break;
                case JE:
                    *cnd = cpu->zf;
                    break;
                case JNE:
                    *cnd = !cpu->zf;
                    break;
                case JGE:
                    *cnd = !(cpu->sf ^ cpu->of);
                    break;
                case JG:
                    *cnd = !(cpu->sf ^ cpu->of) & !cpu->zf;
                    break;
                default:
                    cpu->stat = INS;
                    inst->ifun.jump = BADJUMP;
                    break;
            }
        case IRMOVQ:
            valE = inst->valC.v;
            break;
        case RMMOVQ:
            *valA = cpu->reg[inst->ra];
            valB = cpu->reg[inst->rb];
            valE = valB + inst->valC.d;
            break;
        case MRMOVQ:
            valB = cpu->reg[inst->rb];
            valE = valB + inst->valC.d;
            break;
        case OPQ:
            *valA = cpu->reg[inst->ra];
            valB = cpu->reg[inst->rb];
            switch (inst->ifun.op) {
                case ADD:
                    valE = *valA + valB;
                    cpu->of = valE > 255 ? 1 : 0;
                    break;
                case SUB:
                    valE = valB - *valA;
                    cpu->of = valE > 255 ? 1 : 0;
                    break;
                case AND:
                    valE = *valA & valB;
                    break;
                case XOR:
                    valE = *valA ^ valB;
                    break;
                default:
                    cpu->stat = INS;
                    break;
            }
            if (valE == 0) {
                cpu->zf = 1;
            } else {
                cpu->zf = 0;
            }
            if (valE < 0 || valE >> 60 == 0xf || valE >> 60 == 0x8) {
                cpu->sf = 1;
            } else {
                cpu->sf = 0;
            }
            break;
        case PUSHQ:
            *valA = cpu->reg[inst->ra];
            valB = cpu->reg[RSP];
            valE = valB - 8;
            break;
        case POPQ:
            *valA = cpu->reg[RSP];
            valB = cpu->reg[RSP];
            valE = valB + 8;
            break;
        case RET:
            *valA = cpu->reg[RSP];
            valB = cpu->reg[RSP];
            valE = valB + 8;
            break;
        case CALL:
            valB = cpu->reg[RSP];
            if (valB < 8) {
                cpu->stat = ADR;
                break;
            }
            valE = valB - 8;
            break;
        case IOTRAP:
            break;
        default:
            inst->icode = INVALID;
            cpu->stat = INS;
            break;
    }
    return valE;
}

void memory_wb_pc (y86_t *cpu, y86_inst_t *inst, byte_t *memory,
        bool cnd, y86_reg_t valA, y86_reg_t valE)
{
    if (cpu == NULL) {
        return;
    }
    if (inst == NULL || memory == NULL) {
        cpu->stat = INS;
        return;
    }
    y86_reg_t valM = 0;
    cpu->pc = inst->valP;
    switch (inst->icode) {
        case CMOV:
            if (cnd) {
                cpu->reg[inst->rb] = valE;
            }
            break;
        case JUMP:
            cpu->pc = cnd ? inst->valC.dest : inst->valP;
            break;
        case IRMOVQ:
            cpu->reg[inst->rb] = valE;
            break;
        case RMMOVQ:
            memcpy(&memory[valE], &valA, 8);
            break;
        case MRMOVQ:
            if (valE + 8 > MEMSIZE) {
                cpu->stat = ADR;
                break;
            }
            memcpy(&valM, &memory[valE], 8);
            cpu->reg[inst->ra] = valM;
            break;
        case OPQ:
            cpu->reg[inst->rb] = valE;
            break;
        case PUSHQ:
            memcpy(&memory[valE], &valA, 8);
            cpu->reg[RSP] = valE;
            break;
        case POPQ:
            memcpy(&valM, &memory[valA], 8);
            cpu->reg[RSP] = valE;
            cpu->reg[inst->ra] = valM;
            break;
        case RET:
            memcpy(&valM, &memory[valA], 8);
            cpu->reg[RSP] = valE;
            cpu->pc = valM;
            break;
        case CALL:
            memcpy(&memory[valE], &inst->valP, 8);
            cpu->reg[RSP] = valE;
            cpu->pc = inst->valC.dest;
            break;
        case IOTRAP:
            switch (inst->ifun.trap) {
                case CHAROUT:
                    snprintf(&buffer[index++], 100, "%s", (char *) &memory[cpu->reg[RSI]]);
                    break;
                case CHARIN:
                    // fscanf()
                    break;
                case DECOUT:
                    break;
                case DECIN:
                    break;
                case STROUT:
                    break;
                case FLUSH:
                    printf("%s", buffer);
                    break;
                default:
                    cpu->stat = INS;
                    inst->ifun.trap = BADTRAP;
                    break;
            }
            break;
        default:
            break;
    }
    // free(buffer);
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

