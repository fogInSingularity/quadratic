#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "squareSolver.h"
#include "talkToUser.h"
#include "utils.h"
#include "defaultm.h"

void default_message(){
    double a = NAN;
    double b = NAN;
    double c = NAN;

    if(input_of_coeff(&a, &b, &c) != EOF) {
        double x1 = NAN;
        double x2 = NAN;
        NRoots nRoots = squareSolver(a, b, c, &x1, &x2);

        outputBRoots(nRoots, x1, x2);
    }
}
