#include "AVL_Tree.h"

#include <stdlib.h>
#include <string.h>

int getHeight(Node* tree)
{
    return tree == NULL ? -1 : tree->height;
}

void updateHeight(Node* tree)
{
    tree->height = max(getHeight(tree->leftChild), getHeight(tree->rightChild)) + 1;
}

int getBalance(Node* tree)
{
    return tree == NULL ? 0 : getHeight(tree->rightChild) - getHeight(tree->leftChild);
}

void swap(Node* treeOne, Node* treeTwo)
{
    char* bufferKey = (char*)malloc(strlen(treeOne->element->key) * sizeof(char));
    if (bufferKey == NULL)
    {
        return;
    }

    strcpy(bufferKey, treeOne->element->key);
    strcpy(treeOne->element->key, treeTwo->element->key);
    strcpy(treeTwo->element->key, bufferKey);

    char* bufferValue = (char*)malloc(strlen(treeOne->element->value) * sizeof(char));
    if (bufferValue == NULL)
    {
        return;
    }

    strcpy(bufferValue, treeOne->element->value);
    strcpy(treeOne->element->value, treeTwo->element->value);
    strcpy(treeTwo->element->value, bufferValue);
}

void rightRotate(Node* tree)
{
    swap(tree, tree->leftChild);
    Node* buffer = tree->rightChild;
    tree->rightChild = tree->leftChild;
    tree->leftChild = tree->rightChild->leftChild;
    tree->rightChild->leftChild = tree->rightChild->rightChild;
    tree->rightChild->rightChild = buffer;

    updateHeight(tree->rightChild);
    updateHeight(tree);
}

void leftRotate(Node* tree)
{
    swap(tree, tree->rightChild);
    Node* buffer = tree->leftChild;
    tree->leftChild = tree->rightChild;
    tree->rightChild = tree->leftChild->rightChild;
    tree->leftChild->rightChild = tree->leftChild->leftChild;
    tree->leftChild->leftChild = buffer;

    updateHeight(tree->leftChild);
    updateHeight(tree);
}

void balance(Node* tree)
{
    int balance = getBalance(tree);
    if (balance == -2)
    {
        if (getBalance(tree->leftChild) == 1)
        {
            leftRotate(tree->leftChild);
        }
        rightRotate(tree);
    }
    else if (balance == 2)
    {
        if (getBalance(tree->rightChild) == -1)
        {
            rightRotate(tree->rightChild);
        }
        leftRotate(tree);
    }
}

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

    tree->height = 0;
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
    int compare = strcmp(element->key, (*tree)->element->key);
    if (compare < 0)
    {
        if ((*tree)->leftChild == NULL)
        {
            (*tree)->leftChild = makeNewNode(element);
        }
        else
        {
            addElement(&((*tree)->leftChild), element);
        }
    }
    else if (compare > 0)
    {
        if ((*tree)->rightChild == NULL)
        {
            (*tree)->rightChild = makeNewNode(element);
        }
        else
        {
            addElement(&((*tree)->rightChild), element);
        }
    }
    else if (compare == 0)
    {
        freeElement(tree);
        (*tree)->element = element;
        return;
    }

    updateHeight(*tree);
    balance(*tree);
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

static void updateTree(Node* const tree)
{
    if (tree != NULL)
    {
        updateHeight(tree);
        balance(tree);
    }
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
        updateTree(*tree);
        return;
    }
    if (compare < 0)
    {
        deleteElement(&((*tree)->leftChild), key);
        updateTree(*tree);
        return;
    }

    if ((*tree)->leftChild == NULL && (*tree)->rightChild == NULL)
    {
        freeNode(tree);
        updateTree(*tree);
        return;
    }
    if ((*tree)->rightChild == NULL)
    {
        Node* tmp = *tree;
        *tree = (*tree)->leftChild;
        freeNode(&tmp);
        updateTree(*tree);
        return;
    }
    if ((*tree)->leftChild == NULL)
    {
        Node* tmp = *tree;
        *tree = (*tree)->rightChild;
        freeNode(&tmp);
        updateTree(*tree);
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
            updateTree(*tree);
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
