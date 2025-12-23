#include <stdio.h>

#define CACHE_SIZE 2048
#define CACHE_BLOCK_SIZE 32
#define STARTING_ADDRESS 0x0

#define INTERGERS_PER_BLOCK (CACHE_BLOCK_SIZE / sizeof(int))
#define NUMBER_OF_SETS (CACHE_SIZE / CACHE_BLOCK_SIZE)

#define N 16

unsigned int cache_tags[NUMBER_OF_SETS];
int cache_valid[NUMBER_OF_SETS] = {0};

typedef struct  {
    int c;
    int m;
    int y;
    int k;
} point_color;

point_color square[16][16];

unsigned int misses = 0;

int isInCache(int line, int column, int color_component) {
    int address = STARTING_ADDRESS + (line * N + column) * sizeof(point_color) + color_component * sizeof(int);
    int block_address = address / CACHE_BLOCK_SIZE;
    int setIndex = block_address % NUMBER_OF_SETS;
    int tag = block_address / NUMBER_OF_SETS;
    
    if (cache_valid[setIndex] && cache_tags[setIndex] == tag)
        return 1;
    else {
        cache_tags[setIndex] = tag;
        cache_valid[setIndex] = 1;
        return 0;
    }
}


int main() {
    int i, j;

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            square[i][j].y = 1;
            if(!isInCache(i, j, 2))
                misses++;
        }
    }
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            square[i][j].c = 0;
            if(!isInCache(i, j, 0))
                misses++;

            square[i][j].m = 0;
            if(!isInCache(i, j, 1))
                misses++;
            
            square[i][j].k = 0;
            if(!isInCache(i, j, 3))
                misses++;
        }
    }

    /*for (i = 0; i < 16; i++){
        for (j = 0; j < 16; j++) {
            square[j][i].c = 0;
            if(!isInCache(j, i, 0))
                misses++;
            
                square[j][i].m = 0;
            if(!isInCache(j, i, 1))
                misses++;
            
                square[j][i].y = 1;
            if(!isInCache(j, i, 2))
                misses++;
            
                square[j][i].k = 0;
            if(!isInCache(j, i, 3))
                misses++;
        }
    }*/

    unsigned int reads = N * N * 4;

    printf("Reads: %d\n", reads);
    printf("Misses: %d\n", misses);
    printf("Hit: %d\n", reads - misses);
    printf("Miss percentage: %f\n", misses/(float)(reads) * 100.0);

    return 1;
}