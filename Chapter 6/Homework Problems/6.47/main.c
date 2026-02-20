#include <stdio.h>
#include <time.h>

#define N 512

void col_convert(char *G, int dim) {
    int i, j;
    
    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            G[j*dim + i] = G[j*dim + i] || G[i*dim + j];
}

void col_convert_enhanced(char *G, int dim) {
    for (int i = 0; i < dim; ++i) {
        char *row_i = G + i * dim;
        int j = i + 1;
        char *col_i = G + j * dim + i;

        for (; j + 3 < dim; j += 4) {
            char *p0 = col_i;
            char *p1 = p0 + dim;
            char *p2 = p1 + dim;
            char *p3 = p2 + dim;

            char v0 = row_i[j] | *p0;
            char v1 = row_i[j + 1] | *p1;
            char v2 = row_i[j + 2] | *p2;
            char v3 = row_i[j + 3] | *p3;

            row_i[j] = v0;
            *p0 = v0;
            row_i[j + 1] = v1;
            *p1 = v1;
            row_i[j + 2] = v2;
            *p2 = v2;
            row_i[j + 3] = v3;
            *p3 = v3;

            col_i = p3 + dim;
        }

        for (; j < dim; ++j) {
            char v = row_i[j] | *col_i;
            row_i[j] = v;
            *col_i = v;
            col_i += dim;
        }
    }
}

int main() {
    struct timespec start, end;

    char G[N][N] = {0};
    char G1[N][N] = {0};

    for (int i = 0; i < N; i++) {
        G[i][i] = 1;
        G1[i][i] = 1;

        if (i + 1 < N) {
            G[i][i + 1] = 1;
            G1[i][i + 1] = 1;
        }
    }
    G[N - 1][0] = 1;
    G1[N - 1][0] = 1;

    clock_gettime(CLOCK_MONOTONIC, &start);
    col_convert(&G[0][0], N);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + 
                        (end.tv_nsec - start.tv_nsec) / 1e9;
    
    printf("Time taken: %f seconds\n", time_taken);
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    col_convert_enhanced(&G1[0][0], N);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_taken = (end.tv_sec - start.tv_sec) + 
                 (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Time taken (enhanced): %f seconds\n", time_taken);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (G1[i][j] != G[i][j]) {
                printf("Mismatch at (%d, %d): G = %d, G1 = %d\n", i, j, G[i][j], G1[i][j]);
                return 0;
            }
        }
    }

    return 1;
}
