#ifndef UTILS_H
#define UTILS_H


/// @brief calculation error
const double DELTA = 0.00000001;


/**
 * @brief checks if two numbers are equal
 *
 * @param a first number
 * @param b second number
 *
 * @return if a == b: true else: false
*/
bool is_eql(double a, double b);


/**
 * @brief ckecks if two strings are equal
 *
 * @param a first string
 * @param b second string
 *
 * @return if a == b: true else: false
*/
bool is_eql(const char a[],const char b[]);


/**
 * @brief checks if number is zero
 *
 * @param n number to check
 *
 * @return if n == 0: true else: false
*/
bool is_zero(double n);


/**
 * @brief checks if number is finite
 *
 * @param n number to check
 *
 * @return if n is finite: true else: false
*/
bool is_finite(double n);


/**
 * @brief swaps two given variables
 *
 * @param a pointer to first variable
 * @param b pointer to seond variable
*/
void swapf(void* a, void* b, int size);


#endif // UTILS_H
