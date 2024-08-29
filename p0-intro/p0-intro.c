/*
 * CS 261 PA0: Intro project
 *
 * Name: Jacob Grimes
 */

#include "p0-intro.h"

#include <math.h>

// returns the the sum of the absolute value of 2 numbers.
int add_abs (int num1, int num2)
{
    return abs(num1 + num2);
}

// adds two numbers and stores them into a pointer as long as said pointer is not null.
void add_ptr (int num1, int num2, int *ans)
{
    if (ans != NULL) {
        *ans = num1 + num2;
    }
}

// returns the factorial of a given number.
int factorial (int num)
{
    int ret = 1;
    for (int i = num; i > 0; i--) {
        ret *= i;
    }
    return ret;
}

bool is_prime (int num)
{
    for (int i = 2; i < sqrt(num); i++) {
        if (i % 2 == 0) {
            return false;
        }
    }
    return true;
}

void add_vec (vector_t v1, vector_t v2, vector_t* result)
{
    // vector_t total = &result;
    // *result.x = v1.x + v2.x;
    // *result.y = v1.y + v2.y;
    
}

double dot_prod_vec (vector_t v1, vector_t v2)
{
    return 0;
}

int sum_array (int *nums, size_t n)
{
    int values[n];
    // values = &nums;
    int sum = 0;

    return -1;
}

void sort_array (int *nums, size_t n)
{
}

bool read_line (FILE *f, char *buffer, size_t size)
{
    return false;
}
