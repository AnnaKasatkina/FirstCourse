#pragma once

#include "List.h"

#define BUFFERSIZE 30

void readFromFile(char* nameFile, List* list);

// Merging two Lists
List* merge(List* first, List* second, int criteria);

// Recursive function for Merge Sort
List* mergeSort(List* list, int criteria);
