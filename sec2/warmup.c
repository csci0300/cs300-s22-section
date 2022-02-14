#include <stdio.h>
#include <stdlib.h>

int main() {
    // For each print, answer the following questions:
    // * What gets printed?
    // * Is there undefined behavior?
    // * Is a segfault possible?
    
    // 1. 
    int my_int;
    printf("The value of my_int is %d\n", my_int);






























    // 2.
    my_int = 5;
    printf("my_int is now %d\n", my_int);






























    // 3. 
    char* my_str;
    printf("my_str is %s\n", my_str);
 




























   
    // 4.
    my_str[0] = 'H';
    my_str[1] = 'i';
    my_str[2] = '!';
    printf("my_str is %s\n", my_str);






























    // 5.
    my_str = malloc(3);
    my_str[0] = 'H';
    my_str[1] = 'i';
    my_str[2] = '!';
    printf("my_str is %s\n", my_str);
    free(my_str);






























    // 6.
    my_str = malloc(4);
    my_str[0] = 'H';
    my_str[1] = 'i';
    my_str[2] = '!';
    my_str[3] = '\0';
    printf("my_str is %s\n", my_str);
    free(my_str);





























    // 7.
    my_str = "Hi!";
    printf("my_str is %s\n", my_str);

}
