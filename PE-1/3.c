#include <stdio.h>

void printOdd(int arr[], int n) {
    printf("Odd elements: ");
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 != 0)
            printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10];
    printf("Enter 10 elements:\n");
    for(int i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    printOdd(arr, 10);
    return 0;
}
