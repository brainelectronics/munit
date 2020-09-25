/**
 * @brief      This file implements a calculator example.
 *
 * @author     brainelectronics
 * @date       2020
 */

#include <stdio.h>
#include "src/calculator.h"

int main(int argc, char const *argv[])
{
    int result = 0;
    int a = 3;
    int b = 4;
    int expected = 7;

    int *pa = &a;
    int *pb = &b;
    int *pResult = &result;

    result = calc_sum(a, b);
    printf("Result of %d + %d: %d\n", a, b, result);

    calc_sum_ptr(pa, pb, pResult),
    printf("Result of %d + %d: %d\n", a, b, *pResult);

    return 0;
}