#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue *createPriorityQueue(int capacity)
{
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->array = (int *)malloc(capacity * sizeof(int));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

int isEmpty(PriorityQueue *pq)
{
    return pq->size == 0;
}

void resize(PriorityQueue *pq)
{
    int newCapacity = pq->capacity * 2;
    pq->array = (int *)realloc(pq->array, newCapacity * sizeof(int));
    pq->capacity = newCapacity;
}

void enqueue(PriorityQueue *pq, int data)
{
    if (pq->size == pq->capacity)
    {
        printf("Resizing Priority Queue...\n");
        resize(pq);
    }

    pq->size++;
    int i = pq->size - 1;

    while (i > 0 && data > pq->array[(i - 1) / 2])
    {
        pq->array[i] = pq->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    pq->array[i] = data;
    printf("Enqueued %d into Priority Queue\n", data);
}

int dequeue(PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is empty!\n");
        return -1;
    }

    int root = pq->array[0];
    pq->size--;

    if (pq->size > 0)
    {
        pq->array[0] = pq->array[pq->size];
        int i = 0;
        while (1)
        {
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;
            int max = i;

            if (leftChild < pq->size && pq->array[leftChild] > pq->array[max])
                max = leftChild;

            if (rightChild < pq->size && pq->array[rightChild] > pq->array[max])
                max = rightChild;

            if (max != i)
            {
                // Swap with the larger child
                int temp = pq->array[i];
                pq->array[i] = pq->array[max];
                pq->array[max] = temp;
                i = max;
            }
            else
            {
                break;
            }
        }
    }

    printf("Dequeued %d from Priority Queue\n", root);
    return root;
}

void display(PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Priority Queue: ");
    for (int i = 0; i < pq->size; i++)
    {
        printf("%d ", pq->array[i]);
    }
    printf("\n");
}

void freePriorityQueue(PriorityQueue *pq)
{
    free(pq->array);
    free(pq);
}

int main()
{
    int capacity, choice, data;

    printf("Enter the initial capacity of Priority Queue: ");
    scanf("%d", &capacity);

    PriorityQueue *pq = createPriorityQueue(capacity);

    do
    {
        printf("\n\nPriority Queue MENU:\n");
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
            enqueue(pq, data);
            break;
        case 2:
            dequeue(pq);
            break;
        case 3:
            display(pq);
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid Choice!\n");
        }
    } while (choice != 4);

    freePriorityQueue(pq);

    return 0;
}