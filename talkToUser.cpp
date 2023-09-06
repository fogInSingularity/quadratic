#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>

#include "squareSolver.h"
#include "utest.h"
#include "utils.h"
#include "talkToUser.h"
#include "color.h"

int InputOfCoeff(double* a, double* b, double* c) {
    assert(a != nullptr);
    assert(b != nullptr);
    assert(c != nullptr);
    assert(a != b);
    assert(b != c);
    assert(a != c);

    printf("enter coefficients of\nquadratic equation in form a b c:\n");

    int state = 4; // 4 потому что scanf возвр зн <= 3;
    bool flag = true;

    do {
        state = scanf("%lf %lf %lf", a, b, c);
        if (state == EOF) {
            printf("end of file has been reached!\n");
            return EOF;

        } else if (state < 3) {
            printf("try again\n");
            DropBuf();

        } else {
            int onlySpaces = IgnoreSpaces();

            if (onlySpaces == 1) {
                flag = false;
            } else if (onlySpaces == EOF) {
                printf("end of file has been reached!\n");
                return EOF;
            } else {
                printf("try again\n");
                DropBuf();
            }
        }
    } while (state != 3 || flag);
    return 0;
}

void OutputRoots(NRoots nRoots, double x1, double x2) {
    printf("this equation has:\n");

    switch (nRoots) {
        case INF_ROOTS:
            printf("infinte number of roots\n");
            break;

        case ZERO:
            printf("zero roots\n");
            break;

        case ONE:
            printf("one root: %lf\n", x1);
            break;

        case TWO:
            printf("two roots: %lf and %lf\n", x1, x2);
            break;

        default:
            assert(0 && "something went wrong, unnown number of roots");
            break;
    }
}
