#include <stdio.h>

#define CACHE_SIZE (64 * 1024)
#define CACHE_BLOCK_SIZE 4

#define PIXELS_PER_BLOCK (CACHE_BLOCK_SIZE / sizeof(pixel))
#define NUMBER_OF_SETS (CACHE_SIZE / CACHE_BLOCK_SIZE)

#define WIDTH 640
#define HEIGHT 480

unsigned int cache[NUMBER_OF_SETS];

typedef struct  {
    char r;
    char g;
    char b;
    char a;
} pixel;

pixel buffer[WIDTH][HEIGHT];

unsigned int misses = 0;

void isInCache(char** addr) {
    //printf("Address: %p\n", addr);
    unsigned long address = (unsigned long)*addr;
    //printf("Address as int: %lu\n", address);
    int block_address = address / CACHE_BLOCK_SIZE;
    int setIndex = block_address % NUMBER_OF_SETS;

    if (cache[setIndex] != block_address) {
        misses++;
        cache[setIndex] = block_address;
    }
}


int main() {
    char *cptr = (char *) buffer;
    for (; cptr < (((char *) buffer) + 640 * 480 * 4); cptr++) {
        *cptr = 0;
        //printf("%d\n", *cptr);
        //printf("%p\n", &cptr);
        isInCache(&cptr);
    }

    unsigned int reads = WIDTH * HEIGHT * 4;

    printf("Reads: %d\n", reads);
    printf("Misses: %d\n", misses);
    printf("Hit: %d\n", reads - misses);
    printf("Miss percentage: %.2f%%\n", misses/(float)reads * 100.0);

    return 1;
}