#include <stdio.h>
#include <stdint.h>

#define CACHE_SIZE (64 * 1024)
#define CACHE_BLOCK_SIZE 4
#define NUMBER_OF_SETS (CACHE_SIZE / CACHE_BLOCK_SIZE)

#define WIDTH 640
#define HEIGHT 480

unsigned long cache[NUMBER_OF_SETS] = {0};
unsigned int misses = 0;

typedef struct {
    char r;
    char g;
    char b;
    char a;
} pixel;

pixel buffer[HEIGHT][WIDTH];

void isInCache(uintptr_t address) {
    uintptr_t block_address = address / CACHE_BLOCK_SIZE;
    unsigned long setIndex = block_address % NUMBER_OF_SETS;

    if (cache[setIndex] != block_address) {
        misses++;
        cache[setIndex] = block_address;
    }
}

int main() {    
    int *iptr = (int *)buffer;
    for (; iptr < ((int *)buffer + 640*480); iptr++) {
       *iptr = 0;
        isInCache((uintptr_t)iptr);
    }

    unsigned int reads = WIDTH * HEIGHT;
    printf("Reads: %d\n", reads);
    printf("Misses: %d\n", misses);
    printf("Hit: %d\n", reads - misses);
    printf("Miss percentage: %.2f%%\n", misses/(float)reads * 100.0);

    return 0;
}