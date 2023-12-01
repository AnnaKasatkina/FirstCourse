#include "AVL_Tree.h"

#include <stdlib.h>
#include <string.h>

static void freeElement(Node** const tree)
{
    free((*tree)->element->value);
    free((*tree)->element->key);
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

    const int compare = strcmp((*tree)->element->key, element->key);
    if (compare == 0)
    {
        freeElement(tree);
        (*tree)->element = element;
        return;
    }
    else if (compare > 0)
    {
        addElement(&((*tree)->leftChild), element);
    }
    else
    {
        addElement(&((*tree)->rightChild), element);
    }
}

char* findElement(const Node* const tree, const char* const key)
{
    if (tree == NULL)
    {
        return NULL;
    }

    const int compare = strcmp(tree->element->key, key);
    if (compare == 0)
    {
        return tree->element->value;
    }
    else if (compare > 0)
    {
        return findElement(tree->leftChild, key);
    }
    else
    {
        return findElement(tree->rightChild, key);
    }
}

bool checkElement(const Node* const tree, const char* const key)
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

void deleteElement(Node** const tree, const char* const key)
{
    if (*tree == NULL)
    {
        return;
    }

    const int compare = strcmp(key, (*tree)->element->key);
    if (compare > 0)
    {
        deleteElement(&((*tree)->rightChild), key);
        return;
    }
    if (compare < 0)
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
        strcpy((*tree)->element->key, nextElement->element->key);
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

void copyValue(Node** const treeOne, Node** const treeTwo)
{
    strcpy((*treeOne)->element->key, (*treeTwo)->element->key);
    strcpy((*treeOne)->element->value, (*treeTwo)->element->value);
}

void swapNodes(Node** const treeOne, Node** const treeTwo)
{
    Node* tmpNode = makeNewNode((*treeOne)->element);

    copyValue(*treeOne, *treeTwo);
    copyValue(*treeTwo, tmpNode);

    freeNode(&tmpNode);
}

void rightRotateTree(Node** const tree)
{
    swapNodes(tree, &((*tree)->leftChild));

    Node* tmpNode = makeNewNode((*tree)->rightChild);
    copyValue((*tree)->rightChild, (*tree)->leftChild);
    copyValue((*tree)->leftChild, (*tree)->leftChild);


    freeNode(&tmpNode);

}

void balanceTree()
{

}

