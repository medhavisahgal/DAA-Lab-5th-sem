#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printOptimalParens(int **s, int i, int j, char *name) {
    if (i == j) {
        printf("%c", name[i]);
        return;
    }
    printf("(");
    printOptimalParens(s, i, s[i][j], name);
    printOptimalParens(s, s[i][j] + 1, j, name);
    printf(")");
}

void matrixChainMultiplication(int p[], int n) {
    int **m = (int **)malloc(n * sizeof(int *));
    int **s = (int **)malloc(n * sizeof(int *));
    
    for (int i = 0; i < n; i++) {
        m[i] = (int *)malloc(n * sizeof(int));
        s[i] = (int *)malloc(n * sizeof(int));
        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("\nM Table:\n");
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j)
                printf("0\t");
            else
                printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\nS Table:\n");
    for (int i = 1; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            printf("%d\t", s[i][j]);
        }
        printf("\n");
    }

    printf("\nOptimal Parenthesization: ");
    char *name = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n-1; i++) {
        name[i+1] = 'A' + i;
    }
    printOptimalParens(s, 1, n-1, name);
    printf("\nMinimum number of scalar multiplications: %d\n", m[1][n-1]);

    for (int i = 0; i < n; i++) {
        free(m[i]);
        free(s[i]);
    }
    free(m);
    free(s);
    free(name);
}

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    n++;

    int *dimensions = (int *)malloc(n * sizeof(int));
    int prev_cols;

    printf("Enter dimensions of matrices:\n");
    for (int i = 0; i < n-1; i++) {
        printf("Enter row and col size of A%d: ", i+1);
        if (i == 0) {
            scanf("%d %d", &dimensions[0], &dimensions[1]);
            prev_cols = dimensions[1];
        } else {
            int rows, cols;
            scanf("%d %d", &rows, &cols);
            if (rows != prev_cols) {
                printf("Error: Invalid dimensions. Matrix multiplication not possible.\n");
                free(dimensions);
                return 1;
            }
            dimensions[i+1] = cols;
            prev_cols = cols;
        }
    }

    matrixChainMultiplication(dimensions, n);
    free(dimensions);
    return 0;
}
