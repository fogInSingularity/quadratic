#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "utils.h"
#include "squareSolver.h"

NRoots LinearSolver(double a, double b, double* x) {
    assert(IsFinite(a));
    assert(IsFinite(b));
    assert(x != nullptr);

    if (IsZero(a)) {
        *x = NAN;

        return IsZero(b) ? NRoots::INF_ROOTS : NRoots::ZERO;
    } else {
        *x = -b/a;
        *x = IsZero(*x) ? 0.0 : (*x);

        return NRoots::ONE;
    }
}

NRoots SquareSolver(double a, double b, double c, double* x1, double* x2) {
    assert(IsFinite(a));
    assert(IsFinite(b));
    assert(IsFinite(c));
    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(x1 != x2);

    if (IsZero(a)) {
        *x2 = NAN;

        return LinearSolver(b, c, x1);
    } else {
        double d = b*b - 4.0*a*c;
        if (IsZero(d)) {
            *x1 = (-b)/(2.0*a);
            *x1 = IsZero(*x1) ? 0.0 : (*x1);

            *x2 = NAN;

            return NRoots::ONE;
        } else if (d > 0.0) {
            double d_sqrt = IsZero(c) ? b : sqrt(d);

            *x1 = (-b - d_sqrt) / (2.0 * a);
            *x1 = IsZero(*x1) ? 0.0 : (*x1);

            *x2 = (-b + d_sqrt) / (2.0 * a);
            *x2 = IsZero(*x2) ? 0.0 : (*x2);

            return NRoots::TWO;
        } else {
            return NRoots::ZERO;
        }
    }
}
