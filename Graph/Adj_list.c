#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node in the adjacency list
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int vertex)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory Allocation failed\n");
        exit(0);
    }
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the front of the linked list
Node *insertFront(Node *start, int data)
{
    Node *newNode = createNode(data);
    newNode->next = start;
    start = newNode;
    return start;
}

int numVertices;
Node **adjacencyList;

// Function to initialize the graph with the given number of vertices
void initializeGraph(int numVertex)
{
    numVertices = numVertex;
    adjacencyList = (Node **)malloc(numVertex * sizeof(Node *));
    if (adjacencyList == NULL)
    {
        printf("Memory Allocation failed\n");
        exit(0);
    }
    for (int i = 0; i < numVertex; i++)
    {
        adjacencyList[i] = NULL;
    }
}
// Function to add an edge between two vertices in the graph
void addEdge(int src, int dest)
{
    adjacencyList[src] = insertFront(adjacencyList[src], dest);
    adjacencyList[dest] = insertFront(adjacencyList[dest], src);
}
// Function to print the adjacency list representation of the graph
void printGraph()
{
    for (int i = 0; i < numVertices; i++)
    {
        Node *temp = adjacencyList[i];
        printf("Vertex %d", i);
        while (temp)
        {
            printf("->%d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
// Function to free the memory allocated for the adjacency list
void freeGraph()
{
    for (int i = 0; i < numVertices; ++i)
    {
        Node *temp = adjacencyList[i];
        while (temp)
        {
            Node *prev = temp;
            temp = temp->next;
            free(prev);
        }
    }
    free(adjacencyList);
}
int main()
{
    int choice, src, dest, numVertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertex);
    initializeGraph(numVertex);
    do
    {
        printf("\n\n----- Menu -----\n");
        printf("1. Add Edge\n");
        printf("2. Print Graph\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter source and destination vertices: ");
            scanf("%d %d", &src, &dest);
            addEdge(src, dest);
            break;
        case 2:
            printf("\n----- Adjacency List -----\n");
            printGraph();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 3);
    freeGraph(); 
    return 0;
}
