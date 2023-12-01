#include "AVL_Tree.h"

#include <stdlib.h>
#include <string.h>

int height(Node* p)
{
    return p ? p->delta : 0;
}

int bfactor(Node* p)
{
    return height(p->rightChild) - height(p->leftChild);
}

void fixheight(Node* p)
{
    int hl = height(p->leftChild);
    int hr = height(p->rightChild);
    p->delta = (hl > hr ? hl : hr) + 1;
}

Node* rotateright(Node* p) // правый поворот вокруг p
{
    Node* q = p->leftChild;
    p->leftChild = q->rightChild;
    q->rightChild = p;
    fixheight(p);
    fixheight(q);
    return q;
}

Node* rotateleft(Node* q) // левый поворот вокруг q
{
    Node* p = q->rightChild;
    q->rightChild = p->leftChild;
    p->leftChild = q;
    fixheight(q);
    fixheight(p);
    return p;
}

Node* balance(Node* p) // балансировка узла p
{
    fixheight(p);
    if (bfactor(p) == 2)
    {
        if (bfactor(p->rightChild) < 0)
            p->rightChild = rotateright(p->rightChild);
        return rotateleft(p);
    }
    if (bfactor(p) == -2)
    {
        if (bfactor(p->leftChild) > 0)
            p->leftChild = rotateleft(p->leftChild);
        return rotateright(p);
    }
    return p; // балансировка не нужна
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

    //return balance(*tree);
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
