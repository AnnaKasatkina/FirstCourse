#include "Tests.h"
#include "BinaryTree.h"

#include <stdlib.h>
#include <stdio.h>

bool testsCase(int* array, size_t length)
{
    Node* tree = makeTreeFromArray(array, length);
    if (tree == NULL)
    {
        return false;
    }

    size_t index = 0;
    orderTree(tree, array, &index);
    deleteTree(&tree);
    return true;
}

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

static bool compareArrays(const int* const array1, const int* const array2, const size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        if (array1[i] != array2[i])
        {
            return false;
        }
    }
    return true;
}

static bool testIncreasingArray(void)
{
    const size_t length = 5;
    int array1[] = { 0, 1, 2, 3, 4 };
    int array2[] = { 0, 1, 2, 3, 4 };

    if (testsCase(array1, length))
    {
        return compareArrays(array1, array2, length);
    }
    return false;
}

static bool testDecreasingArray(void)
{
    const size_t length = 10;
    int array1[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int array2[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    if (testsCase(array1, length))
    {
        return compareArrays(array1, array2, length);
    }
    return false;
}

static bool testIdenticalCharacters(void)
{
    const size_t length = 15;
    int array1[] = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 };
    int array2[] = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 };

    if (testsCase(array1, length))
    {
        return compareArrays(array1, array2, length);
    }
    return false;
}

bool testsResult(void)
{
    const bool answerOne = testIncreasingArray();
    const bool answerTwo = testDecreasingArray();
    const bool answerThree = testIdenticalCharacters();

    printResultTest(answerOne, "Increasing Array");
    printResultTest(answerTwo, "Decreasing Array");
    printResultTest(answerTwo, "Identical Characters");
    printf("\n");

    return answerOne && answerTwo && answerThree;
}