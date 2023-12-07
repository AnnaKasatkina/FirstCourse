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
    List* list = getStringFromFile(nameFile);

    List** hashTable = makeHashTable(list);

    float fillFactor = 0.0f;
    size_t maxLength = 0;
    size_t averageLength = 0;
    countHashTableStatus(hashTable, list->size, &fillFactor, &maxLength, &averageLength);
    bool result1 = fillFactor == fillFactorAnswer;
    bool result2 = maxLength == maxLengthAnswer;
    bool result3 = averageLength == averageLengthAnswer;

    size_t* count = countHashTableElements(hashTable, list);
    bool result4 = compareArrays(count, countAnswer, list->size);

    return result1 && result2 && result3 && result4;
}

static bool testTextColumn(void)
{
    char* nameFile = "Tests/testTextColumn.txt";
    float fillFactorAnswer = 0.444444448;
    size_t maxLengthAnswer = 3;
    size_t averageLengthAnswer = 1;
    size_t countAnswer[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    return testCase(nameFile, fillFactorAnswer, maxLengthAnswer, averageLengthAnswer, countAnswer);
}

static bool testTextLine(void)
{
    char* nameFile = "Tests/testTextLine.txt";
    float fillFactorAnswer = 0.250000000;
    size_t maxLengthAnswer = 5;
    size_t averageLengthAnswer = 1;
    size_t countAnswer[] = { 3, 3, 3, 2, 3, 3, 1, 3, 3, 2, 3, 3 };

    return testCase(nameFile, fillFactorAnswer, maxLengthAnswer, averageLengthAnswer, countAnswer);
}

static bool testOneWord(void)
{
    char* nameFile = "Tests/testOneWord.txt";
    float fillFactorAnswer = 1.000000000;
    size_t maxLengthAnswer = 1;
    size_t averageLengthAnswer = 1;
    size_t countAnswer[] = { 1 };

    return testCase(nameFile, fillFactorAnswer, maxLengthAnswer, averageLengthAnswer, countAnswer);
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
