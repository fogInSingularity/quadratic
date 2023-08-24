#ifndef UTEST_H
#define UTEST_H


/// @brief definition of struct that holds all programmer entered variables for square test
struct SquareSTest {
    double a;         ///< coeff a
    double b;         ///< coeff b
    double c;         ///< coeff c
    double x1ref;     ///< expexted x1
    double x2ref;     ///< expected x2
    NRoots nRootsRef; ///< expected nRootsRef
};


/**
 * @brief tests given SquareStest
 *
 * @param test struct that hold variables
 *
 * @return if test passed: true else: false
*/
bool testOneSquareS(const SquareSTest* test);


/**
 * @brief read tests for squareSolver() from tests.txt that ckecks them
*/
void testAllSquareS();

/// @brief definition of struct that holds all programmer entered variables for swap test
struct SwapTest {
    const char* str1;
    const char* str2;
};


/**
 * @brief tests given SwaoTest
 *
 * @param test struct that hold variables
 *
 * @return if test passed: true else: false
*/
bool testOneSwap(const SwapTest* test);


/**
 * @brief tests all defined tests of swap()
*/
void testAllSwap();


#endif // UTEST_H
