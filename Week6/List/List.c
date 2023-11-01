#include "List.h"

#include <stdio.h>
#include <stdlib.h>

void initList(List** const list)
{
    *list = (List*)malloc(sizeof(List));
    (*list)->begin = NULL;
    (*list)->end = NULL;
    (*list)->size = 0;
}

size_t getSize(const List* const list)
{
    return list->size;
}

bool compareLists(const List* const list1, const List* const list2)
{
    if (getSize(list1) != getSize(list2))
    {
        return false;
    }

    size_t index = getSize(list1);
    ListElement* currentElement1 = list1->begin;
    ListElement* currentElement2 = list2->begin;

    for (size_t i = 0; i < index; ++i)
    {
        if (currentElement1->value != currentElement1->value)
        {
            return false;
        }

        currentElement1 = currentElement1->next;
        currentElement2 = currentElement2->next;
    }

    return true;
}

void erase(List* const list, const size_t index)
{
    ListElement* currentElement = 0;
    if (index == 0)
    {
        currentElement = list->end;
    }
    else
    {
        currentElement = getElement(list, index - 1);
    }

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

void setAt(List* const list, const size_t index, const int value)
{
    getElement(list, index)->value = value;
}

int getAt(const List* const list, const size_t index)
{
    return getElement(list, index)->value;
}

ListElement* getElement(const List* const list, size_t index)
{
    index %= getSize(list);
    ListElement* currentElement = list->begin;
    for (size_t i = 0; i < index; ++i)
    {
        currentElement = currentElement->next;
    }
    return currentElement;
}

void pushBack(List* const list, const int value)
{
    ListElement* newElement = (ListElement*)malloc(sizeof(ListElement));
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
