#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 99999

void printPath(int **next, int src, int dest) {
    if (next[src][dest] == -1) {
        printf("No path exists\n");
        return;
    }
    
    printf("\nShortest Path from vertex %d to vertex %d: %d", src, dest, src);
    int intermediate = src;
    while (intermediate != dest) {
        intermediate = next[intermediate][dest];
        printf("->%d", intermediate);
    }
}

void floydWarshall(int **graph, int V, int src, int dest) {
    int **dist = (int **)malloc(V * sizeof(int *));
    int **next = (int **)malloc(V * sizeof(int *));
    
    for (int i = 0; i < V; i++) {
        dist[i] = (int *)malloc(V * sizeof(int));
        next[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            if (graph[i][j] == INF)
                next[i][j] = -1;
            else
                next[i][j] = j;
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    printf("\nOutput:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%-4d", dist[i][j]);
        }
        printf("\n");
    }

    if (src != -1 && dest != -1) {
        printPath(next, src, dest);
        printf("\nPath weight: %d\n", dist[src][dest]);
    }

    for (int i = 0; i < V; i++) {
        free(dist[i]);
        free(next[i]);
    }
    free(dist);
    free(next);
}

int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
    }

    printf("Enter the adjacency matrix (use %d for infinity):\n", INF);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (i != j && graph[i][j] == 0) {
                graph[i][j] = INF;
            }
        }
    }

    int src, dest;
    printf("Enter the source and destination vertices: ");
    scanf("%d %d", &src, &dest);
    src--; dest--;

    floydWarshall(graph, V, src, dest);

    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
