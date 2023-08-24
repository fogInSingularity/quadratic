#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>

#include "utils.h"
#include "squareSolver.h"
#include "utest.h"

bool testOne(const Utest* utest) {
    double x1 = NAN;
    double x2 = NAN;

    int nRoots = squareSolver(utest->a, utest->b, utest->c, &x1, &x2);

    if(utest->x1ref > utest->x2ref)
        swapf(&x1, &x2);

    /**
     * left bit x1
     * middle bit x2
     * right bit nRoots
    */
    int flag = 0b000;

    if(is_eql(x1, utest->x1ref) != 1 || isnan(x1) != isnan(utest->x1ref)) {
        if(isnan(x1) != isnan(utest->x1ref)) {
            flag |= 0b100;
        }
    }

    if(is_eql(x2, utest->x2ref) != 1 || isnan(x2) != isnan(utest->x2ref)) {
        if(isnan(x1) != isnan(utest->x1ref)) {
            flag |= 0b010;
        }
    }

    if(nRoots != utest->nRootsRef)
        flag |= 0b001;


    if(flag == 0b000) {
        printf("# test passed\n");
        return true;
    } else {
        printf("! FAILED:\n");
        if(flag & 0b100)
            printf("# x1 calculated wrong\n"
                "  x1 == %lf, x1ref == %lf\n", x1, utest->x1ref);
        if(flag & 0b010)
            printf("# x2 calculated wrong\n"
                "  x2 == %lf, x2ref == %lf\n", x2, utest->x2ref);
        if(flag & 0b001)
            printf("# nRoots calcuated wrong\n"
                "  nRoots == %d, nRootsRef == %d\n", nRoots, utest->nRootsRef);
        return false;
    }
}

void testAll() {
    FILE* file = NULL;
    file = fopen("tests.txt", "r");
    assert(file);

    Utest utest = { NAN, NAN, NAN, NAN, NAN, NRoots::INF_ROOTS };

    printf("# testing...\n");
    // в функ
    while(fscanf(file, "%lf %lf %lf %lf %lf %d", &(utest.a), &(utest.b), &(utest.c),
                                                 &(utest.x1ref), &(utest.x2ref),
                                                (int*)(&(utest.nRootsRef))) != EOF) {
        testOne(&utest);
    }

    fclose(file);
}
