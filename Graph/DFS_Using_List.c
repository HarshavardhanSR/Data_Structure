#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in adjacency list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Node *adjList[], int u, int v)
{
    struct Node *newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

// Function to perform Depth First Search on a graph
// represented using adjacency list
void dfs(struct Node *adjList[], int currentNode, int visited[])
{
    // Mark the current node as visited and print it
    visited[currentNode] = 1;
    printf("%d ", currentNode);

    // Traverse all adjacent vertices of the current node
    struct Node *temp = adjList[currentNode];
    while (temp != NULL)
    {
        int neighbor = temp->data;
        if (!visited[neighbor])
        {
            // If neighbor is not visited, recursively call DFS
            dfs(adjList, neighbor, visited);
        }
        temp = temp->next;
    }
}

int main()
{
    // Number of vertices in the graph
    int vertices = 5;

    // Adjacency list representation of the graph
    struct Node *adjList[vertices];
    for (int i = 0; i < vertices; ++i)
        adjList[i] = NULL;

    // Add edges to the graph
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 4);

    // Mark all the vertices as not visited
    int visited[vertices];
    for (int i = 0; i < vertices; ++i)
        visited[i] = 0;

    // Perform DFS traversal starting from vertex 0
    printf("Depth First Traversal starting from vertex 0: ");
    dfs(adjList, 0, visited);

    return 0;
}
