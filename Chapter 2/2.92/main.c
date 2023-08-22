#include <stdio.h>
#include <assert.h>

typedef unsigned float_bits;

float_bits float_absval(float_bits f) {
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_nam = (exp == 0xFF && frac != 0);
    if (is_nam) {
        return f;
    }

    return 0 << 31 | exp << 23 | frac;
}

int main() {
    assert(float_absval(0x89) == 0x89);
    assert(float_absval(0x89999999) == 0x9999999);
    assert(float_absval(0x7F900000) == 0x7F900000);
    
    return 0;
}