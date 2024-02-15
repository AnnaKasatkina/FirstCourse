#include "SortingList.h"

#include <stdio.h>

void addElement(List* const list)
{
    ListElement* currentElement = list->begin;
    size_t size = getSize(list);

    printf("Введите число: ");
    int number = 0;
    if (scanf("%d", &number) != 1)
    {
        printf("Ошибка ввода!");
        return;
    }

    if (size != 0)
    {
        if (number < currentElement->value)
        {
            ListElement* newElement = (ListElement*)malloc(sizeof(ListElement));
            newElement->value = number;
            newElement->next = currentElement;
            list->begin = newElement;
            list->size++;
            return;
        }

        currentElement = currentElement->next;
        for (size_t i = 1; i < size; ++i)
        {
            if (number < currentElement->value)
            {
                addAt(list, i, number);
                return;
            }
            currentElement = currentElement->next;
        }
    }

    pushBack(list, number);
}

void printList(const List* const list)
{
    printf("Результат: ");
    ListElement* currentElement = list->begin;
    size_t size = getSize(list);
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", currentElement->value);
        currentElement = currentElement->next;
    }
}

void deleteElement(List* const list)
{
    ListElement* currentElement = list->begin;
    size_t size = getSize(list);

    printf("Введите число: ");
    int number = 0;
    if (scanf("%d", &number) != 1)
    {
        printf("Ошибка ввода!");
        return;
    }

    if (number == currentElement->value)
    {
        list->begin = currentElement->next;
        free(currentElement);
        list->size--;
        return;
    }
    currentElement = currentElement->next;

    for (size_t i = 1; i < size; ++i)
    {
        if (number == currentElement->value)
        {
            erase(list, i);
            list->size--;
            return;
        }
        currentElement = currentElement->next;
    }
    printf("Элемент не найден");
}

void choose(const size_t choice, List* const list)
{
    switch (choice)
    {
    case 0:
        exit(EXIT_SUCCESS);
        break;

    case 1:
        addElement(list);
        printf("\n");
        break;

    case 2:
        deleteElement(list);
        printf("\n");
        break;

    case 3:
        printList(list);
        printf("\n\n");
        break;

    default:
        printf("Введено неверное значение.\n");
        break;
    }
}
