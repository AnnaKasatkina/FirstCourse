#include "Tests.h"

#include <stdlib.h>
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

static bool testCase(int* answer, int priorityOne, int priorityTwo, int priorityThree)
{
    PriorityQueue* queue = initializeQueue();
    if (queue == NULL)
    {
        return false;
    }

    ErrorCode errorCode = ok;
    enqueue(queue, 10, priorityOne, &errorCode);
    if (errorCode != ok)
    {
        freeQueue(queue);
        return false;
    }
    enqueue(queue, 20, priorityTwo, &errorCode);
    if (errorCode != ok)
    {
        freeQueue(queue);
        return false;
    }
    enqueue(queue, 30, priorityThree, &errorCode);
    if (errorCode != ok)
    {
        freeQueue(queue);
        return false;
    }

    size_t length = 3;
    for (size_t i = 0; i < length; i++)
    {
        if (dequeue(queue, &errorCode) != answer[i])
        {
            freeQueue(queue);
            return false;
        }
    }

    freeQueue(queue);
    return true;
}

static bool testSamePriorities(void)
{
    int answer[] = {10, 20, 30};

    return testCase(answer, 1, 1, 1);
}

static bool testIncreasingPriorities(void)
{
    int answer[] = { 30, 20, 10 };

    return testCase(answer, 1, 2, 3);
}

static bool testDecreasingPriorities(void)
{
    int answer[] = { 10, 20, 30 };

    return testCase(answer, 3, 2, 1);
}

bool testResult(void)
{
    bool result1 = testSamePriorities();
    bool result2 = testIncreasingPriorities();
    bool result3 = testDecreasingPriorities();

    printResultTest(result1, "Same Priorities");
    printResultTest(result2, "Increasing Priorities");
    printResultTest(result3, "Decreasing Priorities");
    printf("\n");

    return result1 && result2 && result3;
}