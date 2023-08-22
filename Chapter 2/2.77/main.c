// Round fix based on:
// https://valineliu.gitbook.io/deuterium-wiki/reading/cs-jing-dian-shu-ji/csapp-3e-homework-solution/2.-representing-and-manipulating-information/2.78-divide-power-2

#include <assert.h>
#include <limits.h>

int divide_power2(int x, int k)
{
	// Used to fix negative rounding
	int neg_flag = x & INT_MIN;
	neg_flag && (x = x + (1 << k) - 1);
	//

	return x >> k;
}

int main()
{
	assert(divide_power2(5, 1) == 2);
	assert(divide_power2(-5, 1) == -2);

	return 0;
}