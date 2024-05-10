#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the binary tree
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} Node;

// Function to create a new node with given data
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary tree
Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else
    {
        if (data <= root->data)
        {
            root->left = insertNode(root->left, data);
        }
        else
        {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

// Function to display the binary tree in inorder traversal
void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{
    Node *root = NULL;
    int choice, data;

    do
    {
        printf("\nBinary Tree Menu\n");
        printf("1. Insert Node\n");
        printf("2. Display Tree (Inorder Traversal)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insertNode(root, data);
            printf("Node inserted successfully.\n");
            break;
        case 2:
            printf("Binary Tree (Inorder Traversal): ");
            inorderTraversal(root);
            printf("\n");
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
