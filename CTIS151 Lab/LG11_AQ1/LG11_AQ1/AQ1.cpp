#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void parser(int amount, int* bnknt100, int* bnknt50, int* bnknt10, int* bnknt5)
{
	while (amount >= 100)
	{
		amount -= 100;
		*bnknt100+=1;
	}
	while (amount >= 50)
	{
		amount -= 50;
		*bnknt50 += 1;
	}
	while (amount >= 10)
	{
		amount -= 10;
		*bnknt10 += 1;
	}
	if (amount == 5)
		*bnknt5 += 1;
}

int main(void)
{
	int amount,
		bnknt100 = 0, bnknt50 = 0, bnknt10 = 0, bnknt5 = 0;

	do {
		printf("Enter the amount to be withdrawn (multiple of 5): ");
		scanf("%d", &amount);
		if (amount % 5 != 0)
			printf("%d TL cannot be given.\nMoney amount should be a multiple of 5 TL.\n\n",amount);
	} while (amount % 5 != 0);

	parser(amount, &bnknt100, &bnknt50, &bnknt10, &bnknt5);

	printf("\nFor 965, the ATM will give the following banknotes:\n");
	printf("%d unit(s) of 100 TL, %d unit(s) of 50 TL, %d unit(s) of 10 TL, %d unit(s) of 5 TL", bnknt100, bnknt50, bnknt10, bnknt5);
}