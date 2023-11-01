/*
Ввести два числа, перевести в двоичное представление
в дополнительном коде и напечатать,
сложить в столбик в двоичном представлении, вывести сумму,
перевести в десятичное, вывести сумму в десятичном виде.
Все сообщения писать по-русски.
*/

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include <locale.h>

#define LEN 8
#define ERROR -1

bool compareArrays(int const *const array1, int const *const array2)
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

void printArray(int const *const array)
{
    for (size_t i = 0; i < LEN; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

void binarySum(int *const array1, int *const array2, int *const rezult)
{
    for (size_t i = 7; i >= 0; --i)
    {
        if (array1[i] + array2[i] <= 1)
        {
            rezult[i] = array1[i] + array2[i];
        }
        else
        {
            array1[i - 1] += 1;

            if ((array1[i] + array2[i]) % 2 == 1)
            {
                rezult[i] = 1;
            }
            else
            {
                rezult[i] = 0;
            }
        }
    }
}

bool testBinarySum(void)
{
    int testingArrayOne[] = {0, 0, 1, 1, 1, 1, 1, 1};
    int testingArrayTwo[] = {0, 0, 0, 1, 1, 1, 1, 1};
    int testingArrayRezult[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int rightTestingArray[] = {0, 1, 0, 1, 1, 1, 1, 0};

    binarySum(testingArrayOne, testingArrayTwo, testingArrayRezult);
    return compareArrays(rightTestingArray, testingArrayRezult);
}

void conversionToBinary(int *const array, int number)
{
    number = fabs(number);
    for (size_t i = 7; i >= 1; --i)
    {
        array[i] = number % 2;
        number = number / 2;
    }
}

bool testConversionToBinary(void)
{
    int testingNumber = 63;
    int testingArray[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int rightTestingArray[] = {0, 0, 1, 1, 1, 1, 1, 1};

    conversionToBinary(testingArray, testingNumber);
    return compareArrays(rightTestingArray, testingArray);
}

void reverse(int *const array)
{
    for (size_t i = 0; i < LEN; ++i)
    {
        if (array[i] == 0)
        {
            array[i] = 1;
        }
        else
        {
            array[i] = 0;
        }
    }
}

bool testReverse(void)
{
    int testingArray[] = {0, 1, 1, 1, 0, 0, 1, 0};
    int rightTestingArray[] = {1, 0, 0, 0, 1, 1, 0, 1};

    reverse(testingArray);
    return compareArrays(rightTestingArray, testingArray);
}

void twosComplement(int *const array, int number)
{
    conversionToBinary(array, number);
    if (number < 0)
    {
        reverse(array);
        int one[] = {0, 0, 0, 0, 0, 0, 0, 1};
        binarySum(array, one, array);
    }
}

bool testTwosComplement(void)
{
    int testingNumber = -3;
    int testingArray[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int rightTestingArray[] = {1, 1, 1, 1, 1, 1, 0, 1};

    twosComplement(testingArray, testingNumber);
    return compareArrays(rightTestingArray, testingArray);
}

int conversionToDecimal(int *const array)
{
    int number = 0;
    int sign = 1;
    if (array[0] == 1)
    {
        sign = -1;
        int minusOne[] = {1, 1, 1, 1, 1, 1, 1, 1};
        binarySum(array, minusOne, array);
        reverse(array);
    }

    for (size_t i = 1; i < LEN; ++i)
    {
        number += array[i] * pow(2, 7 - i);
    }
    return number *= sign;
}

bool testConversionToDecimal(void)
{
    int testingArray[] = {1, 1, 1, 1, 0, 0, 0, 1};
    int rightTestingNumber = -15;

    return rightTestingNumber == conversionToDecimal(testingArray);
}

void printResultTest(const bool rezult, const char *const nameTest)
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
    const bool answerThree = testReverse();
    const bool answerFour = testTwosComplement();
    const bool answerFive = testConversionToDecimal();

    printResultTest(answerOne, "Сумма двоичных чисел");
    printResultTest(answerTwo, "Перевод в двоичную систему");
    printResultTest(answerThree, "Инверсия массива");
    printResultTest(answerFour, "Дополнительный код");
    printResultTest(answerFive, "Перевод в десятичную систему");
    printf("\n");

    return (answerOne && answerTwo && answerThree && answerFour && answerFive);
}

int main(void)
{
    setlocale(LC_ALL, "Rus");

    if (!resultTests())
    {
        printf("Error!");
        return ERROR;
    }

    printf("Введите 2 числа, которые в сумме не превышают 127: ");

    int num1 = 0;
    int num2 = 0;

    if (scanf("%d %d", &num1, &num2) != 2)
    {
        printf("Ошибка ввода");
        return 1;
    }

    if (num1 + num2 > 127)
    {
        printf("Числа слишком большие");
        return 1;
    }

    int array1[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int array2[] = {0, 0, 0, 0, 0, 0, 0, 0};

    printf("Числа в двоичном представлении в дополнительном коде: \n");
    twosComplement(array1, num1);
    twosComplement(array2, num2);
    printArray(array1);
    printArray(array2);

    printf("Сумма чисел в двоичной системе: \n");
    int rezult[] = {0, 0, 0, 0, 0, 0, 0, 0};
    binarySum(array1, array2, rezult);
    printArray(rezult);

    printf("Сумма чисел в десятичной системе: \n");
    int rezultSum = conversionToDecimal(rezult);
    printf("%d", rezultSum);

    return 0;
}