#include <assert.h>

int mul3div4(int x)
{
	int mult = (x << 1) + x;
	return mult >> 2;
}

int main()
{
	assert(mul3div4(12) == 9);
	assert(mul3div4(-12) == -9);

	return 0;
}