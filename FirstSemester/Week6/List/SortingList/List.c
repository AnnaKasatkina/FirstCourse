#include "List.h"

void initList(List** list)
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

void erase(List* list, size_t index)
{
    ListElement* currentElement = getElement(list, index - 1);

    ListElement* erasedElement = currentElement->next;
    currentElement->next = erasedElement->next;
    free(erasedElement);
}

void setAt(List* list, size_t index, int value)
{
    ListElement * currentElement = getElement(list, index);
    currentElement->value = value;
}

int getAt(List* list, size_t index)
{
    ListElement* currentElement = getElement(list, index);
    return currentElement->value;
}

ListElement* getElement(const List* const list, const size_t index)
{
    ListElement* currentElement = list->begin;
    for (size_t i = 0; i < index; i++)
    {
        if (currentElement == list->end->next)
        {
            printf("Out of List");
            break;
        }
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
        free(currentElement);
        currentElement = nextElement;
    }
    free(list);
}

void addAt(List* const list, const size_t index, const int number)
{
    ListElement* newElement = (ListElement*)malloc(sizeof(ListElement));
    newElement->value = number;
    ListElement* previousElement = getElement(list, index - 1);
    newElement->next = previousElement->next;
    previousElement->next = newElement;
    list->size++;
}
