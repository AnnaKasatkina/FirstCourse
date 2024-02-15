#include "UserModule.h"

static void printHashTableStatus(HashTable* const hashTable)
{
    float fillFactor = 0.00;
    size_t maxLength = 0;
    size_t averageLength = 0;

    countHashTableStatus(hashTable, &fillFactor, &maxLength, &averageLength);

    printf("There are %zd words in the text\n"
        "The hash table's fill factor is %.2f\n"
        "The maximum length of the list in segment is %zd\n"
        "The average length of the list in segment is %zd\n",
        hashTable->sizeOfTable, fillFactor, maxLength, averageLength);
}

static void printHashTableElements(HashTable* const hashTable)
{
    for (size_t i = 0; i < hashTable->sizeOfTable; ++i) 
    {
        struct ListElement* current = hashTable->data[i]->begin;
        while (current != NULL) 
        {
            printf("%s: %zu\n", current->value, current->count);
            current = current->next;
        }
    }
}

void printHashTable(HashTable* hashTable)
{
    printHashTableStatus(hashTable);
    printHashTableElements(hashTable);
}
