#include<stdio.h>
int main(){
    int num;
    int count = 0;

    printf("enter you number : ");
    scanf("%d",&num);
    while (num > 0)
    {
        count++;
        num = num / 10;
    }
    printf("you  digit is %d",count);
    return 0;
}