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
    // TODO fix hard coding?
    return ret == 1 && 4607045 == hdr->magic;
}

/**********************************************************************
 *                         OPTIONAL FUNCTIONS
 *********************************************************************/

void dump_header (elf_hdr_t *hdr)
{
    // print header in little endian
    printf("%02x ", hdr->e_version);
    printf("%x ", hdr->e_entry);
    printf("%x ", hdr->e_phdr_start);
    printf("%x ", hdr->e_num_phdr);
    printf("%x ", hdr->e_symtab);
    printf("%x ", hdr->e_strtab);
    printf("%x ", hdr->magic);
    printf("\n");

    // print rest of output
    printf("Mini-ELF version %d\n", hdr->e_version);
    printf("Entry point 0x%x\n", hdr->e_entry);
    printf("There are %d program headers, starting at offset %d (0x%x)\n", hdr->e_num_phdr, hdr->e_phdr_start, hdr->e_phdr_start);
    if (hdr->e_symtab == 0) {
        printf("There is no symbol table present\n");
    } else {
        printf("There is a symbol table starting at offset %d (0x%x)\n", hdr->e_symtab, hdr->e_symtab);
    }
    if (hdr->e_strtab == 0) {
        printf("There is no string table present\n");
    } else {
        printf("There is a string table starting at offset %d (0x%x)\n", hdr->e_strtab, hdr->e_strtab);
    }
}

