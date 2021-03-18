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


void __quicksort(int *array, int start, int end) {
    if (end <= start) {
        return;
    }
    int i = start;
    int ip = end;  // always choose the last element as pivot
    int p = array[ip];
    int tmp;
    while (i < ip) {
        if (array[i] > p) {
            tmp = array[ip];
            array[ip] = array[i];
            array[i] = array[ip-1];
            array[ip-1] = tmp;
            ip = ip -1;
        } else {
            ++i;
        }
    }
    __quicksort(array, start, ip-1);
    __quicksort(array, ip+1, end);
}

void quicksort(int *array, int len) {
    /**
     * Quick sort algorithm that resolves the
     * sort order on divide and conquer principle.
     */
    __quicksort(array, 0, len-1);
}


int comparator(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


void stdlib_qsort(int *array, int len) {
    qsort(array, len, sizeof(int), comparator);
}
