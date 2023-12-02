#include "List.h"

#include <string.h>

bool compareLists(List* list1, List* list2)
{
    size_t length = getSize(list1);

    ListElement* element1 = list1->begin;
    ListElement* element2 = list2->begin;

    for (size_t i = 0; i < length; i++)
    {
        if (element1 == list1->end->next || element2 == list2->end->next)
        {
            printf("Out of List");
            break;
        }

        if (strcmp(element1->value[0], element2->value[0]) != 0 || strcmp(element1->value[1], element2->value[1]) != 0)
        {
            return false;
        }

        element1 = element1->next;
        element2 = element2->next;
    }

    return true;
}

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
