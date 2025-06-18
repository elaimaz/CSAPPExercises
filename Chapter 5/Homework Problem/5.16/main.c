#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int data_t;

typedef struct {
    long int len;
    data_t *data;
} vec_rec, *vec_ptr;

long int vec_length(vec_ptr v)
{
    return v->len;
}

data_t *get_vec_start(vec_ptr v)
{
    return v->data;
}

void inner4(vec_ptr u, vec_ptr v, data_t *dest)
{
    long int i;
    int length = vec_length(u);
    data_t *udata = get_vec_start(u);
    data_t *vdata = get_vec_start(v);
    data_t sum = (data_t) 0;
    for (i = 0; i < length; i++) {
        sum = sum + udata[i] * vdata[i];
    }
    *dest = sum;
}

void inner4_loop_unroling_4x(vec_ptr u, vec_ptr v, data_t *dest)
{
    unsigned int i;
    int length = vec_length(u);
    data_t *udata = get_vec_start(u);
    data_t *vdata = get_vec_start(v);
    data_t sum = (data_t) 0;

    for (i = 0; i < length - 3; i += 4) {
        sum = sum + udata[i] * vdata[i];
        sum = sum + udata[i + 1] * vdata[i + 1];
        sum = sum + udata[i + 2] * vdata[i + 2];
        sum = sum + udata[i + 3] * vdata[i + 3];
    }
    for (; i < length; i++) {
        sum = sum + udata[i] * vdata[i];
    }
    *dest = sum;
}

vec_ptr new_vec(long int len)
{
    /* Allocate header structure */
    vec_ptr result = (vec_ptr) malloc(sizeof(vec_rec));
    if (!result)
        return NULL; /* Couldn’t allocate storage */
    result->len = len;
    /* Allocate array */
    if (len > 0) {
        data_t *data = (data_t *)calloc(len, sizeof(data_t));
        if (!data) {
            free((void *) result);
            return NULL; /* Couldn’t allocate storage */
        }
        result->data = data;
    }
    else
        result->data = NULL;
    return result;
}

void test() {
    vec_ptr v = new_vec(10);
    for (long int i = 0; i < 10; i++) {
        v->data[i] = i + 1;
    }
    data_t sum = 0;
    data_t sum_unroling = 0;
    inner4(v, v, &sum);
    assert(sum == 385); // 1^2 + 2^2 + ... + 10^2

    inner4_loop_unroling_4x(v, v, &sum_unroling);
    assert(sum_unroling == 385);

    assert(sum == sum_unroling);
    free(v->data);
    free(v);
}

int main()
{
    test();

    return 0;
}