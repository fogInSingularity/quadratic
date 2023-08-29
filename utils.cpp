#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

#include "utils.h"

bool IsEql(double a, double b) {
    if (isnan(a) == 1 && isnan(b) == 1) {
        return true;
    } else if (isnan(a) + isnan(b) == 1) {
        return false;
    } else {
        return abs(a - b) < DELTA;
    }
}

bool IsEql(const char a[],const char b[]) {
    const char* aMove = a;
    const char* bMove = b;
    while (*aMove != '\0' || *bMove != '\0') {
        if (*aMove != *bMove) {
            return false;
        }
        aMove++;
        bMove++;
    }
    if (*aMove != *bMove) {
        return false;
    } else {
        return true;
    }
}

bool IsZero(double n) {
    if (isnan(n)) {
        return false;
    } else {
        return abs(n) < DELTA;
    }
}

bool IsFinite(double n) {
    return (isnan(n) != true) && (n > -INFINITY) && (n < INFINITY);
}

void SwapBytes(void* a, void* b, size_t size) {
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

void DropBuf() {
    int ch = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

void FDropBuf(FILE* file) {
    assert(file != NULL);
    int ch = 0;

    while ((ch = fgetc(file)) != '\n' && ch != EOF) {}
}

int IgnoreSpaces() {
    int ch = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (!IsSpace((char)ch))
            return 0;
    }

    if (ch == EOF)
        return EOF;

    return 1;
}

bool IsSpace(const char ch) {
    return ch == ' ' ? true : false;
}
