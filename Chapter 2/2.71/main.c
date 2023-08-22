#include <stdio.h>
#include <assert.h>

typedef unsigned packet_t;

int xbyte(packet_t word, int bytenum)
{
	int maxBytenum = 3;
	return (int)word << ((maxBytenum - bytenum) << 3) >> (maxBytenum << 3);
}

int main()
{
	assert(xbyte(0x00112233, 0) == 0x33);

	assert(xbyte(0xAABBCCDD, 0) == 0xFFFFFFDD);

	return 0;
}