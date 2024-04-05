#include <stdio.h>
#include <stdlib.h>

// Node structure for circular linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
Node *insertAtBeginning(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = head->next;
    head->next = newNode;
    return head;
}

// Function to insert a node at the end of the circular linked list
Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        newNode->next = newNode; 
        return newNode;
    }
    newNode->next = head->next;
    head->next = newNode;
    return newNode;
}

// Function to delete the first node of the circular linked list
Node *deleteFirst(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == head)
    { 
        free(head);
        return NULL;
    }
    Node *temp = head->next;
    head->next = temp->next;
    free(temp);
    return head;
}

// Function to delete the last node of the circular linked list
Node *deleteLast(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == head)
    { 
        free(head);
        return NULL;
    }
    Node *temp = head;
    while (temp->next != head->next)
    {
        if (temp->next->next == head->next)
        {
            free(temp->next);
            temp->next = head->next;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

// Function to print the circular linked list
void printList(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *temp = head->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head->next);
    printf("\n");
}

int main()
{
    Node *head = NULL;
    int ch, data;

    do
    {
        printf("\nCircular Linked List Operations\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete first\n");
        printf("4. Delete last\n");
        printf("5. Print list\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter data to insert at beginning: ");
            scanf("%d", &data);
            head = insertAtBeginning(head, data);
            break;
        case 2:
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
            break;
        case 3:
            head = deleteFirst(head);
            break;
        case 4:
            head = deleteLast(head);
            break;
        case 5:
            printf("Circular Linked List: ");
            printList(head);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (ch != 6);
    return 0;
}
