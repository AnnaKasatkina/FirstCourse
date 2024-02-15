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

static char* getValue(ErrorCode* const errorCode, const char* const nameValue)
{
    getchar();
    printf("Введите %s: ", nameValue);
    return getString(errorCode);
}

static void methodAdd(const size_t choice, Node** const tree)
{
    ErrorCode errorCode = ok;
    char* key = getValue(&errorCode, "key");
    char* value = getValue(&errorCode, "value");

    addElement(tree, value, key);
}

static void methodFind(const size_t choice, Node** const tree)
{
    ErrorCode errorCode = ok;
    char* key = getValue(&errorCode, "ключ");
    if (errorCode != ok)
    {
        deleteTree(tree);
        printf(PRINT_ERROR);
        return;
    }
    char* result = findElement(*tree, key);

    printf(result != NULL ? result : PRINT_NOT_FOUND);
    printf("\n");
}

static void methodCheck(const size_t choice, Node** const tree)
{
    ErrorCode errorCode = ok;
    char* key = getValue(&errorCode, "ключ");
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
    char* key = getValue(&errorCode, "ключ");
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
