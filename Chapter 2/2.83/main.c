// Reference:
// https://dreamanddead.github.io/CSAPP-3e-Solutions/chapter2/2.84/

#include <assert.h>

unsigned f2u(float x)
{
    return *(unsigned*)&x;
}

int float_le(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    /* Give an expression using only ux, uy, sx, and sy */
    return (ux << 1 == 0 && uy << 1 == 0) ||    // Both zeros 
        (sx && !sy) ||                          // z < 0, y >= 0 or x <= 0, y > 0
        (!sx && !sy && ux <= uy) ||             // x > 0, y >= 0 or x >= 0, y > 0
        (sx && sy && ux >= uy);                 // x < 0, y <= 0 or x <= 0, y < 0
}

int main()
{
    assert(float_le(-0, +0));
    assert(float_le(+0, -0));
    assert(float_le(0, 3));
    assert(float_le(-4, -0));
    assert(float_le(-4, 4));
	return 0;
}