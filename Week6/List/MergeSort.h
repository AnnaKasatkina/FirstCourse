#pragma once

#include "List.h"

// Creteria for sort
typedef enum Criteria 
{
    byName, 
    byNumber
} Criteria;

// Merging two Lists
List* merge(List* first, List* second, Criteria criteria);

// Recursive function for Merge Sort
List* mergeSort(List* list, Criteria criteria);
