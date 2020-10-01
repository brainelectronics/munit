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

    // int *pa = &a;
    // int *pb = &b;
    // int *pResult = &result;

    result = calc_sum(a, b);
    printf("Result of %d + %d: %d\n", a, b, result);

    // calc_sum_ptr(pa, pb, pResult),
    // printf("Result of %d + %d: %d\n", a, b, *pResult);

    result = calc_difference(a, b);
    printf("Result of %d - %d: %d\n", a, b, result);

    // calc_difference_ptr(pa, pb, pResult);
    // printf("Result of %d - %d: %d\n", a, b, *pResult);

    result = multiplication(a, b);
    printf("Result of %d * %d: %d\n", a, b, result);

    // multiplication_ptr(pa, pb, pResult);
    // printf("Result of %d * %d: %d\n", a, b, *pResult);

    double dResult = division(a, b);
    printf("Result of %d / %d: %1.2f\n", a, b, dResult);

    // uncomment the next line to run into an assert
    dResult = division(a, 0);
    printf("Result of %d / %d: %1.2f\n", a, 0, dResult);

    // double *pdResult = &dResult;
    // division_ptr(pa, pb, pdResult);
    // printf("Result of %d / %d: %1.2f\n", a, b, *pdResult);

    return 0;
}