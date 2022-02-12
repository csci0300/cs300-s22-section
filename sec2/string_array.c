#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** copy_string_array(char** arr, int count) {
    char** new_arr;

    for (int i = 0; i < count; i++) {
        strcpy(new_arr[i], arr[i]);
    }

    return new_arr;
}

/**
 * A simple program that accepts names as arguments
 * and prints those names out with their first letter uppercased
 */
int main(int argc, char** argv) {
    int name_count = argc - 1;
    char** start_of_names = argv + 1;

    char** copy_of_names = copy_string_array(start_of_names, name_count);

    for (int i = 0; i < name_count; i++) {
        copy_of_names[i][0] = copy_of_names[i][0] - 32;
        printf("%s\n", copy_of_names[i]);
    }

}
