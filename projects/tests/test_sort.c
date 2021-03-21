#include <stdlib.h>
#include <string.h>
#include "limits.h"
#include "../algorithm/sort.h"
#include "../include/ctest/ctest.h"


#define MAX_ARRAY_SIZE 100000
#define SIZE_TEST_DATA_ARRAY_LARGE 10000


typedef struct TestData {
    unsigned int size;
    int input[MAX_ARRAY_SIZE];
    int expected[MAX_ARRAY_SIZE];
} td;


td TEST_DATA_SIMPLE = {
    .size=2,
    .input={2,1},
    .expected={1,2}
};


td TEST_DATA_SEVEN = {
    .size=7,
    .input={99,4,2,1,55,0,1},
    .expected={0,1,1,2,4,55,99}
};


td TEST_DATA_NINE = {
    .size=9,
    .input={3,7,8,5,2,1,9,5,4},
    .expected={1,2,3,4,5,5,7,8,9}
};


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


void assert_arrays(int *expected, int *actual, unsigned int length) {
    for (int i = 0; i < length; ++i) {
        ASSERT_EQUAL(expected[i], actual[i]);
    }
}


td* deep_copy(td *obj) {
    td *d = malloc(sizeof(td));
    memcpy(d, obj, sizeof(td));
    return d;
}


CTEST_DATA(worstcase) {
    td *two;
    td *nine;
    td *large;
};


CTEST_SETUP(worstcase) {
    data->two = deep_copy(&TEST_DATA_SIMPLE);
    data->nine = deep_copy(&TEST_DATA_NINE);
    data->large = newTestDataWorstCase(SIZE_TEST_DATA_ARRAY_LARGE);
}


CTEST_TEARDOWN(worstcase) {
    free(data->two);
    free(data->nine);
    free(data->large);
}


CTEST2(worstcase, maxsort1) {
    maxsort(data->two->input, data->two->size);
    assert_arrays(data->two->expected, data->two->input, data->two->size);
}


CTEST2(worstcase, maxsort2) {
    maxsort(data->nine->input, data->nine->size);
    assert_arrays(data->nine->expected, data->nine->input, data->nine->size);
}


CTEST2(worstcase, maxsort3) {
    maxsort(data->large->input, data->large->size);
    assert_arrays(data->large->expected, data->large->input, data->large->size);
}


CTEST2(worstcase, bubblesort1) {
    bubblesort(data->two->input, data->two->size);
    assert_arrays(data->two->expected, data->two->input, data->two->size);
}


CTEST2(worstcase, bubblesort2) {
    bubblesort(data->nine->input, data->nine->size);
    assert_arrays(data->nine->expected, data->nine->input, data->nine->size);
}


CTEST2(worstcase, bubblesort3) {
    bubblesort(data->large->input, data->large->size);
    assert_arrays(data->large->expected, data->large->input, data->large->size);
}


CTEST2(worstcase, quicksort1) {
    quicksort(data->two->input, 0, data->two->size-1);
    assert_arrays(data->two->expected, data->two->input, data->two->size);
}


CTEST2(worstcase, quicksort2) {
    quicksort(data->nine->input, 0, data->nine->size-1);
    assert_arrays(data->nine->expected, data->nine->input, data->nine->size);
}


CTEST2(worstcase, quicksort3) {
    quicksort(data->large->input, 0, data->large->size-1);
    assert_arrays(data->large->expected, data->large->input, data->large->size);
}


CTEST2(worstcase, stdlibqsort1) {
    stdqsort(data->two->input, data->two->size);
    assert_arrays(data->two->expected, data->two->input, data->two->size);
}


CTEST2(worstcase, stdlibqsort2) {
    stdqsort(data->nine->input, data->nine->size);
    assert_arrays(data->nine->expected, data->nine->input, data->nine->size);
}


CTEST2(worstcase, stdlibqsort3) {
    stdqsort(data->large->input, data->large->size);
    assert_arrays(data->large->expected, data->large->input, data->large->size);
}
