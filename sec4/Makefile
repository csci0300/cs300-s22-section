CC := gcc
CCFLAGS := -Wall -Wextra -g

all: fileio testfile

fileio: fileio_section.c
	$(CC) $(CCFLAGS) $^ -o $@
testfile: 
	rm -rf test.txt
	echo "welcome to file io section from cs300" > test.txt
clean: 
	rm -rf fileio
