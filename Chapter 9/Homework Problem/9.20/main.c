#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

#include <malloc.h>

#define HEAP_MAX_SIZE 128
#define HEADER_SIZE 4
#define BIT_MASK_ONE 0x1

#define ALLOCATED(value) (value & BIT_MASK_ONE > 0 ? 1 : 0)
#define ALLOCATE(value) (value |= BIT_MASK_ONE)
#define DEALLOCATE(value) (value &= ~BIT_MASK_ONE)

static void *heap_init_ptr = NULL;
static void *heap_end_ptr = NULL;

int insert_header(void* header_ptr, size_t size) {
    if (header_ptr == NULL || size <= HEADER_SIZE) {
        printf("Invalid header pointer or size\n");
        return 0;
    }

    uint32_t header = size - HEADER_SIZE; // Subtract header size for the header itself
    header <<= 3; // Shift left by 3 to set the last 3 bits to 0 (indicating free block)

    memcpy(header_ptr, &header, sizeof(uint32_t));

    return 1;
}

int init_heap() {
    heap_init_ptr = mmap(NULL, HEAP_MAX_SIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
    if (heap_init_ptr == MAP_FAILED) {
        perror("Error mapping file");
        return 0;
    }

    memset(heap_init_ptr, 0, HEAP_MAX_SIZE);
    heap_end_ptr = heap_init_ptr + HEAP_MAX_SIZE;

    void* header_ptr = heap_init_ptr;
    size_t byte_space = 8;
    while (header_ptr < heap_end_ptr) {
        insert_header(header_ptr, byte_space);
        header_ptr += byte_space;
        byte_space <<= 1; // Double the byte space for the next header
    }
    
    return 1;
}

void *value_ptr(void *header_ptr, size_t size) {
    if (header_ptr == NULL) {
        perror("Error: NULL pointer passed to value_ptr");
        return NULL;
    }

    uint32_t header;
    memcpy(&header, header_ptr, sizeof(uint32_t));
    
    if (!ALLOCATED(header)) {
        perror("Error: Attempting to get value pointer from an unallocated block");
        return NULL;
    }

    // Get the address of the content of the block
    void* content_ptr = header_ptr + HEADER_SIZE + (header >> 3) - size;

    return content_ptr;
}

// return the address of the allocated block if successful, otherwise return NULL
void* alloc_in_heap(void* ptr, size_t size) {
    if (heap_init_ptr == NULL) {
        perror("Error mapping file");
        return NULL;
    }

    void *header_ptr = heap_init_ptr;
    while (header_ptr < heap_end_ptr) {
        uint32_t header;
        memcpy(&header, header_ptr, sizeof(uint32_t));
        size_t block_size = (header >> 3);
        if (ALLOCATED(header) || block_size < size) {
            header_ptr += block_size + HEADER_SIZE; // Move to the next header
            continue;
        }

        ALLOCATE(header);
        memcpy(header_ptr, &header, sizeof(uint32_t));
        
        void* content_ptr = value_ptr(header_ptr, size);
        memcpy(content_ptr, ptr, size);
        
        return header_ptr;
    }

    return NULL;
}

int free_heap(void *ptr) {
    if (ptr == NULL) {
        perror("Error: NULL pointer passed to free_heap");
        return 0;
    }
    
    uint32_t header;
    memcpy(&header, ptr, sizeof(uint32_t));

    if (!ALLOCATED(header)) {
        perror("Error: Attempting to free an unallocated block");
        return 0;
    }

    size_t block_size = (header >> 3);
    memset(ptr + HEADER_SIZE, 0, block_size);
    DEALLOCATE(header);
    memcpy(ptr, &header, sizeof(uint32_t));

    return 1;
}

int main () {
    init_heap();

    char letter = 'A';
    short size = 8;
    int32_t value = 42;
    int64_t big_value = 1234567890123456789;
    int64_t array[4] = {1, 2, 3, 4};
    void* allocated_ptr = NULL;

    if ((allocated_ptr = alloc_in_heap(&letter, sizeof(letter))) == NULL) {
        fprintf(stderr, "Failed to allocate memory for letter\n");
        return 0;
    } else {
        printf("Allocated letter '%c' at address %p\n", *(char*)value_ptr(allocated_ptr, sizeof(letter)), allocated_ptr);
    }

    if ((allocated_ptr = alloc_in_heap(&size, sizeof(size))) == NULL) {
        fprintf(stderr, "Failed to allocate memory for size\n");
        return 0;
    } else {
        printf("Allocated size '%d' at address %p\n", *(short*)value_ptr(allocated_ptr, sizeof(size)), allocated_ptr);
    }

    if ((allocated_ptr = alloc_in_heap(&value, sizeof(value))) == NULL) {
        fprintf(stderr, "Failed to allocate memory for value\n");
        return 0;
    } else {
        printf("Allocated value '%d' at address %p\n", *(int32_t*)value_ptr(allocated_ptr, sizeof(value)), allocated_ptr);
    }

    if ((allocated_ptr = alloc_in_heap(&big_value, sizeof(big_value))) == NULL) {
        fprintf(stderr, "Failed to allocate memory for big_value\n");
        return 0;
    } else {
        printf("Allocated big_value '%ld' at address %p\n", *(int64_t*)value_ptr(allocated_ptr, sizeof(big_value)), allocated_ptr);
    }

    if ((allocated_ptr = alloc_in_heap(array, sizeof(array))) == NULL) {
        fprintf(stderr, "Failed to allocate memory for array\n");
        return 0;
    } else {
        int64_t array_print[4] = {0, 0, 0, 0};
        memcpy(array_print, value_ptr(allocated_ptr, sizeof(array)), sizeof(array));
        printf("Allocated int64_t array '%ld' at address %p\n", array_print[0], allocated_ptr);
        printf("Allocated int64_t array '%ld' at address %p\n", array_print[1], allocated_ptr + sizeof(int64_t));
        printf("Allocated int64_t array '%ld' at address %p\n", array_print[2], allocated_ptr + 2 * sizeof(int64_t));
        printf("Allocated int64_t array '%ld' at address %p\n", array_print[3], allocated_ptr + 3 * sizeof(int64_t));
    }

    return 1;
}