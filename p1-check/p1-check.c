/*
 * CS 261 PA1: Mini-ELF header verifier
 *
 * Name: Jacob Grimes
 */

#include "p1-check.h"

/**********************************************************************
 *                         REQUIRED FUNCTIONS
 *********************************************************************/

bool read_header (FILE *file, elf_hdr_t *hdr)
{
    if (file == NULL || hdr == NULL) {
        return false;
    }
    int ret = fread(hdr, sizeof(elf_hdr_t), 1, file);
    return ret == 1 && strtol("ELF\0", NULL, 16) == hdr->magic;
}

/**********************************************************************
 *                         OPTIONAL FUNCTIONS
 *********************************************************************/

void dump_header (elf_hdr_t *hdr)
{
}

