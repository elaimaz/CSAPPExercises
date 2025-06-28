#include <stdio.h>
#include <assert.h>
#include <time.h>

#define DEGREE 30
#define X 2

typedef unsigned int TYPE;

typedef struct {
    clock_t start;
    clock_t end;
} timer;

void timer_start(timer *t)
{
    t->start = clock();
}

double timer_end(timer *t)
{
    t->end = clock();
    return (double)(t->end - t->start) / CLOCKS_PER_SEC;
}

TYPE polyh(TYPE a[], TYPE x, int degree)
{
    int i;
    TYPE result = a[degree];
    for (i = degree-1; i >= 0; i--)
        result = a[i] + x*result;
    return result;
}

TYPE polyh_enhanced(TYPE a[], TYPE x, int degree)
{
    TYPE result = 0, result1 = 0;

    if ((degree + 1) % 2 != 0) {
        result = a[degree];
        degree--;
    }

    for (; degree > 0; degree -= 2){
        result = a[degree] + x*result;
        result1 = a[degree - 1] + x*result;
        result = result1;
    }

    if (degree == 0)
        result = a[degree] + x*result;

    return result;
}

void test()
{
    TYPE a[DEGREE];

    for (int i = 0; i < DEGREE; i++)
        a[i] = (TYPE)i + 1;

    timer t1, t2;

    timer_start(&t1);
    TYPE result = polyh(a, X, DEGREE - 1);
    double time_polyh = timer_end(&t1);
    printf("Time taken by polyh: %f seconds\n", time_polyh);

    timer_start(&t2);
    TYPE result_enhanced = polyh_enhanced(a, X, DEGREE - 1);
    double time_polyh_enhanced = timer_end(&t2);
    printf("Time taken by polyh_enhanced: %f seconds\n", time_polyh_enhanced);

    assert(result == result_enhanced);
}

int main(void)
{
    test();
    
    return 0;
}
