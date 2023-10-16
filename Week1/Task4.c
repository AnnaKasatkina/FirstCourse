/*
4. Счастливые билеты
Подсчитать число «счастливых билетов» из шести цифр,
всего существующих в мире
(билет считается «счастливым», если сумма первых трёх цифр
его номера равна сумме трёх последних).
*/

#include <stdio.h>

int main()
{
    int array[28] = {0};
    int sumOfDigits = 0;

    for (int num1 = 0; num1 < 10; num1++)
    {
        for (int num2 = 0; num2 < 10; num2++)
        {
            for (int num3 = 0; num3 < 10; num3++)
            {
                sumOfDigits = num1 + num2 + num3;
                array[sumOfDigits]++;
            }
        }
    }

    int numberOfTickets = 0;
    for (int i = 0; i < 29; i++)
    {
        numberOfTickets += array[i] * array[i];
    }

    printf("There are %d lucky tickets.", numberOfTickets);

    return 0;
}
