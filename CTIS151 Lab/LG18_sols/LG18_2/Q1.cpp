#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ROW 20
#define COL 4
int readFromFile(FILE* inp, int* id, double points[][COL])
{
	int status, r=0;
	status = fscanf(inp, "%d %lf %lf %lf %lf", &id[r], &points[r][0], &points[r][1], &points[r][2], &points[r][3]);
	while (status != EOF)
	{
		r++;
		status = fscanf(inp, "%d %lf %lf %lf %lf", &id[r], &points[r][0], &points[r][1], &points[r][2], &points[r][3]);
	}
	return r;
}
void display(int* id, double points[][COL], int std)
{
	double avg;
	printf("ID\tR\tL\tS\tW\tELIGIBLE\tOVERALL\n");
	for (int i = 0; i < std; i++)
	{
		printf("%-7d %-7.2f %-7.2f %-7.2f %-7.2f  ", id[i], points[i][0], points[i][1], points[i][2], points[i][3]);

		avg = (points[i][0] + points[i][1] + points[i][2] + points[i][3]) / COL;
		if (avg < 6.5)
			printf("N\t\t");
		else
			printf("Y\t\t");
		printf("%.2f\n", avg);
	}
		
}
int main(void)
{
	FILE* inp;
	inp = fopen("ielts.txt", "r");

	if (inp == NULL)
		printf("Error!");
	else
	{
		int std,
			id[ROW];
		double points[ROW][COL];
		std = readFromFile(inp, id, points);
		display(id, points, std);
	}
}