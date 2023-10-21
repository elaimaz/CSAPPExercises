#define E1(n) (2 + (2 * n))
#define E2(n) (3 * n)

int sum_col(int n, int A[E1(n)][E2(n)], int j)
{
	int i;
	int result = 0;
	for (i = 0; i < E1(n); i++)
		result += A[i][j];
	return result;
}

int main() {
    return 0;
}