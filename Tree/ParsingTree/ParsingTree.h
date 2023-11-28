#pragma once

#include "Stack.h"

typedef struct Node
{
    char value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* buildTree(char** string, Node** tree);

char* getStringFromTree(Node* tree);

int calculateResult(char* string, ErrorCode* errorCode);

void deleteTree(Node** const tree);
