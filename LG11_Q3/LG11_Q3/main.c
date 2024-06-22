#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef struct{
    char nick[20];
    char name[10];
    char surname[20];
    char phoneNum[15];
} user_t;

int readFromFile(FILE* inp, user_t* users){
    int cnt = 0;
    while(fscanf(inp, "%s %s %s %s", users[cnt].nick, users[cnt].name,users[cnt].surname,users[cnt].phoneNum) != EOF)
        cnt++;
    return cnt;
}
void swap(user_t* a, user_t* b){
    user_t temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(user_t* users, int cnt){
    if (cnt == 1) {
        return;
    }
    for (int i = 0; i < cnt - 1; i++) {
        if (strcmp(users[i].nick, users[i+1].nick) > 0) {
            swap(&users[i], &users[i+1]);
        }
    }
    bubbleSort(users, cnt-1);
}

void display(user_t* users, int cnt){
    printf("There are %d users in the list.\n\n", cnt);
    printf("Username        \tName               \tSurname          \tPhone          \n");
    printf("****************\t****************** \t******************\t**************\n");
    for (int i = 0; i<cnt; i++)
        printf("%-20s%-20s%-20s%-12s\n",users[i].nick,users[i].name,users[i].surname,users[i].phoneNum);
}

int binarySearch(user_t* users, char *searchword, int bot, int top){
    if (bot > top)
        return -1;
    int mid = (top+bot)/2;
    if(strcmp(users[mid].nick,searchword) == 0)
        return mid;
    else if(strcmp(users[mid].nick,searchword) > 0)
        return binarySearch(users, searchword, bot, mid-1);
    else if(strcmp(users[mid].nick,searchword) < 0)
        return binarySearch(users, searchword, mid+1, top);
    return -1;
}

int main(void) {
    FILE* inp;
    inp = fopen("/Users/eneskaynakci/CTIS152/LG11_files/userinfo.txt","r");
    
    if (inp == NULL){
        printf("Cannot open given txt file!");
    }
    else
    {
        user_t users[50];
        int cnt, res;
        char search[20];
        cnt = readFromFile(inp, users);
        bubbleSort(users, cnt);
        display(users, cnt);
        
        do{
            printf("Enter the username (END for exit): ");
            scanf(" %s", search);
            res = binarySearch(users, search, 0, cnt);
            if ((res == -1) && strcmp(search, "END") != 0)
                printf("NOT FOUND\n");
            else if (strcmp(search, "END") != 0)
                printf("%-20s%-20s%-20s%-12s\n",users[res].nick,users[res].name,users[res].surname,users[res].phoneNum);
        } while(strcmp(search, "END") != 0);
    }
}
