#include <stdio.h>

float findAverage(int a[3][3], int rows, int cols) {
    int sum = 0, count = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            sum += a[i][j];
            count++;
        }
    }
    return (float)sum / count;
}

int main() {
    int a[3][3];
    printf("Enter 9 elements of 3x3 matrix:\n");
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);

    printf("Average = %.2f\n", findAverage(a, 3, 3));
    return 0;
}
