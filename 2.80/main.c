// literally copied from because i did not understand =( :
// https://github.com/agelessman/csapp-3e-solutions/blob/master/%E7%AC%AC%E4%BA%8C%E7%AB%A0%E7%AD%94%E6%A1%88/2.81.c

#include <stdio.h>
#include <assert.h>
#include <limits.h>

int A(int k)
{
    return -1 << k;
}

int B(int k, int j)
{
    return ~A(k) << j;
}


int main(int argc, char* argv[])
{
    assert(A(8) == 0xFFFFFF00);
    assert(B(16, 8) == 0x00FFFF00);

    printf("%d", -INT_MIN);
    return 0;
}