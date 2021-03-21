#include <stdlib.h>
#include <unistd.h>

#include "sort.h"
#include "stdio.h"


#define SWAP(array,i,j)({int tmp = array[i]; array[i] = array[j]; array[j] = tmp;})


void __printarr(int *array, int start, int end) {
    for (int j = start; j <= end; ++j) {
        printf("%d ", array[j]);
    }
}


void maxsort(int *array, int len) {
    int i, j, idx, max;
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
        SWAP(array, i, idx);
    }
}


void bubblesort(int *array, int len) {
    /**
    * Bubble sort algorithm that swaps the next value
    * with previous value if its larger.
    */
    int i, j;
    for (i = 0; i < len - 1; ++i) {
        j = i;
        while (j >= 0 && array[j] > array[j+1]) {
            SWAP(array, j, j+1);
            j--;
        }
    }
}


void __quicksort(int *array, int start, int end) {
    if (end <= start) {
        return;
    }
    int p = array[end];
    int j = start;
    for (int i = start; i < end; ++i) {
        if (array[i] < p) {
            SWAP(array, i, j);
            j++;
        }
    }
    SWAP(array, j, end);
    __quicksort(array, start, j-1);
    return __quicksort(array, j+1, end);
}


void quicksort(int *array, int len) {
    /**
     * Quick sort algorithm that resolves the
     * sort order on divide and conquer principle.
     */
    __quicksort(array, 0, len-1);
}


int __comparator(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


void stdqsort(int *array, int len) {
    /**
     * Standard library quick sort that can be used for
     * benchmarking against user-defined sort algorithms.
     */
    qsort(array, len, sizeof(int), __comparator);
}
