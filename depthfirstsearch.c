#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int vertex;  // Structure to represent a graph node
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node* adjLists[MAX_VERTICES];  // Structure to represent a graph
    int visited[MAX_VERTICES];
};

struct Node* createNode(int v) {   // Function to create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {  // Function to create a graph with 'V' vertices
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = V;
    for (int i = 0; i < V; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {  // Function to add an edge to the graph
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void DFS(struct Graph* graph, int vertex) {  // Depth First Search
    graph->visited[vertex] = 1;
    printf("Visited %d\n", vertex);  // Mark the current vertex as visited

    struct Node* adjList = graph->adjLists[vertex];
    while (adjList) {                              // Recur for all the adjacent vertices
        int connectedVertex = adjList->vertex;
        if (!graph->visited[connectedVertex]) {
            DFS(graph, connectedVertex);
        }
        adjList = adjList->next;
    }
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    struct Graph* graph = createGraph(V);

    int E;
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (source and destination): \n");
    for (int i = 0; i < E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Depth First Traversal (starting from vertex 0):\n");
    DFS(graph, 0);

    return 0;
}
