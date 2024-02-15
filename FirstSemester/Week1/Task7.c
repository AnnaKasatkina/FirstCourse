/*
7. Подстрока
Алгоритм нахождения количества вхождений второй строки в первую как подстроки.
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("Enter 2 lines up to 99 characters long: ");

    char string1[100] = "";
    char string2[100] = "";
    scanf("%s %s", &string1, &string2);

    int count = 0;
    for (int i = 0; string1[i] != '\0'; i++)
    {
        bool trigger = true;
        for (int j = 0; string2[j] != '\0'; j++)
        {
            if (string1[i + j] != string2[j]) // когда элемент i+j будет иметь значение '\0',
            {                                 // то если последний элемент не имеет индекс j
                trigger = false;              // цикл прервется, так как встретятся различные элементы, в противном случае
                break;                        // это будет последняя итерация, а следовательно выхода за границы строки не будет
            }
        }
        if (trigger)
        {
            count++;
        }
    }

    printf("The number of occurrences is %d", count);

    return 0;
}
