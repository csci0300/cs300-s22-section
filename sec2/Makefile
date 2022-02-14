

CFLAGS = -fsanitize=address -ggdb3 

BINS = mem_error1 mem_error2 string_array warmup

.PHONY = clean all

all: mem_error1 mem_error2 string_array warmup

mem_error1: mem_error1.c
	gcc $(CFLAGS) -o $@ $?

mem_error2: mem_error2.c
	gcc $(CFLAGS) -o $@ $?

string_array: string_array.c
	gcc $(CFLAGS) -o $@ $?

warmup: warmup.c
	gcc $(CFLAGS) -o $@ $?

clean:
	rm $(BINS)

