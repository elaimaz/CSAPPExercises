/*
	Fill in code for the following C functions. Function srl performs a logical right shift using 
	an arithmetic right shift (given by value xsra), followed by other operations not including
	right shifts or division. Function sra performs an arithmetic right shift using a logical
	right shift (given by the value xsrl), followed by other operations not including right shifts
	or division. You may use the computation 8*sizeof(int) to determine w, the number of bits in
	data type int. The shift amount k can range from 0 to w - 1.
*/

#include <stdio.h>

void printBits(size_t const size, void const * const ptr)
{
	unsigned char* b = (unsigned char*)ptr;
	unsigned char byte;

	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = 7; j >= 0; j--)
		{
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
	}
	puts("");
}

unsigned srl(unsigned x, int k)
{
	printf("Starting srl");
	printf("\nunsigned x: ");
	printBits(sizeof(x), &x);
	printf("\nint k: ");
	printBits(sizeof(k), &k);
	/* Perform shift arithmetically */
	unsigned xsra = (int)x >> k;

	printf("\nxsra: ");
	printBits(sizeof(xsra), &xsra);
}

int sra(int x, int k)
{
	/* Perform shift logically */
	int xsrl = (unsigned)x >> k;
}

int main()
{
	srl(4, 2);
	return 0;
}