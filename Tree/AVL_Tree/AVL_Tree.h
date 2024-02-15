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

typedef struct Element Element;

typedef struct Node
{
    int height;
    Element* element;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

// Добавить элемент в дерево
void addElement(Node** const tree, const char* const value, const char* const key);

// Вывод элемента по ключу
char* findElement(const Node* const tree, const char* const key);

// Проверка наличия элемента по ключу
bool checkElement(const Node* const tree, const char* const key);

// Удаление элемента по ключу
void deleteElement(Node** const tree, const char* const key);

// Удаление дерева
void deleteTree(Node** const tree);

// Обход дерева
bool treeTraversal(Node* tree, char** array, size_t* index);
