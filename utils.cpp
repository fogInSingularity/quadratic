#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>

#include "utils.h"

bool is_eql(double a, double b) {
    return abs(a - b) < DELTA;
}

bool is_eql(const char a[],const char b[]) {
    int size_a = 0;
    int size_b = 0;
    while(a[size_a] != '\0')
        size_a++;
    while(b[size_b] != '\0')
        size_b++;
    if(size_a != size_b)
        return false;

    int i = 0;
    int j = 0;
    for(; a[i] != '\0' && b[i] != '\0'; i++) {
        if(a[i] == b[i])
            j++;
    }

    return (i == j) ? true : false;
}

bool is_zero(double n) {
    return abs(n) < DELTA;
}

bool is_finite(double n) {
    return (isnan(n) != true) && (n > -INFINITY) && (n < INFINITY);
}

void swapf(void* a, void* b, size_t size) {
    assert(a != b);
    assert(a != NULL);
    assert(b != NULL);

    size_t nFullOps = size >> 3; // колво шагов по 8
    int trailer = size & 0b111; // оставшиеся 7 байт

    for(size_t i = 0; i < nFullOps; i++) {
        uint64_t temp = *(uint64_t*)((uint8_t*)a + i*sizeof(uint64_t));
                        *(uint64_t*)((uint8_t*)a + i*sizeof(uint64_t)) = *(uint64_t*)((uint8_t*)b + i*sizeof(uint64_t));
                                                                         *(uint64_t*)((uint8_t*)b + i*sizeof(uint64_t)) = temp;
    }

    size_t basePos = nFullOps * sizeof(uint64_t);
    if(trailer & 0b100) {
        uint32_t temp = *(uint32_t*)((uint8_t*)a + basePos);
                        *(uint32_t*)((uint8_t*)a + basePos) = *(uint32_t*)((uint8_t*)b + basePos);
                                                              *(uint32_t*)((uint8_t*)b + basePos) = temp;
        basePos += sizeof(uint32_t);
    }
    if(trailer & 0b010) {
        uint16_t temp = *(uint16_t*)((uint8_t*)a + basePos);
                        *(uint16_t*)((uint8_t*)a + basePos) = *(uint16_t*)((uint8_t*)b + basePos);
                                                              *(uint16_t*)((uint8_t*)b + basePos) = temp;
        basePos += sizeof(uint16_t);
    }
    if(trailer & 0b001) {
        uint8_t temp = *((uint8_t*)a + basePos);
                       *((uint8_t*)a + basePos) = *((uint8_t*)b + basePos);
                                                  *((uint8_t*)b + basePos) = temp;
    }
}
