#pragma once

#include <stdio.h>
#include <stdlib.h>

// enum for ErrorCode
typedef enum
{
    ok,
    errorCode,
    outOfMemory
} ErrorCode;

// List element
typedef struct ListElement
{
    const char* value;
    size_t length;
    size_t count;
    struct ListElement* next;
}ListElement;

// Descripter of List
typedef struct List
{
    ListElement* begin;
    ListElement* end;
    size_t size;
}List;

// Delete the List
void freeList(List** const list);

// Add the element to the end
void pushBack(List* const list, char* const value, const size_t length, ErrorCode* const errorCode);

// Count duplicates and add non-duplicate elements
void countDuplicates(List* const list, char* const value, const size_t length, ErrorCode* const errorCode);
