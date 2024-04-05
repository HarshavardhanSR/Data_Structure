#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int front, rear, capacity;
} CQ;

CQ *createCQ(int capacity)
{
    CQ *cq = (CQ *)malloc(sizeof(CQ));
    cq->array = (int *)malloc(capacity * sizeof(int));
    cq->capacity = capacity;
    cq->front = cq->rear = -1;
    return cq;
}

int isEmpty(CQ *cq)
{
    return cq->front == -1;
}

int isFull(CQ *cq)
{
    return (cq->rear + 1) % cq->capacity == cq->front;
}

void resize(CQ *cq)
{
    int newCapacity = cq->capacity * 2;
    cq->array = (int *)realloc(cq->array, newCapacity * sizeof(int));

    if (cq->front > cq->rear)
    {
        // If front is greater than rear, need to shift elements to the end
        for (int i = 0; i <= cq->rear; ++i)
        {
            cq->array[i + cq->capacity] = cq->array[i];
        }
        cq->rear += cq->capacity;
    }

    cq->capacity = newCapacity;
}

void enqueue(CQ *cq, int data)
{
    if (isFull(cq))
    {
        printf("Resizing Circular Queue...\n");
        resize(cq);
    }

    if (isEmpty(cq))
        cq->front = 0;

    cq->rear = (cq->rear + 1) % cq->capacity;
    cq->array[cq->rear] = data;
    printf("Enqueued %d into Circular Queue\n", data);
}

int dequeue(CQ *cq)
{
    if (isEmpty(cq))
    {
        printf("Circular Queue is empty!\n");
        return -1;
    }

    int data = cq->array[cq->front];
    if (cq->front == cq->rear)
        cq->front = cq->rear = -1;
    else
        cq->front = (cq->front + 1) % cq->capacity;

    printf("Dequeued %d from Circular Queue\n", data);
    return data;
}

void display(CQ *cq)
{
    if (isEmpty(cq))
    {
        printf("Circular Queue is empty!\n");
        return;
    }

    int i = cq->front;
    printf("Circular Queue: ");
    do
    {
        printf("%d ", cq->array[i]);
        i = (i + 1) % cq->capacity;
    } while (i != (cq->rear + 1) % cq->capacity);
    printf("\n");
}

void freeCQ(CQ *cq)
{
    free(cq->array);
    free(cq);
}

int main()
{
    int capacity, choice, data;

    printf("Enter the initial capacity of Circular Queue: ");
    scanf("%d", &capacity);

    CQ *cq = createCQ(capacity);

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
    freeCQ(cq);
    return 0;
}