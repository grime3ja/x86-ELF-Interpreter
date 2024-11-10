/*
 * CS 261 PA4: Mini-ELF interpreter
 *
 * Name: 
 */

#include "p4-interp.h"

/**********************************************************************
 *                         REQUIRED FUNCTIONS
 *********************************************************************/

y86_reg_t decode_execute (y86_t *cpu, y86_inst_t *inst, bool *cnd, y86_reg_t *valA)
{
    y86_reg_t valE = 0;

    return valE;
}

void memory_wb_pc (y86_t *cpu, y86_inst_t *inst, byte_t *memory,
        bool cnd, y86_reg_t valA, y86_reg_t valE)
{
}

/**********************************************************************
 *                         OPTIONAL FUNCTIONS
 *********************************************************************/

void dump_cpu_state (y86_t *cpu)
{
}

