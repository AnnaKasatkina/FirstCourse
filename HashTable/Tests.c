#include "Tests.h"
#include "HashTable.h"
#include "Utility.h"

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

static bool compareArrays(const size_t* const array1, const size_t* const array2, const size_t length)
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

static bool testCase(const char* const nameFile, const float fillFactorAnswer,
    const size_t maxLengthAnswer, const size_t averageLengthAnswer, const size_t* const countAnswer)
{
    return true;
}

static bool testTextColumn(void)
{
    char* nameFile = "Tests/testTextColumn.txt";

    return true;
}

static bool testTextLine(void)
{
    char* nameFile = "Tests/testTextLine.txt";

    return true;
}

static bool testOneWord(void)
{
    char* nameFile = "Tests/testOneWord.txt";

    return true;
}

bool testResult(void)
{
    bool result1 = testTextColumn();
    bool result2 = testTextLine();
    bool result3 = testOneWord();

    printResultTest(result1, "Text Column");
    printResultTest(result2, "Text Line");
    printResultTest(result3, "One Word");
    printf("\n");

    return result1 && result2 && result3;
}
