#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef enum ErrorCode
{
    ok,
    stackIsEmpty,
    outOfMemory,
    error,
    inputError
}ErrorCode;

typedef struct Node
{
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

// Add element in tree
void addElement(Node** const tree, const int value);

// Delete tree
void deleteTree(Node** const tree);

// Order tree
void orderTree(Node* tree, int* const array, size_t* index);

// Make tree from array
Node* makeTreeFromArray(int* array, size_t length);
