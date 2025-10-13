#include <stdio.h>
#include <string.h>

//1: Length Finder
void lengthFinder()
{
    char str[100];
    char *ptr;
    int length = 0;

    printf("\nLength Finder\n");
    printf("Enter any string: ");

    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    ptr = str;

    while (*ptr != '\0')
    {
        length++;
        ptr++;
    }

    printf("The length of string is: %d\n", length);
}

//2: Cubes Generator

void cubesGenerator()
{
    int a[10][10], n;
    int *ptr;

    printf("Cubes Generator\n");
    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nCubes of all elements:\n");
    ptr = &a[0][0];
    for (int i = 0; i < n * n; i++)
    {
        int cube = (*ptr) * (*ptr) * (*ptr);
        printf("%d ", cube);
        if ((i + 1) % n == 0)
            printf("\n");
        ptr++;
    }

    
}