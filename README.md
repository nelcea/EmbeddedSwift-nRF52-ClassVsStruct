# Class vs Struct

This small example project illustrate an error encountered when trying to define a class in an external file (different than where @main is defined).
It's been tested with nRF Connect SDK v2.7.0, targeting nRF 52840 DK board.

If MainLoop is a struct, the project builds and runs fine.

Making MainLoop a class breaks the build.
The linking fails with error `collect2: error: ld returned 1 exit status` without any more information (even with -v option).

Keeping MainLoop a class but commenting out the print statement makes that error go away.

## Update 2025-04-04

Changing the optimization level on Swift compilation fixes the issue.  
Using either -O or -Ounchecked makes the project build, while using -Onone, -Osize or -Oplayground makes it fail.
