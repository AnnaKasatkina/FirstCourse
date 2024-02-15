/*
3. Неполное частное
Алгоритм нахождения неполного частного от деления a на b (целые числа),
использующий только операции сложения, вычитания и умножения.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int divisible = 0;
    int divisor = 0;

    printf("Enter the divisible and the divisor: ");
    scanf("%d %d", &divisible, &divisor);

    if (divisor == 0)
    {
        printf("Error! Division by zero!");
        return -1;
    }

    bool isNegative = false;
    if (divisible * divisor < 0)
    {
        isNegative = true;
    }

    bool isDivisionInteger = false;
    if (divisible % divisor == 0)
    {
        isDivisionInteger = true;
    }

    bool isNegativeDivisible = false;
    if (divisible < 0)
    {
        isNegativeDivisible = true;
    }

    divisible = abs(divisible);
    divisor = abs(divisor);

    int result = 0;
    while ((divisible - divisor) >= 0)
    {
        divisible -= divisor;
        result += 1;
    }

    if (isNegativeDivisible && !isDivisionInteger)
    {
        result++;
    }

    if (isNegative)
    {
        result = -result;
    }

    printf("The incomplete quotient is %d", result);
}