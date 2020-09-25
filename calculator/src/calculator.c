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

void calc_sum_ptr(int *pa, int *pb, int *pResult)
{
    *pResult = *pa + *pb;
}