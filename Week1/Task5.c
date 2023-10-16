/*
5.Баланс скобок
Алгоритм проверки баланса скобок в исходной строке
(т.е. число открывающих скобок равно числу закрывающих и выполняется правило вложенности скобок).
Скобки бывают только одного типа.
*/

#include <stdio.h>

int main()
{
    printf("Enter line up to 100 characters long: ");

    int counter = 0;
    char string[100];
    scanf("%s", &string);

    for (int i = 0; string[i] != '\0' && counter >= 0; i++)
    {
        if (string[i] == '(')
        {
            counter++;
        }
        if (string[i] == ')')
        {
            counter--;
        }
    }

    if (counter == 0)
    {
        printf("Correct!");
    }
    else
    {
        printf("Error!");
    }

    return 0;
}
