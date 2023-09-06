#ifndef GETOPT_H
#define GETOPT_H

#include <stddef.h>

/// @brief holds options data
struct Option {
    const char* longName;         ///< long option without --
    char shortName;               ///< short option without -
    int (*func) (Option* option);///< option func
    bool seen;                    ///< is option had been seen in given options (should be init with false)
    size_t nArgs;                 ///< how many args had been given (should be init with 0)
    char** data;                  ///< holds array of strings (should be init with nullptr)
};


/**
 * @brief parse option given to program and fill option array
 *
 * @param argc number of options given to program
 * @param argv options given to program
 * @param option Option array
*/
void Getopt(int argc, const char** argv, Option* options);


/**
 * @brief parse long option
 *
 * @param opts sting to parse
 * @param options Option array
*/
void ParseLong(const char* opts, Option* options);


/**
 * @brief parse short option
 *
 * @param opts string to parse
 * @param options Option array
*/
void ParseShort(const char* opts, Option* options);


/**
 * @brief parse args of option
 *
 * @param pos args to parse (should be started at '=')
 * @param option option to parse
*/
void ParseArgs(const char* pos, Option* option);


/**
 * @brief check when to stop option iteration
 *
 * @param option option to check
 *
 * @return if option is null-term: true else: false
*/
bool Stop(Option* option);


/**
 * @brief copy string [begin, end) to dest
 *
 * @param dest where to copy
 * @param begin start of sting (included)
 * @param end end of string (not included)
*/
void Strcpy(char* dest, const char* begin, const char* end);


/**
 * @brief free all memory used by getopt
 *
 * @param option Option array to free
*/
void FreeOpt(Option* option);


/**
 * @brief prints information about each option (used for debug purposes)
 *
 * @param option Option array
*/
void PrintOpt(Option* option);


#endif // GETOPT_H
