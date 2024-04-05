#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the stack

// Stack structure
typedef struct
{
    int array[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *stack)
{
    stack->top = -1; // Initialize top to -1 indicating an empty stack
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

// Function to push (insert) an element onto the stack
void push(Stack *stack, int data)
{
    if (isFull(stack))
    {
        printf("Stack overflow! Cannot push more elements.\n");
        exit(1);
    }

    stack->top++;
    stack->array[stack->top] = data;

    printf("%d pushed to the stack.\n", data);
}

// Function to pop (remove) an element from the stack
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        exit(1);
    }

    int data = stack->array[stack->top];
    stack->top--;

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

    return stack->array[stack->top];
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
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
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

    return 0;
}