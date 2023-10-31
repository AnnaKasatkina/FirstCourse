#include "test.h"
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

static bool compareLists(List* list1, List* list2)
{
    for (size_t i = 0; i < getSize(list1); i++)
    {
        if (strcmp(getAt(list1, i), getAt(list2, i)) != 0)
        {
            return false;
        }
    }
    return true;
}

static bool testCase(Criteria criteria, char* fileTest, char* fileAnswer)
{
    List* listTest = 0;
    initList(&listTest);

    List* listAnswer = 0;
    initList(&listAnswer);

    readFromFile(fileTest, listTest);
    readFromFile(fileAnswer, listAnswer);

    listTest = mergeSort(listTest, criteria);

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

bool resultTests(void)
{
    bool answerOne = testIdenticalNames();
    bool answerTwo = testIdenticalNumber();
    bool answerThree = testOneEntry();

    printResultTest(answerOne, "Identical Names");
    printResultTest(answerTwo, "Identical Number");
    printResultTest(answerTwo, "One Entry");
    printf("\n");

    return (answerOne && answerTwo && answerThree);
}
