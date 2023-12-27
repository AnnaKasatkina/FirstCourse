#include "List.h"

#include <string.h>

void pushBack(List* const list, char* const value, const size_t length, ErrorCode* const errorCode)
{
    ListElement* newElement = (ListElement*)calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        *errorCode = outOfMemory;
        return;
    }
    newElement->value = value;
    newElement->count = 1;
    newElement->length = length;
    if (list->begin == NULL)
    {
        list->begin = newElement;
        list->end = newElement;
    }
    else
    {
        newElement->next = list->end->next;
        list->end->next = newElement;
        list->end = newElement;
    }
    list->size++;
}

void countDuplicates(List* const list, char* const value, const size_t length, ErrorCode* const errorCode)
{
    ListElement* current = list->begin;
    while (current != NULL)
    {
        if (strcmp(current->value, value) == 0)
        {
            current->count++;
            free(value);
            return;
        }
        current = current->next;
    }
    ListElement* newElement = (ListElement*)malloc(sizeof(ListElement));
    if (newElement == NULL)
    {
        *errorCode = outOfMemory;
        return;
    }

    pushBack(list, value, length, errorCode);
    if (*errorCode != ok)
    {
        return;
    }
}

void freeList(List** const list)
{
    ListElement* currentElement = (*list)->begin;
    while (currentElement != NULL)
    {
        ListElement* next = currentElement->next;
        free(currentElement);
        currentElement = next;
    }
    free(*list);
    *list = NULL;
}
