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
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(a != b);
    assert(b != c);
    assert(a != c);

    TurnOnColor(Color::YELLOW);
    TurnOnStyle(Style::BOLD);
    printf("enter coefficients of\nquadratic equation in form a b c:\n");
    TurnOffAll();

    int state = 4; // 4 потому что scanf возвр зн <= 3;
    int flag = true;
    do {
        TurnOnColor(Color::GREEN);
        TurnOnStyle(Style::BOLD);
        state = scanf("%lf %lf %lf", a, b, c);
        TurnOffAll();
        if (state == EOF) {
            TurnOnColor(Color::RED);
            TurnOnStyle(Style::BOLD);
            printf("end of file has been reached!\n");
            TurnOffAll();
            return EOF;
        } else if (state < 3) {
            TurnOnColor(Color::RED);
            TurnOnStyle(Style::BOLD);
            printf("try again\n");
            TurnOffAll();
            DropBuf();
        } else {
            int onlySpaces = IgnoreSpaces();
            if (onlySpaces == 1) {
                flag = false;
            } else if (onlySpaces == EOF) {
                TurnOnColor(Color::RED);
                TurnOnStyle(Style::BOLD);
                printf("end of file has been reached!\n");
                TurnOffAll();
                return EOF;
            } else {
                TurnOnColor(Color::RED);
                TurnOnStyle(Style::BOLD);
                printf("try again\n");
                TurnOffAll();
                DropBuf();
            }
        }
    } while (state != 3 || flag);
    return 0;
}

void OutputRoots(NRoots nRoots, double x1, double x2) {
    TurnOnColor(Color::YELLOW);
    TurnOnStyle(Style::BOLD);
    printf("this equation has:\n");
    TurnOffAll();

    TurnOnColor(Color::CYAN);
    TurnOnStyle(Style::BOLD);
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
    TurnOffAll();
}

void DropBuf() {
    int ch = 0;

    while((ch = getchar()) != '\n' && ch != EOF) {}
}

int IgnoreSpaces() {
    int ch = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (!isspace(ch))
            return 0;
    }

    if (ch == EOF)
        return EOF;

    return 1;
}
