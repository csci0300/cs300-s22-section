# CC := x86_64-linux-gnu-gcc-9
CC := gcc

CFLAGS := -O0 -g -std=c99 -Wall -Werror

.PHONY: all clean

all: stack1 stack4

stack1: stack1.c
	$(CC) $(CFLAGS) -o $@ $^
	# @ x86_64-linux-gnu-objdump -d $@ > asm1.txt
	@ objdump -d $@ > asm1.txt

stack4: stack4.c
	$(CC) $(CFLAGS) -o $@ $^
	# @ x86_64-linux-gnu-objdump -d $@ > asm2.txt
	@ objdump -d $@ > asm4.txt

clean:
	@ rm -rf stack1 stack4 asm1.txt asm2.txt
