/*
 * CS 261: Main driver
 *
 * Name: Jacob Grimes
 */

#include "p1-check.h"

/*
 * helper function for printing help text
 */
void usage (char **argv)
{
    printf("Usage: %s <option(s)> mini-elf-file\n", argv[0]);
    printf(" Options are:\n");
    printf("  -h      Display usage\n");
    printf("  -H      Show the Mini-ELF header\n");
}

int main (int argc, char **argv)
{
    int opt = 0;

    char *filename = NULL;
    bool h_flag = false;

    if ((opt = getopt(argc, argv, "-hH")) != -1) {
        switch (opt) {
            case 'h':
                usage(argv);
                exit(EXIT_SUCCESS);
            case 'H':
                h_flag = true;
                filename = argv[optind];
                break;
            case '?':
                usage(argv);
                exit(EXIT_FAILURE);
        }
    }
    // multiple parameters
    if (argc > 3) {
        usage(argv);
        exit(EXIT_FAILURE);
    }
    if (h_flag && filename == NULL) {
        usage(argv);
        exit(EXIT_FAILURE);
    } else if (!h_flag) {
        filename = argv[optind - 1];
    }
    FILE *file = fopen(filename, "r");
    elf_hdr_t hdr;
    if (!read_header(file, &hdr)) {
        printf("Failed to read file\n");
        exit(EXIT_FAILURE);
    }
    if (h_flag) {
        dump_header(&hdr);
        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}

