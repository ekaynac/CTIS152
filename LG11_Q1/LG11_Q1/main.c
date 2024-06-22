#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sumDivisor(int num, int div){
    if(div == 1)
        return 1;
    if(num % div == 0)
        return div + sumDivisor(num, div-1);
    return sumDivisor(num, div-1);
}

int main(void) {
    int num;
    
    do{
        printf("Enter a non-negative number: ");
        scanf("%d", &num);
    }while(num<=0);
    
    int sum = sumDivisor(num, num/2);
    if(sum == num)
        printf("%d is a perfect number!\n", num);
    else
        printf("%d is NOT a perfect number!\n",num);
}
