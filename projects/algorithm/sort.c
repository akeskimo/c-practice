#include <string.h>
#include <stdlib.h>
#include "sort.h"
#include "stdio.h"


int* sort_array(int *array, int len) {
    int tmp, i, j, idx, max;
    for (i = 0; i < len; ++i) {
        max = array[i];
        idx = i;
        for (j = i + 1; j < len; ++j) {
            if (array[j] < max) {
                max = array[j];
                idx = j;
            }
        }
        if (idx == i) continue;
        tmp = array[i];
        array[i] = array[idx];
        array[idx] = tmp;
    }
    return array;
}
