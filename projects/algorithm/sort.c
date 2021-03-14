#include <string.h>
#include <stdlib.h>
#include "sort.h"
#include "stdio.h"


int* sort_array(int *array, int len) {
    int *result = malloc(len * sizeof(int));
    memset(result, 0, len);

    for (int i = 0; i < len; ++i) {
        result[i] = array[i];
    }

    for (int i = 0; i < len; ++i) {
        int max = result[i];
        int idx = i;
        for (int j = i + 1; j < len; ++j) {
            if (result[j] < max) {
                max = result[j];
                idx = j;
            }
        }
        if (idx == i) continue;
        int tmp = result[i];
        result[i] = result[idx];
        result[idx] = tmp;
    }
    return result;
}
