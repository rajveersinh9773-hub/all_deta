#include <stdio.h>

int main() {
    int marks[5];
    float sum = 0, avg;
    char grade;

    printf("Enter marks for 5 subjects (out of 100):\n");
    for(int i = 0; i < 5; i++) {
        scanf("%d", &marks[i]);
        sum += marks[i];
    }

    avg = sum / 5;

    if(avg >= 90) grade = 'A';
    else if(avg >= 75) grade = 'B';
    else if(avg >= 60) grade = 'C';
    else if(avg >= 45) grade = 'D';
    else grade = 'F';

    printf("\nAverage = %.2f", avg);
    printf("\nGrade = %c\n", grade);

    return 0;
}
  