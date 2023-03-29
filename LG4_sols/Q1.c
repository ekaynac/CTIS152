#include <stdio.h>
#include <stdlib.h>
void readFile (FILE* inp, char** arr)
{
    int cnt=0;
    fscanf(inp, "%s", arr[cnt++]);
}

int main (void)
{
    char **arr;
    int rownum, colnum;
    arr = (char**)malloc(sizeof(char*));
    FILE* inp;
    inp=fopen("D:/Github/CTIS152/LG4_sols/Files/words.txt","r");

    fscanf(inp, "%d", &rownum);

    for (int i = 0; i< rownum; i++)
        *(arr+i) = (char*)malloc(10*sizeof(char));

    readFile(inp, arr);
    

}