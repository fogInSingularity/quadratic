#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "squareSolver.h"
#include "talkToUser.h"
#include "utils.h"
#include "defaultm.h"
#include "color.h"

void DefaultMessage() {
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
