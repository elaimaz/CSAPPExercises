#include <assert.h>

/* Swap value x at xp with value y at yp */
void swap(int *xp, int *yp)
{
    *xp = *xp + *yp;    /* x+y */
    *yp = *xp - *yp;    /* x+y-y = x */
    *xp = *xp - *yp;    /* x+y-x = y */
}

void test()
{
    int x = 2;
    int *y = &x;

    swap(&x, y);
    assert(x == *y);
    assert(x == 0);
    assert(*y == 0);

    x = 2;
    int z = 2;

    swap(&x, &z);
    assert(x == z);
    assert(x != 0);
    assert(z != 0);

    x = 2;
    z = 4;
    y = &z;
    swap(&x, y);
    assert(x != *y);
    assert(x != 0);
    assert(y != 0);
}

int main()
{
    test();

    return 0;
}
