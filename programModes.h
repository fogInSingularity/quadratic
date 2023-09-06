#ifndef PROGRAM_MODES_H
#define PROGRAM_MODES_H

#include "getopt.h"


enum ProgramState{
    SUCCESS = 0,
    CLI_ERROR = 1,
    FILE_ERROR_CANT_OPEN = 2,
    FILE_ERROR_WRONG_DATA = 3,
};


/**
 * @brief help mode that prints help information to user
 *
 * @param option Option with parsed options
 *
 * @return Program state
*/
int Help(Option* option);


/**
 * @brief standart mode to solve equation
 *
 * @param option Option with parsed options
 *
 * @return Program state
*/
int DefaultStdio(Option* option);


/**
 * @brief cli mode to solve equation
 *
 * @param option Option with parsed options
 *
 * @return Program state
*/
int DefaultCli(Option* option);


/**
 * @brief file mode to solve equation
 *
 * @param option Option with parsed options
 *
 * @return Program state
*/
int DefaultFile(Option* option);

/**
 * @brief parse coefs for cli mode
 *
 * @param coef where to store coef
 * @param data string that contains coef
 *
 * @return if data containes nans: CLI_ERROR else: SUCCESS
*/
int ParseCoef(double* coef,const char* data);


#endif // PROGRAM_MODES_H
