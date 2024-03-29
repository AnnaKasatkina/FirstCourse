#include "Tests.h"
#include "ParsingTree.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

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

static int readValue(const char* const string, size_t* const index)
{
    int value = 0;
    if (sscanf(&string[*index], "%d", &value) != 1)
    {
        return false;
    }
    while (isdigit(string[*index]) || string[*index] == '-')
    {
        (*index)++;
    }
    return value;
}

static bool treeCompare(const Node* const tree, const char* const string, size_t* const index)
{
    if (tree == NULL)
    {
        return false;
    }
    if (tree->leftChild == NULL)
    {
        int nodeValue = readValue(string, index);
        if (nodeValue != tree->value)
        {
            return false;
        }
        return true;
    }
    if (string[(*index)++] != '(')
    {
        return false;
    }

    if (string[(*index)++] != tree->value)
    {
        return false;
    }

    ++(*index);
    if (!treeCompare(tree->leftChild, string, index))
    {
        return false;
    }

    ++(*index);
    if (!treeCompare(tree->rightChild, string, index))
    {
        return false;
    }

    if (string[(*index)++] != ')')
    {
        return false;

    }
    return true;
}

static bool testCase(const char* const nameFile, const char* const rightTree,
    const int answer, const char* const nameTest)
{
    FILE* file = fopen(nameFile, "r");
    if (file == NULL)
    {
        printf(STRING_ERROR);
        return false;
    }

    Node* tree = buildTree(file);
    if (buildTree == NULL)
    {
        fclose(file);
        return false;
    }
    fclose(file);

    size_t index = 0;
    bool answerOne = treeCompare(tree, rightTree, &index);

    ErrorCode errorCode = ok;
    int result = calculateResult(tree, &errorCode);
    if (errorCode != ok)
    {
        deleteTree(&tree);
        printf(STRING_ERROR);
        return false;
    }
    answerOne = answerOne && (result == answer);

    deleteTree(&tree);

    printResultTest(answerOne, nameTest);
    return answerOne;
}

static bool testOne()
{
    const char* const name = "TestFiles/TestOne.txt";
    const char* const rightTree = "(* (+ 1 12) 2)";
    const int answer = 26;

    return testCase(name, rightTree, answer, "Test One");
}

static bool testTwo()
{
    const char* const name = "TestFiles/TestTwo.txt";
    const char* const rightTree = "(/ 80 (* 2 (- 5 1)))";
    const int answer = 10;

    return testCase(name, rightTree, answer, "Test Two");
}

static bool testThree()
{
    const char* const name = "TestFiles/TestThree.txt";
    const char* const rightTree = "(+ (* 2 14) (/ 8 2))";
    const int answer = 32;

    return testCase(name, rightTree, answer, "Test Three");
}

static bool testFour()
{
    const char* const name = "TestFiles/TestFour.txt";
    const char* const rightTree = "(* (+ 5 2) (/ (+ 6 2) 4))";
    const int answer = 14;

    return testCase(name, rightTree, answer, "Test Four");
}

bool testResult(void)
{
    bool result1 = testOne();
    bool result2 = testTwo();
    bool result3 = testThree();
    bool result4 = testFour();
    printf("\n");

    return result1 && result2 && result3 && result4;
}
