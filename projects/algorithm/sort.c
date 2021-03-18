#include "sort.h"
#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>


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

void print_array(int *array, int start, int end) {
    for (int j = start; j <= end; ++j) {
        printf("%d ", array[j]);
    }
}


void __swap(int *array, int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}


void quicksort(int *array, int start, int end) {
    /**
     * Quick sort algorithm that resolves the
     * sort order on divide and conquer principle.
     */
    if (end <= start) {
        return;
    }
    int p = array[end];
    int j = start;
    for (int i = start; i < end; ++i) {
        if (array[i] < p) {
            __swap(array, i, j);
            j++;
        }
    }
    __swap(array, j, end);
    quicksort(array, start, j-1);
    quicksort(array, j+1, end);
}


int comparator(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


void stdlib_qsort(int *array, int len) {
    qsort(array, len, sizeof(int), comparator);
}
