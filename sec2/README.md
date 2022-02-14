# Section 2

The section is split into 4 different parts, corresponding to the 4 different `.c` files present in this directory. You can compile each part with `make <name>` such as `make warmup` or `make mem_error1`. Answers are in `answers.md`.

## `warmup`
For each snippet of code, try to predict what will get printed, if the snippet causes undefined behavior, and if a segfault is possible.

## `mem_error1`
Compile and run the program. Use the sanitizer error you get to try and fix the bug.

## `mem_error2`
Compile and run the program. Use the sanitizer error you get to try and fix the bug. There are 3 total bugs, can you find them all? The third may only raise a sanitizer error if you compile with optimizations (change the Makefile to use the `-O3` flag).

## `string_array`
Make bug fixes and adjustments to fix the buggy program.

