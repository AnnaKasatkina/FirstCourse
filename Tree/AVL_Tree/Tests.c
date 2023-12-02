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

static Element* createElement(const char* const value, const char* const key)
{
    Element* element = malloc(sizeof(Element));
    if (element == NULL)
    {
        free(element);
        return NULL;
    }

    element->key = createValue(key, element);
    if (element->key == NULL)
    {
        free(element);
        return NULL;
    }

    element->value = createValue(value, element);
    if (element->value == NULL)
    {
        free(element);
        return NULL;
    }

    return element;
}

static bool treeTraversal(Node* tree, char** array, size_t* index)
{
    if (tree)
    {
        treeTraversal(tree->leftChild, array, index);
        treeTraversal(tree->rightChild, array, index);
        if (strcmp(tree->element->key, array[*index]) != 0)
        {
            return false;
        }
        ++(*index);
    }
    return true;
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

    addElement(&tree, createElement("five", "5"));
    addElement(&tree, createElement("two", "2"));
    addElement(&tree, createElement("one", "1"));
    bool testHeight1 = answerHeight1 == tree->height;

    addElement(&tree, createElement("three", "3"));
    addElement(&tree, createElement("seven", "7"));
    addElement(&tree, createElement("six", "6"));
    bool testHeight2 = answerHeight2 == tree->height;

    bool result1 = testAddElement(tree);
    bool result2 = testFindElement(tree);
    bool result3 = testCheckElement(tree);
    bool result4 = testDeleteElement(tree);
    bool result5 = testHeight1 && testHeight2;

    printResultTest(result1, "Add Element");
    printResultTest(result2, "Find Element");
    printResultTest(result3, "Check Element");
    printResultTest(result4, "Delete Element");
    printResultTest(result5, "Height test");
    printf("\n");

    deleteTree(&tree);

    return result1 && result2 && result3 && result4 && testHeight1 && testHeight2;
}
