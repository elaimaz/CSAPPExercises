//Write a C function expression that will yield a word consisting
// of the least significant byte of x, and renaiming bytes of y.
// For operands x = 0x89ABCDEF and y = 0x76543210, this would give 0x765432EF.

#include <stdio.h>

int main() {
    int x = 0x89ABCDEF;
    int y = 0x76543210;

    int result = (x & 0xFF) | (y & ~0xFF);

    printf("%X", result);

    return 0;
}