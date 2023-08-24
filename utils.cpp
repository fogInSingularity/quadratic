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

void swapf(void* a, void* b, int size) {
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
