/*
Числа Фибоначчи
Реализовать вычисление чисел Фибоначчи рекурсивно,
реализовать итеративно,
выяснить, с какого номера числа Фибоначчи
рекурсивный вариант заметно медленнее итеративного.
*/

#include <stdio.h>
#include <time.h>

int recursiveComputation(int number)
{
    if (number == 1)
    {
        return 0;
    }
    else if (number <= 3)
    {
        return 1;
    }
    else
    {
        return recursiveComputation(number - 1) + recursiveComputation(number - 2);
    }
}

int iterativeComputation(int number)
{
    if (number == 1)
    {
        return 0;
    }
    else if (number <= 2)
    {
        return 1;
    }

    int lastValues[3] = {0, 1, 1};
    for (int i = 3; i <= number; i++)
    {
        lastValues[2] = lastValues[0] + lastValues[1];
        lastValues[0] = lastValues[1];
        lastValues[1] = lastValues[2];
    }
    return lastValues[2];
}

int main()
{
    printf("Enter the number of the Fibonacci series number: ");

    int number = 0;
    scanf("%d", &number);

    printf("The number is %d\n", recursiveComputation(number));
    printf("The number is %d", iterativeComputation(number));

    /*
    int i = 0;
    clock_t iterativeTime = 0;
    clock_t recursiveTime = 0;

    while (iterativeTime <= recursiveTime)
    {
        clock_t start, stop;

        start = clock();
        recursiveComputation(i);
        stop = clock();
        recursiveTime = stop - start;

        start = clock();
        iterativeComputation(i);
        stop = clock();
        iterativeTime = stop - start;

        i++;
    }
    printf("%d", i);
    */

    return 0;
}
