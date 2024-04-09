long array[10] = {7, 5, 7, 10, 9, 7, 3, 7, 8, 3};

void bubble_s_pointer(long *data, long count) {
    long last;
    long* array_end = data + count - 1;
    for (last = count - 1; last > 0; last--) {
        while(data < array_end) {
            if (*(data + 1) < *(data)) {
                long t = *(data + 1);
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
    bubble_s_pointer(array, 10);

    return 0;
}