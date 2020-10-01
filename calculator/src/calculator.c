/**
 * @brief      This file implements functions of a calculator.
 *
 * @author     brainelectronics
 * @date       2020
 */

#include "calculator.h"

int calc_sum(int a, int b)
{
    return a+b;
}

// void calc_sum_ptr(int *pa, int *pb, int *pResult)
// {
//     *pResult = *pa + *pb;
// }

int calc_difference(int a, int b)
{
    return a-b;
}

// void calc_difference_ptr(int *pa, int *pb, int *pResult)
// {
//     *pResult = *pa - *pb;
// }

int multiplication(int a, int b)
{
    return a*b;
}

// void multiplication_ptr(int *pa, int *pb, int *pResult)
// {
//     *pResult = *pa * *pb;
// }

double division(int dividend, int divisor)
{
    assert(divisor);

    return (double)dividend / (double)divisor;
}

// void division_ptr(int *pDividend, int *pDivisor, double *pQuotient)
// {
//     *pQuotient = *pDividend / (double)*pDivisor;
// }
