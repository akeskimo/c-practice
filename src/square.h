
struct Point {
    double x;
    double y;
};

double square(struct Point p);

typedef enum {
    PARSE_OK = 0,
    PARSE_EMPTY_RESULT,
    PARSE_BUFFER_OVERFLOW,
} ParserErrorType;

int parse_flag(char *s, double *d);
