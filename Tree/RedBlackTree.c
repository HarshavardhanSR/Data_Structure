#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    RED,
    BLACK
} Color;

typedef struct Node
{
    int data;
    Color color;
    struct Node *left, *right, *parent;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED; // New nodes are always red
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

void leftRotate(Node **root, Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL)
    {
        *root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRotate(Node **root, Node *y)
{
    Node *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
    {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NULL)
    {
        *root = x;
    }
    else if (y == y->parent->right)
    {
        y->parent->right = x;
    }
    else
    {
        y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
}

void fixViolation(Node **root, Node *z)
{
    while (z != *root && z->parent->color == RED)
    {
        if (z->parent == z->parent->parent->left)
        {
            Node *y = z->parent->parent->right;
            if (y != NULL && y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        }
        else
        {
            Node *y = z->parent->parent->left;
            if (y != NULL && y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

void addNode(Node **root, int data)
{
    Node *newNode = createNode(data);
    Node *current = *root;
    Node *parent = NULL;

    while (current != NULL)
    {
        parent = current;
        if (data < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    newNode->parent = parent;
    if (parent == NULL)
    {
        *root = newNode; // Tree is empty
    }
    else if (data < parent->data)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }

    fixViolation(root, newNode);
}

void printInOrder(Node *node)
{
    if (node == NULL)
        return;
    printInOrder(node->left);
    printf("Node: %d, Color: %s\n", node->data, node->color == RED ? "RED" : "BLACK");
    printInOrder(node->right);
}

void printPreOrder(Node *node)
{
    if (node == NULL)
        return;
    printf("Node: %d, Color: %s\n", node->data, node->color == RED ? "RED" : "BLACK");
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printPostOrder(Node *node)
{
    if (node == NULL)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("Node: %d, Color: %s\n", node->data, node->color == RED ? "RED" : "BLACK");
}

int main()
{
    Node *root = NULL;

    // Add nodes to the Red-Black Tree
    addNode(&root, 10);
    addNode(&root, 5);
    addNode(&root, 15);
    addNode(&root, 3);
    addNode(&root, 8);
    addNode(&root, 12);
    addNode(&root, 18);

    // Print nodes in order with color
    printf("Nodes in order with color:\n");
    printInOrder(root);

    printf("\n\n");

    // Print nodes in pre-order with color
    printf("Nodes in pre-order with color:\n");
    printPreOrder(root);

    printf("\n\n");

    // Print nodes in post-order with color
    printf("Nodes in post-order with color:\n");
    printPostOrder(root);

    return 0;
}
