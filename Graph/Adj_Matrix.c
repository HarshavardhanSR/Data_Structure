#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Define a typedef for the Graph structure
typedef struct
{
    int numVertices;
    int **adjMatrix;
} Graph;

// Function to initialize a graph with a given number of vertices
Graph *createGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    if (graph == NULL)
    {
        printf("Memory Allocation failed\n");
        exit(0);
    }
    graph->numVertices = numVertices;
    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int**)malloc(numVertices * sizeof(int *));
    if (graph->adjMatrix == NULL)
    {
        printf("Memory Allocation failed\n");
        exit(0);
    }
    for (int i = 0; i < numVertices; i++)
    {
        graph->adjMatrix[i] = (int *)malloc(numVertices * sizeof(int));
        if (graph->adjMatrix[i] == NULL)
        {
            printf("Memory Allocation failed\n");
            exit(0);
        }
        for (int j = 0; j < numVertices; j++)
        {
            graph->adjMatrix[i][j] = 0; 
        }
    }
    return graph;
}
// Function to free memory allocated for the adjacency matrix
void freeAdjacencyMatrix(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
}
// Function to add an edge to the graph
void addEdge(Graph *graph, int source, int destination)
{
    if (source >= 0 && source < graph->numVertices && destination >= 0 && destination < graph->numVertices)
    {
        graph->adjMatrix[source][destination] = 1; 
        graph->adjMatrix[destination][source] = 1;
        printf("Edge added successfully!\n");
    }
    else
    {
        printf("Invalid edge!\n");
    }
}
// Function to print the adjacency matrix
void printAdjacencyMatrix(Graph *graph)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    // Create a graph
    Graph *graph = createGraph(numVertices);
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add an edge\n");
        printf("2. Print adjacency matrix\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the source vertex and destination vertex: ");
            int source, destination;
            scanf("%d %d", &source, &destination);
            addEdge(graph, source, destination);
            break;
        }
        case 2:
            printAdjacencyMatrix(graph);
            break;
        case 3:
            // Free memory allocated for the adjacency matrix
            freeAdjacencyMatrix(graph);
            free(graph);
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
