#include "ParsingTree.h"

#include <stdlib.h>
#include <string.h>

#define ERROR -1

Node* buildTree(FILE* file) 
{
    char token = ' ';
    if (fscanf(file, " %c", &token) != 1)
    {
        return NULL;
    }

    Node* newNode = (Node*)calloc(1, sizeof(Node));
    if (newNode == NULL)
    {
        return NULL;
    }

    if (token == '(') 
    {
        if (fscanf(file, " %c", &token) != 1)
        {
            return NULL;
        }

        newNode->operation = token;
        newNode->leftChild = buildTree(file);
        newNode->rightChild = buildTree(file);

        if (fscanf(file, " %c", &token) != 1)
        {
            return NULL;
        }
    }
    else 
    {
        ungetc(token, file);
        if (fscanf(file, "%d", &newNode->value) != 1)
        {
            return NULL;
        }
    }

    return newNode;
}

static int count(ErrorCode* const errorCode, const char character, 
    const int numberOne, const int numberTwo)
{
    switch (character)
    {
    case '+':
        return numberOne + numberTwo;
    case '/':
        return numberOne / numberTwo;
    case '*':
        return numberOne * numberTwo;
    case '-':
        return numberOne - numberTwo;
    default:
        *errorCode = error;
        return ERROR;
    }
}

int calculateResult(const Node* const tree, ErrorCode* const errorCode)
{
    if (tree) 
    {
        if (tree->value) 
        {
            return tree->value;
        }
        else 
        {
            int leftValue = calculateResult(tree->leftChild, errorCode);
            int rightValue = calculateResult(tree->rightChild, errorCode);

            return count(errorCode, tree->operation, leftValue, rightValue);
            if (*errorCode != ok)
            {
                return ERROR;
            }
        }
    }
    return 0;
}

void printTree(const Node* const tree)
{
    if (tree) 
    {
        if (tree->value) 
        {
            printf("%d ", tree->value);
        }
        else 
        {
            printf("(%c ", tree->operation);
            printTree(tree->leftChild);
            printTree(tree->rightChild);
            printf(") ");
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
    free(*tree);
    *tree = NULL;
}
