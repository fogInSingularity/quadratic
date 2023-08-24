#ifndef SQUARE_SOLVER_H
#define SQUARE_SOLVER_H

enum NRoots {
    INF_ROOTS = -1,
    ZERO      =  0,
    ONE       =  1,
    TWO       =  2
};

NRoots linearSolver(double a, double b, double* x);
NRoots squareSolver(double a, double b, double c, double* x1, double* x2);

#endif