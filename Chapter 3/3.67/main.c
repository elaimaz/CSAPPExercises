union ele {
	struct {
		int *p;
		int y;
	} e1;
	struct {
		int x;
		union ele *next;
	} e2;
};

int main() {
    return 0;
}