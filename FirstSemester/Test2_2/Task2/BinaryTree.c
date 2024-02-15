#include "BinaryTree.h"

#include <string.h>

struct Node
{
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
};

static Node* makeNewNode(const int value)
{
    Node* tree = (Node*)calloc(1, sizeof(Node));
    if (tree == NULL)
    {
        return NULL;
    }

    tree->value = value;
    return tree;
}

void addElement(Node** const tree, const int value)
{
    if (*tree == NULL)
    {
        *tree = makeNewNode(value);
        return;
    }
    else if ((*tree)->value > value)
    {
        addElement(&((*tree)->leftChild), value);
    }
    else
    {
        addElement(&((*tree)->rightChild), value);
    }
}

void deleteTree(Node** const tree)
{
    if (*tree == NULL)
    {
        return;
    }

    deleteTree(&(*tree)->leftChild);
    deleteTree(&(*tree)->rightChild);
    free(*tree);
    *tree = NULL;
}

void orderTree(Node* tree, int* const array, size_t* index)
{
    if (tree != NULL)
    {
        orderTree(tree->leftChild, array, index);

        array[*index] = tree->value;
        ++(*index);

        orderTree(tree->rightChild, array, index);
    }
}

Node* makeTreeFromArray(int* array, size_t length)
{
    Node* tree = NULL;
    for (size_t i = 0; i < length; i++)
    {
        addElement(&tree, array[i]);
    }
    return tree;
}
