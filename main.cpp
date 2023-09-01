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

/// @brief enum for holding program mode
enum OptinonsMap {
    HELP_M  = 0, ///< print help message
    CLI_M   = 1, ///< use command line options as input source
    FILE_M  = 2, ///< use file as input source
    STDIN_M = 3, ///< use stdin as input source
};

int main(int argc,const char** argv) {
#ifdef _TEST
    TestAllSquareS();
    TestAllSwap();

#else
    Option optArr[] = {{"help"        , 'h' , &Help        , false, 0, nullptr},
                       {"command-line", 'c' , &DefaultCli  , false, 0, nullptr},
                       {"file"        , 'f' , &DefaultFile , false, 0, nullptr},
                       {"stdin"       , 's' , &DefaultStdio, false, 0, nullptr},
                       {nullptr       , '\0', nullptr      , false, 0, nullptr}}; // stop option

    Getopt(argc, argv, optArr);

    void (*funcToExec)(Option*) = &DefaultStdio;

    if (optArr[HELP_M].seen) {
        funcToExec = optArr[HELP_M].func;
    } else if (optArr[STDIN_M].seen) {
        funcToExec = optArr[STDIN_M].func;
    } else if (optArr[CLI_M].seen) {
        funcToExec = optArr[CLI_M].func;
    } else if (optArr[FILE_M].seen) {
        funcToExec = optArr[FILE_M].func;
    }

    if (funcToExec != nullptr) {
        (*funcToExec)(optArr);
    } else {
        printf("use ./quadratic --help\n");
    }

    FreeOpt(optArr);
#endif // _DEBUG

    return 0;
}
