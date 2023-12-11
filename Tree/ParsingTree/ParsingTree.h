#pragma once

#include <stdio.h>

typedef enum ErrorCode
{
    ok,
    error,
    divisionByZero,
    wrongOperation,
    treeIsEmpty
}ErrorCode;

typedef struct Node
{
    char value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

// Build tree from a file
Node* buildTree(FILE* file);

// Print the tree
void printTree(const Node* const root, ErrorCode* const errorCode);

// Calculatt the value of an expression
char calculateResult(const Node* const tree, ErrorCode* const errorCode);

// Delete tree
void deleteTree(Node** const tree);
