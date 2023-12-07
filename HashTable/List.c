#include "List.h"

List* initList(void)
{
    List* list = (List*)malloc(sizeof(List));

    if (list == NULL)
    {
        return NULL;
    }
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;

    return list;
}

void erase(List* list, size_t index)
{
    if (index == 0)
    {
        ListElement* currentElement = list->begin;
        list->begin = currentElement->next;
        free(currentElement);
        return;
    }

    ListElement* currentElement = getElement(list, index - 1);
    ListElement* erasedElement = currentElement->next;
    currentElement->next = erasedElement->next;
    free(erasedElement);
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

void pushBack(List* list, char* value, size_t length)
{
    ListElement* newElement = (ListElement*)calloc(1, sizeof(ListElement));
    newElement->value = value;
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
