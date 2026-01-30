#include <stdio.h>
#include <time.h>

#define DIM 64
#define B 16

void transpose(int *dst, int *src, int dim)
{
    int i, j;
    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            dst[j*dim + i] = src[i*dim + j];
}

void transpose_enhanced(int *dst, int *src, int dim)
{
    int i, j;
    for (i = 0; i < dim; i++) {
        const int *src_row = src + i * dim;
        for (j = 0; j < dim - 3; j+=4) {
            int *d0 = dst + j * dim + i;
            int *d1 = d0 + dim;         
            int *d2 = d1 + dim;         
            int *d3 = d2 + dim;

            int s0 = src_row[j];
            int s1 = src_row[j + 1];
            int s2 = src_row[j + 2];
            int s3 = src_row[j + 3];

            *d0 = s0;
            *d1 = s1;
            *d2 = s2;
            *d3 = s3;
        }
    }
}

void transpose_blocked_unroll4(int *restrict dst,
                               const int *restrict src,
                               int dim)
{
    for (int ii = 0; ii < dim; ii += B) {
        for (int jj = 0; jj < dim; jj += B) {

            int i_max = ii + B;
            int j_max = jj + B;

            for (int i = ii; i < i_max; ++i) {
                const int *src_row = src + i * dim;

                int j = jj;
                for (; j + 3 < j_max; j += 4) {
                    int *d0 = dst + j * dim + i;
                    int *d1 = d0 + dim;
                    int *d2 = d1 + dim;
                    int *d3 = d2 + dim;

                    int s0 = src_row[j];
                    int s1 = src_row[j + 1];
                    int s2 = src_row[j + 2];
                    int s3 = src_row[j + 3];

                    *d0 = s0;
                    *d1 = s1;
                    *d2 = s2;
                    *d3 = s3;
                }
            }
        }
    }
}

int main() {
    struct timespec start, end;
    unsigned int count = 0;
    
    int src[DIM][DIM];
    int dst[DIM][DIM] = {0};
    int dst2[DIM][DIM] = {0};
    int dst3[DIM][DIM] = {0};

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            src[i][j] = count;
            count++;
        }

    }

    clock_gettime(CLOCK_MONOTONIC, &start);
    transpose((int *)dst, (int *)src, DIM);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + 
                        (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Time taken for transposition: %f seconds\n", time_taken);

    clock_gettime(CLOCK_MONOTONIC, &start);
    transpose((int *)dst2, (int *)src, DIM);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_taken = (end.tv_sec - start.tv_sec) + 
                        (end.tv_nsec - start.tv_nsec) / 1e9;

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            if (dst[i][j] != dst2[i][j]) {
                printf("Mismatch at (%d, %d): %d != %d\n", i, j, dst[i][j], dst2[i][j]);
                return -1;
            }
        }
    }

    printf("Time taken for enhanced transposition: %f seconds\n", time_taken);

    clock_gettime(CLOCK_MONOTONIC, &start);
    transpose_blocked_unroll4((int *)dst3, (const int *)src, DIM);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_taken = (end.tv_sec - start.tv_sec) + 
                        (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Time taken for blocked and unrolled transposition: %f seconds\n", time_taken);

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            if (dst[i][j] != dst3[i][j]) {
                printf("Mismatch at (%d, %d): %d != %d\n", i, j, dst[i][j], dst3[i][j]);
                return -1;
            }
        }
    }
    return 0;
}