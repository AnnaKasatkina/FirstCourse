#include "List.h"

#include <stdio.h>
#include <stdlib.h>

ListElement* getSubsequentElement(ListElement* currentElement, const size_t index)
{
    for (size_t i = 2; i < index; i++)
    {
        currentElement = currentElement->next;
    }
    return currentElement;
}

static size_t getSize(const List* const list)
{
    return list->size;
}

void eraseNextElement(ListElement* const currentElement, List* const list)
{
    ListElement* erasedElement = currentElement->next;
    currentElement->next = erasedElement->next;

    if (currentElement == list->end)
    {
        list->begin = currentElement->next;
    }
    if (erasedElement == list->end) {
        list->end = currentElement;
    }
    free(erasedElement);
    list->size--;
}

void pushBack(List* const list, const size_t value, ErrorCode* errorCode)
{
    ListElement* newElement = (ListElement*)calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        *errorCode = outOfMemory;
        return;
    }

    newElement->value = value;
    if (list->begin == NULL)
    {
        list->begin = newElement;
        list->end = newElement;
        list->end->next = list->begin;
    }
    else
    {
        newElement->next = list->end->next;
        list->end->next = newElement;
        list->end = newElement;
    }
    list->size++;
}

void freeList(List* list)
{
    ListElement* currentElement = list->begin;
    size_t size = getSize(list);
    for (size_t i = 0; i < size; ++i)
    {
        ListElement* nextElement = currentElement->next;
        free(currentElement);
        currentElement = nextElement;
    }
    free(list);
}
