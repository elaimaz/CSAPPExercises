#include <stdio.h>
#include <assert.h>

int decode2(int x, int y, int z) {
    y -= z;
    
    z = y; 

    z <<= 31;
    z >>= 31;

    y *= x;

    return y ^ z;
}

int decode2_asm(int x, int y, int z) {
    int eaxValue = 0;

    //Intel syntax
    __asm {
        mov edx, y
        sub edx, z
        mov eax, edx
        sal eax, 31
        sar eax, 31
        imul edx, x
        xor eax, edx
        mov eaxValue, eax
    }

    return eaxValue;
}

int main() {
    assert(decode2(1, 2, 3) == decode2_asm(1, 2, 3));
    assert(decode2(3, 2, 1) == decode2_asm(3, 2, 1));
    assert(decode2(-537, 885, 199) == decode2_asm(-537, 885, 199));

    return 0;
}
