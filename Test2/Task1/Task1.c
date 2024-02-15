#include "Task1.h"

void deleteOddIndexes(List* list)
{
    ListElement* currentElement = list->begin;
    size_t size = getSize(list);

    for (size_t i = 1; i < size; ++i)
    {
        erase(list, i);
        --size;
    }
}
