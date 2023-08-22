#define _USE_MATH_DEFINES

#include <stdint.h>
#include <stdio.h>
#include <math.h>


typedef union v32_union {
	float f;
	uint32_t u;
} v32;

typedef union v64_union {
	double f;
	uint64_t u;
} v64;

void print_float_bits (float f) {
	v32 v; v.f = f;
	uint32_t mask = 1 << 31;
	do {
		if (mask == 0x40000000 || mask == 0x400000) putchar(' ');
		putchar(v.u & mask ? '1' : '0');
	} while (mask >>= 1);
}

int main(void) {
	float pi = M_PI;

	print_float_bits(22/7); /* 0 10000000 10010010000111111011010 */
	putchar('\n');
	print_float_bits(223/71); /* 0 10000000000 1001001000011111101101010100010001000010110100011000 */
	putchar('\n');
	print_float_bits(pi);
}