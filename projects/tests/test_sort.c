#include <stdlib.h>
#include <string.h>
#include "limits.h"
#include "../algorithm/sort.h"
#include "../include/ctest/ctest.h"


#define MAX_ARRAY_SIZE 100000


typedef struct TestData {
    unsigned int size;
    int input[MAX_ARRAY_SIZE];
    int expected[MAX_ARRAY_SIZE];
} data;


data TEST_DATA_SIMPLE = {
    .size=2,
    .input={2,1},
    .expected={1,2}
};


data TEST_DATA_SEVEN = {
    .size=7,
    .input={99,4,2,1,55,0,1},
    .expected={0,1,1,2,4,55,99}
};


data* newTestDataWorstCase(unsigned int size) {
    /*
    * Create new test data structure of size with
    * worst case.
    */
    if (size > MAX_ARRAY_SIZE) {
        return NULL;
    }
    data init;
    data *d = &init;
    for (int i = 0; i < size; ++i) {
        d->expected[i] = i;
        d->input[i] = size-1-i;
    }
    d->size = size;
    return d;
}


void assert_arrays(int *expected, int *actual, unsigned int length) {
    for (int i = 0; i < length; ++i) {
        ASSERT_EQUAL(expected[i], actual[i]);
    }
}


data* shallow_copy(data *obj) {
    data *d = malloc(sizeof(data));
    memcpy(d, obj, sizeof(data));
    return d;
}


CTEST(suite1, test1) {
    data *d = shallow_copy(&TEST_DATA_SIMPLE);
    sort_array(d->input, d->size);
    assert_arrays(d->expected, d->input, d->size);
}


CTEST(suite1, test2) {
    data *d = shallow_copy(&TEST_DATA_SEVEN);
    sort_array(d->input, d->size);
    assert_arrays(d->expected, d->input, d->size);
}


CTEST(suite1, test3) {
    data *tmp = newTestDataWorstCase(1000);
    data *d = shallow_copy(tmp);
    sort_array(d->input, d->size);
    assert_arrays(d->expected, d->input, d->size);
}


CTEST(suite2, test1) {
    data *d = shallow_copy(&TEST_DATA_SIMPLE);
    bsort(d->input, d->size);
    assert_arrays(d->expected, d->input, d->size);
}


CTEST(suite2, test2) {
    data *d = shallow_copy(&TEST_DATA_SEVEN);
    bsort(d->input, d->size);
    assert_arrays(d->expected, d->input, d->size);
}


CTEST(suite2, test3) {
    data *tmp = newTestDataWorstCase(1000);
    data *d = shallow_copy(tmp);
    bsort(d->input, d->size);
    assert_arrays(d->expected, d->input, d->size);
}
