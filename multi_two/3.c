#include<stdio.h>
int main(){
    int first,last,sum,num;
   
    printf("enter your number : ");
    scanf("%d",&num);

    last = num % 10;
    first = num / 100;
    sum = first + last;
    printf(" you first and last digit sum is : %d",sum);

    return 0;
}