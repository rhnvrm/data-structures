#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main(){


	int n;

	printf("%s\n", "Enter the size of the array: ");

	int *array;

	array = (int*)malloc(n * (sizeof(int)));

	if(array == NULL){
		printf("Error allocating memory\n");
		return 1;
	}

	scanf("%d", &n);

	printf("Enter the %d elements of the array\n", n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &array[i]);
	}

	printf("Enter position where you would like to delete the element: ");

	int pos;//, item;
	scanf("%d", &pos);

	if(pos-1 < n){
		printf("Element %d deleted\n", pos);
		array[pos-1] = INT_MIN; //treating INT_MIN as the deleted value
	}
	else{
		printf("You exceeded the array\n");
	}
	
	for(int i = 0; i < n; i++){
		printf("%d\n", array[i]);
	}

	free(array);

}