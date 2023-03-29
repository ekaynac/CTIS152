#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ROW 20
#define COL 4
int readFromFile(FILE* inp, int* id, int points[][COL])
{
	int status, r = 0;
	status = fscanf(inp, "%d %d %d %d %d", &id[r], &points[r][0], &points[r][1], &points[r][2], &points[r][3]);
	while (status != EOF)
	{
		r++;
		status = fscanf(inp, "%d %d %d %d %d", &id[r], &points[r][0], &points[r][1], &points[r][2], &points[r][3]);
	}
	return r;
}
void findTeamAvg(int points[][COL], double* teamavg, int numofteams)
{
	int sum;
	double avg;
	for (int r = 0; r < numofteams; r++)
	{
		sum = 0;
		for (int c = 0; c < COL; c++)
			sum += points[r][c];
		avg = 1.*sum / COL;
		teamavg[r] = avg;
	}
}
void findGameAvg(int points[][COL], double* gameavg, int numofteams)
{
	int sum;
	double avg;
	for (int c = 0; c < COL; c++)
	{
		sum = 0;
		for (int r = 0; r < numofteams; r++)
			sum += points[r][c];
		avg = 1. * sum / numofteams;
		gameavg[c] = avg;
	}
}
void display(int* id, double *avg, int std)
{
	for (int i = 0; i < std; i++)
	{
		printf("%-7d\t\t%-7.2f\n", id[i], avg[i]);
	}
}
int main(void)
{
	FILE* inp;
	inp = fopen("bowling.txt", "r");

	if (inp == NULL)
		printf("Error!");
	else
	{
		int std,
			id[ROW],
			points[ROW][COL],
			gamenum[COL] = { 1,2,3,4 };
		double teamavg[ROW],
			gameavg[COL];
		std = readFromFile(inp, id, points);
		findTeamAvg(points, teamavg, std);
		findGameAvg(points, gameavg, std);
		printf("Team Number     Average\n");
		printf("***********     *******\n");
		display(id, teamavg, std);
		printf("Game Number     Average\n");
		printf("***********     *******\n");
		display(gamenum, gameavg, COL);
	}
}