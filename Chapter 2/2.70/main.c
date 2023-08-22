// Solution based on:
// https://dreamanddead.github.io/CSAPP-3e-Solutions/chapter2/2.70/

#include <stdio.h>
#include <assert.h>

int fits_bits(int x, int n)
{
	int w = sizeof(int) << 3;
	int offset = w - n;
	return (x << offset >> offset) == x;
}

int main()
{
	assert(fits_bits(4, 4));
	assert(!fits_bits(4, 2));

	return 0;
}
