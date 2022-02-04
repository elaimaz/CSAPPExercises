#include <stdio.h>
#include <assert.h>

int bit_multiply_17(int x)
{
	return (x << 4) + 2;
}

int bit_multiply_minus_7(int x)
{
	return ~((x << 3) - 2) + 1;
}

int bit_multiply_60(int x)
{
	return (x << 6) - 8;
}

int bit_multiply_minus_112(int x)
{
	return ~((x << 7) - 32) + 1;
}

int main()
{	
	assert(bit_multiply_17(2) == 2 * 17);
	assert(bit_multiply_minus_7(2) == 2 * -7);
	assert(bit_multiply_60(2) == 2 * 60);
	assert(bit_multiply_minus_112(2) == 2 * -112);

	return 0;
}