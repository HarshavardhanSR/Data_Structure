#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *createnode(int newdata)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Allocation of the memory failed\n");
        return NULL;
    }
    newNode->data = newdata;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node *insertFront(int data, Node *head)
{
    Node *newNode = createnode(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return head;
}

Node *insertRear(int data, Node *head)
{
    Node *newNode = createnode(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}

Node *insertPosition(int data, int pos, Node *head)
{
    Node *newNode = createnode(data);
    if (pos < 1)
    {
        printf("Invalid Position!!\n");
        free(newNode);
        return head;
    }
    else if (pos == 1)
    {
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return head;
    }
    else
    {
        int count = 1;
        Node *temp = head;
        while (temp->next != NULL && count != pos)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL && count != pos)
        {
            printf("Invalid Position!!\n");
            free(newNode);
            return head;
        }
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
        return head;
    }
}

Node *insertAfterData(int data, int prevdata, Node *head)
{
    Node *newNode = createnode(data);
    if (head == NULL)
    {
        printf("Empty List\n");
        return head;
    }
    Node *temp = head;
    while (temp != NULL && temp->data != prevdata)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Data not found!!\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node *deleteFront(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return head;
    }
    Node *temp = head;
    head = temp->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    int deldata = temp->data;
    printf("The data at the beginning is going to be deleted: %d\n", deldata);
    free(temp);
    return head;
}

Node *deleteRear(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return head;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return head;
}

Node *deletePosition(Node *head, int pos)
{
    Node *temp = head;
    if (pos < 1)
    {
        printf("Invalid Position!!\n");
        return head;
    }
    else if (pos == 1)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }
    int count = 1;
    while (temp->next != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL && count != pos)
    {
        printf("Invalid Position!!\n");
        return head;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return head;
}

Node *deleteData(Node *head, int deldata)
{
    Node *temp = head;
    if (head == NULL)
    {
        printf("Empty List\n");
        return head;
    }
    if (head->data == deldata)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }
    while (temp != NULL && temp->data != deldata)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Data not found!!\n");
        return head;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return head;
}

Node *deleteList(Node *head)
{
    while (head != NULL)
    {
        head = deleteFront(head);
    }
    printf("All the elements in the list are deleted\n");
    return head;
}

Node *middleElement(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *insertionSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *sortedlist = NULL;
    while (head != NULL)
    {
        Node *current = head;
        head = head->next;

        if (sortedlist == NULL || current->data <= sortedlist->data)
        {
            current->next = sortedlist;
            if (sortedlist != NULL)
            {
                sortedlist->prev = current;
            }
            sortedlist = current;
            sortedlist->prev = NULL;
        }
        else
        {
            Node *temp = sortedlist;
            while (temp->next != NULL && temp->next->data < current->data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next != NULL)
            {
                temp->next->prev = current;
            }
            temp->next = current;
            current->prev = temp;
        }
    }
    return sortedlist;
}

void printlist(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    printf("Printing the list: \n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n\n");
}

int main()
{
    int ch, data;
    Node *head = NULL;
    printf("Author: Harshavardhan SR\n\n");
    do
    {
        printf("Double Linked List\n\n");
        printf("Insertion:\n");
        printf("1. Insert At Beginning\n");
        printf("2. Insert At End\n");
        printf("3. Insert At Position\n");
        printf("4. Insert After Data\n\n");
        printf("Deletion:\n");
        printf("5. Delete At Beginning\n");
        printf("6. Delete At End\n");
        printf("7. Delete At Position\n");
        printf("8. Delete Data\n\n");
        printf("9. Print List\n");
        printf("10. Clear the list\n");
        printf("11. Sort elements in the linked list\n");
        printf("12. Find the middle element of the list\n");
        printf("13. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data to insert at beginning:\n");
            scanf("%d", &data);
            head = insertFront(data, head);
            printlist(head);
            break;

        case 2:
            printf("Enter the data to insert at end:\n");
            scanf("%d", &data);
            head = insertRear(data, head);
            printlist(head);
            break;

        case 3:
            printf("Enter the data to insert:\n");
            scanf("%d", &data);
            printf("Enter the position to insert:\n");
            int pos;
            scanf("%d", &pos);
            head = insertPosition(data, pos, head);
            printlist(head);
            break;

        case 4:
            printf("Enter the data to insert:\n");
            scanf("%d", &data);
            printf("Enter the data after which you want to insert:\n");
            int prevdata;
            scanf("%d", &prevdata);
            head = insertAfterData(data, prevdata, head);
            printlist(head);
            break;

        case 5:
            head = deleteFront(head);
            printlist(head);
            break;

        case 6:
            head = deleteRear(head);
            printlist(head);
            break;

        case 7:
            printf("Enter the position to delete:\n");
            int pos_delete;
            scanf("%d", &pos_delete);
            head = deletePosition(head, pos_delete);
            printlist(head);
            break;

        case 8:
            printf("Enter the data to delete:\n");
            int del_data;
            scanf("%d", &del_data);
            head = deleteData(head, del_data);
            printlist(head);
            break;

        case 9:
            printlist(head);
            break;

        case 10:
            head = deleteList(head);
            break;

        case 11:
            head = insertionSort(head);
            printlist(head);
            break;

        case 12:
            printf("The middle element is: %d\n", middleElement(head)->data);
            break;

        case 13:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid Syntax!!\n");
            printf("Enter the correct choice.\n");
            break;
        }
    } while (ch != 13);
    return 0;
}