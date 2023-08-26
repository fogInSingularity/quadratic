#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "help.h"
#include "color.h"

void PrintHelpM() {
    printf("This utility that solves quadratic\n"
           "equation based on given coefficients\n\n");

    TurnOnStyle(Style::UDERLINE);
    TurnOnStyle(Style::BOLD);
    printf("Usage:");
    TurnOffAll();

    TurnOnStyle(Style::BOLD);
    printf(" ./quadratic ");
    TurnOffStyle(Style::BOLD);
    printf("[OPTIONS]\n\n");

    TurnOnStyle(Style::UDERLINE);
    TurnOnStyle(Style::BOLD);
    printf("Oprtions:\n");
    TurnOffAll();
    TurnOnStyle(Style::BOLD);
    printf("      --test\n");
    TurnOffAll();
    printf("          starts unit tests\n\n");
    TurnOnStyle(Style::BOLD);
    printf("      --help\n");
    TurnOffAll();
    printf("          prints this message\n");
}
