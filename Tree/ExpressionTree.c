#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define a structure for a node in the expression tree
typedef struct TreeNode
{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
}Node;

// Function to create a new node with given data
Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to check if a character is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to build an expression tree from a postfix expression
Node *buildExpressionTree(char postfix[])
{
    Node *stack[100]; // Assuming postfix expression won't exceed 100 characters
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        Node *newNode = createNode(postfix[i]);

        if (isalnum(postfix[i]))
        { // If operand, push onto stack
            stack[++top] = newNode;
        }
        else
        { // If operator, pop two operands and create subtree
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
    }

    return stack[top]; // Top of stack will be the root of the expression tree
}

// Function to evaluate an expression tree
int evaluateExpressionTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (!isOperator(root->data))
    {
        return root->data - '0'; // Convert character to integer
    }

    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    switch (root->data)
    {
    case '+':
        return leftValue + rightValue;
    case '-':
        return leftValue - rightValue;
    case '*':
        return leftValue * rightValue;
    case '/':
        return leftValue / rightValue;
    default:
        return 0;
    }
}

// Function to print infix expression (inorder traversal)
void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        if (isOperator(root->data))
        {
            printf("(");
        }
        inorderTraversal(root->left);
        printf("%c", root->data);
        inorderTraversal(root->right);
        if (isOperator(root->data))
        {
            printf(")");
        }
    }
}

// Function to print prefix expression (preorder traversal)
void preorderTraversal(Node *root)
{
    if (root != NULL)
    {
        printf("%c", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to print postfix expression (postorder traversal)
void postorderTraversal(Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%c", root->data);
    }
}

int main()
{
    char postfix[] = "53*82/+";

    // Build expression tree
    Node *root = buildExpressionTree(postfix);

    // Evaluate expression tree
    int result = evaluateExpressionTree(root);

    printf("Postfix expression: %s\n", postfix);
    printf("Infix expression: ");
    inorderTraversal(root);
    printf("\n");
    printf("Prefix expression: ");
    preorderTraversal(root);
    printf("\n");
    printf("Postfix expression: ");
    postorderTraversal(root);
    printf("\n");
    printf("Result of expression: %d\n", result);

    return 0;
}
