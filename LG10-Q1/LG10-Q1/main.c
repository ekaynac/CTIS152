#include <stdio.h>

#define SIZE 20
#define NAMEMAX 20

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
    char charr[SIZE][NAMEMAX];
    int cnt;
    FILE *inp;

    inp = fopen("/Users/eneskaynakci/CTIS152/LG10/flowers.txt","r");

    
    cnt = readFile(inp, charr);
    printf("The number of words in the text file: %d\n\n", cnt);
    printf(" The List of Flowers\n");
    printf("*******\n");
    return 0;
}
