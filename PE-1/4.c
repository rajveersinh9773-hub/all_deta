#include <stdio.h>

int main() {
    int arr[10], *ptr;
    printf("Enter 10 elements:\n");
    for(int i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    ptr = arr;
    printf("Even elements: ");
    for(int i = 0; i < 10; i++) {
        if(*(ptr + i) % 2 == 0)
            printf("%d ", *(ptr + i));
    }
    printf("\n");
    return 0;
}
