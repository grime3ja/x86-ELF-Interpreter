/*
 * CS 261: Intro project driver
 *
 * Name: 
 */

#include "p0-intro.h"
#include <getopt.h>

int main (int argc, char **argv)
{
    int opt;

    int flags = 0;

    while ((opt = getopt(argc, argv, "gf:ctu")) != -1) {
        switch(opt) {
            case 'g':
                flags++;
                printf("%s", "Goodbye!\n");
                break;
            case 'f':
                flags++;
                printf("%d\n", factorial(strtol(optarg, &optarg, 10)));
                break;
            case 'c':
                flags++;
                if (optind != argc - 1) {
                    printf("%s\n", "Invalid argument.");
                    break;
                }
                FILE *file = fopen(argv[optind], "r");
                if (file == NULL) {
                    printf("%s\n", "Invalid file.");
                    break;
                }
                char buffer[sizeof(char *)];
                while (read_line(file, buffer, sizeof(buffer))) {
                    printf("%s", buffer);
                }
                break;
            case 't':
                flags++;
                if (optind != argc - 1) {
                    printf("%s\n", "Invalid argument.");
                    break;
                }
                int bound = strtol(argv[optind], &argv[optind], 10);
                for (int i = 1; i <= bound; i++) {
                    if (i % 3 == 0 && i % 2 == 1) {
                        printf("%s\n", "triodd");
                    }
                    else if (i % 3 == 0) {
                        printf("%s\n", "tri");
                    }
                    else if (i % 2 == 1) {
                        printf("%s\n", "odd");
                    }
                    else {
                        printf("%d\n", i);
                    }
                }
                break;
            case 'u':
                flags++;
                if (optind != argc - 1) {
                    printf("%s\n", "Invalid argument.");
                    break;
                }
                file = fopen(argv[optind], "r");
                if (file == NULL) {
                    printf("%s\n", "Invalid file.");
                    break;
                }
                buffer[sizeof(char *)];
                // while (read_line(file, buffer, sizeof(buffer))) {
                    // if (buffer is not equal to the previous line) {
                        // printf("%s", buffer);
                    // }
                // }
                break;
            default:
                printf("%s\n", "Invalid argument.");
                return EXIT_SUCCESS;
        }
    }
    if (flags == 0) {
        printf("%s", "Hello, world!\n");
    }
    return EXIT_SUCCESS;
}
