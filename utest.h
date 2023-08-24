#ifndef UTEST_H
#define UTEST_H


/// @brief definition of struct that holds all programmer entered variables
struct Utest {
    double a;         ///< coeff a
    double b;         ///< coeff b
    double c;         ///< coeff c
    double x1ref;     ///< expexted x1
    double x2ref;     ///< expected x2
    NRoots nRootsRef; ///< expected nRootsRef
};


/**
 * @brief tests given Utest
 *
 * @param utest struct that hold variables
 *
 * @return if test passed: true else: false
*/
bool testOne(const Utest* utest);


/**
 * @brief read test from tests.txt that ckecks them
*/
void testAll();


#endif // UTEST_H
