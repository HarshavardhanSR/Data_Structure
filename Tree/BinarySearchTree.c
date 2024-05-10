#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the binary search tree
typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
}Node;

// Function to create a new node with given data
Node* createNode(int data)
{
    Node* newNode = (Node* )malloc(sizeof(Node*));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary search tree
Node* insertNode(Node* root, int data)
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

// Function to search for a value in the binary search tree
Node* search(Node* root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (key < root->data)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Function to display the binary search tree in inorder traversal
void inorderTraversal(Node* root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to display the binary search tree in preorder traversal
void preorderTraversal(Node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to display the binary search tree in postorder traversal
void postorderTraversal(Node* root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    Node* *root = NULL;
    int choice, data, key;
    Node* *result;

    do
    {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert Node\n");
        printf("2. Search Node\n");
        printf("3. Display Tree (Inorder Traversal)\n");
        printf("4. Display Tree (Preorder Traversal)\n");
        printf("5. Display Tree (Postorder Traversal)\n");
        printf("6. Exit\n");
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
            printf("Enter key to search: ");
            scanf("%d", &key);
            result = search(root, key);
            if (result != NULL)
            {
                printf("%d is found in the binary search tree.\n", key);
            }
            else
            {
                printf("%d is not found in the binary search tree.\n", key);
            }
            break;
        case 3:
            printf("Binary Search Tree (Inorder Traversal): ");
            inorderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("Binary Search Tree (Preorder Traversal): ");
            preorderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("Binary Search Tree (Postorder Traversal): ");
            postorderTraversal(root);
            printf("\n");
            break;
        case 6:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}
