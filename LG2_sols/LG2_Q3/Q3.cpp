#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 500

int compare(FILE *out, int* arr, int cnt)
{
	int dupcnt=0;
	for (int i = 0; i < cnt; i++)
		for (int j = i + 1; j < cnt; j++)
			if (*(arr + i) == *(arr + j))
			{
				fprintf(out, "%d\n", *(arr + i));
				dupcnt++;
			}
	return dupcnt;
}

int main(void)
{
	FILE* out;
	out = fopen("matchedItems.txt", "w");
	int cnt = -1, dupcnt;
	int arr[SIZE];

	do {
		cnt++;
		printf("Enter a number: ");
		scanf("%d", arr + cnt);
	} while (*(arr+cnt) != -99);
	dupcnt = compare(out, arr, cnt);
	printf("\nThe number of duplicate elements found in the array -> %d", dupcnt);
	

	return 0;
}