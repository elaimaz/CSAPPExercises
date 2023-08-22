#include <stdio.h>
#include <assert.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f) {
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_nam = (exp == 0xFF && frac != 0);
    if (is_nam) {
        return f;
    }

    return ~sig << 31 | exp << 23 | frac;
}

int main() {
    assert(float_negate(0x89) == 0x80000089);
    assert(float_negate(0x89999999) == 0x9999999);
    assert(float_negate(0x7F900000) == 0x7F900000);
    
    return 0;
}