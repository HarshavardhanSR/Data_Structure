#include <stdio.h>
#include <stdlib.h>

// Stack structure
typedef struct
{
    int *array;
    int top;
    int capacity;
} Stack;

// Function to initialize the stack
void initialize(Stack *stack, int capacity)
{
    stack->array = (int *)malloc(sizeof(int) * capacity);
    if (stack->array == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    stack->top = -1;
    stack->capacity = capacity;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Function to double the stack capacity
void doubleCapacity(Stack *stack)
{
    stack->capacity *= 2;
    stack->array = (int *)realloc(stack->array, sizeof(int) * stack->capacity);
    if (stack->array == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}

// Function to push an element onto the stack
void push(Stack *stack, int data)
{
    if (isFull(stack))
    {
        doubleCapacity(stack);
    }

    stack->array[++stack->top] = data;
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

    return stack->array[stack->top--];
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
    for (int i = 0; i <= stack->top; ++i)
    {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Function to free the memory used by the dynamic array
void freeStack(Stack *stack)
{
    free(stack->array);
}

int main()
{
    Stack stack;
    initialize(&stack, 5); // Initial capacity is set to 5

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
    return  0;
}