#include <stdio.h>
#define TABLE_SIZE 12

void initializeHashTable(int table[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = -1; // Initialize each slot of the table to -1, indicating an empty slot
    }
}

int hash(int key)
{
    return key % TABLE_SIZE; // Returns the index by taking the modulo of the key with the table size
}

void insertKey(int key, int table[])
{
    int index = hash(key);   // Calculate the initial index using the hash function
    int start_index = index; // Store the initial index to detect if the table is full

    // Find the next available slot using linear probing
    while (table[index] != -1 && table[index] != -2)
    {
        index = (index + 1) % TABLE_SIZE; // Move to the next slot using linear probing
        if (index == start_index)
        { // If we've wrapped around and returned to the start index, the table is full
            printf("Hash Table is Full\n");
            return;
        }
    }
    table[index] = key; // Insert the key into the found empty slot
    printf("%d is inserted at index %d\n", key, index);
}

int searchKey(int key, int table[])
{
    int index = hash(key);   // Calculate the initial index using the hash function
    int start_index = index; // Store the initial index to detect if we've traversed the whole table

    // Search for the key using linear probing
    while (table[index] != -1)
    { // While we haven't reached an empty slot
        if (table[index] == key)
        { // If the key is found, print its index and return it
            printf("%d found at index %d\n", key, index);
            return index;
        }
        index = (index + 1) % TABLE_SIZE; // Move to the next slot using linear probing
        if (index == start_index)
        { // If we've traversed the whole table, the key is not present
            printf("Key not found\n");
            return -1;
        }
    }
    printf("Key not found\n"); // If we reach here, the key is not present in the table
    return -1;
}

void deleteKey(int key, int table[])
{
    int index = searchKey(key, table); // Search for the key to find its index in the table
    if (index != -1)
    {                      // If the key is found
        table[index] = -2; // Mark the slot as deleted (-2)
        printf("%d deleted from index %d\n", key, index);
    }
    else
    { // If the key is not found
        printf("Key not found\n");
    }
}

void printHashTable(int table[])
{
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != -1 && table[i] != -2)
        {
            printf("Index %d: Key %d\n", i, table[i]);
        }
        else if (table[i] == -1)
        {
            printf("Index %d: Empty\n", i);
        }
        else
        {
            printf("Index %d: Deleted\n", i);
        }
    }
}

int main()
{
    int hashTable[TABLE_SIZE];
    initializeHashTable(hashTable); // Initialize the hash table

    int choice, key;

    do
    {
        printf("\nHash Table Operations:\n");
        printf("1. Insert a key\n");
        printf("2. Search for a key\n");
        printf("3. Delete a key\n");
        printf("4. Print the hash table\n");
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
            printHashTable(hashTable);
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
