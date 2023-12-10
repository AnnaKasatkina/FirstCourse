#include "List.h"
#include "Tests.h"
#include "CyclicList.h"

#include <stdio.h>
#include <stdlib.h>

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

static bool testCase(const size_t amount, const size_t gap, const size_t answer)
{
    List* list = (List*)calloc(1, sizeof(List));
    if (list == NULL)
    {
        return false;
    }

    ErrorCode errorCode = ok;
    fillList(amount, list, &errorCode);
    if (errorCode != ok)
    {
        freeList(list);
        return false;
    }

    size_t safePleace = kill(gap, list);
    bool result = safePleace == answer;
    freeList(list);

    return result;
}

static bool testOne(void)
{
    return testCase(41, 3, 31);
}

static bool testTwo(void)
{
    return testCase(30, 9, 21);
}

static bool testThree(void)
{
    return testCase(41, 2, 19);
}

bool resultTests(void)
{
    const bool answerOne = testOne();
    const bool answerTwo = testTwo();
    const bool answerThree = testThree();

    printResultTest(answerOne, "Josephus problem");
    printResultTest(answerTwo, "Whith another exaple");
    printResultTest(answerThree, "Every second one dies");
    printf("\n");

    return answerOne && answerTwo && answerThree;
}
