#include <stdio.h>
#include <math.h>
#include <assert.h>

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
    ProgramMode programMode = DEFAULT;
    for(int i = 1; i < argc; i++) {
        if(is_eql(argv[i], "--test")) {
            programMode = UNIT_TEST;
        }
        if(is_eql(argv[i], "--help")) {
            programMode = HELP_MESSAGE;
        }
    }

    switch(programMode) {
        case DEFAULT:
            default_message();
            return 0;
            break;
        case UNIT_TEST:
            testAll();
            return 0;
            break;
        case HELP_MESSAGE:
            printHelpM();
            return 0;
            break;
        default:
            printf("! unknown program mode\n");
            return 0;
            break;
    }
}