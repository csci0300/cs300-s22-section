#include <stdio.h>
#include <stdlib.h>

void weird_swap(int **arr, int *num) {
    int temp = **arr;
    **arr = *num;
    *num = temp;
}
int main(){
	int arr[2] = {2, 2};
	int* arr_ptr = arr;
	int num = 1;

	weird_swap(&arr_ptr, &num);
	printf("Weird swap results: %d, %d\n", arr[0], num);

    return 0;
}
