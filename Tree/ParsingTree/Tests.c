#include "Tests.h"
#include "ParsingTree.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ERROR -1
#define STRING_ERROR "Error!"

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
        if (tree->value)
        {
            if (((int)string[(*index)++] - 48) != tree->value)
            {
                return false;
            }
        }
        else
        {
            if (string[(*index)++] != '(')
            {
                return false;
            }

            if (string[(*index)++] != tree->operation)
            {
                return false;
            }

            ++(*index);
            treeCompare(tree->leftChild, string, index);

            ++(*index);
            treeCompare(tree->rightChild, string, index);

            if (string[(*index)++] != ')')
            {
                return false;
            }
        }
    }
    return true;
}

static bool testCase(const char* const nameFile, const char* const rightTree, const int answer)
{
    FILE* file = fopen(nameFile, "r");
    if (file == NULL)
    {
        printf(STRING_ERROR);
        return false;
    }

    Node* tree = buildTree(file);
    size_t index = 0;
    bool answerOne = treeCompare(tree, rightTree, &index);

    ErrorCode errorCode = ok;
    int result = calculateResult(tree, &errorCode);
    if (errorCode != ok)
    {
        printf(STRING_ERROR);
        return false;
    }
    bool answerTwo = (result == answer);

    deleteTree(&tree);
    fclose(file);
    return answerOne && answerTwo;
}

static bool testOne()
{
    const char* const name = "TestFiles/TestOne.txt";
    const char* const rightTree = "(* (+ 1 1) 2)";
    const int answer = 4;

    return testCase(name, rightTree, answer);
}

static bool testTwo()
{
    const char* const name = "TestFiles/TestTwo.txt";
    const char* const rightTree = "(/ 8 (* 2 (- 5 1)))";
    const int answer = 1;

    return testCase(name, rightTree, answer);
}

static bool testThree()
{
    const char* const name = "TestFiles/TestThree.txt";
    const char* const rightTree = "(+ (* 2 4) (/ 8 2))";
    const int answer = 12;

    return testCase(name, rightTree, answer);
}

static bool testFour()
{
    const char* const name = "TestFiles/TestFour.txt";
    const char* const rightTree = "(* (+ 5 2) (/ (+ 6 2) 4))";
    const int answer = 14;

    return testCase(name, rightTree, answer);
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
