#include <stdio.h>
#include <assert.h>

typedef unsigned float_bits;

int float_f2i(float_bits f) {
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_nam = (exp == 0xFF && frac != 0);
    if (is_nam) {
        return 0x80000000;
    }

    if (exp == 0) {
        return 0;
    } else if ((exp == 0xFF || exp == 0xFE) && frac == 0) {
        return 0x80000000; 
    } 
    
    int E = exp - 127;
    if (E < 0) {
        return 0;
    }

    float M = 0;
    unsigned int mantissaPos = 0;
    for (int i = 22; i >= 0; i--) {
        int bit = (frac >> i) & 1;
        mantissaPos++;
        
        if (bit == 1) {
            M += (float)1 / (1 << mantissaPos);
        }
    }
    M += 1;

    int intValue = M * (2 << (E - 1));

    return sig ? -intValue : intValue;
}

int main() {
    assert(float_f2i(0x42E1999A) == 112);
    assert(float_f2i(0xC2E1999A) == -112);
    assert(float_f2i(0x3F000000) == 0);
    assert(float_f2i(0xBF000000) == 0);
    
    return 0;
}