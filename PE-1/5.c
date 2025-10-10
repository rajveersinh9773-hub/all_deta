#include <stdio.h>

int main() {
    int i, j, k;
    for(i = 10; i >= 6; i--) {
        for(j = 6; j < i; j++) {
            printf("_ ");
        }
        for(k = i; k <= 10; k++) {
            printf("%d ", k);
        }
        printf("\n");
    }
    return 0;
}
