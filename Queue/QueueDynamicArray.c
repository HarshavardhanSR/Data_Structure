#include <stdio.h>
#include <stdlib.h>

// Queue structure
typedef struct
{
    int *array;
    int front, rear, capacity;
} Queue;

// Function to initialize the queue
Queue *initialize(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    queue->array = (int *)malloc(capacity * sizeof(int));
    if (queue->array == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;

    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue)
{
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isFull(Queue *queue)
{
    return (queue->rear + 1) % queue->capacity == queue->front;
}

// Function to enqueue (insert) an element into the queue
void enqueue(Queue *queue, int data)
{
    if (isFull(queue))
    {
        printf("Queue overflow! Cannot enqueue more elements.\n");
        exit(1);
    }

    if (isEmpty(queue))
    {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = data;

    printf("%d enqueued to the queue.\n", data);
}

// Function to dequeue (remove) an element from the queue
int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue underflow! Cannot dequeue from an empty queue.\n");
        exit(1);
    }

    int data = queue->array[queue->front];

    if (queue->front == queue->rear)
    {
        // Reset front and rear to -1 when the last element is dequeued
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % queue->capacity;
    }

    return data;
}

// Function to peek the front element of the queue without dequeuing
int peek(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        exit(1);
    }

    return queue->array[queue->front];
}

// Function to display the elements of the queue
void display(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    int i = queue->front;
    do
    {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->capacity;
    } while (i != (queue->rear + 1) % queue->capacity);
    printf("\n");
}

// Function to free the memory used by the dynamic array
void freeQueue(Queue *queue)
{
    free(queue->array);
    free(queue);
}

int main()
{
    int choice, data, capacity;

    printf("Enter the capacity of the queue: ");
    scanf("%d", &capacity);

    Queue *queue = initialize(capacity);

    do
    {
        printf("\nMENU:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(queue, data);
            break;
        case 2:
            printf("Dequeued element: %d\n", dequeue(queue));
            break;
        case 3:
            printf("Front element: %d\n", peek(queue));
            break;
        case 4:
            display(queue);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 5);

    freeQueue(queue);

    return 0;
}