#include <stdio.h>
#include <math.h>
#include <assert.h>

void swapf(double* a, double* b);
int is_eql(double a, double b);
int is_eql(const char a[],const char b[]);
int is_zero(double n);
int is_finite(double n);

/// @brief calculation error
const double DELTA = 0.00000001;

/**
 * @brief swaps two given variables
 * 
 * @param a pointer to first variable
 * @param b pointer to seond variable
*/
void swapf(double* a, double* b){
    assert(a != b);
    assert(a == NULL);
    assert(b == NULL);
    double t = *a;
          *a = *b;
          *b =  t;
}

/**
 * @brief checks if two numbers are equal
 * 
 * @param a first number
 * @param b second number
 * 
 * @return if a == b: 1 else: 0
*/
int is_eql(double a, double b) {
    return abs(a - b) < DELTA;
}

/**
 * @brief ckecks if two strings are equal
 * 
 * @param a first string
 * @param b second string
 * 
 * @return if a == b: 1 else: 0
*/
int is_eql(const char a[],const char b[]){
    int size_a = 0;
    int size_b = 0;
    while(a[size_a] != '\0')
        size_a++;
    while(b[size_b] != '\0')
        size_b++;
    if(size_a != size_b)
        return 0;

    int i = 0;
    int j = 0;
    for(; a[i] != '\0' && b[i] != '\0'; i++){
        if(a[i] == b[i])
            j++;
    }

    return (i == j) ? 1 : 0;
}

/**
 * @brief checks if number is zero
 * 
 * @param n number to check
 * 
 * @return if n == 0: 1 else: 0
*/
int is_zero(double n) {
    return abs(n) < DELTA;
}

/**
 * @brief checks if number is finite
 * 
 * @param n number to check
 * 
 * @return if n is finite: 1 else: 0
*/
int is_finite(double n) {
    return (isnan(n) != 1) && (n > -INFINITY) && (n < INFINITY);
}