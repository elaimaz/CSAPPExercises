union ele {
	struct {
		int *p;
		int y;
	} el;
	struct {
		int x;
		union ele *next;
	} e2;
};

int main() {
    return 0;
}