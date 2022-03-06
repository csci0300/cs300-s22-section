# CC := x86_64-linux-gnu-gcc-9
CC := gcc

CFLAGS := -O0 -g -std=c99 -Wall -Werror

.PHONY: all clean

all: stack1 stack2 stack3 stack4 example

example: example.c
	$(CC) $(CFLAGS) -o $@ $^
	# @ x86_64-linux-gnu-objdump -d $@ > asm_ex.txt
	@ objdump -d $@ > asm_ex.txt

stack1: stack1.c
	$(CC) $(CFLAGS) -o $@ $^
	# @ x86_64-linux-gnu-objdump -d $@ > asm1.txt
	@ objdump -d $@ > asm1.txt
	
stack2: stack2.c
	$(CC) $(CFLAGS) -o $@ $^
	# @ x86_64-linux-gnu-objdump -d $@ > asm2.txt
	@ objdump -d $@ > asm2.txt

stack3: stack3.c
	$(CC) $(CFLAGS) -o $@ $^
	# @ x86_64-linux-gnu-objdump -d $@ > asm3.txt
	@ objdump -d $@ > asm3.txt

stack4: stack4.c
	$(CC) $(CFLAGS) -o $@ $^
	# @ x86_64-linux-gnu-objdump -d $@ > asm2.txt
	@ objdump -d $@ > asm4.txt

clean:
	rm -rf stack1 stack2 stack3 stack4 example asm1.txt asm2.txt asm3.txt asm4.txt asm_ex.txt
