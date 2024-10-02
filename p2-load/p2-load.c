/*
 * CS 261 PA2: Mini-ELF loader
 *
 * Name: Jacob Grimes
 */

#include "p2-load.h"

/**********************************************************************
 *                         REQUIRED FUNCTIONS
 *********************************************************************/

bool read_phdr (FILE *file, uint16_t offset, elf_phdr_t *phdr)
{
    if (file == NULL || phdr == NULL) {
        return false;
    }
    fseek(file, offset, SEEK_SET);
    return fread(phdr, sizeof(elf_phdr_t), 1, file) == 1 && phdr->magic == 0xdeadbeef;
}

bool load_segment (FILE *file, byte_t *memory, elf_phdr_t *phdr)
{
    if (file == NULL || memory == NULL || phdr == NULL || phdr->p_vaddr > sizeof(memory)) {
        return false;
    }
    fseek(file, phdr->p_offset, SEEK_SET);
    int ret = fread(&memory[phdr->p_vaddr], phdr->p_size, 1, file);
    return ret == 1 && (phdr->p_type == DATA || phdr->p_type == CODE);
}

/**********************************************************************
 *                         OPTIONAL FUNCTIONS
 *********************************************************************/

void dump_phdrs (uint16_t numphdrs, elf_phdr_t *phdrs)
{
    // -s flag
    printf(" Segment   Offset    Size      VirtAddr  Type      Flags\n");
    for (int i = 0; i < numphdrs; i++) {
        printf("  %02x       ", i);
        printf("0x%04x    ", phdrs[i].p_offset);
        printf("0x%04x    ", phdrs[i].p_size);
        printf("0x%04x    ", phdrs[i].p_vaddr);
        // if type is CODE else DATA
        printf("%s      ", (DATA + phdrs[i].p_type) == 0 ? "DATA" : "CODE");
        // if flag is 0x4 (R  ), 0x5 (R X), 0x6 (RW )
        if (phdrs[i].p_flags == 0x4) {
            printf("R  ");
        } else if (phdrs[i].p_flags == 0x5) {
            printf("R X");
        } else {
            printf("RW ");
        }
        printf("\n");
    }
}

void dump_memory (byte_t *memory, uint16_t start, uint16_t end)
{
}

