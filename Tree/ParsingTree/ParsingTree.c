#include "ParsingTree.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

static void sizeOfTree(Node* tree, size_t* size)
{
    if (tree)
    {
        sizeOfTree(tree->leftChild, size);
        sizeOfTree(tree->rightChild, size);
        ++(*size);
    }
}

static Node* makeNewNode(const char value)
{
    Node* tree = (Node*)malloc(sizeof(Node));
    if (tree == NULL)
    {
        return NULL;
    }

    tree->value = value;
    tree->leftChild = (Node*)calloc(1, sizeof(Node));
    tree->rightChild = (Node*)calloc(1, sizeof(Node));

    return tree;
}

Node* buildTree(char** string, Node** tree)
{
    for (const char** character = string; **(character) != ')'; (*character)++)
    {
        if (**character == '(')
        {
            ++(*character);
            *tree = makeNewNode(**character);
            (*tree)->leftChild = buildTree(character, &((*tree)->leftChild));
            (*tree)->rightChild = buildTree(character, &((*tree)->rightChild));
            ++(*character);
            return *tree;
        }

        if (isdigit((*character)[0]))
        {
            (*tree)->value = (*character)[0];
            ++(*character);
            return *tree;
        }
    }
    return *tree;
}

static void treeTraversal(Node* tree, char* string, size_t* index)
{
    if (tree)
    {
        while (string[*index] != '\0')
        {
            (*index)++;
        }
        string[*index] = tree->value;
        string[*index + 1] = '\0';
        treeTraversal(tree->leftChild, string, index);
        treeTraversal(tree->rightChild, string, index);
    }
}

char* getStringFromTree(Node* tree)
{
    size_t size = 0;
    size_t index = 0;
    sizeOfTree(tree, &size);

    char* string = (char*)calloc(size + 1, sizeof(char));
    treeTraversal(tree, string, &index);

    return string;
}

int countResult(char* string)
{
    return 0;
}
