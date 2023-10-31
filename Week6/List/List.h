#pragma once

#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 30

// List element
typedef struct ListElement
{
    char* value;
    struct ListElement* next;
} ListElement;

// Descripter of List
typedef struct List
{
    ListElement* begin;
    ListElement* end;
    size_t size;
} List;

// Print value of List
void printList(const List* const list);

// Read info from file to List
void readFromFile(const char* const nameFile, List* const list);

// Return the size of the List
size_t getSize(const List* const list);

// List initialization
void initList(List** const list);

// Delete element of List at index
void erase(List* const list, const size_t index);

// Change the value at index
void setAt(List* const list, const size_t index, const char* const value);

// Return the value at index
char* getAt(const List* const list, const size_t index);

// Return the element at index
ListElement* getElement(const List* const list, const size_t index);

// Delete the List
void freeList(List* list);

// Add the element to the end
void pushBack(List* const list, const char* const value);
