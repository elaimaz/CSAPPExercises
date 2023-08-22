// Based on:
// https://github.com/agelessman/csapp-3e-solutions/blob/master/%E7%AC%AC%E4%BA%8C%E7%AB%A0%E7%AD%94%E6%A1%88/2.80.c

#include <limits.h>
#include <assert.h>

int threefourths(int x)
{
	int is_neg = x & INT_MIN;

	int f = x & ~0x3;
	int l = x & 0x3;

	int fd4 = f >> 2;
	int fd4m3 = (fd4 << 1) + fd4;

	int lm3 = (l << 1) + l;
	int bias = (1 << 1) + 1;
	(is_neg && (lm3 += bias));
	int lm3d4 = lm3 >> 2;

	return fd4m3 + lm3d4;
}

int main()
{
	assert(threefourths(8) == 6);
	assert(threefourths(-8) == -6);

	return 0;
}