int var_prod_ele(int n, int A[n][n], int B[n][n], int i, int k) {
    int j;
    int result = 0;

    for (j = 0; j < n; j++)
        A[i][0] += A[i][j] * B[j][k];

    return A[i][0];
}

int main() {
    return 0;
}