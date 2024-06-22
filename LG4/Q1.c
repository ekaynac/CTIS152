#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void readFile(FILE* inp, char **charr)
{
    int r = 0; 
    while (fscanf(inp, "%s", *(charr+r)) != EOF){
        r++;
    }
}

int main (void)
{
    char **charr;
    int cnt, colnum;
    FILE *inp;

    inp = fopen("/Users/eneskaynakci/CTIS152/LG4/words.txt","r");
    fscanf(inp, "%d", &cnt);
    printf("The number of words in the text file: %d\n\n", cnt);
    charr = (char**)malloc(cnt*sizeof(char*));

    for (int i = 0; i<cnt; i++)
        *(charr+i) = (char*)malloc(SIZE*sizeof(char));

    readFile(inp, charr);
    printf(" WORDS \n");
    printf("*******\n");
    for (int i = 0; i<cnt; i++)
    {
        for (int j = 0; j<SIZE; j++)
            printf("%c", *(*(charr+i)+j));
        printf("\n");
        
    }
    printf("\nEnter the column number: ");
    scanf("%d", &colnum);
    for (int i = 0; i<cnt; i++)
        printf("%c", *(*(charr+i)+colnum-1));
    return 0;
}