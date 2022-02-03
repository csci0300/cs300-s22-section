#include <stdio.h>
#include <stdlib.h>

void weird_swap(int **arr, int *num){
	// TODO: Swap the first element of arr with num! 
}
int main(){
	int* arr = {2, 2};
	int num = 1;
	
	weird_swap(&arr, &num);
	printf("Weird swap results: %d, %d\n", *arr, num);

	return 0;
}
