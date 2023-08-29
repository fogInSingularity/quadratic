#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#include "programModes.h"
#include "utest.h"
#include "talkToUser.h"
#include "squareSolver.h"
#include "utils.h"
#include "color.h"
#include "getopt.h"

enum ProgramMode {
    DEFAULT,
    TEST,
    HELP,
};

int main(int argc, char* argv[]) {
    // Option option[] = {{"test", 't', NULL, false, 0, NULL},
    //                     {NULL, '\0', NULL, false, 0, NULL}};
    // Getopt(argc, argv, option);

    // for(size_t i = 0; i < option->nArgs; i++) {
    //     printf("%s\n", (option->data)[i]);
    // }

    ProgramMode mode = DEFAULT;
    for (int i = 1; i < argc; i++) {
        if (IsEql(argv[i], "--test")) {
            mode = TEST;
            break;
        } else if (IsEql(argv[i], "--help")) {
            mode = HELP;
            break;
        }
    }

    switch(mode){
        case DEFAULT:
            Default();
            break;
        case TEST:
            TestAllSquareS();
            TestAllSwap();
            break;
        case HELP:
            Help();
            break;
        default:
            assert(0 && "unknown mode");
    }

    // for (size_t i = 0; i < option->nArgs; i++) {
    //     free(option->data[i]);
    // }
    // free(option->data);

    return 0;
}
