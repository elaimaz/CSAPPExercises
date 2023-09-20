int var_prod_ele(int n, int A[n][n], int B[n][n], int i, int k) {
    int j;

    for (j = 0; j < n; j++)
        A[i][0] += A[i][j] * B[j][k];

    return j < n ? A[i][0] : 0;
}

int main() {
    return 0;
}