#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

#define FILE_MAX_SIZE 1024

void *mmapcopy(void *start, size_t length, int prot, int flags, int fd, off_t offset) {
    void *ptr = mmap(start, length, prot, flags, fd, offset); 
    if (ptr == MAP_FAILED) {
        perror("mmap failed");
        return NULL;
    }

    return ptr;
}

FILE* get_file_ptr(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file)
        return file;

    perror("Failed to open file");
    return NULL;
}

int read_file_content(FILE *file, char *buffer) {
    size_t read_length = fread(buffer, sizeof(char), FILE_MAX_SIZE, file);
    if (read_length <= 0) {
        perror("Failed to read file");
        return 0;
    }
    return read_length;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    FILE *file = get_file_ptr(argv[1]);
    if (file == NULL) {
        return 0;
    }

    char file_content[FILE_MAX_SIZE] = { 0 };
    size_t read_length = read_file_content(file, file_content);
    if (read_length <= 0) {
        printf("Failed to read file content.\n");
        fclose(file);
        return 0;
    }

    void *mapped_ptr = mmapcopy(NULL, read_length, PROT_WRITE, MAP_PRIVATE, fileno(file), 0);
    if (mapped_ptr == NULL) {
        printf("Failed to map file content to memory.\n");
        fclose(file);
        return 0;
    }

    char file_content_in_memory[FILE_MAX_SIZE] = { 0 };
    memcpy(file_content_in_memory, mapped_ptr, read_length);

    if (strncmp(file_content, file_content_in_memory, read_length) != 0){
        printf("File content and memory content do not match.\n");
        fclose(file);
        return 0;
    }

    printf("%s\n", file_content_in_memory);

    fclose(file);
    return 1;
}