#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

#include "utils.h"

bool IsEql(double a, double b) {
    return abs(a - b) < DELTA;
}

bool IsEql(const char* a,const char* b) {
    assert(a != nullptr);
    assert(b != nullptr);

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
    return abs(n) < DELTA;
}

bool IsFinite(double n) {
    return (isnan(n) != true) && (n > -INFINITY) && (n < INFINITY);
}

void SwapBytes(void* a, void* b, size_t size) {
    assert(a != b);
    assert(a != NULL);
    assert(b != NULL);

    int step = sizeof(uint64_t); // шаг
    int bits_remained = size; // сколько байт осталось не обработано
    for(int curnt_pos = 0; curnt_pos < size; curnt_pos += step) {
        while(bits_remained < step) {
            step >>= 1;
        }
        if(step == sizeof(uint64_t)) {
            uint64_t temp = *(uint64_t*)((uint8_t*)a + curnt_pos);
                            *(uint64_t*)((uint8_t*)a + curnt_pos) = *(uint64_t*)((uint8_t*)b + curnt_pos);
                                                                    *(uint64_t*)((uint8_t*)b + curnt_pos) = temp;
            bits_remained -= step;
        } else if(step == sizeof(uint32_t)) {
            uint32_t temp = *(uint32_t*)((uint8_t*)a + curnt_pos);
                            *(uint32_t*)((uint8_t*)a + curnt_pos) = *(uint32_t*)((uint8_t*)b + curnt_pos);
                                                                    *(uint32_t*)((uint8_t*)b + curnt_pos) = temp;
            bits_remained -= step;
        } else if(step == sizeof(uint16_t)) {
            uint16_t temp = *(uint16_t*)((uint8_t*)a + curnt_pos);
                            *(uint16_t*)((uint8_t*)a + curnt_pos) = *(uint16_t*)((uint8_t*)b + curnt_pos);
                                                                    *(uint16_t*)((uint8_t*)b + curnt_pos) = temp;
            bits_remained -= step;
        } else {
            uint8_t temp = *((uint8_t*)a + curnt_pos);
                           *((uint8_t*)a + curnt_pos) = *((uint8_t*)b + curnt_pos);
                                                        *((uint8_t*)b + curnt_pos) = temp;
        }
    }
}


void DropBuf() {
    int ch = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

void FDropBuf(FILE* file) {
    assert(file != nullptr);

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
    return ch == ' ';
}
