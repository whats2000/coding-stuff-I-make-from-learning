#include <stdio.h>
#define SIZE 10
#define ROW 4
#define COL 5

int main(void)
{
	int i, j, k;
	int arr[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int idx = 6;

	for (i = 0; i < SIZE; ++i)
	{
		printf("arr[%d]: %d is located at %p\n", i, arr[i], &arr[i]);
	}

	printf("\n\n");
	printf("%p + (%d - 0) * %d = %p", &arr[0], idx, (&arr[1] - &arr[0]) * sizeof(arr[0]), &arr[0] + (idx - 0) * (&arr[1] - &arr[0]));
	printf("\n\n");

	// matrix
	int matrix[ROW][COL] = {{0, 1, 2, 3, 4},
							{5, 6, 7, 8, 9},
							{10, 11, 12, 13, 14},
							{15, 16, 17, 18, 19}};

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%p ", &matrix[i][j]);
		}
		printf("\n");
	}

	int unit = (&matrix[0][1] - &matrix[0][0]);
	printf("\nMatrix(3, 3) is located at %p\n", &matrix[3][3]);
	printf("%p + ((3-0) * %d + (3-0)) * %d = ", &matrix[0][0], COL, (&matrix[0][1] - &matrix[0][0]) * sizeof(matrix[0][0]));

	printf("%p", &matrix[0][0] + ((3 - 0) * COL + (3 - 0)) * unit);

	return 0;
}