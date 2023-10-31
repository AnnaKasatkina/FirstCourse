#include "List.h"
#include "test.h"
#include "CyclicList.h"


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

static bool testCase(const size_t amount, const size_t gap, int* const answer)
{
    List* list = 0;
    initList(&list);

    fillList(amount, list);
    count(amount, gap, list);

    int* array = listToArray(list, gap);
    freeList(list);

    bool result = compareArrays(array, answer, gap - 1);
    free(array);

    return result;
}

static bool testOne(void)
{
    int answer[] = { 16, 31 };
    return testCase(41, 3, answer);
}

static bool testTwo(void)
{
    int answer[] = { 1, 3, 4, 13, 14, 15, 20, 21 };
    return testCase(30, 9, answer);
}

static bool testThree(void)
{
    int answer[] = { 19 };
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
