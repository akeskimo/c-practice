#include "sort.h"
#include "stdio.h"


void sort_array(int *array, int len) {
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
}


void bsort(int *array, int len) {
    /**
    * Bubble sort algorithm that swaps
    * the next value with previous value.
    */
    int i, j, tmp;
    for (i = 0; i < len - 1; ++i) {
        j = i;
        while (j >= 0 && array[j] > array[j+1]) {
            tmp = array[j+1];
            array[j+1] = array[j];
            array[j] = tmp;
            j--;
        }
    }
}
