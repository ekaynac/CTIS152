#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
void input(int* arr, int cnt)
{
	printf("Enter %d grades: ",cnt);
	for (int i = 0; i < cnt; i++)
		scanf("%d", arr + i);
}
double findGrade(int* arr, int cnt)
{
	int sum = 0;
	for (int i = 0; i < cnt; i++)
		sum += *(arr + i);
	return sum * 4. / 10;
}
int main(void)
{
	int* p;
	int n;

	do {
		printf("How many grades? ");
		scanf("%d", &n);

		if (n != -1)
		{
			p = (int*)malloc(n * sizeof(int));

			input(p, n);

			printf("The %%40 of the total grade : %.2f\n\n", findGrade(p, n));

			free(p);
		}
	} while (n != -1);
	

}