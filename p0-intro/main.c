/*
 * CS 261: Intro project driver
 *
 * Name: Jacob Grimes
 */

#include "p0-intro.h"
#include <getopt.h>

int main (int argc, char **argv)
{
    int opt;

    int flags = 0;

    bool flag_g = false, flag_f = false, flag_c = false, flag_t = false, flag_u = false;
    int val_f = 0;
    FILE *file = NULL;
    FILE *temp_f = NULL;
    char buffer[100];
    int bound = 0;

    while ((opt = getopt(argc, argv, "gf:ctu")) != -1) {
        switch(opt) {
            case 'g':
                flags++;
                flag_g = true;
                break;
            case 'f':
                flags++;
                flag_f = true;
                val_f = strtol(optarg, &optarg, 10);
                break;
            case 'c':
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
                flag_c = true;
                break;
            case 't':
                flags++;
                flag_t = true;
                if (optind != argc - 1) {
                    printf("%s\n", "Invalid argument.");
                    break;
                }
                bound = strtol(argv[optind], &argv[optind], 10);
                break;
            case 'u':
                flags++;
                if (optind != argc - 1) {
                    printf("%s\n", "Invalid argument.");
                    break;
                }
                file = fopen(argv[optind], "r");
                temp_f = fopen(argv[optind], "r");
                flag_u = true;
                break;
            default:
                printf("%s\n", "Invalid argument.");
                return EXIT_SUCCESS;
        }
    }
    if (flags == 0) {
        printf("%s", "Hello, world!\n");
    }
    else {
        if (flag_g) {
            printf("%s", "Goodbye!\n");
        }
        if (flag_f) {
            printf("%d\n", factorial(val_f));
        }
        if (flag_c) {
            while (read_line(file, buffer, sizeof(buffer))) {
                printf("%s", buffer);
            }
        }
        if (flag_t) {
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
        }
        if (flag_u) {
            if (file == NULL) {
                printf("%s\n", "Invalid file.");
            }
            char temp[100];
            if (read_line(file, buffer, 100)) {
                printf("%s", buffer);
            }
            while (read_line(temp_f, temp, 100)) {
                read_line(file, buffer, 100);
                // if (buffer is not equal to the previous line)
                if (strncmp(buffer, temp, (sizeof(buffer) >= sizeof(temp) ? sizeof(buffer) : sizeof(temp))) != 0) {
                    printf("%s", buffer);
                }
            }
        }
    }
    return EXIT_SUCCESS;
}
