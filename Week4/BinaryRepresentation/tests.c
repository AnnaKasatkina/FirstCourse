#include "BinaryRepresentation.h"
#include "tests.h"

#include <stdio.h>

#define LEN 8

const bool compareArrays(int const* const array1, int const* const array2)
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
    int testingArrayOne[] = { 0, 0, 1, 1, 1, 1, 1, 1 };
    const int testingArrayTwo[] = { 0, 0, 0, 1, 1, 1, 1, 1 };
    int testingArrayRezult[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    const int rightTestingArray[] = { 0, 1, 0, 1, 1, 1, 1, 0 };

    binarySum(testingArrayOne, testingArrayTwo, testingArrayRezult, LEN);
    return compareArrays(rightTestingArray, testingArrayRezult);
}

const bool testConversionToBinary(void)
{
    const int testingNumber = -3;
    int testingArray[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    const int rightTestingArray[] = { 1, 1, 1, 1, 1, 1, 0, 1 };

    conversionToBinary(testingArray, testingNumber, LEN);
    return compareArrays(rightTestingArray, testingArray);
}

static bool testconversionToDecimal()
{
    int testingArray[] = { 1, 1, 1, 1, 0, 0, 0, 1 };
    int rightNumber = -15;

    int answer = conversionToDecimal(testingArray, LEN);
    return answer == rightNumber;
}

const void printResultTest(const bool rezult, const char* const nameTest)
{
    if (rezult)
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
