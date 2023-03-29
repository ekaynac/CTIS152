#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ROW 7
#define COL 4
void readFromFile(FILE* inp, double mat[][COL])
{
	for (int r = 0; r < ROW; r++)
		for (int c =0; c <COL; c++)
			fscanf(inp, "%lf", &mat[r][c]);
}
void display(double mat[ROW][COL])
{
	printf("The contents of the array is:\n");
	for (int r = 0; r < ROW; r++)
	{
		for (int c = 0; c < COL; c++)
			printf("%6.1f", mat[r][c]);
		printf("\n");
	}
}
void swapArrs(double* arr1, double* arr2, int size)
{
	double temp;
	for (int i = 0; i < size; i++)
	{
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
}
void swapRows(double mat[][COL], int row1, int row2)
{
	printf("Zort");
}
int main(void)
{
	FILE* inp;
	inp = fopen("matrix.txt", "r");

	if (inp == NULL)
		printf("Error!");
	else
	{
		int row1, row2;
		double mat[ROW][COL];
		readFromFile(inp, mat);
		display(mat);

		do {
			printf("Enter two row indices to swap: ");
			scanf("%d %d", &row1, &row2);
		} while (!(row1 < ROW && row1 >= 0 && row2 < ROW && row2 >= 0));
		swapArrs(mat[row1], mat[row2], COL);
		display(mat);
	}
}