#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

#include "utils.h"

bool IsEql(double a, double b) {
    return abs(a - b) < DELTA;
}

bool IsEql(const char a[],const char b[]) {
    int size_a = 0;
    int size_b = 0;
    while (a[size_a] != '\0')
        size_a++;
    while (b[size_b] != '\0')
        size_b++;
    if (size_a != size_b)
        return false;

    int i = 0;
    int j = 0;
    for (; a[i] != '\0' && b[i] != '\0'; i++) {
        if (a[i] == b[i])
            j++;
    }

    return (i == j) ? true : false;
}

bool IsZero(double n) {
    return abs(n) < DELTA;
}

bool IsFinite(double n) {
    return (isnan(n) != true) && (n > -INFINITY) && (n < INFINITY);
}

void SwapB(void* a, void* b, size_t size) {
    assert(a != b);
    assert(a != NULL);
    assert(b != NULL);

    size_t nFullOps = size >> 3; // колво шагов по 8
    int trailer = size & 0b111; // оставшиеся 7 байт

    uint8_t* aMove = (uint8_t*)a;
    uint8_t* bMove = (uint8_t*)b;
    for (size_t i = 0; i < nFullOps; i++) {
        uint64_t temp = 0;
        memcpy(&temp, aMove, sizeof(uint64_t));
               memcpy(aMove, bMove, sizeof(uint64_t));
                      memcpy(bMove, &temp, sizeof(uint64_t));
        aMove += sizeof(uint64_t);
        bMove += sizeof(uint64_t);
    }

    if (trailer & 0b100) {
        uint32_t temp = 0;
        memcpy(&temp, aMove, sizeof(uint32_t));
               memcpy(aMove, bMove, sizeof(uint32_t));
                      memcpy(bMove, &temp, sizeof(uint32_t));
        aMove += sizeof(uint32_t);
        bMove += sizeof(uint32_t);
    }
    if (trailer & 0b010) {
        uint16_t temp = 0;
        memcpy(&temp, aMove, sizeof(uint16_t));
               memcpy(aMove, bMove, sizeof(uint16_t));
                      memcpy(bMove, &temp, sizeof(uint16_t));
        aMove += sizeof(uint16_t);
        bMove += sizeof(uint16_t);
    }
    if (trailer & 0b001) {
        uint8_t temp = 0;
        memcpy(&temp, aMove, sizeof(uint8_t));
               memcpy(aMove, bMove, sizeof(uint8_t));
                      memcpy(bMove, &temp, sizeof(uint8_t));
    }
}
