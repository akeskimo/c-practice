
#include "square.h"
#include <stdio.h>


int handle_error(char *s, int err) {
    switch (err)
    {
    case PARSE_EMPTY_RESULT:
        printf("Converting string '%s' to double failed.\n", s);
        break;
    case PARSE_BUFFER_OVERFLOW:
        printf("Value is '%s' too large for size double.\n", s);
        break;
    }
    return err;
}


int main(int argc, char **argv) {
    if (argc != 3) {
        printf("usage:\n  ./square 2.0 3.5\n");
        return 1;
    }

    double x, y;
    int err;

    err = parse_flag(argv[1], &x);
    if (err != 0) {
        return handle_error(argv[1], err);
    }
    err = parse_flag(argv[2], &y);
    if (err != 0) {
        return handle_error(argv[2], err);
    }

    struct Point p = {x, y};
    printf("%1.2f\n", square(p));
    return 0;
}