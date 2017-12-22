#include <stdio.h>
#include <stdlib.h>

int **alloc_2d(int rows, int cols)
{
	int i, **arr = malloc(rows * sizeof(int *));

	for (i = 0; i < sizeof(arr); i++)
	{
		arr[i] = malloc(cols * sizeof(int));
	}

	return arr;
}

int main(void)
{
	int **my_array = alloc_2d(5, 10);

	// First array index is row, second is column:
	my_array[2][3] = 3490;

	// The same array access could be made with pointer arithmetic:
	*(*(my_array + 2) + 3) = 3490;

	// By the C spec, the array notation and pointer arithmetic notation
	// are 100% equivalent.

	printf("my_array[2][3] = %d\n", my_array[2][3]);

	return **my_array;
}