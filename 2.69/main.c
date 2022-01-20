// Dificulty: ***
// Expected 2 hours

// Write code for a function with the following prototype:

/*
* Do rotating left shift. Assume 0 <= n < w
* Examples when x = 0x12345678 and w = 32:
*	n=4 -> 0x23456781, n=20 ->0x67812345
*/

// unsigned rotate_left(unsigned x, int n);

// Your function should follow the bit-level integer coding rules (page 120). Be careful of the
// case n = 0.

// x   = 0x12345678 =  305419896 =      0001 0010 0011 0100 0101 0110 0111 1000
// n=4 = 0x23456781 = 9468016785 = 0010 0011 0100 0101 0110 0111 1000 1001 0001

// Based on:
// https://www.geeksforgeeks.org/rotate-bits-of-an-integer/

#include "stdio.h"
#include "assert.h"

unsigned rotate_left(unsigned x, int n)
{
	return (x << n) | (x >> (32 - n));
}
													
int main()
{
	assert(rotate_left(0x12345678, 4) == 0x23456781);
	assert(rotate_left(0x12345678, 20) == 0x67812345);
}