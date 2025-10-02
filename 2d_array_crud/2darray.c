#include <stdio.h>

int main() {
    int row = 10, col = 10;
    int arr[10][10]; 

    while (1<2) {

        printf("\n--- Welcome to our program ---\n\n\n");


        printf("enter 1 to make array\n");
        printf("enter 2 to print array\n");
        printf("enter 3 to update array\n");
        printf("enter 4 to exit\n\n");

        printf("enter your choice: ");
        int num;
        scanf("%d", &num);

        if (num == 1) {
            printf("enter number of rows: ");
            scanf("%d", &row);
            printf("enter number of columns: ");
            scanf("%d", &col);
            printf("enter %d elements:\n", row * col);
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    scanf("%d", &arr[i][j]);
                }
            }
            printf("2D array created successfully.\n");
        } 
        else if (num == 2) {
                printf("2D array elements:\n");
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < col; j++) {
                        printf("%d ", arr[i][j]);
                    }
                    printf("\n");
                }
            
        } 
        else if (num == 3) {
                int i, j, val;
                printf("enter row index (1 to %d): ", row);
                scanf("%d", &i);
                printf("enter column index (1 to %d): ", col);
                scanf("%d", &j);
                printf("enter new value: ");
                scanf("%d", &val);
                arr[i][j] = val;
                printf("value updated.\n");
        } 
        else if (num == 4) {
            printf("exiting program.\n");
            break;
        }
        else {
            printf("invalid option.\n");
        }
    }
    return 0;
}
