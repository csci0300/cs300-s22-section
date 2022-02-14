## warmup
For each snippet of code, say what gets printed, if there's undefined behavior, and if a segfault is possible.

1. N/A, yes, no
2. "my_int is now 5", no, no
3. N/A, yes, yes
4. "N/A", yes, yes
5. "N/A", yes, yes
6. "my_str is Hi!", no, no
7. "my_str is Hi!", no, no


## mem_error1
* remember to free in the error case

## mem_error2
* make malloc allocated 12 bytes
* free at end of main
* don't use stack pointer in struct

## string_array
* add malloc for pointers to strings
* add free at end of main for pointers to strings
* add malloc before each call to strcpy
  * zero out this memory manually
* add free after each printf
