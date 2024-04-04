#include<stdio.h>
#include<stdlib.h>

// Author : Code_with_Passion
// Name : Harshavardhan SR
// Linked list
// Menu driven Program 
// createing the structure

typedef struct node{
    int data;
    struct node* next;
}Node;

// createing the node
Node* createnode(int newdata){
    Node* newNode = (Node*)malloc(sizeof(Node*));
    if(newNode==NULL){
        printf("Allocation of the memory failed ");
        return NULL;
    }
    newNode->data = newdata;
    newNode->next = NULL;
    return newNode;
}

// Insert front
Node* insertFront(int data,Node* head){
    Node * newNode = createnode(data);
    newNode->next=head;
    head=newNode;
    return head;
}

// Insert rear
Node* insertRear(int data,Node* head){
    Node *newNode = createnode(data);
    if(head==NULL){
        head = newNode;
        return head;
    }
    Node *temp = head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return newNode;
}

// Insert Position 
Node* insertPosition(int data,int pos,Node* head){
    Node *newNode = createnode(data);
    if( pos < 1 ){
        printf("Invalid Postion !! \n");
        free(newNode);
        return head;
    }
    else if(pos == 1){
        newNode->next=head;
        head = newNode;
        return head;
    }
    int count=1;
    Node *temp=head;
    Node *prev=NULL;
    while(temp->next != NULL && count != pos){
        prev=temp;
        temp=temp->next;
        count ++;
    }
    if(temp==NULL & count != pos){
        printf("Invalid Position!! \n");
        free(newNode);
        return head;
    }
    prev->next=newNode;
    newNode->next=temp;
    return head;
}

// Insert after a data
Node *insertAfterData(int data, int prevdata, Node *head)
{
    Node *newNode = createnode(data);
    if (head == NULL)
    {
        printf("Empty List \n");
        return head;
    }
    Node *temp = head;
    while (temp != NULL && temp->data != prevdata)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Data not found !! \n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Delete front
Node* deleteFront(Node* head){
    if (head == NULL)
    {
        printf("Empty List \n");
        return head;
    }
    Node *temp = head;
    head = temp->next;
    int deldata = temp->data;
    printf("The data in beginning is going to be deleted : %d \n", deldata);
    free(temp);
    return head;
}

// Delete Rear
Node* deleteRear(Node* head){
    if (head == NULL)
    {
        printf("Empty List \n");
        return head;
    }
    if (head->next == NULL){
        free(head);
        return NULL;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp= temp->next;
    }
    prev->next = NULL;
    free(temp);
    return head;
}

//Delete from given position 
Node* deletePostion(Node* head, int pos){
    Node *temp = head;
    if (pos < 1)
    {
        printf("Invalid Postion !! \n");
        return head;
    }
    else if (pos == 1)
    {
        head=head->next;
        free(temp);
        return head;
    }
    int count = 1;
    Node *prev = NULL;
    while (temp->next != NULL && count != pos)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (temp == NULL & count != pos)
    {
        printf("Invalid Position!! \n");
        return head;
    }
    prev->next = temp->next ;
    return head;
}

//Delete the given data
Node* deleteData(Node* head, int deldata){
    Node* temp = head;
    if(deldata== head->data){
        head = head->next;
        free(temp);
        return head;
    }
    Node *prev=NULL;
    while(temp != NULL && temp->data != deldata){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Data not found !! \n");
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;

}

//Deleting all elements in the list
Node* deleteList(Node* head){
    Node *temp = head;
    while (temp != NULL)
    {
        head = temp;
        temp = temp->next;
        free(head);
    }
    printf("All the Elements in the list are deleted \n");
    head = NULL;
    return head;
}

//Finding the middle elemnt in the list
Node* middleElement(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//Sorting the elements in the array
Node *insertionSort(Node *head){
    if(head== NULL || head->next == NULL){
        return head;
    }
    Node* sortedlist=NULL;
    while (head != NULL){
        Node *current = head;
        head = head->next;

        if (sortedlist == NULL || current->data <= sortedlist->data)
        {
            current->next = sortedlist;
            sortedlist = current;
        }
        else
        {
            Node *temp = sortedlist;
            while (temp->next != NULL && temp->next->data < current->data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    return sortedlist;
}

//Printing all the List
void printlist(Node* head){
    if(head==NULL){
        printf("Empty LIst \n");
        return;
    }
    Node *temp = head;
    printf("Printing the list: \n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n\n");
}

// Main fuction 
int main(){
    int ch,data;
    Node* head=NULL;
    printf("Author : Harshavardhan SR !!!\n\n");
    do{
        printf("Single Linked List !! \n\n");
        printf("Insertion !!\n");
        printf("1.Insert At Beginning. \n");
        printf("2.Insert At End. \n");
        printf("3.Insert At Position. \n");
        printf("4.Insert After Data. \n\n");
        printf("Deletion !!\n");
        printf("5.Delete At Beginning. \n");
        printf("6.Delete At End. \n");
        printf("7.Delete At Position. \n");
        printf("8.Delete After Data. \n\n");
        printf("9.Print List");
        printf("10.Clear the list. \n");
        printf("11.Sort elements in the linked list. \n");
        printf("12.Find the midddle elemtnt of the list. \n");
        printf("13.Exit. \n");
        printf("Enter your choice : \n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                printf("Enter the data to insert at Beginning : \n");
                scanf("%d",&data);
                head=insertFront(data,head);
                printlist(head);
                break;
            
            case 2:
                printf("Enter the data to insert at End : \n");
                scanf("%d", &data);
                head = insertRear(data, head);
                printlist(head);
                break;

            case 3:
                printf("Enter the data to insert: \n");
                scanf("%d", &data);
                printf("Enter the position to insert: \n");
                int pos;
                scanf("%d", &pos);
                head = insertPosition(data, pos, head);
                printlist(head);
                break;

            case 4:
                printf("Enter the data to insert: \n");
                scanf("%d", &data);
                printf("Enter the data after which you want to insert: \n");
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
                printf("Enter the position to delete: \n");
                int pos_delete;
                scanf("%d", &pos_delete);
                head = deletePostion(head, pos_delete);
                printlist(head);
                break;

            case 8:
                printf("Enter the data to delete: \n");
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
                printf("Invalide Syntax !! \n");
                printf("Enter the correct choice \n .");
                break;
        }
    }while(ch != 13);
}