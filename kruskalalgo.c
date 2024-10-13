#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, w;
    /*u: One vertex of the edge.
      v: The other vertex of the edge.
      w: The weight of the edge.
*/
} Edge;

typedef struct {
    int parent[MAX];
    int rank[MAX];
    /*parent[MAX]: Stores the parent of each vertex.
      rank[MAX]: Stores the rank (depth) of each vertex 
      tree in the union-find structure.*/
} DisjointSet;

void initializeSet(DisjointSet* set, int n) {
    //initializes the DisjointSet for n vertices
    for (int i = 0; i < n; i++) {
        set->parent[i] = i;
        set->rank[i] = 0;
    }
}

int find(DisjointSet* set, int u) {
    //finds the representative (or root) of the set 
    //that a vertex u belongs to, using path compression 
    //for optimization
    if (set->parent[u] != u)
        set->parent[u] = find(set, set->parent[u]);
    return set->parent[u];
}

void unionSets(DisjointSet* set, int u, int v) {
    //function merges the sets containing vertices u and v
    int rootU = find(set, u);
    int rootV = find(set, v);
    /*union is done by rank, which means the root 
    with the smaller rank is made a child of the 
    root with the larger rank to keep the tree as shallow 
    as possible*/

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
    //function is used by the qsort() function 
    //to sort the edges by their weight (w)
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
    /*Initialize the Disjoint Set: It initializes the disjoint set for n vertices.
     Sort the Edges: The edges are sorted by weight using qsort() and compareEdges().
     Select Edges for MST: It iterates through the sorted edges and adds an edge to the MST if it 
    does not form a cycle. This is determined by checking if the two vertices of the 
    edge are in different sets using find(). If they are, the sets are merged using unionSets().
    Output the MST: The edges included in the MST are printed along with the total weight of the MST.*/

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
