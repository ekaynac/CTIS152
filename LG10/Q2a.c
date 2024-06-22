#include <stdio.h>

int digits(int num){
    printf("\t%d", num%10);
    num = num/10;
    if (num >0)
        digits(num);
}
int main(void){
    printf("Enter a number: ");
    int num;
    scanf("%d", &num);
    printf("Digits of the number %d are:\n", num);
    digits(num);
}