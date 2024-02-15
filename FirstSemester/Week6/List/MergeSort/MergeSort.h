#pragma once

#include "List.h"

// Creteria for sort
typedef enum Criteria
{
    byName,
    byNumber
} Criteria;

// Merging two Lists
List* merge(List* const first, List* const second, const Criteria criteria);

// Recursive function for Merge Sort
List* mergeSort(List* const list, const Criteria criteria);