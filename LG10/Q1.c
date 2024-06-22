#include <stdio.h>
#include <string.h>

#define SIZE 25
#define NAMEMAX 25
int binarySearch(char charr[][NAMEMAX], int top, int bottom, char search[NAMEMAX]){
    int mid = (top + bottom ) /2;
    while(top!=bottom)
    {
        if (strcmp(charr[mid], search) == 1)
            return mid;
        else if (strcmp(charr[mid], search) > 0)
            top = mid+1;
        else
            bottom = mid-1;
    }
}
int readFile(FILE* inp, char charr[][NAMEMAX])
{
    int r = 0; 
    while (fscanf(inp, " %[^\n]s", *(charr+r)) != EOF){
        r++;
    }
    return r;
}

int main (void)
{
    char charr[NAMEMAX][SIZE],
    search[NAMEMAX];
    int cnt;
    FILE *inp;

    inp = fopen("/Users/eneskaynakci/CTIS152/LG10/flowers.txt","r");


    cnt = readFile(inp, charr);
    printf("The number of words in the text file: %d\n\n", cnt);
    printf(" The List of Flowers\n");
    printf("*********************\n");
    for(int i = 0; i<NAMEMAX;i++){
        printf("%s\n", charr[i]);
    }
    do{
        printf("Enter a flower name to search (or END to stop searching): ");
        scanf(" %[^\n]s", search);
    } while()
    return 0;
}