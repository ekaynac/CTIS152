#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isPalindrome(char *charr){
    if (strlen(charr)<=1)
        return 1;
    else if(*charr != *(charr+strlen(charr)-1))
        return 0;
    else{
        # to assign NULL to the last char oh the array
        *(charr + strlen(charr) -1) = '\0';
        return isPalindrome(charr+1);
    }
    
    
}

int main(void) {
    char word[15];
    
    printf("Enter a word: ");
    scanf("%s", word);
    
    if(isPalindrome(word)==1)
        printf("The word entered was a palindrome\n");
    else
        printf("The word entered was NOT a palindrome\n");
    
    return 0;

}
