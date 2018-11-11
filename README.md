# trace

Trace function entry and exits. For example:

```
./a.out
Entering main
 Entering f
Wow in f
 Exiting f
hi there
Exiting main
```

At some point this is limited by what function names can be recovered. I'm not
sure what the point is though.
