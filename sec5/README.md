# Section 5

Welcome to the synchronization section! We'll cover the basics of multithreaded programming in C++.

## Warmup

### `sample01`

What is the expected output of this program? How many threads are running concurrently at once?

### `sample02`

What is the expected output of this program? How many threads are running concurrently at once?

### `sample03`

What is the expected output of this program? How many threads are running concurrently at once?

## Prime Finding

### `primefinder-naive.cc`

This is a basic single-threaded implementation of finding the number of primes below some specified
number (here, `MAX_LIMIT = 20,000,000`). Note how long it takes to finish running!

### `primefinder-threads.cc`

In here, you will implement a basic multi-threaded version of the prime finding program.

### `primefinder-queue.cc`

In here, you'll improve on `primefinder-threads.cc` by more evenly distributing the work among
threads.

### `primefinder-ends.cc`

> Please don't open this file until you're done with `primefinder-queue.cc`!

In here, you'll build on `primefinder-queue.cc`, and print out any prime that ends in a specific
digit (currently `ENDS_IN = 7`) on demand.

## Debugging

### `transactions-deadlock.cc`

In here, we'll explore a basic version of transferring money between two users, and how a lack of
lock ordering can result in a deadlock. We'll look at some tips for using GDB on multi-threaded
programs.

Useful GDB commands:

- `Ctrl-Z`: halt execution of the program (without killing it)
- `[i]nfo threads`: print information about every thread currently running
- `thread [#]`: switch to a specific thread's line of execution
- `backtrace`: view all previously executed instructions
- `frame [#]`: go to the specified stack frame (e.g. to view local variables)
- `thread apply all [CMD]`: apply `[CMD]` to all threads (i.e. useful with `backtrace`)
