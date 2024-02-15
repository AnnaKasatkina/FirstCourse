#include "List.h"
#include "Task1.h"

#include <stdbool.h>

void printList(const List* const list)
{
    ListElement* currentElement = list->begin;
    size_t size = getSize(list);

    for (size_t i = 0; i < size; ++i)
    {
        printf("%d ", currentElement->value);
        currentElement = currentElement->next;
    }

    printf("\n");
}

int main(void)
{
    List* list = initList();
    if (list == NULL)
    {
        return;
    }

    pushBack(list, 1);
    pushBack(list, 2);
    pushBack(list, 3);
    pushBack(list, 4);
    pushBack(list, 5);

    printList(list);

    deleteOddIndexes(list);
    printList(list);

    freeList(list);

    return 0;
}
