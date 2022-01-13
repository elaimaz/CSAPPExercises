// Dificulty: **
// Expected 20 min

// Write code for a function with the following prototype:

//
//	Mask with least significant n bits set to 1
//	Examples: n = 6 ---> 0x3F, n = 17 --> 0x1FFFF
//	Assume 1 <= n <= w
//

// int lower_one_mask(int n);

// Your function should follow the bit level integer coding rules (page 120). Be careful of the
// case n = w.

// n = 6  = 0000 0110 = 0x06 => 0x3F    = 0000 0000 0000 0011 1111 = 63
// n = 17 = 0001 0001 = 0x11 => 0x1FFFF = 0001 1111 1111 1111 1111 = 131071

#include "stdio.h"
#include "assert.h"
#include "limits.h"

int lower_one_mask(int n)
{
	return ~((n | ~n) << n);
}

int main()
{
	assert(lower_one_mask(6) == 63);
	assert(lower_one_mask(17) == 131071);
	assert(lower_one_mask(INT_MAX) == INT_MAX);

	return 0;
}