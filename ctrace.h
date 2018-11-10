#ifndef __CTRACE_H__
#define __CTRACE_H__

#include <stdio.h>
#include <execinfo.h>

void __cyg_profile_func_enter (void *, void *) __attribute__((no_instrument_function));
void __cyg_profile_func_exit (void *, void *) __attribute__((no_instrument_function));

void __cyg_profile_func_enter (void *this_fn, void *call_site) {
  backtrace_symbols_fd(&this_fn, 1, 1);

  printf("lmao entering %p\n", this_fn);
}

void __cyg_profile_func_exit (void *this_fn, void *call_site) {
  printf("lmao exiting %p\n", this_fn);
}

#endif
