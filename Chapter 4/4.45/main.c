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

int main()
{
    return 0;
}