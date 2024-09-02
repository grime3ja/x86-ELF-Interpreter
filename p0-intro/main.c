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

    bool g_flag;

    // bool g_flag, f_flag, c_flag, t_flag, u_flag;

    while ((opt = getopt(argc, argv, "gf:c:t:u:")) != -1) {
        switch(opt) {
            case 'g':
                g_flag = true;
                break;
            case 'f':
                // f_flag = true;
                break;
            case 'c':
                // c_flag = true;
                break;
            case 't':
                // t_flag = true;
                break;
            case 'u':
                // u_flag = true;
                break;
        }
    }
    if (g_flag) {
        printf("%s", "Goodbye!\n");
    }
    // if (f_flag) {
    //     printf("%s", "factorial\n");
    // }
    // if (c_flag) {
    //     printf("%s", "c!\n");
    // }
    // if (t_flag) {
    //     printf("%s", "t\n");
    // }
    // if (u_flag) {
    //     printf("%s", "u!\n");
    // }
    return EXIT_SUCCESS;
}
