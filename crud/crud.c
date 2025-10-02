#include<stdio.h>
int main(){
    while (1<2)
    {
        printf("welcome to our program\n\n\n");

        printf("enter 0 to make array");
        printf("enter 1 to print array");
        printf("enter 3 to update array");
        printf("enter 4 to delete array");
        printf("enter 5 to exit");

        int num;
        printf("enter your number : ");
        scanf("%d",num);

        int arr[0];
        int size = 0;

        if (num == 0) {
            printf("How many elements do you want to add in the array? ");
            scanf("%d", &size);
            if (size > 10 || size < 1) {
            printf("Invalid size! Please enter a value between 1 and 10.\n");
            size = 0;
            continue;
            }
            printf("Enter %d elements:\n", size);
            for (int i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
            }
            printf("Array created succefuly.\n");
        } else if (num == 1) {
            if (size == 0) {
            printf("Array is empty.\n");
            } else {
            printf("Array elements: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            }
        } else if (num == 3) {
            if (size == 0) {
            printf("Array is empty.\n");
            } else {
            int i;
            int val;
            printf("Enter index to update (0 to %d): ", size - 1);
            scanf("%d", &i);
            if (i < 0 || i >= size) {
                printf("Invalid index.\n");
            } else {
                printf("Enter new value: ");
                scanf("%d", &val);
                arr[i] = val;
                printf("Value updated.\n");
            }
            }
        } else if (num == 5) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid option.\n");
        }
    }
    
}