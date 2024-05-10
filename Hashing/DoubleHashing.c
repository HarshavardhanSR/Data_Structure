#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 11

void initializeHashTable(int arr[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        arr[i] = -1;
    }
}

int hash(int key, int attempt)
{
    // First hash function
    int h1 = key % TABLE_SIZE;

    // Second hash function
    int h2 = 7 - (key % 7); // 7 is chosen as a prime number smaller than TABLE_SIZE

    return (h1 + attempt * h2) % TABLE_SIZE;
}

void insertKey(int key, int table[])
{
    int attempt = 0;
    int index;

    do
    {
        index = hash(key, attempt++);
        if (table[index] == -1 || table[index] == -2)
        {
            table[index] = key;
            printf("%d is inserted at index %d\n", key, index);
            return;
        }
    } while (attempt < TABLE_SIZE);

    printf("Hash Table is Full\n");
}

int searchKey(int key, int table[])
{
    int attempt = 0;
    int index;

    do
    {
        index = hash(key, attempt++);
        if (table[index] == key)
        {
            printf("%d found at index %d\n", key, index);
            return index;
        }
    } while (attempt < TABLE_SIZE && table[index] != -1);

    printf("Key not found\n");
    return -1;
}

void deleteKey(int key, int table[])
{
    int index = searchKey(key, table);
    if (index != -1)
    {
        table[index] = -2;
        printf("%d deleted from index %d\n", key, index);
    }
    else
    {
        printf("Key not found\n");
    }
}

void displayTable(int table[])
{
    printf("Hash Table: ");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != -1)
        {
            printf("%d ", table[i]);
        }
        else
        {
            printf("- ");
        }
    }
    printf("\n");
}

int main()
{
    int hashTable[TABLE_SIZE];
    initializeHashTable(hashTable);

    int choice, key;

    do
    {
        printf("\nHash Table Operations:\n");
        printf("1. Insert a key\n");
        printf("2. Search for a key\n");
        printf("3. Delete a key\n");
        printf("4. Display the hash table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the key to insert: ");
            scanf("%d", &key);
            insertKey(key, hashTable);
            break;
        case 2:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            searchKey(key, hashTable);
            break;
        case 3:
            printf("Enter the key to delete: ");
            scanf("%d", &key);
            deleteKey(key, hashTable);
            break;
        case 4:
            displayTable(hashTable);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

