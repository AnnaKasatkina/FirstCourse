#pragma once

#include <stdio.h>

typedef enum ErrorCode
{
    ok,
    error
}ErrorCode;

typedef struct Node
{
    char operation;
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

// Build tree from a file
Node* buildTree(FILE* file);

// Print the tree
void printTree(const Node* const root);

// Calculatt the value of an expression
int calculateResult(const Node* const tree, ErrorCode* const errorCode);

// Delete tree
void deleteTree(Node** const tree);
