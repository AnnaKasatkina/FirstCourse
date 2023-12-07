#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "List.h"

// Calculare Hash
size_t calculateHash(const char* const string, const size_t lengthString, const size_t number);

// Make HashTable from list
List** makeHashTable(const List* const list);

// Count fill factor HashTable, maximum and average length of the list in segment
void countHashTableStatus(const List* const* const hashTable, const size_t sizeOfTable,
    float* const fillFactor, size_t* const maxLength, size_t* const averageLength);

// Count the number of times a word occurs
size_t* countHashTableElements(const List* const* const hashTable, const List* const list);
