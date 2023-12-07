#pragma once

#include <stdio.h>
#include <stdlib.h>

// List element
typedef struct ListElement
{
    char* value;
    size_t length;
    struct ListElement* next;
}ListElement;

// Descripter of List
typedef struct List
{
    ListElement* begin;
    ListElement* end;
    size_t size;
}List;

// List initialization
List* initList(void);

// Delete element of List at index
void erase(List* list, size_t index);

// Return the element at index
ListElement* getElement(const List* const list, const size_t index);

// Delete the List
void freeList(List* list);

// Add the element to the end
void pushBack(List* list, char* value, size_t length);
