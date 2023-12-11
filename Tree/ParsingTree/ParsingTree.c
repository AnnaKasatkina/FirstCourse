#include "ParsingTree.h"

#include <stdlib.h>
#include <string.h>

#define ERROR -1

static int fromCharToInt(const char character)
{
    return (int)character - (int)'0';
}

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

        newNode->value = token;
        newNode->leftChild = buildTree(file);
        if (newNode->leftChild == NULL)
        {
            return NULL;
        }

        newNode->rightChild = buildTree(file);
        if (newNode->rightChild == NULL)
        {
            return NULL;
        }

        if (fscanf(file, " %c", &token) != 1)
        {
            return NULL;
        }
    }
    else
    {
        ungetc(token, file);
        if (fscanf(file, "%c", &newNode->value) != 1)
        {
            return NULL;
        }
    }

    return newNode;
}

static int calculate(ErrorCode* const errorCode, const char character,
    const int numberOne, const int numberTwo)
{
    *errorCode = ok;
    switch (character)
    {
    case '+':
        return numberOne + numberTwo;
    case '/':
        if (numberTwo == 0)
        {
            *errorCode = divisionByZero;
            return ERROR;
        }
        return numberOne / numberTwo;
    case '*':
        return numberOne * numberTwo;
    case '-':
        return numberOne - numberTwo;
    default:
        *errorCode = wrongOperation;
        return ERROR;
    }
}

char calculateResult(const Node* const tree, ErrorCode* const errorCode)
{
    *errorCode = ok;
    if (tree == NULL)
    {
        *errorCode = treeIsEmpty;
        return ERROR;
    }
    if (tree->leftChild == NULL)
    {
        return tree->value;
    }

    char leftValue = calculateResult(tree->leftChild, errorCode);
    if (*errorCode != ok)
    {
        return ERROR;
    }

    char rightValue = calculateResult(tree->rightChild, errorCode);
    if (*errorCode != ok)
    {
        return ERROR;
    }

    char result = calculate(errorCode, tree->value, 
        fromCharToInt(leftValue), fromCharToInt(rightValue)) + (int)'0';
    if (*errorCode != ok)
    {
        return ERROR;
    }

    return result;
}

void printTree(const Node* const tree, ErrorCode* const errorCode)
{
    if (tree == NULL)
    {
        *errorCode = treeIsEmpty;
        return;
    }
    if (tree->leftChild == NULL)
    {
        int number = (int)tree->value - (int)'0';
        printf("%d ", number);
    }
    else
    {
        printf("(%c ", tree->value);

        printTree(tree->leftChild, errorCode);
        if (*errorCode != ok)
        {
            return;
        }

        printTree(tree->rightChild, errorCode);
        if (*errorCode != ok)
        {
            return;
        }

        printf(") ");
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
