#ifndef __CTRACE_H__
#define __CTRACE_H__

#include <stdio.h>
#include <string.h>
#include <execinfo.h>

void __cyg_profile_func_enter (void *, void *) __attribute__((no_instrument_function));
void __cyg_profile_func_exit (void *, void *) __attribute__((no_instrument_function));

static int depth = -1;

void __cyg_profile_func_enter (void *this_fn, void *call_site) {
  depth++;

  char** symbols = backtrace_symbols(&this_fn, 1);
  char* token;
  char* rest = symbols[0];
  for (int i = 0; i < 4; i++) {
    token = strtok_r(rest, " ", &rest);
  }

  for (int i = 0; i < depth; i++) {
    printf(" ");
  }
  printf("Entering %s\n", token);
}

void __cyg_profile_func_exit (void *this_fn, void *call_site) {
  char** symbols = backtrace_symbols(&this_fn, 1);
  char* token;
  char* rest = symbols[0];
  for (int i = 0; i < 4; i++) {
    token = strtok_r(rest, " ", &rest);
  }

  for (int i = 0; i < depth; i++) {
    printf(" ");
  }
  printf("Exiting %s\n", token);

  depth--;
}

#endif
