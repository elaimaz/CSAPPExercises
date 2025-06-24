#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>

#define BUFFER_SIZE 1000000

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

/* Basic implementation of memset */
void *basic_memset(void *s, int c, size_t n)
{
    size_t cnt = 0;
    unsigned char *schar = s;
    while (cnt < n) {
        *schar++ = (unsigned char) c;
        cnt++;
    }

    return s;
}

void *enhanced_memset(void *s, int c, size_t n)
{
    if (n == 0)
        return s; // No operation if n is zero

    size_t i;
    if (n < 8 && n >= 4) {
        for(i = 0; i < n - 3; i += 4) {
            ((unsigned char *)s)[i] = (unsigned char)c;
            ((unsigned char *)s)[i + 1] = (unsigned char)c;
            ((unsigned char *)s)[i + 2] = (unsigned char)c;
            ((unsigned char *)s)[i + 3] = (unsigned char)c;
        }
    } else if (n > 8) {
        for(i = 0; i < n - 7; i += 8) {
            ((unsigned char *)s)[i] = (unsigned char)c;
            ((unsigned char *)s)[i + 1] = (unsigned char)c;
            ((unsigned char *)s)[i + 2] = (unsigned char)c;
            ((unsigned char *)s)[i + 3] = (unsigned char)c;
            ((unsigned char *)s)[i + 4] = (unsigned char)c;
            ((unsigned char *)s)[i + 5] = (unsigned char)c;
            ((unsigned char *)s)[i + 6] = (unsigned char)c;
            ((unsigned char *)s)[i + 7] = (unsigned char)c;

        }
    }

    for( ; i < n; i++) {
        ((unsigned char *)s)[i] = (unsigned char)c;
    }

    return s;
}

void test_memset()
{
    char buffer[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];

    timer t1, t2;
    
    // Test basic_memset
    timer_start(&t1);
    basic_memset(buffer, 0, BUFFER_SIZE);
    double time_basic = timer_end(&t1);
    printf("Time taken by basic_memset: %f seconds\n", time_basic);

    // Test enhanced_memset
    timer_start(&t2);
    enhanced_memset(buffer2, 0, BUFFER_SIZE);
    double time_enhanced = timer_end(&t2);
    printf("Time taken by enhanced_memset: %f seconds\n", time_enhanced);

    for (int i = 0; i < BUFFER_SIZE; i++) {
        assert(buffer[i] == 0 && buffer2[i] == 0);
    }
}

int main()
{
    test_memset();

    return 0;
}