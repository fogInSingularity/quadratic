#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "squareSolver.h"
#include "talkToUser.h"
#include "utils.h"
#include "programModes.h"
#include "color.h"
#include "getopt.h"

void Help(Option* option) {
    assert(option != nullptr);

    printf("This utility that solves quadratic\n"
           "equation based on given coefficients\n\n");

    printf("Usage:");
    printf(" ./quadratic [OPTIONS]\n\n");

    printf("Oprtions:\n");
    printf("      --test\n");
    printf("          starts unit tests\n\n");
    printf("      --help\n");
    printf("          prints this message\n");
}

void DefaultStdio(Option* option) {
    assert(option != nullptr);

    double a = NAN;
    double b = NAN;
    double c = NAN;

    if (InputOfCoeff(&a, &b, &c) != EOF) {
        double x1 = NAN;
        double x2 = NAN;
        NRoots nRoots = SquareSolver(a, b, c, &x1, &x2);

        OutputRoots(nRoots, x1, x2);
    }
}

void DefaultCli(Option* option) {
    assert(option != nullptr);

    const int CLI_M = 1;

    assert(option[CLI_M].nArgs >= 3); // аргументы кроме первых трёх будут игнорироваться ?
    assert(option[CLI_M].data[0] != nullptr);
    assert(option[CLI_M].data[1] != nullptr);
    assert(option[CLI_M].data[2] != nullptr);

    double a = atof(option[CLI_M].data[0]);
    double b = atof(option[CLI_M].data[1]);
    double c = atof(option[CLI_M].data[2]);

    double x1 = NAN;
    double x2 = NAN;
    NRoots nRoots = SquareSolver(a, b, c, &x1, &x2);

    OutputRoots(nRoots, x1, x2);
}

void DefaultFile(Option* option) {
    assert(option != nullptr);

    const int FILE_M = 2;

    assert(option[FILE_M].data[0] != NULL);

    const char* fileName = option[FILE_M].data[0];

    FILE* file = fopen(fileName, "r");
    assert(file != nullptr);

    double a = NAN;
    double b = NAN;
    double c = NAN;
    if(fscanf(file, "%lf %lf %lf", &a, &b, &c) < 3) {
        assert(0 && "something wrong with file data");
    }

    double x1 = NAN;
    double x2 = NAN;
    NRoots nRoots = SquareSolver(a, b, c, &x1, &x2);

    OutputRoots(nRoots, x1, x2);

    fclose(file);
}
