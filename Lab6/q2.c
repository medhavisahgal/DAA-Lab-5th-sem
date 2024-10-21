#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100
#define MAX_VERTICES 100

struct Edge {
    int u, v, w;
};

struct Edge edges[MAX_EDGES];
int parent[MAX_VERTICES];
int rank[MAX_VERTICES];
int n, m;

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

void union_sets(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void kruskalMST() {
    int e = 0;
    int i = 0;
    struct Edge result[n-1];

    qsort(edges, m, sizeof(edges[0]), compareEdges);

    for (i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    i = 0;

    while (e < n - 1 && i < m) {
        struct Edge next_edge = edges[i++];

        int x = find(next_edge.u - 1);
        int y = find(next_edge.v - 1);

        if (x != y) {
            result[e++] = next_edge;
            union_sets(x, y);
        }
    }

    printf("Edge   Cost\n");
    int totalCost = 0;
    for (i = 0; i < e; i++) {
        printf("%d-%d    %d\n", result[i].u, result[i].v, result[i].w);
        totalCost += result[i].w;
    }
    printf("Total Weight of the Spanning Tree: %d\n", totalCost);
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskalMST();

    return 0;
}
