#include "UserModule.h"
#include "Utility.h"

#include <stdio.h>
#include <string.h>

#define PRINT_ERROR "Ошибка ввода!\n"
#define PRINT_NOT_FOUND "Элемент не найден!"

enum Choise
{
    exitProgram,
    addCommand,
    findCommand,
    checkCommand,
    deleteCommand
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
        free(element);
        return NULL;
    }

    element->key = getKey(errorCode);
    if (*errorCode != ok)
    {
        free(element);
        return NULL;
    }

    printf("Введите значение: ");
    getchar();
    element->value = getString(errorCode);
    if (*errorCode != ok)
    {
        free(element);
        return NULL;
    }

    return element;
}

static void methodAdd(const size_t choice, Node** const tree)
{
    ErrorCode errorCode = ok;
    Element* element = getElement(&errorCode);
    if (element == NULL)
    {
        deleteTree(tree);
        printf(PRINT_ERROR);
        return;
    }
    addElement(tree, element);
}

static void methodFind(const size_t choice, Node* const* const tree)
{
    ErrorCode errorCode = ok;
    int key = getKey(&errorCode);
    if (errorCode != ok)
    {
        deleteTree(tree);
        printf(PRINT_ERROR);
        return;
    }
    char* result = findElement(*tree, key);

    printf (result != NULL ? result : PRINT_NOT_FOUND);
    printf("\n");
}

static void methodCheck(const size_t choice, Node* const* const tree)
{
    ErrorCode errorCode = ok;
    int key = getKey(&errorCode);
    if (errorCode != ok)
    {
        deleteTree(tree);
        printf(PRINT_ERROR);
        return;
    }

    if (checkElement(*tree, key))
    {
        printf("Элемент найден");
        return;
    }
    printf(PRINT_NOT_FOUND);
}

static void methodDelete(const size_t choice, Node** const tree)
{
    ErrorCode errorCode = ok;
    int key = getKey(&errorCode);
    if (errorCode != ok)
    {
        deleteTree(tree);
        printf(PRINT_ERROR);
        return;
    }
    deleteElement(tree, key);
}

static void methodExit(const Node** const tree)
{
    deleteTree(tree);
    exit(EXIT_SUCCESS);
}

void choose(const size_t choice, Node** const tree)
{
    switch (choice)
    {
    case exitProgram:
        methodExit(tree);
        break;

    case addCommand:
        methodAdd(choice, tree);
        printf("\n");
        break;

    case findCommand:
        methodFind(choice, tree);
        printf("\n");
        break;

    case checkCommand:
        methodCheck(choice, tree);
        printf("\n\n");
        break;

    case deleteCommand:
        methodDelete(choice, tree);
        printf("\n");
        break;

    default:
        printf("Введено неверное значение.\n");
        break;
    }
}
