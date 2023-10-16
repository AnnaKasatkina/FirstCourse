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

void testArray(int *rightTestingArray, int *testingArray)
{
    for (int i = 0; i < 8; ++i)
    {
        assert(rightTestingArray[i] == testingArray[i]);
    }
}

void printing(int *array)
{
    for (int i = 0; i < 8; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void binarySum(int *array1, int *array2, int *rezult)
{
    for (int i = 7; i >= 0; i--)
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

void testBinarySum()
{
    int testingArrayOne[] = {0, 0, 1, 1, 1, 1, 1, 1};
    int testingArrayTwo[] = {0, 0, 0, 1, 1, 1, 1, 1};
    int testingArrayRezult[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int rightTestingArray[] = {0, 1, 0, 1, 1, 1, 1, 0};

    binarySum(testingArrayOne, testingArrayTwo, testingArrayRezult);
    testArray(rightTestingArray, testingArrayRezult);
    printf("Тест Сумма двоичных чисел прошел успешно.\n");
}

void conversionToBinary(int *array, int number)
{
    number = fabs(number);
    for (int i = 7; i >= 1; i--)
    {
        array[i] = number % 2;
        number = number / 2;
    }
}

void testConversionToBinary()
{
    int testingNumber = 63;
    int testingArray[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int rightTestingArray[] = {0, 0, 1, 1, 1, 1, 1, 1};

    conversionToBinary(testingArray, testingNumber);
    testArray(rightTestingArray, testingArray);
    printf("Тест Перевод в двоичную систему прошел успешно.\n");
}

void reverse(int *array)
{
    for (int i = 0; i < 8; i++)
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

void testReverse()
{
    int testingArray[] = {0, 1, 1, 1, 0, 0, 1, 0};
    int rightTestingArray[] = {1, 0, 0, 0, 1, 1, 0, 1};

    reverse(testingArray);
    testArray(rightTestingArray, testingArray);
    printf("Тест Инверсия массива прошел успешно.\n");
}

void twosComplement(int *array, int number)
{
    conversionToBinary(array, number);
    if (number < 0)
    {
        reverse(array);
        int one[] = {0, 0, 0, 0, 0, 0, 0, 1};
        binarySum(array, one, array);
    }
}

void testTwosComplement()
{
    int testingNumber = -3;
    int testingArray[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int rightTestingArray[] = {1, 1, 1, 1, 1, 1, 0, 1};

    twosComplement(testingArray, testingNumber);
    testArray(rightTestingArray, testingArray);
    printf("Тест Дополнительный код прошел успешно.\n");
}

int conversionToDecimal(int *array)
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

    for (int i = 1; i < 8; i++)
    {
        number += array[i] * pow(2, 7 - i);
    }
    return number *= sign;
}

void testConversionToDecimal()
{
    int testingArray[] = {1, 1, 1, 1, 0, 0, 0, 1};
    int rightTestingNumber = -15;

    assert(rightTestingNumber == conversionToDecimal(testingArray));
    printf("Тест Перевод в десятичную систему прошел успешно.\n\n");
}

int main()
{
    system("chcp 65001");

    testBinarySum();
    testConversionToBinary();
    testReverse();
    testTwosComplement();
    testConversionToDecimal();

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
    printing(array1);
    printing(array2);

    printf("Сумма чисел в двоичной системе: \n");
    int rezult[] = {0, 0, 0, 0, 0, 0, 0, 0};
    binarySum(array1, array2, rezult);
    printing(rezult);

    printf("Сумма чисел в десятичной системе: \n");
    int rezultSum = conversionToDecimal(rezult);
    printf("%d", rezultSum);

    return 0;
}