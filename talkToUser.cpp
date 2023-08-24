#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>

#include "squareSolver.h"
#include "utest.h"
#include "utils.h"
#include "talkToUser.h"

int input_of_coeff(double* a, double* b, double* c) {
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(a != b);
    assert(b != c);
    assert(a != c);

    printf("enter coefficients of\nquadratic equation in form a b c:\n");
    int state = 4; // 4 потому что scanf возвр зн <= 3;
    int flag = true;
    do {
        state = scanf("%lf %lf %lf", a, b, c);
        if(state == EOF) {
            printf("end of file has been reached!\n");
            return EOF;
        } else if(state < 3) {
            printf("try again\n");
            drop_duf();
        } else {
            int onlySpaces = ignore_spaces();
            if(onlySpaces == 1){
                flag = false;
            } else if(onlySpaces == EOF) {
                printf("end of file has been reached!\n");
                return EOF;
            } else {
                printf("try again\n"); // f
                drop_duf();
            }
        }
    } while(state != 3 || flag);
    return 0;
}

void outputBRoots(NRoots nRoots, double x1, double x2){
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
            assert(0 && "something went wrong, unnown number of roots");
            break;
    }
}

void drop_duf() {
    int ch = 0;

    while((ch = getchar()) != '\n' && ch != EOF) {}
}

int ignore_spaces() {
    int ch = 0;

    while((ch = getchar()) != '\n' && ch != EOF) {
        if (!isspace(ch))
            return 0;
    }

    if(ch == EOF)
        return EOF;

    return 1;
}
