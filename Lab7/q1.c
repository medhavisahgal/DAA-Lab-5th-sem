#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

int graph[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES];
int prev[MAX_VERTICES];
int visited[MAX_VERTICES];
int n;

void readGraph(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    fclose(file);
}

int minDistance() {
    int min = INF, min_index;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int dest) {
    if (prev[dest] == -1) {
        printf("%d", dest + 1);
        return;
    }
    printPath(prev[dest]);
    printf("->%d", dest + 1);
}

void dijkstra(int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance();
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }

    printf("Source\tDestination\tCost\tPath\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t", src + 1, i + 1);
        if (dist[i] == INF) {
            printf("INF\t-\n");
        } else {
            printf("%d\t", dist[i]);
            printPath(i);
            printf("\n");
        }
    }
}

int main() {
    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    int src;
    printf("Enter the Source Vertex: ");
    scanf("%d", &src);
    src--;

    readGraph("inDiAdjMat1.dat");
    dijkstra(src);

    return 0;
}
