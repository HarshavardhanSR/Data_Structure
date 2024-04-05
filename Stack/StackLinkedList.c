#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Stack structure
typedef struct
{
    Node *top;
} Stack;

// Function to initialize the stack
void initialize(Stack *stack)
{
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack *stack, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;

    printf("%d pushed to the stack.\n", data);
}

// Function to pop an element from the stack
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        exit(1);
    }

    Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);

    return data;
}

// Function to peek the top element of the stack without popping
int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        exit(1);
    }

    return stack->top->data;
}

// Function to display the elements of the stack
void display(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");
    Node *current = stack->top;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory used by the linked list
void freeStack(Stack *stack)
{
    while (!isEmpty(stack))
    {
        pop(stack);
    }
}

int main()
{
    Stack stack;
    initialize(&stack);

    int choice, data;

    do
    {
        printf("\nMENU:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to push: ");
            scanf("%d", &data);
            push(&stack, data);
            break;
        case 2:
            printf("Popped element: %d\n", pop(&stack));
            break;
        case 3:
            printf("Top element: %d\n", peek(&stack));
            break;
        case 4:
            display(&stack);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 5);

    freeStack(&stack);
    return 0;
}