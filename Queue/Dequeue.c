#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int front;
    int rear;
    int size;
    int capacity;
} CircularQueue;

CircularQueue *createCircularQueue(int capacity)
{
    CircularQueue *cq = (CircularQueue *)malloc(sizeof(CircularQueue));
    cq->array = (int *)malloc(capacity * sizeof(int));
    cq->front = cq->rear = -1;
    cq->size = 0;
    cq->capacity = capacity;
    return cq;
}

int isEmpty(CircularQueue *cq)
{
    return cq->size == 0;
}

int isFull(CircularQueue *cq)
{
    return cq->size == cq->capacity;
}

void resize(CircularQueue *cq)
{
    int newCapacity = cq->capacity * 2;
    cq->array = (int *)realloc(cq->array, newCapacity * sizeof(int));
    cq->capacity = newCapacity;
}

void enqueue(CircularQueue *cq, int data)
{
    if (isFull(cq))
    {
        printf("Resizing Circular Queue...\n");
        resize(cq);
    }

    if (isEmpty(cq))
    {
        cq->front = cq->rear = 0;
    }
    else
    {
        cq->rear = (cq->rear + 1) % cq->capacity;
    }

    cq->array[cq->rear] = data;
    cq->size++;
    printf("Enqueued %d into Circular Queue\n", data);
}

int dequeue(CircularQueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Circular Queue is empty!\n");
        return -1;
    }

    int data = cq->array[cq->front];
    if (cq->front == cq->rear)
    {
        cq->front = cq->rear = -1;
    }
    else
    {
        cq->front = (cq->front + 1) % cq->capacity;
    }

    cq->size--;
    printf("Dequeued %d from Circular Queue\n", data);
    return data;
}

void display(CircularQueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Circular Queue is empty!\n");
        return;
    }

    printf("Circular Queue: ");
    int i = cq->front;
    do
    {
        printf("%d ", cq->array[i]);
        i = (i + 1) % cq->capacity;
    } while (i != (cq->rear + 1) % cq->capacity);
    printf("\n");
}

void freeCircularQueue(CircularQueue *cq)
{
    free(cq->array);
    free(cq);
}

int main()
{
    int capacity, choice, data;

    printf("Enter the initial capacity of Circular Queue: ");
    scanf("%d", &capacity);

    CircularQueue *cq = createCircularQueue(capacity);

    do
    {
        printf("\n\nCircular Queue MENU:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(cq, data);
            break;
        case 2:
            dequeue(cq);
            break;
        case 3:
            display(cq);
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid Choice!\n");
        }
    } while (choice != 4);

    freeCircularQueue(cq);

    return 0;
}