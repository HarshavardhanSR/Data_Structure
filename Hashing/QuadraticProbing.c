#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 11

// Function to initialize the hash table
void initializeHashTable(int arr[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        arr[i] = -1; // Initialize each slot of the table to -1, indicating an empty slot
    }
}

// Hash function to determine the index in the hash table
int hash(int key)
{
    return key % TABLE_SIZE; // Returns the index by taking the modulo of the key with the table size
}

// Function to insert a key into the hash table using quadratic probing
void insertKey(int key, int table[])
{
    int index = hash(key); // Calculate the initial index using the hash function
    int i = 0;

    // Quadratic probing
    while (table[index] != -1)
    {                                         // While the slot is not empty
        i++;                                  // Increase the quadratic offset
        index = (index + i * i) % TABLE_SIZE; // Calculate the next index using quadratic probing

        if (i == TABLE_SIZE)
        { // If we've tried all slots and the table is full
            printf("Hash Table is Full\n");
            return;
        }
    }
    table[index] = key; // Insert the key into the found empty slot
    printf("%d is inserted at index %d\n", key, index);
}

// Function to search for a key in the hash table
int searchKey(int key, int table[])
{
    int index = hash(key); // Calculate the initial index using the hash function
    int i = 0;
    // Quadratic probing
    while (table[index] != -1)
    { // While the slot is not empty
        if (table[index] == key)
        { // If the key is found, print its index and return it
            printf("%d found at index %d\n", key, index);
            return index;
        }

        i++;                                  // Increase the quadratic offset
        index = (index + i * i) % TABLE_SIZE; // Calculate the next index using quadratic probing

        if (i == TABLE_SIZE)
        { // If we've tried all slots and the key is not found
            printf("Key not found\n");
            return -1;
        }
    }
    printf("Key not found\n"); // If we reach here, the key is not present in the table
    return -1;
}

// Function to delete a key from the hash table
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