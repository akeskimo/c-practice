#include <stdlib.h>
#include <stdio.h>
#include "square.h"


double square(struct Point p)
{
  return p.x * p.y;
}


int parse_flag(char *s, double *d)
{
  char *endptr;
  double value;

  value = strtod(s, &endptr);
  if (value == 0) {
    if (endptr == s)
    {
      return PARSE_EMPTY_RESULT;
    }
  }
  *d = value;
  return 0;
}