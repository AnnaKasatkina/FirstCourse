#include "Tests.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void printResultTest(const bool result, const char* const nameTest)
{
    if (result)
    {
        printf("Test %s is OK\n", nameTest);
    }
    else
    {
        printf("Test %s failed with an error\n", nameTest);
    }
}

static char* createValue(const char* const nameValue, Element* element)
{
    char* string = (char*)malloc(sizeof(nameValue));
    if (string == NULL)
    {
        free(element);
        return NULL;
    }

    strcpy(string, nameValue);

    return string;
}

static bool testAddElement(Node* tree)
{
    char* array[] = { "1", "3", "2", "6", "7", "5" };
    size_t index[1] = { 0 };

    return treeTraversal(tree, array, index);
}

static bool testFindElement(Node* tree)
{
    char* trueValue = "six";
    char* trueKey = "6";
    bool result1 = (!strcmp(trueValue, findElement(tree, trueKey)));

    char* falseKey = "15";
    bool result2 = (NULL == findElement(tree, falseKey));

    return result1 && result2;
}

static bool testCheckElement(Node* tree)
{
    char* trueKey = "1";
    bool result1 = checkElement(tree, trueKey);

    char* falseKey = "15";
    bool result2 = !checkElement(tree, falseKey);

    return result1 && result2;
}

static bool testDeleteElement(Node* tree)
{
    char* keyOne = "7";
    deleteElement(&tree, keyOne);
    char* arrayOne[] = { "1", "3", "2", "6", "5" };
    size_t index[1] = { 0 };
    bool result1 = treeTraversal(tree, arrayOne, index);

    char* keyTwo = "5";
    deleteElement(&tree, keyTwo);
    char* arrayTwo[] = { "1", "3", "2", "6" };
    index[0] = 0;
    bool result2 = treeTraversal(tree, arrayTwo, index);

    return result1 && result2;
}

bool testResult(void)
{
    Node* tree = NULL;
    int answerHeight1 = 1;
    int answerHeight2 = 2;

    addElement(&tree, _strdup("five"), _strdup("5"));
    addElement(&tree, _strdup("two"), _strdup("2"));
    addElement(&tree, _strdup("one"), _strdup("1"));
    bool testHeight1 = answerHeight1 == tree->height;

    addElement(&tree, _strdup("three"), _strdup("3"));
    addElement(&tree, _strdup("seven"), _strdup("7"));
    addElement(&tree, _strdup("six"), _strdup("6"));
    bool testHeight2 = answerHeight2 == tree->height;

    bool result1 = testAddElement(tree);
    bool result2 = testFindElement(tree);
    bool result3 = testCheckElement(tree);
    bool result4 = testDeleteElement(tree);
    bool result5 = testHeight1 && testHeight2;

    printResultTest(result1, "Add Element");
    printResultTest(result2, "Find Element");
    printResultTest(result3, "Check Element");
    //printResultTest(result4, "Delete Element");
    printResultTest(result5, "Height test");
    printf("\n");

    deleteTree(&tree);

    return result1 && result2 && result3 && result4 && testHeight1 && testHeight2;
}
