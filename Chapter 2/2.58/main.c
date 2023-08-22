//Write a procedure is_little_endian that will return 1 when compiled and
// run on a little endian machine, and will return 0 when compiled and
// run on a big endian machine. This program shoud run on any machine,
// regardless of it's word size.

#include <stdio.h>

int is_little_endian() {
    int number = 1;
    char *ptr =(char*) &number;

    return ptr[0] == 1 ? 1 : 0;
}

int main() {
    printf("%d", is_little_endian());
    return 0;
}