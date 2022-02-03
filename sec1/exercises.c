#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ########################### EXERCISE 1 ###########################
void addTwoNums(int* num1, int* num2, int* result) {
    // TODO: Add values of num1 and num2 and store it in result
}

void exercise1() {
    int a = 10;
    int b = 10;
    int c;

    addTwoNums(&a, &b, &c);
    printf("EXPECTED: addTwoNums: 10 + 10 = 20\n");
    printf("GOT: addTwoNums: %d + %d = %d\n", a, b, c);
}

// ########################### EXERCISE 2 ###########################

void exercise2() {
    char* word = "Hello World!";
    char* x = (char*)(((int*)word) + 1);

    int increment = 0;  // TODO: CHANGE THIS SO x == y
    char* y = word + increment;

    printf("EXPECTED: x == y \n");
    printf("x = %s\n", x);
    printf("y = %s\n", y);
}

// ########################### EXERCISE 3 ###########################

char* extract_cs300(char* content) {
    char* cs300;
    // TODO: cs300 should now point to the "CS300!" of content

    return cs300;
}

void exercise3() {
    char* content = "Hello CS300!";
    char* cs300 = extract_cs300(content);

    printf("EXPECTED: cs300: CS300!\n");
    printf("GOT: cs300: %s\n", cs300);
}

// ########################### EXERCISE 4 ###########################

/**
 * Copy `numbytes` from `src` to `dest`.
 *
 * No copying occurs if the either pointer is NULL.
 *
 * If neither `dest` or `src` are NULL, assume both pointers point to memory
 * regions with at least `numbytes` of bytes allocated.
 *
 * Memory pointed to by `src` should not be modified under any circumstances
 * (see the `const` qualifier to `src`).
 */
void my_memcpy(void* dest, const void* src, size_t numbytes) {
    // TODO
}

void exercise4() {
    char src[] = {'H','e','l','l','o',' ','C','S','3','0','0','!','\0'};
    char dst[] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0'};

    my_memcpy(NULL, NULL, 30);
    my_memcpy(dst, src, 13);

    printf("EXPECTED: src: Hello CS300!\n");
    printf("GOT: src: %s\n", src);
    printf("EXPECTED: dst: Hello CS300!\n");
    printf("GOT: dst: %s\n", dst);
}

int main() {
    printf("######################## EXERCISE 1 ########################\n");
    exercise1();

    printf("\n######################## EXERCISE 2 ########################\n");
    exercise2();

    printf("\n######################## EXERCISE 3 ########################\n");
    exercise3();

    printf("\n######################## EXERCISE 4 ########################\n");
    exercise4();

    return 0;
}
