# Section 4: File IO

In this section, we will learn about how to read and write to a file using
file system calls.

## Getting started

The main program is `fileio_section.c`. This program operates on text file
`test.txt`.

To compile, run `make`.

## How to follow along

`fileio_section.c` is structured with line breaks between file operations. To
follow along, we recommend:

1. Begin by commenting out everything except for the `open()` and `close()`
   code blocks
2. Uncomment one code block at a time. Run `make && ./fileio && cat test.txt`
   to recompile, and see how the new code block changes the text file.

## Section material

Below, we go through each code block in `fileio_section.c`.

### 1. Opening a file

Line 7 opens `test.txt` by `open("test.txt", O_RDONLY)`.

`open()` returns a **file descriptor**. A file descriptor is an unsigned
integer that identifies a file. It can be used in other file system calls,
like `read()` and `write()`, until the file is closed.

Some file descriptors are reserved for special files. File descriptor 0
corresponds to `STDIN`, 1 to `STDOUT`, and 2 `STDERR`.

### 2. Reading file content

Line 10 reads 7 bytes of `test.txt` into buffer `buf` by `read(fd, buf, 7)`.

`read()` returns the number of bytes read. On line 10, `r` is set to `7`.

Note: line 11 sets the 8th byte to the null byte, so that the following line
only prints the first 7 bytes of `buf`.

### 3. Multiple `read()`s: the read/write head

Line 14 reads another 9 bytes of `test.txt`, following the 7 bytes from line
10.

This reads 9 bytes _after_ "welcome", read by line 10. Notably, `read()` calls
do not always start reading from the beginning of a file; it reads starting
after the last character that the previous `read()` read.

As we will see, this `read()` and `write()` calls do not maintain separate
"internal offsets"; a `write()` call advances the read/write head, as do
a `read()`.

Read/write head is also typically known as the file offset. Below we'll use
these two terms interchangeably.

### 4. Reading more than the file size

Line 18 requests reading 40 bytes of the file.

`read()` returns the number of bytes read, which can be lower than its third
argument: the number of bytes requested. As we have already performed two
`read()`s, there are only 22 bytes remaining in the file. Therefore, on line 18
`r` is set to 22.

In general, if `read()` returns a non-negative number that's lower than the
third argument, we have reached the end of file.

### 5. `read()`: checking for error conditions

Line 22 incorrectly passes a negative integer as the file descriptor: file
descriptors are unsigned integers.

Here, `read()` returns `-1` to indicate an error happened. To see the reason
for error, see `errno`. The [man page of `read()`](https://man7.org/linux/man-pages/man2/read.2.html)
provides a list of possible reasons for error, and their corresponding error 
numbers.

### 6. `write()` error-checking and `open()` permissions

Line 26 attempts to add an exclamation point to the end of the file (Question
for you: how did we infer where `write()` is writing to?).

This `write()` call fails. It returns a `-1`, just like `read()` did. Take a 
look at the [man page of `write()`](https://man7.org/linux/man-pages/man2/write.2.html)
to see a list of possible errors.

Line 26 fails because we opened our file with read-only permission. On line 7,
the second argument for `open()` is `O_RDONLY`, which stands for read-only.

You can find a list of possible flags for `open()` on its 
[man page](https://man7.org/linux/man-pages/man2/open.2.html).

### 7. Re-open file with read-write permission

Line 29 and 30 closes the file, and re-opens it with read-write permission.

### 8. Writing to file

Line 32 writes an exclamation point to the beginning of the file.

Run `cat test.txt`: where is the exclamation point written to?

Recall that `test.txt`'s internal read/write head was advanced to the end of
this file on line 18. Why didn't we write the exclamation point to the end
instead?

The reason is line 29, where `test.txt` is closed. Whenever a file is closed,
its internal read/write head is no longer maintained. We write to the beginning
again after it is opened.

### 9. Consecutive `write()` calls

Line 35 writes another exclamation point to `test.txt`.

This line writes an exclamation point as the file's second character. This is
because the previous `write()` call advanced the read/write head to offset 2.

### 10. `lseek()`: moving the read/write head

Sometimes, it is useful to move the read/write head without actually performing
any reads or writes. `lseek()` does exactly this. 

On line 38, `lseek()` advances the read/write head by 5. It moves the 
read/write head from 2 (due to the 2 previous `write()`s) to 7.

`SEEK_CUR`, the third argument to `lseek()`, specifies that we're updating the
file offset based on the current file offset value. New file offset is the
current file offset + N, where N is the second argument.

### 11. `lseek()`: seek relative to end-of-file

`lseek()` also supports seeking relative to the end of a file, with `SEEK_END`.

Here, we seek to the end of the file and writes an exclamation point. This
overwrites the previous, last character `\n` to "!".

Running `cat test.txt` should no longer print the file with a newline; you
may see your terminal prompt rendered immediately after the file's content.

### 12. `lseek()`: setting an absolute file offset

Another useful `lseek()` operation is to set the read/write head directly.
This is achieved via flag `SEEK_SET`.

Line 42 and 43 writes exclamation point to the 10th byte of the file. Try
printing the file's content and see what this does!

### 13. Writing multiple characters to a file

So far, we have only written a single character to a file at a time. Line 51
demonstrates how to write multiple bytes to a file.

It is up to the programmer to specify `write()`'s third argument correctly.
A number that's too large may lead to invalid memory access, leading to a
program crash.

### 14. Mixing `read()`s and `write()`s 

Line 53 performs a `read()` after a `write()`. As we have seen, `read()`s
and `write()`s share the same file offset for a file descriptor. Here, because
`write()` has advanced the file offset to after "FILE IO ", the `read()` call
reads 8 bytes after "IO ".

## Questions?

That's all of the section material! If you have any questions, feel free to
make a post on Ed, and we'll answer your questions there!
