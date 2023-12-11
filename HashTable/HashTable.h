#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "List.h"

typedef struct
{
    List** data;
    size_t sizeOfTable;
} HashTable;

// Initialize HashTable
HashTable* initializeHashTable(const size_t sizeOfTable);

// Make HashTable from list
HashTable* makeHashTable(const List* const list, size_t sizeOfTable);

// Count fill factor HashTable, maximum and average length of the list in segment
void countHashTableStatus(HashTable* hashTable, float* const fillFactor, 
    size_t* const maxLength, size_t* const averageLength);

void deleteHashTable(HashTable* hashTable);
