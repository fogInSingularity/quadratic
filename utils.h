#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <math.h>
#include <assert.h>

static const double DELTA = 0.00000001;

// static int is_eql(double a, double b) {
//     return abs(a - b) < DELTA;
// }

static int is_zero(double n) {
    return abs(n) < DELTA;
}

static int is_finite(double n) {
    return (isnan(n) != 1) && (n > -INFINITY) && (n < INFINITY);
}

#endif