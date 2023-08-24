#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "squareSolver.h"
#include "utest.h"
#include "utils.h"

int input_of_coeff(double* a, double* b, double* c);
void outputBRoots(NRoots nRoots, double x1, double x2);
void drop_duf(int* ch);
void ignore_spaces(int* ch);

/**
 * @brief input of coefficients of quadratic equations
 * 
 * @param a pointer to coeff a
 * @param b pointer to coeff b
 * @param c pointer to coeff c
 * 
 * @return if end of file had been reached: EOF else 0
*/
int input_of_coeff(double* a, double* b, double* c) {
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(a != b);
    assert(b != c);
    assert(a != c);

    printf("enter coefficients of\nquadratic equation in form a b c:\n");
    int state = 4; // 4 потому что scanf возвр зн <= 3;
    int flag = 1;
    do {
        state = scanf("%lf %lf %lf", a, b, c);
        if(state == EOF) {
            printf("end of file has been reached!\n");
            return EOF;
        } else if(state < 3) {
            printf("try again\n");
            int ch = '\0';
            drop_duf(&ch);
        } else {
            int ch = '\0';
            ignore_spaces(&ch);
            if(ch == '\n' || ch == EOF){
                flag = 0;
            } else {
                printf("try again\n"); // f
                drop_duf(&ch);
            }
        }
    } while(state != 3 || flag);
    return 0;
}

/**
 * @brief print roots of equation
 * 
 * @param nRoots number of roots
 * @param x1 first root
 * @param x2 first root
*/
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
            printf("something went wrong, unnown number of roots\n");
            break;
    }
}

/**
 * @brief drops input buffer
 * 
 * @param ch pointer to char witch clears buffer
*/
void drop_duf(int* ch) {
    while((*ch = getchar()) != '\n')
        ;
}

/**
 * @brief ignores spaces in input buffer
 * 
 * @param ch pointer to char witch clears spaces
*/
void ignore_spaces(int* ch) {
    while((*ch = getchar()) == ' ')
        ;
}