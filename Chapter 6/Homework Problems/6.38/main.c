#include <stdio.h>

#define CACHE_SIZE (1024 * 4) // 4KB
#define CACHE_BLOCK_SIZE 16   // 16 Bytes
#define STARTING_ADDRESS 0x08000000

#define INTERGERS_PER_BLOCK (CACHE_BLOCK_SIZE / sizeof(int)) // Assuming 4 bytes per int
#define NUMBER_OF_SETS (CACHE_SIZE / CACHE_BLOCK_SIZE)

#define N 64

int cache[NUMBER_OF_SETS][INTERGERS_PER_BLOCK];

typedef int array_t[N][N];

int misses = 0;

int isInCache(int line, int column) {
    int address = STARTING_ADDRESS + (line * N + column) * sizeof(int);
    int setIndex = (address / CACHE_BLOCK_SIZE) % NUMBER_OF_SETS; // Assuming 4 bytes per int
    for (int i = 0; i < INTERGERS_PER_BLOCK; i++) {
        if (cache[setIndex][i] == address) {
            return 1;
        }
    }

    //cache miss, load into cache
    for (int i = 0; i < INTERGERS_PER_BLOCK; i++) {
        cache[setIndex][i] = address;
        address += sizeof(int); // Move to next block
        
        if (setIndex != (address / CACHE_BLOCK_SIZE) % NUMBER_OF_SETS)
            break;
    }

    return 0;
}

int sumB(array_t a)
{
    int i, j;
    int sum = 0;
    for (j = 0; j < N; j++)
        for (i = 0; i < N; i++) {
            sum += a[i][j];
            //Check cache simulation (not part of original logic)
            if (!isInCache(i, j)) {
                misses++;
            }
        }
    return sum;
}

int sumC(array_t a)
{
    int i, j;
    int sum = 0;
    for (j = 0; j < N; j+=2)
        for (i = 0; i < N; i+=2) {
            sum += (a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1]);
            
            if (!isInCache(i, j))
                misses++;

            if (!isInCache(i + 1, j))
                misses++;

            if (!isInCache(i, j + 1))
                misses++;

            if (!isInCache(i + 1, j + 1))
                misses++;
        }
    return sum;
}

int main() {
    array_t a;
    int count = 0;
    // Initialize the array with some values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            a[i][j] = count++;
    }

    int result = sumC(a);

    printf("Reads: %d\n", N * N);
    printf("Misses: %d\n", misses);
    printf("Hit: %d\n", N * N - misses);
    printf("Miss percentage: %f\n", misses/(float)(N * N) * 100.0);

    return 1;
}