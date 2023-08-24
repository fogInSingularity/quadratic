#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <getopt.h>

#include "squareSolver.h"
#include "talkToUser.h"
#include "utils.h"
#include "utest.h"
#include "help.h"
#include "defaultm.h"

enum ProgramMode {
    DEFAULT,
    UNIT_TEST,
    HELP_MESSAGE
};

int main(int argc, char* argv[]) {
    option opt[3];

    opt[0] = {
        "test",
        0,
        0,
        UNIT_TEST
    };
    opt[1] = {
        "help",
        0,
        0,
        HELP_MESSAGE
    };
    // opt[2] = {0,0,0,0};

    int opt_ch = 0;

    while((opt_ch = getopt_long(argc, argv, "", opt, NULL)) != -1){
        switch(opt_ch){
            case UNIT_TEST:
                testAllSquareS();
                testAllSwap();
                break;
            case HELP_MESSAGE:
                printHelpM();
                break;
            default:
                break;
        }
    }
    if(optind == 1){
        default_message();
    }
}
