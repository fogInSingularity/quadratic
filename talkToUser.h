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


/**
 * @brief drops input buffer
 *
 * @param ch pointer to char witch clears buffer
*/
void DropBuf();


/**
 * @brief ignores spaces in input buffer
 *
 * @param ch pointer to char witch clears spaces
 *
 * @return if buffer consisted only of spaces: 1 else if buffer ends with eof: eof else: 0
*/
int IgnoreSpaces();


#endif // TALK_TO_USER
