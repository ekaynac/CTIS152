#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int num)
{
	int i, res =1;
	for (i = 2; i <= num; i++)
		res *= i;	
	return res;
}

int permutation(int num1, int num2)
{
	return factorial(num1) / factorial(num1 - num2);
}

int combination(int num1, int num2)
{
	int permu, res;
	permu = permutation(num1, num2);
	res = permu / factorial(num2);
	return res;
}

int main(void)
{
	int num1, num2;
	do {
		printf("Enter n value: ");
		scanf("%d", &num1);
	} while (num1 <= 0);
	printf("\n");
	do {
		printf("Enter n value: ");
		scanf("%d", &num2);
	} while (num2 <= 0 || num2>num1);

	printf("P(%d, %d) = %d\n", num1, num2, permutation(num1, num2));
	printf("C(%d, %d) = %d", num1, num2, combination(num1, num2));
}