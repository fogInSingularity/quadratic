#ifndef PROGRAM_MODES_H
#define PROGRAM_MODES_H

#include "getopt.h"

/**
 * @brief help mode that prints help information to user
*/
void Help(Option* option);


/**
 * @brief standart mode to solve equation
*/
void DefaultStdio(Option* option);


/**
 * @brief cli mode to solve equation
*/
void DefaultCli(Option* option);


/**
 * @brief file mode to solve equation
*/
void DefaultFile(Option* option);


#endif // PROGRAM_MODES_H
