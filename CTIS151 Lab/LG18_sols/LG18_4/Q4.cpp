#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ROW 20
#define COL 5

int readFromFile(FILE* inp, int mat[][COL])
{
	int status, r = 0;
	status = fscanf(inp, "%d %d %d %d %d", &mat[r][0], &mat[r][1], &mat[r][2], &mat[r][3], &mat[r][4]);
	while (status != EOF)
	{
		r++;
		status = fscanf(inp, "%d %d %d %d %d", &mat[r][0], &mat[r][1], &mat[r][2], &mat[r][3], &mat[r][4]);
	}
	return r;
}
void display(int mat[][COL], int rowsize)
{
	for (int r = 0; r < rowsize; r++)
	{
		for (int c = 0; c < COL; c++)
			printf("%3d", mat[r][c]);
		printf("\n");
	}
}
int sumOfMinor(int mat[][COL])
{
	int sum = 0;
	for (int i = 0; i < COL; i++)
	{
		sum += mat[i][COL - 1 - i];
	}
	return sum;
}
int productOfRow(int mat[][COL], int rownum)
{
	int product = 1;
	for (int i = 0; i < COL; i++)
		product *= mat[rownum][i];
	return product;
}
int main(void)
{
	FILE* inp;
	inp = fopen("input1.txt", "r");

	if (inp == NULL)
		printf("Error!");
	else
	{
		int rowsize,
			mat[ROW][COL];
		rowsize = readFromFile(inp, mat);
		display(mat, rowsize);
		if (rowsize != COL)
		{
			int rownum;
			printf("\nThe matrix is not a SQUARE matrix\n");
			printf("Enter the row number: ");
			scanf("%d", &rownum); rownum--;
			printf("The product of the elements on the given row: %d", productOfRow(mat, rownum));
		}

		else
		{
			printf("\nThe matrix is a square matrix\n");
			printf("The sum of the elements on the Minor Diagonal is: %d", sumOfMinor(mat));
		}

		
	}
}