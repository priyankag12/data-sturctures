#include<stdio.h>
#define v 4 //maximum vertices defined. 

void init(int arr[][v]){ //Initialise the matrix.
	int i,j;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			arr[i][j]=0;
		}
	}
}

void addEdge(int arr[][v],int i,int j){  //Add edges in the matrix.
	arr[i][j]=1;
	arr[j][i]=1;
}

int main() {
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int adjacencyMatrix[vertices][vertices];

    printf("Enter the adjacency matrix :\n"); //(0 for no connection, 1 for connection) // Input the adjacency matrix

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("What is the connection between vertex %d and vertex %d?: ", i, j);
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("Adjacency Matrix:\n");     // Display the adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//Print the matrix.
//void printAdjMatrix(int arr[][v]){
//	int i,j;
//	for(i=0;i<v;i++){
//		printf("%d ",i);
//		for(j=0;j<v;j++){
//			printf("%d", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main(){
//	int adjMatrix[v][v];
//	init(adjMatrix);	
//	printAdjMatrix(adjMatrix);
//	printf("\n");
//	addEdge(adjMatrix,0,1);
//	addEdge(adjMatrix,0,2);
//	addEdge(adjMatrix,3,1);
//	addEdge(adjMatrix,1,1);
//	addEdge(adjMatrix,1,2);
//	addEdge(adjMatrix,0,3);
//	addEdge(adjMatrix,2,1);	
//	printAdjMatrix(adjMatrix);
//	return 0;
