#include <stdio.h>
#include <stdlib.h>

int main() {
    // For each print, answer the following questions:
    // * What gets printed?
    // * Is there undefined behavior?
    // * Is a segfualt possible?
    

    int my_int;
    printf("The value of my_int is %d\n", my_int);






































    my_int = 5;
    printf("my_int is now %d\n", my_int);







































    char* my_str;
    printf("my_str is %s\n", my_str);







































    my_str[0] = 'H';
    my_str[1] = 'i';
    my_str[2] = '!';
    printf("my_str is %s\n", my_str);








































    my_str = malloc(3);
    my_str[0] = 'H';
    my_str[1] = 'i';
    my_str[2] = '!';
    printf("my_str is %s\n", my_str);
    free(my_str);







































    
    my_str = malloc(4);
    my_str[0] = 'H';
    my_str[1] = 'i';
    my_str[2] = '!';
    my_str[3] = '\0';
    printf("my_str is %s\n", my_str);
    free(my_str);








































    my_str = "Hi!";
    printf("my_str is %s\n", my_str);

}
