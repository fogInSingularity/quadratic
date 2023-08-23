#ifndef INPUT_OF_COEFF
#define INPUT_OF_COEFF

#include <stdio.h>
#include <math.h>
#include <assert.h>

// возвр EOF или 0 (всё ок)
static int input_of_coeff(double* a, double* b, double* c) {
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
            int ch = 0;
            while((ch = getchar()) != '\n')
                ;
        } else {
            int ch = '\0';
            while((ch = getchar()) == ' ')
                ;
            if(ch == '\n' || ch == EOF){
                flag = 0;
            } else {
                printf("try again\n");
                while((ch = getchar()) != '\n')
                    ;
            }
        }
    } while(state != 3 || flag);
    return 0;
}

#endif