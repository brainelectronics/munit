//--------------------------------------------------------------------------------------------------

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <assert.h>

/**
 * @brief      Calculate the sum of two elements
 *
 * @param[in]  a     First element
 * @param[in]  b     Second element
 *
 * @return     Result of calculation
 */
int calc_sum(int a, int b);

/**
 * @brief      Calculate sum using pointers
 *
 * @param      pa       Pointer to first element
 * @param      pb       Pointer to second element
 * @param      pResult  Pointer to the result
 */
// void calc_sum_ptr(int *pa, int *pb, int *pResult);

/**
 * @brief      Calculate the difference of two elements
 *
 * @param[in]  a     First element to substract from
 * @param[in]  b     Second element to be substracted
 *
 * @return     Result of calculation
 */
int calc_difference(int a, int b);

/**
 * @brief      Calculate sum using pointers
 *
 * @param      pa       Pointer to first element to substract from
 * @param      pb       Pointer to second element to be substracted
 * @param      pResult  Pointer to the result
 */
// void calc_difference_ptr(int *pa, int *pb, int *pResult);

/**
 * @brief      Calculate the product of two elements
 *
 * @param[in]  a     First element
 * @param[in]  b     Second element
 *
 * @return     Result of calculation
 */
int multiplication(int a, int b);

/**
 * @brief      Calculate product using pointers
 *
 * @param      pa       Pointer to first element
 * @param      pb       Pointer to second element
 * @param      pResult  Pointer to the result
 */
// void multiplication_ptr(int *pa, int *pb, int *pResult);

/**
 * @brief      Calculate the quotient of two elements
 *
 * @param[in]  a     Dividend
 * @param[in]  b     Divisor
 *
 * @return     Result of calculation
 */
double division(int dividend, int divisor);

/**
 * @brief      Calculate quotient using pointers
 *
 * @param      pa       Pointer to dividend
 * @param      pb       Pointer to divisor
 * @param      pResult  Pointer to the result
 */
// void division_ptr(int *pDividend, int *pDivisor, double *pQuotient);

#endif
