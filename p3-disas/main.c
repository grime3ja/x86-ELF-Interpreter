/*
 * CS 261: Main driver
 *
 * Name: Jacob Grimes
 */

#include "p1-check.h"
#include "p2-load.h"
#include "p3-disas.h"

/*
 * helper function for printing help text
 */
void usage (char **argv)
{
    printf("Usage: %s <option(s)> mini-elf-file\n", argv[0]);
    printf(" Options are:\n");
    printf("  -h      Display usage\n");
    printf("  -H      Show the Mini-ELF header\n");
    printf("  -a      Show all with brief memory\n");
    printf("  -f      Show all with full memory\n");
    printf("  -s      Show the program headers\n");
    printf("  -m      Show the memory contents (brief)\n");
    printf("  -M      Show the memory contents (full)\n");
    printf("  -d      Disassemble code contents\n");
    printf("  -D      Disassemble data contents\n");
}

int main (int argc, char **argv)
{
    int opt;

    bool h_flag = false;
    bool s_flag = false;
    bool m_flag = false;
    bool upper_m_flag = false;
    bool d_flag = false;
    bool upper_d_flag = false;

    while ((opt = getopt(argc, argv, "-hHafsmMdD")) != 1) {
        switch (opt) {
            case 'h':
                usage(argv);
                exit(EXIT_SUCCESS);
            case 'H':
                h_flag = true;
                break;
            case 'a':
                h_flag = true;
                s_flag = true;
                m_flag = true;
                break;
            case 'f':
                h_flag = true;
                s_flag = true;
                upper_m_flag = true;
                break;
            case 's':
                s_flag = true;
                break;
            case 'm':
                m_flag = true;
                break;
            case 'M':
                upper_m_flag = true;
                break;
            case 'd':
                d_flag = true;
            case 'D':
                upper_d_flag = true;
        }
    }

    if (argc > optind) {
        // no file given
        usage(argv);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[optind - 1];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        usage(argv);
        exit(EXIT_FAILURE);
    }

    elf_hdr_t hdr;
    if (!read_header(file, &hdr)) {
        printf("Failed to read file\n");
        exit(EXIT_FAILURE);
    }

    elf_phdr_t *phdr = 
        (elf_phdr_t *) calloc(hdr.e_num_phdr, sizeof(elf_phdr_t));
    byte_t *mem = (byte_t *) calloc(MEMSIZE, 1);
    int offset = hdr.e_phdr_start;
    for (int i = 0; i < hdr.e_num_phdr; i++) {
        if (!read_phdr(file, offset, &phdr[i])) {
            printf("Failed to read file\n");
            exit(EXIT_FAILURE);
        }
        offset += 20;
    }
    for (int i = 0; i < hdr.e_num_phdr; i++) {
        if (!load_segment(file, mem, &phdr[i])) {
            printf("Failed to read file\n");
            exit(EXIT_FAILURE);
        }
    }
    // y86_t cpu;
    // y86_inst_t inst;

    // for (int i = 0; i < phdr->p_size; i++) {
    //     inst = fetch(&cpu, &mem[cpu.pc]);
    //     cpu.pc += inst.valP;
    // }

    if (m_flag && upper_m_flag) {
        usage(argv);
        exit(EXIT_FAILURE);
    }
    if (h_flag) {
        dump_header(&hdr);
    }
    if (s_flag) {
        dump_phdrs(hdr.e_num_phdr, phdr);
    }
    if (m_flag) {
        for (int i = 0; i < hdr.e_num_phdr; i++) {
            dump_memory
                (mem, phdr[i].p_vaddr, phdr[i].p_vaddr + phdr[i].p_size);
        }
    }
    if (upper_m_flag) {
        dump_memory(mem, 0, MEMSIZE);
    }
    if (d_flag) {
        printf("Disassembly of executable contents:\n");
        for (int i = 0; i < hdr.e_num_phdr; i++) {
            disassemble_code(mem, &phdr[i], &hdr);
        }
    }

    // if (upper_d_flag) {
    //     disassemble_data(mem, phdr);
    // }

    free(phdr);
    free(mem);
    return EXIT_SUCCESS;
}

