#include <stdio.h>
#include <stdlib.h>

#define SIZE_ARRAY 5

int main(){

	int *array = (int*)malloc(SIZE_ARRAY * (sizeof(int)));

	for(int i = 0; i < SIZE_ARRAY; i++){
		scanf("%d", &array[i]);
	}

	int even = 0, odd = 0;

	for(int i = 0; i < SIZE_ARRAY; i++){
		for (int j = 0; j < SIZE_ARRAY; j++)
		{
			if(array[i] + array[j] == 25)
				printf("Pair found! (%d, %d)\n", array[i], array[j]);
		}

		if(i & 1)
			odd++;
		else
			even++;
	}

	printf("# of odd: %d\n# of even: %d\n", odd, even);

	return 0;
}