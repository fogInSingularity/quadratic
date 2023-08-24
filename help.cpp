#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "help.h"

void printHelpM(){
    printf("\nThis utility helps solve quadratic\n"
           " equation based on given coefficients\n\n");
    printf("Usage:\n");
    printf("  ./quadratic [OPTIONS]\n\n");
    printf("Oprtions:\n");
    printf("  --test\n");
    printf("          starts unit tests\n\n");
    printf("  --help\n");
    printf("          prints this message\n\n");
}
