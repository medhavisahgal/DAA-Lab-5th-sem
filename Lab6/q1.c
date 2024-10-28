#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int mst[MAX_VERTICES][MAX_VERTICES];
int n;

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST() {
    printf("\nOutput:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mst[i][j]);
        }
        printf("\n");
    }
}

void primMST(int start) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int mstSet[MAX_VERTICES];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[start] = 0;
    parent[start] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mst[i][j] = 0;

    int total_weight = 0;
    for (int i = 1; i < n; i++) {
        mst[parent[i]][i] = graph[parent[i]][i];
        mst[i][parent[i]] = graph[parent[i]][i];
        total_weight += graph[parent[i]][i];
    }

    printMST();
    printf("Total Weight of the Spanning Tree: %d\n", total_weight);
}

int main() {
    FILE *file = fopen("inUnAdjMat.dat", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
    fclose(file);

    int start;
    printf("Enter the Starting Vertex: ");
    scanf("%d", &start);
    start--;

    primMST(start);

    return 0;
}
