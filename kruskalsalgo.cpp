#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    int parent[MAX];
    int rank[MAX];
} DisjointSet;

void initializeSet(DisjointSet* set, int n) {
    for (int i = 0; i < n; i++) {
        set->parent[i] = i;
        set->rank[i] = 0;
    }
}

int find(DisjointSet* set, int u) {
    if (set->parent[u] != u)
        set->parent[u] = find(set, set->parent[u]);
    return set->parent[u];
}

void unionSets(DisjointSet* set, int u, int v) {
    int rootU = find(set, u);
    int rootV = find(set, v);

    if (rootU != rootV) {
        if (set->rank[rootU] > set->rank[rootV])
            set->parent[rootV] = rootU;
        else if (set->rank[rootU] < set->rank[rootV])
            set->parent[rootU] = rootV;
        else {
            set->parent[rootV] = rootU;
            set->rank[rootU]++;
        }
    }
}

int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->w - edgeB->w;
}

void kruskal(Edge edges[], int n, int e) {
    DisjointSet set;
    initializeSet(&set, n);
    qsort(edges, e, sizeof(Edge), compareEdges);

    Edge mst[MAX];
    int mstSize = 0;
    int mstWeight = 0;

    for (int i = 0; i < e; i++) {
        Edge edge = edges[i];
        if (find(&set, edge.u) != find(&set, edge.v)) {
            mst[mstSize++] = edge;
            mstWeight += edge.w;
            unionSets(&set, edge.u, edge.v);
        }
    }

    printf("Minimum Spanning Tree edges:\n");
    for (int i = 0; i < mstSize; i++)
        printf("%d -- %d == %d\n", mst[i].u, mst[i].v, mst[i].w);

    printf("Total weight of MST: %d\n", mstWeight);  // Total cost of MST
}

int main() {
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    Edge edges[MAX];
    printf("Enter the edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal(edges, n, e);

    return 0;
}

