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

    while ((opt = getopt(argc, argv, "-hH:")) != -1) {
        switch (opt) {
            case 'h':
                usage(argv);
            case 'H':
            
        }
    }

    return EXIT_SUCCESS;
}

