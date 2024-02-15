#include "Test.h"
#include "MergeSort.h"

#include <string.h>

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

static bool testCase(const Criteria criteria, const char* const fileTest, const char* const fileAnswer)
{
    List* listTest = initList();
    if (listTest == NULL)
    {
        return false;
    }

    List* listAnswer = initList();
    if (listAnswer == NULL)
    {
        freeList(listTest);
        return false;
    }

    readFromFile(fileTest, listTest);
    readFromFile(fileAnswer, listAnswer);

    listTest = mergeSort(listTest, criteria);
    if (listTest == NULL)
    {
        freeList(listAnswer);
        freeList(listTest);
        return false;
    }

    bool result = compareLists(listAnswer, listTest);

    freeList(listAnswer);
    freeList(listTest);

    return result;
}

static bool testIdenticalNames(void)
{
    return testCase(byName, "tests/testIdenticalNames.txt", "tests/answerIdenticalNames.txt");
}

static bool testIdenticalNumber(void)
{
    return testCase(byNumber, "tests/testIdenticalNumber.txt", "tests/answerIdenticalNumber.txt");
}

static bool testOneEntry(void)
{
    return testCase(byNumber, "tests/testOneEntry.txt", "tests/answerOneEntry.txt");
}

bool testsResult(void)
{
    const bool answerOne = testIdenticalNames();
    const bool answerTwo = testIdenticalNumber();
    const bool answerThree = testOneEntry();

    printResultTest(answerOne, "Identical Names");
    printResultTest(answerTwo, "Identical Number");
    printResultTest(answerTwo, "One Entry");
    printf("\n");

    return (answerOne && answerTwo && answerThree);
}
