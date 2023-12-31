﻿#include "Tests.h"
#include "MostCommonElement.h"

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

static bool oneElement(void)
{
    const size_t length = 1;
    int array[] = { 52 };
    const answer = 52;

    return answer == findTheMostCommon(array, length);
}

static bool identicalElement(void)
{
    const size_t length = 5;
    int array[] = { 52, 52, 52, 52, 52 };
    const answer = 52;

    return answer == findTheMostCommon(array, length);
}

static bool sameАrequency(void)
{
    const size_t length = 5;
    int array[] = { 52, 45, 1, 1, 45 };
    const answer = 45;

    return answer == findTheMostCommon(array, length);
}

bool resultTests(void)
{
    const bool answerOne = oneElement();
    const bool answerTwo = identicalElement();
    const bool answerThree = sameАrequency();

    printResultTest(answerOne, "One Element");
    printResultTest(answerTwo, "Identical Element");
    printResultTest(answerThree, "Same Arequency");
    printf("\n");

    return answerOne && answerTwo && answerThree;
}
