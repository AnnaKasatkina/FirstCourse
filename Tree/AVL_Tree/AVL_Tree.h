#pragma once

#include <stdbool.h>

typedef enum ErrorCode
{
    ok,
    stackIsEmpty,
    outOfMemory,
    error,
    inputError
}ErrorCode;

typedef struct Element
{
    char* value;
    char* key;
} Element;

typedef struct Node
{
    int height;
    Element* element;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

// Добавить элемент в дерево
void addElement(Node** const tree, const Element* const element);

// Вывод элемента по ключу
char* findElement(const Node* const tree, const char* const key);

// Проверка наличия элемента по ключу
bool checkElement(const Node* const tree, const char* const key);

// Удаление элемента по ключу
void deleteElement(Node** const tree, const char* const key);

// Удаление дерева
void deleteTree(Node** const tree);
