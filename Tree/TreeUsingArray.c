#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure for the binary tree
struct BinaryTree
{
    int array[MAX_SIZE];
    int size;
};

// Function to initialize a binary tree
void initialize(struct BinaryTree *tree)
{
    tree->size = 0;
}

// Function to check if the binary tree is empty
int isEmpty(struct BinaryTree *tree)
{
    return tree->size == 0;
}

// Function to insert a new node into the binary tree
void insert(struct BinaryTree *tree, int data)
{
    if (tree->size < MAX_SIZE)
    {
        tree->array[tree->size++] = data;
        printf("Node inserted successfully.\n");
    }
    else
    {
        printf("Error: Binary tree is full. Cannot insert node.\n");
    }
}

// Function to display the binary tree
void display(struct BinaryTree *tree)
{
    if (isEmpty(tree))
    {
        printf("Binary tree is empty.\n");
        return;
    }

    printf("Binary Tree: ");
    for (int i = 0; i < tree->size; i++)
    {
        printf("%d ", tree->array[i]);
    }
    printf("\n");
}

int main()
{
    struct BinaryTree tree;
    initialize(&tree);

    int choice, data;

    do
    {
        printf("\nBinary Tree Menu\n");
        printf("1. Insert Node\n");
        printf("2. Display Tree\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insert(&tree, data);
            break;
        case 2:
            display(&tree);
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
