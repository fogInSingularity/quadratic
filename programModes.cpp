#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "squareSolver.h"
#include "talkToUser.h"
#include "utils.h"
#include "programModes.h"
#include "color.h"
#include "getopt.h"

int Help(Option* option) {
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

    return SUCCESS;
}

int DefaultStdio(Option* option) {
    (void) option;

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

    return SUCCESS;
}

int DefaultCli(Option* option) {
    assert(option != nullptr);

    const int CLI_M = 1;

    assert(option[CLI_M].nArgs >= 3); // аргументы кроме первых трёх будут игнорироваться ?
    assert(option[CLI_M].data[0] != nullptr);
    assert(option[CLI_M].data[1] != nullptr);
    assert(option[CLI_M].data[2] != nullptr);

    double a = NAN;
    double b = NAN;
    double c = NAN;

    if(ParseCoef(&a, option[CLI_M].data[0]) +
       ParseCoef(&b, option[CLI_M].data[1]) +
       ParseCoef(&c, option[CLI_M].data[2]) != 3 * SUCCESS) {
        return CLI_ERROR;
    }

    double x1 = NAN;
    double x2 = NAN;
    NRoots nRoots = SquareSolver(a, b, c, &x1, &x2);

    OutputRoots(nRoots, x1, x2);

    return SUCCESS;
}

int DefaultFile(Option* option) {
    assert(option != nullptr);

    const int FILE_M = 2;

    assert(option[FILE_M].data[0] != nullptr);

    const char* fileName = option[FILE_M].data[0];

    FILE* file = fopen(fileName, "r");
    if (file == nullptr) {
        return FILE_ERROR_CANT_OPEN;
    }

    double a = NAN;
    double b = NAN;
    double c = NAN;
    if(fscanf(file, "%lf %lf %lf", &a, &b, &c) < 3) {
       return FILE_ERROR_WRONG_DATA;
    }

    double x1 = NAN;
    double x2 = NAN;
    NRoots nRoots = SquareSolver(a, b, c, &x1, &x2);

    OutputRoots(nRoots, x1, x2);

    fclose(file);

    return SUCCESS;
}

int ParseCoef(double* coef,const char* data) {
    char* check;

    double n = strtod(data, &check);
    if (data + strlen(data) != check) {
        return CLI_ERROR;
    }

    *coef = n;

    return SUCCESS;
}
