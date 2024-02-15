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
    int key;
} Element;

typedef struct Node
{
    Element* element;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

// Добавить элемент в дерево
void addElement(Node** const tree, const Element* const element);

// Вывод элемента по ключу
char* findElement(const Node* const tree, const int key);

// Проверка наличия элемента по ключу
bool checkElement(const Node* const tree, const int key);

// Удаление элемента по ключу
void deleteElement(Node** const tree, const int key);

// Удаление дерева
void deleteTree(Node** const tree);
