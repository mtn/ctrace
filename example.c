#include "ctrace.h"
#include <stdio.h>

static int g(int j) {
  return -1;
}

static int f (int i) {
  printf("Wow in f\n");
  if (i > 0) {
    return g(2);
  } else {
    return 0;
  }
}


int main() {
  f(1);
  printf("hi there\n");
}
