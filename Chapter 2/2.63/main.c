/*
	Fill in code for the following C functions. Function srl performs a logical right shift using
	an arithmetic right shift (given by value xsra), followed by other operations not including
	right shifts or division. Function sra performs an arithmetic right shift using a logical
	right shift (given by the value xsrl), followed by other operations not including right shifts
	or division. You may use the computation 8*sizeof(int) to determine w, the number of bits in
	data type int. The shift amount k can range from 0 to w - 1.
*/

// Based on the resolution of this repo https://github.com/Tomilla/CS-APP2e/blob/master/Solution/Chapter%202/S2HP_2.63.c

#include <stdio.h>

#define W sizeof(int) << 3

unsigned srl(unsigned x, int k)
{
	/* Perform shift arithmetically */
	unsigned xsra = (int)x >> k;

	unsigned mask = (unsigned)~0 >> k;

	return xsra & mask;
}

int sra(int x, int k)
{
	/* Perform shift logically */
	int xsrl = (unsigned)x >> k;
	int sign = x & 1 << (W - 1);
	int mask = ((1 << k) - 1 << (W - k));
	(sign) && (xsrl |= mask);
}

int main()
{
	srl(0xFFFFFFFF, 0xFFFFFF);
	sra(0xFFFFFFFF, 0xFFFFFF);
	return 0;
}