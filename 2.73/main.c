// Based on:
// https://valineliu.gitbook.io/deuterium-wiki/reading/cs-jing-dian-shu-ji/csapp-3e-homework-solution/2.-representing-and-manipulating-information/2.73-saturating-add

#include <stdio.h>
#include <limits.h>
#include <assert.h>

int saturating_add(int x, int y)
{
	int sum = x + y;
	
	int mask = INT_MIN;
	
	int pos_flag = !(x & mask) && !(y & mask) && (sum & mask);
	int neg_flag = (x & mask) && (y & mask) && !(sum & mask);

	(pos_flag && (sum = INT_MAX) || neg_flag && (sum = INT_MIN));

	return sum;
}

int main()
{
	assert(saturating_add(0x80000000, 0x80000000) == INT_MIN);
	assert(saturating_add(0x10, 0x20) == 0x30);
	assert(saturating_add(0x7FFFFFFF, 0x7FFFFFFF) == INT_MAX);

	return 0;
}