// Solution based on: https://dreamanddead.github.io/CSAPP-3e-Solutions/chapter2/2.94/

#include <stdio.h>
#include <assert.h>

typedef unsigned float_bits;

float_bits float_twice(float_bits f) {
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_nam = (exp == 0xFF && frac != 0);
    if (is_nam) {
        return f;
    }

    if (exp == 0) {
        // Denormalized
        frac <<= 1;
    } else if (exp == 0xFF - 1) {
        // twice to oo
        exp = 0xFF;
        frac = 0;
    } else {
        // Normalized
        exp += 1;
    }

    return sig << 31 | exp << 23 | frac;
}

int main() {
    assert(float_twice(0x03F800000) == 0x040000000);
    assert(float_twice(0x03FC00000) == 0x040400000);
    assert(float_twice(0x03F99999A) == 0x04019999A);
    
    return 0;
}