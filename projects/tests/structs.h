#ifndef STRUCTS_H
#define STRUCTS_H

#include <string.h>
#include <stdlib.h>

#include "../include/ctest/ctest.h"


#define MAX_ARRAY_SIZE 100000
#define MAX_RAND_ELEM_SIZE 1000000


typedef struct TestData {
    unsigned int size;
    int input[MAX_ARRAY_SIZE];
    int expected[MAX_ARRAY_SIZE];
} td;


typedef void (*__fn_arr_gen) (td*, int);


void __fn_arr_gen_worst(td *d, int idx) {
    d->input[idx] = d->size-1-idx;
}


void __fn_arr_gen_rand(td *d, int idx) {
    int tmp = rand() % MAX_RAND_ELEM_SIZE;
    d->input[tmp % d->size] = tmp;
}


int __fn_comp_sort(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}


td* newTestData(unsigned int size, __fn_arr_gen f) {
    if (size > MAX_ARRAY_SIZE) {
        return NULL;
    }
    td *d = malloc(sizeof(td));
    d->size = size;
    for (int i = 0; i < size; ++i) {
        (*f)(d, i);
    }
    memcpy(d->expected, d->input, d->size*sizeof(int));
    qsort(d->expected, d->size, sizeof(int), __fn_comp_sort);
    return d;
}


td* deep_copy(td *obj) {
    td *d = malloc(sizeof(td));
    memcpy(d, obj, sizeof(td));
    return d;
};

#endif
