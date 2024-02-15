#include "Tests.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void printResultTest(const bool rezult, const char* const nameTest)
{
    if (rezult)
    {
        printf("Test %s is OK\n", nameTest);
    }
    else
    {
        printf("Test %s failed with an error\n", nameTest);
    }
}

static Element* createElement(const char* const value, const int key)
{
    Element* element = malloc(sizeof(Element));
    if (element == NULL)
    {
        free(element);
        return NULL;
    }

    element->key = key;

    char* string = (char*)malloc(sizeof(value));
    if (string == NULL)
    {
        free(element);
        return NULL;
    }
    
    if (strcpy(string, value) == NULL)
    {
        return NULL;
    }

    element->value = string;

    return element;
}

static bool treeTraversal(Node* tree, int* array, size_t* index)
{
    if (tree)
    {
        treeTraversal(tree->leftChild, array, index);
        treeTraversal(tree->rightChild, array, index);
        if (array[*index] != tree->element->key)
        {
            return false;
        }
        ++(*index);
    }
    return true;
}

static bool testAddElement(Node* tree)
{
    int array[] = { 1, 3, 2, 6, 7, 5 };
    size_t index[1] = { 0 };

    return treeTraversal(tree, array, index);
}

static bool testFindElement(Node* tree)
{
    char* trueValue = "six";
    const int trueKey = 6;
    bool result1 = (!strcmp(trueValue, findElement(tree, trueKey)));

    const int falseKey = 15;
    bool result2 = (NULL == findElement(tree, falseKey));

    return result1 && result2;
}

static bool testCheckElement(Node* tree)
{
    const int trueKey = 1;
    bool result1 = checkElement(tree, trueKey);

    const int falseKey = 15;
    bool result2 = !checkElement(tree, falseKey);

    return result1 && result2;
}

static bool testDeleteElement(Node* tree)
{
    const int keyOne = 7;
    deleteElement(&tree, keyOne);
    int arrayOne[] = { 1, 3, 2, 6, 5 };
    size_t index[1] = { 0 };
    bool result1 = treeTraversal(tree, arrayOne, index);

    const int keyTwo = 5;
    deleteElement(&tree, keyTwo);
    int arrayTwo[] = { 1, 3, 2, 6 };
    index[0] = 0;
    bool result2 = treeTraversal(tree, arrayTwo, index);

    return result1 && result2;
}

bool testResult(void)
{
    Node* tree = NULL;

    addElement(&tree, createElement("five", 5));
    addElement(&tree, createElement("two", 2));
    addElement(&tree, createElement("one", 1));
    addElement(&tree, createElement("three", 3));
    addElement(&tree, createElement("seven", 7));
    addElement(&tree, createElement("six", 6));

    bool result1 = testAddElement(tree);
    bool result2 = testFindElement(tree);
    bool result3 = testCheckElement(tree);
    bool result4 = testDeleteElement(tree);

    printResultTest(result1, "Add Element");
    printResultTest(result2, "Find Element");
    printResultTest(result3, "Check Element");
    printResultTest(result4, "Delete Element");
    printf("\n");

    deleteTree(&tree);

    return result1 && result2 && result3 && result4;
}
