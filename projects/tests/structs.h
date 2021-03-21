#ifndef STRUCTS_H
#define STRUCTS_H

#include <string.h>

#include "../include/ctest/ctest.h"


#define MAX_ARRAY_SIZE 100000


typedef struct TestData {
    unsigned int size;
    int input[MAX_ARRAY_SIZE];
    int expected[MAX_ARRAY_SIZE];
} td;


td* newTestDataWorstCase(unsigned int size) {
    /*
    * Create new test data structure of size with
    * worst case.
    */
    if (size > MAX_ARRAY_SIZE) {
        return NULL;
    }
    td *d = malloc(sizeof(td));
    for (int i = 0; i < size; ++i) {
        d->expected[i] = i;
        d->input[i] = size-1-i;
    }
    d->size = size;
    return d;
}


td* deep_copy(td *obj) {
    td *d = malloc(sizeof(td));
    memcpy(d, obj, sizeof(td));
    return d;
};

#endif
