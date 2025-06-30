#include <assert.h>
#include <stdio.h>
#include <x86intrin.h>

#define N 10000

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

void psum1a_enhanced(float a[], float p[], long int n)
{
    long int i;
    /* last_val holds p[i-1]; val holds p[i] */
    float last_val, val;
    last_val = p[0] = a[0];
    for (i = 1; i < n-1; i+=2) {
        val = last_val + a[i];
        p[i] = val;
        
        val += a[i+1];
        p[i+1] = val;
        
        last_val = val;
    }

    if (i < n)
        p[i] = last_val + a[i];
}

void test()
{
    float a[N] = {0};
    float b[N] = {0};
    float c[N] = {0};
    float p[N], ptr[N], cp[N];

    for (int i = 0; i < N; i++) {
        a[i] = N + 1;
        b[i] = a[i];
        c[i] = a[i];
    }

    unsigned long long start, end;
    start = __rdtsc();
    psum1(a, p, N);
    end = __rdtsc();
    printf("psum1 cycles: %llu\n", (end - start)/N);

    start = __rdtsc();
    psum1a(b, ptr, N);
    end = __rdtsc();
    printf("psum1a cycles: %llu\n", (end - start)/N);

    start = __rdtsc();
    psum1a_enhanced(c, cp, N);
    end = __rdtsc();
    printf("psum1a_enhanced cycles: %llu\n", (end - start)/N);

    for (int i = 0; i < N; i++) 
        assert(ptr[i] == cp[i]);
}

int main() 
{
    test();

    return 0;
}