#pragma once

#include "List.h"
#include "HashTable.h"

#include <stdlib.h>

// Print fill factor HashTable, maximum and average length of the list in segment
void printHashTableStatus(const List* const* const hashTable, const size_t sizeOfTable);

// Print all the words with the number of times
void printHashTableElements(const List* const* const hashTable, const List* const list);
