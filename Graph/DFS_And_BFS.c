#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10

// Define the graph structure
typedef struct Graph
{
    int numVertices;
    int **adjMatrix;
    int *visited;
} Graph;

// Function prototypes
Graph *createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
void printGraph(Graph *graph);
void freeGraph(Graph *graph);
void depthFirstSearch(Graph *graph, int vertex);
void dfsTraversal(Graph *graph);
void breadthFirstSearch(Graph *graph, int vertex);
void bfsTraversal(Graph *graph);

int main()
{
    int choice, vertices, src, dest;
    Graph *graph = NULL;

    do
    {
        printf("\n=== Graph Operations ===\n");
        printf("1. Create Graph\n");
        printf("2. Add Edge\n");
        printf("3. Depth-First Search Traversal\n");
        printf("4. Breadth-First Search Traversal\n");
        printf("5. Print Graph\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number of vertices: ");
            scanf("%d", &vertices);
            if (graph != NULL)
            {
                freeGraph(graph); // Free previous graph if exists
            }
            graph = createGraph(vertices);
            break;
        case 2:
            if (graph == NULL)
            {
                printf("Graph not created yet!\n");
                break;
            }
            printf("Enter source and destination vertices: ");
            scanf("%d %d", &src, &dest);
            addEdge(graph, src, dest);
            break;
        case 3:
            if (graph == NULL)
            {
                printf("Graph not created yet!\n");
                break;
            }
            dfsTraversal(graph);
            break;
        case 4:
            if (graph == NULL)
            {
                printf("Graph not created yet!\n");
                break;
            }
            bfsTraversal(graph);
            break;
        case 5:
            if (graph == NULL)
            {
                printf("Graph not created yet!\n");
                break;
            }
            printGraph(graph);
            break;
        case 6:
            printf("Exiting program...\n");
            freeGraph(graph);
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to create a graph with the given number of vertices
Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));

    if (graph == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    graph->numVertices = vertices;
    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));

    if (graph->adjMatrix == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < vertices; i++)
    {
        graph->adjMatrix[i] = (int *)calloc(vertices, sizeof(int));

        if (graph->adjMatrix[i] == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    graph->visited = (int *)calloc(vertices, sizeof(int));

    if (graph->visited == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    return graph;
}

// Function to add an edge between two vertices in the graph
void addEdge(Graph *graph, int src, int dest)
{
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices)
    {
        graph->adjMatrix[src][dest] = 1;
        graph->adjMatrix[dest][src] = 1;
        printf("Edge added between vertices %d and %d.\n", src, dest);
    }
    else
    {
        printf("Invalid vertices!\n");
    }
}

// Function to print the adjacency matrix of the graph
void printGraph(Graph *graph)
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

// Function to free the memory allocated for the graph
void freeGraph(Graph *graph)
{
    if (graph != NULL)
    {
        if (graph->adjMatrix != NULL)
        {
            for (int i = 0; i < graph->numVertices; i++)
            {
                free(graph->adjMatrix[i]);
            }
            free(graph->adjMatrix);
        }
        if (graph->visited != NULL)
        {
            free(graph->visited);
        }
        free(graph);
    }
}

// Function for Depth-First Search traversal
void depthFirstSearch(Graph *graph, int vertex)
{
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->adjMatrix[vertex][i] && !graph->visited[i])
        {
            depthFirstSearch(graph, i);
        }
    }
}

// Function for Depth-First Search traversal for the entire graph
void dfsTraversal(Graph *graph)
{
    printf("Depth-First Search Traversal:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        if (!graph->visited[i])
        {
            depthFirstSearch(graph, i);
        }
    }
    printf("\n");
}

// Function for Breadth-First Search traversal
void breadthFirstSearch(Graph *graph, int vertex)
{
    int queue[MAX_VERTICES], front = 0, rear = 0;
    queue[rear++] = vertex;
    graph->visited[vertex] = 1;

    printf("Breadth-First Search Traversal:\n");
    while (front != rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++)
        {
            if (graph->adjMatrix[currentVertex][i] && !graph->visited[i])
            {
                queue[rear++] = i;
                graph->visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Function for Breadth-First Search traversal for the entire graph
void bfsTraversal(Graph *graph)
{
    printf("Breadth-First Search Traversal:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        if (!graph->visited[i])
        {
            breadthFirstSearch(graph, i);
        }
    }
}
