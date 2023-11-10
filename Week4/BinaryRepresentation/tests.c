#include "BinaryRepresentation.h"
#include "tests.h"

#include <stdio.h>

#define LEN 8

const bool compareArrays(char const* const array1, char const* const array2)
{
    for (size_t i = 0; i < LEN; ++i)
    {
        if (array1[i] != array2[i])
        {
            return false;
        }
    }
    return true;
}

const bool testBinarySum(void)
{
    char testingArrayOne[] = { 0, 0, 1, 1, 1, 1, 1, 1 };
    const char testingArrayTwo[] = { 0, 0, 0, 1, 1, 1, 1, 1 };
    char testingArrayresult[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    const char rightTestingArray[] = { 0, 1, 0, 1, 1, 1, 1, 0 };

    binarySum(testingArrayOne, testingArrayTwo, testingArrayresult, LEN);
    return compareArrays(rightTestingArray, testingArrayresult);
}

const bool testConversionToBinary(void)
{
    const int testingNumber = -3;
    char testingArray[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    const char rightTestingArray[] = { 1, 1, 1, 1, 1, 1, 0, 1 };

    conversionToBinary(testingArray, testingNumber, LEN);
    return compareArrays(rightTestingArray, testingArray);
}

static bool testconversionToDecimal()
{
    char testingArray[] = { 1, 1, 1, 1, 0, 0, 0, 1 };
    int rightNumber = -15;

    int answer = conversionToDecimal(testingArray, LEN);
    return answer == rightNumber;
}

const void printResultTest(const bool result, const char* const nameTest)
{
    if (result)
    {
        printf("Тест %s прошел успешно.\n", nameTest);
    }
    else
    {
        printf("Тест %s завершился с ошибкой.\n", nameTest);
    }
}

bool resultTests(void)
{
    const bool answerOne = testBinarySum();
    const bool answerTwo = testConversionToBinary();
    const bool answerFour = testconversionToDecimal();

    printResultTest(answerOne, "Сумма двоичных чисел");
    printResultTest(answerTwo, "Перевод в двоичную систему");
    printResultTest(answerFour, "Перевод в десятичную систему");
    printf("\n");

    return answerOne && answerTwo && answerFour;
}
