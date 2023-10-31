#pragma once

#include "List.h"

// Fill the List with indexes
void fillList(const size_t amount, List* const list);

// Calculate a safe place
void count(const size_t amount, const size_t gap, List* const list);

// Print result
void printResult(const List* const list);

// Convert a list to an array
int* listToArray(const List* const list, const size_t gap);
