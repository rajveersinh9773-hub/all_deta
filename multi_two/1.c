#include<stdio.h>
int main() {
    char i = 'A';
    do {
        printf("%c ", i);
        i += 4;
    } while (i <= 'Z');
    return 0;
}