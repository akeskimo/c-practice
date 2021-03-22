#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "../algorithm/sort.h"
#include "structs.h"


typedef void (*func) (int*, int);


typedef struct Benchmark {
    char *name;
    td *data;
    func test;
} Benchmark;


void run(Benchmark bm) {
    float start_time = (float)clock()/CLOCKS_PER_SEC;
    (*bm.test)(bm.data->input, bm.data->size);
    float elapsed = (float)clock()/CLOCKS_PER_SEC - start_time;
    printf("%s:\n%-10s%1.4f seconds\n\n", bm.name, "user", elapsed);
    free(bm.data);
}


void benchmark() {
    /** Run tests against multiple reference data
     * sets and compare the results.
     */

    size_t data_size = 10000;

    Benchmark benchmarks[] = {
        {
            .name = "maxsort",
            .data = newTestData(data_size, __fn_arr_gen_worst),
            .test = maxsort,
        },
        {
            .name = "quicksort",
            .data = newTestData(data_size, __fn_arr_gen_worst),
            .test = quicksort,
        },
        {
            .name = "bubblesort",
            .data = newTestData(data_size, __fn_arr_gen_worst),
            .test = bubblesort,
        },
        {
            .name = "qsort (std)",
            .data = newTestData(data_size, __fn_arr_gen_worst),
            .test = stdqsort,
        },
    };

    for (int i = 0; i < sizeof(benchmarks)/sizeof(Benchmark); ++i) {
        run((Benchmark)benchmarks[i]);
    }
};


int main() {
    benchmark();
    return 0;
}
