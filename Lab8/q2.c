#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printLCS(char *X, int **b, int i, int j) {
    if (i == 0 || j == 0)
        return;
        
    if (b[i][j] == 1) {
        printLCS(X, b, i - 1, j - 1);
        printf("%c", X[i - 1]);
    } else if (b[i][j] == 2) {
        printLCS(X, b, i - 1, j);
    } else {
        printLCS(X, b, i, j - 1);
    }
}

void findLCS(char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);
    
    int **c = (int **)malloc((m + 1) * sizeof(int *));
    int **b = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        c[i] = (int *)malloc((n + 1) * sizeof(int));
        b[i] = (int *)malloc((n + 1) * sizeof(int));
    }
    
    for (int i = 0; i <= m; i++)
        c[i][0] = 0;
    for (int j = 0; j <= n; j++)
        c[0][j] = 0;
        
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 2;
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 3;
            }
        }
    }
    
    printf("\nLCS: ");
    printLCS(X, b, m, n);
    printf("\nLCS Length: %d\n", c[m][n]);
    
    for (int i = 0; i <= m; i++) {
        free(c[i]);
        free(b[i]);
    }
    free(c);
    free(b);
}

int main() {
    char str1[100], str2[100];
    
    printf("Enter the first string: ");
    scanf("%s", str1);
    
    printf("Enter the second string: ");
    scanf("%s", str2);
    
    for (int i = 0; str1[i]; i++) {
        if (str1[i] != '0' && str1[i] != '1') {
            printf("Error: First string should contain only 0s and 1s\n");
            return 1;
        }
    }
    
    for (int i = 0; str2[i]; i++) {
        if (str2[i] != '0' && str2[i] != '1') {
            printf("Error: Second string should contain only 0s and 1s\n");
            return 1;
        }
    }
    
    findLCS(str1, str2);
    return 0;
}
