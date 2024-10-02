/*
 * CS 261: Main driver
 *
 * Name: Jacob Grimes
 */

#include "p1-check.h"
#include "p2-load.h"

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
}

int main (int argc, char **argv)
{
    // FILE *fp = fopen ("inputs/simple.o", "r");
    // byte_t *memory = (byte_t*) calloc (32, sizeof (uint8_t));
    // elf_phdr_t phdr;
    // phdr.p_offset = 0x30;
    // phdr.p_vaddr = 0x10;
    // phdr.p_size = 0x10;
    // phdr.p_type = DATA;
    // phdr.p_flags = 0x6;      // 110
    // phdr.magic = 0xDEADBEEF;
    // uint8_t expected[] = { 0, 0, 6, 0, 0xef, 0xbe, 0xad, 0xde,
    //     0x30, 0xf3, 0xf, 0, 0, 0, 0x20, 0x31 };
    // size_t i = 0;
    // bool rc = load_segment (fp, memory, &phdr);


    int opt = 0;

    bool h_flag = false;
    bool s_flag = false;
    // bool m_flag = false;
    // bool upper_m_flag = false;

    while ((opt = getopt(argc, argv, "-hHafsmM")) != -1) {
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
                // m_flag = true;
                break;
            case 'f':
                h_flag = true;
                s_flag = true;
                // upper_m_flag = true;
                break;
            case 's':
                s_flag = true;
                break;
            // case 'm':
                // m_flag = true;
                break;
            // case 'M':
                // upper_m_flag = true;
                break;
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

    elf_phdr_t *phdr = (elf_phdr_t *) calloc(hdr.e_num_phdr, sizeof(elf_phdr_t));
    int offset = hdr.e_phdr_start;
    for (int i = 0; i < hdr.e_num_phdr; i++) {
        if (!read_phdr(file, offset, &phdr[i])) {
            printf("Failed to read file\n");
            exit(EXIT_FAILURE);
        }
        offset += 20;
    }
    // if (!load_segment(file, mem, &phdr)) {
    //     printf("Failed to read file\n");
    //     exit(EXIT_FAILURE);
    // }

    if (h_flag) {
        dump_header(&hdr);
    }
    if (s_flag) {
        dump_phdrs(hdr.e_num_phdr, phdr);
    }
    // segments

    // contents of memory

    free(phdr);
    // free(mem);
    
    return EXIT_SUCCESS;
}

