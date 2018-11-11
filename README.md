# trace

Trace function entry and exits, just by including a header file (and compiling
with some flags). For example, including `ctrace.h` in the following code:

```c
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
```

produces the following output:

```
Entering main
 Entering f
Wow in f
  Entering g
  Exiting g
 Exiting f
hi there
Exiting main
```

It works via `gcc -finstrument-functions`. At some point this is limited by
what function names can be recovered. I'm not sure what the point is though.
