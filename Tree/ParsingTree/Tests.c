#include "Tests.h"
#include "ParsingTree.h"
#include "Utility.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ERROR -1

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

static bool treeCompare(const Node* const tree, const char* const string, size_t* const index)
{
    if (tree)
    {
        treeCompare(tree->leftChild, string, index);
        treeCompare(tree->rightChild, string, index);
        if (string[*index] != tree->value)
        {
            return false;
        }
        ++(*index);
    }
    return true;
}

static bool testCase(const char* const name, const char* const rightStringFromTree, const char* const rightStringFromFile, const int answer)
{
    Node* tree = NULL;
    ErrorCode errorCode = ok;

    char* stringFromFile = getStringFromFile(name);
    bool answerOne = strcmp(stringFromFile, rightStringFromFile) == 0;

    buildTree(&stringFromFile, &tree);
    size_t index[1] = { 0 };
    bool answerTwo = treeCompare(tree, rightStringFromTree, index);

    char* stringFromTree = getStringFromTree(tree);
    bool answerThree = strcmp(stringFromTree, rightStringFromTree) == 0;

    int result = calculateResult(stringFromTree, &errorCode);
    bool answerFour = (result == answer);

    deleteTree(&tree);

    return answerOne && answerTwo && answerThree && answerFour;
}

static bool testOne()
{
    const char* const name = "TestFiles/TestOne.txt";
    const char* const rightStringFromTree = "*+112";
    const char* const rightStringFromFile = "(*(+11)2)";
    const int answer = 4;

    return testCase(name, rightStringFromTree, rightStringFromFile, answer);
}

static bool testTwo()
{
    const char* const name = "TestFiles/TestTwo.txt";
    const char* const rightStringFromTree = "/8*2-51";
    const char* const rightStringFromFile = "(/8(*2(-51)))";
    const int answer = 1;

    return testCase(name, rightStringFromTree, rightStringFromFile, answer);
}

static bool testThree()
{
    const char* const name = "TestFiles/TestThree.txt";
    const char* const rightStringFromTree = "+*24/82";
    const char* const rightStringFromFile = "(+(*24)(/82))";
    const int answer = 12;

    return testCase(name, rightStringFromTree, rightStringFromFile, answer);
}

static bool testFour()
{
    const char* const name = "TestFiles/TestFour.txt";
    const char* const rightStringFromTree = "*+52/+624";
    const char* const rightStringFromFile = "(*(+52)(/(+62)4))";
    const int answer = 14;

    return testCase(name, rightStringFromTree, rightStringFromFile, answer);
}

bool testResult(void)
{
    bool result1 = testOne();
    bool result2 = testTwo();
    bool result3 = testThree();
    bool result4 = testFour();

    printResultTest(result1, "Test One");
    printResultTest(result2, "Test Two");
    printResultTest(result3, "Test Three");
    printResultTest(result4, "Test Four");
    printf("\n");

    return result1 && result2 && result3 && result4;
}
