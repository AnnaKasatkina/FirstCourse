#pragma once

typedef struct Node
{
    char value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* buildTree(char** string, Node** tree);

char* getStringFromTree(Node* tree);

int countResult(char* string);
