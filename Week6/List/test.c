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

static bool testIdenticalNames()
{
    List* listTest = 0;
    initList(&listTest);

    List* listAnswer = 0;
    initList(&listAnswer);

    readFromFile("tests/testIdenticalNames.txt", listTest);
    readFromFile("tests/answerIdenticalNames.txt", listAnswer);

    listTest = mergeSort(listTest, 0);

    return compareLists(listAnswer, listTest);
}

static bool testIdenticalNumber()
{
    List* listTest = 0;
    initList(&listTest);

    List* listAnswer = 0;
    initList(&listAnswer);

    readFromFile("tests/testIdenticalNumber.txt", listTest);
    readFromFile("tests/answerIdenticalNumber.txt", listAnswer);

    listTest = mergeSort(listTest, 1);

    return compareLists(listAnswer, listTest);
}

static bool testOneEntry()
{
    List* listTest = 0;
    initList(&listTest);

    List* listAnswer = 0;
    initList(&listAnswer);

    readFromFile("tests/testOneEntry.txt", listTest);
    readFromFile("tests/answerOneEntry.txt", listAnswer);

    listTest = mergeSort(listTest, 1);

    return compareLists(listAnswer, listTest);
}

bool resultTests()
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
