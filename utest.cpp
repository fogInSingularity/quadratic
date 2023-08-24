#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

#include "utils.h"
#include "squareSolver.h"
#include "utest.h"

bool testOneSquareS(const SquareSTest* test) {
    double x1 = NAN;
    double x2 = NAN;

    int nRoots = squareSolver(test->a, test->b, test->c, &x1, &x2);

    if(test->x1ref > test->x2ref)
        swapf(&x1, &x2, sizeof(x1));

    /**
     * left bit x1
     * middle bit x2
     * right bit nRoots
    */
    int flag = 0b000;

    if(is_eql(x1, test->x1ref) != 1 || isnan(x1) != isnan(test->x1ref)) {
        if(isnan(x1) != isnan(test->x1ref)) {
            flag |= 0b100;
        }
    }

    if(is_eql(x2, test->x2ref) != 1 || isnan(x2) != isnan(test->x2ref)) {
        if(isnan(x1) != isnan(test->x1ref)) {
            flag |= 0b010;
        }
    }

    if(nRoots != test->nRootsRef)
        flag |= 0b001;


    if(flag == 0b000) {
        printf("# test passed\n");
        return true;
    } else {
        printf("! FAILED:\n");
        if(flag & 0b100)
            printf("# x1 calculated wrong\n"
                "  x1 == %lf, x1ref == %lf\n", x1, test->x1ref);
        if(flag & 0b010)
            printf("# x2 calculated wrong\n"
                "  x2 == %lf, x2ref == %lf\n", x2, test->x2ref);
        if(flag & 0b001)
            printf("# nRoots calcuated wrong\n"
                "  nRoots == %d, nRootsRef == %d\n", nRoots, test->nRootsRef);
        return false;
    }
}

void testAllSquareS() {
    FILE* file = NULL;
    file = fopen("tests.txt", "r");
    assert(file);

    SquareSTest test = { NAN, NAN, NAN, NAN, NAN, NRoots::INF_ROOTS };

    printf("# testing solver...\n");
    while(fscanf(file, "%lf %lf %lf %lf %lf %d", &(test.a), &(test.b), &(test.c),
                                                 &(test.x1ref), &(test.x2ref),
                                                (int*)(&(test.nRootsRef))) != EOF) {
        testOneSquareS(&test);
    }

    fclose(file);
}

bool testOneSwap(const SwapTest* test){
    char str1[101] = "";
    char str2[101] = "";
    char str1ref[101] = "";
    char str2ref[101] = "";

    strcpy(str1, test->str1);
    strcpy(str2, test->str2);
    strcpy(str1ref, test->str2);
    strcpy(str2ref, test->str1);

    size_t size = 0;
    while(str1[size] != '\0'){
        size++;
    }

    swapf(str1, str2, size);

    /**
     * left bit str1
     * right bit str2
    */
    int flag = 0b00;
    if(!is_eql(str1, str1ref)){
        flag |= 0b10;
    }

    if(!is_eql(str2, str2ref)){
        flag |= 0b01;
    }

    if(flag == 0){
        printf("# test passed\n");
        return true;
    } else {
        printf("! FAILED:\n");
        printf("! bytes swaped incorrectly\n");
        printf("! expected value for first variable:\n"
               "!     %s", str1ref);
        printf("! received value for first variable:\n"
               "!     %s", str1);
        printf("! expected value for first variable:\n"
               "!     %s", str2ref);
        printf("! received value for first variable:\n"
               "!     %s", str2);

        return false;
    }
}

void testAllSwap(){
    SwapTest testArr[20] = {
        {"a", "b"},
        {"ab", "cd"},
        {"foo", "bar"},
        {"snus", "cock"},
        {"EmL890MZ", "3RvD4QmT"},
        {"N3DAv8TvUXf", "98mW84HcBhA"},
        {"YWcNsgD1YZAsax2", "bUhUpXiF4GurRZB"},
        {"H9ACX8mUaof9p7Dt", "H9ACX8mUaof9p7Dt"},
        {"K2GsNhToFDXJ2MEVEc", "K2GsNhToFDXJ2MEVEc"},
        {"LdUiCw2s0QBp1BoHQp3w8HE2DqG", "LeaBsenVPq4otw461LKkY1GZ4Da"},
        {"pZ28fQywMAkm1jorei9nhWggyrn4FV5", "JQY0KCXbcZtNXvMsxpuBdg5c3eX0noX"},
        {"9zcpKYjx9RxCYkLv86ycp4XFMAniVbMYNiTkF", "eymec03RzqpQ72nGqG1r88UXXwfZQCVVU72rF"},
        {"PXRcYiyKCL5hKXaAC2J81REYn58BCeWkMXB7PRrZwLF", "Z4DDusLcUC2JR3y6mNxga646inPn0gGbfdtAEo92Goq"},
        {"duwCrTLAF11B1vpvTEQPJvb5kcWdvyv62nPpRL2VVWW3YzojeH", "uz7cRAw3DTsgozBcegyjk5dtRjR68sHCNE3xskd5GCU3fwo3iU"},
        {"gCa2FGgnYZwQarKLwmLcc0R1xdrtnu9QbM8rHNPXCw2oQ3eE7JPEMH4WoVL", "0co5FNQveZPjhvenMpnP0fiU43kHnGZkinfCXRr8ACEBLzm7NyhVe5h7ad3"},
        {"yNkRT3HufgVe9ouHLYDbvHiUVuN1X2VDDMTn990eiNzLbrBKFsK85VAtZeGV01Qs", "zALQVjPnKgNWw70QjMhDUjhcCQQ2oL8Vq4TGL60vYQ0R0eiQ1i2gH7Njk35kjh6h"},
        {"AUTXX0yQ47V8pndjd7jy8BQbHEvtJYdYEAzxhL61Fjf2ZxsDCvYsBHndxKWnNZHtikRmqZ", "5gzKcfXwgGbR5Y3mh3fvP1GWZw2bnkG6yq1123ArhRj8PMwYXUAzxdBenW7i6H1d87P2bT"},
        {"eiEdmKCCfvWnc7KMahdYpXfXpTnYFbhKZP9nBtLJAbWrvsiAPBYrftMPRyTN1z1hYyxrUydG04", "BsiLWZF5HVkWefZFdJ9wTj23XfcpCKCH9uFyqvmk1okYektJvm1subzMYpoqLW0c1k8DB929JH"},
        {"ivz90hksUAiYPiWaMU7ZiJD6PgMuFNdWmJxTYt4eojm5BzDTcjkpDfngs2Btw4f5v8PmJy9fuTsndBUvvL", "UZxxwVvg8darcXhhLfuGo2oRwjzEG3GkHp1M31PU6cMr8k6GvGrPJfd7iR3uND97kZmdXnXF3GmxuDi45x"},
        {"thF2mG5ztie4jhABsCAfFmUpMHyiwo7To3AWYiJKYcRsarLKohzieqrEVXkgExvGZGC6nDcVTCmHpBtNaEfXmov9QHssB7LVFLWa", "tisbTxcRvKspzf4U0MQEbtBqxhfEVVEgvqcbiEu3xnorghtRPQyHG9yN3nKQ3mxV0k2iVzjnTpZz7YE0AjDf4PmRQ7rEHBZbrPf8"}
    };
    int nTest = 20;
    printf("# testing swap...\n");
    for(int i = 0; i < nTest; i++){
        testOneSwap(&testArr[i]);
    }
}
