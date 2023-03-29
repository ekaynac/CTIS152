#include <stdio.h>

int main(void)
{
	double array[4][3] = { { 21.70, 43.71, 14.30 }, { 39.21, 25.97, 55.18 }, { 77.18, 82.7, 54.89 }, { 37.51, 41.99, 22.22 } };

	printf("%p\n", array);
	printf("%p\n", array + 1);
	printf("%p\n", *(array + 1));
	printf("%p\n", *array + 1);
	printf("%f\n", *(*array + 1)); // 43.71
	printf("%f\n", **(array + 1)); // 39.21
	printf("%f\n", *(*(array)+1) + 2); // 45.71
	printf("%p\n", *(array + 1) + 2);
	printf("%f\n", *(*(array + 1) + 2)); // 55.18
}