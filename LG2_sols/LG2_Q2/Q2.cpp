#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pow(int num, int pow)
{
	int res = 1;
	for (int i = 0; i < pow; i++)
		res *= num;
	return res;
}
int main(void)
{
	FILE* out;
	out = fopen("sequence.txt", "w");

	int num = 9;
	int arr[6] = { 0 };
	for (int i = 0; i < 6; i++)
		*(arr + i) = pow(num, i + 1);
	
	fprintf(out,"Element Name \tValue\tAddress \n");
	fprintf(out,"-------------\t-----\t--------\n");
	for (int i = 0; i < 6; i++)
		fprintf(out, "* (nums + %d)%9d\t%p\n", i, *(arr + i), arr + i);
	printf("Successful! Please see the sequence.txt file for the output.");
	return 0;
}