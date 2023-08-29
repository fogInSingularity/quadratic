#ifndef TALK_TO_USER
#define TALK_TO_USER


#include "squareSolver.h"


/**
 * @brief input of coefficients of quadratic equations
 *
 * @param a pointer to coeff a
 * @param b pointer to coeff b
 * @param c pointer to coeff c
 *
 * @return if end of file had been reached: EOF else 0
*/
int InputOfCoeff(double* a, double* b, double* c);


/**
 * @brief print roots of equation
 *
 * @param nRoots number of roots
 * @param x1 first root
 * @param x2 second root
*/
void OutputRoots(NRoots nRoots, double x1, double x2);


#endif // TALK_TO_USER
