#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "utils.h"
#include "squareSolver.h"

NRoots linearSolver(double a, double b, double* x) {
    assert(is_finite(a));
    assert(is_finite(b));
    assert(x != NULL);

    if(is_zero(a)) {
        *x = NAN;
        return is_zero(b) ? NRoots::INF_ROOTS : NRoots::ZERO;
    } else {
        *x = -b/a;
        *x = is_zero(*x) ? 0.0 : (*x);
        return NRoots::ONE;
    }
}

NRoots squareSolver(double a, double b, double c, double* x1, double* x2) {
    assert(is_finite(a));
    assert(is_finite(b));
    assert(is_finite(c));
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if(is_zero(a)) {
        *x2 = NAN;

        return linearSolver(b, c, x1);
    } else {
        double d = b*b - 4.0*a*c;
        if(is_zero(d)) {
            *x1 = (-b)/(2.0*a);
            *x1 = is_zero(*x1) ? 0.0 : (*x1);

            *x2 = NAN;

            return NRoots::ONE;
        } else if(d > 0.0) {
            double d_sqrt = NAN;
            if(is_zero(c)) {
                d_sqrt = b;
            } else {
                d_sqrt = sqrt(d);
            }

            *x1 = (-b - d_sqrt) / (2.0 * a);
            *x1 = is_zero(*x1) ? 0.0 : (*x1);

            *x2 = (-b + d_sqrt) / (2.0 * a);
            *x2 = is_zero(*x2) ? 0.0 : (*x2);

            return NRoots::TWO;
        } else {
            return NRoots::ZERO;
        }
    }
}
