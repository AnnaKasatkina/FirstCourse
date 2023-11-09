#include "BinaryRepresentation.h"
#include "tests.h"

#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

#define ERROR -1

void printArray(int const* const array, size_t length)
{
    for (size_t i = 0; i < length; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main(void)
{
    setlocale(LC_ALL, "Rus");

    if (!resultTests())
    {
        printf("Error!");
        return ERROR;
    }

    printf("Введите 2 числа: ");

    int num1 = 0;
    int num2 = 0;

    if (scanf("%d %d", &num1, &num2) != 2)
    {
        printf("Ошибка ввода");
        return 1;
    }
    
    int maxNumber = max(abs(num1), abs(num2));
    size_t length = (size_t)(log2(max(abs(num1 + num2), maxNumber)) + 2);

    int* array1 = (int*)calloc(length, sizeof(int));
    int* array2 = (int*)calloc(length, sizeof(int));

    printf("Числа в двоичном представлении в дополнительном коде: \n");
    twosComplement(array1, num1, length);
    twosComplement(array2, num2, length);
    printArray(array1, length);
    printArray(array2, length);

    printf("Сумма чисел в двоичной системе: \n");
    int* rezult = (int*)calloc(length, sizeof(int));
    binarySum(array1, array2, rezult, length);
    printArray(rezult, length);

    printf("Сумма чисел в десятичной системе: \n");
    int rezultSum = conversionToDecimal(rezult, length);
    printf("%d", rezultSum);

    return 0;
}
