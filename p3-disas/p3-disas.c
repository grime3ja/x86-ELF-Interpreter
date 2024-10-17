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

    return ins;
}

/**********************************************************************
 *                         OPTIONAL FUNCTIONS
 *********************************************************************/

void disassemble (y86_inst_t *inst)
{
}

void disassemble_code (byte_t *memory, elf_phdr_t *phdr, elf_hdr_t *hdr)
{
}

void disassemble_data (byte_t *memory, elf_phdr_t *phdr)
{
}

void disassemble_rodata (byte_t *memory, elf_phdr_t *phdr)
{
}

