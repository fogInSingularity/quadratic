#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "squareSolver.h"
#include "talkToUser.h"
#include "utils.h"
#include "programModes.h"
#include "color.h"

void Help() {
    printf("This utility that solves quadratic\n"
           "equation based on given coefficients\n\n");

    printf("Usage:");
    printf(" ./quadratic [OPTIONS]\n\n");

    printf("Oprtions:\n");
    printf("      --test\n");
    printf("          starts unit tests\n\n");
    printf("      --help\n");
    printf("          prints this message\n");
}

void Default() {
    double a = NAN;
    double b = NAN;
    double c = NAN;

    if (InputOfCoeff(&a, &b, &c) != EOF) {
        double x1 = NAN;
        double x2 = NAN;
        NRoots nRoots = SquareSolver(a, b, c, &x1, &x2);

        OutputRoots(nRoots, x1, x2);
    }
}
