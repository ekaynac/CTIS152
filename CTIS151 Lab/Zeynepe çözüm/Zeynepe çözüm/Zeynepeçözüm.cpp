#define _CRT_SECURE_NO_WARNINGS
#define COL 4
#define ROW 15
#include<stdio.h>
int readFromFile(FILE* inp, int arr1[], int arr2[][COL])
{
    int num = 0, status;
    status = fscanf(inp, "%d %d %d %d %d", &arr1[num], &arr2[num][0], &arr2[num][1], &arr2[num][2], &arr2[num][3]);
    while (status != EOF)
    {
        num++;
        status = fscanf(inp, "%d %d %d %d %d", &arr1[num], &arr2[num][0], &arr2[num][1], &arr2[num][2], &arr2[num][3]);
    }
    return(num);
}
void findTeamAvg(int arr1[][COL], double arr2[], int num)
{
    double sum, avg;
    int r, c;
    for (r = 0; r < num; r++) {
        sum = 0;
        for (c = 0; c < COL; c++)
            sum += arr1[r][c];
        avg = sum / COL;
        arr2[r] = avg;
    }
}
void findGameAvg(int arr1[][COL], double arr2[], int num)
{
    double sum, avg;
    int r, c;
    for (c = 0; c < COL; c++) {
        sum = 0;
        for (r = 0; r < num; r++)
            sum += arr1[r][c];
        avg = sum / num;
        arr2[c] = avg;
    }
}
void displayGameAvg(double arr[])
{
    int i;
    for (i = 0; i < COL; i++)
        printf("%d\t%.2f\n", i+1, arr[i]);
}
void displayArr(int arr1[][COL], int num)
{
    for (int r = 0; r < num; r++)
    {
        for (int c = 0; c < COL; c++)
            printf("%d\t", arr1[r][c]);
        printf("\n");
    }    
}
int main()
{
    FILE* inp = fopen("bowling.txt", "r");
    if (inp == NULL)
        printf("Error");
    else
    {
        int num, arr1[ROW], arr2[ROW][COL];
        double arr3[ROW], arr4[COL];
        num = readFromFile(inp, arr1, arr2);
        printf("Team Number   Average\n");
        printf("***********   *******\n");
        findTeamAvg(arr2, arr3, num);
        for (int i = 0; i < num; i++) {
            printf("%d\t\t%.2f\n", arr1[i], arr3[i]);
        }
        printf("Game Number   Average\n");
        printf("***********   *******\n");

        findGameAvg(arr2, arr4, num);
        displayGameAvg(arr4);
    }
    fclose(inp);
    return 0;
}