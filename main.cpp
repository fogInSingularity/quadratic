#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "squareSolver.h"
#include "talkToUser.h"
#include "utils.h"
#include "utest.h"

int main(int argc, char* argv[]) {
    int testOp = 0;
    for(int i = 1; i < argc; i++) {
        if(is_eql(argv[i], "--test")) {
            testOp = 1;
        }
    }

    if(testOp) {
        testAll();

        return 0;
    } else {
        double a = NAN;
        double b = NAN;
        double c = NAN;

        if(input_of_coeff(&a, &b, &c) == EOF) {
            return 0;
        }

        double x1 = NAN;
        double x2 = NAN;
        NRoots nRoots = squareSolver(a, b, c, &x1, &x2);

        outputBRoots(nRoots, x1, x2);

        return 0;
    }
}