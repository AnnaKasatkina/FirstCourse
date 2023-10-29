#include "List.h"

int main() {
    List* list = 0;
    initList(&list);
    pushBack(list, 5);
    pushBack(list, 7);
    pushBack(list, 8);
    pushBack(list, 9);
    for (size_t i = 0; i < getSize(list); i++)
    {
        printf("%d", getAt(list, i));
    }
    freeList(list);
}