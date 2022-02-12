#include <stdio.h>
#include <stdlib.h>

struct my_struct {
    int* fav_num_ptr;
    int other_num;
};

struct my_struct* make_struct() {
    int i = 12;
    int j = 7;

    struct my_struct* st = (struct my_struct*) malloc(10);

    st->fav_num_ptr = &i;
    st->other_num = j;

    return st;
}


int main() {
    struct my_struct* st = make_struct();
    printf("My favorite number is: %d\n", *(st->fav_num_ptr));
}
