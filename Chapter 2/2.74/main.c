// Based on:
// https://valineliu.gitbook.io/deuterium-wiki/reading/cs-jing-dian-shu-ji/csapp-3e-homework-solution/2.-representing-and-manipulating-information/2.74-sub-ok

#include <stdio.h>
#include <assert.h>
#include <limits.h>

int tsub_ok(int x, int y)
{
	int sub = x - y;

	int pos_flag = x >= 0 && y < 0 && sub < 0;
	int neg_flag = x < 0 && y >= 0 && sub >= 0;

	return !pos_flag && !neg_flag;
}

int main()
{
	assert(!tsub_ok(INT_MIN, 1));
	assert(!tsub_ok(INT_MAX, -1));
	assert(tsub_ok(0, 0));
	assert(tsub_ok(666, 9));

	return 0;
}