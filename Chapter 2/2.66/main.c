// Dificulty: ***
// Expected 2 hours

// Write code to implement the following function:
//	//
	// Generate mask indicating leftmost 1 in x. Assume w=32
	// For example 0xFF00 -> 0x8000, and 0x6600 --> 0x4000.
	// If x = 0, then return 0.
//	//

// int leftmost_one(unsigned x);

// Your function should follow the bit-level integer coding rules (page 120), except that you may
// assume that data type int has w = 32 bits.
//	Your code should contain a total of at most 15 arithmetic, bit-wise, and logical operations.

// Hint: First transform x into a bit vector of the form [0...011...1].

// 0xFF00 = 1111 1111 0000 0000 = 65280
// 0x8000 = 1000 0000 0000 0000 = 32768

// 0x6600 = 0110 0110 0000 0000 = 26112
// 0x4000 = 0100 0000 0000 0000 = 16384

// Based on the solution of:
// https://hackmd.io/@B3ogAUE5RP6LiBszkSf0Fg/B1RnrasJz?type=view

#include "stdio.h"

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

int main()
{
	int result = leftmost_one(0x6600);

	printf("%d", result);
}