#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef struct Node Node;

// Add element in tree
void addElement(Node** const tree, const int value);

// Delete tree
void deleteTree(Node** const tree);

// Order tree
void orderTree(Node* tree, int* const array, size_t* index);

// Make tree from array
Node* makeTreeFromArray(int* array, size_t length);
