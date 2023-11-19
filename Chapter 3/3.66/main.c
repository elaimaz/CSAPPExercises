typedef struct
{
	int left;
	a_struct a[CNT];
	int right;
} b_struct;

void test(int i, b_struct* bp)
{
	int n = bp->left + bp->right;
	a_struct* ap = &bp->a[i];
	ap->x[ap->idx] = n;
}

int main() {
    return 0;
}