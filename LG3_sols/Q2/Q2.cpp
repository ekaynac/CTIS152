#include <stdio.h>
#define ROWSIZE 3
#define COLSIZE 3

int pow(int num, int pow)
{
	int res = 1;
	for (int i = 0; i < pow; i++)
		res *= num;
	return res;
}

int main(void)
{
	int arr[ROWSIZE][COLSIZE],
		num = 3, cnt=1;

	printf("Element Name      \tValue\t Address\n");
	printf("------------------\t-----\t--------\n");

	for (int r = 0; r<ROWSIZE;r++)
		for (int c = 0; c < COLSIZE; c++)
		{
			*(*(arr + r) + c) = pow(3, cnt++);
			printf("*(*(arr + %d) + %d)\t%5d\t%p\n", r, c, *(*(arr + r) + c), *(arr + r) + c);
		}
	
	return 0;
}