// Compiled with: gcc -m32 main.c -o main

#include <assert.h>

/* Bubble sort: Array version */
void bubble_s(int *data, int count) {
    int i, last;
    for (last = count - 1; last > 0; last--) {
        for (i = 0; i < last; i++) {
            if (data[i+1] < data[i]) {
                /* Swap adjacent elements */
                int t = data[i+1];
                data[i+1] = data[i];
                data[i] = t;
            }
        }
    }
}

/* Bubble sort: Pointer version */
void bubble_s_pointer(int *data, int count) {
    int last;
    int* array_end = data + count - 1;
    for (last = count - 1; last > 0; last--) {
        while(data < array_end) {
            if (*(data + 1) < *(data)) {
                int t = *(data + 1);
                *(data + 1) = *(data);
                *(data) = t;
            }
            data++;
        };
        array_end--;
        data = data - last;
    }
}

int main()
{
    int array[10] = {7, 5, 7, 10, 9, 7, 3, 7, 8, 3};
    int array2[10] = {7, 5, 7, 10, 9, 7, 3, 7, 8, 3};

    bubble_s(array, 10);

    bubble_s_pointer(array2, 10);

    for (int i = 0; i < 10; i++) {
        assert(array[i] == array2[i]);
    }

    return 0;
}