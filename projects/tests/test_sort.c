#include "limits.h"
#include "stdio.h"
#include "stdlib.h"

#include "../algorithm/sort.h"
#include "../include/ctest/ctest.h"

void assert_arrays(int *exp, int expl, int *res, int resl) {
    ASSERT_EQUAL(expl, resl);
    for (int i = 0; i < expl; ++i) {
        ASSERT_EQUAL(exp[i], res[i]);
    }
}


CTEST(suite1, test1) {
    int input[] = {2,1};
    int expected[] = {1,2};
    int *result = sort_array(input, 2);
    assert_arrays(expected, 2, result, 2);
}

CTEST(suite1, test2) {
    int input[] = {99,4,2,1,55,0,1};
    int expected[] = {0,1,1,2,4,55,99};
    int *result = sort_array(input, 7);
    assert_arrays(expected, 7, result, 7);
}

CTEST(suite1, test3) {
    int size = 100000;
    int input[size];
    for (int i = size; i >= 0; --i) {
        input[i] = i;
    }
    printf("sorting array\n");
    int *result = sort_array(input, size);
    printf("sorting done\n");
    int expected[size];
    for (int i = 0; i < size; ++i) {
        expected[i] = i;
    }
    printf("asserting...\n");
    assert_arrays(expected, size, result, size);
    printf("asserted.\n");
}

