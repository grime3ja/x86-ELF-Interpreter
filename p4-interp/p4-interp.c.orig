/*
 * CS 261 PA4: Mini-ELF interpreter
 *
 * Name: Jacob Grimes
 */

#include "p4-interp.h"

// Field variables for iotrap usage

// output buffer, and current index, for characters and strings
char buffer[100];
int bindex;
// output array, and current index, for integer values
int ints[100];
int iindex;
// boolean tracking if the decout functionality was used in the y86 instruction
bool dec = false;

/**********************************************************************
 *                         REQUIRED FUNCTIONS
 *********************************************************************/

// all functionality of this function was found in the y86 reference
// provided on the p4 specification document.
y86_reg_t decode_execute (y86_t *cpu, y86_inst_t *inst, bool *cnd, y86_reg_t *valA)
{
    y86_reg_t valE = 0;
    y86_reg_t valB = 0;
    // checking for null pointers passed
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
                // condition setting for this function found in CS:APP
                // figure 3.15
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
                // condition setting for this function found in CS:APP
                // figure 3.15
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
                    // is the sum greater than 255? (0xff)
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
            // is the value after running the op instruction 0?
            cpu->zf = valE == 0 ? 1 : 0;
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

// all functionality of this function was found in the y86 reference
// provided on the p4 specification document.
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
    // functionality setup
    y86_reg_t valM = 0;
    cpu->pc = inst->valP;

    // iotrap variables
    
    // the end of an 8 byte value from output
    int i = cpu->reg[RSI] + 8;
    // number of significant bytes
    int bytes = 0;
    // used in charin
    char cin = 0;
    // used in decin
    int iin = 0;
    
    switch (inst->icode) {
        case CMOV:
            if (cnd) {
                cpu->reg[inst->rb] = valE;
            }
            break;
        case JUMP:
            // is the condition code met? 
            // if so jump to the specified destination, if not continue
            cpu->pc = cnd ? inst->valC.dest : inst->valP;
            break;
        case IRMOVQ:
            cpu->reg[inst->rb] = valE;
            break;
        case RMMOVQ:
            memcpy(&memory[valE], &valA, 8);
            break;
        case MRMOVQ:
            // trying to move outside of the virtual memory space
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
                    // copy the char from %rsi into the output buffer
                    snprintf(&buffer[bindex++], 2, "%c", (char) memory[cpu->reg[RSI]]);
                    break;
                case CHARIN:
                    // is the value in standard input a value char?
                    if (scanf("%c", &cin) == 0) {
                        printf("I/O Error\n");
                        cpu->stat = HLT;
                        break;
                    }
                    // copy the character from standard input into memory at %rdi
                    memory[cpu->reg[RDI]] = cin;
                    break;
                case DECOUT:
                    // find where the significant bytes start, 
                    // and how many of them there are
                    while (memory[i] == 0 && i >= cpu->reg[RSI]) {
                        i--;
                        bytes++;
                    }
                    bytes--;
                    // save the int you want to output to the ints array
                    memcpy(&ints[iindex++], &memory[cpu->reg[RSI]], 8 - bytes);
                    dec = true;
                    break;
                case DECIN:
                    // is the value in standard input a valid decimal value?
                    if (scanf("%d", &iin) == 0) {
                        printf("I/O Error\n");
                        cpu->stat = HLT;
                        break;
                    }
                    // copy the int in memory at %rdi
                    memory[cpu->reg[RDI]] = iin;
                    break;
                case STROUT:
                    // save the value in %rsi into the output buffer
                    snprintf(&buffer[bindex], 100, "%s", (char *) &memory[cpu->reg[RSI]]);
                    bindex += 8;
                    break;
                case FLUSH:
                    // is a decimal value being output?
                    if (dec) {
                        // output the ints array
                        for (int i = 0; i < iindex; i++) {
                            printf("%d", ints[i]);
                        }
                        // clear the ints array
                        memset(ints, 0, sizeof(ints));
                    }
                    // print the buffer
                    printf("%s", buffer);
                    // clear the buffer
                    memset(buffer, 0, sizeof(buffer));

                    // reset the indexes of the int array and buffer
                    iindex = 0;
                    bindex = 0;
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
}

/**********************************************************************
 *                         OPTIONAL FUNCTIONS
 *********************************************************************/

void dump_cpu_state (y86_t *cpu)
{
    printf("Y86 CPU state:\n");

    // prints the program counter, and flag information
    printf("    PC: %016lx   ", cpu->pc);
    printf("flags: Z%d S%d O%d     ", cpu->zf & 0xf, cpu->sf & 0xf, cpu->of & 0xf);

    // prints the cpu status
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
    
    // prints the value of each register
    printf("  %%rax: %016lx    %%rcx: %016lx\n", cpu->reg[RAX], cpu->reg[RCX]);
    printf("  %%rdx: %016lx    %%rbx: %016lx\n", cpu->reg[RDX], cpu->reg[RBX]);
    printf("  %%rsp: %016lx    %%rbp: %016lx\n", cpu->reg[RSP], cpu->reg[RBP]);
    printf("  %%rsi: %016lx    %%rdi: %016lx\n", cpu->reg[RSI], cpu->reg[RDI]);
    printf("   %%r8: %016lx     %%r9: %016lx\n", cpu->reg[R8], cpu->reg[R9]);
    printf("  %%r10: %016lx    %%r11: %016lx\n", cpu->reg[R10], cpu->reg[R11]);
    printf("  %%r12: %016lx    %%r13: %016lx\n", cpu->reg[R12], cpu->reg[R13]);
    printf("  %%r14: %016lx\n", cpu->reg[R14]);
}

