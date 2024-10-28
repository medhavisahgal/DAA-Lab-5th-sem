#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_VERTICES 100
#define INF INT_MAX

struct PathInfo {
    int destination;
    int cost;
    char path[100];
};

int minDistance(int dist[], int sptSet[], int V) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void constructPath(int parent[], int j, char* path) {
    if (parent[j] == -1) {
        sprintf(path, "%d", j + 1);
        return;
    }
    constructPath(parent, parent[j], path);
    char temp[100];
    sprintf(temp, "->%d", j + 1);
    strcat(path, temp);
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int V, int src, struct PathInfo result[]) {
    int dist[MAX_VERTICES], sptSet[MAX_VERTICES], parent[MAX_VERTICES];
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
        parent[i] = -1;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    for (int i = 0; i < V; i++) {
        if (i != src) {
            result[i].destination = i + 1;
            result[i].cost = dist[i];
            constructPath(parent, i, result[i].path);
        }
    }
}

int main() {
    int V;
    printf("Enter the Number of Vertices: ");
    scanf("%d", &V);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
    fclose(file);

    int src;
    printf("Enter the Source Vertex: ");
    scanf("%d", &src);
    src--;

    struct PathInfo result[MAX_VERTICES];
    dijkstra(graph, V, src, result);

    printf("\nOutput:\n");
    printf("Source\tDestination\tCost\tPath\n");
    for (int i = 0; i < V; i++) {
        if (i != src) {
            printf("%d\t%d\t\t%d\t%s\n", src + 1, result[i].destination, result[i].cost, result[i].path);
        }
    }
    return 0;
}