#include "UserModule.h"
#include "Utility.h"

#include <stdio.h>
#include <string.h>

#define BREAK_LINE printf("\n")

enum Choise
{
    exitProgram,
    add,
    find,
    check,
    delete
};

static int getKey(ErrorCode* const errorCode)
{
    printf("Введите ключ: ");
    int key = 0;
    if (scanf(" %d", &key) != 1)
    {
        *errorCode = inputError;
        return 0;
    }
    return key;
}

static Element* getElement(ErrorCode* errorCode)
{
    Element* element = malloc(sizeof(Element));
    if (element == NULL)
    {
        *errorCode = outOfMemory;
        return NULL;
    }

    element->key = getKey(errorCode);
    if (*errorCode != ok)
    {
        return NULL;
    }

    printf("Введите значение: ");
    element->value = getString(errorCode);
    if (*errorCode != ok)
    {
        return NULL;
    }

    return element;
}

static void methodAdd(const size_t choice, Node** const tree)
{
    ErrorCode errorCode = ok;
    Element* element = getElement(&errorCode);
    if (errorCode != ok)
    {
        printf("Ошибка!\n");
        return;
    }
    addElement(tree, element);
}

static void methodFind(const size_t choice, const Node* const* const tree)
{
    ErrorCode errorCode = ok;
    int key = getKey(&errorCode);
    if (errorCode != ok)
    {
        printf("Ошибка ввода!");
        return;
    }
    char* result = findElement(*tree, key);

    result != NULL ? printf(result) : printf("Элемент не найден!");
    BREAK_LINE;
}

static void methodCheck(const size_t choice, const Node* const* const tree)
{
    ErrorCode errorCode = ok;
    int key = getKey(&errorCode);
    if (errorCode != ok)
    {
        printf("Ошибка ввода!");
        return;
    }

    if (checkElement(*tree, key))
    {
        printf("Элемент найден");
        return;
    }
    printf("Элемент не найден!");
}

static void methodDelete(const size_t choice, Node** const tree)
{
    bool flag = false;
    ErrorCode errorCode = ok;
    int key = getKey(&errorCode);
    if (errorCode != ok)
    {
        printf("Ошибка ввода!");
        return;
    }
    deleteElement(tree, key, &flag);
}

void choose(const size_t choice, Node** const tree)
{
    switch (choice)
    {
    case exitProgram:
        exit(EXIT_SUCCESS);
        break;

    case add:
        methodAdd(choice, tree);
        BREAK_LINE;
        break;

    case find:
        methodFind(choice, tree);
        BREAK_LINE;
        break;

    case check:
        methodCheck(choice, tree);
        BREAK_LINE;
        break;

    case delete:
        methodDelete(choice, tree);
        BREAK_LINE;
        break;

    default:
        printf("Введено неверное значение.\n");
        break;
    }
}