#include "../../../Utils/csapp.h"

void foo(int n)
{
    int i;

    for (i = 0; i < n; i++)
        Fork();
    printf("hello\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s <n>\n", argv[0]);
        exit(0);
    }
    foo(atoi(argv[1]));
    return 0;
}
