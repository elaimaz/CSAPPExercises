#include <assert.h>

int A(int x, int y)
{
	return (x < y) == (-x > -y);
}

int B(int x, int y)
{
	return ((x + y) << 4) + y - x == 17 * y + 15 * x;
}

int C(int x, int y)
{
	return -x + -y + 1 == -(x + y);
}

int D(int x, int y)
{
	unsigned ux = (unsigned)x;
	unsigned uy = (unsigned)y;
	return (ux - uy) == -(unsigned)(y - x);
}

int E(int x)
{
	return ((x >> 2) << 2) <= x;
}

int main()
{
	assert(C(0, 0) == 1);
	
	return 0;
}