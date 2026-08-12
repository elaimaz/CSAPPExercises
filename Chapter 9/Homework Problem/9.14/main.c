#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <err.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define FILE_NAME "hello.txt"
#define TEXT "Jello World!\n"

int main() {
    int fd;
    struct stat sb;

    fd = open(FILE_NAME, O_RDWR);
    if (fd == -1) {
        close(fd);
        err(EXIT_FAILURE, "open");
    }

    if (fstat(fd, &sb) == -1) {           /* To obtain file size */
        close(fd);
        err(EXIT_FAILURE, "fstat");
    }

    void* filePtr = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (filePtr == MAP_FAILED) {
        close(fd);
        err(EXIT_FAILURE, "mmap");
    }

    memcpy(filePtr, TEXT, sb.st_size);

    return 0;
}
