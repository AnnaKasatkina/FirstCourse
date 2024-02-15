/*
6. Простые числа
Программа, печатающая все простые числа, не превосходящие заданного числа.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int givenNumber = 0;
    printf("Enter your number: ");
    scanf("%d", &givenNumber);
    bool *primeMask = calloc(givenNumber - 1, sizeof(bool));
    for (int num = 2; num * num <= givenNumber; ++num)
    {
        if (!primeMask[num - 2])
        {
            for (int i = num * num - 2; i < givenNumber - 1; i += num)
            {
                if ((i + 2) % num == 0 && (i + 2) != num)
                {
                    primeMask[i] = true;
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < givenNumber - 1; ++i)
    {
        if (!primeMask[i])
        {
            count++;
        }
    }

    printf("There are %d primes from 0 to %d\n", count, givenNumber);
    free(primeMask);
}