#include <stdio.h>
#include <stdlib.h>


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

	printf("Enter position where you would like to insert the new element: ");

	int pos;//, item;
	scanf("%d", &pos);

	if(pos-1 <= n){
		printf("Enter value of the new element: ");
		scanf("%d", &array[pos-1]);
	}
	else{
		printf("You exceeded the array\n");
	}
	
	for(int i = 0; i < n; i++){
		printf("%d\n", array[i]);
	}

	free(array);

}