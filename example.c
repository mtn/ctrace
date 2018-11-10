#include "ctrace.h"
#include <stdio.h>

int f(int i) {
  printf("f function pointer: %p\n", &f);

  if (i > 0) {
    return 1;
  } else {
    return 0;
  }
}


int main() {
  f(1);
  printf("Main function pointer: %p\n", &main);

  printf("hi there\n");
}
