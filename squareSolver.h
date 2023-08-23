#ifndef SQUARE_SOLVER_H
#define SQUARE_SOLVER_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "utils.h"

enum NRoots {
    INF_ROOTS = -1,
    ZERO = 0,
    ONE = 1,
    TWO = 2
};

// возвр число корней
static NRoots linearSolver(double a, double b, double* x) {
    assert(is_finite(a));
    assert(is_finite(b));
    assert(x != NULL);

    if(is_zero(a)) {
        return is_zero(b) ? INF_ROOTS : ZERO;
    } else {
        *x = (-b)/a;
        *x = is_zero(*x) ? 0.0 : (*x);
        return ONE;
    }
}

// возвр число корней 
static NRoots squareSolver(double a, double b, const double c, double* x1, double* x2) {
    assert(is_finite(a));
    assert(is_finite(b));
    assert(is_finite(c));
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if(is_zero(a)) {
        return linearSolver(b, c, x1);
        *x2 = NAN;
    } else {
        double d = b*b - 4.0*a*c;
        if(is_zero(d)) {
            *x1 = (-b)/(2.0*a);
            *x1 = is_zero(*x1) ? 0.0 : (*x1);
            *x2 = NAN;
            return ONE;
        } else if(d > 0.0) {
            double d_sqrt = sqrt(d);
            *x1 = (-b + d_sqrt) / (2.0 * a);
            *x1 = is_zero(*x1) ? 0.0 : (*x1);
            *x2 = (-b - d_sqrt) / (2.0 * a);
            *x2 = is_zero(*x2) ? 0.0 : (*x2);
            return TWO;
        } else {
            return ZERO;
        }
    }
}

#endif