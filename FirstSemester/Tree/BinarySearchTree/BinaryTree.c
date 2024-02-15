#include "BinaryTree.h"

#include <stdlib.h>
#include <string.h>

static void freeElement(Node** const tree)
{
    free((*tree)->element->value);
    free((*tree)->element);
}

static Node* makeNewNode(const Element* const element)
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
        *tree = makeNewNode(element);
        return;
    }
    if ((*tree)->element->key == element->key)
    {
        freeElement(tree);
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
        return findElement(tree->leftChild, key);
    }
    else
    {
        return findElement(tree->rightChild, key);
    }
}

bool checkElement(const Node* const tree, const int key)
{
    return findElement(tree, key) != NULL;
}

static Node* findNextElement(const Node* const tree)
{
    Node* nextElement = tree->rightChild;
    for (; nextElement->leftChild; nextElement = nextElement->leftChild);
    return nextElement;
}

static void freeNode(Node** const tree)
{
    freeElement(tree);
    free(*tree);
    *tree = NULL;
}

void deleteElement(Node** const tree, const int key)
{
    if (*tree == NULL)
    {
        return;
    }

    if (key > (*tree)->element->key)
    {
        deleteElement(&((*tree)->rightChild), key);
        return;
    }
    if (key < (*tree)->element->key)
    {
        deleteElement(&((*tree)->leftChild), key);
        return;
    }

    if ((*tree)->leftChild == NULL && (*tree)->rightChild == NULL)
    {
        freeNode(tree);
        return;
    }
    if ((*tree)->rightChild == NULL)
    {
        Node* tmp = *tree;
        *tree = (*tree)->leftChild;
        freeNode(&tmp);
        return;
    }
    if ((*tree)->leftChild == NULL)
    {
        Node* tmp = *tree;
        *tree = (*tree)->rightChild;
        freeNode(&tmp);
        return;
    }
    else
    {
        Node* nextElement = findNextElement(*tree);
        (*tree)->element->key = nextElement->element->key;
        strcpy((*tree)->element->value, nextElement->element->value);

        if (*tree != NULL)
        {
            deleteElement(&((*tree)->rightChild), nextElement->element->key);
        }
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
    freeNode(tree);
}
