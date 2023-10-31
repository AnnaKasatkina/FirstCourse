﻿#include "List.h"

void initList(List** list)
{
    *list = (List*)malloc(sizeof(List));
    (*list)->begin = NULL;
    (*list)->end = NULL;
    (*list)->size = 0;
}

size_t getSize(List* list)
{
    return list->size;
}

void erase(List* list, size_t index)
{
    ListElement* currentElement = list->begin;
    for (size_t i = 0; i < index - 1; i++)
    {
        currentElement = currentElement->next;
    }

    ListElement* erasedElement = currentElement->next;
    currentElement->next = erasedElement->next;
    free(erasedElement->value);
    free(erasedElement);
    list->size--;
}

void setAt(List* list, size_t index, int value)
{
    ListElement* currentElement = list->begin;
    for (size_t i = 0; i < index; i++)
    {
        currentElement = currentElement->next;
    }
    currentElement->value = value;
}

int getAt(List* list, size_t index)
{
    ListElement* currentElement = list->begin;
    for (size_t i = 0; i < index; i++)
    {
        currentElement = currentElement->next;
    }
    return currentElement->value;
}

ListElement* getElement(List* list, size_t index)
{
    ListElement* currentElement = list->begin;
    for (size_t i = 0; i < index; i++)
    {
        currentElement = currentElement->next;
    }
    return currentElement;
}

void pushBack(List* list, int value)
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
    ListElement* nextAfterEnd = list->end->next;
    while (currentElement != nextAfterEnd)
    {
        ListElement* nextElement = currentElement->next;
        free(currentElement->value);
        free(currentElement);
        currentElement = nextElement;
    }
    free(list);
}
