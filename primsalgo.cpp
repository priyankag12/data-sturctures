
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int V; // Number of vertices

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

/*This function returns the index of the vertex with the smallest key value
that is not yet included in the Minimum Spanning Tree (MST).

It iterates through all vertices and updates 
the minimum key value and its corresponding index.*/

void printMST(int parent[], int graph[MAX][MAX], int *totalCost) {
    printf("Edge \tWeight\n");
    *totalCost = 0; // Initialize total cost
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        *totalCost += graph[i][parent[i]]; // Accumulate the weight of each edge
    }
    printf("Total cost of MST: %d\n", *totalCost); // Print the total cost
}

//prints the edges and weights of the MST
//iterates from 1 to V-1 and prints the parent
// and child vertices along with the edge weight

void primMST(int graph[MAX][MAX]) {
    int parent[MAX]; //parent[] stores the MST.
    int key[MAX]; //key[] is used to pick the minimum weight edge in the cut.
    bool mstSet[MAX]; //mstSet[] keeps track of vertices included in the MST.
    int totalCost; // Variable to store the total cost of the MST

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;
    

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, &totalCost); // Call printMST with a reference to totalCost
}

// key value of the first vertex is set to 0 so that it is picked first.
//The algorithm picks the minimum key vertex that is not yet included in the 
//MST, updates the mstSet and updates the key values of adjacent vertices.

int main() {
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &V); //reads the number of vertices.

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        } // reads the adjacency matrix representing the graph.
    }

/*
Prim's algorithm is a greedy algorithm that finds a Minimum Spanning Tree (MST) 
for a weighted undirected graph. The MST is a subset of the graph's edges that 
connects all vertices with the minimum possible total edge weight and no cycles.

Prim's Algorithm: Finds the Minimum Spanning Tree (MST) of a graph, which 
connects all vertices with the minimum total edge weight and no cycles.

Dijkstra's Algorithm: Finds the shortest path from a single source vertex to all 
other vertices in a graph with non-negative edge weights.
*/

    primMST(graph); //call the prims function.

    return 0;
}
