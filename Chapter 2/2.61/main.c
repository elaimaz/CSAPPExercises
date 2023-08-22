/* Write C expressions that evaluate to 1 when the followwing conditions are true, and to 0 when
they are false. Assume x of type int.
    A. Any bit of x equals 1.
    B. Any bit of x equals 0.
    C. Any bit in the least significant byte of x equals 1.
    D. Any bit in the most significant byte of x equals 0.
    
Your code should follow the bit-level integer coding rules (page 120) with the additional
restrictions that you may not use equality (==) or inequality (!=) tests. */

#include <stdio.h>

int AnyByteEqualsOne(unsigned x);
int AnyByteEqualsZero(unsigned x);
int LeastSignificantByteEqualsOne(unsigned x);
int MostSignificantByteEqualZero(unsigned x);

int main() {
    unsigned result = AnyByteEqualsOne(0x123456);
    unsigned result2 = AnyByteEqualsZero(0x123456);
    unsigned result3 = LeastSignificantByteEqualsOne(0x123456);
    unsigned result4 = MostSignificantByteEqualZero(0x123456);

    printf("%u", result);
    printf("%u", result2);
    printf("%u", result3);
    printf("%u", result4);
    return 0;
}

int AnyByteEqualsOne(unsigned x) {
    return !!x;
}

int AnyByteEqualsZero(unsigned x) {
    return !!(x ^ 0xff);
}

int LeastSignificantByteEqualsOne(unsigned x) {
    return !!(x & 0x0f);
}

int MostSignificantByteEqualZero(unsigned x) {
    return !!((x & 0xf0) ^ 0xf0);
}
