#pragma once

#include <stdbool.h>

// List element
typedef struct ListElement
{
    int value;
    struct ListElement* next;
} ListElement;

// Descripter of List
typedef struct List
{
    ListElement* begin;
    ListElement* end;
    size_t size;
} List;

// Return the size of the List
size_t getSize(const List* const list);

// List initialization
void initList(List** const list);

// Compare Lists
bool compareLists(const List* const list1, const List* const list2);

// Delete element of List at index
void erase(List* const list, const size_t index);

// Change the value at index
void setAt(List* const list, const size_t index, const int value);

// Return the value at index
int getAt(const List* const list, const size_t index);

// Return the element at index
ListElement* getElement(const List* const list, size_t index);

// Delete the List
void freeList(List* list);

// Add the element to the end
void pushBack(List* const list, const int value);
