#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "squareSolver.h"
#include "input_of_coeff.h"

int main(){
    double a = NAN;
    double b = NAN;
    double c = NAN;

    if(input_of_coeff(&a, &b, &c) == EOF){
        return 0;
    }

    double x1 = NAN;
    double x2 = NAN;
    NRoots nRoots = squareSolver(a, b, c, &x1, &x2);


    printf("this equation has:\n");
    switch(nRoots) {
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
            printf("something went wrong, unnown number of roots\n");
            break;
    }

    return 0;
}