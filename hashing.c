#include <stdio.h>

#define SIZE 10 // Size of the hash table

int hash(int key) {
    return key % SIZE; // Simple hash function to determine the index
}

void insert(int hashTable[], int key) {
    int index = hash(key); // Get the initial index

    // Look for the next available slot using linear probing
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE; // Increment index and wrap around if needed
    }

    hashTable[index] = key; // Insert the key into the hash table
}

int search(int hashTable[], int key) {
    int index = hash(key); // Get the initial index

    // Search for the key using linear probing
    while (hashTable[index] != key) {
        if (hashTable[index] == -1)
            return -1; // Key not found
        index = (index + 1) % SIZE; // Increment index and wrap around if needed
    }

    return index; // Return the index where the key was found
}

int main() {
    int hashTable[SIZE];
    int i;
    int j;
    int a;
    // Initialize hash table with -1 (indicating empty slot)
    for (i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    /*insert(hashTable, 5);
    insert(hashTable, 15);
    insert(hashTable, 25);
    insert(hashTable, 35);*/
    for(j=0;j<4;j++)
    {
       scanf("%d",&a);
        insert(hashTable, a);
    }

    printf("Hash Table:\n");
    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }

    int searchKey = 15;
    int searchResult = search(hashTable, searchKey);
    if (searchResult == -1) {
        printf("Key %d not found.\n", searchKey);
    } else {
        printf("Key %d found at index %d.\n", searchKey, searchResult);
    }

    return 0;
}

