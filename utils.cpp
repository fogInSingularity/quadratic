#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "utils.h"

void swapf(double* a, double* b) {
    assert(a != b);
    assert(a == NULL);
    assert(b == NULL);

    double t = *a;
               *a = *b;
                    *b =  t;
}

bool is_eql(double a, double b) {
    return abs(a - b) < DELTA;
}

bool is_eql(const char a[],const char b[]) {
    int size_a = 0;
    int size_b = 0;
    while(a[size_a] != '\0')
        size_a++;
    while(b[size_b] != '\0')
        size_b++;
    if(size_a != size_b)
        return false;

    int i = 0;
    int j = 0;
    for(; a[i] != '\0' && b[i] != '\0'; i++) {
        if(a[i] == b[i])
            j++;
    }

    return (i == j) ? true : false;
}

bool is_zero(double n) {
    return abs(n) < DELTA;
}

bool is_finite(double n) {
    return (isnan(n) != true) && (n > -INFINITY) && (n < INFINITY);
}
