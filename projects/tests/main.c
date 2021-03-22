#define CTEST_MAIN

#include <time.h>
#include <stdlib.h>

#include "../include/ctest/ctest.h"

int main(int argc, const char *argv[]) {
    // seed random generator
    srand((unsigned int)time(NULL));

    int result = ctest_main(argc, argv);
    return result;
}
