#pragma once

#include <stdio.h>
#include <stdlib.h>

// Descripter of List
typedef struct List List;

// List element
typedef struct ListElement ListElement;

// Return the size of the List
size_t getSize(List* list);

// List initialization
void initList(List** list);

// Delete element of List at index
void erase(List* list, size_t index);

// Change the value at index
void setAt(List* list, size_t index, int value);

// Return the value at index
int getAt(List* list, size_t index);

// Delete the List
void freeList(List* list);

// Add the element to the end
void pushBack(List* list, int value);