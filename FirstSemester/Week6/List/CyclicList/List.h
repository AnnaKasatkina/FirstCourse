#pragma once

#include <stdbool.h>

typedef enum ErrorCode
{
    outOfMemory,
    ok
}ErrorCode;

// List element
typedef struct ListElement
{
    size_t value;
    struct ListElement* next;
} ListElement;

// Descripter of List
typedef struct List
{
    ListElement* begin;
    ListElement* end;
    size_t size;
} List;

// Return the element that stands index positions apart
ListElement* getSubsequentElement(ListElement* currentElement, size_t const index);

// Erase next element
void eraseNextElement(ListElement* const currentElement, List* const list);

// Delete the List
void freeList(List* const list);

// Add the element to the end
void pushBack(List* const list, const size_t value, ErrorCode* const errorCode);
