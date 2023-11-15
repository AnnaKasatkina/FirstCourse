#include "BinaryTree.h"

#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    Element* element;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

static Node* makeNewElement(const Element* const element)
{
    Node* tree = (Node*)calloc(1, sizeof(Node));
    if (tree == NULL)
    {
        return NULL;
    }

    tree->element = element;
    return tree;
}

void addElement(Node** const tree, const Element* const element)
{
    if (*tree == NULL)
    {
        *tree = makeNewElement(element);
        return;
    }
    if ((*tree)->element->key == element->key)
    {
        (*tree)->element = element;
        return;
    }
    else if ((*tree)->element->key > element->key)
    {
        addElement(&((*tree)->leftChild), element);
    }
    else
    {
        addElement(&((*tree)->rightChild), element);
    }
}

char* findElement(const Node* const tree, const int key)
{
    if (tree == NULL)
    {
        return NULL;
    }
    if (tree->element->key == key)
    {
        return tree->element->value;
    }
    else if (tree->element->key > key)
    {
        findElement(tree->leftChild, key);
    }
    else
    {
        findElement(tree->rightChild, key);
    }
}

bool checkElement(const Node* const tree, const int key)
{
    return findElement(tree, key) != NULL;
}

static Node* findNextElement(const Node* const tree)
{
    Node* nextElement = tree->rightChild;
    while (nextElement != NULL && nextElement->leftChild != NULL)
    {
        nextElement = nextElement->leftChild;
    }
    return nextElement;
}

static void freeNode(Node** const tree, bool* const flag)
{
    free((*tree)->element);
    free(*tree);
    *tree = NULL;
    *flag = true;
}

void deleteElement(Node** const tree, const int key, bool* const flag)
{
    if (*tree == NULL)
    {
        *flag = true;
        return;
    }
    if (key > (*tree)->element->key)
    {
        deleteElement(&((*tree)->rightChild), key, flag);
    }
    if (key < (*tree)->element->key)
    {
        deleteElement(&((*tree)->leftChild), key, flag);
    }
    else
    {
        if (*flag)
        {
            return;
        }
        if ((*tree)->leftChild == NULL && (*tree)->rightChild == NULL)
        {
            freeNode(tree, flag);
            return;
        }
        else if ((*tree)->rightChild == NULL)
        {
            (*tree)->element = (*tree)->leftChild->element;
            freeNode(&((*tree)->leftChild), flag);
            return;
        }
        else if ((*tree)->leftChild == NULL)
        {
            (*tree)->element = (*tree)->rightChild->element;
            freeNode(&((*tree)->rightChild), flag);
            return;
        }
        else
        {
            Node* nextElement = findNextElement(*tree);
            (*tree)->element = nextElement->element;
            deleteElement(&((*tree)->rightChild), nextElement->element->key, flag);
        }
        if (*flag)
        {
            return;
        }
    }
}
