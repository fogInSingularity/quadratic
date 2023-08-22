#include <stdio.h>
#include <math.h>
#include <assert.h>

static const double DELTA = 0.00000001;
static const int INF_ROOTS = -1;

int input_of_coeff(double* a, double* b, double* c);
int is_zero(double n);
int is_finite(double n);
int linearSolver(double a, double b, double* x);
int squareSolver(double a, double b, const double c, double* x1, double* x2);

int main(){
    double a = NAN;
    double b = NAN;
    double c = NAN;

    if(input_of_coeff(&a, &b, &c) == EOF){
        return 0;
    }

    double x1 = NAN;
    double x2 = NAN;
    int nRoots = squareSolver(a, b, c, &x1, &x2);

    printf("this equation has:\n");
    switch(nRoots) {
        case INF_ROOTS:
            printf("infinte number of roots\n");
            break;
        case 0:
            printf("zero roots\n");
            break;
        case 1:
            printf("one root: %lf\n", x1);
            break;
        case 2:
            printf("two roots: %lf and %lf\n", x1, x2);
            break;
        default:
            printf("something went wrong, unnown number of roots\n");
            break;
    }

    return 0;
}

// возвр EOF или 0 (всё ок)
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

int is_zero(double n) {
    return abs(n) < DELTA;
}

int is_finite(double n) {
    return (isnan(n) != 1) && (n > -INFINITY) && (n < INFINITY);
}

// возвр число корней
int linearSolver(double a, double b, double* x) {
    assert(is_finite(a));
    assert(is_finite(b));
    assert(x != NULL);

    if(is_zero(a)) {
        return is_zero(b) ? INF_ROOTS : 0;
    } else {
        *x = (-b)/a;
        *x = is_zero(*x) ? 0.0 : (*x);
        return 1;
    }
}

// возвр число корней 
int squareSolver(double a, double b, const double c, double* x1, double* x2) {
    assert(is_finite(a));
    assert(is_finite(b));
    assert(is_finite(c));
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if(is_zero(a)) {
        return linearSolver(b, c, x1);
        *x2 = NAN;
    } else {
        double d = b*b - 4.0*a*c;
        if(is_zero(d)) {
            *x1 = (-b)/(2.0*a);
            *x1 = is_zero(*x1) ? 0.0 : (*x1);
            *x2 = NAN;
            return 1;
        } else if(d > 0.0) {
            double d_sqrt = sqrt(d);
            *x1 = (-b + d_sqrt) / (2.0 * a);
            *x1 = is_zero(*x1) ? 0.0 : (*x1);
            *x2 = (-b - d_sqrt) / (2.0 * a);
            *x2 = is_zero(*x2) ? 0.0 : (*x2);
            return 2;
        } else {
            return 0;
        }
    }
}