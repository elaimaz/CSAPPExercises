#include <stdio.h>
#include <assert.h>

typedef unsigned float_bits;

float_bits float_f2i(float_bits f) {
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_nam = (exp == 0xFF && frac != 0);
    if (is_nam) {
        return 0x80000000;
    }

    // if (exp == 0) {
    //     // Denormalized
    //     frac >>= 1;
    // } else if (exp == 0xFF - 1) {
    //     // twice to oo
    //     exp = 0xFF;
    //     frac = 0;
    // } else {
    //     // Normalized
    //     exp -= 1;
    // }

    // return sig << 31 | exp << 23 | frac;
}

int main() {
    // assert(float_f2i(0x40000000) == 0x3F800000);
    // assert(float_f2i(0x40A00000) == 0x40200000);
    // assert(float_f2i(0x40200000) == 0x3fA00000);
    
    return 0;
}