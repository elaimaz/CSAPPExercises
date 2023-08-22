/* Write code to implement the following function: */

/* Return 1 when any odd bit of x equals 1; 0 otherwise. Assume w=32. */

#include <stdio.h>

int any_odd_one(unsigned x)
{
	for (int i = 0; i < 32; i++)
	{
		if ((x & (1 << i)) != 0 && i % 2 != 0)
		{
			return 1;
		}
	}

	return 0;
}

int main()
{
	printf("1 do not have odd one: %d", any_odd_one(1));
	printf("10 does have odd one: %d", any_odd_one(10));
	return 0;
}