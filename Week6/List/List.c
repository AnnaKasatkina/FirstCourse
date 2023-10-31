#include "List.h"

void printList(const List* const list)
{
    for (size_t i = 0; i < getSize(list); i++)
    {
        printf("%s - %s\n", getAt(list, i), getAt(list, i) + BUFFERSIZE);
    }
}

void readFromFile(const char* const nameFile, List* const list)
{
    FILE* file = fopen(nameFile, "r");
    if (file == NULL)
    {
        printf("File is not open\n");
        return;
    }

    while (!feof(file))
    {
        char* newEntry = (char*)malloc(sizeof(char) * BUFFERSIZE * 2);
        fscanf(file, "%s - %s", newEntry, newEntry + BUFFERSIZE);
        pushBack(list, newEntry);
    }
    fclose(file);
}

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

void erase(List* const list, const size_t index)
{
    ListElement* currentElement = list->begin;
    for (size_t i = 0; i < index - 1; i++)
    {
        if (currentElement == list->end->next)
        {
            printf("Out of List");
            return;
        }
        currentElement = currentElement->next;
    }

    ListElement* erasedElement = currentElement->next;
    currentElement->next = erasedElement->next;
    free(erasedElement->value);
    free(erasedElement);
}

void setAt(List* const list, const size_t index, const char* const value)
{
    ListElement* currentElement = list->begin;
    for (size_t i = 0; i < index; i++)
    {
        if (currentElement == list->end->next)
        {
            printf("Out of List");
            return;
        }
        currentElement = currentElement->next;
    }
    currentElement->value = value;
}

char* getAt(const List* const list, const size_t index)
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

void pushBack(List* const list, const char* const value)
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
        free(currentElement->value);
        free(currentElement);
        currentElement = nextElement;
    }
    free(list);
}
