/*
2. Swap
Поменять значения двух целочисленных переменных
местами без привлечения третьей переменной и файлов
*/

#include <stdio.h>

int main()
{
    int num1 = 0;
    int num2 = 0;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;

    printf("a = %d, b = %d", num1, num2);

    return 0;
}
