#ifndef UTILS_H
#define UTILS_H


#include <stddef.h>
#include <stdio.h>


/// @brief calculation error
const double DELTA = 0.00000001;


/**
 * @brief checks if two numbers are equal
 *
 * @param a first number
 * @param b second number
 *
 * @return if a == b: true else: false (if two nambers is NAN it will return false)
*/
bool IsEql(double a, double b);


/**
 * @brief ckecks if two strings are equal
 *
 * @param a first string
 * @param b second string
 *
 * @return if a == b: true else: false
*/
bool IsEql(const char* a,const char* b);


/**
 * @brief checks if number is zero
 *
 * @param n number to check
 *
 * @return if n == 0: true else: false (nan returns false)
*/
bool IsZero(double n);


/**
 * @brief checks if number is finite
 *
 * @param n number to check
 *
 * @return if n is finite: true else: false
*/
bool IsFinite(double n);


/**
 * @brief swaps two given variables
 *
 * @param a pointer to first variable
 * @param b pointer to seond variable
 * @param size byte size of given variables
*/
void SwapBytes(void* a, void* b, size_t size);


/**
 * @brief drops input buffer
*/
void DropBuf();


/**
 * @brief skips input streem until \n or EOF had been reached
 *
 * @param file file that surves as a stream
*/
void FDropBuf(FILE* file);


/**
 * @brief ignores spaces in input buffer
 *
 * @return if buffer consisted only of spaces: 1 else if buffer ends with eof: eof else: 0
*/
int IgnoreSpaces();


/**
 * @brief chechs is given char is space
 *
 * @param ch char to check
 *
 * @return if ch is space: true else: false
*/
bool IsSpace(const char ch);


#endif // UTILS_H
