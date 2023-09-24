#define M 13

typedef int Marray_t[M][M];

void transpose(Marray_t A) {
    int i, j;
    for (i = 0; i < M; i++)
        for (j = 0; j < i; j++)
        {
            int t = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = t;
        }
}

void transpose_opt(Marray_t A) {
    for (int i = 0; i < M; i++)
    {
        int* Aptr = &A[i][0];
        for (int j = 0; j < i; j++)
        {
            int t = Aptr[j]; //int t = A[i][j]
            Aptr += M;      //Aptr* = A[j][i]
            Aptr = &t;       //A[j][i] = t
        }
    }
}

int main() {
    return 0;
}