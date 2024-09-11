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
    return abs(num1) + abs(num2);
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
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void add_vec (vector_t v1, vector_t v2, vector_t* result)
{
    if (result != NULL) {
        result->x = v1.x + v2.x;
        result->y = v1.y + v2.y;
    }
}

double dot_prod_vec (vector_t v1, vector_t v2)
{
    return (v1.x * v2.x) + (v1.y * v2.y);
}

int sum_array (int *nums, size_t n)
{
    if (nums != NULL) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += *nums++;
        }
        return sum;
    }
    return 0;
}

// performs a selection sort on the given int array, as taught in CS240 at JMU by Dr. Molloy.
void sort_array (int *nums, size_t n)
{
    if (nums != NULL) {
        for (int i = 0; i < n; i++) {
            int big = 0;
            for (int j = 1; j < n - i; j++) {
                if (*(nums + j) > *(nums + big)) {
                    big = j;
                }
            }
            int swap = *(nums + big);
            *(nums + big) = *(nums + n - i - 1);
            *(nums + n - i - 1) = swap;
        }
    }
}

bool read_line (FILE *f, char *buffer, size_t size)
{
    // return f != NULL && buffer != NULL && fgets(buffer, size, f) != NULL;
    if (f != NULL && buffer != NULL) {
        char *ret = fgets(buffer, size, f);
        return ret != NULL;
    }
    return false;
}
