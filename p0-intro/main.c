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
    char *val_c;
    char *val_u;
    char *endpointer;
    FILE *file = NULL;
    FILE *temp_f = NULL;
    char buffer[100];
    int bound = 0;

    while ((opt = getopt(argc, argv, "-gf:c:t:u:")) != -1) {
        switch(opt) {
            case 'g':
                flags++;
                flag_g = true;
                break;
            case 'f':
                flags++;
                flag_f = true;
                val_f = strtol(optarg, NULL, 10);
                break;
            case 'c':
                flags++;
                flag_c = true;
                val_c = optarg;
                break;
            case 't':
                flags++;
                flag_t = true;
                bound = strtol(optarg, &endpointer, 10);
                if (*endpointer != '\0') {
                    exit(EXIT_FAILURE);
                }
                break;
            case 'u':
                flags++;
                flag_u = true;
                val_u = optarg;
                break;
            default:
                printf("%s\n", "Invalid argument.");
                exit(EXIT_FAILURE);
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
            if (val_c == NULL) {
                printf("%s\n", "Invalid argument.");
                exit(EXIT_FAILURE);
            }
            file = fopen(val_c, "r");
            if (file == NULL) {
                printf("%s\n", "Invalid file.");
                exit(EXIT_FAILURE);
            }
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
            if (val_u == NULL) {
                printf("%s\n", "Invalid argument.");
                exit(EXIT_FAILURE);
            }
            file = fopen(val_u, "r");
            temp_f = fopen(val_u, "r");
            if (file == NULL) {
                printf("%s\n", "Invalid file.");
                exit(EXIT_FAILURE);
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
    exit(EXIT_SUCCESS);
}
