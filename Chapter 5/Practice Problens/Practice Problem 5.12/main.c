#include <assert.h>

void psum1(float a[], float p[], long int n)
{
    long int i;
    p[0] = a[0];
    for (i = 1; i < n; i++)
        p[i] = p[i-1] + a[i];
}

void psum1a(float a[], float p[], long int n)
{
    long int i;
    /* last_val holds p[i-1]; val holds p[i] */
    float last_val, val;
    last_val = p[0] = a[0];
    for (i = 1; i < n; i++) {
        val = last_val + a[i];
        p[i] = val;
        last_val = val;
    }
}

int main() 
{
    float a[] = { 1, 2, 3, 4, 5};
    float b[] = { 1, 2, 3, 4, 5};
    float p[5], ptr[5];

    psum1(a, p, 5);
    psum1a(b, ptr, 5);

    for (int i = 0; i < 5; i++) 
        assert(p[i] == ptr[i]);

    return 0;
}