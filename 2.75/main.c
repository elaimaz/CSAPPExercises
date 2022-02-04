// Based on:
// https://valineliu.gitbook.io/deuterium-wiki/reading/cs-jing-dian-shu-ji/csapp-3e-homework-solution/2.-representing-and-manipulating-information/2.75-unsigned-high-prod

#include<stdio.h>
#include <assert.h>
#include <inttypes.h>

unsigned int unsigned_high_prod(unsigned x, unsigned y)
{
	int sign_x = x >> 31;
	int sign_y = y >> 31;
	int signed_prod = signed_high_prod(x, y);
	return signed_prod + sign_x * y + sign_y * x;
}

int signed_high_prod(int x, int y)
{
	int64_t prod = (int64_t)x * y;
	return prod >> 32;
}

unsigned unsigned_high_prod_for_test(unsigned x, unsigned y)
{
	uint64_t prod = (uint64_t)x * y;
	return prod >> 32;
}

int main()
{
	unsigned x = 0x12345678;
	unsigned y = 0xFFFFFFFF;
	assert(unsigned_high_prod(x, y) == unsigned_high_prod_for_test(x, y));
	return 0;
}