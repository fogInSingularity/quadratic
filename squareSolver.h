#ifndef SQUARE_SOLVER_H
#define SQUARE_SOLVER_H


/// @brief definition of enum that holds number of roots in equation
enum NRoots {
    INF_ROOTS = -1, ///< infinite number of roots
    ZERO      =  0, ///< zero roots
    ONE       =  1, ///< one root
    TWO       =  2  ///< two roots
};


/**
 * @brief calculates roots of linrear equation (ax + b = 0)
 *
 * @param a coefficient a
 * @param b coefficient b
 * @param x pointer to root
 *
 * @return number of roots
*/
NRoots LinearSolver(double a, double b, double* x);


/**
 * @brief calculates roots of quadratic equation (ax^2 + bx + c = 0)
 *
 * @param a coefficient a
 * @param b coefficient b
 * @param c coefficient c
 * @param x1 pointer to first root
 * @param x2 pointer to second root
 *
 * @return number of roots
*/
NRoots SquareSolver(double a, double b, double c, double* x1, double* x2);


#endif // SQUARE_SOLVER_H
