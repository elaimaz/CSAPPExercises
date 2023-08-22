// Dificulty: **
// Expected 20 min

// You are given the task of writting a procedure int_size_is_32() that yields 1 when run on a
// machine for which an int is 32 bits and yields 0 otherwise. You are not allowed to use the
// sizeof operator. Here is a first attempt:

//
// /* The following code does not run properly on some machines */
// int bad_int_size_is_32() {
//	/* Set most significant bit (msb) of 32-bit machine */
//	int set_msb = 1 << 31;
//	/* Shift past msb of 32-bit word */
//	int beyond_msb = 1 << 32;
// 
//	/* set_msb is nonzero when word size >= 32 beyond_msb is zero when word size <= 32 */
//	return set_msb && !beyond_msb;
// }
//

// When compiled and run on a 32-bit SUN SPARC, however, this procedure returns 0. The following
// compiler message gives us an indication of the problem:

//	//	Warning: left shift count >= width of type

// A. In what way does our code fail to comply with the C standard?

// B. Modify the code to run properly on any machine for which data type int is at least 32 bits.

// C. Modify the code to run properly on any machine for which data type int is at least 16 bits.

// Answers based on:
// https://valineliu.gitbook.io/deuterium-wiki/reading/cs-jing-dian-shu-ji/csapp-3e-homework-solution/2.-representing-and-manipulating-information/2.67-int-size-is-32

// A - answear.
// If the value of the right operand is negative or is greater than or equal to the width of the
// promoted left operand, the behavior it undefined

#include <stdio.h>

int int_size_is_32()
{
	int set_msb = 1 << 31;
	int beyond_msb = set_msb << 1;
	return set_msb && !beyond_msb;
}

int int_size_is_32_16bits()
{
	int set_msb = 1 << 15 << 15 << 1;
	int beyond_msb = set_msb << 1;
	return set_msb && !beyond_msb;
}

int main()
{
	int Result = int_size_is_32();
	printf("%d", Result);
}
