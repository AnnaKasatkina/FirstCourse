#include "List.h"
#include "test.h"
#include "CyclicList.h"

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

static bool compareArrays(int const* const array1, int const* const array2, const size_t length)
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

static List* arrayToList(const int* const array, const size_t length)
{
    List* answer = 0;
    initList(&answer);

    for (size_t i = 0; i < length; ++i)
    {
        pushBack(answer, array[i]);
    }

    return answer;
}

static bool testCase(const size_t amount, const size_t gap, List* const answer)
{
    List* list = 0;
    initList(&list);

    fillList(amount, list);
    count(amount, gap, list);

    bool result = compareLists(list, answer);
    freeList(list);

    return result;
}

static bool testOne(void)
{
    int data[] = { 16, 31 };
    List* answer = arrayToList(data, 2);
    return testCase(41, 3, answer);
}

static bool testTwo(void)
{
    int data[] = { 1, 3, 4, 13, 14, 15, 20, 21 };
    List* answer = arrayToList(data, 8);
    return testCase(30, 9, answer);
}

static bool testThree(void)
{
    int data[] = { 19 };
    List* answer = arrayToList(data, 1);
    return testCase(41, 2, answer);
}

bool resultTests(void)
{
    const bool answerOne = testOne();
    const bool answerTwo = testTwo();
    const bool answerThree = testThree();

    printResultTest(answerOne, "Josephus problem");
    printResultTest(answerTwo, "Whith another exaple");
    printResultTest(answerTwo, "Every second one dies");
    printf("\n");

    return (answerOne && answerTwo && answerThree);
}
