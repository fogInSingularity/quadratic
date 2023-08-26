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
bool IsEql(double a, double b);


/**
 * @brief ckecks if two strings are equal
 *
 * @param a first string
 * @param b second string
 *
 * @return if a == b: true else: false
*/
bool IsEql(const char a[],const char b[]);


/**
 * @brief checks if number is zero
 *
 * @param n number to check
 *
 * @return if n == 0: true else: false
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
void SwapBits(void* a, void* b, size_t size);


#endif // UTILS_H
