#include <stdio.h>
#include <assert.h>

typedef unsigned float_bits;

int leftmost_one(unsigned x)
{
	// This will move the bits to the right keeping the most significant
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 16;

	// Set all bits to 0 except the most significant
	return x & ~(x >> 1);
}

unsigned SetHighestBitToZero(unsigned originalValue)
{
    unsigned mask = originalValue;

    mask |= mask >> 1;
    mask |= mask >> 2;
    mask |= mask >> 4;
    mask |= mask >> 8;
    mask |= mask >> 16;

    mask = mask >> 1;

    return originalValue & mask;
}

float_bits float_i2f(int i) {
    if (i == 0) {
        return i;
    }

    unsigned sig = i >> 31;
    if (sig)
    {
        i = ~i + 1;
    }

    unsigned bias = 0x7F;
    unsigned integer_value = i & 0x7FFFFFFF;
    unsigned leftmostOne = leftmost_one(integer_value);

    unsigned bitPosValue = 1;
    char position = 0;
    while(leftmostOne != bitPosValue) {
        bitPosValue = bitPosValue << 1;
        position++;
    }

    unsigned expValue = bias + position;
    unsigned fracValue = SetHighestBitToZero(integer_value);

    return sig << 31 | expValue << 23 | fracValue << (23 - position);
}

int main() {
    assert(float_i2f(0xA) == 0x41200000);
    assert(float_i2f(250) == 0x437A0000);
    assert(float_i2f(-10) == 0xC1200000);
    assert(float_i2f(0x1) == 0x3F800000);
    
  return 0;
}